// [2021y-04m-13d][21:17:01] Idrisov Denis R. 100
// [2021y-04m-14d][01:45:51] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_HAS_OPERATOR_ACCESS_USED_ 
#define dTOOLS_HAS_OPERATOR_ACCESS_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_VARIADIC_TEMPLATE
    #include <tools/types/common/has_operator_access/has_operator_access-2013.hpp>
#else
    // msvc2012 or older
    #include <tools/types/common/has_operator_access/has_operator_access-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_HAS_OPERATOR_ACCESS_USED_
