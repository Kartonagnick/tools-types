// [2021y-04m-06d][20:55:40] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_VOLATILE_DATA_2008_USED_ 
#define dTOOLS_IS_VOLATILE_DATA_2008_USED_ 100,2008

#include <tools/types/traits.hpp>

//==============================================================================
//=== is_volatile_data =========================================================
namespace tools
{
    namespace detail
    {
        template<class t> class is_volatile_data_
        {
            typedef dTRAIT::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type 
                x;
            typedef dTRAIT::remove_pointer<x> 
                no_ptr;
            typedef typename no_ptr::type 
                z;
            typedef dTRAIT::is_volatile<z>
                v;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    template<class t> struct is_volatile_data
        : dDETAIL_CONSTANT(is_volatile_data_<t>)
    {};

    #define dif_volatile_data(t, r)                 \
        typename dTRAIT::enable_if<                 \
            ::tools::is_volatile_data<t>::value, r  \
        >::type

    #define dif_not_volatile_data(t, r)             \
        typename dTRAIT::enable_if<                 \
            !::tools::is_volatile_data<t>::value, r \
        >::type

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_VOLATILE_DATA_2008_USED_
