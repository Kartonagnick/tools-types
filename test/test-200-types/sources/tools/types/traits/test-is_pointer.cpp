// [2021y-03m-24d][20:28:49] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_POINTER

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_pointer
#define dTEST_TAG tdd

#include <tools/types/traits.hpp>
#include <tools/features.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                     \
            static_assert(                                 \
                me::is_pointer<type>::value == expected,   \
                "'tools::is_pointer<" # type ">::value' "  \
                "must be '" #expected "'"                  \
            )
    #else
        #define dCHECK(type, expected)                     \
            dSTATIC_ASSERT(                                \
                me::is_pointer<type>::value == expected,   \
                ERROR_MUST_BE_##expected                   \
            )
    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int                       , false);
    dCHECK(int*                      , true );
    dCHECK(int&                      , false);
    dCHECK(int[1]                    , false);
    dCHECK(int(*)[1]                 , true );
    dCHECK(int(&)[1]                 , false);

    dCHECK(volatile int             , false );
    dCHECK(volatile int*            , true  );
    dCHECK(volatile int&            , false );
    dCHECK(volatile int[1]          , false );
    dCHECK(volatile int(*)[1]       , true  );
    dCHECK(volatile int(&)[1]       , false );

    dCHECK(const int                , false );
    dCHECK(const int*               , true  );
    dCHECK(const int&               , false );
    dCHECK(const int[1]             , false );
    dCHECK(const int(*)[1]          , true  );
    dCHECK(const int(&)[1]          , false );
                                            
    dCHECK(volatile const int       , false );
    dCHECK(volatile const int*      , true  );
    dCHECK(volatile const int&      , false );
    dCHECK(volatile const int[1]    , false );
    dCHECK(volatile const int(*)[1] , true  );
    dCHECK(volatile const int(&)[1] , false );
                                            
    dCHECK(const int                , false );
    dCHECK(int*const                , true  );
    dCHECK(int*const volatile       , true  );
    dCHECK(const int&               , false );
    dCHECK(const int[1]             , false );
    dCHECK(int(*const)[1]           , true  );
    dCHECK(int(*volatile)[1]        , true  );
    dCHECK(int(*volatile const)[1]  , true  );
    dCHECK(const int(&)[1]          , false );

    dCHECK(int*const&               , false );
    dCHECK(int*const volatile&      , false );
    dCHECK(int(*const&)[1]          , false );
    dCHECK(int(*volatile&)[1]       , false );
    dCHECK(int(*volatile const&)[1] , false );
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_POINTER

