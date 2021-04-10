// [2021y-04m-04d][23:22:49] Idrisov Denis R. 100
// [2021y-04m-10d][03:34:51] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_ARRAY_USED_ 
#define dTOOLS_ARRAY_USED_ 101 PRE

#include <tools/pragma/pragma.hpp>
#include <tools/features.hpp>

#if 0
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
#endif


#ifdef dHAS_USING_ALIAS
    #include <tools/types/common/array/array-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/array/array-2012.hpp>
#else
    #include <tools/types/common/array/array-2008.hpp>
#endif


//==============================================================================
//==============================================================================
#endif // !dTOOLS_ARRAY_USED_
