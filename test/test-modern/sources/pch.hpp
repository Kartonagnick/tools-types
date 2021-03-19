﻿// [2021y-02m-16d][23:00:41] Idrisov Denis R.
// [2021y-02m-20d][23:00:41] birthday of the project
#pragma once
//==============================================================================
//=== [pch] ====================================================================

#define dPCH_USED 1
#include <tools/pragma/view_build.hpp>

//==============================================================================
//=== [view build`s info =======================================================
#include <tools/types/version.hpp>
dVIEW_BUILD("[test-modern]", dTYPES)

//==============================================================================
//=== [mygtest] ================================================================
#include <mygtest/pch_used.hpp>
#include <mygtest/main.hpp>

//==============================================================================
//=== [tools] ==================================================================
#include <tools/dfunction.hpp>
#include <tools/features.hpp>
#include <tools/assert.hpp>

//==============================================================================
//=== [standart] ===============================================================
#include <stdexcept>
#include <cassert>
#include <cstddef>

#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>
#endif

//==============================================================================
//==============================================================================

