// [2021y-05m-04d][21:27:57] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_ACCESS
#define dTEST_COMPONENT tools, types, sfinae, available
#define dTEST_METHOD access
#define dTEST_TAG ext

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

    #define dTEST_SFINAE_BODY             1
    #define dTEST_SFINAE_DBODY            1
    #define dTEST_SFINAE_PBODY            1
    #define dTEST_SFINAE_DPBODY           1

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

    #define dTEST_SFINAE_BODY             1
    #define dTEST_SFINAE_DBODY            1
    #define dTEST_SFINAE_PBODY            0
    #define dTEST_SFINAE_DPBODY           0

#elif defined(dHAS_TYPE_TRAITS) 
    // msvc2010
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
    #define dTEST_SFINAE_PUNSUITABLE      0
    #define dTEST_SFINAE_DPUNSUITABLE     0
                                          
    #define dTEST_SFINAE_INT              1
    #define dTEST_SFINAE_DINT             1
    #define dTEST_SFINAE_PINT             0
    #define dTEST_SFINAE_DPINT            0

    #define dTEST_SFINAE_BODY             1
    #define dTEST_SFINAE_DBODY            1
    #define dTEST_SFINAE_PBODY            0
    #define dTEST_SFINAE_DPBODY           0

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

    #define dTEST_SFINAE_BODY             1
    #define dTEST_SFINAE_DBODY            1
    #define dTEST_SFINAE_PBODY            0
    #define dTEST_SFINAE_DPBODY           0
#endif

namespace 
{
    #if defined (dTEST_SFINAE_PRIVATE) && dTEST_SFINAE_PRIVATE == 0
        const bool privat = true;
    #else
        const bool privat = false;
    #endif

} // namespace 

#include "test-access.hpp"
#include "test-avail_ex.hpp"

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_REGULAR

// --- simple: false
TEST_COMPONENT(000)
{
    //       |   type   | index | expected |
    make_test(Maket     ,  int  ,  false   );
    make_test(Dummy     ,  int  ,  false   );
    make_test(int       ,  int  ,  false   );
    make_test(int()     ,  int  ,  false   );
//-----------------------------------------
    make_test(Maket&    ,  int  ,  false   );
    make_test(Dummy&    ,  int  ,  false   );
    make_test(int&      ,  int  ,  false   );
    make_test(int(&)()  ,  int  ,  false   );
//-----------------------------------------
    make_rval(Maket&&   ,  int  ,  false   );
    make_rval(Dummy&&   ,  int  ,  false   );
    make_rval(int&&     ,  int  ,  false   );
    make_rval(int(&&)() ,  int  ,  false   );
//-----------------------------------------
    make_test(Maket*    ,  int  ,  true    );
    make_test(Dummy*    ,  int  ,  true    );
    make_test(int*      ,  int  ,  true    );
    make_test(int(*)()  ,  int  ,  false   );
//=====================================================
    //       |   type   | index  | expected |
    make_test(Maket     ,  void* ,  false   );
    make_test(Dummy     ,  void* ,  false   );
    make_test(int       ,  void* ,  false   );
    make_test(int()     ,  void* ,  false   );
//------------------------------------------
    make_test(Maket&    ,  void* ,  false   );
    make_test(Dummy&    ,  void* ,  false   );
    make_test(int&      ,  void* ,  false   );
    make_test(int(&)()  ,  void* ,  false   );
//------------------------------------------
    make_rval(Maket&&   ,  void* ,  false   );
    make_rval(Dummy&&   ,  void* ,  false   );
    make_rval(int&&     ,  void* ,  false   );
    make_rval(int(&&)() ,  void* ,  false   );
//------------------------------------------
    make_test(Maket*    ,  void* ,  false   );
    make_test(Dummy*    ,  void* ,  false   );
    make_test(int*      ,  void* ,  false   );
    make_test(int(*)()  ,  void* ,  false   );
}

// --- non-const
TEST_COMPONENT(001)
{
    //       |   type     | index  | expected |
    make_test(Const       , size_t ,  true    );
    make_test(Mutable     , size_t ,  true    );
    make_test(Container   , size_t ,  true    );

    make_test(Const&      , size_t ,  true    );
    make_test(Mutable&    , size_t ,  true    );
    make_test(Container&  , size_t ,  true    );

    make_rval(Const&&     , size_t ,  true    );
    make_rval(Mutable&&   , size_t ,  true    );
    make_rval(Container&& , size_t ,  true    );
//-----------------------------------------------------
    //       |   type     | index | expected |
    make_test(Const       , void* ,  false   );
    make_test(Mutable     , void* ,  false   );
    make_test(Container   , void* ,  false   );

    make_test(Const&      , void* ,  false   );
    make_test(Mutable&    , void* ,  false   );
    make_test(Container&  , void* ,  false   );

    make_rval(Const&&     , void* ,  false   );
    make_rval(Mutable&&   , void* ,  false   );
    make_rval(Container&& , void* ,  false   );

}

// --- const
TEST_COMPONENT(002)
{
    //       |   type           | index  | expected |
    make_test(const Const       , size_t ,  true    );
    make_test(const Mutable     , size_t ,  false   );
    make_test(const Container   , size_t ,  true    );

    make_test(const Const&      , size_t ,  true    );
    make_test(const Mutable&    , size_t ,  false   );
    make_test(const Container&  , size_t ,  true    );

    make_rval(const Const&&     , size_t ,  true    );
    make_rval(const Mutable&&   , size_t ,  false   );
    make_rval(const Container&& , size_t ,  true    );
//-----------------------------------------------------
    //       |   type           | index  | expected |
    make_test(const Const       , void*  ,  false   );
    make_test(const Mutable     , void*  ,  false   );
    make_test(const Container   , void*  ,  false   );

    make_test(const Const&      , void*  ,  false   );
    make_test(const Mutable&    , void*  ,  false   );
    make_test(const Container&  , void*  ,  false   );
  
    make_rval(const Const&&     , void*  ,  false   );
    make_rval(const Mutable&&   , void*  ,  false   );
    make_rval(const Container&& , void*  ,  false   );
}

#endif // dTEST_SFINAE_REGULAR

//==============================================================================
//==============================================================================

#ifdef dTEST_SFINAE_DERIVED
// --- derived non-const
TEST_COMPONENT(003)
{
    //       |   type      | index  | expected |
    make_test(DConst       , size_t ,  true    );
    make_test(DMutable     , size_t ,  true    );
    make_test(DContainer   , size_t ,  true    );

    make_test(DConst&      , size_t ,  true    );
    make_test(DMutable&    , size_t ,  true    );
    make_test(DContainer&  , size_t ,  true    );

    make_rval(DConst&&     , size_t ,  true    );
    make_rval(DMutable&&   , size_t ,  true    );
    make_rval(DContainer&& , size_t ,  true    );
//-----------------------------------------------------
    //       |   type      | index  | expected |
    make_test(DConst       , void*  ,  false   );
    make_test(DMutable     , void*  ,  false   );
    make_test(DContainer   , void*  ,  false   );

    make_test(DConst&      , void*  ,  false   );
    make_test(DMutable&    , void*  ,  false   );
    make_test(DContainer&  , void*  ,  false   );

    make_rval(DConst&&     , void*  ,  false   );
    make_rval(DMutable&&   , void*  ,  false   );
    make_rval(DContainer&& , void*  ,  false   );
}

// --- derived const
TEST_COMPONENT(004)
{
    //       |   type            | index  | expected |
    make_test(const DConst       , size_t ,  true    );
    make_test(const DMutable     , size_t ,  false   );
    make_test(const DContainer   , size_t ,  true    );
                                 
    make_test(const DConst&      , size_t ,  true    );
    make_test(const DMutable&    , size_t ,  false   );
    make_test(const DContainer&  , size_t ,  true    );
                                 
    make_rval(const DConst&&     , size_t ,  true    );
    make_rval(const DMutable&&   , size_t ,  false   );
    make_rval(const DContainer&& , size_t ,  true    );
//-----------------------------------------------------
    //       |   type            | index  | expected |
    make_test(const DConst       , void*  ,  false   );
    make_test(const DMutable     , void*  ,  false   );
    make_test(const DContainer   , void*  ,  false   );
                                             
    make_test(const DConst&      , void*  ,  false   );
    make_test(const DMutable&    , void*  ,  false   );
    make_test(const DContainer&  , void*  ,  false   );
                                             
    make_rval(const DConst&&     , void*  ,  false   );
    make_rval(const DMutable&&   , void*  ,  false   );
    make_rval(const DContainer&& , void*  ,  false   );

}
#endif  // dTEST_SFINAE_DERIVED

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRIVATE
// --- private non-const
TEST_COMPONENT(005)
{
    //       |   type      | index  | expected |
    make_test(PConst       , size_t ,  privat  );
    make_test(PMutable     , size_t ,  privat  );
    make_test(PContainer   , size_t ,  privat  );

    make_test(PConst&      , size_t ,  privat  );
    make_test(PMutable&    , size_t ,  privat  );
    make_test(PContainer&  , size_t ,  privat  );

    make_rval(PConst&&     , size_t ,  privat  );
    make_rval(PMutable&&   , size_t ,  privat  );
    make_rval(PContainer&& , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type      | index  | expected |
    make_test(PConst       , void*  ,  false   );
    make_test(PMutable     , void*  ,  false   );
    make_test(PContainer   , void*  ,  false   );

    make_test(PConst&      , void*  ,  false   );
    make_test(PMutable&    , void*  ,  false   );
    make_test(PContainer&  , void*  ,  false   );

    make_rval(PConst&&     , void*  ,  false   );
    make_rval(PMutable&&   , void*  ,  false   );
    make_rval(PContainer&& , void*  ,  false   );
}

// --- private const
TEST_COMPONENT(006)
{
    //       |   type            | index  | expected |
    make_test(const PConst       , size_t ,  privat  );
    make_test(const PMutable     , size_t ,  false   );
    make_test(const PContainer   , size_t ,  privat  );

    make_test(const PConst&      , size_t ,  privat  );
    make_test(const PMutable&    , size_t ,  false   );
    make_test(const PContainer&  , size_t ,  privat  );

    make_rval(const PConst&&     , size_t ,  privat  );
    make_rval(const PMutable&&   , size_t ,  false   );
    make_rval(const PContainer&& , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type            | index  | expected |
    make_test(const PConst       , void*  ,  false   );
    make_test(const PMutable     , void*  ,  false   );
    make_test(const PContainer   , void*  ,  false   );
                                   
    make_test(const PConst&      , void*  ,  false   );
    make_test(const PMutable&    , void*  ,  false   );
    make_test(const PContainer&  , void*  ,  false   );
                                   
    make_rval(const PConst&&     , void*  ,  false   );
    make_rval(const PMutable&&   , void*  ,  false   );
    make_rval(const PContainer&& , void*  ,  false   );
}
#endif // dTEST_SFINAE_PRIVATE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRVATE
// --- derived private  non-const
TEST_COMPONENT(007)
{
    //       |   type       | index  | expected |
    make_test(DPConst       , size_t ,  privat  );
    make_test(DPMutable     , size_t ,  privat  );
    make_test(DPContainer   , size_t ,  privat  );

    make_test(DPConst&      , size_t ,  privat  );
    make_test(DPMutable&    , size_t ,  privat  );
    make_test(DPContainer&  , size_t ,  privat  );

    make_rval(DPConst&&     , size_t ,  privat  );
    make_rval(DPMutable&&   , size_t ,  privat  );
    make_rval(DPContainer&& , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type       | index  | expected |
    make_test(DPConst       , void*  ,  privat  );
    make_test(DPMutable     , void*  ,  privat  );
    make_test(DPContainer   , void*  ,  privat  );
                              
    make_test(DPConst&      , void*  ,  privat  );
    make_test(DPMutable&    , void*  ,  privat  );
    make_test(DPContainer&  , void*  ,  privat  );
                              
    make_rval(DPConst&&     , void*  ,  privat  );
    make_rval(DPMutable&&   , void*  ,  privat  );
    make_rval(DPContainer&& , void*  ,  privat  );
}

// --- derived private const
TEST_COMPONENT(008)
{
    //       |   type             | index  | expected |
    make_test(const DPConst       , size_t ,  privat  );
    make_test(const DPMutable     , size_t ,  false   );
    make_test(const DPContainer   , size_t ,  privat  );
 
    make_test(const DPConst&      , size_t ,  privat  );
    make_test(const DPMutable&    , size_t ,  false   );
    make_test(const DPContainer&  , size_t ,  privat  );

    make_rval(const DPConst&&     , size_t ,  privat  );
    make_rval(const DPMutable&&   , size_t ,  false   );
    make_rval(const DPContainer&& , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type             | index  | expected |
    make_test(const DPConst       , void*  ,  false   );
    make_test(const DPMutable     , void*  ,  false   );
    make_test(const DPContainer   , void*  ,  false   );

    make_test(const DPConst&      , void*  ,  false   );
    make_test(const DPMutable&    , void*  ,  false   );
    make_test(const DPContainer&  , void*  ,  false   );

    make_rval(const DPConst&&     , void*  ,  false   );
    make_rval(const DPMutable&&   , void*  ,  false   );
    make_rval(const DPContainer&& , void*  ,  false   );
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
    //       |   type      | index  | expected |
    make_test(RConst       , size_t ,   true   );
    make_test(RMutable     , size_t ,   true   );
    make_test(RContainer   , size_t ,   true   );

    make_test(RConst&      , size_t ,   true   );
    make_test(RMutable&    , size_t ,   true   );
    make_test(RContainer&  , size_t ,   true   );

    make_rval(RConst&&     , size_t ,   true   );
    make_rval(RMutable&&   , size_t ,   true   );
    make_rval(RContainer&& , size_t ,   true   );
//-----------------------------------------------------
    //       |   type      | index  | expected |
    make_test(RConst       , void*  ,   false  );
    make_test(RMutable     , void*  ,   false  );
    make_test(RContainer   , void*  ,   false  );

    make_test(RConst&      , void*  ,   false  );
    make_test(RMutable&    , void*  ,   false  );
    make_test(RContainer&  , void*  ,   false  );

    make_rval(RConst&&     , void*  ,   false  );
    make_rval(RMutable&&   , void*  ,   false  );
    make_rval(RContainer&& , void*  ,   false  );
}

// --- recursieve const
TEST_COMPONENT(010)
{
    //       |   type            | index  | expected |
    make_test(const RConst       , size_t ,   true   );
    make_test(const RMutable     , size_t ,   false  );
    make_test(const RContainer   , size_t ,   true   );

    make_test(const RConst&      , size_t ,   true   );
    make_test(const RMutable&    , size_t ,   false  );
    make_test(const RContainer&  , size_t ,   true   );

    make_rval(const RConst&&     , size_t ,   true   );
    make_rval(const RMutable&&   , size_t ,   false  );
    make_rval(const RContainer&& , size_t ,   true   );
//-----------------------------------------------------
    //       |   type            | index  | expected |
    make_test(const RConst       , void*  ,  false   );
    make_test(const RMutable     , void*  ,  false   );
    make_test(const RContainer   , void*  ,  false   );

    make_test(const RConst&      , void*  ,  false   );
    make_test(const RMutable&    , void*  ,  false   );
    make_test(const RContainer&  , void*  ,  false   );
                                             
    make_rval(const RConst&&     , void*  ,  false   );
    make_rval(const RMutable&&   , void*  ,  false   );
    make_rval(const RContainer&& , void*  ,  false   );
}
#endif // dTEST_SFINAE_RECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DRECURSIEVE
// --- derived recursieve non-const
TEST_COMPONENT(011)
{
    //       |   type       | index  | expected |
    make_test(DRConst       , size_t ,   true   );
    make_test(DRMutable     , size_t ,   true   );
    make_test(DRContainer   , size_t ,   true   );
  
    make_test(DRConst&      , size_t ,   true   );
    make_test(DRMutable&    , size_t ,   true   );
    make_test(DRContainer&  , size_t ,   true   );

    make_rval(DRConst&&     , size_t ,   true   );
    make_rval(DRMutable&&   , size_t ,   true   );
    make_rval(DRContainer&& , size_t ,   true   );
//-----------------------------------------------------
    //       |   type       | index  | expected |
    make_test(DRConst       , void*  ,  false   );
    make_test(DRMutable     , void*  ,  false   );
    make_test(DRContainer   , void*  ,  false   );
                              
    make_test(DRConst&      , void*  ,  false   );
    make_test(DRMutable&    , void*  ,  false   );
    make_test(DRContainer&  , void*  ,  false   );
                              
    make_rval(DRConst&&     , void*  ,  false   );
    make_rval(DRMutable&&   , void*  ,  false   );
    make_rval(DRContainer&& , void*  ,  false   );
}

// --- derived recursieve const
TEST_COMPONENT(012)
{
    //       |   type             | index  | expected |
    make_test(const DRConst       , size_t ,   true   );
    make_test(const DRMutable     , size_t ,   false  );
    make_test(const DRContainer   , size_t ,   true   );
                                  
    make_test(const DRConst&      , size_t ,   true   );
    make_test(const DRMutable&    , size_t ,   false  );
    make_test(const DRContainer&  , size_t ,   true   );
                                  
    make_rval(const DRConst&&     , size_t ,   true   );
    make_rval(const DRMutable&&   , size_t ,   false  );
    make_rval(const DRContainer&& , size_t ,   true   );
//-----------------------------------------------------
    //       |   type             | index  | expected |
    make_test(const DRConst       , void*  ,  false   );
    make_test(const DRMutable     , void*  ,  false   );
    make_test(const DRContainer   , void*  ,  false   );

    make_test(const DRConst&      , void*  ,  false   );
    make_test(const DRMutable&    , void*  ,  false   );
    make_test(const DRContainer&  , void*  ,  false   );

    make_rval(const DRConst&&     , void*  ,  false   );
    make_rval(const DRMutable&&   , void*  ,  false   );
    make_rval(const DRContainer&& , void*  ,  false   );
}
#endif // dTEST_SFINAE_DRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PRECURSIEVE
// --- private recursieve non-const
TEST_COMPONENT(013)
{
    //       |   type       | index  | expected |
    make_test(PRConst       , size_t ,  privat  );
    make_test(PRMutable     , size_t ,  privat  );
    make_test(PRContainer   , size_t ,  privat  );
                               
    make_test(PRConst&      , size_t ,  privat  );
    make_test(PRMutable&    , size_t ,  privat  );
    make_test(PRContainer&  , size_t ,  privat  );
                            
    make_rval(PRConst&&     , size_t ,  privat  );
    make_rval(PRMutable&&   , size_t ,  privat  );
    make_rval(PRContainer&& , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type       | index  | expected |
    make_test(PRConst       , void*  ,  false   );
    make_test(PRMutable     , void*  ,  false   );
    make_test(PRContainer   , void*  ,  false   );

    make_test(PRConst&      , void*  ,  false   );
    make_test(PRMutable&    , void*  ,  false   );
    make_test(PRContainer&  , void*  ,  false   );

    make_rval(PRConst&&     , void*  ,  false   );
    make_rval(PRMutable&&   , void*  ,  false   );
    make_rval(PRContainer&& , void*  ,  false   );
}

// --- private recursieve const
TEST_COMPONENT(014)
{
    //       |   type             | index  | expected |
    make_test(const PRConst       , size_t ,  privat  );
    make_test(const PRMutable     , size_t ,  false   );
    make_test(const PRContainer   , size_t ,  privat  );

    make_test(const PRConst&      , size_t ,  privat  );
    make_test(const PRMutable&    , size_t ,  false   );
    make_test(const PRContainer&  , size_t ,  privat  );

    make_rval(const PRConst&&     , size_t ,  privat  );
    make_rval(const PRMutable&&   , size_t ,  false   );
    make_rval(const PRContainer&& , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type             | index  | expected |
    make_test(const PRConst       , void*  ,  false   );
    make_test(const PRMutable     , void*  ,  false   );
    make_test(const PRContainer   , void*  ,  false   );

    make_test(const PRConst&      , void*  ,  false   );
    make_test(const PRMutable&    , void*  ,  false   );
    make_test(const PRContainer&  , void*  ,  false   );

    make_rval(const PRConst&&     , void*  ,  false   );
    make_rval(const PRMutable&&   , void*  ,  false   );
    make_rval(const PRContainer&& , void*  ,  false   );
}
#endif // dTEST_SFINAE_PRECURSIEVE

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPRECURSIEVE
// --- derived private recursieve non-const
TEST_COMPONENT(015)
{
    //       |   type        | index  | expected |
    make_test(DPRConst       , size_t ,  privat  );
    make_test(DPRMutable     , size_t ,  privat  );
    make_test(DPRContainer   , size_t ,  privat  );

    make_test(DPRConst&      , size_t ,  privat  );
    make_test(DPRMutable&    , size_t ,  privat  );
    make_test(DPRContainer&  , size_t ,  privat  );

    make_rval(DPRConst&&     , size_t ,  privat  );
    make_rval(DPRMutable&&   , size_t ,  privat  );
    make_rval(DPRContainer&& , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type        | index  | expected |
    make_test(DPRConst       , void*  ,  false  );
    make_test(DPRMutable     , void*  ,  false  );
    make_test(DPRContainer   , void*  ,  false  );

    make_test(DPRConst&      , void*  ,  false  );
    make_test(DPRMutable&    , void*  ,  false  );
    make_test(DPRContainer&  , void*  ,  false  );

    make_rval(DPRConst&&     , void*  ,  false  );
    make_rval(DPRMutable&&   , void*  ,  false  );
    make_rval(DPRContainer&& , void*  ,  false  );
}

// --- derived private recursieve const
TEST_COMPONENT(016)
{
    //       |   type              | index  | expected |
    make_test(const DPRConst       , size_t ,  privat  );
    make_test(const DPRMutable     , size_t ,  false   );
    make_test(const DPRContainer   , size_t ,  privat  );

    make_test(const DPRConst&      , size_t ,  privat  );
    make_test(const DPRMutable&    , size_t ,  false   );
    make_test(const DPRContainer&  , size_t ,  privat  );

    make_rval(const DPRConst&&     , size_t ,  privat  );
    make_rval(const DPRMutable&&   , size_t ,  false   );
    make_rval(const DPRContainer&& , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type              | index  | expected |
    make_test(const DPRConst       , void*  ,  false   );
    make_test(const DPRMutable     , void*  ,  false   );
    make_test(const DPRContainer   , void*  ,  false   );

    make_test(const DPRConst&      , void*  ,  false   );
    make_test(const DPRMutable&    , void*  ,  false   );
    make_test(const DPRContainer&  , void*  ,  false   );

    make_rval(const DPRConst&&     , void*  ,  false   );
    make_rval(const DPRMutable&&   , void*  ,  false   );
    make_rval(const DPRContainer&& , void*  ,  false   );
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
    //       |   type             | index  | expected |
    make_test(UnsuitableConst     , size_t ,  false   );
    make_test(UnsuitableMutable   , size_t ,  false   );
    make_test(Unsuitable          , size_t ,  false   );

    make_test(UnsuitableConst&    , size_t ,  false   );
    make_test(UnsuitableMutable&  , size_t ,  false   );
    make_test(Unsuitable&         , size_t ,  false   );

    make_rval(UnsuitableConst&&   , size_t ,  false   );
    make_rval(UnsuitableMutable&& , size_t ,  false   );
    make_rval(Unsuitable&&        , size_t ,  false   );
//-----------------------------------------------------
    //       |   type             | index  | expected |
    make_test(UnsuitableConst     , void*  ,  false   );
    make_test(UnsuitableMutable   , void*  ,  false   );
    make_test(Unsuitable          , void*  ,  false   );

    make_test(UnsuitableConst&    , void*  ,  false   );
    make_test(UnsuitableMutable&  , void*  ,  false   );
    make_test(Unsuitable&         , void*  ,  false   );

    make_rval(UnsuitableConst&&   , void*  ,  false   );
    make_rval(UnsuitableMutable&& , void*  ,  false   );
    make_rval(Unsuitable&&        , void*  ,  false   );
}
TEST_COMPONENT(018)
{
    //       |   type                   | index  | expected |
    make_test(const UnsuitableConst     , size_t ,  false   );
    make_test(const UnsuitableMutable   , size_t ,  false   );
    make_test(const Unsuitable          , size_t ,  false   );

    make_test(const UnsuitableConst&    , size_t ,  false   );
    make_test(const UnsuitableMutable&  , size_t ,  false   );
    make_test(const Unsuitable&         , size_t ,  false   );

    make_rval(const UnsuitableConst&&   , size_t ,  false   );
    make_rval(const UnsuitableMutable&& , size_t ,  false   );
    make_rval(const Unsuitable&&        , size_t ,  false   );
//-----------------------------------------------------
    //       |   type                   | index  | expected |
    make_test(const UnsuitableConst     , void*  ,  false   );
    make_test(const UnsuitableMutable   , void*  ,  false   );
    make_test(const Unsuitable          , void*  ,  false   );
                                          
    make_test(const UnsuitableConst&    , void*  ,  false   );
    make_test(const UnsuitableMutable&  , void*  ,  false   );
    make_test(const Unsuitable&         , void*  ,  false   );
                                          
    make_rval(const UnsuitableConst&&   , void*  ,  false   );
    make_rval(const UnsuitableMutable&& , void*  ,  false   );
    make_rval(const Unsuitable&&        , void*  ,  false   );
}
#endif // dTEST_SFINAE_UNSUITABLE

#ifdef dTEST_SFINAE_DUNSUITABLE
TEST_COMPONENT(019)
{ 
    //       |   type              | index  | expected |
    make_test(DUnsuitableConst     , size_t ,  false   );
    make_test(DUnsuitableMutable   , size_t ,  false   );
    make_test(DUnsuitable          , size_t ,  false   );

    make_test(DUnsuitableConst&    , size_t ,  false   );
    make_test(DUnsuitableMutable&  , size_t ,  false   );
    make_test(DUnsuitable&         , size_t ,  false   );

    make_rval(DUnsuitableConst&&   , size_t ,  false   );
    make_rval(DUnsuitableMutable&& , size_t ,  false   );
    make_rval(DUnsuitable&&        , size_t ,  false   );
//-----------------------------------------------------
    //       |   type              | index  | expected |
    make_test(DUnsuitableConst     , void*  ,  false   );
    make_test(DUnsuitableMutable   , void*  ,  false   );
    make_test(DUnsuitable          , void*  ,  false   );

    make_test(DUnsuitableConst&    , void*  ,  false   );
    make_test(DUnsuitableMutable&  , void*  ,  false   );
    make_test(DUnsuitable&         , void*  ,  false   );

    make_rval(DUnsuitableConst&&   , void*  ,  false   );
    make_rval(DUnsuitableMutable&& , void*  ,  false   );
    make_rval(DUnsuitable&&        , void*  ,  false   );
}
TEST_COMPONENT(020)
{ 
    //       |   type                    | index  | expected |
    make_test(const DUnsuitableConst     , size_t ,  false   );
    make_test(const DUnsuitableMutable   , size_t ,  false   );
    make_test(const DUnsuitable          , size_t ,  false   );

    make_test(const DUnsuitableConst&    , size_t ,  false   );
    make_test(const DUnsuitableMutable&  , size_t ,  false   );
    make_test(const DUnsuitable&         , size_t ,  false   );

    make_rval(const DUnsuitableConst&&   , size_t ,  false   );
    make_rval(const DUnsuitableMutable&& , size_t ,  false   );
    make_rval(const DUnsuitable&&        , size_t ,  false   );
//-----------------------------------------------------
    //       |   type                    | index  | expected |
    make_test(const DUnsuitableConst     , void*  ,  false   );
    make_test(const DUnsuitableMutable   , void*  ,  false   );
    make_test(const DUnsuitable          , void*  ,  false   );
                                                  
    make_test(const DUnsuitableConst&    , void*  ,  false   );
    make_test(const DUnsuitableMutable&  , void*  ,  false   );
    make_test(const DUnsuitable&         , void*  ,  false   );
                                                  
    make_rval(const DUnsuitableConst&&   , void*  ,  false   );
    make_rval(const DUnsuitableMutable&& , void*  ,  false   );
    make_rval(const DUnsuitable&&        , void*  ,  false   );
}
#endif // dTEST_SFINAE_DUNSUITABLE

#ifdef dTEST_SFINAE_PUNSUITABLE
TEST_COMPONENT(021)
{ 
    //       |   type              | index  | expected |
    make_test(PUnsuitableConst     , size_t ,  false   );
    make_test(PUnsuitableMutable   , size_t ,  false   );
    make_test(PUnsuitable          , size_t ,  false   );
                                             
    make_test(PUnsuitableConst&    , size_t ,  false   );
    make_test(PUnsuitableMutable&  , size_t ,  false   );
    make_test(PUnsuitable&         , size_t ,  false   );
                                             
    make_rval(PUnsuitableConst&&   , size_t ,  false   );
    make_rval(PUnsuitableMutable&& , size_t ,  false   );
    make_rval(PUnsuitable&&        , size_t ,  false   );
//-----------------------------------------------------
    //       |   type              | index  | expected |
    make_test(PUnsuitableConst     , void*  ,  false   );
    make_test(PUnsuitableMutable   , void*  ,  false   );
    make_test(PUnsuitable          , void*  ,  false   );
                                       
    make_test(PUnsuitableConst&    , void*  ,  false   );
    make_test(PUnsuitableMutable&  , void*  ,  false   );
    make_test(PUnsuitable&         , void*  ,  false   );
                                     
    make_rval(PUnsuitableConst&&   , void*  ,  false   );
    make_rval(PUnsuitableMutable&& , void*  ,  false   );
    make_rval(PUnsuitable&&        , void*  ,  false   );
}
TEST_COMPONENT(022)
{ 
    //       |   type                    | index  | expected |
    make_test(const PUnsuitableConst     , size_t ,  false   );
    make_test(const PUnsuitableMutable   , size_t ,  false   );
    make_test(const PUnsuitable          , size_t ,  false   );
                                          
    make_test(const PUnsuitableConst&    , size_t ,  false   );
    make_test(const PUnsuitableMutable&  , size_t ,  false   );
    make_test(const PUnsuitable&         , size_t ,  false   );
                                         
    make_rval(const PUnsuitableConst&&   , size_t ,  false   );
    make_rval(const PUnsuitableMutable&& , size_t ,  false   );
    make_rval(const PUnsuitable&&        , size_t ,  false   );
//-----------------------------------------------------
    //       |   type                    | index  | expected |
    make_test(const PUnsuitableConst     , void*  ,  false   );
    make_test(const PUnsuitableMutable   , void*  ,  false   );
    make_test(const PUnsuitable          , void*  ,  false   );
                                           
    make_test(const PUnsuitableConst&    , void*  ,  false   );
    make_test(const PUnsuitableMutable&  , void*  ,  false   );
    make_test(const PUnsuitable&         , void*  ,  false   );
                                           
    make_rval(const PUnsuitableConst&&   , void*  ,  false   );
    make_rval(const PUnsuitableMutable&& , void*  ,  false   );
    make_rval(const PUnsuitable&&        , void*  ,  false   );
}
#endif // dTEST_SFINAE_PUNSUITABLE

#ifdef dTEST_SFINAE_DPUNSUITABLE
TEST_COMPONENT(023)
{ 
    //       |   type               | index  | expected |
    make_test(DPUnsuitableConst     , size_t ,  false   );
    make_test(DPUnsuitableMutable   , size_t ,  false   );
    make_test(DPUnsuitable          , size_t ,  false   );
                                    
    make_test(DPUnsuitableConst&    , size_t ,  false   );
    make_test(DPUnsuitableMutable&  , size_t ,  false   );
    make_test(DPUnsuitable&         , size_t ,  false   );
                                    
    make_rval(DPUnsuitableConst&&   , size_t ,  false   );
    make_rval(DPUnsuitableMutable&& , size_t ,  false   );
    make_rval(DPUnsuitable&&        , size_t ,  false   );
//-----------------------------------------------------
    //       |   type               | index  | expected |
    make_test(DPUnsuitableConst     , void*  ,  false   );
    make_test(DPUnsuitableMutable   , void*  ,  false   );
    make_test(DPUnsuitable          , void*  ,  false   );
                                      
    make_test(DPUnsuitableConst&    , void*  ,  false   );
    make_test(DPUnsuitableMutable&  , void*  ,  false   );
    make_test(DPUnsuitable&         , void*  ,  false   );
                                      
    make_rval(DPUnsuitableConst&&   , void*  ,  false   );
    make_rval(DPUnsuitableMutable&& , void*  ,  false   );
    make_rval(DPUnsuitable&&        , void*  ,  false   );
}
TEST_COMPONENT(024)
{ 
    //       |   type                     | index  | expected |
    make_test(const DPUnsuitableConst     , size_t ,  false   );
    make_test(const DPUnsuitableMutable   , size_t ,  false   );
    make_test(const DPUnsuitable          , size_t ,  false   );
                                            
    make_test(const DPUnsuitableConst&    , size_t ,  false   );
    make_test(const DPUnsuitableMutable&  , size_t ,  false   );
    make_test(const DPUnsuitable&         , size_t ,  false   );
                                          
    make_rval(const DPUnsuitableConst&&   , size_t ,  false   );
    make_rval(const DPUnsuitableMutable&& , size_t ,  false   );
    make_rval(const DPUnsuitable&&        , size_t ,  false   );
//-----------------------------------------------------
    //       |   type                     | index  | expected |
    make_test(const DPUnsuitableConst     , void*  ,  false   );
    make_test(const DPUnsuitableMutable   , void*  ,  false   );
    make_test(const DPUnsuitable          , void*  ,  false   );

    make_test(const DPUnsuitableConst&    , void*  ,  false   );
    make_test(const DPUnsuitableMutable&  , void*  ,  false   );
    make_test(const DPUnsuitable&         , void*  ,  false   );

    make_rval(const DPUnsuitableConst&&   , void*  ,  false   );
    make_rval(const DPUnsuitableMutable&& , void*  ,  false   );
    make_rval(const DPUnsuitable&&        , void*  ,  false   );
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
    //       |   type      | index  | expected |
    make_test(IntConst     , size_t ,  true    );
    make_test(IntMutable   , size_t ,  true    );
    make_test(Int          , size_t ,  true    );

    make_test(IntConst&    , size_t ,  true    );
    make_test(IntMutable&  , size_t ,  true    );
    make_test(Int&         , size_t ,  true    );

    make_rval(IntConst&&   , size_t ,  true    );
    make_rval(IntMutable&& , size_t ,  true    );
    make_rval(Int&&        , size_t ,  true    );
//-----------------------------------------------------
    //       |   type      | index  | expected |
    make_test(IntConst     , void*  ,  false   );
    make_test(IntMutable   , void*  ,  false   );
    make_test(Int          , void*  ,  false   );
                                       
    make_test(IntConst&    , void*  ,  false   );
    make_test(IntMutable&  , void*  ,  false   );
    make_test(Int&         , void*  ,  false   );
                                       
    make_rval(IntConst&&   , void*  ,  false   );
    make_rval(IntMutable&& , void*  ,  false   );
    make_rval(Int&&        , void*  ,  false   );
}

// --- const
TEST_COMPONENT(026)
{
    //       |   type            | index  | expected |
    make_test(const IntConst     , size_t ,  true    );
    make_test(const IntMutable   , size_t ,  false   );
    make_test(const Int          , size_t ,  true    );

    make_test(const IntConst&    , size_t ,  true    );
    make_test(const IntMutable&  , size_t ,  false   );
    make_test(const Int&         , size_t ,  true    );

    make_rval(const IntConst&&   , size_t ,  true    );
    make_rval(const IntMutable&& , size_t ,  false   );
    make_rval(const Int&&        , size_t ,  true    );
//-----------------------------------------------------
    //       |   type            | index  | expected |
    make_test(const IntConst     , void*  ,  false   );
    make_test(const IntMutable   , void*  ,  false   );
    make_test(const Int          , void*  ,  false   );
                                             
    make_test(const IntConst&    , void*  ,  false   );
    make_test(const IntMutable&  , void*  ,  false   );
    make_test(const Int&         , void*  ,  false   );
                                             
    make_rval(const IntConst&&   , void*  ,  false   );
    make_rval(const IntMutable&& , void*  ,  false   );
    make_rval(const Int&&        , void*  ,  false   );
}
#endif // dTEST_SFINAE_INT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DINT
// --- non-const
TEST_COMPONENT(027)
{
    //       |   type       | index  | expected |
    make_test(DIntConst     , size_t ,  true    );
    make_test(DIntMutable   , size_t ,  true    );
    make_test(DInt          , size_t ,  true    );

    make_test(DIntConst&    , size_t ,  true    );
    make_test(DIntMutable&  , size_t ,  true    );
    make_test(DInt&         , size_t ,  true    );

    make_rval(DIntConst&&   , size_t ,  true    );
    make_rval(DIntMutable&& , size_t ,  true    );
    make_rval(DInt&&        , size_t ,  true    );
//-----------------------------------------------------
    //       |   type       | index  | expected |
    make_test(DIntConst     , void*  ,  false   );
    make_test(DIntMutable   , void*  ,  false   );
    make_test(DInt          , void*  ,  false   );

    make_test(DIntConst&    , void*  ,  false   );
    make_test(DIntMutable&  , void*  ,  false   );
    make_test(DInt&         , void*  ,  false   );

    make_rval(DIntConst&&   , void*  ,  false   );
    make_rval(DIntMutable&& , void*  ,  false   );
    make_rval(DInt&&        , void*  ,  false   );
}

// --- const
TEST_COMPONENT(028)
{
    //       |   type             | index  | expected |
    make_test(const DIntConst     , size_t ,  true    );
    make_test(const DIntMutable   , size_t ,  false   );
    make_test(const DInt          , size_t ,  true    );

    make_test(const DIntConst&    , size_t ,  true    );
    make_test(const DIntMutable&  , size_t ,  false   );
    make_test(const DInt&         , size_t ,  true    );

    make_rval(const DIntConst&&   , size_t ,  true    );
    make_rval(const DIntMutable&& , size_t ,  false   );
    make_rval(const DInt&&        , size_t ,  true    );
//-----------------------------------------------------
    //       |   type             | index  | expected |
    make_test(const DIntConst     , void*  ,  false   );
    make_test(const DIntMutable   , void*  ,  false   );
    make_test(const DInt          , void*  ,  false   );
                                              
    make_test(const DIntConst&    , void*  ,  false   );
    make_test(const DIntMutable&  , void*  ,  false   );
    make_test(const DInt&         , void*  ,  false   );
                                              
    make_rval(const DIntConst&&   , void*  ,  false   );
    make_rval(const DIntMutable&& , void*  ,  false   );
    make_rval(const DInt&&        , void*  ,  false   );
}
#endif // dTEST_SFINAE_DINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PINT
// --- non-const
TEST_COMPONENT(029)
{
    //       |   type       | index  | expected |
    make_test(PIntConst     , size_t ,  privat  );
    make_test(PIntMutable   , size_t ,  privat  );
    make_test(PInt          , size_t ,  privat  );

    make_test(PIntConst&    , size_t ,  privat  );
    make_test(PIntMutable&  , size_t ,  privat  );
    make_test(PInt&         , size_t ,  privat  );

    make_rval(PIntConst&&   , size_t ,  privat  );
    make_rval(PIntMutable&& , size_t ,  privat  );
    make_rval(PInt&&        , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type       | index  | expected |
    make_test(PIntConst     , void*  ,  false   );
    make_test(PIntMutable   , void*  ,  false   );
    make_test(PInt          , void*  ,  false   );

    make_test(PIntConst&    , void*  ,  false   );
    make_test(PIntMutable&  , void*  ,  false   );
    make_test(PInt&         , void*  ,  false   );

    make_rval(PIntConst&&   , void*  ,  false   );
    make_rval(PIntMutable&& , void*  ,  false   );
    make_rval(PInt&&        , void*  ,  false   );
}

// --- const
TEST_COMPONENT(030)
{
    //       |   type             | index  | expected |
    make_test(const PIntConst     , size_t ,  privat  );
    make_test(const PIntMutable   , size_t ,  false   );
    make_test(const PInt          , size_t ,  privat  );
  
    make_test(const PIntConst&    , size_t ,  privat  );
    make_test(const PIntMutable&  , size_t ,  false   );
    make_test(const PInt&         , size_t ,  privat  );

    make_rval(const PIntConst&&   , size_t ,  privat  );
    make_rval(const PIntMutable&& , size_t ,  false   );
    make_rval(const PInt&&        , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type             | index  | expected |
    make_test(const PIntConst     , void*  ,  false  );
    make_test(const PIntMutable   , void*  ,  false  );
    make_test(const PInt          , void*  ,  false  );

    make_test(const PIntConst&    , void*  ,  false  );
    make_test(const PIntMutable&  , void*  ,  false  );
    make_test(const PInt&         , void*  ,  false  );

    make_rval(const PIntConst&&   , void*  ,  false  );
    make_rval(const PIntMutable&& , void*  ,  false  );
    make_rval(const PInt&&        , void*  ,  false  );
}
#endif // dTEST_SFINAE_PINT

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPINT
// --- non-const
TEST_COMPONENT(031)
{
    //       |   type        | index  | expected |
    make_test(DPIntConst     , size_t ,  privat  );
    make_test(DPIntMutable   , size_t ,  privat  );
    make_test(DPInt          , size_t ,  privat  );
  
    make_test(DPIntConst&    , size_t ,  privat  );
    make_test(DPIntMutable&  , size_t ,  privat  );
    make_test(DPInt&         , size_t ,  privat  );

    make_rval(DPIntConst&&   , size_t ,  privat  );
    make_rval(DPIntMutable&& , size_t ,  privat  );
    make_rval(DPInt&&        , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type        | index  | expected |
    make_test(DPIntConst     , void*  ,  false   );
    make_test(DPIntMutable   , void*  ,  false   );
    make_test(DPInt          , void*  ,  false   );

    make_test(DPIntConst&    , void*  ,  false   );
    make_test(DPIntMutable&  , void*  ,  false   );
    make_test(DPInt&         , void*  ,  false   );

    make_rval(DPIntConst&&   , void*  ,  false   );
    make_rval(DPIntMutable&& , void*  ,  false   );
    make_rval(DPInt&&        , void*  ,  false   );

}

// --- const
TEST_COMPONENT(032)
{
    //       |   type              | index  | expected |
    make_test(const DPIntConst     , size_t ,  privat  );
    make_test(const DPIntMutable   , size_t ,  false   );
    make_test(const DPInt          , size_t ,  privat  );

    make_test(const DPIntConst&    , size_t ,  privat  );
    make_test(const DPIntMutable&  , size_t ,  false   );
    make_test(const DPInt&         , size_t ,  privat  );

    make_rval(const DPIntConst&&   , size_t ,  privat  );
    make_rval(const DPIntMutable&& , size_t ,  false   );
    make_rval(const DPInt&&        , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type              | index  | expected |
    make_test(const DPIntConst     , void*  ,  false  );
    make_test(const DPIntMutable   , void*  ,  false  );
    make_test(const DPInt          , void*  ,  false  );

    make_test(const DPIntConst&    , void*  ,  false  );
    make_test(const DPIntMutable&  , void*  ,  false  );
    make_test(const DPInt&         , void*  ,  false  );

    make_rval(const DPIntConst&&   , void*  ,  false  );
    make_rval(const DPIntMutable&& , void*  ,  false  );
    make_rval(const DPInt&&        , void*  ,  false  );
}
#endif // dTEST_SFINAE_DPINT

//..............................................................................
//..............................................................................

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_BODY
// --- non-const
TEST_COMPONENT(033)
{
    //       |   type         | index  | expected |
    make_test(BodyConst       , size_t ,  true    );
    make_test(BodyMutable     , size_t ,  true    );
    make_test(Body            , size_t ,  true    );

    make_test(BodyConst&      , size_t ,  true    );
    make_test(BodyMutable&    , size_t ,  true    );
    make_test(Body&           , size_t ,  true    );

    make_rval(BodyConst&&     , size_t ,  true    );
    make_rval(BodyMutable&&   , size_t ,  true    );
    make_rval(Body&&          , size_t ,  true    );
//-----------------------------------------------------
    //       |   type         | index  | expected |
    make_test(BodyConst       , void*  ,  false   );
    make_test(BodyMutable     , void*  ,  false   );
    make_test(Body            , void*  ,  false   );

    make_test(BodyConst&      , void*  ,  false   );
    make_test(BodyMutable&    , void*  ,  false   );
    make_test(Body&           , void*  ,  false   );

    make_rval(BodyConst&&     , void*  ,  false   );
    make_rval(BodyMutable&&   , void*  ,  false   );
    make_rval(Body&&          , void*  ,  false   );
}

// --- const
TEST_COMPONENT(034)
{
    //       |   type              | index  | expected |
    make_test(const BodyConst      , size_t ,  true    );
    make_test(const BodyMutable    , size_t ,  false   );
    make_test(const Body           , size_t ,  true    );
                    
    make_test(const BodyConst&     , size_t ,  true    );
    make_test(const BodyMutable&   , size_t ,  false   );
    make_test(const Body&          , size_t ,  true    );
                    
    make_rval(const BodyConst&&    , size_t ,  true    );
    make_rval(const BodyMutable&&  , size_t ,  false   );
    make_rval(const Body&&         , size_t ,  true    );
//-----------------------------------------------------
    //       |   type              | index  | expected |
    make_test(const BodyConst      , void*  ,  false   );
    make_test(const BodyMutable    , void*  ,  false   );
    make_test(const Body           , void*  ,  false   );

    make_test(const BodyConst&     , void*  ,  false   );
    make_test(const BodyMutable&   , void*  ,  false   );
    make_test(const Body&          , void*  ,  false   );

    make_rval(const BodyConst&&    , void*  ,  false   );
    make_rval(const BodyMutable&&  , void*  ,  false   );
    make_rval(const Body&&         , void*  ,  false   );
}
#endif // dTEST_SFINAE_REGULAR

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DBODY
// --- derived non-const
TEST_COMPONENT(035)
{
    //       |   type        | index  | expected |
    make_test(DBodyConst     , size_t ,  true    );
    make_test(DBodyMutable   , size_t ,  true    );
    make_test(DBody          , size_t ,  true    );

    make_test(DBodyConst&    , size_t ,  true    );
    make_test(DBodyMutable&  , size_t ,  true    );
    make_test(DBody&         , size_t ,  true    );

    make_rval(DBodyConst&&   , size_t ,  true    );
    make_rval(DBodyMutable&& , size_t ,  true    );
    make_rval(DBody&&        , size_t ,  true    );
//-----------------------------------------------------
    //       |   type        | index  | expected |
    make_test(DBodyConst     , void*  ,  false   );
    make_test(DBodyMutable   , void*  ,  false   );
    make_test(DBody          , void*  ,  false   );

    make_test(DBodyConst&    , void*  ,  false   );
    make_test(DBodyMutable&  , void*  ,  false   );
    make_test(DBody&         , void*  ,  false   );

    make_rval(DBodyConst&&   , void*  ,  false   );
    make_rval(DBodyMutable&& , void*  ,  false   );
    make_rval(DBody&&        , void*  ,  false   );
}

// --- derived const
TEST_COMPONENT(036)
{
    //       |   type              | index  | expected |
    make_test(const DBodyConst     , size_t ,  true    );
    make_test(const DBodyMutable   , size_t ,  false   );
    make_test(const DBody          , size_t ,  true    );

    make_test(const DBodyConst&    , size_t ,  true    );
    make_test(const DBodyMutable&  , size_t ,  false   );
    make_test(const DBody&         , size_t ,  true    );

    make_rval(const DBodyConst&&   , size_t ,  true    );
    make_rval(const DBodyMutable&& , size_t ,  false   );
    make_rval(const DBody&&        , size_t ,  true    );
//-----------------------------------------------------
    //       |   type              | index  | expected |
    make_test(const DBodyConst     , void*  ,  false   );
    make_test(const DBodyMutable   , void*  ,  false   );
    make_test(const DBody          , void*  ,  false   );

    make_test(const DBodyConst&    , void*  ,  false   );
    make_test(const DBodyMutable&  , void*  ,  false   );
    make_test(const DBody&         , void*  ,  false   );

    make_rval(const DBodyConst&&   , void*  ,  false   );
    make_rval(const DBodyMutable&& , void*  ,  false   );
    make_rval(const DBody&&        , void*  ,  false   );
}
#endif  // dTEST_SFINAE_DERIVED

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_PBODY
// --- private non-const
TEST_COMPONENT(037)
{
    //       |   type        | index  | expected |
    make_test(PBodyConst     , size_t ,  privat  );
    make_test(PBodyMutable   , size_t ,  privat  );
    make_test(PBody          , size_t ,  privat  );
                             
    make_test(PBodyConst&    , size_t ,  privat  );
    make_test(PBodyMutable&  , size_t ,  privat  );
    make_test(PBody&         , size_t ,  privat  );
               
    make_rval(PBodyConst&&   , size_t ,  privat  );
    make_rval(PBodyMutable&& , size_t ,  privat  );
    make_rval(PBody&&        , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type        | index  | expected |
    make_test(PBodyConst     , void*  ,  false   );
    make_test(PBodyMutable   , void*  ,  false   );
    make_test(PBody          , void*  ,  false   );

    make_test(PBodyConst&    , void*  ,  false   );
    make_test(PBodyMutable&  , void*  ,  false   );
    make_test(PBody&         , void*  ,  false   );

    make_rval(PBodyConst&&   , void*  ,  false   );
    make_rval(PBodyMutable&& , void*  ,  false   );
    make_rval(PBody&&        , void*  ,  false   );
}

// --- private const
TEST_COMPONENT(038)
{
    //       |   type              | index  | expected |
    make_test(const PBodyConst     , size_t ,  privat  );
    make_test(const PBodyMutable   , size_t ,  false   );
    make_test(const PBody          , size_t ,  privat  );

    make_test(const PBodyConst&    , size_t ,  privat  );
    make_test(const PBodyMutable&  , size_t ,  false   );
    make_test(const PBody&         , size_t ,  privat  );

    make_rval(const PBodyConst&&   , size_t ,  privat  );
    make_rval(const PBodyMutable&& , size_t ,  false   );
    make_rval(const PBody&&        , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type              | index  | expected |
    make_test(const PBodyConst     , void*  ,  false  );
    make_test(const PBodyMutable   , void*  ,  false  );
    make_test(const PBody          , void*  ,  false  );

    make_test(const PBodyConst&    , void*  ,  false  );
    make_test(const PBodyMutable&  , void*  ,  false  );
    make_test(const PBody&         , void*  ,  false  );

    make_rval(const PBodyConst&&   , void*  ,  false  );
    make_rval(const PBodyMutable&& , void*  ,  false  );
    make_rval(const PBody&&        , void*  ,  false  );
}
#endif // dTEST_SFINAE_PBODY

//==============================================================================
//==============================================================================
#ifdef dTEST_SFINAE_DPBODY
// --- derived private  non-const
TEST_COMPONENT(039)
{
    //       |   type         | index  | expected |
    make_test(DPBodyConst     , size_t ,  privat  );
    make_test(DPBodyMutable   , size_t ,  privat  );
    make_test(DPBody          , size_t ,  privat  );
                              
    make_test(DPBodyConst&    , size_t ,  privat  );
    make_test(DPBodyMutable&  , size_t ,  privat  );
    make_test(DPBody&         , size_t ,  privat  );
                              
    make_rval(DPBodyConst&&   , size_t ,  privat  );
    make_rval(DPBodyMutable&& , size_t ,  privat  );
    make_rval(DPBody&&        , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type         | index  | expected |
    make_test(DPBodyConst     , void*  ,  false   );
    make_test(DPBodyMutable   , void*  ,  false   );
    make_test(DPBody          , void*  ,  false   );

    make_test(DPBodyConst&    , void*  ,  false   );
    make_test(DPBodyMutable&  , void*  ,  false   );
    make_test(DPBody&         , void*  ,  false   );

    make_rval(DPBodyConst&&   , void*  ,  false   );
    make_rval(DPBodyMutable&& , void*  ,  false   );
    make_rval(DPBody&&        , void*  ,  false   );
}

// --- derived private const
TEST_COMPONENT(040)
{
    //       |   type               | index  | expected |
    make_test(const DPBodyConst     , size_t ,  privat  );
    make_test(const DPBodyMutable   , size_t ,  false   );
    make_test(const DPBody          , size_t ,  privat  );

    make_test(const DPBodyConst&    , size_t ,  privat  );
    make_test(const DPBodyMutable&  , size_t ,  false   );
    make_test(const DPBody&         , size_t ,  privat  );

    make_rval(const DPBodyConst&&   , size_t ,  privat  );
    make_rval(const DPBodyMutable&& , size_t ,  false   );
    make_rval(const DPBody&&        , size_t ,  privat  );
//-----------------------------------------------------
    //       |   type               | index  | expected |
    make_test(const DPBodyConst     , void*  ,  false   );
    make_test(const DPBodyMutable   , void*  ,  false   );
    make_test(const DPBody          , void*  ,  false   );
 
    make_test(const DPBodyConst&    , void*  ,  false   );
    make_test(const DPBodyMutable&  , void*  ,  false   );
    make_test(const DPBody&         , void*  ,  false   );

    make_rval(const DPBodyConst&&   , void*  ,  false   );
    make_rval(const DPBodyMutable&& , void*  ,  false   );
    make_rval(const DPBody&&        , void*  ,  false   );
}
#endif // dTEST_SFINAE_DPBODY

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_SFINAE_ACCESS
