// [2021y-04m-27d][20:51:57] Idrisov Denis R. 100 PRE

#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2015_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2015_USED_ 100 PRE

#include <cstddef>
#include <type_traits>
#include <tools/types/void_t.hpp>

#define dIMPLEMENT_(...)                  \
    public ::std::integral_constant<bool, \
        detail::__VA_ARGS__::value        \
    >

//==============================================================================
//==============================================================================

namespace tools     {
namespace sfinae    {
namespace available {

    namespace detail
    {
        template<class t, class ...args> class call_
        {
            using x = ::std::remove_reference_t<t>;

            template<class u> static
            decltype(::std::declval<u>()(::std::declval<args>()...), 
                ::std::true_type())
                check(u*);

            template<class> static
            ::std::false_type
                check(...);

            typedef decltype(check<x>(nullptr))
                checked;
        public:
            call_() = delete;
            enum { value = checked::value };
        };

    } // namespace detail

    template<class t, class...args>
    struct call
        : dIMPLEMENT_(call_<t, args...>)
    {};

//==============================================================================
//==============================================================================

    template<class, class = void>
    struct dereference : ::std::false_type {};
 
    template<class t> struct dereference<t,
            ::std::void_t<decltype(*::std::declval<t>())>
        > : ::std::true_type
    {};

//==============================================================================
//==============================================================================

    template<class, class = size_t, class = void>
    struct access : ::std::false_type {};
 
    template<class t> struct access<t, size_t,
            ::std::void_t<decltype(::std::declval<t>()[0u])>
        > : ::std::true_type
    {};

    template<class t, class i> struct access<t, i,
            ::std::void_t<decltype(::std::declval<t>()[::std::declval<i>()])>
        > : ::std::true_type
    {};

//==============================================================================
//==============================================================================

    template<class, class = void>
    struct begin: ::std::false_type {};
 
    template<class t> struct begin<t,
            ::std::void_t<decltype(::std::declval<t>().begin())>
        > : ::std::true_type 
    {};

//==============================================================================
//==============================================================================

    #ifdef _MSC_VER
        #if _MSC_VER >= 1900 && _MSC_VER < 1919
            // msvc2015
        #endif
    #endif

    template<class, class = void>
    struct end: ::std::false_type {};
 
    template<class t> struct end<t,
        dSFINAE_VOID_TYPE(decltype(::std::declval<t>().end()))
        > : ::std::true_type 
    {};

} // namespace available
} // namespace sfinae
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_AVAILABLE_2015_USED_
