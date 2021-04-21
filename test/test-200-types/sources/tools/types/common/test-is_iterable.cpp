// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-04m-12d][02:22:31] Idrisov Denis R.
// [2021y-04m-21d][13:18:27] Idrisov Denis R.

#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_ITERABLE

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD is_iterable
#define dTEST_TAG tdd

#include <tools/types/sfinae/is_iterable.hpp>
#include <iostream>
#include <vector>
#include <map>

namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    class A {};
    typedef std::vector<double>   vec_t;
    typedef std::map<double, int> map_t;
    typedef vec_t::iterator       it_v;
    typedef map_t::iterator       it_m;

    #define dEXPRESSION(a,v) \
        me::is_iterable<a>::value == v

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                     \
            static_assert(                                 \
                dEXPRESSION(type, expected),               \
                "'tools::is_iterable<" # type ">::value' " \
                "must be '" #expected "'"                  \
            )
    #else
        #define dCHECK(type, expected)      \
            dSTATIC_CHECK(                  \
                ERROR_INVALID_##expected,   \
                dEXPRESSION(type, expected) \
            )
    #endif

    struct iter
    {
        // prefix: ++it
        iter& operator++();
        iter& operator--();

        // postfix: it++
        iter operator++(int);
        iter operator--(int);

        // dereference
        int* operator*();
    };

    struct postfix
    {
        // postfix: it++
        postfix operator++(int);
        postfix operator--(int);

        // dereference
        int* operator*();
    };

    struct prefix
    {
        // prefix: ++it
        prefix& operator++();
        prefix& operator--();

        // dereference
        int* operator*();
    };

    class privat
    {
        // postfix: it++
        privat operator++(int);
        privat operator--(int);

        // prefix: ++it
        privat& operator++();
        privat& operator--();

        // dereference
        int* operator*();

    public:
        privat();
    };

} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int*    , true );
    dCHECK(it_v    , true );
    dCHECK(it_m    , true );
    dCHECK(iter    , true );
    dCHECK(postfix , true );
}
TEST_COMPONENT(001)
{
    dCHECK(int   , false);
    dCHECK(vec_t , false);
    dCHECK(map_t , false);
    dCHECK(double, false);
    dCHECK(A     , false);
    dCHECK(int   , false);
}

#ifdef dHAS_ENUM_CLASS
TEST_COMPONENT(002)
{
    // --- check qualifier
    dCHECK(const iter   , false);
    dCHECK(const postfix, false);
    dCHECK(const prefix , false);
    dCHECK(const privat , false);
}
#endif

TEST_COMPONENT(003)
{
    dCHECK(prefix  , true );

    #ifdef dHAS_CPP11
        dCHECK(privat  , false);
    #else
        // bug: msvc2013 or older
        dCHECK(privat  , true );
    #endif
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_IS_ITERABLE

