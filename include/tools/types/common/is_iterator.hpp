// [2021y-04m-12d][14:52:02] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_IS_ITERATOR_USED_ 
#define dTOOLS_IS_ITERATOR_USED_ 100

#include <tools/features.hpp>

#ifdef dHAS_CPP11
    #include <tools/types/common/is_iterator/is_iterator-2015.hpp>
#elif dHAS_USING_ALIAS
    #include <tools/types/common/is_iterator/is_iterator-2013.hpp>
#elif defined (dHAS_ENUM_CLASS)
    #include <tools/types/common/is_iterator/is_iterator-2012.hpp>
#else
    #include <tools/types/common/is_iterator/is_iterator-2008.hpp>
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_ITERATOR_USED_

#if 0

    // must be dereferencable and incrementable
    template<class t> class is_iterable
        : dDETAIL_CONSTANT(is_iterable_<t>)
    {};

#endif