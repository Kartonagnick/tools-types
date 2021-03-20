// [2021y-03m-19d][19:47:19] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_COMMON_NEW_USED_ 
#define dTOOLS_COMMON_NEW_USED_ 102

#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>
    #define dMY ::std
#else
    #include <tools/types/traits.hpp>
    #define dMY ::tools
#endif

#define dDETAIL_CONSTANT(...) \
    dMY::integral_constant<bool, detail::__VA_ARGS__::value>

#define dVARIADIC_7 \
    class t1, class t2 = empty, class t3 = empty, class t4 = empty, \
    class t5 = empty, class t6 = empty, class t7  = empty


//==============================================================================
//=== find_type ================================================================
#ifndef dTOOLS_FIND_TYPE_USED_ 
#define dTOOLS_FIND_TYPE_USED_ 100
namespace tools
{
    struct empty;

    // if type 't' is in the list 'args' --> true
    namespace detail
    {
        template<class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        struct find_type
        {
            enum { r1 = dMY::is_same<t1, t2>::value };
            enum { r2 = dMY::is_same<t1, t3>::value };
            enum { r3 = dMY::is_same<t1, t4>::value };
            enum { r4 = dMY::is_same<t1, t5>::value };
            enum { r5 = dMY::is_same<t1, t6>::value };
            enum { r6 = dMY::is_same<t1, t7>::value };
            enum { value = r1 || r2 || r3 || r4 || r5 || r6 };
        };

        template<class t1, class t2, class t3, class t4, class t5, class t6> 
        struct find_type<t1, t2, t3, t4, t5, t6, empty>
        {
            enum { r1 = dMY::is_same<t1, t2>::value };
            enum { r2 = dMY::is_same<t1, t3>::value };
            enum { r3 = dMY::is_same<t1, t4>::value };
            enum { r4 = dMY::is_same<t1, t5>::value };
            enum { r5 = dMY::is_same<t1, t6>::value };
            enum { value = r1 || r2 || r3 || r4 || r5 };
        };

        template<class t1, class t2, class t3, class t4, class t5> 
        struct find_type<t1, t2, t3, t4, t5, empty, empty>
        {
            enum { r1 = dMY::is_same<t1, t2>::value };
            enum { r2 = dMY::is_same<t1, t3>::value };
            enum { r3 = dMY::is_same<t1, t4>::value };
            enum { r4 = dMY::is_same<t1, t5>::value };
            enum { value = r1 || r2 || r3 || r4 };
        };

        template<class t1, class t2, class t3, class t4> 
        struct find_type<t1, t2, t3, t4, empty, empty, empty>
        {
            enum { r1 = dMY::is_same<t1, t2>::value };
            enum { r2 = dMY::is_same<t1, t3>::value };
            enum { r3 = dMY::is_same<t1, t4>::value };
            enum { value = r1 || r2 || r3 };
        };

        template<class t1, class t2, class t3> 
        struct find_type<t1, t2, t3, empty, empty, empty, empty>
        {
            enum { r1 = dMY::is_same<t1, t2>::value };
            enum { r2 = dMY::is_same<t1, t3>::value };
            enum { value = r1 || r2 };
        };

        template<class t1, class t2> 
        struct find_type<t1, t2, empty, empty, empty, empty, empty>
        {
            enum { value = dMY::is_same<t1, t2>::value };
        };

        template<class t1> 
        struct find_type<t1, empty, empty, empty, empty, empty, empty>
        {
            enum { value = false };
        };

    } // namespace detail

    // if type 't' is in the list 'args' --> true
    template<dVARIADIC_7>
    struct find_type
        : dDETAIL_CONSTANT(find_type<t1, t2, t3, t4, t5, t6, t7>)
    {};

} // namespace tools 
#endif // !dTOOLS_FIND_TYPE_USED_

#if 0
//=== working but outdated version =============================================
//=== is_functor ===============================================================
#ifndef dTOOLS_IS_FUNCTOR_USED_ 
#define dTOOLS_IS_FUNCTOR_USED_ 100
namespace tools
{
    namespace detail
    {
        struct oper { void operator()() const; };

        template <class v, v> struct 
            help {};

        typedef char (&no )[1]; 
        typedef char (&yes)[2];

        template <class t, bool>
        struct is_functor_
        {
            struct der : oper, t {};

            template <class u> static
                no check(help<void (u::*)(), &u::operator()>*);

            template <typename> static
                yes check(...);

            enum { result = sizeof(check<der>(0)) };
            enum { value = result != sizeof(no)   };
        };

        template <class t> 
        struct is_functor_<t, false>
        {
            enum { value = false };
        };

        template <class t>
        struct is_functor
        {
            typedef dMY::remove_reference<t>
                noref;
            typedef typename noref::type 
                x;

            enum { ok    = dMY::is_class<x>::value   };
            enum { value = is_functor_<x, ok>::value };
        };

    } // namespace detail

    template<class F> class is_functor
        : public dDETAIL_CONSTANT(is_functor<F>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_FUNCTOR_USED_
#endif

//==============================================================================
//=== is_functor ===============================================================
#ifndef dTOOLS_IS_FUNCTOR_USED_ 
#define dTOOLS_IS_FUNCTOR_USED_ 101
namespace tools
{
    namespace detail
    {
        template<class F, bool> struct is_functor_
        {
            __if_exists(F::operator())
            {
                enum { value = true };
            }

            __if_not_exists(F::operator()) 
            {
                enum { value = false };
            }
        };

        template <class t> 
        struct is_functor_<t, false>
        {
            enum { value = false };
        };

        template <class t> struct is_functor
        {
            typedef dMY::remove_reference<t>
                noref;
            typedef typename noref::type 
                x;

            enum { ok = dMY::is_class<x>::value  };
            enum { value = is_functor_<x, ok>::value };
        };

    } // namespace detail

    template<class F> class is_functor
        : public dDETAIL_CONSTANT(is_functor<F>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_FUNCTOR_USED_

//==============================================================================
//==============================================================================
#undef dMY
#endif // !dTOOLS_COMMON_NEW_USED_


