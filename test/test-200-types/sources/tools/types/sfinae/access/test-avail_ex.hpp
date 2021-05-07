// [2021y-05m-07d][15:32:55] Idrisov Denis R.
#pragma once
#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::available;
//==============================================================================
//==============================================================================
namespace test_access
{
    #define dexpression(type, index, expected) \
        me::access<type, index>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, index, expected)                          \
            static_assert(                                                \
                dexpression(type, index, expected),                       \
                "tools::sfinae::available::access<" #type "," #index "> " \
                "must be '" #expected "'"                                 \
            )
    #else
        #define make_test(type, index, expected)   \
            dSTATIC_CHECK(                         \
                ERROR_MUST_BE_##expected,          \
                dexpression(type, index, expected) \
            )
    #endif

    #ifdef dHAS_RVALUE_REFERENCES
        #define make_rval(type, index, expected) \
            make_test(type, index, expected)
    #else
        #define make_rval(type, index, expected) \
            void()
    #endif

} // namespace test_access

using namespace test_access;
//==============================================================================
//==============================================================================
