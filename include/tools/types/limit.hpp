// [2021y-04m-19d][16:17:50] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_LIMIT_USED_
#define dTOOLS_LIMIT_USED_ 100
//==============================================================================
//==============================================================================

#if (defined(_MSC_VER) && _MSC_VER >= 1900) || __cplusplus >= 201103L
    // #pragma message("build for msvc2015 (or newer) or other compiler")
    #include <tools/types/fixed/fixed-cpp11.hpp>
#else
    #include <tools/types/fixed/fixed-cpp98.hpp>
#endif

#include <tools/type_traits.hpp>

//==============================================================================
//=== limit ====================================================================
#ifndef dTOOLS_LIMIT_USED_ 
#define dTOOLS_LIMIT_USED_ 101
namespace tools
{
    template<class t> struct limit_unsigned
        : map_unsigned<sizeof(t)>
    {};

    template<class t> struct limit_signed
        : map_signed<sizeof(t)>
    {};

    namespace detail
    {
        template <class t, bool, bool> 
            struct limit_impl_;

        template <class t> struct limit_impl_<t, true, true>
            : limit_signed<t>
        {};

        template <class t> struct limit_impl_<t, true, false>
            : limit_unsigned<t>
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
#endif // !dTOOLS_LIMIT_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_LIMIT_USED_
