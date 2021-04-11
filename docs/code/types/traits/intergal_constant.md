
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

intergal_constant
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0000  | 0.2.7 [![P]][M] | 1.0.3 | 0.0.3  | 0.0.1  | 2021y-03m-19d | 23:13:45 |  

<br/>
<br/>

| mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008 |  
|:-----------------:|:-------------------:|:------------------------:|  
|   [![V]][MINGW]   |   [![V]][VS-NEW]    |         [![V]][M]        |  

[M]:       #integral_constant   "тип-константное значение"  
[MINGW]:   #mingw-new           "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new            "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old            "поддержка старых компиляторов msvc"  

описание
--------
Тип-константное значение:

```
enum { expr = sizeof(t) > 1 };
using x = tools::intergal_constant<expr, int>;
std::cout << x::value << '\n';
```

