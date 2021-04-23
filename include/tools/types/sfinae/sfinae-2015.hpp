// [2021y-04m-23d][13:44:02] Idrisov Denis R. 100 PRE
#pragma once
#ifndef dTOOLS_SFINAE_2015_USED_ 
#define dTOOLS_SFINAE_2015_USED_ 100 PRE

#include <type_traits>

//==============================================================================
//=== is_lambda ================================================================
#ifndef dTOOLS_IS_LAMBDA_USED_ 
#define dTOOLS_IS_LAMBDA_USED_ 1
namespace tools
{
    namespace detail
    {
        template<class, class = void>
        struct is_lambda_ : ::std::false_type {};
 
        template<class F> struct is_lambda_<F, 
            ::std::void_t<decltype(&F::operator())> >
            : ::std::true_type
        {};

    } // namespace detail

    template<class F> class is_lambda
        : dDETAIL_CONSTANT(is_lambda_< ::std::remove_reference_t<F> >)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_LAMBDA_USED_

//==============================================================================
//=== is_dereferencable ========================================================
#ifndef dTOOLS_IS_DEREFERENCABLE_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct is_dereferencable : ::std::false_type {};
 
    template<class t> struct is_dereferencable<t, 
        ::std::void_t<decltype(*::std::declval<t>())> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_IS_DEREFERENCABLE_USED_

//==============================================================================
//=== is_prefix_incrementable ==================================================
#ifndef dTOOLS_IS_PREFIX_INCREMENTABLE_USED_ 
#define dTOOLS_IS_PREFIX_INCREMENTABLE_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct is_prefix_incrementable : ::std::false_type {};
 
    template<class t> struct is_prefix_incrementable<t, 
        ::std::void_t<decltype(++::std::declval<t&>())> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_IS_PREFIX_INCREMENTABLE_USED_

//==============================================================================
//=== is_postfix_incrementable =================================================
#ifndef dTOOLS_IS_POSTFIX_INCREMENTABLE_USED_ 
#define dTOOLS_IS_POSTFIX_INCREMENTABLE_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct is_postfix_incrementable : ::std::false_type {};
 
    template<class t> struct is_postfix_incrementable<t, 
        ::std::void_t<decltype(::std::declval<t&>()++)> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_IS_POSTFIX_INCREMENTABLE_USED_

//==============================================================================
//=== is_incrementable =========================================================
#ifndef dTOOLS_IS_INCREMENTABLE_USED_ 
#define dTOOLS_IS_INCREMENTABLE_USED_ 1
namespace tools 
{
    template<class t> struct is_incrementable
        : ::std::integral_constant<bool, 
        ::tools::is_postfix_incrementable<t>::value || 
        ::tools::is_prefix_incrementable<t>::value>
    {};

} // namespace tools
#endif // !dTOOLS_IS_INCREMENTABLE_USED_

//==============================================================================
//=== is_prefix_decrementable ==================================================
#ifndef dTOOLS_IS_PREFIX_DECREMENTABLE_USED_ 
#define dTOOLS_IS_PREFIX_DECREMENTABLE_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct is_prefix_decrementable : ::std::false_type {};
 
    template<class t> struct is_prefix_decrementable<t, 
        ::std::void_t<decltype(--::std::declval<t&>())> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_IS_PREFIX_DECREMENTABLE_USED_

//==============================================================================
//=== is_postfix_decrementable =================================================
#ifndef dTOOLS_IS_POSTFIX_DECREMENTABLE_USED_ 
#define dTOOLS_IS_POSTFIX_DECREMENTABLE_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct is_postfix_decrementable : ::std::false_type {};
 
    template<class t> struct is_postfix_decrementable<t, 
        ::std::void_t<decltype(::std::declval<t&>()--)> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_IS_POSTFIX_DECREMENTABLE_USED_

//==============================================================================
//=== is_decrementable =========================================================
#ifndef dTOOLS_IS_DECREMENTABLE_USED_ 
#define dTOOLS_IS_DECREMENTABLE_USED_ 1
namespace tools 
{
    template<class t> struct is_decrementable
        : ::std::integral_constant<bool, 
        ::tools::is_postfix_decrementable<t>::value || 
        ::tools::is_prefix_decrementable<t>::value>
    {};

} // namespace tools
#endif // !dTOOLS_IS_DECREMENTABLE_USED_

//==============================================================================
//=== is_iterable ==============================================================
#ifndef dTOOLS_IS_ITERABLE_USED_ 
#define dTOOLS_IS_ITERABLE_USED_ 1
namespace tools
{
    template<class t> struct is_iterable
        : ::std::integral_constant<bool, 
        ::tools::is_dereferencable<t>::value &&
        ::tools::is_incrementable<t>::value>
    {};

} // namespace tools 
#endif // !dTOOLS_IS_ITERABLE_USED_

//==============================================================================
//=== is_iterator ==============================================================
#ifndef dTOOLS_IS_ITERATOR_USED_ 
#define dTOOLS_IS_ITERATOR_USED_ 1
namespace tools
{
    namespace detail
    {
        template<class, class = void>
        struct is_iter_ : ::std::false_type {};
 
        template<class t> struct is_iter_<t, 
            ::std::void_t<
                typename t::iterator_category,
                typename t::value_type,       
                typename t::difference_type,  
                typename t::pointer,          
                typename t::reference         
            >
        > : ::std::true_type {};

        template<class t> struct is_iterator_
            : ::std::integral_constant<bool, 
            ::std::is_pointer<t>::value ||
            ::tools::detail::is_iter_<t>::value
        > {};
        
    } // namespace detail

    // pointer* ------------------> true
    // std-compatible iterator ---> true
    template<class t> class is_iterator
        : dDETAIL_CONSTANT(is_iterator_< ::std::remove_reference_t<t> >)
    {};

} // namespace tools 
#endif // !dTOOLS_IS_ITERATOR_USED_

//==============================================================================
//=== has_value_type ===========================================================
#ifndef dTOOLS_HAS_VALUE_TYPE_USED_ 
#define dTOOLS_HAS_VALUE_TYPE_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct has_value_type : ::std::false_type {};
 
    template<class t> struct has_value_type<t, 
        ::std::void_t<typename t::value_type> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_HAS_VALUE_TYPE_USED_

//==============================================================================
//=== has_mapped_type ==========================================================
#ifndef dTOOLS_HAS_MAPPED_TYPE_USED_ 
#define dTOOLS_HAS_MAPPED_TYPE_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct has_mapped_type : ::std::false_type {};
 
    template<class t> struct has_mapped_type<t, 
        ::std::void_t<typename t::mapped_type> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_HAS_MAPPED_TYPE_USED_

//==============================================================================
//=== has_begin ================================================================
#ifndef dTOOLS_HAS_BEGIN_USED_ 
#define dTOOLS_HAS_BEGIN_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct has_begin : ::std::false_type {};
 
    template<class t> struct has_begin<t, 
        ::std::void_t<decltype(::std::declval<t>().begin())> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_HAS_BEGIN_USED_

//==============================================================================
//=== has_end ==================================================================
#ifndef dTOOLS_HAS_END_USED_ 
#define dTOOLS_HAS_END_USED_ 1
namespace tools 
{
    template<class, class = void>
    struct has_end : ::std::false_type {};
 
    template<class t> struct has_end<t, 
        ::std::void_t<decltype(::std::declval<t>().end())> >
        : ::std::true_type
    {};

} // namespace tools
#endif // !dTOOLS_HAS_END_USED_

//==============================================================================
//=== has_operator_access ======================================================
#ifndef dTOOLS_HAS_OPERATOR_ACCESS_USED_ 
#define dTOOLS_HAS_OPERATOR_ACCESS_USED_ 1
namespace tools 
{
    template<class, class = size_t, class = void>
    struct has_operator_access : ::std::false_type {};
 
    template<class t, class i> 
    struct has_operator_access<t, i,
        ::std::void_t<
            decltype(::std::declval<t>()[::std::declval<i>()])
        >
    > : ::std::true_type {};

    template<class t> 
    struct has_operator_access<t, size_t,
        ::std::void_t<
            decltype(::std::declval<t>()[0u])
        >
    > : ::std::true_type {};

} // namespace tools
#endif // !dTOOLS_HAS_OPERATOR_ACCESS_USED_

//==============================================================================
//==============================================================================
#endif // !dTOOLS_SFINAE_2015_USED_
