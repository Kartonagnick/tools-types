// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-23d][22:22:01] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_VOLATILE_DATA

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_volatile_data
#define dTEST_TAG new

#include <tools/types/common.hpp>
#include <string>

namespace me = ::tools;
//==============================================================================
//=== make_test ================================================================
namespace
{
    #define dexpression(type, expected) \
        me::is_volatile_data<type>::value == expected

    #define make_test(type, expected)                     \
        static_assert(                                    \
            dexpression(type, expected),                  \
            "tools::is_volatile_data<" #type ">::value "  \
            "must be '" #expected "'"                     \
        )

    template<class s, dfor_volatile_data(s)>
    constexpr bool new_consept(s&&) noexcept { return true; }

    template<class s, dfor_not_volatile_data(s)>
    constexpr bool new_consept(s&&) noexcept { return false; }

    template<class s>
    constexpr dif_volatile_data(s, bool)
    old_consept(s&&) noexcept { return true; }

    template<class s>
    constexpr dif_not_volatile_data(s, bool)
    old_consept(s&&) noexcept { return false; }

    char arr[] = "";
    volatile char carr[] = "";

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
    make_test(const char                   ,   false  );
    make_test(const char&                  ,   false  );
    make_test(const char(&)[1]             ,   false  );
    make_test(const char(*)[1]             ,   false  );
//------------------------------------------------------------------------------
    make_test(char*                        ,   false  );
    make_test(char* const                  ,   false  );
    make_test(char* volatile               ,   false  );
    make_test(char* volatile const         ,   false  );
//------------------------------------------------------------------------------
    make_test(const char*                  ,   false  );
    make_test(const char* const            ,   false  );
    make_test(const char* volatile         ,   false  );
    make_test(const char* volatile const   ,   false  );
//------------------------------------------------------------------------------
    make_test(char*&                       ,   false  );
    make_test(char* const&                 ,   false  );
    make_test(char* volatile&              ,   false  );
    make_test(char* volatile const&        ,   false  );
//------------------------------------------------------------------------------
    make_test(const char*&                 ,   false  );
    make_test(const char* const&           ,   false  );
    make_test(const char* volatile&        ,   false  );
    make_test(const char* volatile const&  ,   false  );
//------------------------------------------------------------------------------
    make_test(char*&&                      ,   false  );
    make_test(char* const&&                ,   false  );
    make_test(char* volatile&&             ,   false  );
    make_test(char* volatile const&&       ,   false  );
//------------------------------------------------------------------------------
    make_test(const char*&&                ,   false  );
    make_test(const char* const&&          ,   false  );
    make_test(const char* volatile&&       ,   false  );
    make_test(const char* volatile const&& ,   false  );
    
}//namespace

//==============================================================================
//=== true =====================================================================
namespace
{
    //       |   type                               | expected |
    make_test(volatile char                         ,   true   );
    make_test(volatile char&                        ,   true   );
    make_test(volatile char(&)[1]                   ,   true   );
    make_test(volatile char(*)[1]                   ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile const char                   ,   true   );
    make_test(volatile const char&                  ,   true   );
    make_test(volatile const char(&)[1]             ,   true   );
    make_test(volatile const char(*)[1]             ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile char*                        ,   true   );
    make_test(volatile char* const                  ,   true   );
    make_test(volatile char* volatile               ,   true   );
    make_test(volatile char* volatile const         ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile const char*                  ,   true   );
    make_test(volatile const char* const            ,   true   );
    make_test(volatile const char* volatile         ,   true   );
    make_test(volatile const char* volatile const   ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile char*&                       ,   true   );
    make_test(volatile char* const&                 ,   true   );
    make_test(volatile char* volatile&              ,   true   );
    make_test(volatile char* volatile const&        ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile const char*&                 ,   true   );
    make_test(volatile const char* const&           ,   true   );
    make_test(volatile const char* volatile&        ,   true   );
    make_test(volatile const char* volatile const&  ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile char*&&                      ,   true   );
    make_test(volatile char* const&&                ,   true   );
    make_test(volatile char* volatile&&             ,   true   );
    make_test(volatile char* volatile const&&       ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile const char*&&                ,   true   );
    make_test(volatile const char* const&&          ,   true   );
    make_test(volatile const char* volatile&&       ,   true   );
    make_test(volatile const char* volatile const&& ,   true   );
    
} // namespace
//==============================================================================

TEST_COMPONENT(000){}

//==============================================================================
//==============================================================================
#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_IS_VOLATILE_DATA

