// [2021y-04m-06d][19:20:58] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_TYPE_OF_ENUM_2013_USED_ 
#define dTOOLS_TYPE_OF_ENUM_2013_USED_ 100, 2013

#include <type_traits>

//================================================================================
//=== type_of_enum ============================================= (type_traits) ===
namespace tools
{
    namespace detail
    {
        template<class t, bool = ::std::is_enum<t>::value>
        struct type_of_enum_
        {
            using x = ::std::underlying_type<t>;
            using type = typename x::type;
        };

        template<class t> 
        struct type_of_enum_<t, false>
            { using type = t; };

    } // namespace detail

    template<class t> struct type_of_enum
        : ::tools::detail::type_of_enum_<t>
    {};

    template<class t> 
    using type_of_enum_t
        = typename ::tools::type_of_enum<t>::type;

} // tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_TYPE_OF_ENUM_2013_USED_
