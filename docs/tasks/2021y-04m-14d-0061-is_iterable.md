
| дата начала         |   дата конца        |  длительность    | исполнитель  |
|:-------------------:|:-------------------:|:----------------:|:------------:|
| 2020y-04m-14d 02:15 | 2020y-04m-14d 23:55 | 21 hours, 40 min | Kartonagnick |

is_iterable
---

Дизайн:  

```
using vec = std::vector<int>;
using it  = vec::iterator;
using x   = tools::is_iterable<it>;
enum { itarable = x::value };
```
План:  
  - `Часть-1` перестановки:  
    - [x] добавляем реализацию  
    - [x] добавляем тесты  
  - `Часть-2`  
    - [x] проверяем сборку на всех компиляторах  
    - [x] заполняем историю  
    - [x] обновляем таблицу  



