// [2021y-04m-12d][17:40:05] Idrisov Denis R. 10
#pragma once
#ifndef dTOOLS_IS_DECREMENTABLE_2013_USED_ 
#define dTOOLS_IS_DECREMENTABLE_2013_USED_ 100,2013

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
            using x = ::std::remove_reference_t<t>;

            #define dCHECK_EXPRESSION(...) \
                decltype(__VA_ARGS__, ::std::true_type{})

            template<class u> static dCHECK_EXPRESSION( 
                --val<u&>()
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            using checked 
                = decltype(check<x>(nullptr));
        public:
            is_prefix_decrementable_impl_() = delete;
            enum { value = checked::value };
        };

        template<class t> class is_prefix_decrementable_impl_<t, false>
            : public ::std::is_pointer<t>
        {};

        template <class t> class is_prefix_decrementable_
        {
            using no_ref = ::std::remove_reference<t>;
            using x = typename no_ref::type;
            enum { ok = ::std::is_class<x>::value };
            using v = ::tools::detail::is_prefix_decrementable_impl_<x, ok>;
        public:
            is_prefix_decrementable_() = delete;
            enum { value = v::value };
        };

    } // namespace detail

    // postfix++
    namespace detail
    {
        template<class t, bool> class is_postfix_decrementable_impl_
        {
            using x = ::std::remove_reference_t<t>;

            #define dCHECK_EXPRESSION(...) \
                decltype((__VA_ARGS__, ::std::true_type{}))

            template<class u> static dCHECK_EXPRESSION( 
                val<u&>()--
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            using checked 
                = decltype(check<x>(nullptr));
        public:
            is_postfix_decrementable_impl_() = delete;
            enum { value = checked::value };
        };

        template<class t> class is_postfix_decrementable_impl_<t, false>
            : public ::std::is_pointer<t>
        {};

        template <class t> class is_postfix_decrementable_
        {
            using no_ref = ::std::remove_reference<t>;
            using x = typename no_ref::type;
            enum { ok = ::std::is_class<x>::value };
            using v = ::tools::detail::is_postfix_decrementable_impl_<x, ok>;
        public:
            is_postfix_decrementable_() = delete;
            enum { value = v::value };
        };

    } // namespace detail

    // is_decrementable
    namespace detail
    {
        template <class t> class is_decrementable_
        {
            using x = ::std::remove_reference_t<t>;
            using prefix  = ::tools::detail::is_prefix_decrementable_<x>;
            using postfix = ::tools::detail::is_postfix_decrementable_<x>;

            enum { v1 = prefix::value  };
            enum { v2 = postfix::value };
        public:
            is_decrementable_() = delete;
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
#endif // !dTOOLS_IS_DECREMENTABLE_2013_USED_
