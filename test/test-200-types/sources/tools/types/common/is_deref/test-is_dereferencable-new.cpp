// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-20d][22:41:59] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_DEREFERENCABLE

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_dereferencable
#define dTEST_TAG new

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

    #define make_test(type, expected)       \
        static_assert(                      \
            dexpression(type, expected),    \
            "is_dereferencable<" #type ">"  \
            "must be '" #expected "'"       \
        )
  
}//namespace

//==============================================================================
//==============================================================================
namespace
{
    using shared = ::std::shared_ptr<int>;
    using iter   = ::std::string::iterator;

    struct foo
    {
        int operator*() const { return 0; }
    };

    struct bar
    {
        int operator*() { return 0; }
    };

    struct baz{};

    //       |   type         | expected |
    make_test(bool            ,   false  );
    make_test(::std::nullptr_t,   false  );
    make_test(::std::string   ,   false  );
    make_test(char[2]         ,   true   );
    make_test(char*           ,   true   );
    make_test(iter            ,   true   );
    make_test(shared          ,   true   );
    make_test(shared&         ,   true   );
    make_test(foo             ,   true   );
    make_test(foo&            ,   true   );
    make_test(const foo       ,   true   );
    make_test(const foo&      ,   true   );
    make_test(bar             ,   true   );
    make_test(bar&            ,   true   );
    make_test(const bar       ,   false  );
    make_test(const bar&      ,   false  );
    make_test(baz             ,   false  );
    make_test(baz&            ,   false  );
    make_test(const baz       ,   false  );
    make_test(const baz&      ,   false  );

}//namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000){}

//==============================================================================
//==============================================================================


#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_IS_DEREFERENCABLE

