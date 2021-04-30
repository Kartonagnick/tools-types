// [2021y-04m-21d][13:03:07] Idrisov Denis R. 100 PRE
// [2021y-04m-23d][13:47:47] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_USED_ 
#define dTOOLS_SFINAE_USED_ 100 PRE

#include <tools/features.hpp>
//==============================================================================
//==============================================================================

#ifdef _MSC_VER
    // msvc2019:
    //   - has bugs:
    //     - not worked in (Visual Studio 2019 version 16.8, 16.9)
    //       workaround: disable compatibility mode
    //       workaround: change
    //         from:  /permissive-
    //         to:    /permissive
    #include <tools/types/sfinae/exist-2008.hpp>
#endif
//==============================================================================
//==============================================================================

#ifdef dHAS_CPP11
    #ifdef _MSC_VER
        // msvc2015 or newer: 
        //   - used 'void_t' idiom
        //   - correct implementation
        //   - has no restrictions
        //   - recommended for use
        #include <tools/types/sfinae/available-2015.hpp>
        #include <tools/types/sfinae/signature-2015.hpp>
    #else
        // gcc (and mingw) has bugs:
        //   - available-2015:
        //       - ignored private/protected access
        //   - workaround: use available-2013
        #include <tools/types/sfinae/available-2013.hpp>
        #include <tools/types/sfinae/signature-2015.hpp>
    #endif
#elif defined(dHAS_VARIADIC_TEMPLATE) 
    // msvc2013:
    //   - used classic sfinae with 'decltype'
    //   - has bugs:
    //     - ignored private/protected access
    //     - signature: not worked for derived 
    #include <tools/types/sfinae/available-2013.hpp>
    #include <tools/types/sfinae/signature-2013.hpp>
#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2013 - msvc2010:
    //   - used classic sfinae with 'decltype'
    //   - has bugs:
    //     - ignored private/protected access
    //     - signature: not worked for derived 
    #include <tools/types/sfinae/available-2010.hpp>
    #include <tools/types/sfinae/signature-2010.hpp>
#else
    // msvc2008:
    //   - used old-sfinae with 'sizeof'
    //   - has bugs:
    //     - ignored private/protected access
    //     - signature: not worked for derived 
    #include <tools/types/sfinae/available-2008.hpp>
    #include <tools/types/sfinae/signature-2008.hpp>
#endif

//==============================================================================
//==============================================================================
namespace tools
{
    namespace detail
    {
        template <class t> class is_dereferencable_
        {
            typedef ::tools::sfinae::available::dereference<t>
                impl;
        public:
            is_dereferencable_();
            enum { value = impl::value };
        };

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t> struct is_dereferencable
        : dDETAIL_CONSTANT(is_dereferencable_<t>)
    {};

}
//#include <tools/types/sfinae/is_dereferencable.hpp>
//#include <tools/types/sfinae/begin.hpp>

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_USED_
