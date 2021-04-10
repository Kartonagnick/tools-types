// [2021y-04m-06d][16:24:22] Idrisov Denis R. 100
// [2021y-04m-10d][02:53:29] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_DEGRADATE_2008_USED_ 
#define dTOOLS_DEGRADATE_2008_USED_ 101,2008

#include <tools/type_traits.hpp>

namespace tools 
{
    template<class t> class degradate
    {
        typedef dTRAIT::remove_reference<t>
            no_ref;
        typedef typename no_ref::type 
            x;
        typedef dTRAIT::remove_cv<x>
            no_cv;
    public:
        typedef typename no_cv::type
            type;
    };

    #define ddegradate(t) \
        typename ::tools::degradate<t>::type

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DEGRADATE_2008_USED_
