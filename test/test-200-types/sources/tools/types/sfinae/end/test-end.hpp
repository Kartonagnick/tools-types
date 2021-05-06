// [2021y-05m-04d][16:34:05] Idrisov Denis R.
#pragma once
#include <tools/features.hpp>

//==============================================================================
//=== [first unit-tests] =======================================================
namespace test_end
{
    #ifdef dTEST_SFINAE_REGULAR
        struct Maket;
        struct Dummy {};
        struct Mutable { void end(); };
        struct Const   { void end() const; };
        struct Container
        {
            void end();
            void end() const;
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
            void end();
        public:
            PMutable();
        };
        class PConst
        {
            void end() const;
        public:
            PConst();
        };
        class PContainer
        {
            void end() ;
            void end() const;
        public:
            PContainer();
        };
    #endif // defined(dTEST_SFINAE_PRIVATE) || defined(dTEST_SFINAE_DPRVATE)

    #ifdef dTEST_SFINAE_DPRVATE
        struct DPMutable   : PMutable   {};
        struct DPConst     : PConst     {};
        struct DPContainer : PContainer {};
    #endif // dTEST_SFINAE_DPRVATE
} // namespace test_end

//==============================================================================
//=== [ recursieve containers ] ================================================
namespace test_end
{
    #ifdef dTEST_SFINAE_RECURSIEVE
        struct RMutable 
        {
            RMutable end();
        };
        struct RConst 
        {
            RConst end() const;
        };
        struct RContainer
        {
            RContainer end() ;
            RContainer end() const;
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
            PRMutable end();
        public:
            PRMutable();
        };
        class PRConst
        {
            PRConst end() const;
        public:
            PRConst();
        };
        class PRContainer
        {
            PRContainer end() ;
            PRContainer end() const;
        public:
            PRContainer();
        };
    #endif // defined(dTEST_SFINAE_PRECURSIEVE) || defined(dTEST_SFINAE_DPRECURSIEVE)

    #ifdef dTEST_SFINAE_DPRECURSIEVE
        struct DPRMutable   : PRMutable   {};
        struct DPRConst     : PRConst     {};
        struct DPRContainer : PRContainer {};
    #endif // dTEST_SFINAE_DPRECURSIEVE
} // namespace test_end

//==============================================================================
//=== [ unsuitable containers ] ================================================
namespace test_end
{
    #ifdef dTEST_SFINAE_UNSUITABLE
        struct UnsuitableMutable
        {
             void end(int); 
        };
        struct UnsuitableConst
        {
             void end(int) const; 
        };
        struct Unsuitable
        {
             void end(int) ; 
             void end(int) const; 
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
             void end(int); 
        public:
            PUnsuitableMutable();
        };
        class PUnsuitableConst
        {
             void end(int) const; 
        public:
            PUnsuitableConst();
        };
        class PUnsuitable
        {
             void end(int) ; 
             void end(int) const; 
        public:
            PUnsuitable();
        };
    #endif // defined(dTEST_SFINAE_PUNSUITABLE) || defined(dTEST_SFINAE_DPUNSUITABLE)

    #ifdef dTEST_SFINAE_DPUNSUITABLE
        struct DPUnsuitableMutable : PUnsuitableMutable {};
        struct DPUnsuitableConst   : PUnsuitableConst   {};
        struct DPUnsuitable        : PUnsuitable        {};
    #endif
} // namespace test_end

//==============================================================================
//=== [ return int ] ===========================================================
namespace test_end
{
    #ifdef dTEST_SFINAE_INT
        struct IntMutable
        {
             int end(); 
        };
        struct IntConst
        {
             int end() const; 
        };
        struct Int
        {
             int end() ; 
             int end() const; 
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
             int end(); 
        public:
            PIntMutable();
        };
        class PIntConst
        {
             int end() const; 
        public:
            PIntConst();
        };
        class PInt
        {
             int end() ; 
             int end() const; 
        public:
            PInt();
        };
    #endif // defined(dTEST_SFINAE_PINT) || defined(dTEST_SFINAE_DPINT)

    #ifdef dTEST_SFINAE_DPINT
        struct DPIntMutable : PIntMutable {};
        struct DPIntConst   : PIntConst   {};
        struct DPInt        : PInt        {};
    #endif

} // namespace test_end

//==============================================================================
//=== [ return body ] ==========================================================
namespace test_end
{
    #ifdef dTEST_SFINAE_BODY
        struct BodyMutable 
        {
            double end(); 
            char buf[300]; 
        };
        struct BodyConst   
        {
            double end() const; 
            char buf[300]; 
        };
        struct Body
        {
            double end();
            double end() const;
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
            double end();
            char buf[300]; 
        public:
            PBodyMutable();
        };
        class PBodyConst
        {
            double end() const;
            char buf[300]; 
        public:
            PBodyConst();
        };
        class PBody
        {
            double end() ;
            double end() const;
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

} // namespace test_end

using namespace test_end;
//==============================================================================
//==============================================================================

