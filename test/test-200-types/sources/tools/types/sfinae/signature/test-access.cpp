// [2021y-04m-27d][22:26:21] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_ACCESS
#define dTEST_COMPONENT tools, types, sfinae, signature
#define dTEST_METHOD access
#define dTEST_TAG new

#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::signature;
//==============================================================================
//=== macro ====================================================================
namespace
{
    #define dexpression(type, sig, expected) \
        me::access<type, sig>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, sig, expected)                           \
            static_assert(                                               \
                dexpression(type, sig, expected),                        \
                "tools::sfinae::signature::access<" #type ", " #sig "> " \
                "must be '" #expected "'"                                \
            )
    #else
        #define make_test(type, sig, expected)   \
            dSTATIC_CHECK(                       \
                ERROR_MUST_BE_##expected,        \
                dexpression(type, sig, expected) \
            )
    #endif

//----------------------------------
    struct maket;

    struct dummy {};

    struct one_mutable 
    {
        void operator[](size_t) {}
    };
    struct one_const
    {
        void operator[](size_t) const {}
    };

    struct two
    {
        void operator[](size_t) {}
        void operator[](size_t) const {}
    };

    class one_private_mutable 
    {
        void operator[](size_t) {}
    public:
        one_private_mutable() {}
    };

    class one_private_const
    {
        void operator[](size_t) const {}
    public:
        one_private_const() {}
    };

    class two_private
    {
        void operator[](size_t) {}
        void operator[](size_t) const {}
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
        void operator[](size_t) {}
        void operator[](int) {}
    };
    struct overload_const 
    {
        void operator[](size_t) const    {}
        void operator[](int) const {}
    };
    struct overload
    {
        void operator[](size_t) {}
        void operator[](int) {}
        void operator[](size_t) const {}
        void operator[](int) const {}
    };

    class overload_priv_mut
    {
        void operator[](size_t) {}
        void operator[](int) {}
    public:
        overload_priv_mut() {}
    };

    class overload_priv_const
    {
        void operator[](size_t) const {}
        void operator[](int) const {}
    public:
        overload_priv_const() {}
    };

    class overload_private
    {
        void operator[](size_t) {}
        void operator[](size_t) const {}

        void operator[](int) {}
        void operator[](int) const {}

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
//----------------------------------

    struct rec_mutable 
    {
        rec_mutable operator[](size_t);
    };
    struct rec_const 
    {
        rec_const operator[](size_t) const;
    };
    struct rec
    {
        rec operator[](size_t);
        rec operator[](int);
        rec operator[](size_t) const;
        rec operator[](int) const;
    };
    struct der_rec: public rec {};

    struct der_rec_private: private rec {};

} // namespace

    //static_cast<void(cl::*)(size_t)>(&cl::operator[])

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    //       |   type               |      signature                         | expected |
    make_test(maket                 , void(maket::*)(size_t)                 ,  false   );
    make_test(dummy                 , void(dummy::*)(size_t)                 ,  false   );
    make_test(one_mutable           , void(one_mutable::*)(size_t)           ,  true    );
    make_test(one_const             , void(one_const::*)(size_t)             ,  false   );
    make_test(two                   , void(two::*)(size_t)                   ,  true    );
//---------                                                                  
    make_test(one_private_mutable   , void(one_private_mutable::*)(size_t)   ,  false   );
    make_test(one_private_const     , void(one_private_const::*)(size_t)     ,  false   );
    make_test(two_private           , void(two_private::*)(size_t)           ,  false   );
//---------                                                                  
    make_test(der_mutable           , void(der_mutable::*)(size_t)           ,  true    );
    make_test(der_const             , void(der_const::*)(size_t)             ,  false   );
    make_test(der_two               , void(der_two::*)(size_t)               ,  true    );
//---------                                                                  
    make_test(der_private_mutable   , void(der_private_mutable::*)(size_t)   ,  false   );
    make_test(der_private_const     , void(der_private_const::*)(size_t)     ,  false   );
    make_test(der_two_private       , void(der_two_private::*)(size_t)       ,  false   );
//---------                                                                  
    make_test(overload_mutable      , void(overload_mutable::*)(size_t)      ,  true    );
    make_test(overload_const        , void(overload_const::*)(size_t)        ,  false   );
    make_test(overload              , void(overload::*)(size_t)              ,  true    );
//---------                                                                  
    make_test(overload_priv_mut     , void(overload_priv_mut::*)(size_t)     ,  false   );
    make_test(overload_priv_const   , void(overload_priv_const::*)(size_t)   ,  false   );
    make_test(overload_private      , void(overload_private::*)(size_t)      ,  false   );
//---------                                                                  
    make_test(der_overload_mutable  , void(der_overload_mutable::*)(size_t)  ,  true    );
    make_test(der_overload_const    , void(der_overload_const::*)(size_t)    ,  false   );
    make_test(der_overload_two      , void(der_overload_two::*)(size_t)      ,  true    );
//---------
    make_test(der_priv_over_mutable , void(der_priv_over_mutable::*)(size_t) ,  false   );
    make_test(der_priv_over_const   , void(der_priv_over_const::*)(size_t)   ,  false   );
    make_test(der_over_private      , void(der_over_private::*)(size_t)      ,  false   );
}

TEST_COMPONENT(001)
{
    //       |   type               |      signature                               | expected |
    make_test(maket                 , void(maket::*)(size_t)                 const ,  false   );
    make_test(dummy                 , void(dummy::*)(size_t)                 const ,  false   );
    make_test(one_mutable           , void(one_mutable::*)(size_t)           const ,  false   );
    make_test(one_const             , void(one_const::*)(size_t)             const ,  true    );
    make_test(two                   , void(two::*)(size_t)                   const ,  true    );
//---------                                                                  
    make_test(one_private_mutable   , void(one_private_mutable::*)(size_t)   const ,  false   );
    make_test(one_private_const     , void(one_private_const::*)(size_t)     const ,  false   );
    make_test(two_private           , void(two_private::*)(size_t)           const ,  false   );
//---------                                                                  
    make_test(der_mutable           , void(der_mutable::*)(size_t)           const ,  false   );
    make_test(der_const             , void(der_const::*)(size_t)             const ,  true    );
    make_test(der_two               , void(der_two::*)(size_t)               const ,  true    );
//---------                                                                  
    make_test(der_private_mutable   , void(der_private_mutable::*)(size_t)   const ,  false   );
    make_test(der_private_const     , void(der_private_const::*)(size_t)     const ,  false   );
    make_test(der_two_private       , void(der_two_private::*)(size_t)       const ,  false   );
//---------                                                                  
    make_test(overload_mutable      , void(overload_mutable::*)(size_t)      const ,  false   );
    make_test(overload_const        , void(overload_const::*)(size_t)        const ,  true    );
    make_test(overload              , void(overload::*)(size_t)              const ,  true    );
//---------                                                                  
    make_test(overload_priv_mut     , void(overload_priv_mut::*)(size_t)     const ,  false   );
    make_test(overload_priv_const   , void(overload_priv_const::*)(size_t)   const ,  false   );
    make_test(overload_private      , void(overload_private::*)(size_t)      const ,  false   );
//---------                                                                  
    make_test(der_overload_mutable  , void(der_overload_mutable::*)(size_t)  const ,  false   );
    make_test(der_overload_const    , void(der_overload_const::*)(size_t)    const ,  true    );
    make_test(der_overload_two      , void(der_overload_two::*)(size_t)      const ,  true    );
//---------
    make_test(der_priv_over_mutable , void(der_priv_over_mutable::*)(size_t) const ,  false   );
    make_test(der_priv_over_const   , void(der_priv_over_const::*)(size_t)   const ,  false   );
    make_test(der_over_private      , void(der_over_private::*)(size_t)      const ,  false   );
}

TEST_COMPONENT(002)
{
    //       |   type         |      signature                              | expected |
    make_test(rec_mutable     , rec_mutable(rec_mutable::*)(size_t)         ,  true    );
    make_test(rec_const       , rec_const(rec_const::*)(size_t)             ,  false   );
    make_test(rec             , rec(rec::*)(size_t)                         ,  true    );
    make_test(der_rec         , rec(der_rec::*)(size_t)                     ,  true    );
    make_test(der_rec_private , der_rec_private(der_rec_private::*)(size_t) ,  false   );
}

TEST_COMPONENT(003)
{
    make_test(rec_mutable     , rec_mutable(rec_mutable::*)(size_t)         const,  false   );
    make_test(rec_const       , rec_const(rec_const::*)(size_t)             const,  true    );
    make_test(rec             , rec(rec::*)(size_t)                         const,  true    );
    make_test(der_rec         , rec(der_rec::*)(size_t)                     const,  true    );
    make_test(der_rec_private , der_rec_private(der_rec_private::*)(size_t) const,  false   );
}

#if 0

// bug msvc2017

struct foo 
{
    void operator[](size_t) {}
};


template <class t>
struct help
{
    using type = decltype(&t::operator[]);
};

template <class t>
using method = typename help<t>::type;

using x = method<foo>;
#endif

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_SFINAE_ACCESS
