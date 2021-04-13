// [2021y-04m-12d][16:04:25] Idrisov Denis R. 10
#pragma once
#ifndef dTOOLS_IS_INCREMENTABLE_2013_USED_ 
#define dTOOLS_IS_INCREMENTABLE_2013_USED_ 100,2013

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_incrementable =========================================================
namespace tools 
{
    // ++prefix
    namespace detail
    {
        template<class t> t val();

        template<class t, bool> class is_prefix_incrementable_impl_
        {
            using x = ::std::remove_reference_t<t>;

            #define dCHECK_EXPRESSION(...) \
                decltype((__VA_ARGS__, ::std::true_type{}))

            template<class u> static dCHECK_EXPRESSION(
                ++val<u&>()
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            using checked 
                = decltype(check<x>(nullptr));
        public:
            is_prefix_incrementable_impl_() = delete;
            enum { value = checked::value };
        };

        template<class t> class is_prefix_incrementable_impl_<t, false>
            : public ::std::is_pointer<t>
        {};

        template <class t> class is_prefix_incrementable_
        {
            using no_ref = ::std::remove_reference<t>;
            using x = typename no_ref::type;
            enum { ok = ::std::is_class<x>::value };
            using v = ::tools::detail::is_prefix_incrementable_impl_<x, ok>;
        public:
            is_prefix_incrementable_() = delete;
            enum { value = v::value };
        };

    } // namespace detail

    // postfix++
    namespace detail
    {
        template<class t, bool> class is_postfix_incrementable_impl_
        {
            using x = ::std::remove_reference_t<t>;

            #define dCHECK_EXPRESSION(...) \
                decltype(__VA_ARGS__, ::std::true_type{})

            template<class u> static dCHECK_EXPRESSION( 
                val<u&>()++
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            using checked 
                = decltype(check<x>(nullptr));
        public:
            is_postfix_incrementable_impl_() = delete;
            enum { value = checked::value };
        };

        template<class t> class is_postfix_incrementable_impl_<t, false>
            : public ::std::is_pointer<t>
        {};

        template <class t> class is_postfix_incrementable_
        {
            using no_ref = ::std::remove_reference<t>;
            using x = typename no_ref::type;
            enum { ok = ::std::is_class<x>::value };
            using v = ::tools::detail::is_postfix_incrementable_impl_<x, ok>;
        public:
            is_postfix_incrementable_() = delete;
            enum { value = v::value };
        };

    } // namespace detail

    // is_incrementable
    namespace detail
    {
        template <class t> class is_incrementable_
        {
            using x = ::std::remove_reference_t<t>;
            using prefix  = ::tools::detail::is_prefix_incrementable_<x>;
            using postfix = ::tools::detail::is_postfix_incrementable_<x>;

            enum { v1 = prefix::value  };
            enum { v2 = postfix::value };
        public:
            is_incrementable_() = delete;
            enum { value = v1 || v2 };
        };

    } // namespace detail

    // if the syntax is valid: ++it ---> true 
    template<class t> struct is_prefix_incrementable
        : dDETAIL_CONSTANT(is_prefix_incrementable_<t>)
    {};

    // if the syntax is valid: ++it ---> true 
    template<class t> struct is_postfix_incrementable
        : dDETAIL_CONSTANT(is_postfix_incrementable_<t>)
    {};

    // if the syntax is valid: ++it or it++ ---> dereferencable 
    template<class t> struct is_incrementable
        : dDETAIL_CONSTANT(is_incrementable_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_INCREMENTABLE_2013_USED_
