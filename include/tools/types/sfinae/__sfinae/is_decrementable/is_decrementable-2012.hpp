// [2021y-04m-13d][13:17:55] Idrisov Denis R. 100
// [2021y-04m-14d][01:40:54] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_IS_DECREMENTABLE_2012_USED_ 
#define dTOOLS_IS_DECREMENTABLE_2012_USED_ 100,2012

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_decrementable =========================================================
namespace tools 
{
    // ++prefix
    namespace detail
    {
        template<class t> t val();

        template<class t, bool> class is_prefix_decrementable_impl_
        {
            #define dCHECK_EXPRESSION(...) \
                decltype((__VA_ARGS__, ::std::true_type()))

            template<class u> static dCHECK_EXPRESSION(
                --val<u&>()
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            typedef decltype(check<t>(nullptr)) 
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t> class is_prefix_decrementable_impl_<t, false>
            : public ::std::is_pointer<t>
        {};

        template <class t> class is_prefix_decrementable_
        {
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type
                x;
            enum { ok = ::std::is_class<x>::value };
            typedef ::tools::detail::is_prefix_decrementable_impl_<x, ok>
                v;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    // postfix++
    namespace detail
    {
        template<class t, bool> class is_postfix_decrementable_impl_
        {
            #define dCHECK_EXPRESSION(...) \
                decltype(__VA_ARGS__, ::std::true_type())

            template<class u> static dCHECK_EXPRESSION( 
                val<u&>()--
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            typedef decltype(check<t>(nullptr)) 
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t> class is_postfix_decrementable_impl_<t, false>
            : public ::std::is_pointer<t>
        {};

        template <class t> class is_postfix_decrementable_
        {
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type
                x;
            enum { ok = ::std::is_class<x>::value };
            typedef ::tools::detail::is_postfix_decrementable_impl_<x, ok>
                v;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    // is_decrementable
    namespace detail
    {
        template <class t> class is_decrementable_
        {
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type
                x;
            typedef ::tools::detail::is_prefix_decrementable_<x>
                prefix;
            typedef ::tools::detail::is_postfix_decrementable_<x>
                postfix;

            enum { v1 = prefix::value  };
            enum { v2 = postfix::value };
        public:
            enum { value = v1 || v2 };
        };

    } // namespace detail

    // if the syntax is valid: ++it ---> true 
    template<class t> struct is_prefix_decrementable
        : dDETAIL_CONSTANT(is_prefix_decrementable_<t>)
    {};

    // if the syntax is valid: ++it ---> true 
    template<class t> struct is_postfix_decrementable
        : dDETAIL_CONSTANT(is_postfix_decrementable_<t>)
    {};

    // if the syntax is valid: ++it or it++ ---> dereferencable 
    template<class t> struct is_decrementable
        : dDETAIL_CONSTANT(is_decrementable_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_DECREMENTABLE_2012_USED_
