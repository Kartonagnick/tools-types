// [2020y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-04m-08d][03:09:44] Idrisov Denis R.
#include <mygtest/modern.hpp>


#ifdef TEST_TOOLS_IS_VOLATILE_DATA

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_volatile_data
#define dTEST_TAG tdd

#include <tools/types/common.hpp>
#include <string>
#include <memory>

//==============================================================================
//=== make_test ================================================================
namespace
{
    #define dexpression(type, expected) \
        ::tools::is_volatile_data<type>::value == expected

    #define make_test(type, expected)                    \
        static_assert(                                   \
            dexpression(type, expected),                 \
            "tools::is_volatile_data<" #type ">::value " \
            "must be '" #expected "'"                    \
        )

    ::std::string val;

    using shared
        = ::std::shared_ptr<int>;

    // --- ignore top-level const
    struct bar    { int operator*();            };
    struct sample { int* volatile& operator*(); };
    struct foo    { volatile int& operator*();  };

    bar b;

    using t = decltype(*b);

    //       |   type                | expected |
    make_test(int volatile           ,   true   );
    make_test(volatile int           ,   true   );
    make_test(volatile int&          ,   true   );
    make_test(volatile int*          ,   true   );
    make_test(volatile int* volatile ,   true   );
    make_test(volatile int*&         ,   true   );
    make_test(volatile int[1]        ,   true   );
    make_test(volatile int(&)[1]     ,   true   );
    make_test(volatile int(*)[1]     ,   true   );
    make_test(int* volatile          ,   false  );

    make_test(decltype(val.cbegin()) ,   false  );
    make_test(decltype(val.begin())  ,   false  );

    make_test(volatile shared        ,   true   );
    make_test(const shared           ,   false  );
    make_test(shared                 ,   false  );

    make_test(volatile sample        ,   true   );
    make_test(sample                 ,   true   );

    make_test(foo                    ,   true   );
    make_test(volatile foo           ,   true   );

    make_test(bar                    ,   false  );
    make_test(decltype(*b)           ,   false  );

    template<class s, dfor_volatile_data(s)>
    constexpr bool new_consept(s&&) noexcept
        { return true; }

    template<class s, dfor_not_volatile_data(s)>
    constexpr bool new_consept(s&&) noexcept
        { return false; }

    template<class s>
    constexpr dif_volatile_data(s, bool)
    old_consept(s&&) noexcept 
        { return true; }

    template<class s>
    constexpr dif_not_volatile_data(s, bool)
    old_consept(s&&) noexcept
        { return false; }

    char arr[] = "";
    volatile char carr[] = "";

    static_assert(!new_consept(arr), "bug");
    static_assert(new_consept(carr), "bug");

    static_assert(!old_consept(arr), "bug");
    static_assert(old_consept(carr), "bug");

} // namespace
//==============================================================================

namespace
{
    struct some  { int operator*(); };
    struct csome { int* volatile& operator*(); };
    struct bsome { volatile int*  operator*(); };
    struct dsome { volatile int&  operator*(); };
    struct fsome { volatile some  operator*(); };
    struct gsome { volatile some& operator*(); };
    struct dummy;

} // namespace

TEST_COMPONENT(001)
{
    //       |   type        | expected |
    make_test(volatile char* ,  true    );
    make_test(char* volatile ,  false   );
    make_test(volatile some  ,  true    );  // <--- can not dereferencable, but it is const
    make_test(csome          ,  true    );
    make_test(bsome          ,  false   );
    make_test(dsome          ,  true    );
    make_test(fsome          ,  true    );
    make_test(gsome          ,  true    );
    make_test(dummy          ,  false   );
    make_test(volatile dummy ,  true    );
    make_test(volatile int   ,  true    );
}

//==============================================================================
//==============================================================================
#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_IS_CONST_DATA

