// [2021y-03m-26d][01:58:39] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_BASE_OF

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_base_of
#define dTEST_TAG tdd

#include <tools/types/traits.hpp>
#include <tools/features.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    struct B {};
    struct D : B {};

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(B, D, expected)                          \
            static_assert(                                      \
                me::is_base_of<B, D>::value == expected,        \
                "'tools::is_base_of<" # B ", " # D ">::value' " \
                "must be '" #expected "'"                       \
            )
    #else
        #define dEXPRESSION(B, D, expected) \
            me::is_base_of<B,D>::value == expected

        #define dCHECK(B, D, expected)      \
            dSTATIC_ASSERT(                 \
                dEXPRESSION(B,D, expected), \
                ERROR_MUST_BE_##expected    \
            )
    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(B, B, true );
    dCHECK(B, D, true );
    dCHECK(D, B, false);

    dCHECK(int, B  , false);
    dCHECK(D  , int, false);
    dCHECK(int, int, true );
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_BASE_OF

