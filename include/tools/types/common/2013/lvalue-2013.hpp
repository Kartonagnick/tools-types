// [2021y-04m-06d][16:29:40] Idrisov Denis R. 100
// [2021y-04m-10d][03:37:41] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_FOR_LVALUE_USED_ 
#define dTOOLS_FOR_LVALUE_USED_ 101,2013

#include <type_traits>

//==============================================================================
//==============================================================================

namespace tools
{
    #define dfor_lvalue(t) ::tools::for_lvalue_t<t>* = nullptr
    template<class t, class ret = void> 
        using for_lvalue_t
            = ::std::enable_if_t<
                ::std::is_lvalue_reference<t>::value,
                ret
            >;

    #define dfor_not_lvalue(t) ::tools::for_not_lvalue_t<t>* = nullptr
    template<class t, class ret = void> 
        using for_not_lvalue_t
            = ::std::enable_if_t<
                ! ::std::is_lvalue_reference<t>::value,
                ret
            >;

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_FOR_LVALUE_USED_
