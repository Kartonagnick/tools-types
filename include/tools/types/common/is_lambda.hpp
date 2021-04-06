// [2021y-04m-06d][15:43:33] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_IS_LAMBDA_USED_ 
#define dTOOLS_IS_LAMBDA_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_VARIADIC_TEMPLATE
    #include <tools/types/common/is_lambda/is_lambda-2013.hpp>
#else
    // msvc2012 or older
    #include <tools/types/common/is_lambda/is_lambda-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_LAMBDA_USED_
