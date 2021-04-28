// [2021y-04m-27d][22:26:21] Idrisov Denis R.
#if _MSC_VER != 1928
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_ACCESS
#define dTEST_COMPONENT tools, types, sfinae, exist
#define dTEST_METHOD access
#define dTEST_TAG new

#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::exist;
//==============================================================================
//=== macro ====================================================================
namespace
{
    #define dexpression(type, expected) \
        me::access<type>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, expected)                  \
            static_assert(                                 \
                dexpression(type, expected),               \
                "tools::sfinae::exist::access<" #type "> " \
                "must be '" #expected "'"                  \
            )
    #else
        #define make_test(type, expected)   \
            dSTATIC_CHECK(                  \
                ERROR_MUST_BE_##expected,   \
                dexpression(type, expected) \
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

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    //       |   type               | expected |
    make_test(maket                 ,  false   );
    make_test(dummy                 ,  false   );
    make_test(one_mutable           ,  true    );
    make_test(one_const             ,  true    );
    make_test(two                   ,  true    );
//---------                         
    make_test(one_private_mutable   ,  true    );
    make_test(one_private_const     ,  true    );
    make_test(two_private           ,  true    );
//---------                         
    make_test(der_mutable           ,  true    );
    make_test(der_const             ,  true    );
    make_test(der_two               ,  true    );
//---------                         
    make_test(der_private_mutable   ,  true    );
    make_test(der_private_const     ,  true    );
    make_test(der_two_private       ,  true    );
//---------                         
    make_test(overload_mutable      ,  true    );
    make_test(overload_const        ,  true    );
    make_test(overload              ,  true    );
//---------                         
    make_test(overload_priv_mut     ,  true    );
    make_test(overload_priv_const   ,  true    );
    make_test(overload_private      ,  true    );
//---------                         
    make_test(der_overload_mutable  ,  true    );
    make_test(der_overload_const    ,  true    );
    make_test(der_overload_two      ,  true    );
//---------
    make_test(der_priv_over_mutable ,  true    );
    make_test(der_priv_over_const   ,  true    );
    make_test(der_over_private      ,  true    );
}

TEST_COMPONENT(001)
{
    //       |   type              | expected |
    make_test(maket                ,  false   );
    make_test(dummy                ,  false   );
    make_test(one_mutable          ,  true    );
    make_test(one_const            ,  true    );
    make_test(two                  ,  true    );
//---------                        
    make_test(one_private_mutable  ,  true    );
    make_test(one_private_const    ,  true    );
    make_test(two_private          ,  true    );
//---------                        
    make_test(der_mutable          ,  true    );
    make_test(der_const            ,  true    );
    make_test(der_two              ,  true    );
//---------                        
    make_test(der_private_mutable  ,  true    );
    make_test(der_private_const    ,  true    );
    make_test(der_two_private      ,  true    );
//---------                        
    make_test(overload_mutable     ,  true    );
    make_test(overload_const       ,  true    );
    make_test(overload             ,  true    );
//---------                        
    make_test(overload_priv_mut    ,  true    );
    make_test(overload_priv_const  ,  true    );
    make_test(overload_private     ,  true    );
//---------
    make_test(der_overload_mutable ,  true    );
    make_test(der_overload_const   ,  true    );
    make_test(der_overload_two     ,  true    );
//---------
    make_test(der_priv_over_mutable,  true    );
    make_test(der_priv_over_const  ,  true    );
    make_test(der_over_private     ,  true    );
}

TEST_COMPONENT(002)
{
    //       |   type         | expected |
    make_test(rec_mutable     ,  true    );
    make_test(rec_const       ,  true    );
    make_test(rec             ,  true    );
    make_test(der_rec         ,  true    );
    make_test(der_rec_private ,  true    );
}

TEST_COMPONENT(003)
{
    make_test(rec_mutable     ,  true    );
    make_test(rec_const       ,  true    );
    make_test(rec             ,  true    );
    make_test(der_rec         ,  true    );
    make_test(der_rec_private ,  true    );
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_SFINAE_ACCESS
#endif // #if _MSC_VER != 1928