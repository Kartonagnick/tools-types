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

    dSTATIC_ASSERT(
        STATIC_ASSERT_NOT_WORKED, 
        value
    );

    void check_zone() dNOEXCEPT
    {
        dSTATIC_CHECK(
            STATIC_CHECK_NOT_WORKED, 
            value
        );
    }

}//namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    check_zone();
}

TEST_COMPONENT(001)
{
    dSTATIC_ASSERT(
        STATIC_ASSERT_NOT_WORKED, 
        value
    );
}

TEST_COMPONENT(002)
{
    dSTATIC_CHECK(
        STATIC_CHECK_NOT_WORKED, 
        value
    );
}


//==============================================================================
//==============================================================================
#endif // ! TEST_TOOLS_FEATURE_STASTIC_ASSERT



