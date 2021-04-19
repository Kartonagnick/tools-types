// [2021y-02m-05d][18:41:19] Idrisov Denis R.
// [2021y-03m-10d][23:23:35] Idrisov Denis R. 108
// [2021y-03m-15d][18:28:44] Idrisov Denis R. 109
// [2021y-03m-17d][23:19:45] Idrisov Denis R. 110
// [2021y-03m-19d][16:14:09] Idrisov Denis R. 111
// [2021y-03m-20d][02:13:22] Idrisov Denis R. 112
// [2021y-03m-20d][19:41:07] Idrisov Denis R. 113
// [2021y-03m-30d][03:40:56] Idrisov Denis R. 114
// [2021y-03m-31d][01:56:33] Idrisov Denis R. 115
// [2021y-04m-02d][00:39:44] Idrisov Denis R. 116
// [2021y-04m-03d][22:59:27] Idrisov Denis R. 117
// [2021y-04m-04d][07:05:55] Idrisov Denis R. 118
#pragma once
#ifndef dTOOLS_FEATURES_USED_
#define dTOOLS_FEATURES_USED_ 118
//==============================================================================
//=== dMESSAGE =================================================================

#ifdef _MSC_VER
    #define dMESSAGE(...)  __pragma(message(__VA_ARGS__))
#else
    #define dMESSAGE(...) 
#endif

//==============================================================================
//=== dHAS_NULLPTR =============================================================

#if defined(__GNUC__) && __GNUC__ * 10 + __GNUC_MINOR__ >= 46
    #define dHAS_NULLPTR 1
#endif

#if !defined(_MSC_VER) || _MSC_VER >= 1600
    // #pragma message("build for msvc2010 (or newer)")

    // [WARNING] msvc2010 has bug with reference
    // bug: can be "std::tr1::_Remove_reference<_Ty&&>"
    // bug: or "std::tr1::_Remove_reference<_Ty&>"
    #define dHAS_TYPE_TRAITS 1

    #define dHAS_DECLTYPE 1
    #define dHAS_NULLPTR 1
    #define dHAS_LAMBDA 1
    #define dHAS_HASH 1
#endif

#if __cplusplus >= 201103L
    #define dHAS_NULLPTR 1
#endif

#ifdef dHAS_NULLPTR
    typedef decltype(nullptr) nullptr_t;
#endif

//==============================================================================
//=== dSTATIC_ASSERT ===========================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1600
    // #pragma message("build for msvc2010 (or newer)")
    #define dHAS_CSTDINT 1
    #define dHAS_STATIC_ASSERT 1

    #define dSTATIC_ASSERT(msg, ...) \
        static_assert((__VA_ARGS__), #msg)

    #define dSTATIC_CHECK(msg, ...)  \
        static_assert((__VA_ARGS__), #msg)

#else

    #define dSTATIC_ASSERT_3(msg, ...) \
        struct msg { int static_assert_ : !!(__VA_ARGS__); }

    #define dSTATIC_ASSERT_2(msg, L, C, ...)  \
        dSTATIC_ASSERT_3(msg##_##L##_##C , __VA_ARGS__)

    #define dSTATIC_ASSERT_1(msg, L, C, ...) \
        dSTATIC_ASSERT_2(msg, L, C, __VA_ARGS__)

    #define dSTATIC_ASSERT(msg, ...) \
        dSTATIC_ASSERT_1(msg, __LINE__, __COUNTER__, __VA_ARGS__)

    
    template<bool> struct static_assert_;
    template<> struct static_assert_<true> {};

    #define dSTATIC_CHECK(msg, ...)          \
    {                                        \
        ::static_assert_<(__VA_ARGS__)> msg; \
        (void) msg;                          \
    } void()

#endif

//==============================================================================
//=== dHAS_RVALUE_REFERENCES/dHAS_ATOMIC =======================================

#if !defined(_MSC_VER) || _MSC_VER >= 1700
    // #pragma message("build for msvc2012 (or newer) or other compiler")

    // [WARNING] msvc2010 has bug with rvalue
    // (example eror: from "const char [4]" to "std::string &&")
    #define dHAS_RVALUE_REFERENCES 1

    #define dHAS_ARRAY_EMPTY_SIZE 1
    #define dHAS_ENUM_CLASS 1
    #define dHAS_EMPLACE 1    
    #define dHAS_CHRONO 1
    #define dHAS_ATOMIC 1
#endif

//==============================================================================
//=== dTRAIT ===================================================================

#ifdef dHAS_TYPE_TRAITS
    #define dTRAIT std
#else
    #define dTRAIT tools
#endif

#define dDETAIL_CONSTANT(...)              \
    public dTRAIT::integral_constant<bool, \
        detail::__VA_ARGS__::value         \
    >

//==============================================================================
//=== dHAS_DELETING_FUNCTIONS ==================================================

#if (defined(_MSC_VER) && _MSC_VER >= 1800) || __cplusplus >= 201103L
    // #pragma message("build for msvc2013 (or newer) or other compiler")
    // #pragma message("build for c++11 (or newer)")
    #define dHAS_TEMPLATE_FUNCTION_DEFAULT_PARAM 1
    #define dHAS_AGGREGATE_INITIALIZE 1
    #define dHAS_DELETING_FUNCTIONS 1
    #define dHAS_VARIADIC_TEMPLATE 1
    #define dHAS_USING_ALIAS 1
#endif

#ifdef dHAS_DELETING_FUNCTIONS
    #define dNOCOPYABLE(Class)                   \
        Class(const Class&)            = delete; \
        Class(Class&&)                 = delete; \
        Class& operator=(const Class&) = delete; \
        Class& operator=(Class&&)      = delete
#else
    #define dNOCOPYABLE(Class) \
        Class(const Class&);   \
        Class& operator=(const Class&)
#endif

//==============================================================================
//=== dHAS_CPP11 ===============================================================

#if (defined(_MSC_VER) && _MSC_VER >= 1900) || __cplusplus >= 201103L
    // #pragma message("build for msvc2015 (or newer) or other compiler")
    // #pragma message("build for c++11 (or newer)")
    // #define dHAS_TRAILING_RETURN_TYPE 1
    // #define dHAS_AUTO_RETURN_TYPE 1
    #define dCONSTEXPR_CPP11 constexpr
    #define dHAS_CONSTEXPR_CPP11 1
    #define dHAS_ABOMINABLE 1
    #define dHAS_CPP11 1
#else 
    #define dCONSTEXPR_CPP11 inline
#endif

#ifdef dHAS_CONSTEXPR_CPP11
    #define dCONSTANT constexpr
#else
    #define dCONSTANT const
#endif

//==============================================================================
//=== dNOEXCEPT ================================================================

#if defined(__clang__)
    #if __has_feature(cxx_noexcept)
        #define dHAS_NOEXCEPT 1
    #endif
#endif

#if defined(__GXX_EXPERIMENTAL_CXX0X__) && __GNUC__ * 10 + __GNUC_MINOR__ >= 46
    #define dHAS_NOEXCEPT 1
#endif

#if defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 190023026
    // #pragma message("build for msvc2015 (or newer)")
    #define dHAS_NOEXCEPT 1
#endif
                
#ifdef dHAS_NOEXCEPT
    #define dNOEXCEPT noexcept
#else
    #define dNOEXCEPT throw()
#endif

//==============================================================================
//=== dTHREAD_LOCAL ============================================================

#ifdef _MSC_VER
    #define dTHREAD_LOCAL_EXTENSION  __declspec(thread)
#else
    #define dTHREAD_LOCAL_EXTENSION  __thread
#endif

#if defined (_MSC_VER) && _MSC_VER >= 1900
    // #pragma message("build for msvc2015 (or newer) or other compiler")
    #define dHAS_THREAD_LOCAL 1
#elif __cplusplus >= 201103L
    // #pragma message("build for c++11")
    #define dHAS_THREAD_LOCAL 1
#endif

//==============================================================================
//=== dCONSTEXPR_CPP14 =========================================================

#if (defined(_MSC_VER) && _MSC_VER > 1900) || __cplusplus >= 201402L
    // #pragma message("build for msvc2017 (or newer) or other compiler")
    // #pragma message("build for c++14 (or newer)")
    #define dCONSTEXPR_CPP14 constexpr
    #define dHAS_CONSTEXPR_CPP14 1
    #define dHAS_CPP14 1
#else
    #define dCONSTEXPR_CPP14 inline
#endif

//==============================================================================
//=== dHAS_RVALUE_ARRAY ========================================================

#if !defined(_MSC_VER) || _MSC_VER > 1900
    // #pragma message("build for msvc2017 (or newer) or gcc-like compiler")
    #define dHAS_RVALUE_ARRAY 1
#endif

//==============================================================================
//=== dNODISCARD ===============================================================

#if (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L
    // #pragma message("build for c++17 (or newer))
    #define dNODISCARD [[nodiscard]]
    #define dHAS_CPP17 1
#else
    #define dNODISCARD
#endif

//==============================================================================
//=== dHAS_ZERO_SIZE_ARRAY =====================================================

#ifndef _MSC_VER
    #define dHAS_ZERO_SIZE_ARRAY 1
#endif 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_FEATURES_USED_
