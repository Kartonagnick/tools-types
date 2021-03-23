
| дата начала         |   дата конца        | длительность   | исполнитель  |
|:-------------------:|:-------------------:|:--------------:|:------------:|
| 2020y-03m-23d 22:15 | 2020y-03m-23d 23:45 | 1 hour, 30 min | Kartonagnick |

is_volatile_data
---

синопсис:

```
//==============================================================================
//=== is_volatile_data =========================================================
#ifndef dTOOLS_IS_VOLATILE_DATA_USED_ 
#define dTOOLS_IS_VOLATILE_DATA_USED_
namespace tools
{
    namespace detail
    {
        template<class t> struct is_volatile_data
        {
        private:
            using x = ::std::remove_reference_t<t>;
            using z = ::std::remove_pointer_t<x>;
        public:
            enum { value = ::std::is_volatile<z>::value };
        };

    } // namespace detail

    template<class t> struct is_volatile_data
        : dDETAIL_CONSTANT(is_volatile_data<t>)
    {};

} // namespace tools
#endif // !dTOOLS_IS_VOLATILE_DATA_USED_
```

Метафункция вернет true, если аргумент ссылается на `volatile` данные.

План:  
  - [ ] добавляем `is_volatile_data` во все версии common
  - [ ] проверяем сборку на всех компиляторах  
  - [ ] заполняем историю  
  - [ ] обновляем таблицу  



