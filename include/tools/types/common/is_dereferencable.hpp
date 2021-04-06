// [2021y-04m-06d][20:54:59] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/is_dereferencable/is_dereferencable-2013.hpp>
//#elif defined (dHAS_ENUM_CLASS)
//    #include <tools/types/common/is_dereferencable/is_dereferencable-2012.hpp>
#else
    #include <tools/types/common/is_dereferencable/is_dereferencable-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_DEREFERENCABLE_USED_
