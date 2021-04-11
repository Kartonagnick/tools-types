
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

remove_reference
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.0.8 | 0.0.5  | 0.0.2  | 2021y-03m-23d | 23:55:08 |  
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 0.0.2  | 0.0.1  | 2021y-03m-18d | 23:45:05 |  

<br/>
<br/>

| mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008 |  
|:-----------------:|:-------------------:|:------------------------:|  
|   [![V]][MINGW]   |   [![V]][VS-NEW]    |         [![V]][M]        |  

[M]:       #remove_reference    "мета-функция: удаляет у типа ссылку"  
[MINGW]:   #mingw-new           "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new            "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old            "поддержка старых компиляторов msvc"  

описание
--------
Мета-функция: удаляет у типа ссылку.  

```
using no_ref = tools::remove_reference<int&&>;
using result = typename no_ref::type; // int
```

