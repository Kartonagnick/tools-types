
| дата начала         |   дата конца        | длительность   | исполнитель  |
|:-------------------:|:-------------------:|:--------------:|:------------:|
| 2020y-03m-29d 22:20 | 2020y-03m-29d 23:55 | 1 hour, 35 min | Kartonagnick |

add_const_data
---

Синопсис

```

using x = tools::add_const_data_t<int*>;
static_assert(std::is_same<x, const int*>::value, "bug");

```

План:  
  - `Часть-1`  добавляем реализцию:  
    - [x] add_const_data
  - `Часть-2` добавляем тесты:  
    - [x] test-add_const_data
  - `Часть-3`
    - [x] проверяем сборку на всех компиляторах  
    - [x] заполняем историю  
    - [x] обновляем таблицу  

