// [2021y-04m-06d][20:55:54] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_VOLATILE_DATA_2012_USED_ 
#define dTOOLS_IS_VOLATILE_DATA_2012_USED_ 100,2012

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
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type
                x;
            typedef ::std::remove_pointer<x> 
                no_ptr;
            typedef typename no_ptr::type
                z;
            typedef ::std::is_volatile<z>
                v;
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
#endif // !dTOOLS_IS_VOLATILE_DATA_2012_USED_
