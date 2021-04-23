// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-04m-12d][02:22:31] Idrisov Denis R.
// [2021y-04m-21d][13:19:19] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_HAS_VALUE_TYPE

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD has_value_type
#define dTEST_TAG tdd

#include <tools/types/sfinae.hpp>
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
        me::has_value_type<a>::value == v

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                        \
            static_assert(                                    \
                dEXPRESSION(type, expected),                  \
                "'tools::has_value_type<" # type ">::value' " \
                "must be '" #expected "'"                     \
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

} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int   , false);
    dCHECK(int*  , false);
    dCHECK(iter  , false);
    dCHECK(it_v  , true );
    dCHECK(it_m  , true );

    dCHECK(vec_t , true );
    dCHECK(map_t , true );
}

TEST_COMPONENT(001)
{
    dCHECK(const int   , false);
    dCHECK(const int*  , false);
    dCHECK(const iter  , false);
    dCHECK(const it_v  , true );
    dCHECK(const it_m  , true );

    dCHECK(const vec_t , true );
    dCHECK(const map_t , true );
}

TEST_COMPONENT(002)
{
    dCHECK(int&   , false);
    dCHECK(int*&  , false);
    dCHECK(iter&  , false);
    dCHECK(it_v&  , false);
    dCHECK(it_m&  , false);

    dCHECK(vec_t& , false);
    dCHECK(map_t& , false);
}

TEST_COMPONENT(003)
{
    dCHECK(const int&   , false);
    dCHECK(const int*&  , false);
    dCHECK(const iter&  , false);
    dCHECK(const it_v&  , false);
    dCHECK(const it_m&  , false);

    dCHECK(const vec_t& , false);
    dCHECK(const map_t& , false);
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_HAS_VALUE_TYPE

