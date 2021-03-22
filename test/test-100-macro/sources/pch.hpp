// [2021y-03m-22d][07:47:05] Idrisov Denis R.
// [2021y-03m-22d][07:47:05] birthday of the project
#pragma once
//==============================================================================
//=== [pch] ====================================================================

#define dPCH_USED 1
#include <tools/pragma/view_build.hpp>

//==============================================================================
//=== [view build`s info =======================================================
#include <tools/types/version.hpp>
dVIEW_BUILD("[test-000-platform]", dTYPES)

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
//=== [unit-test] ==============================================================

#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>

#ifdef dHAS_ATOMIC
    #include <thread>
    #include <future>
    #include <atomic>
#endif

#ifdef dHAS_CHRONO
    #include <chrono>
#endif

#ifdef dHAS_CSTDINT
    #include <cstdint>
#endif

#ifdef dHAS_HASH
    #include <functional>
#endif

//==============================================================================
//==============================================================================

