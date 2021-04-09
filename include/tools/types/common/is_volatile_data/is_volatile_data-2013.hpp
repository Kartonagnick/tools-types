// [2021y-04m-06d][20:56:12] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_VOLATILE_DATA_2015_USED_ 
#define dTOOLS_IS_VOLATILE_DATA_2015_USED_ 100,2013

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_volatile_data =========================================================
namespace tools
{
    namespace detail
    {
        template<class t, bool> struct is_volatile_data_impl_
        {
        private:
            using y = decltype(*::std::declval<t>());
            using x = ::std::remove_reference_t<y>;
            //using z = ::std::remove_pointer_t<x>;
        public:
            enum { value = ::std::is_volatile<x>::value };
        };

        template<class t> 
        struct is_volatile_data_impl_<t, false>
            { enum { value = false }; };

        template<class t> class is_volatile_data_
        {
            using x = ::std::remove_reference_t<t>;
            using z = ::std::remove_pointer_t<x>;
            using d = ::tools::is_dereferencable<x>;
            using c = ::std::is_volatile<z>;
            
            enum { ok = d::value };
            using h
                = ::tools::detail::is_volatile_data_impl_<x, ok>;

            enum { top = !ok && c::value };
            enum { dwn =  ok && h::value };
        public:
            enum { value = top || dwn };
        };

    } // namespace detail

    template<class t> struct is_volatile_data
        : dDETAIL_CONSTANT(is_volatile_data_<t>)
    {};

    template<class t, class v = void> 
    using for_volatile_data 
        = ::std::enable_if_t< ::tools::is_volatile_data<t>::value, v>;

    template<class t, class v = void> 
    using for_not_volatile_data 
        = ::std::enable_if_t< !::tools::is_volatile_data<t>::value, v>;

    #define dif_volatile_data(s, r) \
        ::tools::for_volatile_data<s, r>

    #define dif_not_volatile_data(s, r) \
        ::tools::for_not_volatile_data<s, r>

    #define dfor_volatile_data(s) \
        dif_volatile_data(s, void)* = nullptr

    #define dfor_not_volatile_data(s) \
        dif_not_volatile_data(s, void)* = nullptr

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_VOLATILE_DATA_2015_USED_
