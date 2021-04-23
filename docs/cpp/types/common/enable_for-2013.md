
[S]: ../../../icons/star-down.png
[P]: ../../../icons/progress.png
[V]: ../../../icons/success.png
[X]: ../../../icons/failed.png
[D]: ../../../icons/danger.png
[E]: ../../../icons/empty.png
[N]: ../../../icons/na.png

| **ID**  | 2019      | 20017     | 2015      | 2013      | 2012      | 2010      | 2008      |  
|:-------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|  
|  msvc   | [![V]][M] | [![V]][M] | [![V]][M] | [![V]][M] | [![N]][M] | [![N]][M] | [![N]][M] |  

| **ID**  | 810       | 720       | 710       |  
|:-------:|:---------:|:---------:|:---------:|  
|  mingw  | [![V]][M] | [![V]][M] | [![V]][M] |  

[M]:       #enable_for    "инстанцирование функциий только для аргументов, указанных в списке"  

enable_for-2013, v1.0.1
---
Концепт:  
Разрешает инстанцировать шаблон только для аргументов указанного типа.  

Например, в следующем примере разрешается инстанцировать шаблон 
только для аргументов типа `char` или `wchar_t`  
```
// 't' must be 'char' or 'wchar_t' only
template<class t>
dif_enabled(bool, t, char, wchar_t) 
check_return(const t&) dNOEXCEPT
    { return true; }
```

В этом примере запрещается инстанцировать шаблон для аргументов типа `char` или `wchar_t`  
```
// 't' can not be 'char' and 'wchar_t' 
template<class t>
dif_disabled(bool, t, char, wchar_t) 
сheck_return(const t&) dNOEXCEPT
    { return false; }
```

Каталог:  
  - enable_if_find_t  
  - disable_if_find_t  
  - dif_enabled  
  - dif_disabled  
  - enable_for_t  
  - disable_for_t  
  - dfor_enabled_impl  
  - dfor_disabled_impl  
  - dfor_enabled  
  - dfor_disabled  

История изменений
---
| **ID** | tools           | types | common | версия |     дата      |  время   |  
|:------:|:---------------:|:-----:|:------:|:------:|:-------------:|:--------:|  
|  0000  | 0.2.7 [![P]][M] | 1.2.5 | 1.1.3  | 1.0.0  | 2021y-04m-10d | 07:23:33 |  
