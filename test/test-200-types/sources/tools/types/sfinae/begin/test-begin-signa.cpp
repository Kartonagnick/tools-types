// [2021y-04m-29d][12:21:22] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_BEGIN
#define dTEST_COMPONENT tools, types, sfinae, signature
#define dTEST_METHOD begin
#define dTEST_TAG tdd

//==============================================================================
//==============================================================================

#include <tools/features.hpp>

#ifdef dHAS_CPP11
    // msvc2015 or newer 
    #define dTEST_SFINAE_REGULAR          1
    #define dTEST_SFINAE_DERIVED          1
    #define dTEST_SFINAE_PRIVATE          1
    #define dTEST_SFINAE_DPRVATE          1
                                          
    #define dTEST_SFINAE_RECURSIEVE       1
    #define dTEST_SFINAE_DRECURSIEVE      1
    #define dTEST_SFINAE_PRECURSIEVE      1
    #define dTEST_SFINAE_DPRECURSIEVE     1
                                          
    #define dTEST_SFINAE_UNSUITABLE       1
    #define dTEST_SFINAE_DUNSUITABLE      1
    #define dTEST_SFINAE_PUNSUITABLE      1
    #define dTEST_SFINAE_DPUNSUITABLE     1

    #define dTEST_SFINAE_INT              1
    #define dTEST_SFINAE_DINT             1
    #define dTEST_SFINAE_PINT             1
    #define dTEST_SFINAE_DPINT            1
#elif defined(dHAS_VARIADIC_TEMPLATE) 
    // msvc2013
    //   - has bug:
    //     - error: private/protected access
    //     - error: derived

    #define dTEST_SFINAE_REGULAR             1
    // #define dTEST_SFINAE_DERIVED          1
    // #define dTEST_SFINAE_PRIVATE          0
    // #define dTEST_SFINAE_DPRVATE          0
                                          
    #define dTEST_SFINAE_RECURSIEVE          1
    // #define dTEST_SFINAE_DRECURSIEVE      1
    // #define dTEST_SFINAE_PRECURSIEVE      0
    // #define dTEST_SFINAE_DPRECURSIEVE     0

    #define dTEST_SFINAE_UNSUITABLE          1
    // #define dTEST_SFINAE_DUNSUITABLE      1
    // #define dTEST_SFINAE_PUNSUITABLE      1
    // #define dTEST_SFINAE_DPUNSUITABLE     1

    #define dTEST_SFINAE_INT                 1
    // #define dTEST_SFINAE_DINT             1
    // #define dTEST_SFINAE_PINT             0
    // #define dTEST_SFINAE_DPINT            0

#elif defined(dHAS_ENUM_CLASS) 
    // msvc2012
    //   - has bug:
    //     - not worked: private/protected access
    //     - not worked: derived

    #define dTEST_SFINAE_REGULAR            1
    // #define dTEST_SFINAE_DERIVED         1
    // #define dTEST_SFINAE_PRIVATE         0
    // #define dTEST_SFINAE_DPRVATE         0
    
    #define dTEST_SFINAE_RECURSIEVE         1
    // #define dTEST_SFINAE_DRECURSIEVE     1
    // #define dTEST_SFINAE_PRECURSIEVE     0
    // #define dTEST_SFINAE_DPRECURSIEVE    0
    
    #define dTEST_SFINAE_UNSUITABLE         1
    #define dTEST_SFINAE_DUNSUITABLE        1
    // #define dTEST_SFINAE_PUNSUITABLE     1
    // #define dTEST_SFINAE_DPUNSUITABLE    1
    
    #define dTEST_SFINAE_INT                1
    // #define dTEST_SFINAE_DINT            1
    // #define dTEST_SFINAE_PINT            0
    // #define dTEST_SFINAE_DPINT           0

#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2010
    //   - has bug:
    //     - not worked: private/protected access
    //     - not worked: derived for int()

    #define dTEST_SFINAE_REGULAR          1
    // #define dTEST_SFINAE_DERIVED       1
    // #define dTEST_SFINAE_PRIVATE       0
    // #define dTEST_SFINAE_DPRVATE       0

    #define dTEST_SFINAE_RECURSIEVE       1
    // #define dTEST_SFINAE_DRECURSIEVE   1
    // #define dTEST_SFINAE_PRECURSIEVE   0
    // #define dTEST_SFINAE_DPRECURSIEVE  0

    #define dTEST_SFINAE_UNSUITABLE       1
    // #define dTEST_SFINAE_DUNSUITABLE   1
    // #define dTEST_SFINAE_PUNSUITABLE   0
    // #define dTEST_SFINAE_DPUNSUITABLE  0

    #define dTEST_SFINAE_INT              1
    // #define dTEST_SFINAE_DINT          1
    // #define dTEST_SFINAE_PINT          0
    // #define dTEST_SFINAE_DPINT         0

#else
    // msvc20008 or older
    #define dTEST_SFINAE_REGULAR          1
    // #define dTEST_SFINAE_DERIVED       1
    // #define dTEST_SFINAE_PRIVATE       0
    // #define dTEST_SFINAE_DPRVATE       0
    
    #define dTEST_SFINAE_RECURSIEVE       1
    // #define dTEST_SFINAE_DRECURSIEVE   1
    // #define dTEST_SFINAE_PRECURSIEVE   0
    // #define dTEST_SFINAE_DPRECURSIEVE  0

    #define dTEST_SFINAE_UNSUITABLE       1
    // #define dTEST_SFINAE_DUNSUITABLE   1
    // #define dTEST_SFINAE_PUNSUITABLE   1
    // #define dTEST_SFINAE_DPUNSUITABLE  1
    
    #define dTEST_SFINAE_INT              1
    // #define dTEST_SFINAE_DINT          1
    // #define dTEST_SFINAE_PINT          0
    // #define dTEST_SFINAE_DPINT         0
#endif

namespace
{
    #if defined (dTEST_SFINAE_PRIVATE) &&  dTEST_SFINAE_PRIVATE == 0
        const bool privat = true;
    #else
        const bool privat = false;
    #endif
}

#include "test-begin.hpp"
#include "test-signa.hpp"

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_REGULAR
// --- simple false
TEST_COMPONENT(000)
{
    //       |   type   | signature        | expected |
    make_test(Maket     , void(Maket::*)() ,  false   );
    make_test(Dummy     , void(Dummy::*)() ,  false   );
    make_test(int       , void(Maket::*)() ,  false   );
    make_test(int()     , void(Maket::*)() ,  false   );
//------------------------------------------
    make_test(Maket&    , void(Maket::*)() ,  false   );
    make_test(Dummy&    , void(Dummy::*)() ,  false   );
    make_test(int&      , void(Maket::*)() ,  false   );
    make_test(int(&)()  , void(Maket::*)() ,  false   );
//------------------------------------------
    make_rval(Maket&&   , void(Maket::*)() ,  false   );
    make_rval(Dummy&&   , void(Dummy::*)() ,  false   );
    make_rval(int&&     , void(Maket::*)() ,  false   );
    make_rval(int(&&)() , void(Maket::*)() ,  false   );
//------------------------------------------
    make_test(Maket*    , void(Maket::*)() ,  false   );
    make_test(Dummy*    , void(Dummy::*)() ,  false   );
    make_test(int*      , void(Maket::*)() ,  false   );
    make_test(int(*)()  , void(Maket::*)() ,  false   );
}
TEST_COMPONENT(001)
{
    //       |   type   | signature        | expected |
    make_test(Maket     , void(Maket::*)() const,  false   );
    make_test(Dummy     , void(Dummy::*)() const,  false   );
    make_test(int       , void(Maket::*)() const,  false   );
    make_test(int()     , void(Maket::*)() const,  false   );
//------------------------------------------
    make_test(Maket&    , void(Maket::*)() const,  false   );
    make_test(Dummy&    , void(Dummy::*)() const,  false   );
    make_test(int&      , void(Maket::*)() const,  false   );
    make_test(int(&)()  , void(Maket::*)() const,  false   );
//------------------------------------------
    make_rval(Maket&&   , void(Maket::*)() const,  false   );
    make_rval(Dummy&&   , void(Dummy::*)() const,  false   );
    make_rval(int&&     , void(Maket::*)() const,  false   );
    make_rval(int(&&)() , void(Maket::*)() const,  false   );
//------------------------------------------
    make_test(Maket*    , void(Maket::*)() const,  false   );
    make_test(Dummy*    , void(Dummy::*)() const,  false   );
    make_test(int*      , void(Maket::*)() const,  false   );
    make_test(int(*)()  , void(Maket::*)() const,  false   );
}

// --- non-const
TEST_COMPONENT(002)
{
    //       |   type     | signature            | expected |
    make_test(Const       , void(Const::*)()     ,  false   );
    make_test(Mutable     , void(Mutable::*)()   ,  true    );
    make_test(Container   , void(Container::*)() ,  true    );

    make_test(Const&      , void(Const::*)()     ,  false   );
    make_test(Mutable&    , void(Mutable::*)()   ,  true    );
    make_test(Container&  , void(Container::*)() ,  true    );

    make_rval(Const&&     , void(Const::*)()     ,  false   );
    make_rval(Mutable&&   , void(Mutable::*)()   ,  true    );
    make_rval(Container&& , void(Container::*)() ,  true    );
}
TEST_COMPONENT(003)
{
    //       |   type     | signature                 | expected |
    make_test(Const       , void(Const::*)()     const,  true    );
    make_test(Mutable     , void(Mutable::*)()   const,  false   );
    make_test(Container   , void(Container::*)() const,  true    );

    make_test(Const&      , void(Const::*)()     const,  true    );
    make_test(Mutable&    , void(Mutable::*)()   const,  false   );
    make_test(Container&  , void(Container::*)() const,  true    );

    make_rval(Const&&     , void(Const::*)()     const,  true    );
    make_rval(Mutable&&   , void(Mutable::*)()   const,  false   );
    make_rval(Container&& , void(Container::*)() const,  true    );
}

// --- const
TEST_COMPONENT(004)
{
    //       |   type           | signature            | expected |
    make_test(const Const       , void(Const::*)()     ,  false   );
    make_test(const Mutable     , void(Mutable::*)()   ,  true    );
    make_test(const Container   , void(Container::*)() ,  true    );

    make_test(const Const&      , void(Const::*)()     ,  false   );
    make_test(const Mutable&    , void(Mutable::*)()   ,  true    );
    make_test(const Container&  , void(Container::*)() ,  true    );

    make_rval(const Const&&     , void(Const::*)()     ,  false   );
    make_rval(const Mutable&&   , void(Mutable::*)()   ,  true    );
    make_rval(const Container&& , void(Container::*)() ,  true    );
}
TEST_COMPONENT(005)
{
    //       |   type           | signature                 | expected |
    make_test(const Const       , void(Const::*)()     const,  true    );
    make_test(const Mutable     , void(Mutable::*)()   const,  false   );
    make_test(const Container   , void(Container::*)() const,  true    );
                                                      
    make_test(const Const&      , void(Const::*)()     const,  true    );
    make_test(const Mutable&    , void(Mutable::*)()   const,  false   );
    make_test(const Container&  , void(Container::*)() const,  true    );
                                                       
    make_rval(const Const&&     , void(Const::*)()     const,  true    );
    make_rval(const Mutable&&   , void(Mutable::*)()   const,  false   );
    make_rval(const Container&& , void(Container::*)() const,  true    );
}

#endif // dTEST_SFINAE_REGULAR

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DERIVED
// --- derived non-const
TEST_COMPONENT(006)
{
    //       |   type      | signature             | expected |
    make_test(DConst       , void(DConst::*)()     ,  false   );
    make_test(DMutable     , void(DMutable::*)()   ,  true    );
    make_test(DContainer   , void(DContainer::*)() ,  true    );

    make_test(DConst&      , void(DConst::*)()     ,  false   );
    make_test(DMutable&    , void(DMutable::*)()   ,  true    );
    make_test(DContainer&  , void(DContainer::*)() ,  true    );

    make_rval(DConst&&     , void(DConst::*)()     ,  false   );
    make_rval(DMutable&&   , void(DMutable::*)()   ,  true    );
    make_rval(DContainer&& , void(DContainer::*)() ,  true    );
}
TEST_COMPONENT(007)
{
    //       |   type      | signature                   | expected |
    make_test(DConst       , void(DConst::*)()     const ,  true    );
    make_test(DMutable     , void(DMutable::*)()   const ,  false   );
    make_test(DContainer   , void(DContainer::*)() const ,  true    );
                                                   
    make_test(DConst&      , void(DConst::*)()     const ,  true    );
    make_test(DMutable&    , void(DMutable::*)()   const ,  false   );
    make_test(DContainer&  , void(DContainer::*)() const ,  true    );
                                                   
    make_rval(DConst&&     , void(DConst::*)()     const ,  true    );
    make_rval(DMutable&&   , void(DMutable::*)()   const ,  false   );
    make_rval(DContainer&& , void(DContainer::*)() const ,  true    );
}

// --- derived const
TEST_COMPONENT(008)
{
    //       |   type            | signature             | expected |
    make_test(const DConst       , void(DConst::*)()     ,  false   );
    make_test(const DMutable     , void(DMutable::*)()   ,  true    );
    make_test(const DContainer   , void(DContainer::*)() ,  true    );
                                                         
    make_test(const DConst&      , void(DConst::*)()     ,  false   );
    make_test(const DMutable&    , void(DMutable::*)()   ,  true    );
    make_test(const DContainer&  , void(DContainer::*)() ,  true    );
                                                         
    make_rval(const DConst&&     , void(DConst::*)()     ,  false   );
    make_rval(const DMutable&&   , void(DMutable::*)()   ,  true    );
    make_rval(const DContainer&& , void(DContainer::*)() ,  true    );
}
TEST_COMPONENT(009)
{
    //       |   type            | signature                  | expected |
    make_test(const DConst       , void(DConst::*)()     const,  true    );
    make_test(const DMutable     , void(DMutable::*)()   const,  false   );
    make_test(const DContainer   , void(DContainer::*)() const,  true    );
                                                         
    make_test(const DConst&      , void(DConst::*)()     const,  true    );
    make_test(const DMutable&    , void(DMutable::*)()   const,  false   );
    make_test(const DContainer&  , void(DContainer::*)() const,  true    );
                                                         
    make_rval(const DConst&&     , void(DConst::*)()     const,  true    );
    make_rval(const DMutable&&   , void(DMutable::*)()   const,  false   );
    make_rval(const DContainer&& , void(DContainer::*)() const,  true    );
}
#endif // dTEST_SFINAE_DERIVED

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRIVATE
// --- private non-const 
TEST_COMPONENT(010)
{
    //       |   type      | signature             | expected |
    make_test(PConst       , void(PConst::*)()     ,  false   );
    make_test(PMutable     , void(PMutable::*)()   ,  false   );
    make_test(PContainer   , void(PContainer::*)() ,  false   );
                                  
    make_test(PConst&      , void(PConst::*)()     ,  false   );
    make_test(PMutable&    , void(PMutable::*)()   ,  false   );
    make_test(PContainer&  , void(PContainer::*)() ,  false   );
                                                     
    make_rval(PConst&&     , void(PConst::*)()     ,  false   );
    make_rval(PMutable&&   , void(PMutable::*)()   ,  false   );
    make_rval(PContainer&& , void(PContainer::*)() ,  false   );
}
TEST_COMPONENT(011)
{
    //       |   type      | signature                   | expected |
    make_test(PConst       , void(PConst::*)()     const ,  false   );
    make_test(PMutable     , void(PMutable::*)()   const ,  false   );
    make_test(PContainer   , void(PContainer::*)() const ,  false   );
                                  
    make_test(PConst&      , void(PConst::*)()     const ,  false   );
    make_test(PMutable&    , void(PMutable::*)()   const ,  false   );
    make_test(PContainer&  , void(PContainer::*)() const ,  false   );
                                  
    make_rval(PConst&&     , void(PConst::*)()     const ,  false   );
    make_rval(PMutable&&   , void(PMutable::*)()   const ,  false   );
    make_rval(PContainer&& , void(PContainer::*)() const ,  false   );
}

// --- private const 
TEST_COMPONENT(012)
{
    //       |   type            | signature             | expected |
    make_test(const PConst       , void(PConst::*)()     ,  false   );
    make_test(const PMutable     , void(PMutable::*)()   ,  false   );
    make_test(const PContainer   , void(PContainer::*)() ,  false   );
                                        
    make_test(const PConst&      , void(PConst::*)()     ,  false   );
    make_test(const PMutable&    , void(PMutable::*)()   ,  false   );
    make_test(const PContainer&  , void(PContainer::*)() ,  false   );
                                        
    make_rval(const PConst&&     , void(PConst::*)()     ,  false   );
    make_rval(const PMutable&&   , void(PMutable::*)()   ,  false   );
    make_rval(const PContainer&& , void(PContainer::*)() ,  false   );
}
TEST_COMPONENT(013)
{
    //       |   type            | signature                   | expected |
    make_test(const PConst       , void(PConst::*)()     const ,  false   );
    make_test(const PMutable     , void(PMutable::*)()   const ,  false   );
    make_test(const PContainer   , void(PContainer::*)() const ,  false   );
                                        
    make_test(const PConst&      , void(PConst::*)()     const ,  false   );
    make_test(const PMutable&    , void(PMutable::*)()   const ,  false   );
    make_test(const PContainer&  , void(PContainer::*)() const ,  false   );
                                        
    make_rval(const PConst&&     , void(PConst::*)()     const ,  false   );
    make_rval(const PMutable&&   , void(PMutable::*)()   const ,  false   );
    make_rval(const PContainer&& , void(PContainer::*)() const ,  false   );
}
#endif // dTEST_SFINAE_PRIVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRVATE
// --- derived private non-const  
TEST_COMPONENT(014)
{
    //       |   type       | signature              | expected |
    make_test(DPConst       , void(DPConst::*)()     ,  false   );
    make_test(DPMutable     , void(DPMutable::*)()   ,  false   );
    make_test(DPContainer   , void(DPContainer::*)() ,  false   );

    make_test(DPConst&      , void(DPConst::*)()     ,  false   );
    make_test(DPMutable&    , void(DPMutable::*)()   ,  false   );
    make_test(DPContainer&  , void(DPContainer::*)() ,  false   );

    make_rval(DPConst&&     , void(DPConst::*)()     ,  false   );
    make_rval(DPMutable&&   , void(DPMutable::*)()   ,  false   );
    make_rval(DPContainer&& , void(DPContainer::*)() ,  false   );
}
TEST_COMPONENT(015)
{
    //       |   type       | signature                    | expected |
    make_test(DPConst       , void(DPConst::*)()     const ,  false   );
    make_test(DPMutable     , void(DPMutable::*)()   const ,  false   );
    make_test(DPContainer   , void(DPContainer::*)() const ,  false   );
                                                     
    make_test(DPConst&      , void(DPConst::*)()     const ,  false   );
    make_test(DPMutable&    , void(DPMutable::*)()   const ,  false   );
    make_test(DPContainer&  , void(DPContainer::*)() const ,  false   );
                                                     
    make_rval(DPConst&&     , void(DPConst::*)()     const ,  false   );
    make_rval(DPMutable&&   , void(DPMutable::*)()   const ,  false   );
    make_rval(DPContainer&& , void(DPContainer::*)() const ,  false   );
}

// --- derived private const 
TEST_COMPONENT(016)
{
    //       |   type             | signature              | expected |
    make_test(const DPConst       , void(DPConst::*)()     ,  false   );
    make_test(const DPMutable     , void(DPMutable::*)()   ,  false   );
    make_test(const DPContainer   , void(DPContainer::*)() ,  false   );

    make_test(const DPConst&      , void(DPConst::*)()     ,  false   );
    make_test(const DPMutable&    , void(DPMutable::*)()   ,  false   );
    make_test(const DPContainer&  , void(DPContainer::*)() ,  false   );

    make_rval(const DPConst&&     , void(DPConst::*)()     ,  false   );
    make_rval(const DPMutable&&   , void(DPMutable::*)()   ,  false   );
    make_rval(const DPContainer&& , void(DPContainer::*)() ,  false   );
}
TEST_COMPONENT(017)
{
    //       |   type             | signature                    | expected |
    make_test(const DPConst       , void(DPConst::*)()     const ,  false   );
    make_test(const DPMutable     , void(DPMutable::*)()   const ,  false   );
    make_test(const DPContainer   , void(DPContainer::*)() const ,  false   );
                                                           
    make_test(const DPConst&      , void(DPConst::*)()     const ,  false   );
    make_test(const DPMutable&    , void(DPMutable::*)()   const ,  false   );
    make_test(const DPContainer&  , void(DPContainer::*)() const ,  false   );
                                                           
    make_rval(const DPConst&&     , void(DPConst::*)()     const ,  false   );
    make_rval(const DPMutable&&   , void(DPMutable::*)()   const ,  false   );
    make_rval(const DPContainer&& , void(DPContainer::*)() const ,  false   );
}
#endif // dTEST_SFINAE_DPRVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_RECURSIEVE
// --- recursieve non-const
TEST_COMPONENT(018)
{
    //       |   type      | signature                   | expected |
    make_test(RConst       , RConst(RConst::*)()         ,  false   );
    make_test(RMutable     , RMutable(RMutable::*)()     ,  true    );
    make_test(RContainer   , RContainer(RContainer::*)() ,  true    );
              
    make_test(RConst&      , RConst(RConst::*)()         ,  false   );
    make_test(RMutable&    , RMutable(RMutable::*)()     ,  true    );
    make_test(RContainer&  , RContainer(RContainer::*)() ,  true    );
                                  
    make_rval(RConst&&     , RConst(RConst::*)()         ,  false   );
    make_rval(RMutable&&   , RMutable(RMutable::*)()     ,  true    );
    make_rval(RContainer&& , RContainer(RContainer::*)() ,  true    );
}
TEST_COMPONENT(019)
{ 
    //       |   type      | signature                         | expected |
    make_test(RConst       , RConst(RConst::*)()         const ,  true    );
    make_test(RMutable     , RMutable(RMutable::*)()     const ,  false   );
    make_test(RContainer   , RContainer(RContainer::*)() const ,  true    );
                                                          
    make_test(RConst&      , RConst(RConst::*)()         const ,  true    );
    make_test(RMutable&    , RMutable(RMutable::*)()     const ,  false   );
    make_test(RContainer&  , RContainer(RContainer::*)() const ,  true    );
                                                         
    make_rval(RConst&&     , RConst(RConst::*)()         const ,  true    );
    make_rval(RMutable&&   , RMutable(RMutable::*)()     const ,  false   );
    make_rval(RContainer&& , RContainer(RContainer::*)() const ,  true    );
}

// --- recursieve const
TEST_COMPONENT(020)
{
    //       |   type            | signature                   | expected |
    make_test(const RConst       , RConst(RConst::*)()         ,  false   );
    make_test(const RMutable     , RMutable(RMutable::*)()     ,  true    );
    make_test(const RContainer   , RContainer(RContainer::*)() ,  true    );
              
    make_test(const RConst&      , RConst(RConst::*)()         ,  false   );
    make_test(const RMutable&    , RMutable(RMutable::*)()     ,  true    );
    make_test(const RContainer&  , RContainer(RContainer::*)() ,  true    );
              
    make_rval(const RConst&&     , RConst(RConst::*)()         ,  false   );
    make_rval(const RMutable&&   , RMutable(RMutable::*)()     ,  true    );
    make_rval(const RContainer&& , RContainer(RContainer::*)() ,  true    );
}
TEST_COMPONENT(021)
{ 
    //       |   type            | signature                         | expected |
    make_test(const RConst       , RConst(RConst::*)()         const ,  true    );
    make_test(const RMutable     , RMutable(RMutable::*)()     const ,  false   );
    make_test(const RContainer   , RContainer(RContainer::*)() const ,  true    );
                                                          
    make_test(const RConst&      , RConst(RConst::*)()         const ,  true    );
    make_test(const RMutable&    , RMutable(RMutable::*)()     const ,  false   );
    make_test(const RContainer&  , RContainer(RContainer::*)() const ,  true    );
              
    make_rval(const RConst&&     , RConst(RConst::*)()         const ,  true    );
    make_rval(const RMutable&&   , RMutable(RMutable::*)()     const ,  false   );
    make_rval(const RContainer&& , RContainer(RContainer::*)() const ,  true    );
}
#endif // dTEST_SFINAE_RECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DRECURSIEVE
// --- derived recursieve non-const
TEST_COMPONENT(022)
{
    //       |   type       | signature                    | expected |
    make_test(DRConst       , RConst(DRConst::*)()         ,  false   );
    make_test(DRMutable     , RMutable(DRMutable::*)()     ,  true    );
    make_test(DRContainer   , RContainer(DRContainer::*)() ,  true    );
                                 
    make_test(DRConst&      , RConst(DRConst::*)()         ,  false   );
    make_test(DRMutable&    , RMutable(DRMutable::*)()     ,  true    );
    make_test(DRContainer&  , RContainer(DRContainer::*)() ,  true    );
    
    make_rval(DRConst&&     , RConst(DRConst::*)()         ,  false   );
    make_rval(DRMutable&&   , RMutable(DRMutable::*)()     ,  true    );
    make_rval(DRContainer&& , RContainer(DRContainer::*)() ,  true    );
}
TEST_COMPONENT(023)
{
    //       |   type       | signature                          | expected |
    make_test(DRConst       , RConst(DRConst::*)()         const ,  true    );
    make_test(DRMutable     , RMutable(DRMutable::*)()     const ,  false   );
    make_test(DRContainer   , RContainer(DRContainer::*)() const ,  true    );
                              
    make_test(DRConst&      , RConst(DRConst::*)()         const ,  true    );
    make_test(DRMutable&    , RMutable(DRMutable::*)()     const ,  false   );
    make_test(DRContainer&  , RContainer(DRContainer::*)() const ,  true    );
                              
    make_rval(DRConst&&     , RConst(DRConst::*)()         const ,  true    );
    make_rval(DRMutable&&   , RMutable(DRMutable::*)()     const ,  false   );
    make_rval(DRContainer&& , RContainer(DRContainer::*)() const ,  true    );
}

// --- derived recursieve const
TEST_COMPONENT(024)
{
    //       |   type             | signature                    | expected |
    make_test(const DRConst       , RConst(DRConst::*)()         ,  false   );
    make_test(const DRMutable     , RMutable(DRMutable::*)()     ,  true    );
    make_test(const DRContainer   , RContainer(DRContainer::*)() ,  true    );
                                 
    make_test(const DRConst&      , RConst(DRConst::*)()         ,  false   );
    make_test(const DRMutable&    , RMutable(DRMutable::*)()     ,  true    );
    make_test(const DRContainer&  , RContainer(DRContainer::*)() ,  true    );
              
    make_rval(const DRConst&&     , RConst(DRConst::*)()         ,  false   );
    make_rval(const DRMutable&&   , RMutable(DRMutable::*)()     ,  true    );
    make_rval(const DRContainer&& , RContainer(DRContainer::*)() ,  true    );
}
TEST_COMPONENT(025)
{
    //       |   type             | signature                          | expected |
    make_test(const DRConst       , RConst(DRConst::*)()         const ,  true    );
    make_test(const DRMutable     , RMutable(DRMutable::*)()     const ,  false   );
    make_test(const DRContainer   , RContainer(DRContainer::*)() const ,  true    );
                              
    make_test(const DRConst&      , RConst(DRConst::*)()         const ,  true    );
    make_test(const DRMutable&    , RMutable(DRMutable::*)()     const ,  false   );
    make_test(const DRContainer&  , RContainer(DRContainer::*)() const ,  true    );
              
    make_rval(const DRConst&&     , RConst(DRConst::*)()         const ,  true    );
    make_rval(const DRMutable&&   , RMutable(DRMutable::*)()     const ,  false   );
    make_rval(const DRContainer&& , RContainer(DRContainer::*)() const ,  true    );
}
#endif // dTEST_SFINAE_DRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRECURSIEVE
// --- private recursieve non-const 
TEST_COMPONENT(026)
{
    //       |   type       | signature                    | expected |
    make_test(PRConst       , PConst(PRConst::*)()         ,  false   );
    make_test(PRMutable     , PMutable(PRMutable::*)()     ,  false   );
    make_test(PRContainer   , PContainer(PRContainer::*)() ,  false   );
                                    
    make_test(PRConst&      , PConst(PRConst::*)()         ,  false   );
    make_test(PRMutable&    , PMutable(PRMutable::*)()     ,  false   );
    make_test(PRContainer&  , PContainer(PRContainer::*)() ,  false   );
                                    
    make_rval(PRConst&&     , PConst(PRConst::*)()         ,  false   );
    make_rval(PRMutable&&   , PMutable(PRMutable::*)()     ,  false   );
    make_rval(PRContainer&& , PContainer(PRContainer::*)() ,  false   );
}
TEST_COMPONENT(027)
{
    //       |   type       | signature                          | expected |
    make_test(PRConst       , PConst(PRConst::*)()         const ,  false   );
    make_test(PRMutable     , PMutable(PRMutable::*)()     const ,  false   );
    make_test(PRContainer   , PContainer(PRContainer::*)() const ,  false   );
                                                                 
    make_test(PRConst&      , PConst(PRConst::*)()         const ,  false   );
    make_test(PRMutable&    , PMutable(PRMutable::*)()     const ,  false   );
    make_test(PRContainer&  , PContainer(PRContainer::*)() const ,  false   );
                                                                 
    make_rval(PRConst&&     , PConst(PRConst::*)()         const ,  false   );
    make_rval(PRMutable&&   , PMutable(PRMutable::*)()     const ,  false   );
    make_rval(PRContainer&& , PContainer(PRContainer::*)() const ,  false   );
}

// --- private recursieve non-const 
TEST_COMPONENT(028)
{
    //       |   type             | signature                    | expected |
    make_test(const PRConst       , PConst(PRConst::*)()         ,  false   );
    make_test(const PRMutable     , PMutable(PRMutable::*)()     ,  false   );
    make_test(const PRContainer   , PContainer(PRContainer::*)() ,  false   );
                                    
    make_test(const PRConst&      , PConst(PRConst::*)()         ,  false   );
    make_test(const PRMutable&    , PMutable(PRMutable::*)()     ,  false   );
    make_test(const PRContainer&  , PContainer(PRContainer::*)() ,  false   );
              
    make_rval(const PRConst&&     , PConst(PRConst::*)()         ,  false   );
    make_rval(const PRMutable&&   , PMutable(PRMutable::*)()     ,  false   );
    make_rval(const PRContainer&& , PContainer(PRContainer::*)() ,  false   );
}
TEST_COMPONENT(029)
{
    //       |   type             | signature                          | expected |
    make_test(const PRConst       , PConst(PRConst::*)()         const ,  false   );
    make_test(const PRMutable     , PMutable(PRMutable::*)()     const ,  false   );
    make_test(const PRContainer   , PContainer(PRContainer::*)() const ,  false   );
                                                                 
    make_test(const PRConst&      , PConst(PRConst::*)()         const ,  false   );
    make_test(const PRMutable&    , PMutable(PRMutable::*)()     const ,  false   );
    make_test(const PRContainer&  , PContainer(PRContainer::*)() const ,  false   );
              
    make_rval(const PRConst&&     , PConst(PRConst::*)()         const ,  false   );
    make_rval(const PRMutable&&   , PMutable(PRMutable::*)()     const ,  false   );
    make_rval(const PRContainer&& , PContainer(PRContainer::*)() const ,  false   );
}
#endif // dTEST_SFINAE_PRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRECURSIEVE
// --- derived private recursieve non-const  
TEST_COMPONENT(030)
{
    //       |   type        | signature                      | expected |
    make_test(DPRConst       , PRConst(DPRConst::*)()         ,  false   );
    make_test(DPRMutable     , PRMutable(DPRMutable::*)()     ,  false   );
    make_test(DPRContainer   , PRContainer(DPRContainer::*)() ,  false   );
                
    make_test(DPRConst&      , PRConst(DPRConst::*)()         ,  false   );
    make_test(DPRMutable&    , PRMutable(DPRMutable::*)()     ,  false   );
    make_test(DPRContainer&  , PRContainer(DPRContainer::*)() ,  false   );
                
    make_rval(DPRConst&&     , PRConst(DPRConst::*)()         ,  false   );
    make_rval(DPRMutable&&   , PRMutable(DPRMutable::*)()     ,  false   );
    make_rval(DPRContainer&& , PRContainer(DPRContainer::*)() ,  false   );
}
TEST_COMPONENT(031)
{
    //       |   type        | signature                            | expected |
    make_test(DPRConst       , PRConst(DPRConst::*)()         const ,  false   );
    make_test(DPRMutable     , PRMutable(DPRMutable::*)()     const ,  false   );
    make_test(DPRContainer   , PRContainer(DPRContainer::*)() const ,  false   );

    make_test(DPRConst&      , PRConst(DPRConst::*)()         const ,  false   );
    make_test(DPRMutable&    , PRMutable(DPRMutable::*)()     const ,  false   );
    make_test(DPRContainer&  , PRContainer(DPRContainer::*)() const ,  false   );

    make_rval(DPRConst&&     , PRConst(DPRConst::*)()         const ,  false   );
    make_rval(DPRMutable&&   , PRMutable(DPRMutable::*)()     const ,  false   );
    make_rval(DPRContainer&& , PRContainer(DPRContainer::*)() const ,  false   );
}

// --- derived private recursieve non-const  
TEST_COMPONENT(032)
{
    //       |   type              | signature                      | expected |
    make_test(const DPRConst       , PRConst(DPRConst::*)()         ,  false   );
    make_test(const DPRMutable     , PRMutable(DPRMutable::*)()     ,  false   );
    make_test(const DPRContainer   , PRContainer(DPRContainer::*)() ,  false   );
              
    make_test(const DPRConst&      , PRConst(DPRConst::*)()         ,  false   );
    make_test(const DPRMutable&    , PRMutable(DPRMutable::*)()     ,  false   );
    make_test(const DPRContainer&  , PRContainer(DPRContainer::*)() ,  false   );
                
    make_rval(const DPRConst&&     , PRConst(DPRConst::*)()         ,  false   );
    make_rval(const DPRMutable&&   , PRMutable(DPRMutable::*)()     ,  false   );
    make_rval(const DPRContainer&& , PRContainer(DPRContainer::*)() ,  false   );
}
TEST_COMPONENT(034)
{
    //       |   type              | signature                            | expected |
    make_test(const DPRConst       , PRConst(DPRConst::*)()         const ,  false   );
    make_test(const DPRMutable     , PRMutable(DPRMutable::*)()     const ,  false   );
    make_test(const DPRContainer   , PRContainer(DPRContainer::*)() const ,  false   );
              
    make_test(const DPRConst&      , PRConst(DPRConst::*)()         const ,  false   );
    make_test(const DPRMutable&    , PRMutable(DPRMutable::*)()     const ,  false   );
    make_test(const DPRContainer&  , PRContainer(DPRContainer::*)() const ,  false   );
              
    make_rval(const DPRConst&&     , PRConst(DPRConst::*)()         const ,  false   );
    make_rval(const DPRMutable&&   , PRMutable(DPRMutable::*)()     const ,  false   );
    make_rval(const DPRContainer&& , PRContainer(DPRContainer::*)() const ,  false   );
}
#endif // dTEST_SFINAE_DPRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_UNSUITABLE
// --- non-const
TEST_COMPONENT(035)
{
    //       |   type             | signature                   | expected |
    make_test(UnsuitableConst     , void(UnsuitableConst::*)()  ,  false   );
    make_test(UnsuitableMutable   , void(UnsuitableMutable::*)(),  false   );
    make_test(Unsuitable          , void(Container::*)()        ,  false   );
                                  
    make_test(UnsuitableConst&    , void(UnsuitableConst::*)()  ,  false   );
    make_test(UnsuitableMutable&  , void(UnsuitableMutable::*)(),  false   );
    make_test(Unsuitable&         , void(Container::*)()        ,  false   );

    make_rval(UnsuitableConst&&   , void(UnsuitableConst::*)()  ,  false   );
    make_rval(UnsuitableMutable&& , void(UnsuitableMutable::*)(),  false   );
    make_rval(Unsuitable&&        , void(Container::*)()        ,  false   );
}
TEST_COMPONENT(036)
{
    //       |   type             | signature                          | expected |
    make_test(UnsuitableConst     , void(UnsuitableConst::*)()   const ,  false   );
    make_test(UnsuitableMutable   , void(UnsuitableMutable::*)() const ,  false   );
    make_test(Unsuitable          , void(Container::*)()         const ,  false   );

    make_test(UnsuitableConst&    , void(UnsuitableConst::*)()   const ,  false   );
    make_test(UnsuitableMutable&  , void(UnsuitableMutable::*)() const ,  false   );
    make_test(Unsuitable&         , void(Container::*)()         const ,  false   );

    make_rval(UnsuitableConst&&   , void(UnsuitableConst::*)()   const ,  false   );
    make_rval(UnsuitableMutable&& , void(UnsuitableMutable::*)() const ,  false   );
    make_rval(Unsuitable&&        , void(Container::*)()         const ,  false   );
}

// --- const
TEST_COMPONENT(037)
{
    //       |   type                   | signature                    | expected |
    make_test(const UnsuitableConst     , void(UnsuitableConst::*)()   ,  false   );
    make_test(const UnsuitableMutable   , void(UnsuitableMutable::*)() ,  false   );
    make_test(const Unsuitable          , void(Unsuitable::*)()        ,  false   );
                                  
    make_test(const UnsuitableConst&    , void(UnsuitableConst::*)()   ,  false   );
    make_test(const UnsuitableMutable&  , void(UnsuitableMutable::*)() ,  false   );
    make_test(const Unsuitable&         , void(Unsuitable::*)()        ,  false   );
              
    make_rval(const UnsuitableConst&&   , void(UnsuitableConst::*)()   ,  false   );
    make_rval(const UnsuitableMutable&& , void(UnsuitableMutable::*)() ,  false   );
    make_rval(const Unsuitable&&        , void(Unsuitable::*)()        ,  false   );
}
TEST_COMPONENT(038)
{
    //       |   type                   | signature                          | expected |
    make_test(const UnsuitableConst     , void(UnsuitableConst::*)()   const ,  false   );
    make_test(const UnsuitableMutable   , void(UnsuitableMutable::*)() const ,  false   );
    make_test(const Unsuitable          , void(Unsuitable::*)()        const ,  false   );

    make_test(const UnsuitableConst&    , void(UnsuitableConst::*)()   const ,  false   );
    make_test(const UnsuitableMutable&  , void(UnsuitableMutable::*)() const ,  false   );
    make_test(const Unsuitable&         , void(Unsuitable::*)()        const ,  false   );

    make_rval(const UnsuitableConst&&   , void(UnsuitableConst::*)()   const ,  false   );
    make_rval(const UnsuitableMutable&& , void(UnsuitableMutable::*)() const ,  false   );
    make_rval(const Unsuitable&&        , void(Unsuitable::*)()        const ,  false   );
}
#endif // dTEST_SFINAE_UNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DUNSUITABLE
// --- non-const
TEST_COMPONENT(039)
{
    //       |   type              | signature                    | expected |
    make_test(DUnsuitableConst     , void(DUnsuitableConst::*)()  ,  false   );
    make_test(DUnsuitableMutable   , void(DUnsuitableMutable::*)(),  false   );
    make_test(DUnsuitable          , void(DUnsuitable::*)()       ,  false   );
                                          
    make_test(DUnsuitableConst&    , void(DUnsuitableConst::*)()  ,  false   );
    make_test(DUnsuitableMutable&  , void(DUnsuitableMutable::*)(),  false   );
    make_test(DUnsuitable&         , void(DUnsuitable::*)()       ,  false   );
                                          
    make_rval(DUnsuitableConst&&   , void(DUnsuitableConst::*)()  ,  false   );
    make_rval(DUnsuitableMutable&& , void(DUnsuitableMutable::*)(),  false   );
    make_rval(DUnsuitable&&        , void(DUnsuitable::*)()       ,  false   );
}
TEST_COMPONENT(040)
{
    //       |   type              | signature                           | expected |
    make_test(DUnsuitableConst     , void(DUnsuitableConst::*)()   const ,  false   );
    make_test(DUnsuitableMutable   , void(DUnsuitableMutable::*)() const ,  false   );
    make_test(DUnsuitable          , void(DUnsuitable::*)()        const ,  false   );
              
    make_test(DUnsuitableConst&    , void(DUnsuitableConst::*)()   const ,  false   );
    make_test(DUnsuitableMutable&  , void(DUnsuitableMutable::*)() const ,  false   );
    make_test(DUnsuitable&         , void(DUnsuitable::*)()        const ,  false   );
              
    make_rval(DUnsuitableConst&&   , void(DUnsuitableConst::*)()   const ,  false   );
    make_rval(DUnsuitableMutable&& , void(DUnsuitableMutable::*)() const ,  false   );
    make_rval(DUnsuitable&&        , void(DUnsuitable::*)()        const ,  false   );
}

// --- const
TEST_COMPONENT(041)
{ 
    //       |   type                    | signature                    | expected |
    make_test(const DUnsuitableConst     , void(DUnsuitableConst::*)()  ,  false   );
    make_test(const DUnsuitableMutable   , void(DUnsuitableMutable::*)(),  false   );
    make_test(const DUnsuitable          , void(DUnsuitable::*)()       ,  false   );

    make_test(const DUnsuitableConst&    , void(DUnsuitableConst::*)()  ,  false   );
    make_test(const DUnsuitableMutable&  , void(DUnsuitableMutable::*)(),  false   );
    make_test(const DUnsuitable&         , void(DUnsuitable::*)()       ,  false   );

    make_rval(const DUnsuitableConst&&   , void(DUnsuitableConst::*)()  ,  false   );
    make_rval(const DUnsuitableMutable&& , void(DUnsuitableMutable::*)(),  false   );
    make_rval(const DUnsuitable&&        , void(DUnsuitable::*)()       ,  false   );
}
TEST_COMPONENT(042)
{
    //       |   type                    | signature                           | expected |
    make_test(const DUnsuitableConst     , void(DUnsuitableConst::*)()   const ,  false   );
    make_test(const DUnsuitableMutable   , void(DUnsuitableMutable::*)() const ,  false   );
    make_test(const DUnsuitable          , void(DUnsuitable::*)()        const ,  false   );

    make_test(const DUnsuitableConst&    , void(DUnsuitableConst::*)()   const ,  false   );
    make_test(const DUnsuitableMutable&  , void(DUnsuitableMutable::*)() const ,  false   );
    make_test(const DUnsuitable&         , void(DUnsuitable::*)()        const ,  false   );

    make_rval(const DUnsuitableConst&&   , void(DUnsuitableConst::*)()   const ,  false   );
    make_rval(const DUnsuitableMutable&& , void(DUnsuitableMutable::*)() const ,  false   );
    make_rval(const DUnsuitable&&        , void(DUnsuitable::*)()        const ,  false   );
}
#endif // dTEST_SFINAE_DUNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PUNSUITABLE
// --- non-const
TEST_COMPONENT(043)
{
    //       |   type              | signature                     | expected |
    make_test(PUnsuitableConst     , void(PUnsuitableConst::*)()   ,  false   );
    make_test(PUnsuitableMutable   , void(PUnsuitableMutable::*)() ,  false   );
    make_test(PUnsuitable          , void(PUnsuitable::*)()        ,  false   );
              													   
    make_test(PUnsuitableConst&    , void(PUnsuitableConst::*)()   ,  false   );
    make_test(PUnsuitableMutable&  , void(PUnsuitableMutable::*)() ,  false   );
    make_test(PUnsuitable&         , void(PUnsuitable::*)()        ,  false   );
              													   
    make_rval(PUnsuitableConst&&   , void(PUnsuitableConst::*)()   ,  false   );
    make_rval(PUnsuitableMutable&& , void(PUnsuitableMutable::*)() ,  false   );
    make_rval(PUnsuitable&&        , void(PUnsuitable::*)()        ,  false   );
}
TEST_COMPONENT(044)
{
    //       |   type              | signature                           | expected |
    make_test(PUnsuitableConst     , void(PUnsuitableConst::*)()   const ,  false   );
    make_test(PUnsuitableMutable   , void(PUnsuitableMutable::*)() const ,  false   );
    make_test(PUnsuitable          , void(PUnsuitable::*)()        const ,  false   );
              
    make_test(PUnsuitableConst&    , void(PUnsuitableConst::*)()   const ,  false   );
    make_test(PUnsuitableMutable&  , void(PUnsuitableMutable::*)() const ,  false   );
    make_test(PUnsuitable&         , void(PUnsuitable::*)()        const ,  false   );
              
    make_rval(PUnsuitableConst&&   , void(PUnsuitableConst::*)()   const ,  false   );
    make_rval(PUnsuitableMutable&& , void(PUnsuitableMutable::*)() const ,  false   );
    make_rval(PUnsuitable&&        , void(PUnsuitable::*)()        const ,  false   );
}

// --- const
TEST_COMPONENT(045)
{ 
    //       |   type                    | signature                     | expected |
    make_test(const PUnsuitableConst     , void(PUnsuitableConst::*)()   ,  false   );
    make_test(const PUnsuitableMutable   , void(PUnsuitableMutable::*)() ,  false   );
    make_test(const PUnsuitable          , void(PUnsuitable::*)()        ,  false   );
                    
    make_test(const PUnsuitableConst&    , void(PUnsuitableConst::*)()   ,  false   );
    make_test(const PUnsuitableMutable&  , void(PUnsuitableMutable::*)() ,  false   );
    make_test(const PUnsuitable&         , void(PUnsuitable::*)()        ,  false   );
                    
    make_rval(const PUnsuitableConst&&   , void(PUnsuitableConst::*)()   ,  false   );
    make_rval(const PUnsuitableMutable&& , void(PUnsuitableMutable::*)() ,  false   );
    make_rval(const PUnsuitable&&        , void(PUnsuitable::*)()        ,  false   );
}
TEST_COMPONENT(046)
{
    //       |   type                    | signature                           | expected |
    make_test(const PUnsuitableConst     , void(PUnsuitableConst::*)()   const ,  false   );
    make_test(const PUnsuitableMutable   , void(PUnsuitableMutable::*)() const ,  false   );
    make_test(const PUnsuitable          , void(PUnsuitable::*)()        const ,  false   );
                    
    make_test(const PUnsuitableConst&    , void(PUnsuitableConst::*)()   const ,  false   );
    make_test(const PUnsuitableMutable&  , void(PUnsuitableMutable::*)() const ,  false   );
    make_test(const PUnsuitable&         , void(PUnsuitable::*)()        const ,  false   );
                    
    make_rval(const PUnsuitableConst&&   , void(PUnsuitableConst::*)()   const ,  false   );
    make_rval(const PUnsuitableMutable&& , void(PUnsuitableMutable::*)() const ,  false   );
    make_rval(const PUnsuitable&&        , void(PUnsuitable::*)()        const ,  false   );
}
#endif // dTEST_SFINAE_PUNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPUNSUITABLE
// --- non-const
TEST_COMPONENT(047)
{
    //       |   type               | signature                      | expected |
    make_test(DPUnsuitableConst     , void(DPUnsuitableConst::*)()   ,  false   );
    make_test(DPUnsuitableMutable   , void(DPUnsuitableMutable::*)() ,  false   );
    make_test(DPUnsuitable          , void(DPUnsuitable::*)()        ,  false   );
              
    make_test(DPUnsuitableConst&    , void(DPUnsuitableConst::*)()   ,  false   );
    make_test(DPUnsuitableMutable&  , void(DPUnsuitableMutable::*)() ,  false   );
    make_test(DPUnsuitable&         , void(DPUnsuitable::*)()        ,  false   );
              
    make_rval(DPUnsuitableConst&&   , void(DPUnsuitableConst::*)()   ,  false   );
    make_rval(DPUnsuitableMutable&& , void(DPUnsuitableMutable::*)() ,  false   );
    make_rval(DPUnsuitable&&        , void(DPUnsuitable::*)()        ,  false   );
}
TEST_COMPONENT(048)
{
    //       |   type               | signature                            | expected |
    make_test(DPUnsuitableConst     , void(DPUnsuitableConst::*)()   const ,  false   );
    make_test(DPUnsuitableMutable   , void(DPUnsuitableMutable::*)() const ,  false   );
    make_test(DPUnsuitable          , void(DPUnsuitable::*)()        const ,  false   );

    make_test(DPUnsuitableConst&    , void(DPUnsuitableConst::*)()   const ,  false   );
    make_test(DPUnsuitableMutable&  , void(DPUnsuitableMutable::*)() const ,  false   );
    make_test(DPUnsuitable&         , void(DPUnsuitable::*)()        const ,  false   );

    make_rval(DPUnsuitableConst&&   , void(DPUnsuitableConst::*)()   const ,  false   );
    make_rval(DPUnsuitableMutable&& , void(DPUnsuitableMutable::*)() const ,  false   );
    make_rval(DPUnsuitable&&        , void(DPUnsuitable::*)()        const ,  false   );
}

// --- const
TEST_COMPONENT(049)
{ 
    //       |   type                     | signature                      | expected |
    make_test(const DPUnsuitableConst     , void(DPUnsuitableConst::*)()   ,  false   );
    make_test(const DPUnsuitableMutable   , void(DPUnsuitableMutable::*)() ,  false   );
    make_test(const DPUnsuitable          , void(DPUnsuitable::*)()        ,  false   );
                    
    make_test(const DPUnsuitableConst&    , void(DPUnsuitableConst::*)()   ,  false   );
    make_test(const DPUnsuitableMutable&  , void(DPUnsuitableMutable::*)() ,  false   );
    make_test(const DPUnsuitable&         , void(DPUnsuitable::*)()        ,  false   );
                    
    make_rval(const DPUnsuitableConst&&   , void(DPUnsuitableConst::*)()   ,  false   );
    make_rval(const DPUnsuitableMutable&& , void(DPUnsuitableMutable::*)() ,  false   );
    make_rval(const DPUnsuitable&&        , void(DPUnsuitable::*)()        ,  false   );
}
TEST_COMPONENT(050)
{
    //       |   type                     | signature                            | expected |
    make_test(const DPUnsuitableConst     , void(DPUnsuitableConst::*)()   const ,  false   );
    make_test(const DPUnsuitableMutable   , void(DPUnsuitableMutable::*)() const ,  false   );
    make_test(const DPUnsuitable          , void(DPUnsuitable::*)()        const ,  false   );

    make_test(const DPUnsuitableConst&    , void(DPUnsuitableConst::*)()   const ,  false   );
    make_test(const DPUnsuitableMutable&  , void(DPUnsuitableMutable::*)() const ,  false   );
    make_test(const DPUnsuitable&         , void(DPUnsuitable::*)()        const ,  false   );

    make_rval(const DPUnsuitableConst&&   , void(DPUnsuitableConst::*)()   const ,  false   );
    make_rval(const DPUnsuitableMutable&& , void(DPUnsuitableMutable::*)() const ,  false   );
    make_rval(const DPUnsuitable&&        , void(DPUnsuitable::*)()        const ,  false   );
}
#endif // dTEST_SFINAE_DPUNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_INT
// --- non-const
TEST_COMPONENT(051)
{
    //       |   type      | signature            | expected |
    make_test(IntConst     , int(IntConst::*)()   ,   false  );
    make_test(IntMutable   , int(IntMutable::*)() ,   true   );
    make_test(Int          , int(Int::*)()        ,   true   );

    make_test(IntConst&    , int(IntConst::*)()   ,   false  );
    make_test(IntMutable&  , int(IntMutable::*)() ,   true   );
    make_test(Int&         , int(Int::*)()        ,   true   );

    make_rval(IntConst&&   , int(IntConst::*)()   ,   false  );
    make_rval(IntMutable&& , int(IntMutable::*)() ,   true   );
    make_rval(Int&&        , int(Int::*)()        ,   true   );
}
TEST_COMPONENT(052)
{
    //       |   type      | signature                  | expected |
    make_test(IntConst     , int(IntConst::*)()   const ,   true   );
    make_test(IntMutable   , int(IntMutable::*)() const ,   false  );
    make_test(Int          , int(Int::*)()        const ,   true   );

    make_test(IntConst&    , int(IntConst::*)()   const ,   true   );
    make_test(IntMutable&  , int(IntMutable::*)() const ,   false  );
    make_test(Int&         , int(Int::*)()        const ,   true   );

    make_rval(IntConst&&   , int(IntConst::*)()   const ,   true   );
    make_rval(IntMutable&& , int(IntMutable::*)() const ,   false  );
    make_rval(Int&&        , int(Int::*)()        const ,   true   );
}

// --- const
TEST_COMPONENT(053)
{
    //       |   type            | signature            | expected |
    make_test(const IntConst     , int(IntConst::*)()   ,   false  );
    make_test(const IntMutable   , int(IntMutable::*)() ,   true   );
    make_test(const Int          , int(Int::*)()        ,   true   );

    make_test(const IntConst&    , int(IntConst::*)()   ,   false  );
    make_test(const IntMutable&  , int(IntMutable::*)() ,   true   );
    make_test(const Int&         , int(Int::*)()        ,   true   );

    make_rval(const IntConst&&   , int(IntConst::*)()   ,   false  );
    make_rval(const IntMutable&& , int(IntMutable::*)() ,   true   );
    make_rval(const Int&&        , int(Int::*)()        ,   true   );
}
TEST_COMPONENT(054)
{
    //       |   type            | signature                  | expected |
    make_test(const IntConst     , int(IntConst::*)()   const ,   true   );
    make_test(const IntMutable   , int(IntMutable::*)() const ,   false  );
    make_test(const Int          , int(Int::*)()        const ,   true   );
              
    make_test(const IntConst&    , int(IntConst::*)()   const ,   true   );
    make_test(const IntMutable&  , int(IntMutable::*)() const ,   false  );
    make_test(const Int&         , int(Int::*)()        const ,   true   );
              
    make_rval(const IntConst&&   , int(IntConst::*)()   const ,   true   );
    make_rval(const IntMutable&& , int(IntMutable::*)() const ,   false  );
    make_rval(const Int&&        , int(Int::*)()        const ,   true   );
}
#endif // dTEST_SFINAE_INT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DINT
// --- non-const
TEST_COMPONENT(055)
{
    //       |   type       | signature             | expected |
    make_test(DIntConst     , int(DIntConst::*)()   ,   false  );
    make_test(DIntMutable   , int(DIntMutable::*)() ,   true   );
    make_test(DInt          , int(DInt::*)()        ,   true   );
              
    make_test(DIntConst&    , int(DIntConst::*)()   ,   false  );
    make_test(DIntMutable&  , int(DIntMutable::*)() ,   true   );
    make_test(DInt&         , int(DInt::*)()        ,   true   );
              
    make_rval(DIntConst&&   , int(DIntConst::*)()   ,   false  );
    make_rval(DIntMutable&& , int(DIntMutable::*)() ,   true   );
    make_rval(DInt&&        , int(DInt::*)()        ,   true   );
}
TEST_COMPONENT(056)
{
    //       |   type       | signature                   | expected |
    make_test(DIntConst     , int(DIntConst::*)()   const ,   true   );
    make_test(DIntMutable   , int(DIntMutable::*)() const ,   false  );
    make_test(DInt          , int(DInt::*)()        const ,   true   );
              
    make_test(DIntConst&    , int(DIntConst::*)()   const ,   true   );
    make_test(DIntMutable&  , int(DIntMutable::*)() const ,   false  );
    make_test(DInt&         , int(DInt::*)()        const ,   true   );
              
    make_rval(DIntConst&&   , int(DIntConst::*)()   const ,   true   );
    make_rval(DIntMutable&& , int(DIntMutable::*)() const ,   false  );
    make_rval(DInt&&        , int(DInt::*)()        const ,   true   );
}

// --- const
TEST_COMPONENT(057)
{
    //       |   type             | signature             | expected |
    make_test(const DIntConst     , int(DIntConst::*)()   ,   false  );
    make_test(const DIntMutable   , int(DIntMutable::*)() ,   true   );
    make_test(const DInt          , int(DInt::*)()        ,   true   );
                    
    make_test(const DIntConst&    , int(DIntConst::*)()   ,   false  );
    make_test(const DIntMutable&  , int(DIntMutable::*)() ,   true   );
    make_test(const DInt&         , int(DInt::*)()        ,   true   );
                    
    make_rval(const DIntConst&&   , int(DIntConst::*)()   ,   false  );
    make_rval(const DIntMutable&& , int(DIntMutable::*)() ,   true   );
    make_rval(const DInt&&        , int(DInt::*)()        ,   true   );
}
TEST_COMPONENT(058)
{
    //       |   type             | signature                   | expected |
    make_test(const DIntConst     , int(DIntConst::*)()   const ,   true   );
    make_test(const DIntMutable   , int(DIntMutable::*)() const ,   false  );
    make_test(const DInt          , int(DInt::*)()        const ,   true   );
                    
    make_test(const DIntConst&    , int(DIntConst::*)()   const ,   true   );
    make_test(const DIntMutable&  , int(DIntMutable::*)() const ,   false  );
    make_test(const DInt&         , int(DInt::*)()        const ,   true   );
                    
    make_rval(const DIntConst&&   , int(DIntConst::*)()   const ,   true   );
    make_rval(const DIntMutable&& , int(DIntMutable::*)() const ,   false  );
    make_rval(const DInt&&        , int(DInt::*)()        const ,   true   );
}
#endif // dTEST_SFINAE_DINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PINT
// --- non-const
TEST_COMPONENT(059)
{
    //       |   type       | signature             | expected |
    make_test(PIntConst     , int(PIntConst::*)()   ,   false  );
    make_test(PIntMutable   , int(PIntMutable::*)() ,   false  );
    make_test(PInt          , int(PInt::*)()        ,   false  );

    make_test(PIntConst&    , int(PIntConst::*)()   ,   false  );
    make_test(PIntMutable&  , int(PIntMutable::*)() ,   false  );
    make_test(PInt&         , int(PInt::*)()        ,   false  );

    make_rval(PIntConst&&   , int(PIntConst::*)()   ,   false  );
    make_rval(PIntMutable&& , int(PIntMutable::*)() ,   false  );
    make_rval(PInt&&        , int(PInt::*)()        ,   false  );
}
TEST_COMPONENT(060)
{
    //       |   type       | signature                   | expected |
    make_test(PIntConst     , int(PIntConst::*)()   const ,   false  );
    make_test(PIntMutable   , int(PIntMutable::*)() const ,   false  );
    make_test(PInt          , int(PInt::*)()        const ,   false  );
              
    make_test(PIntConst&    , int(PIntConst::*)()   const ,   false  );
    make_test(PIntMutable&  , int(PIntMutable::*)() const ,   false  );
    make_test(PInt&         , int(PInt::*)()        const ,   false  );
              
    make_rval(PIntConst&&   , int(PIntConst::*)()   const ,   false  );
    make_rval(PIntMutable&& , int(PIntMutable::*)() const ,   false  );
    make_rval(PInt&&        , int(PInt::*)()        const ,   false  );
}

// --- const
TEST_COMPONENT(061)
{
    //       |   type             | signature             | expected |
    make_test(const PIntConst     , int(PIntConst::*)()   ,   false  );
    make_test(const PIntMutable   , int(PIntMutable::*)() ,   false  );
    make_test(const PInt          , int(PInt::*)()        ,   false  );
                    
    make_test(const PIntConst&    , int(PIntConst::*)()   ,   false  );
    make_test(const PIntMutable&  , int(PIntMutable::*)() ,   false  );
    make_test(const PInt&         , int(PInt::*)()        ,   false  );
                    
    make_rval(const PIntConst&&   , int(PIntConst::*)()   ,   false  );
    make_rval(const PIntMutable&& , int(PIntMutable::*)() ,   false  );
    make_rval(const PInt&&        , int(PInt::*)()        ,   false  );
}
TEST_COMPONENT(062)
{
    //       |   type             | signature                   | expected |
    make_test(const PIntConst     , int(PIntConst::*)()   const ,   false  );
    make_test(const PIntMutable   , int(PIntMutable::*)() const ,   false  );
    make_test(const PInt          , int(PInt::*)()        const ,   false  );

    make_test(const PIntConst&    , int(PIntConst::*)()   const ,   false  );
    make_test(const PIntMutable&  , int(PIntMutable::*)() const ,   false  );
    make_test(const PInt&         , int(PInt::*)()        const ,   false  );

    make_rval(const PIntConst&&   , int(PIntConst::*)()   const ,   false  );
    make_rval(const PIntMutable&& , int(PIntMutable::*)() const ,   false  );
    make_rval(const PInt&&        , int(PInt::*)()        const ,   false  );
}
#endif // dTEST_SFINAE_PINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPINT
// --- non-const
TEST_COMPONENT(063)
{
    //       |   type        | signature              | expected |
    make_test(DPIntConst     , int(DPIntConst::*)()   ,   false  );
    make_test(DPIntMutable   , int(DPIntMutable::*)() ,   false  );
    make_test(DPInt          , int(DPInt::*)()        ,   false  );
              
    make_test(DPIntConst&    , int(DPIntConst::*)()   ,   false  );
    make_test(DPIntMutable&  , int(DPIntMutable::*)() ,   false  );
    make_test(DPInt&         , int(DPInt::*)()        ,   false  );
              
    make_rval(DPIntConst&&   , int(DPIntConst::*)()   ,   false  );
    make_rval(DPIntMutable&& , int(DPIntMutable::*)() ,   false  );
    make_rval(DPInt&&        , int(DPInt::*)()        ,   false  );
}
TEST_COMPONENT(064)
{
    //       |   type        | signature                    | expected |
    make_test(DPIntConst     , int(DPIntConst::*)()   const ,   false  );
    make_test(DPIntMutable   , int(DPIntMutable::*)() const ,   false  );
    make_test(DPInt          , int(DPInt::*)()        const ,   false  );
              
    make_test(DPIntConst&    , int(DPIntConst::*)()   const ,   false  );
    make_test(DPIntMutable&  , int(DPIntMutable::*)() const ,   false  );
    make_test(DPInt&         , int(DPInt::*)()        const ,   false  );
              
    make_rval(DPIntConst&&   , int(DPIntConst::*)()   const ,   false  );
    make_rval(DPIntMutable&& , int(DPIntMutable::*)() const ,   false  );
    make_rval(DPInt&&        , int(DPInt::*)()        const ,   false  );
}

// --- const
TEST_COMPONENT(065)
{
    //       |   type              | signature              | expected |
    make_test(const DPIntConst     , int(DPIntConst::*)()   ,   false  );
    make_test(const DPIntMutable   , int(DPIntMutable::*)() ,   false  );
    make_test(const DPInt          , int(DPInt::*)()        ,   false  );
                    
    make_test(const DPIntConst&    , int(DPIntConst::*)()   ,   false  );
    make_test(const DPIntMutable&  , int(DPIntMutable::*)() ,   false  );
    make_test(const DPInt&         , int(DPInt::*)()        ,   false  );
                    
    make_rval(const DPIntConst&&   , int(DPIntConst::*)()   ,   false  );
    make_rval(const DPIntMutable&& , int(DPIntMutable::*)() ,   false  );
    make_rval(const DPInt&&        , int(DPInt::*)()        ,   false  );
}
TEST_COMPONENT(066)
{
    //       |   type              | signature                    | expected |
    make_test(const DPIntConst     , int(DPIntConst::*)()   const ,   false  );
    make_test(const DPIntMutable   , int(DPIntMutable::*)() const ,   false  );
    make_test(const DPInt          , int(DPInt::*)()        const ,   false  );
                    
    make_test(const DPIntConst&    , int(DPIntConst::*)()   const ,   false  );
    make_test(const DPIntMutable&  , int(DPIntMutable::*)() const ,   false  );
    make_test(const DPInt&         , int(DPInt::*)()        const ,   false  );
                    
    make_rval(const DPIntConst&&   , int(DPIntConst::*)()   const ,   false  );
    make_rval(const DPIntMutable&& , int(DPIntMutable::*)() const ,   false  );
    make_rval(const DPInt&&        , int(DPInt::*)()        const ,   false  );
}
#endif // dTEST_SFINAE_DPINT

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_SFINAE_BEGIN