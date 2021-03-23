
[![logo](table.png)](../home.md "for developers") 

[P]: ../icons/progress.png
[V]: ../icons/success.png
[X]: ../icons/failed.png
[D]: ../icons/danger.png
[E]: ../icons/empty.png
[N]: ../icons/na.png

Tools`s version 0.2.7  [![P]][M]
---

Корреляции  
---

| **ID** | **элементы**    |      include guard      | где используется            | оригинальное расположение    |  
|:------:|:---------------:|:-----------------------:|:---------------------------:|:----------------------------:|  
|  0006  | [remove_cv][e0] | dTOOLS_REMOVE_CV_USED_  | [tools/types/fixed.hpp][u0] | [tools/types/traits.hpp][p0] |  
|  0007  | [is_signed][e1] | dTOOLS_IS_SIGNED_USED_  | [tools/types/fixed.hpp][u0] | [tools/types/traits.hpp][p0] |  

[p0]: ../../include/tools/types/traits.hpp   "расположение файла"  
[u0]: ../../include/tools/types/fixed.hpp    "расположение копии"  

[e0]: ../code/types/traits.md    "мета-функция: удаляет квалификаторы типов"  
[e1]: ../code/types/traits.md    "мета-функция: определяет: является ли тип знаковым"  

<br/>

Разделы
---

| **ID** | разделы         |  tools    | версия    | mingw 830, 720 710  | msvc 2019, 2017, 2015 | msvc 2013, 2012, 2010, 2008 |  
|:------:|:---------------:|:---------:|:---------:|:-------------------:|:---------------------:|:---------------------------:|  
|  0001  | [features][01]  | 0.0.1     | 1.1.3     |    [![V]][MINGW]    |    [![V]][VS-NEW]     | [![V]][VS-OLD]              |  
|  0003  | [types][19]     | 0.1.8     | 1.0.7     |    [![V]][MINGW]    |    [![V]][VS-NEW]     | [![D]][VS-OLD]              |  

<br/>

Модули  
---

| **ID** | модули          | tools | версия | mingw 830, 720 710  | msvc 2019, 2017, 2015 | msvc 2013, 2012, 2010, 2008 |  
|:------:|:---------------:|:-----:|:------:|:-------------------:|:---------------------:|:---------------------------:|  
|  0000  | [assert][00]    | 0.0.1 | 1.0.1  |    [![V]][MINGW]    |    [![V]][VS-NEW]     | [![V]][VS-OLD]              |  
|  0001  | [features][01]  | 0.0.1 | 1.1.3  |    [![V]][MINGW]    |    [![V]][VS-NEW]     | [![V]][VS-OLD]              |  
|  0007  | [dFUNCTION][07] | 0.0.6 | 1.0.0  |    [![V]][MINGW]    |    [![V]][VS-NEW]     | [![V]][VS-OLD]              |  
|  0018  | [macro][18]     | 0.1.7 | 1.0.0  |    [![V]][MINGW]    |    [![V]][VS-NEW]     | [![V]][VS-OLD]              |  
|  0019  | [types][19]     | 0.1.8 | 1.0.8  |    [![V]][MINGW]    |    [![V]][VS-NEW]     | [![D]][VS-OLD]              |  

<br/>

[M]: #table                   "проект tools"  
[0]: #mingw-new.md            "поддержка компиляторов mingw"  
						      
[MINGW]:  #mingw-new.md       "поддержка компиляторов mingw"  
[VS-NEW]: #msvc-new.md        "поддержка новых компиляторов msvc"  
[VS-OLD]: #msvc-old.md        "поддержка старых компиляторов msvc"  

[00]: ../code/assert.md       "подключает assert только в дебаге"  
[01]: ../code/features.md     "определяет технические возможности компилятора"  
[07]: ../code/dfunction.md    "макрос раскрывается в текстовое имя функции"  
[18]: ../code/macro.md        "магия препроцессора (макросы с переменным количеством аргументом)"  
[19]: ../code/types.md        "tools/types метафункции, и обработка типов"  

1) [История](../history.md)  


