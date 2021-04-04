// [2021y-03m-22d][03:30:55] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_VERSION_USED_
#define dTOOLS_VERSION_USED_ 100
//===============================================================================
//===============================================================================
#include <tools/macro/overload-5.hpp>

#define dSTRINGIZE(...) #__VA_ARGS__
#define dSSTRINGIZE(x) dSTRINGIZE(x)

//===============================================================================
//=== [COMPACT] =================================================================

#define dVERSION_COMPACT_STR_0()                   error_0
#define dVERSION_COMPACT_STR_1(a1)                 dSSTRINGIZE(a1)
#define dVERSION_COMPACT_STR_2(a1, a2)             dSSTRINGIZE(a1.a2)
#define dVERSION_COMPACT_STR_3(a1, a2, a3)         dSSTRINGIZE(a1.a2.a3)
#define dVERSION_COMPACT_STR_4(a1, a2, a3, a4)     dSSTRINGIZE(a1.a2.a3.a4)
#define dVERSION_COMPACT_STR_5(a1, a2, a3, a4, a5) dSSTRINGIZE(a1.a2.a3.a4.a5)
#define dVERSION_COMPACT_STR(...) \
    dMACRO_CHOOSER_5(dVERSION_COMPACT_STR, __VA_ARGS__)(__VA_ARGS__)

// compact version format: 9.99.9.99.999
#define dVERSION_COMPACT_NUM_0()                   error_0
#define dVERSION_COMPACT_NUM_1(a1)                 a1 * 100000000
#define dVERSION_COMPACT_NUM_2(a1, a2)             a1 * 100000000 + a2 * 1000000
#define dVERSION_COMPACT_NUM_3(a1, a2, a3)         a1 * 100000000 + a2 * 1000000 + a3 * 100000
#define dVERSION_COMPACT_NUM_4(a1, a2, a3, a4)     a1 * 100000000 + a2 * 1000000 + a3 * 100000 + a4 * 1000
#define dVERSION_COMPACT_NUM_5(a1, a2, a3, a4, a5) a1 * 100000000 + a2 * 1000000 + a3 * 100000 + a4 * 1000 + a5
#define dVERSION_COMPACT_NUM(...) \
    dMACRO_CHOOSER_5(dVERSION_COMPACT_NUM, __VA_ARGS__)(__VA_ARGS__)

//==============================================================================
//=== [CLASSIC] ================================================================

// classic version format: 99.99.99.999
#define dVERSION_CLASSIC_NUM_0()                   error_0
#define dVERSION_CLASSIC_NUM_1(a1)                 a1 * 10000000
#define dVERSION_CLASSIC_NUM_2(a1, a2)             a1 * 10000000 + a2 * 100000
#define dVERSION_CLASSIC_NUM_3(a1, a2, a3)         a1 * 10000000 + a2 * 100000 + a3 * 1000
#define dVERSION_CLASSIC_NUM_4(a1, a2, a3, a4)     a1 * 10000000 + a2 * 100000 + a3 * 1000 + a4
#define dVERSION_CLASSIC_NUM_5(a1, a2, a3, a4, a5) dVERSION_CLASSIC_NUM_4(a1, a2, a3, a4)

#define dVERSION_CLASSIC_NUM(...) \
    dMACRO_CHOOSER_5(dVERSION_CLASSIC_NUM, __VA_ARGS__)(__VA_ARGS__)
#define dVERSION_CLASSIC_STR(...) dVERSION_COMPACT_STR(__VA_ARGS__)

//==============================================================================
//=== [PLUGIN] =================================================================

// plugin version format: 12345678.99
#define dVERSION_PLUGIN_NUM_0()                   error_0
#define dVERSION_PLUGIN_NUM_1(a1)                 a1 * 100
#define dVERSION_PLUGIN_NUM_2(a1, a2)             a1 * 100 + a2
#define dVERSION_PLUGIN_NUM_3(a1, a2, a3)         dVERSION_PLUGIN_NUM_2(a1, a2)
#define dVERSION_PLUGIN_NUM_4(a1, a2, a3, a4)     dVERSION_PLUGIN_NUM_2(a1, a2)
#define dVERSION_PLUGIN_NUM_5(a1, a2, a3, a4, a5) dVERSION_PLUGIN_NUM_2(a1, a2)

#define dVERSION_PLUGIN_NUM(...) \
    dMACRO_CHOOSER_5(dVERSION_PLUGIN_NUM, __VA_ARGS__)(__VA_ARGS__)
#define dVERSION_PLUGIN_STR(...) dVERSION_COMPACT_STR(__VA_ARGS__)

//==============================================================================
//=== [TOOLS] ==================================================================

// tools`s version format: 123.2008
#define dVERSION_TOOLS_NUM_0()                   error_0
#define dVERSION_TOOLS_NUM_1(a1)                 a1 * 10000
#define dVERSION_TOOLS_NUM_2(a1, a2)             a1 * 10000 + a2
#define dVERSION_TOOLS_NUM_3(a1, a2, a3)         dVERSION_TOOLS_NUM_2(a1, a2)
#define dVERSION_TOOLS_NUM_4(a1, a2, a3, a4)     dVERSION_TOOLS_NUM_2(a1, a2)
#define dVERSION_TOOLS_NUM_5(a1, a2, a3, a4, a5) dVERSION_TOOLS_NUM_2(a1, a2)

#define dVERSION_TOOLS_NUM(...) \
    dMACRO_CHOOSER_5(dVERSION_TOOLS_NUM, __VA_ARGS__)(__VA_ARGS__)
#define dVERSION_TOOLS_STR(...) dVERSION_COMPACT_STR(__VA_ARGS__)

//==============================================================================
//=== [common] =================================================================

#define dMAKE_STR_VERSION_0()       make_str_version_0
#define dMAKE_STR_VERSION_1(a1)     dVERSION_COMPACT_STR(a1##_VERSION)
#define dMAKE_STR_VERSION_2(a1, a2) dVERSION_##a1##_STR(a2##_VERSION)

#define dMAKE_STR_VERSION(...) \
    dMACRO_CHOOSER_5(dMAKE_STR_VERSION, __VA_ARGS__)(__VA_ARGS__)

#define dMAKE_NUM_VERSION_0()       make_num_version_0
#define dMAKE_NUM_VERSION_1(a1)     dVERSION_COMPACT_NUM(a1##_VERSION)
#define dMAKE_NUM_VERSION_2(a1, a2) dVERSION_##a1##_NUM(a2##_VERSION)

#define dMAKE_NUM_VERSION(...) \
    dMACRO_CHOOSER_5(dMAKE_NUM_VERSION, __VA_ARGS__)(__VA_ARGS__)

#define dVERSION_STR(...) dVERSION_COMPACT_STR(__VA_ARGS__)
#define dVERSION_NUM(...) dVERSION_COMPACT_NUM(__VA_ARGS__)

//==============================================================================
//==============================================================================
#endif // !dTOOLS_VERSION_USED_








//==============================================================================
//==============================================================================

#if 0

// usage:
#define dTYPES0_VERSION 0
#define dTYPES1_VERSION 9
#define dTYPES2_VERSION 9,99
#define dTYPES3_VERSION 9,99,9
#define dTYPES4_VERSION 9,99,9,99
#define dTYPES5_VERSION 9,99,9,99,999

#include<tools/version.hpp>
#include<iostream>

#if dMAKE_NUM_VERSION(dTYPES1) >= dMAKE_NUM_VERSION(dTYPES2)
    #pragma message("--1--")
#else
    #pragma message("--2--")
#endif

int main()
{
    std::cout << dMAKE_STR_VERSION(dTYPES0) << '\n';
    std::cout << dMAKE_NUM_VERSION(dTYPES0) << '\n';
    
    std::cout << dMAKE_STR_VERSION(dTYPES1) << '\n';
    std::cout << dMAKE_NUM_VERSION(dTYPES1) << '\n';
    
    std::cout << dMAKE_STR_VERSION(dTYPES2) << '\n';
    std::cout << dMAKE_NUM_VERSION(dTYPES2) << '\n';
    
    std::cout << dMAKE_STR_VERSION(dTYPES3) << '\n';
    std::cout << dMAKE_NUM_VERSION(dTYPES3) << '\n';

    std::cout << dMAKE_STR_VERSION(dTYPES4) << '\n';
    std::cout << dMAKE_NUM_VERSION(dTYPES4) << '\n';

    std::cout << dMAKE_STR_VERSION(dTYPES5) << '\n';
    std::cout << dMAKE_NUM_VERSION(dTYPES5) << '\n';
}

#endif

//==============================================================================
//==============================================================================
