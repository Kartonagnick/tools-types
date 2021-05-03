// [2021y-04m-30d][03:26:10] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_SIGNATURE_2013_USED_ 
#define dTOOLS_SFINAE_SIGNATURE_2013_USED_ 100 PRE

#include <tools/types/sfinae/staff.hpp>

//==============================================================================
//==============================================================================

namespace tools  {
namespace sfinae {
namespace signature {

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig> class call_
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                yes check(signature_<sig, &u::operator()>*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

    } // namespace detail

    template<class t, class sig> 
    class call
        : dIMPLEMENT_(call_<t, sig>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class dereference_
        {
            dNO_REFERENCE_(t, x);

            template <class u> static 
                yes check(signature_<sig, &u::operator*>*);

            template <class> static no check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            dereference_();
            enum { value = sz < sizeof(no) };
        };

    } // namespace detail

    template<class t, class sig> 
    class dereference : dIMPLEMENT_(dereference_<t, sig>) {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class access_
        {
            dNO_REFERENCE_(t, x);

            template <class u> static 
                yes check(signature_<sig, &u::operator[]>*);

            template <class> static no check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            access_();
            enum { value = sz < sizeof(no) };
        };

    } // namespace detail

    template<class t, class sig> 
    class access : dIMPLEMENT_(access_<t, sig>) {};

//==============================================================================
//==============================================================================

#if 0
    namespace detail
    {
        template<class t, class sig>
        class begin_
        {
            dNO_REFERENCE_(t, x);

            template <class u> static 
                yes check(signature_<sig, &u::begin>*);

            template <class> static no check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            begin_();
            enum { value = sz < sizeof(no) };
        };

    } // namespace detail
#endif

	namespace detail_begin
    {
        template<class t, class sig, bool>
        class impl_
        {
            template <class u> static 
                ::std::true_type check(signature_<sig, &u::begin>*);

            template <class> static 
                ::std::false_type check(...);

            typedef decltype(check<t>(0))
                checked;
        public:
            impl_();
            enum { value = checked::value };
        };

        template<class t, class sig> class impl_<t, sig, false>
        {
        public:
            enum { value = false };
        };

    } // namespace detail

    namespace detail
    {
        template<class t, class sig> class begin_
        {
            dNO_REFERENCE_(t, x);
            dSFINAE_PROTECTOR_SIG_(begin, x, sig, impl_);
        public:
            enum { value = impl_::value };
        };

    } // namespace detail


    template<class t, class sig> 
    class begin : dIMPLEMENT_(begin_<t, sig>) {};

//==============================================================================
//==============================================================================

} // namespace signature
} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_SIGNATURE_2013_USED_
