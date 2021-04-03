// [2021y-03m-23d][23:29:01] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_VOLATILE

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_volatile
#define dTEST_TAG tdd

#include <tools/types/traits.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                     \
            static_assert(                                 \
                me::is_volatile<type>::value == expected,  \
                "'tools::is_volatile<" # type ">::value' " \
                "must be '" #expected "'"                  \
            )
    #else
        #define dCHECK(type, expected)                     \
            dSTATIC_ASSERT(                                \
                ERROR_MUST_BE_##expected,                  \
                me::is_volatile<type>::value == expected   \
            )
    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int      , false);
    dCHECK(int*     , false);
    dCHECK(int&     , false);
    dCHECK(int[1]   , false);
    dCHECK(int(*)[1], false);
    dCHECK(int(&)[1], false);

    dCHECK(volatile int      , true );
    dCHECK(volatile int*     , false);
    dCHECK(volatile int&     , false);
    dCHECK(volatile int[1]   , true );
    dCHECK(volatile int(*)[1], false);
    dCHECK(volatile int(&)[1], false);

    dCHECK(const int      , false);
    dCHECK(const int*     , false);
    dCHECK(const int&     , false);
    dCHECK(const int[1]   , false);
    dCHECK(const int(*)[1], false);
    dCHECK(const int(&)[1], false);

    dCHECK(volatile const int      , true );
    dCHECK(volatile const int*     , false);
    dCHECK(volatile const int&     , false);
    dCHECK(volatile const int[1]   , true );
    dCHECK(volatile const int(*)[1], false);
    dCHECK(volatile const int(&)[1], false);

    dCHECK(const int              , false);
    dCHECK(int*const              , false);
    dCHECK(int*const volatile     , true );
    dCHECK(const int&             , false);
    dCHECK(const int[1]           , false);
    dCHECK(int(*const)[1]         , false);
    dCHECK(int(*volatile)[1]      , true );
    dCHECK(int(*volatile const)[1], true );
    dCHECK(const int(&)[1]        , false);
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_VOLATILE

