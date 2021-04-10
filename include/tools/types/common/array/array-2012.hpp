// [2021y-04m-05d][03:01:01] Idrisov Denis R. 100 PRE
// [2021y-04m-10d][03:34:51] Idrisov Denis R. 101 PRE
#pragma once
#ifndef dTOOLS_ARRAY_2012_USED_ 
#define dTOOLS_ARRAY_2012_USED_ 101,2012

#include <tools/pragma/pragma.hpp>
#include <tools/features.hpp>
#include <type_traits>
#include <cstddef>

//==============================================================================
//===[true_type/false_type]=====================================================
namespace std
{
    typedef integral_constant<bool, true>
        true_type;

    typedef integral_constant<bool, false>
        false_type;

} // namespace std

//==============================================================================
//=== is_zero_array ============================================================
#ifndef dTOOLS_IS_ZERO_ARRAY_USED_ 
#define dTOOLS_IS_ZERO_ARRAY_USED_ 100,2012
namespace tools 
{
    #ifdef dHAS_ZERO_SIZE_ARRAY
        dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        template<class t> struct is_zero_array
            : ::std::false_type
        { typedef t type; };


        template<class t> struct is_zero_array<t[0]>
            : ::std::true_type
        { typedef t type; };

        dPRAGMA_POP
    #else

        template<class t> struct is_zero_array
            : ::std::false_type
        { typedef t type; };

    #endif

} // namespace tools 
#endif // !dTOOLS_IS_ZERO_ARRAY_USED_


//==============================================================================
//=== size_array ========================================== (is_zero_array) ====
#ifndef dTOOLS_SIZE_ARRAY_USED_ 
#define dTOOLS_SIZE_ARRAY_USED_ 100,2012
namespace tools
{
    template<class t> struct size_array
    {
    private:
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
        typedef type&& rval;
    };

    template<class t, size_t N> struct size_array<t[N]>
    {
        enum { valid = 1        };
        enum { value = N        };
        enum { big   = N  > 255 };
        enum { Small = N <= 255 };
        enum { empty = 0        };
        enum { zero  = N == 0   };
        typedef t type;
        typedef type arr[value];
        typedef type(&ref)[value];
        typedef type(&&rval)[value];
    };

    template<class t> struct size_array<t[]>
    {
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
        typedef type(&&rval)[];
        #endif
    };

    #define dif_big_array(arr, ret)                         \
        typename ::std::enable_if<                          \
            ::tools::size_array<                            \
                typename ::std::remove_reference<arr>::type \
            >::big, ret                                     \
        >::type

    #define dif_small_array(arr, ret)                       \
        typename ::std::enable_if<                          \
            ::tools::size_array<                            \
                typename ::std::remove_reference<arr>::type \
            >::Small, ret                                   \
        >::type

    #define dfor_big_array(arr)         \
        dif_big_array(arr, void) * = nullptr

    #define dfor_small_array(arr)        \
        dif_small_array(arr, void) * = nullptr

} // namespace tools 
#endif // !dTOOLS_SIZE_ARRAY_USED_


//==============================================================================
//=== small_array ================================== (degradate)(size_array) ===
#ifndef dTOOLS_SMALL_ARRAY_USED_ 
#define dTOOLS_SMALL_ARRAY_USED_ 100,2012
namespace tools 
{
    template<class s1, class s2>
    class small_array_selector
    {
        typedef ::std::remove_reference<s1> 
            no_ref1;
        typedef std::remove_reference<s2> 
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

    #define dif_big_arrays(a, b, ret)                    \
        typename dTRAIT::enable_if<                      \
            !::tools::small_array_selector<a, b>::value, \
            ret                                          \
        >::type 

    #define dif_small_arrays(a, b, ret)                  \
        typename dTRAIT::enable_if<                      \
            ::tools::small_array_selector<a, b>::value,  \
            ret                                          \
        >::type 

} // namespace tools 
#endif // !dTOOLS_SMALL_ARRAY_USED_


//==============================================================================
//==============================================================================
#endif // !dTOOLS_ARRAY_2012_USED_
