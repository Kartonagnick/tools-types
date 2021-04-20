
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

decay 0.0.1
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #decay  "мета-функция: разложение типа lvalue-to-rvalue"

описание
--------
```
The decay type of T is the same type that results 
from the standard conversions 
that happen when an lvalue expression is used as an rvalue, 
with its cv-qualifier stripped:
```
Мета-функция: преобразует  
 - lvalue-to-rvalue,  
 - array-to-pointer,  
 - function-to-pointer.  
И удаляет cv-qualifiers.  

<details>
<summary>Пример использования</summary>
<pre><code class="language-c++">


  #include <iostream>
  #include <tools/type_traits.hpp>
 
template <typename T, typename U>
struct decay_equiv : 
    tools::is_same<typename tools::decay<T>::type, U>::type 
{};
 
int main()
{
    std::cout << std::boolalpha
        << decay_equiv<int, int>::value              << '\n'
        << decay_equiv<int&, int>::value             << '\n'
        << decay_equiv<int&&, int>::value            << '\n'
        << decay_equiv<const int&, int>::value       << '\n'
        << decay_equiv<int[2], int*>::value          << '\n'
        << decay_equiv<int(int), int(*)(int)>::value << '\n';
}

</code></pre>
</details>

<br/>
<br/>

История изменений
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 0.0.2  | 0.0.1  | 2021y-03m-18d | 23:45:05 |  
