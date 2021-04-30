// [2021y-04m-30d][03:26:10] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_SIGNATURE_2013_USED_ 
#define dTOOLS_SFINAE_SIGNATURE_2013_USED_ 100 PRE

#include <tools/types/traits.hpp>

#define dIMPLEMENT_(...)                    \
    public ::tools::integral_constant<bool, \
        detail::__VA_ARGS__::value          \
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

    typedef char(&no )[1];
    typedef char(&yes)[2];

    template<class v, v> struct help;

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class sig> class call_
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                yes check(help<sig, &u::operator()>*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
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
                yes check(help<sig, &u::operator*>*);

            template <class> static no check(...);

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
            dNO_REFERENCE_(t, x);

            template <class u> static 
                yes check(help<sig, &u::operator[]>*);

            template <class> static no check(...);

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
        class begin_
        {
            dNO_REFERENCE_(t, x);

            template <class u> static 
                yes check(help<sig, &u::begin>*);

            template <class> static no check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            begin_();
            enum { value = sz != sizeof(no) };
        };

    } // namespace detail

    template<class t, class sig> 
    class begin : dIMPLEMENT_(begin_<t, sig>) {};

//==============================================================================
//==============================================================================

} // namespace signature
} // namespace sfinae
} // namespace tools

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_SIGNATURE_2013_USED_
