// [2021y-04m-13d][21:20:30] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_HAS_OPERATOR_ACCCESS_2013_USED_ 
#define dTOOLS_HAS_OPERATOR_ACCCESS_2013_USED_ 100,2013

#include <tools/type_traits.hpp>

//==============================================================================
//=== has_operaror_access ======================================================
namespace tools
{
    namespace detail
    {
        template<class t> t val();

        template<class t, class a, bool>
        class has_operator_access_impl_
        {
            template<class u> static ::std::true_type
                check(
                    typename std::add_pointer< 
                        decltype( val<u&>()[ val<a&>() ] )
                    >::type 
                );

            template<class> static ::std::false_type
                check(...);

            using checked
                = decltype(check<t>(nullptr));
        public:
            has_operator_access_impl_() = delete;
            enum { value = checked::value };
        };

        template<class t>
        class has_operator_access_impl_<t, void, true>
        {
            template<class u> static ::std::true_type
                check(decltype(&u::operator[])*);

            template<class> static ::std::false_type
                check(...);

            using checked
                = decltype(check<t>(nullptr));

            using x 
                = ::tools::detail::has_operator_access_impl_<t, size_t, true>;
            enum { v = x::value };
        public:
            has_operator_access_impl_() = delete;
            enum { value = checked::value || v};
        };

        template <class t, class a> 
        class has_operator_access_impl_<t, a, false>
        {
            using check = ::std::is_array<t>;
        public:
            has_operator_access_impl_() = delete;
            enum { value = check::value };
        };

        template <class t, class a> 
        struct has_operator_access_
        {
            using z = ::std::remove_reference_t<t>;
            using x = ::std::remove_cv_t<z>;
            enum { ok = ::std::is_class<x>::value };
            using v = ::tools::detail::has_operator_access_impl_<x, a, ok>;
        public:
            has_operator_access_() = delete;
            enum { value = v::value };
        };

    } // namespace detail

    template<class t, class a = void> 
    class has_operator_access
        : dDETAIL_CONSTANT(has_operator_access_<t, a>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_HAS_OPERATOR_ACCCESS_2013_USED_
