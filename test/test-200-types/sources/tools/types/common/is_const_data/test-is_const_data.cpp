// [2020y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-04m-08d][03:09:44] Idrisov Denis R.
#include <mygtest/modern.hpp>


#ifdef TEST_TOOLS_IS_CONST_DATA

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_const_data
#define dTEST_TAG tdd

#include <tools/types/common.hpp>
#include <string>
#include <memory>

//==============================================================================
//=== make_test ================================================================
namespace
{
    #define dexpression(type, expected) \
        ::tools::is_const_data<type>::value == expected

    #define make_test(type, expected)                 \
        static_assert(                                \
            dexpression(type, expected),              \
            "tools::is_const_data<" #type ">::value " \
            "must be '" #expected "'"                 \
        )

    ::std::string val;

    using shared
        = ::std::shared_ptr<int>;

    using const_shared 
        = const ::std::shared_ptr<int>;

    // --- ignore top-level const
    struct bar    { int operator*();        };
    struct sample { int operator*();        };
    struct foo    { const int& operator*(); };

    bar b;

    using t = decltype(*b);

    //       |   type                | expected |
    make_test(int const              ,   true   );
    make_test(const int              ,   true   );
    make_test(const int&             ,   true   );
    make_test(const int*             ,   true   );
    make_test(const int* const       ,   true   );
    make_test(const int*&            ,   true   );
    make_test(const int[1]           ,   true   );
    make_test(const int(&)[1]        ,   true   );
    make_test(const int(*)[1]        ,   true   );
    make_test(int* const             ,   false  );

    make_test(decltype(val.cbegin()) ,   true   );
    make_test(decltype(val.begin())  ,   false  );
                                                
    make_test(const_shared           ,   false  );
    make_test(shared                 ,   false  );

    make_test(const sample           ,   true   );
    make_test(sample                 ,   false  );

    make_test(foo                    ,   true   );
    make_test(const foo              ,   true   );

    make_test(bar                    ,   false  );
    make_test(decltype(*b)           ,   false  );

    template<class s, dfor_const_data(s)>
    constexpr bool new_consept(s&&) noexcept { return true; }

    template<class s, dfor_not_const_data(s)>
    constexpr bool new_consept(s&&) noexcept { return false; }

    template<class s>
    constexpr dif_const_data(s, bool)
    old_consept(s&&) noexcept { return true; }

    template<class s>
    constexpr dif_not_const_data(s, bool)
    old_consept(s&&) noexcept { return false; }

    char arr[] = "";
    const char carr[] = "";

    static_assert(!new_consept(arr), "bug");
    static_assert(new_consept(carr), "bug");

    static_assert(!old_consept(arr), "bug");
    static_assert(old_consept(carr), "bug");

} // namespace
//==============================================================================

TEST_COMPONENT(000)
{
    const_shared sh(new int(1));
    int& ref = *sh; // <--- non-const
    ASSERT_TRUE(ref == 1);
}

namespace
{
    // warning C4822: local class member function does not have a body

    struct some { int operator*(); };
    struct csome { int* const& operator*(); };
    struct bsome { const int*  operator*(); };
    struct dsome { const int&  operator*(); };
    struct fsome { const some  operator*(); };
    struct dummy;

} // namespace

TEST_COMPONENT(001)
{
    //       |   type     | expected |
    make_test(const char* ,  true    );
    make_test(char* const ,  false   );
    make_test(const some  ,  true    );  // <--- can not dereferencable, but it is const
    make_test(csome       ,  false   );
    make_test(bsome       ,  true    );
    make_test(dsome       ,  true    );
    make_test(fsome       ,  true    );
    make_test(dummy       ,  false   );
    make_test(const dummy ,  true    );
    make_test(const int   ,  true    );
}

//==============================================================================
//==============================================================================
#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_IS_CONST_DATA

