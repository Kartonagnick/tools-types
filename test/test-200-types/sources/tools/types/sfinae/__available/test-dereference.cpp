// [2021y-04m-28d][00:34:05] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_SFINAE_DEREFERENCE
#define dTEST_COMPONENT tools, types, sfinae, available
#define dTEST_METHOD dereference
#define dTEST_TAG new

#include <tools/types/sfinae.hpp>
namespace me = ::tools::sfinae::available;
//==============================================================================
//=== macro ====================================================================
namespace
{
    #define dexpression(type, expected) \
        me::dereference<type>::value == expected

    #ifdef dHAS_TYPE_TRAITS
        #define make_test(type, expected)                           \
            static_assert(                                          \
                dexpression(type, expected),                        \
                "tools::sfinae::available::dereference<" #type "> " \
                "must be '" #expected "'"                           \
            )
    #else
        #define make_test(type, expected)                       \
            dSTATIC_CHECK(                                      \
                ERROR_MUST_BE_##expected,                       \
                dexpression(type, expected)                     \
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
//----------------------------------

    struct rec_mutable 
    {
        rec_mutable operator*();
    };
    struct rec_const 
    {
        rec_const operator*() const;
    };
    struct rec
    {
        rec operator*();
        rec operator*(int);
        rec operator*() const;
        rec operator*(int) const;
    };
    struct der_rec: public rec {};

    struct der_rec_private: private rec {};

} // namespace

//==============================================================================
//==============================================================================
#if 0
TEST_COMPONENT(000)
{
    //       |   type               | expected |
    make_test(maket                 ,  false   );
    make_test(dummy                 ,  false   );
    make_test(one_mutable           ,  true    );
    make_test(one_const             ,  true    );
    make_test(two                   ,  true    );
//---------                         
    make_test(one_private_mutable   ,  false   );
    make_test(one_private_const     ,  false   );
    make_test(two_private           ,  false   );
//---------                         
    make_test(der_mutable           ,  true    );
    make_test(der_const             ,  true    );
    make_test(der_two               ,  true    );
//---------                         
    make_test(der_private_mutable   ,  false   );
    make_test(der_private_const     ,  false   );
    make_test(der_two_private       ,  false   );
//---------                         
    make_test(overload_mutable      ,  true    );
    make_test(overload_const        ,  true    );
    make_test(overload              ,  true    );
//---------                         
    make_test(overload_priv_mut     ,  false   );
    make_test(overload_priv_const   ,  false   );
    make_test(overload_private      ,  false   );
//---------                         
    make_test(der_overload_mutable  ,  true    );
    make_test(der_overload_const    ,  true    );
    make_test(der_overload_two      ,  true    );
//---------
    make_test(der_priv_over_mutable ,  false   );
    make_test(der_priv_over_const   ,  false   );
    make_test(der_over_private      ,  false   );
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
    make_test(one_private_mutable  ,  false   );
    make_test(one_private_const    ,  false   );
    make_test(two_private          ,  false   );
//---------                        
    make_test(der_mutable          ,  true    );
    make_test(der_const            ,  true    );
    make_test(der_two              ,  true    );
//---------                        
    make_test(der_private_mutable  ,  false   );
    make_test(der_private_const    ,  false   );
    make_test(der_two_private      ,  false   );
//---------                        
    make_test(overload_mutable     ,  true    );
    make_test(overload_const       ,  true    );
    make_test(overload             ,  true    );
//---------                        
    make_test(overload_priv_mut    ,  false   );
    make_test(overload_priv_const  ,  false   );
    make_test(overload_private     ,  false   );
//---------
    make_test(der_overload_mutable ,  true    );
    make_test(der_overload_const   ,  true    );
    make_test(der_overload_two     ,  true    );
//---------
    make_test(der_priv_over_mutable,  false   );
    make_test(der_priv_over_const  ,  false   );
    make_test(der_over_private     ,  false   );
}

TEST_COMPONENT(002)
{
    //       |   type         | expected |
    make_test(rec_mutable     ,  true    );
    make_test(rec_const       ,  true    );
    make_test(rec             ,  true    );
    make_test(der_rec         ,  true    );
    make_test(der_rec_private ,  false   );
}

TEST_COMPONENT(003)
{
    make_test(rec_mutable     ,  true    );
    make_test(rec_const       ,  true    );
    make_test(rec             ,  true    );
    make_test(der_rec         ,  true    );
    make_test(der_rec_private ,  false   );
}
#endif
//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_SFINAE_DEREFERENCE
