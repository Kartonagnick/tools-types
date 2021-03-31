// [2021y-02m-07d][18:40:18] Idrisov Denis R.
// [2021y-03m-31d][22:57:11] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_ASSERT_USED_
#define dTOOLS_ASSERT_USED_ 101
//==============================================================================
//==============================================================================

#ifdef NDEBUG
    #define dASSERT(...) void()
#else
    #include <cassert>
    #define dASSERT(...) assert((__VA_ARGS__))
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_ASSERT_USED_
