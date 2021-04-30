// [2021y-04m-23d][23:55:38] Idrisov Denis R. 100 PRE
// [2021y-04m-27d][20:50:12] Idrisov Denis R. 100 PRE

#pragma once
#ifndef dTOOLS_SFINAE_2015_USED_ 
#define dTOOLS_SFINAE_2015_USED_ 100 PRE
//==============================================================================
//==============================================================================

#include <tools/types/sfinae/exist-2008.hpp>
#include <tools/types/sfinae/available-2015.hpp>
#include <tools/types/sfinae/signature-2015.hpp>

#define dIMPLEMENT_(...)                  \
    public ::std::integral_constant<bool, \
        detail::__VA_ARGS__::value        \
    >

namespace tools
{
    namespace detail
    {
        template<class lambda> class is_lambda_
        {
            using x = ::std::remove_reference_t<lambda>;

            template<class u> static ::std::true_type
                check(decltype(&u::operator()));

            template<class> static ::std::false_type
                check(...);

            typedef decltype(check<x>(nullptr))
                checked;
        public:
            enum { value = checked::value };
        };

    } // namespace detail

    template<class f> class is_lambda
        : dIMPLEMENT_(is_lambda_<f>)
    {};

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_2015_USED_
