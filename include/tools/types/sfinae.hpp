// [2021y-04m-21d][13:03:07] Idrisov Denis R. 100 PRE
// [2021y-04m-23d][13:47:47] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_USED_ 
#define dTOOLS_SFINAE_USED_ 100 PRE

#include <tools/features.hpp>
#include <tools/types/sfinae/exist-2008.hpp>
//==============================================================================
//==============================================================================

#ifdef dHAS_CPP11

    // msvc2015 or newer: 
    //   - used 'void_t' idiom
    //   - correct implementation
    //   - has no restrictions
    //   - recommended for use

    #include <tools/types/sfinae/available-2015.hpp>
    #include <tools/types/sfinae/signature-2015.hpp>

#elif defined(dHAS_VARIADIC_TEMPLATE) 
    // msvc2013: 
    //   - used classic sfinae with 'decltype'
    //   - ignored private/protected access
    //   - signature: not worked for derived 
    #include <tools/types/sfinae/available-2013.hpp>
    #include <tools/types/sfinae/signature-2013.hpp>
#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2013 - msvc2010: 
    //   - used classic sfinae with 'decltype'
    //   - ignored private/protected access
    //   - signature: not worked for derived 
    #include <tools/types/sfinae/available-2010.hpp>
    #include <tools/types/sfinae/signature-2010.hpp>
#else
    // msvc2008: 
    //   - used classic sfinae with 'decltype'
    //   - ignored private/protected access
    //   - signature: not worked for derived 
    #include <tools/types/sfinae/available-2008.hpp>
    #include <tools/types/sfinae/signature-2008.hpp>
#endif

#include <tools/types/sfinae/is_dereferencable.hpp>
//#include <tools/types/sfinae/begin.hpp>

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_USED_
