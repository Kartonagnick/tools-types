// [2021y-04m-08d][03:02:40] Idrisov Denis R. 100
// [2021y-04m-10d][07:21:07] Idrisov Denis R. 101

// [2021y-04m-21d][13:09:29] Idrisov Denis R. 102 PRE
#pragma once
#ifndef dTOOLS_IS_CONST_DATA_USED_ 
#define dTOOLS_IS_CONST_DATA_USED_ 102 PRE

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/is_const_data/is_const_data-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/is_const_data/is_const_data-2012.hpp>
#else
    #include <tools/types/common/is_const_data/is_const_data-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_VOLATILE_DATA_USED_
