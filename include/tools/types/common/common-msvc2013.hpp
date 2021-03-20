// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-17d][20:59:19] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_COMMON_NEW_USED_ 
#define dTOOLS_COMMON_NEW_USED_ 102

// msvc2013 has bug: std::is_rvalue_reference is not worked

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
//==============================================================================
#endif // !dTOOLS_COMMON_NEW_USED_
