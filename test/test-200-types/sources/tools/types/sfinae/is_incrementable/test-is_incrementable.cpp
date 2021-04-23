// [2021y-04m-12d][16:30:57] Idrisov Denis R.
// [2021y-04m-21d][13:12:30] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_INCREMENTABLE

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD is_incrementable
#define dTEST_TAG tdd

#include <tools/types/sfinae.hpp>
#include <vector>
#include <map>

namespace me = ::tools;
//==============================================================================
//==============================================================================
namespace
{
    class A {};
    typedef std::vector<double>   vec_t;
    typedef std::map<double, int> map_t;
    typedef vec_t::iterator       it_v;
    typedef map_t::iterator       it_m;

    #define dEXPRESSION(a,v) \
        me::is_incrementable<a>::value == v

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                          \
            static_assert(                                      \
                dEXPRESSION(type, expected),                    \
                "'tools::is_incrementable<" # type ">::value' " \
                "must be '" #expected "'"                       \
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
    };

    struct postfix
    {
        // postfix: it++
        postfix operator++(int);
        postfix operator--(int);
    };

    struct prefix
    {
        // prefix: ++it
        prefix& operator++();
        prefix& operator--();
    };

    class privat
    {
        // postfix: it++
        privat operator++(int);
        privat operator--(int);

        // prefix: ++it
        privat& operator++();
        privat& operator--();
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
    dCHECK(prefix  , true );

    dCHECK(int     , true );
    dCHECK(double  , true );
}
TEST_COMPONENT(001)
{
    dCHECK(vec_t , false);
    dCHECK(map_t , false);
    dCHECK(A     , false);
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
#else
TEST_COMPONENT(002)
{
    // --- ignore qualifier
    dCHECK(const iter   , true);
    dCHECK(const postfix, true);
    dCHECK(const prefix , true);
    dCHECK(const privat , true);
}
#endif

TEST_COMPONENT(003)
{
    #ifdef dHAS_CPP11
        dCHECK(privat  , false);
    #else
        // bug: msvc2013 or older
        dCHECK(privat  , true );
    #endif
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_IS_DEREFERENCABLE

