// [2021y-04m-13d][01:53:52] Idrisov Denis R. 100
#pragma once
#ifndef dTOOLS_HAS_END_2013_USED_ 
#define dTOOLS_HAS_END_2013_USED_ 100,2013

#include <tools/type_traits.hpp>

//==============================================================================
//=== has_end ==================================================================
namespace tools
{
    namespace detail
    {
        template<class t> t val();

        template<class t, bool>
        struct has_end_impl_
        {
            template<class u> static ::std::true_type
                check(
                    typename ::std::add_pointer< 
                        decltype(val<u&>().end())
                    >::type 
                );

            template<class> static ::std::false_type
                check(...);

            using checked
                = decltype(check<t>(nullptr));

            enum { value = checked::value };
        };

        template <class t> 
        struct has_end_impl_<t, false>
        { 
            enum { value = false }; 
        };

        template <class t> 
        struct has_end_
        {
            using x = ::std::remove_reference_t<t>;
            enum { ok = ::std::is_class<x>::value };
            using v 
                = ::tools::detail::has_end_impl_<x, ok>;
        
            enum { value = v::value };
        };

    } // namespace detail

    template<class t> 
    class has_end
        : dDETAIL_CONSTANT(has_end_<t>)
    {};

} // namespace tools 

//==============================================================================
//==============================================================================
#endif // !dTOOLS_HAS_END_2013_USED_
