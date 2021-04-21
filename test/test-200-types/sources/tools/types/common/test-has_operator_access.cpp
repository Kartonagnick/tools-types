// [2021y-04m-13d][21:15:33] Idrisov Denis R.
// [2021y-04m-21d][13:18:05] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_HAS_OPERATOR_ACCESS

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD has_operator_access
#define dTEST_TAG tdd

#include <tools/types/sfinae/has_operator_access.hpp>

namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #define dEXPRESSION(a,v) \
        me::has_operator_access<a>::value == v

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                            \
            static_assert(                                        \
                dEXPRESSION(type, expected),                      \
                "tools::has_operator_access<" # type ">::value "  \
                "must be '" #expected "'"                         \
            )
    #else
        #define dCHECK(type, expected)      \
        dSTATIC_ASSERT(                     \
            ERROR_INTERNAL,                 \
            dEXPRESSION(type, expected)     \
        )
    #endif

    struct foo { bool& operator[](int); };

    struct bar 
    {
        bool& operator[](int); 
        const bool& operator[](int) const; 
    };

    struct dummy{};

} // namespace


#if 0
// bug in msvc2019
// fatal error C1001: Внутренняя ошибка компилятора.
// 1>(Файл компилятора "D:\a01\_work\6\s\src\vctools\Compiler\CxxFE\sl\p1\cxx\RDParser.cpp", строка 13284.)

    #ifdef _MSC_VER
    template<class t>
    struct Has_operator_access
    {
        __if_exists( t::operator[] )
            { enum { value = true }; }

        __if_not_exists( t::operator[] ) 
            { enum { value = false }; }
    };
    #endif
#endif

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int[1]      , true );
    dCHECK(foo         , true );
    dCHECK(const foo   , true );
    dCHECK(const foo&  , true );
    dCHECK(foo&        , true );
    dCHECK(int(&)[1]   , true );

    #ifdef dHAS_ARRAY_EMPTY_SIZE
    dCHECK(int(&)[]    , true );
    dCHECK(int[]       , true );
    #endif

    dCHECK(int         , false);
    dCHECK(dummy       , false);
}
TEST_COMPONENT(001)
{
    dCHECK(bar       , true);
    dCHECK(const bar , true);
    dCHECK(bar&      , true);
    dCHECK(const bar&, true);
}

#ifdef dHAS_VARIADIC_TEMPLATE
TEST_COMPONENT(002)
{
    dSTATIC_CHECK(
        ERROR_INTERNAL,
        me::has_operator_access<bar, int>::value
    );
    dSTATIC_CHECK(
        ERROR_INTERNAL,
        me::has_operator_access<const bar, int>::value
    );
    dSTATIC_CHECK(
        ERROR_INTERNAL,
        me::has_operator_access<bar&, int>::value
    );
    dSTATIC_CHECK(
        ERROR_INTERNAL,
        me::has_operator_access<const bar&, int>::value
    );

    dSTATIC_CHECK(
        ERROR_INTERNAL,
        me::has_operator_access<const bar, float>::value
    );
    dSTATIC_CHECK(
        ERROR_INTERNAL,
        !me::has_operator_access<const bar, foo>::value
    );
}
#endif

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_IS_LAMBDA

