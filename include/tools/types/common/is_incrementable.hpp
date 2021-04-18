// [2021y-04m-12d][16:04:38] Idrisov Denis R. 100
// [2021y-04m-14d][01:38:23] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_IS_INCREMENTABLE_USED_ 
#define dTOOLS_IS_INCREMENTABLE_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/is_incrementable/is_incrementable-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/is_incrementable/is_incrementable-2012.hpp>
#else
    #include <tools/types/common/is_incrementable/is_incrementable-2008.hpp>
#endif

//==============================================================================
//=============================================================================
#endif // !dTOOLS_IS_INCREMENTABLE_USED_
