// [2021y-04m-04d][23:22:49] Idrisov Denis R. 100
// [2021y-04m-10d][07:18:56] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_ARRAY_USED_ 
#define dTOOLS_ARRAY_USED_ 101

#include <tools/pragma/pragma.hpp>
#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/array/array-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/array/array-2012.hpp>
#else
    #include <tools/types/common/array/array-2008.hpp>
#endif


//==============================================================================
//==============================================================================
#endif // !dTOOLS_ARRAY_USED_
