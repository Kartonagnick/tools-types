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
    #define TEST_REMOVE_REFERENCE                           // ready!
    #define TEST_DECAY                                      // ready!
    #define TEST_IS_CLASS                                   // ready!
    #define TEST_IS_CONST                                   // ready!
    #define TEST_IS_VOLATILE                                // ready!
    #define TEST_IS_POINTER                                 // ready!
    #define TEST_IS_REFERENCE                               // ready!
    #define TEST_REMOVE_POINTER                             // ready!
    #define TEST_IS_FUNCTION                                // ready!
    #define TEST_IS_ARRAY                                   // ready!
    #define TEST_IS_BASE_OF                                 // ready!
    #define TEST_IS_CONVERTIBLE                             // ready!
    #define TEST_REMOVE_EXTENSION                           // ready!
    #define TEST_REMOVE_ALL_EXTENSION                       // ready!
    #define TEST_ADD_POINTER                                // ready!
    #define TEST_IS_UNSIGNED                                // ready!

//==============================================================================
//===== tools/types/common =================================||==================
    #define TEST_TOOLS_DEGRADATE                            // ready!
    #define TEST_TOOLS_FOR_LVALUE                           // ready!
    #define TEST_TOOLS_FOR_RVALUE                           // ready!
    #define TEST_TOOLS_FIND_TYPE                            // ready!
    
    #define TEST_TOOLS_IS_ZERO_ARRAY                        // ready!
    #define TEST_TOOLS_SIZE_ARRAY                           // ready!
    #define TEST_TOOLS_SMALL_ARRAY                          // ready!
    #define TEST_TYPE_OF_ENUM                               // ready!
    #define TEST_TOOLS_VARIADIC                             // ready!
    #define TEST_TOOLS_IS_VOLATILE_DATA                     // ready!
    #define TEST_TOOLS_IS_CONST_DATA                        // ready!
    #define TEST_TOOLS_ADD_CONST_DATA                       // ready!
    #define TEST_TOOLS_ENABLE_FOR                           // ready!
    
//==============================================================================
//===== tools/types/sfinae =================================||==================
    #define TEST_TOOLS_SFINAE_DEREFERENCE                   // ready!
    #define TEST_TOOLS_SFINAE_ACCESS                        // ready!
    #define TEST_TOOLS_SFINAE_CALL                          // in progress...

    #define TEST_TOOLS_SFINAE_BEGIN                         // ready!
    #define TEST_TOOLS_SFINAE_END                           // ready!

//==============================================================================
//===== tools/types/sfinae =================================||==================
    // #define TEST_TOOLS_DEREF_AVAILABLE                   // in progress...
    #define TEST_TOOLS_SFINAE                               // ready!
    // #define TEST_TOOLS_IS_LAMBDA                         // in progress...
    // #define TEST_TOOLS_IS_DEREFERENCABLE                 // in progress...
    // #define TEST_TOOLS_HAS_OPERATOR_ACCESS               // in progress...
    // #define TEST_TOOLS_IS_INCREMENTABLE                  // in progress...
    // #define TEST_TOOLS_IS_DECREMENTABLE                  // in progress...
    // #define TEST_TOOLS_IS_ITERABLE                       // in progress...
    // #define TEST_TOOLS_IS_ITERATOR                       // in progress...
    // #define TEST_TOOLS_HAS_VALUE_TYPE                    // in progress...
    // #define TEST_TOOLS_HAS_MAPPED_TYPE                   // in progress...
    // #define TEST_TOOLS_HAS_BEGIN                         // in progress...
    // #define TEST_TOOLS_HAS_END                           // in progress...

//==============================================================================
//===== tools/types ========================================||==================
    #define TEST_TOOLS_FIXED                                // ready!
    #define TEST_TOOLS_LIMIT                                // ready!
    #define TEST_TOOLS_DEMANGLE                             // ready!
    #define TEST_TOOLS_VOID_T                               // ready!

//==============================================================================
//==============================================================================

#endif // !dTEST_STABLE_USED_

