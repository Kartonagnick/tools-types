// [2021y-04m-04d][23:22:49] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_ARRAY_USED_ 
#define dTOOLS_ARRAY_USED_ 100

#include <tools/pragma/pragma.hpp>
#include <tools/features.hpp>

#ifndef _MSC_VER
    #include <tools/types/common/array/array-2013.hpp>
#else
    #if _MSC_VER < 1600
        // msvc2008 or older
        #include <tools/types/common/array/array-2008.hpp>
    #elif _MSC_VER >= 1600 && _MSC_VER <= 1700
        // msvc2010 - msvc2012
        #include <tools/types/common/array/array-2012.hpp>
    #else
        // msvc2013 or newer
        #include <tools/types/common/array/array-2013.hpp>
    #endif
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_ARRAY_USED_
