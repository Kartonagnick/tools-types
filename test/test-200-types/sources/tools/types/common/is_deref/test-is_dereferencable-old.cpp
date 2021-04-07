// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-20d][22:41:59] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_DEREFERENCABLE

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_dereferencable
#define dTEST_TAG old

#include <tools/types/common.hpp>

#include <string>
#include <memory>

namespace me = ::tools;
//==============================================================================
//=== macro ====================================================================
namespace
{
    #define dexpression(type, expected) \
        me::is_dereferencable<type>::value == expected

    #ifdef dHAS_STATIC_ASSERT
        #define make_test(type, expected)       \
            static_assert(                      \
                dexpression(type, expected),    \
                "is_dereferencable<" #type "> " \
                "must be '" #expected "'"       \
            )
    #else
        #define make_test(type, expected)       \
            dSTATIC_ASSERT(                     \
                ERROR_INTERNAL,                 \
                dexpression(type, expected)     \
            )
    #endif
  
}//namespace

//==============================================================================
//==============================================================================
namespace
{
    #ifdef dHAS_NULLPTR
    typedef ::std::shared_ptr<int> 
        shared;
    #endif

    typedef ::std::string::iterator  
        iter;

    struct foo
    {
        int operator*() const;
    };

    struct bar
    {
        int operator*();
    };

    struct baz{};

    struct voidd
    {
        void operator*();
        void foo();
    };
    typedef void(voidd::*method)();

    class privat
    {
        void operator*();
    public:
        privat();
    };

    class two
    {
        int operator*();
        int operator*(int);
    public:
        two();
    };

    class multi
    {
        int operator*(int);
    public:
        multi();
    };

} // namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    //       |   type         | expected |
    make_test(bool            ,   false  );

    #ifdef dHAS_NULLPTR
    make_test(std::nullptr_t  ,   false  );
    #endif

    make_test(std::string     ,   false  );
    make_test(char[2]         ,   true   );
    make_test(char*           ,   true   );
    make_test(iter            ,   true   );

    #ifdef dHAS_NULLPTR
    make_test(shared          ,   true   );
    make_test(shared&         ,   true   );
    #endif

    make_test(foo             ,   true   );
    make_test(foo&            ,   true   );
    make_test(const foo       ,   true   );
    make_test(const foo&      ,   true   );
    make_test(bar             ,   true   );
    make_test(bar&            ,   true   );

    #ifdef dHAS_VARIADIC_TEMPLATE
        // msvc2013
        make_test(const bar   ,   false  );
        make_test(const bar&  ,   false  );
    #else
        //bug: vc2008 - vc2013  ignore 'qualifier'
        make_test(const bar   ,   true   );
        make_test(const bar&  ,   true   );
    #endif

    make_test(baz             ,   false  );
    make_test(baz&            ,   false  );
    make_test(const baz       ,   false  );
    make_test(const baz&      ,   false  );
    make_test(voidd           ,   true   );
    make_test(method          ,   false  );

    #ifdef dHAS_CPP11
        make_test(two         ,   false  );
        make_test(privat      ,   false  );
        make_test(multi       ,   false  );
    #else
        //bug: vc2008 - vc2013  ignore 'private' acccess
        make_test(two         ,   true   );
        make_test(privat      ,   true   );

        #ifdef dHAS_USING_ALIAS
            // msvc2013
            make_test(multi   ,   false  );
        #else
            // bug: vc2008 - vc2012 
            // does not distinguish between multiplication and dereferencing operator
            make_test(multi   ,   true   );

        #endif
    #endif
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_IS_DEREFERENCABLE

