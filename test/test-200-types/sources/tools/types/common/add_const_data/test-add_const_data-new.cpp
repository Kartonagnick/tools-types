// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-29d][22:26:12] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_ADD_CONST_DATA

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD add_const_data
#define dTEST_TAG new

#include <tools/types/common.hpp>
//==============================================================================
//=== make_test ================================================================
namespace
{
    #define make_test(before, after)                \
        static_assert(                              \
            ::std::is_same<                         \
                ::tools::add_const_data_t<before>,  \
                after                               \
            >::value,                               \
            "add_const_data_t<" #before "> "        \
            "must be '" #after "'"                  \
        )

    struct some;

    template<class s>
    ::tools::add_const_data_t<s&&> process_array(s&& arr) noexcept
    {
        return ::std::forward<s>(arr);
    }

}//namespace

//==============================================================================
//==============================================================================
// --- char/ char&/ char&&
TEST_COMPONENT(000)
{
    //       |    before      |   after               |
    make_test(char            , const char            );
    make_test(const char      , const char            );
    make_test(volatile char   , const volatile char   );

    make_test(char&           , const char&           );
    make_test(const char&     , const char&           );
    make_test(volatile char&  , const volatile char&  );

    make_test(char&&          , const char&&          );
    make_test(const char&&    , const char&&          );
    make_test(volatile char&& , const volatile char&& );
}

// --- pointers*
TEST_COMPONENT(001)
{
    //       |    before                            |   after                                 |
    make_test(char*                                 , const char*                             );
    make_test(const char*                           , const char*                             );
    make_test(volatile char*                        , const volatile char*                    );
    make_test(volatile const char*                  , const volatile char*                    );
//--------------------------------------------------------------------------------------------
    make_test(char* const                           , const char* const                       );
    make_test(const char* const                     , const char* const                       );
    make_test(volatile char* const                  , const volatile char* const              );
    make_test(volatile const char* const            , const volatile char* const              );
//--------------------------------------------------------------------------------------------
    make_test(char* volatile                        , const char* volatile                    );
    make_test(const char* volatile                  , const char* volatile                    );
    make_test(volatile char* volatile               , const volatile char* volatile           );
    make_test(volatile const char* volatile         , const volatile char* volatile           );
//--------------------------------------------------------------------------------------------
    make_test(char* volatile const                  , const char* volatile const              );
    make_test(const char* volatile const            , const char* volatile const              );
    make_test(volatile char* volatile const         , const volatile char* volatile const     );
    make_test(volatile const char* volatile const   , const volatile char* volatile const     );
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
    make_test(char*&                                , const char*&                            );
    make_test(const char*&                          , const char*&                            );
    make_test(volatile char*&                       , const volatile char*&                   );
    make_test(volatile const char*&                 , const volatile char*&                   );
//--------------------------------------------------------------------------------------------
    make_test(char* const&                          , const char* const&                      );
    make_test(const char* const&                    , const char* const&                      );
    make_test(volatile char* const&                 , const volatile char* const&             );
    make_test(volatile const char* const&           , const volatile char* const&             );
//--------------------------------------------------------------------------------------------
    make_test(char* volatile&                       , const char* volatile&                   );
    make_test(const char* volatile&                 , const char* volatile&                   );
    make_test(volatile char* volatile&              , const volatile char* volatile&          );
    make_test(volatile const char* volatile&        , const volatile char* volatile&          );
//--------------------------------------------------------------------------------------------
    make_test(char* volatile const&                 , const char* volatile const&             );
    make_test(const char* volatile const&           , const char* volatile const&             );
    make_test(volatile char* volatile const&        , const volatile char* volatile const&    );
    make_test(volatile const char* volatile const&  , const volatile char* volatile const&    );
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
    make_test(char*&&                               , const char*&&                           );
    make_test(const char*&&                         , const char*&&                           );
    make_test(volatile char*&&                      , const volatile char*&&                  );
    make_test(volatile const char*&&                , const volatile char*&&                  );
//--------------------------------------------------------------------------------------------
    make_test(char* const&&                         , const char* const&&                     );
    make_test(const char* const&&                   , const char* const&&                     );
    make_test(volatile char* const&&                , const volatile char* const&&            );
    make_test(volatile const char* const&&          , const volatile char* const&&            );
//--------------------------------------------------------------------------------------------
    make_test(char* volatile&&                      , const char* volatile&&                  );
    make_test(const char* volatile&&                , const char* volatile&&                  );
    make_test(volatile char* volatile&&             , const volatile char* volatile&&         );
    make_test(volatile const char* volatile&&       , const volatile char* volatile&&         );
//--------------------------------------------------------------------------------------------
    make_test(char* volatile const&&                , const char* volatile const&&            );
    make_test(const char* volatile const&&          , const char* volatile const&&            );
    make_test(volatile char* volatile const&&       , const volatile char* volatile const&&   );
    make_test(volatile const char* volatile const&& , const volatile char* volatile const&&   );
}

// --- pointers**
TEST_COMPONENT(002)
{
    //       |    before                            |   after                                   |
    make_test(char**                                 , const char**                             );
    make_test(const char**                           , const char**                             );
    make_test(volatile char**                        , const volatile char**                    );
    make_test(volatile const char**                  , const volatile char**                    );
//--------------------------------------------------------------------------------------------
    make_test(char** const                           , const char** const                       );
    make_test(const char** const                     , const char** const                       );
    make_test(volatile char** const                  , const volatile char** const              );
    make_test(volatile const char** const            , const volatile char** const              );
//--------------------------------------------------------------------------------------------
    make_test(char** volatile                        , const char** volatile                    );
    make_test(const char** volatile                  , const char** volatile                    );
    make_test(volatile char** volatile               , const volatile char** volatile           );
    make_test(volatile const char** volatile         , const volatile char** volatile           );
//--------------------------------------------------------------------------------------------
    make_test(char** volatile const                  , const char** volatile const              );
    make_test(const char** volatile const            , const char** volatile const              );
    make_test(volatile char** volatile const         , const volatile char** volatile const     );
    make_test(volatile const char** volatile const   , const volatile char** volatile const     );
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
    make_test(char**&                                , const char**&                            );
    make_test(const char**&                          , const char**&                            );
    make_test(volatile char**&                       , const volatile char**&                   );
    make_test(volatile const char**&                 , const volatile char**&                   );
//--------------------------------------------------------------------------------------------
    make_test(char** const&                          , const char** const&                      );
    make_test(const char** const&                    , const char** const&                      );
    make_test(volatile char** const&                 , const volatile char** const&             );
    make_test(volatile const char** const&           , const volatile char** const&             );
//--------------------------------------------------------------------------------------------
    make_test(char** volatile&                       , const char** volatile&                   );
    make_test(const char** volatile&                 , const char** volatile&                   );
    make_test(volatile char** volatile&              , const volatile char** volatile&          );
    make_test(volatile const char** volatile&        , const volatile char** volatile&          );
//--------------------------------------------------------------------------------------------
    make_test(char** volatile const&                 , const char** volatile const&             );
    make_test(const char** volatile const&           , const char** volatile const&             );
    make_test(volatile char** volatile const&        , const volatile char** volatile const&    );
    make_test(volatile const char** volatile const&  , const volatile char** volatile const&    );
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
    make_test(char**&&                               , const char**&&                           );
    make_test(const char**&&                         , const char**&&                           );
    make_test(volatile char**&&                      , const volatile char**&&                  );
    make_test(volatile const char**&&                , const volatile char**&&                  );
//--------------------------------------------------------------------------------------------
    make_test(char** const&&                         , const char** const&&                     );
    make_test(const char** const&&                   , const char** const&&                     );
    make_test(volatile char** const&&                , const volatile char** const&&            );
    make_test(volatile const char** const&&          , const volatile char** const&&            );
//--------------------------------------------------------------------------------------------
    make_test(char** volatile&&                      , const char** volatile&&                  );
    make_test(const char** volatile&&                , const char** volatile&&                  );
    make_test(volatile char** volatile&&             , const volatile char** volatile&&         );
    make_test(volatile const char** volatile&&       , const volatile char** volatile&&         );
//--------------------------------------------------------------------------------------------
    make_test(char** volatile const&&                , const char** volatile const&&            );
    make_test(const char** volatile const&&          , const char** volatile const&&            );
    make_test(volatile char** volatile const&&       , const volatile char** volatile const&&   );
    make_test(volatile const char** volatile const&& , const volatile char** volatile const&&   );
}

// --- pointers stress
TEST_COMPONENT(003)
{
    //       |    before                        |   after                                 |
    make_test(char** const                      , const char** const                      );
    make_test(char* const* const                , const char* const* const                );
    make_test(char* const* const&               , const char* const* const&               );
    make_test(char* const** const&&             , const char* const** const&&             );
    make_test(char*** const* const** const&&    , const char*** const* const** const&&    );
    make_test(char*** volatile* const** const&& , const char*** volatile* const** const&& );
    make_test(char*** const* volatile** const&& , const char*** const* volatile** const&& );
}

// --- arrays[255]
TEST_COMPONENT(004)
{
    //       |    before                       |   after                           |
    make_test(char[255]                        , const char[255]                   );
    make_test(char(&)[255]                     , const char(&)[255]                );
    make_test(char(&&)[255]                    , const char(&&)[255]               );
    make_test(char(*)[255]                     , const char(*)[255]                );
    make_test(char(*&)[255]                    , const char(*&)[255]               );
//---------------------------------------------------------------------------------
    make_test(const char[255]                  , const char[255]                   );
    make_test(const char(&)[255]               , const char(&)[255]                );
    make_test(const char(&&)[255]              , const char(&&)[255]               );
    make_test(const char(*)[255]               , const char(*)[255]                );
    make_test(const char(*&)[255]              , const char(*&)[255]               );
//---------------------------------------------------------------------------------
    make_test(volatile char[255]               , volatile const char[255]          );
    make_test(volatile char(&)[255]            , volatile const char(&)[255]       );
    make_test(volatile char(&&)[255]           , volatile const char(&&)[255]      );
    make_test(volatile char(*)[255]            , volatile const char(*)[255]       );
    make_test(volatile char(*&)[255]           , volatile const char(*&)[255]      );
//---------------------------------------------------------------------------------
    make_test(volatile const char[255]         , volatile const char[255]          );
    make_test(volatile const char(&)[255]      , volatile const char(&)[255]       );
    make_test(volatile const char(&&)[255]     , volatile const char(&&)[255]      );
    make_test(volatile const char(*)[255]      , volatile const char(*)[255]       );
    make_test(volatile const char(*&)[255]     , volatile const char(*&)[255]      );
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
    make_test(char[1][2][3]                    , const char[1][2][3]               );
    make_test(char(&)[1][2][3]                 , const char(&)[1][2][3]            );
    make_test(char(&&)[1][2][3]                , const char(&&)[1][2][3]           );
    make_test(char(*)[1][2][3]                 , const char(*)[1][2][3]            );
    make_test(char(*&)[1][2][3]                , const char(*&)[1][2][3]           );
//---------------------------------------------------------------------------------
    make_test(const char[1][2][3]              , const char[1][2][3]               );
    make_test(const char(&)[1][2][3]           , const char(&)[1][2][3]            );
    make_test(const char(&&)[1][2][3]          , const char(&&)[1][2][3]           );
    make_test(const char(*)[1][2][3]           , const char(*)[1][2][3]            );
    make_test(const char(*&)[1][2][3]          , const char(*&)[1][2][3]           );
//---------------------------------------------------------------------------------
    make_test(volatile char[1][2][3]           , volatile const char[1][2][3]      );
    make_test(volatile char(&)[1][2][3]        , volatile const char(&)[1][2][3]   );
    make_test(volatile char(&&)[1][2][3]       , volatile const char(&&)[1][2][3]  );
    make_test(volatile char(*)[1][2][3]        , volatile const char(*)[1][2][3]   );
    make_test(volatile char(*&)[1][2][3]       , volatile const char(*&)[1][2][3]  );
//---------------------------------------------------------------------------------
    make_test(volatile const char[1][2][3]     , volatile const char[1][2][3]      );
    make_test(volatile const char(&)[1][2][3]  , volatile const char(&)[1][2][3]   );
    make_test(volatile const char(&&)[1][2][3] , volatile const char(&&)[1][2][3]  );
    make_test(volatile const char(*)[1][2][3]  , volatile const char(*)[1][2][3]   );
    make_test(volatile const char(*&)[1][2][3] , volatile const char(*&)[1][2][3]  );
}

// --- arrays[]
TEST_COMPONENT(005)
{
    //       |    before                      |   after                          |
    make_test(wchar_t[]                       , const wchar_t[]                  );
    make_test(char[]                          , const char[]                     );
    make_test(char(&)[]                       , const char(&)[]                  );
    make_test(char(&&)[]                      , const char(&&)[]                 );
    make_test(char(*)[]                       , const char(*)[]                  );
    make_test(char(*&)[]                      , const char(*&)[]                 );
//-------------------------------------------------------------------------------
    make_test(const char[]                    , const char[]                     );
    make_test(const char(&)[]                 , const char(&)[]                  );
    make_test(const char(&&)[]                , const char(&&)[]                 );
    make_test(const char(*)[]                 , const char(*)[]                  );
    make_test(const char(*&)[]                , const char(*&)[]                 );
//-------------------------------------------------------------------------------
    make_test(volatile char[]                 , volatile const char[]            );
    make_test(volatile char(&)[]              , volatile const char(&)[]         );
    make_test(volatile char(&&)[]             , volatile const char(&&)[]        );
    make_test(volatile char(*)[]              , volatile const char(*)[]         );
    make_test(volatile char(*&)[]             , volatile const char(*&)[]        );
//-------------------------------------------------------------------------------
    make_test(volatile const char[]           , volatile const char[]            );
    make_test(volatile const char(&)[]        , volatile const char(&)[]         );
    make_test(volatile const char(&&)[]       , volatile const char(&&)[]        );
    make_test(volatile const char(*)[]        , volatile const char(*)[]         );
    make_test(volatile const char(*&)[]       , volatile const char(*&)[]        );
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
    make_test(char[][2][3]                    , const char[][2][3]               );
    make_test(char(&)[][2][3]                 , const char(&)[][2][3]            );
    make_test(char(&&)[][2][3]                , const char(&&)[][2][3]           );
    make_test(char(*)[][2][3]                 , const char(*)[][2][3]            );
    make_test(char(*&)[][2][3]                , const char(*&)[][2][3]           );
//-------------------------------------------------------------------------------
    make_test(const char[][2][3]              , const char[][2][3]               );
    make_test(const char(&)[][2][3]           , const char(&)[][2][3]            );
    make_test(const char(&&)[][2][3]          , const char(&&)[][2][3]           );
    make_test(const char(*)[][2][3]           , const char(*)[][2][3]            );
    make_test(const char(*&)[][2][3]          , const char(*&)[][2][3]           );
//-------------------------------------------------------------------------------
    make_test(volatile char[][2][3]           , volatile const char[][2][3]      );
    make_test(volatile char(&)[][2][3]        , volatile const char(&)[][2][3]   );
    make_test(volatile char(&&)[][2][3]       , volatile const char(&&)[][2][3]  );
    make_test(volatile char(*)[][2][3]        , volatile const char(*)[][2][3]   );
    make_test(volatile char(*&)[][2][3]       , volatile const char(*&)[][2][3]  );
//-------------------------------------------------------------------------------
    make_test(volatile const char[][2][3]     , volatile const char[][2][3]      );
    make_test(volatile const char(&)[][2][3]  , volatile const char(&)[][2][3]   );
    make_test(volatile const char(&&)[][2][3] , volatile const char(&&)[][2][3]  );
    make_test(volatile const char(*)[][2][3]  , volatile const char(*)[][2][3]   );
    make_test(volatile const char(*&)[][2][3] , volatile const char(*&)[][2][3]  );
}

// --- arrays stress
TEST_COMPONENT(006)
{
    //       |    before                                            |   after                                                     |
    make_test(char*[1][2][3]                                        , const char*[1][2][3]                                        );
    make_test(char*(*)[1][2][3]                                     , const char*(*)[1][2][3]                                     );
    make_test(char*(&)[1][2][3]                                     , const char*(&)[1][2][3]                                     );
    make_test(char*(*&)[1][2][3]                                    , const char*(*&)[1][2][3]                                    );
//--------------------------------------------------------------------------------------------------------------------------      
    make_test(const char* const(*&)[1][2][3]                        , const char* const(*&)[1][2][3]                              );
    make_test(const char* const(**&)[1][2][3]                       , const char* const(**&)[1][2][3]                             );
    make_test(const char* const(* const* const&)[1][2][3]           , const char* const(* const* const&)[1][2][3]                 );
    make_test(const char* const(* volatile* const&)[1][2][3]        , const char* const(* volatile* const&)[1][2][3]              );
    make_test(volatile char* const(* volatile* volatile&&)[1][2][3] , const volatile char* const(* volatile* volatile&&)[1][2][3] );
}

// --- arrays[0]
#ifdef dHAS_ZERO_ARRAY
TEST_COMPONENT(007)
{
    //       |    before                       |   after                          |
    make_test(wchar_t[0]                       , const wchar_t[0]                 );
    make_test(char[0]                          , const char[0]                    );
    make_test(char(&)[0]                       , const char(&)[0]                 );
    make_test(char(&&)[0]                      , const char(&&)[0]                );
    make_test(char(*)[0]                       , const char(*)[0]                 );
    make_test(char(*&)[0]                      , const char(*&)[0]                );
//--------------------------------------------------------------------------------
    make_test(const char[0]                    , const char[0]                    );
    make_test(const char(&)[0]                 , const char(&)[0]                 );
    make_test(const char(&&)[0]                , const char(&&)[0]                );
    make_test(const char(*)[0]                 , const char(*)[0]                 );
    make_test(const char(*&)[0]                , const char(*&)[0]                );
//--------------------------------------------------------------------------------
    make_test(volatile char[0]                 , volatile const char[0]           );
    make_test(volatile char(&)[0]              , volatile const char(&)[0]        );
    make_test(volatile char(&&)[0]             , volatile const char(&&)[0]       );
    make_test(volatile char(*)[0]              , volatile const char(*)[0]        );
    make_test(volatile char(*&)[0]             , volatile const char(*&)[0]       );
//--------------------------------------------------------------------------------
    make_test(volatile const char[0]           , volatile const char[0]           );
    make_test(volatile const char(&)[0]        , volatile const char(&)[0]        );
    make_test(volatile const char(&&)[0]       , volatile const char(&&)[0]       );
    make_test(volatile const char(*)[0]        , volatile const char(*)[0]        );
    make_test(volatile const char(*&)[0]       , volatile const char(*&)[0]       );
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
    make_test(char[0][2][3]                    , const char[0][2][3]              );
    make_test(char(&)[0][2][3]                 , const char(&)[0][2][3]           );
    make_test(char(&&)[0][2][3]                , const char(&&)[0][2][3]          );
    make_test(char(*)[0][2][3]                 , const char(*)[0][2][3]           );
    make_test(char(*&)[0][2][3]                , const char(*&)[0][2][3]          );
//--------------------------------------------------------------------------------
    make_test(const char[0][2][3]              , const char[0][2][3]              );
    make_test(const char(&)[0][2][3]           , const char(&)[0][2][3]           );
    make_test(const char(&&)[0][2][3]          , const char(&&)[0][2][3]          );
    make_test(const char(*)[0][2][3]           , const char(*)[0][2][3]           );
    make_test(const char(*&)[0][2][3]          , const char(*&)[0][2][3]          );
//--------------------------------------------------------------------------------
    make_test(volatile char[0][2][3]           , volatile const char[0][2][3]     );
    make_test(volatile char(&)[0][2][3]        , volatile const char(&)[0][2][3]  );
    make_test(volatile char(&&)[0][2][3]       , volatile const char(&&)[0][2][3] );
    make_test(volatile char(*)[0][2][3]        , volatile const char(*)[0][2][3]  );
    make_test(volatile char(*&)[0][2][3]       , volatile const char(*&)[0][2][3] );
//--------------------------------------------------------------------------------
    make_test(volatile const char[0][2][3]     , volatile const char[0][2][3]     );
    make_test(volatile const char(&)[0][2][3]  , volatile const char(&)[0][2][3]  );
    make_test(volatile const char(&&)[0][2][3] , volatile const char(&&)[0][2][3] );
    make_test(volatile const char(*)[0][2][3]  , volatile const char(*)[0][2][3]  );
    make_test(volatile const char(*&)[0][2][3] , volatile const char(*&)[0][2][3] );
}
#endif // !dHAS_ZERO_ARRAY

// --- functions int()
TEST_COMPONENT(008)
{
    //       |    before                |   after                   |
    make_test(int()                     , int()                     );
    make_test(int(&)()                  , int(&)()                  );
    make_test(int(&&)()                 , int(&&)()                 );

    make_test(int(*)()                  , int(*)()                  );
    make_test(int(* const)()            , int(* const)()            );
    make_test(int(* volatile)()         , int(* volatile)()         );
    make_test(int(* volatile const)()   , int(* volatile const)()   );

    make_test(int(*&)()                 , int(*&)()                 );
    make_test(int(* const&)()           , int(* const&)()           );
    make_test(int(* volatile&)()        , int(* volatile&)()        );
    make_test(int(* volatile const&)()  , int(* volatile const&)()  );

    make_test(int(*&&)()                , int(*&&)()                );
    make_test(int(* const&&)()          , int(* const&&)()          );
    make_test(int(* volatile&&)()       , int(* volatile&&)()       );
    make_test(int(* volatile const&&)() , int(* volatile const&&)() );
}

// --- function-pointers
TEST_COMPONENT(009)
{                  
    //       |    before                                    |   after                                      |
    make_test(int(* const*&)(bool, char)                    , int(* const*&)(bool, char)                   );
    make_test(int(** const*&)(bool, char)                   , int(** const*&)(bool, char)                  );
    make_test(int(* const* const*&)(bool, char)             , int(* const* const*&)(bool, char)            );
    make_test(int(* volatile* volatile*&)(bool, char)       , int(* volatile* volatile*&)(bool, char)      );
    make_test(int(* volatile* volatile const*&)(bool, char) , int(* volatile* volatile const*&)(bool, char));
}

// --- abominable int() const
TEST_COMPONENT(010)
{
    //       |    before              |   after                 |
    make_test(int()                   , int()                   );
    make_test(int() const             , int() const             );

    make_test(int() volatile          , int() volatile          );
    make_test(int() volatile const    , int() volatile const    );

    make_test(int() &                 , int() &                 );
    make_test(int() const &           , int() const &           );
    make_test(int() volatile &        , int() volatile &        );
    make_test(int() volatile const &  , int() volatile const &  );

    make_test(int() &&                , int() &&                );
    make_test(int() const &&          , int() const &&          );
    make_test(int() volatile &&       , int() volatile &&       );
    make_test(int() volatile const && , int() volatile const && );
}

// --- method int(some::*)()
TEST_COMPONENT(011)
{
    //       |    before                                     |   after                                        |
    make_test(int(some::*)()                                 , int(some::*)()                                 );
    make_test(int(some::*&)()                                , int(some::*&)()                                );
    make_test(int(some::*&&)()                               , int(some::*&&)()                               );

    make_test(int(some::* const)()                           , int(some::* const)()                           );
    make_test(int(some::* volatile)()                        , int(some::* volatile)()                        );
    make_test(int(some::* volatile const)()                  , int(some::* volatile const)()                  );

    make_test(int(some::* const&)()                          , int(some::* const&)()                          );
    make_test(int(some::* volatile&)()                       , int(some::* volatile&)()                       );
    make_test(int(some::* volatile const&)()                 , int(some::* volatile const&)()                 );

    make_test(int(some::* const&&)()                         , int(some::* const&&)()                         );
    make_test(int(some::* volatile&&)()                      , int(some::* volatile&&)()                      );
    make_test(int(some::* volatile const&&)()                , int(some::* volatile const&&)()                );
}

// --- member int
TEST_COMPONENT(012)
{
    //       |    before                                     |   after                                       |
    make_test(int some::*                                    , const int some::*                             );
    make_test(int some::*&                                   , const int some::*&                            );
    make_test(int some::*&&                                  , const int some::*&&                           );
                                                               
    make_test(int some::* const                              , const int some::* const                       );
    make_test(int some::* const&                             , const int some::* const&                      );
    make_test(int some::* const&&                            , const int some::* const&&                     );
                                                               
    make_test(int some::* volatile                           , const int some::* volatile                    );
    make_test(int some::* volatile&                          , const int some::* volatile&                   );
    make_test(int some::* volatile&&                         , const int some::* volatile&&                  );
                                                               
    make_test(int some::* volatile const                     , const int some::* volatile const              );
    make_test(int some::* volatile const&                    , const int some::* volatile const&             );
    make_test(int some::* volatile const&&                   , const int some::* volatile const&&            );
//------------------------------------------------------------------------------------------------------------
    make_test(const int some::*                              , const int some::*                             );
    make_test(const int some::*&                             , const int some::*&                            );
    make_test(const int some::*&&                            , const int some::*&&                           );
                                                               
    make_test(const int some::* const                        , const int some::* const                       );
    make_test(const int some::* const&                       , const int some::* const&                      );
    make_test(const int some::* const&&                      , const int some::* const&&                     );
                                                               
    make_test(const int some::* volatile                     , const int some::* volatile                    );
    make_test(const int some::* volatile&                    , const int some::* volatile&                   );
    make_test(const int some::* volatile&&                   , const int some::* volatile&&                  );
                                                               
    make_test(const int some::* volatile const               , const int some::* volatile const              );
    make_test(const int some::* volatile const&              , const int some::* volatile const&             );
    make_test(const int some::* volatile const&&             , const int some::* volatile const&&            );
//------------------------------------------------------------------------------------------------------------
    make_test(volatile int some::*                           , volatile const int some::*                    );
    make_test(volatile int some::*&                          , volatile const int some::*&                   );
    make_test(volatile int some::*&&                         , volatile const int some::*&&                  );
                                                                        
    make_test(volatile int some::* const                     , volatile const int some::* const              );
    make_test(volatile int some::* const&                    , volatile const int some::* const&             );
    make_test(volatile int some::* const&&                   , volatile const int some::* const&&            );
                                                                        
    make_test(volatile int some::* volatile                  , volatile const int some::* volatile           );
    make_test(volatile int some::* volatile&                 , volatile const int some::* volatile&          );
    make_test(volatile int some::* volatile&&                , volatile const int some::* volatile&&         );
                                                                        
    make_test(volatile int some::* volatile const            , volatile const int some::* volatile const     );
    make_test(volatile int some::* volatile const&           , volatile const int some::* volatile const&    );
    make_test(volatile int some::* volatile const&&          , volatile const int some::* volatile const&&   );
//------------------------------------------------------------------------------------------------------------
    make_test(volatile const int some::*                     , volatile const int some::*                    );
    make_test(volatile const int some::*&                    , volatile const int some::*&                   );
    make_test(volatile const int some::*&&                   , volatile const int some::*&&                  );
                       
    make_test(volatile const int some::* const               , volatile const int some::* const              );
    make_test(volatile const int some::* const&              , volatile const int some::* const&             );
    make_test(volatile const int some::* const&&             , volatile const int some::* const&&            );
                       
    make_test(volatile const int some::* volatile            , volatile const int some::* volatile           );
    make_test(volatile const int some::* volatile&           , volatile const int some::* volatile&          );
    make_test(volatile const int some::* volatile&&          , volatile const int some::* volatile&&         );
                       
    make_test(volatile const int some::* volatile const      , volatile const int some::* volatile const     );
    make_test(volatile const int some::* volatile const&     , volatile const int some::* volatile const&    );
    make_test(volatile const int some::* volatile const&&    , volatile const int some::* volatile const&&   );
}

// --- member int stress
TEST_COMPONENT(013)
{
    using arr    = int[3];
    using foo    = int(bool);
    using pfoo   = int(*)(bool);
    using arrfoo = pfoo[3];

    using method1 = char (some::*)(float);

    //       |    before      |   after                            |
    make_test(arr some::*     , const int(some::*)[3]              );
    make_test(foo some::*     , int(some::*)(bool)                 );
    make_test(arrfoo some::*  , int(*const (some::*)[3])(bool)     );
    make_test(pfoo some::*    , int(* const some::*)(bool)         );
    make_test(method1 some::* , char(some::* const some::*)(float) );
}

// --- msvc`s bug: decltype(auto) incorrect
TEST_COMPONENT(014)
{
    char arr[] = "1234";
    const char (&ref)[5] = process_array(arr);
    ASSERT_EQ(ref, arr);

    using result_t = decltype(process_array(arr));
    //       |  before   |       after      |
    make_test(char(&)[5] , result_t         );
    make_test(char(&)[5] , const char (&)[5]);
}

//==============================================================================
//==============================================================================
#endif // !dHAS_CPP11
#endif // !TEST_TOOLS_ADD_CONST_DATA

