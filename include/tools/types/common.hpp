// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-17d][20:25:15] Idrisov Denis R.
// [2021y-03m-19d][22:03:35] Idrisov Denis R. 102
// [2021y-03m-20d][19:43:08] Idrisov Denis R. 103
// [2021y-03m-21d][04:01:28] Idrisov Denis R. 104
// [2021y-03m-23d][23:55:08] Idrisov Denis R. 105
// [2021y-03m-30d][03:40:56] Idrisov Denis R. 106
// [2021y-04m-04d][07:05:55] Idrisov Denis R. 107

// [2021y-04m-05d][04:32:42] Idrisov Denis R. 108 PRE
#pragma once
#ifndef dTOOLS_COMMON_USED_ 
#define dTOOLS_COMMON_USED_ 108 PRE

#include <tools/features.hpp>
#include <tools/pragma/pragma.hpp>

//==============================================================================
//==============================================================================

#ifdef dHAS_CPP11
    // dMESSAGE("[c++11][types/common]")
    #include <tools/types/common/common-msvc2015.hpp>
#elif dHAS_USING_ALIAS
    // dMESSAGE("[alias][types/common]")
    #include <tools/types/common/common-msvc2013.hpp>
#else
    // dMESSAGE("[old][types/common]")
    #include <tools/types/common/common-msvc2008.hpp>
#endif

#include <tools/types/common/array.hpp>

//================================================================================
//=== type_of_enum ============================================= (type_traits) ===
#ifdef dHAS_ENUM_CLASS
#ifndef dTOOLS_ENUM_TYPE_USED_ 
#define dTOOLS_ENUM_TYPE_USED_ 100
namespace tools
{
    template<class t, bool = ::std::is_enum<t>::value>
    struct type_of_enum
    {
        typedef typename ::std::underlying_type<t>::type
            type;
    };

    template<class t> struct type_of_enum<t, false>
        { typedef t type; };

    #ifdef dHAS_USING_ALIAS
    template<class t> 
    using type_of_enum_t
        = typename ::tools::type_of_enum<t>::type;
    #endif

} // tools
#endif // !dTOOLS_ENUM_TYPE_USED_
#endif // !dHAS_ENUM_CLASS


//==============================================================================
//=== add_const_data ===========================================================
#ifndef dTOOLS_ADD_CONST_DATA_USED_ 
#define dTOOLS_ADD_CONST_DATA_USED_ 101
namespace tools
{
    namespace detail
    {
        template<class t, bool = dTRAIT::is_function<t>::value >
        struct add_const_type_
            { typedef t type; };

        template<class t> struct add_const_type_<t, false>
            { typedef const t type; };

        template<class t> struct add_const_data_impl_
        {
            typedef ::tools::detail::add_const_type_<t> 
                const_t;
            typedef typename const_t::type
                type; 
        };

        template<class t> struct add_const_data_impl_<t&>
        {
            typedef ::tools::detail::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type
				x;
            typedef x& type; 
        };

		#ifdef dHAS_RVALUE_REFERENCES
        template<class t> struct add_const_data_impl_<t&&>
        {
            typedef ::tools::detail::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type
				x;
            typedef x&& type; 
        };
		#endif

        template<class t> struct add_const_data_impl_<t[]>
		{
            typedef ::tools::detail::add_const_data_impl_<t> 
                add_const_t;
			typedef typename add_const_t::type 
				type[]; 
		};
        template<class t, size_t n> struct add_const_data_impl_<t[n]>
        { 
            typedef ::tools::detail::add_const_data_impl_<t> 
                add_const_t;
			typedef typename add_const_t::type 
				type[n]; 
		};

        template<class t> struct add_const_data_impl_<t*>
        {
            typedef ::tools::detail::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type* 
                type; 
        };
        template<class t> struct add_const_data_impl_<t*const>
        {
            typedef ::tools::detail::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type*const 
                type; 
        };
        template<class t> struct add_const_data_impl_<t*volatile>
        {
            typedef ::tools::detail::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type*volatile 
                type; 
        };
        template<class t> struct add_const_data_impl_<t*volatile const>
        {
            typedef ::tools::detail::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type*volatile const 
                type; 
        };

        template<class m, class cl> 
        struct add_const_data_impl_<m cl::*>
        {
            typedef add_const_type_<m> 
                const_t;
            typedef typename const_t::type x;
            typedef x cl::*type;
        };

        template<class m, class cl> 
        struct add_const_data_impl_<m cl::*const>
        {
            typedef add_const_type_<m> 
                const_t;
            typedef typename const_t::type x;
            typedef x cl::*const type;
        };

        template<class m, class cl> 
        struct add_const_data_impl_<m cl::*volatile>
        {
            typedef add_const_type_<m> 
                const_t;
            typedef typename const_t::type x;
            typedef x cl::*volatile type;
        };

        template<class m, class cl> 
        struct add_const_data_impl_<m cl::*volatile const>
        {
            typedef add_const_type_<m> 
                const_t;
            typedef typename const_t::type x;
            typedef x cl::*volatile const type;
        };

        template<class t, bool> struct add_const_data_
            { typedef t type; };

        template<class t> struct add_const_data_<t, false>
            : add_const_data_impl_<t>
        {};

        #if !defined(_MSC_VER) || _MSC_VER <= 1600
        // msvc2010 has bug 
        template<class t> struct no_ref_      { typedef t type; };
        template<class t> struct no_ref_ <t&> { typedef t type; };
        #endif

    } // namespace detail

    template<class t> class add_const_data
    {
        #if !defined(_MSC_VER) || _MSC_VER <= 1600
        // bug in msvc2010
        typedef ::tools::detail::no_ref_<t>
            no_ref;
        #else
        typedef dTRAIT::remove_reference<t&>
            no_ref;
        #endif

        typedef typename no_ref::type
            x;
        typedef dTRAIT::remove_cv<x>  // bug in msvc20013
            no_cv;
        typedef typename no_cv::type
            z;
        typedef dTRAIT::remove_pointer<z>
            no_ptr;
        typedef typename no_ptr::type
            w;
        enum { v = dTRAIT::is_function<w>::value };
        typedef ::tools::detail::add_const_data_<t, v> 
            add_const_t;
    public:
        typedef typename add_const_t::type 
            type;
    };

    #ifdef dHAS_USING_ALIAS
    template<class t> 
    using add_const_data_t
        = typename add_const_data<t>::type;
    #endif

} // namespace tools
#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMMON_USED_
