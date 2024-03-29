// [2021y-04m-12d][16:04:25] Idrisov Denis R. 100
// [2021y-04m-14d][01:38:51] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_IS_INCREMENTABLE_2008_USED_ 
#define dTOOLS_IS_INCREMENTABLE_2008_USED_ 100,2008

#include <tools/type_traits.hpp>

//==============================================================================
//=== is_incrementable =========================================================
namespace tools 
{
    namespace detail
    {
        template<class t, bool> class is_incrementable_impl_
        {
        public:
            __if_exists(t::operator++)
            {
                enum { value = true };
            }

            __if_not_exists(t::operator++) 
            {
                enum { value = false };
            }
        };

        template<class t> class is_incrementable_impl_<t, false>
        {
        public:
            enum { value = dTRAIT::is_pointer<t>::value };  
        };

        template <class t> class is_incrementable_
        {
            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type 
                x;
            enum { ok = dTRAIT::is_class<x>::value };
            typedef ::tools::detail::is_incrementable_impl_<x, ok>
                v;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    // if the syntax is valid: ++it or it++ ---> dereferencable 
    template<class t> struct is_incrementable
        : dDETAIL_CONSTANT(is_incrementable_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_INCREMENTABLE_2008_USED_
