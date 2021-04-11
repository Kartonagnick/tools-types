﻿
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

conditional
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 0.0.2  | 0.0.1  | 2021y-03m-18d | 23:45:05 |  

<br/>
<br/>

| mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008 |  
|:-----------------:|:-------------------:|:------------------------:|  
|   [![V]][MINGW]   |   [![V]][VS-NEW]    |         [![V]][M]        |  

[M]:       #conditional   "мета-функция: выбор одного из двух типов по условию"  
[MINGW]:   #mingw-new     "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new      "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old      "поддержка старых компиляторов msvc"  

описание
--------
Мета-функция: выбор одного из двух типов по условию.  
Если условия true, тогда результат равен A, а иначе - B  

```
enum { expr = true };
using cond = tools::conditional<expr, A, B>;
using result = typename cond::type; // result is A
```
