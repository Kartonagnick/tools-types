// [2021y-04m-27d][20:51:13] Idrisov Denis R. 100 PRE
// [2021y-04m-28d][17:16:02] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_EXIST_2008_USED_ 
#define dTOOLS_SFINAE_EXIST_2008_USED_ 100 PRE

#ifndef _MSC_VER
    #error Visual Studio compiler required.
#else
#include <tools/types/traits/no_ref.hpp>

namespace tools  {
namespace sfinae {
namespace exist  {

    #if _MSC_VER != 1928
    // bug msvc2019: not worked in (Visual Studio 2019 version 16.8, 16.9)
    // workaround: disable compatibility mode 
    // workaround: change 
    //   from:  /permissive- 
    //   to:    /permissive

    template<class t> struct call
    {
        dNO_REFERENCE_(t, x);
        __if_exists    (t::operator()) { enum { value = 1 }; }
        __if_not_exists(t::operator()) { enum { value = 0 }; }
    };                                      

    template<class t> struct dereference
    {            
        dNO_REFERENCE_(t, x);
        __if_exists    (t::operator*) { enum { value = 1 }; }
        __if_not_exists(t::operator*) { enum { value = 0 }; }
    };               

    template<class t> struct access
    {            
        dNO_REFERENCE_(t, x);
        __if_exists    (t::operator[]) { enum { value = 1 }; }
        __if_not_exists(t::operator[]) { enum { value = 0 }; }
    };              

    #endif // _MSC_VER != 1928

    template<class t> struct begin
    {
        dNO_REFERENCE_(t, x);
        __if_exists    (x::begin) { enum { value = 1 }; }
        __if_not_exists(x::begin) { enum { value = 0 }; }
    };                                      

} // namespace exist
} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // _MSC_VER
#endif // !dTOOLS_SFINAE_EXIST_2008_USED_
