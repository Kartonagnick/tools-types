// [2021y-04m-21d][23:27:37] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_REFERENCE

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_rvalue_reference
#define dTEST_TAG tdd

#include <tools/types/traits.hpp>
#include <tools/features.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                             \
            static_assert(                                         \
                me::is_rvalue_reference<type>::value == expected,  \
                "tools::is_rvalue_reference<" # type ">::value "   \
                "must be '" #expected "'"                          \
            )
    #else
        #define dCHECK(type, expected)                             \
            dSTATIC_ASSERT(                                        \
                ERROR_MUST_BE_##expected,                          \
                me::is_rvalue_reference<type>::value == expected   \
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
    dCHECK(int&                      , false);
    dCHECK(int[1]                    , false);
    dCHECK(int(*)[1]                 , false);
    dCHECK(int(&)[1]                 , false);
    dRVAL_(int(&&)[1]                , true );
                                     
    dCHECK(volatile int              , false);
    dCHECK(volatile int*             , false);
    dCHECK(volatile int&             , false);
    dCHECK(volatile int[1]           , false);
    dCHECK(volatile int(*)[1]        , false);
    dCHECK(volatile int(&)[1]        , false);
    dRVAL_(volatile int(&&)[1]       , true );
                                     
    dCHECK(const int                 , false);
    dCHECK(const int*                , false);
    dCHECK(const int&                , false);
    dCHECK(const int[1]              , false);
    dCHECK(const int(*)[1]           , false);
    dCHECK(const int(&)[1]           , false);
    dRVAL_(const int(&&)[1]          , true );
                                             
    dCHECK(volatile const int        , false);
    dCHECK(volatile const int*       , false);
    dCHECK(volatile const int&       , false);
    dCHECK(volatile const int[1]     , false);
    dCHECK(volatile const int(*)[1]  , false);
    dCHECK(volatile const int(&)[1]  , false);
    dRVAL_(volatile const int(&&)[1] , true );
                                            
    dCHECK(const int                 , false);
    dCHECK(int*const                 , false);
    dCHECK(int*const volatile        , false);
    dCHECK(const int&                , false);
    dCHECK(const int[1]              , false);
    dCHECK(int(*const)[1]            , false);
    dCHECK(int(*volatile)[1]         , false);
    dCHECK(int(*volatile const)[1]   , false);
    dCHECK(const int(&)[1]           , false);
    dRVAL_(const int(&&)[1]          , true );

    dCHECK(int*const&                , false);
    dCHECK(int*const volatile&       , false);
    dCHECK(int(*const&)[1]           , false);
    dCHECK(int(*volatile&)[1]        , false);
    dCHECK(int(*volatile const&)[1]  , false);

    dRVAL_(int*const&&               , true );
    dRVAL_(int*const volatile&&      , true );
    dRVAL_(int(*const&&)[1]          , true );
    dRVAL_(int(*volatile&&)[1]       , true );
    dRVAL_(int(*volatile const&&)[1] , true );
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_REFERENCE

