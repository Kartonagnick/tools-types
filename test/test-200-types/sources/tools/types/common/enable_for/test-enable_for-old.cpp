// [2021y-02m-20d][18:49:18] Idrisov Denis R.
// [2021y-04m-10d][01:18:47] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_ENABLE_FOR

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD enable_for
#define dTEST_TAG old

#include <tools/types/common.hpp>
namespace me = ::tools;
//==============================================================================
namespace
{
    // 't' must be 'char' or 'wchar_t' only
    template<class t>
    dif_enabled(bool, t, char, wchar_t) 
    check_return(const t&) dNOEXCEPT
        { return true; }

    // 't' can not be 'char' and 'wchar_t' 
    template<class t>
    dif_disabled(bool, t, char, wchar_t) 
    check_return(const t&) dNOEXCEPT
        { return false; }
  
} // namespace
//==============================================================================
TEST_COMPONENT(002)
{
    ASSERT_TRUE( check_return('a' ));
    ASSERT_TRUE( check_return(L'a'));
    ASSERT_TRUE(!check_return(10  ));
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_ENABLE_FOR

