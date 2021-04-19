// [2021y-03m-10d][12:44:35] Idrisov Denis R.
// [2021y-04m-02d][23:54:49] Idrisov Denis R.
// [2021y-04m-03d][23:13:40] Idrisov Denis R. 101
// [2021y-04m-04d][07:05:55] Idrisov Denis R. 102
// [2021y-04m-19d][16:24:10] Idrisov Denis R. 103 PRE
#pragma once
#ifndef dTOOLS_FIXED_USED_
#define dTOOLS_FIXED_USED_ 103 PRE
//==============================================================================
//==============================================================================

#include <tools/features.hpp>
#ifdef dHAS_CPP11
    // msvc2015 (or newer)
    #include <tools/types/fixed/fixed-cpp11.hpp>
#else
    #include <tools/types/fixed/fixed-cpp98.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_FIXED_USED_
