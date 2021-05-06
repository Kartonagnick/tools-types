// [2021y-05m-04d][21:27:57] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_ACCESS
#define dTEST_COMPONENT tools, types, sfinae, signature
#define dTEST_METHOD access
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

    #define dTEST_SFINAE_BODY             1
    #define dTEST_SFINAE_DBODY            1
    #define dTEST_SFINAE_PBODY            1
    #define dTEST_SFINAE_DPBODY           1
#elif defined(dHAS_VARIADIC_TEMPLATE) 
    // msvc2013
    //   - has bug:
    //     - error: private/protected access
    //     - error: derived

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

    #define dTEST_SFINAE_BODY             1
    // #define dTEST_SFINAE_DBODY         1
    // #define dTEST_SFINAE_PBODY         0
    // #define dTEST_SFINAE_DPBODY        0
#elif defined(dHAS_ENUM_CLASS) 
    // msvc2012
    //   - has bug:
    //     - not worked: private/protected access
    //     - not worked: derived

    #define dTEST_SFINAE_REGULAR          1
    // #define dTEST_SFINAE_DERIVED       1
    // #define dTEST_SFINAE_PRIVATE       0
    // #define dTEST_SFINAE_DPRVATE       0
    
    #define dTEST_SFINAE_RECURSIEVE       1
    // #define dTEST_SFINAE_DRECURSIEVE   1
    // #define dTEST_SFINAE_PRECURSIEVE   0
    // #define dTEST_SFINAE_DPRECURSIEVE  0
    
    #define dTEST_SFINAE_UNSUITABLE       1
    #define dTEST_SFINAE_DUNSUITABLE      1
    // #define dTEST_SFINAE_PUNSUITABLE   1
    // #define dTEST_SFINAE_DPUNSUITABLE  1
    
    #define dTEST_SFINAE_INT              1
    // #define dTEST_SFINAE_DINT          1
    // #define dTEST_SFINAE_PINT          0
    // #define dTEST_SFINAE_DPINT         0

    #define dTEST_SFINAE_BODY             1
    // #define dTEST_SFINAE_DBODY         1
    // #define dTEST_SFINAE_PBODY         0
    // #define dTEST_SFINAE_DPBODY        0

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

    #define dTEST_SFINAE_BODY             1
    // #define dTEST_SFINAE_DBODY         1
    // #define dTEST_SFINAE_PBODY         0
    // #define dTEST_SFINAE_DPBODY        0

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

    #define dTEST_SFINAE_BODY             1
    // #define dTEST_SFINAE_DBODY         1
    // #define dTEST_SFINAE_PBODY         0
    // #define dTEST_SFINAE_DPBODY        0
#endif

namespace
{
    #if defined (dTEST_SFINAE_PRIVATE) &&  dTEST_SFINAE_PRIVATE == 0
        const bool privat = true;
    #else
        const bool privat = false;
    #endif
}

#include "test-access.hpp"
#include "test-signa.hpp"

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_REGULAR
// --- simple false
TEST_COMPONENT(000)
{
    //       |   type   | signature              | expected |
    make_test(Maket     , void(Maket::*)(size_t) ,  false   );
    make_test(Dummy     , void(Dummy::*)(size_t) ,  false   );
    make_test(int       , void(Maket::*)(size_t) ,  false   );
    make_test(int()     , void(Maket::*)(size_t) ,  false   );
//------------------------------------------
    make_test(Maket&    , void(Maket::*)(size_t) ,  false   );
    make_test(Dummy&    , void(Dummy::*)(size_t) ,  false   );
    make_test(int&      , void(Maket::*)(size_t) ,  false   );
    make_test(int(&)()  , void(Maket::*)(size_t) ,  false   );
//------------------------------------------
    make_rval(Maket&&   , void(Maket::*)(size_t) ,  false   );
    make_rval(Dummy&&   , void(Dummy::*)(size_t) ,  false   );
    make_rval(int&&     , void(Maket::*)(size_t) ,  false   );
    make_rval(int(&&)() , void(Maket::*)(size_t) ,  false   );
//------------------------------------------
    make_test(Maket*    , void(Maket::*)(size_t) ,  false   );
    make_test(Dummy*    , void(Dummy::*)(size_t) ,  false   );
    make_test(int*      , void(Maket::*)(size_t) ,  false   );
    make_test(int(*)()  , void(Maket::*)(size_t) ,  false   );
}
TEST_COMPONENT(001)
{
    //       |   type   | signature                   | expected |
    make_test(Maket     , void(Maket::*)(size_t) const,  false   );
    make_test(Dummy     , void(Dummy::*)(size_t) const,  false   );
    make_test(int       , void(Maket::*)(size_t) const,  false   );
    make_test(int()     , void(Maket::*)(size_t) const,  false   );
//------------------------------------------
    make_test(Maket&    , void(Maket::*)(size_t) const,  false   );
    make_test(Dummy&    , void(Dummy::*)(size_t) const,  false   );
    make_test(int&      , void(Maket::*)(size_t) const,  false   );
    make_test(int(&)()  , void(Maket::*)(size_t) const,  false   );
//------------------------------------------
    make_rval(Maket&&   , void(Maket::*)(size_t) const,  false   );
    make_rval(Dummy&&   , void(Dummy::*)(size_t) const,  false   );
    make_rval(int&&     , void(Maket::*)(size_t) const,  false   );
    make_rval(int(&&)() , void(Maket::*)(size_t) const,  false   );
//------------------------------------------
    make_test(Maket*    , void(Maket::*)(size_t) const,  false   );
    make_test(Dummy*    , void(Dummy::*)(size_t) const,  false   );
    make_test(int*      , void(Maket::*)(size_t) const,  false   );
    make_test(int(*)()  , void(Maket::*)(size_t) const,  false   );
}

// --- non-const
TEST_COMPONENT(002)
{
    //       |   type     | signature                  | expected |
    make_test(Const       , void(Const::*)(size_t)     ,  false   );
    make_test(Mutable     , void(Mutable::*)(size_t)   ,  true    );
    make_test(Container   , void(Container::*)(size_t) ,  true    );

    make_test(Const&      , void(Const::*)(size_t)     ,  false   );
    make_test(Mutable&    , void(Mutable::*)(size_t)   ,  true    );
    make_test(Container&  , void(Container::*)(size_t) ,  true    );

    make_rval(Const&&     , void(Const::*)(size_t)     ,  false   );
    make_rval(Mutable&&   , void(Mutable::*)(size_t)   ,  true    );
    make_rval(Container&& , void(Container::*)(size_t) ,  true    );
}
TEST_COMPONENT(003)
{
    //       |   type     | signature                 | expected |
    make_test(Const       , void(Const::*)(size_t)     const,  true    );
    make_test(Mutable     , void(Mutable::*)(size_t)   const,  false   );
    make_test(Container   , void(Container::*)(size_t) const,  true    );

    make_test(Const&      , void(Const::*)(size_t)     const,  true    );
    make_test(Mutable&    , void(Mutable::*)(size_t)   const,  false   );
    make_test(Container&  , void(Container::*)(size_t) const,  true    );

    make_rval(Const&&     , void(Const::*)(size_t)     const,  true    );
    make_rval(Mutable&&   , void(Mutable::*)(size_t)   const,  false   );
    make_rval(Container&& , void(Container::*)(size_t) const,  true    );
}

// --- const
TEST_COMPONENT(004)
{
    //       |   type           | signature            | expected |
    make_test(const Const       , void(Const::*)(size_t)     ,  false   );
    make_test(const Mutable     , void(Mutable::*)(size_t)   ,  true    );
    make_test(const Container   , void(Container::*)(size_t) ,  true    );

    make_test(const Const&      , void(Const::*)(size_t)     ,  false   );
    make_test(const Mutable&    , void(Mutable::*)(size_t)   ,  true    );
    make_test(const Container&  , void(Container::*)(size_t) ,  true    );

    make_rval(const Const&&     , void(Const::*)(size_t)     ,  false   );
    make_rval(const Mutable&&   , void(Mutable::*)(size_t)   ,  true    );
    make_rval(const Container&& , void(Container::*)(size_t) ,  true    );
}
TEST_COMPONENT(005)
{
    //       |   type           | signature                 | expected |
    make_test(const Const       , void(Const::*)(size_t)     const,  true    );
    make_test(const Mutable     , void(Mutable::*)(size_t)   const,  false   );
    make_test(const Container   , void(Container::*)(size_t) const,  true    );
                                                      
    make_test(const Const&      , void(Const::*)(size_t)     const,  true    );
    make_test(const Mutable&    , void(Mutable::*)(size_t)   const,  false   );
    make_test(const Container&  , void(Container::*)(size_t) const,  true    );
                                                       
    make_rval(const Const&&     , void(Const::*)(size_t)     const,  true    );
    make_rval(const Mutable&&   , void(Mutable::*)(size_t)   const,  false   );
    make_rval(const Container&& , void(Container::*)(size_t) const,  true    );
}

#endif // dTEST_SFINAE_REGULAR

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DERIVED
// --- derived non-const
TEST_COMPONENT(006)
{
    //       |   type      | signature             | expected |
    make_test(DConst       , void(DConst::*)(size_t)     ,  false   );
    make_test(DMutable     , void(DMutable::*)(size_t)   ,  true    );
    make_test(DContainer   , void(DContainer::*)(size_t) ,  true    );

    make_test(DConst&      , void(DConst::*)(size_t)     ,  false   );
    make_test(DMutable&    , void(DMutable::*)(size_t)   ,  true    );
    make_test(DContainer&  , void(DContainer::*)(size_t) ,  true    );

    make_rval(DConst&&     , void(DConst::*)(size_t)     ,  false   );
    make_rval(DMutable&&   , void(DMutable::*)(size_t)   ,  true    );
    make_rval(DContainer&& , void(DContainer::*)(size_t) ,  true    );
}
TEST_COMPONENT(007)
{
    //       |   type      | signature                   | expected |
    make_test(DConst       , void(DConst::*)(size_t)     const ,  true    );
    make_test(DMutable     , void(DMutable::*)(size_t)   const ,  false   );
    make_test(DContainer   , void(DContainer::*)(size_t) const ,  true    );
                                                   
    make_test(DConst&      , void(DConst::*)(size_t)     const ,  true    );
    make_test(DMutable&    , void(DMutable::*)(size_t)   const ,  false   );
    make_test(DContainer&  , void(DContainer::*)(size_t) const ,  true    );
                                                   
    make_rval(DConst&&     , void(DConst::*)(size_t)     const ,  true    );
    make_rval(DMutable&&   , void(DMutable::*)(size_t)   const ,  false   );
    make_rval(DContainer&& , void(DContainer::*)(size_t) const ,  true    );
}

// --- derived const
TEST_COMPONENT(008)
{
    //       |   type            | signature                   | expected |
    make_test(const DConst       , void(DConst::*)(size_t)     ,  false   );
    make_test(const DMutable     , void(DMutable::*)(size_t)   ,  true    );
    make_test(const DContainer   , void(DContainer::*)(size_t) ,  true    );
                                                         
    make_test(const DConst&      , void(DConst::*)(size_t)     ,  false   );
    make_test(const DMutable&    , void(DMutable::*)(size_t)   ,  true    );
    make_test(const DContainer&  , void(DContainer::*)(size_t) ,  true    );
                                                         
    make_rval(const DConst&&     , void(DConst::*)(size_t)     ,  false   );
    make_rval(const DMutable&&   , void(DMutable::*)(size_t)   ,  true    );
    make_rval(const DContainer&& , void(DContainer::*)(size_t) ,  true    );
}
TEST_COMPONENT(009)
{
    //       |   type            | signature                        | expected |
    make_test(const DConst       , void(DConst::*)(size_t)     const,  true    );
    make_test(const DMutable     , void(DMutable::*)(size_t)   const,  false   );
    make_test(const DContainer   , void(DContainer::*)(size_t) const,  true    );
                                                         
    make_test(const DConst&      , void(DConst::*)(size_t)     const,  true    );
    make_test(const DMutable&    , void(DMutable::*)(size_t)   const,  false   );
    make_test(const DContainer&  , void(DContainer::*)(size_t) const,  true    );
                                                         
    make_rval(const DConst&&     , void(DConst::*)(size_t)     const,  true    );
    make_rval(const DMutable&&   , void(DMutable::*)(size_t)   const,  false   );
    make_rval(const DContainer&& , void(DContainer::*)(size_t) const,  true    );
}
#endif // dTEST_SFINAE_DERIVED

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRIVATE
// --- private non-const 
TEST_COMPONENT(010)
{
    //       |   type      | signature                   | expected |
    make_test(PConst       , void(PConst::*)(size_t)     ,  false   );
    make_test(PMutable     , void(PMutable::*)(size_t)   ,  false   );
    make_test(PContainer   , void(PContainer::*)(size_t) ,  false   );
                                  
    make_test(PConst&      , void(PConst::*)(size_t)     ,  false   );
    make_test(PMutable&    , void(PMutable::*)(size_t)   ,  false   );
    make_test(PContainer&  , void(PContainer::*)(size_t) ,  false   );
                                                     
    make_rval(PConst&&     , void(PConst::*)(size_t)     ,  false   );
    make_rval(PMutable&&   , void(PMutable::*)(size_t)   ,  false   );
    make_rval(PContainer&& , void(PContainer::*)(size_t) ,  false   );
}
TEST_COMPONENT(011)
{
    //       |   type      | signature                         | expected |
    make_test(PConst       , void(PConst::*)(size_t)     const ,  false   );
    make_test(PMutable     , void(PMutable::*)(size_t)   const ,  false   );
    make_test(PContainer   , void(PContainer::*)(size_t) const ,  false   );
                                  
    make_test(PConst&      , void(PConst::*)(size_t)     const ,  false   );
    make_test(PMutable&    , void(PMutable::*)(size_t)   const ,  false   );
    make_test(PContainer&  , void(PContainer::*)(size_t) const ,  false   );
                                  
    make_rval(PConst&&     , void(PConst::*)(size_t)     const ,  false   );
    make_rval(PMutable&&   , void(PMutable::*)(size_t)   const ,  false   );
    make_rval(PContainer&& , void(PContainer::*)(size_t) const ,  false   );
}

// --- private const 
TEST_COMPONENT(012)
{
    //       |   type            | signature                   | expected |
    make_test(const PConst       , void(PConst::*)(size_t)     ,  false   );
    make_test(const PMutable     , void(PMutable::*)(size_t)   ,  false   );
    make_test(const PContainer   , void(PContainer::*)(size_t) ,  false   );
                                        
    make_test(const PConst&      , void(PConst::*)(size_t)     ,  false   );
    make_test(const PMutable&    , void(PMutable::*)(size_t)   ,  false   );
    make_test(const PContainer&  , void(PContainer::*)(size_t) ,  false   );
                                        
    make_rval(const PConst&&     , void(PConst::*)(size_t)     ,  false   );
    make_rval(const PMutable&&   , void(PMutable::*)(size_t)   ,  false   );
    make_rval(const PContainer&& , void(PContainer::*)(size_t) ,  false   );
}
TEST_COMPONENT(013)
{
    //       |   type            | signature                         | expected |
    make_test(const PConst       , void(PConst::*)(size_t)     const ,  false   );
    make_test(const PMutable     , void(PMutable::*)(size_t)   const ,  false   );
    make_test(const PContainer   , void(PContainer::*)(size_t) const ,  false   );
                                        
    make_test(const PConst&      , void(PConst::*)(size_t)     const ,  false   );
    make_test(const PMutable&    , void(PMutable::*)(size_t)   const ,  false   );
    make_test(const PContainer&  , void(PContainer::*)(size_t) const ,  false   );
                                        
    make_rval(const PConst&&     , void(PConst::*)(size_t)     const ,  false   );
    make_rval(const PMutable&&   , void(PMutable::*)(size_t)   const ,  false   );
    make_rval(const PContainer&& , void(PContainer::*)(size_t) const ,  false   );
}
#endif // dTEST_SFINAE_PRIVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRVATE
// --- derived private non-const  
TEST_COMPONENT(014)
{
    //       |   type       | signature                    | expected |
    make_test(DPConst       , void(DPConst::*)(size_t)     ,  false   );
    make_test(DPMutable     , void(DPMutable::*)(size_t)   ,  false   );
    make_test(DPContainer   , void(DPContainer::*)(size_t) ,  false   );

    make_test(DPConst&      , void(DPConst::*)(size_t)     ,  false   );
    make_test(DPMutable&    , void(DPMutable::*)(size_t)   ,  false   );
    make_test(DPContainer&  , void(DPContainer::*)(size_t) ,  false   );

    make_rval(DPConst&&     , void(DPConst::*)(size_t)     ,  false   );
    make_rval(DPMutable&&   , void(DPMutable::*)(size_t)   ,  false   );
    make_rval(DPContainer&& , void(DPContainer::*)(size_t) ,  false   );
}
TEST_COMPONENT(015)
{
    //       |   type       | signature                          | expected |
    make_test(DPConst       , void(DPConst::*)(size_t)     const ,  false   );
    make_test(DPMutable     , void(DPMutable::*)(size_t)   const ,  false   );
    make_test(DPContainer   , void(DPContainer::*)(size_t) const ,  false   );
                                                     
    make_test(DPConst&      , void(DPConst::*)(size_t)     const ,  false   );
    make_test(DPMutable&    , void(DPMutable::*)(size_t)   const ,  false   );
    make_test(DPContainer&  , void(DPContainer::*)(size_t) const ,  false   );
                                                     
    make_rval(DPConst&&     , void(DPConst::*)(size_t)     const ,  false   );
    make_rval(DPMutable&&   , void(DPMutable::*)(size_t)   const ,  false   );
    make_rval(DPContainer&& , void(DPContainer::*)(size_t) const ,  false   );
}

// --- derived private const 
TEST_COMPONENT(016)
{
    //       |   type             | signature                    | expected |
    make_test(const DPConst       , void(DPConst::*)(size_t)     ,  false   );
    make_test(const DPMutable     , void(DPMutable::*)(size_t)   ,  false   );
    make_test(const DPContainer   , void(DPContainer::*)(size_t) ,  false   );

    make_test(const DPConst&      , void(DPConst::*)(size_t)     ,  false   );
    make_test(const DPMutable&    , void(DPMutable::*)(size_t)   ,  false   );
    make_test(const DPContainer&  , void(DPContainer::*)(size_t) ,  false   );

    make_rval(const DPConst&&     , void(DPConst::*)(size_t)     ,  false   );
    make_rval(const DPMutable&&   , void(DPMutable::*)(size_t)   ,  false   );
    make_rval(const DPContainer&& , void(DPContainer::*)(size_t) ,  false   );
}
TEST_COMPONENT(017)
{
    //       |   type             | signature                          | expected |
    make_test(const DPConst       , void(DPConst::*)(size_t)     const ,  false   );
    make_test(const DPMutable     , void(DPMutable::*)(size_t)   const ,  false   );
    make_test(const DPContainer   , void(DPContainer::*)(size_t) const ,  false   );
                                                           
    make_test(const DPConst&      , void(DPConst::*)(size_t)     const ,  false   );
    make_test(const DPMutable&    , void(DPMutable::*)(size_t)   const ,  false   );
    make_test(const DPContainer&  , void(DPContainer::*)(size_t) const ,  false   );
                                                           
    make_rval(const DPConst&&     , void(DPConst::*)(size_t)     const ,  false   );
    make_rval(const DPMutable&&   , void(DPMutable::*)(size_t)   const ,  false   );
    make_rval(const DPContainer&& , void(DPContainer::*)(size_t) const ,  false   );
}
#endif // dTEST_SFINAE_DPRVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_RECURSIEVE
// --- recursieve non-const
TEST_COMPONENT(018)
{
    //       |   type      | signature                         | expected |
    make_test(RConst       , RConst(RConst::*)(size_t)         ,  false   );
    make_test(RMutable     , RMutable(RMutable::*)(size_t)     ,  true    );
    make_test(RContainer   , RContainer(RContainer::*)(size_t) ,  true    );
              
    make_test(RConst&      , RConst(RConst::*)(size_t)         ,  false   );
    make_test(RMutable&    , RMutable(RMutable::*)(size_t)     ,  true    );
    make_test(RContainer&  , RContainer(RContainer::*)(size_t) ,  true    );
                                  
    make_rval(RConst&&     , RConst(RConst::*)(size_t)         ,  false   );
    make_rval(RMutable&&   , RMutable(RMutable::*)(size_t)     ,  true    );
    make_rval(RContainer&& , RContainer(RContainer::*)(size_t) ,  true    );
}
TEST_COMPONENT(019)
{ 
    //       |   type      | signature                               | expected |
    make_test(RConst       , RConst(RConst::*)(size_t)         const ,  true    );
    make_test(RMutable     , RMutable(RMutable::*)(size_t)     const ,  false   );
    make_test(RContainer   , RContainer(RContainer::*)(size_t) const ,  true    );
                                                          
    make_test(RConst&      , RConst(RConst::*)(size_t)         const ,  true    );
    make_test(RMutable&    , RMutable(RMutable::*)(size_t)     const ,  false   );
    make_test(RContainer&  , RContainer(RContainer::*)(size_t) const ,  true    );
                                                         
    make_rval(RConst&&     , RConst(RConst::*)(size_t)         const ,  true    );
    make_rval(RMutable&&   , RMutable(RMutable::*)(size_t)     const ,  false   );
    make_rval(RContainer&& , RContainer(RContainer::*)(size_t) const ,  true    );
}

// --- recursieve const
TEST_COMPONENT(020)
{
    //       |   type            | signature                         | expected |
    make_test(const RConst       , RConst(RConst::*)(size_t)         ,  false   );
    make_test(const RMutable     , RMutable(RMutable::*)(size_t)     ,  true    );
    make_test(const RContainer   , RContainer(RContainer::*)(size_t) ,  true    );
              
    make_test(const RConst&      , RConst(RConst::*)(size_t)         ,  false   );
    make_test(const RMutable&    , RMutable(RMutable::*)(size_t)     ,  true    );
    make_test(const RContainer&  , RContainer(RContainer::*)(size_t) ,  true    );
              
    make_rval(const RConst&&     , RConst(RConst::*)(size_t)         ,  false   );
    make_rval(const RMutable&&   , RMutable(RMutable::*)(size_t)     ,  true    );
    make_rval(const RContainer&& , RContainer(RContainer::*)(size_t) ,  true    );
}
TEST_COMPONENT(021)
{ 
    //       |   type            | signature                               | expected |
    make_test(const RConst       , RConst(RConst::*)(size_t)         const ,  true    );
    make_test(const RMutable     , RMutable(RMutable::*)(size_t)     const ,  false   );
    make_test(const RContainer   , RContainer(RContainer::*)(size_t) const ,  true    );
                                                          
    make_test(const RConst&      , RConst(RConst::*)(size_t)         const ,  true    );
    make_test(const RMutable&    , RMutable(RMutable::*)(size_t)     const ,  false   );
    make_test(const RContainer&  , RContainer(RContainer::*)(size_t) const ,  true    );
              
    make_rval(const RConst&&     , RConst(RConst::*)(size_t)         const ,  true    );
    make_rval(const RMutable&&   , RMutable(RMutable::*)(size_t)     const ,  false   );
    make_rval(const RContainer&& , RContainer(RContainer::*)(size_t) const ,  true    );
}
#endif // dTEST_SFINAE_RECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DRECURSIEVE
// --- derived recursieve non-const
TEST_COMPONENT(022)
{
    //       |   type       | signature                          | expected |
    make_test(DRConst       , RConst(DRConst::*)(size_t)         ,  false   );
    make_test(DRMutable     , RMutable(DRMutable::*)(size_t)     ,  true    );
    make_test(DRContainer   , RContainer(DRContainer::*)(size_t) ,  true    );
                                 
    make_test(DRConst&      , RConst(DRConst::*)(size_t)         ,  false   );
    make_test(DRMutable&    , RMutable(DRMutable::*)(size_t)     ,  true    );
    make_test(DRContainer&  , RContainer(DRContainer::*)(size_t) ,  true    );
    
    make_rval(DRConst&&     , RConst(DRConst::*)(size_t)         ,  false   );
    make_rval(DRMutable&&   , RMutable(DRMutable::*)(size_t)     ,  true    );
    make_rval(DRContainer&& , RContainer(DRContainer::*)(size_t) ,  true    );
}
TEST_COMPONENT(023)
{
    //       |   type       | signature                                | expected |
    make_test(DRConst       , RConst(DRConst::*)(size_t)         const ,  true    );
    make_test(DRMutable     , RMutable(DRMutable::*)(size_t)     const ,  false   );
    make_test(DRContainer   , RContainer(DRContainer::*)(size_t) const ,  true    );
                              
    make_test(DRConst&      , RConst(DRConst::*)(size_t)         const ,  true    );
    make_test(DRMutable&    , RMutable(DRMutable::*)(size_t)     const ,  false   );
    make_test(DRContainer&  , RContainer(DRContainer::*)(size_t) const ,  true    );
                              
    make_rval(DRConst&&     , RConst(DRConst::*)(size_t)         const ,  true    );
    make_rval(DRMutable&&   , RMutable(DRMutable::*)(size_t)     const ,  false   );
    make_rval(DRContainer&& , RContainer(DRContainer::*)(size_t) const ,  true    );
}

// --- derived recursieve const
TEST_COMPONENT(024)
{
    //       |   type             | signature                          | expected |
    make_test(const DRConst       , RConst(DRConst::*)(size_t)         ,  false   );
    make_test(const DRMutable     , RMutable(DRMutable::*)(size_t)     ,  true    );
    make_test(const DRContainer   , RContainer(DRContainer::*)(size_t) ,  true    );
                                 
    make_test(const DRConst&      , RConst(DRConst::*)(size_t)         ,  false   );
    make_test(const DRMutable&    , RMutable(DRMutable::*)(size_t)     ,  true    );
    make_test(const DRContainer&  , RContainer(DRContainer::*)(size_t) ,  true    );
              
    make_rval(const DRConst&&     , RConst(DRConst::*)(size_t)         ,  false   );
    make_rval(const DRMutable&&   , RMutable(DRMutable::*)(size_t)     ,  true    );
    make_rval(const DRContainer&& , RContainer(DRContainer::*)(size_t) ,  true    );
}
TEST_COMPONENT(025)
{
    //       |   type             | signature                                | expected |
    make_test(const DRConst       , RConst(DRConst::*)(size_t)         const ,  true    );
    make_test(const DRMutable     , RMutable(DRMutable::*)(size_t)     const ,  false   );
    make_test(const DRContainer   , RContainer(DRContainer::*)(size_t) const ,  true    );
                              
    make_test(const DRConst&      , RConst(DRConst::*)(size_t)         const ,  true    );
    make_test(const DRMutable&    , RMutable(DRMutable::*)(size_t)     const ,  false   );
    make_test(const DRContainer&  , RContainer(DRContainer::*)(size_t) const ,  true    );
              
    make_rval(const DRConst&&     , RConst(DRConst::*)(size_t)         const ,  true    );
    make_rval(const DRMutable&&   , RMutable(DRMutable::*)(size_t)     const ,  false   );
    make_rval(const DRContainer&& , RContainer(DRContainer::*)(size_t) const ,  true    );
}
#endif // dTEST_SFINAE_DRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRECURSIEVE
// --- private recursieve non-const 
TEST_COMPONENT(026)
{
    //       |   type       | signature                          | expected |
    make_test(PRConst       , PConst(PRConst::*)(size_t)         ,  false   );
    make_test(PRMutable     , PMutable(PRMutable::*)(size_t)     ,  false   );
    make_test(PRContainer   , PContainer(PRContainer::*)(size_t) ,  false   );
                                    
    make_test(PRConst&      , PConst(PRConst::*)(size_t)         ,  false   );
    make_test(PRMutable&    , PMutable(PRMutable::*)(size_t)     ,  false   );
    make_test(PRContainer&  , PContainer(PRContainer::*)(size_t) ,  false   );
                                    
    make_rval(PRConst&&     , PConst(PRConst::*)(size_t)         ,  false   );
    make_rval(PRMutable&&   , PMutable(PRMutable::*)(size_t)     ,  false   );
    make_rval(PRContainer&& , PContainer(PRContainer::*)(size_t) ,  false   );
}
TEST_COMPONENT(027)
{
    //       |   type       | signature                                | expected |
    make_test(PRConst       , PConst(PRConst::*)(size_t)         const ,  false   );
    make_test(PRMutable     , PMutable(PRMutable::*)(size_t)     const ,  false   );
    make_test(PRContainer   , PContainer(PRContainer::*)(size_t) const ,  false   );
                                                                 
    make_test(PRConst&      , PConst(PRConst::*)(size_t)         const ,  false   );
    make_test(PRMutable&    , PMutable(PRMutable::*)(size_t)     const ,  false   );
    make_test(PRContainer&  , PContainer(PRContainer::*)(size_t) const ,  false   );
                                                                 
    make_rval(PRConst&&     , PConst(PRConst::*)(size_t)         const ,  false   );
    make_rval(PRMutable&&   , PMutable(PRMutable::*)(size_t)     const ,  false   );
    make_rval(PRContainer&& , PContainer(PRContainer::*)(size_t) const ,  false   );
}

// --- private recursieve non-const 
TEST_COMPONENT(028)
{
    //       |   type             | signature                          | expected |
    make_test(const PRConst       , PConst(PRConst::*)(size_t)         ,  false   );
    make_test(const PRMutable     , PMutable(PRMutable::*)(size_t)     ,  false   );
    make_test(const PRContainer   , PContainer(PRContainer::*)(size_t) ,  false   );
                                    
    make_test(const PRConst&      , PConst(PRConst::*)(size_t)         ,  false   );
    make_test(const PRMutable&    , PMutable(PRMutable::*)(size_t)     ,  false   );
    make_test(const PRContainer&  , PContainer(PRContainer::*)(size_t) ,  false   );
              
    make_rval(const PRConst&&     , PConst(PRConst::*)(size_t)         ,  false   );
    make_rval(const PRMutable&&   , PMutable(PRMutable::*)(size_t)     ,  false   );
    make_rval(const PRContainer&& , PContainer(PRContainer::*)(size_t) ,  false   );
}
TEST_COMPONENT(029)
{
    //       |   type             | signature                                | expected |
    make_test(const PRConst       , PConst(PRConst::*)(size_t)         const ,  false   );
    make_test(const PRMutable     , PMutable(PRMutable::*)(size_t)     const ,  false   );
    make_test(const PRContainer   , PContainer(PRContainer::*)(size_t) const ,  false   );
                                                                 
    make_test(const PRConst&      , PConst(PRConst::*)(size_t)         const ,  false   );
    make_test(const PRMutable&    , PMutable(PRMutable::*)(size_t)     const ,  false   );
    make_test(const PRContainer&  , PContainer(PRContainer::*)(size_t) const ,  false   );
              
    make_rval(const PRConst&&     , PConst(PRConst::*)(size_t)         const ,  false   );
    make_rval(const PRMutable&&   , PMutable(PRMutable::*)(size_t)     const ,  false   );
    make_rval(const PRContainer&& , PContainer(PRContainer::*)(size_t) const ,  false   );
}
#endif // dTEST_SFINAE_PRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRECURSIEVE
// --- derived private recursieve non-const  
TEST_COMPONENT(030)
{
    //       |   type        | signature                            | expected |
    make_test(DPRConst       , PRConst(DPRConst::*)(size_t)         ,  false   );
    make_test(DPRMutable     , PRMutable(DPRMutable::*)(size_t)     ,  false   );
    make_test(DPRContainer   , PRContainer(DPRContainer::*)(size_t) ,  false   );
                
    make_test(DPRConst&      , PRConst(DPRConst::*)(size_t)         ,  false   );
    make_test(DPRMutable&    , PRMutable(DPRMutable::*)(size_t)     ,  false   );
    make_test(DPRContainer&  , PRContainer(DPRContainer::*)(size_t) ,  false   );
                
    make_rval(DPRConst&&     , PRConst(DPRConst::*)(size_t)         ,  false   );
    make_rval(DPRMutable&&   , PRMutable(DPRMutable::*)(size_t)     ,  false   );
    make_rval(DPRContainer&& , PRContainer(DPRContainer::*)(size_t) ,  false   );
}
TEST_COMPONENT(031)
{
    //       |   type        | signature                                  | expected |
    make_test(DPRConst       , PRConst(DPRConst::*)(size_t)         const ,  false   );
    make_test(DPRMutable     , PRMutable(DPRMutable::*)(size_t)     const ,  false   );
    make_test(DPRContainer   , PRContainer(DPRContainer::*)(size_t) const ,  false   );

    make_test(DPRConst&      , PRConst(DPRConst::*)(size_t)         const ,  false   );
    make_test(DPRMutable&    , PRMutable(DPRMutable::*)(size_t)     const ,  false   );
    make_test(DPRContainer&  , PRContainer(DPRContainer::*)(size_t) const ,  false   );

    make_rval(DPRConst&&     , PRConst(DPRConst::*)(size_t)         const ,  false   );
    make_rval(DPRMutable&&   , PRMutable(DPRMutable::*)(size_t)     const ,  false   );
    make_rval(DPRContainer&& , PRContainer(DPRContainer::*)(size_t) const ,  false   );
}

// --- derived private recursieve non-const  
TEST_COMPONENT(032)
{
    //       |   type              | signature                            | expected |
    make_test(const DPRConst       , PRConst(DPRConst::*)(size_t)         ,  false   );
    make_test(const DPRMutable     , PRMutable(DPRMutable::*)(size_t)     ,  false   );
    make_test(const DPRContainer   , PRContainer(DPRContainer::*)(size_t) ,  false   );
              
    make_test(const DPRConst&      , PRConst(DPRConst::*)(size_t)         ,  false   );
    make_test(const DPRMutable&    , PRMutable(DPRMutable::*)(size_t)     ,  false   );
    make_test(const DPRContainer&  , PRContainer(DPRContainer::*)(size_t) ,  false   );
                
    make_rval(const DPRConst&&     , PRConst(DPRConst::*)(size_t)         ,  false   );
    make_rval(const DPRMutable&&   , PRMutable(DPRMutable::*)(size_t)     ,  false   );
    make_rval(const DPRContainer&& , PRContainer(DPRContainer::*)(size_t) ,  false   );
}
TEST_COMPONENT(034)
{
    //       |   type              | signature                                  | expected |
    make_test(const DPRConst       , PRConst(DPRConst::*)(size_t)         const ,  false   );
    make_test(const DPRMutable     , PRMutable(DPRMutable::*)(size_t)     const ,  false   );
    make_test(const DPRContainer   , PRContainer(DPRContainer::*)(size_t) const ,  false   );
              
    make_test(const DPRConst&      , PRConst(DPRConst::*)(size_t)         const ,  false   );
    make_test(const DPRMutable&    , PRMutable(DPRMutable::*)(size_t)     const ,  false   );
    make_test(const DPRContainer&  , PRContainer(DPRContainer::*)(size_t) const ,  false   );
              
    make_rval(const DPRConst&&     , PRConst(DPRConst::*)(size_t)         const ,  false   );
    make_rval(const DPRMutable&&   , PRMutable(DPRMutable::*)(size_t)     const ,  false   );
    make_rval(const DPRContainer&& , PRContainer(DPRContainer::*)(size_t) const ,  false   );
}
#endif // dTEST_SFINAE_DPRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_UNSUITABLE
// --- non-const
TEST_COMPONENT(035)
{
    //       |   type             | signature                         | expected |
    make_test(UnsuitableConst     , void(UnsuitableConst::*)(size_t)  ,  false   );
    make_test(UnsuitableMutable   , void(UnsuitableMutable::*)(size_t),  false   );
    make_test(Unsuitable          , void(Container::*)(size_t)        ,  false   );
                                  
    make_test(UnsuitableConst&    , void(UnsuitableConst::*)(size_t)  ,  false   );
    make_test(UnsuitableMutable&  , void(UnsuitableMutable::*)(size_t),  false   );
    make_test(Unsuitable&         , void(Container::*)(size_t)        ,  false   );

    make_rval(UnsuitableConst&&   , void(UnsuitableConst::*)(size_t)  ,  false   );
    make_rval(UnsuitableMutable&& , void(UnsuitableMutable::*)(size_t),  false   );
    make_rval(Unsuitable&&        , void(Container::*)(size_t)        ,  false   );
}
TEST_COMPONENT(036)
{
    //       |   type             | signature                                | expected |
    make_test(UnsuitableConst     , void(UnsuitableConst::*)(size_t)   const ,  false   );
    make_test(UnsuitableMutable   , void(UnsuitableMutable::*)(size_t) const ,  false   );
    make_test(Unsuitable          , void(Container::*)(size_t)         const ,  false   );

    make_test(UnsuitableConst&    , void(UnsuitableConst::*)(size_t)   const ,  false   );
    make_test(UnsuitableMutable&  , void(UnsuitableMutable::*)(size_t) const ,  false   );
    make_test(Unsuitable&         , void(Container::*)(size_t)         const ,  false   );

    make_rval(UnsuitableConst&&   , void(UnsuitableConst::*)(size_t)   const ,  false   );
    make_rval(UnsuitableMutable&& , void(UnsuitableMutable::*)(size_t) const ,  false   );
    make_rval(Unsuitable&&        , void(Container::*)(size_t)         const ,  false   );
}

// --- const
TEST_COMPONENT(037)
{
    //       |   type                   | signature                          | expected |
    make_test(const UnsuitableConst     , void(UnsuitableConst::*)(size_t)   ,  false   );
    make_test(const UnsuitableMutable   , void(UnsuitableMutable::*)(size_t) ,  false   );
    make_test(const Unsuitable          , void(Unsuitable::*)(size_t)        ,  false   );
                                  
    make_test(const UnsuitableConst&    , void(UnsuitableConst::*)(size_t)   ,  false   );
    make_test(const UnsuitableMutable&  , void(UnsuitableMutable::*)(size_t) ,  false   );
    make_test(const Unsuitable&         , void(Unsuitable::*)(size_t)        ,  false   );
              
    make_rval(const UnsuitableConst&&   , void(UnsuitableConst::*)(size_t)   ,  false   );
    make_rval(const UnsuitableMutable&& , void(UnsuitableMutable::*)(size_t) ,  false   );
    make_rval(const Unsuitable&&        , void(Unsuitable::*)(size_t)        ,  false   );
}
TEST_COMPONENT(038)
{
    //       |   type                   | signature                                | expected |
    make_test(const UnsuitableConst     , void(UnsuitableConst::*)(size_t)   const ,  false   );
    make_test(const UnsuitableMutable   , void(UnsuitableMutable::*)(size_t) const ,  false   );
    make_test(const Unsuitable          , void(Unsuitable::*)(size_t)        const ,  false   );

    make_test(const UnsuitableConst&    , void(UnsuitableConst::*)(size_t)   const ,  false   );
    make_test(const UnsuitableMutable&  , void(UnsuitableMutable::*)(size_t) const ,  false   );
    make_test(const Unsuitable&         , void(Unsuitable::*)(size_t)        const ,  false   );

    make_rval(const UnsuitableConst&&   , void(UnsuitableConst::*)(size_t)   const ,  false   );
    make_rval(const UnsuitableMutable&& , void(UnsuitableMutable::*)(size_t) const ,  false   );
    make_rval(const Unsuitable&&        , void(Unsuitable::*)(size_t)        const ,  false   );
}
#endif // dTEST_SFINAE_UNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DUNSUITABLE
// --- non-const
TEST_COMPONENT(039)
{
    //       |   type              | signature                          | expected |
    make_test(DUnsuitableConst     , void(DUnsuitableConst::*)(size_t)  ,  false   );
    make_test(DUnsuitableMutable   , void(DUnsuitableMutable::*)(size_t),  false   );
    make_test(DUnsuitable          , void(DUnsuitable::*)(size_t)       ,  false   );
                                          
    make_test(DUnsuitableConst&    , void(DUnsuitableConst::*)(size_t)  ,  false   );
    make_test(DUnsuitableMutable&  , void(DUnsuitableMutable::*)(size_t),  false   );
    make_test(DUnsuitable&         , void(DUnsuitable::*)(size_t)       ,  false   );
                                          
    make_rval(DUnsuitableConst&&   , void(DUnsuitableConst::*)(size_t)  ,  false   );
    make_rval(DUnsuitableMutable&& , void(DUnsuitableMutable::*)(size_t),  false   );
    make_rval(DUnsuitable&&        , void(DUnsuitable::*)(size_t)       ,  false   );
}
TEST_COMPONENT(040)
{
    //       |   type              | signature                                 | expected |
    make_test(DUnsuitableConst     , void(DUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(DUnsuitableMutable   , void(DUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(DUnsuitable          , void(DUnsuitable::*)(size_t)        const ,  false   );
              
    make_test(DUnsuitableConst&    , void(DUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(DUnsuitableMutable&  , void(DUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(DUnsuitable&         , void(DUnsuitable::*)(size_t)        const ,  false   );
              
    make_rval(DUnsuitableConst&&   , void(DUnsuitableConst::*)(size_t)   const ,  false   );
    make_rval(DUnsuitableMutable&& , void(DUnsuitableMutable::*)(size_t) const ,  false   );
    make_rval(DUnsuitable&&        , void(DUnsuitable::*)(size_t)        const ,  false   );
}

// --- const
TEST_COMPONENT(041)
{ 
    //       |   type                    | signature                          | expected |
    make_test(const DUnsuitableConst     , void(DUnsuitableConst::*)(size_t)  ,  false   );
    make_test(const DUnsuitableMutable   , void(DUnsuitableMutable::*)(size_t),  false   );
    make_test(const DUnsuitable          , void(DUnsuitable::*)(size_t)       ,  false   );

    make_test(const DUnsuitableConst&    , void(DUnsuitableConst::*)(size_t)  ,  false   );
    make_test(const DUnsuitableMutable&  , void(DUnsuitableMutable::*)(size_t),  false   );
    make_test(const DUnsuitable&         , void(DUnsuitable::*)(size_t)       ,  false   );

    make_rval(const DUnsuitableConst&&   , void(DUnsuitableConst::*)(size_t)  ,  false   );
    make_rval(const DUnsuitableMutable&& , void(DUnsuitableMutable::*)(size_t),  false   );
    make_rval(const DUnsuitable&&        , void(DUnsuitable::*)(size_t)       ,  false   );
}
TEST_COMPONENT(042)
{
    //       |   type                    | signature                                 | expected |
    make_test(const DUnsuitableConst     , void(DUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(const DUnsuitableMutable   , void(DUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(const DUnsuitable          , void(DUnsuitable::*)(size_t)        const ,  false   );

    make_test(const DUnsuitableConst&    , void(DUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(const DUnsuitableMutable&  , void(DUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(const DUnsuitable&         , void(DUnsuitable::*)(size_t)        const ,  false   );

    make_rval(const DUnsuitableConst&&   , void(DUnsuitableConst::*)(size_t)   const ,  false   );
    make_rval(const DUnsuitableMutable&& , void(DUnsuitableMutable::*)(size_t) const ,  false   );
    make_rval(const DUnsuitable&&        , void(DUnsuitable::*)(size_t)        const ,  false   );
}
#endif // dTEST_SFINAE_DUNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PUNSUITABLE
// --- non-const
TEST_COMPONENT(043)
{
    //       |   type              | signature                           | expected |
    make_test(PUnsuitableConst     , void(PUnsuitableConst::*)(size_t)   ,  false   );
    make_test(PUnsuitableMutable   , void(PUnsuitableMutable::*)(size_t) ,  false   );
    make_test(PUnsuitable          , void(PUnsuitable::*)(size_t)        ,  false   );
              													   
    make_test(PUnsuitableConst&    , void(PUnsuitableConst::*)(size_t)   ,  false   );
    make_test(PUnsuitableMutable&  , void(PUnsuitableMutable::*)(size_t) ,  false   );
    make_test(PUnsuitable&         , void(PUnsuitable::*)(size_t)        ,  false   );
              													   
    make_rval(PUnsuitableConst&&   , void(PUnsuitableConst::*)(size_t)   ,  false   );
    make_rval(PUnsuitableMutable&& , void(PUnsuitableMutable::*)(size_t) ,  false   );
    make_rval(PUnsuitable&&        , void(PUnsuitable::*)(size_t)        ,  false   );
}
TEST_COMPONENT(044)
{
    //       |   type              | signature                                 | expected |
    make_test(PUnsuitableConst     , void(PUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(PUnsuitableMutable   , void(PUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(PUnsuitable          , void(PUnsuitable::*)(size_t)        const ,  false   );
              
    make_test(PUnsuitableConst&    , void(PUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(PUnsuitableMutable&  , void(PUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(PUnsuitable&         , void(PUnsuitable::*)(size_t)        const ,  false   );
              
    make_rval(PUnsuitableConst&&   , void(PUnsuitableConst::*)(size_t)   const ,  false   );
    make_rval(PUnsuitableMutable&& , void(PUnsuitableMutable::*)(size_t) const ,  false   );
    make_rval(PUnsuitable&&        , void(PUnsuitable::*)(size_t)        const ,  false   );
}

// --- const
TEST_COMPONENT(045)
{ 
    //       |   type                    | signature                           | expected |
    make_test(const PUnsuitableConst     , void(PUnsuitableConst::*)(size_t)   ,  false   );
    make_test(const PUnsuitableMutable   , void(PUnsuitableMutable::*)(size_t) ,  false   );
    make_test(const PUnsuitable          , void(PUnsuitable::*)(size_t)        ,  false   );
                    
    make_test(const PUnsuitableConst&    , void(PUnsuitableConst::*)(size_t)   ,  false   );
    make_test(const PUnsuitableMutable&  , void(PUnsuitableMutable::*)(size_t) ,  false   );
    make_test(const PUnsuitable&         , void(PUnsuitable::*)(size_t)        ,  false   );
                    
    make_rval(const PUnsuitableConst&&   , void(PUnsuitableConst::*)(size_t)   ,  false   );
    make_rval(const PUnsuitableMutable&& , void(PUnsuitableMutable::*)(size_t) ,  false   );
    make_rval(const PUnsuitable&&        , void(PUnsuitable::*)(size_t)        ,  false   );
}
TEST_COMPONENT(046)
{
    //       |   type                    | signature                                 | expected |
    make_test(const PUnsuitableConst     , void(PUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(const PUnsuitableMutable   , void(PUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(const PUnsuitable          , void(PUnsuitable::*)(size_t)        const ,  false   );
                    
    make_test(const PUnsuitableConst&    , void(PUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(const PUnsuitableMutable&  , void(PUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(const PUnsuitable&         , void(PUnsuitable::*)(size_t)        const ,  false   );
                    
    make_rval(const PUnsuitableConst&&   , void(PUnsuitableConst::*)(size_t)   const ,  false   );
    make_rval(const PUnsuitableMutable&& , void(PUnsuitableMutable::*)(size_t) const ,  false   );
    make_rval(const PUnsuitable&&        , void(PUnsuitable::*)(size_t)        const ,  false   );
}
#endif // dTEST_SFINAE_PUNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPUNSUITABLE
// --- non-const
TEST_COMPONENT(047)
{
    //       |   type               | signature                            | expected |
    make_test(DPUnsuitableConst     , void(DPUnsuitableConst::*)(size_t)   ,  false   );
    make_test(DPUnsuitableMutable   , void(DPUnsuitableMutable::*)(size_t) ,  false   );
    make_test(DPUnsuitable          , void(DPUnsuitable::*)(size_t)        ,  false   );
              
    make_test(DPUnsuitableConst&    , void(DPUnsuitableConst::*)(size_t)   ,  false   );
    make_test(DPUnsuitableMutable&  , void(DPUnsuitableMutable::*)(size_t) ,  false   );
    make_test(DPUnsuitable&         , void(DPUnsuitable::*)(size_t)        ,  false   );
              
    make_rval(DPUnsuitableConst&&   , void(DPUnsuitableConst::*)(size_t)   ,  false   );
    make_rval(DPUnsuitableMutable&& , void(DPUnsuitableMutable::*)(size_t) ,  false   );
    make_rval(DPUnsuitable&&        , void(DPUnsuitable::*)(size_t)        ,  false   );
}
TEST_COMPONENT(048)
{
    //       |   type               | signature                                  | expected |
    make_test(DPUnsuitableConst     , void(DPUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(DPUnsuitableMutable   , void(DPUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(DPUnsuitable          , void(DPUnsuitable::*)(size_t)        const ,  false   );

    make_test(DPUnsuitableConst&    , void(DPUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(DPUnsuitableMutable&  , void(DPUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(DPUnsuitable&         , void(DPUnsuitable::*)(size_t)        const ,  false   );

    make_rval(DPUnsuitableConst&&   , void(DPUnsuitableConst::*)(size_t)   const ,  false   );
    make_rval(DPUnsuitableMutable&& , void(DPUnsuitableMutable::*)(size_t) const ,  false   );
    make_rval(DPUnsuitable&&        , void(DPUnsuitable::*)(size_t)        const ,  false   );
}

// --- const
TEST_COMPONENT(049)
{ 
    //       |   type                     | signature                            | expected |
    make_test(const DPUnsuitableConst     , void(DPUnsuitableConst::*)(size_t)   ,  false   );
    make_test(const DPUnsuitableMutable   , void(DPUnsuitableMutable::*)(size_t) ,  false   );
    make_test(const DPUnsuitable          , void(DPUnsuitable::*)(size_t)        ,  false   );
                    
    make_test(const DPUnsuitableConst&    , void(DPUnsuitableConst::*)(size_t)   ,  false   );
    make_test(const DPUnsuitableMutable&  , void(DPUnsuitableMutable::*)(size_t) ,  false   );
    make_test(const DPUnsuitable&         , void(DPUnsuitable::*)(size_t)        ,  false   );
                    
    make_rval(const DPUnsuitableConst&&   , void(DPUnsuitableConst::*)(size_t)   ,  false   );
    make_rval(const DPUnsuitableMutable&& , void(DPUnsuitableMutable::*)(size_t) ,  false   );
    make_rval(const DPUnsuitable&&        , void(DPUnsuitable::*)(size_t)        ,  false   );
}
TEST_COMPONENT(050)
{
    //       |   type                     | signature                                  | expected |
    make_test(const DPUnsuitableConst     , void(DPUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(const DPUnsuitableMutable   , void(DPUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(const DPUnsuitable          , void(DPUnsuitable::*)(size_t)        const ,  false   );

    make_test(const DPUnsuitableConst&    , void(DPUnsuitableConst::*)(size_t)   const ,  false   );
    make_test(const DPUnsuitableMutable&  , void(DPUnsuitableMutable::*)(size_t) const ,  false   );
    make_test(const DPUnsuitable&         , void(DPUnsuitable::*)(size_t)        const ,  false   );

    make_rval(const DPUnsuitableConst&&   , void(DPUnsuitableConst::*)(size_t)   const ,  false   );
    make_rval(const DPUnsuitableMutable&& , void(DPUnsuitableMutable::*)(size_t) const ,  false   );
    make_rval(const DPUnsuitable&&        , void(DPUnsuitable::*)(size_t)        const ,  false   );
}
#endif // dTEST_SFINAE_DPUNSUITABLE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_INT
// --- non-const
TEST_COMPONENT(051)
{
    //       |   type      | signature                  | expected |
    make_test(IntConst     , int(IntConst::*)(size_t)   ,   false  );
    make_test(IntMutable   , int(IntMutable::*)(size_t) ,   true   );
    make_test(Int          , int(Int::*)(size_t)        ,   true   );

    make_test(IntConst&    , int(IntConst::*)(size_t)   ,   false  );
    make_test(IntMutable&  , int(IntMutable::*)(size_t) ,   true   );
    make_test(Int&         , int(Int::*)(size_t)        ,   true   );

    make_rval(IntConst&&   , int(IntConst::*)(size_t)   ,   false  );
    make_rval(IntMutable&& , int(IntMutable::*)(size_t) ,   true   );
    make_rval(Int&&        , int(Int::*)(size_t)        ,   true   );
}
TEST_COMPONENT(052)
{
    //       |   type      | signature                        | expected |
    make_test(IntConst     , int(IntConst::*)(size_t)   const ,   true   );
    make_test(IntMutable   , int(IntMutable::*)(size_t) const ,   false  );
    make_test(Int          , int(Int::*)(size_t)        const ,   true   );

    make_test(IntConst&    , int(IntConst::*)(size_t)   const ,   true   );
    make_test(IntMutable&  , int(IntMutable::*)(size_t) const ,   false  );
    make_test(Int&         , int(Int::*)(size_t)        const ,   true   );

    make_rval(IntConst&&   , int(IntConst::*)(size_t)   const ,   true   );
    make_rval(IntMutable&& , int(IntMutable::*)(size_t) const ,   false  );
    make_rval(Int&&        , int(Int::*)(size_t)        const ,   true   );
}

// --- const
TEST_COMPONENT(053)
{
    //       |   type            | signature                  | expected |
    make_test(const IntConst     , int(IntConst::*)(size_t)   ,   false  );
    make_test(const IntMutable   , int(IntMutable::*)(size_t) ,   true   );
    make_test(const Int          , int(Int::*)(size_t)        ,   true   );

    make_test(const IntConst&    , int(IntConst::*)(size_t)   ,   false  );
    make_test(const IntMutable&  , int(IntMutable::*)(size_t) ,   true   );
    make_test(const Int&         , int(Int::*)(size_t)        ,   true   );

    make_rval(const IntConst&&   , int(IntConst::*)(size_t)   ,   false  );
    make_rval(const IntMutable&& , int(IntMutable::*)(size_t) ,   true   );
    make_rval(const Int&&        , int(Int::*)(size_t)        ,   true   );
}
TEST_COMPONENT(054)
{
    //       |   type            | signature                        | expected |
    make_test(const IntConst     , int(IntConst::*)(size_t)   const ,   true   );
    make_test(const IntMutable   , int(IntMutable::*)(size_t) const ,   false  );
    make_test(const Int          , int(Int::*)(size_t)        const ,   true   );
              
    make_test(const IntConst&    , int(IntConst::*)(size_t)   const ,   true   );
    make_test(const IntMutable&  , int(IntMutable::*)(size_t) const ,   false  );
    make_test(const Int&         , int(Int::*)(size_t)        const ,   true   );
              
    make_rval(const IntConst&&   , int(IntConst::*)(size_t)   const ,   true   );
    make_rval(const IntMutable&& , int(IntMutable::*)(size_t) const ,   false  );
    make_rval(const Int&&        , int(Int::*)(size_t)        const ,   true   );
}
#endif // dTEST_SFINAE_INT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DINT
// --- non-const
TEST_COMPONENT(055)
{
    //       |   type       | signature                   | expected |
    make_test(DIntConst     , int(DIntConst::*)(size_t)   ,   false  );
    make_test(DIntMutable   , int(DIntMutable::*)(size_t) ,   true   );
    make_test(DInt          , int(DInt::*)(size_t)        ,   true   );
              
    make_test(DIntConst&    , int(DIntConst::*)(size_t)   ,   false  );
    make_test(DIntMutable&  , int(DIntMutable::*)(size_t) ,   true   );
    make_test(DInt&         , int(DInt::*)(size_t)        ,   true   );
              
    make_rval(DIntConst&&   , int(DIntConst::*)(size_t)   ,   false  );
    make_rval(DIntMutable&& , int(DIntMutable::*)(size_t) ,   true   );
    make_rval(DInt&&        , int(DInt::*)(size_t)        ,   true   );
}
TEST_COMPONENT(056)
{
    //       |   type       | signature                         | expected |
    make_test(DIntConst     , int(DIntConst::*)(size_t)   const ,   true   );
    make_test(DIntMutable   , int(DIntMutable::*)(size_t) const ,   false  );
    make_test(DInt          , int(DInt::*)(size_t)        const ,   true   );
              
    make_test(DIntConst&    , int(DIntConst::*)(size_t)   const ,   true   );
    make_test(DIntMutable&  , int(DIntMutable::*)(size_t) const ,   false  );
    make_test(DInt&         , int(DInt::*)(size_t)        const ,   true   );
              
    make_rval(DIntConst&&   , int(DIntConst::*)(size_t)   const ,   true   );
    make_rval(DIntMutable&& , int(DIntMutable::*)(size_t) const ,   false  );
    make_rval(DInt&&        , int(DInt::*)(size_t)        const ,   true   );
}

// --- const
TEST_COMPONENT(057)
{
    //       |   type             | signature                   | expected |
    make_test(const DIntConst     , int(DIntConst::*)(size_t)   ,   false  );
    make_test(const DIntMutable   , int(DIntMutable::*)(size_t) ,   true   );
    make_test(const DInt          , int(DInt::*)(size_t)        ,   true   );
                    
    make_test(const DIntConst&    , int(DIntConst::*)(size_t)   ,   false  );
    make_test(const DIntMutable&  , int(DIntMutable::*)(size_t) ,   true   );
    make_test(const DInt&         , int(DInt::*)(size_t)        ,   true   );
                    
    make_rval(const DIntConst&&   , int(DIntConst::*)(size_t)   ,   false  );
    make_rval(const DIntMutable&& , int(DIntMutable::*)(size_t) ,   true   );
    make_rval(const DInt&&        , int(DInt::*)(size_t)        ,   true   );
}
TEST_COMPONENT(058)
{
    //       |   type             | signature                         | expected |
    make_test(const DIntConst     , int(DIntConst::*)(size_t)   const ,   true   );
    make_test(const DIntMutable   , int(DIntMutable::*)(size_t) const ,   false  );
    make_test(const DInt          , int(DInt::*)(size_t)        const ,   true   );
                    
    make_test(const DIntConst&    , int(DIntConst::*)(size_t)   const ,   true   );
    make_test(const DIntMutable&  , int(DIntMutable::*)(size_t) const ,   false  );
    make_test(const DInt&         , int(DInt::*)(size_t)        const ,   true   );
                    
    make_rval(const DIntConst&&   , int(DIntConst::*)(size_t)   const ,   true   );
    make_rval(const DIntMutable&& , int(DIntMutable::*)(size_t) const ,   false  );
    make_rval(const DInt&&        , int(DInt::*)(size_t)        const ,   true   );
}
#endif // dTEST_SFINAE_DINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PINT
// --- non-const
TEST_COMPONENT(059)
{
    //       |   type       | signature                   | expected |
    make_test(PIntConst     , int(PIntConst::*)(size_t)   ,   false  );
    make_test(PIntMutable   , int(PIntMutable::*)(size_t) ,   false  );
    make_test(PInt          , int(PInt::*)(size_t)        ,   false  );

    make_test(PIntConst&    , int(PIntConst::*)(size_t)   ,   false  );
    make_test(PIntMutable&  , int(PIntMutable::*)(size_t) ,   false  );
    make_test(PInt&         , int(PInt::*)(size_t)        ,   false  );

    make_rval(PIntConst&&   , int(PIntConst::*)(size_t)   ,   false  );
    make_rval(PIntMutable&& , int(PIntMutable::*)(size_t) ,   false  );
    make_rval(PInt&&        , int(PInt::*)(size_t)        ,   false  );
}
TEST_COMPONENT(060)
{
    //       |   type       | signature                         | expected |
    make_test(PIntConst     , int(PIntConst::*)(size_t)   const ,   false  );
    make_test(PIntMutable   , int(PIntMutable::*)(size_t) const ,   false  );
    make_test(PInt          , int(PInt::*)(size_t)        const ,   false  );
              
    make_test(PIntConst&    , int(PIntConst::*)(size_t)   const ,   false  );
    make_test(PIntMutable&  , int(PIntMutable::*)(size_t) const ,   false  );
    make_test(PInt&         , int(PInt::*)(size_t)        const ,   false  );
              
    make_rval(PIntConst&&   , int(PIntConst::*)(size_t)   const ,   false  );
    make_rval(PIntMutable&& , int(PIntMutable::*)(size_t) const ,   false  );
    make_rval(PInt&&        , int(PInt::*)(size_t)        const ,   false  );
}

// --- const
TEST_COMPONENT(061)
{
    //       |   type             | signature                   | expected |
    make_test(const PIntConst     , int(PIntConst::*)(size_t)   ,   false  );
    make_test(const PIntMutable   , int(PIntMutable::*)(size_t) ,   false  );
    make_test(const PInt          , int(PInt::*)(size_t)        ,   false  );
                    
    make_test(const PIntConst&    , int(PIntConst::*)(size_t)   ,   false  );
    make_test(const PIntMutable&  , int(PIntMutable::*)(size_t) ,   false  );
    make_test(const PInt&         , int(PInt::*)(size_t)        ,   false  );
                    
    make_rval(const PIntConst&&   , int(PIntConst::*)(size_t)   ,   false  );
    make_rval(const PIntMutable&& , int(PIntMutable::*)(size_t) ,   false  );
    make_rval(const PInt&&        , int(PInt::*)(size_t)        ,   false  );
}
TEST_COMPONENT(062)
{
    //       |   type             | signature                         | expected |
    make_test(const PIntConst     , int(PIntConst::*)(size_t)   const ,   false  );
    make_test(const PIntMutable   , int(PIntMutable::*)(size_t) const ,   false  );
    make_test(const PInt          , int(PInt::*)(size_t)        const ,   false  );

    make_test(const PIntConst&    , int(PIntConst::*)(size_t)   const ,   false  );
    make_test(const PIntMutable&  , int(PIntMutable::*)(size_t) const ,   false  );
    make_test(const PInt&         , int(PInt::*)(size_t)        const ,   false  );

    make_rval(const PIntConst&&   , int(PIntConst::*)(size_t)   const ,   false  );
    make_rval(const PIntMutable&& , int(PIntMutable::*)(size_t) const ,   false  );
    make_rval(const PInt&&        , int(PInt::*)(size_t)        const ,   false  );
}
#endif // dTEST_SFINAE_PINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPINT
// --- non-const
TEST_COMPONENT(063)
{
    //       |   type        | signature                    | expected |
    make_test(DPIntConst     , int(DPIntConst::*)(size_t)   ,   false  );
    make_test(DPIntMutable   , int(DPIntMutable::*)(size_t) ,   false  );
    make_test(DPInt          , int(DPInt::*)(size_t)        ,   false  );
              
    make_test(DPIntConst&    , int(DPIntConst::*)(size_t)   ,   false  );
    make_test(DPIntMutable&  , int(DPIntMutable::*)(size_t) ,   false  );
    make_test(DPInt&         , int(DPInt::*)(size_t)        ,   false  );
              
    make_rval(DPIntConst&&   , int(DPIntConst::*)(size_t)   ,   false  );
    make_rval(DPIntMutable&& , int(DPIntMutable::*)(size_t) ,   false  );
    make_rval(DPInt&&        , int(DPInt::*)(size_t)        ,   false  );
}
TEST_COMPONENT(064)
{
    //       |   type        | signature                          | expected |
    make_test(DPIntConst     , int(DPIntConst::*)(size_t)   const ,   false  );
    make_test(DPIntMutable   , int(DPIntMutable::*)(size_t) const ,   false  );
    make_test(DPInt          , int(DPInt::*)(size_t)        const ,   false  );
              
    make_test(DPIntConst&    , int(DPIntConst::*)(size_t)   const ,   false  );
    make_test(DPIntMutable&  , int(DPIntMutable::*)(size_t) const ,   false  );
    make_test(DPInt&         , int(DPInt::*)(size_t)        const ,   false  );
              
    make_rval(DPIntConst&&   , int(DPIntConst::*)(size_t)   const ,   false  );
    make_rval(DPIntMutable&& , int(DPIntMutable::*)(size_t) const ,   false  );
    make_rval(DPInt&&        , int(DPInt::*)(size_t)        const ,   false  );
}

// --- const
TEST_COMPONENT(065)
{
    //       |   type              | signature                    | expected |
    make_test(const DPIntConst     , int(DPIntConst::*)(size_t)   ,   false  );
    make_test(const DPIntMutable   , int(DPIntMutable::*)(size_t) ,   false  );
    make_test(const DPInt          , int(DPInt::*)(size_t)        ,   false  );
                    
    make_test(const DPIntConst&    , int(DPIntConst::*)(size_t)   ,   false  );
    make_test(const DPIntMutable&  , int(DPIntMutable::*)(size_t) ,   false  );
    make_test(const DPInt&         , int(DPInt::*)(size_t)        ,   false  );
                    
    make_rval(const DPIntConst&&   , int(DPIntConst::*)(size_t)   ,   false  );
    make_rval(const DPIntMutable&& , int(DPIntMutable::*)(size_t) ,   false  );
    make_rval(const DPInt&&        , int(DPInt::*)(size_t)        ,   false  );
}
TEST_COMPONENT(066)
{
    //       |   type              | signature                          | expected |
    make_test(const DPIntConst     , int(DPIntConst::*)(size_t)   const ,   false  );
    make_test(const DPIntMutable   , int(DPIntMutable::*)(size_t) const ,   false  );
    make_test(const DPInt          , int(DPInt::*)(size_t)        const ,   false  );
                    
    make_test(const DPIntConst&    , int(DPIntConst::*)(size_t)   const ,   false  );
    make_test(const DPIntMutable&  , int(DPIntMutable::*)(size_t) const ,   false  );
    make_test(const DPInt&         , int(DPInt::*)(size_t)        const ,   false  );
                    
    make_rval(const DPIntConst&&   , int(DPIntConst::*)(size_t)   const ,   false  );
    make_rval(const DPIntMutable&& , int(DPIntMutable::*)(size_t) const ,   false  );
    make_rval(const DPInt&&        , int(DPInt::*)(size_t)        const ,   false  );
}
#endif // dTEST_SFINAE_DPINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_BODY
// --- non-const
TEST_COMPONENT(067)
{
    //       |   type       | signature                       | expected |
    make_test(BodyConst     , double (BodyConst::*)(size_t)   ,  false   );
    make_test(BodyMutable   , double (BodyMutable::*)(size_t) ,  true    );
    make_test(Body          , double (Body::*)(size_t)        ,  true    );

    make_test(BodyConst&    , double (BodyConst::*)(size_t)   ,  false   );
    make_test(BodyMutable&  , double (BodyMutable::*)(size_t) ,  true    );
    make_test(Body&         , double (Body::*)(size_t)        ,  true    );

    make_rval(BodyConst&&   , double (BodyConst::*)(size_t)   ,  false   );
    make_rval(BodyMutable&& , double (BodyMutable::*)(size_t) ,  true    );
    make_rval(Body&&        , double (Body::*)(size_t)        ,  true    );
}
TEST_COMPONENT(068)
{
    //       |   type       | signature                             | expected |
    make_test(BodyConst     , double (BodyConst::*)(size_t)   const ,  true    );
    make_test(BodyMutable   , double (BodyMutable::*)(size_t) const ,  false   );
    make_test(Body          , double (Body::*)(size_t)        const ,  true    );

    make_test(BodyConst&    , double (BodyConst::*)(size_t)   const ,  true    );
    make_test(BodyMutable&  , double (BodyMutable::*)(size_t) const ,  false   );
    make_test(Body&         , double (Body::*)(size_t)        const ,  true    );

    make_rval(BodyConst&&   , double (BodyConst::*)(size_t)   const ,  true    );
    make_rval(BodyMutable&& , double (BodyMutable::*)(size_t) const ,  false   );
    make_rval(Body&&        , double (Body::*)(size_t)        const ,  true    );
}

// --- const
TEST_COMPONENT(069)
{
    //       |   type             | signature                       | expected |
    make_test(const BodyConst     , double (BodyConst::*)(size_t)   ,  false   );
    make_test(const BodyMutable   , double (BodyMutable::*)(size_t) ,  true    );
    make_test(const Body          , double (Body::*)(size_t)        ,  true    );

    make_test(const BodyConst&    , double (BodyConst::*)(size_t)   ,  false   );
    make_test(const BodyMutable&  , double (BodyMutable::*)(size_t) ,  true    );
    make_test(const Body&         , double (Body::*)(size_t)        ,  true    );

    make_rval(const BodyConst&&   , double (BodyConst::*)(size_t)   ,  false   );
    make_rval(const BodyMutable&& , double (BodyMutable::*)(size_t) ,  true    );
    make_rval(const Body&&        , double (Body::*)(size_t)        ,  true    );
}
TEST_COMPONENT(070)
{
    //       |   type             | signature                             | expected |
    make_test(const BodyConst     , double (BodyConst::*)(size_t)   const ,  true    );
    make_test(const BodyMutable   , double (BodyMutable::*)(size_t) const ,  false   );
    make_test(const Body          , double (Body::*)(size_t)        const ,  true    );

    make_test(const BodyConst&    , double (BodyConst::*)(size_t)   const ,  true    );
    make_test(const BodyMutable&  , double (BodyMutable::*)(size_t) const ,  false   );
    make_test(const Body&         , double (Body::*)(size_t)        const ,  true    );

    make_rval(const BodyConst&&   , double (BodyConst::*)(size_t)   const ,  true    );
    make_rval(const BodyMutable&& , double (BodyMutable::*)(size_t) const ,  false   );
    make_rval(const Body&&        , double (Body::*)(size_t)        const ,  true    );
}
#endif // dTEST_SFINAE_BODY

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DBODY
// --- non-const
TEST_COMPONENT(071)
{
    //       |   type        | signature                        | expected |
    make_test(DBodyConst     , double (DBodyConst::*)(size_t)   ,  false   );
    make_test(DBodyMutable   , double (DBodyMutable::*)(size_t) ,  true    );
    make_test(DBody          , double (DBody::*)(size_t)        ,  true    );

    make_test(DBodyConst&    , double (DBodyConst::*)(size_t)   ,  false   );
    make_test(DBodyMutable&  , double (DBodyMutable::*)(size_t) ,  true    );
    make_test(DBody&         , double (DBody::*)(size_t)        ,  true    );

    make_rval(DBodyConst&&   , double (DBodyConst::*)(size_t)   ,  false   );
    make_rval(DBodyMutable&& , double (DBodyMutable::*)(size_t) ,  true    );
    make_rval(DBody&&        , double (DBody::*)(size_t)        ,  true    );
}
TEST_COMPONENT(072)
{
    //       |   type        | signature                              | expected |
    make_test(DBodyConst     , double (DBodyConst::*)(size_t)   const ,  true    );
    make_test(DBodyMutable   , double (DBodyMutable::*)(size_t) const ,  false   );
    make_test(DBody          , double (DBody::*)(size_t)        const ,  true    );

    make_test(DBodyConst&    , double (DBodyConst::*)(size_t)   const ,  true    );
    make_test(DBodyMutable&  , double (DBodyMutable::*)(size_t) const ,  false   );
    make_test(DBody&         , double (DBody::*)(size_t)        const ,  true    );

    make_rval(DBodyConst&&   , double (DBodyConst::*)(size_t)   const ,  true    );
    make_rval(DBodyMutable&& , double (DBodyMutable::*)(size_t) const ,  false   );
    make_rval(DBody&&        , double (DBody::*)(size_t)        const ,  true    );
}

// --- const
TEST_COMPONENT(073)
{
    //       |   type              | signature                        | expected |
    make_test(const DBodyConst     , double (DBodyConst::*)(size_t)   ,  false   );
    make_test(const DBodyMutable   , double (DBodyMutable::*)(size_t) ,  true    );
    make_test(const DBody          , double (DBody::*)(size_t)        ,  true    );

    make_test(const DBodyConst&    , double (DBodyConst::*)(size_t)   ,  false   );
    make_test(const DBodyMutable&  , double (DBodyMutable::*)(size_t) ,  true    );
    make_test(const DBody&         , double (DBody::*)(size_t)        ,  true    );

    make_rval(const DBodyConst&&   , double (DBodyConst::*)(size_t)   ,  false   );
    make_rval(const DBodyMutable&& , double (DBodyMutable::*)(size_t) ,  true    );
    make_rval(const DBody&&        , double (DBody::*)(size_t)        ,  true    );
}
TEST_COMPONENT(074)
{
    //       |   type              | signature                              | expected |
    make_test(const DBodyConst     , double (DBodyConst::*)(size_t)   const ,  true    );
    make_test(const DBodyMutable   , double (DBodyMutable::*)(size_t) const ,  false   );
    make_test(const DBody          , double (DBody::*)(size_t)        const ,  true    );

    make_test(const DBodyConst&    , double (DBodyConst::*)(size_t)   const ,  true    );
    make_test(const DBodyMutable&  , double (DBodyMutable::*)(size_t) const ,  false   );
    make_test(const DBody&         , double (DBody::*)(size_t)        const ,  true    );

    make_rval(const DBodyConst&&   , double (DBodyConst::*)(size_t)   const ,  true    );
    make_rval(const DBodyMutable&& , double (DBodyMutable::*)(size_t) const ,  false   );
    make_rval(const DBody&&        , double (DBody::*)(size_t)        const ,  true    );
}
#endif // dTEST_SFINAE_DBODY

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PBODY
// --- non-const
TEST_COMPONENT(075)
{
    //       |   type        | signature                        | expected |
    make_test(PBodyConst     , double (PBodyConst::*)(size_t)   ,  false   );
    make_test(PBodyMutable   , double (PBodyMutable::*)(size_t) ,  false   );
    make_test(PBody          , double (PBody::*)(size_t)        ,  false   );

    make_test(PBodyConst&    , double (PBodyConst::*)(size_t)   ,  false   );
    make_test(PBodyMutable&  , double (PBodyMutable::*)(size_t) ,  false   );
    make_test(PBody&         , double (PBody::*)(size_t)        ,  false   );

    make_rval(PBodyConst&&   , double (PBodyConst::*)(size_t)   ,  false   );
    make_rval(PBodyMutable&& , double (PBodyMutable::*)(size_t) ,  false   );
    make_rval(PBody&&        , double (PBody::*)(size_t)        ,  false   );
}
TEST_COMPONENT(076)
{
    //       |   type        | signature                              | expected |
    make_test(PBodyConst     , double (PBodyConst::*)(size_t)   const ,  false   );
    make_test(PBodyMutable   , double (PBodyMutable::*)(size_t) const ,  false   );
    make_test(PBody          , double (PBody::*)(size_t)        const ,  false   );

    make_test(PBodyConst&    , double (PBodyConst::*)(size_t)   const ,  false   );
    make_test(PBodyMutable&  , double (PBodyMutable::*)(size_t) const ,  false   );
    make_test(PBody&         , double (PBody::*)(size_t)        const ,  false   );

    make_rval(PBodyConst&&   , double (PBodyConst::*)(size_t)   const ,  false   );
    make_rval(PBodyMutable&& , double (PBodyMutable::*)(size_t) const ,  false   );
    make_rval(PBody&&        , double (PBody::*)(size_t)        const ,  false   );
}

// --- const
TEST_COMPONENT(077)
{
    //       |   type              | signature                        | expected |
    make_test(const PBodyConst     , double (PBodyConst::*)(size_t)   ,  false   );
    make_test(const PBodyMutable   , double (PBodyMutable::*)(size_t) ,  false   );
    make_test(const PBody          , double (PBody::*)(size_t)        ,  false   );

    make_test(const PBodyConst&    , double (PBodyConst::*)(size_t)   ,  false   );
    make_test(const PBodyMutable&  , double (PBodyMutable::*)(size_t) ,  false   );
    make_test(const PBody&         , double (PBody::*)(size_t)        ,  false   );

    make_rval(const PBodyConst&&   , double (PBodyConst::*)(size_t)   ,  false   );
    make_rval(const PBodyMutable&& , double (PBodyMutable::*)(size_t) ,  false   );
    make_rval(const PBody&&        , double (PBody::*)(size_t)        ,  false   );
}
TEST_COMPONENT(078)
{
    //       |   type              | signature                              | expected |
    make_test(const PBodyConst     , double (PBodyConst::*)(size_t)   const ,  false   );
    make_test(const PBodyMutable   , double (PBodyMutable::*)(size_t) const ,  false   );
    make_test(const PBody          , double (PBody::*)(size_t)        const ,  false   );

    make_test(const PBodyConst&    , double (PBodyConst::*)(size_t)   const ,  false   );
    make_test(const PBodyMutable&  , double (PBodyMutable::*)(size_t) const ,  false   );
    make_test(const PBody&         , double (PBody::*)(size_t)        const ,  false   );

    make_rval(const PBodyConst&&   , double (PBodyConst::*)(size_t)   const ,  false   );
    make_rval(const PBodyMutable&& , double (PBodyMutable::*)(size_t) const ,  false   );
    make_rval(const PBody&&        , double (PBody::*)(size_t)        const ,  false   );
}
#endif // dTEST_SFINAE_PBODY

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPBODY
// --- non-const
TEST_COMPONENT(079)
{
    //       |   type         | signature                         | expected |
    make_test(DPBodyConst     , double (DPBodyConst::*)(size_t)   ,  false   );
    make_test(DPBodyMutable   , double (DPBodyMutable::*)(size_t) ,  false   );
    make_test(DPBody          , double (DPBody::*)(size_t)        ,  false   );

    make_test(DPBodyConst&    , double (DPBodyConst::*)(size_t)   ,  false   );
    make_test(DPBodyMutable&  , double (DPBodyMutable::*)(size_t) ,  false   );
    make_test(DPBody&         , double (DPBody::*)(size_t)        ,  false   );

    make_rval(DPBodyConst&&   , double (DPBodyConst::*)(size_t)   ,  false   );
    make_rval(DPBodyMutable&& , double (DPBodyMutable::*)(size_t) ,  false   );
    make_rval(DPBody&&        , double (DPBody::*)(size_t)        ,  false   );
}
TEST_COMPONENT(080)
{
    //       |   type         | signature                               | expected |
    make_test(DPBodyConst     , double (DPBodyConst::*)(size_t)   const ,  false   );
    make_test(DPBodyMutable   , double (DPBodyMutable::*)(size_t) const ,  false   );
    make_test(DPBody          , double (DPBody::*)(size_t)        const ,  false   );

    make_test(DPBodyConst&    , double (DPBodyConst::*)(size_t)   const ,  false   );
    make_test(DPBodyMutable&  , double (DPBodyMutable::*)(size_t) const ,  false   );
    make_test(DPBody&         , double (DPBody::*)(size_t)        const ,  false   );

    make_rval(DPBodyConst&&   , double (DPBodyConst::*)(size_t)   const ,  false   );
    make_rval(DPBodyMutable&& , double (DPBodyMutable::*)(size_t) const ,  false   );
    make_rval(DPBody&&        , double (DPBody::*)(size_t)        const ,  false   );
}

// --- const
TEST_COMPONENT(081)
{
    //       |   type               | signature                         | expected |
    make_test(const DPBodyConst     , double (DPBodyConst::*)(size_t)   ,  false   );
    make_test(const DPBodyMutable   , double (DPBodyMutable::*)(size_t) ,  false   );
    make_test(const DPBody          , double (DPBody::*)(size_t)        ,  false   );

    make_test(const DPBodyConst&    , double (DPBodyConst::*)(size_t)   ,  false   );
    make_test(const DPBodyMutable&  , double (DPBodyMutable::*)(size_t) ,  false   );
    make_test(const DPBody&         , double (DPBody::*)(size_t)        ,  false   );

    make_rval(const DPBodyConst&&   , double (DPBodyConst::*)(size_t)   ,  false   );
    make_rval(const DPBodyMutable&& , double (DPBodyMutable::*)(size_t) ,  false   );
    make_rval(const DPBody&&        , double (DPBody::*)(size_t)        ,  false   );
}
TEST_COMPONENT(082)
{
    //       |   type               | signature                               | expected |
    make_test(const DPBodyConst     , double (DPBodyConst::*)(size_t)   const ,  false   );
    make_test(const DPBodyMutable   , double (DPBodyMutable::*)(size_t) const ,  false   );
    make_test(const DPBody          , double (DPBody::*)(size_t)        const ,  false   );

    make_test(const DPBodyConst&    , double (DPBodyConst::*)(size_t)   const ,  false   );
    make_test(const DPBodyMutable&  , double (DPBodyMutable::*)(size_t) const ,  false   );
    make_test(const DPBody&         , double (DPBody::*)(size_t)        const ,  false   );

    make_rval(const DPBodyConst&&   , double (DPBodyConst::*)(size_t)   const ,  false   );
    make_rval(const DPBodyMutable&& , double (DPBodyMutable::*)(size_t) const ,  false   );
    make_rval(const DPBody&&        , double (DPBody::*)(size_t)        const ,  false   );
}
#endif // dTEST_SFINAE_DPBODY

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_SFINAE_ACCESS