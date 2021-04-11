﻿
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

is_same
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.2.5 | 0.1.0  | 0.0.2  | 2021y-04m-03d | 00:12:30 |  
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 0.0.2  | 0.0.1  | 2021y-03m-18d | 23:45:05 |  

<br/>
<br/>

| mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008 |  
|:-----------------:|:-------------------:|:------------------------:|  
|   [![V]][MINGW]   |   [![V]][VS-NEW]    |         [![V]][M]        |  

[M]:       #is_same       "мета-функция: сравнивает типы на равенство"  
[MINGW]:   #mingw-new     "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new      "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old      "поддержка старых компиляторов msvc"  

описание
--------
Мета-функция: сравнивает указанные типы.  
Возвращает true, если типы равны.  

```
std::cout<< tools::is_same<bool, bool>::value << '\n'; // 1
std::cout<< tools::is_same<long, bool>::value << '\n'; // 0
```
