// [2021y-04m-30d][02:53:00] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_SIGNATURE_2013_USED_ 
#define dTOOLS_SFINAE_SIGNATURE_2013_USED_ 100 PRE

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

    template<class V, V> struct help;

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class call_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(help<sig, &u::operator()>*);

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
        class dereference_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(help<sig, &u::operator*>*);

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
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(help<sig, &u::operator[]>*);

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
        class begin_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(help<sig, &u::begin>*);

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

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_SIGNATURE_2013_USED_
