// [2021y-04m-30d][02:53:00] Idrisov Denis R. 100 PRE
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
        template<class t, class sig>
        class call_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(signature_<sig, &u::operator()>*);

            template <class> static 
                ::std::false_type  check(...);

            using result = decltype(check<x>(0));
        public:
            call_() = delete;
            enum { value = result::value };
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
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(signature_<sig, &u::operator*>*);

            template <class> static 
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            dereference_() = delete;
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class sig> 
    class dereference
        : dIMPLEMENT_(dereference_<t, sig>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class access_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                ::std::true_type check(signature_<sig, &u::operator[]>*);

            template <class> static 
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            access_() = delete;
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class sig> 
    class access
        : dIMPLEMENT_(access_<t, sig>)
    {};

//==============================================================================
//==============================================================================

    namespace detail_begin
    {
        template<class t, class sig, bool>
        class impl_
        {
            template <class u> static 
                ::std::true_type check(signature_<sig, &u::begin>*);

            template <class> static 
                ::std::false_type check(...);

            using result = decltype(check<t>(0));
        public:
            impl_() = delete;
            enum { value = result::value };
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
    class begin
        : dIMPLEMENT_(begin_<t, sig>)
    {};

//==============================================================================
//==============================================================================

} // namespace signature
} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_SIGNATURE_2013_USED_
