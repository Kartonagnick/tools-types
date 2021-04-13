// [2021y-04m-13d][16:34:51] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_IS_ITERATOR_2015_USED_ 
#define dTOOLS_IS_ITERATOR_2015_USED_ 100,2015

#include <tools/type_traits.hpp>

//==============================================================================
//==============================================================================
namespace tools
{
    namespace detail
    {
        #define dSFINAE(t) ::std::void_t<   \
            typename t::iterator_category,  \
            typename t::value_type,         \
            typename t::difference_type,    \
            typename t::pointer,            \
            typename t::reference           \
        >

        template<class, class = void>
        struct is_iter_
            { enum { value = false }; };

        template<class t>
        struct is_iter_<t, dSFINAE(t)>
            { enum { value = true }; };

        #undef dSFINAE

        template<class t, bool> struct is_iterator_impl_
            { enum { value = true }; };

        template<class t> struct is_iterator_impl_<t, false>
            : ::tools::detail::is_iter_<t>
        {};

        template<class t> class is_iterator_
        {
            enum { ok = ::std::is_pointer<t>::value };
            using result
                = ::tools::detail::is_iterator_impl_<t, ok>;
        public:
            enum { value = result::value };
        };

    } // namespace detail

    // pointer* -----------------> true
    // std-compatible iterator --> true
    template<class t> class is_iterator
        : dDETAIL_CONSTANT(is_iterator_<t>)
    {};

} // namespace tools 
//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_ITERATOR_2015_USED_
