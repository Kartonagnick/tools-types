// [2021y-04m-21d][13:03:07] Idrisov Denis R. 100 PRE
// [2021y-04m-23d][13:47:47] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_USED_ 
#define dTOOLS_SFINAE_USED_ 100 PRE

#include <tools/types/sfinae/staff.hpp>
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
#elif defined (dHAS_ENUM_CLASS)
    // msvc2012:
    //   - used classic sfinae with 'decltype'
    //   - has bugs:
    //     - ignored private/protected access
    //     - signature: not worked for derived 
    #include <tools/types/sfinae/available-2012.hpp>
    #include <tools/types/sfinae/signature-2010.hpp>
#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2010:
    //   - used classic sfinae with 'decltype'
    //   - has bugs:
	//     - invalis sfinea
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
        : dIMPLEMENT_(is_dereferencable_<t>)
    {};

    namespace detail
    {
        // msvc2015 or newer: 
        //   - used 'void_t' idiom
        //   - correct implementation
        //   - has no restrictions
        //   - recommended for use

        // msvc2008 - msvc2013:
        //   - has bugs:
        //     - ignored private/protected access
        //     - signature: not worked for derived 

        #ifdef dHAS_CPP11
            //msvc2015 or newer
            template<class, class = void>
            struct is_lambda_ : ::std::false_type {};
 
            template<class F> struct is_lambda_<F, 
                ::std::void_t<decltype(&F::operator())> >
                : ::std::true_type
            {};
        #elif defined(dHAS_USING_ALIAS)
            //msvc2013
            template<class lambda> class is_lambda_
            {
                using x = ::std::remove_reference_t<lambda>;

                template<class u> static ::std::true_type
                    check(decltype(&u::operator()));

                template<class> static ::std::false_type
                    check(...);

                typedef decltype(check<x>(nullptr))
                    checked;
            public:
                enum { value = checked::value };
            };
        #elif defined(dHAS_TYPE_TRAITS) 
            //msvc2010-2012
            template<class lambda> class is_lambda_
            {
                dNO_REFERENCE_(lambda, x);
                template<class u> static ::std::true_type
                    check(decltype(&u::operator()));
                template<class> static ::std::false_type
                    check(...);
                typedef decltype(check<x>(nullptr))
                    checked;
            public:
                enum { value = checked::value };
            };
        #else
            //msvc2008 or older
            template<class lambda> struct is_lambda_
            {
                dNO_REFERENCE_(lambda, x);
                __if_exists    (t::operator()) { enum { value = 1 }; }
                __if_not_exists(t::operator()) { enum { value = 0 }; }
            };                                      
        #endif

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t> struct is_lambda
        : dIMPLEMENT_(is_lambda_<t>)
    {};

} // namespace tools

#undef dIMPLEMENT_
#undef dSFINAE_PROTECTOR_
#undef dSFINAE_PROTECTOR_SIG_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_USED_
