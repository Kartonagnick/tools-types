
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

is_lvalue_reference 0.0.1
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![D]][0] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #is_pointer  "мета-функция: true, если тип - указательный"  
[0]: #-баг-msvc2010  "msvc2010 не правильно определяет характеристики rvalue-reference типов"

описание
--------
Мета-функция: true, если тип - ссылочный.  

```cpp
const bool v1 = tools::is_reference<int>::value;        // FALSE
const bool v2 = tools::is_reference<int*>::value;       // FALSE
const bool v2 = tools::is_reference<int&>::value;       // TRUE
const bool v2 = tools::is_reference<int[1]>::value;     // FALSE
const bool v2 = tools::is_reference<int(*)[1]>::value;  // FALSE
const bool v2 = tools::is_reference<int(&)[1]>::value;  // TRUE
const bool v2 = tools::is_reference<int(&&)[1]>::value; // TRUE
```

<br/>
<br/>

[![D]][0] баг msvc2010
---
В компиляторах msvc2010 обнаружился неприятный баг:  

```cpp
#include <type_traits>

int main()
{
    static_assert(
        std::is_rvalue_reference<void(&&)()>::value,
        "bug-msvc2010"
    );
}
```
Соответственно, вся та функциональность, 
которая имеет дело с ссылочными типами,
может функционировать неправильно.  

<br/>
<br/>

История изменений
---

| **ID** | tools           | types | traits | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0001  | 0.2.7 [![P]][M] | 1.1.8 | 0.1.1  | 0.0.2  | 2021y-04m-03d | 23:09:37 |  
|  0000  | 0.2.7 [![P]][M] | 1.0.9 | 0.0.6  | 0.0.1  | 2021y-03m-24d | 21:31:43 |  
