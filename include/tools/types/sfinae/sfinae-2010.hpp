// [2021y-04m-23d][13:45:01] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_2010_USED_ 
#define dTOOLS_SFINAE_2010_USED_ 100 PRE

#include <tools/features.hpp>
#include <type_traits>
#include <cstddef>

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
        template<class u> u obj_();

        template<class t> class is_deref_decltype_ 
        {
            struct no_ {};

            template <class u> static
                decltype(*::tools::detail::obj_<u>())
                check(u*);

            template <class> static
                no_ check(...);

            typedef decltype(check<t>(0))
                checked;

            enum { invalid1 = ::std::is_same<checked, t  >::value };
            enum { invalid2 = ::std::is_same<checked, no_>::value };
        public:
            enum { value = !(invalid1 || invalid2) };
            enum { problem = invalid1 };
        };

        #ifdef _MSC_VER
            #pragma warning(push)
            // warning C4200: nonstandard extension used : zero-sized array in struct/union
            #pragma warning(disable : 4200)
        #endif

        template<size_t n> struct sfinae_
            { char buf[n]; };

        #ifdef _MSC_VER
            #pragma warning(pop)
        #endif

        template<class t> class is_deref_sizeof_ 
        {
            struct no_ { char buf[1024]; };

            template <class u> static
                sfinae_< sizeof( *::tools::detail::obj_<u>()) >
                check(u*);

            template <class> static
                no_ check(...);

            enum { sz = sizeof(check<t>(0)) };
        public:
            //enum { value = sz == 0 || sz != sizeof(no_) };
            enum { value = sz != sizeof(no_) };
            enum { problem = sz == 1 };
        };


        template<class t, bool> struct is_deref_ 
        {
            typedef is_deref_decltype_<t>
                decltype_;

            typedef is_deref_sizeof_<t>                
                sizeof_;

            enum { v1 = sizeof_::value     };
            enum { v2 = sizeof_::problem   };

            enum { v3 = decltype_::value   };
            enum { v4 = decltype_::problem };

            enum  { value = v4? v1: v3 };
        };

    } // namespace detail

    namespace detail
    {
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

