// [2021y-04m-06d][15:43:33] Idrisov Denis R. 100

// [2021y-04m-21d][12:54:38] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_IS_LAMBDA_USED_ 
#define dTOOLS_IS_LAMBDA_USED_ 101 PRE

#include <tools/features.hpp>

#ifdef dHAS_VARIADIC_TEMPLATE
    #include <tools/types/sfinae/is_lambda/is_lambda-2013.hpp>
#else
    // msvc2012 or older
    #include <tools/types/sfinae/is_lambda/is_lambda-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_LAMBDA_USED_
