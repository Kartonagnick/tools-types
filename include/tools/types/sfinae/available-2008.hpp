// [2021y-04m-30d][03:25:40] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2008_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2008_USED_ 100 PRE

#include <tools/types/sfinae/staff.hpp>

//==============================================================================
//==============================================================================

namespace tools     {
namespace sfinae    {
namespace available {

    namespace detail
    {
        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7> class call_
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(obj<u>().operator()(obj<t1>(), obj<t2>(), obj<t3>(), obj<t4>(), obj<t5>(), obj<t6>(), obj<t7>()))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

        template<class t, class t1, class t2, class t3, class t4, class t5, class t6> 
        class call_<t, t1, t2, t3, t4, t5, t6, empty>
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(obj<u>().operator()(obj<t1>(), obj<t2>(), obj<t3>(), obj<t4>(), obj<t5>(), obj<t6>()))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

        template<class t, class t1, class t2, class t3, class t4, class t5> 
        class call_<t, t1, t2, t3, t4, t5, empty, empty>
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(obj<u>().operator()(obj<t1>(), obj<t2>(), obj<t3>(), obj<t4>(), obj<t5>()))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

        template<class t, class t1, class t2, class t3, class t4> 
        class call_<t, t1, t2, t3, t4, empty, empty, empty>
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(obj<u>().operator()(obj<t1>(), obj<t2>(), obj<t3>(), obj<t4>()))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

        template<class t, class t1, class t2, class t3> 
        class call_<t, t1, t2, t3, empty, empty, empty, empty>
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(obj<u>().operator()(obj<t1>(), obj<t2>(), obj<t3>()))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

        template<class t, class t1, class t2> 
        class call_<t, t1, t2, empty, empty, empty, empty, empty>
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(obj<u>().operator()(obj<t1>(), obj<t2>()))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

        template<class t, class t1> 
        class call_<t, t1, empty, empty, empty, empty, empty, empty>
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(obj<u>().operator()(obj<t1>()))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

        template<class t> 
        class call_<t, empty, empty, empty, empty, empty, empty, empty>
        {
            dNO_REFERENCE_(t, x);

            template <class u> static 
                //typename sizeof_<u, sizeof(obj<u>()())>::type

                typename sizeof_<sizeof( obj<u>().operator()() )>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
        };

    } // namespace detail

    #define dVARIADIC_7 \
        class t1, class t2 = empty, class t3 = empty, class t4 = empty, \
        class t5 = empty, class t6 = empty, class t7  = empty

    template<class t, dVARIADIC_7>
    struct call
        : dIMPLEMENT_(call_<t, t1,t2,t3,t4,t5,t6,t7>)
    {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t> class dereference_
        {
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(*obj<u>())>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
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
            dNO_REFERENCE_(t, x);
            template <class u> static 
                typename sizeof_<sizeof(obj<u>()[ obj<i>() ]) >::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<x>(0)) };
        public:
            enum { value = sz != sizeof(no) };
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
            template <class u> static 
                typename sizeof_< sizeof(obj<u>().begin()) >::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
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
            template <class u> static 
                typename sizeof_< sizeof(obj<u>().end()) >::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
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
#endif // !dTOOLS_SFINAE_AVAILABLE_2008_USED_
