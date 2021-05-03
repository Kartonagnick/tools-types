// [2021y-04m-30d][02:36:11] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2013_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2013_USED_ 100 PRE

#include <type_traits>
#include <cstddef>

#define dIMPLEMENT_(...)                  \
    public ::std::integral_constant<bool, \
        detail::__VA_ARGS__::value        \
    >

//==============================================================================
//==============================================================================

namespace tools     {
namespace sfinae    {
namespace available {

    template<class a, class b>
    struct help 
        { using type = ::std::true_type;};

    namespace detail
    {
        template<class t, class ...args> class call_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename help<u, decltype(::std::declval<u>()(::std::declval<args>()...))>::type 
				check(u*);

            template<class> static
                ::std::false_type
                check(...);

            typedef decltype(check<x>(nullptr))
                checked;
        public:
            call_();
            enum { value = checked::value };
        };

    } // namespace detail

    template<class t, class...args>
    struct call
        : dIMPLEMENT_(call_<t, args...>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t> class dereference_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename help<u, decltype(*::std::declval<u>())>::type 
				check(u*);

            template <class> static
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            dereference_();
            enum { value = result::value };
        };

    } // namespace detail

    template<class t> 
    class dereference
        : dIMPLEMENT_(dereference_<t>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class i> class access_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename help<u, decltype(::std::declval<u>()[::std::declval<i>()])>::type 
				check(u*);

            template <class> static
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            access_();
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class i = size_t> 
    class access
        : dIMPLEMENT_(access_<t, i>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t> class begin_
        {
        public:
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename help<u, decltype(::std::declval<u>().begin())>::type
				check(u*);

            template <class> static
                ::std::false_type check(...);

            using result_t = decltype(check<x>(nullptr));
        public:
            begin_() = delete;
            enum { value = result_t::value };
        };

#if 0
        // diagnostic version
        template<class t> class begin_
        {
        public:
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                help<u, decltype(::std::declval<u>().begin())>
				check(u*);

            template <class> static
                ::std::false_type check(...);

            using check_t = decltype(check<x>(nullptr));

            enum { v = ! ::std::is_same<check_t, ::std::false_type>::value };

            using cond_t
                = ::std::conditional<v, ::std::true_type, ::std::false_type>;

            using result_t = typename cond_t::type;
        public:
            begin_() = delete;
            enum { value = result_t::value };
        };
#endif

    } // namespace detail

    template<class t> 
    class begin
        : dIMPLEMENT_(begin_<t>)
    {};

} // namespace available
} // namespace sfinae
} // namespace tools

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_AVAILABLE_2015_USED_
