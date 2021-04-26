// [2021y-04m-23d][13:45:06] Idrisov Denis R. 100 PRE
// [2021y-04m-26d][21:50:56] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_METHOD_EXISTS_MINGW_USED_ 
#define dTOOLS_METHOD_EXISTS_MINGW_USED_ 100 PRE

#ifdef _MSC_VER
    #error expected gcc or mingw
#endif

namespace tools  {
namespace sfinae {
namespace exists {

    template<class t> struct op_call
    {                             
        enum { value = 0 };
    };                                      

    template<class t> struct op_deref
    {                             
        enum { value = 0 };
    };               

    template<class t> struct op_access
    {                             
        enum { value = 0 };
    };               

} // namespace exists
} // namespace sfinae
} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_METHOD_EXISTS_MINGW_USED_
