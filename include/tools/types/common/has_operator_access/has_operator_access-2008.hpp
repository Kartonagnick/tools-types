// [2021y-04m-13d][21:20:30] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_HAS_OPERATOR_ACCCESS_2008_USED_ 
#define dTOOLS_HAS_OPERATOR_ACCCESS_2008_USED_ 100,2008

#include <tools/type_traits.hpp>

//==============================================================================
//=== has_operaror_access ======================================================
namespace tools
{
    namespace detail
    {
        template<class t, bool> 
        struct has_operator_access_impl_
        {
            typedef dTRAIT::remove_cv<t>
                no_cv;
            typedef typename no_cv::type 
                x;

            __if_exists(x::operator[])
            {
                enum { value = true };
            }

            __if_not_exists(x::operator[]) 
            {
                enum { value = false };
            }
        };

        template <class t> 
        struct has_operator_access_impl_<t, false>
        {
            typedef dTRAIT::is_array<t>
                check;
            enum { value = check::value };
        };

        template <class t> struct has_operator_access_
        {
            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef dTRAIT::remove_cv<no_ref>
                no_cv;
            typedef typename no_cv::type 
                x;
            enum { ok = dTRAIT::is_class<x>::value };
            typedef ::tools::detail::has_operator_access_impl_<x, ok> 
                v;
            enum { value = v::value };
        };

    } // namespace detail

    template<class t> class has_operator_access
        : dDETAIL_CONSTANT(has_operator_access_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_HAS_OPERATOR_ACCCESS_2008_USED_
