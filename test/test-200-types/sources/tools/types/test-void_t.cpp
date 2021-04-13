// [2021y-04m-13d][15:11:11] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_VOID_T

#define dTEST_COMPONENT tools, types
#define dTEST_METHOD void_t
#define dTEST_TAG tdd

#include <tools/type_traits.hpp>
#include <tools/types/void_t.hpp>
#include <vector>
#include <string>
//==============================================================================
//==============================================================================
namespace
{
    typedef std::string      str_t;
    typedef std::vector<int> vec_t;

    typedef ::std::void_t<int, bool, char, float, double, short, long>
        chk;
  
    template<class, class = void>
    struct has_value_type
        : std::integral_constant<bool, false>
    {};
 
    template<class T>
    struct has_value_type<T, ::std::void_t<typename T::value_type> > 
        : std::integral_constant<bool, true>
    {};

    dSTATIC_ASSERT(
        VEC_ERROR, has_value_type<str_t>::value
    );

    dSTATIC_ASSERT(
        MAP_ERROR, has_value_type<vec_t>::value
    );

    dSTATIC_ASSERT(
        INT_ERROR, !has_value_type<int>::value
    );

} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000){}
//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_VOID_T

