// [2021y-04m-06d][21:36:00] Idrisov Denis R.
// [2021y-04m-08d][01:38:17] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_2013_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_2013_USED_ 101,2013

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace detail
    {
        template<class t> t val();

        template<class t, bool> class is_deref_
        {
            using x = ::std::remove_reference_t<t>;

            #define dCHECK_EXPRESSION(...) \
                decltype(__VA_ARGS__, ::std::true_type{})

            template<class u> static dCHECK_EXPRESSION( 
                *val<u&>()
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            using checked 
                = decltype(check<x>(nullptr));
        public:
            is_deref_() = delete;
            enum { value = checked::value };
        };

        template<class t> class is_deref_<t, false>
        {
            enum { v1 = ::std::is_pointer<t>::value };  
            enum { v2 = ::std::is_array<t>::value   };  
        public:
            is_deref_() = delete;
            enum { value = v1 || v2 };  
        };

        template <class t> class is_dereferencable_
        {
            using no_ref = ::std::remove_reference<t>;
            using x = typename no_ref::type;
            enum { ok = ::std::is_class<x>::value };
            using v = ::tools::detail::is_deref_<x, ok>;
        public:
            is_dereferencable_() = delete;
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
#endif // !dTOOLS_IS_DEREFERENCABLE_2013_USED_
