// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-23d][22:22:01] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_IS_VOLATILE_DATA

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD is_volatile_data
#define dTEST_TAG old

#include <tools/types/common.hpp>
#include <string>

namespace me = ::tools;
//==============================================================================
//=== make_test ================================================================
namespace
{
    #define dexpression(type, expected) \
        me::is_volatile_data<type>::value == expected


    #ifdef dHAS_STATIC_ASSERT
        #define make_test(type, expected)                     \
            static_assert(                                    \
                dexpression(type, expected),                  \
                "tools::is_volatile_data<" #type ">::value "  \
                "must be '" #expected "'"                     \
            )
    #else
        #define make_test(type, expected)    \
            dSTATIC_ASSERT(                  \
                dexpression(type, expected), \
                ERROR_INTERNAL               \
            )
    #endif
    
}//namespace

//==============================================================================
//=== false ====================================================================
TEST_COMPONENT(000)
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
    #ifdef dHAS_RVALUE_REFERENCES
    make_test(char*&&                      ,   false  );
    make_test(char* const&&                ,   false  );
    make_test(char* volatile&&             ,   false  );
    make_test(char* volatile const&&       ,   false  );
//------------------------------------------------------------------------------
    make_test(const char*&&                ,   false  );
    make_test(const char* const&&          ,   false  );
    make_test(const char* volatile&&       ,   false  );
    make_test(const char* volatile const&& ,   false  );
    #endif
}

//==============================================================================
//=== true =====================================================================
TEST_COMPONENT(001)
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
    #ifdef dHAS_RVALUE_REFERENCES
    make_test(volatile char*&&                      ,   true   );
    make_test(volatile char* const&&                ,   true   );
    make_test(volatile char* volatile&&             ,   true   );
    make_test(volatile char* volatile const&&       ,   true   );
//------------------------------------------------------------------------------
    make_test(volatile const char*&&                ,   true   );
    make_test(volatile const char* const&&          ,   true   );
    make_test(volatile const char* volatile&&       ,   true   );
    make_test(volatile const char* volatile const&& ,   true   );
    #endif
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_IS_VOLATILE_DATA

