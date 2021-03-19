
// [2021y-02m-20d][16:14:09] Idrisov Denis R.
// [2021y-02m-20d][16:14:09] birthday of the project
// [2021y-03m-18d][23:51:55] 101
#pragma once
#ifndef dTOOLS_TYPES_CONFBUILD_USED_
#define dTOOLS_TYPES_CONFBUILD_USED_ 101
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
    #define dTXT_AMODEL "64-bit"
#elif defined(dX32)
    #define dTXT_AMODEL "32-bit"
#endif

#ifdef NDEBUG
    #define dTXT_CONFIG "release"
#else
    #define dTXT_CONFIG "debug"
#endif

#ifdef STABLE_RELEASE
    #define dTXT_STABLE "stable"
#else
    #define dTXT_STABLE "unstable"
#endif

#define dVERSION_MAJOR      1
#define dVERSION_MINOR      0
#define dVERSION_PATCH      1

#define dSTRINGIZE(...) #__VA_ARGS__
#define dSSTRINGIZE(x) dSTRINGIZE(x)

#define dFILE_VERSION       dVERSION_MAJOR, dVERSION_MINOR, dVERSION_PATCH
#define dFILE_VERSION_NUM   dVERSION_MAJOR * 100 + dVERSION_MINOR * 10 + dVERSION_PATCH
#define dFILE_VERSION_STR   dSSTRINGIZE(dVERSION_MAJOR.dVERSION_MINOR.dVERSION_PATCH)

#define dABOUT_ME \
    dTXT_CONFIG "-" dTXT_AMODEL ", " dTXT_STABLE 

#define dFULL_VERSION dFILE_VERSION_STR ", " dABOUT_ME

//==============================================================================
//==============================================================================
#endif // !dTOOLS_TYPES_CONFBUILD_USED_