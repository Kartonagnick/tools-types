// [2021y-03m-10d][02:14:35] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_INTEGRAL

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_integral
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
                me::is_integral<type>::value == expected,  \
                "'tools::is_integral<" # type ">::value' " \
                "must be '" #expected "'"                  \
            )
    #else
        #define dCHECK(type, expected)                     \
            dSTATIC_ASSERT(                                \
                ERROR_MUST_BE_##expected,                  \
                me::is_integral<type>::value == expected   \
            )
    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(wchar_t  , true);

#if !defined(_MSC_VER) || _MSC_VER >= 1600
    dCHECK(char16_t          , true );
    dCHECK(char32_t          , true );
#endif

#ifdef __cpp_char8_t
    dCHECK(char8_t           , true );
#endif 

    dCHECK(short             , true );
    dCHECK(int               , true );
    dCHECK(long              , true );
    dCHECK(long long         , true );

    dCHECK(unsigned short    , true );
    dCHECK(unsigned int      , true );
    dCHECK(unsigned long     , true );
    dCHECK(unsigned long long, true );
    dCHECK(unsigned          , true );
    dCHECK(size_t            , true );


    dCHECK(signed char       , true );
    dCHECK(unsigned char     , true );
    dCHECK(float             , false);
    dCHECK(double            , false);
    dCHECK(long double       , false);
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_INTEGRAL

