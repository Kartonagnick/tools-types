// [2021y-04m-12d][17:40:05] Idrisov Denis R. 10
#pragma once
#ifndef dTOOLS_IS_DECREMENTABLE_2008_USED_ 
#define dTOOLS_IS_DECREMENTABLE_2008_USED_ 100,2008

#include <tools/type_traits.hpp>

//==============================================================================
//=== is_decrementable =========================================================
namespace tools 
{
    namespace detail
    {
        template<class t, bool> class is_decrementable_impl_
        {
        public:
            __if_exists(t::operator--)
            {
                enum { value = true };
            }

            __if_not_exists(t::operator--) 
            {
                enum { value = false };
            }
        };

        template<class t> class is_decrementable_impl_<t, false>
        {
        public:
            enum { value = dTRAIT::is_pointer<t>::value };  
        };

        template <class t> class is_decrementable_
        {
            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type 
                x;
            enum { ok = dTRAIT::is_class<x>::value };
            typedef ::tools::detail::is_decrementable_impl_<x, ok>
                v;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    // if the syntax is valid: ++it or it++ ---> dereferencable 
    template<class t> struct is_decrementable
        : dDETAIL_CONSTANT(is_decrementable_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_DECREMENTABLE_2008_USED_
