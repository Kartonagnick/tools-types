// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-29d][22:26:12] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_ADD_CONST_DATA

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD add_const_data
#define dTEST_TAG old

#include <tools/types/common.hpp>
namespace me = ::tools;
//==============================================================================
//=== dCHECK ================================================================
namespace
{
    struct some;

    #define dVAL(a) \
        typename me::add_const_data<a>::type

    #ifdef dHAS_STATIC_ASSERT
        #define dCHECK(a, b)                             \
            static_assert(                               \
                ::std::is_same<dVAL(a), b>::value,       \
                "'tools::add_const_data<" #a ">::type' " \
                "must be '" #b "'"                       \
            )
    #else
        #define dCHECK(a, b)                        \
        {                                           \
            typedef me::add_const_data<a>::type x;  \
            typedef dTRAIT::is_same<x, b> y;        \
            dSTATIC_ASSERT(                         \
                ERROR_MUST_BE_##expected, y::value  \
            );                                      \
        } void()
    #endif

    #ifdef dHAS_RVALUE_REFERENCES
        #define dRVAL1(a, b) dCHECK(a, b)
        #define dRVAL2(a, b) dCHECK(a, b)
    #else
        #define dRVAL2(a, b)
        #define dRVAL1(a, b)
    #endif

    #ifdef dHAS_RVALUE_REFERENCES

        template<class s> 
        typename me::add_const_data<s&&>::type
        process_array(s&& arr) dNOEXCEPT
            { return ::std::forward<s>(arr); }

    #else
        template<class s> 
        typename me::add_const_data<s&>::type
        process_array(s& arr) dNOEXCEPT
            { return arr;  }
    #endif

} // namespace

//==============================================================================
//==============================================================================
// --- char/ char&/ char&&
TEST_COMPONENT(000)
{
    //    |    before      |   after               |
    dCHECK(char            , const char            );
    dCHECK(const char      , const char            );
    dCHECK(volatile char   , const volatile char   );

    dCHECK(char&           , const char&           );
    dCHECK(const char&     , const char&           );
    dCHECK(volatile char&  , const volatile char&  );

    dRVAL2(char&&          , const char&&          );
    dRVAL2(const char&&    , const char&&          );
    dRVAL2(volatile char&& , const volatile char&& );
}

// --- pointers*
TEST_COMPONENT(001)
{
    //    |    before                            |   after                                 |
    dCHECK(char*                                 , const char*                             );
    dCHECK(const char*                           , const char*                             );
    dCHECK(volatile char*                        , const volatile char*                    );
    dCHECK(volatile const char*                  , const volatile char*                    );
//--------------------------------------------------------------------------------------------
    dCHECK(char* const                           , const char* const                       );
    dCHECK(const char* const                     , const char* const                       );
    dCHECK(volatile char* const                  , const volatile char* const              );
    dCHECK(volatile const char* const            , const volatile char* const              );
//--------------------------------------------------------------------------------------------
    dCHECK(char* volatile                        , const char* volatile                    );
    dCHECK(const char* volatile                  , const char* volatile                    );
    dCHECK(volatile char* volatile               , const volatile char* volatile           );
    dCHECK(volatile const char* volatile         , const volatile char* volatile           );
//--------------------------------------------------------------------------------------------
    dCHECK(char* volatile const                  , const char* volatile const              );
    dCHECK(const char* volatile const            , const char* volatile const              );
    dCHECK(volatile char* volatile const         , const volatile char* volatile const     );
    dCHECK(volatile const char* volatile const   , const volatile char* volatile const     );
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
    dCHECK(char*&                                , const char*&                            );
    dCHECK(const char*&                          , const char*&                            );
    dCHECK(volatile char*&                       , const volatile char*&                   );
    dCHECK(volatile const char*&                 , const volatile char*&                   );
//--------------------------------------------------------------------------------------------
    dCHECK(char* const&                          , const char* const&                      );
    dCHECK(const char* const&                    , const char* const&                      );
    dCHECK(volatile char* const&                 , const volatile char* const&             );
    dCHECK(volatile const char* const&           , const volatile char* const&             );
//--------------------------------------------------------------------------------------------
    dCHECK(char* volatile&                       , const char* volatile&                   );
    dCHECK(const char* volatile&                 , const char* volatile&                   );
    dCHECK(volatile char* volatile&              , const volatile char* volatile&          );
    dCHECK(volatile const char* volatile&        , const volatile char* volatile&          );
//--------------------------------------------------------------------------------------------
    dCHECK(char* volatile const&                 , const char* volatile const&             );
    dCHECK(const char* volatile const&           , const char* volatile const&             );
    dCHECK(volatile char* volatile const&        , const volatile char* volatile const&    );
    dCHECK(volatile const char* volatile const&  , const volatile char* volatile const&    );
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(char*&&                               , const char*&&                           );
    dCHECK(const char*&&                         , const char*&&                           );
    dCHECK(volatile char*&&                      , const volatile char*&&                  );
    dCHECK(volatile const char*&&                , const volatile char*&&                  );
//--------------------------------------------------------------------------------------------
    dCHECK(char* const&&                         , const char* const&&                     );
    dCHECK(const char* const&&                   , const char* const&&                     );
    dCHECK(volatile char* const&&                , const volatile char* const&&            );
    dCHECK(volatile const char* const&&          , const volatile char* const&&            );
//--------------------------------------------------------------------------------------------
    dCHECK(char* volatile&&                      , const char* volatile&&                  );
    dCHECK(const char* volatile&&                , const char* volatile&&                  );
    dCHECK(volatile char* volatile&&             , const volatile char* volatile&&         );
    dCHECK(volatile const char* volatile&&       , const volatile char* volatile&&         );
//--------------------------------------------------------------------------------------------
    dCHECK(char* volatile const&&                , const char* volatile const&&            );
    dCHECK(const char* volatile const&&          , const char* volatile const&&            );
    dCHECK(volatile char* volatile const&&       , const volatile char* volatile const&&   );
    dCHECK(volatile const char* volatile const&& , const volatile char* volatile const&&   );
    #endif // !dHAS_RVALUE_REFERENCES
}

// --- pointers**
TEST_COMPONENT(002)
{
    //    |    before                            |   after                                   |
    dCHECK(char**                                 , const char**                             );
    dCHECK(const char**                           , const char**                             );
    dCHECK(volatile char**                        , const volatile char**                    );
    dCHECK(volatile const char**                  , const volatile char**                    );
//--------------------------------------------------------------------------------------------
    dCHECK(char** const                           , const char** const                       );
    dCHECK(const char** const                     , const char** const                       );
    dCHECK(volatile char** const                  , const volatile char** const              );
    dCHECK(volatile const char** const            , const volatile char** const              );
//--------------------------------------------------------------------------------------------
    dCHECK(char** volatile                        , const char** volatile                    );
    dCHECK(const char** volatile                  , const char** volatile                    );
    dCHECK(volatile char** volatile               , const volatile char** volatile           );
    dCHECK(volatile const char** volatile         , const volatile char** volatile           );
//--------------------------------------------------------------------------------------------
    dCHECK(char** volatile const                  , const char** volatile const              );
    dCHECK(const char** volatile const            , const char** volatile const              );
    dCHECK(volatile char** volatile const         , const volatile char** volatile const     );
    dCHECK(volatile const char** volatile const   , const volatile char** volatile const     );
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
    dCHECK(char**&                                , const char**&                            );
    dCHECK(const char**&                          , const char**&                            );
    dCHECK(volatile char**&                       , const volatile char**&                   );
    dCHECK(volatile const char**&                 , const volatile char**&                   );
//--------------------------------------------------------------------------------------------
    dCHECK(char** const&                          , const char** const&                      );
    dCHECK(const char** const&                    , const char** const&                      );
    dCHECK(volatile char** const&                 , const volatile char** const&             );
    dCHECK(volatile const char** const&           , const volatile char** const&             );
//--------------------------------------------------------------------------------------------
    dCHECK(char** volatile&                       , const char** volatile&                   );
    dCHECK(const char** volatile&                 , const char** volatile&                   );
    dCHECK(volatile char** volatile&              , const volatile char** volatile&          );
    dCHECK(volatile const char** volatile&        , const volatile char** volatile&          );
//--------------------------------------------------------------------------------------------
    dCHECK(char** volatile const&                 , const char** volatile const&             );
    dCHECK(const char** volatile const&           , const char** volatile const&             );
    dCHECK(volatile char** volatile const&        , const volatile char** volatile const&    );
    dCHECK(volatile const char** volatile const&  , const volatile char** volatile const&    );
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(char**&&                               , const char**&&                           );
    dCHECK(const char**&&                         , const char**&&                           );
    dCHECK(volatile char**&&                      , const volatile char**&&                  );
    dCHECK(volatile const char**&&                , const volatile char**&&                  );
//--------------------------------------------------------------------------------------------
    dCHECK(char** const&&                         , const char** const&&                     );
    dCHECK(const char** const&&                   , const char** const&&                     );
    dCHECK(volatile char** const&&                , const volatile char** const&&            );
    dCHECK(volatile const char** const&&          , const volatile char** const&&            );
//--------------------------------------------------------------------------------------------
    dCHECK(char** volatile&&                      , const char** volatile&&                  );
    dCHECK(const char** volatile&&                , const char** volatile&&                  );
    dCHECK(volatile char** volatile&&             , const volatile char** volatile&&         );
    dCHECK(volatile const char** volatile&&       , const volatile char** volatile&&         );
//--------------------------------------------------------------------------------------------
    dCHECK(char** volatile const&&                , const char** volatile const&&            );
    dCHECK(const char** volatile const&&          , const char** volatile const&&            );
    dCHECK(volatile char** volatile const&&       , const volatile char** volatile const&&   );
    dCHECK(volatile const char** volatile const&& , const volatile char** volatile const&&   );
    #endif // !dHAS_RVALUE_REFERENCES
}

// --- pointers stress
TEST_COMPONENT(003)
{
    //    |    before                        |   after                                 |
    dCHECK(char** const                      , const char** const                      );
    dCHECK(char* const* const                , const char* const* const                );
    dCHECK(char* const* const&               , const char* const* const&               );

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(char* const** const&&             , const char* const** const&&             );
    dCHECK(char*** const* const** const&&    , const char*** const* const** const&&    );
    dCHECK(char*** volatile* const** const&& , const char*** volatile* const** const&& );
    dCHECK(char*** const* volatile** const&& , const char*** const* volatile** const&& );
    #endif
}

// --- arrays[255]
TEST_COMPONENT(004)
{
    //    |    before                       |   after                           |
    dCHECK(char[255]                        , const char[255]                   );
    dCHECK(char(&)[255]                     , const char(&)[255]                );
    dRVAL2(char(&&)[255]                    , const char(&&)[255]               );
    dCHECK(char(*)[255]                     , const char(*)[255]                );
    dCHECK(char(*&)[255]                    , const char(*&)[255]               );
//---------------------------------------------------------------------------------
    dCHECK(const char[255]                  , const char[255]                   );
    dCHECK(const char(&)[255]               , const char(&)[255]                );
    dRVAL2(const char(&&)[255]              , const char(&&)[255]               );
    dCHECK(const char(*)[255]               , const char(*)[255]                );
    dCHECK(const char(*&)[255]              , const char(*&)[255]               );
//---------------------------------------------------------------------------------
    dCHECK(volatile char[255]               , volatile const char[255]          );
    dCHECK(volatile char(&)[255]            , volatile const char(&)[255]       );
    dRVAL2(volatile char(&&)[255]           , volatile const char(&&)[255]      );
    dCHECK(volatile char(*)[255]            , volatile const char(*)[255]       );
    dCHECK(volatile char(*&)[255]           , volatile const char(*&)[255]      );
//---------------------------------------------------------------------------------
    dCHECK(volatile const char[255]         , volatile const char[255]          );
    dCHECK(volatile const char(&)[255]      , volatile const char(&)[255]       );
    dRVAL2(volatile const char(&&)[255]     , volatile const char(&&)[255]      );
    dCHECK(volatile const char(*)[255]      , volatile const char(*)[255]       );
    dCHECK(volatile const char(*&)[255]     , volatile const char(*&)[255]      );
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
    dCHECK(char[1][2][3]                    , const char[1][2][3]               );
    dCHECK(char(&)[1][2][3]                 , const char(&)[1][2][3]            );
    dRVAL2(char(&&)[1][2][3]                , const char(&&)[1][2][3]           );
    dCHECK(char(*)[1][2][3]                 , const char(*)[1][2][3]            );
    dCHECK(char(*&)[1][2][3]                , const char(*&)[1][2][3]           );
//---------------------------------------------------------------------------------
    dCHECK(const char[1][2][3]              , const char[1][2][3]               );
    dCHECK(const char(&)[1][2][3]           , const char(&)[1][2][3]            );
    dRVAL2(const char(&&)[1][2][3]          , const char(&&)[1][2][3]           );
    dCHECK(const char(*)[1][2][3]           , const char(*)[1][2][3]            );
    dCHECK(const char(*&)[1][2][3]          , const char(*&)[1][2][3]           );
//---------------------------------------------------------------------------------
    dCHECK(volatile char[1][2][3]           , volatile const char[1][2][3]      );
    dCHECK(volatile char(&)[1][2][3]        , volatile const char(&)[1][2][3]   );
    dRVAL2(volatile char(&&)[1][2][3]       , volatile const char(&&)[1][2][3]  );
    dCHECK(volatile char(*)[1][2][3]        , volatile const char(*)[1][2][3]   );
    dCHECK(volatile char(*&)[1][2][3]       , volatile const char(*&)[1][2][3]  );
//---------------------------------------------------------------------------------
    dCHECK(volatile const char[1][2][3]     , volatile const char[1][2][3]      );
    dCHECK(volatile const char(&)[1][2][3]  , volatile const char(&)[1][2][3]   );
    dRVAL2(volatile const char(&&)[1][2][3] , volatile const char(&&)[1][2][3]  );
    dCHECK(volatile const char(*)[1][2][3]  , volatile const char(*)[1][2][3]   );
    dCHECK(volatile const char(*&)[1][2][3] , volatile const char(*&)[1][2][3]  );
}

// --- arrays[]
TEST_COMPONENT(005)
{
    //    |    before                      |   after                          |
    dCHECK(wchar_t[]                       , const wchar_t[]                  );
    dCHECK(char[]                          , const char[]                     );
    dRVAL1(char(&)[]                       , const char(&)[]                  );
    dRVAL2(char(&&)[]                      , const char(&&)[]                 );
    dCHECK(char(*)[]                       , const char(*)[]                  );
    dCHECK(char(*&)[]                      , const char(*&)[]                 );
//-------------------------------------------------------------------------------
    dCHECK(const char[]                    , const char[]                     );
    dRVAL1(const char(&)[]                 , const char(&)[]                  );
    dRVAL2(const char(&&)[]                , const char(&&)[]                 );
    dCHECK(const char(*)[]                 , const char(*)[]                  );
    dCHECK(const char(*&)[]                , const char(*&)[]                 );
//-------------------------------------------------------------------------------
    dCHECK(volatile char[]                 , volatile const char[]            );
    dRVAL1(volatile char(&)[]              , volatile const char(&)[]         );
    dRVAL2(volatile char(&&)[]             , volatile const char(&&)[]        );
    dCHECK(volatile char(*)[]              , volatile const char(*)[]         );
    dCHECK(volatile char(*&)[]             , volatile const char(*&)[]        );
//-------------------------------------------------------------------------------
    dCHECK(volatile const char[]           , volatile const char[]            );
    dRVAL1(volatile const char(&)[]        , volatile const char(&)[]         );
    dRVAL2(volatile const char(&&)[]       , volatile const char(&&)[]        );
    dCHECK(volatile const char(*)[]        , volatile const char(*)[]         );
    dCHECK(volatile const char(*&)[]       , volatile const char(*&)[]        );
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
    dCHECK(char[][2][3]                    , const char[][2][3]               );
    dRVAL1(char(&)[][2][3]                 , const char(&)[][2][3]            );
    dRVAL2(char(&&)[][2][3]                , const char(&&)[][2][3]           );
    dCHECK(char(*)[][2][3]                 , const char(*)[][2][3]            );
    dCHECK(char(*&)[][2][3]                , const char(*&)[][2][3]           );
//-------------------------------------------------------------------------------
    dCHECK(const char[][2][3]              , const char[][2][3]               );
    dRVAL1(const char(&)[][2][3]           , const char(&)[][2][3]            );
    dRVAL2(const char(&&)[][2][3]          , const char(&&)[][2][3]           );
    dCHECK(const char(*)[][2][3]           , const char(*)[][2][3]            );
    dCHECK(const char(*&)[][2][3]          , const char(*&)[][2][3]           );
//-------------------------------------------------------------------------------
    dCHECK(volatile char[][2][3]           , volatile const char[][2][3]      );
    dRVAL1(volatile char(&)[][2][3]        , volatile const char(&)[][2][3]   );
    dRVAL2(volatile char(&&)[][2][3]       , volatile const char(&&)[][2][3]  );
    dCHECK(volatile char(*)[][2][3]        , volatile const char(*)[][2][3]   );
    dCHECK(volatile char(*&)[][2][3]       , volatile const char(*&)[][2][3]  );
//-------------------------------------------------------------------------------
    dCHECK(volatile const char[][2][3]     , volatile const char[][2][3]      );
    dRVAL1(volatile const char(&)[][2][3]  , volatile const char(&)[][2][3]   );
    dRVAL2(volatile const char(&&)[][2][3] , volatile const char(&&)[][2][3]  );
    dCHECK(volatile const char(*)[][2][3]  , volatile const char(*)[][2][3]   );
    dCHECK(volatile const char(*&)[][2][3] , volatile const char(*&)[][2][3]  );
}

// --- arrays stress
TEST_COMPONENT(006)
{
    //    |    before                                            |   after                                                     |
    dCHECK(char*[1][2][3]                                        , const char*[1][2][3]                                        );
    dCHECK(char*(*)[1][2][3]                                     , const char*(*)[1][2][3]                                     );
    dCHECK(char*(&)[1][2][3]                                     , const char*(&)[1][2][3]                                     );
    dCHECK(char*(*&)[1][2][3]                                    , const char*(*&)[1][2][3]                                    );
//--------------------------------------------------------------------------------------------------------------------------      
    dCHECK(const char* const(*&)[1][2][3]                        , const char* const(*&)[1][2][3]                              );
    dCHECK(const char* const(**&)[1][2][3]                       , const char* const(**&)[1][2][3]                             );
    dCHECK(const char* const(* const* const&)[1][2][3]           , const char* const(* const* const&)[1][2][3]                 );
    dCHECK(const char* const(* volatile* const&)[1][2][3]        , const char* const(* volatile* const&)[1][2][3]              );
    dRVAL2(volatile char* const(* volatile* volatile&&)[1][2][3] , const volatile char* const(* volatile* volatile&&)[1][2][3] );
}

// --- arrays[0]
#ifdef dHAS_ZERO_ARRAY
TEST_COMPONENT(007)
{
    //    |    before                       |   after                          |
    dCHECK(wchar_t[0]                       , const wchar_t[0]                 );
    dCHECK(char[0]                          , const char[0]                    );
    dCHECK(char(&)[0]                       , const char(&)[0]                 );
    dRVAL2(char(&&)[0]                      , const char(&&)[0]                );
    dCHECK(char(*)[0]                       , const char(*)[0]                 );
    dCHECK(char(*&)[0]                      , const char(*&)[0]                );
//--------------------------------------------------------------------------------
    dCHECK(const char[0]                    , const char[0]                    );
    dCHECK(const char(&)[0]                 , const char(&)[0]                 );
    dRVAL2(const char(&&)[0]                , const char(&&)[0]                );
    dCHECK(const char(*)[0]                 , const char(*)[0]                 );
    dCHECK(const char(*&)[0]                , const char(*&)[0]                );
//--------------------------------------------------------------------------------
    dCHECK(volatile char[0]                 , volatile const char[0]           );
    dCHECK(volatile char(&)[0]              , volatile const char(&)[0]        );
    dRVAL2(volatile char(&&)[0]             , volatile const char(&&)[0]       );
    dCHECK(volatile char(*)[0]              , volatile const char(*)[0]        );
    dCHECK(volatile char(*&)[0]             , volatile const char(*&)[0]       );
//--------------------------------------------------------------------------------
    dCHECK(volatile const char[0]           , volatile const char[0]           );
    dCHECK(volatile const char(&)[0]        , volatile const char(&)[0]        );
    dRVAL2(volatile const char(&&)[0]       , volatile const char(&&)[0]       );
    dCHECK(volatile const char(*)[0]        , volatile const char(*)[0]        );
    dCHECK(volatile const char(*&)[0]       , volatile const char(*&)[0]       );
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
    dCHECK(char[0][2][3]                    , const char[0][2][3]              );
    dCHECK(char(&)[0][2][3]                 , const char(&)[0][2][3]           );
    dRVAL2(char(&&)[0][2][3]                , const char(&&)[0][2][3]          );
    dCHECK(char(*)[0][2][3]                 , const char(*)[0][2][3]           );
    dCHECK(char(*&)[0][2][3]                , const char(*&)[0][2][3]          );
//--------------------------------------------------------------------------------
    dCHECK(const char[0][2][3]              , const char[0][2][3]              );
    dCHECK(const char(&)[0][2][3]           , const char(&)[0][2][3]           );
    dRVAL2(const char(&&)[0][2][3]          , const char(&&)[0][2][3]          );
    dCHECK(const char(*)[0][2][3]           , const char(*)[0][2][3]           );
    dCHECK(const char(*&)[0][2][3]          , const char(*&)[0][2][3]          );
//--------------------------------------------------------------------------------
    dCHECK(volatile char[0][2][3]           , volatile const char[0][2][3]     );
    dCHECK(volatile char(&)[0][2][3]        , volatile const char(&)[0][2][3]  );
    dRVAL2(volatile char(&&)[0][2][3]       , volatile const char(&&)[0][2][3] );
    dCHECK(volatile char(*)[0][2][3]        , volatile const char(*)[0][2][3]  );
    dCHECK(volatile char(*&)[0][2][3]       , volatile const char(*&)[0][2][3] );
//--------------------------------------------------------------------------------
    dCHECK(volatile const char[0][2][3]     , volatile const char[0][2][3]     );
    dCHECK(volatile const char(&)[0][2][3]  , volatile const char(&)[0][2][3]  );
    dRVAL2(volatile const char(&&)[0][2][3] , volatile const char(&&)[0][2][3] );
    dCHECK(volatile const char(*)[0][2][3]  , volatile const char(*)[0][2][3]  );
    dCHECK(volatile const char(*&)[0][2][3] , volatile const char(*&)[0][2][3] );
}
#endif // !dHAS_ZERO_ARRAY

// --- functions int()
TEST_COMPONENT(008)
{
    //    |    before                |   after                   |
    dCHECK(int()                     , int()                     );
    dCHECK(int(&)()                  , int(&)()                  );
    dRVAL2(int(&&)()                 , int(&&)()                 );

    dCHECK(int(*)()                  , int(*)()                  );
    dCHECK(int(* const)()            , int(* const)()            );
    dCHECK(int(* volatile)()         , int(* volatile)()         );
    dCHECK(int(* volatile const)()   , int(* volatile const)()   );


    dCHECK(int(*&)()                 , int(*&)()                 );
    dCHECK(int(* const&)()           , int(* const&)()           );
    dCHECK(int(* volatile&)()        , int(* volatile&)()        );
    dCHECK(int(* volatile const&)()  , int(* volatile const&)()  );

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(int(*&&)()                , int(*&&)()                );
    dCHECK(int(* const&&)()          , int(* const&&)()          );
    dCHECK(int(* volatile&&)()       , int(* volatile&&)()       );
    dCHECK(int(* volatile const&&)() , int(* volatile const&&)() );
    #endif
}

// --- function-pointers
TEST_COMPONENT(009)
{                  
    //    |    before                                    |   after                                      |
    dCHECK(int(* const*&)(bool, char)                    , int(* const*&)(bool, char)                   );
    dCHECK(int(** const*&)(bool, char)                   , int(** const*&)(bool, char)                  );
    dCHECK(int(* const* const*&)(bool, char)             , int(* const* const*&)(bool, char)            );
//--    dCHECK(int(* volatile* volatile*&)(bool, char)       , int(* volatile* volatile*&)(bool, char)      );
//--    dCHECK(int(* volatile* volatile const*&)(bool, char) , int(* volatile* volatile const*&)(bool, char));
}

// --- abominable int() const
#ifdef dHAS_ABOMINABLE
TEST_COMPONENT(010)
{
    //    |    before              |   after                 |
    dCHECK(int()                   , int()                   );
    dCHECK(int() const             , int() const             );

    dCHECK(int() volatile          , int() volatile          );
    dCHECK(int() volatile const    , int() volatile const    );

    dCHECK(int() &                 , int() &                 );
    dCHECK(int() const &           , int() const &           );
    dCHECK(int() volatile &        , int() volatile &        );
    dCHECK(int() volatile const &  , int() volatile const &  );

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(int() &&                , int() &&                );
    dCHECK(int() const &&          , int() const &&          );
    dCHECK(int() volatile &&       , int() volatile &&       );
    dCHECK(int() volatile const && , int() volatile const && );
    #endif
}
#endif // !dHAS_ABOMINABLE

// --- method int(some::*)()
TEST_COMPONENT(011)
{
    //    |    before                                     |   after                                        |
    dCHECK(int(some::*)()                                 , int(some::*)()                                 );
    dCHECK(int(some::*&)()                                , int(some::*&)()                                );
    dRVAL2(int(some::*&&)()                               , int(some::*&&)()                               );

    dCHECK(int(some::* const)()                           , int(some::* const)()                           );
//--    dCHECK(int(some::* volatile)()                        , int(some::* volatile)()                        );
    dCHECK(int(some::* volatile const)()                  , int(some::* volatile const)()                  );

    dCHECK(int(some::* const&)()                          , int(some::* const&)()                          );
//--    dCHECK(int(some::* volatile&)()                       , int(some::* volatile&)()                       );
    dCHECK(int(some::* volatile const&)()                 , int(some::* volatile const&)()                 );

    #ifdef dHAS_RVALUE_REFERENCES
    dCHECK(int(some::* const&&)()                         , int(some::* const&&)()                         );
//--    dCHECK(int(some::* volatile&&)()                      , int(some::* volatile&&)()                      );
    dCHECK(int(some::* volatile const&&)()                , int(some::* volatile const&&)()                );
    #endif
}

// --- member int
TEST_COMPONENT(012)
{
    //    |    before                                     |   after                                       |
    dCHECK(int some::*                                    , const int some::*                             );
    dCHECK(int some::*&                                   , const int some::*&                            );
    dRVAL2(int some::*&&                                  , const int some::*&&                           );
                                                               
    dCHECK(int some::* const                              , const int some::* const                       );
    dCHECK(int some::* const&                             , const int some::* const&                      );
    dRVAL2(int some::* const&&                            , const int some::* const&&                     );
                                                               
    dCHECK(int some::* volatile                           , const int some::* volatile                    );
    dCHECK(int some::* volatile&                          , const int some::* volatile&                   );
    dRVAL2(int some::* volatile&&                         , const int some::* volatile&&                  );
                                                               
    dCHECK(int some::* volatile const                     , const int some::* volatile const              );
    dCHECK(int some::* volatile const&                    , const int some::* volatile const&             );
    dRVAL2(int some::* volatile const&&                   , const int some::* volatile const&&            );
//------------------------------------------------------------------------------------------------------------
    dCHECK(const int some::*                              , const int some::*                             );
    dCHECK(const int some::*&                             , const int some::*&                            );
    dRVAL2(const int some::*&&                            , const int some::*&&                           );
                                                               
    dCHECK(const int some::* const                        , const int some::* const                       );
    dCHECK(const int some::* const&                       , const int some::* const&                      );
    dRVAL2(const int some::* const&&                      , const int some::* const&&                     );
                                                               
    dCHECK(const int some::* volatile                     , const int some::* volatile                    );
    dCHECK(const int some::* volatile&                    , const int some::* volatile&                   );
    dRVAL2(const int some::* volatile&&                   , const int some::* volatile&&                  );
                                                               
    dCHECK(const int some::* volatile const               , const int some::* volatile const              );
    dCHECK(const int some::* volatile const&              , const int some::* volatile const&             );
    dRVAL2(const int some::* volatile const&&             , const int some::* volatile const&&            );
//------------------------------------------------------------------------------------------------------------
    dCHECK(volatile int some::*                           , volatile const int some::*                    );
    dCHECK(volatile int some::*&                          , volatile const int some::*&                   );
    dRVAL2(volatile int some::*&&                         , volatile const int some::*&&                  );
                                                                        
    dCHECK(volatile int some::* const                     , volatile const int some::* const              );
    dCHECK(volatile int some::* const&                    , volatile const int some::* const&             );
    dRVAL2(volatile int some::* const&&                   , volatile const int some::* const&&            );
                                                                        
    dCHECK(volatile int some::* volatile                  , volatile const int some::* volatile           );
    dCHECK(volatile int some::* volatile&                 , volatile const int some::* volatile&          );
    dRVAL2(volatile int some::* volatile&&                , volatile const int some::* volatile&&         );
                                                                        
    dCHECK(volatile int some::* volatile const            , volatile const int some::* volatile const     );
    dCHECK(volatile int some::* volatile const&           , volatile const int some::* volatile const&    );
    dRVAL2(volatile int some::* volatile const&&          , volatile const int some::* volatile const&&   );
//------------------------------------------------------------------------------------------------------------
    dCHECK(volatile const int some::*                     , volatile const int some::*                    );
    dCHECK(volatile const int some::*&                    , volatile const int some::*&                   );
    dRVAL2(volatile const int some::*&&                   , volatile const int some::*&&                  );
                       
    dCHECK(volatile const int some::* const               , volatile const int some::* const              );
    dCHECK(volatile const int some::* const&              , volatile const int some::* const&             );
    dRVAL2(volatile const int some::* const&&             , volatile const int some::* const&&            );
                       
    dCHECK(volatile const int some::* volatile            , volatile const int some::* volatile           );
    dCHECK(volatile const int some::* volatile&           , volatile const int some::* volatile&          );
    dRVAL2(volatile const int some::* volatile&&          , volatile const int some::* volatile&&         );
                       
    dCHECK(volatile const int some::* volatile const      , volatile const int some::* volatile const     );
    dCHECK(volatile const int some::* volatile const&     , volatile const int some::* volatile const&    );
    dRVAL2(volatile const int some::* volatile const&&    , volatile const int some::* volatile const&&   );
}

// --- member int stress
TEST_COMPONENT(013)
{
    typedef int arr[3];
    typedef int foo(bool);
    typedef int(*pfoo)(bool);
    typedef pfoo arrfoo[3];

    typedef char (some::*method1)(float);

    //    |    before      |   after                            |
    dCHECK(arr some::*     , const int(some::*)[3]              );
    dCHECK(foo some::*     , int(some::*)(bool)                 );
    dCHECK(arrfoo some::*  , int(*const (some::*)[3])(bool)     );
    dCHECK(pfoo some::*    , int(*const some::*)(bool)          );
    dCHECK(method1 some::* , char(some::* const some::*)(float) );
}

// --- msvc`s bug: decltype(auto) incorrect
TEST_COMPONENT(014)
{
    char arr[] = "1234";
    const char (&ref)[5] = process_array(arr);
    ASSERT_EQ(ref, arr);

    #ifdef dHAS_DECLTYPE

    typedef  decltype(process_array(arr)) 
        result_t;
    //       |  before   |       after      |
    dCHECK(char(&)[5] , result_t         );
    dCHECK(char(&)[5] , const char (&)[5]);

    #endif // dHAS_DECLTYPE
}

//==============================================================================
//=== [bug: msvc2010] ==========================================================
namespace bug_msvc2010
{
    #if defined(_MSC_VER) && _MSC_VER <= 1600
        // msvc2010 has bug 
        template<class t> struct no_ref_       { typedef t type; };
        template<class t> struct no_ref_ <t&>  { typedef t type; };
    #endif

    template<class t> struct example
    {
        #if defined(_MSC_VER) && _MSC_VER <= 1600
            typedef no_ref_<t> no_ref;
        #else
            typedef std::remove_reference<t>
                no_ref;
        #endif

        typedef typename no_ref::type
            type;
    };

} // namespace test_msvc2010

// ---msvc2010 has bug
TEST_COMPONENT(015)
{
    typedef bug_msvc2010::example<int(&)()>
        bug;
    typedef bug::type 
        result;

    dSTATIC_CHECK(
        ERROR_BUG_MSVC2010, 
        dTRAIT::is_same<result, int()>::value
    );
}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_ADD_CONST_DATA

