// [2021y-03m-10d][12:44:35] Idrisov Denis R.
// [2021y-04m-02d][23:54:49] Idrisov Denis R.
// [2021y-04m-03d][23:13:40] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_FIXED_USED_
#define dTOOLS_FIXED_USED_ 101
//==============================================================================
//==============================================================================

#if (defined(_MSC_VER) && _MSC_VER >= 1900) || __cplusplus >= 201103L
    // #pragma message("build for msvc2015 (or newer) or other compiler")
    #include <tools/types/fixed/fixed-cpp11.hpp>
#else
    #include <tools/types/fixed/fixed-cpp98.hpp>
#endif

#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>
#else
    #include <tools/types/traits.hpp>
#endif


#if 0
//==============================================================================
//=== remove_cv ================================================================
#ifndef dTOOLS_REMOVE_CV_USED_ 
#define dTOOLS_REMOVE_CV_USED_ 1
namespace tools
{
    template<class t> struct remove_cv                     
        { typedef t type; };
    template<class t> struct remove_cv <const t>           
        { typedef t type; };
    template<class t> struct remove_cv <volatile t>        
        { typedef t type; };
    template<class t> struct remove_cv <volatile  const t> 
        { typedef t type; };

} // namespace tools 
#endif // !dTOOLS_REMOVE_CV_USED_

//==============================================================================
//=== is_signed ================================================================
#ifndef dTOOLS_IS_SIGNED_USED_ 
#define dTOOLS_IS_SIGNED_USED_ 1
namespace tools
{
    template <class t> struct is_signed
    {
        typedef typename remove_cv<t>::type x;
        enum { value = static_cast<x>(-1) < static_cast<x>(0) };
    };
    template <class t> struct is_unsigned
    {
        enum { value = !is_signed<t>::value };
    };

} // namespace tools 
#endif // !dTOOLS_IS_SIGNED_USED_
#endif

//==============================================================================
//=== limit ====================================================================
#ifndef dTOOLS_LIMIT_USED_ 
#define dTOOLS_LIMIT_USED_ 1
namespace tools
{
    template<class t> struct limit_unsigned
        : map_unsigned<sizeof(t)>
    {};

    template<class t> struct limit_signed
        : map_signed<sizeof(t)>
    {};

    template <class t, bool> struct limit_
        : limit_signed<t>
    {};

    template <class t> struct limit_<t, false>
        : limit_unsigned<t>
    {};

    template <class t> struct limit
        : limit_<t, dTRAIT::is_signed<t>::value>
    {};

} // namespace tools 
#endif // !dTOOLS_LIMIT_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_FIXED_USED_
