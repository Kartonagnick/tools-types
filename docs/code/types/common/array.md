
[S]: ../../../icons/star-down.png
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

array, version 101
---

| **ID** | tools           | types | common | версия |     дата      |   время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:---------:|  
|  0001  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 1.0.1  | 2021y-04m-10d | 07:23:33  |  
|  0000  | 0.2.7 [![P]][M] | 1.0.5 | 1.0.3  | 1.0.0  | 2021y-03m-20d | 19:45:37  |  

[M]:       #array         "утилиты для работы с массивами"  
[MINGW]:   #mingw-new     "поддержка компиляторов mingw"  
[VS-NEW]:  #msvc-new      "поддержка новых компиляторов msvc"  
[VS-OLD]:  #msvc-old      "поддержка старых компиляторов msvc"  

is_zero_array
---
мета-функция возвращает true, 
если T - массив с нулевым количеством элементов.  
```
using v = tools::is_zero_array<int[0]>;
std::cout << v::value << '\n';
```

size_array
---
мета-функция определяет свойства массива:  
```
using arr = tools::size_array<int[10]>;
std::cout << arr::valid << '\n';
std::cout << arr::value << '\n';
std::cout << arr::big   << '\n';
std::cout << arr::Small << '\n';
std::cout << arr::empty << '\n';
std::cout << arr::zero  << '\n';
```


small_arrays
---
вспомогательная мета-функция используется концептами:
```
using a = int[20];
using b = int[200];
using x = tools::small_array_selector<a, b>;
const bool small = x::value;
```

array-2013, version 101
---

| **ID** | элементы                     | версия | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:----------------------------:|:------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0010  | [![S]][M] [small_arrays][M]  | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0009  | [dif_big_arrays][M]          | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0008  | [dif_small_arrays][M]        | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0007  | [dfor_big_arrays][M]         | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0006  | [dfor_small_arrays][M]       | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0005  | [![S]][M] [size_array][M]    | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0004  | [dif_big_array][M]           | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0003  | [dif_small_array][M]         | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0002  | [dfor_big_array][M]          | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0001  | [dfor_small_array][M]        | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![N]][0] [![N]][0] [![N]][0] |  
|  0000  | [![S]][M] [is_zero_array][M] | 1.0.0  |   [![V]][MINGW]   |   [![D]][0]         | [![D]][0] [![N]][0] [![N]][0] [![N]][0] |  

<br/>
<br/>

array-2012, version 101
---

| **ID** | элементы                     | версия | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:----------------------------:|:------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0006  | [![S]][M] [small_arrays][M]  | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![N]][0] [![N]][0] |  
|  0005  | [dif_big_arrays][M]          | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![N]][0] [![N]][0] |  
|  0004  | [dif_small_arrays][M]        | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![N]][0] [![N]][0] |  
|  0003  | [![S]][M] [size_array][M]    | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![N]][0] [![N]][0] |  
|  0002  | [dif_big_array][M]           | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![N]][0] [![N]][0] |  
|  0001  | [dif_small_array][M]         | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![N]][0] [![N]][0] |  
|  0000  | [![S]][M] [is_zero_array][M] | 1.0.0  |   [![V]][MINGW]   |   [![D]][0]         | [![D]][0] [![D]][0] [![N]][0] [![N]][0] |  

<br/>
<br/>

array-2008, version 101
---

| **ID** | элементы                     | версия | mingw 830,720,710 | msvc 2019,2017,2015 | msvc 2013,2012,2010,2008                |  
|:------:|:----------------------------:|:------:|:-----------------:|:-------------------:|:---------------------------------------:|  
|  0006  | [![S]][M] [small_arrays][M]  | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![V]][0] [![V]][0] |  
|  0005  | [dif_big_arrays][M]          | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![V]][0] [![V]][0] |  
|  0004  | [dif_small_arrays][M]        | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![V]][0] [![V]][0] |  
|  0003  | [![S]][M] [size_array][M]    | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![V]][0] [![V]][0] |  
|  0002  | [dif_big_array][M]           | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![V]][0] [![V]][0] |  
|  0001  | [dif_small_array][M]         | 1.0.0  |   [![V]][MINGW]   |   [![V]][VS-NEW]    | [![V]][0] [![V]][0] [![V]][0] [![V]][0] |  
|  0000  | [![S]][M] [is_zero_array][M] | 1.0.0  |   [![V]][MINGW]   |   [![D]][0]         | [![D]][0] [![D]][0] [![D]][0] [![D]][0] |  

<br/>
<br/>

[0]:       #-ограничения  "ограничения для массивов"

[![D]][M] ограничения
---------------------
```
if !dHAS_ZERO_SIZE_ARRAY   (msvc-all)
    is_zero_array: всегда возвращает false

if !dHAS_ARRAY_EMPTY_SIZE  (msvc2012)
    size_array: type(&ref)[] не доступен

if !dHAS_RVALUE_REFERENCE  (msvc2012)
    size_array: rval не доступен

макро-функции:
  dif_big_array
  dif_small_array
доступны всем компиляторам

мета-функции:
  using for_big_arrays 
  using for_small_arrays 
доступны только начиная с msvc2013

макро-функции:
    dfor_big_arrays(arr1, arr2)
    dfor_small_arrays(arr1, arr2)
доступны только начиная с msvc2013
```
