
| дата начала         |   дата конца        | длительность     | исполнитель  |
|:-------------------:|:-------------------:|:----------------:|:------------:|
| 2020y-04m-08d 02:50 | 2020y-04m-08d 21:05 | 18 hours, 15 min | Kartonagnick |

is_const_data
---

```
true, если t представляет собой неизменяемые данные
is_const_data<t>::value

is_const_data<char*>::value             // false
is_const_data<char* const>::value       // false

is_const_data<const char*>::value       // true
is_const_data<const char*const>::value  // true
```

План:  
  - `Часть-1` реализация:  
    - [x] добавляем реализацию  
    - [x] добавляем тесты  
  - `Часть-2` сборка:  
    - [x] проверяем сборку на всех компиляторах  
    - [x] заполняем историю  
    - [x] обновляем таблицу  


