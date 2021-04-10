
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

degradate
---

| **ID** | tools           | types | common | версия |     дата      |   время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:---------:|  
|  0001  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 1.0.1  | 2021y-04m-10d | 07:23:33  |  
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 1.0.0  | 1.0.0  | 2021y-03m-18d | 23:45:05  |  

<br/>
<br/>

| **ID** | элементы            | версия | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:-------------------:|:------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0000  | [degradate-2013][M] | 1.0.1  |   [![V]][MINGW]   |   [![V]][VS-NEW]    |             [![V]][VS-OLD]              |  
|  0001  | [degradate-2012][M] | 1.0.1  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][M] [![D]][0] [![D]][0] [![D]][0] |  
|  0002  | [degradate-2008][M] | 1.0.1  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][M] [![D]][0] [![D]][0] [![D]][0] |  

| **ID** | элементы                | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:-----------------------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0000  | [template degradate][M] |   [![V]][MINGW]   |   [![V]][VS-NEW]    |             [![V]][VS-OLD]              |  
|  0001  | [macro ddegradate][M]   |   [![V]][MINGW]   |   [![V]][VS-NEW]    |             [![V]][VS-OLD]              |  
|  0002  | [alias degradate_t][M]  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][M] [![D]][0] [![D]][0] [![D]][0] |  

[M]:       #degradate     "разлагает тип: lvalue-to-rvalue"  
[MINGW]:   #mingw-new     "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new      "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old      "поддержка старых компиляторов msvc"  
[0]:       #-ограничения  "требуется поддержка template using alias"  

описание
--------
Преобразует ссылочный тип к нессылочному, попутно снимая квалификатор первого уровня.  
Например:  `const int&& -> int`  

Синопсис:  
```
template<class t> 
using degradate_t = ::std::remove_cv_t<
    ::std::remove_reference_t<t> 
>;
```

Доступно всем компиляторам:

```
template<class t> class degradate
{
    typedef /* unspecified */ type;
};

#define ddegradate(t) /* unspecified */
```

[![D]][M] ограничения
---------------------
Доступно начиная с `msvc2013`, или для `mingw`
```
template<class t> 
    using degradate_t = /* unspecified */
```




