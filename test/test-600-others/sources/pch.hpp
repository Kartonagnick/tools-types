﻿// [2021y-02m-16d][00:01:43] Idrisov Denis R.
// [2021y-02m-16d][00:01:43] birthday of the project
// [2021y-03m-31d][22:18:58] Idrisov Denis R.
#pragma once
//================================================================================
//================================================================================

#if defined(_MSC_VER) && !defined(WIN32_LEAN_AND_MEAN)
    #define WIN32_LEAN_AND_MEAN
#endif

//==============================================================================
//=== [pch] ====================================================================

#define dPCH_USED 1
#include <tools/pragma/view_build.hpp>

//==============================================================================
//=== [view build`s info =======================================================
#include <tools/types/version.hpp>
dVIEW_BUILD("[test-600-others]", dTYPES)

//==============================================================================
//=== [mygtest] ================================================================
#include <mygtest/pch_used.hpp>
#include <mygtest/main.hpp>

//================================================================================
//================================================================================

#include <tools/features.hpp>
#include <tools/assert.hpp>
#include <cassert>
#include <cstddef>
