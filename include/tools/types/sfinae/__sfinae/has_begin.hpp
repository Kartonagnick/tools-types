// [2021y-04m-13d][01:52:14] Idrisov Denis R. 100
// [2021y-04m-21d][13:21:50] Idrisov Denis R. 101 PRE
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_HAS_BEGIN_USED_ 
#define dTOOLS_HAS_BEGIN_USED_ 101 PRE

#include <tools/features.hpp>

#ifdef dHAS_VARIADIC_TEMPLATE
    #include <tools/types/sfinae/has_begin/has_begin-2013.hpp>
#else
    // msvc2012 or older
    #include <tools/types/sfinae/has_begin/has_begin-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_HAS_BEGIN_USED_
