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

    namespace detail_call
    {
        template<class t> struct number_arguments
        {
            enum { valid   = 0 };
            enum { count   = 0 };
            enum { ellipse = 0 };
        };

        template<class r> struct number_arguments<r()>
        {
            enum { valid   = 1 };
            enum { count   = 0 };
            enum { ellipse = 0 };
        };

        template<class r, class t1> struct number_arguments<r(t1)>
        {
            enum { valid   = 1 };
            enum { count   = 1 };
            enum { ellipse = 0 };
        };

        template<class r, class t1, class t2> struct number_arguments<r(t1, t2)>
        {
            enum { valid   = 1 };
            enum { count   = 2 };
            enum { ellipse = 0 };
        };

        template<class r, class t1, class t2, class t3>
        struct number_arguments<r(t1, t2, t3)>
        {
            enum { valid   = 1 };
            enum { count   = 3 };
            enum { ellipse = 0 };
        };

        template<class r, class t1, class t2, class t3, class t4>
        struct number_arguments<r(t1, t2, t3, t4)>
        {
            enum { valid   = 1 };
            enum { count   = 4 };
            enum { ellipse = 0 };
        };

        template<class r, class t1, class t2, class t3, class t4, class t5>
        struct number_arguments<r(t1, t2, t3, t4, t5)>
        {
            enum { valid   = 1 };
            enum { count   = 5 };
            enum { ellipse = 0 };
        };

        template<class r, class t1, class t2, class t3, class t4, class t5, class t6> 
        struct number_arguments<r(t1, t2, t3, t4, t5, t6)>
        {
            enum { valid   = 1 };
            enum { count   = 6 };
            enum { ellipse = 0 };
        };

        template<class r, class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        struct number_arguments<r(t1, t2, t3, t4, t5, t6, t7)>
        {
            enum { valid   = 1 };
            enum { count   = 7 };
            enum { ellipse = 0 };
        };

//-------------------------------

        template<class r> struct number_arguments<r(...)>
        {
            enum { valid   = 1 };
            enum { count   = 0 };
            enum { ellipse = 1 };
        };

        template<class r, class t1> struct number_arguments<r(t1, ...)>
        {
            enum { valid   = 1 };
            enum { count   = 1 };
            enum { ellipse = 1 };
        };

        template<class r, class t1, class t2> struct number_arguments<r(t1, t2, ...)>
        {
            enum { valid   = 1 };
            enum { count   = 2 };
            enum { ellipse = 1 };
        };

        template<class r, class t1, class t2, class t3>
        struct number_arguments<r(t1, t2, t3, ...)>
        {
            enum { valid   = 1 };
            enum { count   = 3 };
            enum { ellipse = 1 };
        };

        template<class r, class t1, class t2, class t3, class t4>
        struct number_arguments<r(t1, t2, t3, t4, ...)>
        {
            enum { valid   = 1 };
            enum { count   = 4 };
            enum { ellipse = 1 };
        };

        template<class r, class t1, class t2, class t3, class t4, class t5>
        struct number_arguments<r(t1, t2, t3, t4, t5, ...)>
        {
            enum { valid   = 1 };
            enum { count   = 5 };
            enum { ellipse = 1 };
        };

        template<class r, class t1, class t2, class t3, class t4, class t5, class t6> 
        struct number_arguments<r(t1, t2, t3, t4, t5, t6, ...)>
        {
            enum { valid   = 1 };
            enum { count   = 6 };
            enum { ellipse = 1 };
        };

        template<class r, class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        struct number_arguments<r(t1, t2, t3, t4, t5, t6, t7, ...)>
        {
            enum { valid   = 1 };
            enum { count   = 7 };
            enum { ellipse = 1 };
        };

//-------------------------------

        template<class fn1, class fn2> struct check_arguments_
            { enum { value = false }; };

        template<class r1, class r2> 
        struct check_arguments_<r1(), r2()>
            { enum { value = true };  };

        template<class r1, class a1, class r2, class b1> 
        struct check_arguments_<r1(a1), r2(b1)>
        {
            enum { value = dTRAIT::is_convertible<b1, a1>::value };
        };

        template<
            class r1, class a1, class a2, 
            class r2, class b1, class b2> 
        struct check_arguments_<r1(a1, a2), r2(b1, b2)>
        {
            enum { v1 = dTRAIT::is_convertible<b1, a1>::value };
            enum { v2 = dTRAIT::is_convertible<b2, a2>::value };
            enum { value = v1 && v2 };
        };

        template<
            class r1, class a1, class a2, class a3, 
            class r2, class b1, class b2, class b3> 
        struct check_arguments_<r1(a1, a2, a3), r2(b1, b2, b3)>
        {
            enum { v1 = dTRAIT::is_convertible<b1, a1>::value };
            enum { v2 = dTRAIT::is_convertible<b2, a2>::value };
            enum { v3 = dTRAIT::is_convertible<b3, a3>::value };
            enum { value = v1 && v2 && v3 };
        };

        template<
            class r1, class a1, class a2, class a3, class a4, 
            class r2, class b1, class b2, class b3, class b4> 
        struct check_arguments_<r1(a1, a2, a3, a4), r2(b1, b2, b3, b4)>
        {
            enum { v1 = dTRAIT::is_convertible<b1, a1>::value };
            enum { v2 = dTRAIT::is_convertible<b2, a2>::value };
            enum { v3 = dTRAIT::is_convertible<b3, a3>::value };
            enum { v4 = dTRAIT::is_convertible<b4, a4>::value };
            enum { value = v1 && v2 && v3 && v4 };
        };

        template<
            class r1, class a1, class a2, class a3, class a4, class a5, 
            class r2, class b1, class b2, class b3, class b4, class b5> 
        struct check_arguments_<r1(a1, a2, a3, a4, a5), r2(b1, b2, b3, b4, b5)>
        {
            enum { v1 = dTRAIT::is_convertible<b1, a1>::value };
            enum { v2 = dTRAIT::is_convertible<b2, a2>::value };
            enum { v3 = dTRAIT::is_convertible<b3, a3>::value };
            enum { v4 = dTRAIT::is_convertible<b4, a4>::value };
            enum { v5 = dTRAIT::is_convertible<b5, a5>::value };
            enum { value = v1 && v2 && v3 && v4 && v5 };
        };

        template<
            class r1, class a1, class a2, class a3, class a4, class a5, class a6,
            class r2, class b1, class b2, class b3, class b4, class b5, class b6> 
        struct check_arguments_<r1(a1, a2, a3, a4, a5, a6), r2(b1, b2, b3, b4, b5, b6)>
        {
            enum { v1 = dTRAIT::is_convertible<b1, a1>::value };
            enum { v2 = dTRAIT::is_convertible<b2, a2>::value };
            enum { v3 = dTRAIT::is_convertible<b3, a3>::value };
            enum { v4 = dTRAIT::is_convertible<b4, a4>::value };
            enum { v5 = dTRAIT::is_convertible<b5, a5>::value };
            enum { v6 = dTRAIT::is_convertible<b6, a6>::value };
            enum { value = v1 && v2 && v3 && v4 && v5 && v6 };
        };

        template<
            class r1, class a1, class a2, class a3, class a4, class a5, class a6, class a7,
            class r2, class b1, class b2, class b3, class b4, class b5, class b6, class b7> 
        struct check_arguments_<r1(a1, a2, a3, a4, a5, a6, a7), r2(b1, b2, b3, b4, b5, b6, b7)>
        {
            enum { v1 = dTRAIT::is_convertible<b1, a1>::value };
            enum { v2 = dTRAIT::is_convertible<b2, a2>::value };
            enum { v3 = dTRAIT::is_convertible<b3, a3>::value };
            enum { v4 = dTRAIT::is_convertible<b4, a4>::value };
            enum { v5 = dTRAIT::is_convertible<b5, a5>::value };
            enum { v6 = dTRAIT::is_convertible<b6, a6>::value };
            enum { v7 = dTRAIT::is_convertible<b7, a7>::value };
            enum { value = v1 && v2 && v3 && v4 && v5 && v6 && v7 };
        };

        template<class f1, class f2> class check_arguments
        {
            enum { valid_1 = number_arguments<f1>::valid };
            enum { valid_2 = number_arguments<f2>::valid };
            enum { valid   = valid_1 && valid_1 };

            enum { count_1 = number_arguments<f1>::count };
            enum { count_2 = number_arguments<f2>::count };
            enum { count   = count_1 == count_2 };

            typedef dTRAIT::conditional<
                valid && count,
                check_arguments_<f1, f2>,
                dTRAIT::false_type
            > impl;

            enum { ellipse_1 = number_arguments<f1>::ellipse };
            enum { ellipse_2 = number_arguments<f2>::ellipse };
            enum { ellipse = ellipse_1 || ellipse_2 };
        public:
            check_arguments()
            {
                dSTATIC_CHECK(ERROR_ELLIPSIS_NOT_ALLOWED, ellipse);
            }

            enum { value = impl::value };
        };

        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        class function_
        {
            typedef int fn(t1, t2, t3, t4, t5, t6, t7);
        public:
            enum { value = check_arguments<t, fn>::value };
        };

        template<class t, class t1> 
        class function_<t, t1, empty, empty, empty, empty, empty, empty>
        {
            typedef int fn(t1);
        public:
            enum { value = check_arguments<t, fn>::value };
        };

        template<class t> 
        class function_<t, empty, empty, empty, empty, empty, empty, empty>
        {
            enum { count = number_arguments<t>::count };
        public:
            enum { value = count == 0 };
        };

        #define dARG(n) obj<t##n>()
        #define dCALL obj<u&>().operator()

        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7>
        class functor_
        {
            template <class u> static 
                typename sizeof_<sizeof(dCALL(dARG(1), dARG(2), dARG(3), dARG(4), dARG(5), dARG(6), dARG(7)))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t, class t1, class t2, class t3, class t4, class t5, class t6> 
        class functor_<t, t1, t2, t3, t4, t5, t6, empty>
        {
            template <class u> static 
                typename sizeof_<sizeof(dCALL(dARG(1), dARG(2), dARG(3), dARG(4), dARG(5), dARG(6)))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t, class t1, class t2, class t3, class t4, class t5> 
        class functor_<t, t1, t2, t3, t4, t5, empty, empty>
        {
            template <class u> static 
                typename sizeof_<sizeof(dCALL(dARG(1), dARG(2), dARG(3), dARG(4), dARG(5)))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t, class t1, class t2, class t3, class t4> 
        class functor_<t, t1, t2, t3, t4, empty, empty, empty>
        {
            template <class u> static 
                typename sizeof_<sizeof(dCALL(dARG(1), dARG(2), dARG(3), dARG(4)))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t, class t1, class t2, class t3> 
        class functor_<t, t1, t2, t3, empty, empty, empty, empty>
        {
            template <class u> static 
                typename sizeof_<sizeof(dCALL(dARG(1), dARG(2), dARG(3)))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t, class t1, class t2> 
        class functor_<t, t1, t2, empty, empty, empty, empty, empty>
        {
            template <class u> static 
                typename sizeof_<sizeof(dCALL(dARG(1), dARG(2)))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t, class t1> 
        class functor_<t, t1, empty, empty, empty, empty, empty, empty>
        {
            template <class u> static 
                typename sizeof_<sizeof(dCALL(dARG(1)))>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t> 
        class functor_<t, empty, empty, empty, empty, empty, empty, empty>
        {
            template <class u> static 
                typename sizeof_<sizeof(dCALL())>::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        #undef dCALL
        #undef dARG

        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7, int> 
            class impl_;

        // !class && !function
        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        class impl_<t, t1, t2, t3, t4, t5, t6, t7, 0>
        {
        public:
            enum { value = 0 };
        };

        // class
        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        class impl_<t, t1, t2, t3, t4, t5, t6, t7, 1>
        {
            typedef functor_<t, t1, t2, t3, t4, t5, t6, t7> impl;
        public:
            enum { value = impl::value };
        };

        // function
        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        class impl_<t, t1, t2, t3, t4, t5, t6, t7, 2>
        {
            typedef dTRAIT::remove_pointer<t>                
                no_ptr;
            typedef typename no_ptr::type                
                z;
            typedef function_<z, t1, t2, t3, t4, t5, t6, t7> impl;
        public:
            enum { value = impl::value };
        };

    } // detail_call

    namespace detail
    {
        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        class call_
        {
            dNO_REFERENCE_(t, x);
            typedef dTRAIT::remove_pointer<x>                
                no_ptr;
            typedef typename no_ptr::type                
                z;
            enum { f = dTRAIT::is_function<z>::value };
            enum { c = dTRAIT::is_class<x>::value    };

            #ifdef _MSC_VER
                __if_exists    (x::operator()) { enum { v = 1 }; };
                __if_not_exists(x::operator()) { enum { v = 0 }; };
            #else
                { enum { v = 1 }; };
            #endif

            enum { select = f ? 2: c? v: 0 };
            typedef detail_call::impl_<x, t1,t2,t3,t4,t5,t6,t7, select> 
                impl;
        public:
            enum { value = impl::value };
        };

    } // namespace detail

    #define dVARIADIC_0_7 \
        class t1 = empty, class t2 = empty, class t3 = empty, \
        class t4 = empty, class t5 = empty, class t6 = empty, \
        class t7  = empty

    template<class t, dVARIADIC_0_7>
    struct call
        : dIMPLEMENT_(call_<t, t1,t2,t3,t4,t5,t6,t7>)
    {};

//==============================================================================
//==============================================================================

    namespace detail_dereference
    {
        template<class t, bool> struct check_
        {
            template <class u> static 
                typename sizeof_<sizeof(*obj<u>())>::type
                check(u*);

            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t> struct check_<t, false>
            { enum { value = false }; };

        template<class t, int> 
            class impl_;

        // --- !array && !pointer && !class
        template<class t> struct impl_<t, 0>
            { enum { value = false }; };

        // --- array or pointer or function
        template<class t> struct impl_<t, 1>
            { enum { value = true }; };

        // --- class
        template<class t> struct impl_<t, 2>
        {
        private:
            #ifdef _MSC_VER
                __if_exists    (t::operator*) { enum { v = 1 }; };
                __if_not_exists(t::operator*) { enum { v = 0 }; };
                typedef check_<t, v> result;
            #else
                typedef check_<t, true> result;
            #endif
        public:
            enum { value = result::value };
        };

    } // namespace detail_dereference

    namespace detail
    {
        template<class t> class dereference_
        {
            dNO_REFERENCE_(t, x);
            typedef dTRAIT::remove_pointer<x>                
                no_ptr;
            typedef typename no_ptr::type                
                z;
            enum { f = dTRAIT::is_function<z>::value };
            enum { p = dTRAIT::is_pointer<x>::value  };
            enum { a = dTRAIT::is_array<x>::value    };
            enum { c = dTRAIT::is_class<x>::value    };
            enum { apf = a || p || f     };
            enum { v = apf ? 1: c? 2 : 0 };
            typedef detail_dereference::impl_<x, v> 
                impl;
        public:
            enum { value = impl::value };
        };

    } // namespace detail


    template<class t> 
    class dereference
        : dIMPLEMENT_(dereference_<t>)
    {};

//==============================================================================
//=== access ===================================================================

    namespace detail_access
    {
        template<class t, class i, bool> 
        struct check_
        {
            template <class u> static 
                typename sizeof_< sizeof(obj<u>()[obj<i>()]) >::type
                check(u*);
            template <class> static no check(...);
            enum { sz = sizeof(check<t>(0)) };
        public:
            enum { value = sz < sizeof(no) };
        };

        template<class t, class i> 
        struct check_<t, i, false>
            { enum { value = false }; };

        template<class t, class i, int> 
            class impl_;

        // --- !array && !pointer && !class
        template<class t, class i> struct impl_<t, i, 0>
        { enum { value = false }; };

        // --- array or pointer
        template<class t, class i> struct impl_<t, i, 1>
        {
            enum { value = dTRAIT::is_integral<i>::value }; 
        };

        // --- class
        template<class t, class i> struct impl_<t, i, 2>
        {
        private:
            #ifdef _MSC_VER
                __if_exists    (t::operator[]) { enum { v = 1 }; }
                __if_not_exists(t::operator[]) { enum { v = 0 }; }
                typedef check_<t, i, v> check;
            #else
                typedef check_<t, i, true> check;
            #endif
        public:
            enum { value = check::value };
        };

    } // namespace detail_access

    namespace detail
    {
        template<class t, class i> class access_
        {
            dNO_REFERENCE_(t, x);
            typedef dTRAIT::remove_pointer<x>                
                no_ptr;
            typedef typename no_ptr::type                
                z;
            enum { f = dTRAIT::is_function<z>::value };
            enum { p = dTRAIT::is_pointer<x>::value  };
            enum { a = dTRAIT::is_array<x>::value    };
            enum { c = dTRAIT::is_class<x>::value    };
            enum { ap = !f && (a || p)  };
            enum { v = ap ? 1: c? 2 : 0 };
            typedef detail_access::impl_<x, i, v> 
                impl;
        public:
            enum { value = impl::value };
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
