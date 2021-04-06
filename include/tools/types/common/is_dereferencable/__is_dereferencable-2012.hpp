// [2021y-04m-06d][21:36:00] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_2012_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_2012_USED_ 100,2012

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        
        // ::std::true_type get_true();


        template<class t> class is_dereferencable_
        {
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type 
                x;

#if 0
            #define dCHECK_EXPRESSION(...) \
                decltype(__VA_ARGS__, ::std::true_type())

            template<class u> static dCHECK_EXPRESSION( 
                *::std::declval<u>()
            ) check(u*);

            #undef dCHECK_EXPRESSION
#endif

#if 1
            template<class u>
            static ::std::true_type
                check(decltype(*::std::declval<u>())*);

                //check(typename ::std::add_pointer< decltype(*::std::declval<u>()) >::type)
                //check(typename ::std::add_pointer<decltype(*::std::declval<u>()) >::type);
#endif

            template<class> static ::std::false_type
                check(...);

            typedef decltype(check<x>(nullptr)) 
                checked;
        public:
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
#endif // !dTOOLS_IS_DEREFERENCABLE_2012_USED_
