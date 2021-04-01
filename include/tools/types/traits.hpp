// [2021y-03m-11d][01:46:56] Idrisov Denis R. 3
// [2021y-03m-20d][02:38:01] Idrisov Denis R. 4
// [2021y-03m-23d][23:55:08] Idrisov Denis R. 5
// [2021y-03m-24d][21:32:12] Idrisov Denis R. 6
// [2021y-03m-26d][08:26:36] Idrisov Denis R. 7
// [2021y-03m-30d][01:14:57] Idrisov Denis R. 8
// [2021y-04m-02d][00:40:44] Idrisov Denis R. 9
#pragma once
#ifndef dTOOLS_TRAITS_USED_ 
#define dTOOLS_TRAITS_USED_ 9

#include <tools/features.hpp>

#define dDETAIL_CONSTANT(...) \
    public dTRAIT::integral_constant<bool, detail::__VA_ARGS__::value>

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
//=== remove_cv ================================================================
#ifndef dTOOLS_REMOVE_CV_USED_ 
#define dTOOLS_REMOVE_CV_USED_ 1
namespace tools
{
    template<class t> struct remove_cv                     
        { typedef t type; };

    template<class t> struct remove_cv <const t>           
        { typedef t type; };

    template<class t> struct remove_cv <volatile t>        
        { typedef t type; };

    template<class t> struct remove_cv <volatile  const t> 
        { typedef t type; };

} // namespace tools 
#endif // !dTOOLS_REMOVE_CV_USED_


//==============================================================================
//=== remove_reference =========================================================
#ifndef dTOOLS_REMOVE_REFERENCE_USED_ 
#define dTOOLS_REMOVE_REFERENCE_USED_ 2
namespace tools
{
    template<class t> struct remove_reference
        { typedef t type; };

    template<class t> struct remove_reference <t&>           
        { typedef t type; };

    template<class t, size_t n> struct remove_reference <t(&)[n]>           
        { typedef t type[n]; };

    #ifdef dHAS_RVALUE_REFERENCES
    template<class t> struct remove_reference <t&&>        
        { typedef t type; };

    template<class t, size_t n> struct remove_reference <t(&&)[n]>           
        { typedef t type[n]; };
    #endif

} // namespace tools 
#endif // !dTOOLS_REMOVE_REFERENCE_USED_


//==============================================================================
//=== remove_pointer ===========================================================
#ifndef dTOOLS_REMOVE_POINTER_USED_ 
#define dTOOLS_REMOVE_POINTER_USED_ 2
namespace tools
{
    template <class t> struct remove_pointer 
        { typedef t type; };

    template <class t> struct remove_pointer<t*> 
        { typedef t type; };

    template <class t> struct remove_pointer<t* const> 
        { typedef t type; };

    template <class t> struct remove_pointer<t* volatile>
        { typedef t type; };

    template <class t> struct remove_pointer<t* const volatile> 
        { typedef t type; };

//--------------
    template <class r> struct remove_pointer<r(*)()>
        { typedef r type(); };
    template <class r, dCLASS_A1> struct remove_pointer<r(*)(dARGS_A1)>
        { typedef r type(dARGS_A1); };
    template <class r, dCLASS_A2> struct remove_pointer<r(*)(dARGS_A2)>
        { typedef r type(dARGS_A2); };
    template <class r, dCLASS_A3> struct remove_pointer<r(*)(dARGS_A3)>
        { typedef r type(dARGS_A3); };
    template <class r, dCLASS_A4> struct remove_pointer<r(*)(dARGS_A4)>
        { typedef r type(dARGS_A4); };
    template <class r, dCLASS_A5> struct remove_pointer<r(*)(dARGS_A5)>
        { typedef r type(dARGS_A5); };
    template <class r, dCLASS_A6> struct remove_pointer<r(*)(dARGS_A6)>
        { typedef r type(dARGS_A6); };
    template <class r, dCLASS_A7> struct remove_pointer<r(*)(dARGS_A7)>
        { typedef r type(dARGS_A7); };

//--------------
    template <class r> struct remove_pointer<r(*const)()>
        { typedef r type(); };
    template <class r, dCLASS_A1> struct remove_pointer<r(*const)(dARGS_A1)>
        { typedef r type(dARGS_A1); };
    template <class r, dCLASS_A2> struct remove_pointer<r(*const)(dARGS_A2)>
        { typedef r type(dARGS_A2); };
    template <class r, dCLASS_A3> struct remove_pointer<r(*const)(dARGS_A3)>
        { typedef r type(dARGS_A3); };
    template <class r, dCLASS_A4> struct remove_pointer<r(*const)(dARGS_A4)>
        { typedef r type(dARGS_A4); };
    template <class r, dCLASS_A5> struct remove_pointer<r(*const)(dARGS_A5)>
        { typedef r type(dARGS_A5); };
    template <class r, dCLASS_A6> struct remove_pointer<r(*const)(dARGS_A6)>
        { typedef r type(dARGS_A6); };
    template <class r, dCLASS_A7> struct remove_pointer<r(*const)(dARGS_A7)>
        { typedef r type(dARGS_A7); };

//--------------
    template <class r> struct remove_pointer<r(*volatile)()>
        { typedef r type(); };
    template <class r, dCLASS_A1> struct remove_pointer<r(*volatile)(dARGS_A1)>
        { typedef r type(dARGS_A1); };
    template <class r, dCLASS_A2> struct remove_pointer<r(*volatile)(dARGS_A2)>
        { typedef r type(dARGS_A2); };
    template <class r, dCLASS_A3> struct remove_pointer<r(*volatile)(dARGS_A3)>
        { typedef r type(dARGS_A3); };
    template <class r, dCLASS_A4> struct remove_pointer<r(*volatile)(dARGS_A4)>
        { typedef r type(dARGS_A4); };
    template <class r, dCLASS_A5> struct remove_pointer<r(*volatile)(dARGS_A5)>
        { typedef r type(dARGS_A5); };
    template <class r, dCLASS_A6> struct remove_pointer<r(*volatile)(dARGS_A6)>
        { typedef r type(dARGS_A6); };
    template <class r, dCLASS_A7> struct remove_pointer<r(*volatile)(dARGS_A7)>
        { typedef r type(dARGS_A7); };

//--------------
    template <class r> struct remove_pointer<r(*volatile const)()>
        { typedef r type(); };
    template <class r, dCLASS_A1> struct remove_pointer<r(*volatile const)(dARGS_A1)>
        { typedef r type(dARGS_A1); };
    template <class r, dCLASS_A2> struct remove_pointer<r(*volatile const)(dARGS_A2)>
        { typedef r type(dARGS_A2); };
    template <class r, dCLASS_A3> struct remove_pointer<r(*volatile const)(dARGS_A3)>
        { typedef r type(dARGS_A3); };
    template <class r, dCLASS_A4> struct remove_pointer<r(*volatile const)(dARGS_A4)>
        { typedef r type(dARGS_A4); };
    template <class r, dCLASS_A5> struct remove_pointer<r(*volatile const)(dARGS_A5)>
        { typedef r type(dARGS_A5); };
    template <class r, dCLASS_A6> struct remove_pointer<r(*volatile const)(dARGS_A6)>
        { typedef r type(dARGS_A6); };
    template <class r, dCLASS_A7> struct remove_pointer<r(*volatile const)(dARGS_A7)>
        { typedef r type(dARGS_A7); };

//--------------
//--------------
    template <class r> struct remove_pointer<r(*)(...)>
        { typedef r type(); };
    template <class r, dCLASS_A1> struct remove_pointer<r(*)(dARGS_A1, ...)>
        { typedef r type(dARGS_A1); };
    template <class r, dCLASS_A2> struct remove_pointer<r(*)(dARGS_A2, ...)>
        { typedef r type(dARGS_A2); };
    template <class r, dCLASS_A3> struct remove_pointer<r(*)(dARGS_A3, ...)>
        { typedef r type(dARGS_A3); };
    template <class r, dCLASS_A4> struct remove_pointer<r(*)(dARGS_A4, ...)>
        { typedef r type(dARGS_A4); };
    template <class r, dCLASS_A5> struct remove_pointer<r(*)(dARGS_A5, ...)>
        { typedef r type(dARGS_A5); };
    template <class r, dCLASS_A6> struct remove_pointer<r(*)(dARGS_A6, ...)>
        { typedef r type(dARGS_A6); };
    template <class r, dCLASS_A7> struct remove_pointer<r(*)(dARGS_A7, ...)>
        { typedef r type(dARGS_A7); };

//--------------
    template <class r> struct remove_pointer<r(*const)(...)>
        { typedef r type(...); };
    template <class r, dCLASS_A1> struct remove_pointer<r(*const)(dARGS_A1, ...)>
        { typedef r type(dARGS_A1, ...); };
    template <class r, dCLASS_A2> struct remove_pointer<r(*const)(dARGS_A2, ...)>
        { typedef r type(dARGS_A2, ...); };
    template <class r, dCLASS_A3> struct remove_pointer<r(*const)(dARGS_A3, ...)>
        { typedef r type(dARGS_A3, ...); };
    template <class r, dCLASS_A4> struct remove_pointer<r(*const)(dARGS_A4, ...)>
        { typedef r type(dARGS_A4, ...); };
    template <class r, dCLASS_A5> struct remove_pointer<r(*const)(dARGS_A5, ...)>
        { typedef r type(dARGS_A5, ...); };
    template <class r, dCLASS_A6> struct remove_pointer<r(*const)(dARGS_A6, ...)>
        { typedef r type(dARGS_A6, ...); };
    template <class r, dCLASS_A7> struct remove_pointer<r(*const)(dARGS_A7, ...)>
        { typedef r type(dARGS_A7, ...); };

//--------------
    template <class r> struct remove_pointer<r(*volatile)(...)>
        { typedef r type(...); };
    template <class r, dCLASS_A1> struct remove_pointer<r(*volatile)(dARGS_A1, ...)>
        { typedef r type(dARGS_A1, ...); };
    template <class r, dCLASS_A2> struct remove_pointer<r(*volatile)(dARGS_A2, ...)>
        { typedef r type(dARGS_A2, ...); };
    template <class r, dCLASS_A3> struct remove_pointer<r(*volatile)(dARGS_A3, ...)>
        { typedef r type(dARGS_A3, ...); };
    template <class r, dCLASS_A4> struct remove_pointer<r(*volatile)(dARGS_A4, ...)>
        { typedef r type(dARGS_A4, ...); };
    template <class r, dCLASS_A5> struct remove_pointer<r(*volatile)(dARGS_A5, ...)>
        { typedef r type(dARGS_A5, ...); };
    template <class r, dCLASS_A6> struct remove_pointer<r(*volatile)(dARGS_A6, ...)>
        { typedef r type(dARGS_A6, ...); };
    template <class r, dCLASS_A7> struct remove_pointer<r(*volatile)(dARGS_A7, ...)>
        { typedef r type(dARGS_A7, ...); };

//--------------
    template <class r> struct remove_pointer<r(*volatile const)(...)>
        { typedef r type(...); };
    template <class r, dCLASS_A1> struct remove_pointer<r(*volatile const)(dARGS_A1, ...)>
        { typedef r type(dARGS_A1, ...); };
    template <class r, dCLASS_A2> struct remove_pointer<r(*volatile const)(dARGS_A2, ...)>
        { typedef r type(dARGS_A2, ...); };
    template <class r, dCLASS_A3> struct remove_pointer<r(*volatile const)(dARGS_A3, ...)>
        { typedef r type(dARGS_A3, ...); };
    template <class r, dCLASS_A4> struct remove_pointer<r(*volatile const)(dARGS_A4, ...)>
        { typedef r type(dARGS_A4, ...); };
    template <class r, dCLASS_A5> struct remove_pointer<r(*volatile const)(dARGS_A5, ...)>
        { typedef r type(dARGS_A5, ...); };
    template <class r, dCLASS_A6> struct remove_pointer<r(*volatile const)(dARGS_A6, ...)>
        { typedef r type(dARGS_A6, ...); };
    template <class r, dCLASS_A7> struct remove_pointer<r(*volatile const)(dARGS_A7, ...)>
        { typedef r type(dARGS_A7, ...); };

} // namespace tools 
#endif // !dTOOLS_REMOVE_POINTER_USED_


//==============================================================================
//=== remove_extent ============================================================
#ifndef dTOOLS_REMOVE_EXTENT_USED_ 
#define dTOOLS_REMOVE_EXTENT_USED_ 1
namespace tools
{
    template <class t> struct remove_extent 
        { typedef t type; };

    template <class t, size_t n> struct remove_extent<t[n]>
        { typedef t type; };

    template <class t> struct remove_extent<t[]>
        { typedef t type; };

} // namespace tools 
#endif // !dTOOLS_REMOVE_EXTENT_USED_

//==============================================================================
//=== remove_all_extent ========================================================
#ifndef dTOOLS_REMOVE_ALL_EXTENT_USED_ 
#define dTOOLS_REMOVE_ALL_EXTENT_USED_ 1
namespace tools
{
    template <class t> struct remove_all_extent 
        { typedef t type; };

    template <class t, size_t n> struct remove_all_extent<t[n]>
    {
        typedef typename remove_all_extent<t>::type
            type;
    };

    template <class t> struct remove_all_extent<t[]>
    {
        typedef typename remove_all_extent<t>::type
            type;
    };

} // namespace tools 
#endif // !dTOOLS_REMOVE_ALL_EXTENT_USED_


//==============================================================================
//=== add_pointer ==============================================================
#ifndef dTOOLS_ADD_POINTER_USED_ 
#define dTOOLS_ADD_POINTER_USED_ 1
namespace tools
{
    template <class t> struct add_pointer 
    {
        typedef remove_reference<t> 
            no_ref;
        typedef typename no_ref::type
            x;

        typedef x* type; 
    };

} // namespace tools 
#endif // !dTOOLS_ADD_POINTER_USED_


//==============================================================================
//=== integral_constant ========================================================
#ifndef dTOOLS_INTEGRAL_CONSTANT_USED_ 
#define dTOOLS_INTEGRAL_CONSTANT_USED_ 1
namespace tools
{
    template <class t, t val>
    struct integral_constant 
    {
        enum { value = val };

        typedef t value_type;

        typedef integral_constant 
            type;

        dCONSTEXPR_CPP11 operator value_type() const dNOEXCEPT
            { return value; }

        dNODISCARD dCONSTEXPR_CPP11
        value_type operator()() const dNOEXCEPT
            { return value; }
    };

    typedef integral_constant<bool, true> 
        true_type;

    typedef integral_constant<bool, false>
        false_type;

} // namespace tools 
#endif // !dTOOLS_INTEGRAL_CONSTANT_USED_


//==============================================================================
//=== is_same ==================================================================
#ifndef dTOOLS_IS_SAME_USED_ 
#define dTOOLS_IS_SAME_USED_ 1
namespace tools
{
    template<class a, class b> struct is_same
        { enum { value = 0 }; };

    template<class t> struct is_same<t, t>
        { enum { value = 1 }; };

} // namespace tools 
#endif // !dTOOLS_IS_SAME_USED_


//==============================================================================
//=== is_pointer ===============================================================
#ifndef dTOOLS_IS_POINTER_USED_ 
#define dTOOLS_IS_POINTER_USED_ 1
namespace tools
{
    template <class t> struct is_pointer 
    {
        enum { value = false };
    };

    template <class t> struct is_pointer <t*>
    {
        enum { value = true };
    };

    template <class t> struct is_pointer <t* const>
    {
        enum { value = true };
    };

    template <class t> struct is_pointer <t* volatile>
    {
        enum { value = true };
    };

    template <class t> struct is_pointer <t* volatile const>
    {
        enum { value = true };
    };

} // namespace tools 
#endif // !dTOOLS_IS_POINTER_USED_


//==============================================================================
//=== is_reference =============================================================
#ifndef dTOOLS_IS_REFERENCE_USED_ 
#define dTOOLS_IS_REFERENCE_USED_ 1
namespace tools
{
    template <class t> struct is_reference
    {
        enum { value = false };
    };

    template <class t> struct is_reference <t&>
    {
        enum { value = true };
    };

    #ifdef dHAS_RVALUE_REFERENCES
    template <class t> struct is_reference <t&&>
    {
        enum { value = true };
    };
    #endif

} // namespace tools 
#endif // !dTOOLS_IS_REFERENCE_USED_


//==============================================================================
//=== is_class =================================================================
#ifndef dTOOLS_IS_CLASS_USED_ 
#define dTOOLS_IS_CLASS_USED_ 1
namespace tools
{
    template <class t> struct is_class 
    {
        typedef char (&no )[1]; 
        typedef char (&yes)[2];

        template <typename cl> static yes 
            check (int cl::* p);

        template <class> static no 
            check (...);

        enum { result = sizeof(check<t>(0))  };
        enum { value = result == sizeof(yes) };
    };

} // namespace tools 
#endif // !dTOOLS_IS_CLASS_USED_


//==============================================================================
//=== is_const =================================================================
#ifndef dTOOLS_IS_CONST_USED_ 
#define dTOOLS_IS_CONST_USED_ 1
namespace tools
{
    template <class t> struct is_const
    {
        enum { value = false };
    };

    template <class t> struct is_const<const t>
    {
        enum { value = true };
    };

    template <class t, size_t n> struct is_const<const t[n]>
    {
        enum { value = true };
    };

} // namespace tools 
#endif // !dTOOLS_IS_CONST_USED_


//==============================================================================
//=== is_volatile ==============================================================
#ifndef dTOOLS_IS_VOLATILE_USED_ 
#define dTOOLS_IS_VOLATILE_USED_ 1
namespace tools
{
    template <class t> struct is_volatile
    {
        enum { value = false };
    };

    template <class t> struct is_volatile<volatile t>
    {
        enum { value = true };
    };

    template <class t, size_t n> struct is_volatile<volatile t[n]>
    {
        enum { value = true };
    };

} // namespace tools 
#endif // !dTOOLS_IS_VOLATILE_USED_


//==============================================================================
//=== is_signed ================================================================
#ifndef dTOOLS_IS_SIGNED_USED_ 
#define dTOOLS_IS_SIGNED_USED_ 1
namespace tools
{
    template <class t> struct is_signed
    {
        typedef typename remove_cv<t>::type x;
        enum { value = static_cast<x>(-1) < static_cast<x>(0) };
    };

    template <class t> struct is_unsigned
    {
        enum { value = !is_signed<t>::value };
    };

} // namespace tools 
#endif // !dTOOLS_IS_SIGNED_USED_


//==============================================================================
//=== is_floating ==============================================================
#ifndef dTOOLS_IS_FLOATING_USED_ 
#define dTOOLS_IS_FLOATING_USED_ 1
namespace tools
{
    template <class t> struct is_floating_
        { enum { value = 0 }; };

    template <> struct is_floating_<float>
        { enum { value = 1 }; };

    template <> struct is_floating_<double>
        { enum { value = 1 }; };

    template <> struct is_floating_<long double>
        { enum { value = 1 }; };

    template <class t> struct is_floating_point
        : is_floating_<typename remove_cv<t>::type>
    {};

} // namespace tools 
#endif // !dTOOLS_IS_FLOATING_USED_


//==============================================================================
//=== is_integral ==============================================================
#ifndef dTOOLS_IS_INTEGRAL_USED_ 
#define dTOOLS_IS_INTEGRAL_USED_ 1
namespace tools
{
    template <class t> struct is_integral_
        { enum { value = 0 }; };

    #if !defined(_MSC_VER) || _MSC_VER >= 1900
    template <> struct is_integral_<char16_t>
        { enum { value = 1 }; };

    template <> struct is_integral_<char32_t>
        { enum { value = 1 }; };
    #endif

    template <> struct is_integral_<short>
        { enum { value = 1 }; };

    template <> struct is_integral_<unsigned short>
        { enum { value = 1 }; };

    template <> struct is_integral_<int>
        { enum { value = 1 }; };

    template <> struct is_integral_<unsigned int>
        { enum { value = 1 }; };

    template <> struct is_integral_<long>
        { enum { value = 1 }; };

    template <> struct is_integral_<unsigned long>
        { enum { value = 1 }; };

    template <> struct is_integral_<long long>
        { enum { value = 1 }; };

    template <> struct is_integral_<unsigned long long>
        { enum { value = 1 }; };

    template <class t> struct is_integral
        : is_integral_<typename remove_cv<t>::type>
    {};

} // namespace tools 
#endif // !dTOOLS_IS_INTEGRAL_USED_


//==============================================================================
//=== is_array =================================================================
#ifndef dTOOLS_IS_ARRAY_USED_ 
#define dTOOLS_IS_ARRAY_USED_ 2
namespace tools
{
    template <class t> struct is_array
    {
        enum { value = false };
    };

    template <class t, size_t n> struct is_array<t[n]>
    {
        enum { value = true };
    };

    #ifdef dHAS_ARRAY_EMPTY_SIZE

    template <class t> struct is_array<t[]>
    {
        enum { value = true };
    };

    #endif

} // namespace tools 
#endif // !dTOOLS_IS_ARRAY_USED_


//==============================================================================
//=== is_function ==============================================================
#ifndef dTOOLS_IS_FUNCTION_USED_ 
#define dTOOLS_IS_FUNCTION_USED_ 1
namespace tools
{
    #ifdef _MSC_VER
        #pragma warning(push)
        // warning C4180: qualifier applied to function type has no meaning; ignored
        #pragma warning(disable : 4180)

        // warning C4181: qualifier applied to reference type; ignored
        #pragma warning(disable : 4181)
    #endif

    // only function types and reference types can't be const qualified
    template <class t> struct is_function
    {
        enum { v1 = is_const<const t>::value };
        enum { v2 = is_reference<t>::value   };
        enum { value = !v1 && !v2 };
    };

    #ifdef _MSC_VER
        #pragma warning(pop)
    #endif

} // namespace tools 
#endif // !dTOOLS_IS_FUNCTION_USED_


//==============================================================================
//=== conditional ==============================================================
#ifndef dTOOLS_CONDITIONAL_USED_ 
#define dTOOLS_CONDITIONAL_USED_ 1
namespace tools
{
    template <bool, class a, class b>
    struct conditional
        { typedef a type; };

    template <class a, class b> 
    struct conditional<false, a, b>
        { typedef b type; };

} // namespace tools 
#endif // !dTOOLS_SELECT_USED_


//==============================================================================
//=== decay ====================================================================
#ifndef dTOOLS_DECAY_USED_ 
#define dTOOLS_DECAY_USED_ 2
namespace tools
{
    template <class t> class decay 
    { 
        typedef ::tools::remove_reference<t>
            no_ref;
        typedef typename no_ref::type
            x;
        enum { foo = ::tools::is_function<x>::value };
        enum { arr = ::tools::is_array<x>::value    };

        typedef typename ::tools::add_pointer<x>::type
            ptr1;
        typedef typename ::tools::remove_cv<x>::type
            n_cv;
        typedef ::tools::conditional<foo, ptr1, n_cv>
            select1;
        typedef typename select1::type
            one;

        typedef typename ::tools::remove_extent<x>::type
            no_ext;
        typedef typename ::tools::add_pointer<no_ext>::type
            ptr2;

        typedef ::tools::conditional<arr, ptr2, one>
            select2;
    public:
        typedef typename select2::type
            type;
    };

} // namespace tools 
#endif // !dTOOLS_DECAY_USED_


//==============================================================================
//=== enable_if ================================================================
#ifndef dTOOLS_ENABLE_IF_USED_ 
#define dTOOLS_ENABLE_IF_USED_ 1
namespace tools
{
    template <bool, class t = void> 
        struct enable_if;

    template <class t> struct enable_if<true, t>
        { typedef t type; };

} // namespace tools 
#endif // !dTOOLS_SELECT_USED_


//==============================================================================
//=== is_base_of ===============================================================
#ifndef dTOOLS_IS_BASE_OF_USED_ 
#define dTOOLS_IS_BASE_OF_USED_ 1
namespace tools
{
    namespace detail
    {
        typedef char no[1];
        typedef char yes[2];

        template <class b, class d>
        struct is_base_of
        {
            template <class u> static
                yes& check(u*);

            template <typename> static
                no& check(...);

            enum { result = sizeof(check<b>(static_cast<d*>(0))) };
            enum { value = result != sizeof(no)  };
        };

    } // namespace detail

    template <class b, class d>
    struct is_base_of
        : dDETAIL_CONSTANT(is_base_of<b, d>)
    {};

} // namespace tools 

#endif // !dTOOLS_IS_BASE_OF_USED_


//================================================================================
//=== type_of_enum ===============================================================
#ifdef dHAS_ENUM_CLASS
#ifndef dTOOLS_ENUM_TYPE_USED_ 
#define dTOOLS_ENUM_TYPE_USED_ 1
namespace tools
{
    template<class t, bool = ::std::is_enum<t>::value>
    struct type_of_enum
    {
        typedef typename ::std::underlying_type<t>::type
            type;
    };

    template<class t> 
    struct type_of_enum<t, false>
        { typedef t type; };

    #ifdef dHAS_USING_ALIAS
    template<class t> 
    using type_of_enum_t
        = typename ::tools::type_of_enum<t>::type;
    #endif

} // tools
#endif // !dTOOLS_ENUM_TYPE_USED_
#endif // !dHAS_ENUM_CLASS


//==============================================================================
//==============================================================================
#endif // !dTOOLS_TRAITS_USED_
