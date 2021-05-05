// [2021y-05m-05d][23:02:09] Idrisov Denis R.
#pragma once
#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::signature;
//==============================================================================
//==============================================================================
namespace test_dereference
{
    #define dexpression(type, sig, expected) \
        me::dereference<type, sig>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, sig, expected)                               \
            static_assert(                                                   \
                dexpression(type, sig, expected),                            \
                "tools::sfinae::signature::dereference<" #type "," #sig "> " \
                "must be '" #expected "'"                                    \
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

} // namespace test_dereference

using namespace test_dereference;
//==============================================================================
//==============================================================================
