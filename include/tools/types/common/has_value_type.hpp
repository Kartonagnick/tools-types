// [2021y-04m-13d][18:30:25] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_HAS_VALUE_TYPE_USED_ 
#define dTOOLS_HAS_VALUE_TYPE_USED_ 100

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
                typename u::value_type    \
            >::type

        template<class t> class has_value_type_
        {
            template<class u> static yes
                check(dSFINAE(u));

            template<class> static no
                check(...);

            enum { result = sizeof(check<t>(0)) };
        public:
            has_value_type_();
            enum { value = result != sizeof(no) };
        };

        #undef dSFINAE

    } // namespace detail

    // t::value_type --> true
    template<class t> class has_value_type
        : dDETAIL_CONSTANT(has_value_type_<t>)
    {};

} // namespace tools 
//==============================================================================
//==============================================================================

#endif // !dTOOLS_IS_ITERABLE_USED_
