// [2021y-04m-12d][21:03:40] Idrisov Denis R.
// [2021y-04m-21d][13:16:22] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_HAS_MAPPED_TYPE

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD has_mapped_type
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
        me::has_mapped_type<a>::value == v

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                         \
            static_assert(                                     \
                dEXPRESSION(type, expected),                   \
                "'tools::has_mapped_type<" # type ">::value' " \
                "must be '" #expected "'"                      \
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
    dCHECK(it_v  , false);
    dCHECK(it_m  , false);

    dCHECK(vec_t , false);
    dCHECK(map_t , true );
}

TEST_COMPONENT(001)
{
    dCHECK(const int   , false);
    dCHECK(const int*  , false);
    dCHECK(const iter  , false);
    dCHECK(const it_v  , false);
    dCHECK(const it_m  , false);

    dCHECK(const vec_t , false);
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
#endif // !TEST_TOOLS_HAS_MAPPED_TYPE

