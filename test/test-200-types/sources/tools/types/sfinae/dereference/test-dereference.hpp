// [2021y-05m-05d][23:02:09] Idrisov Denis R.
#pragma once
#include <tools/features.hpp>

#if 0
#define dTEST_SFINAE_REGULAR       1
#define dTEST_SFINAE_DERIVED       1
#define dTEST_SFINAE_PRIVATE       1
#define dTEST_SFINAE_DPRVATE       1

#define dTEST_SFINAE_RECURSIEVE    1
#define dTEST_SFINAE_DRECURSIEVE   1
#define dTEST_SFINAE_PRECURSIEVE   1
#define dTEST_SFINAE_DPRECURSIEVE  1

#define dTEST_SFINAE_UNSUITABLE    1
#define dTEST_SFINAE_DUNSUITABLE   1
#define dTEST_SFINAE_PUNSUITABLE   1
#define dTEST_SFINAE_DPUNSUITABLE  1

#define dTEST_SFINAE_INT           1
#define dTEST_SFINAE_DINT          1
#define dTEST_SFINAE_PINT          1
#define dTEST_SFINAE_DPINT         1
#endif

//==============================================================================
//=== [first unit-tests] =======================================================
namespace test_dereference
{
    #ifdef dTEST_SFINAE_REGULAR
        struct Maket;
        struct Dummy   
        { 
            char buf[255]; 
        };
        struct Mutable 
        {
            double operator*(); 
            char buf[255]; 
        };
        struct Const   
        {
            double operator*() const; 
            char buf[255]; 
        };
        struct Container
        {
            double operator*();
            double operator*() const;
            char buf[255]; 
        };
    #endif // dTEST_SFINAE_REGULAR

    #ifdef dTEST_SFINAE_DERIVED
        struct DMutable   : Mutable   {};
        struct DConst     : Const     {};
        struct DContainer : Container {};
    #endif // dTEST_SFINAE_DERIVED

    #if defined(dTEST_SFINAE_PRIVATE) || defined(dTEST_SFINAE_DPRVATE)
        class PMutable 
        {
            double operator*();
            char buf[255]; 
        public:
            PMutable();
        };
        class PConst
        {
            double operator*() const;
            char buf[255]; 
        public:
            PConst();
        };
        class PContainer
        {
            double operator*() ;
            double operator*() const;
            char buf[255]; 
        public:
            PContainer();
        };
    #endif // defined(dTEST_SFINAE_PRIVATE) || defined(dTEST_SFINAE_DPRVATE)

    #ifdef dTEST_SFINAE_DPRVATE
        struct DPMutable   : PMutable   {};
        struct DPConst     : PConst     {};
        struct DPContainer : PContainer {};
    #endif // dTEST_SFINAE_DPRVATE
} // namespace test_dereference

//==============================================================================
//=== [ recursieve containers ] ================================================
namespace test_dereference
{
    //#ifdef dTEST_SFINAE_RECURSIEVE
        struct RMutable 
        {
            RMutable operator*();
            char buf[255]; 
        };
        struct RConst 
        {
            RConst operator*() const;
            char buf[255]; 
        };
        struct RContainer
        {
            RContainer operator*() ;
            RContainer operator*() const;
            char buf[255]; 
        };
    //#endif // dTEST_SFINAE_RECURSIEVE

    //#ifdef dTEST_SFINAE_DRECURSIEVE
        struct DRMutable   : RMutable   {};
        struct DRConst     : RConst     {};
        struct DRContainer : RContainer {};
    //#endif // dTEST_SFINAE_DRECURSIEVE

    #if defined(dTEST_SFINAE_PRECURSIEVE) || defined(dTEST_SFINAE_DPRECURSIEVE)
        class PRMutable 
        {
            char buf[255]; 
            PRMutable operator*();
        public:
            PRMutable();
        };
        class PRConst
        {
            char buf[255]; 
            PRConst operator*() const;
        public:
            PRConst();
        };
        class PRContainer
        {
            char buf[255]; 
            PRContainer operator*() ;
            PRContainer operator*() const;
        public:
            PRContainer();
        };
    #endif // defined(dTEST_SFINAE_PRECURSIEVE) || defined(dTEST_SFINAE_DPRECURSIEVE)

    #ifdef dTEST_SFINAE_DPRECURSIEVE
        struct DPRMutable   : PRMutable   {};
        struct DPRConst     : PRConst     {};
        struct DPRContainer : PRContainer {};
    #endif // dTEST_SFINAE_DPRECURSIEVE
} // namespace test_dereference

//==============================================================================
//=== [ unsuitable containers ] ================================================
namespace test_dereference
{
    #ifdef dTEST_SFINAE_UNSUITABLE
        struct UnsuitableMutable
        {
            char buf[255]; 
            double operator*(int); 
        };
        struct UnsuitableConst
        {
            char buf[255]; 
            double operator*(int) const; 
        };
        struct Unsuitable
        {
            char buf[255]; 
            double operator*(int) ; 
            double operator*(int) const; 
        };
    #endif // dTEST_SFINAE_UNSUITABLE

    #ifdef dTEST_SFINAE_DUNSUITABLE
        struct DUnsuitableMutable : UnsuitableMutable {};
        struct DUnsuitableConst   : UnsuitableConst   {};
        struct DUnsuitable        : Unsuitable        {};
    #endif // dTEST_SFINAE_DUNSUITABLE

    #if defined(dTEST_SFINAE_PUNSUITABLE) || defined(dTEST_SFINAE_DPUNSUITABLE)
        class PUnsuitableMutable
        {
            char buf[255]; 
            double operator*(int); 
        public:
            PUnsuitableMutable();
        };
        class PUnsuitableConst
        {
            char buf[255]; 
            double operator*(int) const; 
        public:
            PUnsuitableConst();
        };
        class PUnsuitable
        {
            char buf[255]; 
            double operator*(int) ; 
            double operator*(int) const; 
        public:
            PUnsuitable();
        };
    #endif // defined(dTEST_SFINAE_PUNSUITABLE) || defined(dTEST_SFINAE_DPUNSUITABLE)

    #ifdef dTEST_SFINAE_DPUNSUITABLE
        struct DPUnsuitableMutable : PUnsuitableMutable {};
        struct DPUnsuitableConst   : PUnsuitableConst   {};
        struct DPUnsuitable        : PUnsuitable        {};
    #endif
} // namespace test_dereference

//==============================================================================
//=== [ return int ] ===========================================================
namespace test_dereference
{
    #ifdef dTEST_SFINAE_INT
        struct IntMutable
        {
            char buf[255]; 
            int operator*(); 
        };
        struct IntConst
        {
            char buf[255]; 
            int operator*() const; 
        };
        struct Int
        {
            char buf[255]; 
            int operator*() ; 
            int operator*() const; 
        };
    #endif // dTEST_SFINAE_INT

    #ifdef dTEST_SFINAE_DINT
        struct DIntMutable : IntMutable {};
        struct DIntConst   : IntConst   {};
        struct DInt        : Int        {};
    #endif // dTEST_SFINAE_DUNSUITABLE

    #if defined(dTEST_SFINAE_PINT) || defined(dTEST_SFINAE_DPINT)
        class PIntMutable
        {
            char buf[255]; 
            int operator*(); 
        public:
            PIntMutable();
        };
        class PIntConst
        {
            char buf[255]; 
            int operator*() const; 
        public:
            PIntConst();
        };
        class PInt
        {
            char buf[255]; 
            int operator*() ; 
            int operator*() const; 
        public:
            PInt();
        };
    #endif // defined(dTEST_SFINAE_PINT) || defined(dTEST_SFINAE_DPINT)

    #ifdef dTEST_SFINAE_DPINT
        struct DPIntMutable : PIntMutable {};
        struct DPIntConst   : PIntConst   {};
        struct DPInt        : PInt        {};
    #endif

} // namespace test_dereference

using namespace test_dereference;
//==============================================================================
//==============================================================================

