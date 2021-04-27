// [2021y-04m-27d][20:51:57] Idrisov Denis R. 100 PRE

#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2015_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2015_USED_ 100 PRE

#include <type_traits>
#include <cstddef>

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
            decltype(::std::declval<u>()(::std::declval<args>()...), ::std::true_type())
                check(u*);

            template<class> static
            ::std::false_type
                check(...);

            typedef decltype(check<x>(nullptr))
                checked;
        public:
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
    struct dereferencable : ::std::false_type {};
 
    template<class t> struct dereferencable<t,
            ::std::void_t<decltype(*::std::declval<t>())>
        > : ::std::true_type
    {};

//==============================================================================
//==============================================================================

    template<class, class = size_t, class = void>
    struct access : ::std::false_type {};
 
    template<class t> struct access<t, size_t,
            ::std::void_t<decltype(::std::declval<t>()[0])>
        > : ::std::true_type
    {};

    template<class t, class i> struct access<t, i,
            ::std::void_t<decltype(::std::declval<t>()[::std::declval<i>()])>
        > : ::std::true_type
    {};

} // namespace available
} // namespace sfinae
} // namespace tools

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_AVAILABLE_2015_USED_
