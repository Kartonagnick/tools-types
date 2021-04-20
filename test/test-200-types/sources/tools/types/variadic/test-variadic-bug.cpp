
// [2021y-04m-20d][21:54:03] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_VARIADIC

#define dTEST_COMPONENT tools, types
#define dTEST_METHOD variadic
#define dTEST_TAG bug

// msvc2008  and  msvc2010 has bug
// this concept is a workaround

//================================================================================
//================================================================================

namespace test_variadic
{
    struct dummy;

    template <bool, class = void>
    struct if_ {};

    template <class t>
    struct if_<true, t> { typedef t type; };

    template <class t, class u>
    struct same_ { enum { value = 0 }; };

    template <class t>
    struct same_ <t, t> { enum { value = 1 }; };

    template<class t, class u> struct help_
    {
        enum { v = same_<t, u>::value };
        typedef if_<!v, dummy*>
            if_t;
        typedef typename if_t::type
            type;
    };

    #define impl(t,u) \
        typename help_<t,u>::type

    #define decl(t,u) \
        impl(t,u) = 0

    struct example
    {
        template<class A>
        example(const A&, decl(A, example));
        example(const example&);
        example();
    };

    template<class A>
    example::example(const A& a, impl(A, example)) {}

} // namespace test_variadic

//================================================================================

TEST_COMPONENT(000)
{
}

//================================================================================
#endif // !TEST_TOOLS_TYPE_DEMANGLE

