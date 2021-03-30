// [2021y-02m-20d][18:40:18] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SIZE_ARRAY

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD size_array
#define dTEST_TAG old

#include <tools/types/common.hpp>

#ifdef dHAS_TYPE_TRAITS
    namespace STD = ::std;
#else
    namespace STD = ::tools;
#endif

namespace me = ::tools;
//==============================================================================
//=== macro ====================================================================
namespace
{
    #define dEXPR(x, etalon)                         \
        STD::is_same<                                \
            typename me::size_array<x>::type, etalon \
        >::value

    #define dCHECK_TYPE(ty, etalon)           \
        dSTATIC_ASSERT(                        \
            ERROR_INTERNAL, dEXPR(ty, etalon)  \
        )

    #define dCHECK_VALID(type, etalon)             \
        dSTATIC_ASSERT(                            \
            me::size_array<type>::valid == etalon, \
            ERROR_INTERNAL                         \
        )
    #define dCHECK_VALUE(type, etalon)             \
        dSTATIC_ASSERT(                            \
            me::size_array<type>::value == etalon, \
            ERROR_INTERNAL                         \
        )
    #define dCHECK_BIG(type, etalon)               \
        dSTATIC_ASSERT(                            \
            me::size_array<type>::big == etalon,   \
            ERROR_INTERNAL                         \
        )
    #define dCHECK_SMALL(type, etalon)             \
        dSTATIC_ASSERT(                            \
            me::size_array<type>::Small == etalon, \
            ERROR_INTERNAL                         \
        )
    #define dCHECK_EMPTY(type, etalon)             \
        dSTATIC_ASSERT(                            \
            me::size_array<type>::empty == etalon, \
            ERROR_INTERNAL                         \
        )
    #define dCHECK_ZERO(type, etalon)              \
        dSTATIC_ASSERT(                            \
            me::size_array<type>::zero == etalon,  \
            ERROR_INTERNAL                         \
        )

    #define dCHECK(type, based, valid, value, big, Small, empty, zero) \
        dCHECK_TYPE(type, based);  \
        dCHECK_VALID(type, valid); \
        dCHECK_VALUE(type, value); \
        dCHECK_BIG(type, big);     \
        dCHECK_SMALL(type, Small); \
        dCHECK_EMPTY(type, empty); \
        dCHECK_ZERO(type, zero)

}//namespace

//==============================================================================
//==============================================================================
namespace
{
    #define dfor_big_(arr) \
        dif_big_array(arr, bool)

    #define dfor_small_(arr) \
        dif_small_array(arr, bool)

    template<class s>
    inline dfor_small_(s) check(s&) dNOEXCEPT 
        { return true; }

    template<class s>
    inline dfor_big_(s) check(s&) dNOEXCEPT 
        { return false; }
  
}//namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    const int g_small[2] = {};
    const int g_big[256] = {};
    ASSERT_TRUE(check(g_small));
    ASSERT_TRUE(!check(g_big));
}

TEST_COMPONENT(001)
{
    dCHECK(int                    , int               , 0, 0  , 0, 0, 0, 0);
    dCHECK(int[5]                 , int               , 1, 5  , 0, 1, 0, 0);
    dCHECK(int[256]               , int               , 1, 256, 1, 0, 0, 0);
    dCHECK(int[]                  , int               , 1, 0  , 0, 0, 1, 0);
                                                      
    dCHECK(const int              , const int         , 0, 0  , 0, 0, 0, 0);
    dCHECK(const int[5]           , const int         , 1, 5  , 0, 1, 0, 0);
    dCHECK(const int[256]         , const int         , 1, 256, 1, 0, 0, 0);
    dCHECK(const int[]            , const int         , 1, 0  , 0, 0, 1, 0);
                                                      
    dCHECK(volatile int           , volatile int      , 0, 0  , 0, 0, 0, 0);
    dCHECK(volatile int[5]        , volatile int      , 1, 5  , 0, 1, 0, 0);
    dCHECK(volatile int[256]      , volatile int      , 1, 256, 1, 0, 0, 0);
    dCHECK(volatile int[]         , volatile int      , 1, 0  , 0, 0, 1, 0);

    dCHECK(volatile const int     , volatile const int, 0, 0  , 0, 0, 0, 0);
    dCHECK(volatile const int[5]  , volatile const int, 1, 5  , 0, 1, 0, 0);
    dCHECK(volatile const int[256], volatile const int, 1, 256, 1, 0, 0, 0);
    dCHECK(volatile const int[]   , volatile const int, 1, 0  , 0, 0, 1, 0);
}

#ifdef dHAS_ZERO_SIZE_ARRAY
TEST_COMPONENT(002)
{
    dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        dCHECK(int[0]                 , int               , 0, 0  , 0, 0, 0, 1);
        dCHECK(const int[0]           , const int         , 0, 0  , 0, 0, 0, 1);
        dCHECK(volatile int[0]        , volatile int      , 0, 0  , 0, 0, 0, 1);
        dCHECK(volatile const int[0]  , volatile const int, 0, 0  , 0, 0, 0, 1);
    dPRAGMA_POP
}
#endif // !dHAS_ZERO_SIZE_ARRAY

TEST_COMPONENT(003)
{
    int arr[2];
    ASSERT_TRUE(check(arr));
}
TEST_COMPONENT(004)
{
    int arr[256];
    ASSERT_TRUE(!check(arr));
}

//==============================================================================
//==============================================================================

#endif // !TEST_TOOLS_SIZE_ARRAY

