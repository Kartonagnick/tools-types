// [2021y-02m-28d][01:43:52] Idrisov Denis R.
#include <mygtest/modern.hpp>
//=================================================================================
//=================================================================================

#ifdef TEST_TOOLS_FEATURE_STASTIC_ASSERT

#define dTEST_COMPONENT tools, features
#define dTEST_METHOD test_HAS_STATIC_ASSERT
#define dTEST_TAG tdd

#include <tools/features.hpp>

#ifndef dHAS_STATIC_ASSERT
    dMESSAGE("[test] tools: disabled -> dHAS_STATIC_ASSERT")
#else
    dMESSAGE("[test] tools: enabled -> dHAS_STATIC_ASSERT")
#endif

//==============================================================================
//==============================================================================
namespace
{
    enum { value = 1 };

    #if dHAS_STATIC_ASSERT
        static_assert(value, "'static_assert' not worked");
    #endif

}//namespace

TEST_COMPONENT(000)
{
    dSTATIC_ASSERT(
        STATIC_ASSERT_NOT_WORKED,
        value
    );
}

//==============================================================================
//==============================================================================
#if 0
#include <tools/types/traits.hpp>

#if !defined(_MSC_VER) || _MSC_VER >= 1600
    // #pragma message("build for msvc2010 (or newer)")

    #define STATIC_ASSERT(msg, ...) \
        static_assert(__VA_ARGS__, #msg)
#else
    template<bool> struct static_assert_;
    template<> struct static_assert_<true> 
    {
        typedef void type;
    };


    //#define STATIC_ASSERT(COND,MSG) typedef char static_assertion_##MSG[(!!(COND))*2-1]

    #define dSTATIC_ASSERT_EX(msg, ...) \
        typedef static_assert_<__VA_ARGS__> msg

    #define dCOMPILE_TIME_ASSERT3(msg, L, ...) dSTATIC_ASSERT_EX(msg##L, __VA_ARGS__)
    #define dCOMPILE_TIME_ASSERT2(msg, L, ...) dCOMPILE_TIME_ASSERT3(msg,L, __VA_ARGS__)
    #define dCOMPILE_TIME_ASSERT1(msg, L, ...) dCOMPILE_TIME_ASSERT2(msg,L, __VA_ARGS__)

    #define STATIC_ASSERT(msg, ...) \
    typedef static_assert_<__VA_ARGS__>::type msg

        //dCOMPILE_TIME_ASSERT1(msg, __LINE__, __VA_ARGS__)
        
#endif

// STATIC_ASSERT(SAMPLE, false);

/*
STATIC_ASSERT(INTERNAL, dTRAIT::is_signed<unsigned>::value);
STATIC_ASSERT(INTERNAL, dTRAIT::is_signed<unsigned>::value);

STATIC_ASSERT(INTERNAL, dTRAIT::is_signed<signed>::value);
STATIC_ASSERT(INTERNAL, dTRAIT::is_signed<signed>::value);
*/

TEST_COMPONENT(001)
{
    STATIC_ASSERT(INTERNAL, dTRAIT::is_signed<signed>::value);
    STATIC_ASSERT(INTERNAL, dTRAIT::is_signed<signed>::value);
}
#endif
//==============================================================================
//==============================================================================
#endif // ! TEST_TOOLS_FEATURE_STASTIC_ASSERT



