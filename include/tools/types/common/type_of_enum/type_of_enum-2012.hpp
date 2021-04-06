// [2021y-04m-06d][19:20:58] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_TYPE_OF_ENUM_2012_USED_ 
#define dTOOLS_TYPE_OF_ENUM_2012_USED_ 100, 2012

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
            typedef ::std::underlying_type<t>
                x;
            typedef typename x::type 
                type;
        };

        template<class t> 
        struct type_of_enum_<t, false>
            { typedef t type; };

    } // namespace detail

    template<class t> struct type_of_enum
        : ::tools::detail::type_of_enum_<t>
    {};

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_TYPE_OF_ENUM_2012_USED_
