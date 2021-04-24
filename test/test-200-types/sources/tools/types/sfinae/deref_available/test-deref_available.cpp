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

    struct maket {};

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

  
} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    //       |   type             |      signature                 | expected |
    make_test(maket               , void(maket::*)()               ,  false   );
    make_test(one_mutable         , void(one_mutable::*)()         ,  true    );
    make_test(one_const           , void(one_const::*)()           ,  false   );
    make_test(two                 , void(two::*)()                 ,  true    );
    make_test(one_private_mutable , void(one_private_mutable::*)() ,  false   );
    make_test(one_private_const   , void(one_private_const::*)()   ,  false   );
    //make_test(two_private         , void(two_private::*)()         ,  false   );
}

TEST_COMPONENT(001)
{
    //       |   type             |      signature                       | expected |
    make_test(maket               , void(maket::*)()               const ,  false   );
    make_test(one_mutable         , void(one_mutable::*)()         const ,  false   );
    make_test(one_const           , void(one_const::*)()           const ,  true    );
    make_test(two                 , void(two::*)()                 const ,  true    );
    make_test(one_private_mutable , void(one_private_mutable::*)() const ,  false   );
    make_test(one_private_const   , void(one_private_const::*)()   const ,  false   );
    //make_test(two_private         , void(two_private::*)()         const ,  false   );
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_DEREF_AVAILABLE

