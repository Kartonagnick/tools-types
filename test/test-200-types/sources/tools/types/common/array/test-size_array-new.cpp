// [2021y-02m-20d][18:40:18] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SIZE_ARRAY

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD size_array
#define dTEST_TAG new

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#include <tools/types/common.hpp>
namespace me = ::tools;
//==============================================================================
//=== macro ====================================================================
namespace
{
    #define dCHECK_TYPE(ty, etalon)                \
        static_assert(                             \
            ::std::is_same<                        \
                etalon,                            \
                typename me::size_array<ty>::type  \
            >::value,                              \
            "expected that "                       \
            "tools::size_array<" #ty ">::type"     \
            " -> '" #etalon "'"                    \
        )

    #define dCHECK_VALID(type, etalon)             \
        static_assert(                             \
            me::size_array<type>::valid == etalon, \
            "expected that "                       \
            "tools::size_array<" #type ">::valid"  \
            " -> '" #etalon "'"                    \
        )
    #define dCHECK_VALUE(type, etalon)             \
        static_assert(                             \
            me::size_array<type>::value == etalon, \
            "expected that "                       \
            "tools::size_array<" #type ">::value"  \
            " -> '" #etalon "'"                    \
        )
    #define dCHECK_BIG(type, etalon)               \
        static_assert(                             \
            me::size_array<type>::big == etalon,   \
            "expected that "                       \
            "tools::size_array<" #type ">::big"    \
            " -> '" #etalon "'"                    \
        )
    #define dCHECK_SMALL(type, etalon)             \
        static_assert(                             \
            me::size_array<type>::Small == etalon, \
            "expected that "                       \
            "tools::size_array<" #type ">::Small"  \
            " -> '" #etalon "'"                    \
        )
    #define dCHECK_EMPTY(type, etalon)             \
        static_assert(                             \
            me::size_array<type>::empty == etalon, \
            "expected that "                       \
            "tools::size_array<" #type ">::empty"  \
            " -> '" #etalon "'"                    \
        )
    #define dCHECK_ZERO(type, etalon)              \
        static_assert(                             \
            me::size_array<type>::zero == etalon,  \
            "expected that "                       \
            "tools::size_array<" #type ">::zero"   \
            " -> '" #etalon "'"                    \
        )

    #define dCHECK(type, based, valid, value, big, Small, empty, zero) \
        dCHECK_TYPE(type, based);  \
        dCHECK_VALID(type, valid); \
        dCHECK_VALUE(type, value); \
        dCHECK_BIG(type, big);     \
        dCHECK_SMALL(type, Small); \
        dCHECK_EMPTY(type, empty); \
        dCHECK_ZERO(type, zero)

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

} // namespace

//==============================================================================
//=== dHAS_ZERO_SIZE_ARRAY =====================================================
namespace
{
    #ifdef dHAS_ZERO_SIZE_ARRAY
    dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        dCHECK(int[0]                 , int               , 0, 0  , 0, 0, 0, 1);
        dCHECK(const int[0]           , const int         , 0, 0  , 0, 0, 0, 1);
        dCHECK(volatile int[0]        , volatile int      , 0, 0  , 0, 0, 0, 1);
        dCHECK(volatile const int[0]  , volatile const int, 0, 0  , 0, 0, 0, 1);
    dPRAGMA_POP
    #endif // !dHAS_ZERO_SIZE_ARRAY

} // namespace

//==============================================================================
//==============================================================================
namespace
{
    template<class s, dfor_small_array(s)>
    constexpr bool check(s&&) noexcept 
        { return true; }

    template<class s, dfor_big_array(s&&)>
    constexpr bool check(s&&) noexcept 
        { return false; }

    constexpr int g_small[2] = {};
    constexpr int g_big[256] = {};

    static_assert(check(g_small), "must be true");
    static_assert(!check(g_big), "must be false");
  
}//namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    int arr[2];
    ASSERT_TRUE(check(arr));
}
TEST_COMPONENT(001)
{
    int arr[256];
    ASSERT_TRUE(!check(arr));
}

//==============================================================================
//==============================================================================
#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_SIZE_ARRAY

