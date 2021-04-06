// [2021y-04m-06d][20:56:12] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_VOLATILE_DATA_2015_USED_ 
#define dTOOLS_IS_VOLATILE_DATA_2015_USED_ 100,2013

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_volatile_data =========================================================
namespace tools
{
    namespace detail
    {
        template<class t> class is_volatile_data_
        {
            using x = ::std::remove_reference_t<t>;
            using z = ::std::remove_pointer_t<x>;
            using v = ::std::is_volatile<z>;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    template<class t> struct is_volatile_data
        : dDETAIL_CONSTANT(is_volatile_data_<t>)
    {};

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_VOLATILE_DATA_2015_USED_
