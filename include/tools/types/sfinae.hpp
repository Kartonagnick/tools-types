// [2021y-04m-21d][13:03:07] Idrisov Denis R. 100 PRE
// [2021y-04m-23d][13:47:47] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_USED_ 
#define dTOOLS_SFINAE_USED_ 100 PRE

#include <tools/features.hpp>
//==============================================================================
//==============================================================================

#ifdef dHAS_CPP11
    // msvc2015 or newer: used 'void_t' idiom
    #include <tools/types/sfinae/sfinae-2015.hpp>
#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2010 or newer: used classic sfinae with 'decltype'
    #include <tools/types/sfinae/sfinae-2010.hpp>
#else
    #include <tools/types/sfinae/sfinae-2008.hpp>
    // msvc2008 or older: used '__if_exist'
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_USED_
