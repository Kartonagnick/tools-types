// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-20d][06:22:01] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_ZERO_ARRAY

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_zero_array
#define dTEST_TAG tdd

#include <tools/types/common.hpp>

namespace me = ::tools;
//==============================================================================
//=== macro ====================================================================
namespace
{
    #define dexpression(type, expected) \
        me::is_zero_array<type>::value == expected

    #ifdef dHAS_STATIC_ASSERT
        #define make_test(type, expected)          \
            static_assert(                         \
                dexpression(type, expected),       \
                "tools::is_zero_array<" #type "> " \
                "must be '" #expected "'"          \
            )

        make_test(int    , false);
        make_test(int[1] , false);
        make_test(int[]  , false);

        #ifdef dHAS_ZERO_SIZE_ARRAY
            dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
            make_test(int[0] , true );
            dPRAGMA_POP
        #endif // !dHAS_ZERO_SIZE_ARRAY

        // do not remove this dublicate !

        make_test(int    , false);
        make_test(int[1] , false);
        make_test(int[]  , false);

        #ifdef dHAS_ZERO_SIZE_ARRAY
            dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
            make_test(int[0] , true );
            dPRAGMA_POP
        #endif // !dHAS_ZERO_SIZE_ARRAY

    #else
        #define make_test(type, expected)    \
            dSTATIC_ASSERT(                  \
                dexpression(type, expected), \
                ERROR_INTERNAL               \
            )

    #endif // dHAS_STATIC_ASSERT

} // namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    make_test(int    , false);
    make_test(int[1] , false);
    make_test(int[]  , false);

    #ifdef dHAS_ZERO_SIZE_ARRAY
        dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        make_test(int[0] , true );
        dPRAGMA_POP
    #endif // !dHAS_ZERO_SIZE_ARRAY
}

//==============================================================================
//==============================================================================

#endif // !TEST_TOOLS_IS_ZERO_ARRAY

