// [2021y-03m-10d][02:14:35] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TYPE_OF_ENUM

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD type_of_enum
#define dTEST_TAG tdd

#include <tools/features.hpp>

#ifndef dHAS_ENUM_CLASS
    dMESSAGE("[test] tools: disabled -> dHAS_ENUM_CLASS")
#else

dMESSAGE("[test] tools: enabled -> dHAS_ENUM_CLASS")
#include <tools/types/traits.hpp>

namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #ifdef dHAS_USING_ALIAS
        #define dVAL(a) \
            me::type_of_enum_t<a>
    #else
        #define dVAL(a) \
            typename me::type_of_enum<a>::type
    #endif

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(a, b, v)                          \
            static_assert(                               \
                me::is_same<dVAL(a),b>::value == v,      \
                "'tools::type_of_enum_t<" #a ">::type' " \
                "must be '" #v "'"                       \
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
#endif // !dHAS_ENUM_CLASS
#endif // !TEST_TYPE_OF_ENUM

