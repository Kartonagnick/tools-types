
[P]: ../../icons/progress.png
[V]: ../../icons/success.png
[X]: ../../icons/failed.png
[D]: ../../icons/danger.png
[E]: ../../icons/empty.png
[N]: ../../icons/na.png

version 0.0.2
---

variadic-new.hpp, version 0.0.1
---

| **ID** | элементы                 | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:------------------------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0000  | is_heir                  |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][M] [![N]][0] [![N]][0] [![N]][0] |  
|  0001  | dTEMPLATE_CONSTRUCT      |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][M] [![N]][0] [![N]][0] [![N]][0] |  
|  0002  | dTEMPLATE_CONSTRUCT_IMPL |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][M] [![N]][0] [![N]][0] [![N]][0] |  
|  0003  | dTEMPLATE_CONSTRUCT_ARG  |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][M] [![N]][0] [![N]][0] [![N]][0] |  

variadic-old.hpp, version 0.0.1
---

| **ID** | элементы                 | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:------------------------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0000  | is_heir                  |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][VS-OLD]                          |  
|  0001  | dTEMPLATE_CONSTRUCT      |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![N]][0]                               |  
|  0002  | dTEMPLATE_CONSTRUCT_IMPL |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][M] [![V]][M] [![V]][M] [![X]][1] |  
|  0003  | dTEMPLATE_CONSTRUCT_ARG  |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][M] [![V]][M] [![V]][M] [![X]][1] |  


[M]:  #variadic  "решение проблемы провалов в вариадик конструкторы"  
[MINGW]:   #mingw-new   "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new    "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old    "поддержка старых компиляторов msvc"  

[0]:  #-особенности    "требуется поддержка параметров по умолчанию для функций"  
[1]:  #-особенности    "баг в компиляторе msvc2008"  

variadic
---
Решает проблему провалов в шаблоно-конструкторы

<details>
<summary>Пример использования dTEMPLATE_CONSTRUCT</summary>
<pre><code class="language-c++">

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
</code></pre>
</details>

<details>
<summary>Пример использования dTEMPLATE_CONSTRUCT_ARG</summary>
<pre><code class="language-c++">

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
</code></pre>
</details>

[![D]][M] особенности
---------------------

```
if !dHAS_TEMPLATE_FUNCTION_DEFAULT_PARAM  (msvc2013)
    dTEMPLATE_CONSTRUCT: функциональность не доступна

баг в компиляторе msvc2008
    dTEMPLATE_CONSTRUCT_IMPL: функциональность не доступна

```

История изменений 
------

| **ID** |      tools      | types | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.1.1 | 0.0.2  | 2021y-03m-26d | 08:26:36 |  
|  0000  | 0.2.7 [![P]][M] | 1.1.0 | 0.0.1  | 2021y-03m-25d | 21:31:43 |  
