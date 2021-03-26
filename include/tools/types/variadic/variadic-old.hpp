// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2020y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-26d][01:24:02] Idrisov Denis R.
//==============================================================================
#pragma once
#ifndef dTOOLS_VARIADIC_OLD_USED_ 
#define dTOOLS_VARIADIC_OLD_USED_ 1

#include <tools/types/traits.hpp>

//==============================================================================
//=== is_heir ==================================================================
#ifndef dTOOLS_IS_HEIR_USED_ 
#define dTOOLS_IS_HEIR_USED_ 1, 2008
namespace tools
{
    struct dummy {};

    namespace detail
    {
        template <class b, class d>
        struct is_heir
        {
            typedef typename dTRAIT::decay<b>::type 
                bb;
            typedef typename dTRAIT::decay<d>::type
                dd;
            typedef dTRAIT::is_base_of<bb, dd> 
                xx;
            enum { value = xx::value };
        };

    } // namespace detail

    template<class b, class d>
    struct is_heir
        : dDETAIL_CONSTANT(is_heir<b, d>)
    {};

} // namespace tools
#endif //!dTOOLS_IS_HEIR_USED_

//==============================================================================
//==============================================================================

#define dTEMPLATE_CONSTRUCT_IMPL(base, arg)  \
    typename dTRAIT::enable_if<              \
        ! tools::detail::is_heir<base, arg>::value,   \
         const tools::dummy&                 \
    >::type


#define dTEMPLATE_CONSTRUCT_ARG(base, arg)  \
    dTEMPLATE_CONSTRUCT_IMPL(base, arg) \
        = tools::dummy()

//==============================================================================
//==============================================================================
#endif //!dTOOLS_VARIADIC_OLD_USED_

