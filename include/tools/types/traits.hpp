// [2021y-03m-11d][01:46:56] Idrisov Denis R. 3
// [2021y-03m-20d][02:38:01] Idrisov Denis R. 4
// [2021y-03m-23d][22:29:28] Idrisov Denis R. 5 PRE
#pragma once
#ifndef dTOOLS_TRAITS_USED_ 
#define dTOOLS_TRAITS_USED_ 5 PRE

#include <tools/features.hpp>

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
//=== decay ====================================================================
#ifndef dTOOLS_DECAY_USED_ 
#define dTOOLS_DECAY_USED_ 1
namespace tools
{
    template<class t> struct decay
    {
        typedef t type;
    };
    template<class t, size_t n> struct decay<t[n]>
    {
        typedef t* type;
    };
    template<class t, size_t n> struct decay<t(&)[n]>
    {
        typedef t* type;
    };
    #ifdef dHAS_RVALUE_REFERENCES
    template<class t, size_t n> struct decay<t(&&)[n]>
    {
        typedef t* type;
    };
    #endif

} // namespace tools 
#endif // !dTOOLS_DECAY_USED_


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
#define dTOOLS_REMOVE_POINTER_USED_ 1
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

} // namespace tools 
#endif // !dTOOLS_REMOVE_POINTER_USED_


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
