// [2021y-04m-13d][01:52:22] Idrisov Denis R. 100
// [2021y-04m-21d][13:20:27] Idrisov Denis R. 101 PRE
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_HAS_END_USED_ 
#define dTOOLS_HAS_END_USED_ 101 PRE

#include <tools/features.hpp>

#ifdef dHAS_VARIADIC_TEMPLATE
    #include <tools/types/sfinae/has_end/has_end-2013.hpp>
#else
    // msvc2012 or older
    #include <tools/types/sfinae/has_end/has_end-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_HAS_OPERATOR_ACCESS_USED_
