// [2021y-04m-27d][21:07:30] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_SIGNATURE_2015_USED_ 
#define dTOOLS_SFINAE_SIGNATURE_2015_USED_ 100 PRE

#include <type_traits>

#ifndef _MSC_VER
    #include <tools/types/sfinae/exist-2015.hpp>
#endif

#define dIMPLEMENT_(...)                \
    public std::integral_constant<bool, \
        detail::__VA_ARGS__::value      \
    >

namespace tools 
{
    typedef char(&no)[1];
    typedef char(&yes)[2];

} // namespace tools 

//==============================================================================
//==============================================================================

namespace tools  {
namespace sfinae {
namespace signature {

    namespace detail
    {
        template<class t, class sig>
        class dereferencable_
        {
            template <class cl>
            using method
                = decltype(static_cast<sig>(&cl::operator*));

            using x = ::std::remove_reference_t<t>;

            template <class u> static yes check(method<u>*);
            template <class>   static no  check(...);

            enum { sz = sizeof(check<x>(0)) };
        public:
            dereferencable_() = delete;
            enum { value = sz != sizeof(no) };
        };

    } // namespace detail

    template<class t, class sig> 
    class dereferencable
        : dIMPLEMENT_(dereferencable_<t, sig>)
    {};

} // namespace signature
} // namespace sfinae
} // namespace tools

#undef dIMPLEMENT_
//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_SIGNATURE_2015_USED_