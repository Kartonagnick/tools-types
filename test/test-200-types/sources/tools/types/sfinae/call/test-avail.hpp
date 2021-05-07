// [2021y-05m-07d][17:10:153] Idrisov Denis R.
#pragma once
#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::available;
//==============================================================================
//==============================================================================
namespace test_call
{
    #define dexpression(type, expected) \
        me::call<type>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, expected)                    \
            static_assert(                                   \
                dexpression(type, expected),                 \
                "tools::sfinae::available::call<" #type "> " \
                "must be '" #expected "'"                    \
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

} // namespace test_call
using namespace test_call;
//==============================================================================
//==============================================================================
