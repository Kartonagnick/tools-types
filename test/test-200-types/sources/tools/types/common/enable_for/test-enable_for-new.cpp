// [2021y-02m-20d][18:49:18] Idrisov Denis R.
// [2021y-04m-10d][01:18:47] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_ENABLE_FOR

#include <tools/features.hpp>
#ifdef dHAS_USING_ALIAS

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD enable_for
#define dTEST_TAG new

#include <tools/types/common.hpp>
namespace me = ::tools;
//==============================================================================
namespace
{
    // 't' can be 'char' or 'wchar_t' only
    template<class t, me::enable_for_t<t, char, wchar_t>* = nullptr>
    bool check(const t&) dNOEXCEPT
        { return true; }

    // 't' can not be 'char' and 'wchar_t' 
    template<class t, me::disable_for_t<t, char, wchar_t>* = nullptr>
    bool check(const t&) dNOEXCEPT
        { return false; }



    // 't' must be 'char' or 'wchar_t' only
    template<class t, dfor_enabled(t, char, wchar_t)>
    bool check_consept(const t&) dNOEXCEPT
        { return true; }

    // 't' can not be 'char' and 'wchar_t' 
    template<class t, dfor_disabled(t, char, wchar_t)>
    bool check_consept(const t&) dNOEXCEPT
        { return false; }



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
TEST_COMPONENT(000)
{
    ASSERT_TRUE( check( 'a'));
    ASSERT_TRUE( check(L'a'));
    ASSERT_TRUE(!check(10  ));
}
TEST_COMPONENT(001)
{
    ASSERT_TRUE( check_consept( 'a'));
    ASSERT_TRUE( check_consept(L'a'));
    ASSERT_TRUE(!check_consept(10  ));
}

TEST_COMPONENT(002)
{
    ASSERT_TRUE( check_return( 'a'));
    ASSERT_TRUE( check_return(L'a'));
    ASSERT_TRUE(!check_return(10  ));
}

//==============================================================================
//==============================================================================
#endif // !dHAS_USING_ALIAS
#endif // !TEST_TOOLS_ENABLE_FOR

