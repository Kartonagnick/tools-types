// [2021y-04m-27d][21:07:30] Idrisov Denis R. 100 PRE
// [2021y-04m-30d][02:05:47] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_SIGNATURE_2015_USED_ 
#define dTOOLS_SFINAE_SIGNATURE_2015_USED_ 100 PRE

#include <type_traits>

#define dIMPLEMENT_(...)                  \
    public ::std::integral_constant<bool, \
        detail::__VA_ARGS__::value        \
    >

//==============================================================================
//==============================================================================

namespace tools  {
namespace sfinae {
namespace signature {

    namespace detail
    {
        template<class t, class sig>
        class dereference_
        {
            template <class cl>
            using method
                = decltype(static_cast<sig>(&cl::operator*));

            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(method<u>*);

            template <class> static 
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            dereference_() = delete;
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class sig> 
    class dereference
        : dIMPLEMENT_(dereference_<t, sig>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class access_
        {
            #define dSFINAE_ \
                decltype(static_cast<sig>(&u::operator[]))

            template <class u, class x = dSFINAE_ >
            struct method
            {
                using type = x;
            };
            #undef dSFINAE_

            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(method<u>*);

            template <class> static 
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            access_() = delete;
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class sig> 
    class access
        : dIMPLEMENT_(access_<t, sig>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class call_
        {
            template <class u>
            using method
                = decltype(static_cast<sig>(&u::operator()));

            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(method<u>*);

            template <class> static 
                ::std::false_type  check(...);

            using result = decltype(check<x>(0));
        public:
            call_() = delete;
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class sig> 
    class call
        : dIMPLEMENT_(call_<t, sig>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class begin_
        {
            template <class u>
            using method
                = decltype(static_cast<sig>(&u::begin));

            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(method<u>*);

            template <class> static 
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            begin_() = delete;
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class sig> 
    class begin
        : dIMPLEMENT_(begin_<t, sig>)
    {};

//==============================================================================
//==============================================================================

} // namespace signature
} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_SIGNATURE_2015_USED_
