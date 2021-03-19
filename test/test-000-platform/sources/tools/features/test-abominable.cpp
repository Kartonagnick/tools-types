// [2021y-02m-26d][06:07:32] Idrisov Denis R.
#include <mygtest/modern.hpp>
//=================================================================================
//=================================================================================

#ifdef TEST_TOOLS_FEATURE_ABOMINABLE

#define dTEST_COMPONENT tools, features
#define dTEST_METHOD test_HAS_ABOMINABLE
#define dTEST_TAG tdd

#include <tools/features.hpp>

#ifdef dHAS_ABOMINABLE
    dMESSAGE("[test] tools: enabled -> dHAS_ABOMINABLE")
#else
    dMESSAGE("[test] tools: disabled -> dHAS_ABOMINABLE")
#endif

//==============================================================================
//==============================================================================
namespace
{
    #if dHAS_ABOMINABLE

    typedef void func() const;
    struct some
    {
        some()
        {
        }

        void foo() const 
        {
            dprint(std::cout << __func__ << '\n');
        }

        func m_method;
    };

    func some::*m_method =  &some::foo;

    #endif

} // namespace


#if dHAS_ABOMINABLE
TEST_COMPONENT(000)
{
    some s;
    (s.*m_method)();
}
#endif

//==============================================================================
//==============================================================================
#endif // ! TEST_TOOLS_FEATURE_ABOMINABLE



