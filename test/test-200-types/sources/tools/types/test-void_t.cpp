// [2021y-04m-13d][15:11:11] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_VOID_T

#define dTEST_COMPONENT tools, types
#define dTEST_METHOD void_t
#define dTEST_TAG tdd

#include <tools/types/void_t.hpp>
#include <tools/type_traits.hpp>
#include <vector>
#include <string>
#include <map>
//==============================================================================
//==============================================================================

namespace
{
    typedef ::std::string           str_t;
    typedef ::std::vector<int>      vec_t;
    typedef ::std::map<size_t, int> map_t;

    #if !defined(_MSC_VER) || _MSC_VER >= 1800
        // msvc2013 or newer
        using void_t = ::tools::void_t<int, bool, char, float, double, short, long>;
    #else
        // msvc2012 or older
        typedef ::tools::void_type<int, bool, char, float, double, short, long>                
            chk_t;
        typedef chk_t::type 
            void_t;
    #endif

    template<class t> t obj();
  
//-------------------------------------
    template<class, class = void>
    struct has_value_type
        : dTRAIT::false_type
    {};
 
    template<class T>
    struct has_value_type<T, dSFINAE_VOID_TYPE(typename T::value_type)> 
        : dTRAIT::true_type
    {};

    dSTATIC_ASSERT(STR_VT_ERROR,  has_value_type<str_t>::value);
    dSTATIC_ASSERT(VEC_VT_ERROR,  has_value_type<vec_t>::value);
    dSTATIC_ASSERT(MAP_VT_ERROR,  has_value_type<map_t>::value);
    dSTATIC_ASSERT(INT_VT_ERROR, !has_value_type<int>::value);

//-------------------------------------
    template<class, class = void>
    struct has_mapped_type
        : dTRAIT::false_type
    {};
 
    template<class T>
    struct has_mapped_type<T, dSFINAE_VOID_TYPE(typename T::mapped_type)> 
        : dTRAIT::true_type
    {};

    dSTATIC_ASSERT(STR_MT_ERROR, !has_mapped_type<str_t>::value);
    dSTATIC_ASSERT(VEC_MT_ERROR, !has_mapped_type<vec_t>::value);
    dSTATIC_ASSERT(MAP_MT_ERROR,  has_mapped_type<map_t>::value);
    dSTATIC_ASSERT(INT_MT_ERROR, !has_mapped_type<int>::value);

//-------------------------------------
    #ifdef dHAS_CPP11
    template<class, class = void>
    struct has_begin
        : dTRAIT::false_type
    {};
 
    template<class T>
    struct has_begin<T, dSFINAE_VOID_TYPE(decltype(obj<T>().begin()))> 
        : dTRAIT::true_type
    {};

    dSTATIC_ASSERT(STR_MT_ERROR,  has_begin<str_t>::value);
    dSTATIC_ASSERT(VEC_MT_ERROR,  has_begin<vec_t>::value);
    dSTATIC_ASSERT(MAP_MT_ERROR,  has_begin<map_t>::value);
    dSTATIC_ASSERT(INT_MT_ERROR, !has_begin<int>::value);

//-------------------------------------
    
    template<class, class = size_t, class = void>
    struct has_op_access
        : dTRAIT::false_type
    {};
 
    template<class T, class I>
    struct has_op_access<T, I, dSFINAE_VOID_TYPE(decltype(obj<T>()[obj<I>()]))> 
        : dTRAIT::true_type
    {};
    
    template<class T>
    struct has_op_access<T, size_t, dSFINAE_VOID_TYPE(decltype(obj<T>()[0u]))> 
        : dTRAIT::true_type
    {};

    dSTATIC_ASSERT(STR_ACCESS_ERROR,  has_op_access<str_t>::value);
    dSTATIC_ASSERT(VEC_ACCESS_ERROR,  has_op_access<vec_t>::value);
    dSTATIC_ASSERT(MAP_ACCESS_ERROR,  has_op_access<map_t>::value);
    dSTATIC_ASSERT(INT_ACCESS_ERROR, !has_op_access<int>::value);

    dSTATIC_ASSERT(STR_ACCESS_ERROR,  has_op_access<str_t, size_t>::value);
    dSTATIC_ASSERT(VEC_ACCESS_ERROR,  has_op_access<vec_t, size_t>::value);
    dSTATIC_ASSERT(MAP_ACCESS_ERROR,  has_op_access<map_t, size_t>::value);
    dSTATIC_ASSERT(INT_ACCESS_ERROR, !has_op_access<int, size_t>::value);

    dSTATIC_ASSERT(STR_ACCESS_ERROR,  has_op_access<str_t, int>::value);
    dSTATIC_ASSERT(VEC_ACCESS_ERROR,  has_op_access<vec_t, int>::value);
    dSTATIC_ASSERT(MAP_ACCESS_ERROR,  has_op_access<map_t, int>::value);
    dSTATIC_ASSERT(INT_ACCESS_ERROR, !has_op_access<int, int>::value);

    dSTATIC_ASSERT(STR_ACCESS_ERROR, !has_op_access<str_t, void*>::value);
    dSTATIC_ASSERT(VEC_ACCESS_ERROR, !has_op_access<vec_t, void*>::value);
    dSTATIC_ASSERT(MAP_ACCESS_ERROR, !has_op_access<map_t, void*>::value);
    dSTATIC_ASSERT(INT_ACCESS_ERROR, !has_op_access<int, void*>::value);
    
//-------------------------------------
    template<class, class, class = void>
    struct can_cast
        : dTRAIT::false_type
    {};
 
    template<class From, class To>
    struct can_cast<From, To, dSFINAE_VOID_TYPE(
            decltype(static_cast<To>(obj<From>()))
        )> : dTRAIT::true_type
    {};

    dSTATIC_ASSERT(INT_CAST_ERROR,  can_cast<int, int>::value);
    dSTATIC_ASSERT(INT_CAST_ERROR,  can_cast<int, float>::value);
    dSTATIC_ASSERT(STR_CAST_ERROR, !can_cast<str_t, int>::value);

    #endif

} // namespace

//==============================================================================
//==============================================================================
TEST_COMPONENT(000){}

//==============================================================================
//==============================================================================

// --- msvc2015 has bug (see: docs/articles/using-declaration.md)

#if defined(_MSC_VER) && _MSC_VER >= 1900
    // msvc2015 or newer
    #include <type_traits>

#if _MSC_VER == 1900
    // msvc2015 only 
    namespace util
    {
        template<class... args>
        using void_t = ::std::void_t<args...>;
    }
#else
    // modern compiler (msvc2017 or newer)
    namespace util
    {
        using ::std::void_t;
    }
#endif

TEST_COMPONENT(001)
{
    util::void_t<int>* p = 0;
    (void)p;
}

#endif

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_VOID_T

