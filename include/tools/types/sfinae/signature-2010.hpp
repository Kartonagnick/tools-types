// [2021y-04m-30d][03:11:14] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_SIGNATURE_2013_USED_ 
#define dTOOLS_SFINAE_SIGNATURE_2013_USED_ 100 PRE

#include <tools/types/traits/no_ref.hpp>
#include <type_traits>

#define dIMPLEMENT_(...)                  \
    public ::std::integral_constant<bool, \
        detail::__VA_ARGS__::value        \
    >

#define dNO_REFERENCE_(t,x)              \
    typedef ::tools::remove_reference<t> \
        no_ref;                          \
    typedef typename no_ref::type x

//==============================================================================
//==============================================================================

namespace tools  {
namespace sfinae {
namespace signature {

    template<class V, V> struct help;

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class call_
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                ::std::true_type check(help<sig, &u::operator()>*);

            template <class> static 
                ::std::false_type  check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            call_();
            enum { value = checked::value };
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
                ::std::true_type check(help<sig, &u::operator*>*);

            template <class> static 
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            dereference_();
            enum { value = checked::value };
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
            dNO_REFERENCE_(t, x);

            template <class u> static 
                ::std::true_type check(help<sig, &u::operator[]>*);

            template <class> static 
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            access_();
            enum { value = checked::value };
        };

    } // namespace detail

    template<class t, class sig> 
    class access
        : dIMPLEMENT_(access_<t, sig>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class begin_
        {
            dNO_REFERENCE_(t, x);

            template <class u> static 
                ::std::true_type check(help<sig, &u::begin>*);

            template <class> static 
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            begin_();
            enum { value = checked::value };
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

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_SIGNATURE_2013_USED_
