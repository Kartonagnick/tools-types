// [2021y-04m-06d][17:41:43] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_IS_LAMBDA_2008_USED_ 
#define dTOOLS_IS_LAMBDA_2008_USED_ 100,2008

#include <tools/type_traits.hpp>

//==============================================================================
//=== is_lambda ===============================================================
namespace tools
{
    namespace detail
    {
        template<class F, bool> struct is_lambda_impl_
        {
            __if_exists(F::operator())
            {
                enum { value = true };
            }

            __if_not_exists(F::operator()) 
            {
                enum { value = false };
            }
        };

        template <class t> struct is_lambda_impl_<t, false>
        {
            enum { value = false };
        };

        template <class t> struct is_lambda_
        {
            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type 
                x;
            enum { ok = dTRAIT::is_class<x>::value };
            typedef ::tools::detail::is_lambda_impl_<x, ok> 
                v;
            enum { value = v::value };
        };

    } // namespace detail

    template<class F> class is_lambda
        : dDETAIL_CONSTANT(is_lambda_<F>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_LAMBDA_2008_USED_
