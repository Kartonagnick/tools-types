// [2021y-04m-06d][16:24:22] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_DEGRADATE_USED_ 
#define dTOOLS_DEGRADATE_USED_ 100,2013

#include <type_traits>

namespace tools 
{
    template<class t> 
    using degradate = ::std::remove_cv_t<
        ::std::remove_reference_t<t> 
    >;

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMMON_USED_
