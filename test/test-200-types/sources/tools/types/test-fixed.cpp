// [2021y-03m-10d][12:47:17] Idrisov Denis R.
#include <mygtest/modern.hpp>
//=================================================================================
//=================================================================================

#ifdef TEST_TOOLS_FIXED

#define dTEST_COMPONENT tools, types
#define dTEST_METHOD fixed
#define dTEST_TAG tdd

#include <tools/types/fixed.hpp>

namespace me = ::tools;

//==============================================================================
//==============================================================================

TEST_COMPONENT(000)
{
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_8BIT , sizeof(me::uint8_t ) == 1);
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_16BIT, sizeof(me::uint16_t) == 2);
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_32BIT, sizeof(me::uint32_t) == 4);
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_64BIT, sizeof(me::int64_t ) == 8);
}

TEST_COMPONENT(001)
{
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_8BIT , sizeof(me::int8_t ) == 1);
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_16BIT, sizeof(me::int16_t) == 2);
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_32BIT, sizeof(me::int32_t) == 4);
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_64BIT, sizeof(me::int64_t) == 8);
}

//==============================================================================
//=== map_signed ===============================================================

TEST_COMPONENT(002)
{
    typedef me::map_signed<1>::type 
        type;
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_8BIT, sizeof(type) == 1);
}
TEST_COMPONENT(003)
{
    typedef me::map_signed<2>::type 
        type;
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_16BIT, sizeof(type) == 2);
}
TEST_COMPONENT(004)
{
    typedef me::map_signed<4>::type 
        type;
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_32BIT, sizeof(type) == 4);
}
TEST_COMPONENT(005)
{
    typedef me::map_signed<8>::type 
        type;
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_64BIT, sizeof(type) == 8);
}

//==============================================================================
//=== map_unsigned =============================================================
TEST_COMPONENT(006)
{
    typedef me::map_unsigned<1>::type 
        type;
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_8BIT, sizeof(type) == 1);
}
TEST_COMPONENT(007)
{
    typedef me::map_unsigned<2>::type 
        type;
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_16BIT, sizeof(type) == 2);
}
TEST_COMPONENT(008)
{
    typedef me::map_unsigned<4>::type 
        type;
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_32BIT, sizeof(type) == 4);
}
TEST_COMPONENT(009)
{
    typedef me::map_unsigned<8>::type 
        type;
    dSTATIC_ASSERT(ERROR_INVALID_SIZE_MUST_BE_64BIT, sizeof(type) == 8);
}

//==============================================================================
//=== macro ====================================================================

TEST_COMPONENT(010)
{
    me::int8_t min8   = INT8_MIN ;
    me::int8_t max8   = INT8_MAX ;

    me::int16_t min16 = INT16_MIN;
    me::int16_t max16 = INT16_MAX;

    me::int32_t min32 = INT32_MIN;
    me::int32_t max32 = INT32_MAX;

    me::int64_t min64 = INT64_MIN;
    me::int64_t max64 = INT64_MAX;

    dSTATIC_ASSERT(ERROR_INT8_MIN , me::map_signed<1>::min_value == INT8_MIN );
    dSTATIC_ASSERT(ERROR_INT16_MIN, me::map_signed<2>::min_value == INT16_MIN);    
    dSTATIC_ASSERT(ERROR_INT32_MIN, me::map_signed<4>::min_value == INT32_MIN);
    dSTATIC_ASSERT(ERROR_INT64_MIN, me::map_signed<8>::min_value == INT64_MIN);
    dSTATIC_ASSERT(ERROR_INT8_MAX , me::map_signed<1>::max_value == INT8_MAX );
    dSTATIC_ASSERT(ERROR_INT16_MAX, me::map_signed<2>::max_value == INT16_MAX);    
    dSTATIC_ASSERT(ERROR_INT32_MAX, me::map_signed<4>::max_value == INT32_MAX);
    dSTATIC_ASSERT(ERROR_INT64_MAX, me::map_signed<8>::min_value == INT64_MIN);

    ASSERT_TRUE(min8  == me::map_signed<1>::min_value);
    ASSERT_TRUE(min16 == me::map_signed<2>::min_value);
    ASSERT_TRUE(min32 == me::map_signed<4>::min_value);
    ASSERT_TRUE(min64 == me::map_signed<8>::min_value);

    ASSERT_TRUE(max8  == me::map_signed<1>::max_value);
    ASSERT_TRUE(max16 == me::map_signed<2>::max_value);
    ASSERT_TRUE(max32 == me::map_signed<4>::max_value);
    ASSERT_TRUE(max64 == me::map_signed<8>::max_value);
}

TEST_COMPONENT(011)
{
    me::uint8_t min8   = 0 ;
    me::uint8_t max8   = UINT8_MAX ;

    me::uint16_t min16 = 0;
    me::uint16_t max16 = UINT16_MAX;

    me::uint32_t min32 = 0;
    me::uint32_t max32 = UINT32_MAX;

    me::uint64_t min64 = 0;
    me::uint64_t max64 = UINT64_MAX;

    dSTATIC_ASSERT(ERROR_UINT8_MIN , me::map_unsigned<1>::min_value == 0);
    dSTATIC_ASSERT(ERROR_UINT16_MIN, me::map_unsigned<2>::min_value == 0);    
    dSTATIC_ASSERT(ERROR_UINT32_MIN, me::map_unsigned<4>::min_value == 0);
    dSTATIC_ASSERT(ERROR_UINT64_MIN, me::map_unsigned<8>::min_value == 0);

    dSTATIC_ASSERT(ERROR_UINT8_MAX , me::map_unsigned<1>::max_value == UINT8_MAX );
    dSTATIC_ASSERT(ERROR_UINT16_MAX, me::map_unsigned<2>::max_value == UINT16_MAX);    
    dSTATIC_ASSERT(ERROR_UINT32_MAX, me::map_unsigned<4>::max_value == UINT32_MAX);
    dSTATIC_ASSERT(ERROR_UINT64_MAX, me::map_unsigned<8>::max_value == UINT64_MAX);

    ASSERT_TRUE(min8  == me::map_unsigned<1>::min_value);
    ASSERT_TRUE(min16 == me::map_unsigned<2>::min_value);
    ASSERT_TRUE(min32 == me::map_unsigned<4>::min_value);
    ASSERT_TRUE(min64 == me::map_unsigned<8>::min_value);

    ASSERT_TRUE(max8  == me::map_unsigned<1>::max_value);
    ASSERT_TRUE(max16 == me::map_unsigned<2>::max_value);
    ASSERT_TRUE(max32 == me::map_unsigned<4>::max_value);
    ASSERT_TRUE(max64 == me::map_unsigned<8>::max_value);
}

#if 0
TEST_COMPONENT(012)
{
    dSTATIC_ASSERT(ERROR_UINT8_MIN , me::limit<me::uint8_t >::min_value == 0);
    dSTATIC_ASSERT(ERROR_UINT16_MIN, me::limit<me::uint16_t>::min_value == 0);    
    dSTATIC_ASSERT(ERROR_UINT32_MIN, me::limit<me::uint32_t>::min_value == 0);
    dSTATIC_ASSERT(ERROR_UINT64_MIN, me::limit<me::uint64_t>::min_value == 0);

    dSTATIC_ASSERT(ERROR_UINT8_MAX , me::limit<me::uint8_t >::max_value == UINT8_MAX );
    dSTATIC_ASSERT(ERROR_UINT16_MAX, me::limit<me::uint16_t>::max_value == UINT16_MAX);    
    dSTATIC_ASSERT(ERROR_UINT32_MAX, me::limit<me::uint32_t>::max_value == UINT32_MAX);
    dSTATIC_ASSERT(ERROR_UINT64_MAX, me::limit<me::uint64_t>::max_value == UINT64_MAX);
}

TEST_COMPONENT(013)
{
    dSTATIC_ASSERT(ERROR_INT8_MIN , me::limit<me::int8_t >::min_value == INT8_MIN );
    dSTATIC_ASSERT(ERROR_INT16_MIN, me::limit<me::int16_t>::min_value == INT16_MIN);    
    dSTATIC_ASSERT(ERROR_INT32_MIN, me::limit<me::int32_t>::min_value == INT32_MIN);
    dSTATIC_ASSERT(ERROR_INT64_MIN, me::limit<me::int64_t>::min_value == INT64_MIN);

    dSTATIC_ASSERT(ERROR_INT8_MAX , me::limit<me::int8_t >::max_value == INT8_MAX );
    dSTATIC_ASSERT(ERROR_INT16_MAX, me::limit<me::int16_t>::max_value == INT16_MAX);    
    dSTATIC_ASSERT(ERROR_INT32_MAX, me::limit<me::int32_t>::max_value == INT32_MAX);
    dSTATIC_ASSERT(ERROR_INT64_MAX, me::limit<me::int64_t>::max_value == INT64_MAX);
}
#endif


//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_FIXED

