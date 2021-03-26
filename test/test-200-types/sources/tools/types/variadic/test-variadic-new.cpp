// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2020y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-25d][23:23:05] Idrisov Denis R.
#include <mygtest/test-list.hpp>

#ifdef TEST_TOOLS_VARIADIC

#include <tools/features.hpp>
#ifdef dHAS_VARIADIC_TEMPLATE

#include <tools/types/variadic.hpp>
#include <utility>

#define TEST_CASE_NAME tools
#define TEST_NUMBER(n) variadic_##n

namespace me = ::TEST_CASE_NAME;
//==============================================================================
//==============================================================================

#ifdef _MSC_VER
    // msvc2013: false alarm
    // warning C4520: '`anonymous-namespace'::example' : multiple default constructors specified
    #pragma warning(disable : 4520)
#endif
 
#ifdef __GNUC__
    #if __GNUC__ >= 9
        // this is gcc 9.0 or greater
        // moving a local object in a return statement prevents copy elision
        // example: return std::move(obj);
        #pragma GCC diagnostic ignored "-Wpessimizing-move"
    #endif
#endif

//==============================================================================
//=== TDD ======================================================================
namespace
{
    enum eCTOR{ eDEFAULT, eCOPY, eRVALUE, eTEMPLATE, eVARIADIC };

    struct example
    {
        template<typename... Args, dTEMPLATE_CONSTRUCT(example, Args...)>
        example(Args&&...): m_ctor(eVARIADIC)
        { 
            // dprint(::std::cout <<  "variadic\n");
        }
    
        template<typename Arg, dTEMPLATE_CONSTRUCT(example, Arg)>
        example(Arg&&): m_ctor(eTEMPLATE)
        {
            // dprint(::std::cout <<  "template\n");
        }

        example(): m_ctor(eDEFAULT)
        { 
            // dprint(::std::cout <<  "default\n"); 
        }

        example(const example&): m_ctor(eCOPY)
        { 
            // dprint(::std::cout <<  "copy\n"); 
        }

        example(example&&): m_ctor(eRVALUE)
        {
            // dprint(::std::cout <<  "move\n"); 
        }

        eCTOR m_ctor;
    };

    struct der: example
    {
        der(): example(){}
        der(const int a): example(a){}
        der(const int a, const int b): example(a, b){}
        der(const der& a, const int b): example(a, b){}
        der(const example& a, const int b): example(a, b){}
        der(const der& rhs): example(rhs){}
        der(der&& rhs): example(::std::move(rhs)){}

        template<typename... Args, dTEMPLATE_CONSTRUCT(der, Args...)>
        der(Args&&...args)
            : example( ::std::forward<Args>(args)... )
        {}
    };

    der rvalue() 
    { 
        // moving a local object in a return statement prevents copy elision
        // #pragma GCC diagnostic ignored "-Wpessimizing-move"
        der d;
        return ::std::move(d);
    }

    struct der2: example
    {
        der2():example(){}
        der2(const int a):example(a){}
        der2(const int a, const int b):example(a,b){}
        der2(const der2& a, const int b):example(a,b){}
        der2(const example& a, const int b):example(a,b){}
        der2(const der2& rhs):example(rhs){}
        der2(der2&& rhs):example(::std::move(rhs)){}

        template<typename... Args, dTEMPLATE_CONSTRUCT(der2, Args...)>
            der2(Args&&...args);
    };

    template<typename... Args, typename>
    der2::der2(Args&&...args)
        : example(::std::forward<Args>(args)...)
    {}

    der2 rvalue2() 
    { 
        // moving a local object in a return statement prevents copy elision
        // #pragma GCC diagnostic ignored "-Wpessimizing-move"
        der2 d;
        return ::std::move(d);
    }

} // namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    der d0;
    ASSERT_TRUE(d0.m_ctor == eDEFAULT);
                             
    der d1(10,20);           
    ASSERT_TRUE(d1.m_ctor == eVARIADIC);
                             
    der d2(10);              
    ASSERT_TRUE(d2.m_ctor == eTEMPLATE);

    der d3(d1); 
    ASSERT_TRUE(d3.m_ctor == eCOPY);
                             
    der d4 = rvalue();       
    ASSERT_TRUE(d4.m_ctor == eRVALUE);
}
TEST_COMPONENT(001)
{
    der d;
    der d1(d, 10);
    ASSERT_TRUE(d1.m_ctor == eVARIADIC);
}
TEST_COMPONENT(002)
{
    der d;
    der d1(d, d);
    ASSERT_TRUE(d1.m_ctor == eVARIADIC);
}
TEST_COMPONENT(003)
{
    der2 d0;
    ASSERT_TRUE(d0.m_ctor == eDEFAULT);
                             
    der2 d1(10, 20);          
    ASSERT_TRUE(d1.m_ctor == eVARIADIC);
                             
    der2 d2(10);             
    ASSERT_TRUE(d2.m_ctor == eTEMPLATE);
                             
    der2 d3 = d1;            
    ASSERT_TRUE(d3.m_ctor == eCOPY);
                             
    der2 d4 = rvalue2();     
    ASSERT_TRUE(d4.m_ctor == eRVALUE);
}                            
TEST_COMPONENT(004)
{
    der2 d;
    der2 d1(d, 10);
    ASSERT_TRUE(d1.m_ctor == eVARIADIC);
}
TEST_COMPONENT(005)
{
    der2 d;
    der2 d1(d, d);
    ASSERT_TRUE(d1.m_ctor == eVARIADIC);
}

TEST_COMPONENT(006)
{
    example e;
    ASSERT_TRUE(e.m_ctor == eDEFAULT);

    der d(e);
    ASSERT_TRUE(d.m_ctor == eCOPY);
}

//==============================================================================
//==============================================================================
#endif // !dHAS_VARIADIC_TEMPLATE
#endif // !TEST_TOOLS_VARIADIC

