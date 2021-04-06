// [2021y-04m-06d][21:36:00] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_2008_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_2008_USED_ 100,2008

#include <tools/type_traits.hpp>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        template<class F, bool> struct is_deref_
        {
            __if_exists(F::operator*)
            {
                enum { value = true };
            }

            __if_not_exists(F::operator*) 
            {
                enum { value = false };
            }
        };

        template <class t> struct is_deref_<t, false>
        {
            enum { value = false };
        };

        template <class t> struct is_deref_<t*, false>
        {
            enum { value = true };
        };
        template <class t> struct is_deref_<t*const, false>
        {
            enum { value = true };
        };
        template <class t> struct is_deref_<t*volatile, false>
        {
            enum { value = true };
        };
        template <class t> struct is_deref_<t*volatile const, false>
        {
            enum { value = true };
        };

        template <class t, size_t n> struct is_deref_<t[n], false>
        {
            enum { value = true };
        };

        template <class t> struct is_dereferencable
        {
            typedef dTRAIT::remove_reference<t>
                noref;
            typedef typename noref::type 
                x;

            enum { ok = dTRAIT::is_class<x>::value };
            enum { value = is_deref_<x, ok>::value };
        };

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t> struct is_dereferencable
        : dDETAIL_CONSTANT(is_dereferencable<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_DEREFERENCABLE_2008_USED_
