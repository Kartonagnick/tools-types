
[P]: ../icons/progress.png
[V]: ../icons/success.png
[X]: ../icons/failed.png
[D]: ../icons/danger.png
[E]: ../icons/empty.png
[N]: ../icons/na.png

version 1.1.0 [![P]][M]
---

| **ID** | элемент        | tools           | версия | mingw 830, 720 710 | msvc 2019, 2017, 2015 | msvc 2013, 2012, 2010, 2008             |  
|:------:|:--------------:|:---------------:|:------:|:------------------:|:---------------------:|:---------------------------------------:|  
|  0000  | [fixed][01]    | 0.1.8           | 1.0.0  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][VS-OLD]                          |  
|  0001  | [traits][02]   | 0.1.9           | 0.0.7  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][0] [![D]][0] [![D]][0] [![D]][0] |  
|  0002  | [common][03]   | 0.2.6           | 1.0.5  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![D]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0003  | [variadic][04] | 0.2.7 [![P]][M] | 0.0.2  |   [![V]][MINGW]    |  [![V]][VS-NEW]       | [![V]][0] [![V]][0] [![V]][0] [![D]][1] |  

[M]:  #types  "обработака типов"  
[MINGW]:   #mingw-new   "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new    "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old    "поддержка старых компиляторов msvc"  
[0]:       #msvc-old    "поддержка старых компиляторов msvc"  
[1]:       #msvc-old    "баг в компиляторе msvc2008: не работает dTEMPLATE_CONSTRUCT_IMPL"  

[01]: types/fixed.md     "фиксированные типы данных"  
[02]: types/traits.md    "набор метафункций"  
[03]: types/common.md    "набор метафункций"  
[04]: types/variadic.md  "макрос dTEMPLATE_CONSTRUCT"  
