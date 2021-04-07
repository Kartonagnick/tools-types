// [2021y-04m-06d][21:36:00] Idrisov Denis R.
#pragma once
#ifndef dTOOLS_IS_DEREFERENCABLE_2012_USED_ 
#define dTOOLS_IS_DEREFERENCABLE_2012_USED_ 100,2012

#include <tools/features.hpp>
#include <type_traits>

//==============================================================================
//=== is_dereferencable ========================================================
namespace tools
{
    namespace detail
    {
        typedef char (&no )[1]; 
        typedef char (&yes)[2];

        template<class t> t maket();

        template<size_t n> struct sfinae
            { char v[n]; };

        template<> struct sfinae<0>
            { char v[2]; };

        template<class t> struct is_deref_ext_
        {
            __if_exists(t::operator*)
            {
                enum { value = true };
            }

            __if_not_exists(t::operator*) 
            {
                enum { value = false };
            }
        };

        template <class t, bool>  class is_deref_impl_
        {
            template <class u> static
                sfinae<sizeof(*maket<u>())> 
                check(u*);

            template<class> static 
                no check(...);

            enum { v = sizeof(check<t>(0)) };
        public:
            enum { value = v != sizeof(no) };
        };

        template <class t> class is_deref_impl_<t, false>
        {
        public:
            enum { value = false };
        };

        template <class t, bool> class is_deref_
        {
            typedef is_deref_ext_<t>
                check;
            enum { v = check::value };
            typedef is_deref_impl_<t, v> 
                result;
        public:
            enum { value = result::value };
        };

        template <class t> class is_deref_<t, false>
        {
            enum { v1 = ::std::is_pointer<t>::value };  
            enum { v2 = ::std::is_array<t>::value   };  
        public:
            enum { value = v1 || v2 };  
        };

        template <class t> class is_dereferencable_
        {
            typedef ::std::remove_reference<t>
                no_ref;
            typedef typename no_ref::type 
                x;
            enum { ok = ::std::is_class<x>::value  };
            typedef ::tools::detail::is_deref_<x, ok> 
                v;
        public:
            enum { value = v::value };
        };

    } // namespace detail

    template<class t> class is_dereferencable
        : dDETAIL_CONSTANT(is_dereferencable_<t>)
    {};

} // namespace tools 


#if 0
//==============================================================================
//=== is_dereferencable ========================================================
namespace tools 
{
    
    // warning C4200: нестандартное расширение: массив нулевого размера в структуре (объединении)
    // Невозможно создать конструктор копии или оператор присвоения копии, когда UDT содержит массив нулевого размера
    #pragma warning(disable : 4200)

    #if 0
        #define dCHECK_EXPRESSION(...) \
            decltype(__VA_ARGS__, ::std::true_type())

        template<class u> static dCHECK_EXPRESSION( 
            *::std::declval<u>()
        ) check(u*);

        #undef dCHECK_EXPRESSION
    #endif

    namespace detail
    {
        typedef char(&no )[1];
        typedef char(&yes)[2];

        template<size_t n> struct sfinae
            { char v[n]; };

        template <class t> t& val();

        template<class u, size_t n = sizeof(u) > struct pay
            { char v[n + 1]; };

        template <class u>
            pay<u> xxx(const u&);

        template<class u, size_t n = sizeof(xxx(*val<u&>())) > 
        struct help { typedef sfinae<n> type; };
       
        template<class t> class is_dereferencable_
        {
            typedef ::std::remove_reference<t> 
                no_ref;
            typedef typename no_ref::type 
                x;
            //template<class u> static  check(decltype(*val<u&>())*);

            template<class u> static 
            typename help<u>::type 
                check(u*);
                //check(typename help<u>::type*);

            template<class> static 
                no check(...);

            enum { v = sizeof(check<x>(0)) };
        public:
            enum { value = v == 0 || v != sizeof(no) };
        };

    } // namespace detail

    // if the syntax is valid: *obj ---> dereferencable 
    template<class t> struct is_dereferencable
        : dDETAIL_CONSTANT(is_dereferencable_<t>)
    {};

} // namespace tools 

#endif

//==============================================================================
//==============================================================================
#endif // !dTOOLS_IS_DEREFERENCABLE_2012_USED_
