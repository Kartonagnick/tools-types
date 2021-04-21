// [2021y-03m-11d][01:46:56] Idrisov Denis R. 3
// [2021y-03m-20d][02:38:01] Idrisov Denis R. 4
// [2021y-03m-23d][23:55:08] Idrisov Denis R. 5
// [2021y-03m-24d][21:32:12] Idrisov Denis R. 6
// [2021y-03m-26d][08:26:36] Idrisov Denis R. 7
// [2021y-03m-30d][01:14:57] Idrisov Denis R. 8
// [2021y-04m-02d][00:40:44] Idrisov Denis R. 9
// [2021y-04m-03d][00:13:00] Idrisov Denis R. 10
// [2021y-04m-03d][23:11:10] Idrisov Denis R. 11
// [2021y-04m-04d][01:36:02] Idrisov Denis R. 12

// [2021y-04m-21d][00:41:22] Idrisov Denis R. 13 PRE
#pragma once
#ifndef dTOOLS_TRAITS_USED_ 
#define dTOOLS_TRAITS_USED_ 13 PRE

#include <tools/features.hpp>

#define dDETAIL_TRAITS(...)                  \
    public ::tools::integral_constant<bool,  \
        ::tools::detail::__VA_ARGS__::value  \
    >

//==============================================================================
//=== integral_constant ========================================= (features) ===
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

        dCONSTEXPR_CPP11
        operator value_type() const dNOEXCEPT
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
//=== remove_reference ======================= (features)(integral_constant) ===
#ifndef dTOOLS_REMOVE_REFERENCE_USED_ 
#define dTOOLS_REMOVE_REFERENCE_USED_ 2
namespace tools
{
    template<class t> struct remove_reference
        { typedef t type; };

    template<class t> struct remove_reference <t&>           
        { typedef t type; };

    #ifdef dHAS_RVALUE_REFERENCES
    template<class t> struct remove_reference <t&&>        
        { typedef t type; };
    #endif

} // namespace tools 
#endif // !dTOOLS_REMOVE_REFERENCE_USED_


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
//=== remove_cv ================================================================
#ifndef dTOOLS_REMOVE_CV_USED_ 
#define dTOOLS_REMOVE_CV_USED_ 2
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

    #if (defined(_MSC_VER) && _MSC_VER <= 1800)
    // msvc2008 - msvc20013
    template<class t, size_t n> struct remove_cv<t[n]>
    {
        typedef typename ::tools::remove_cv<t>::type
            no_cv;
        typedef no_cv type[n];
    };

    template<class t> struct remove_cv<t[]>
    {
        typedef typename ::tools::remove_cv<t>::type
            no_cv;
        typedef no_cv type[];
    };
    #endif

} // namespace tools 
#endif // !dTOOLS_REMOVE_CV_USED_


//==============================================================================
//=== is_same ========================================== (integral_constant) ===
#ifndef dTOOLS_IS_SAME_USED_ 
#define dTOOLS_IS_SAME_USED_ 2
namespace tools
{
    namespace detail
    {
        template<class a, class b> struct is_same_
            { enum { value = 0 }; };

        template<class t> struct is_same_<t, t>
            { enum { value = 1 }; };

    } // namespace detail

    template <class a, class b> struct is_same
        : dDETAIL_TRAITS(is_same_<a, b>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_SAME_USED_


//==============================================================================
//=== is_lvalue_reference ============================== (integral_constant) ===
#ifndef dTOOLS_IS_LVALUE_REFERENCE_USED_ 
#define dTOOLS_IS_LVALUE_REFERENCE_USED_ 1
namespace tools
{
    namespace detail
    {
        template <class t> struct is_lvalue_reference_
            { enum { value = false }; };

        template <class t> struct is_lvalue_reference_<t&>
            { enum { value = true }; };

    } // namespace detail

    template <class t> struct is_lvalue_reference
        : dDETAIL_TRAITS(is_lvalue_reference_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_LVALUE_REFERENCE_USED_


//==============================================================================
//=== is_rvalue_reference ============================== (integral_constant) ===
#ifndef dTOOLS_IS_RVALUE_REFERENCE_USED_ 
#define dTOOLS_IS_RVALUE_REFERENCE_USED_ 2
namespace tools
{
    namespace detail
    {
        template <class t> struct is_rvalue_reference_
            { enum { value = false }; };

        #ifdef dHAS_RVALUE_REFERENCES
        template <class t> struct is_rvalue_reference_<t&&>
            { enum { value = true }; };
        #endif

    } // namespace detail

    template <class t> struct is_rvalue_reference
        : dDETAIL_TRAITS(is_rvalue_reference_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_RVALUE_REFERENCE_USED_


//==============================================================================
//=== is_reference =================================== (is_lvalue_reference) ===
//=== is_reference =================================== (is_rvalue_reference) ===
//=== is_reference ===================================== (integral_constant) ===
#ifndef dTOOLS_IS_REFERENCE_USED_ 
#define dTOOLS_IS_REFERENCE_USED_ 2
namespace tools
{
    namespace detail
    {
        #if defined(_MSC_VER) && _MSC_VER == 1600
            // msvc2010
            template <class t> class is_reference_
            { 
                typedef ::tools::detail::is_lvalue_reference_<t>
                    lval_t;
                typedef ::tools::detail::is_rvalue_reference_<t>
                    rval_t;

                enum { lval = lval_t::value }; 
                enum { rval = rval_t::value }; 
            public:
                is_reference_();
                enum { value = lval || rval }; 
            };
        #else
            // if not msvc2010
            template <class t> struct is_reference_
                { enum { value = false }; };

            template <class t> struct is_reference_ <t&>
                { enum { value = true }; };

            #ifdef dHAS_RVALUE_REFERENCES
            template <class t> struct is_reference_ <t&&>
                { enum { value = true }; };
            #endif

        #endif

    } // namespace detail

    template <class t> struct is_reference
        : dDETAIL_TRAITS(is_reference_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_REFERENCE_USED_


//==============================================================================
//=== is_pointer ============================ (remove_cv)(integral_constant) ===
#ifndef dTOOLS_IS_POINTER_USED_ 
#define dTOOLS_IS_POINTER_USED_ 2
namespace tools
{
    namespace detail
    {
        template <class t> struct is_pointer_impl_
            { enum { value = false }; };

        template <class t> struct is_pointer_impl_ <t*>
            { enum { value = true }; };

        template <class t> struct is_pointer_impl_ <t* const>
            { enum { value = true }; };

        template <class t> struct is_pointer_impl_ <t* volatile>
            { enum { value = true }; };

        template <class t> struct is_pointer_impl_ <t* volatile const>
            { enum { value = true }; };

        #if (defined(_MSC_VER) && _MSC_VER <= 1800)
            // old: msvc2013 or older
            template <class t> struct is_pointer_
            {
                typedef typename ::tools::remove_cv<t>::type 
                    x;
                typedef ::tools::detail::is_pointer_impl_<x> 
                    v;
                enum { value = v::value };
            };
        #else
            // new: msvc2015 or newest
            template <class t> struct is_pointer_
                : ::tools::detail::is_pointer_impl_<t>
            {};
        #endif

    } // namespace detail

    template <class t> struct is_pointer
        : dDETAIL_TRAITS(is_pointer_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_POINTER_USED_


//==============================================================================
//=== remove_pointer ========================================== (is_pointer) ===
#ifndef dTOOLS_REMOVE_POINTER_USED_ 
#define dTOOLS_REMOVE_POINTER_USED_ 2
namespace tools
{
    namespace detail
    {
        template <class t> struct remove_pointer_impl_ 
            { typedef t type; };

        template <class t> struct remove_pointer_impl_<t*> 
            { typedef t type; };

        template <class t> struct remove_pointer_impl_<t* const> 
            { typedef t type; };

        template <class t> struct remove_pointer_impl_<t* volatile>
            { typedef t type; };

        template <class t> struct remove_pointer_impl_<t* const volatile> 
            { typedef t type; };


        #if (defined(_MSC_VER) && _MSC_VER <= 1800)
            // old: msvc2013 or older
            template <class t, bool> struct remove_ptr_
            {
                typedef typename ::tools::remove_cv<t>::type 
                    x;
                typedef ::tools::detail::remove_pointer_impl_<x>
                    result;
                typedef typename result::type type;
            };

            template <class t> struct remove_ptr_<t, false>
                { typedef t type; };

            template <class t> class remove_pointer_
            {
                typedef ::tools::is_pointer<t> v;
                typedef remove_ptr_<t, v ::value> x;
            public:
                typedef typename x::type type;
            };
        #else
            // new: msvc2015 or newest
            template <class t> struct remove_pointer_
                : remove_pointer_impl_<t>
            {};
        #endif

    } // namespace detail

    template <class t> struct remove_pointer
        : ::tools::detail::remove_pointer_<t>
    {};

} // namespace tools 
#endif // !dTOOLS_REMOVE_POINTER_USED_


//================================================================= (sfinae) ===
//=== add_pointer ======================================= (remove_reference) ===
#ifndef dTOOLS_ADD_POINTER_USED_ 
#define dTOOLS_ADD_POINTER_USED_ 2
namespace tools
{
    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];

        template <class t> struct can_add_pointer_
        {
            template <class u> static 
                yes check(u* p);

            template <class> static
                no check(...);

            enum { result = sizeof(check<t>(0)) };
            enum { value = result == sizeof(yes) };
        };

        template <class t, bool> struct add_pointer_impl_ 
        {
            typedef ::tools::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type
                x;
            typedef x* type; 
        };

        template <class t> struct add_pointer_impl_ <t, false>
            { typedef t type; };

        template <class t> class add_pointer_
        {
            typedef ::tools::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type
                x;
            typedef ::tools::detail::can_add_pointer_<x>
                can;
            typedef ::tools::detail::add_pointer_impl_<t, can::value> 
                result;
        public:
            typedef typename result::type 
                type;
        };

    } // namespace detail

    template <class t> struct add_pointer
        : ::tools::detail::add_pointer_<t>
    {};

} // namespace tools 
#endif // !dTOOLS_ADD_POINTER_USED_


//================================================================= (sfinae) ===
//=== is_class ========================================= (integral_constant) ===
#ifndef dTOOLS_IS_CLASS_USED_ 
#define dTOOLS_IS_CLASS_USED_ 2
namespace tools
{
    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];

        template <class t> struct is_class_
        {
            template <typename cl> static 
                yes check(int cl::* p);

            template <class> static 
                no check(...);

            enum { result = sizeof(check<t>(0)) };
            enum { value = result == sizeof(yes) };
        };

    } // namespace detail

    template <class t> struct is_class
        : dDETAIL_TRAITS(is_class_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_CLASS_USED_


//==============================================================================
//=== is_const ========================================= (remove_all_extent) ===
#ifndef dTOOLS_IS_CONST_USED_ 
#define dTOOLS_IS_CONST_USED_ 2
namespace tools
{
    namespace detail
    {
        template <class t> struct is_const_impl_
            { enum { value = false }; };

        template <class t> struct is_const_impl_<const t>
            { enum { value = true }; };


        #if defined(_MSC_VER) && _MSC_VER <= 1800
            // old: msvc2013 or older
            template <class t> struct is_const_
            {
                typedef ::tools::remove_all_extent<t> 
                    no_ext;
                typedef typename no_ext::type x;
                typedef ::tools::detail::is_const_impl_<x> 
                    v;
                enum { value = v::value };
            };
        #else
            // new: msvc2015 or newest
            template <class t> struct is_const_
                : ::tools::detail::is_const_impl_<t>
            {};
        #endif

    } // namespace detail

    template <class t> struct is_const
        : dDETAIL_TRAITS(is_const_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_CONST_USED_


//==============================================================================
//=== is_volatile ===================================== (remove_all_extent) ===
#ifndef dTOOLS_IS_VOLATILE_USED_ 
#define dTOOLS_IS_VOLATILE_USED_ 2
namespace tools
{
    namespace detail
    {
        template <class t> struct is_volatile_impl_
            { enum { value = false }; };

        template <class t> struct is_volatile_impl_<volatile t>
            { enum { value = true }; };


        #if defined(_MSC_VER) && _MSC_VER <= 1800
            // old: msvc2013 or older
            template <class t> struct is_volatile_
            {
                typedef ::tools::remove_all_extent<t> 
                    no_ext;
                typedef typename no_ext::type x;
                typedef ::tools::detail::is_volatile_impl_<x>
                    v;
                enum { value = v::value };
            };
        #else
            // new: msvc2015 or newest
            template <class t> struct is_volatile_
                : is_volatile_impl_<t>
            {};
        #endif

    } // namespace detail

    template <class t> struct is_volatile
        : dDETAIL_TRAITS(is_volatile_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_VOLATILE_USED_


//==============================================================================
//=== is_floating_point ===================== (remove_cv)(integral_constant) ===
#ifndef dTOOLS_IS_FLOATING_USED_
#define dTOOLS_IS_FLOATING_USED_ 2
namespace tools
{
    namespace detail
    {
        template <class t> struct is_floating_
            { enum { value = 0 }; };

        template <> struct is_floating_<float>
            { enum { value = 1 }; };

        template <> struct is_floating_<double>
            { enum { value = 1 }; };

        template <> struct is_floating_<long double>
            { enum { value = 1 }; };

        template <class t> struct is_floating_point_
            : is_floating_<typename ::tools::remove_cv<t>::type>
        {};

    } // namespace detail

    template <class t> struct is_floating_point
        : dDETAIL_TRAITS(is_floating_point_<t>)
    {};

} // namespace tools
#endif // !dTOOLS_IS_FLOATING_USED_


//==============================================================================
//=== is_integral =========================== (remove_cv)(integral_constant) ===
#ifndef dTOOLS_IS_INTEGRAL_USED_
#define dTOOLS_IS_INTEGRAL_USED_ 2
namespace tools
{
    namespace detail
    {
        template <class t> struct is_integral_impl_
            { enum { value = 0 }; };

        #if !defined(_MSC_VER) || _MSC_VER >= 1900
        template <> struct is_integral_impl_<char16_t>
            { enum { value = 1 }; };

        template <> struct is_integral_impl_<char32_t>
            { enum { value = 1 }; };
        #endif

        #ifdef __cpp_char8_t
        template <> struct is_integral_impl_<char8_t,>
            { enum { value = 1 }; };
        #endif // __cpp_char8_t

        template <> struct is_integral_impl_<wchar_t>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<bool>
            { enum { value = 1 }; };

        template <> struct is_integral_impl_<char>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<signed char>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<unsigned char>
            { enum { value = 1 }; };

        template <> struct is_integral_impl_<short>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<int>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<long>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<long long>
            { enum { value = 1 }; };

        template <> struct is_integral_impl_<unsigned short>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<unsigned int>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<unsigned long>
            { enum { value = 1 }; };
        template <> struct is_integral_impl_<unsigned long long>
            { enum { value = 1 }; };

        template <class t> struct is_integral_
        {
            typedef typename ::tools::remove_cv<t>::type
                x;
            typedef ::tools::detail::is_integral_impl_<x>
                result;
            enum { value = result::value };
        };

    } // namespace detail

    template <class t> struct is_integral
        : dDETAIL_TRAITS(is_integral_<t>)
    {};

} // namespace tools
#endif // !dTOOLS_IS_INTEGRAL_USED_


//==============================================================================
//=== is_signed ============================= (remove_cv)(is_floating_point) ===
//=== is_signed ============================================== (is_integral) ===
#ifndef dTOOLS_IS_SIGNED_USED_ 
#define dTOOLS_IS_SIGNED_USED_ 2
namespace tools
{
    namespace detail
    {
        template <class t, bool> struct is_signed_impl_
        {
            typedef ::tools::remove_cv<t>
                no_cv;
            typedef typename no_cv::type x;
            enum
            {
                value = static_cast<x>(-1) < static_cast<x>(0) 
            };
        };

        template <class t> struct is_signed_impl_<t, false>
        {
            enum { value = ::tools::is_floating_point<t>::value };
        };

        template <class t> struct is_signed_
        {
            enum { ok = ::tools::is_integral<t>::value };
            typedef ::tools::detail::is_signed_impl_<t, ok>
                impl;
            enum { value = impl::value };
        };

        template <class t> struct is_unsigned_
        {
            enum { ok = ::tools::is_integral<t>::value };
            typedef ::tools::detail::is_signed_impl_<t, ok>
                impl;
            enum { value = ok && !impl::value };
        };

    } // namespace detail

    template <class t> struct is_signed
        : dDETAIL_TRAITS(is_signed_<t>)
    {};

    template <class t> struct is_unsigned
        : dDETAIL_TRAITS(is_unsigned_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_SIGNED_USED_


//==============================================================================
//=== is_array ========================================= (integral_constant) ===
#ifndef dTOOLS_IS_ARRAY_USED_ 
#define dTOOLS_IS_ARRAY_USED_ 2
namespace tools
{
    namespace detail 
    {
        template <class t> struct is_array_
            { enum { value = false }; };

        template <class t, size_t n> struct is_array_<t[n]>
            { enum { value = true }; };

        #ifdef dHAS_ARRAY_EMPTY_SIZE
        template <class t> struct is_array_<t[]>
            { enum { value = true }; };
        #endif

    } // namespace detail 

    template <class t> struct is_array
        : dDETAIL_TRAITS(is_array_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_ARRAY_USED_


//==============================================================================
//=== is_function ================================= (is_const)(is_reference) ===
#ifndef dTOOLS_IS_FUNCTION_USED_ 
#define dTOOLS_IS_FUNCTION_USED_ 2
namespace tools
{
    namespace detail 
    {
        #ifdef _MSC_VER
            #pragma warning(push)
            // warning C4180: qualifier applied to function type has no meaning; ignored
            #pragma warning(disable : 4180)

            // warning C4181: qualifier applied to reference type; ignored
            #pragma warning(disable : 4181)
        #endif

        // only function types and reference types can't be const qualified
        template <class t> struct is_function_
        {
            enum { v1 = ::tools::is_const<const t>::value };
            enum { v2 = ::tools::is_reference<t>::value   };
            enum { value = !v1 && !v2 };
        };

        #ifdef _MSC_VER
            #pragma warning(pop)
        #endif

    } // namespace detail 

    template <class t> struct is_function
        : dDETAIL_TRAITS(is_function_<t>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_FUNCTION_USED_


//================================================================= (sfinae) ===
//=== is_base_of ======================================= (integral_constant) ===
#ifndef dTOOLS_IS_BASE_OF_USED_ 
#define dTOOLS_IS_BASE_OF_USED_ 2
namespace tools
{
    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];

        template <class b, class d>
        struct is_base_of_
        {
            template <class u> static  yes check(u*);
            template <typename> static no check(...);
            enum { result = sizeof(check<b>(static_cast<d*>(0))) };
            enum { value = result != sizeof(no)  };
        };

    } // namespace detail

    template <class b, class d>
    struct is_base_of
        : dDETAIL_TRAITS(is_base_of_<b, d>)
    {};

} // namespace tools 

#endif // !dTOOLS_IS_BASE_OF_USED_

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

//================================================================= (sfinae) ===
//=== is_convertible ====================== (integral_constant)(conditional) ===
#ifndef dTOOLS_IS_CONVERTIBLE_USED_ 
#define dTOOLS_IS_CONVERTIBLE_USED_ 1
namespace tools
{
    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];
        template<class t> t obj();

        #ifdef _MSC_VER
            #pragma warning(push)
            // warning C4244: 'argument' : conversion from 'float' to 'int', 
            // possible loss of data
            #pragma warning(disable: 4244)
        #endif

        template <class from, class to>
        struct is_convertible_
        {
            #ifdef dHAS_RVALUE_REFERENCES
                typedef from&& from_t;
            #endif

            template <class u> static yes check(u);
            template <class>   static  no check(...);

            #ifdef dHAS_RVALUE_REFERENCES
                enum { result = sizeof(check<to>(obj<from_t>())) };
            #else
                enum { result = sizeof(check<to>(obj<from>())) };
            #endif
        
            enum { value = result != sizeof(no) };
        };

        #ifdef _MSC_VER
            #pragma warning(pop)
        #endif

        template <class to>
        struct is_convertible_<void, to>
            { enum { value = false }; };

        template <class from> 
        struct is_convertible_<from, void>
            { enum { value = false }; };

        template <class t> 
        struct is_convertible_<t, t>
            { enum { value = true }; };

    } // namespace detail

    template <class from, class to>
    struct is_convertible
        : dDETAIL_TRAITS(is_convertible_<from, to>)
    {};

} // namespace tools 

#endif // !dTOOLS_IS_CONVERTIBLE_USED_

//==============================================================================
//=== decay =================================== (is_array)(remove_reference) ===
//=== decay =================================== (add_pointer)(remove_extent) ===
//=== decay ===================================== (conditional)(is_function) ===
//=== decay ==================================================== (remove_cv) ===
#ifndef dTOOLS_DECAY_USED_ 
#define dTOOLS_DECAY_USED_ 2
namespace tools
{
    // first step: remove reference
    // function ---> pointer-to-function
    // array ------> pointer-to-first-element (remove one extent)
    // other ------> remove-reference and remove-cv
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
            no_cv;
        typedef ::tools::conditional<foo, ptr1, no_cv>
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
//==============================================================================
#endif // !dTOOLS_TRAITS_USED_
