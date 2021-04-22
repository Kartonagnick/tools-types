
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

is_rvalue_reference 0.0.1
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![D]][0] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #is_rvalue_reference  "мета-функция: true, если тип - rvalue-ссылка"  
[0]: #-баг-msvc2010  "msvc2010 не правильно определяет характеристики rvalue-reference типов"

is_rvalue_reference
--------
Мета-функция: true, если тип - rvalue-ссылка.  

```cpp
const bool v1 = tools::is_reference<int>::value;        // FALSE
const bool v2 = tools::is_reference<int*>::value;       // FALSE
const bool v2 = tools::is_reference<int&>::value;       // TRUE
const bool v2 = tools::is_reference<int[1]>::value;     // FALSE
const bool v2 = tools::is_reference<int(*)[1]>::value;  // FALSE
const bool v2 = tools::is_reference<int(&)[1]>::value;  // TRUE
const bool v2 = tools::is_reference<int(&&)[1]>::value; // TRUE
```

<br/>
<br/>

[![D]][0] баг msvc2010
---

В компиляторах msvc2010 обнаружился неприятный баг:
```cpp
include <type_traits>
int main()
{
    static_assert(
        std::is_rvalue_reference<void(&&)()>::value,
        "bug-msvc2010"
    );
}
```

Второй пример:

```cpp
include <type_traits>
template<class t> struct example
{
    typedef std::remove_reference<t>
        no_ref;
    typedef typename no_ref::type
        type;
};
int main()
{
    typedef example<int (&)()> 
        bug;
    typedef bug::type 
        result;
}
```
Ошибка компиляции:  

```cpp
error C2752: is_ref_<t>: 
списку аргументов шаблона соответствует более одной частичной специализации
может быть "is_ref_<t&&>" или "is_ref_<t&>"
```

Третий пример:  

```cpp
include <string>
void foo(std::string&&){}
int main()
{
    foo("111");
}
```

Ошибка компиляции:
```cpp
error C2664: невозможно преобразовать параметр 1 из "const char [4]" в "std::string &&"
Нельзя привязать левостороннее значение к ссылке на правостороннее значение
```

Итого:  
Так как msvc2010 не умеет нормально работать с rvalue-reference,  
то их поддержка оффициально заявлена только начинася с msvc2012.  
Макрос: `dHAS_RVALUE_REFERENCES` активирован начиная с msvc2012.  
С точки зрения `tools`, msvc2010 не поддерживает rvalue-reference.  

<br/>
<br/>

История изменений
---

| **ID** | tools           | types           | traits          | версия |     дата      |  время   |  
|:------:|:---------------:|:---------------:|:---------------:|:------:|:-------------:|:--------:|  
|  0000  | 0.2.7 [![P]][M] | 1.2.7 [![P]][M] | 0.1.3 [![P]][M] | 0.0.1  | 2021y-04m-21d | 11:00:00 |  



