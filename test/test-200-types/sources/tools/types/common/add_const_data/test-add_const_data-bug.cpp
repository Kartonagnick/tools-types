// [2021y-04m-21d][17:48:49] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_ADD_CONST_DATA

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD add_const_data
#define dTEST_TAG bug

#include <tools/types/common.hpp>
namespace me = ::tools;
//==============================================================================
//=== [bug: msvc2010] ==========================================================
namespace bug_msvc2010
{
    #if !defined(dHAS_TYPE_TRAITS)
    // msvc2008
    template<class t> struct example
    {
        typedef dTRAIT::remove_reference<t>
            no_ref;
        typedef typename no_ref::type
            type;
    };
    #elif !defined(dHAS_ENUM_CLASS)
        // msvc2010
        template<class t> t& obj_();
        template<class t> t* decay_(t&);

        template<class t> struct remove_reference_
        {
            typedef decltype(decay_(obj_<t>()))
                naked;
            typedef ::std::remove_pointer<naked>
                no_ptr;
            typedef typename no_ptr::type
                type;
        };
        template<class t> struct example
        {
            typedef bug_msvc2010::remove_reference_<t>
                no_ref;
            typedef typename no_ref::type
                type;
        };
    #else
        // msvc2012 or newer
        template<class t> struct example
        {
            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type
                type;
        };
    #endif

} // namespace bug_msvc2010

// ---msvc2010 has bug
TEST_COMPONENT(015)
{
    typedef bug_msvc2010::example<int(&)()>
        bug;
    typedef bug::type 
        result;

    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        dTRAIT::is_same<result, int()>::value
    );
}
#ifdef dHAS_TYPE_TRAITS
TEST_COMPONENT(016)
{
    typedef bug_msvc2010::example<int(&&)()>
        bug;
    typedef bug::type 
        result;
    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        dTRAIT::is_same<result, int()>::value
    );
}
#endif

TEST_COMPONENT(017)
{
    typedef bug_msvc2010::example<int()>
        bug;
    typedef bug::type 
        result;
    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        dTRAIT::is_same<result, int()>::value
    );
}

TEST_COMPONENT(018)
{
    typedef bug_msvc2010::example<int[2]>
        bug;
    typedef bug::type 
        result;
    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        dTRAIT::is_same<result, int[2]>::value
    );
}
TEST_COMPONENT(019)
{
    typedef bug_msvc2010::example<int(&)[2]>
        bug;
    typedef bug::type 
        result;
    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        dTRAIT::is_same<result, int[2]>::value
    );
}
#ifdef dHAS_TYPE_TRAITS
TEST_COMPONENT(020)
{
    typedef bug_msvc2010::example<int(&&)[2]>
        bug;
    typedef bug::type 
        result;
    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        dTRAIT::is_same<result, int[2]>::value
    );
}
#endif

//==============================================================================
//=== [bug: msvc2010] ==========================================================
namespace bug_msvc2010
{
    template <class t> struct is_lval_ref_
        { enum { value = false }; };

    template <class t> struct is_lval_ref_<t&>
        { enum { value = true }; };

    template <class t> struct is_rval_ref_
        { enum { value = false }; };

    #ifdef dHAS_TYPE_TRAITS
    template <class t> struct is_rval_ref_<t&&>
        { enum { value = true }; };
    #endif

    #if defined(_MSC_VER) && _MSC_VER == 1600
        // msvc2010
        template <class t> struct is_ref_
        { 
            typedef is_lval_ref_<t> lval_t;
            typedef is_rval_ref_<t> rval_t;
            enum { lval = lval_t::value }; 
            enum { rval = rval_t::value }; 
            enum { value = lval || rval }; 
        };
    #else
        // not msvc2010
        template <class t> struct is_ref_
            { enum { value = false }; };
        template <class t> struct is_ref_ <t&>
            { enum { value = true }; };
        #ifdef dHAS_TYPE_TRAITS
        template <class t> struct is_ref_ <t&&>
            { enum { value = true }; };
        #endif
    #endif

} // namespace bug_msvc2010

TEST_COMPONENT(021)
{
    dSTATIC_CHECK(
        ERROR_BUG_LVALUE_MSVC2010, 
        bug_msvc2010::is_lval_ref_<void(&)()>::value
    );

    dSTATIC_CHECK(
        ERROR_BUG_LVALUE_MSVC2010, 
        bug_msvc2010::is_ref_<void(&)()>::value
    );
}

#if 0
// bug
#ifdef dHAS_TYPE_TRAITS
TEST_COMPONENT(022)
{
    dSTATIC_CHECK(
        ERROR_BUG_IS_RVALUE_MSVC2010, 
        bug_msvc2010::is_rval_ref_<void(&&)()>::value
    );

    dSTATIC_CHECK(
        ERROR_BUG_IS_REF_MSVC2010, 
        bug_msvc2010::is_ref_<void(&&)()>::value
    );
}
#endif
#endif

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_ADD_CONST_DATA

