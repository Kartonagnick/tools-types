// [2021y-04m-24d][22:30:39] Idrisov Denis R. 100 PRE
// [2021y-04m-25d][23:17:59] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_DEREF_AVAILABLE_NEW_USED_ 
#define dTOOLS_DEREF_AVAILABLE_NEW_USED_ 1

#include <tools/types/traits.hpp>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];

        template<class t, class sig> 
        class deref_available_ 
        {
            template <class cl>
            using method
                = decltype(static_cast<sig>(&cl::operator*));

            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                x;

            template <class u> static yes check(method<u>*);
            template <class> static   no check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            deref_available_();
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
#endif // !dTOOLS_DEREF_AVAILABLE_NEW_USED_
