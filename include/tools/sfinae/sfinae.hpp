// [2021y-04m-13d][15:08:02] Idrisov Denis R. 100 
// [2021y-04m-19d][11:41:29] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_VOID_T_USED_ 
#define dTOOLS_VOID_T_USED_ 101 PRE

#if defined(__cplusplus) && __cplusplus >= 201103L
    // c++11 support
    #include <type_traits>
    namespace tools { using ::std::void_t; }

#elif !defined(_MSC_VER)
    // other compilers not processed
    #include <type_traits>
    namespace tools { using ::std::void_t; }

#elif _MSC_VER > 1900
    // msvc2017 or newer
    #include <type_traits>
    namespace tools { using ::std::void_t; }

#elif _MSC_VER == 1900
    // msvc2015 has bug (see: docs/articles/using-declaration.md)
    #include <type_traits>
    namespace tools 
    {
        template<class ...args>
        using void_t = ::std::void_t<args...>;
    }

#elif _MSC_VER == 1800
    // msvc2013 has problem (see: docs/articles/void_t.md)
    namespace tools
    {
        namespace detail_void_t
        {
            template<class... Args> struct discriminator_
                { enum { value = 1 }; };

            template<class A, class... Args> struct discriminator_<A, Args...>
            { 
                using x = ::tools::detail_void_t::discriminator_<Args...>;
                enum { v = ::std::is_same<A, A>::value };
                enum { value = v && x::value };
            };

        } // namespace detail_void_t

        template<class... Args> 
        using void_t 
            = ::std::enable_if_t<  
                ::tools::detail_void_t::discriminator_<Args...>::value 
            >;

    } // namespace tools

#else
    // msvc2012 or older
    #include <tools/types/traits.hpp>

    #define dVARIADIC_7 \
        class t1, class t2 = empty, class t3 = empty, class t4 = empty, \
        class t5 = empty, class t6 = empty, class t7  = empty

    namespace tools
    {
        struct empty;
        namespace detail_void_t
        {
            template<dVARIADIC_7> 
            struct discriminator_
            {
                enum { r1 = ::tools::is_same<t1, t1>::value };
                enum { r2 = discriminator_<t2, t3, t4, t5, t6, t7>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2, class t3, class t4, class t5, class t6> 
            struct discriminator_<t1, t2, t3, t4, t5, t6, empty>
            {
                enum { r1 = ::tools::is_same<t1, t1>::value };
                enum { r2 = discriminator_<t2, t3, t4, t5, t6>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2, class t3, class t4, class t5> 
            struct discriminator_<t1, t2, t3, t4, t5, empty, empty>
            {
                enum { r1 = ::tools::is_same<t1, t1>::value        };
                enum { r2 = discriminator_<t2, t3, t4, t5>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2, class t3, class t4> 
            struct discriminator_<t1, t2, t3, t4, empty, empty, empty>
            {
                enum { r1 = ::tools::is_same<t1, t1>::value    };
                enum { r2 = discriminator_<t2, t3, t4>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2, class t3> 
            struct discriminator_<t1, t2, t3, empty, empty, empty, empty>
            {
                enum { r1 = ::tools::is_same<t1, t1>::value };
                enum { r2 = discriminator_<t2, t3>::value  };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2> 
            struct discriminator_<t1, t2, empty, empty, empty, empty, empty>
            {
                enum { r1 = ::tools::is_same<t1, t1>::value };
                enum { r2 = discriminator_<t2>::value };
                enum { value = r1 && r2 };
            };

            template<class t1> 
            struct discriminator_<t1, empty, empty, empty, empty, empty, empty>
            {
                enum { value = ::tools::is_same<t1, t1>::value };
            };

        } // namespace detail_void_t

        template<dVARIADIC_7> struct void_type
        {
            typedef typename ::tools::enable_if<
                ::tools::detail_void_t::discriminator_<t1,t2,t3,t4,t4,t6,t7>::value 
            >::type 
                type;
        };

    } // namespace tools
#endif

//==============================================================================
//=== dSFINAE_CHECK ============================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1800
    // msvc2013 or newer
    #define dSFINAE_VOID_TYPE(...) ::tools::void_t< __VA_ARGS__ >
#else
    // msvc2012 or older
    #define dSFINAE_VOID_TYPE(...) \
        typename ::tools::void_type<__VA_ARGS__>::type
#endif

#if 0
#if !defined(_MSC_VER) || _MSC_VER >= 1600
    // msvc2010 or newer
    #define dSFINAE_EXPRESSION(...) \
        dSFINAE_CHECK(decltype(__VA_ARGS__))
#else
    // msvc2012 or older
    #define dSFINAE_EXPRESSION(...) \
        dSFINAE_CHECK(char[1 + sizeof(__VA_ARGS__)])
#endif
#endif

//==============================================================================
//==============================================================================

#if 0

#define dSFINAE_DECLARATION_1(Name, Type, ...)            \
    template<class, class = void>                         \
    struct Name                                           \
        : dTRAIT::false_type                              \
    {};                                                   \
    template<class Type>                                  \
    struct Name <Type, dSFINAE_EXPRESSION(__VA_ARGS__)>   \
        : dTRAIT::true_type                               \
    {}

#define dSFINAE_DECLARATION_2(name, T1, T2, ... )         \
    template<class, class, class = void>                  \
    struct name                                           \
        : dTRAIT::false_type                              \
    {};                                                   \
    template<class T1, class T2>                          \
    struct name<T1, T2, dSFINAE_EXPRESSION(__VA_ARGS__) > \
        : dTRAIT::true_type                               \
    {}

#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_VOID_T_USED_
