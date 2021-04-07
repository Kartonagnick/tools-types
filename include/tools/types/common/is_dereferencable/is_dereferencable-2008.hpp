// [2021y-04m-06d][21:36:00] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_2008_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_2008_USED_ 101,2008

#include <tools/type_traits.hpp>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        template<class t, bool> class is_deref_
        {
        public:
            __if_exists(t::operator*)
            {
                enum { value = true };
            }

            __if_not_exists(t::operator*) 
            {
                enum { value = false };
            }
        };

        template<class t> class is_deref_<t, false>
        {
            enum { v1 = dTRAIT::is_pointer<t>::value };  
            enum { v2 = dTRAIT::is_array<t>::value   };  
        public:
            enum { value = v1 || v2 };  
        };

        template <class t> class is_dereferencable_
        {
            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type 
                x;
            enum { ok = dTRAIT::is_class<x>::value };
            typedef ::tools::detail::is_deref_<x, ok>
                v;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t> struct is_dereferencable
        : dDETAIL_CONSTANT(is_dereferencable_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_DEREFERENCABLE_2008_USED_
