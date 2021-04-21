// [2021y-04m-21d][23:27:37] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_REFERENCE

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_lvalue_reference
#define dTEST_TAG tdd

#include <tools/types/traits.hpp>
#include <tools/features.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                            \
            static_assert(                                        \
                me::is_lvalue_reference<type>::value == expected, \
                "tools::is_lvalue_reference<" # type ">::value "  \
                "must be '" #expected "'"                         \
            )
    #else
        #define dCHECK(type, expected)                            \
            dSTATIC_ASSERT(                                       \
                ERROR_MUST_BE_##expected,                         \
                me::is_lvalue_reference<type>::value == expected  \
            )
    #endif

    #ifdef dHAS_RVALUE_REFERENCES
        #define dRVAL_(type, expected) \
            dCHECK(type, expected)
    #else
        #define dRVAL_(type, expected)
    #endif

} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int                       , false);
    dCHECK(int*                      , false);
    dCHECK(int&                      , true );
    dCHECK(int[1]                    , false);
    dCHECK(int(*)[1]                 , false);
    dCHECK(int(&)[1]                 , true );
    dRVAL_(int(&&)[1]                , false);
                                     
    dCHECK(volatile int              , false);
    dCHECK(volatile int*             , false);
    dCHECK(volatile int&             , true );
    dCHECK(volatile int[1]           , false);
    dCHECK(volatile int(*)[1]        , false);
    dCHECK(volatile int(&)[1]        , true );
    dRVAL_(volatile int(&&)[1]       , false);
                                     
    dCHECK(const int                 , false);
    dCHECK(const int*                , false);
    dCHECK(const int&                , true );
    dCHECK(const int[1]              , false);
    dCHECK(const int(*)[1]           , false);
    dCHECK(const int(&)[1]           , true );
    dRVAL_(const int(&&)[1]          , false);
                                             
    dCHECK(volatile const int        , false);
    dCHECK(volatile const int*       , false);
    dCHECK(volatile const int&       , true );
    dCHECK(volatile const int[1]     , false);
    dCHECK(volatile const int(*)[1]  , false);
    dCHECK(volatile const int(&)[1]  , true );
    dRVAL_(volatile const int(&&)[1] , false);
                                            
    dCHECK(const int                 , false);
    dCHECK(int*const                 , false);
    dCHECK(int*const volatile        , false);
    dCHECK(const int&                , true );
    dCHECK(const int[1]              , false);
    dCHECK(int(*const)[1]            , false);
    dCHECK(int(*volatile)[1]         , false);
    dCHECK(int(*volatile const)[1]   , false);
    dCHECK(const int(&)[1]           , true );
    dRVAL_(const int(&&)[1]          , false);

    dCHECK(int*const&                , true );
    dCHECK(int*const volatile&       , true );
    dCHECK(int(*const&)[1]           , true );
    dCHECK(int(*volatile&)[1]        , true );
    dCHECK(int(*volatile const&)[1]  , true );

    dRVAL_(int*const&&               , false);
    dRVAL_(int*const volatile&&      , false);
    dRVAL_(int(*const&&)[1]          , false);
    dRVAL_(int(*volatile&&)[1]       , false);
    dRVAL_(int(*volatile const&&)[1] , false);
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_REFERENCE

