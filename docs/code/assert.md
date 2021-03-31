
[P]: ../icons/progress.png
[V]: ../icons/success.png
[X]: ../icons/failed.png
[D]: ../icons/danger.png
[E]: ../icons/empty.png
[N]: ../icons/na.png

version 1.0.1 [![P]][0]
---

| **ID** | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
| msvc   | [![V]][0] | [![V]][0] | [![V]][0] | [![V]][0] | [![V]][0] | [![V]][0] | [![V]][0] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
| mingw   | [![V]][0] | [![V]][0] | [![V]][0] |  


[0]: #assert  "макрос dASSERT"  

assert
------

Предназначение:  
Заголовок `<cassert>` подключается только в дебааге.  
В дебаге макрос `dASSERT` вызывает `assert`  
В релизе макрос `dASSERT` сворачивается в пустоту.  

Использование:  

```
bool val = false;
if (!val)
    dASSERT(some<int, int>().compare(1, 1) && "trololo");

```

Возможная реализация:  

```
#ifdef NDEBUG
    #define dASSERT(...) void()
#else
    #include <cassert>
    #define dASSERT(...) assert((__VA_ARGS__))
#endif
```

