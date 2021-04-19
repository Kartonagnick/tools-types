// [2021y-04m-19d][16:17:50] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_LIMIT_USED_
#define dTOOLS_LIMIT_USED_ 100
//==============================================================================
//==============================================================================

#include <tools/types/fixed.hpp>
#ifdef dHAS_TYPE_TRAITS
    #include <type_traits>
#else
    #include <tools/types/traits.hpp>
#endif

namespace tools
{
    namespace detail
    {
        template<class t> struct limit_unsigned_
            : ::tools::map_unsigned<sizeof(t)>
        {};

        template<class t> struct limit_signed_
            : ::tools::map_signed<sizeof(t)>
        {};

        template <class t, bool, bool> 
            struct limit_impl_;

        template <class t> struct limit_impl_<t, true, true>
            : ::tools::detail::limit_signed_<t>
        {};

        template <class t> struct limit_impl_<t, true, false>
            : ::tools::detail::limit_unsigned_<t>
        {};

        template <class t> struct limit_
        {
            enum { v1 = dTRAIT::is_signed<t>::value         };
            enum { v2 = dTRAIT::is_integral<t>::value       };
            enum { v3 = dTRAIT::is_floating_point<t>::value };
            enum { v4 = v2 || v3 };
            dSTATIC_ASSERT(ERROR_MUST_BE_ARTITHMETIC, v4);
            typedef ::tools::detail::limit_impl_<t, v4, v1> 
                type;
        };

    } // namespace detail

    template <class t> struct limit
        : ::tools::detail::limit_<t>::type
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_LIMIT_USED_
