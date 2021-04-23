
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![D]][0] | [![D]][0] | [![D]][0] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #degradate  "разлагает тип: lvalue-to-rvalue"  
[0]: #-Ограничения  "degradate_t: не доступно"  

degradate-2008, v1.0.1
---

Каталог инструментов:  
  -  Шаблон: `degradate<T> { /* unspecified */ };`  
  -  Макро-функция: `ddegradate(...) /* unspecified */`  

Описание
--------
Мета-функция `degradate` преобразует lvalue-to-rvalue, и удаляет cv-qualifiers.  
Например:  
 - `const int*& -> const int*`  
 - `const int&& -> int`  
 - `const int&  -> int`  

Синопсис выглядит так:  
```cpp
template<class t> class degradate
{
    typedef dTRAIT::remove_reference<t>
        no_ref;
    typedef typename no_ref::type 
        x;
    typedef dTRAIT::remove_cv<x>
        no_cv;
public:
    typedef typename no_cv::type
        type;
};
```

[![D]][M] Ограничения
---------------------
Функциональность доступна начиная с с++11 (msvc2013, или mingw)
```
if !dHAS_USING_ALIAS (msvc2013)
  degradate_t: функциональность не доступна
```



История изменений
---

| **ID** | tools           | types | common | версия |     дата      |   время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:---------:|  
|  0001  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 1.0.1  | 2021y-04m-10d | 07:23:33  |  
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 1.0.0  | 1.0.0  | 2021y-03m-18d | 23:45:05  |  
