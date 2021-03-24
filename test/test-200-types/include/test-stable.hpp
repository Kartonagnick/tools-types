// [2021y-03m-10d][12:46:41] Idrisov Denis R.
#pragma once

#ifndef dTEST_STABLE_USED_ 
#define dTEST_STABLE_USED_ 1

    #define dFORBID_ZERO_SIZE_ARRAY
    #define INCLUDE_AUTO_GENERATED

    // #define INCLUDE_STRESS_TESTS
    #define INCLUDE_LONG_LONG_TESTS
    #define INCLUDE_LONG_TESTS

//==============================================================================
//===== tools/types/traits =================================||==================
    #define TEST_IS_FLOATING                                // ready!
    #define TEST_IS_SIGNED                                  // ready!
    #define TEST_IS_INTEGRAL                                // ready!
    #define TEST_REMOVE_CV                                  // ready!
    #define TEST_CONDITIONAL                                // ready!
    #define TEST_IS_SAME                                    // ready!
    #define TEST_ENABLE_IF                                  // ready!
    #define TEST_TYPE_OF_ENUM                               // ready!
    #define TEST_REMOVE_REFERENCE                           // ready!
    #define TEST_DECAY                                      // ready!
    #define TEST_IS_CLASS                                   // ready!

    #define TEST_IS_CONST                                   // in progress...
    #define TEST_IS_VOLATILE                                // in progress...
    #define TEST_IS_POINTER                                 // in progress...
    #define TEST_IS_REFERENCE                               // in progress...
    #define TEST_REMOVE_POINTER                             // in progress...

//==============================================================================
//===== tools/types/common =================================||==================
    #define TEST_TOOLS_DEGRADATE                            // ready!
    #define TEST_TOOLS_FOR_LVALUE                           // ready!
    #define TEST_TOOLS_FOR_RVALUE                           // ready!
    #define TEST_TOOLS_FIND_TYPE                            // ready!
    #define TEST_TOOLS_IS_FUNCTOR                           // ready!
    #define TEST_TOOLS_IS_ZERO_ARRAY                        // ready!
    #define TEST_TOOLS_SIZE_ARRAY                           // ready!
    #define TEST_TOOLS_SMALL_ARRAY                          // ready!
    #define TEST_TOOLS_IS_DEREFERENCABLE                    // ready!

    #define TEST_TOOLS_IS_VOLATILE_DATA                     // in progress...

//==============================================================================
//===== tools/types ========================================||==================
    #define TEST_FIXED                                      // ready!

//==============================================================================
//==============================================================================
#endif // !dTEST_STABLE_USED_

