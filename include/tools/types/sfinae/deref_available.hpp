// [2021y-04m-24d][22:30:39] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_DEREF_AVAILABLE_USED_ 
#define dTOOLS_DEREF_AVAILABLE_USED_ 1

#include <tools/features.hpp>
#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>
#else
    #include <tools/types/traits.hpp>
#endif

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        // template<class t> t obj_();

        typedef char(&no )[1];
        typedef char(&yes)[2];

        template <class v, v> struct sfinae_sig_;

        template<class t, class sig> class deref_available_ 
        {
            #define dSFINAE_ \
                ::tools::detail::sfinae_sig_<sig, &u::operator*>

            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                x;

            // struct s { void operator*(){} };
            // struct der: s, x {};

            template <class u> static 
                yes check(dSFINAE_*);

            template <class> static    
                no check(...);

            #undef dSFINAE_
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t, class sig> struct deref_available
        : dDETAIL_CONSTANT(deref_available_<t, sig>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DEREF_AVAILABLE_USED_
