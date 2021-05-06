// [2021y-05m-02d][22:23:34] Idrisov Denis R.
#pragma once
#include <tools/features.hpp>

//==============================================================================
//=== [first unit-tests] =======================================================
namespace test_begin
{
    #ifdef dTEST_SFINAE_REGULAR
        struct Maket;
        struct Dummy {};
        struct Mutable { void begin(); };
        struct Const   { void begin() const; };
        struct Container
        {
            void begin();
            void begin() const;
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
            void begin();
        public:
            PMutable();
        };
        class PConst
        {
            void begin() const;
        public:
            PConst();
        };
        class PContainer
        {
            void begin() ;
            void begin() const;
        public:
            PContainer();
        };
    #endif // defined(dTEST_SFINAE_PRIVATE) || defined(dTEST_SFINAE_DPRVATE)

    #ifdef dTEST_SFINAE_DPRVATE
        struct DPMutable   : PMutable   {};
        struct DPConst     : PConst     {};
        struct DPContainer : PContainer {};
    #endif // dTEST_SFINAE_DPRVATE
} // namespace test_begin

//==============================================================================
//=== [ recursieve containers ] ================================================
namespace test_begin
{
    #ifdef dTEST_SFINAE_RECURSIEVE
        struct RMutable 
        {
            RMutable begin();
        };
        struct RConst 
        {
            RConst begin() const;
        };
        struct RContainer
        {
            RContainer begin() ;
            RContainer begin() const;
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
            PRMutable begin();
        public:
            PRMutable();
        };
        class PRConst
        {
            PRConst begin() const;
        public:
            PRConst();
        };
        class PRContainer
        {
            PRContainer begin() ;
            PRContainer begin() const;
        public:
            PRContainer();
        };
    #endif // defined(dTEST_SFINAE_PRECURSIEVE) || defined(dTEST_SFINAE_DPRECURSIEVE)

    #ifdef dTEST_SFINAE_DPRECURSIEVE
        struct DPRMutable   : PRMutable   {};
        struct DPRConst     : PRConst     {};
        struct DPRContainer : PRContainer {};
    #endif // dTEST_SFINAE_DPRECURSIEVE
} // namespace test_begin

//==============================================================================
//=== [ unsuitable containers ] ================================================
namespace test_begin
{
    #ifdef dTEST_SFINAE_UNSUITABLE
        struct UnsuitableMutable
        {
             void begin(int); 
        };
        struct UnsuitableConst
        {
             void begin(int) const; 
        };
        struct Unsuitable
        {
             void begin(int) ; 
             void begin(int) const; 
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
             void begin(int); 
        public:
            PUnsuitableMutable();
        };
        class PUnsuitableConst
        {
             void begin(int) const; 
        public:
            PUnsuitableConst();
        };
        class PUnsuitable
        {
             void begin(int) ; 
             void begin(int) const; 
        public:
            PUnsuitable();
        };
    #endif // defined(dTEST_SFINAE_PUNSUITABLE) || defined(dTEST_SFINAE_DPUNSUITABLE)

    #ifdef dTEST_SFINAE_DPUNSUITABLE
        struct DPUnsuitableMutable : PUnsuitableMutable {};
        struct DPUnsuitableConst   : PUnsuitableConst   {};
        struct DPUnsuitable        : PUnsuitable        {};
    #endif
} // namespace test_begin

//==============================================================================
//=== [ return int ] ===========================================================
namespace test_begin
{
    #ifdef dTEST_SFINAE_INT
        struct IntMutable
        {
             int begin(); 
        };
        struct IntConst
        {
             int begin() const; 
        };
        struct Int
        {
             int begin() ; 
             int begin() const; 
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
             int begin(); 
        public:
            PIntMutable();
        };
        class PIntConst
        {
             int begin() const; 
        public:
            PIntConst();
        };
        class PInt
        {
             int begin() ; 
             int begin() const; 
        public:
            PInt();
        };
    #endif // defined(dTEST_SFINAE_PINT) || defined(dTEST_SFINAE_DPINT)

    #ifdef dTEST_SFINAE_DPINT
        struct DPIntMutable : PIntMutable {};
        struct DPIntConst   : PIntConst   {};
        struct DPInt        : PInt        {};
    #endif

} // namespace test_begin

//==============================================================================
//=== [ return body ] ==========================================================
namespace test_begin
{
    #ifdef dTEST_SFINAE_BODY
        struct BodyMutable 
        {
            double begin(); 
            char buf[300]; 
        };
        struct BodyConst   
        {
            double begin() const; 
            char buf[300]; 
        };
        struct Body
        {
            double begin();
            double begin() const;
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
            double begin();
            char buf[300]; 
        public:
            PBodyMutable();
        };
        class PBodyConst
        {
            double begin() const;
            char buf[300]; 
        public:
            PBodyConst();
        };
        class PBody
        {
            double begin() ;
            double begin() const;
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

} // namespace test_begin

using namespace test_begin;
//==============================================================================
//==============================================================================

