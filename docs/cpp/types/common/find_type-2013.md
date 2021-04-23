﻿
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![N]][M] | [![N]][M] | [![N]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #find_type "true, если find_type обнаружит указанный тип в списке"  

find_type-2013, v1.0.1
---
Мета-функция возврвщает true, 
если указанный тип присутствует в указанном списке:  

```
// первый параметр - тип, который нужно найти
// остальные параметры - список типов, среди которых нужно искать

using result 
    = tools::find_type<char, int, bool, float>;

std::cout << result::value << '\n';
```

История изменений
---

| **ID** | tools           | types | common | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 1.0.1  | 2021y-04m-10d | 07:23:33 |  
|  0000  | 0.2.7 [![P]][M] | 1.0.3 | 1.0.1  | 1.0.0  | 2021y-03m-19d | 23:13:45 |  