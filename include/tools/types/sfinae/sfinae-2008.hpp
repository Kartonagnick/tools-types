// [2021y-04m-23d][13:45:06] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_2008_USED_ 
#define dTOOLS_SFINAE_2008_USED_ 100 PRE

#include <tools/features.hpp>
#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>
#else
    #include <tools/types/traits.hpp>
#endif

//==============================================================================
//=== is_lambda ================================================= (features) ===
#ifndef dTOOLS_IS_LAMBDA_USED_ 
#define dTOOLS_IS_LAMBDA_USED_ 1
namespace tools
{
    namespace detail
    {
        template<class t> struct is_lambda_
        {                             
            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                x;

            __if_exists( x::operator() )     { enum { value = 1 }; }
            __if_not_exists( x::operator() ) { enum { value = 0 }; }
        };                                      

    } // namespace detail

    template<class F> class is_lambda
        : dDETAIL_CONSTANT(is_lambda_<F>)
    {};

} // namespace tools 
#endif // !dTOOLS_INTEGRAL_CONSTANT_USED_


//==============================================================================
//=== is_dereferencable ========================================================
#ifndef dTOOLS_IS_DEREFERENCABLE_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_USED_ 1
namespace tools 
{
    namespace detail
    {
        template<class t, bool> class is_deref_
        {
        public:
            __if_exists(t::operator*)     { enum { value = 1 }; }
            __if_not_exists(t::operator*) { enum { value = 0 }; }
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
#endif // !dTOOLS_IS_DEREFERENCABLE_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_2008_USED_
