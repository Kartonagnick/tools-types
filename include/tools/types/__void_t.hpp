// [2021y-04m-13d][15:08:02] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_VOID_T_USED_ 
#define dTOOLS_VOID_T_USED_ 100 PRE

#if defined(__cplusplus) && __cplusplus >= 201103L
    // c++11 support
    #include <type_traits>

#elif !defined(_MSC_VER)
    // other compilers not processed
    #include <type_traits>

#elif _MSC_VER >= 1900
    // msvc2015 or newest
    #include <type_traits>

#elif _MSC_VER == 1800
    // msvc203
    namespace std
    {
        template<class...> using void_t = void;

    } // namespace std
#else
    // msvc2012 or older
    namespace std
    {
        #define dVARIADIC_7 \
            class t1, class t2 = empty, class t3 = empty, class t4 = empty, \
            class t5 = empty, class t6 = empty, class t7  = empty

        struct empty;
        template<dVARIADIC_7> class void_t
        {
            typedef void type;
        };

    } // namespace std
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_VOID_T_USED_
