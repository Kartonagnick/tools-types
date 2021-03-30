// [2021y-03m-14d][22:10:18] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_REMOVE_ALL_EXTENSION

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD remove_all_extent
#define dTEST_TAG tdd

#include <tools/types/traits.hpp>
#include <tools/features.hpp>
namespace me = ::tools;

#ifndef _MSC_VER
    #pragma GCC diagnostic ignored "-Wignored-qualifiers"
#endif

//==============================================================================
//=== TDD ======================================================================
namespace
{
    #define dVAL(a) \
        typename me::remove_all_extent<a>::type

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(a, b)                                \
            static_assert(                                  \
                me::is_same<dVAL(a), b>::value,             \
                "'tools::remove_all_extent<" #a ">::type' " \
                "must be '" #b "'"                          \
            )
    #else
        #define dCHECK(a, b)                          \
        {                                             \
            typedef me::remove_all_extent<a>::type x; \
            typedef me::is_same<x, b> y;              \
            dSTATIC_ASSERT(                           \
                ERROR_MUST_BE_##expected, y::value    \
            );                                        \
        } void()

    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int[]    , int);
    dCHECK(int[1]   , int);
    dCHECK(int[1][2], int);
}

TEST_COMPONENT(001)
{
    dCHECK(const int[]    , const int);
    dCHECK(const int[1]   , const int);
    dCHECK(const int[1][2], const int);
}

TEST_COMPONENT(002)
{
    dCHECK(volatile int[]    , volatile int);
    dCHECK(volatile int[1]   , volatile int);
    dCHECK(volatile int[1][2], volatile int);
}

TEST_COMPONENT(003)
{
    dCHECK(volatile const int[]    , volatile const int);
    dCHECK(volatile const int[1]   , volatile const int);
    dCHECK(volatile const int[1][2], volatile const int);
}

//==============================================================================
//==============================================================================
#endif // !TEST_REMOVE_ALL_EXTENSION

