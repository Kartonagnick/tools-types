
Кратко:
------
Проблема msvc2013 и более старых компиляторов,  
или зачем могут быть нужны дикриминаторы.  


Описание проблемы:
------            
В Visual Studio 2013 не работает идиома `std::void_t`  
Следующий код корректен с точки зрения правил языка.  
Но сборка msvc2013 слетает на static_assert:  

```cpp
#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
 
namespace util
{
    template<class...> using void_t = void;
 
} // namespace util
 
typedef std::string       str_t;
typedef std::vector<int>  vec_t;
typedef std::map<int,int> map_t;
  
template<class, class = void>
struct has_value_type
    : std::integral_constant<bool, false>
{};
 
template<class T>
struct has_value_type<T, util::void_t<typename T::value_type> > 
    : std::integral_constant<bool, true>
{};

// error C2338
static_assert(!has_value_type<int>::value, "INT_ERROR"); 
 
static_assert(has_value_type<str_t>::value, "VEC_ERROR");
static_assert(has_value_type<vec_t>::value, "MAP_ERROR");
 
int main()
{
    std::cout << "[ALL TESTS PASSED]\n";
}
```
Можно ли как ни будь подружить `msvc2013` и `std::void_t` ?


Решение
------
Что бы решить эту проблему, нужно сначала понять суть этой проблемы.  
А что бы понять в чем суть проблемы,  
нужно сначала понять принцип действия техники `void_t`  
А для того, что бы понять принцип действия техники `void_t`,  
нужно сначала понять "принцип инстанцирования специализации шаблона по умолчанию"  


Итак, начнем по порядку.  

## Принцип инстанцирования специализации шаблона по умолчанию

Гласит:  
сначала компилятор подставляет значение по умолчанию,  
а затем проверяет: если полученный набор параметров удовлетворяет специализации,  
тогда он инстанцирует эту специализацию,  
в противном случае инстанцируется главный шаблон.  
Таким образом, по умолчанию всегда запускается специализация,  
а не главный шаблон.  

```cpp
#include <iostream>
 
template<class t, bool = true>
struct example
{
    example() noexcept { std::cout << "general\n"; }
};
 
template<class t>
struct example<t, true>
{
    example() noexcept { std::cout << "example<t,true>\n"; }
};
 
int main()
{
    example<int> ex; // example<t,true>
}
```
Если не указать второй параметр, то по умолчанию он будет `true`,  
что соответствует специализации,  
и именно она и будет в итоге инстанцирована.  

## void_t
Представляет собой алиас с типом `void`

```cpp
namespace std
{
    template<class...> using void_t = void;
 
} // namespace std
```

По правилам языка с++, псевдоним типа и сам тип - это одно и тоже.  
Другими словами, `std::void_t<любые параметры>` - на самом деле является просто `void`  

Теперь рассмотрим классический случай использования техники на практике:  

```cpp
#include <type_traits>
#include <string>
 
template<class, class = void> struct has_value_type
    : std::false_type
{};
 
template<class T> 
struct has_value_type<T, std::void_t<typename T::value_type> > 
    : std::true_type
{};
 
static_assert(has_value_type<std::string>::value, "ERROR");
int main(){}
```

Мы уже знаем, что если явно не указать значение по умолчанию,  
то компилятор попытается инстанцировать дефолтную специализацию.  
В данном случае компилятор будет искать специализацию `<T,void>`  

А поскольку `std::void_t<typename T::value_type>` и есть `void`,  
то именно эту специализацию и попытается инстанцировать компилятор по умолчанию:  

```cpp
template<class T> 
struct has_value_type<T, std::void_t<typename T::value_type> > 
    : std::true_type
{};
```

Но(!) с одним условием: тип данных `std::void_t<typename T::value_type>` должен быть валидным.  
А валидным он может быть только и только в том случае,  
если внутри `T` окажется доступным тип `value_type`  
Если же это условие не выполняется,  
тогда вся специализация `has_value_type<T, std::void_t<typename T::value_type> >` становится не_валидной,  
и выпадает из конкурса на инстанцирование.  

В этом случае, согласно правилам SFINAE,  
компилятор должен выбрать оставшиёся единственным главный шаблон:  
```
template<class, class = void> struct has_value_type
    : std::false_type
{};
```

## Cуть проблемы msvc2013
Следующий код иллюстрирует суть проблемы:  

```cpp
template<class T, class VT = typename T::value_type> 
using enable_if_has_value_type_t = void;
 
template<class T, class = void>
struct has_value_type : std::false_type {};
 
template<class T>
struct has_value_type<T, enable_if_has_value_type_t<T> > 
  : ::std::true_type {};    
 
static_assert(!has_value_type<int>::value, "ERROR"); // upppssss
int main(){}
```

Что здесь произошло?  
Компилятор успешно инстанцировал специализацию `true_type`,  
невзирая на то, что запись `class VT = typename T::value_type` синтаксически не_корректна.  

Это произошло потому, 
что компилятор и не пытался распарсить `typename T::value_type`  
Ещё раз внимательно смотрим на алиас:  

```
namespace std
{
    template<class...> using void_t = void;
 
} // namespace std
```
Как и в примере выше: `using enable_if_has_value_type_t = void`,  
итоговый результат не_зависит от параметров шаблона.  
Старым компиляторам (msvc2013 или более старым)  
это даёт основание забить болт на "тяжелые" вычисления,  
и минуя их, сразу выдать итоговый результат - `void`  

Кто-то скажет: но ведь параметры шаблона могут быть кривыми!  
Почему это компилятор их не проверяет?  

На это в стандарте есть железобетонная отмазка: 
делай нормально, и будет у тебя нормально.  
А будешь делать криво - будет у тебя UB, 
и никто тебе ничего не должен.  

Компилятор имеет полное право закладываться на то,  
что программист - не идиот,  
а значит не будет писать всякий бред.  

Нельзя сказать что компилятор msvc2013 содержит баг.  
Потому что для тогдашнего `с++11` такое поведение было корректным.  
Но в дальнейшем такое поведение таки было признано дефектом,  
и в настоящий момент компиляторы таки обязаны валидировать параметры в `SFINAE` контексте.  

Получилась забавная ситуация:  
для изготовления самодельного `std::void_t` достаточно `с++11`,  
но для того, что бы оно корретно работало, требуется поддержка `с++17`  

## Лекарство
Самое простое и очевидное решение - использовать дискриминатор.  

```
Дискриминатор - элемент конструкции, который делает саму конструкцию более сложной,
но при этом итоговый результат остаётся без изменений.
```

C помощью дискриминатора можно заставить компилятор
честно проверить все параметры шаблона:  

```cpp
#include <type_traits>
 
namespace util
{
    template<class... Args> struct discriminator
        { enum { value = 1 }; };

    template<class A, class... Args> struct discriminator_<A, Args...>
        { 
            using x = ::std::detail::discriminator_<Args...>;
            enum { v = ::std::is_same<A, A>::value };
            enum { value = v && x::value };
        };
 
    template<class... Args> 
        using void_t = ::std::enable_if_t< discriminator<Args...>::value >;
 
} // namespace util
 
 
template<class, class = void>
struct has_value_type
    : std::integral_constant<bool, false>
{};
 
template<class T>
struct has_value_type<T, util::void_t<typename T::value_type> > 
    : std::integral_constant<bool, true>
{};
 
#include <iostream>
#include <vector>
#include <string>
#include <map>
 
using str_t = std::string;
using vec_t = std::vector<int>;
using map_t = std::map<int,int>;
 
static_assert(has_value_type<str_t>::value, "STR_ERROR");
static_assert(has_value_type<vec_t>::value, "VEC_ERROR");
static_assert(has_value_type<map_t>::value, "MAP_ERROR");
static_assert(!has_value_type<int>::value , "INT_ERROR");
 
int main()
{
    std::cout << "[ALL TESTS PASSED]\n";
}
```

В этом примере, что бы вычислить значение `void_t`,  
компилятор вынужден инстанцировать дискриминатор,  
который в свою очередь требует вычисления всех параметров шаблона,  
что в свою очередь не позволяет компилятору их проигнорировать.  

`PROFIT???!!!!`
