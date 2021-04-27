// [2021y-04m-27d][20:51:57] Idrisov Denis R. 100 PRE

#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2015_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2015_USED_ 100 PRE

#include <type_traits>

namespace tools     {
namespace sfinae    {
namespace available {

    template<class, class = void>
    struct dereferencable : ::std::false_type {};
 
    template<class t> struct dereferencable<t,
            ::std::void_t<decltype(*::std::declval<t>())>
        > : ::std::true_type
    {};

} // namespace available
} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_AVAILABLE_2015_USED_
