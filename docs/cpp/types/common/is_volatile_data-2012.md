﻿
[S]: ../../../icons/star-down.png
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![D]][0] | [![N]][0] | [![N]][0] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #is_volatile_data  "мета-функция: true, если указанный тип представляет собой волатильные данные"
[0]: #-Ограничения      "различия в логике работы для старых компиляторов"  

is_volatile_data-2012, v1.0.1
---
Мета-функция возврвщает true, 
если указанный тип представляет волатильные данные.  

Синопсис:  
  - для указателей:     `is_volatile(no_ref(*ptr))`  
  - для массивов:       `is_volatile(no_ref(*arr))`  
  - для итераторов:     `is_volatile(no_ref(*it))`  
  - для смартпоинтеров: `is_volatile(no_ref(*smart))`  
  - для всех прочих:    `is_volatile(no_ref(obj))`  

Каталог:  
  - is_volatile_data  
  - dif_volatile_data  
  - dif_not_volatile_data  

```
using result 
    = tools::is_volatile_data<volatile int&>;
std::cout << result::value << '\n';
```

[![D]][M] Ограничения
---------------------
```
if !dHAS_USING_ALIAS (msvc2013)
  - итераторы и смартпоинтеры не учитываются.
```

История изменений
---

| **ID** | tools           | types | common | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0002  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 1.0.1  | 2021y-04m-10d | 07:23:33 |  
|  0001  | 0.2.7 [![P]][M] | 1.2.4 | 1.1.2  | 1.0.0  | 2021y-04m-09d | 23:32:25 |  
|  0000  | 0.2.7 [![P]][M] | 1.0.8 | 1.0.5  | 1.0.0  | 2021y-03m-23d | 23:55:08 |  
