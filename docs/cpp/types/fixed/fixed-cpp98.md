
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

[M]: #main  "типы фиксированного размера"  

version 1.0.0
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
| msvc    | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
| mingw   | [![V]][M] | [![V]][M] | [![V]][M] |  


fixed-cpp98
---
Реализация для компиляторов, которые не поддерживают с++11  
Им не доступен `<cstdint>`, поэтому используется собственная реализация:

```
namespace tools
{
    typedef unsigned char    uint8_t ;
    typedef unsigned __int16 uint16_t;
    typedef unsigned __int32 uint32_t;
    typedef unsigned __int64 uint64_t;

    typedef signed char      int8_t  ;
    typedef __int16          int16_t ;
    typedef __int32          int32_t ;
    typedef __int64          int64_t ;
}
```

Cтандартные макросы не доступны, поэтому используются свои аналоги:

```cpp
#define INT8_MIN         (-127 - 1)
#define INT16_MIN        (-32767 - 1)
#define INT32_MIN        (-2147483647 - 1)
#define INT64_MIN        (-9223372036854775807 - 1)

#define INT8_MAX         127
#define INT16_MAX        32767
#define INT32_MAX        2147483647
#define INT64_MAX        9223372036854775807

#define UINT8_MAX        0xff
#define UINT16_MAX       0xffff
#define UINT32_MAX       0xffffffff
#define UINT64_MAX       0xffffffffffffffff
```


Квалификатор `constexpr` недоступен, поэтому используется `enum`

```cpp
namespace tools
{
    template<size_t Size> struct map_signed;
    
    template<> struct map_signed<1>
    {
        typedef ::tools::int8_t type; 
        enum
        { 
            min_value = INT8_MIN,
            max_value = INT8_MAX
        };
    };

    ... 

} // namespace tools
```


История изменений 
------

| **ID** | tools | types | версия |     дата      |  время   |  
|:------:|:-----:|:-----:|:------:|:-------------:|:--------:|  
|  0000  | 0.1.9 | 1.0.0 | 1.0.0  | 2021y-03m-11d | 23:18:42 |  



