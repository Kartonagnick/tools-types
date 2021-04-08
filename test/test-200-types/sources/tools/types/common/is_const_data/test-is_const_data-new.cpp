// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-23d][22:22:01] Idrisov Denis R.
// [2021y-04m-08d][03:09:44] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_CONST_DATA

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_const_data
#define dTEST_TAG new

#include <tools/types/common.hpp>
#include <string>

namespace me = ::tools;
//==============================================================================
//=== make_test ================================================================
namespace
{
    #define dexpression(type, expected) \
        me::is_const_data<type>::value == expected

    #define make_test(type, expected)                  \
        static_assert(                                 \
            dexpression(type, expected),               \
            "tools::is_const_data<" #type ">::value "  \
            "must be '" #expected "'"                  \
        )

    template<class s, dfor_const_data(s)>
    constexpr bool new_consept(s&&) noexcept { return true; }

    template<class s, dfor_not_const_data(s)>
    constexpr bool new_consept(s&&) noexcept { return false; }

    template<class s>
    constexpr dif_const_data(s, bool)
    old_consept(s&&) noexcept { return true; }

    template<class s>
    constexpr dif_not_const_data(s, bool)
    old_consept(s&&) noexcept { return false; }

    char arr[] = "";
    const char carr[] = "";

    static_assert(!new_consept(arr), "bug");
    static_assert(new_consept(carr), "bug");

    static_assert(!old_consept(arr), "bug");
    static_assert(old_consept(carr), "bug");
    
} // namespace

//==============================================================================
//=== false ====================================================================
namespace
{
    //       |   type                      | expected |
    make_test(char                         ,   false  );
    make_test(char&                        ,   false  );
    make_test(char(&)[1]                   ,   false  );
    make_test(char(*)[1]                   ,   false  );
//------------------------------------------------------------------------------
    make_test(const char                   ,   true   );
    make_test(const char&                  ,   true   );
    make_test(const char(&)[1]             ,   true   );
    make_test(const char(*)[1]             ,   true   );
//------------------------------------------------------------------------------
    make_test(char*                        ,   false  );
    make_test(char* const                  ,   false  );
    make_test(char* volatile               ,   false  );
    make_test(char* volatile const         ,   false  );
//------------------------------------------------------------------------------
    make_test(const char*                  ,   true   );
    make_test(const char* const            ,   true   );
    make_test(const char* volatile         ,   true   );
    make_test(const char* volatile const   ,   true   );
//------------------------------------------------------------------------------
    make_test(char*&                       ,   false  );
    make_test(char* const&                 ,   false  );
    make_test(char* volatile&              ,   false  );
    make_test(char* volatile const&        ,   false  );
//------------------------------------------------------------------------------
    make_test(const char*&                 ,   true   );
    make_test(const char* const&           ,   true   );
    make_test(const char* volatile&        ,   true   );
    make_test(const char* volatile const&  ,   true   );
//------------------------------------------------------------------------------
    make_test(char*&&                      ,   false  );
    make_test(char* const&&                ,   false  );
    make_test(char* volatile&&             ,   false  );
    make_test(char* volatile const&&       ,   false  );
//------------------------------------------------------------------------------
    make_test(const char*&&                ,   true   );
    make_test(const char* const&&          ,   true   );
    make_test(const char* volatile&&       ,   true   );
    make_test(const char* volatile const&& ,   true   );
    
}//namespace

//==============================================================================
//=== true =====================================================================
namespace
{
    //       |   type                               | expected |
    make_test(volatile char                         ,  false   );
    make_test(volatile char&                        ,  false   );
    make_test(volatile char(&)[1]                   ,  false   );
    make_test(volatile char(*)[1]                   ,  false   );
//------------------------------------------------------------------------------
    make_test(volatile const char                   ,   true   );
    make_test(volatile const char&                  ,   true   );
    make_test(volatile const char(&)[1]             ,   true   );
    make_test(volatile const char(*)[1]             ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile char*                        ,  false   );
    make_test(volatile char* const                  ,  false   );
    make_test(volatile char* volatile               ,  false   );
    make_test(volatile char* volatile const         ,  false   );
//------------------------------------------------------------------------------
    make_test(volatile const char*                  ,   true   );
    make_test(volatile const char* const            ,   true   );
    make_test(volatile const char* volatile         ,   true   );
    make_test(volatile const char* volatile const   ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile char*&                       ,  false   );
    make_test(volatile char* const&                 ,  false   );
    make_test(volatile char* volatile&              ,  false   );
    make_test(volatile char* volatile const&        ,  false   );
//------------------------------------------------------------------------------
    make_test(volatile const char*&                 ,   true   );
    make_test(volatile const char* const&           ,   true   );
    make_test(volatile const char* volatile&        ,   true   );
    make_test(volatile const char* volatile const&  ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile char*&&                      ,  false   );
    make_test(volatile char* const&&                ,  false   );
    make_test(volatile char* volatile&&             ,  false   );
    make_test(volatile char* volatile const&&       ,  false   );
//------------------------------------------------------------------------------
    make_test(volatile const char*&&                ,   true   );
    make_test(volatile const char* const&&          ,   true   );
    make_test(volatile const char* volatile&&       ,   true   );
    make_test(volatile const char* volatile const&& ,   true   );
    
}//namespace

//==============================================================================
//==============================================================================
#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_IS_CONST_DATA

