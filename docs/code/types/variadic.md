
[P]: ../../icons/progress.png
[V]: ../../icons/success.png
[X]: ../../icons/failed.png
[D]: ../../icons/danger.png
[E]: ../../icons/empty.png
[N]: ../../icons/na.png

current version 0.0.2
---

| **ID** |      tools      | types | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.1.1 | 0.0.2  | 2021y-03m-26d | 08:26:36 |  
|  0000  | 0.2.7 [![P]][M] | 1.1.0 | 0.0.1  | 2021y-03m-25d | 21:31:43 |  

variadic-new.hpp, version 0.0.1
---

| **ID** | элементы                 | tools           | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008 |  
|:------:|:------------------------:|:---------------:|:-----------------:|:-------------------:|:------------------------:|  
|  0000  | is_heir                  | 0.2.7 [![P]][M] |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![N]][VS-OLD]           |  
|  0001  | dTEMPLATE_CONSTRUCT      | 0.2.7 [![P]][M] |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![N]][VS-OLD]           |  
|  0002  | dTEMPLATE_CONSTRUCT_IMPL | 0.2.7 [![P]][M] |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![N]][VS-OLD]           |  
|  0003  | dTEMPLATE_CONSTRUCT_ARG  | 0.2.7 [![P]][M] |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![N]][VS-OLD]           |  

variadic-old.hpp, version 0.0.1
---

| **ID** | элементы                 | tools           | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:------------------------:|:---------------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0000  | is_heir                  | 0.2.7 [![P]][M] |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][VS-OLD]                          |  
|  0001  | dTEMPLATE_CONSTRUCT      | 0.2.7 [![P]][M] |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][M] [![N]][0] [![N]][0] [![N]][0] |  
|  0002  | dTEMPLATE_CONSTRUCT_IMPL | 0.2.7 [![P]][M] |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][M] [![V]][M] [![V]][M] [![X]][1] |  
|  0003  | dTEMPLATE_CONSTRUCT_ARG  | 0.2.7 [![P]][M] |   [![V]][MINGW]   |  [![V]][VS-NEW]     | [![V]][VS-OLD]                          |  

[M]:  #variadic  "решение проблемы провалов в вариадик конструкторы"  
[MINGW]:   #mingw-new   "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new    "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old    "поддержка старых компиляторов msvc"  

[0]:  #-особенности    "требуется поддержка параметров по умолчанию для функций"  
[1]:  #-особенности    "баг в компиляторе msvc2008"  

variadic
---
Решает проблему провалов в variadic конструкторы


<details>
<summary>Пример использования</summary>
<pre>

    #include<cassert>
    #include<iostream>

    enum eCTOR{ eDEFAULT, eCOPY, eRVALUE, eTEMPLATE, eVARIADIC };
    struct example
    {
        template<typename... args, dTEMPLATE_CONSTRUCT(example, args...)>
        example(args&&...):m_ctor(eVARIADIC)
            { std::cout << "variadic\n"; }
        
        template<typename args, dTEMPLATE_CONSTRUCT(example, args)>
        example(args&&):m_ctor(eTEMPLATE)
            { std::cout << "template\n"; }

        example():m_ctor(eDEFAULT)
            { std::cout << "default\n"; }

        example(const example&):m_ctor(eCOPY)
            { std::cout << "copy\n"; }

        example(example&&):m_ctor(eRVALUE)
            { std::cout << "move\n"; }

        eCTOR m_ctor;
    };

    struct der: example
    {
        der():example(){}
        der(const int a):example(a){}
        der(const int a, const int b):example(a,b){}
        der(const der& a, const int b):example(a,b){}
        der(const example& a, const int b):example(a,b){}
        der(const der& rhs):example(rhs){}
        der(der&& rhs):example(std::move(rhs)){}
    };

    der rvalue() {  return std::move(der(10)); }

    int main()
    {
        // output:
        //   default
        //   variadic
        //   template
        //   copy
        //   template
        //   move
        //   default
        //   variadic    
        //   default
        //   variadic        

        der d0;
        assert(d0.m_ctor==eDEFAULT);

        der d1(10,20);
        assert(d1.m_ctor==eVARIADIC);

        der d2(10);
        assert(d2.m_ctor==eTEMPLATE);
        
        der d3 = d1;
        assert(d3.m_ctor==eCOPY);

        der d4 = rvalue();
        assert(d4.m_ctor==eRVALUE);
        
        der d5( der{}, 10);
        assert(d5.m_ctor==eVARIADIC);
        
        der d6( example{}, 10);
        assert(d6.m_ctor==eVARIADIC);
    }
</pre>  
</details>


[![D]][M] особенности
---------------------

```
if !dHAS_TEMPLATE_FUNCTION_DEFAULT_PARAM  (msvc2013)
    dTEMPLATE_CONSTRUCT: функциональность не доступна

баг в компиляторе msvc2008
    dTEMPLATE_CONSTRUCT_IMPL: функциональность не доступна

```
