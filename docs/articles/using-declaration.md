
Кратко:
------
Баг msvc2015  


Описание проблемы:
------            
Следующий код успешно компилируется при помощи mingw, или студийными компиляторами начиная с msvc2017:  

```cpp
#include <type_traits>

namespace util
{
    using ::std::void_t;
}

int main()
{
    util::void_t<int>* p = 0;
    (void)p;
}
```

Но не компилируется в msvc2015:
```
error C2039: 'void_t<int>': is not a member of 'util'
```

## Лекарство
Для msvc2015 придётся ввести дополнительный алиас:  

```
#include <type_traits>
 
#if defined(_MSC_VER) && _MSC_VER == 1900
    // workaround for msvc2015
    namespace util
    {
        template<class... args>
        using void_t = ::std::void_t<args...>;
    }
#else
    // modern compiler (msvc2017 or newer)
    namespace util
    {
        using ::std::void_t;
    }
#endif
 
int main()
{
    util::void_t<int>* p = 0;
    (void)p;
}
```
