// [2021y-04m-24d][22:40:39] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_DEREF_AVAILABLE

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD deref_available
#define dTEST_TAG old

#include <tools/types/sfinae.hpp>

#include <string>
#include <memory>

namespace me = ::tools;
//==============================================================================
//=== macro ====================================================================
namespace
{
    #define dexpression(type, sig, expected) \
        me::deref_available<type, sig>::value == expected

    #ifdef dHAS_STATIC_ASSERT
        #define make_test(type, sig, expected)                 \
            static_assert(                                     \
                dexpression(type, sig, expected),              \
                "tools::deref_available<" #type ", " #sig "> " \
                "must be '" #expected "'"                      \
            )
    #else
        #define make_test(type, sig, expected)   \
            dSTATIC_ASSERT(ERROR_INTERNAL,       \
                dexpression(type, sig, expected) \
            )
    #endif

//----------------------------------
    struct maket;

    struct dummy {};

    struct one_mutable 
    {
        void operator*() {}
    };
    struct one_const
    {
        void operator*() const {}
    };

    struct two
    {
        void operator*() {}
        void operator*() const {}
    };

    class one_private_mutable 
    {
        void operator*() {}
    public:
        one_private_mutable() {}
    };

    class one_private_const
    {
        void operator*() const {}
    public:
        one_private_const() {}
    };

    class two_private
    {
        void operator*() {}
        void operator*() const {}
    public:
        two_private() {}
    };

//----------------------------------
    class der_mutable : public one_mutable {};
    class der_const   : public one_const   {};
    class der_two     : public two         {};

    class der_private_mutable : public one_private_mutable {};
    class der_private_const   : public one_private_const   {};
    class der_two_private     : public two_private         {};

//----------------------------------
    struct overload_mutable 
    {
        void operator*() {}
        void operator*(int) {}
    };
    struct overload_const 
    {
        void operator*() const    {}
        void operator*(int) const {}
    };
    struct overload
    {
        void operator*() {}
        void operator*(int) {}
        void operator*() const {}
        void operator*(int) const {}
    };

    class overload_priv_mut
    {
        void operator*() {}
        void operator*(int) {}
    public:
        overload_priv_mut() {}
    };

    class overload_priv_const
    {
        void operator*() const {}
        void operator*(int) const {}
    public:
        overload_priv_const() {}
    };

    class overload_private
    {
        void operator*() {}
        void operator*() const {}

        void operator*(int) {}
        void operator*(int) const {}

    public:
        overload_private() {}
    };

//----------------------------------
    class der_overload_mutable : public overload_mutable {};
    class der_overload_const   : public overload_const   {};
    class der_overload_two     : public overload         {};

    class der_priv_over_mutable : public overload_priv_mut   {};
    class der_priv_over_const   : public overload_priv_const {};
    class der_over_private      : public overload_private    {};

} // namespace

//==============================================================================
//==============================================================================
#ifdef dHAS_CPP11
TEST_COMPONENT(000)
{
    //       |   type              |      signature                  | expected |
    make_test(maket                , void(maket::*)()                ,  false   );
    make_test(dummy                , void(dummy::*)()                ,  false   );
    make_test(one_mutable          , void(one_mutable::*)()          ,  true    );
    make_test(one_const            , void(one_const::*)()            ,  false   );
    make_test(two                  , void(two::*)()                  ,  true    );
//---------                                                          
    make_test(one_private_mutable  , void(one_private_mutable::*)()  ,  false   );
    make_test(one_private_const    , void(one_private_const::*)()    ,  false   );
    make_test(two_private          , void(two_private::*)()          ,  false   );
//---------                                                          
    make_test(der_mutable          , void(der_mutable::*)()          ,  true    );
    make_test(der_const            , void(der_const::*)()            ,  false   );
    make_test(der_two              , void(der_two::*)()              ,  true    );
//---------                                                          
    make_test(der_private_mutable  , void(der_private_mutable::*)()  ,  false   );
    make_test(der_private_const    , void(der_private_const::*)()    ,  false   );
    make_test(der_two_private      , void(der_two_private::*)()      ,  false   );
//---------                                                          
    make_test(overload_mutable     , void(overload_mutable::*)()     ,  true    );
    make_test(overload_const       , void(overload_const::*)()       ,  false   );
    make_test(overload             , void(overload::*)()             ,  true    );
//---------                                                          
    make_test(overload_priv_mut    , void(overload_priv_mut::*)()    ,  false   );
    make_test(overload_priv_const  , void(overload_priv_const::*)()  ,  false   );
    make_test(overload_private     , void(overload_private::*)()     ,  false   );
//---------
    make_test(der_overload_mutable , void(der_overload_mutable::*)() ,  true    );
    make_test(der_overload_const   , void(der_overload_const::*)()   ,  false   );
    make_test(der_overload_two     , void(der_overload_two::*)()     ,  true    );
//---------
    make_test(der_priv_over_mutable , void(der_priv_over_mutable::*)() ,  false );
    make_test(der_priv_over_const   , void(der_priv_over_const::*)()   ,  false );
    make_test(der_over_private      , void(der_over_private::*)()      ,  false );
}

TEST_COMPONENT(001)
{
    //       |   type              |      signature                        | expected |
    make_test(maket                , void(maket::*)()                const ,  false   );
    make_test(dummy                , void(dummy::*)()                const ,  false   );
    make_test(one_mutable          , void(one_mutable::*)()          const ,  false   );
    make_test(one_const            , void(one_const::*)()            const ,  true    );
    make_test(two                  , void(two::*)()                  const ,  true    );
//---------                                                         
    make_test(one_private_mutable  , void(one_private_mutable::*)()  const ,  false   );
    make_test(one_private_const    , void(one_private_const::*)()    const ,  false   );
    make_test(two_private          , void(two_private::*)()          const ,  false   );
//---------                                                         
    make_test(der_mutable          , void(der_mutable::*)()          const ,  false   );
    make_test(der_const            , void(der_const::*)()            const ,  true    );
    make_test(der_two              , void(der_two::*)()              const ,  true    );
//---------                                                         
    make_test(der_private_mutable  , void(der_private_mutable::*)()  const ,  false   );
    make_test(der_private_const    , void(der_private_const::*)()    const ,  false   );
    make_test(der_two_private      , void(der_two_private::*)()      const ,  false   );
//---------                                                         
    make_test(overload_mutable     , void(overload_mutable::*)()     const ,  false   );
    make_test(overload_const       , void(overload_const::*)()       const ,  true    );
    make_test(overload             , void(overload::*)()             const ,  true    );
//---------                                                         
    make_test(overload_priv_mut    , void(overload_priv_mut::*)()    const ,  false   );
    make_test(overload_priv_const  , void(overload_priv_const::*)()  const ,  false   );
    make_test(overload_private     , void(overload_private::*)()     const ,  false   );
//---------
    make_test(der_overload_mutable , void(der_overload_mutable::*)() const ,  false   );
    make_test(der_overload_const   , void(der_overload_const::*)()   const ,  true    );
    make_test(der_overload_two     , void(der_overload_two::*)()     const ,  true    );
//---------
    make_test(der_priv_over_mutable , void(der_priv_over_mutable::*)() const ,  false );
    make_test(der_priv_over_const   , void(der_priv_over_const::*)()   const ,  false );
    make_test(der_over_private      , void(der_over_private::*)()      const ,  false );
}
#else

TEST_COMPONENT(000)
{
    //       |   type              |      signature                  | expected |
    // make_test(maket                , void(maket::*)()                ,  false   );
    make_test(dummy                , void(dummy::*)()                ,  false   );
    make_test(one_mutable          , void(one_mutable::*)()          ,  true    );
    make_test(one_const            , void(one_const::*)()            ,  false   );
    make_test(two                  , void(two::*)()                  ,  true    );
//---------                                                          
    // make_test(one_private_mutable  , void(one_private_mutable::*)()  ,  false   );
    // make_test(one_private_const    , void(one_private_const::*)()    ,  false   );
    // make_test(two_private          , void(two_private::*)()          ,  false   );
//---------                                                          
    // make_test(der_mutable          , void(der_mutable::*)()          ,  true    );
    // make_test(der_const            , void(der_const::*)()            ,  false   );
    // make_test(der_two              , void(der_two::*)()              ,  true    );
//---------                                                          
    // make_test(der_private_mutable  , void(der_private_mutable::*)()  ,  false   );
    // make_test(der_private_const    , void(der_private_const::*)()    ,  false   );
    // make_test(der_two_private      , void(der_two_private::*)()      ,  false   );
//---------                                                          
    make_test(overload_mutable     , void(overload_mutable::*)()     ,  true    );
    make_test(overload_const       , void(overload_const::*)()       ,  false   );
    make_test(overload             , void(overload::*)()             ,  true    );
//---------                                                          
    // make_test(overload_priv_mut    , void(overload_priv_mut::*)()    ,  false   );
    // make_test(overload_priv_const  , void(overload_priv_const::*)()  ,  false   );
    // make_test(overload_private     , void(overload_private::*)()     ,  false   );
//---------
    // make_test(der_overload_mutable , void(der_overload_mutable::*)() ,  true    );
    // make_test(der_overload_const   , void(der_overload_const::*)()   ,  false   );
    // make_test(der_overload_two     , void(der_overload_two::*)()     ,  true    );
//---------
    // make_test(der_priv_over_mutable , void(der_priv_over_mutable::*)() ,  false );
    // make_test(der_priv_over_const   , void(der_priv_over_const::*)()   ,  false );
    // make_test(der_over_private      , void(der_over_private::*)()      ,  false );
}

TEST_COMPONENT(001)
{
    //       |   type              |      signature                        | expected |
    // make_test(maket                , void(maket::*)()                const ,  false   );
    make_test(dummy                , void(dummy::*)()                const ,  false   );
    make_test(one_mutable          , void(one_mutable::*)()          const ,  false   );
    make_test(one_const            , void(one_const::*)()            const ,  true    );
    make_test(two                  , void(two::*)()                  const ,  true    );
//---------                                                         
    // make_test(one_private_mutable  , void(one_private_mutable::*)()  const ,  false   );
    // make_test(one_private_const    , void(one_private_const::*)()    const ,  false   );
    // make_test(two_private          , void(two_private::*)()          const ,  false   );
//---------                                                         
    // make_test(der_mutable          , void(der_mutable::*)()          const ,  false   );
    // make_test(der_const            , void(der_const::*)()            const ,  true    );
    // make_test(der_two              , void(der_two::*)()              const ,  true    );
//---------                                                         
    // make_test(der_private_mutable  , void(der_private_mutable::*)()  const ,  false   );
    // make_test(der_private_const    , void(der_private_const::*)()    const ,  false   );
    // make_test(der_two_private      , void(der_two_private::*)()      const ,  false   );
//---------                                                         
    make_test(overload_mutable     , void(overload_mutable::*)()     const ,  false   );
    make_test(overload_const       , void(overload_const::*)()       const ,  true    );
    make_test(overload             , void(overload::*)()             const ,  true    );
//---------                                                         
    // make_test(overload_priv_mut    , void(overload_priv_mut::*)()    const ,  false   );
    // make_test(overload_priv_const  , void(overload_priv_const::*)()  const ,  false   );
    // make_test(overload_private     , void(overload_private::*)()     const ,  false   );
//---------
    // make_test(der_overload_mutable , void(der_overload_mutable::*)() const ,  false   );
    // make_test(der_overload_const   , void(der_overload_const::*)()   const ,  true    );
    // make_test(der_overload_two     , void(der_overload_two::*)()     const ,  true    );
//---------
    // make_test(der_priv_over_mutable , void(der_priv_over_mutable::*)() const ,  false );
    // make_test(der_priv_over_const   , void(der_priv_over_const::*)()   const ,  false );
    // make_test(der_over_private      , void(der_over_private::*)()      const ,  false );
}
#endif

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_DEREF_AVAILABLE

