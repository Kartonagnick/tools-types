
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #degradate  "разлагает тип: lvalue-to-rvalue"  

degradate-2013, v1.0.1
---

Каталог инструментов:  
  -  Шаблон: `degradate<T> { /* unspecified */ };`  
  -  Алиас: `degradate_t<T> using = /* unspecified */`  
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
template<class t> 
using degradate_t = ::std::remove_cv_t<
    ::std::remove_reference_t<t> 
>;
```

История изменений
---

| **ID** | tools           | types | common | версия |     дата      |   время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:---------:|  
|  0001  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 1.0.1  | 2021y-04m-10d | 07:23:33  |  
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 1.0.0  | 1.0.0  | 2021y-03m-18d | 23:45:05  |  
