// [2021y-04m-12d][14:52:02] Idrisov Denis R. 100
// [2021y-04m-14d][01:44:38] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_IS_ITERATOR_2008_USED_ 
#define dTOOLS_IS_ITERATOR_2008_USED_ 100,2008

#include <tools/type_traits.hpp>

//==============================================================================
//==============================================================================
namespace tools
{
    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];

        #define dSFINAE(t) help_iter_<      \
            typename t::iterator_category   \
        >

        template<class t> 
            struct help_iter_;

        template<class t> class is_iter_
        {
            template<class u> static yes
                check(dSFINAE(u)*);

            template<class> static no
                check(...);
                        
            enum { result = sizeof(check<t>(0)) };
        public:
            enum { value = result != sizeof(no) };
        };

        #undef dSFINAE

        template<class t, bool> struct is_iterator_impl_
            { enum { value = true }; };

        template<class t> struct is_iterator_impl_<t, false>
            : ::tools::detail::is_iter_<t>
        {};

        template<class t> class is_iterator_
        {
            enum { ok = dTRAIT::is_pointer<t>::value };
            typedef ::tools::detail::is_iterator_impl_<t, ok>
                result;
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
#endif // !dTOOLS_IS_ITERATOR_2008_USED_
