// [2021y-05m-03d][16:50:15] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2012_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2012_USED_ 100 PRE

#include <tools/types/sfinae/staff.hpp>

//==============================================================================
//==============================================================================

namespace tools     {
namespace sfinae    {
namespace available {

    namespace detail
    {
        template<class t, class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        class call_
        {
            typedef ::std::remove_reference<t> no_ref;
            typedef typename no_ref::type x;

            template<class u> static
                decltype(::std::declval<u>()(
                ::std::declval<t1>(),
                ::std::declval<t2>(), 
                ::std::declval<t3>(), 
                ::std::declval<t4>(), 
                ::std::declval<t5>(),
                ::std::declval<t6>(), 
                ::std::declval<t7>()
                ), ::std::true_type()
                ) check(u*);

            template<class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t, class t1, class t2, class t3, class t4, class t5, class t6> 
        class call_<t, t1, t2, t3, t4, t5, t6, empty>
        {
            typedef ::std::remove_reference<t> no_ref;
            typedef typename no_ref::type x;

            template<class u> static
                decltype(::std::declval<u>()(
                ::std::declval<t1>(),
                ::std::declval<t2>(), 
                ::std::declval<t3>(), 
                ::std::declval<t4>(), 
                ::std::declval<t5>(),
                ::std::declval<t6>()
                ), ::std::true_type()
                ) check(u*);

            template<class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t, class t1, class t2, class t3, class t4, class t5> 
        class call_<t, t1, t2, t3, t4, t5, empty, empty>
        {
            typedef ::std::remove_reference<t> no_ref;
            typedef typename no_ref::type x;

            template<class u> static
                decltype(::std::declval<u>()(
                ::std::declval<t1>(),
                ::std::declval<t2>(), 
                ::std::declval<t3>(), 
                ::std::declval<t4>(), 
                ::std::declval<t5>()
                ), ::std::true_type()
                ) check(u*);

            template<class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t, class t1, class t2, class t3, class t4> 
        class call_<t, t1, t2, t3, t4, empty, empty, empty>
        {
            typedef ::std::remove_reference<t> no_ref;
            typedef typename no_ref::type x;

            template<class u> static
                decltype(::std::declval<u>()(
                ::std::declval<t1>(),
                ::std::declval<t2>(), 
                ::std::declval<t3>(), 
                ::std::declval<t4>() 
                ), ::std::true_type()
                ) check(u*);

            template<class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t, class t1, class t2, class t3> 
        class call_<t, t1, t2, t3, empty, empty, empty, empty>
        {
            typedef ::std::remove_reference<t> no_ref;
            typedef typename no_ref::type x;

            template<class u> static
                decltype(::std::declval<u>()(
                ::std::declval<t1>(),
                ::std::declval<t2>(), 
                ::std::declval<t3>() 
                ), ::std::true_type()
                ) check(u*);

            template<class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t, class t1, class t2> 
        class call_<t, t1, t2, empty, empty, empty, empty, empty>
        {
            typedef ::std::remove_reference<t> no_ref;
            typedef typename no_ref::type x;

            template<class u> static
                decltype(::std::declval<u>()(
                ::std::declval<t1>(),
                ::std::declval<t2>()
                ), ::std::true_type()
                ) check(u*);

            template<class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t, class t1> 
        class call_<t, t1, empty, empty, empty, empty, empty, empty>
        {
            typedef ::std::remove_reference<t> no_ref;
            typedef typename no_ref::type x;

            template<class u> static
                decltype(::std::declval<u>()(::std::declval<t1>()), 
                ::std::true_type()
                ) check(u*);

            template<class> static
                ::std::false_type check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            enum { value = checked::value };
        };

        template<class t> 
        class call_<t, empty, empty, empty, empty, empty, empty, empty>
        {
            typedef ::std::remove_reference<t> no_ref;
            typedef typename no_ref::type x;

            template<class u> static
                decltype(::std::declval<u>()(), ::std::true_type())
                check(u*);

            template<class> static
                ::std::false_type
                check(...);

            typedef decltype(check<x>(0))
                checked;
        public:
            enum { value = checked::value };
        };

    } // namespace detail

    #define dVARIADIC_0_7 \
        class t1 = empty, class t2 = empty, class t3 = empty, class t4 = empty, \
        class t5 = empty, class t6 = empty, class t7  = empty

    template<class t, dVARIADIC_0_7>
    struct call
        : dIMPLEMENT_(call_<t, t1,t2,t3,t4,t4,t6,t7>)
    {};

//==============================================================================
//==============================================================================

    namespace detail_dereference
    {
        template<class t, class sig>
        class sig_
        {
            template <class u> static 
                ::std::true_type check(signature_<sig, &u::operator*>*);

            template <class> static 
                ::std::false_type check(...);

            typedef decltype(check<t>(nullptr))
                result;
        public:
            enum { value = result::value };
        };

        template<class t, bool> struct check_
        {
            typedef ::std::remove_cv<t> no_cv;
            typedef typename no_cv::type x;

            enum { ms = sig_<x, x(x::*)()     >::value };
            enum { cs = sig_<x, x(x::*)()const>::value };

            template <class u> static 
                    typename decltype_<u, decltype(*::std::declval<u>())>::second 
                    check(u*);

            template <class> static
                ::std::false_type check(...);

            typedef decltype(check<t>(nullptr))
                checked;

            typedef ::std::add_pointer<checked> add;
            typedef typename add::type z;

            enum { inva = ::std::is_same<checked, ::std::false_type>::value };
            enum { same = ::std::is_same<z, t*>::value };
            enum { isConst = ::std::is_const<t>::value };
            enum { first = isConst? cs : (cs || ms)    };
        public:
            enum { value = inva ? false: (!same || first) };
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

            typedef ::std::remove_pointer<x>                
                no_ptr;
            typedef typename no_ptr::type                
                z;
            enum { f = ::std::is_function<z>::value };
            enum { p = ::std::is_pointer<x>::value  };
            enum { a = ::std::is_array<x>::value    };
            enum { c = ::std::is_class<x>::value    };
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
//==============================================================================

    namespace detail_access
    {
        template<class t, class i, bool> struct check_
        {
            template <class u> static 
                typename decltype_<u, decltype(::std::declval<u>()[::std::declval<i>()]) >::type
                check(u*);

            template <class> static
                ::std::false_type check(...);

            typedef decltype(check<t>(nullptr))
                result;
        public:
            enum { value = result::value };
        };

        template<class t, class i> struct check_<t, i, false>
            { enum { value = false }; };

        template<class t, class i, int> 
            class impl_;

        // --- !array && !pointer && !class
        template<class t, class i> struct impl_<t, i, 0>
            { enum { value = false }; };

        // --- array or pointer
        template<class t, class i> struct impl_<t, i, 1>
        {
            enum { value = ::std::is_integral<i>::value }; 
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
            typedef ::std::remove_pointer<x>                
                no_ptr;
            typedef typename no_ptr::type                
                z;
            enum { f = ::std::is_function<z>::value };
            enum { p = ::std::is_pointer<x>::value  };
            enum { a = ::std::is_array<x>::value    };
            enum { c = ::std::is_class<x>::value    };
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
                typename decltype_<u, decltype(::std::declval<u>().begin())>::type
                check(u*);

            template <class> static
                ::std::false_type check(...);

            typedef decltype(check<t>(0))
                result;
        public:
            enum { value = result::value };
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
                typename decltype_<u, decltype(::std::declval<u>().end())>::type
                check(u*);

            template <class> static
                ::std::false_type check(...);

            typedef decltype(check<t>(0))
                result;
        public:
            enum { value = result::value };
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
#endif // !dTOOLS_SFINAE_AVAILABLE_2012_USED_
