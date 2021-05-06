// [2021y-04m-30d][02:36:11] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2013_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2013_USED_ 100 PRE

#include <tools/types/sfinae/staff.hpp>

//==============================================================================
//==============================================================================

namespace tools     {
namespace sfinae    {
namespace available {

#if 0
    namespace detail
    {
        template<class t, class ...args> class call_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename decltype_<u, decltype(::std::declval<u>()(::std::declval<args>()...))>::type 
				check(u*);

            template<class> static
                ::std::false_type
                check(...);

            typedef decltype(check<x>(nullptr))
                checked;
        public:
            call_();
            enum { value = checked::value };
        };

    } // namespace detail

    template<class t, class...args>
    struct call
        : dIMPLEMENT_(call_<t, args...>)
    {};
#endif

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t> class dereference_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename decltype_<u, decltype(*::std::declval<u>())>::type 
				check(u*);

            template <class> static
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            dereference_();
            enum { value = result::value };
        };

    } // namespace detail

    template<class t> 
    class dereference
        : dIMPLEMENT_(dereference_<t>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class i> class access_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename decltype_<u, decltype(::std::declval<u>()[::std::declval<i>()])>::type 
				check(u*);

            template <class> static
                ::std::false_type check(...);

            using result = decltype(check<x>(0));
        public:
            access_();
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class i = size_t> 
    class access
        : dIMPLEMENT_(access_<t, i>)
    {};

//==============================================================================
//==============================================================================

    namespace detail_begin
    {
        template<class t, bool> class impl_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename decltype_<u, decltype(::std::declval<u>().begin())>::type
				check(u*);

            template <class> static
                ::std::false_type check(...);

            using result_t = decltype(check<x>(nullptr));
        public:
            impl_() = delete;
            enum { value = result_t::value };
        };

        template<class t> class impl_<t, false>
        {
        public:
            enum { value = false };
        };

    } // namespace detail_begin

    namespace detail
    {
        template<class t> class begin_
        {
            dNO_REFERENCE_(t, x);
            dSFINAE_PROTECTOR_(begin, x, impl_);
        public:
            enum { value = impl_::value };
        };

    } // namespace detail

    template<class t> 
    class begin
        : dIMPLEMENT_(begin_<t>)
    {};

//==============================================================================
//==============================================================================

    namespace detail_end
    {
        template<class t, bool> class impl_
        {
            using x = ::std::remove_reference_t<t>;

            template <class u> static 
                typename decltype_<u, decltype(::std::declval<u>().end())>::type
				check(u*);

            template <class> static
                ::std::false_type check(...);

            using result_t = decltype(check<x>(nullptr));
        public:
            impl_() = delete;
            enum { value = result_t::value };
        };

        template<class t> class impl_<t, false>
        {
        public:
            enum { value = false };
        };

    } // namespace detail_begin

    namespace detail
    {
        template<class t> class end_
        {
            dNO_REFERENCE_(t, x);
            dSFINAE_PROTECTOR_(end, x, impl_);
        public:
            enum { value = impl_::value };
        };

    } // namespace detail

    template<class t> 
    class end
        : dIMPLEMENT_(end_<t>)
    {};


} // namespace available
} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_AVAILABLE_2015_USED_
