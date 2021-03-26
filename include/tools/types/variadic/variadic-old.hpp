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
    namespace detail
    {
        template <class b, class d>
        struct is_heir<b, d>
        {
            typedef dTRAIT::decay<b> bb;
            typedef dTRAIT::decay<d> dd;
            using xx = dTRAIT::is_base_of<bb, dd>;
            enum { value = xx::value };
        };

    } // namespace detail

    template<class... args>
    struct is_heir
        : dDETAIL_CONSTANT(is_heir<args...>)
    {};

} // namespace tools
#endif //!dTOOLS_IS_HEIR_USED_

//==============================================================================
//==============================================================================

#define dTEMPLATE_CONSTRUCT(type, arg)      \
    typename t = ::std::enable_if_t<        \
        !::tools::is_heir<type, arg>::value \
    >

//==============================================================================
//==============================================================================
#endif //!dTOOLS_VARIADIC_OLD_USED_

