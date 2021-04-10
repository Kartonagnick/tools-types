// [2021y-04m-06d][15:43:33] Idrisov Denis R. 100
// [2021y-04m-10d][02:48:58] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_FIND_TYPES_USED_ 
#define dTOOLS_FIND_TYPES_USED_ 101 PRE

#include <tools/features.hpp>

#ifdef dHAS_VARIADIC_TEMPLATE
    #include <tools/types/common/find_type/find_type-2013.hpp>
#else
    // msvc2012 or older
    #include <tools/types/common/find_type/find_type-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_FIND_TYPES_USED_
