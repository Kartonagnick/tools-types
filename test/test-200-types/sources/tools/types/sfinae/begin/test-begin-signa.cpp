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
    //     - ignore private/protected access

    #define dTEST_SFINAE_REGULAR          1
    #define dTEST_SFINAE_DERIVED          1
    #define dTEST_SFINAE_PRIVATE          0
    #define dTEST_SFINAE_DPRVATE          0
                                          
    #define dTEST_SFINAE_RECURSIEVE       1
    #define dTEST_SFINAE_DRECURSIEVE      1
    #define dTEST_SFINAE_PRECURSIEVE      0
    #define dTEST_SFINAE_DPRECURSIEVE     0

    #define dTEST_SFINAE_UNSUITABLE       1
    #define dTEST_SFINAE_DUNSUITABLE      1
    #define dTEST_SFINAE_PUNSUITABLE      1
    #define dTEST_SFINAE_DPUNSUITABLE     1

    #define dTEST_SFINAE_INT              1
    #define dTEST_SFINAE_DINT             1
    #define dTEST_SFINAE_PINT             0
    #define dTEST_SFINAE_DPINT            0

#elif defined(dHAS_ENUM_CLASS) 
    // msvc2012
    //   - has bug:
    //     - ignore private/protected access

    #define dTEST_SFINAE_REGULAR          1
    #define dTEST_SFINAE_DERIVED          1
    #define dTEST_SFINAE_PRIVATE          0
    #define dTEST_SFINAE_DPRVATE          0

    #define dTEST_SFINAE_RECURSIEVE       1
    #define dTEST_SFINAE_DRECURSIEVE      1
    #define dTEST_SFINAE_PRECURSIEVE      0
    #define dTEST_SFINAE_DPRECURSIEVE     0

    #define dTEST_SFINAE_UNSUITABLE       1
    #define dTEST_SFINAE_DUNSUITABLE      1
    #define dTEST_SFINAE_PUNSUITABLE      1
    #define dTEST_SFINAE_DPUNSUITABLE     1

    #define dTEST_SFINAE_INT              1
    #define dTEST_SFINAE_DINT             1
    #define dTEST_SFINAE_PINT             0
    #define dTEST_SFINAE_DPINT            0

#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2010
    //   - has bug:
    //     - not worked: private/protected access
    //     - not worked: derived for int()

    #define dTEST_SFINAE_REGULAR          1
    #define dTEST_SFINAE_DERIVED          1
    #define dTEST_SFINAE_PRIVATE          0
    #define dTEST_SFINAE_DPRVATE          0

    #define dTEST_SFINAE_RECURSIEVE       1
    #define dTEST_SFINAE_DRECURSIEVE      1
    #define dTEST_SFINAE_PRECURSIEVE      0
    #define dTEST_SFINAE_DPRECURSIEVE     0

    #define dTEST_SFINAE_UNSUITABLE       1
    #define dTEST_SFINAE_DUNSUITABLE      1
    #define dTEST_SFINAE_PUNSUITABLE      0
    #define dTEST_SFINAE_DPUNSUITABLE     0

    #define dTEST_SFINAE_INT              1
    #define dTEST_SFINAE_DINT             1
    #define dTEST_SFINAE_PINT             0
    #define dTEST_SFINAE_DPINT            0

#else
    // msvc20008 or older
    #define dTEST_SFINAE_REGULAR          1
    #define dTEST_SFINAE_DERIVED          1
    #define dTEST_SFINAE_PRIVATE          0
    #define dTEST_SFINAE_DPRVATE          0
                                          
    #define dTEST_SFINAE_RECURSIEVE       1
    #define dTEST_SFINAE_DRECURSIEVE      1
    #define dTEST_SFINAE_PRECURSIEVE      0
    #define dTEST_SFINAE_DPRECURSIEVE     0
                                          
    #define dTEST_SFINAE_UNSUITABLE       1
    #define dTEST_SFINAE_DUNSUITABLE      1
    #define dTEST_SFINAE_PUNSUITABLE      1
    #define dTEST_SFINAE_DPUNSUITABLE     1

    #define dTEST_SFINAE_INT              1
    #define dTEST_SFINAE_DINT             1
    #define dTEST_SFINAE_PINT             0
    #define dTEST_SFINAE_DPINT            0
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
#endif // !TEST_TOOLS_SFINAE_BEGIN