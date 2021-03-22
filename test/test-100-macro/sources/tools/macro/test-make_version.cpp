// [2021y-03m-22d][03:44:57] Idrisov Denis R.
#include <mygtest/modern.hpp>
//=================================================================================
//=================================================================================

#ifdef TEST_TOOLS_MAKE_VERSION

#define dTEST_COMPONENT tools
#define dTEST_METHOD version
#define dTEST_TAG tdd

#include <tools/features.hpp>
#include <tools/macro/make_version.hpp>
#include <string>

#define dMY_VERSION 1,22,3,44,555
dMESSAGE("example version: " dMAKE_STR_VERSION(dMY))
dMESSAGE("example version: " dVERSION_STR(dMY_VERSION))

#define dMAX_VERSION 9,99,9,99,999
dMESSAGE("example version: " dMAKE_STR_VERSION(dMAX))
dMESSAGE("example version: " dVERSION_STR(dMAX_VERSION))

//==============================================================================
//==============================================================================

namespace
{
    typedef std::string str_t;

} // namespace

TEST_COMPONENT(000)
{
    const size_t v1 = dVERSION_NUM(1);
    ASSERT_EQ(v1, 100000000u);

    const size_t v2 = dVERSION_NUM(9);
    ASSERT_EQ(v2, 900000000u);

    const size_t v3 = dVERSION_NUM(9,1);
    dprint(std::cout << v3 << '\n');
    ASSERT_EQ(v3, 901000000u);

    const size_t v4 = dVERSION_NUM(9,10);
    dprint(std::cout << v4 << '\n');
    ASSERT_EQ(v4, 910000000u);

    const size_t v5 = dVERSION_NUM(9,99);
    dprint(std::cout << v5 << '\n');
    ASSERT_EQ(v5, 999000000u);

    const size_t v6 = dVERSION_NUM(9,99,1);
    dprint(std::cout << v6 << '\n');
    ASSERT_EQ(v6, 999100000u);

    const size_t v7 = dVERSION_NUM(9,99,9);
    dprint(std::cout << v7 << '\n');
    ASSERT_EQ(v7, 999900000u);

    const size_t v8 = dVERSION_NUM(9,99,9);
    dprint(std::cout << v8 << '\n');
    ASSERT_EQ(v8, 999900000u);

    const size_t v9 = dVERSION_NUM(9,99,9,1);
    dprint(std::cout << v9 << '\n');
    ASSERT_EQ(v9, 999901000u);

    const size_t v10 = dVERSION_NUM(9,99,9,12);
    dprint(std::cout << v10 << '\n');
    ASSERT_EQ(v10, 999912000u);

    const size_t v11 = dVERSION_NUM(9,99,9,99);
    dprint(std::cout << v11 << '\n');
    ASSERT_EQ(v11, 999999000u);

    const size_t v12 = dVERSION_NUM(9,99,9,99,1);
    dprint(std::cout << v12 << '\n');
    ASSERT_EQ(v12, 999999001u);

    const size_t v13 = dVERSION_NUM(9,99,9,99,12);
    dprint(std::cout << v13 << '\n');
    ASSERT_EQ(v13, 999999012u);

    const size_t v14 = dVERSION_NUM(9,99,9,99,124);
    dprint(std::cout << v14 << '\n');
    ASSERT_EQ(v14, 999999124u);

    const size_t v15 = dVERSION_NUM(9,99,9,99,999);
    dprint(std::cout << v15 << '\n');
    ASSERT_EQ(v15, 999999999u);
}

TEST_COMPONENT(001)
{
    const str_t v1 = dMAKE_STR_VERSION(dMY);
    const str_t v2 = dVERSION_STR(dMY_VERSION);
    const str_t v3 = dVERSION_STR(1,22,3,44,555);
    const str_t v4 = "1.22.3.44.555";

    ASSERT_EQ(v1, v2);
    ASSERT_EQ(v1, v2);
    ASSERT_EQ(v1, v3);
    ASSERT_EQ(v1, v4);
}
TEST_COMPONENT(002)
{
    const str_t v1 = dMAKE_STR_VERSION(dMAX);
    const str_t v2 = dVERSION_STR(dMAX_VERSION);
    const str_t v3 = dVERSION_STR(9,99,9,99,999);
    const str_t v4 = "9.99.9.99.999";

    ASSERT_EQ(v1, v2);
    ASSERT_EQ(v1, v2);
    ASSERT_EQ(v1, v3);
    ASSERT_EQ(v1, v4);
}

TEST_COMPONENT(003)
{
    #if dVERSION_NUM(1) != dVERSION_NUM(1)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(1,2) != dVERSION_NUM(1,2)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(9,99) != dVERSION_NUM(9,99)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(9,99,9) != dVERSION_NUM(9,99,9)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(9,99,9,99) != dVERSION_NUM(9,99,9,99)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(9,99,9,99,9) != dVERSION_NUM(9,99,9,99,9)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(9,99,9,99,99) != dVERSION_NUM(9,99,9,99,99)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(9,99,9,99,999) != dVERSION_NUM(9,99,9,99,999)
        #error internal error --1--
    #endif
}
TEST_COMPONENT(004)
{
    #if dVERSION_NUM(2) < dVERSION_NUM(1)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2) < dVERSION_NUM(1,1)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2) < dVERSION_NUM(1,1,1)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2) < dVERSION_NUM(1,1,1,1)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2) < dVERSION_NUM(1,1,1,1,1)
        #error internal error --1--
    #endif
}

TEST_COMPONENT(005)
{
    #if dVERSION_NUM(2) < dVERSION_NUM(1)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2) < dVERSION_NUM(1,99)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2) < dVERSION_NUM(1,99,9)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2) < dVERSION_NUM(1,99,9,99)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2) < dVERSION_NUM(1,99,9,99,999)
        #error internal error --1--
    #endif
}

TEST_COMPONENT(006)
{
    #if dVERSION_NUM(2,1) < dVERSION_NUM(2)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2,99,2) < dVERSION_NUM(2,99,1)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2,99,9,1) < dVERSION_NUM(2,99,9)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(2,99,9,99,1) < dVERSION_NUM(2,99,9,99)
        #error internal error --1--
    #endif

    #if dVERSION_NUM(3) < dVERSION_NUM(2,99,9,99,999)
        #error internal error --1--
    #endif
}

TEST_COMPONENT(007)
{
    #define dAAA_VERSION 0
    #define dBBB_VERSION 9
    #define dCCC_VERSION 9,99
    #define dDDD_VERSION 9,99,9
    #define dFFF_VERSION 9,99,9,99
    #define dGGG_VERSION 9,99,9,99,999

    {
        dprint(std::cout << dMAKE_STR_VERSION(dAAA) << '\n');
        dprint(std::cout << dMAKE_NUM_VERSION(dAAA) << '\n');
        const str_t txt  = dMAKE_STR_VERSION(dAAA);
        const size_t num = dMAKE_NUM_VERSION(dAAA);
        ASSERT_EQ(txt, "0");
        ASSERT_EQ(num, 0u);
    }
    {
        dprint(std::cout << dMAKE_STR_VERSION(dBBB) << '\n');
        dprint(std::cout << dMAKE_NUM_VERSION(dBBB) << '\n');
        const str_t txt  = dMAKE_STR_VERSION(dBBB);
        const size_t num = dMAKE_NUM_VERSION(dBBB);
        ASSERT_EQ(txt, "9");
        ASSERT_EQ(num, 900000000u);
    }
    {
        dprint(std::cout << dMAKE_STR_VERSION(dCCC) << '\n');
        dprint(std::cout << dMAKE_NUM_VERSION(dCCC) << '\n');
        const str_t txt  = dMAKE_STR_VERSION(dCCC);
        const size_t num = dMAKE_NUM_VERSION(dCCC);
        ASSERT_EQ(txt, "9.99");
        ASSERT_EQ(num, 999000000u);
    }
    {
        dprint(std::cout << dMAKE_STR_VERSION(dDDD) << '\n');
        dprint(std::cout << dMAKE_NUM_VERSION(dDDD) << '\n');
        const str_t txt  = dMAKE_STR_VERSION(dDDD);
        const size_t num = dMAKE_NUM_VERSION(dDDD);
        ASSERT_EQ(txt, "9.99.9");
        ASSERT_EQ(num, 999900000u);
    }
    {
        dprint(std::cout << dMAKE_STR_VERSION(dFFF) << '\n');
        dprint(std::cout << dMAKE_NUM_VERSION(dFFF) << '\n');
        const str_t txt  = dMAKE_STR_VERSION(dFFF);
        const size_t num = dMAKE_NUM_VERSION(dFFF);
        ASSERT_EQ(txt, "9.99.9.99");
        ASSERT_EQ(num, 999999000u);
    }
    {
        dprint(std::cout << dMAKE_STR_VERSION(dGGG) << '\n');
        dprint(std::cout << dMAKE_NUM_VERSION(dGGG) << '\n');
        const str_t txt  = dMAKE_STR_VERSION(dGGG);
        const size_t num = dMAKE_NUM_VERSION(dGGG);
        ASSERT_EQ(txt, "9.99.9.99.999");
        ASSERT_EQ(num, 999999999u);
    }
}

//==============================================================================
//=== [CLASSIC] ================================================================
TEST_COMPONENT(008)
{
    {
        #define dCLASSIC_VERSION 12,34,56,78,999
        const str_t  s1 = dMAKE_STR_VERSION(dCLASSIC);
        const size_t v1 = dMAKE_NUM_VERSION(CLASSIC, dCLASSIC);
        ASSERT_EQ(s1, "12.34.56.78.999");
        ASSERT_EQ(v1, 123456078u);
        #undef dCLASSIC_VERSION
    }
    {
        #define dCLASSIC_VERSION 12,34,56,789,123
        const str_t  s1 = dMAKE_STR_VERSION(dCLASSIC);
        const size_t v1 = dMAKE_NUM_VERSION(CLASSIC, dCLASSIC);
        ASSERT_EQ(s1, "12.34.56.789.123");
        ASSERT_EQ(v1, 123456789u);
        #undef dCLASSIC_VERSION
    }
}

//==============================================================================
//=== [PLUGIN] =================================================================
TEST_COMPONENT(009)
{
    // plugins:
    //          0 - 0.00
    //          1 - 0.01
    //         21 - 0.21
    //        321 - 3.21
    //       4321 - 43.21
    //      54321 - 543.21
    // 1234567891 - 12345678.99

    {
        #define dPLUGIN_VERSION 123,99
        const str_t  s1 = dMAKE_STR_VERSION(dPLUGIN);
        const size_t v1 = dMAKE_NUM_VERSION(PLUGIN, dPLUGIN);
        ASSERT_EQ(s1, "123.99");
        ASSERT_EQ(v1, 12399u);
        #undef dPLUGIN_VERSION
    }
    {
        #define dPLUGIN_VERSION 1234567,89
        const str_t  s1 = dMAKE_STR_VERSION(dPLUGIN);
        const size_t v1 = dMAKE_NUM_VERSION(PLUGIN, dPLUGIN);
        ASSERT_EQ(s1, "1234567.89");
        ASSERT_EQ(v1, 123456789u);
        #undef dPLUGIN_VERSION
    }
    {
        #define dPLUGIN_VERSION 12345678,91
        const str_t  s1 = dMAKE_STR_VERSION(dPLUGIN);
        const size_t v1 = dMAKE_NUM_VERSION(PLUGIN, dPLUGIN);
        ASSERT_EQ(s1, "12345678.91");
        ASSERT_EQ(v1, 1234567891u);
        #undef dPLUGIN_VERSION
    }
}

//==============================================================================
//=== [TOOLS] ==================================================================

TEST_COMPONENT(010)
{
    {
        #define dTOOLS_COMPONENT_VERSION 0,2008
        const str_t  s1 = dMAKE_STR_VERSION(TOOLS, dTOOLS_COMPONENT);
        const size_t v1 = dMAKE_NUM_VERSION(TOOLS, dTOOLS_COMPONENT);
        ASSERT_EQ(s1, "0.2008");
        ASSERT_EQ(v1, 2008u);
        #undef dTOOLS_COMPONENT_VERSION
    }
    {
        #define dTOOLS_COMPONENT_VERSION 1,2008
        const str_t  s1 = dMAKE_STR_VERSION(TOOLS, dTOOLS_COMPONENT);
        const size_t v1 = dMAKE_NUM_VERSION(TOOLS, dTOOLS_COMPONENT);
        ASSERT_EQ(s1, "1.2008");
        ASSERT_EQ(v1, 12008u);
        #undef dTOOLS_COMPONENT_VERSION
    }
    {
        #define dTOOLS_COMPONENT_VERSION 123,2008
        const str_t  s1 = dMAKE_STR_VERSION(TOOLS, dTOOLS_COMPONENT);
        const size_t v1 = dMAKE_NUM_VERSION(TOOLS, dTOOLS_COMPONENT);
        ASSERT_EQ(s1, "123.2008");
        ASSERT_EQ(v1, 1232008u);
        #undef dTOOLS_COMPONENT_VERSION
    }
    {
        #define dTOOLS_COMPONENT_VERSION 999,2008
        const str_t  s1 = dMAKE_STR_VERSION(TOOLS, dTOOLS_COMPONENT);
        const size_t v1 = dMAKE_NUM_VERSION(TOOLS, dTOOLS_COMPONENT);
        ASSERT_EQ(s1, "999.2008");
        ASSERT_EQ(v1, 9992008u);
        #undef dTOOLS_COMPONENT_VERSION
    }
    {
        #define dTOOLS_COMPONENT_VERSION 1999,2008
        const str_t  s1 = dMAKE_STR_VERSION(TOOLS, dTOOLS_COMPONENT);
        const size_t v1 = dMAKE_NUM_VERSION(TOOLS, dTOOLS_COMPONENT);
        ASSERT_EQ(s1, "1999.2008");
        ASSERT_EQ(v1, 19992008u);
        #undef dTOOLS_COMPONENT_VERSION
    }
    {
        #define dTOOLS_COMPONENT_VERSION 19999,2008
        const str_t  s1 = dMAKE_STR_VERSION(TOOLS, dTOOLS_COMPONENT);
        const size_t v1 = dMAKE_NUM_VERSION(TOOLS, dTOOLS_COMPONENT);
        ASSERT_EQ(s1, "19999.2008");
        ASSERT_EQ(v1, 199992008u);
        #undef dTOOLS_COMPONENT_VERSION
    }
}

//==============================================================================
//==============================================================================
#endif // ! TEST_TOOLS_FEATURE_ABOMINABLE
