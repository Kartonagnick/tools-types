// [2021y-02m-20d][18:40:18] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SMALL_ARRAY

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD small_array
#define dTEST_TAG old

#include <tools/types/common.hpp>
//==============================================================================
//==============================================================================

namespace
{
    template<class s1, class s2>
    dif_big_arrays(s1, s2, bool)
    check(s1&, s2&) { return false; }
    
    template<class s1, class s2>
    dif_small_arrays(s1, s2, bool)
    check(s1&, s2&) { return true; }
  
} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    const int g_arr[256] = {};

    ASSERT_TRUE( check("123", "123"));
    ASSERT_TRUE(!check("123", g_arr));
    ASSERT_TRUE(!check(g_arr, "123"));
    ASSERT_TRUE(!check(g_arr, g_arr));
}

TEST_COMPONENT(001)
{
    ASSERT_TRUE(check("123", "123"));
}
TEST_COMPONENT(002)
{
    int arr[256];
    ASSERT_TRUE(!check("123", arr));
}
TEST_COMPONENT(003)
{
    int arr[256];
    ASSERT_TRUE(!check(arr, "123"));
}

//==============================================================================
//==============================================================================

#endif // !TEST_TOOLS_IS_ZERO_ARRAY

