
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

is_convertibe 0.0.1
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #is_convertibe  "мета-функция: true, если From может быть неявно преобразованно в To"

описание
--------
Мета-функция: true, если From может быть неявно преобразованно в To

```cpp
std::cout << tools::is_convertible<int&, int>::value         << '\n'; // true
std::cout << tools::is_convertible<int&, int&>::value        << '\n'; // true
std::cout << tools::is_convertible<int&, const int>::value   << '\n'; // true
std::cout << tools::is_convertible<int&, const int&>::value  << '\n'; // true
std::cout << tools::is_convertible<int&, const int&&>::value << '\n'; // false
std::cout << tools::is_convertible<int&, int&&>::value       << '\n'; // false

std::cout << tools::is_convertible<const int&, int>::value         << '\n'; // true
std::cout << tools::is_convertible<const int&, int&>::value        << '\n'; // false
std::cout << tools::is_convertible<const int&, const int>::value   << '\n'; // true
std::cout << tools::is_convertible<const int&, const int&>::value  << '\n'; // true
std::cout << tools::is_convertible<const int&, const int&&>::value << '\n'; // false
std::cout << tools::is_convertible<const int&, int&&>::value       << '\n'; // false
```

<br/>
<br/>

История изменений
---

| **ID** | tools           | types | trait s | версия          |     дата      |  время   |  
|:------:|:---------------:|:-----:|:-------:|:---------------:|:-------------:|:--------:|  
|  0012  | 0.2.7 [![P]][M] | 1.2.7 [![P]][M] | 0.1.3 [![P]][M] | 2021y-04m-21d | 02:32:33 |  
