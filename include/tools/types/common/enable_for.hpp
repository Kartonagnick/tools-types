// [2021y-04m-10d][01:40:44] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_ENABLE_FOR_USED_ 
#define dTOOLS_ENABLE_FOR_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/enable_for/enable_for-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/enable_for/enable_for-2012.hpp>
#else
    #include <tools/types/common/enable_for/enable_for-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_ENABLE_FOR_USED_
