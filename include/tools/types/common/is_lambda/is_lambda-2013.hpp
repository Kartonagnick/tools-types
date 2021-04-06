// [2021y-04m-06d][17:41:43] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_IS_LAMBDA_2013_USED_ 
#define dTOOLS_IS_LAMBDA_2013_USED_ 100,2013

#include <tools/type_traits.hpp>

//==============================================================================
//=== is_lambda ===============================================================
namespace tools
{
    namespace detail
    {
        template<class lambda> class is_lambda_
        {
            using x
                = ::std::remove_reference_t<lambda>;

            template<class u> static ::std::true_type
                check(decltype(&u::operator())*);

            template<class> static ::std::false_type
                check(...);

            using checked
                = decltype(check<x>(nullptr));
        public:
            is_lambda_() = delete;
            enum { value = checked::value };
        };

    } // namespace detail

    template<class F> class is_lambda
        : dDETAIL_CONSTANT(is_lambda_<F>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_LAMBDA_2013_USED_
