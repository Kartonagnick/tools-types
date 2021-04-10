// [2021y-04m-06d][20:55:54] Idrisov Denis R.
// [2021y-04m-10d][04:42:17] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_IS_VOLATILE_DATA_2012_USED_ 
#define dTOOLS_IS_VOLATILE_DATA_2012_USED_ 101,2012

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

    #define dif_volatile_data(t, r)                 \
        typename ::std::enable_if<                  \
            ::tools::is_volatile_data<t>::value, r  \
        >::type

    #define dif_not_volatile_data(t, r)             \
        typename ::std::enable_if<                  \
            !::tools::is_volatile_data<t>::value, r \
        >::type

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_VOLATILE_DATA_2012_USED_
