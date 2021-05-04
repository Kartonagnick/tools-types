// [2021y-04m-06d][20:54:59] Idrisov Denis R. 100
// [2021y-04m-08d][01:38:17] Idrisov Denis R. 101

// [2021y-04m-21d][12:53:59] Idrisov Denis R. 102 PRE
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_USED_ 102 PRE

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/sfinae/is_dereferencable/is_dereferencable-2013.hpp>
#else
    #include <tools/types/sfinae/is_dereferencable/is_dereferencable-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_DEREFERENCABLE_USED_
