// [2021y-04m-12d][16:12:10] Idrisov Denis R. 100
// [2021y-04m-14d][01:40:54] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_IS_DECREMENTABLE_USED_ 
#define dTOOLS_IS_DECREMENTABLE_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/is_decrementable/is_decrementable-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/is_decrementable/is_decrementable-2012.hpp>
#else
    #include <tools/types/common/is_decrementable/is_decrementable-2008.hpp>
#endif

//==============================================================================
//=============================================================================
#endif // !dTOOLS_IS_DECREMENTABLE_USED_
