// [2021y-04m-13d][01:53:52] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_HAS_END_2008_USED_ 
#define dTOOLS_HAS_END_2008_USED_ 100,2008

#include <tools/type_traits.hpp>

//==============================================================================
//=== has_operaror_access ======================================================
namespace tools
{
    namespace detail
    {
        template<class t, bool> 
        struct has_end_impl_
        {
            __if_exists(t::end)
            {
                enum { value = true };
            }

            __if_not_exists(t::end) 
            {
                enum { value = false };
            }
        };

        template <class t> 
        struct has_end_impl_<t, false>
        {
            enum { value = false };
        };

        template <class t> struct has_end_
        {
            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                z;
            typedef dTRAIT::remove_cv<z>
                no_cv;
            typedef typename no_cv::type 
                x;
            enum { ok = dTRAIT::is_class<x>::value };
            typedef ::tools::detail::has_end_impl_<x, ok> 
                v;
            enum { value = v::value };
        };

    } // namespace detail

    template<class t> class has_end
        : dDETAIL_CONSTANT(has_end_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_HAS_END_2008_USED_
