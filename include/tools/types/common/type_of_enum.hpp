// [2021y-04m-06d][20:14:32] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_TYPE_OF_ENUM_USED_ 
#define dTOOLS_TYPE_OF_ENUM_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/type_of_enum/type_of_enum-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/type_of_enum/type_of_enum-2012.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_TYPE_OF_ENUM_USED_
