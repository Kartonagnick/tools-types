
| дата начала         |   дата конца        | длительность    | исполнитель  |
|:-------------------:|:-------------------:|:---------------:|:------------:|
| 2020y-03m-30d 21:20 | 2020y-03m-31d 01:55 | 4 hours, 35 min | Kartonagnick |

static_assert
---

Исправляем ошибку в дизайне.  
Было:  

```
#define dSTATIC_ASSERT(expr, msg)
```

Стало:  

```
#define dSTATIC_ASSERT(msg, ...)
```

Раньше dSTATIC_ASSERT можно было использовать только в скоупе функции.  
Теперь можно объявлять, как в скоупе функции, так и в глобальное области.  


План:  
  - `Часть-1` исправляем макрос  
  - `Часть-2` исправляем тесты  
  - `Часть-3`  
    - [x] проверяем сборку на всех компиляторах  
    - [x] заполняем историю  
    - [x] обновляем таблицу  


