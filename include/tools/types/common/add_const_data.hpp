// [2021y-04m-06d][19:15:34] Idrisov Denis R. 100
// [2021y-04m-06d][23:09:28] Idrisov Denis R. 100
// [2021y-04m-08d][03:06:44] Idrisov Denis R. 100
// [2021y-04m-30d][00:01:49] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_ADD_CONST_DATA_USED_ 
#define dTOOLS_ADD_CONST_DATA_USED_ 101 PRE

#include <tools/type_traits.hpp>

//==============================================================================
//==============================================================================

namespace tools
{
    namespace detail_add_const
    {
        template<class t, bool = dTRAIT::is_function<t>::value>
        struct add_const_type_
            { typedef t type; };

        template<class t> struct add_const_type_<t, false>
            { typedef const t type; };

        template<class t> struct add_const_data_impl_
        {
            typedef ::tools::detail_add_const::add_const_type_<t> 
                const_t;
            typedef typename const_t::type
                type; 
        };

        template<class t> struct add_const_data_impl_<t&>
        {
            typedef ::tools::detail_add_const::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type
                x;
            typedef x& type; 
        };

        #ifdef dHAS_RVALUE_REFERENCES
        template<class t> struct add_const_data_impl_<t&&>
        {
            typedef ::tools::detail_add_const::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type
                x;
            typedef x&& type; 
        };
        #endif

        template<class t> struct add_const_data_impl_<t[]>
        {
            typedef ::tools::detail_add_const::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type 
                type[]; 
        };
        template<class t, size_t n> struct add_const_data_impl_<t[n]>
        { 
            typedef ::tools::detail_add_const::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type 
                type[n]; 
        };
        template<class t> struct add_const_data_impl_<t*>
        {
            typedef ::tools::detail_add_const::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type* 
                type; 
        };
        template<class t> struct add_const_data_impl_<t*const>
        {
            typedef ::tools::detail_add_const::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type*const 
                type; 
        };
        template<class t> struct add_const_data_impl_<t*volatile>
        {
            typedef ::tools::detail_add_const::add_const_data_impl_<t> 
                add_const_t;
            typedef typename add_const_t::type*volatile 
                type; 
        };
        template<class t> struct add_const_data_impl_<t*volatile const>
        {
            typedef ::tools::detail_add_const::add_const_data_impl_<t> 
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

        #if defined(_MSC_VER) && _MSC_VER <= 1600
        // msvc2010 has bug 
        template<class t> struct no_ref_      { typedef t type; };
        template<class t> struct no_ref_ <t&> { typedef t type; };
        #endif

    } // namespace detail_add_const

    template<class t> class add_const_data
    {
        #if defined(_MSC_VER) && _MSC_VER <= 1600
            // bug in msvc2010
            typedef ::tools::detail_add_const::no_ref_<t>
                no_ref;
        #else
            typedef dTRAIT::remove_reference<t>
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
        typedef ::tools::detail_add_const::add_const_data_<t, v> 
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

//==============================================================================
//==============================================================================
#endif // !dTOOLS_COMMON_USED_
