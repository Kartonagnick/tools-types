// [2021y-04m-29d][11:52:19] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_BEGIN_USED_ 
#define dTOOLS_SFINAE_BEGIN_USED_ 100 PRE

#include <tools/features.hpp>
#include <tools/type_traits.hpp>

#define dIMPLEMENT_(...)                  \
    public ::std::integral_constant<bool, \
        detail::__VA_ARGS__::value        \
    >

//==============================================================================
//==============================================================================

#if defined(__cplusplus) && __cplusplus >= 201103L
    // c++11 support
    #define dTOOLS_SFINAE_BEGIN_MODERN_USED_ 1
#elif !defined(_MSC_VER)
    // other compilers not processed
    #define dTOOLS_SFINAE_BEGIN_MODERN_USED_ 1
#else
    #if _MSC_VER >= 1900
        // msvc2015 or newer
        #define dTOOLS_SFINAE_BEGIN_MODERN_USED_ 1
    #elif _MSC_VER == 1800 
        // msvc2013 12.0
        #define dTOOLS_SFINAE_BEGIN_2013_USED_ 1
    #elif _MSC_VER == 1700 
        // msvc2012 11.0
        #define dTOOLS_SFINAE_BEGIN_MODERN_USED_ 1
    #elif _MSC_VER == 1600 
        // msvc2010 10.0
    #elif _MSC_VER == 1500 
        // msvc2008 9.0

    #elif _MSC_VER == 1400 
        // msvc2005 8.0
    #elif _MSC_VER == 1310 
        // msvc2003 .NET 7.1
    #elif _MSC_VER == 1300 
        // msvc2002 .NET 7.0
    #elif _MSC_VER == 1200 
        // msvc6 6.0
    #else
        #error too old msvc not support
    #endif
#endif

//==============================================================================
//==============================================================================

namespace tools  {
namespace sfinae {

    template<class t> t obj();

    template<class a, class b>
    struct ava_help
    {
        typedef ::std::true_type type;
        //using type = ::std::true_type; 
    };

    template<class V, V> struct sig_help;

//==============================================================================
//==============================================================================
namespace exist  {

    template<class t> struct begin
    {
        typedef ::std::remove_reference<t> 
            no_ref;
        typedef typename no_ref::type x;

        __if_exists    (x::begin) { enum { value = 1 }; }
        __if_not_exists(x::begin) { enum { value = 0 }; }
    };                                      

} // namespace exist

//==============================================================================
//==============================================================================

#ifdef dTOOLS_SFINAE_BEGIN_MODERN_USED_

//==============================================================================
//==============================================================================
namespace signature {
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

} // namespace signature
//==============================================================================
namespace available
{
    template<class, class = void>
    struct begin : ::std::false_type {};
 
    template<class t> struct begin<t,
            ::std::void_t<decltype(::std::declval<t>().begin())>
        > : ::std::true_type 
    {};

} // namespace available

#elif dTOOLS_SFINAE_BEGIN_2013_USED_

//==============================================================================
//==============================================================================
namespace available
{
    namespace detail
    {
        template<class t> class begin_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename ava_help<u, decltype(obj<u>().begin()) >::type
                check(u*);

            template <class> static
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
            enum { sz = sizeof(check<x>(0)) };
        public:
            begin_() = delete;
            enum { value = result::value };
        };

    } // namespace detail

    template<class t> 
    class begin
        : dIMPLEMENT_(begin_<t>)
    {};

} // namespace available

//==============================================================================
//==============================================================================
namespace signature
{
    namespace detail
    {
        template<class t, class sig>
        class begin_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type 
                    check(sig_help<sig, &u::begin>*);

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

} // namespace signature

//==============================================================================
//==============================================================================

#else
    #error compiler not support
#endif

//==============================================================================
//==============================================================================

} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#undef dIMPLEMENT_
#endif // !dTOOLS_SFINAE_BEGIN_USED_
