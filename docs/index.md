[![logo](logo.png)](../README.md "for users")  

[P]: icons/progress.png
[V]: icons/success.png
[X]: icons/failed.png
[D]: icons/danger.png
[E]: icons/empty.png
[N]: icons/na.png

[M]: #main "проект tools-types"  
[MINGW]:  #mingw-new.md "поддержка компиляторов mingw"  
[VS-NEW]: #msvc-new.md  "поддержка новых компиляторов msvc"  
[VS-OLD]: #msvc-old.md  "поддержка старых компиляторов msvc"  


Текущая версия types 1.2.6  
------
1. [assert][01]  
2. [dFUNCTION][02]  
3. [features][03]  
4. [type_traits][04]  
5. types  
    5.1. types.hpp  
    5.2. version.hpp  
    5.3. traits.hpp  
    5.4. [common.hpp][51]  
    5.6. variadic.hpp  
    5.7. [void_t.hpp][57]  
    5.8. fixed.hpp  
    5.9. [demangle.hpp][59]  
6. macro  
    6.1. overload-5.hpp  
    6.2. make_version.hpp  
7. pragma  
    7.1. pragma.hpp  
    7.2. confbuild.hpp  
    7.3. view_build.hpp  
    7.4. warning.hpp  


[01]: cpp/assert.md          "улучшенный assert"  
[02]: cpp/dfunction.md       "макрос dFUNCTION раскрывается в текст, хранящий имя и сигнатуру функции, где он был использован"  
[03]: cpp/features.md        "здесь выявляются возможности компилятора"  
[04]: cpp/type_traits.md     "подключает type_traits"  
[51]: cpp/types/common.md    "сборник мета-алгоритмов общего назначения"  
[57]: cpp/types/void_t.md    "идиома std::void_t: sfinae-конструкция"  
[59]: cpp/types/demangle.md  "преобразует результат typeid(T).name() в человеко-читабельный вид"  