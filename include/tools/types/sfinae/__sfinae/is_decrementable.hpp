// [2021y-04m-12d][16:12:10] Idrisov Denis R. 100
// [2021y-04m-14d][01:40:54] Idrisov Denis R. 100
// [2021y-04m-21d][13:25:21] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_IS_DECREMENTABLE_USED_ 
#define dTOOLS_IS_DECREMENTABLE_USED_ 101 PRE

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/sfinae/is_decrementable/is_decrementable-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/sfinae/is_decrementable/is_decrementable-2012.hpp>
#else
    #include <tools/types/sfinae/is_decrementable/is_decrementable-2008.hpp>
#endif

//==============================================================================
//=============================================================================
#endif // !dTOOLS_IS_DECREMENTABLE_USED_
