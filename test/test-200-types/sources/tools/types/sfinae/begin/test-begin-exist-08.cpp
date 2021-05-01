// [2021y-04m-29d][12:21:22] Idrisov Denis R.
#ifdef _MSC_VER
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_BEGIN
#define dTEST_COMPONENT tools, types, sfinae, exist
#define dTEST_METHOD begin
#define dTEST_TAG new

#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::exist;
//==============================================================================
//==============================================================================
namespace
{
    #define dexpression(type, expected) \
        me::begin<type>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, expected)                 \
            static_assert(                                \
                dexpression(type, expected),              \
                "tools::sfinae::exist::begin<" #type "> " \
                "must be '" #expected "'"                 \
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
    make_test(const Mutable     ,  true    );
    make_test(const Container   ,  true    );

    make_test(const Const&      ,  true    );
    make_test(const Mutable&    ,  true    );
    make_test(const Container&  ,  true    );

    make_rval(const Const&&     ,  true    );
    make_rval(const Mutable&&   ,  true    );
    make_rval(const Container&& ,  true    );
}

// --- non-const derived
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

// --- const derived
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

// --- non-const private
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

// --- const private
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

// --- non-const derived private 
TEST_COMPONENT(007)
{
    //       |   type      | expected |
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

// --- const derived private 
TEST_COMPONENT(008)
{
    //       |   type            | expected |
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

//==============================================================================
//==============================================================================
#endif // _MSC_VER
#endif // TEST_TOOLS_SFINAE_BEGIN