
[S]: ../../../icons/point-red.png
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #array  "инструменты для работы с массивами"  
[1]: #is_zero_array  "tru, если массив нулевого размера"  
[2]: #size_array     "свойства массивов"  
[3]: #small_array    "обработка массивов"  

array-2013, v1.0.1
---
Каталог:  
  - [is_zero_array][1]  
  - [size_array][2]:  
    - dif_big_array  
    - dif_small_array  
    - dfor_big_array  
    - dfor_small_array  
  - [small_array][3]  
    - for_big_arrays_t  
    - for_small_arrays_t  
    - dif_big_arrays  
    - dif_small_arrays  
    - dfor_big_arrays  
    - dfor_small_arrays  

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

История изменений
---

| **ID** | tools           | types | common | версия |     дата      |   время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:---------:|  
|  0001  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 1.0.1  | 2021y-04m-10d | 07:23:33  |  
|  0000  | 0.2.7 [![P]][M] | 1.0.5 | 1.0.3  | 1.0.0  | 2021y-03m-20d | 19:45:37  |  

