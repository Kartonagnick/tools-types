// [2021y-04m-29d][12:57:49] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_BEGIN
#define dTEST_COMPONENT tools, types, sfinae, available
#define dTEST_METHOD begin
#define dTEST_TAG tdd

#include <tools/features.hpp>

#ifdef dHAS_CPP11
    // msvc2015 or newer 
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
#elif defined(dHAS_VARIADIC_TEMPLATE) 
    // msvc2013
    //   - has bug:
    //     - ignore private/protected access

    #define dTEST_SFINAE_REGULAR          1
    #define dTEST_SFINAE_DERIVED          1
    // #define dTEST_SFINAE_PRIVATE       0
    // #define dTEST_SFINAE_DPRVATE       0
                                          
    #define dTEST_SFINAE_RECURSIEVE       1
    #define dTEST_SFINAE_DRECURSIEVE      1
    // #define dTEST_SFINAE_PRECURSIEVE   0
    // #define dTEST_SFINAE_DPRECURSIEVE  0

    #define dTEST_SFINAE_UNSUITABLE       1
    #define dTEST_SFINAE_DUNSUITABLE      1
    #define dTEST_SFINAE_PUNSUITABLE      1
    #define dTEST_SFINAE_DPUNSUITABLE     1
#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2013 - msvc2010
    #define dTEST_SFINAE_REGULAR       1
    #define dTEST_SFINAE_DERIVED       1
    // #define dTEST_SFINAE_PRIVATE       1
    // #define dTEST_SFINAE_DPRVATE       1

    #define dTEST_SFINAE_RECURSIEVE    1
    #define dTEST_SFINAE_DRECURSIEVE   1
    // #define dTEST_SFINAE_PRECURSIEVE   1
    // #define dTEST_SFINAE_DPRECURSIEVE  1

    #define dTEST_SFINAE_UNSUITABLE    1
    #define dTEST_SFINAE_DUNSUITABLE   1
    #define dTEST_SFINAE_PUNSUITABLE   1
    #define dTEST_SFINAE_DPUNSUITABLE  1
#else
    // msvc20008 or older
#endif

#include "test-begin.hpp"
#include "test-avail.hpp"

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_REGULAR
// --- simple: false
TEST_COMPONENT(000)
{
    //       |   type   | expected |
    make_test(Maket     ,  false   );
    make_test(Dummy     ,  false   );
    make_test(int       ,  false   );
    make_test(int()     ,  false   );
//-----------------------------------------
    make_test(Maket&    ,  false   );
    make_test(Dummy&    ,  false   );
    make_test(int&      ,  false   );
    make_test(int(&)()  ,  false   );
//-----------------------------------------
    make_rval(Maket&&   ,  false   );
    make_rval(Dummy&&   ,  false   );
    make_rval(int&&     ,  false   );
    make_rval(int(&&)() ,  false   );
//-----------------------------------------
    make_test(Maket*    ,  false   );
    make_test(Dummy*    ,  false   );
    make_test(int*      ,  false   );
    make_test(int(*)()  ,  false   );
}

// --- non-const
TEST_COMPONENT(001)
{
    //       |   type     | expected |
    make_test(Const       ,  true    );
    make_test(Mutable     ,  true    );
    make_test(Container   ,  true    );

    make_test(Const&      ,  true    );
    make_test(Mutable&    ,  true    );
    make_test(Container&  ,  true    );

    make_rval(Const&&     ,  true    );
    make_rval(Mutable&&   ,  true    );
    make_rval(Container&& ,  true    );
}

// --- const
TEST_COMPONENT(002)
{
    //       |   type           | expected |
    make_test(const Const       ,  true    );
    make_test(const Mutable     ,  false   );
    make_test(const Container   ,  true    );

    make_test(const Const&      ,  true    );
    make_test(const Mutable&    ,  false   );
    make_test(const Container&  ,  true    );

    make_rval(const Const&&     ,  true    );
    make_rval(const Mutable&&   ,  false   );
    make_rval(const Container&& ,  true    );
}
#endif // dTEST_SFINAE_REGULAR

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DERIVED
// --- derived non-const
TEST_COMPONENT(003)
{
    //       |   type      | expected |
    make_test(DConst       ,  true    );
    make_test(DMutable     ,  true    );
    make_test(DContainer   ,  true    );

    make_test(DConst&      ,  true    );
    make_test(DMutable&    ,  true    );
    make_test(DContainer&  ,  true    );

    make_rval(DConst&&     ,  true    );
    make_rval(DMutable&&   ,  true    );
    make_rval(DContainer&& ,  true    );
}

// --- derived const
TEST_COMPONENT(004)
{
    //       |   type            | expected |
    make_test(const DConst       ,  true    );
    make_test(const DMutable     ,  false   );
    make_test(const DContainer   ,  true    );

    make_test(const DConst&      ,  true    );
    make_test(const DMutable&    ,  false   );
    make_test(const DContainer&  ,  true    );

    make_rval(const DConst&&     ,  true    );
    make_rval(const DMutable&&   ,  false   );
    make_rval(const DContainer&& ,  true    );
}
#endif  // dTEST_SFINAE_DERIVED

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRIVATE
// --- private non-const
TEST_COMPONENT(005)
{
    //       |   type      | expected |
    make_test(PConst       ,  false   );
    make_test(PMutable     ,  false   );
    make_test(PContainer   ,  false   );
                              
    make_test(PConst&      ,  false   );
    make_test(PMutable&    ,  false   );
    make_test(PContainer&  ,  false   );
                              
    make_rval(PConst&&     ,  false   );
    make_rval(PMutable&&   ,  false   );
    make_rval(PContainer&& ,  false   );
}

// --- private const
TEST_COMPONENT(006)
{
    //       |   type            | expected |
    make_test(const PConst       ,  false   );
    make_test(const PMutable     ,  false   );
    make_test(const PContainer   ,  false   );
                                    
    make_test(const PConst&      ,  false   );
    make_test(const PMutable&    ,  false   );
    make_test(const PContainer&  ,  false   );
                                    
    make_rval(const PConst&&     ,  false   );
    make_rval(const PMutable&&   ,  false   );
    make_rval(const PContainer&& ,  false   );
}
#endif // dTEST_SFINAE_PRIVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRVATE
// --- derived private  non-const
TEST_COMPONENT(007)
{
    //       |   type       | expected |
    make_test(DPConst       ,  false   );
    make_test(DPMutable     ,  false   );
    make_test(DPContainer   ,  false   );
                               
    make_test(DPConst&      ,  false   );
    make_test(DPMutable&    ,  false   );
    make_test(DPContainer&  ,  false   );
                               
    make_rval(DPConst&&     ,  false   );
    make_rval(DPMutable&&   ,  false   );
    make_rval(DPContainer&& ,  false   );
}

// --- derived private const
TEST_COMPONENT(008)
{
    //       |   type             | expected |
    make_test(const DPConst       ,  false   );
    make_test(const DPMutable     ,  false   );
    make_test(const DPContainer   ,  false   );
                                     
    make_test(const DPConst&      ,  false   );
    make_test(const DPMutable&    ,  false   );
    make_test(const DPContainer&  ,  false   );
                                     
    make_rval(const DPConst&&     ,  false   );
    make_rval(const DPMutable&&   ,  false   );
    make_rval(const DPContainer&& ,  false   );
}
#endif // dTEST_SFINAE_DPRVATE

//..............................................................................
//..............................................................................

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_RECURSIEVE
// --- recursieve non-const
TEST_COMPONENT(009)
{
    //       |   type      | expected |
    make_test(RConst       ,   true   );
    make_test(RMutable     ,   true   );
    make_test(RContainer   ,   true   );
                               
    make_test(RConst&      ,   true   );
    make_test(RMutable&    ,   true   );
    make_test(RContainer&  ,   true   );
                               
    make_rval(RConst&&     ,   true   );
    make_rval(RMutable&&   ,   true   );
    make_rval(RContainer&& ,   true   );
}

// --- recursieve const
TEST_COMPONENT(010)
{
    //       |   type            | expected |
    make_test(const RConst       ,   true   );
    make_test(const RMutable     ,   false  );
    make_test(const RContainer   ,   true   );
                                     
    make_test(const RConst&      ,   true   );
    make_test(const RMutable&    ,   false  );
    make_test(const RContainer&  ,   true   );
                                     
    make_rval(const RConst&&     ,   true   );
    make_rval(const RMutable&&   ,   false  );
    make_rval(const RContainer&& ,   true   );
}

#endif // dTEST_SFINAE_RECURSIEVE
//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DRECURSIEVE
// --- derived recursieve non-const
TEST_COMPONENT(011)
{
    //       |   type       | expected |
    make_test(DRConst       ,   true   );
    make_test(DRMutable     ,   true   );
    make_test(DRContainer   ,   true   );
                                
    make_test(DRConst&      ,   true   );
    make_test(DRMutable&    ,   true   );
    make_test(DRContainer&  ,   true   );
                                
    make_rval(DRConst&&     ,   true   );
    make_rval(DRMutable&&   ,   true   );
    make_rval(DRContainer&& ,   true   );
}

// --- derived recursieve const
TEST_COMPONENT(012)
{
    //       |   type             | expected |
    make_test(const DRConst       ,   true   );
    make_test(const DRMutable     ,   false  );
    make_test(const DRContainer   ,   true   );
                                      
    make_test(const DRConst&      ,   true   );
    make_test(const DRMutable&    ,   false  );
    make_test(const DRContainer&  ,   true   );
                                      
    make_rval(const DRConst&&     ,   true   );
    make_rval(const DRMutable&&   ,   false  );
    make_rval(const DRContainer&& ,   true   );
}
#endif // dTEST_SFINAE_DRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRECURSIEVE
// --- private recursieve non-const
TEST_COMPONENT(013)
{
    //       |   type       | expected |
    make_test(PRConst       ,  false   );
    make_test(PRMutable     ,  false   );
    make_test(PRContainer   ,  false   );
                                       
    make_test(PRConst&      ,  false   );
    make_test(PRMutable&    ,  false   );
    make_test(PRContainer&  ,  false   );
                                       
    make_rval(PRConst&&     ,  false   );
    make_rval(PRMutable&&   ,  false   );
    make_rval(PRContainer&& ,  false   );
}

// --- private recursieve const
TEST_COMPONENT(014)
{
    //       |   type             | expected |
    make_test(const PRConst       ,  false   );
    make_test(const PRMutable     ,  false   );
    make_test(const PRContainer   ,  false   );
                                       
    make_test(const PRConst&      ,  false   );
    make_test(const PRMutable&    ,  false   );
    make_test(const PRContainer&  ,  false   );
                                     
    make_rval(const PRConst&&     ,  false   );
    make_rval(const PRMutable&&   ,  false   );
    make_rval(const PRContainer&& ,  false   );
}
#endif // dTEST_SFINAE_PRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRECURSIEVE
// --- derived private recursieve non-const
TEST_COMPONENT(015)
{
    //       |   type        | expected |
    make_test(DPRConst       ,  false   );
    make_test(DPRMutable     ,  false   );
    make_test(DPRContainer   ,  false   );
                                
    make_test(DPRConst&      ,  false   );
    make_test(DPRMutable&    ,  false   );
    make_test(DPRContainer&  ,  false   );
                                
    make_rval(DPRConst&&     ,  false   );
    make_rval(DPRMutable&&   ,  false   );
    make_rval(DPRContainer&& ,  false   );
}

// --- derived private recursieve const
TEST_COMPONENT(016)
{
    //       |   type              | expected |
    make_test(const DPRConst       ,  false   );
    make_test(const DPRMutable     ,  false   );
    make_test(const DPRContainer   ,  false   );
                                      
    make_test(const DPRConst&      ,  false   );
    make_test(const DPRMutable&    ,  false   );
    make_test(const DPRContainer&  ,  false   );
                                      
    make_rval(const DPRConst&&     ,  false   );
    make_rval(const DPRMutable&&   ,  false   );
    make_rval(const DPRContainer&& ,  false   );
}
#endif // dTEST_SFINAE_DPRECURSIEVE

//..............................................................................
//..............................................................................

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_UNSUITABLE
// --- unsuitable non-const
TEST_COMPONENT(017)
{
    //       |   type             | expected |
    make_test(UnsuitableConst     ,  false   );
    make_test(UnsuitableMutable   ,  false   );
    make_test(Unsuitable          ,  false   );
                                            
    make_test(UnsuitableConst&    ,  false   );
    make_test(UnsuitableMutable&  ,  false   );
    make_test(Unsuitable&         ,  false   );
                                            
    make_test(UnsuitableConst&&   ,  false   );
    make_test(UnsuitableMutable&& ,  false   );
    make_test(Unsuitable&&        ,  false   );
}
TEST_COMPONENT(018)
{
    //       |   type                   | expected |
    make_test(const UnsuitableConst     ,  false   );
    make_test(const UnsuitableMutable   ,  false   );
    make_test(const Unsuitable          ,  false   );

    make_test(const UnsuitableConst&    ,  false   );
    make_test(const UnsuitableMutable&  ,  false   );
    make_test(const Unsuitable&         ,  false   );
                              
    make_test(const UnsuitableConst&&   ,  false   );
    make_test(const UnsuitableMutable&& ,  false   );
    make_test(const Unsuitable&&        ,  false   );
}
#endif // dTEST_SFINAE_UNSUITABLE

#ifdef dTEST_SFINAE_DUNSUITABLE
TEST_COMPONENT(019)
{ 
    //       |   type              | expected |
    make_test(DUnsuitableConst     ,  false   );
    make_test(DUnsuitableMutable   ,  false   );
    make_test(DUnsuitable          ,  false   );
                                            
    make_test(DUnsuitableConst&    ,  false   );
    make_test(DUnsuitableMutable&  ,  false   );
    make_test(DUnsuitable&         ,  false   );
                                            
    make_rval(DUnsuitableConst&&   ,  false   );
    make_rval(DUnsuitableMutable&& ,  false   );
    make_rval(DUnsuitable&&        ,  false   );
}
TEST_COMPONENT(020)
{ 
    //       |   type                    | expected |
    make_test(const DUnsuitableConst     ,  false   );
    make_test(const DUnsuitableMutable   ,  false   );
    make_test(const DUnsuitable          ,  false   );
              
    make_test(const DUnsuitableConst&    ,  false   );
    make_test(const DUnsuitableMutable&  ,  false   );
    make_test(const DUnsuitable&         ,  false   );
                                            
    make_rval(const DUnsuitableConst&&   ,  false   );
    make_rval(const DUnsuitableMutable&& ,  false   );
    make_rval(const DUnsuitable&&        ,  false   );
}
#endif // dTEST_SFINAE_DUNSUITABLE

#ifdef dTEST_SFINAE_PUNSUITABLE
TEST_COMPONENT(021)
{ 
    //       |   type              | expected |
    make_test(PUnsuitableConst     ,  false   );
    make_test(PUnsuitableMutable   ,  false   );
    make_test(PUnsuitable          ,  false   );
                                           
    make_test(PUnsuitableConst&    ,  false   );
    make_test(PUnsuitableMutable&  ,  false   );
    make_test(PUnsuitable&         ,  false   );
              
    make_rval(PUnsuitableConst&&   ,  false   );
    make_rval(PUnsuitableMutable&& ,  false   );
    make_rval(PUnsuitable&&        ,  false   );
}
TEST_COMPONENT(022)
{ 
    //       |   type                    | expected |
    make_test(const PUnsuitableConst     ,  false   );
    make_test(const PUnsuitableMutable   ,  false   );
    make_test(const PUnsuitable          ,  false   );
                    
    make_test(const PUnsuitableConst&    ,  false   );
    make_test(const PUnsuitableMutable&  ,  false   );
    make_test(const PUnsuitable&         ,  false   );
                    
    make_rval(const PUnsuitableConst&&   ,  false   );
    make_rval(const PUnsuitableMutable&& ,  false   );
    make_rval(const PUnsuitable&&        ,  false   );
}
#endif // dTEST_SFINAE_PUNSUITABLE

#ifdef dTEST_SFINAE_DPUNSUITABLE
TEST_COMPONENT(023)
{ 
    //       |   type              | expected |
    make_test(DPUnsuitableConst     ,  false   );
    make_test(DPUnsuitableMutable   ,  false   );
    make_test(DPUnsuitable          ,  false   );
              
    make_test(DPUnsuitableConst&    ,  false   );
    make_test(DPUnsuitableMutable&  ,  false   );
    make_test(DPUnsuitable&         ,  false   );
              
    make_rval(DPUnsuitableConst&&   ,  false   );
    make_rval(DPUnsuitableMutable&& ,  false   );
    make_rval(DPUnsuitable&&        ,  false   );
}
TEST_COMPONENT(024)
{ 
    //       |   type                    | expected |
    make_test(const DPUnsuitableConst     ,  false   );
    make_test(const DPUnsuitableMutable   ,  false   );
    make_test(const DPUnsuitable          ,  false   );
                    
    make_test(const DPUnsuitableConst&    ,  false   );
    make_test(const DPUnsuitableMutable&  ,  false   );
    make_test(const DPUnsuitable&         ,  false   );
                    
    make_rval(const DPUnsuitableConst&&   ,  false   );
    make_rval(const DPUnsuitableMutable&& ,  false   );
    make_rval(const DPUnsuitable&&        ,  false   );
}
#endif // dTEST_SFINAE_PUNSUITABLE

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_SFINAE_BEGIN
