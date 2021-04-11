
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

is_pointer
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.1.8 | 0.1.1  | 0.0.2  | 2021y-04m-03d | 23:09:37 |  
|  0000  | 0.2.7 [![P]][M] | 1.0.9 | 0.0.6  | 0.0.1  | 2021y-03m-24d | 21:31:43 |  

<br/>
<br/>

| mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008 |  
|:-----------------:|:-------------------:|:------------------------:|  
|   [![V]][MINGW]   |   [![V]][VS-NEW]    |         [![V]][M]        |  

[M]:       #is_class      "мета-функция: true, если тип - указательный"  
[MINGW]:   #mingw-new     "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new      "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old      "поддержка старых компиляторов msvc"  

описание
--------
Мета-функция: true, если тип - указательный.  

```
const bool v1 = tools::is_pointer<int>::value; // FALSE
const bool v2 = tools::is_pointer<int*>::value; // TRUE
```