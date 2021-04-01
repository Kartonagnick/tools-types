// [2021y-02m-25d][04:21:08] Idrisov Denis R.
#include <mygtest/modern.hpp>
//=================================================================================
//=================================================================================

#ifdef TEST_TOOLS_FEATURE_ARRAY_EMTY_SIZE

#define dTEST_COMPONENT tools, features
#define dTEST_METHOD test_HAS_ARRAY_EMTY_SIZE
#define dTEST_TAG tdd

#include <tools/features.hpp>

#include <cassert>

#ifdef dHAS_ARRAY_EMPTY_SIZE
    dMESSAGE("[test] tools: enabled -> dHAS_ARRAY_EMPTY_SIZE")
#else
    dMESSAGE("[test] tools: disabled -> dHAS_ARRAY_EMPTY_SIZE")
#endif

//==============================================================================
//==============================================================================

#ifdef dHAS_ARRAY_EMPTY_SIZE
TEST_COMPONENT(000) 
{
    typedef int arr1[];
    typedef int arr2[][1];

    arr1* p1 = 0;
    arr2* p2 = 0;

    ASSERT_TRUE(!p1);
    ASSERT_TRUE(!p2);
}
#endif

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_FEATURE_ARRAY_EMTY_SIZE

