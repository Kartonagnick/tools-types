
[P]: ../../icons/progress.png
[V]: ../../icons/success.png
[X]: ../../icons/failed.png
[D]: ../../icons/danger.png
[E]: ../../icons/empty.png
[N]: ../../icons/na.png

[M]: #limit  "Метафункция получения лимитов для целочисленных интегральных типов"  

version 1.0.0
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
| msvc    | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
| mingw   | [![V]][M] | [![V]][M] | [![V]][M] |  

limit
-----
Метафункция получения лимитов для целочисленных интегральных типов:  

```
std::cout << limit<int>::max_value << '\n';
std::cout << limit<int>::min_value << '\n';
```

[![V]][M] особенности
---------------------

```
if dHAS_CPP11
    используются constexpr константы 
else 
    используются enum константы
```

```
if dHAS_CSTDINT
    используется <cstdint>
else 
    используется самодельная реализация
```

История изменений 
------

| **ID** |      tools      | types           | версия |     дата      |  время   |  
|:------:|:---------------:|:---------------:|:------:|:-------------:|:--------:|  
|  0000  | 0.2.7 [![P]][M] | 1.2.7 [![P]][M] | 1.0.0  | 2021y-04m-19d | 11:54:01 |  

