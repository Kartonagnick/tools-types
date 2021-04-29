// [2021y-04m-28d][17:13:14] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2010_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2010_USED_ 100 PRE

//#include <type_traits>
#include <cstddef>

#include <tools/types/void_t.hpp>

#define dIMPLEMENT_(...)                  \
    public ::std::integral_constant<bool, \
        detail::__VA_ARGS__::value        \
    >

//==============================================================================
//==============================================================================

namespace tools 
{
    struct empty;

namespace sfinae    {

    typedef char(&no )[1];
    typedef char(&yes)[2];

namespace available {

    namespace detail
    {
        #ifdef dHAS_VARIADIC_TEMPLATE
        template<class t, class ...args> class call_
        {
            using x = ::std::remove_reference<t>;

            template<class u> static
            decltype(::std::declval<u>()(::std::declval<args>()...), ::std::true_type())
                check(u*);

            template<class> static
            ::std::false_type
                check(...);

            typedef decltype(check<x>(nullptr))
                checked;
        public:
            enum { value = checked::value };
        };

        #else

            #define dVARIADIC_7 \
                class t1, class t2 = empty, class t3 = empty, class t4 = empty, \
                class t5 = empty, class t6 = empty, class t7  = empty

            template<class t, dVARIADIC_7> class call_
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
        #endif

    } // namespace detail

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
            struct no_{};

            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type x;

            template<class u> static
            decltype(*::std::declval<u>()) check(u*);

            template<class> static no_
                check(...);
            typedef decltype(check<x>(nullptr))
                checked;
            enum { ok = ::std::is_same<checked, no_>::value };
            typedef std::integral_constant<bool, ok>
                result;
        public:
            enum { value = result::value };
        };

    } // namespace detail

    template<class t> 
    class dereference : dIMPLEMENT_(dereference_<t>) {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class i> class access_
        {
            struct no_{};
            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type x;

            template<class u> static
            decltype(::std::declval<u&>()[::std::declval<i>()]) 
                check(u*);
            template<class> static no_
                check(...);
            typedef decltype(check<x>(nullptr))
                checked;
            enum { ok = ::std::is_same<checked, no_>::value };
            typedef std::integral_constant<bool, ok>
                result;
        public:
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class i = size_t> 
    class access : dIMPLEMENT_(access_<t, i>) {};

} // namespace available
} // namespace sfinae
} // namespace tools

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_AVAILABLE_2010_USED_
