// [2021y-04m-19d][16:21:19] Idrisov Denis R.
#include <mygtest/modern.hpp>
//=================================================================================
//=================================================================================

#ifdef TEST_TOOLS_LIMIT

#define dTEST_COMPONENT tools, types
#define dTEST_METHOD limit
#define dTEST_TAG tdd

#include <tools/types/limit.hpp>

namespace me = ::tools;
//=================================================================================
//=================================================================================

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

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_LIMIT

