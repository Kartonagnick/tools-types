// [2021y-04m-23d][13:45:01] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_2010_USED_ 
#define dTOOLS_SFINAE_2010_USED_ 100 PRE

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_lambda ================================================= (features) ===
#ifndef dTOOLS_IS_LAMBDA_USED_ 
#define dTOOLS_IS_LAMBDA_USED_ 1
namespace tools
{
    namespace detail
    {
        template<class lambda> class is_lambda_
        {
            typedef ::std::remove_reference<lambda>
                no_ref;
            typedef typename no_ref::type 
                x;

            template<class u> static ::std::true_type
                check(decltype(&u::operator()));

            template<class> static ::std::false_type
                check(...);

            typedef decltype(check<x>(nullptr))
                checked;
        public:
            enum { value = checked::value };
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
        template<class u> u obj();

        template<class u, class t, 
            class r = decltype(*::tools::detail::obj_<u>()),
            bool = ::std::is_same<r, t>::value
        > struct enable_;

        template<class u, class t, class r>
        struct enable_<u, t, r, false>
        {
            typedef ::std::true_type type; 
        };

        template<class t, bool> struct is_deref_
        {
            // decltype(*::obj_<u>(), ::std::true_type())

            #define dCHECK_EXPRESSION_ \
            decltype(*::tools::detail::obj<u>(), ::std::true_type())

                //typename enable_<u, t>::type

            template<class u> static 
                dCHECK_EXPRESSION_ 
                check(dCHECK_EXPRESSION_*);

            template<class> static ::std::false_type
                check(...);
            typedef decltype(check<t>(nullptr))
                checked;
        public:
            #undef dCHECK_EXPRESSION_
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

//#include <tools/types/sfinae/is_deref-2010.hpp>
#endif // !dTOOLS_IS_DEREFERENCABLE_USED_



//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_2010_USED_
