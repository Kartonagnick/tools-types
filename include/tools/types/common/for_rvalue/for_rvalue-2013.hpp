// [2021y-04m-06d][16:33:07] Idrisov Denis R. 100
// [2021y-04m-10d][07:20:15] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_FOR_RVALUE_USED_ 
#define dTOOLS_FOR_RVALUE_USED_ 101,2013

#include <type_traits>

//==============================================================================
//==============================================================================

namespace tools
{
    #define dfor_rvalue(t) ::tools::for_rvalue_t<t>* = nullptr
    template<class t, class ret = void> 
        using for_rvalue_t
            = ::std::enable_if_t<
                ::std::is_rvalue_reference<t>::value,
                ret
            >;

    #define dfor_not_rvalue(t) ::tools::for_not_rvalue_t<t>* = nullptr
    template<class t, class ret = void> 
        using for_not_rvalue_t
            = ::std::enable_if_t<
                ! ::std::is_rvalue_reference<t>::value,
                ret
            >;

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_FOR_RVALUE_USED_
