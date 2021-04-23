// [2021y-04m-12d][14:53:13] Idrisov Denis R.
// [2021y-04m-21d][13:18:55] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_ITERATOR

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD is_iterator
#define dTEST_TAG tdd

#include <tools/types/sfinae.hpp>
#include <iostream>
#include <vector>
#include <map>

namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    class A {};
    typedef std::vector<double> vec_t;
    typedef std::vector<double> map_t;
    typedef vec_t::iterator it_v;
    typedef map_t::iterator it_m;

    #define dEXPRESSION(a,v) \
        me::is_iterator<a>::value == v

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                     \
            static_assert(                                 \
                dEXPRESSION(type, expected),               \
                "'tools::is_iterator<" # type ">::value' " \
                "must be '" #expected "'"                  \
            )
    #else
        #define dCHECK(type, expected)                     \
            dSTATIC_CHECK(                                 \
                ERROR_INVALID_##expected,                  \
                dEXPRESSION(type, expected)                \
            )
    #endif

    struct base
    {
        typedef std::random_access_iterator_tag
            iterator_category;

        typedef int value_type;
        typedef int difference_type;
        typedef int* pointer;
        typedef int& reference;
    };

    struct iter: base
    {
        // prefix: ++it
        iter& operator++();
        iter& operator--();

        // postfix: it++
        iter operator++(int);
        iter operator--(int);
    };

} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(it_v, true );
    dCHECK(it_m, true );
    dCHECK(iter, true );
}
TEST_COMPONENT(001)
{
    dCHECK(const it_v, true );
    dCHECK(const it_m, true );
    dCHECK(const iter, true );
}
TEST_COMPONENT(002)
{
    dCHECK(const it_v, true );
    dCHECK(const it_m, true );
    dCHECK(const iter, true );
}
TEST_COMPONENT(003)
{
    dCHECK(volatile it_v, true );
    dCHECK(volatile it_m, true );
    dCHECK(volatile iter, true );
}
TEST_COMPONENT(004)
{
    dCHECK(volatile const it_v, true );
    dCHECK(volatile const it_m, true );
    dCHECK(volatile const iter, true );
}

TEST_COMPONENT(005)
{
    dCHECK(it_v&, true);
    dCHECK(it_m&, true);
    dCHECK(iter&, true);
}

#ifdef dHAS_RVALUE_REFERENCES
TEST_COMPONENT(006)
{
    dCHECK(it_v&&, true);
    dCHECK(it_m&&, true);
    dCHECK(iter&&, true);
}
#endif


TEST_COMPONENT(007)
{
    dCHECK(int*              , true );
    dCHECK(int*const         , true );
    dCHECK(int*volatile      , true );
    dCHECK(int*volatile const, true );

    dCHECK(const int*              , true );
    dCHECK(const int*const         , true );
    dCHECK(const int*volatile      , true );
    dCHECK(const int*volatile const, true );

    dCHECK(volatile int*              , true );
    dCHECK(volatile int*const         , true );
    dCHECK(volatile int*volatile      , true );
    dCHECK(volatile int*volatile const, true );

    dCHECK(volatile const int*              , true );
    dCHECK(volatile const int*const         , true );
    dCHECK(volatile const int*volatile      , true );
    dCHECK(volatile const int*volatile const, true );
}

TEST_COMPONENT(008)
{
    dCHECK(int*&              , true );
    dCHECK(int*const&         , true );
    dCHECK(int*volatile&      , true );
    dCHECK(int*volatile const&, true );

    dCHECK(const int*&              , true );
    dCHECK(const int*const&         , true );
    dCHECK(const int*volatile&      , true );
    dCHECK(const int*volatile const&, true );

    dCHECK(volatile int*&              , true );
    dCHECK(volatile int*const&         , true );
    dCHECK(volatile int*volatile&      , true );
    dCHECK(volatile int*volatile const&, true );

    dCHECK(volatile const int*&              , true );
    dCHECK(volatile const int*const&         , true );
    dCHECK(volatile const int*volatile&      , true );
    dCHECK(volatile const int*volatile const&, true );
}

#ifdef dHAS_RVALUE_REFERENCES
TEST_COMPONENT(009)
{
    dCHECK(int*&&              , true );
    dCHECK(int*const&&         , true );
    dCHECK(int*volatile&&      , true );
    dCHECK(int*volatile const&&, true );

    dCHECK(const int*&&              , true );
    dCHECK(const int*const&&         , true );
    dCHECK(const int*volatile&&      , true );
    dCHECK(const int*volatile const&&, true );

    dCHECK(volatile int*&&              , true );
    dCHECK(volatile int*const&&         , true );
    dCHECK(volatile int*volatile&&      , true );
    dCHECK(volatile int*volatile const&&, true );

    dCHECK(volatile const int*&&              , true );
    dCHECK(volatile const int*const&&         , true );
    dCHECK(volatile const int*volatile&&      , true );
    dCHECK(volatile const int*volatile const&&, true );
}
#endif

//==============================================================================
//==============================================================================

TEST_COMPONENT(010)
{
    dCHECK(int   , false);
    dCHECK(vec_t , false);
    dCHECK(map_t , false);
    dCHECK(double, false);
    dCHECK(A     , false);
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_IS_ITERABLE

