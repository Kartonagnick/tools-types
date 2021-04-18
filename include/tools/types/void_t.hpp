// [2021y-04m-13d][15:08:02] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_VOID_T_USED_ 
#define dTOOLS_VOID_T_USED_ 100 PRE

#if defined(__cplusplus) && __cplusplus >= 201103L
    // c++11 support
    #include <type_traits>

#elif !defined(_MSC_VER)
    // other compilers not processed
    #include <type_traits>

#elif _MSC_VER >= 1900
    // msvc2015 or newest
    #include <type_traits>

#elif _MSC_VER == 1800
    // msvc2013
    namespace std
    {
        namespace detail
        {
            template<class... Args> struct discriminator_
                { enum { value = 1 }; };

            template<class A, class... Args> struct discriminator_<A, Args...>
            { 
                using x = ::std::detail::discriminator_<Args...>;
                enum { v1 = ::std::is_same<A, A>::value };
                enum { value = v1 && x::value };
            };
        }

        template<class... Args> 
        using void_t 
            = ::std::enable_if_t<
                ::std::detail::discriminator_<Args...>::value 
            >;

    } // namespace std

#else
    // msvc2012 or older

    #define dVARIADIC_7 \
        class t1, class t2 = empty, class t3 = empty, class t4 = empty, \
        class t5 = empty, class t6 = empty, class t7  = empty

    namespace std
    {
        struct empty;
        namespace detail
        {
            template <bool, class t = void> 
                struct enable_if_;

            template <class t> struct enable_if_<true, t>
                { typedef t type; };

            template<class a, class b> struct is_same_
                { enum { value = 0 }; };

            template<class t> struct is_same_<t, t>
                { enum { value = 1 }; };


            template<dVARIADIC_7> 
            struct discriminator_
            {
                enum { r1 = ::std::detail::is_same_<t1, t1>::value };
                enum { r2 = discriminator_<t2, t3, t4, t5, t6, t7>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2, class t3, class t4, class t5, class t6> 
            struct discriminator_<t1, t2, t3, t4, t5, t6, empty>
            {
                enum { r1 = ::std::detail::is_same_<t1, t1>::value };
                enum { r2 = discriminator_<t2, t3, t4, t5, t6>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2, class t3, class t4, class t5> 
            struct discriminator_<t1, t2, t3, t4, t5, empty, empty>
            {
                enum { r1 = ::std::detail::is_same_<t1, t1>::value };
                enum { r2 = discriminator_<t2, t3, t4, t5>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2, class t3, class t4> 
            struct discriminator_<t1, t2, t3, t4, empty, empty, empty>
            {
                enum { r1 = ::std::detail::is_same_<t1, t1>::value };
                enum { r2 = discriminator_<t2, t3, t4>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2, class t3> 
            struct discriminator_<t1, t2, t3, empty, empty, empty, empty>
            {
                enum { r1 = ::std::detail::is_same_<t1, t1>::value };
                enum { r2 = discriminator_<t2, t3>::value };
                enum { value = r1 && r2 };
            };

            template<class t1, class t2> 
            struct discriminator_<t1, t2, empty, empty, empty, empty, empty>
            {
                enum { r1 = ::std::detail::is_same_<t1, t1>::value };
                enum { r2 = discriminator_<t2>::value };
                enum { value = r1 && r2 };
            };

            template<class t1> 
            struct discriminator_<t1, empty, empty, empty, empty, empty, empty>
            {
                enum { value = ::std::detail::is_same_<t1, t1>::value };
            };

        } // namespace detail

        template<dVARIADIC_7> struct void_type
        {
            typedef typename ::std::detail::enable_if_<
                ::std::detail::discriminator_<t1,t2,t3,t4,t4,t6,t7>::value 
            >::type 
                type;
        };

    } // namespace std
#endif

//==============================================================================
//==============================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1800
    // msvc2013 or newest
    #define dSFINAE_CHECK(...) \
        std::void_t< __VA_ARGS__ >
#else
    // msvc2012 or older
    #define dSFINAE_CHECK(...) \
        typename ::std::void_type<__VA_ARGS__>::type
#endif

#if !defined(_MSC_VER) || _MSC_VER >= 1600
    // msvc2010 or newest
    #define dSFINAE_EXPRESSION(...) \
        dSFINAE_CHECK( decltype(__VA_ARGS__) )
#else
    // msvc2012 or older
    #define dSFINAE_EXPRESSION(...) \
        dSFINAE_CHECK(char[1 + sizeof(__VA_ARGS__)])
#endif

//==============================================================================
//==============================================================================

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

//==============================================================================
//==============================================================================
#endif // !dTOOLS_VOID_T_USED_
