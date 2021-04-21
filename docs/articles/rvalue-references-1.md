
Кратко:
------
Баг в msvc2010.  


Описание проблемы:
------            
Компиляция следующего кода при помощи msvc2010 завершается с ошибкой:  

```cpp
#include <type_traits>

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

Ошибка:

```cpp
error C2752: std::tr1::_Remove_reference<_Ty>: 
списку аргументов шаблона соответствует более одной частичной специализации
with
[
    _Ty=int (__cdecl &)(void)
]
xtr1common(356): может быть "std::tr1::_Remove_reference<_Ty&&>"
xtr1common(350): или       "std::tr1::_Remove_reference<_Ty&>"
```

## Анализ
msvc2010 не всегда правильно понимает, 
какие типы относятся к rvalue-reference, а какаие к rvalue-reference.  

В частности, он считает, что для `int (&)()` подходит как `T&`, так и `T&&`
Это приводит к поломке мета-функции: `std::tr1::_Remove_reference<_Ty>`,
А так же приводит к поломкам всех тех мета-функций, которые от неё зависят.
Например, ломается `std::decay<int (&)()>`


## Лекарство
Для msvc2010 используется необычная конструкция `remove_reference` 
При помощи `decltype` и вспомогательных функций достигается эффект `decay`,


```cpp
#include <tools/type_traits.hpp>

#if !defined(dHAS_TYPE_TRAITS)
    // msvc2008 or older
    template<class t> struct example
    {
        typedef dTRAIT::remove_reference<t>
            no_ref;
        typedef typename no_ref::type
            type;
    };
#elif !defined(dHAS_ENUM_CLASS)
    // msvc2010
    template<class t> t& obj_();
    template<class t> t* decay_(t&);

    template<class t> struct remove_reference_
    {
        typedef decltype(decay_(obj_<t>()))
            naked;
        typedef ::std::remove_pointer<naked>
            no_ptr;
        typedef typename no_ptr::type
            type;
    };

    template<class t> struct example
    {
        typedef remove_reference_<t>
            no_ref;
        typedef typename no_ref::type
            type;
    };
#else
    // msvc2012 or newer
    template<class t> struct example
    {
        typedef ::std::remove_reference<t>
            no_ref;
        typedef typename no_ref::type
            type;
    };
#endif

int main()
{
    typedef bug_msvc2010::example<int(&)()>
        bug;
    typedef bug::type 
        result;

    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        dTRAIT::is_same<result, int()>::value
    );
}
```




