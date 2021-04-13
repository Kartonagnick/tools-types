// [2021y-04m-12d][14:52:02] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_IS_ITERATOR_2013_USED_ 
#define dTOOLS_IS_ITERATOR_2013_USED_ 100,2013

#include <tools/type_traits.hpp>

//==============================================================================
//==============================================================================
namespace tools
{
    namespace detail
    {
        #define dSFINAE(t) help_iter_<      \
            typename t::iterator_category,  \
            typename t::value_type,         \
            typename t::difference_type,    \
            typename t::pointer,            \
            typename t::reference           \
        >

        template<class t1, class t2, class t3, class t4, class t5> 
            struct help_iter_;

        template<class t> class is_iter_
        {
            template<class u> static ::std::true_type
                check(dSFINAE(u)*);

            template<class> static ::std::false_type
                check(...);

            using checked
                = decltype(check<t>(nullptr));
        public:
            enum { value = checked::value };
        };

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
#endif // !dTOOLS_IS_ITERATOR_2013_USED_
