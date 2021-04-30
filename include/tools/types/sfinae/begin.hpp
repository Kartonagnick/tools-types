// [2021y-04m-29d][11:52:19] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_BEGIN_USED_ 
#define dTOOLS_SFINAE_BEGIN_USED_ 100 PRE

#include <tools/features.hpp>
#include <tools/type_traits.hpp>

#if !defined(_MSC_VER) || _MSC_VER >= 1600
    #define dIMPLEMENT_(...)                  \
        public ::std::integral_constant<bool, \
            detail::__VA_ARGS__::value        \
        >
#else
    #define dIMPLEMENT_(...)                   \
        public dTRAIT::integral_constant<bool, \
            detail::__VA_ARGS__::value         \
        >
#endif

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
        #define dTOOLS_SFINAE_BEGIN_2012_USED_ 1
    #elif _MSC_VER == 1600 
        // msvc2010 10.0
        #define dTOOLS_SFINAE_BEGIN_2010_USED_ 1
    #elif _MSC_VER <= 1500 
        // msvc2008 9.0 or older
        #define dTOOLS_SFINAE_BEGIN_OLD_USED_ 1
    #else
        #error unknown msvc not support
    #endif
#endif

//==============================================================================
//==============================================================================

namespace tools  {

namespace detail
{
    typedef char(&no )[1];
    typedef char(&yes)[2];

} // namespace detail

namespace sfinae {

    template<class t> t obj();

    template<class t> t* make_decay(t&);
 
    #if defined(_MSC_VER) && _MSC_VER == 1600
        template<class t> class remove_reference
        {
            typedef decltype(make_decay(obj<t&>()))
                naked;
            typedef ::std::remove_pointer<naked>
                no_ptr;
        public:
            remove_reference();
            typedef typename no_ptr::type
                type;
        };
    #else
        template<class t> class remove_reference
        {
            typedef dTRAIT::remove_reference<t> 
                no_ref;
        public:
            remove_reference();
            typedef typename no_ref::type
                type;
        };
    #endif

    template<class a, class b>
    struct ava_help
    {
        typedef dTRAIT::true_type type;
    };

    template<class V, V> struct sig_help;

//==============================================================================
//==============================================================================
namespace exist  {

    template<class t> struct begin
    {
        typedef ::tools::sfinae::remove_reference<t> 
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

#elif dTOOLS_SFINAE_BEGIN_2012_USED_

//==============================================================================
//==============================================================================
namespace available
{
    namespace detail
    {
        template<class t> class begin_
        {
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type x;

            template <class u> static 
                typename ava_help<u, decltype(obj<u>().begin()) >::type
                check(u*);

            template <class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                 result;
        public:
            begin_();
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
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type x;

            template <class u> static 
                ::std::true_type 
                    check(sig_help<sig, &u::begin>*);

            template <class> static 
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                 result;
        public:
            begin_();
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

#elif dTOOLS_SFINAE_BEGIN_2010_USED_

//==============================================================================
//==============================================================================
namespace available
{
    namespace detail
    {
        template<class t> class begin_
        {
            typedef ::tools::sfinae::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type x;

            template <class u> static 
                typename ava_help<u, decltype(obj<u>().begin()) >::type
                check(u*);

            template <class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                 result;
        public:
            begin_();
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
            typedef ::tools::sfinae::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type x;

            template <class u> static 
                ::std::true_type 
                    check(sig_help<sig, &u::begin>*);

            template <class> static 
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                 result;
        public:
            begin_();
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

#elif dTOOLS_SFINAE_BEGIN_OLD_USED_

//==============================================================================
//==============================================================================
namespace available
{
    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];

        template<class t> class begin_
        {
            typedef ::tools::sfinae::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type x;

            template<class a, size_t n>
            struct help { char buf[n]; };

            template <class u> static 
                typename help<u, sizeof(obj<u>().begin()) >::type
                check(u*);

            template <class> static
                no check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            begin_();
            enum { value = sz != sizeof(no) };
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
        typedef char(&no )[1];
        typedef char(&yes)[2];

        template<class t, class sig>
        class begin_
        {
            typedef ::tools::sfinae::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type x;

            template <class u> static 
                yes check(sig_help<sig, &u::begin>*);

            template <class> static 
                no check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            begin_();
            enum { value = sz != sizeof(no) };
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
