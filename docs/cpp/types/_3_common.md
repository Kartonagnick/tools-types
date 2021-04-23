
[P]: ../../icons/progress.png
[V]: ../../icons/success.png
[X]: ../../icons/failed.png
[D]: ../../icons/danger.png
[E]: ../../icons/empty.png
[N]: ../../icons/na.png

[M]: #common  "сборник мета-алгоритмов общего назначения"  

common 1.1.5  [![P]][M]
---
                                                               
| **ID** |    элементы                    | common |  ver  |  
|:------:|:------------------------------:|:------:|:-----:|  
|  0012  | [enable_for][12]               |  1.1.3 | 1.0.0 |  
|  0011  | [is_const_data][11]            |  1.1.1 | 1.0.0 |  
|  0010  | [type_of_enum][10]             |  1.0.7 | 1.0.0 |  
|  0009  | [is_volatile_data][09]         |  1.0.5 | 1.0.0 |  
|  0008  | [~~is_dereferencable~~][08]    |  1.0.4 | 1.0.0 |  
|  0005  | [array][05]                    |  1.0.3 | 1.0.0 |  
|  0004  | [~~is_lambda~~][04]            |  1.0.2 | 1.0.0 |  
|  0003  | [find_type][03]                |  1.0.1 | 1.0.0 |  
|  0002  | [for_rvalue][02]               |  1.0.0 | 1.0.0 |  
|  0001  | [for_lvalue][01]               |  1.0.0 | 1.0.0 |  
|  0000  | [degradate][00]                |  1.0.0 | 1.0.0 |  

[00]: common/degradate.md/#degradate      "мета-функция: для обработки аргументов функций"  
[01]: common/for_lvalue.md/#for_lvalue    "мета-функция: для обработки lvalue-аргументов функций"  
[02]: common/for_rvalue.md/#for_rvalue    "мета-функция: для обработки rvalue-аргументов функций"  
[03]: common/find_type.md/#find_type      "мета-функция: true, если указанный тип присутствует в списке"  
[04]: common/is_lambda.md/#is_lambda      "мета-функция: true, если указанный тип - лямбда (переехала в sfinae)"  
[05]: common/array.md/#is_zero_array      "мета-функция: true, если указанный тип - массив с нулевым кол-вом элементов"  
[06]: common/array.md/#size_array         "мета-функция: возвращает свойства массива"  
[07]: common/array.md/#small_arrays       "концепт: для функций, аргументы которых - массивы"  
[08]: common/is_dereferencable.md         "мета-функция: true, если объект T можно разыменовать (переехала в sfinae)"  
[09]: common/is_volatile_data.md          "мета-функция: true, если указанный тип представляет собой волатильные данные"  
[10]: common/type_of_enum.md              "мета-функция: возвращает underlying_type"
[11]: common/is_const_data.md             "мета-функция: true, если указанный тип представляет собой неизменяемые данные"  
[12]: common/enable_for.md                "мета-функция: инстанцирует только те аргументы, которые имеются/отсутствуют в указанном списке"  

История изменений 
---

| **ID** |      tools      | types | common |     дата      |  время   | действие                |  версия  |
|:------:|:---------------:|:-----:|:------:|:-------------:|:--------:|:-----------------------:|:--------:|
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | mov: ~~is_zero_array~~  |   n/a    |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | mov: ~~size_array~~     |   n/a    |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | mov: ~~small_array~~    |   n/a    |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: types/common/array |   100    |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2008 |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2013 |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2015 |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2008 |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2012 |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2015 |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2008 |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2013 |
|  0009  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 | add: array/is_zero_array | 100.2015 |
|--------|-----------------|-------|--------|---------------|----------|-------------------------|----------|
|  0008  | 0.2.7 [![P]][M] | 1.1.9 | 1.0.7  | 2021y-04m-04d | 07:05:55 | add: type_of_enum       |   100    |
|  0008  | 0.2.7 [![P]][M] | 1.1.9 | 1.0.7  | 2021y-04m-04d | 07:05:55 | del: ~~add_const_data~~ | 100.2008 |
|  0008  | 0.2.7 [![P]][M] | 1.1.9 | 1.0.7  | 2021y-04m-04d | 07:05:55 | del: ~~add_const_data~~ | 100.2013 |
|  0008  | 0.2.7 [![P]][M] | 1.1.9 | 1.0.7  | 2021y-04m-04d | 07:05:55 | del: ~~add_const_data~~ | 100.2015 |
|  0008  | 0.2.7 [![P]][M] | 1.1.9 | 1.0.7  | 2021y-04m-04d | 07:05:55 | `bug` add_const_data    |   101    |
|--------|-----------------|-------|--------|---------------|----------|-------------------------|----------|
|  0007  | 0.2.7 [![P]][M] | 1.1.3 | 1.0.6  | 2021y-03m-30d | 03:40:56 | add: add_const_data     | 100.2008 |
|  0007  | 0.2.7 [![P]][M] | 1.1.3 | 1.0.6  | 2021y-03m-30d | 03:40:56 | add: add_const_data     | 100.2013 |
|  0007  | 0.2.7 [![P]][M] | 1.1.3 | 1.0.6  | 2021y-03m-30d | 03:40:56 | add: add_const_data     | 100.2015 |
|--------|-----------------|-------|--------|---------------|----------|-------------------------|----------|
|  0006  | 0.2.7 [![P]][M] | 1.0.8 | 1.0.5  | 2021y-03m-23d | 23:55:08 | add: is_volatile_data   | 100.2008 |
|  0006  | 0.2.7 [![P]][M] | 1.0.8 | 1.0.5  | 2021y-03m-23d | 23:55:08 | add: is_volatile_data   | 100.2013 |
|  0006  | 0.2.7 [![P]][M] | 1.0.8 | 1.0.5  | 2021y-03m-23d | 23:55:08 | add: is_volatile_data   | 100.2015 |
|--------|-----------------|-------|--------|---------------|----------|-------------------------|----------|
|  0005  | 0.2.7 [![P]][M] | 1.0.7 | 1.0.4  | 2021y-03m-22d | 11:07:57 | upd: формат версий      |   n/a    |
|  0004  | 0.2.7 [![P]][M] | 1.0.6 | 1.0.4  | 2021y-03m-21d | 17:51:39 | add: is_dereferencable  |   100    |
|--------|-----------------|-------|--------|---------------|----------|-------------------------|----------|
|  0003  | 0.2.7 [![P]][M] | 1.0.5 | 1.0.3  | 2021y-03m-20d | 19:45:37 | add: is_zero_array      |   100    |
|  0003  | 0.2.7 [![P]][M] | 1.0.5 | 1.0.3  | 2021y-03m-20d | 19:45:37 | add: size_array         |   100    |
|  0003  | 0.2.7 [![P]][M] | 1.0.5 | 1.0.3  | 2021y-03m-20d | 19:45:37 | add: small_array        |   100    |
|--------|-----------------|-------|--------|---------------|----------|-------------------------|----------|
|  0002  | 0.2.7 [![P]][M] | 1.0.4 | 1.0.2  | 2021y-03m-20d | 05:35:17 | add: is_functor         |   100    |
|--------|-----------------|-------|--------|---------------|----------|-------------------------|----------|
|  0001  | 0.2.7 [![P]][M] | 1.0.3 | 1.0.1  | 2021y-03m-19d | 23:13:45 | add: find_type-2008     |   100    |
|  0001  | 0.2.7 [![P]][M] | 1.0.3 | 1.0.1  | 2021y-03m-19d | 23:13:45 | add: find_type-2013     |   100    |
|  0001  | 0.2.7 [![P]][M] | 1.0.3 | 1.0.1  | 2021y-03m-19d | 23:13:45 | add: find_type-2015     |   100    |
|--------|-----------------|-------|--------|---------------|----------|-------------------------|----------|
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 1.0.0  | 2021y-03m-18d | 23:45:05 | add: degradate-2013     |   100    |
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 1.0.0  | 2021y-03m-18d | 23:45:05 | add: dfor_lvalue-2015   |   100    |
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 1.0.0  | 2021y-03m-18d | 23:45:05 | add: dfor_rvalue-2015   |   100    |







| **ID** |      tools      | types | common |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:-------------:|:--------:|  
|  0013  | 0.2.7 [![P]][M] | 1.2.6 | 1.1.4  | 2021y-04m-14d | 11:54:37 |  
|  0013  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 2021y-04m-10d | 07:23:33 |  
|  0012  | 0.2.7 [![P]][M] | 1.2.4 | 1.1.2  | 2021y-04m-09d | 23:32:25 |  
|  0011  | 0.2.7 [![P]][M] | 1.2.3 | 1.1.1  | 2021y-04m-08d | 20:32:25 |  
|  0010  | 0.2.7 [![P]][M] | 1.2.2 | 1.1.0  | 2021y-04m-07d | 23:43:10 |  
|  0009  | 0.2.7 [![P]][M] | 1.2.1 | 1.0.9  | 2021y-04m-06d | 23:43:10 |  
|  0008  | 0.2.7 [![P]][M] | 1.2.0 | 1.0.8  | 2021y-04m-05d | 04:41:30 |  
|  0007  | 0.2.7 [![P]][M] | 1.1.9 | 1.0.7  | 2021y-04m-04d | 07:05:55 |  
|  0006  | 0.2.7 [![P]][M] | 1.1.3 | 1.0.6  | 2021y-03m-30d | 03:40:56 |  
|  0005  | 0.2.7 [![P]][M] | 1.0.8 | 1.0.5  | 2021y-03m-23d | 23:55:08 |  
|  0004  | 0.2.7 [![P]][M] | 1.0.6 | 1.0.4  | 2021y-03m-21d | 17:51:39 |  
|  0003  | 0.2.7 [![P]][M] | 1.0.5 | 1.0.3  | 2021y-03m-20d | 19:45:37 |  
|  0002  | 0.2.7 [![P]][M] | 1.0.4 | 1.0.2  | 2021y-03m-20d | 05:35:17 |  
|  0001  | 0.2.7 [![P]][M] | 1.0.3 | 1.0.1  | 2021y-03m-19d | 23:13:45 |  
|  0000  | 0.2.7 [![P]][M] | 1.0.1 | 1.0.0  | 2021y-03m-18d | 23:45:05 |  

