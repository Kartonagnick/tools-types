// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2021y-04m-08d][03:04:34] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_CONST_DATA_2013_USED_ 
#define dTOOLS_IS_CONST_DATA_2013_USED_ 100,2013

#include <tools/types/common/is_dereferencable.hpp>

//==============================================================================
//=== is_volatile_data =========================================================
namespace tools
{
    namespace detail
    {
        template<class t, bool> struct is_const_data_impl_
        {
        private:
            using y = decltype(*::std::declval<t>());
            using x = ::std::remove_reference_t<y>;
            using z = ::std::remove_pointer_t<x>;
        public:
            enum { value = ::std::is_const<z>::value };
        };

        template<class t> 
        struct is_const_data_impl_<t, false>
            { enum { value = false }; };

        template<class t> class is_const_data_
        {
            using x = ::std::remove_reference_t<t>;
            using z = ::std::remove_pointer_t<x>;
            using d = ::tools::is_dereferencable<x>;
            using c = ::std::is_const<z>;
            
            enum { ok = d::value };
            using h
                = ::tools::detail::is_const_data_impl_<x, ok>;

            enum { top = !ok && c::value };
            enum { dwn =  ok && h::value };
        public:
            enum { value = top || dwn };
        };

    } // namespace detail

    template<class t> struct is_const_data
        : dDETAIL_CONSTANT(is_const_data_<t>)
    {};

    template<class t, class v = void> 
    using for_const_data 
        = ::std::enable_if_t< ::tools::is_const_data<t>::value, v>;

    template<class t, class v = void> 
    using for_not_const_data 
        = ::std::enable_if_t< !::tools::is_const_data<t>::value, v>;

    #define dif_const_data(s, r) \
        ::tools::for_const_data<s, r>

    #define dif_not_const_data(s, r) \
        ::tools::for_not_const_data<s, r>

    #define dfor_const_data(s) \
        dif_const_data(s, void)* = nullptr

    #define dfor_not_const_data(s) \
        dif_not_const_data(s, void)* = nullptr

} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_CONST_DATA_2013_USED_
