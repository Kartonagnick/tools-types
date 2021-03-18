// [2021y-03m-10d][02:14:35] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_SAME

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_same
#define dTEST_TAG tdd

#include <tools/types/traits.hpp>
#include <tools/features.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(a, b, v)                            \
            static_assert(                                 \
                me::is_same<a,b>::value == v,              \
                "'tools::is_same<" #a ", " #b ">::value' " \
                "must be '" #v "'"                         \
            )
    #else
        #define dCHECK(a, b, v)            \
        {                                  \
            typedef me::is_same<a,b> y;    \
            dSTATIC_ASSERT(                \
                y::value == v,             \
                ERROR_MUST_BE_##expected   \
            );                             \
        } void()

    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int , int       , true );
    dCHECK(int , char      , false);
    dCHECK(char, bool      , false);
    dCHECK(char, const char, false);
    dCHECK(char, char&     , false);
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_SAME

