// [2021y-03m-26d][01:58:39] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_CONVERTIBLE

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_convertible
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

    #define dEXPRESSION(from, to, expected) \
        me::is_convertible<from, to>::value == expected

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(from, to, expected)                          \
            static_assert(                                          \
                dEXPRESSION(from, to, expected),                    \
                "tools::is_convertible<" #from ", " #to ">::value " \
                "must be '" #expected "'"                           \
            )
    #else
        #define dCHECK(from, to, expected)      \
            dSTATIC_ASSERT(                     \
                ERROR_MUST_BE_##expected,       \
                dEXPRESSION(from, to, expected) \
            )
    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(B, B, true );
    dCHECK(B, D, false);
    dCHECK(D, B, true );

    dCHECK(int, B  , false);
    dCHECK(D  , int, false);
    dCHECK(int, int, true );
}

TEST_COMPONENT(001)
{
    dCHECK(int       , float, true);
    dCHECK(float     , int  , true);
}

TEST_COMPONENT(002)
{
    dCHECK(int       , int          , true );
    dCHECK(int       , int&         , false);
    dCHECK(int       , const int    , true );
    dCHECK(int       , const int&   , true );

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(int       , const int&&  , true);
    dCHECK(int       , int&&        , true);
    #endif
}

TEST_COMPONENT(003)
{
    dCHECK(int&      , int          , true );
    dCHECK(int&      , int&         , true );
    dCHECK(int&      , const int    , true );
    dCHECK(int&      , const int&   , true );

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(int&      , const int&&  , false);
    dCHECK(int&      , int&&        , false);
    #endif
}

TEST_COMPONENT(004)
{
    dCHECK(const int       , int          , true );
    dCHECK(const int       , int&         , false);
    dCHECK(const int       , const int    , true );
    dCHECK(const int       , const int&   , true );

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(const int       , const int&&  , true );
    dCHECK(const int       , int&&        , false);
    #endif
}

TEST_COMPONENT(005)
{
    dCHECK(const int&      , int          , true );
    dCHECK(const int&      , int&         , false);
    dCHECK(const int&      , const int    , true );
    dCHECK(const int&      , const int&   , true );

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(const int&      , const int&&  , false);
    dCHECK(const int&      , int&&        , false);
    #endif
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_CONVERTIBLE

