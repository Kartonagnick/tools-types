// [2021y-04m-05d][03:01:01] Idrisov Denis R. 100
// [2021y-04m-10d][07:18:56] Idrisov Denis R. 101

// [2021y-04m-21d][12:46:01] Idrisov Denis R. 102 PRE
#pragma once
#ifndef dTOOLS_ARRAY_2008_USED_ 
#define dTOOLS_ARRAY_2008_USED_ 102,2008

#include <tools/pragma/pragma.hpp>
#include <tools/type_traits.hpp>
#include <cstddef>

//==============================================================================
//=== is_zero_array ============================================================
#ifndef dTOOLS_IS_ZERO_ARRAY_USED_ 
#define dTOOLS_IS_ZERO_ARRAY_USED_ 100,2008
namespace tools 
{
    #ifdef dHAS_ZERO_SIZE_ARRAY
        dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        template<class t> struct is_zero_array
            : dTRAIT::false_type
        { typedef t type; };

        template<class t> struct is_zero_array<s[0]>
            : dTRAIT::true_type
        { typedef t type; };

        dPRAGMA_POP
    #else

        template<class t> struct is_zero_array
            : dTRAIT::false_type
        { typedef t type; };

    #endif

} // namespace tools 
#endif // !dTOOLS_IS_ZERO_ARRAY_USED_


//==============================================================================
//=== size_array ========================================== (is_zero_array) ====
#ifndef dTOOLS_SIZE_ARRAY_USED_ 
#define dTOOLS_SIZE_ARRAY_USED_ 100,2008
namespace tools
{
    template<class t> class size_array
    {
        typedef ::tools::is_zero_array<t> x;
        typedef typename x::type elem;
        enum { z = x::value };
    public:
        enum { valid = 0 };
        enum { value = 0 };
        enum { big   = 0 };
        enum { Small = 0 }; // fucking windows:  #define small char
        enum { empty = 0 };
        enum { zero  = z };

        typedef elem  type;
        typedef type   arr;
        typedef type&  ref;
        #ifdef dHAS_RVALUE_REFERENCE
        typedef type&& rval;
        #endif
    };

    template<class t, size_t N> class size_array<t[N]>
    {
    public:
        enum { valid = 1        };
        enum { value = N        };
        enum { big   = N  > 255 };
        enum { Small = N <= 255 };
        enum { empty = 0        };
        enum { zero  = N == 0   };
        
        typedef t type;
        typedef type arr[value];
        typedef type(&ref)[value];
        #ifdef dHAS_RVALUE_REFERENCE
        typedef type(&&rval)[value];
        #endif
    };

    template<class t> class size_array<t[]>
    {
    public:
        enum { valid = 1 };
        enum { value = 0 };
        enum { big   = 0 };
        enum { Small = 0 };
        enum { empty = 1 };
        enum { zero  = 0 };

        typedef t type;
        typedef type arr[];

        #ifdef dHAS_ARRAY_EMPTY_SIZE
            typedef type(&ref)[];
            #ifdef dHAS_RVALUE_REFERENCE
                typedef type(&&rval)[];
            #endif
        #endif
    };

    #define dif_big_array(arr, ret)                          \
        typename dTRAIT::enable_if<                          \
            ::tools::size_array<                             \
                typename dTRAIT::remove_reference<arr>::type \
            >::big, ret                                      \
        >::type

    #define dif_small_array(arr, ret)                        \
        typename dTRAIT::enable_if<                          \
            ::tools::size_array<                             \
                typename dTRAIT::remove_reference<arr>::type \
            >::Small, ret                                    \
        >::type

} // namespace tools 
#endif // !dTOOLS_SIZE_ARRAY_USED_


//==============================================================================
//=== small_array =================================(degradate)(size_array) =====
#ifndef dTOOLS_SMALL_ARRAY_USED_ 
#define dTOOLS_SMALL_ARRAY_USED_ 101,2008
namespace tools 
{
    template<class s1, class s2>
    class small_array_selector_
    {
        typedef dTRAIT::remove_reference<s1> 
            no_ref1;
        typedef dTRAIT::remove_reference<s2> 
            no_ref2;

        typedef typename no_ref1::type x;
        typedef typename no_ref2::type z;

        typedef ::tools::size_array<x> xx;
        typedef ::tools::size_array<z> zz;

        enum { small1 = xx::Small && xx::valid };
        enum { small2 = zz::Small && zz::valid };
    public:
        enum { value = small1 && small2 };
    };

    #define dif_big_arrays(a, b, ret)                     \
        typename dTRAIT::enable_if<                       \
            !::tools::small_array_selector_<a, b>::value, \
            ret                                           \
        >::type 

    #define dif_small_arrays(a, b, ret)                   \
        typename dTRAIT::enable_if<                       \
            ::tools::small_array_selector_<a, b>::value,  \
            ret                                           \
        >::type 

} // namespace tools 
#endif // !dTOOLS_SMALL_ARRAY_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_ARRAY_2008_USED_
