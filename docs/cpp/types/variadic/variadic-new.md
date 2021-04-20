
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

version 0.0.3  [![P]][M]
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
| msvc    | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![N]][M] | [![N]][M] | [![N]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
| mingw   | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]:  #variadic-new  "решение проблемы провалов в шаблоно-конструкторы"  

variadic-new
---
Решает проблему провалов в шаблоно-конструкторы.  

Пример использвания `dTEMPLATE_CONSTRUCT`  

```cpp
    #include <tools/types/variadic.hpp>
    struct example
    {
        template<typename... args, dTEMPLATE_CONSTRUCT(example, args...)>
        example(args&&...) { /* variadic arguments */ }
        
        template<typename arg, dTEMPLATE_CONSTRUCT(example, arg)>
        example(arg&&) { /* one template argument */ }

        example(const example&);
        example(example&&);
        example();        
    };
```

Пример использвания `dTEMPLATE_CONSTRUCT_ARG`  

```cpp
    #include <tools/types/variadic.hpp>
    struct example
    {
        template<class A>
        example(const A&, dTEMPLATE_CONSTRUCT_ARG(example, A));

        example(const example&);
        example(example&&);
        example();        
    };

    template<class A>
    example::example(const A& a, dTEMPLATE_CONSTRUCT_IMPL(example, A))
    {
        /* one template argument */
    }
```

История изменений 
------

| **ID** |      tools      | types           | версия |     дата      |  время   |  
|:------:|:---------------:|:---------------:|:------:|:-------------:|:--------:|  
|  0002  | 0.2.7 [![P]][M] | 1.2.7 [![P]][M] | 0.0.3  | 2021y-04m-20d | 23:25:37 |  
|  0001  | 0.2.7 [![P]][M] | 1.1.1           | 0.0.2  | 2021y-03m-26d | 08:26:36 |  
|  0000  | 0.2.7 [![P]][M] | 1.1.0           | 0.0.1  | 2021y-03m-25d | 21:31:43 |  
