// [2021y-05m-04d][21:27:57] Idrisov Denis R.
#pragma once
#include <cstddef>

//==============================================================================
//=== [first unit-tests] =======================================================
namespace test_access
{
    #ifdef dTEST_SFINAE_REGULAR
        struct Maket;
        struct Dummy {};
        struct Mutable { void operator[](const size_t); };
        struct Const   { void operator[](const size_t) const; };
        struct Container
        {
            void operator[](const size_t);
            void operator[](const size_t) const;
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
            void operator[](const size_t);
        public:
            PMutable();
        };
        class PConst
        {
            void operator[](const size_t) const;
        public:
            PConst();
        };
        class PContainer
        {
            void operator[](const size_t) ;
            void operator[](const size_t) const;
        public:
            PContainer();
        };
    #endif // defined(dTEST_SFINAE_PRIVATE) || defined(dTEST_SFINAE_DPRVATE)

    #ifdef dTEST_SFINAE_DPRVATE
        struct DPMutable   : PMutable   {};
        struct DPConst     : PConst     {};
        struct DPContainer : PContainer {};
    #endif // dTEST_SFINAE_DPRVATE
} // namespace test_access

//==============================================================================
//=== [ recursieve containers ] ================================================
namespace test_access
{
    #ifdef dTEST_SFINAE_RECURSIEVE
        struct RMutable 
        {
            RMutable operator[](const size_t);
        };
        struct RConst 
        {
            RConst operator[](const size_t) const;
        };
        struct RContainer
        {
            RContainer operator[](const size_t) ;
            RContainer operator[](const size_t) const;
        };
    #endif // dTEST_SFINAE_RECURSIEVE

    #ifdef dTEST_SFINAE_DRECURSIEVE
        struct DRMutable   : RMutable   {};
        struct DRConst     : RConst     {};
        struct DRContainer : RContainer {};
    #endif // dTEST_SFINAE_DRECURSIEVE

    #if defined(dTEST_SFINAE_PRECURSIEVE) || defined(dTEST_SFINAE_DPRECURSIEVE)
        class PRMutable 
        {
            PRMutable operator[](const size_t);
        public:
            PRMutable();
        };
        class PRConst
        {
            PRConst operator[](const size_t) const;
        public:
            PRConst();
        };
        class PRContainer
        {
            PRContainer operator[](const size_t) ;
            PRContainer operator[](const size_t) const;
        public:
            PRContainer();
        };
    #endif // defined(dTEST_SFINAE_PRECURSIEVE) || defined(dTEST_SFINAE_DPRECURSIEVE)

    #ifdef dTEST_SFINAE_DPRECURSIEVE
        struct DPRMutable   : PRMutable   {};
        struct DPRConst     : PRConst     {};
        struct DPRContainer : PRContainer {};
    #endif // dTEST_SFINAE_DPRECURSIEVE
} // namespace test_access

//==============================================================================
//=== [ unsuitable containers ] ================================================
namespace test_access
{
    struct index;

    #ifdef dTEST_SFINAE_UNSUITABLE
        struct UnsuitableMutable
        {
             void operator[](const index&); 
        };
        struct UnsuitableConst
        {
             void operator[](const index&) const; 
        };
        struct Unsuitable
        {
             void operator[](const index&) ; 
             void operator[](const index&) const; 
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
             void operator[](const index&);
        public:
            PUnsuitableMutable();
        };
        class PUnsuitableConst
        {
             void operator[](const index&) const; 
        public:
            PUnsuitableConst();
        };
        class PUnsuitable
        {
             void operator[](const index&) ; 
             void operator[](const index&) const; 
        public:
            PUnsuitable();
        };
    #endif // defined(dTEST_SFINAE_PUNSUITABLE) || defined(dTEST_SFINAE_DPUNSUITABLE)

    #ifdef dTEST_SFINAE_DPUNSUITABLE
        struct DPUnsuitableMutable : PUnsuitableMutable {};
        struct DPUnsuitableConst   : PUnsuitableConst   {};
        struct DPUnsuitable        : PUnsuitable        {};
    #endif
} // namespace test_access

//==============================================================================
//=== [ return int ] ===========================================================
namespace test_access
{
    #ifdef dTEST_SFINAE_INT
        struct IntMutable
        {
             int operator[](const size_t); 
        };
        struct IntConst
        {
             int operator[](const size_t) const; 
        };
        struct Int
        {
             int operator[](const size_t) ; 
             int operator[](const size_t) const; 
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
             int operator[](const size_t); 
        public:
            PIntMutable();
        };
        class PIntConst
        {
             int operator[](const size_t) const; 
        public:
            PIntConst();
        };
        class PInt
        {
             int operator[](const size_t) ; 
             int operator[](const size_t) const; 
        public:
            PInt();
        };
    #endif // defined(dTEST_SFINAE_PINT) || defined(dTEST_SFINAE_DPINT)

    #ifdef dTEST_SFINAE_DPINT
        struct DPIntMutable : PIntMutable {};
        struct DPIntConst   : PIntConst   {};
        struct DPInt        : PInt        {};
    #endif

} // namespace test_access

//==============================================================================
//=== [ return body ] ==========================================================
namespace test_access
{
    #ifdef dTEST_SFINAE_BODY
        struct BodyMutable 
        {
            double operator[](const size_t); 
            char buf[300]; 
        };
        struct BodyConst   
        {
            double operator[](const size_t) const; 
            char buf[300]; 
        };
        struct Body
        {
            double operator[](const size_t);
            double operator[](const size_t) const;
            char buf[300]; 
        };
    #endif // dTEST_SFINAE_BODY

    #ifdef dTEST_SFINAE_DBODY
        struct DBodyMutable : BodyMutable {};
        struct DBodyConst   : BodyConst   {};
        struct DBody        : Body        {};
    #endif // dTEST_SFINAE_DBODY

    #if defined(dTEST_SFINAE_PBODY) || defined(dTEST_SFINAE_DPRVATE)
        class PBodyMutable 
        {
            double operator[](const size_t);
            char buf[300]; 
        public:
            PBodyMutable();
        };
        class PBodyConst
        {
            double operator[](const size_t) const;
            char buf[300]; 
        public:
            PBodyConst();
        };
        class PBody
        {
            double operator[](const size_t) ;
            double operator[](const size_t) const;
            char buf[300]; 
        public:
            PBody();
        };
    #endif // defined(dTEST_SFINAE_PRIVATE) || defined(dTEST_SFINAE_DPRVATE)

    #ifdef dTEST_SFINAE_DPBODY
        struct DPBodyMutable : PBodyMutable {};
        struct DPBodyConst   : PBodyConst   {};
        struct DPBody        : PBody        {};
    #endif // dTEST_SFINAE_DPBODY

} // namespace test_access

using namespace test_access;
//==============================================================================
//==============================================================================

