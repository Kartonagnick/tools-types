// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-17d][20:25:15] Idrisov Denis R.
// [2021y-03m-19d][22:03:35] Idrisov Denis R. 102
// [2021y-03m-20d][19:43:08] Idrisov Denis R. 103
// [2021y-03m-21d][04:01:28] Idrisov Denis R. 104
// [2021y-03m-23d][23:55:08] Idrisov Denis R. 105
// [2021y-03m-29d][22:19:10] Idrisov Denis R. 106 PRE
#pragma once
#ifndef dTOOLS_COMMON_USED_ 
#define dTOOLS_COMMON_USED_ 106 PRE

#include <tools/features.hpp>
#include <tools/pragma/pragma.hpp>

//==============================================================================
//==============================================================================

#ifdef dHAS_CPP11
    // dMESSAGE("[c++11][types/common]")
    #include <tools/types/common/common-msvc2015.hpp>
#elif dHAS_USING_ALIAS
    // dMESSAGE("[alias][types/common]")
    #include <tools/types/common/common-msvc2013.hpp>
#else
    // dMESSAGE("[old][types/common]")
    #include <tools/types/common/common-msvc2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMMON_USED_
