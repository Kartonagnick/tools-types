
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

функциаональность:  

| **ID** | элементы                | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:-----------------------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0000  | [template degradate][M] |   [![V]][MINGW]   |   [![V]][VS-NEW]    |             [![V]][VS-OLD]              |  
|  0001  | [alias degradate_t][M]  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][M] [![D]][0] [![D]][0] [![D]][0] |  
|  0002  | [macro ddegradate][M]   |   [![V]][MINGW]   |   [![V]][VS-NEW]    |             [![V]][VS-OLD]              |  

[M]:       #degradate     "разлагает тип: lvalue-to-rvalue"  
[MINGW]:   #mingw-new     "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new      "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old      "поддержка старых компиляторов msvc"  
[0]:       #-ограничения  "требуется поддержка template using alias"  

cинопсис
--------

```
template<class t> 
using degradate_t = ::std::remove_cv_t<
    ::std::remove_reference_t<t> 
>;
```

описание
--------
Мета-функция `degradate` преобразует lvalue-to-rvalue, и удаляет cv-qualifiers.  
Например:  
 - `const int*& -> const int*`  
 - `const int&& -> int`  
 - `const int&  -> int`  

В поставку входит:  
Шаблон мета-функции:  
```
template<class t> class degradate
{
    typedef /* unspecified */ type;
};
```
Алиас (начиная с с++11)  
```
template<class t> 
    using degradate_t = /* unspecified */
```
Макро-функция:  

```
#define ddegradate(t) /* unspecified */
```
Все три инструмента взаимозаменяемые.  


[![D]][M] ограничения
---------------------
Функциональность доступна начиная с с++11 (msvc2013, или mingw)
```
if !dHAS_USING_ALIAS (msvc2013)
  degradate_t: функциональность не доступна
```





