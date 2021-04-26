// [2021y-04m-24d][22:30:39] Idrisov Denis R. 100 PRE
// [2021y-04m-25d][23:17:59] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_DEREF_AVAILABLE_OLD_USED_ 
#define dTOOLS_DEREF_AVAILABLE_OLD_USED_ 1

#include <tools/types/traits.hpp>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        // template<class t> t obj_();

        typedef char(&no )[1];
        typedef char(&yes)[2];

        template <class v, v> struct sig;

        template<class t, class sig> 
        class deref_available_ 
        {
            #define dSFINAE_                             \
                ::tools::detail::sig<                    \
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

        template<class t> struct deref_exists
        {


        };


    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t, class sig> struct deref_available
        : dDETAIL_CONSTANT(deref_available_<t, sig>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DEREF_AVAILABLE_OLD_USED_


struct op_dereference;
struct op_access;
struct op_call;