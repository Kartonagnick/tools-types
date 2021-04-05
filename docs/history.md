Основан
-------
20 февраля 2021 15:19:37, Картонажником.  
[2021y-02m-20d][15:19:37] Idrisov Denis R.  
[2021y-02m-20d][15:19:37] birthday of the project  


**История изменений**  

**Версия 1.2.0 (предварительная)**  
----------------------------------
[2021y-04m-05d][04:41:30] #43_array

1) обновлен: version                    120
2) обновлен: types                      120

3) добавляем: common/array              100
    - миграция из types/common

3) обновлен: common                     108

**Версия 1.1.9 (предварительная)**  
----------------------------------
[2021y-04m-04d][07:05:55] #41_stage

1) обновлен: version                    119
2) обновлен: types                      119

3) добавлен tools/type_traits.hpp       100

4) type_of_enum                         100
     - переехал из traits в common

5) улучшение common                     107
     - фикс бага: add_const_data        101

6) исправление features:                118
     - фикс бага: dHAS_TYPE_TRAITS
     - фикс бага: dTRAIT

7) исправление fixed:                   102
     - фикс бага: limit                 002


**Версия 1.1.8 (предварительная)**  
----------------------------------
[2021y-04m-03d][23:09:37] #39_traits_4

1) обновлен: version                    118
2) обновлен: types                      118

3) обновление features                  017
     - добавлен: dDETAIL_CONSTANT

4) обновление types/traits              011
     - улучшение: is_class             002
     - улучшение: is_function          002
     - улучшение: remove_reference     002
     - фикс бага: remove_pointer       002
     - фикс бага: add_pointer          002
     - фикс бага: is_pointer           002
     - фикс бага: is_reference         002
     - фикс бага: is_const             002
     - фикс бага: is_volatile          002
                                      
5) обновлены тесты: test-200-types
     - тесты: is_class
     - тесты: is_pointer
     - тесты: is_reference
     - тесты: is_const
     - тесты: is_volatile
     - тесты: is_function
     - тесты: remove_reference
     - тесты: remove_pointer
     - тесты: remove_extent
     - тесты: remove_all_extent
     - тесты: add_pointer
     - тесты: decay

**Версия 1.1.7 (предварительная)**  
----------------------------------
[2021y-04m-03d][00:12:30] #35_traits_3

1) обновлен: version                    117
2) обновлен: types                      117

3) обновление types/traits              010
     - фикс бага: is_integral         002
     - фикс бага: is_signed           002
     - фикс бага: remove_cv           002
     - улучшение: is_same             002
     - улучшение: is_floating_point   002
                                      
4) обновлены тесты: test-200-types
     - тесты: is_foating
     - тесты: is_integral
     - тесты: is_unsigned
     - тесты: is_signed
     - тесты: remove_cv

**Версия 1.1.6 (предварительная)**  
----------------------------------
[2021y-04m-02d][00:41:19] #35_traits_2

1) обновлен: version                    116
2) обновлен: types                      116

3) обновление tools/features            116
     - добавлен: dSTATIC_CHECK
     - добавлен: dHAS_ARRAY_EMPTY_SIZE

4) обновление types/traits              009
     - исправление бага: is_array   002

5) обновлены тесты: test-000-platform
     - тесты: array_empty_size
     - тесты: static_assert

6) обновлены тесты: test-200-types
     - тесты: is_array
     - тесты: is_same

**Версия 1.1.5 (предварительная)**  
----------------------------------
[2021y-03m-31d][22:25:27] #33_assert
1) обновлен: version                    115
2) обновлен: types                      115
4) исправлен баг:
     - assert.hpp                       101
5) добавлен: test-600-others
     - тесты: tools/assert.hpp

**Версия 1.1.4 (предварительная)**  
----------------------------------
[2021y-03m-31d][01:54:22] #31_static_assert
1) обновлен: version                    114
2) обновлен: types                      114
3) изменение: features                  115
     - улучшен: dSTATIC_ASSERT 
4) рефакторинг юнит-тестов:
     - для работы с новым dSTATIC_ASSERT

**Версия 1.1.3 (предварительная)**  
----------------------------------
[2021y-03m-30d][03:40:56] #29_add_const_data
1) обновлен: version                    113
2) обновлен: types                      113
4) обновлен: common                     106
     - common-msvc2008.hpp  100,2008
       - add_const_data     100,2008
     - common-msvc2013.hpp  100,2013
       - add_const_data     100,2013
     - common-msvc2015.hpp  100,2015
       - add_const_data     100,2013
5) обновлен: traits                     008
     - исправлен баг:
       - remove_pointer                 002

6) изменение: features                  114
     - изменение:
       - dTRAIT теперь доступен с msvc2012

**Версия 1.1.2 (предварительная)**  
----------------------------------
[2021y-03m-27d][23:59:59] #27_demangle
1) обновлен: version                    112
2) обновлен: types                      112
3) добавлен: damangle                   001


**Версия 1.1.1 (предварительная)**  
----------------------------------
[2021y-03m-26d][08:26:36] #25_traits
1) обновлен: version                    111
2) обновлен: types                      111
3) обновлен: variadic                   002
     - поддержка всех компиляторов
     - dTEMPLATE_CONSTRUCT
     - dTEMPLATE_CONSTRUCT_IMPL
     - dTEMPLATE_CONSTRUCT_ARG

4) обновлен: traits                     007
     - исправлен: decay             002
     - добавлен: is_function        001
     - добавлен: is_array           001
     - добавлен: remove_extent      001
     - добавлен: remove_all_extent  001
     - добавлен: add_pointer        001
     - добавлен: is_base_of         001


**Версия 1.1.0 (предварительная)**  
----------------------------------
[2021y-03m-25d][21:31:43] #23_variadic
1) обновлен: version                    110
2) обновлен: types                      110
3) добавлен: variadic                   001
     - dTEMPLATE_CONSTRUCT:


**Версия 1.0.9 (предварительная)**  
----------------------------------
[2021y-03m-24d][21:31:43] #21_is_pointer
1) обновлен: version                    109
2) обновлен: types                      109
3) обновлен: traits                     006
     - добавлено:
       - is_pointer              001
       - is_reference            001


**Версия 1.0.8 (предварительная)**  
----------------------------------
[2021y-03m-23d][23:55:08] #19_is_volatile_data
1) обновлен: version                    108
2) обновлен: types                      108
4) обновлен: common                     105
     - common-msvc2008.hpp
       - is_volatile_data   100,2008
     - common-msvc2013.hpp  100,2013
       - is_volatile_data   100,2008
     - common-msvc2015.hpp  100,2015
       - is_volatile_data   100,2008

5) обновлен: traits                     005
     - is_const              001
     - is_volatile           001

6) исправление бага:
     - traits/remove_reference   002

**Версия 1.0.7 (предварительная)**  
----------------------------------
[2021y-03m-22d][11:07:57] #17_version
1) обновлен: version                    107
2) обновлен: types                      107
3) добавлен: macro:
    - overload-5.hpp                    001
    - make_version.hpp                  100
4) обновлен: common                     104
     - обновлен формат версии:
       - common-msvc2008.hpp  100,2008
       - common-msvc2013.hpp  100,2013
       - common-msvc2015.hpp  100,2015
5) обновлен: fixed                      100
     - обновлен формат версии:
       - fixed-cpp98.hpp      100,1998
       - fixed-cpp11.hpp      100,2011
6) обновлен: pragma/confbuild.hpp       101
7) обновлен: view_build.hpp             101


**Версия 1.0.6 (предварительная)**  
----------------------------------
[2021y-03m-21d][17:51:39] #15_is_dereferencable
1) обновлен: version                    106
2) обновлен: types                      106
3) обновлен: common                     104
     - добавлен: is_dereferencable      100


**Версия 1.0.5 (предварительная)**  
----------------------------------
[2021y-03m-20d][19:45:37] #13_array
1) обновлен: version                    105
2) обновлен: types                      105
3) обновлен: common                     103
     - добавлен: is_zero_array          100
     - добавлен: size_array             100
     - добавлен: small_array            100
4) обновлен: features                   113
     - добавлен: dTRAIT


**Версия 1.0.4 (предварительная)**  
----------------------------------
[2021y-03m-20d][05:35:17] #11_is_functor
1) обновлен: version                    104
2) обновлен: types                      104
3) обновлен: common                     102
     - добавлен: is_functor             100
4) обновлен: features                   112
     - добавлен: dHAS_DECLTYPE
     - добавлен: dHAS_LAMBDA
5) обновлен: traits                     004
     - добавлен: is_class               1


**Версия 1.0.3 (предварительная)**  
----------------------------------
[2021y-03m-19d][23:13:45] #9_find_type
1) обновлен: version                   103
2) обновлен: types                     103
3) обновлен: features                  111
     - добавлен: dHAS_ABOMINABLE
4) обновлен: traits                    003
     - добавлен: integral_constant     001
5) обновлен: common                    101
     - добавлен: common-msvc2008       101
         - добавлен: find_type         100
     - обновлен: common-msvc2013       101
         - добавлен: find_type         100
     - обновлен: common-msvc2015       101
         - добавлен: find_type         100


**Версия 1.0.2 (предварительная)**  
----------------------------------
[2021y-03m-19d][23:01:17] #7_version
1) обновлен: types            102
2) добавлен: version          102
3) добавлен: view_build       100
4) добавлен: pragma/confbuild 100


**Версия 1.0.1 (предварительная)**  
----------------------------------
[2021-03m-18d][23:45:05] #5_reorganozation
1) обновлен: features 110
    - добавлен: dHAS_NULLPTR
    - добавлен: dHAS_TYPE_TRAITS
    - добавлен: dHAS_HASH
    - добавлен: dSTATIC_ASSERT
    - добавлен: dHAS_CSTDINT
    - добавлен: dHAS_ENUM_CLASS
    - добавлен: dHAS_EMPLACE
    - добавлен: dHAS_CHRONO
    - добавлен: dHAS_ATOMIC
    - добавлен: dCONSTANT
    - добавлен: dHAS_AGGREGATE_INITIALIZE
    - добавлен: dHAS_VARIADIC_TEMPLATE
    - добавлен: dTHREAD_LOCAL_EXTENSION
    - добавлен: dHAS_THREAD_LOCAL
    - добавлен: dHAS_ZERO_SIZE_ARRAY
2) обновлен: confbuild                101
3) обновлен: docs
    - обновлен: docs/icons
    - обновлен: docs/adm
    - обновлен: docs/code
    - обновлен: docs/table
    - обновлен: docs/test
4) добавлен: pragma                    100
5) добавлен: types                     101
    - добавлен: traits                 002
      - добавлен: decay                1
      - добавлен: is_same              1
      - добавлен: remove_cv            1
      - добавлен: remove_reference     1
      - добавлен: is_signed            1
      - добавлен: is_floating          1
      - добавлен: is_integral          1
      - добавлен: conditional          1 
      - добавлен: enable_if            1
      - добавлен: type_of_enum         1
    - добавлен: common                 100
      - добавлен: common-msvc2013      100
        - добавлен: degradate          100
        - добавлен: dfor_lvalue        100
      - добавлен: common-msvc2015      100
        - добавлен: degradate          100
        - добавлен: dfor_lvalue        100
        - добавлен: dfor_rvalue        100
    - добавлен: fixed                  100
      - добавлен: fixed-cpp98          100
      - добавлен: fixed-cpp11          100


**Версия 0.0.1 (предварительная)**  
----------------------------------
[2021y-02m-20d][16:13:00] #3_sources
1) добавлен: deploy
2) добавлен: features 101
     - добавлен: dMESSAGE
     - добавлен: dHAS_CPP11
     - добавлен: dHAS_CPP14
     - добавлен: dHAS_CPP17	 
     - добавлен: dHAS_CONSTEXPR_CPP11
     - добавлен: dHAS_CONSTEXPR_CPP14
     - добавлен: dCONSTEXPR_CPP11
     - добавлен: dCONSTEXPR_CPP14
     - добавлен: dHAS_DELETING_FUNCTIONS
     - добавлен: dHAS_TEMPLATE_FUNCTION_DEFAULT_PARAM
     - добавлен: dHAS_DELETING_FUNCTIONS
     - добавлен: dHAS_RVALUE_REFERENCES
     - добавлен: dHAS_RVALUE_ARRAY	 
     - добавлен: dHAS_USING_ALIAS
     - добавлен: dHAS_NOEXCEPT	 
     - добавлен: dNOCOPYABLE
     - добавлен: dNOEXCEPT
     - добавлен: dNODISCARD

3) добавлен: confbuild 001


**Версия 0.0.1 (предварительная)**  
----------------------------------
[2021y-02m-20d][15:19:37] #1_first
1) добавлена: первая задача  
2) добавлен: .gitignore  
3) добавлены: иконки  
  
