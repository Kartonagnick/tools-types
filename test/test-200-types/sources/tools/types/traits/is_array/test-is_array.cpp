// [2021y-03m-26d][02:11:12] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_ARRAY

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_array
#define dTEST_TAG tdd

#include <tools/types/traits.hpp>
#include <tools/features.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    struct some;

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                  \
            static_assert(                              \
                me::is_array<type>::value == expected,  \
                "'tools::is_array<" # type ">::value' " \
                "must be '" #expected "'"               \
            )
    #else
        #define dCHECK(type, expected)                  \
            dSTATIC_ASSERT(                             \
                ERROR_MUST_BE_##expected,               \
                me::is_array<type>::value == expected   \
            )
    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int       , false);
    dCHECK(int&      , false);
    dCHECK(const int , false);
    dCHECK(const int&, false);

    dCHECK(int(&)()  , false);
    dCHECK(int(*)()  , false);

    dCHECK(int()     , false );
    dCHECK(int(int)  , false );

    #ifdef dHAS_ABOMINABLE
    dCHECK(int(int)const, false);
    #endif

    dCHECK(int[1]         , true );
    dCHECK(int[1][2]      , true );
    dCHECK(const int[1][2], true );

    dCHECK(int(&)[1]         , false );
    dCHECK(int(&)[1][2]      , false );
    dCHECK(const int(&)[1][2], false );

    #ifdef dHAS_RVALUE_REFERENCE
    dCHECK(int(&&)[1]         , false );
    dCHECK(int(&&)[1][2]      , false );
    dCHECK(const int(&&)[1][2], false );
    #endif

    dCHECK(int(*)[1]         , false );
    dCHECK(int(*)[1][2]      , false );
    dCHECK(const int(*)[1][2], false );
}

#ifdef dHAS_RVALUE_REFERENCE
TEST_COMPONENT(001)
{
    dCHECK(int&&       , false);
    dCHECK(const int&& , false);
    dCHECK(int(&&)()   , false);
    dCHECK(int(*&)()   , false);
}
#endif

//==============================================================================
//==============================================================================
#endif // !TEST_IS_ARRAY

