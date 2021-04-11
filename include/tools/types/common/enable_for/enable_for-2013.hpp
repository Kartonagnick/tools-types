// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-04m-10d][01:40:31] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_ENABLE_FOR_2013_USED_ 
#define dTOOLS_ENABLE_FOR_2013_USED_ 100,2013

#include <tools/types/common/find_type.hpp>

//==============================================================================
//=== degradate-2013 ===========================================================
#ifndef dTOOLS_DEGRADATE_USED_ 
namespace tools 
{
    template<class t> class degradate
    {
        using x = ::std::remove_reference_t<t>;
    public:
        using type = ::std::remove_cv_t<x>;
    };

    template<class t> 
    using degradate_t = ::std::remove_cv_t<
        ::std::remove_reference_t<t> 
    >;

    #define ddegradate(...) degradate_t<__VA_ARGS__>

} // namespace tools 
#endif // !dTOOLS_DEGRADATE_USED_

//==============================================================================
//=== enable_if_find/disable_if_find =============== (degradate)(find_type) ====
namespace tools 
{
    // if type 't' is in the list 'args' --> compile
    template<class ret, class t, class ...args>
    using enable_if_find_t
        = ::std::enable_if_t< 
            ::tools::find_type< 
                ::tools::degradate_t<t>, args...
            >::value, ret  
        >;

    // if type 't' is not in the list 'args' --> compile
    template<class ret, class t, class ...args>
    using disable_if_find_t 
        = ::std::enable_if_t<
            !::tools::find_type< 
                ::tools::degradate_t<t>,  args... 
            >::value, ret
        >;

    #define dif_enabled(r, ...) \
        ::tools::enable_if_find_t<r, __VA_ARGS__>

    #define dif_disabled(r, ...) \
        ::tools::disable_if_find_t<r, __VA_ARGS__>

} // namespace tools 

//==============================================================================
//=== enable_for/disable_for ======================= (degradate)(find_type) ====
namespace tools 
{
    // if type 't' is in the list 'args' --> compile
    template<class t, class ...args>
    using enable_for_t 
        = ::std::enable_if_t< 
            ::tools::find_type< 
                ::tools::degradate_t<t>, args...
            >::value  
        >;

    // if type 't' is not in the list 'args' --> compile
    template<class t, class ...args>
    using disable_for_t 
        = ::std::enable_if_t<
            !::tools::find_type< 
                ::tools::degradate_t<t>,  args... 
            >::value
        >;

    #define dfor_enabled_impl(...)  ::tools::enable_for_t <__VA_ARGS__>*
    #define dfor_disabled_impl(...) ::tools::disable_for_t<__VA_ARGS__>*

    #define dfor_enabled(...)  dfor_enabled_impl(__VA_ARGS__)  = nullptr
    #define dfor_disabled(...) dfor_disabled_impl(__VA_ARGS__) = nullptr

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_ENABLE_FOR_2013_USED_
