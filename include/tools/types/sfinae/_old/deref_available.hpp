// [2021y-04m-24d][22:30:39] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_DEREF_AVAILABLE_USED_ 
#define dTOOLS_DEREF_AVAILABLE_USED_ 1

#include <tools/features.hpp>
#ifdef dHAS_CPP11
    #include <tools/types/sfinae/deref/deref-new.hpp>
#else
    #include <tools/types/sfinae/deref/deref-old.hpp>
#endif

#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>
#else
    #include <tools/types/traits.hpp>
#endif

#if 0

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        // template<class t> t obj_();

        typedef char(&no )[1];
        typedef char(&yes)[2];

        #ifdef dHAS_CPP11

        template<class t, class sig> 
        class deref_available_ 
        {
            template <class cl>
            using method
                = decltype(static_cast<sig>(&cl::operator*));
            #define dSFINAE_ method<u>

            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                x;

            template <class u> static 
                yes check(dSFINAE_*);

            template <class> static    
                no check(...);

            #undef dSFINAE_

            enum { sz = sizeof(check<x>(0)) };
        public:
            deref_available_();
            enum { value = sz != sizeof(no) };
        };

        #else

        template <class v, v> struct 
            sfinae_sig_;

        template<class t, class sig> 
        class deref_available_ 
        {
            #define dSFINAE_                             \
                ::tools::detail::sfinae_sig_<            \
                    sig, static_cast<sig>(&u::operator*) \
                >

            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                x;

            struct my {};
            struct s { my operator*(); };
            struct der: /*public s, */public x {};

            template <class u> static 
                yes check(dSFINAE_*);

            template <class> static    
                no check(...);

            #undef dSFINAE_

            enum { sz = sizeof(check<der>(0)) };
        public:
            deref_available_();
            enum { value = sz != sizeof(no) };
        };

        #endif

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t, class sig> struct deref_available
        : dDETAIL_CONSTANT(deref_available_<t, sig>)
    {};

} // namespace tools 

#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DEREF_AVAILABLE_USED_
