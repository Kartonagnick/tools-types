
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


fixed-cpp11
---
Реализация для компиляторов, которые поддерживают с++11  
Использует стандартный `<cstdint>`  

```cpp
namespace tools
{
    using ::std::uint8_t ;
    using ::std::uint16_t;
    using ::std::uint32_t;
    using ::std::uint64_t;
        
    using ::std::int8_t  ; 
    using ::std::int16_t ; 
    using ::std::int32_t ; 
    using ::std::int64_t ; 
}
```

Используются стандартные макросы, определенные в `<cstdint>`  
```cpp
#define INT8_MIN   /* значение определено в cstdint */
#define INT16_MIN  /* значение определено в cstdint */
#define INT32_MIN  /* значение определено в cstdint */
#define INT64_MIN  /* значение определено в cstdint */
                   
#define INT8_MAX   /* значение определено в cstdint */
#define INT16_MAX  /* значение определено в cstdint */
#define INT32_MAX  /* значение определено в cstdint */
#define INT64_MAX  /* значение определено в cstdint */
                   
#define UINT8_MAX  /* значение определено в cstdint */
#define UINT16_MAX /* значение определено в cstdint */
#define UINT32_MAX /* значение определено в cstdint */
#define UINT64_MAX /* значение определено в cstdint */
```

Используется `constexpr`

```cpp
namespace tools
{
    template<size_t Size> struct map_signed;
    
    template<> struct map_signed<1>
    {
        typedef ::tools::int8_t type; 
        static constexpr type min_value = INT8_MIN;
        static constexpr type max_value = INT8_MAX;
    };

    ...

} // namespace tools
```


История изменений 
------

| **ID** | tools | types | версия |     дата      |  время   |  
|:------:|:-----:|:-----:|:------:|:-------------:|:--------:|  
|  0000  | 0.1.9 | 1.0.0 | 1.0.0  | 2021y-03m-11d | 23:18:42 |  



