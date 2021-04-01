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
    #define dEXPRESSION(a, b, v) \
        me::is_same<a, b>::value == v

    #define dCHECK(a, b, v)      \
        dSTATIC_ASSERT(          \
            ERROR_MUST_BE_##v,   \
            dEXPRESSION(a, b, v) \
        )

} // namespace

dCHECK(int , int       , true );
dCHECK(int , char      , false);
dCHECK(char, bool      , false);
dCHECK(char, const char, false);
dCHECK(char, char&     , false);

//==============================================================================
//==============================================================================

TEST_COMPONENT(000){}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_SAME

