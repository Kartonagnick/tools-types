// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-04m-10d][01:40:31] Idrisov Denis R. 100
//==============================================================================
//==============================================================================
#pragma once
#ifndef dTOOLS_ENABLE_FOR_2012_USED_ 
#define dTOOLS_ENABLE_FOR_2012_USED_ 100,2012

#include <tools/types/common/find_type.hpp>
#include <tools/types/common/degradate.hpp>

//==============================================================================
//=== enable_if_find/disable_if_find =============== (degradate)(find_type) ====
namespace tools 
{
    // if type 't' is in the list 'args' --> compile
    #define dif_enabled(ret, t, ...)                          \
        typename ::std::enable_if<                            \
            ::tools::find_type<                               \
                typename ::tools::degradate<t>::type,         \
                __VA_ARGS__                                   \
            >::value, ret                                     \
        >::type

    // if type 't' is not in the list 'args' --> compile
    #define dif_disabled(ret, t, ...)                         \
        typename ::std::enable_if<                            \
            ! ::tools::find_type<                             \
                typename ::tools::degradate<t>::type,         \
                __VA_ARGS__                                   \
            >::value, ret                                     \
        >::type

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_ENABLE_FOR_2012_USED_
