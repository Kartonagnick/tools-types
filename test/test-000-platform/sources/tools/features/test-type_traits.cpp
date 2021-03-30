// [2021y-03m-04d][01:29:32] Idrisov Denis R.
#include <mygtest/modern.hpp>
//=================================================================================
//=================================================================================

#ifdef TEST_TOOLS_FEATURE_TYPE_TRAITS

#define dTEST_COMPONENT tools, features
#define dTEST_METHOD test_HAS_TYPE_TRAITS
#define dTEST_TAG tdd

#include <tools/features.hpp>
#include <string>

#ifdef dHAS_TYPE_TRAITS
    dMESSAGE("[test] tools: enabled -> dHAS_TYPE_TRAITS")
    #include <type_traits>
#else
    dMESSAGE("[test] tools: disabled -> dHAS_TYPE_TRAITS")
#endif

//==============================================================================
//==============================================================================
namespace
{
    #ifdef dHAS_TYPE_TRAITS
        enum { value = std::is_array<char[1]>::value };
        dSTATIC_ASSERT(value, MUST_BE_ARRAY);
    #endif

} // namespace

TEST_COMPONENT(000)
{
    const std::string v = dSSTRINGIZE(dTRAIT);
    dprint(std::cout << "dTRAIT: " << v << '\n');

    #if defined(dHAS_TYPE_TRAITS) && defined(dHAS_RVALUE_REFERENCES)
        ASSERT_TRUE(v == "std");
    #else
        ASSERT_TRUE(v == "tools");
    #endif
}

//==============================================================================
//==============================================================================
#endif // ! TEST_TOOLS_FEATURE_TYPE_TRAITS



