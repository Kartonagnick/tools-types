// [2021y-04m-29d][12:57:49] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_BEGIN
#define dTEST_COMPONENT tools, types, sfinae, available
#define dTEST_METHOD begin
#define dTEST_TAG tdd


// #include <tools/features.hpp>
// #ifdef dHAS_CPP11

#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::available;
//==============================================================================
//==============================================================================
namespace
{
    #define dexpression(type, expected) \
        me::begin<type>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, expected)                     \
            static_assert(                                    \
                dexpression(type, expected),                  \
                "tools::sfinae::available::begin<" #type "> " \
                "must be '" #expected "'"                     \
            )
    #else
        #define make_test(type, expected)   \
            dSTATIC_CHECK(                  \
                ERROR_MUST_BE_##expected,   \
                dexpression(type, expected) \
            )
    #endif

    #ifdef dHAS_RVALUE_REFERENCES
        #define make_rval(type, expected) \
            make_test(type, expected)
    #else
        #define make_rval(type, expected) \
            void()
    #endif

//----------------------------------
    struct Maket;
    struct Dummy {};
    struct Mutable
    {
        void begin(); 
    };
    struct Const 
    {
        void begin() const;
    };
    struct Container
    {
        void begin() ;
        void begin() const;
    };
//----------------------------------
    struct DMutable   : Mutable   {};
    struct DConst     : Const     {};
    struct DContainer : Container {};
//----------------------------------
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
//----------------------------------
    struct DPMutable   : PMutable   {};
    struct DPConst     : PConst     {};
    struct DPContainer : PContainer {};
//----------------------------------
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
    struct DRMutable   : RMutable   {};
    struct DRConst     : RConst     {};
    struct DRContainer : RContainer {};
//----------------------------------
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
//----------------------------------
    struct DPRMutable   : PRMutable   {};
    struct DPRConst     : PRConst     {};
    struct DPRContainer : PRContainer {};
//----------------------------------

} // namespace

//==============================================================================
//==============================================================================
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
    make_test(const Mutable     ,  false   );
    make_test(const Container   ,  true    );

    make_test(const Const&      ,  true    );
    make_test(const Mutable&    ,  false   );
    make_test(const Container&  ,  true    );

    make_rval(const Const&&     ,  true    );
    make_rval(const Mutable&&   ,  false   );
    make_rval(const Container&& ,  true    );
}

//==============================================================================
//==============================================================================

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

//==============================================================================
//==============================================================================

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
B    make_test(const PRConst       ,  false   );
    make_test(const PRMutable     ,  false   );
    make_test(const PRContainer   ,  false   );
                                       
    make_test(const PRConst&      ,  false   );
    make_test(const PRMutable&    ,  false   );
    make_test(const PRContainer&  ,  false   );
                                     
    make_rval(const PRConst&&     ,  false   );
    make_rval(const PRMutable&&   ,  false   );
    make_rval(const PRContainer&& ,  false   );
}

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

//==============================================================================
//==============================================================================

//#endif // !#ifdef dHAS_CPP11
#endif // !TEST_TOOLS_SFINAE_BEGIN
