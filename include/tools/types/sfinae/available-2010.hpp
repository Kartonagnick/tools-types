// [2021y-04m-28d][17:13:14] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_AVAILABLE_2010_USED_ 
#define dTOOLS_SFINAE_AVAILABLE_2010_USED_ 100 PRE

//#include <type_traits>
#include <cstddef>

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
            using x = ::std::remove_reference<t>;

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

    namespace detail
    {
        template<class t> class dereference_
        {
            struct no_{};

            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type x;

            template<class u> static
            decltype(*::std::declval<u>()) check(u*);

            template<class> static no_
                check(...);
            typedef decltype(check<x>(nullptr))
                checked;
            enum { ok = ::std::is_same<checked, no_>::value };
            typedef std::integral_constant<bool, ok>
                result;
        public:
            enum { value = result::value };
        };

    } // namespace detail

    template<class t> 
    class dereference : dIMPLEMENT_(dereference_<t>) {};

//==============================================================================
//==============================================================================

    namespace detail
    {
        template<class t, class i> class access_
        {
            struct no_{};
            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type x;

            template<class u> static
            decltype(::std::declval<u&>()[::std::declval<i>()]) 
                check(u*);
            template<class> static no_
                check(...);
            typedef decltype(check<x>(nullptr))
                checked;
            enum { ok = ::std::is_same<checked, no_>::value };
            typedef std::integral_constant<bool, ok>
                result;
        public:
            enum { value = result::value };
        };

    } // namespace detail

    template<class t, class i = size_t> 
    class access : dIMPLEMENT_(access_<t, i>) {};

} // namespace available
} // namespace sfinae
} // namespace tools

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_AVAILABLE_2010_USED_
