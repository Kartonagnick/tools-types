// [2021y-05m-04d][21:27:57] Idrisov Denis R.
#pragma once
#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::available;
//==============================================================================
//==============================================================================
namespace test_access
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

} // namespace test_access

//==============================================================================
//==============================================================================

namespace test_access
{
    #define dexpression_ex(type, index, expected) \
        me::access<type, index>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test_ex(type, index, expected)                       \
            static_assert(                                                \
                dexpression_ex(type, index, expected),                    \
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
        #define make_rval_ex(type, index, expected) \
            make_test(type, index, expected)
    #else
        #define make_rval_ex(type, index, expected) \
            void()
    #endif

} // namespace test_access


using namespace test_access;
//==============================================================================
//==============================================================================
