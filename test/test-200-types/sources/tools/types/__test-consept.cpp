// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-20d][05:14:05] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_FUNCTOR

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD consept
#define dTEST_TAG tdd

// typedef char no[2];

typedef char no[1];
typedef char yes[400];

template<class t> no& confirm(t&);
template<class t> yes& confirm(const t&);

template<class t> t val();

template<class t> struct is_const_data_
{
private:
    enum { sz = sizeof(confirm(val<t&>().foo())) };
public:
    enum { value = sz == sizeof(yes) };
};

struct baz
{
    const int& foo();
};

struct bar
{
    int& foo();
};

#ifdef dHAS_STATIC_ASSERT
    static_assert( is_const_data_<baz>::value , "bug");
    static_assert(!is_const_data_<bar>::value , "bug");
#endif

//==============================================================================
//==============================================================================
TEST_COMPONENT(000)
{
    dSTATIC_ASSERT(ERROR_INTERNAL,  is_const_data_<baz>::value);
    dSTATIC_ASSERT(ERROR_INTERNAL, !is_const_data_<bar>::value);

    ASSERT_TRUE( is_const_data_<baz>::value);
    ASSERT_TRUE(!is_const_data_<bar>::value);
}

//==============================================================================
//==============================================================================

#define dSFINAE(...) \
    decltype(__VA_ARGS__, ::std::true_type{})

template<size_t n> struct sfinae
    { char val[n]; };

template<class t> sfinae<sizeof(t) + 1> stage(const t&);

template<class t> class deref_available
{
    //using x = ::std::remove_reference_t<t>;
    typedef t x;

    template<class u> static
    sfinae< sizeof(stage(*val<u&>())) >
        check(void*);

    template<class> static no& check(...);
public:
    enum { sz = sizeof(check<x>(0)) };
    enum { value = sz != sizeof(no) };
};

struct bazz { const int& operator*(); };
struct barr { int& operator*();       };

TEST_COMPONENT(001)
{
    bool val = false;
    if (!val)
        dASSERT(false && "trololo");


    dSTATIC_ASSERT(ERROR_INTERNAL, deref_available<bazz>::value      );
    dSTATIC_ASSERT(ERROR_INTERNAL, deref_available<barr>::value      );
    //dSTATIC_ASSERT(!deref_available<const bazz>::value, ERROR_INTERNAL);
    //dSTATIC_ASSERT(!deref_available<const barr>::value, ERROR_INTERNAL);

    std::cout << deref_available<const bazz>::sz << '\n';

    ASSERT_TRUE(deref_available<bazz>::value);
    ASSERT_TRUE(deref_available<barr>::value);

    //ASSERT_TRUE(!deref_available<const bazz>::value);
    //ASSERT_TRUE(!deref_available<const barr>::value);
}

struct dazz
{
    char operator*() const;
};

TEST_COMPONENT(002)
{
    dSTATIC_ASSERT(ERROR_INTERNAL, deref_available<dazz>::value);
}

#endif // !TEST_TOOLS_IS_FUNCTOR

