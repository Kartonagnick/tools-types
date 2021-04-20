// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2020y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-26d][01:24:02] Idrisov Denis R.
// [2021y-04m-03d][19:13:13] Idrisov Denis R. 2
// [2021y-04m-20d][22:31:51] Idrisov Denis R. 3 PRE
//==============================================================================
#pragma once
#ifndef dTOOLS_VARIADIC_NEW_USED_ 
#define dTOOLS_VARIADIC_NEW_USED_ 3 PRE

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_heir ==================================================================
#ifndef dTOOLS_IS_HEIR_USED_ 
#define dTOOLS_IS_HEIR_USED_ 3, 2010  PRE
namespace tools
{
    struct dummy;

    namespace detail
    {
        template <class... args>
            struct is_heir_;

        template <class a> struct is_heir_<a>
            { enum { value = false }; };

        template <class b, class d, class... args>
        struct is_heir_<b, d, args...>
        {
            using bb  = ::std::decay_t<b>;
            using dd  = ::std::decay_t<d>;
            using xx  = ::std::is_base_of<bb,dd>;
            enum { v1 = sizeof...(args) == 0 };
            enum { value = v1 && xx::value };
        };

        template<class ...args> 
        using if_variadic_t
            = ::std::enable_if_t< 
                !::tools::detail::is_heir_<args...>::value, 
                ::tools::dummy*
            >;

    } // namespace detail

    template<class... args>
    struct is_heir
        : dDETAIL_CONSTANT(is_heir_<args...>)
    {};

} // namespace tools
#endif //!dTOOLS_IS_HEIR_USED_

//==============================================================================
//==============================================================================

#define dTEMPLATE_CONSTRUCT(type, args)       \
    typename t = ::std::enable_if_t<          \
        !::tools::is_heir<type, args>::value  \
    >

#define dTEMPLATE_CONSTRUCT_IMPL(type, args)  \
    typename ::tools::detail::if_variadic_t<  \
        type, args                            \
    >

#define dTEMPLATE_CONSTRUCT_ARG(type, args)   \
    dTEMPLATE_CONSTRUCT_IMPL(type, args)      \
      = nullptr

//==============================================================================
//==============================================================================
#endif //!dTOOLS_VARIADIC_NEW_USED_


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

