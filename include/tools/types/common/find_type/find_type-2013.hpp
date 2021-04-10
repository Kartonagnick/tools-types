// [2021y-03m-29d][23:43:28] Idrisov Denis R. 100
// [2021y-04m-10d][02:49:51] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_FIND_TYPES_2013_USED_ 
#define dTOOLS_FIND_TYPES_2013_USED_ 101,2013

#include <type_traits>

#define dDETAIL_CONSTANT(...)              \
    public dTRAIT::integral_constant<bool, \
        detail::__VA_ARGS__::value         \
    >

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
            struct find_type_;

        template<class t, class s, class ...args>
        struct find_type_<t, s, args...>
        {
            using x = ::tools::detail::find_type_<t, args...>;
            enum { cur = ::std::is_same<t, s>::value };
            enum { value = cur || x::value };
        };

        template<class t> struct find_type_<t>
        {
            enum { value = false };
        };

    } // namespace detail

    // if type 't' is in the list 'args' --> true
    template<class t, class ...args>
    struct find_type
        : dDETAIL_CONSTANT(find_type_<t, args...>)
    {};

} // namespace tools 
#endif // !dTOOLS_FIND_TYPE_USED_


//==============================================================================
//==============================================================================
#endif // !dTOOLS_FIND_TYPES_2013_USED_
