// [2021y-04m-08d][03:04:34] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_CONST_DATA_2012_USED_ 
#define dTOOLS_IS_CONST_DATA_2012_USED_ 100,2012

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_volatile_data =========================================================
namespace tools
{
    namespace detail
    {
        template<class t> class is_const_data_
        {
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type
                x;
            typedef ::std::remove_pointer<x> 
                no_ptr;
            typedef typename no_ptr::type
                z;
            typedef ::std::is_const<z>
                v;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    template<class t> struct is_const_data
        : dDETAIL_CONSTANT(is_const_data_<t>)
    {};

    #define dif_const_data(t, r)                 \
        typename ::std::enable_if<               \
            ::tools::is_const_data<t>::value, r  \
        >::type

    #define dif_not_const_data(t, r)             \
        typename ::std::enable_if<               \
            !::tools::is_const_data<t>::value, r \
        >::type

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_CONST_DATA_2012_USED_
