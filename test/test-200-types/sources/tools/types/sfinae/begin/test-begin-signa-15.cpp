// [2021y-04m-29d][12:21:22] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_BEGIN
#define dTEST_COMPONENT tools, types, sfinae, signature
#define dTEST_METHOD begin
#define dTEST_TAG new

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::signature;
//==============================================================================
//==============================================================================
namespace
{
    #define dexpression(type, sig, expected) \
        me::begin<type, sig>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, sig, expected)                         \
            static_assert(                                             \
                dexpression(type, sig, expected),                      \
                "tools::sfinae::signature::begin<" #type "," #sig "> " \
                "must be '" #expected "'"                              \
            )
    #else
        #define make_test(type, sig, expected)   \
            dSTATIC_CHECK(                       \
                ERROR_MUST_BE_##expected,        \
                dexpression(type, sig, expected) \
            )
    #endif

    #ifdef dHAS_RVALUE_REFERENCES
        #define make_rval(type, sig, expected) \
            make_test(type, sig, expected)
    #else
        #define make_rval(type, sig, expected) \
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

} // namespace

//==============================================================================
//==============================================================================
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

// --- non-const
TEST_COMPONENT(001)
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

TEST_COMPONENT(002)
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
TEST_COMPONENT(003)
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

TEST_COMPONENT(004)
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

// --- non-const derived
TEST_COMPONENT(005)
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
TEST_COMPONENT(006)
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

// --- const derived
TEST_COMPONENT(007)
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

TEST_COMPONENT(008)
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

// --- non-const private
TEST_COMPONENT(009)
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
TEST_COMPONENT(010)
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

// --- const private
TEST_COMPONENT(011)
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
TEST_COMPONENT(012)
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

// --- non-const derived private 
TEST_COMPONENT(013)
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
TEST_COMPONENT(014)
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

// --- const derived private 
TEST_COMPONENT(015)
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
TEST_COMPONENT(016)
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

//==============================================================================
//==============================================================================
#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_SFINAE_BEGIN