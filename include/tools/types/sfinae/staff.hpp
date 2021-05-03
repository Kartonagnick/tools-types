// [2021y-05m-03d][21:24:24] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_STAFF_USED_ 
#define dTOOLS_SFINAE_STAFF_USED_ 100 PRE

#include <tools/types/traits/no_ref.hpp>

namespace tools  
{
    struct empty;

    namespace sfinae 
    {
        template<class t> t obj();

        typedef char(&no)[1000000];

        template<size_t n> struct sizeof_ 
            { typedef char(&type)[n]; };

        #ifdef dHAS_TYPE_TRAITS
        template<class a, class b> struct decltype_
        {
		    typedef ::std::true_type type;
		    typedef b second;
    	};
        #endif

        template<class v, v> struct signature_;

    } // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_STAFF_USED_
