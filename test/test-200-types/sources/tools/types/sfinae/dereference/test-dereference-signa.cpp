// [2021y-05m-05d][23:02:09] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_DEREFERENCE__
#define dTEST_COMPONENT tools, types, sfinae, signature
#define dTEST_METHOD dereference
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

#include "test-dereference.hpp"
#include "test-signa.hpp"

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_REGULAR
// --- simple false
TEST_COMPONENT(000)
{
    //       |   type   | signature          | expected |
    make_test(Maket     , double(Maket::*)() ,  false   );
    make_test(Dummy     , double(Dummy::*)() ,  false   );
    make_test(int       , double(Maket::*)() ,  false   );
    make_test(int()     , double(Maket::*)() ,  false   );
//------------------------------------------
    make_test(Maket&    , double(Maket::*)() ,  false   );
    make_test(Dummy&    , double(Dummy::*)() ,  false   );
    make_test(int&      , double(Maket::*)() ,  false   );
    make_test(int(&)()  , double(Maket::*)() ,  false   );
//------------------------------------------
    make_rval(Maket&&   , double(Maket::*)() ,  false   );
    make_rval(Dummy&&   , double(Dummy::*)() ,  false   );
    make_rval(int&&     , double(Maket::*)() ,  false   );
    make_rval(int(&&)() , double(Maket::*)() ,  false   );
//------------------------------------------
    make_test(Maket*    , double(Maket::*)() ,  false   );
    make_test(Dummy*    , double(Dummy::*)() ,  false   );
    make_test(int*      , double(Maket::*)() ,  false   );
    make_test(int(*)()  , double(Maket::*)() ,  false   );
}
TEST_COMPONENT(001)
{
    //       |   type   | signature               | expected |
    make_test(Maket     , double(Maket::*)() const,  false   );
    make_test(Dummy     , double(Dummy::*)() const,  false   );
    make_test(int       , double(Maket::*)() const,  false   );
    make_test(int()     , double(Maket::*)() const,  false   );
//------------------------------------------
    make_test(Maket&    , double(Maket::*)() const,  false   );
    make_test(Dummy&    , double(Dummy::*)() const,  false   );
    make_test(int&      , double(Maket::*)() const,  false   );
    make_test(int(&)()  , double(Maket::*)() const,  false   );
//------------------------------------------
    make_rval(Maket&&   , double(Maket::*)() const,  false   );
    make_rval(Dummy&&   , double(Dummy::*)() const,  false   );
    make_rval(int&&     , double(Maket::*)() const,  false   );
    make_rval(int(&&)() , double(Maket::*)() const,  false   );
//------------------------------------------
    make_test(Maket*    , double(Maket::*)() const,  false   );
    make_test(Dummy*    , double(Dummy::*)() const,  false   );
    make_test(int*      , double(Maket::*)() const,  false   );
    make_test(int(*)()  , double(Maket::*)() const,  false   );
}

// --- non-const
TEST_COMPONENT(002)
{
    //       |   type     | signature              | expected |
    make_test(Const       , double(Const::*)()     ,  false   );
    make_test(Mutable     , double(Mutable::*)()   ,  true    );
    make_test(Container   , double(Container::*)() ,  true    );

    make_test(Const&      , double(Const::*)()     ,  false   );
    make_test(Mutable&    , double(Mutable::*)()   ,  true    );
    make_test(Container&  , double(Container::*)() ,  true    );

    make_rval(Const&&     , double(Const::*)()     ,  false   );
    make_rval(Mutable&&   , double(Mutable::*)()   ,  true    );
    make_rval(Container&& , double(Container::*)() ,  true    );
}
TEST_COMPONENT(003)
{
    //       |   type     | signature                   | expected |
    make_test(Const       , double(Const::*)()     const,  true    );
    make_test(Mutable     , double(Mutable::*)()   const,  false   );
    make_test(Container   , double(Container::*)() const,  true    );

    make_test(Const&      , double(Const::*)()     const,  true    );
    make_test(Mutable&    , double(Mutable::*)()   const,  false   );
    make_test(Container&  , double(Container::*)() const,  true    );

    make_rval(Const&&     , double(Const::*)()     const,  true    );
    make_rval(Mutable&&   , double(Mutable::*)()   const,  false   );
    make_rval(Container&& , double(Container::*)() const,  true    );
}

// --- const
TEST_COMPONENT(004)
{
    //       |   type           | signature              | expected |
    make_test(const Const       , double(Const::*)()     ,  false   );
    make_test(const Mutable     , double(Mutable::*)()   ,  true    );
    make_test(const Container   , double(Container::*)() ,  true    );

    make_test(const Const&      , double(Const::*)()     ,  false   );
    make_test(const Mutable&    , double(Mutable::*)()   ,  true    );
    make_test(const Container&  , double(Container::*)() ,  true    );

    make_rval(const Const&&     , double(Const::*)()     ,  false   );
    make_rval(const Mutable&&   , double(Mutable::*)()   ,  true    );
    make_rval(const Container&& , double(Container::*)() ,  true    );
}
TEST_COMPONENT(005)
{
    //       |   type           | signature                   | expected |
    make_test(const Const       , double(Const::*)()     const,  true    );
    make_test(const Mutable     , double(Mutable::*)()   const,  false   );
    make_test(const Container   , double(Container::*)() const,  true    );
                                                      
    make_test(const Const&      , double(Const::*)()     const,  true    );
    make_test(const Mutable&    , double(Mutable::*)()   const,  false   );
    make_test(const Container&  , double(Container::*)() const,  true    );
                                                       
    make_rval(const Const&&     , double(Const::*)()     const,  true    );
    make_rval(const Mutable&&   , double(Mutable::*)()   const,  false   );
    make_rval(const Container&& , double(Container::*)() const,  true    );
}

#endif // dTEST_SFINAE_REGULAR

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DERIVED
// --- derived non-const
TEST_COMPONENT(006)
{
    //       |   type      | signature               | expected |
    make_test(DConst       , double(DConst::*)()     ,  false   );
    make_test(DMutable     , double(DMutable::*)()   ,  true    );
    make_test(DContainer   , double(DContainer::*)() ,  true    );

    make_test(DConst&      , double(DConst::*)()     ,  false   );
    make_test(DMutable&    , double(DMutable::*)()   ,  true    );
    make_test(DContainer&  , double(DContainer::*)() ,  true    );

    make_rval(DConst&&     , double(DConst::*)()     ,  false   );
    make_rval(DMutable&&   , double(DMutable::*)()   ,  true    );
    make_rval(DContainer&& , double(DContainer::*)() ,  true    );
}
TEST_COMPONENT(007)
{
    //       |   type      | signature                     | expected |
    make_test(DConst       , double(DConst::*)()     const ,  true    );
    make_test(DMutable     , double(DMutable::*)()   const ,  false   );
    make_test(DContainer   , double(DContainer::*)() const ,  true    );
                                                   
    make_test(DConst&      , double(DConst::*)()     const ,  true    );
    make_test(DMutable&    , double(DMutable::*)()   const ,  false   );
    make_test(DContainer&  , double(DContainer::*)() const ,  true    );
                                                   
    make_rval(DConst&&     , double(DConst::*)()     const ,  true    );
    make_rval(DMutable&&   , double(DMutable::*)()   const ,  false   );
    make_rval(DContainer&& , double(DContainer::*)() const ,  true    );
}

// --- derived const
TEST_COMPONENT(008)
{
    //       |   type            | signature               | expected |
    make_test(const DConst       , double(DConst::*)()     ,  false   );
    make_test(const DMutable     , double(DMutable::*)()   ,  true    );
    make_test(const DContainer   , double(DContainer::*)() ,  true    );
                                                         
    make_test(const DConst&      , double(DConst::*)()     ,  false   );
    make_test(const DMutable&    , double(DMutable::*)()   ,  true    );
    make_test(const DContainer&  , double(DContainer::*)() ,  true    );
                                                         
    make_rval(const DConst&&     , double(DConst::*)()     ,  false   );
    make_rval(const DMutable&&   , double(DMutable::*)()   ,  true    );
    make_rval(const DContainer&& , double(DContainer::*)() ,  true    );
}
TEST_COMPONENT(009)
{
    //       |   type            | signature                    | expected |
    make_test(const DConst       , double(DConst::*)()     const,  true    );
    make_test(const DMutable     , double(DMutable::*)()   const,  false   );
    make_test(const DContainer   , double(DContainer::*)() const,  true    );
                                                         
    make_test(const DConst&      , double(DConst::*)()     const,  true    );
    make_test(const DMutable&    , double(DMutable::*)()   const,  false   );
    make_test(const DContainer&  , double(DContainer::*)() const,  true    );
                                                         
    make_rval(const DConst&&     , double(DConst::*)()     const,  true    );
    make_rval(const DMutable&&   , double(DMutable::*)()   const,  false   );
    make_rval(const DContainer&& , double(DContainer::*)() const,  true    );
}
#endif // dTEST_SFINAE_DERIVED

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRIVATE
// --- private non-const 
TEST_COMPONENT(010)
{
    //       |   type      | signature               | expected |
    make_test(PConst       , double(PConst::*)()     ,  false   );
    make_test(PMutable     , double(PMutable::*)()   ,  false   );
    make_test(PContainer   , double(PContainer::*)() ,  false   );
                                  
    make_test(PConst&      , double(PConst::*)()     ,  false   );
    make_test(PMutable&    , double(PMutable::*)()   ,  false   );
    make_test(PContainer&  , double(PContainer::*)() ,  false   );
                                                     
    make_rval(PConst&&     , double(PConst::*)()     ,  false   );
    make_rval(PMutable&&   , double(PMutable::*)()   ,  false   );
    make_rval(PContainer&& , double(PContainer::*)() ,  false   );
}
TEST_COMPONENT(011)
{
    //       |   type      | signature                     | expected |
    make_test(PConst       , double(PConst::*)()     const ,  false   );
    make_test(PMutable     , double(PMutable::*)()   const ,  false   );
    make_test(PContainer   , double(PContainer::*)() const ,  false   );
                                  
    make_test(PConst&      , double(PConst::*)()     const ,  false   );
    make_test(PMutable&    , double(PMutable::*)()   const ,  false   );
    make_test(PContainer&  , double(PContainer::*)() const ,  false   );
                                  
    make_rval(PConst&&     , double(PConst::*)()     const ,  false   );
    make_rval(PMutable&&   , double(PMutable::*)()   const ,  false   );
    make_rval(PContainer&& , double(PContainer::*)() const ,  false   );
}

// --- private const 
TEST_COMPONENT(012)
{
    //       |   type            | signature               | expected |
    make_test(const PConst       , double(PConst::*)()     ,  false   );
    make_test(const PMutable     , double(PMutable::*)()   ,  false   );
    make_test(const PContainer   , double(PContainer::*)() ,  false   );
                                        
    make_test(const PConst&      , double(PConst::*)()     ,  false   );
    make_test(const PMutable&    , double(PMutable::*)()   ,  false   );
    make_test(const PContainer&  , double(PContainer::*)() ,  false   );
                                        
    make_rval(const PConst&&     , double(PConst::*)()     ,  false   );
    make_rval(const PMutable&&   , double(PMutable::*)()   ,  false   );
    make_rval(const PContainer&& , double(PContainer::*)() ,  false   );
}
TEST_COMPONENT(013)
{
    //       |   type            | signature                     | expected |
    make_test(const PConst       , double(PConst::*)()     const ,  false   );
    make_test(const PMutable     , double(PMutable::*)()   const ,  false   );
    make_test(const PContainer   , double(PContainer::*)() const ,  false   );
                                        
    make_test(const PConst&      , double(PConst::*)()     const ,  false   );
    make_test(const PMutable&    , double(PMutable::*)()   const ,  false   );
    make_test(const PContainer&  , double(PContainer::*)() const ,  false   );
                                        
    make_rval(const PConst&&     , double(PConst::*)()     const ,  false   );
    make_rval(const PMutable&&   , double(PMutable::*)()   const ,  false   );
    make_rval(const PContainer&& , double(PContainer::*)() const ,  false   );
}
#endif // dTEST_SFINAE_PRIVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRVATE
// --- derived private non-const  
TEST_COMPONENT(014)
{
    //       |   type       | signature                | expected |
    make_test(DPConst       , double(DPConst::*)()     ,  false   );
    make_test(DPMutable     , double(DPMutable::*)()   ,  false   );
    make_test(DPContainer   , double(DPContainer::*)() ,  false   );

    make_test(DPConst&      , double(DPConst::*)()     ,  false   );
    make_test(DPMutable&    , double(DPMutable::*)()   ,  false   );
    make_test(DPContainer&  , double(DPContainer::*)() ,  false   );

    make_rval(DPConst&&     , double(DPConst::*)()     ,  false   );
    make_rval(DPMutable&&   , double(DPMutable::*)()   ,  false   );
    make_rval(DPContainer&& , double(DPContainer::*)() ,  false   );
}
TEST_COMPONENT(015)
{
    //       |   type       | signature                      | expected |
    make_test(DPConst       , double(DPConst::*)()     const ,  false   );
    make_test(DPMutable     , double(DPMutable::*)()   const ,  false   );
    make_test(DPContainer   , double(DPContainer::*)() const ,  false   );
                                                     
    make_test(DPConst&      , double(DPConst::*)()     const ,  false   );
    make_test(DPMutable&    , double(DPMutable::*)()   const ,  false   );
    make_test(DPContainer&  , double(DPContainer::*)() const ,  false   );
                                                     
    make_rval(DPConst&&     , double(DPConst::*)()     const ,  false   );
    make_rval(DPMutable&&   , double(DPMutable::*)()   const ,  false   );
    make_rval(DPContainer&& , double(DPContainer::*)() const ,  false   );
}

// --- derived private const 
TEST_COMPONENT(016)
{
    //       |   type             | signature                | expected |
    make_test(const DPConst       , double(DPConst::*)()     ,  false   );
    make_test(const DPMutable     , double(DPMutable::*)()   ,  false   );
    make_test(const DPContainer   , double(DPContainer::*)() ,  false   );

    make_test(const DPConst&      , double(DPConst::*)()     ,  false   );
    make_test(const DPMutable&    , double(DPMutable::*)()   ,  false   );
    make_test(const DPContainer&  , double(DPContainer::*)() ,  false   );

    make_rval(const DPConst&&     , double(DPConst::*)()     ,  false   );
    make_rval(const DPMutable&&   , double(DPMutable::*)()   ,  false   );
    make_rval(const DPContainer&& , double(DPContainer::*)() ,  false   );
}
TEST_COMPONENT(017)
{
    //       |   type             | signature                      | expected |
    make_test(const DPConst       , double(DPConst::*)()     const ,  false   );
    make_test(const DPMutable     , double(DPMutable::*)()   const ,  false   );
    make_test(const DPContainer   , double(DPContainer::*)() const ,  false   );
                                                           
    make_test(const DPConst&      , double(DPConst::*)()     const ,  false   );
    make_test(const DPMutable&    , double(DPMutable::*)()   const ,  false   );
    make_test(const DPContainer&  , double(DPContainer::*)() const ,  false   );
                                                           
    make_rval(const DPConst&&     , double(DPConst::*)()     const ,  false   );
    make_rval(const DPMutable&&   , double(DPMutable::*)()   const ,  false   );
    make_rval(const DPContainer&& , double(DPContainer::*)() const ,  false   );
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
    make_test(UnsuitableConst     , double(UnsuitableConst::*)()  ,  false   );
    make_test(UnsuitableMutable   , double(UnsuitableMutable::*)(),  false   );
    make_test(Unsuitable          , double(Container::*)()        ,  false   );
                                  
    make_test(UnsuitableConst&    , double(UnsuitableConst::*)()  ,  false   );
    make_test(UnsuitableMutable&  , double(UnsuitableMutable::*)(),  false   );
    make_test(Unsuitable&         , double(Container::*)()        ,  false   );

    make_rval(UnsuitableConst&&   , double(UnsuitableConst::*)()  ,  false   );
    make_rval(UnsuitableMutable&& , double(UnsuitableMutable::*)(),  false   );
    make_rval(Unsuitable&&        , double(Container::*)()        ,  false   );
}
TEST_COMPONENT(036)
{
    //       |   type             | signature                            | expected |
    make_test(UnsuitableConst     , double(UnsuitableConst::*)()   const ,  false   );
    make_test(UnsuitableMutable   , double(UnsuitableMutable::*)() const ,  false   );
    make_test(Unsuitable          , double(Container::*)()         const ,  false   );

    make_test(UnsuitableConst&    , double(UnsuitableConst::*)()   const ,  false   );
    make_test(UnsuitableMutable&  , double(UnsuitableMutable::*)() const ,  false   );
    make_test(Unsuitable&         , double(Container::*)()         const ,  false   );

    make_rval(UnsuitableConst&&   , double(UnsuitableConst::*)()   const ,  false   );
    make_rval(UnsuitableMutable&& , double(UnsuitableMutable::*)() const ,  false   );
    make_rval(Unsuitable&&        , double(Container::*)()         const ,  false   );
}

// --- const
TEST_COMPONENT(037)
{
    //       |   type                   | signature                      | expected |
    make_test(const UnsuitableConst     , double(UnsuitableConst::*)()   ,  false   );
    make_test(const UnsuitableMutable   , double(UnsuitableMutable::*)() ,  false   );
    make_test(const Unsuitable          , double(Unsuitable::*)()        ,  false   );
                                  
    make_test(const UnsuitableConst&    , double(UnsuitableConst::*)()   ,  false   );
    make_test(const UnsuitableMutable&  , double(UnsuitableMutable::*)() ,  false   );
    make_test(const Unsuitable&         , double(Unsuitable::*)()        ,  false   );
              
    make_rval(const UnsuitableConst&&   , double(UnsuitableConst::*)()   ,  false   );
    make_rval(const UnsuitableMutable&& , double(UnsuitableMutable::*)() ,  false   );
    make_rval(const Unsuitable&&        , double(Unsuitable::*)()        ,  false   );
}
TEST_COMPONENT(038)
{
    //       |   type                   | signature                            | expected |
    make_test(const UnsuitableConst     , double(UnsuitableConst::*)()   const ,  false   );
    make_test(const UnsuitableMutable   , double(UnsuitableMutable::*)() const ,  false   );
    make_test(const Unsuitable          , double(Unsuitable::*)()        const ,  false   );

    make_test(const UnsuitableConst&    , double(UnsuitableConst::*)()   const ,  false   );
    make_test(const UnsuitableMutable&  , double(UnsuitableMutable::*)() const ,  false   );
    make_test(const Unsuitable&         , double(Unsuitable::*)()        const ,  false   );

    make_rval(const UnsuitableConst&&   , double(UnsuitableConst::*)()   const ,  false   );
    make_rval(const UnsuitableMutable&& , double(UnsuitableMutable::*)() const ,  false   );
    make_rval(const Unsuitable&&        , double(Unsuitable::*)()        const ,  false   );
}
#endif // dTEST_SFINAE_UNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DUNSUITABLE
// --- non-const
TEST_COMPONENT(039)
{
    //       |   type              | signature                      | expected |
    make_test(DUnsuitableConst     , double(DUnsuitableConst::*)()  ,  false   );
    make_test(DUnsuitableMutable   , double(DUnsuitableMutable::*)(),  false   );
    make_test(DUnsuitable          , double(DUnsuitable::*)()       ,  false   );
                                          
    make_test(DUnsuitableConst&    , double(DUnsuitableConst::*)()  ,  false   );
    make_test(DUnsuitableMutable&  , double(DUnsuitableMutable::*)(),  false   );
    make_test(DUnsuitable&         , double(DUnsuitable::*)()       ,  false   );
                                          
    make_rval(DUnsuitableConst&&   , double(DUnsuitableConst::*)()  ,  false   );
    make_rval(DUnsuitableMutable&& , double(DUnsuitableMutable::*)(),  false   );
    make_rval(DUnsuitable&&        , double(DUnsuitable::*)()       ,  false   );
}
TEST_COMPONENT(040)
{
    //       |   type              | signature                             | expected |
    make_test(DUnsuitableConst     , double(DUnsuitableConst::*)()   const ,  false   );
    make_test(DUnsuitableMutable   , double(DUnsuitableMutable::*)() const ,  false   );
    make_test(DUnsuitable          , double(DUnsuitable::*)()        const ,  false   );
              
    make_test(DUnsuitableConst&    , double(DUnsuitableConst::*)()   const ,  false   );
    make_test(DUnsuitableMutable&  , double(DUnsuitableMutable::*)() const ,  false   );
    make_test(DUnsuitable&         , double(DUnsuitable::*)()        const ,  false   );
              
    make_rval(DUnsuitableConst&&   , double(DUnsuitableConst::*)()   const ,  false   );
    make_rval(DUnsuitableMutable&& , double(DUnsuitableMutable::*)() const ,  false   );
    make_rval(DUnsuitable&&        , double(DUnsuitable::*)()        const ,  false   );
}

// --- const
TEST_COMPONENT(041)
{ 
    //       |   type                    | signature                      | expected |
    make_test(const DUnsuitableConst     , double(DUnsuitableConst::*)()  ,  false   );
    make_test(const DUnsuitableMutable   , double(DUnsuitableMutable::*)(),  false   );
    make_test(const DUnsuitable          , double(DUnsuitable::*)()       ,  false   );

    make_test(const DUnsuitableConst&    , double(DUnsuitableConst::*)()  ,  false   );
    make_test(const DUnsuitableMutable&  , double(DUnsuitableMutable::*)(),  false   );
    make_test(const DUnsuitable&         , double(DUnsuitable::*)()       ,  false   );

    make_rval(const DUnsuitableConst&&   , double(DUnsuitableConst::*)()  ,  false   );
    make_rval(const DUnsuitableMutable&& , double(DUnsuitableMutable::*)(),  false   );
    make_rval(const DUnsuitable&&        , double(DUnsuitable::*)()       ,  false   );
}
TEST_COMPONENT(042)
{
    //       |   type                    | signature                             | expected |
    make_test(const DUnsuitableConst     , double(DUnsuitableConst::*)()   const ,  false   );
    make_test(const DUnsuitableMutable   , double(DUnsuitableMutable::*)() const ,  false   );
    make_test(const DUnsuitable          , double(DUnsuitable::*)()        const ,  false   );

    make_test(const DUnsuitableConst&    , double(DUnsuitableConst::*)()   const ,  false   );
    make_test(const DUnsuitableMutable&  , double(DUnsuitableMutable::*)() const ,  false   );
    make_test(const DUnsuitable&         , double(DUnsuitable::*)()        const ,  false   );

    make_rval(const DUnsuitableConst&&   , double(DUnsuitableConst::*)()   const ,  false   );
    make_rval(const DUnsuitableMutable&& , double(DUnsuitableMutable::*)() const ,  false   );
    make_rval(const DUnsuitable&&        , double(DUnsuitable::*)()        const ,  false   );
}
#endif // dTEST_SFINAE_DUNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PUNSUITABLE
// --- non-const
TEST_COMPONENT(043)
{
    //       |   type              | signature                       | expected |
    make_test(PUnsuitableConst     , double(PUnsuitableConst::*)()   ,  false   );
    make_test(PUnsuitableMutable   , double(PUnsuitableMutable::*)() ,  false   );
    make_test(PUnsuitable          , double(PUnsuitable::*)()        ,  false   );
              													   
    make_test(PUnsuitableConst&    , double(PUnsuitableConst::*)()   ,  false   );
    make_test(PUnsuitableMutable&  , double(PUnsuitableMutable::*)() ,  false   );
    make_test(PUnsuitable&         , double(PUnsuitable::*)()        ,  false   );
              													   
    make_rval(PUnsuitableConst&&   , double(PUnsuitableConst::*)()   ,  false   );
    make_rval(PUnsuitableMutable&& , double(PUnsuitableMutable::*)() ,  false   );
    make_rval(PUnsuitable&&        , double(PUnsuitable::*)()        ,  false   );
}
TEST_COMPONENT(044)
{
    //       |   type              | signature                             | expected |
    make_test(PUnsuitableConst     , double(PUnsuitableConst::*)()   const ,  false   );
    make_test(PUnsuitableMutable   , double(PUnsuitableMutable::*)() const ,  false   );
    make_test(PUnsuitable          , double(PUnsuitable::*)()        const ,  false   );
              
    make_test(PUnsuitableConst&    , double(PUnsuitableConst::*)()   const ,  false   );
    make_test(PUnsuitableMutable&  , double(PUnsuitableMutable::*)() const ,  false   );
    make_test(PUnsuitable&         , double(PUnsuitable::*)()        const ,  false   );
              
    make_rval(PUnsuitableConst&&   , double(PUnsuitableConst::*)()   const ,  false   );
    make_rval(PUnsuitableMutable&& , double(PUnsuitableMutable::*)() const ,  false   );
    make_rval(PUnsuitable&&        , double(PUnsuitable::*)()        const ,  false   );
}

// --- const
TEST_COMPONENT(045)
{ 
    //       |   type                    | signature                       | expected |
    make_test(const PUnsuitableConst     , double(PUnsuitableConst::*)()   ,  false   );
    make_test(const PUnsuitableMutable   , double(PUnsuitableMutable::*)() ,  false   );
    make_test(const PUnsuitable          , double(PUnsuitable::*)()        ,  false   );
                    
    make_test(const PUnsuitableConst&    , double(PUnsuitableConst::*)()   ,  false   );
    make_test(const PUnsuitableMutable&  , double(PUnsuitableMutable::*)() ,  false   );
    make_test(const PUnsuitable&         , double(PUnsuitable::*)()        ,  false   );
                    
    make_rval(const PUnsuitableConst&&   , double(PUnsuitableConst::*)()   ,  false   );
    make_rval(const PUnsuitableMutable&& , double(PUnsuitableMutable::*)() ,  false   );
    make_rval(const PUnsuitable&&        , double(PUnsuitable::*)()        ,  false   );
}
TEST_COMPONENT(046)
{
    //       |   type                    | signature                             | expected |
    make_test(const PUnsuitableConst     , double(PUnsuitableConst::*)()   const ,  false   );
    make_test(const PUnsuitableMutable   , double(PUnsuitableMutable::*)() const ,  false   );
    make_test(const PUnsuitable          , double(PUnsuitable::*)()        const ,  false   );
                    
    make_test(const PUnsuitableConst&    , double(PUnsuitableConst::*)()   const ,  false   );
    make_test(const PUnsuitableMutable&  , double(PUnsuitableMutable::*)() const ,  false   );
    make_test(const PUnsuitable&         , double(PUnsuitable::*)()        const ,  false   );
                    
    make_rval(const PUnsuitableConst&&   , double(PUnsuitableConst::*)()   const ,  false   );
    make_rval(const PUnsuitableMutable&& , double(PUnsuitableMutable::*)() const ,  false   );
    make_rval(const PUnsuitable&&        , double(PUnsuitable::*)()        const ,  false   );
}
#endif // dTEST_SFINAE_PUNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPUNSUITABLE
// --- non-const
TEST_COMPONENT(047)
{
    //       |   type               | signature                        | expected |
    make_test(DPUnsuitableConst     , double(DPUnsuitableConst::*)()   ,  false   );
    make_test(DPUnsuitableMutable   , double(DPUnsuitableMutable::*)() ,  false   );
    make_test(DPUnsuitable          , double(DPUnsuitable::*)()        ,  false   );
              
    make_test(DPUnsuitableConst&    , double(DPUnsuitableConst::*)()   ,  false   );
    make_test(DPUnsuitableMutable&  , double(DPUnsuitableMutable::*)() ,  false   );
    make_test(DPUnsuitable&         , double(DPUnsuitable::*)()        ,  false   );
              
    make_rval(DPUnsuitableConst&&   , double(DPUnsuitableConst::*)()   ,  false   );
    make_rval(DPUnsuitableMutable&& , double(DPUnsuitableMutable::*)() ,  false   );
    make_rval(DPUnsuitable&&        , double(DPUnsuitable::*)()        ,  false   );
}
TEST_COMPONENT(048)
{
    //       |   type               | signature                              | expected |
    make_test(DPUnsuitableConst     , double(DPUnsuitableConst::*)()   const ,  false   );
    make_test(DPUnsuitableMutable   , double(DPUnsuitableMutable::*)() const ,  false   );
    make_test(DPUnsuitable          , double(DPUnsuitable::*)()        const ,  false   );

    make_test(DPUnsuitableConst&    , double(DPUnsuitableConst::*)()   const ,  false   );
    make_test(DPUnsuitableMutable&  , double(DPUnsuitableMutable::*)() const ,  false   );
    make_test(DPUnsuitable&         , double(DPUnsuitable::*)()        const ,  false   );

    make_rval(DPUnsuitableConst&&   , double(DPUnsuitableConst::*)()   const ,  false   );
    make_rval(DPUnsuitableMutable&& , double(DPUnsuitableMutable::*)() const ,  false   );
    make_rval(DPUnsuitable&&        , double(DPUnsuitable::*)()        const ,  false   );
}

// --- const
TEST_COMPONENT(049)
{ 
    //       |   type                     | signature                        | expected |
    make_test(const DPUnsuitableConst     , double(DPUnsuitableConst::*)()   ,  false   );
    make_test(const DPUnsuitableMutable   , double(DPUnsuitableMutable::*)() ,  false   );
    make_test(const DPUnsuitable          , double(DPUnsuitable::*)()        ,  false   );
                    
    make_test(const DPUnsuitableConst&    , double(DPUnsuitableConst::*)()   ,  false   );
    make_test(const DPUnsuitableMutable&  , double(DPUnsuitableMutable::*)() ,  false   );
    make_test(const DPUnsuitable&         , double(DPUnsuitable::*)()        ,  false   );
                    
    make_rval(const DPUnsuitableConst&&   , double(DPUnsuitableConst::*)()   ,  false   );
    make_rval(const DPUnsuitableMutable&& , double(DPUnsuitableMutable::*)() ,  false   );
    make_rval(const DPUnsuitable&&        , double(DPUnsuitable::*)()        ,  false   );
}
TEST_COMPONENT(050)
{
    //       |   type                     | signature                              | expected |
    make_test(const DPUnsuitableConst     , double(DPUnsuitableConst::*)()   const ,  false   );
    make_test(const DPUnsuitableMutable   , double(DPUnsuitableMutable::*)() const ,  false   );
    make_test(const DPUnsuitable          , double(DPUnsuitable::*)()        const ,  false   );

    make_test(const DPUnsuitableConst&    , double(DPUnsuitableConst::*)()   const ,  false   );
    make_test(const DPUnsuitableMutable&  , double(DPUnsuitableMutable::*)() const ,  false   );
    make_test(const DPUnsuitable&         , double(DPUnsuitable::*)()        const ,  false   );

    make_rval(const DPUnsuitableConst&&   , double(DPUnsuitableConst::*)()   const ,  false   );
    make_rval(const DPUnsuitableMutable&& , double(DPUnsuitableMutable::*)() const ,  false   );
    make_rval(const DPUnsuitable&&        , double(DPUnsuitable::*)()        const ,  false   );
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
#endif // !TEST_TOOLS_SFINAE_DEREFERENCE