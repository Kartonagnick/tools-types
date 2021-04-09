
| дата начала         |   дата конца        | длительность | исполнитель  |
|:-------------------:|:-------------------:|:------------:|:------------:|
| 2020y-04m-09d 23:20 | 2020y-04m-09d 23:55 | 35 min       | Kartonagnick |

is_volatile_data
---

Модернизация `is_volatile_data`

```
true, если t представляет собой неизменяемые данные
is_volatile_data<t>::value

is_volatile_data<char*>::value                   // false
is_volatile_data<char* volatile>::value          // false

is_volatile_data<volatile char*>::value          // true
is_volatile_data<volatile char*volatile>::value  // true
```

План:  
  - `Часть-1` реализация:  
    - [x] добавляем реализацию  
    - [x] добавляем тесты  
  - `Часть-2` сборка:  
    - [x] проверяем сборку на всех компиляторах  
    - [x] заполняем историю  
    - [x] обновляем таблицу  


