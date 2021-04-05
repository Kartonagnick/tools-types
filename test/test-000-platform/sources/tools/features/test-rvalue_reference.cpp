// [2021y-02m-22d][04:21:08] Idrisov Denis R.
#include <mygtest/modern.hpp>
//=================================================================================
//=================================================================================

#ifdef TEST_TOOLS_FEATURE_RVALUE_REFERENCE

#define dTEST_COMPONENT tools, features
#define dTEST_METHOD test_HAS_RVALUE_REFERENCES
#define dTEST_TAG tdd

#include <tools/features.hpp>

#ifdef dHAS_RVALUE_REFERENCES
    dMESSAGE("[test] tools: enabled -> dHAS_RVALUE_REFERENCES")
#else
    dMESSAGE("[test] tools: disabled -> dHAS_RVALUE_REFERENCES")
#endif

#ifdef dHAS_RVALUE_REFERENCES
#include <string>

//==============================================================================
//==============================================================================
namespace 
{
    void foo(std::string&& rval, const std::string& etalon)
    {
        std::string dst = std::move(rval);
        ASSERT_TRUE(dst == etalon);
    }

} // namespace
//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    foo("111", "111");
}

TEST_COMPONENT(001)
{
    int v = 0;
    int&& rv = std::move(v);
    ASSERT_TRUE(rv == 0);
}

#endif // !dHAS_RVALUE_REFERENCES

//==============================================================================
//==============================================================================

#endif // !TEST_TOOLS_FEATURE_RVALUE_REFERENCE

