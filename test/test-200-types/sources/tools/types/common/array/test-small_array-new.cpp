// [2021y-02m-20d][18:40:18] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SMALL_ARRAY

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD small_array
#define dTEST_TAG new

#include <tools/types/common.hpp>
//==============================================================================
//==============================================================================
namespace
{
    template<class s1, class s2, dfor_small_arrays(s1, s2)>
    constexpr bool check(s1&&, s2&&) noexcept
        { return true; }

    template<class s1, class s2, dfor_big_arrays(s1, s2)>
    constexpr bool check(s1&&, s2&&) noexcept
        { return false; }

    constexpr int g_arr[256] = {};

    static_assert( check("123", "123"), "must be true" );
    static_assert(!check("123", g_arr), "must be false");
    static_assert(!check(g_arr, "123"), "must be false");
    static_assert(!check(g_arr, g_arr), "must be false");
  
}//namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    ASSERT_TRUE(check("123", "123"));
}
TEST_COMPONENT(001)
{
    int arr[256];
    ASSERT_TRUE(!check("123", arr));
}
TEST_COMPONENT(002)
{
    int arr[256];
    ASSERT_TRUE(!check(arr, "123"));
}

//==============================================================================
//==============================================================================

#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_IS_ZERO_ARRAY

