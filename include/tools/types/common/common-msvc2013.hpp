// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-17d][20:59:19] Idrisov Denis R.
// [2021y-03m-20d][19:43:08] Idrisov Denis R. 103
// [2021y-03m-21d][17:51:39] Idrisov Denis R. 104
// [2021y-03m-23d][23:55:08] Idrisov Denis R. 105
#pragma once
#ifndef dTOOLS_COMMON_NEW_USED_ 
#define dTOOLS_COMMON_NEW_USED_ 105,2013

// msvc2013 has bug: std::is_rvalue_reference is not worked

#include <type_traits>

#define dDETAIL_CONSTANT(...) \
    public ::std::integral_constant<bool, detail::__VA_ARGS__::value>


//==============================================================================
//=== degradate ================================================================
#ifndef dTOOLS_DEGRADATE_USED_ 
#define dTOOLS_DEGRADATE_USED_ 100,2013
namespace tools 
{
    template<class t> 
    using degradate = ::std::remove_cv_t<
        ::std::remove_reference_t<t> 
    >;

} // namespace tools 
#endif // !dTOOLS_DEGRADATE_USED_


//==============================================================================
//=== dfor_lvalue ==============================================================
#ifndef dTOOLS_FOR_LVALUE_USED_ 
#define dTOOLS_FOR_LVALUE_USED_ 100,2013
namespace tools
{
    #define dfor_lvalue(t) ::tools::for_lvalue<t>* = nullptr
    template<class t, class ret = void> 
        using for_lvalue
            = ::std::enable_if_t<
                ::std::is_lvalue_reference<t>::value,
                ret
            >;

    #define dfor_not_lvalue(t) ::tools::for_not_lvalue<t>* = nullptr
    template<class t, class ret = void> 
        using for_not_lvalue
            = ::std::enable_if_t<
                ! ::std::is_lvalue_reference<t>::value,
                ret
            >;

} // namespace tools
#endif // !dTOOLS_FOR_LVALUE_USED_


//==============================================================================
//=== find_type ================================================================
#ifndef dTOOLS_FIND_TYPE_USED_ 
#define dTOOLS_FIND_TYPE_USED_ 100,2013
namespace tools
{
    // if type 't' is in the list 'args' --> true
    namespace detail
    {
        template<class t, class ...args>
            struct find_type;

        template<class t, class s, class ...args>
        struct find_type<t, s, args...>
        {
            using x = ::tools::detail::find_type<t, args...>;
            enum { cur = ::std::is_same<t, s>::value };
            enum { value = cur || x::value };
        };

        template<class t> struct find_type<t>
        {
            enum { value = false };
        };

    } // namespace detail

    // if type 't' is in the list 'args' --> true
    template<class t, class ...args>
    struct find_type
        : dDETAIL_CONSTANT(find_type<t, args...>)
    {};

} // namespace tools 
#endif // !dTOOLS_FIND_TYPE_USED_


//==============================================================================
//=== is_functor ===============================================================
#ifndef dTOOLS_IS_FUNCTOR_USED_ 
#define dTOOLS_IS_FUNCTOR_USED_ 100,2013
namespace tools
{
    namespace detail
    {
        template<class lambda> class is_functor
        {
            using x
                = ::std::remove_reference_t<lambda>;

            template<class u> static ::std::true_type
                check(decltype(&u::operator())*);

            template<class> static ::std::false_type
                check(...);

            using checked
                = decltype(check<x>(nullptr));
        public:
            is_functor() = delete;
            enum { value = checked::value };
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
#define dTOOLS_IS_ZERO_ARRAY_USED_ 100,2013
namespace tools 
{
    #ifdef dHAS_ZERO_SIZE_ARRAY
        dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        template<class s> struct is_zero_array
            : ::std::false_type
        { using type = s; };


        template<class s> struct is_zero_array<s[0]>
            : ::std::true_type
        { using type = s; };

        dPRAGMA_POP
    #else

        template<class s> struct is_zero_array
            : ::std::false_type
        { using type = s; };

    #endif

} // namespace tools 
#endif // !dTOOLS_IS_ZERO_ARRAY_USED_


//==============================================================================
//=== size_array ===========================================(is_zero_array) ====
#ifndef dTOOLS_SIZE_ARRAY_USED_ 
#define dTOOLS_SIZE_ARRAY_USED_ 100,2013
namespace tools
{
    template<class s> class size_array
    {
        using view = ::tools::is_zero_array<s>;
        using view_t = typename view::type;
        enum
        {
            z = ::tools::is_zero_array<s>::value
        };
    public:
        size_array() = delete;
        enum { valid = 0 };
        enum { value = 0 };
        enum { big   = 0 };
        enum { Small = 0 }; // fucking windows:  #define small char
        enum { empty = 0 };
        enum { zero  = z };
        using type = view_t;
        using arr  = type;
        using ref  = type&;
        using rval = type&&;
    };
    template<class s, size_t N> class size_array<s[N]>
    {
    public:
        size_array() = delete;
        enum { valid = 1        };
        enum { value = N        };
        enum { big   = N  > 255 };
        enum { Small = N <= 255 };
        enum { empty = 0        };
        enum { zero  = N == 0   };
        using type = s;
        using arr  = type[value];
        using ref  = type(&)[value];
        using rval = type(&&)[value];
    };
    template<class s> class size_array<s[]>
    {
    public:
        size_array() = delete;
        enum { valid = 1 };
        enum { value = 0 };
        enum { big   = 0 };
        enum { Small = 0 };
        enum { empty = 1 };
        enum { zero  = 0 };
        using type = s;
        using arr  = type[];
        using ref  = type(&)[];
        using rval = type(&&)[];
    };

    #define dif_big_array(arr, ret)     \
        ::std::enable_if_t<             \
            ::tools::size_array<        \
                ::tools::degradate<arr> \
            >::big, ret                 \
        >

    #define dif_small_array(arr, ret)   \
        ::std::enable_if_t<             \
            ::tools::size_array<        \
                ::tools::degradate<arr> \
            >::Small, ret               \
        >

    #define dfor_big_array(arr)         \
        dif_big_array(arr, void) * = nullptr

    #define dfor_small_array(arr)        \
        dif_small_array(arr, void) * = nullptr

} // namespace tools 
#endif // !dTOOLS_SIZE_ARRAY_USED_


//==============================================================================
//=== small_array =================================(degradate)(size_array) =====
#ifndef dTOOLS_SMALL_ARRAY_USED_ 
#define dTOOLS_SMALL_ARRAY_USED_ 100,2013
namespace tools 
{
    template<class s1, class s2>
    class small_array_selector
    {
        using x  = ::std::remove_reference_t<s1>;
        using z  = ::std::remove_reference_t<s2>;
        using xx = ::tools::size_array<x>;
        using zz = ::tools::size_array<z>;

        enum { small1 = xx::Small && xx::valid };
        enum { small2 = zz::Small && zz::valid };
    public:
        small_array_selector() = delete;
        enum { value = small1 && small2 };
    };

    template<class arr1, class arr2, class ret = void>
    using for_big_arrays 
        = ::std::enable_if_t< 
            !::tools::small_array_selector<arr1, arr2>::value,
            ret
        >;

    template<class arr1, class arr2, class ret = void>
    using for_small_arrays 
        = ::std::enable_if_t<
            ::tools::small_array_selector<arr1, arr2>::value, 
            ret
        >;

    #define dif_big_arrays(arr1, arr2, ret) \
        ::tools::for_big_arrays<arr1, arr2, ret>

    #define dif_small_arrays(arr1, arr2, ret) \
        ::tools::for_small_arrays<arr1, arr2, ret>

    #define dfor_big_arrays(arr1, arr2) \
        ::tools::for_big_arrays<arr1, arr2>* = nullptr

    #define dfor_small_arrays(arr1, arr2) \
        ::tools::for_small_arrays<arr1, arr2>* = nullptr

} // namespace tools 
#endif // !dTOOLS_SMALL_ARRAY_USED_


//==============================================================================
//=== is_dereferencable ========================================================
#ifndef dTOOLS_IS_DEREFERENCABLE_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_USED_ 100,2013
namespace tools 
{
    namespace detail
    {
        template<class t> class is_dereferencable
        {
            using x = ::std::remove_reference_t<t>;

            #define dCHECK_EXPRESSION(...) \
                decltype(__VA_ARGS__, ::std::true_type{})

            template<class u> static dCHECK_EXPRESSION( 
                *::std::declval<u>()
            ) check(u*);

            #undef dCHECK_EXPRESSION

            template<class> static ::std::false_type
                check(...);

            using checked     
                = decltype(check<x>(nullptr));
        public:
            is_dereferencable() = delete;
            enum { value = checked::value };
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
#define dTOOLS_IS_VOLATILE_DATA_USED_ 100,2013
namespace tools
{
    namespace detail
    {
        template<class t> struct is_volatile_data
        {
        private:
            using x = ::std::remove_reference_t<t>;
            using z = ::std::remove_pointer_t<x>;
        public:
            enum { value = ::std::is_volatile<z>::value };
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
