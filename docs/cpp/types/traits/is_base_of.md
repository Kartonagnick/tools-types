﻿
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

is_base_of 0.0.1
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #is_base_of  "мета-функция: true, если B - базовый тип для D"

описание
--------
Мета-функция: true, если B - базовый тип для D  

```
struct B {};
struct D : B {};
using x = tools::is_base_of<B, D>; 

...

std::cout << x::value; // true
```

<br/>
<br/>

История изменений
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0000  | 0.2.7 [![P]][M] | 1.1.1 | 0.0.7  | 0.0.1  | 2021y-03m-26d | 08:26:36 |  
