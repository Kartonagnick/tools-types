// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2020y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-26d][01:24:02] Idrisov Denis R.
// [2021y-04m-03d][19:36:45] Idrisov Denis R. 2
// [2021y-04m-20d][22:22:41] Idrisov Denis R. 3
//==============================================================================
#pragma once
#ifndef dTOOLS_VARIADIC_OLD_USED_ 
#define dTOOLS_VARIADIC_OLD_USED_ 3 PRE

#include <tools/features.hpp>
#include <tools/type_traits.hpp>

//==============================================================================
//=== is_heir ==================================================================
#ifndef dTOOLS_IS_HEIR_USED_ 
#define dTOOLS_IS_HEIR_USED_ 3, 2008  PRE
namespace tools
{
    struct dummy;

    namespace detail
    {
        template <class b, class d>
        struct is_heir_
        {
            typedef typename dTRAIT::decay<b>::type 
                bb;
            typedef typename dTRAIT::decay<d>::type
                dd;
            typedef dTRAIT::is_base_of<bb, dd> 
                xx;
            enum { value = xx::value };
        };

        #define dFOR_HEIR_ \
            bool = ::tools::detail::is_heir_<b, d>::value

        template<class b, class d, dFOR_HEIR_ > 
        class if_variadic_;

        template<class b, class d> 
        class if_variadic_<b, d, false>
        {
            typedef ::tools::dummy*
                type;
        };

        #undef dFOR_HEIR_

    } // namespace detail

    template<class b, class d>
    struct is_heir
        : dDETAIL_CONSTANT(is_heir_<b, d>)
    {};

} // namespace tools
#endif //!dTOOLS_IS_HEIR_USED_

//==============================================================================
//==============================================================================

#define dTEMPLATE_CONSTRUCT_IMPL(base, arg) \
    typename ::tools::detail::if_variadic_< \
        base, arg                           \
    >::type

#define dTEMPLATE_CONSTRUCT_ARG(base, arg)  \
    dTEMPLATE_CONSTRUCT_IMPL(base, arg) = 0

//==============================================================================
//==============================================================================
#endif //!dTOOLS_VARIADIC_OLD_USED_

