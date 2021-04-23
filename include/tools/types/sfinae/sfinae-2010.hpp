// [2021y-04m-23d][13:45:01] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_2010_USED_ 
#define dTOOLS_SFINAE_2010_USED_ 100 PRE

#include <tools/features.hpp>

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
            using x
                = ::std::remove_reference_t<lambda>;

            template<class u> static ::std::true_type
                check(decltype(&u::operator()));

            template<class> static ::std::false_type
                check(...);

            using checked
                = decltype(check<x>(nullptr));
        public:
            is_lambda_() = delete;
            enum { value = checked::value };
        };

    } // namespace detail

    template<class F> class is_lambda
        : dDETAIL_CONSTANT(is_lambda_<F>)
    {};
    //#ifdef _MSC_VER

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
#endif // !dTOOLS_IS_DEREFERENCABLE_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_2010_USED_
