// [2021y-04m-13d][01:56:09] Idrisov Denis R.
// [2021y-04m-21d][13:17:28] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_HAS_END

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD has_end
#define dTEST_TAG tdd

#include <tools/types/sfinae.hpp>
#include <string>

namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #define dEXPRESSION(a,v) \
        me::has_end<a>::value == v

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(type, expected)                \
            static_assert(                            \
                dEXPRESSION(type, expected),          \
                "tools::has_end<" # type ">::value "  \
                "must be '" #expected "'"             \
            )
    #else
        #define dCHECK(type, expected)  \
        dSTATIC_ASSERT(                 \
            ERROR_INTERNAL,             \
            dEXPRESSION(type, expected) \
        )
    #endif

    struct regular
    {
        int& end();
    };

    struct constant
    {
        int& end() const;
    };

} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dCHECK(int[1]       , false );
    dCHECK(regular      , true  );
    dCHECK(constant     , true  );
    dCHECK(std::string  , true  );

    dCHECK(int(&)[1]    , false );
    dCHECK(regular&     , true  );
    dCHECK(constant&    , true  );
    dCHECK(std::string& , true  );

    dCHECK(const int(&)[1]    , false );
    dCHECK(const constant&    , true  );
    dCHECK(const std::string& , true  );

    #ifdef dHAS_ARRAY_EMPTY_SIZE
    dCHECK(int[]              , false );
    dCHECK(int(&)[]           , false );
    dCHECK(const int(&)[]     , false );
    #endif

    #ifdef dHAS_USING_ALIAS
    dCHECK(const regular&     , false );
    #else
    dCHECK(const regular&     , true  );
    #endif
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_HAS_END
