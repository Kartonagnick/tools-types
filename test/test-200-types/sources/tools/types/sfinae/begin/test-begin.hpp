// [2021y-05m-02d][22:23:34] Idrisov Denis R.
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
#endif

//==============================================================================
//=== [first unit-tests] =======================================================
namespace
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

    #ifdef dTEST_SFINAE_PRIVATE
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
    #endif // dTEST_SFINAE_PRIVATE

    #ifdef dTEST_SFINAE_DPRVATE
        struct DPMutable   : PMutable   {};
        struct DPConst     : PConst     {};
        struct DPContainer : PContainer {};
    #endif // dTEST_SFINAE_DPRVATE
} // namespace

//==============================================================================
//=== [ recursieve containers ] ================================================
namespace
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

    #ifdef dTEST_SFINAE_PRECURSIEVE
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
    #endif // dTEST_SFINAE_PRECURSIEVE

    #ifdef dTEST_SFINAE_DPRECURSIEVE
        struct DPRMutable   : PRMutable   {};
        struct DPRConst     : PRConst     {};
        struct DPRContainer : PRContainer {};
    #endif // dTEST_SFINAE_DPRECURSIEVE
} // namespace

//==============================================================================
//=== [ unsuitable containers ] ================================================
namespace
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

    #ifdef dTEST_SFINAE_UNSUITABLE
        struct DUnsuitableMutable : UnsuitableMutable {};
        struct DUnsuitableConst   : UnsuitableConst   {};
        struct DUnsuitable        : Unsuitable        {};
    #endif // dTEST_SFINAE_DUNSUITABLE

    #ifdef dTEST_SFINAE_PUNSUITABLE
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
    #endif // dTEST_SFINAE_PUNSUITABLE

    #ifdef dTEST_SFINAE_DPUNSUITABLE
        struct DPUnsuitableMutable : PUnsuitableMutable {};
        struct DPUnsuitableConst   : PUnsuitableConst   {};
        struct DPUnsuitable        : PUnsuitable        {};
    #endif
} // namespace

//==============================================================================
//==============================================================================

