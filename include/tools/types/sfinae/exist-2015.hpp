// [2021y-04m-27d][20:51:13] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_EXIST_2015_USED_ 
#define dTOOLS_SFINAE_EXIST_2015_USED_ 100 PRE

#ifndef _MSC_VER
    #error Visual Studio compiler required.
#endif

#if defined(_MSC_FULL_VER) && _MSC_FULL_VER != 192829334

namespace tools  {
namespace sfinae {
namespace exist  {

    template<class t> struct call
    {                             
        __if_exists(t::operator())     { enum { value = 1 }; }
        __if_not_exists(t::operator()) { enum { value = 0 }; }
    };                                      

    template<class t> struct dereference
    {                             
        __if_exists(t::operator*)     { enum { value = 1 }; }
        __if_not_exists(t::operator*) { enum { value = 0 }; }
    };               

    template<class t> struct access
    {                             
        __if_exists(t::operator[])     { enum { value = 1 }; }
        __if_not_exists(t::operator[]) { enum { value = 0 }; }
    };               

} // namespace exist
} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // #if defined(_MSC_FULL_VER) && _MSC_FULL_VER != 192829334
#endif // !dTOOLS_SFINAE_EXIST_2015_USED_
