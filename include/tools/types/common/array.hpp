// [2021y-04m-04d][23:22:47] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_ARRAY_USED_ 
#define dTOOLS_ARRAY_USED_ 100


#ifndef _MSC_VER
    #include <tools/types/common/array/array-msvc2015.hpp>
#else
    #if _MSC_VER < 1600
        // msvc2008 or older
        #include <tools/types/common/array/array-msvc2008.hpp>
    #elif _MSC_VER >= 1600 && _MSC_VER <= 1700
        // msvc2010 - msvc2012
        #include <tools/types/common/array/array-msvc2012.hpp>
    #else
        #include <tools/types/common/array/array-msvc2015.hpp>
    #endif
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_ARRAY_USED_
