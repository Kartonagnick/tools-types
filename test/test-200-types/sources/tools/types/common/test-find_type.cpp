// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-19d][23:07:03] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_FIND_TYPE

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD find_type
#define dTEST_TAG tdd

#include <tools/types/common.hpp>
namespace me = ::tools;
//==============================================================================
//==============================================================================
namespace
{
    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(expect, ...)                          \
            static_assert(                                   \
                me::find_type<__VA_ARGS__>::value == expect, \
                "expected '" #expect "'"                     \
            )

        //     expect | types         |                           |
        dCHECK(true   , int           , int                       );
        dCHECK(true   , int           , bool, char, int, double   );
        dCHECK(true   , void()        , bool, char, void(), double);

        dCHECK(false  , int*          , bool, char, int, double   );
        dCHECK(false  , int*          , bool, int , int, double   );
        dCHECK(false  , int&          , bool, char, int, double   );
        dCHECK(false  , const int     , bool, char, int, double   );

        #ifdef dHAS_ABOMINABLE
            dCHECK(false  , void() , bool , char, void() const, double);
        #endif

    #endif

    #ifdef dHAS_VARIADIC

        template<class t, class... args>
        dCONSTEXPR_CPP11 bool check(t, args...) noexcept
        {
            using find_t = ::tools::find_type<t, args... >;
            return find_t::value;
        }
        static_assert( check(10, 'a', true, 10)  , "error");
        static_assert(!check(10, 'a', true, 10.5), "error");

    #else

        template<class a1, class a2, class a3, class a4>
        inline bool check(a1,a2,a3,a4) 
        {
            typedef ::tools::find_type<a1,a2,a3,a4> 
                find_t;
            return find_t::value;
        }

    #endif

} // namespace
//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    typedef me::find_type<int, int> x;
    dSTATIC_ASSERT(INTERNAL_ERROR, x::value);
}
TEST_COMPONENT(001)
{
    typedef me::find_type<int, bool, char, int, double, float, wchar_t> x;
    dSTATIC_ASSERT(INTERNAL_ERROR, x::value);
}
TEST_COMPONENT(002)
{
    typedef me::find_type<void(), bool, char, void(), double> x;
    dSTATIC_ASSERT(INTERNAL_ERROR, x::value);
}
TEST_COMPONENT(003)
{
    typedef me::find_type<int*, bool, char, int, double> x;
    dSTATIC_ASSERT(INTERNAL_ERROR, !x::value);
}
TEST_COMPONENT(004)
{
    typedef me::find_type<int*, bool, int , int, double> x;
    dSTATIC_ASSERT(INTERNAL_ERROR, !x::value);
}
TEST_COMPONENT(005)
{
    typedef me::find_type<int&, bool, char, int, double> x;
    dSTATIC_ASSERT(INTERNAL_ERROR, !x::value);
}
TEST_COMPONENT(006)
{
    typedef me::find_type<const int, bool, char, int, double> x;
    dSTATIC_ASSERT(INTERNAL_ERROR, !x::value);
}

#ifdef dHAS_ABOMINABLE
TEST_COMPONENT(007)
{
    typedef me::find_type<void(), bool , char, void() const, double> x;
    dSTATIC_ASSERT(INTERNAL_ERROR, !x::value);
}
#endif // !dHAS_ABOMINABLE

//==============================================================================
//==============================================================================

TEST_COMPONENT(008)
{
    const bool success = check(10, 'a', true, 10);
    ASSERT_TRUE(success);
}
TEST_COMPONENT(009)
{
    const bool success = check(10, 'a', true, 10.5);
    ASSERT_TRUE(!success);
}

#endif // !TEST_TOOLS_FIND_TYPE

