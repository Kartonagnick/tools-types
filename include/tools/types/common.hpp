// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-17d][20:25:15] Idrisov Denis R.
// [2021y-03m-19d][22:03:35] Idrisov Denis R. 102
// [2021y-03m-20d][19:43:08] Idrisov Denis R. 103
// [2021y-03m-21d][04:01:28] Idrisov Denis R. 104
// [2021y-03m-23d][23:55:08] Idrisov Denis R. 105
// [2021y-03m-30d][03:40:56] Idrisov Denis R. 106

// [2021y-04m-04d][01:37:19] Idrisov Denis R. 107 PRE
#pragma once
#ifndef dTOOLS_COMMON_USED_ 
#define dTOOLS_COMMON_USED_ 107 PRE

#include <tools/features.hpp>
#include <tools/pragma/pragma.hpp>

//==============================================================================
//==============================================================================

#ifdef dHAS_CPP11
    // dMESSAGE("[c++11][types/common]")
    #include <tools/types/common/common-msvc2015.hpp>
#elif dHAS_USING_ALIAS
    // dMESSAGE("[alias][types/common]")
    #include <tools/types/common/common-msvc2013.hpp>
#else
    // dMESSAGE("[old][types/common]")
    #include <tools/types/common/common-msvc2008.hpp>
#endif


//================================================================================
//=== type_of_enum ============================================= (type_traits) ===
#ifdef dHAS_ENUM_CLASS
#ifndef dTOOLS_ENUM_TYPE_USED_ 
#define dTOOLS_ENUM_TYPE_USED_ 100
namespace tools
{
    template<class t, bool = ::std::is_enum<t>::value>
    struct type_of_enum
    {
        typedef typename ::std::underlying_type<t>::type
            type;
    };

    template<class t> struct type_of_enum<t, false>
        { typedef t type; };

    #ifdef dHAS_USING_ALIAS
    template<class t> 
    using type_of_enum_t
        = typename ::tools::type_of_enum<t>::type;
    #endif

} // tools
#endif // !dTOOLS_ENUM_TYPE_USED_
#endif // !dHAS_ENUM_CLASS

//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMMON_USED_
