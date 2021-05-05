// [2021y-05m-05d][23:02:09] Idrisov Denis R.
#include <mygtest/modern.hpp>

#define TEST_TOOLS_SFINAE_DEREFERENCE

#ifdef TEST_TOOLS_SFINAE_BEGIN
#define dTEST_COMPONENT tools, types, sfinae, available
#define dTEST_METHOD dereference
#define dTEST_TAG tdd

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

} // namespace 

#include "test-dereference.hpp"
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
    make_test(int()     ,  true    );
//-----------------------------------------
    make_test(Maket&    ,  false   );
    make_test(Dummy&    ,  false   );
    make_test(int&      ,  false   );
    make_test(int(&)()  ,  true    );
//-----------------------------------------
    make_rval(Maket&&   ,  false   );
    make_rval(Dummy&&   ,  false   );
    make_rval(int&&     ,  false   );
    make_rval(int(&&)() ,  true    );
//-----------------------------------------
    make_test(Maket*    ,  true    );
    make_test(Dummy*    ,  true    );
    make_test(int*      ,  true    );
    make_test(int(*)()  ,  true    );
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
    make_test(PConst       ,  privat  );
    make_test(PMutable     ,  privat  );
    make_test(PContainer   ,  privat  );

    make_test(PConst&      ,  privat  );
    make_test(PMutable&    ,  privat  );
    make_test(PContainer&  ,  privat  );

    make_rval(PConst&&     ,  privat  );
    make_rval(PMutable&&   ,  privat  );
    make_rval(PContainer&& ,  privat  );
}

// --- private const
TEST_COMPONENT(006)
{
    //       |   type            | expected |
    make_test(const PConst       ,  privat  );
    make_test(const PMutable     ,  false   );
    make_test(const PContainer   ,  privat  );
                                    
    make_test(const PConst&      ,  privat  );
    make_test(const PMutable&    ,  false   );
    make_test(const PContainer&  ,  privat  );
                                    
    make_rval(const PConst&&     ,  privat  );
    make_rval(const PMutable&&   ,  false   );
    make_rval(const PContainer&& ,  privat  );
}
#endif // dTEST_SFINAE_PRIVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRVATE
// --- derived private  non-const
TEST_COMPONENT(007)
{
    //       |   type       | expected |
    make_test(DPConst       ,  privat  );
    make_test(DPMutable     ,  privat  );
    make_test(DPContainer   ,  privat  );
                               
    make_test(DPConst&      ,  privat  );
    make_test(DPMutable&    ,  privat  );
    make_test(DPContainer&  ,  privat  );
                               
    make_rval(DPConst&&     ,  privat  );
    make_rval(DPMutable&&   ,  privat  );
    make_rval(DPContainer&& ,  privat  );
}

// --- derived private const
TEST_COMPONENT(008)
{
    //       |   type             | expected |
    make_test(const DPConst       ,  privat  );
    make_test(const DPMutable     ,  false   );
    make_test(const DPContainer   ,  privat  );
                                     
    make_test(const DPConst&      ,  privat  );
    make_test(const DPMutable&    ,  false   );
    make_test(const DPContainer&  ,  privat  );
                                     
    make_rval(const DPConst&&     ,  privat  );
    make_rval(const DPMutable&&   ,  false   );
    make_rval(const DPContainer&& ,  privat  );
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
    make_test(PRConst       ,  privat  );
    make_test(PRMutable     ,  privat  );
    make_test(PRContainer   ,  privat  );
                                 
    make_test(PRConst&      ,  privat  );
    make_test(PRMutable&    ,  privat  );
    make_test(PRContainer&  ,  privat  );
                               
    make_rval(PRConst&&     ,  privat  );
    make_rval(PRMutable&&   ,  privat  );
    make_rval(PRContainer&& ,  privat  );
}

// --- private recursieve const
TEST_COMPONENT(014)
{
    //       |   type             | expected |
    make_test(const PRConst       ,  privat  );
    make_test(const PRMutable     ,  false   );
    make_test(const PRContainer   ,  privat  );
                                     
    make_test(const PRConst&      ,  privat  );
    make_test(const PRMutable&    ,  false   );
    make_test(const PRContainer&  ,  privat  );
                                     
    make_rval(const PRConst&&     ,  privat  );
    make_rval(const PRMutable&&   ,  false   );
    make_rval(const PRContainer&& ,  privat  );
}
#endif // dTEST_SFINAE_PRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRECURSIEVE
// --- derived private recursieve non-const
TEST_COMPONENT(015)
{
    //       |   type        | expected |
    make_test(DPRConst       ,  privat  );
    make_test(DPRMutable     ,  privat  );
    make_test(DPRContainer   ,  privat  );
                                
    make_test(DPRConst&      ,  privat  );
    make_test(DPRMutable&    ,  privat  );
    make_test(DPRContainer&  ,  privat  );
                                
    make_rval(DPRConst&&     ,  privat  );
    make_rval(DPRMutable&&   ,  privat  );
    make_rval(DPRContainer&& ,  privat  );
}

// --- derived private recursieve const
TEST_COMPONENT(016)
{
    //       |   type              | expected |
    make_test(const DPRConst       ,  privat  );
    make_test(const DPRMutable     ,  false   );
    make_test(const DPRContainer   ,  privat  );
                                      
    make_test(const DPRConst&      ,  privat  );
    make_test(const DPRMutable&    ,  false   );
    make_test(const DPRContainer&  ,  privat  );
                                      
    make_rval(const DPRConst&&     ,  privat  );
    make_rval(const DPRMutable&&   ,  false   );
    make_rval(const DPRContainer&& ,  privat  );
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
                                            
    make_rval(UnsuitableConst&&   ,  false   );
    make_rval(UnsuitableMutable&& ,  false   );
    make_rval(Unsuitable&&        ,  false   );
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
                              
    make_rval(const UnsuitableConst&&   ,  false   );
    make_rval(const UnsuitableMutable&& ,  false   );
    make_rval(const Unsuitable&&        ,  false   );
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
    //       |   type               | expected |
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
    //       |   type                     | expected |
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

//..............................................................................
//..............................................................................

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_INT
// --- non-const
TEST_COMPONENT(025)
{
    //       |   type      | expected |
    make_test(IntConst     ,  true    );
    make_test(IntMutable   ,  true    );
    make_test(Int          ,  true    );
                           
    make_test(IntConst&    ,  true    );
    make_test(IntMutable&  ,  true    );
    make_test(Int&         ,  true    );

    make_rval(IntConst&&   ,  true    );
    make_rval(IntMutable&& ,  true    );
    make_rval(Int&&        ,  true    );
}

// --- const
TEST_COMPONENT(026)
{
    //       |   type            | expected |
    make_test(const IntConst     ,  true    );
    make_test(const IntMutable   ,  false   );
    make_test(const Int          ,  true    );
                           
    make_test(const IntConst&    ,  true    );
    make_test(const IntMutable&  ,  false   );
    make_test(const Int&         ,  true    );
              
    make_rval(const IntConst&&   ,  true    );
    make_rval(const IntMutable&& ,  false   );
    make_rval(const Int&&        ,  true    );
}
#endif // dTEST_SFINAE_INT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DINT
// --- non-const
TEST_COMPONENT(027)
{
    //       |   type       | expected |
    make_test(DIntConst     ,  true    );
    make_test(DIntMutable   ,  true    );
    make_test(DInt          ,  true    );
                           
    make_test(DIntConst&    ,  true    );
    make_test(DIntMutable&  ,  true    );
    make_test(DInt&         ,  true    );
              
    make_rval(DIntConst&&   ,  true    );
    make_rval(DIntMutable&& ,  true    );
    make_rval(DInt&&        ,  true    );
}

// --- const
TEST_COMPONENT(028)
{
    //       |   type             | expected |
    make_test(const DIntConst     ,  true    );
    make_test(const DIntMutable   ,  false   );
    make_test(const DInt          ,  true    );
                           
    make_test(const DIntConst&    ,  true    );
    make_test(const DIntMutable&  ,  false   );
    make_test(const DInt&         ,  true    );
                    
    make_rval(const DIntConst&&   ,  true    );
    make_rval(const DIntMutable&& ,  false   );
    make_rval(const DInt&&        ,  true    );
}
#endif // dTEST_SFINAE_DINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PINT
// --- non-const
TEST_COMPONENT(029)
{
    //       |   type       | expected |
    make_test(PIntConst     ,  privat  );
    make_test(PIntMutable   ,  privat  );
    make_test(PInt          ,  privat  );
                               
    make_test(PIntConst&    ,  privat  );
    make_test(PIntMutable&  ,  privat  );
    make_test(PInt&         ,  privat  );
                               
    make_rval(PIntConst&&   ,  privat  );
    make_rval(PIntMutable&& ,  privat  );
    make_rval(PInt&&        ,  privat  );
}

// --- const
TEST_COMPONENT(030)
{
    //       |   type             | expected |
    make_test(const PIntConst     ,  privat  );
    make_test(const PIntMutable   ,  false   );
    make_test(const PInt          ,  privat  );
                                     
    make_test(const PIntConst&    ,  privat  );
    make_test(const PIntMutable&  ,  false   );
    make_test(const PInt&         ,  privat  );
                                     
    make_rval(const PIntConst&&   ,  privat  );
    make_rval(const PIntMutable&& ,  false   );
    make_rval(const PInt&&        ,  privat  );
}
#endif // dTEST_SFINAE_PINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPINT
// --- non-const
TEST_COMPONENT(031)
{
    //       |   type        | expected |
    make_test(DPIntConst     ,  privat  );
    make_test(DPIntMutable   ,  privat  );
    make_test(DPInt          ,  privat  );
                                
    make_test(DPIntConst&    ,  privat  );
    make_test(DPIntMutable&  ,  privat  );
    make_test(DPInt&         ,  privat  );
                                
    make_rval(DPIntConst&&   ,  privat  );
    make_rval(DPIntMutable&& ,  privat  );
    make_rval(DPInt&&        ,  privat  );
}

// --- const
TEST_COMPONENT(032)
{
    //       |   type              | expected |
    make_test(const DPIntConst     ,  privat  );
    make_test(const DPIntMutable   ,  false   );
    make_test(const DPInt          ,  privat  );
                                      
    make_test(const DPIntConst&    ,  privat  );
    make_test(const DPIntMutable&  ,  false   );
    make_test(const DPInt&         ,  privat  );
                                      
    make_rval(const DPIntConst&&   ,  privat  );
    make_rval(const DPIntMutable&& ,  false   );
    make_rval(const DPInt&&        ,  privat  );
}
#endif // dTEST_SFINAE_DPINT

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_SFINAE_DEREFERENCE
