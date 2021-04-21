
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
c:\program files (x86)\microsoft visual studio 10.0\vc\include\type_traits(197): error C2752: std::tr1::_Remove_reference<_Ty>: списку аргументов шаблона соответствует более одной частичной специализации
2>          with
2>          [
2>              _Ty=int (__cdecl &)(void)
2>          ]
2>          c:\program files (x86)\microsoft visual studio 10.0\vc\include\xtr1common(356): может быть "std::tr1::_Remove_reference<_Ty&&>"
2>          c:\program files (x86)\microsoft visual studio 10.0\vc\include\xtr1common(350): или       "std::tr1::_Remove_reference<_Ty&>"
2>          c:\kartonagnick\public\tools-types\include\tools\types\common\add_const_data.hpp(163): см. ссылку на создание экземпляров класса шаблон при компиляции "std::tr1::remove_reference<_Ty>"
2>          with
2>          [
2>              _Ty=int (__cdecl &)(void)
2>          ]
```

## Лекарство
msvc2010 не всегда правильно понимает, 
какие типы относятся к rvalue-reference, а какаие к rvalue-reference.  

В частности, он считает, что для `int (&)()` подходит как `T&`, так и `T&&`
Это приводит к поломке мета-функции: `std::tr1::_Remove_reference<_Ty>`,
А так же приводит к поломкам всех тех мета-функций, которые от неё зависят.
Например, ломается `std::decay<int (&)()>`




Очевидное решение: 




Поломка происходит по причине забагованного `std::tr1::_Remove_reference<_Ty>`  
Очевидное решение проблемы: просто не использовать его для msvc2010:  

```cpp
#include <type_traits>

#if defined(_MSC_VER) && _MSC_VER <= 1600
    // msvc2010 or older
    template<class t> struct no_ref_      { typedef t type; };
    template<class t> struct no_ref_ <t&> { typedef t type; };
#endif

template<class t> struct example
{
    #if defined(_MSC_VER) && _MSC_VER <= 1600
        // msvc2010 or older
        typedef no_ref_<t> no_ref;
    #else
        typedef std::remove_reference<t>
            no_ref;
    #endif

    typedef typename no_ref::type
        type;
};

int main()
{
    typedef example<int (&)()> 
        workaround;
    typedef workaround::type 
        result;
}
```




