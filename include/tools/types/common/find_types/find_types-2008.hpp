// [2021y-04m-06d][15:45:19] Idrisov Denis R. 106
#pragma once
#ifndef dTOOLS_FIND_TYPES_2008_USED_ 
#define dTOOLS_FIND_TYPES_2008_USED_ 100, 2008

#include <tools/type_traits.hpp>

#define dVARIADIC_7 \
    class t1, class t2 = empty, class t3 = empty, class t4 = empty, \
    class t5 = empty, class t6 = empty, class t7  = empty

//==============================================================================
//=== find_type ================================================================
#ifndef dTOOLS_FIND_TYPE_USED_ 
#define dTOOLS_FIND_TYPE_USED_ 100,2008
namespace tools
{
    struct empty;

    // if type 't' is in the list 'args' --> true
    namespace detail
    {
        template<class t1, class t2, class t3, class t4, class t5, class t6, class t7> 
        struct find_type_
        {
            enum { r2 = dTRAIT::is_same<t1, t2>::value };
            enum { r3 = dTRAIT::is_same<t1, t3>::value };
            enum { r4 = dTRAIT::is_same<t1, t4>::value };
            enum { r5 = dTRAIT::is_same<t1, t5>::value };
            enum { r6 = dTRAIT::is_same<t1, t6>::value };
            enum { r7 = dTRAIT::is_same<t1, t7>::value };
            enum { value = r2 || r3 || r4 || r5 || r6 || r7 };
        };

        template<class t1, class t2, class t3, class t4, class t5, class t6> 
        struct find_type_<t1, t2, t3, t4, t5, t6, empty>
        {
            enum { r2 = dTRAIT::is_same<t1, t2>::value };
            enum { r3 = dTRAIT::is_same<t1, t3>::value };
            enum { r4 = dTRAIT::is_same<t1, t4>::value };
            enum { r5 = dTRAIT::is_same<t1, t5>::value };
            enum { r6 = dTRAIT::is_same<t1, t6>::value };
            enum { value = r2 || r3 || r4 || r5 || r6 };
        };

        template<class t1, class t2, class t3, class t4, class t5> 
        struct find_type_<t1, t2, t3, t4, t5, empty, empty>
        {
            enum { r2 = dTRAIT::is_same<t1, t2>::value };
            enum { r3 = dTRAIT::is_same<t1, t3>::value };
            enum { r4 = dTRAIT::is_same<t1, t4>::value };
            enum { r5 = dTRAIT::is_same<t1, t5>::value };
            enum { value = r2 || r3 || r4 || r5 };
        };

        template<class t1, class t2, class t3, class t4> 
        struct find_type_<t1, t2, t3, t4, empty, empty, empty>
        {
            enum { r2 = dTRAIT::is_same<t1, t2>::value };
            enum { r3 = dTRAIT::is_same<t1, t3>::value };
            enum { r4 = dTRAIT::is_same<t1, t4>::value };
            enum { value = r2 || r3 || r4 };
        };

        template<class t1, class t2, class t3> 
        struct find_type_<t1, t2, t3, empty, empty, empty, empty>
        {
            enum { r2 = dTRAIT::is_same<t1, t2>::value };
            enum { r3 = dTRAIT::is_same<t1, t3>::value };
            enum { value = r2 || r3 };
        };

        template<class t1, class t2> 
        struct find_type_<t1, t2, empty, empty, empty, empty, empty>
        {
            enum { value = dTRAIT::is_same<t1, t2>::value };
        };

        template<class t1> 
        struct find_type_<t1, empty, empty, empty, empty, empty, empty>
        {
            enum { value = false };
        };

    } // namespace detail

    // if type 't' is in the list 'args' --> true
    template<dVARIADIC_7>
    struct find_type
        : dDETAIL_CONSTANT(find_type_<t1, t2, t3, t4, t5, t6, t7>)
    {};

} // namespace tools 
#endif // !dTOOLS_FIND_TYPE_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_FIND_TYPES_2008_USED_
