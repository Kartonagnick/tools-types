
Кратко:
------
Баг в msvc2010.  


Описание проблемы:
------            
Независимо от типа параметров, с которыми инстанцируют шаблон, результат всегд один и тот же: 1

```cpp
namespace tools
{
    namespace detail
    {
        template<class t> t obj();

        template<class t> class is_dereferencable
        {
            #define dCHECK_EXPRESSION_ \
                decltype(*obj<u>(), ::std::true_type()) 

            template<class u> static dCHECK_EXPRESSION_ 
                check(dCHECK_EXPRESSION_*);

            #undef dCHECK_EXPRESSION_

            template<class> static ::std::false_type
                check(...);

            typedef decltype(check<t>(nullptr))
                checked;
        public:
            enum { value = checked::value };
        };
        
    } // namespace detail
} // namespace tools
```

Ошибка: всегда один и тот же результат 1
То есть, компилятор умыдряется инстанцировать true_type даже для тех случаев,
когда запись: `*obj<u>()` не валидная.

## Лекарство
Нужно всегда явным образом и полностью квалифицировать имена:

```cpp
namespace tools
{
    namespace detail
    {
        template<class t> t obj();

        template<class t> class is_dereferencable
        {
            #define dCHECK_EXPRESSION_ \
                decltype(*::tools::detail::obj<u>(), ::std::true_type()) 

            template<class u> static dCHECK_EXPRESSION_ 
                check(dCHECK_EXPRESSION_*);

            #undef dCHECK_EXPRESSION_

            template<class> static ::std::false_type
                check(...);

            typedef decltype(check<t>(nullptr))
                checked;
        public:
            enum { value = checked::value };
        };
        
    } // namespace detail
} // namespace tools
```



