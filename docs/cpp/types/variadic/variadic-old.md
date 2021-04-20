
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

version 0.0.2
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
| msvc    | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![X]][0] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
| mingw   | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]:  #variadic-old      "решение проблемы провалов в шаблоно-конструкторы"  
[0]:  #-особенности   "баг в компиляторе msvc2008"  

variadic-old
---
Решает проблему провалов в шаблоно-конструкторы.  

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

[![D]][M] особенности
---------------------

```cpp
баг в компиляторе msvc2008
    dTEMPLATE_CONSTRUCT_IMPL: функциональность не доступна
```

История изменений 
------

| **ID** |      tools      | types | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.1.1 | 0.0.2  | 2021y-03m-26d | 08:26:36 |  
|  0000  | 0.2.7 [![P]][M] | 1.1.0 | 0.0.1  | 2021y-03m-25d | 21:31:43 |  
