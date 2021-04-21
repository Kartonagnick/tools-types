// [2021y-04m-12d][02:19:39] Idrisov Denis R. 100
// [2021y-04m-14d][01:45:51] Idrisov Denis R. 100
// [2021y-04m-21d][13:21:17] Idrisov Denis R. 101 PRE
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_IS_ITERABLE_USED_ 
#define dTOOLS_IS_ITERABLE_USED_ 101 PRE

#include <tools/types/sfinae/is_dereferencable.hpp>
#include <tools/types/sfinae/is_incrementable.hpp>

//==============================================================================
//==============================================================================

namespace tools
{
    namespace detail
    {
        template<class t>  struct is_iterable_
        {
            enum { d = ::tools::is_dereferencable<t>::value };
            enum { i = ::tools::is_incrementable<t>::value  };
        public:
            is_iterable_();
            enum { value  = d && i };
        };

    } // namespace detail

    template<class t> class is_iterable
        : dDETAIL_CONSTANT(is_iterable_<t>)
    {};

} // namespace tools 
//==============================================================================
//==============================================================================

#endif // !dTOOLS_IS_ITERABLE_USED_
