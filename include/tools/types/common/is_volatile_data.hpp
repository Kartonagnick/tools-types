// [2021y-04m-06d][20:54:59] Idrisov Denis R. 100
// [2021y-04m-10d][04:42:17] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_IS_VOLATILE_DATA_USED_ 
#define dTOOLS_IS_VOLATILE_DATA_USED_ 101 PRE

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/is_volatile_data/is_volatile_data-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/is_volatile_data/is_volatile_data-2012.hpp>
#else
    #include <tools/types/common/is_volatile_data/is_volatile_data-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_VOLATILE_DATA_USED_
