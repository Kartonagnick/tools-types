// [2021y-04m-13d][15:11:11] Idrisov Denis R.
// [2021y-04m-21d][14:03:07] Idrisov Denis R.
#include <mygtest/modern.hpp>

#define TEST_TOOLS_SFINAE

#ifdef TEST_TOOLS_SFINAE

#define dTEST_COMPONENT tools, types, sfinae
#define dTEST_METHOD concept
#define dTEST_TAG tdd

#include <tools/type_traits.hpp>
#include <vector>
#include <string>
#include <map>
//==============================================================================
//=== [concept] ================================================================
namespace sfinae
{
    #define dEXTRA(...) __VA_ARGS__
    #define dEXPAND(...) dEXTRA(__VA_ARGS__)

    #ifdef dHAS_TYPE_TRAITS
        // msvc2010 or newer
        template<class t> t obj();

        template<class t, bool = ::std::is_same<t,t>::value>
            struct expr_;

        template<class t> struct expr_<t, true>
            { typedef ::std::integral_constant<bool, true> type; };
    
        template<class t>
        typename ::sfinae::expr_<t>::type 
            expr();
    #endif

} // namespace sfinae
//==============================================================================
//=== [msvc2010 or newer] ======================================================
namespace sfinae
{
    #ifdef dHAS_TYPE_TRAITS
        // msvc2010 or newer
        #define dSFINAE_EXPR_(...) \
            decltype(__VA_ARGS__, dTRAIT::true_type())

        #define dSFINAE_DECLARATION_1(name, def, T1, ...)     \
            namespace detail                                  \
            {                                                 \
                template<class t> struct name##_              \
                {                                             \
                    template<class T1> static                 \
                        dSFINAE_EXPR_(__VA_ARGS__)            \
                        check(dSFINAE_EXPR_(__VA_ARGS__)*);   \
                    template<class> static                    \
                        dTRAIT::false_type check(...);        \
                    typedef decltype(check<t>(0))             \
                        type;                                 \
                };                                            \
            }                                                 \
            template<class t dEXTRA def>                      \
            struct name                                       \
                : detail::name##_<t>::type                    \
            {}

        #define dSFINAE_DECLARATION_2(name, def, T1, T2, ...) \
            namespace detail                                  \
            {                                                 \
                template<class t1, class t2> struct name##_   \
                {                                             \
                    template<class T1, class T2> static       \
                        dSFINAE_EXPR_(__VA_ARGS__)            \
                        check(dSFINAE_EXPR_(__VA_ARGS__)*);   \
                    template<class, class> static             \
                        dTRAIT::false_type check(...);        \
                    typedef decltype(check<t1, t2>(0))        \
                        type;                                 \
                };                                            \
            }                                                 \
            template<class t1, class t2 dEXTRA def>           \
            struct name                                       \
                : detail::name##_<t1, t2>::type               \
            {}

    #else
        // msvc2008 or older
        #define dSFINAE_DECLARATION_1(name, def, T1, ...)     \
        namespace detail                                      \
        {                                                     \
            template<class T1> struct name##_                 \
            {                                                 \
                __if_exists(__VA_ARGS__)                      \
                {                                             \
                    typedef dTRAIT::true_type type;           \
                }                                             \
                __if_not_exists(__VA_ARGS__)                  \
                {                                             \
                    typedef dTRAIT::false_type type;          \
                }                                             \
            };                                                \
        }                                                     \
        template<class t dEXTRA def>                          \
        struct name                                           \
            : detail::name##_<t>::type                        \
        {}

        #define dSFINAE_DECLARATION_2(name, def, T1, T2, ...) \
        namespace detail                                      \
        {                                                     \
            template<class T1, class T2> struct name##_       \
            {                                                 \
                __if_exists(__VA_ARGS__)                      \
                {                                             \
                    typedef dTRAIT::true_type type;           \
                }                                             \
                __if_not_exists(__VA_ARGS__)                  \
                {                                             \
                    typedef dTRAIT::false_type type;          \
                }                                             \
            };                                                \
        }                                                     \
        template<class t1, class t2 dEXTRA def>               \
        struct name                                           \
            : detail::name##_<t1, t2>::type                   \
        {}
    #endif

    #ifdef dHAS_TYPE_TRAITS
        // msvc2010 or newer
        dSFINAE_DECLARATION_1(has_mapped_type, () , u, 
            ::sfinae::expr<typename u::mapped_type>()
        );

        dSFINAE_DECLARATION_1(has_value_type, () , u, 
            ::sfinae::expr<typename u::value_type>() 
        );

        dSFINAE_DECLARATION_1(has_begin, (), u, 
            ::sfinae::obj<u>().begin()               
        );

        #if 0
        dSFINAE_DECLARATION_1(has_op_deref, (), u, 
            *::sfinae::obj<u>()
        );
        #endif

        dSFINAE_DECLARATION_2(has_op_access, (= size_t), cl, id, 
            ::sfinae::obj<cl>()[::sfinae::obj<id>()]  
        );
    #else
        // msvc2008 or older
        dSFINAE_DECLARATION_1(has_mapped_type, () , u, u::mapped_type);
        dSFINAE_DECLARATION_1(has_value_type , () , u, u::value_type );
        dSFINAE_DECLARATION_1(has_begin      , () , u, u::begin      );

        dSFINAE_DECLARATION_2(has_op_access, (= size_t), cl, id, 
            cl::operator[]
        );
    #endif

} // namespace sfinae

//==============================================================================
//=== [tests] ==================================================================
namespace
{
    typedef ::std::string           str_t;
    typedef ::std::vector<int>      vec_t;
    typedef ::std::map<size_t, int> map_t;

    struct foo
    {
        int operator*() const;
    };

} // namespace

TEST_COMPONENT(000)
{
    using namespace sfinae;
    dSTATIC_CHECK(STR_MAPPED_ERROR, !has_mapped_type<str_t>::value);
    dSTATIC_CHECK(VEC_MAPPED_ERROR, !has_mapped_type<vec_t>::value);
    dSTATIC_CHECK(MAP_MAPPED_ERROR,  has_mapped_type<map_t>::value);
    dSTATIC_CHECK(INT_MAPPED_ERROR, !has_mapped_type<int>::value  );
}
TEST_COMPONENT(001)
{
    using namespace sfinae;
    dSTATIC_CHECK(STR_VALUE_ERROR,  has_value_type<str_t>::value);
    dSTATIC_CHECK(VEC_VALUE_ERROR,  has_value_type<vec_t>::value);
    dSTATIC_CHECK(MAP_VALUE_ERROR,  has_value_type<map_t>::value);
    dSTATIC_CHECK(INT_VALUE_ERROR, !has_value_type<int>::value  );
}
TEST_COMPONENT(002)
{
    using namespace sfinae;
    dSTATIC_ASSERT(STR_BEGIN_ERROR,  has_begin<str_t>::value    );
    dSTATIC_ASSERT(VEC_BEGIN_ERROR,  has_begin<vec_t>::value    );
    dSTATIC_ASSERT(MAP_BEGIN_ERROR,  has_begin<map_t>::value    );
    dSTATIC_ASSERT(INT_BEGIN_ERROR, !has_begin<int>::value      );
}
#if 0
TEST_COMPONENT(003)
{
    using namespace sfinae;
    dSTATIC_ASSERT(STR_DEREF_ERROR, !has_op_deref<str_t>::value);
    dSTATIC_ASSERT(VEC_DEREF_ERROR, !has_op_deref<vec_t>::value);
    dSTATIC_ASSERT(MAP_DEREF_ERROR, !has_op_deref<map_t>::value);
    dSTATIC_ASSERT(INT_DEREF_ERROR, !has_op_deref<int>::value  );
    dSTATIC_ASSERT(INTP_DEREF_ERROR, has_op_deref<int*>::value );
    dSTATIC_ASSERT(FOO_DEREF_ERROR,  has_op_deref<foo>::value  );
}
#endif
TEST_COMPONENT(004)
{
    using namespace sfinae;
    dSTATIC_ASSERT(STR_ACCESS_ERROR,  has_op_access<str_t>::value);
    dSTATIC_ASSERT(VEC_ACCESS_ERROR,  has_op_access<vec_t>::value);
    dSTATIC_ASSERT(MAP_ACCESS_ERROR,  has_op_access<map_t>::value);
    dSTATIC_ASSERT(INT_ACCESS_ERROR, !has_op_access<int>::value  );
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_VOID_T

