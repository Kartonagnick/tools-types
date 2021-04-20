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


Текущая версия types 1.2.7 [![P]][M]  
------
1. [assert][01]  
2. [dFUNCTION][02]  
3. [features][03]  
4. [type_traits][04]  
5. types  
    5.1. [types.hpp][51]  
    5.2. [version.hpp][52]  
    5.3. traits.hpp  
    5.4. [common.hpp][54]  
    5.6. [variadic.hpp][56] ......... [new][56-NEW][![V]][56-NEW]  [old][56-OLD][![V]][56-OLD]  
    5.7. [void_t.hpp][57] ........... [![D]][57]  
    5.8. [fixed.hpp][58] ............ [c++11][58-11][![V]][58-11]  [c++98][58-98][![V]][58-11]  
    5.9. [limit.hpp][59]  
    5.10. [demangle.hpp][510]  
6. [macro][06]  
    6.1. [overload-5.hpp][61]  
    6.2. [make_version.hpp][62]  
7. [pragma][07]  
    7.1. [pragma.hpp][71]  
    7.2. [confbuild.hpp][72]  
    7.3. [view_build.hpp][73]  
    7.4. [warning.hpp][74]  


[01]: cpp/assert.md           "улучшенный assert"  
[02]: cpp/dfunction.md        "макрос dFUNCTION раскрывается в текст, хранящий имя и сигнатуру функции, где он был использован"  
[03]: cpp/features.md         "здесь выявляются возможности компилятора"  
[04]: cpp/type_traits.md      "подключает type_traits"  

[51]: ../include/tools/types/types.hpp    "версия модуля"  
[52]: ../include/tools/types/version.hpp  "версия модуля"  

[54]: cpp/types/common.md     "сборник мета-алгоритмов общего назначения"  

[56]: cpp/types/variadic.md   "решение проблемы провалов в шаблоно-конструкторы"  
[56-OLD]: cpp/types/variadic/variadic-old.md   "решение проблемы провалов в шаблоно-конструкторы"  
[56-NEW]: cpp/types/variadic/variadic-new.md   "решение проблемы провалов в шаблоно-конструкторы"  


[57]: cpp/types/void_t.md     "идиома std::void_t: sfinae-конструкция"  

[58]: cpp/types/fixed.md      "типы фиксированного размера"  
[58-98]: cpp/types/fixed/fixed-cpp98.md  "типы фиксированного размера: для старых компилторов, которые не поддерживают с++11"  
[58-11]: cpp/types/fixed/fixed-cpp11.md  "типы фиксированного размера: для компилторов в с поддержкой с++11"  

[59]: cpp/types/limit.md      "определяет макс/мин значения различных целочисленных типов"  
[510]: cpp/types/demangle.md  "преобразует результат typeid(T).name() в человеко-читабельный вид"  

[06]: cpp/macro.md                  "магия препроцессора"  
[61]: cpp/macro/kit-5.md/#overload  "перегрузка макросов"  
[62]: cpp/macro/make_version.md     "версия продукта"  

[07]: cpp/pragma.md                 "работа с прагмами"  
[71]: cpp/pragma.md/#pragma_        "служебные подавляторы предупреждений для библиотки tools"
[72]: cpp/pragma.md/#confbuild      "определяет дефайны препроцессора, связанные с конфигурацией сборки"
[73]: cpp/pragma.md/#view_build     "печатает в лог компиляции название, версию, и конфигурации цели сборки"
[74]: cpp/pragma.md/#warning        "кросс-платформенный подавлятор предупреждений"




