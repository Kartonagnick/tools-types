// [2021y-04m-23d][17:54:39] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_2010_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_2010_USED_ 1
#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        template<class t> t obj_();

        template<class t, bool> class is_deref_
        {
            #define dCHECK_EXPRESSION_ \
                decltype(*::tools::detail::obj_<u>(), ::std::true_type()) 

            template<class u> static dCHECK_EXPRESSION_ 
                check(dCHECK_EXPRESSION_*);

            #undef dCHECK_EXPRESSION_

            template<class> static ::std::false_type
                check(...);

            typedef decltype(check<t>(nullptr))
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t> class is_deref_<t, false>
        {
            enum { v1 = ::std::is_pointer<t>::value };  
            enum { v2 = ::std::is_array<t>::value   };  
        public:
            enum { value = v1 || v2 };  
        };

        template <class t> class is_dereferencable_
        {
            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                x;
            enum { ok = ::std::is_class<x>::value };
            typedef::tools::detail::is_deref_<x, ok> 
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
#endif // !dTOOLS_IS_DEREFERENCABLE_2010_USED_
