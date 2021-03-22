Основан
-------
20 февраля 2021 15:19:37, Картонажником.  
[2021y-02m-20d][15:19:37] Idrisov Denis R.  
[2021y-02m-20d][15:19:37] birthday of the project  


**История изменений**  


**Версия 1.0.7 (предварительная)**  
----------------------------------
[2021y-03m-22d][09:31:20] #17_version
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
  
