// [2021y-03m-26d][01:58:39] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_FUNCTION

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_function
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
        #define dCHECK(type, expected)                     \
            static_assert(                                 \
                me::is_function<type>::value == expected,  \
                "'tools::is_function<" # type ">::value' " \
                "must be '" #expected "'"                  \
            )
    #else
        #define dCHECK(type, expected)                     \
            dSTATIC_ASSERT(                                \
                ERROR_MUST_BE_##expected,                  \
                me::is_function<type>::value == expected   \
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

    dCHECK(int()     , true );
    dCHECK(int(int)  , true );

    #ifdef dHAS_ABOMINABLE
    dCHECK(int(int)const, true);
    #endif
}

#ifdef dHAS_RVALUE_REFERENCES
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
#endif // !TEST_IS_FUNCTION

