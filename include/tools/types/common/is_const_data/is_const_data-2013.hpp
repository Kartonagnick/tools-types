// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2021y-04m-08d][03:04:34] Idrisov Denis R.
// [2021y-04m-10d][07:21:07] Idrisov Denis R. 101

// [2021y-04m-21d][13:08:54] Idrisov Denis R. 102 PRE
#pragma once
#ifndef dTOOLS_IS_CONST_DATA_2013_USED_ 
#define dTOOLS_IS_CONST_DATA_2013_USED_ 102,2013

#include <tools/types/sfinae.hpp>

//==============================================================================
//=== is_volatile_data =========================================================
namespace tools
{
    namespace detail
    {
        template<class t, bool> class is_const_smart_
        {
            using y = decltype(*::std::declval<t>());
            using x = ::std::remove_reference_t<y>;
            using c = ::std::is_const<x>;
        public:
            enum { value = c::value };
        };

        template<class t> class is_const_smart_<t, false>
        {
            using c = ::std::is_const<t>;
        public:
            enum { value = c::value };
        };

        template<class t, bool> class is_const_data_impl_
        {
            using d = ::tools::is_dereferencable<t>;
            enum { ok = d::value };
            using result
                = ::tools::detail::is_const_smart_<t, ok>;
        public:
            enum { value = result::value };
        };

        template<class t> class is_const_data_impl_<t, false>
        {
            using x = ::std::remove_reference_t<t>;
            using z = ::std::remove_pointer_t<x>;
            using c = ::std::is_const<z>;
        public:
            enum { value = c::value };  
        };

        template <class t> class is_const_data_
        {
            using x = ::std::remove_reference_t<t>;
            enum { ok = ::std::is_class<x>::value };
            using result 
                = ::tools::detail::is_const_data_impl_<x, ok>;
        public:
            enum { value = result::value };
        };

    } // namespace detail

    template<class t> struct is_const_data
        : dDETAIL_CONSTANT(is_const_data_<t>)
    {};

    template<class t, class v = void> 
    using for_const_data_t 
        = ::std::enable_if_t< 
            ::tools::is_const_data<t>::value, v
        >;

    template<class t, class v = void> 
    using for_not_const_data_t 
        = ::std::enable_if_t< 
            !::tools::is_const_data<t>::value, v
        >;

    #define dif_const_data(s, r) \
        ::tools::for_const_data_t<s, r>

    #define dif_not_const_data(s, r) \
        ::tools::for_not_const_data_t<s, r>

    #define dfor_const_data(s) \
        dif_const_data(s, void)* = nullptr

    #define dfor_not_const_data(s) \
        dif_not_const_data(s, void)* = nullptr

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_CONST_DATA_2013_USED_
