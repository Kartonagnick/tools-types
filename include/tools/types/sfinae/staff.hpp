// [2021y-05m-03d][21:24:24] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_STAFF_USED_ 
#define dTOOLS_SFINAE_STAFF_USED_ 100 PRE

#include <cstddef>
#include <tools/types/traits/no_ref.hpp>

#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>

    #define dIMPLEMENT_(...)                    \
        public ::std::integral_constant<bool,   \
            detail::__VA_ARGS__::value          \
        >
#else
    #include <tools/types/traits.hpp>

    #define dIMPLEMENT_(...)                    \
        public ::tools::integral_constant<bool, \
            detail::__VA_ARGS__::value          \
        >
#endif

#ifdef _MSC_VER
    #define dSFINAE_PROTECTOR_(name, x, impl)        \
        __if_exists    (x::name) { enum { v = 1 }; } \
        __if_not_exists(x::name) { enum { v = 0 }; } \
        typedef detail_##name::impl<x, v> impl

    #define dSFINAE_PROTECTOR_SIG_(name, x, sig, impl) \
        __if_exists    (x::name) { enum { v = 1 }; }   \
        __if_not_exists(x::name) { enum { v = 0 }; }   \
        typedef detail_##name::impl<x, sig, v> impl
#else
    #define dSFINAE_PROTECTOR_(name, x, impl) \
        typedef detail_##name::impl<x, true> impl

    #define dSFINAE_PROTECTOR_SIG_(name, x, sig, impl) \
        typedef detail_##name::impl<x, sig, true> impl
#endif

namespace tools  
{
    struct empty;
    template<class t> t obj();

    namespace sfinae 
    {
        typedef char(&no)[1000000];
        typedef char(&yes)[1];

        template<size_t n> struct sizeof_ 
            { typedef char(&type)[n]; };

        #ifdef dHAS_TYPE_TRAITS
        template<class a, class b> struct decltype_
        {
		    typedef ::std::true_type type;
		    typedef b second;
    	};
        #endif

        template<class v, v> struct signature_;

    } // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_STAFF_USED_
