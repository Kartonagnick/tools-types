
Кратко:
------
Дефект в поведении msvc2013.


Описание проблемы:
------            
В Visual Studio 2013 не работает код вида:

```cpp

#include <tools/types/void_t.hpp>

template<class, class = void>
struct has_begin
    : std::false_type
{};
 
template<class T>
struct has_begin<T, dSFINAE_VOID_TYPE( decltype(obj<T>().begin()) )> 
    : std::true_type
{};

int main(){}
```

Ошибка:
```cpp
error C2228: left of '.begin' must have class/struct/union
```

Шаблон даже не был инстанцирован.


## Лекарство
Не существует.  
В качестве обходного пути можно использовать альтернативную sfinae-конструкцию:  

```cpp
#include <tools/type_traits.hpp>

template<class t> t obj();

#if dHAS_TYPE_TRAITS
    // msvc2010 or newer
    template<class t> struct has_begin_
    {
        #define dEXPR                      \
            typename dTRAIT::add_pointer<  \
                decltype(obj<u>().begin()) \
            >::type                        \

        template<class u> static
            decltype(obj<u>().begin(), dTRAIT::true_type())
            check(dEXPR);

        #undef dEXPR

        template<class> static 
            dTRAIT::false_type check(...);

        typedef decltype(check<t>(0))
            type;
    };
#else
    // msvc2008 or older
    template<class T> struct has_begin_
    {
        __if_exists(T::begin)
        {
            typedef dTRAIT::true_type type;
        }
        __if_not_exists(T::begin)
        {
            typedef dTRAIT::false_type type;
        }
    };

#endif

template<class t> struct has_begin 
    : has_begin_<t>::type
{};

dSTATIC_ASSERT(STR_BEGIN_ERROR,  has_begin<str_t>::value);
dSTATIC_ASSERT(VEC_BEGIN_ERROR,  has_begin<vec_t>::value);
dSTATIC_ASSERT(MAP_BEGIN_ERROR,  has_begin<map_t>::value);
dSTATIC_ASSERT(INT_BEGIN_ERROR, !has_begin<int>::value);

int main(){}

```
