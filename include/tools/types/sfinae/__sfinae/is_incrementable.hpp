// [2021y-04m-12d][16:04:38] Idrisov Denis R. 100
// [2021y-04m-14d][01:38:23] Idrisov Denis R. 100

// [2021y-04m-21d][12:57:27] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_IS_INCREMENTABLE_USED_ 
#define dTOOLS_IS_INCREMENTABLE_USED_ 101 PRE

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/sfinae/is_incrementable/is_incrementable-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/sfinae/is_incrementable/is_incrementable-2012.hpp>
#else
    #include <tools/types/sfinae/is_incrementable/is_incrementable-2008.hpp>
#endif

//==============================================================================
//=============================================================================
#endif // !dTOOLS_IS_INCREMENTABLE_USED_
