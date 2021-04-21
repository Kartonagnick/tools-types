// [2021y-04m-13d][01:52:14] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_HAS_BEGIN_USED_ 
#define dTOOLS_HAS_BEGIN_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_VARIADIC_TEMPLATE
    #include <tools/types/common/has_begin/has_begin-2013.hpp>
#else
    // msvc2012 or older
    #include <tools/types/common/has_begin/has_begin-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_HAS_BEGIN_USED_
