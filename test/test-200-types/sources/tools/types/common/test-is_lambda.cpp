// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-20d][05:14:05] Idrisov Denis R.
// [2021y-04m-06d][23:09:28] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_LAMBDA

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_lambda
#define dTEST_TAG tdd

#include <tools/types/common.hpp>
#include <utility>

namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                    \
            static_assert(                                \
                me::is_lambda<type>::value == expected,   \
                "'tools::is_lambda<" # type ">::value' "  \
                "must be '" #expected "'"                 \
            )
    #else
        #define dCHECK(type, expected)                \
        dSTATIC_ASSERT(                               \
            ERROR_INTERNAL,                           \
            me::is_lambda<type>::value == expected    \
        )
    #endif

    struct some   { bool operator()()  const; };
    struct foo    { bool& operator()() const; };

} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int         , false);
    dCHECK(some        , true );
    dCHECK(some&       , true );
    dCHECK(const some  , true );
    dCHECK(const some& , true );

    dCHECK(const foo&  , true );
    dCHECK(foo&        , true );
    dCHECK(foo         , true );

    #ifdef dHAS_RVALUE_REFERENCE
        dCHECK(some&&      , true);
        dCHECK(const some&&, true);

        dCHECK(foo&&       , true);
        dCHECK(const foo&& , true);
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
#endif // !TEST_TOOLS_IS_LAMBDA

