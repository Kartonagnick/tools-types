// [2021y-05m-04d][16:34:05] Idrisov Denis R.
#ifdef _MSC_VER
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_END
#define dTEST_COMPONENT tools, types, sfinae, exist
#define dTEST_METHOD end
#define dTEST_TAG tdd

#include <tools/features.hpp>

#ifdef dHAS_CPP11
    // msvc2015 or newer
    #define dALL 1
#elif defined(dHAS_VARIADIC_TEMPLATE) 
    // msvc2013
    #define dALL 1
#elif defined(dHAS_ENUM_CLASS) 
    // msvc2012
    #define dALL 1
#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2010
    #define dALL 1
#else
    // msvc2008 or older
    #define dALL 1
#endif

#ifdef dALL
    #define dTEST_SFINAE_REGULAR      1
    #define dTEST_SFINAE_DERIVED      1
    #define dTEST_SFINAE_PRIVATE      1
    #define dTEST_SFINAE_DPRVATE      1
                                      
    #define dTEST_SFINAE_RECURSIEVE   1
    #define dTEST_SFINAE_DRECURSIEVE  1
    #define dTEST_SFINAE_PRECURSIEVE  1
    #define dTEST_SFINAE_DPRECURSIEVE 1

    #define dTEST_SFINAE_INT          1
    #define dTEST_SFINAE_DINT         1
    #define dTEST_SFINAE_PINT         1
    #define dTEST_SFINAE_DPINT        1

    #define dTEST_SFINAE_BODY         1
    #define dTEST_SFINAE_DBODY        1
    #define dTEST_SFINAE_PBODY        1
    #define dTEST_SFINAE_DPBODY       1
#endif

#include "test-end.hpp"
#include "test-exist.hpp"

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_REGULAR
// --- simple false
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
    make_test(const Mutable     ,  true    );
    make_test(const Container   ,  true    );

    make_test(const Const&      ,  true    );
    make_test(const Mutable&    ,  true    );
    make_test(const Container&  ,  true    );

    make_rval(const Const&&     ,  true    );
    make_rval(const Mutable&&   ,  true    );
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
    make_test(const DMutable     ,  true    );
    make_test(const DContainer   ,  true    );

    make_test(const DConst&      ,  true    );
    make_test(const DMutable&    ,  true    );
    make_test(const DContainer&  ,  true    );

    make_rval(const DConst&&     ,  true    );
    make_rval(const DMutable&&   ,  true    );
    make_rval(const DContainer&& ,  true    );
}
#endif // dTEST_SFINAE_DERIVED

#ifdef dTEST_SFINAE_PRIVATE
// --- private non-const
TEST_COMPONENT(005)
{
    //       |   type      | expected |
    make_test(PConst       ,  true    );
    make_test(PMutable     ,  true    );
    make_test(PContainer   ,  true    );

    make_test(PConst&      ,  true    );
    make_test(PMutable&    ,  true    );
    make_test(PContainer&  ,  true    );

    make_rval(PConst&&     ,  true    );
    make_rval(PMutable&&   ,  true    );
    make_rval(PContainer&& ,  true    );
}

// --- private const
TEST_COMPONENT(006)
{
    //       |   type            | expected |
    make_test(const PConst       ,  true    );
    make_test(const PMutable     ,  true    );
    make_test(const PContainer   ,  true    );

    make_test(const PConst&      ,  true    );
    make_test(const PMutable&    ,  true    );
    make_test(const PContainer&  ,  true    );

    make_rval(const PConst&&     ,  true    );
    make_rval(const PMutable&&   ,  true    );
    make_rval(const PContainer&& ,  true    );
}
#endif // dTEST_SFINAE_PRIVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRVATE
// --- derived private non-const 
TEST_COMPONENT(007)
{
    //       |   type       | expected |
    make_test(DPConst       ,  true    );
    make_test(DPMutable     ,  true    );
    make_test(DPContainer   ,  true    );

    make_test(DPConst&      ,  true    );
    make_test(DPMutable&    ,  true    );
    make_test(DPContainer&  ,  true    );

    make_rval(DPConst&&     ,  true    );
    make_rval(DPMutable&&   ,  true    );
    make_rval(DPContainer&& ,  true    );
}

// --- derived private const 
TEST_COMPONENT(008)
{
    //       |   type             | expected |
    make_test(const DPConst       ,  true    );
    make_test(const DPMutable     ,  true    );
    make_test(const DPContainer   ,  true    );

    make_test(const DPConst&      ,  true    );
    make_test(const DPMutable&    ,  true    );
    make_test(const DPContainer&  ,  true    );

    make_rval(const DPConst&&     ,  true    );
    make_rval(const DPMutable&&   ,  true    );
    make_rval(const DPContainer&& ,  true    );
}
#endif // dTEST_SFINAE_DPRVATE

//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_RECURSIEVE
// --- recursieve non-const
TEST_COMPONENT(009)
{
    //       |   type      | expected |
    make_test(RConst       ,  true    );
    make_test(RMutable     ,  true    );
    make_test(RContainer   ,  true    );
              
    make_test(RConst&      ,  true    );
    make_test(RMutable&    ,  true    );
    make_test(RContainer&  ,  true    );
              
    make_rval(RConst&&     ,  true    );
    make_rval(RMutable&&   ,  true    );
    make_rval(RContainer&& ,  true    );
}

// --- const
TEST_COMPONENT(010)
{
    //       |   type            | expected |
    make_test(const RConst       ,  true    );
    make_test(const RMutable     ,  true    );
    make_test(const RContainer   ,  true    );
                    
    make_test(const RConst&      ,  true    );
    make_test(const RMutable&    ,  true    );
    make_test(const RContainer&  ,  true    );
                    
    make_rval(const RConst&&     ,  true    );
    make_rval(const RMutable&&   ,  true    );
    make_rval(const RContainer&& ,  true    );
}
#endif // dTEST_SFINAE_RECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DRECURSIEVE
// --- derived non-const 
TEST_COMPONENT(011)
{
    //       |   type       | expected |
    make_test(DRConst       ,  true    );
    make_test(DRMutable     ,  true    );
    make_test(DRContainer   ,  true    );
               
    make_test(DRConst&      ,  true    );
    make_test(DRMutable&    ,  true    );
    make_test(DRContainer&  ,  true    );
               
    make_rval(DRConst&&     ,  true    );
    make_rval(DRMutable&&   ,  true    );
    make_rval(DRContainer&& ,  true    );
}

// --- derived const
TEST_COMPONENT(012)
{
    //       |   type            | expected |
    make_test(const DConst       ,  true    );
    make_test(const DMutable     ,  true    );
    make_test(const DContainer   ,  true    );

    make_test(const DConst&      ,  true    );
    make_test(const DMutable&    ,  true    );
    make_test(const DContainer&  ,  true    );

    make_rval(const DConst&&     ,  true    );
    make_rval(const DMutable&&   ,  true    );
    make_rval(const DContainer&& ,  true    );
}
#endif

#ifdef dTEST_SFINAE_PRECURSIEVE
// --- private non-const
TEST_COMPONENT(013)
{
    //       |   type       | expected |
    make_test(PRConst       ,  true    );
    make_test(PRMutable     ,  true    );
    make_test(PRContainer   ,  true    );

    make_test(PRConst&      ,  true    );
    make_test(PRMutable&    ,  true    );
    make_test(PRContainer&  ,  true    );

    make_rval(PRConst&&     ,  true    );
    make_rval(PRMutable&&   ,  true    );
    make_rval(PRContainer&& ,  true    );
}

// --- private const
TEST_COMPONENT(014)
{
    //       |   type             | expected |
    make_test(const PRConst       ,  true    );
    make_test(const PRMutable     ,  true    );
    make_test(const PRContainer   ,  true    );
                     
    make_test(const PRConst&      ,  true    );
    make_test(const PRMutable&    ,  true    );
    make_test(const PRContainer&  ,  true    );
                     
    make_rval(const PRConst&&     ,  true    );
    make_rval(const PRMutable&&   ,  true    );
    make_rval(const PRContainer&& ,  true    );
}
#endif // dTEST_SFINAE_PRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRECURSIEVE
// --- derived private non-const 
TEST_COMPONENT(015)
{
    //       |   type        | expected |
    make_test(DPRConst       ,  true    );
    make_test(DPRMutable     ,  true    );
    make_test(DPRContainer   ,  true    );

    make_test(DPRConst&      ,  true    );
    make_test(DPRMutable&    ,  true    );
    make_test(DPRContainer&  ,  true    );

    make_rval(DPRConst&&     ,  true    );
    make_rval(DPRMutable&&   ,  true    );
    make_rval(DPRContainer&& ,  true    );
}

// --- derived private const 
TEST_COMPONENT(016)
{
    //       |   type              | expected |
    make_test(const DPRConst       ,  true    );
    make_test(const DPRMutable     ,  true    );
    make_test(const DPRContainer   ,  true    );

    make_test(const DPRConst&      ,  true    );
    make_test(const DPRMutable&    ,  true    );
    make_test(const DPRContainer&  ,  true    );

    make_rval(const DPRConst&&     ,  true    );
    make_rval(const DPRMutable&&   ,  true    );
    make_rval(const DPRContainer&& ,  true    );
}
#endif // dTEST_SFINAE_DPRECURSIEVE

//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_INT
// --- int non-const
TEST_COMPONENT(017)
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

// --- int const
TEST_COMPONENT(018)
{
    //       |   type            | expected |
    make_test(const IntConst     ,  true    );
    make_test(const IntMutable   ,  true    );
    make_test(const Int          ,  true    );

    make_test(const IntConst&    ,  true    );
    make_test(const IntMutable&  ,  true    );
    make_test(const Int&         ,  true    );

    make_rval(const IntConst&&   ,  true    );
    make_rval(const IntMutable&& ,  true    );
    make_rval(const Int&&        ,  true    );
}
#endif // dTEST_SFINAE_INT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DINT
// --- derived int non-const
TEST_COMPONENT(019)
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

// --- derived int const
TEST_COMPONENT(020)
{
    //       |   type             | expected |
    make_test(const DIntConst     ,  true    );
    make_test(const DIntMutable   ,  true    );
    make_test(const DInt          ,  true    );

    make_test(const DIntConst&    ,  true    );
    make_test(const DIntMutable&  ,  true    );
    make_test(const DInt&         ,  true    );

    make_rval(const DIntConst&&   ,  true    );
    make_rval(const DIntMutable&& ,  true    );
    make_rval(const DInt&&        ,  true    );
}
#endif // dTEST_SFINAE_DINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PINT
// --- private int non-const
TEST_COMPONENT(021)
{
    //       |   type       | expected |
    make_test(PIntConst     ,  true    );
    make_test(PIntMutable   ,  true    );
    make_test(PInt          ,  true    );

    make_test(PIntConst&    ,  true    );
    make_test(PIntMutable&  ,  true    );
    make_test(PInt&         ,  true    );

    make_rval(PIntConst&&   ,  true    );
    make_rval(PIntMutable&& ,  true    );
    make_rval(PInt&&        ,  true    );
}

// --- private int const
TEST_COMPONENT(022)
{
    //       |   type             | expected |
    make_test(const PIntConst     ,  true    );
    make_test(const PIntMutable   ,  true    );
    make_test(const PInt          ,  true    );

    make_test(const PIntConst&    ,  true    );
    make_test(const PIntMutable&  ,  true    );
    make_test(const PInt&         ,  true    );

    make_rval(const PIntConst&&   ,  true    );
    make_rval(const PIntMutable&& ,  true    );
    make_rval(const PInt&&        ,  true    );
}
#endif // dTEST_SFINAE_PINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPINT
// --- derived private int non-const
TEST_COMPONENT(023)
{
    //       |   type        | expected |
    make_test(DPIntConst     ,  true    );
    make_test(DPIntMutable   ,  true    );
    make_test(DPInt          ,  true    );

    make_test(DPIntConst&    ,  true    );
    make_test(DPIntMutable&  ,  true    );
    make_test(DPInt&         ,  true    );

    make_rval(DPIntConst&&   ,  true    );
    make_rval(DPIntMutable&& ,  true    );
    make_rval(DPInt&&        ,  true    );
}

// --- derived private int const
TEST_COMPONENT(024)
{
    //       |   type              | expected |
    make_test(const DPIntConst     ,  true    );
    make_test(const DPIntMutable   ,  true    );
    make_test(const DPInt          ,  true    );

    make_test(const DPIntConst&    ,  true    );
    make_test(const DPIntMutable&  ,  true    );
    make_test(const DPInt&         ,  true    );

    make_rval(const DPIntConst&&   ,  true    );
    make_rval(const DPIntMutable&& ,  true    );
    make_rval(const DPInt&&        ,  true    );
}
#endif // dTEST_SFINAE_PINT

//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_BODY
// --- int non-const
TEST_COMPONENT(025)
{
    //       |   type       | expected |
    make_test(BodyConst     ,  true    );
    make_test(BodyMutable   ,  true    );
    make_test(Body          ,  true    );

    make_test(BodyConst&    ,  true    );
    make_test(BodyMutable&  ,  true    );
    make_test(Body&         ,  true    );

    make_rval(BodyConst&&   ,  true    );
    make_rval(BodyMutable&& ,  true    );
    make_rval(Body&&        ,  true    );
}

// --- int const
TEST_COMPONENT(026)
{
    //       |   type             | expected |
    make_test(const BodyConst     ,  true    );
    make_test(const BodyMutable   ,  true    );
    make_test(const Body          ,  true    );
                    
    make_test(const BodyConst&    ,  true    );
    make_test(const BodyMutable&  ,  true    );
    make_test(const Body&         ,  true    );
                    
    make_rval(const BodyConst&&   ,  true    );
    make_rval(const BodyMutable&& ,  true    );
    make_rval(const Body&&        ,  true    );
}
#endif // dTEST_SFINAE_BODY

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DBODY
// --- derived int non-const
TEST_COMPONENT(027)
{
    //       |   type        | expected |
    make_test(DBodyConst     ,  true    );
    make_test(DBodyMutable   ,  true    );
    make_test(DBody          ,  true    );

    make_test(DBodyConst&    ,  true    );
    make_test(DBodyMutable&  ,  true    );
    make_test(DBody&         ,  true    );

    make_rval(DBodyConst&&   ,  true    );
    make_rval(DBodyMutable&& ,  true    );
    make_rval(DBody&&        ,  true    );
}

// --- derived int const
TEST_COMPONENT(028)
{
    //       |   type              | expected |
    make_test(const DBodyConst     ,  true    );
    make_test(const DBodyMutable   ,  true    );
    make_test(const DBody          ,  true    );

    make_test(const DBodyConst&    ,  true    );
    make_test(const DBodyMutable&  ,  true    );
    make_test(const DBody&         ,  true    );

    make_rval(const DBodyConst&&   ,  true    );
    make_rval(const DBodyMutable&& ,  true    );
    make_rval(const DBody&&        ,  true    );
}
#endif // dTEST_SFINAE_DBODY

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PBODY
// --- private int non-const
TEST_COMPONENT(029)
{
    //       |   type        | expected |
    make_test(PBodyConst     ,  true    );
    make_test(PBodyMutable   ,  true    );
    make_test(PBody          ,  true    );

    make_test(PBodyConst&    ,  true    );
    make_test(PBodyMutable&  ,  true    );
    make_test(PBody&         ,  true    );

    make_rval(PBodyConst&&   ,  true    );
    make_rval(PBodyMutable&& ,  true    );
    make_rval(PBody&&        ,  true    );
}

// --- private int const
TEST_COMPONENT(030)
{
    //       |   type              | expected |
    make_test(const PBodyConst     ,  true    );
    make_test(const PBodyMutable   ,  true    );
    make_test(const PBody          ,  true    );

    make_test(const PBodyConst&    ,  true    );
    make_test(const PBodyMutable&  ,  true    );
    make_test(const PBody&         ,  true    );

    make_rval(const PBodyConst&&   ,  true    );
    make_rval(const PBodyMutable&& ,  true    );
    make_rval(const PBody&&        ,  true    );
}
#endif // dTEST_SFINAE_PBODY

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPBODY
// --- derived private int non-const
TEST_COMPONENT(031)
{
    //       |   type         | expected |
    make_test(DPBodyConst     ,  true    );
    make_test(DPBodyMutable   ,  true    );
    make_test(DPBody          ,  true    );

    make_test(DPBodyConst&    ,  true    );
    make_test(DPBodyMutable&  ,  true    );
    make_test(DPBody&         ,  true    );

    make_rval(DPBodyConst&&   ,  true    );
    make_rval(DPBodyMutable&& ,  true    );
    make_rval(DPBody&&        ,  true    );
}

// --- derived private int const
TEST_COMPONENT(032)
{
    //       |   type               | expected |
    make_test(const DPBodyConst     ,  true    );
    make_test(const DPBodyMutable   ,  true    );
    make_test(const DPBody          ,  true    );

    make_test(const DPBodyConst&    ,  true    );
    make_test(const DPBodyMutable&  ,  true    );
    make_test(const DPBody&         ,  true    );

    make_rval(const DPBodyConst&&   ,  true    );
    make_rval(const DPBodyMutable&& ,  true    );
    make_rval(const DPBody&&        ,  true    );
}
#endif // dTEST_SFINAE_DPBODY

//==============================================================================
//==============================================================================
#endif // TEST_TOOLS_SFINAE_END
#endif // _MSC_VER