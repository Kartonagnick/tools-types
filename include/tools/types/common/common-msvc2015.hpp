// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-17d][23:05:40] Idrisov Denis R.
// [2021y-03m-20d][06:20:40] Idrisov Denis R. 103
#pragma once
#ifndef dTOOLS_COMMON_NEW_USED_ 
#define dTOOLS_COMMON_NEW_USED_ 103

#include <type_traits>

#define dDETAIL_CONSTANT(...) \
    ::std::integral_constant<bool, detail::__VA_ARGS__::value>


//==============================================================================
//=== find_type ================================================================
#ifndef dTOOLS_FIND_TYPE_USED_ 
#define dTOOLS_FIND_TYPE_USED_ 100
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
#define dTOOLS_IS_FUNCTOR_USED_ 100
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
        : public dDETAIL_CONSTANT(is_functor<F>)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_FUNCTOR_USED_


//==============================================================================
//=== degradate ================================================================
#ifndef dTOOLS_DEGRADATE_USED_ 
#define dTOOLS_DEGRADATE_USED_ 100
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
#define dTOOLS_FOR_LVALUE_USED_ 100
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
//=== dfor_rvalue ==============================================================
#ifndef dTOOLS_FOR_RVALUE_USED_ 
#define dTOOLS_FOR_RVALUE_USED_ 100
namespace tools
{

    #define dfor_rvalue(t) ::tools::for_rvalue<t>* = nullptr
    template<class t, class ret = void> 
        using for_rvalue
            = ::std::enable_if_t<
                ::std::is_rvalue_reference<t>::value,
                ret
            >;

    #define dfor_not_rvalue(t) ::tools::for_not_rvalue<t>* = nullptr
    template<class t, class ret = void> 
        using for_not_rvalue
            = ::std::enable_if_t<
                ! ::std::is_rvalue_reference<t>::value,
                ret
            >;

} // namespace tools
#endif // !dTOOLS_FOR_RVALUE_USED_


//==============================================================================
//=== is_zero_array ============================================================
#ifndef dTOOLS_IS_ZERO_ARRAY_USED_ 
#define dTOOLS_IS_ZERO_ARRAY_USED_ 100
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
#define dTOOLS_SIZE_ARRAY_USED_
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

    #define dfor_big_array(arr)         \
        ::std::enable_if_t<             \
            ::tools::size_array<        \
                ::tools::degradate<arr> \
            >::big                      \
        >* = nullptr

    #define dfor_small_array(arr)       \
        ::std::enable_if_t<             \
            ::tools::size_array<        \
                ::tools::degradate<arr> \
            >::Small                    \
        >* = nullptr

} // namespace tools 
#endif // !dTOOLS_SIZE_ARRAY_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMMON_NEW_USED_
