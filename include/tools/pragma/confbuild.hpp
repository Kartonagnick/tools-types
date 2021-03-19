// [2021y-03m-19d][14:33:03] 100
#pragma once
#ifndef dTOOLS_CONFBUILD_USED_
#define dTOOLS_CONFBUILD_USED_ 100
//==============================================================================
//==============================================================================

#if !defined(dX64) && !defined(dX32)
    #ifdef _WIN32
        #ifdef _WIN64
            #define dX64 1
        #else
            #define dX32 1
        #endif
    #else
        #if defined(__LP64__) || defined(_M_IA64)
            #define dX64 1
        #else
            #define dX32 1
        #endif
    #endif
#endif

#if defined(dX64)
    #define dTXT_AMODEL "x64"
#elif defined(dX32)
    #define dTXT_AMODEL "x86"
#endif

#ifdef NDEBUG
    #define dTXT_CONFIG "release"

    #ifdef _DLL
        #define dCRT "MD"
    #else
        #define dCRT "MT"
    #endif

#else
    #define dTXT_CONFIG "debug"

    #ifdef _DLL
        #define dCRT "MDd"
    #else
        #define dCRT "MTd"
    #endif
#endif

#ifdef STABLE_RELEASE
    #define dTXT_STABLE "stable"
#else
    #define dTXT_STABLE "unstable"
#endif

#define dSTRINGIZE(...) #__VA_ARGS__
#define dSSTRINGIZE(x) dSTRINGIZE(x)

#define dVERSION_NUM(MAJOR, MINOR, PATCH)   MAJOR * 100 + MINOR * 10 + PATCH
#define dVERSION_STR(MAJOR, MINOR, PATCH)   dSSTRINGIZE(MAJOR.MINOR.PATCH)

#define dGET_VERSION(NAME) \
    dVERSION_STR(NAME##_MAJOR, NAME##_MINOR, NAME##_PATHS)   

#define dABOUT_ME \
    dTXT_CONFIG "-" dTXT_AMODEL ", " dTXT_STABLE 

#define dFULL_VERSION(NAME) dGET_VERSION(NAME) ", " dABOUT_ME

//==============================================================================
//==============================================================================
#endif // !dTOOLS_CONFBUILD_USED_


// example extract: 
// #define dGET_MAJOR(value) value / 100
// #define dGET_MINOR(value) (value % 100)/10
// #define dGET_PATHS(value) value % 10
