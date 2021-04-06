// [2021y-04m-06d][21:36:00] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_2013_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_2013_USED_ 100,2013

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        template<class t> class is_dereferencable_
        {
            using x = ::std::remove_reference_t<t>;

            #define dCHECK_EXPRESSION(...) \
                decltype(__VA_ARGS__, ::std::true_type{})

            template<class u> static dCHECK_EXPRESSION( 
                *::std::declval<u>()
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            using checked     
                = decltype(check<x>(nullptr));
        public:
            is_dereferencable_() = delete;
            enum { value = checked::value };
        };

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t> struct is_dereferencable
        : dDETAIL_CONSTANT(is_dereferencable_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_DEREFERENCABLE_2013_USED_
