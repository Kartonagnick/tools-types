
[P]: ../icons/progress.png
[V]: ../icons/success.png
[X]: ../icons/failed.png
[D]: ../icons/danger.png
[E]: ../icons/empty.png
[N]: ../icons/na.png

version 1.0.0
---

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
| msvc    | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
| mingw   | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]: #dFUNCTION  "макрос dFUNCTION"  

dFUNCTION
------
Макрос раскрывается в объявление функции, внутри которой он был вызван.  

```cpp
void example()
{
    std::cout << dFUNCTION << '\n';
}
```

Возможная реализация:  

```cpp
#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW__)
    #define dFUNCTION __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
    #define dFUNCTION __FUNCSIG__
#else
    #define dFUNCTION __FUNCTION__
#endif
```

