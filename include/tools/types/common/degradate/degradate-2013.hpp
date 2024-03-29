// [2021y-04m-06d][16:24:22] Idrisov Denis R. 100
// [2021y-04m-10d][07:18:11] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_DEGRADATE_2013_USED_ 
#define dTOOLS_DEGRADATE_2013_USED_ 101,2013

#include <type_traits>

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

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DEGRADATE_2013_USED_
