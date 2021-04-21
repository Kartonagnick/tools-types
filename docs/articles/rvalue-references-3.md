
Кратко:
------
Баг в msvc2010.  


Описание проблемы:
------            
Компиляция следующего кода при помощи msvc2010 завершается с ошибкой:  

```cpp
template <class t> struct is_ref_
    { enum { value = false }; };
    
template <class t> struct is_ref_ <t&>
    { enum { value = true }; };

template <class t> struct is_ref_ <t&&>
    { enum { value = true }; };

int main()
{
    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        is_ref_<void(&)()>::value
    );
}
```

Ошибка:  

```cpp
error C2752: is_ref_<t>: 
списку аргументов шаблона соответствует более одной частичной специализации
with
[
    t=func
]
может быть "is_ref_<t&&>"
или       "is_ref_<t&>"
```

## Анализ
Ссылки бывают `lvalue-reference` или `rvalue-reference`  
Соответственно, все `reference-типы` делятся на `T&` и `T&&`  
Но msvc2010 не всегда правильно понимает,  
к какой категории отнести ту, или иную ссылку.  

В частности, `void(&)()` по мнению msvc2010 подходит для обеих категорий.  
Что и приводит к означенной выше ошибке.  

## Лекарство
Нужно принципиально разделять `T&` и `T&&`, и не смешивать их:  

```cpp
template <class t> struct is_lval_ref_
    { enum { value = false }; };

template <class t> struct is_lval_ref_<t&>
    { enum { value = true }; };

template <class t> struct is_rval_ref_
    { enum { value = false }; };

#ifdef dHAS_TYPE_TRAITS
template <class t> struct is_rval_ref_<t&&>
    { enum { value = true }; };
#endif

#if defined(_MSC_VER) && _MSC_VER == 1600
    // msvc2010
    template <class t> struct is_ref_
    { 
        typedef is_lval_ref_<t> lval_t;
        typedef is_rval_ref_<t> rval_t;
        enum { lval = lval_t::value }; 
        enum { rval = rval_t::value }; 
        enum { value = lval || rval }; 
    };
#else
    template <class t> struct is_ref_
        { enum { value = false }; };
    template <class t> struct is_ref_ <t&>
        { enum { value = true }; };
    #ifdef dHAS_TYPE_TRAITS
    template <class t> struct is_ref_ <t&&>
        { enum { value = true }; };
    #endif
#endif

int main()
{
    dSTATIC_CHECK(
        ERROR_BUG_LVALUE_MSVC2010, 
        is_ref_<void(&)()>::value
    );
    dSTATIC_CHECK(
        ERROR_BUG_RVALUE_MSVC2010, 
        is_ref_<void(&&)()>::value
    );
}

```

Ошибка:  

```cpp
error C2338: ERROR_BUG_RVALUE_MSVC2010
```
Исправить данную ошибку не удалось.  
Проблема в том, что компилятор msvc2010 не опознает подобный тип как rvalue_reference:  

```cpp
    dSTATIC_CHECK(
        ERROR_BUG_IS_RVALUE_MSVC2010, 
        std::is_rvalue_reference<void(&&)()>::value
    );
```
