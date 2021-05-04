// [2021y-05m-04d][21:27:57] Idrisov Denis R.
#pragma once
#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::available;
//==============================================================================
//==============================================================================
namespace test_begin
{
    #define dexpression(type, expected) \
        me::access<type>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, expected)                      \
            static_assert(                                     \
                dexpression(type, expected),                   \
                "tools::sfinae::available::access<" #type "> " \
                "must be '" #expected "'"                      \
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

} // namespace test_begin
using namespace test_begin;
//==============================================================================
//==============================================================================
