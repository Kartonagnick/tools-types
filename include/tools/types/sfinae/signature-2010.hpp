// [2021y-04m-28d][17:13:14] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_SIGNATURE_2010_USED_ 
#define dTOOLS_SFINAE_SIGNATURE_2010_USED_ 100 PRE

#include <type_traits>

#define dIMPLEMENT_(...)                  \
    public ::std::integral_constant<bool, \
        detail::__VA_ARGS__::value        \
    >

namespace tools 
{
    typedef char(&no)[1];
    typedef char(&yes)[2];

} // namespace tools 

//==============================================================================
//==============================================================================

namespace tools  {
namespace sfinae {
namespace signature {

    namespace detail
    {
        template<class t, class sig>
        class dereference_
        {
            #define dSFINAE_ \
                decltype(static_cast<sig>(&u::operator*))
            template <class u, class x = dSFINAE_>
            struct method { typedef x type; };
            #undef dSFINAE_

            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type x;

            template <class u> static yes check(method<u>*);
            template <class>   static no  check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            dereference_();
            enum { value = sz != sizeof(no) };
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
            #define dSFINAE_ \
                decltype(static_cast<sig>(&u::operator[]))
            template <class u, class x = dSFINAE_>
            struct method { typedef x type; };
            #undef dSFINAE_

            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type x;

            template <class u> static yes check(method<u>*);
            template <class>   static no  check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            access_();
            enum { value = sz != sizeof(no) };
        };

    } // namespace detail

    template<class t, class sig> 
    class access : dIMPLEMENT_(access_<t, sig>) {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig>
        class call_
        {
            #define dSFINAE_ \
                decltype(static_cast<sig>(&u::operator()))
            template <class u, class x = dSFINAE_>
            struct method { typedef x type; };
            #undef dSFINAE_

            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type x;

            template <class u> static yes check(method<u>*);
            template <class>   static no  check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            call_();
            enum { value = sz != sizeof(no) };
        };

    } // namespace detail

    template<class t, class sig> 
    class call
        : dIMPLEMENT_(call_<t, sig>)
    {};

} // namespace signature
} // namespace sfinae
} // namespace tools

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_SIGNATURE_2010_USED_
