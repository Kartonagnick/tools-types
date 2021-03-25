// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2020y-02m-20d][18:40:18] Idrisov Denis R.
//==============================================================================
#pragma once
#ifndef dTOOLS_VARIADIC_USED_ 
#define dTOOLS_VARIADIC_USED_ 1

#include <type_traits>

//==============================================================================
//==============================================================================
namespace tools
{
    namespace detail 
    {
        template <class... Args> 
            struct template_check;

        template <class Arg> struct template_check<Arg>
        {
            enum { value = false }; 
        };

        template <class Base, class Derrived>
        struct template_check<Base, Derrived>
        {
            using base     
                = typename ::std::decay<Base>::type;

            using derrived
                = typename ::std::decay<Derrived>::type;

            using x = ::std::is_base_of<base, derrived>;

            enum { value = x::value };
        };

        template <class A, class B, class... Args>
        struct template_check<A, B, Args...>
        {
            enum { value = true };
        };

    } // namespace detail 

} // namespace tools

//==============================================================================
//==============================================================================

#define dTEMPLATE_CONSTRUCT(type, arg)    \
    typename = ::std::enable_if_t<        \
        !::tools::detail::template_check< \
            type, arg                     \
        >::value                          \
    >*

//==============================================================================
//==============================================================================
#endif //!dTOOLS_VARIADIC_USED_


#if 0
// USAGE:

#include<cassert>
#include<iostream>

enum eCTOR{ eDEFAULT, eCOPY, eRVALUE, eTEMPLATE, eVARIADIC };
struct example
{
    template<typename... args, dTEMPLATE_CONSTRUCT(example, args...)>
    example(args&&...):m_ctor(eVARIADIC)
        { std::cout << "variadic\n"; }
    
    template<typename args, dTEMPLATE_CONSTRUCT(example, args)>
    example(args&&):m_ctor(eTEMPLATE)
        { std::cout << "template\n"; }

    example():m_ctor(eDEFAULT)
        { std::cout << "default\n"; }

    example(const example&):m_ctor(eCOPY)
        { std::cout << "copy\n"; }

    example(example&&):m_ctor(eRVALUE)
        { std::cout << "move\n"; }

    eCTOR m_ctor;
};

struct der: example
{
    der():example(){}
    der(const int a):example(a){}
    der(const int a, const int b):example(a,b){}
    der(const der& a, const int b):example(a,b){}
    der(const example& a, const int b):example(a,b){}
    der(const der& rhs):example(rhs){}
    der(der&& rhs):example(std::move(rhs)){}
};

der rvalue() {  return std::move(der(10)); }


int main()
{
    // output:
    //   default
    //   variadic
    //   template
    //   copy
    //   template
    //   move
    //   default
    //   variadic    
    //   default
    //   variadic        

    der d0;
    assert(d0.m_ctor==eDEFAULT);

    der d1(10,20);
    assert(d1.m_ctor==eVARIADIC);

    der d2(10);
    assert(d2.m_ctor==eTEMPLATE);
    
    der d3 = d1;
    assert(d3.m_ctor==eCOPY);

    der d4 = rvalue();
    assert(d4.m_ctor==eRVALUE);
    
    der d5( der{}, 10);
    assert(d5.m_ctor==eVARIADIC);
    
    der d6( example{}, 10);
    assert(d6.m_ctor==eVARIADIC);
}
#endif

