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
#include <map>
//==============================================================================
//==============================================================================

template<class t> t obj();

template<class t>
typename dTRAIT::enable_if< dTRAIT::is_same<t,t>::value, dTRAIT::true_type>::type
check_expression();

typedef char(&no )[1];
typedef char(&yes)[2];

namespace
{
    typedef ::std::string        str_t;
    typedef ::std::vector<int>   vec_t;
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
  
//-------------------------------------

    template<class, class = void>
    struct has_value_type
        : dTRAIT::false_type
    {};
 
    template<class T>
    struct has_value_type<T, dSFINAE_VOID_TYPE(typename T::value_type)> 
        : dTRAIT::true_type
    {};

    dSTATIC_ASSERT(
        STR_ERROR, has_value_type<str_t>::value
    );

    dSTATIC_ASSERT(
        VEC_ERROR, has_value_type<vec_t>::value
    );

    dSTATIC_ASSERT(
        MAP_ERROR, has_value_type<map_t>::value
    );

    dSTATIC_ASSERT(
        INT_ERROR, !has_value_type<int>::value
    );

//-------------------------------------

    #if dHAS_TYPE_TRAITS
        // msvc2010 or newer
        template<class t> struct has_mapped_type_
        {
            #define dEXPR check_expression<typename u::mapped_type>()

            #define dSFINAE_EXPR \
                decltype(check_expression<decltype(dEXPR)>())

            template<class u> static
                decltype(dEXPR, dTRAIT::true_type())
                check(dSFINAE_EXPR*);

            #undef dSFINAE_EXPR
            #undef dEXPR

            template<class> static
                dTRAIT::false_type check(...);

            typedef decltype(check<t>(0))
                type;
        };
    #else
        // msvc2008 or older
        template<class t> struct has_mapped_type_
        {
            __if_exists(t::mapped_type)
            {
                typedef dTRAIT::true_type type;
            }
            __if_not_exists(t::mapped_type)
            {
                typedef dTRAIT::false_type type;
            }
        };
    #endif

    template<class t> 
    struct has_mapped_type
        : has_mapped_type_<t>::type
    {};

    dSTATIC_ASSERT(
        STR_MAPPED_ERROR, !has_mapped_type<str_t>::value
    );
    dSTATIC_ASSERT(
        VEC_MAPPED_ERROR, !has_mapped_type<vec_t>::value
    );
    dSTATIC_ASSERT(
        MAP_MAPPED_ERROR, has_mapped_type<map_t>::value
    );
    dSTATIC_ASSERT(
        INT_MAPPED_ERROR, !has_mapped_type<int>::value
    );

//-------------------------------------
    #if dHAS_TYPE_TRAITS
        // msvc2010 or newer
        template<class t, class i> struct has_op_access_
        {
            #define dEXPR obj<cl>()[obj<id>()]

            #define dSFINAE_EXPR \
                decltype(check_expression<decltype(dEXPR)>())

            template<class cl, class id> static
                decltype(dEXPR, dTRAIT::true_type())
                check(dSFINAE_EXPR*);

            #undef dSFINAE_EXPR
            #undef dEXPR

            template<class, class> static
                dTRAIT::false_type check(...);

            typedef decltype(check<t, i>(0))
                type;
        };
    #else
        // msvc2008 or older
        template<class T, class I> struct has_op_access_
        {
            __if_exists(T::operator[])
            {
                typedef dTRAIT::true_type type;
            }
            __if_not_exists(T::operator[])
            {
                typedef dTRAIT::false_type type;
            }
        };
    #endif

    template<class T, class I = size_t>
    struct has_op_access
        : has_op_access_<T,I>::type
    {};

    dSTATIC_ASSERT(
        STR_ACCESS_ERROR, has_op_access<str_t>::value
    );
    dSTATIC_ASSERT(
        VEC_ACCESS_ERROR, has_op_access<vec_t>::value
    );
    dSTATIC_ASSERT(
        MAP_ACCESS_ERROR, has_op_access<map_t>::value
    );
    dSTATIC_ASSERT(
        INT_ACCESS_ERROR, !has_op_access<int>::value
    );

//-------------------------------------
    #if dHAS_TYPE_TRAITS
        // msvc2010 or newer
        template<class t> struct has_begin_
        {
            #define dEXPR                      \
                typename dTRAIT::add_pointer<  \
                    decltype(obj<u>().begin()) \
                >::type                        \

            template<class u> static
                decltype(obj<u>().begin(), dTRAIT::true_type())
                check(dEXPR);

            #undef dEXPR

            template<class> static 
                dTRAIT::false_type check(...);

            typedef decltype(check<t>(0))
                type;
        };
    #else
        // msvc2008 or older
        template<class T> struct has_begin_
        {
            __if_exists(T::begin)
            {
                typedef dTRAIT::true_type type;
            }
            __if_not_exists(T::begin)
            {
                typedef dTRAIT::false_type type;
            }
        };

    #endif

    template<class t> struct has_begin 
        : has_begin_<t>::type
    {};

    dSTATIC_ASSERT(
        STR_BEGIN_ERROR, has_begin<str_t>::value
    );
    dSTATIC_ASSERT(
        VEC_BEGIN_ERROR, has_begin<vec_t>::value
    );
    dSTATIC_ASSERT(
        MAP_BEGIN_ERROR, has_begin<map_t>::value
    );
    dSTATIC_ASSERT(
        INT_BEGIN_ERROR, !has_begin<int>::value
    );

//-------------------------------------
    #if dHAS_TYPE_TRAITS
        // msvc2010 or newer
        template<class From, class To> struct can_cast_
        {
            typedef ::std::is_convertible<From, To>
                type;
        };
    #else
        #ifdef _MSC_VER
            #pragma warning(push)
            // warning C4244: 'argument' : conversion from 'float' to 'int', 
            // possible loss of data
            #pragma warning(disable: 4244)
        #endif

        // msvc2008 or older
        template<class From, class To> struct can_cast_
        {
            template <class u> static yes check(u);
            template <class> static no check(...);

            enum { result = sizeof(check<From>(obj<To>())) };
            enum { value = result != sizeof(no) };

            typedef dTRAIT::conditional<value, 
                dTRAIT::true_type, 
                dTRAIT::false_type
            > cond_t;

            typedef typename cond_t::type
                type;
        };

        #ifdef _MSC_VER
            #pragma warning(pop)
        #endif

    #endif

    template<class from, class to> struct can_cast 
        : can_cast_<from, to>::type
    {};

    dSTATIC_ASSERT(
        INT_CAST_ERROR, can_cast<int, int>::value
    );
    dSTATIC_ASSERT(
        INT_CAST_ERROR, can_cast<int, float>::value
    );
    dSTATIC_ASSERT(
        STR_CAST_ERROR, !can_cast<str_t, int>::value
    );

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

