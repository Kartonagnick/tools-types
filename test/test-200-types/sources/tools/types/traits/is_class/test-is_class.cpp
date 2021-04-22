// [2021y-03m-10d][02:14:35] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_CLASS

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_class
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
                me::is_class<type>::value == expected,  \
                "'tools::is_class<" # type ">::value' " \
                "must be '" #expected "'"               \
            )
    #else
        #define dCHECK(type, expected)                  \
            dSTATIC_ASSERT(                             \
                ERROR_MUST_BE_##expected,               \
                me::is_class<type>::value == expected   \
            )
    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(wchar_t  , false);

    #if !defined(_MSC_VER) || _MSC_VER >= 1600
    // build for msvc2010 
    dCHECK(char16_t          , false);
    dCHECK(char32_t          , false);
    #endif

    dCHECK(short             , false);
    dCHECK(unsigned short    , false);
    dCHECK(int               , false);
    dCHECK(unsigned          , false);
    dCHECK(long              , false);
    dCHECK(unsigned long     , false);
    dCHECK(unsigned long long, false);
    dCHECK(size_t            , false);
    dCHECK(unsigned          , false);

    dCHECK(signed char       , false);
    dCHECK(unsigned char     , false);
    dCHECK(float             , false);
    dCHECK(double            , false);
    dCHECK(long double       , false);
}

TEST_COMPONENT(001)
{
    dCHECK(const some, true);
    dCHECK(some  , true );
    dCHECK(some& , false);
    dCHECK(some* , false);
    dCHECK(some*&, false);

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(some&&, false);
    #endif
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_CLASS

