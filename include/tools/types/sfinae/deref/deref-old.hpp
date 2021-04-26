// [2021y-04m-24d][22:30:39] Idrisov Denis R. 100 PRE
// [2021y-04m-25d][23:17:59] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_DEREF_AVAILABLE_OLD_USED_ 
#define dTOOLS_DEREF_AVAILABLE_OLD_USED_ 1

#include <tools/types/traits.hpp>

#define dIMPLEMENT(...)              \
    public dTRAIT::integral_constant<bool, \
        __VA_ARGS__::value         \
    >

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    namespace method_exists
    {
        template<class t> struct op_dereference
        {
            __if_exists(t::operator*)     { enum { value = 1 }; }
            __if_not_exists(t::operator*) { enum { value = 0 }; }
        };

    } // namespace method_exists

    namespace method_available
    {
        namespace detail
        {
            typedef char(&no_ )[1];
            typedef char(&yes_)[2];
            template <class v, v> struct sig_;

            template<bool, class t, class sig> 
            struct op_dereference_impl_
            {
                #define dSFINAE_ \
                    sig_<sig, static_cast<sig>(&u::operator*) >

                template <class u> static yes_ check(dSFINAE_*);
                template <class>   static no_  check(...);
                #undef dSFINAE_
                enum { sz = sizeof(check<t>(0))  };
                enum { value = sz != sizeof(no_) };
            };

            template<class t> 
            struct op_dereference_impl_<true, t, void>
            {
                #define dSFINAE_ \
                    typename ::std::add_pointer<decltype(*std::declval<u>())>::type
                template<class u> static ::std::true_type
                    check(dSFINAE_);
                template<class> static ::std::false_type
                    check(...);
                typedef decltype(check<t>(0))
                    checked;
                enum { value = checked::value };
                #undef dSFINAE_
            };

            template<class t, class sig> 
            struct op_dereference_impl_<false, t, sig>
                { enum { value = 0}; };

            template<class t, class sig> struct op_dereference_
            {
                typedef dTRAIT::remove_reference<t>
                    no_ref;
                typedef typename no_ref::type
                    x;
                typedef dTRAIT::remove_cv<t>
                    no_cv;
                typedef typename no_cv::type
                    z;
                typedef ::tools::method_exists::op_dereference<z>
                    exists;
                enum { ex = exists::value };
                typedef op_dereference_impl_<ex, z, sig>
                    result;
                enum { value = result::value };
            };

        } // namespace detail

        template<class t, class sig = void> 
        struct op_dereference
            : dDETAIL_CONSTANT(op_dereference_<t, sig>)
        {};

    } // namespace method_available

    namespace detail
    {
        // template<class t> t obj_();

        typedef char(&no )[1];
        typedef char(&yes)[2];

        template <class v, v> struct sig;

        template<class t, class sig> 
        class deref_available_ 
        {
            #define dSFINAE_                             \
                ::tools::detail::sig<                    \
                    sig, static_cast<sig>(&u::operator*) \
                >

            typedef dTRAIT::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                x;

            struct my {};
            struct s { my operator*(); };
            struct der: /*public s, */public x {};

            template <class u> static 
                yes check(dSFINAE_*);

            template <class> static    
                no check(...);

            #undef dSFINAE_

            enum { sz = sizeof(check<der>(0)) };
        public:
            deref_available_();
            enum { value = sz != sizeof(no) };
        };

    } // namespace detail



#if 0
    // if the syntax is valid: *obj ---> dereferencable 
    template<class t, class sig> struct deref_available
        : dDETAIL_CONSTANT(deref_available_<t, sig>)
    {};
#endif

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t, class sig = void> struct deref_available
        : dIMPLEMENT(method_available::op_dereference<t, sig>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DEREF_AVAILABLE_OLD_USED_


// struct op_dereference;
// struct op_access;
// struct op_call;

