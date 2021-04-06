// [2021y-04m-06d][15:43:33] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_FIND_TYPES_USED_ 
#define dTOOLS_FIND_TYPES_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_VARIADIC_TEMPLATE
    #include <tools/types/common/find_types/find_types-2013.hpp>
#else
    // msvc2012 or older
    #include <tools/types/common/find_types/find_types-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_FIND_TYPES_USED_
