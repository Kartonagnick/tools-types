
[P]: ../icons/progress.png
[V]: ../icons/success.png
[X]: ../icons/failed.png
[D]: ../icons/danger.png
[E]: ../icons/empty.png
[N]: ../icons/na.png

version 1.2.5
---

| **ID** | элемент        | tools           | версия          | mingw 830, 720 710 | msvc 2019, 2017, 2015 | msvc 2013, 2012, 2010, 2008             |  
|:------:|:--------------:|:---------------:|:---------------:|:------------------:|:---------------------:|:---------------------------------------:|  
|  0004  | [common][04]   | 0.2.6           | 1.1.3           |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][0] [![D]][0] [![D]][0] [![D]][0] |  
|  0003  | [traits][03]   | 0.1.0           | 0.1.2           |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][0] [![D]][0] [![D]][0] [![D]][0] |  
|  0002  | [fixed][02]    | 0.1.8           | 1.0.2           |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]                          |  
|  0001  | [variadic][01] | 0.2.7 [![P]][M] | 0.0.2           |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][0] [![V]][0] [![V]][0] [![X]][1] |  
|  0000  | [demangle][00] | 0.2.7 [![P]][M] | 0.0.1           |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]                          |  

[M]:  #types  "обработака типов"  
[MINGW]:   #mingw-new   "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new    "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old    "поддержка старых компиляторов msvc"  
[0]:       #msvc-old    "поддержка старых компиляторов msvc"  
[1]:       #msvc-old    "баг msvc2008: не работает dTEMPLATE_CONSTRUCT_IMPL"  

[04]: types/common.md      "набор метафункций"  
[03]: types/traits.md      "набор метафункций"  
[02]: types/fixed.md       "фиксированные типы данных"  
[01]: types/variadic.md    "макрос dTEMPLATE_CONSTRUCT"  
[00]: types/demangle.md    "человеко-читабельное название типа"  
