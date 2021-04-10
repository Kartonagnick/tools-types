// [2021y-04m-05d][03:01:01] Idrisov Denis R. 100
// [2021y-04m-10d][07:18:56] Idrisov Denis R. 101
#pragma once
#ifndef dTOOLS_ARRAY_2013_USED_ 
#define dTOOLS_ARRAY_2013_USED_ 101,2013

#include <tools/pragma/pragma.hpp>
#include <tools/features.hpp>
#include <type_traits>
#include <cstddef>

//==============================================================================
//=== is_zero_array ============================================================
#ifndef dTOOLS_IS_ZERO_ARRAY_USED_ 
#define dTOOLS_IS_ZERO_ARRAY_USED_ 100,2013
namespace tools 
{
    #ifdef dHAS_ZERO_SIZE_ARRAY
        dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        template<class t> struct is_zero_array
            : ::std::false_type
        { using type = t; };


        template<class t> struct is_zero_array<t[0]>
            : ::std::true_type
        { using type = t; };

        dPRAGMA_POP
    #else

        template<class t> struct is_zero_array
            : ::std::false_type
        { using type = t; };

    #endif

} // namespace tools 
#endif // !dTOOLS_IS_ZERO_ARRAY_USED_


//==============================================================================
//=== size_array ========================================== (is_zero_array) ====
#ifndef dTOOLS_SIZE_ARRAY_USED_ 
#define dTOOLS_SIZE_ARRAY_USED_ 100,2013
namespace tools
{
    template<class t> struct size_array
    {
    private:
        using x = ::tools::is_zero_array<t>;
        using elem = typename x::type;
        enum { z = x::value };
    public:
        enum { valid = 0 };
        enum { value = 0 };
        enum { big   = 0 };
        enum { Small = 0 }; // fucking windows:  #define small char
        enum { empty = 0 };
        enum { zero  = z };
        using type = elem;
        using arr  = type;
        using ref  = type&;
        using rval = type&&;
    };
    template<class t, size_t N> struct size_array<t[N]>
    {
        enum { valid = 1        };
        enum { value = N        };
        enum { big   = N  > 255 };
        enum { Small = N <= 255 };
        enum { empty = 0        };
        enum { zero  = N == 0   };
        using type = t;
        using arr  = type[value];
        using ref  = type(&)[value];
        using rval = type(&&)[value];
    };
    template<class t> struct size_array<t[]>
    {
        enum { valid = 1 };
        enum { value = 0 };
        enum { big   = 0 };
        enum { Small = 0 }; 
        enum { empty = 1 };
        enum { zero  = 0 };
        using type = t;
        using arr  = type[];
        using ref  = type(&)[];
        using rval = type(&&)[];
    };

    #define dif_big_array(arr, ret)       \
        ::std::enable_if_t<               \
            ::tools::size_array<          \
                ::tools::degradate_t<arr> \
            >::big, ret                   \
        >

    #define dif_small_array(arr, ret)     \
        ::std::enable_if_t<               \
            ::tools::size_array<          \
                ::tools::degradate_t<arr> \
            >::Small, ret                 \
        >

    #define dfor_big_array(arr)         \
        dif_big_array(arr, void) * = nullptr

    #define dfor_small_array(arr)        \
        dif_small_array(arr, void) * = nullptr

} // namespace tools 
#endif // !dTOOLS_SIZE_ARRAY_USED_


//==============================================================================
//=== small_array ================================== (degradate)(size_array) ===
#ifndef dTOOLS_SMALL_ARRAY_USED_ 
#define dTOOLS_SMALL_ARRAY_USED_ 100,2013
namespace tools 
{
    template<class s1, class s2>
    class small_array_selector
    {
        using x  = ::std::remove_reference_t<s1>;
        using z  = ::std::remove_reference_t<s2>;
        using xx = ::tools::size_array<x>;
        using zz = ::tools::size_array<z>;

        enum { small1 = xx::Small && xx::valid };
        enum { small2 = zz::Small && zz::valid };
    public:
        enum { value = small1 && small2 };
    };

    template<class arr1, class arr2, class ret = void>
    using for_big_arrays_t 
        = ::std::enable_if_t< 
            !::tools::small_array_selector<arr1, arr2>::value,
            ret
        >;

    template<class arr1, class arr2, class ret = void>
    using for_small_arrays_t 
        = ::std::enable_if_t<
            ::tools::small_array_selector<arr1, arr2>::value, 
            ret
        >;

    #define dif_big_arrays(arr1, arr2, ret) \
        ::tools::for_big_arrays_t<arr1, arr2, ret>

    #define dif_small_arrays(arr1, arr2, ret) \
        ::tools::for_small_arrays_t<arr1, arr2, ret>

    #define dfor_big_arrays(arr1, arr2) \
        ::tools::for_big_arrays_t<arr1, arr2>* = nullptr

    #define dfor_small_arrays(arr1, arr2) \
        ::tools::for_small_arrays_t<arr1, arr2>* = nullptr

} // namespace tools 
#endif // !dTOOLS_SMALL_ARRAY_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_ARRAY_2013_USED_
