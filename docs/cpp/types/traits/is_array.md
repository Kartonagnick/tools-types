﻿
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

is_array 0.0.2
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #is_array  "мета-функция: true, если тип - массив"  

описание
--------
Мета-функция: true, если тип - функция.  

```
const bool v1 = tools::is_array<int[]>::value;  // TRUE
const bool v1 = tools::is_array<int[1]>::value; // TRUE
const bool v2 = tools::is_array<int>::value;    // FALSE
```

<br/>
<br/>

История изменений
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.1.6 | 0.0.9  | 0.0.2  | 2021y-04m-02d | 00:41:19 |  
|  0000  | 0.2.7 [![P]][M] | 1.1.1 | 0.0.7  | 0.0.1  | 2021y-03m-26d | 08:26:36 |  