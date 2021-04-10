// [2021y-04m-10d][03:07:35] Idrisov Denis R. 100
// [2021y-04m-10d][07:18:11] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_DEGRADATE_USED_ 
#define dTOOLS_DEGRADATE_USED_ 101

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/degradate/degradate-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/degradate/degradate-2012.hpp>
#else
    #include <tools/types/common/degradate/degradate-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DEGRADATE_USED_
