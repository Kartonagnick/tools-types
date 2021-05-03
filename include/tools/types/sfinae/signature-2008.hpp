// [2021y-04m-30d][03:26:10] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_SIGNATURE_2008_USED_ 
#define dTOOLS_SFINAE_SIGNATURE_2008_USED_ 100 PRE

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
            enum { value = sz < sizeof(no) };
        };

    } // namespace detail

    template<class t, class sig> 
    class access : dIMPLEMENT_(access_<t, sig>) {};

//==============================================================================
//==============================================================================

	namespace detail_begin
    {
        template<class t, class sig, bool>
        class impl_
        {
            template <class u> static 
                yes check(signature_<sig, &u::begin>*);

            template <class> static 
                no check(...);

            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
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
#endif // !dTOOLS_SFINAE_SIGNATURE_2008_USED_
