// [2021y-05m-04d][21:27:57] Idrisov Denis R.
#pragma once
#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::signature;
//==============================================================================
//==============================================================================
namespace test_access
{
    #define dexpression(type, sig, expected) \
        me::access<type, sig>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, sig, expected)                          \
            static_assert(                                              \
                dexpression(type, sig, expected),                       \
                "tools::sfinae::signature::access<" #type "," #sig "> " \
                "must be '" #expected "'"                               \
            )
    #else
        #define make_test(type, sig, expected)   \
            dSTATIC_CHECK(                       \
                ERROR_MUST_BE_##expected,        \
                dexpression(type, sig, expected) \
            )
    #endif

    #ifdef dHAS_RVALUE_REFERENCES
        #define make_rval(type, sig, expected) \
            make_test(type, sig, expected)
    #else
        #define make_rval(type, sig, expected) \
            void()
    #endif

} // namespace test_access
using namespace test_access;
//==============================================================================
//==============================================================================
