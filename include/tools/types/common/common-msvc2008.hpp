// [2021y-03m-19d][19:47:19] Idrisov Denis R.
// [2021y-03m-20d][19:43:08] Idrisov Denis R. 103
// [2021y-03m-21d][17:51:39] Idrisov Denis R. 104
// [2021y-03m-23d][23:55:08] Idrisov Denis R. 105
// [2021y-03m-29d][23:43:28] Idrisov Denis R. 106 PRE
#pragma once
#ifndef dTOOLS_COMMON_NEW_USED_ 
#define dTOOLS_COMMON_NEW_USED_ 106,2008

#include <cstddef>

#if defined(dHAS_TYPE_TRAITS ) && defined(dHAS_RVALUE_REFERENCES)
    #include <type_traits>
#else
    #include <tools/types/traits.hpp>
#endif

#define dDETAIL_CONSTANT(...) \
    public dTRAIT::integral_constant<bool, detail::__VA_ARGS__::value>

#define dVARIADIC_7 \
    class t1, class t2 = empty, class t3 = empty, class t4 = empty, \
    class t5 = empty, class t6 = empty, class t7  = empty

#define dCLASS_A1 class a1
#define dCLASS_A2 dCLASS_A1, class a2
#define dCLASS_A3 dCLASS_A2, class a3
#define dCLASS_A4 dCLASS_A3, class a4
#define dCLASS_A5 dCLASS_A4, class a5
#define dCLASS_A6 dCLASS_A5, class a6
#define dCLASS_A7 dCLASS_A6, class a7

#define dARGS_A1 a1
#define dARGS_A2 dARGS_A1, a2
#define dARGS_A3 dARGS_A2, a3
#define dARGS_A4 dARGS_A3, a4
#define dARGS_A5 dARGS_A4, a5
#define dARGS_A6 dARGS_A5, a6
#define dARGS_A7 dARGS_A6, a7

//==============================================================================
//=== [sfinae/help] ============================================================
#if 0
#ifndef dTOOLS_SFINAE_USED_ 
#define dTOOLS_SFINAE_USED_ 100
namespace tools
{
    namespace detail
    {
        template <class v, v> struct 
            help {};

        template<size_t n> struct sfinae 
            { char val[n]; };

        struct no  { char val[1]; };
        struct yes { char val[2]; };

        template<class t>       t& operator, (      t&, no);
        template<class t> const t& operator, (const t&, no);

        template<class t> t val();
        template<class t> yes confirm(t&);
        template<class t> yes confirm(const t&);

    } // namespace detail

} // namespace tools 
#endif // !dTOOLS_SFINAE_USED_
#endif

//==============================================================================
//=== find_type ================================================================
#ifndef dTOOLS_FIND_TYPE_USED_ 
#define dTOOLS_FIND_TYPE_USED_ 100,2008
namespace tools
{
    struct empty;

    // if type 't' is in the list 'args' --> true
    namespace detail
    {
        template<class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        struct find_type
        {
            enum { r1 = dTRAIT::is_same<t1, t2>::value };
            enum { r2 = dTRAIT::is_same<t1, t3>::value };
            enum { r3 = dTRAIT::is_same<t1, t4>::value };
            enum { r4 = dTRAIT::is_same<t1, t5>::value };
            enum { r5 = dTRAIT::is_same<t1, t6>::value };
            enum { r6 = dTRAIT::is_same<t1, t7>::value };
            enum { value = r1 || r2 || r3 || r4 || r5 || r6 };
        };

        template<class t1, class t2, class t3, class t4, class t5, class t6> 
        struct find_type<t1, t2, t3, t4, t5, t6, empty>
        {
            enum { r1 = dTRAIT::is_same<t1, t2>::value };
            enum { r2 = dTRAIT::is_same<t1, t3>::value };
            enum { r3 = dTRAIT::is_same<t1, t4>::value };
            enum { r4 = dTRAIT::is_same<t1, t5>::value };
            enum { r5 = dTRAIT::is_same<t1, t6>::value };
            enum { value = r1 || r2 || r3 || r4 || r5 };
        };

        template<class t1, class t2, class t3, class t4, class t5> 
        struct find_type<t1, t2, t3, t4, t5, empty, empty>
        {
            enum { r1 = dTRAIT::is_same<t1, t2>::value };
            enum { r2 = dTRAIT::is_same<t1, t3>::value };
            enum { r3 = dTRAIT::is_same<t1, t4>::value };
            enum { r4 = dTRAIT::is_same<t1, t5>::value };
            enum { value = r1 || r2 || r3 || r4 };
        };

        template<class t1, class t2, class t3, class t4> 
        struct find_type<t1, t2, t3, t4, empty, empty, empty>
        {
            enum { r1 = dTRAIT::is_same<t1, t2>::value };
            enum { r2 = dTRAIT::is_same<t1, t3>::value };
            enum { r3 = dTRAIT::is_same<t1, t4>::value };
            enum { value = r1 || r2 || r3 };
        };

        template<class t1, class t2, class t3> 
        struct find_type<t1, t2, t3, empty, empty, empty, empty>
        {
            enum { r1 = dTRAIT::is_same<t1, t2>::value };
            enum { r2 = dTRAIT::is_same<t1, t3>::value };
            enum { value = r1 || r2 };
        };

        template<class t1, class t2> 
        struct find_type<t1, t2, empty, empty, empty, empty, empty>
        {
            enum { value = dTRAIT::is_same<t1, t2>::value };
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


//=== working but outdated version =============================================
//=== is_functor ===============================================================
#if 0
#ifndef dTOOLS_IS_FUNCTOR_USED_ 
#define dTOOLS_IS_FUNCTOR_USED_ 100,2008
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
            typedef dTRAIT::remove_reference<t>
                noref;
            typedef typename noref::type 
                x;

            enum { ok    = dTRAIT::is_class<x>::value   };
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
#define dTOOLS_IS_FUNCTOR_USED_ 101,2008
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
            typedef dTRAIT::remove_reference<t>
                noref;
            typedef typename noref::type 
                x;

            enum { ok = dTRAIT::is_class<x>::value   };
            enum { value = is_functor_<x, ok>::value };
        };

    } // namespace detail

    template<class F> class is_functor
        : dDETAIL_CONSTANT(is_functor<F>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_FUNCTOR_USED_


//==============================================================================
//=== is_zero_array ============================================================
#ifndef dTOOLS_IS_ZERO_ARRAY_USED_ 
#define dTOOLS_IS_ZERO_ARRAY_USED_ 100,2008
namespace tools 
{
    #ifdef dHAS_ZERO_SIZE_ARRAY
        dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        template<class s> struct is_zero_array
            : dTRAIT::false_type
        { typedef s type; };


        template<class s> struct is_zero_array<s[0]>
            : dTRAIT::true_type
        { typedef s type; };

        dPRAGMA_POP
    #else

        template<class s> struct is_zero_array
            : dTRAIT::false_type
        { typedef s type; };

    #endif

} // namespace tools 
#endif // !dTOOLS_IS_ZERO_ARRAY_USED_


//==============================================================================
//=== size_array ===========================================(is_zero_array) ====
#ifndef dTOOLS_SIZE_ARRAY_USED_ 
#define dTOOLS_SIZE_ARRAY_USED_ 100,2008
namespace tools
{
    template<class s> class size_array
    {
        typedef ::tools::is_zero_array<s> 
            view;

        enum
        {
            z = ::tools::is_zero_array<s>::value
        };
    public:
        enum { valid = 0 };
        enum { value = 0 };
        enum { big   = 0 };
        enum { Small = 0 }; // fucking windows:  #define small char
        enum { empty = 0 };
        enum { zero  = z };

        typedef typename view::type  
            type;

        typedef type   arr;
        typedef type&  ref;
        #ifdef dHAS_RVALUE_REFERENCE
        typedef type&& rval;
        #endif
    };
    template<class s, size_t N> class size_array<s[N]>
    {
    public:
        enum { valid = 1        };
        enum { value = N        };
        enum { big   = N  > 255 };
        enum { Small = N <= 255 };
        enum { empty = 0        };
        enum { zero  = N == 0   };
        
        typedef s type;
        typedef type arr[value];
        typedef type(&ref)[value];
        #ifdef dHAS_RVALUE_REFERENCE
        typedef type(&&rval)[value];
        #endif
    };
    template<class s> class size_array<s[]>
    {
    public:
        enum { valid = 1 };
        enum { value = 0 };
        enum { big   = 0 };
        enum { Small = 0 };
        enum { empty = 1 };
        enum { zero  = 0 };

        typedef s type;
        typedef type arr[];

        #ifdef dHAS_ZERO_SIZE_ARRAY
        typedef type(&ref)[];
        #ifdef dHAS_RVALUE_REFERENCE
        typedef type(&&rval)[];
        #endif
        #endif // dHAS_ZERO_SIZE_ARRAY

    };

    #define dif_big_array(arr, ret)                          \
        typename dTRAIT::enable_if<                          \
            ::tools::size_array<                             \
                typename dTRAIT::remove_reference<arr>::type \
            >::big, ret                                      \
        >::type

    #define dif_small_array(arr, ret)                        \
        typename dTRAIT::enable_if<                          \
            ::tools::size_array<                             \
                typename dTRAIT::remove_reference<arr>::type \
            >::Small, ret                                    \
        >::type

} // namespace tools 
#endif // !dTOOLS_SIZE_ARRAY_USED_


//==============================================================================
//=== small_array =================================(degradate)(size_array) =====
#ifndef dTOOLS_SMALL_ARRAY_USED_ 
#define dTOOLS_SMALL_ARRAY_USED_ 100,2008
namespace tools 
{
    template<class s1, class s2>
    class small_array_selector
    {
        typedef typename dTRAIT::remove_reference<s1>::type x;
        typedef typename dTRAIT::remove_reference<s2>::type z;

        typedef ::tools::size_array<x> xx;
        typedef ::tools::size_array<z> zz;

        enum { small1 = xx::Small && xx::valid };
        enum { small2 = zz::Small && zz::valid };
    public:
        enum { value = small1 && small2 };
    };

    #define dif_big_arrays(a, b, ret)                    \
        typename dTRAIT::enable_if<                      \
            !::tools::small_array_selector<a, b>::value, \
            ret                                          \
        >::type 

    #define dif_small_arrays(a, b, ret)                  \
        typename dTRAIT::enable_if<                      \
            ::tools::small_array_selector<a, b>::value,  \
            ret                                          \
        >::type 

} // namespace tools 
#endif // !dTOOLS_SMALL_ARRAY_USED_


//==============================================================================
//=== add_const_data ===========================================================
#ifndef dTOOLS_ADD_CONST_DATA_USED_ 
#define dTOOLS_ADD_CONST_DATA_USED_ 100,2008
namespace tools
{
    dPRAGMA_PUSH_WARNING_QUALIFIER_APPLIED_TO_REFERENCE_TYPE
    dPRAGMA_PUSH_WARNING_QUALIFIER_RETURN_TYPE

    template<class t> class add_const_data;

    namespace detail
    {
        template<class t> struct add_const_data
        {
            typedef const t type; 
        };

        template<class t> struct add_const_data<t&>
        {
            typedef typename ::tools::add_const_data<t>::type
				x;
            typedef x& type; 
        };

		#ifdef dHAS_RVALUE_REFERENCES
        template<class t> struct add_const_data<t&&>
        {
            typedef typename ::tools::add_const_data<t>::type
				x;
            typedef x&& type; 
        };
		#endif

        template<class t> struct add_const_data<t[]>
		{
			typedef typename add_const_data<t>::type 
				type[]; 
		};

        template<class t, size_t n> struct add_const_data<t[n]>
        { 
			typedef typename add_const_data<t>::type 
				type[n];
		};

        #ifdef dHAS_ZERO_SIZE_ARRAY
        dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        template<class t> struct add_const_data<t[0]>
        {
			typedef typename add_const_data<t>::type 
				type[0]; 
		};
        dPRAGMA_POP
        #endif // !dHAS_ZERO_SIZE_ARRAY

        template<class t> struct add_const_data<t*>
            { typedef typename add_const_data<t>::type* type; };

        template<class t> struct add_const_data<t* const>
            { typedef typename add_const_data<t>::type*const type; };

        template<class t> struct add_const_data<t* volatile>
            { typedef typename add_const_data<t>::type*volatile type; };

        template<class t> struct add_const_data<t* volatile const>
            { typedef typename add_const_data<t>::type*volatile const type; };

        template<class m, class cl> struct add_const_data<m cl::*>
            { typedef const m cl::*type; };

        template<class m, class cl> struct add_const_data<m cl::*const>
            { typedef const m cl::*const type; };

        template<class m, class cl> struct add_const_data<m cl::*volatile>
            { typedef const m cl::*volatile type; };

        template<class m, class cl> struct add_const_data<m cl::*volatile const>
            { typedef const m cl::*volatile const type; };

		template<class t, bool> struct add_const_data_help_
            { typedef t& type; };

		template<class t> struct add_const_data_help_<t, false>
            { typedef t type; };

    } // namespace detail

    template<class t> class add_const_data
    {
        enum { v1 = dTRAIT::is_const<t>::value };
        enum { v2 = dTRAIT::is_volatile<t>::value };
        typedef typename dTRAIT::remove_cv<t>::type
            x;
        typedef typename detail::add_const_data<x>::type 
            r1;
        typedef typename dTRAIT::conditional< v1, const r1, r1>::type 
            r2;
        typedef typename dTRAIT::conditional< v2, volatile r2, r2>::type
            r3;
    public:
        typedef r3 type;



#if 0
		enum { v1 = dTRAIT::is_reference<t>::value };
        typedef typename dTRAIT::remove_reference<t>::type
            x;
        enum { v2 = !v1 && dTRAIT::is_const<x>::value    };
        enum { v3 = !v1 && dTRAIT::is_volatile<x>::value };

        typedef typename dTRAIT::remove_cv<t>::type
            z;
        typedef typename detail::add_const_data<z>::type 
            r1;

        typedef typename dTRAIT::conditional<v2, const r1, r1>::type 
            r2;
        typedef typename dTRAIT::conditional<v3, volatile r2, r2>::type 
            r3;
        typedef typename detail::add_const_data_help_<r3, v1>::type
            r4;
    public:
        typedef r4 type;
#endif
    };

    dPRAGMA_POP
    dPRAGMA_POP

} // namespace tools
#endif // !dTOOLS_ADD_CONST_DATA_USED_


//==============================================================================
//=== is_dereferencable ========================================================
#ifndef dTOOLS_IS_DEREFERENCABLE_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_USED_ 100,2008
namespace tools 
{
    namespace detail
    {
        template<class F, bool> struct is_deref_
        {
            __if_exists(F::operator*)
            {
                enum { value = true };
            }

            __if_not_exists(F::operator*) 
            {
                enum { value = false };
            }
        };

        template <class t> struct is_deref_<t, false>
        {
            enum { value = false };
        };

        template <class t> struct is_deref_<t*, false>
        {
            enum { value = true };
        };
        template <class t> struct is_deref_<t*const, false>
        {
            enum { value = true };
        };
        template <class t> struct is_deref_<t*volatile, false>
        {
            enum { value = true };
        };
        template <class t> struct is_deref_<t*volatile const, false>
        {
            enum { value = true };
        };

        template <class t, size_t n> struct is_deref_<t[n], false>
        {
            enum { value = true };
        };

        template <class t> struct is_dereferencable
        {
            typedef dTRAIT::remove_reference<t>
                noref;
            typedef typename noref::type 
                x;

            enum { ok = dTRAIT::is_class<x>::value };
            enum { value = is_deref_<x, ok>::value };
        };

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t> struct is_dereferencable
        : dDETAIL_CONSTANT(is_dereferencable<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_DEREFERENCABLE_USED_


//==============================================================================
//=== is_volatile_data =========================================================
#ifndef dTOOLS_IS_VOLATILE_DATA_USED_ 
#define dTOOLS_IS_VOLATILE_DATA_USED_ 100,2008
namespace tools
{
    namespace detail
    {
        template<class t> class is_volatile_data
        {
            typedef dTRAIT::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type 
                x;
            typedef dTRAIT::remove_pointer<x> 
                no_ptr;
            typedef typename no_ptr::type 
                z;
        public:
            enum { value = dTRAIT::is_volatile<z>::value };
        };

    } // namespace detail

    template<class t> struct is_volatile_data
        : dDETAIL_CONSTANT(is_volatile_data<t>)
    {};

} // namespace tools
#endif // !dTOOLS_IS_VOLATILE_DATA_USED_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMMON_NEW_USED_
