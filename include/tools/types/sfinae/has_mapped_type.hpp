// [2021y-04m-13d][21:03:13] Idrisov Denis R. 100
// [2021y-04m-14d][01:45:51] Idrisov Denis R. 100
// [2021y-04m-21d][13:27:35] Idrisov Denis R. 101 PRE
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_HAS_MAPPED_TYPE_USED_ 
#define dTOOLS_HAS_MAPPED_TYPE_USED_ 101 PRE

#include <tools/type_traits.hpp>

//==============================================================================
//==============================================================================

namespace tools
{
    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];

        #define dSFINAE(u)                \
            typename dTRAIT::add_pointer< \
                typename u::mapped_type   \
            >::type

        template<class t> class has_mapped_type_
        {
            template<class u> static yes
                check(dSFINAE(u));

            template<class> static no
                check(...);

            enum { result = sizeof(check<t>(0)) };
        public:
            has_mapped_type_();
            enum { value = result != sizeof(no) };
        };

        #undef dSFINAE

    } // namespace detail

    // t::value_type --> true
    template<class t> class has_mapped_type
        : dDETAIL_CONSTANT(has_mapped_type_<t>)
    {};

} // namespace tools 
//==============================================================================
//==============================================================================

#endif // !dTOOLS_IS_ITERABLE_USED_
