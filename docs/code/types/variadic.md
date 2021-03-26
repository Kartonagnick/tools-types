
[P]: ../../icons/progress.png
[V]: ../../icons/success.png
[X]: ../../icons/failed.png
[D]: ../../icons/danger.png
[E]: ../../icons/empty.png
[N]: ../../icons/na.png

variadic-new.hpp
---

| **ID** | элементы                 | tools           | версия | mingw 830, 720 710 | msvc 2019, 2017, 2015 | msvc 2013, 2012, 2010, 2008 |  
|:------:|:------------------------:|:---------------:|:------:|:------------------:|:---------------------:|:---------------------------:|  
|  0000  | is_heir                  | 0.2.7 [![P]][M] | 0.0.1  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]              |  
|  0001  | dTEMPLATE_CONSTRUCT      | 0.2.7 [![P]][M] | 0.0.1  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]              |  
|  0002  | dTEMPLATE_CONSTRUCT_IMPL | 0.2.7 [![P]][M] | 0.0.1  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]              |  
|  0003  | dTEMPLATE_CONSTRUCT_ARG  | 0.2.7 [![P]][M] | 0.0.1  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]              |  

variadic-old.hpp
---

| **ID** | элементы                 | tools           | версия | mingw 830, 720 710 | msvc 2019, 2017, 2015 | msvc 2013, 2012, 2010, 2008 |  
|:------:|:------------------------:|:---------------:|:------:|:------------------:|:---------------------:|:---------------------------:|  
|  0000  | is_heir                  | 0.2.7 [![P]][M] | 0.0.1  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]              |  
|  0001  | dTEMPLATE_CONSTRUCT      | 0.2.7 [![P]][M] | 0.0.1  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]              |  
|  0002  | dTEMPLATE_CONSTRUCT_IMPL | 0.2.7 [![P]][M] | 0.0.1  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]              |  
|  0003  | dTEMPLATE_CONSTRUCT_ARG  | 0.2.7 [![P]][M] | 0.0.1  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]              |  


variadic
---

Пример использования:


```
// USAGE:

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
```

