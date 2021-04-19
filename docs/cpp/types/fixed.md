
[P]: ../../icons/progress.png
[V]: ../../icons/success.png
[X]: ../../icons/failed.png
[D]: ../../icons/danger.png
[E]: ../../icons/empty.png
[N]: ../../icons/na.png

[M]: #main  "типы фиксированного размера"  
[OLD]: fixed/fixed-cpp98.md "заголовок <cstdint> недоступен. используется enum"  
[NEW]: fixed/fixed-cpp11.md "заголовок <cstdint> доступен. используется constexpr"

version 1.0.3 [![P]][M]
---

[c++11][NEW][![V]][NEW]  
[c++98][OLD][![V]][OLD]  

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
| msvc    | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
| mingw   | [![V]][M] | [![V]][M] | [![V]][M] |  

Старые компиляторы не поддерживают `<cstdint>`, поэтому фиксированные типы им не доступны.  
Данный модуль исправляет эту ситуацию:  
  - предоставляет [набор алисов](#cstdint)  
    - для типов фиксиронного размера  
  - предоставляет [набор макросов](#macro)  
    - для указания диапазонов верхних/нижних границ  
  - предоставляет утилиту [map_signed](#map_signed)  
    - для определения лимита знаковых типов.  
  - предоставляет утилиту [map_unsigned](#map_unsigned)  
    - для определения лимита беззнаковых типов.  

## cstdint
Если компилятору доступен стандартный заголовок `<cstdint>`, 
то используются его значения:  

```
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

В противном случае используются собственные реализации типов:  

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

## macro
Если доступен `<cstdint>`, то используются стандартные макросы.  
Иначе используются самодельные аналогичные макросы:  

```
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

## map_signed
Связь между знаковым типом и его размером:  

```
namespace tools
{
    template<size_t Size> struct map_signed;
    template<> struct map_signed<1>;
    template<> struct map_signed<2>;
    template<> struct map_signed<4>;
    template<> struct map_signed<8>;
}
```

Пример использования:

```
std::cout << map_signed<4>::max_value << '\n';
std::cout << map_signed<4>::min_value << '\n';
```

## map_unsigned
Для беззнаковых:  

```
namespace tools
{
    template<size_t Size> struct map_unsigned;
    template<> struct map_unsigned<1>;
    template<> struct map_unsigned<2>;
    template<> struct map_unsigned<4>;
    template<> struct map_unsigned<8>;
}
```

Пример использования:

```
std::cout << map_unsigned<4u>::max_value << '\n';
std::cout << map_unsigned<4u>::min_value << '\n';
```

## Особенности

Основной упор делается:  
  - по возможности используется стандартный `<cstdint>`  
  - по возможности используется constexpr.  


Модуль представлен двумя реализациями:  
  - [fixed-cpp98][OLD] - для старых компиляторов.  
    - вместо constexpr используется enum. заголовок `<cstdint>` недоступен  
  - [fixed-cpp11][NEW] - для новых компиляторов.  
    - использует `<cstdint>` и constexpr.  

История изменений 
------

| **ID** |      tools      | types           | версия |     дата      |  время   |  
|:------:|:---------------:|:---------------:|:------:|:-------------:|:--------:|  
|  0003  | 0.2.7 [![P]][M] | 1.2.7 [![P]][M] | 1.0.3  | 2021y-04m-19d | 16:42:39 |  
|  0002  | 0.2.7 [![P]][M] | 1.1.9           | 1.0.2  | 2021y-04m-04d | 07:05:55 |  
|  0001  | 0.2.7 [![P]][M] | 1.0.7           | 1.0.0  | 2021y-03m-22d | 11:07:57 |  
|  0000  | 0.2.7 [![P]][M] | 1.0.1           | 1.0.0  | 2021y-03m-18d | 23:45:05 |  



