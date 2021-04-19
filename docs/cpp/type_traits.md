
[P]: ../icons/progress.png
[V]: ../icons/success.png
[X]: ../icons/failed.png
[D]: ../icons/danger.png
[E]: ../icons/empty.png
[N]: ../icons/na.png

version 1.0.1
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
| msvc    | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
| mingw   | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #dFUNCTION  "макрос dFUNCTION"  

type_traits
------
По возможности использует стандартный: `<type_traits>`, и `std::void_t`  
Для старых компиляторов используется: `<tools/types/traits.hpp>`, и `dTAIT::void_t`  

Возможная реализация:  

```cpp
#include <tools/features.hpp>
#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>
#else
    #include <tools/types/traits.hpp>
#endif

#include <tools/types/void_t.hpp>
```

