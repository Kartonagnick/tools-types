// [2021y-05m-04d][16:34:05] Idrisov Denis R.
#pragma once
#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::exist;
//==============================================================================
//==============================================================================
namespace test_end
{
    #define dexpression(type, expected) \
        me::end<type>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, expected)               \
            static_assert(                              \
                dexpression(type, expected),            \
                "tools::sfinae::exist::end<" #type "> " \
                "must be '" #expected "'"               \
            )
    #else
        #define make_test(type, expected)   \
            dSTATIC_CHECK(                  \
                ERROR_MUST_BE_##expected,   \
                dexpression(type, expected) \
            )
    #endif

    #ifdef dHAS_RVALUE_REFERENCES
        #define make_rval(type, expected) \
            make_test(type, expected)
    #else
        #define make_rval(type, expected) \
            void()
    #endif

} // namespace test_end
using namespace test_end;
//==============================================================================
//==============================================================================
