// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-20d][05:14:05] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_FUNCTOR

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_functor
#define dTEST_TAG tdd

#include <tools/types/common.hpp>
#include <utility>

namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    struct some
    {
        bool operator()() const dNOEXCEPT { return false; }
    };

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                    \
            static_assert(                                \
                me::is_functor<type>::value == expected,  \
                "'tools::is_functor<" # type ">::value' " \
                "must be '" #expected "'"                 \
            )

    #else
        #define dCHECK(type, expected)                \
        dSTATIC_ASSERT(                               \
            ERROR_INTERNAL,                           \
            me::is_functor<type>::value == expected   \
        )
    #endif

}//namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int         , false);
    dCHECK(some        , true );
    dCHECK(some&       , true );
    dCHECK(const some  , true );
    dCHECK(const some& , true );

    #ifdef dHAS_RVALUE_REFERENCE
        dCHECK(some&&, true);
        dCHECK(const some&&, true);
    #endif
}

#ifdef dHAS_LAMBDA
TEST_COMPONENT(001)
{
    const auto call = [](){};
    typedef decltype(call) x;
    dCHECK(x, true);
    (void) call;
}
TEST_COMPONENT(002)
{
    const auto call = [](bool) mutable{};
    typedef decltype(call) x;
    dCHECK(x, true);
    (void) call;
}
#endif // dHAS_LAMBDA

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_IS_FUNCTOR

