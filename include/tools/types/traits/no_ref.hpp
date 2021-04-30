// [2021y-04m-30d][01:09:28] Idrisov Denis R. 001 PRE
#pragma once
#ifndef dTOOLS_REMOVE_REFERENCE_USED_ 
#define dTOOLS_REMOVE_REFERENCE_USED_ 3 PRE
#include <tools/features.hpp>

//==============================================================================
//==============================================================================
namespace tools
{
    #if defined(_MSC_VER) && _MSC_VER == 1600
        // msvc2010 has bug: 
        //   - see docs/articles/rvalue-references-1.md
        //   - see docs/articles/rvalue-references-2.md
        //   - see docs/articles/rvalue-references-3.md

        namespace detail
        {
            template<class t> t obj_();
            template<class t> t* decay_(t&);

        } // namespace detail

        namespace detail_no_ref
        {
            template <class t> struct no_ptr_ 
                { typedef t type; };

            template <class t> struct no_ptr_<t*> 
                { typedef t type; };

        } // namespace detail_no_ref

        template<class t> struct remove_reference
        {
        private:
            typedef decltype(::tools::detail::decay_(::tools::detail::obj_<t&>()))
                naked;
            typedef ::tools::detail_no_ref::no_ptr_<naked>
                no_ptr;
        public:
            typedef typename no_ptr::type
                type;
        };
    #else
        template<class t> struct remove_reference
            { typedef t type; };

        template<class t> struct remove_reference <t&>           
            { typedef t type; };

        #ifdef dHAS_RVALUE_REFERENCES
        // msvc2012 (or newer)
        template<class t> struct remove_reference <t&&>        
            { typedef t type; };
        #endif

    #endif

    #define dNO_REFERENCE_(t,x)              \
        typedef ::tools::remove_reference<t> \
            no_ref;                          \
        typedef typename no_ref::type x

} // namespace tools 
//==============================================================================
//==============================================================================
#endif // !dTOOLS_REMOVE_REFERENCE_USED_
