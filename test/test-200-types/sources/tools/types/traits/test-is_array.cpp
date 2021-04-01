// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-29d][22:26:12] Idrisov Denis R.
// [2021y-04m-02d][00:01:30] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_SAME

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_array
#define dTEST_TAG true

#include <tools/types/traits.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #define dEXPRESSION(a,v) \
        me::is_array<a>::value == v

    #define dCHECK(a, v)       \
        dSTATIC_ASSERT(        \
            ERROR_MUST_BE_##v, \
            dEXPRESSION(a, v)  \
        )

    #ifdef dHAS_RVALUE_REFERENCE
        #define dRVAL_(a, v) dCHECK(a, v)
    #else
        #define dRVAL_(a, v) void()
    #endif

    struct some;

} // namespace

//==============================================================================
//==============================================================================
// --- char/ char&/ char&&
TEST_COMPONENT(000)
{
    dCHECK(char           , false);
    dCHECK(const char     , false);
    dCHECK(volatile char  , false);
                              
    dCHECK(char&          , false);
    dCHECK(const char&    , false);
    dCHECK(volatile char& , false);
                              
    dRVAL_(char&&         , false);
    dRVAL_(const char&&   , false);
    dRVAL_(volatile char&&, false);
}

// --- pointers*
TEST_COMPONENT(001)
{
    dCHECK(char*                                , false);
    dCHECK(const char*                          , false);
    dCHECK(volatile char*                       , false);
    dCHECK(volatile const char*                 , false);
//------------------------------------------------------------------------------
    dCHECK(char* const                          , false);
    dCHECK(const char* const                    , false);
    dCHECK(volatile char* const                 , false);
    dCHECK(volatile const char* const           , false);
//------------------------------------------------------------------------------
    dCHECK(char* volatile                       , false);
    dCHECK(const char* volatile                 , false);
    dCHECK(volatile char* volatile              , false);
    dCHECK(volatile const char* volatile        , false);
//------------------------------------------------------------------------------
    dCHECK(char* volatile const                 , false);
    dCHECK(const char* volatile const           , false);
    dCHECK(volatile char* volatile const        , false);
    dCHECK(volatile const char* volatile const  , false);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char*&                               , false);
    dCHECK(const char*&                         , false);
    dCHECK(volatile char*&                      , false);
    dCHECK(volatile const char*&                , false);
//------------------------------------------------------------------------------
    dCHECK(char* const&                         , false);
    dCHECK(const char* const&                   , false);
    dCHECK(volatile char* const&                , false);
    dCHECK(volatile const char* const&          , false);
//------------------------------------------------------------------------------
    dCHECK(char* volatile&                      , false);
    dCHECK(const char* volatile&                , false);
    dCHECK(volatile char* volatile&             , false);
    dCHECK(volatile const char* volatile&       , false);
//------------------------------------------------------------------------------
    dCHECK(char* volatile const&                , false);
    dCHECK(const char* volatile const&          , false);
    dCHECK(volatile char* volatile const&       , false);
    dCHECK(volatile const char* volatile const& , false);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dRVAL_(char*&&                              , false);
    dRVAL_(const char*&&                        , false);
    dRVAL_(volatile char*&&                     , false);
    dRVAL_(volatile const char*&&               , false);
//------------------------------------------------------------------------------
    dRVAL_(char* const&&                        , false);
    dRVAL_(const char* const&&                  , false);
    dRVAL_(volatile char* const&&               , false);
    dRVAL_(volatile const char* const&&         , false);
//------------------------------------------------------------------------------
    dRVAL_(char* volatile&&                     , false);
    dRVAL_(const char* volatile&&               , false);
    dRVAL_(volatile char* volatile&&            , false);
    dRVAL_(volatile const char* volatile&&      , false);
//------------------------------------------------------------------------------
    dRVAL_(char* volatile const&&               , false);
    dRVAL_(const char* volatile const&&         , false);
    dRVAL_(volatile char* volatile const&&      , false);
    dRVAL_(volatile const char* volatile const&&, false);
}

// --- pointers**
TEST_COMPONENT(002)
{
    dCHECK(char**                                , false);
    dCHECK(const char**                          , false);
    dCHECK(volatile char**                       , false);
    dCHECK(volatile const char**                 , false);
//------------------------------------------------------------------------------
    dCHECK(char** const                          , false);
    dCHECK(const char** const                    , false);
    dCHECK(volatile char** const                 , false);
    dCHECK(volatile const char** const           , false);
//------------------------------------------------------------------------------
    dCHECK(char** volatile                       , false);
    dCHECK(const char** volatile                 , false);
    dCHECK(volatile char** volatile              , false);
    dCHECK(volatile const char** volatile        , false);
//------------------------------------------------------------------------------
    dCHECK(char** volatile const                 , false);
    dCHECK(const char** volatile const           , false);
    dCHECK(volatile char** volatile const        , false);
    dCHECK(volatile const char** volatile const  , false);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char**&                               , false);
    dCHECK(const char**&                         , false);
    dCHECK(volatile char**&                      , false);
    dCHECK(volatile const char**&                , false);
//------------------------------------------------------------------------------
    dCHECK(char** const&                         , false);
    dCHECK(const char** const&                   , false);
    dCHECK(volatile char** const&                , false);
    dCHECK(volatile const char** const&          , false);
//------------------------------------------------------------------------------
    dCHECK(char** volatile&                      , false);
    dCHECK(const char** volatile&                , false);
    dCHECK(volatile char** volatile&             , false);
    dCHECK(volatile const char** volatile&       , false);
//------------------------------------------------------------------------------
    dCHECK(char** volatile const&                , false);
    dCHECK(const char** volatile const&          , false);
    dCHECK(volatile char** volatile const&       , false);
    dCHECK(volatile const char** volatile const& , false);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dRVAL_(char**&&                              , false);
    dRVAL_(const char**&&                        , false);
    dRVAL_(volatile char**&&                     , false);
    dRVAL_(volatile const char**&&               , false);
//------------------------------------------------------------------------------
    dRVAL_(char** const&&                        , false);
    dRVAL_(const char** const&&                  , false);
    dRVAL_(volatile char** const&&               , false);
    dRVAL_(volatile const char** const&&         , false);
//------------------------------------------------------------------------------
    dRVAL_(char** volatile&&                     , false);
    dRVAL_(const char** volatile&&               , false);
    dRVAL_(volatile char** volatile&&            , false);
    dRVAL_(volatile const char** volatile&&      , false);
//------------------------------------------------------------------------------
    dRVAL_(char** volatile const&&               , false);
    dRVAL_(const char** volatile const&&         , false);
    dRVAL_(volatile char** volatile const&&      , false);
    dRVAL_(volatile const char** volatile const&&, false);
}

// --- pointers stress
TEST_COMPONENT(003)
{
    dCHECK(char** const                     , false);
    dCHECK(char* const* const               , false);
    dCHECK(char* const* const&              , false);

    dRVAL_(char* const** const&&            , false);
    dRVAL_(char*** const* const** const&&   , false);
    dRVAL_(char*** volatile* const** const&&, false);
    dRVAL_(char*** const* volatile** const&&, false);
}

// --- arrays[255]
TEST_COMPONENT(004)
{
    dCHECK(char[255]                       , true);
    dCHECK(char(&)[255]                    , false);
    dRVAL_(char(&&)[255]                   , false);
    dCHECK(char(*)[255]                    , false);
    dCHECK(char(*&)[255]                   , false);
//------------------------------------------------------------------------------
    dCHECK(const char[255]                 , true);
    dCHECK(const char(&)[255]              , false);
    dRVAL_(const char(&&)[255]             , false);
    dCHECK(const char(*)[255]              , false);
    dCHECK(const char(*&)[255]             , false);
//------------------------------------------------------------------------------
    dCHECK(volatile char[255]              , true);
    dCHECK(volatile char(&)[255]           , false);
    dRVAL_(volatile char(&&)[255]          , false);
    dCHECK(volatile char(*)[255]           , false);
    dCHECK(volatile char(*&)[255]          , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[255]        , true);
    dCHECK(volatile const char(&)[255]     , false);
    dRVAL_(volatile const char(&&)[255]    , false);
    dCHECK(volatile const char(*)[255]     , false);
    dCHECK(volatile const char(*&)[255]    , false);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char[1][2][3]                   , true);
    dCHECK(char(&)[1][2][3]                , false);
    dRVAL_(char(&&)[1][2][3]               , false);
    dCHECK(char(*)[1][2][3]                , false);
    dCHECK(char(*&)[1][2][3]               , false);
//------------------------------------------------------------------------------
    dCHECK(const char[1][2][3]             , true);
    dCHECK(const char(&)[1][2][3]          , false);
    dRVAL_(const char(&&)[1][2][3]         , false);
    dCHECK(const char(*)[1][2][3]          , false);
    dCHECK(const char(*&)[1][2][3]         , false);
//------------------------------------------------------------------------------
    dCHECK(volatile char[1][2][3]          , true);
    dCHECK(volatile char(&)[1][2][3]       , false);
    dRVAL_(volatile char(&&)[1][2][3]      , false);
    dCHECK(volatile char(*)[1][2][3]       , false);
    dCHECK(volatile char(*&)[1][2][3]      , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[1][2][3]    , true);
    dCHECK(volatile const char(&)[1][2][3] , false);
    dRVAL_(volatile const char(&&)[1][2][3], false);
    dCHECK(volatile const char(*)[1][2][3] , false);
    dCHECK(volatile const char(*&)[1][2][3], false);
}

// --- arrays[]
#ifdef dHAS_ARRAY_EMPTY_SIZE
TEST_COMPONENT(005)
{
    dCHECK(wchar_t[]                      , true );
    dCHECK(char[]                         , true );
    dCHECK(char(&)[]                      , false);
    dRVAL_(char(&&)[]                     , false);
    dCHECK(char(*)[]                      , false);
    dCHECK(char(*&)[]                     , false);
//------------------------------------------------------------------------------
    dCHECK(const char[]                   , true );
    dCHECK(const char(&)[]                , false);
    dRVAL_(const char(&&)[]               , false);
    dCHECK(const char(*)[]                , false);
    dCHECK(const char(*&)[]               , false);
//------------------------------------------------------------------------------
    dCHECK(volatile char[]                , true );
    dCHECK(volatile char(&)[]             , false);
    dRVAL_(volatile char(&&)[]            , false);
    dCHECK(volatile char(*)[]             , false);
    dCHECK(volatile char(*&)[]            , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[]          , true );
    dCHECK(volatile const char(&)[]       , false);
    dRVAL_(volatile const char(&&)[]      , false);
    dCHECK(volatile const char(*)[]       , false);
    dCHECK(volatile const char(*&)[]      , false);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char[][2][3]                   , true );
    dCHECK(char(&)[][2][3]                , false);
    dRVAL_(char(&&)[][2][3]               , false);
    dCHECK(char(*)[][2][3]                , false);
    dCHECK(char(*&)[][2][3]               , false);
//------------------------------------------------------------------------------
    dCHECK(const char[][2][3]             , true );
    dCHECK(const char(&)[][2][3]          , false);
    dRVAL_(const char(&&)[][2][3]         , false);
    dCHECK(const char(*)[][2][3]          , false);
    dCHECK(const char(*&)[][2][3]         , false);
//------------------------------------------------------------------------------
    dCHECK(volatile char[][2][3]          , true );
    dCHECK(volatile char(&)[][2][3]       , false);
    dRVAL_(volatile char(&&)[][2][3]      , false);
    dCHECK(volatile char(*)[][2][3]       , false);
    dCHECK(volatile char(*&)[][2][3]      , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[][2][3]    , true );
    dCHECK(volatile const char(&)[][2][3] , false);
    dRVAL_(volatile const char(&&)[][2][3], false);
    dCHECK(volatile const char(*)[][2][3] , false);
    dCHECK(volatile const char(*&)[][2][3], false);
}
#endif

// --- arrays stress
TEST_COMPONENT(006)
{
    dCHECK(char*[1][2][3]                                       , true );
    dCHECK(char*(*)[1][2][3]                                    , false);
    dCHECK(char*(&)[1][2][3]                                    , false);
    dCHECK(char*(*&)[1][2][3]                                   , false);
//------------------------------------------------------------------------------
    dCHECK(const char* const(*&)[1][2][3]                       , false);
    dCHECK(const char* const(**&)[1][2][3]                      , false);
    dCHECK(const char* const(* const* const&)[1][2][3]          , false);
    dCHECK(const char* const(* volatile* const&)[1][2][3]       , false);
    dRVAL_(volatile char* const(* volatile* volatile&&)[1][2][3], false);
}
#if 0
// --- arrays[0]
#ifdef dHAS_ZERO_ARRAY
TEST_COMPONENT(007)
{
    dCHECK(wchar_t[0]                      );
    dCHECK(char[0]                         );
    dCHECK(char(&)[0]                      );
    dRVAL_(char(&&)[0]                     );
    dCHECK(char(*)[0]                      );
    dCHECK(char(*&)[0]                     );
//------------------------------------------------------------------------------
    dCHECK(const char[0]                   );
    dCHECK(const char(&)[0]                );
    dRVAL_(const char(&&)[0]               );
    dCHECK(const char(*)[0]                );
    dCHECK(const char(*&)[0]               );
//------------------------------------------------------------------------------
    dCHECK(volatile char[0]                );
    dCHECK(volatile char(&)[0]             );
    dRVAL_(volatile char(&&)[0]            );
    dCHECK(volatile char(*)[0]             );
    dCHECK(volatile char(*&)[0]            );
//------------------------------------------------------------------------------
    dCHECK(volatile const char[0]          );
    dCHECK(volatile const char(&)[0]       );
    dRVAL_(volatile const char(&&)[0]      );
    dCHECK(volatile const char(*)[0]       );
    dCHECK(volatile const char(*&)[0]      );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char[0][2][3]                   );
    dCHECK(char(&)[0][2][3]                );
    dRVAL_(char(&&)[0][2][3]               );
    dCHECK(char(*)[0][2][3]                );
    dCHECK(char(*&)[0][2][3]               );
//------------------------------------------------------------------------------
    dCHECK(const char[0][2][3]             );
    dCHECK(const char(&)[0][2][3]          );
    dRVAL_(const char(&&)[0][2][3]         );
    dCHECK(const char(*)[0][2][3]          );
    dCHECK(const char(*&)[0][2][3]         );
//------------------------------------------------------------------------------
    dCHECK(volatile char[0][2][3]          );
    dCHECK(volatile char(&)[0][2][3]       );
    dRVAL_(volatile char(&&)[0][2][3]      );
    dCHECK(volatile char(*)[0][2][3]       );
    dCHECK(volatile char(*&)[0][2][3]      );
//------------------------------------------------------------------------------
    dCHECK(volatile const char[0][2][3]    );
    dCHECK(volatile const char(&)[0][2][3] );
    dRVAL_(volatile const char(&&)[0][2][3]);
    dCHECK(volatile const char(*)[0][2][3] );
    dCHECK(volatile const char(*&)[0][2][3]);
}
#endif // !dHAS_ZERO_ARRAY

// --- functions int()
TEST_COMPONENT(008)
{
    dCHECK(int()                    );
    dCHECK(int(&)()                 );
    dRVAL_(int(&&)()                );
    
    dCHECK(int(*)()                 );
    dCHECK(int(* const)()           );
    dCHECK(int(* volatile)()        );
    dCHECK(int(* volatile const)()  );
    
    dCHECK(int(*&)()                );
    dCHECK(int(* const&)()          );
    dCHECK(int(* volatile&)()       );
    dCHECK(int(* volatile const&)() );
    
    dRVAL_(int(*&&)()               );
    dRVAL_(int(* const&&)()         );
    dRVAL_(int(* volatile&&)()      );
    dRVAL_(int(* volatile const&&)());
}

// --- function-pointers
TEST_COMPONENT(009)
{                  
    dCHECK(int(* const*&)(bool, char)                   );
    dCHECK(int(** const*&)(bool, char)                  );
    dCHECK(int(* const* const*&)(bool, char)            );
    dCHECK(int(* volatile* volatile*&)(bool, char)      );
    dCHECK(int(* volatile* volatile const*&)(bool, char));
}

// --- abominable int() const
#ifdef dHAS_ABOMINABLE
TEST_COMPONENT(010)
{
    dCHECK(int()                   );
    dCHECK(int() const             );
    
    dCHECK(int() volatile          );
    dCHECK(int() volatile const    );

    dCHECK(int() &                 );
    dCHECK(int() const &           );
    dCHECK(int() volatile &        );
    dCHECK(int() volatile const &  );

    dRVAL_(int() &&                );
    dRVAL_(int() const &&          );
    dRVAL_(int() volatile &&       );
    dRVAL_(int() volatile const && );
}
#endif

// --- method int(some::*)()
TEST_COMPONENT(011)
{
    dCHECK(int(some::*)()                 );
    dCHECK(int(some::*&)()                );
    dRVAL_(int(some::*&&)()               );

    dCHECK(int(some::* const)()           );
    dCHECK(int(some::* volatile)()        );
    dCHECK(int(some::* volatile const)()  );

    dCHECK(int(some::* const&)()          );
    dCHECK(int(some::* volatile&)()       );
    dCHECK(int(some::* volatile const&)() );

    dRVAL_(int(some::* const&&)()         );
    dRVAL_(int(some::* volatile&&)()      );
    dRVAL_(int(some::* volatile const&&)());
}

// --- member int
TEST_COMPONENT(012)
{
    dCHECK(int some::*                                );
    dCHECK(int some::*&                               );
    dRVAL_(int some::*&&                              );

    dCHECK(int some::* const                          );
    dCHECK(int some::* const&                         );
    dRVAL_(int some::* const&&                        );

    dCHECK(int some::* volatile                       );
    dCHECK(int some::* volatile&                      );
    dRVAL_(int some::* volatile&&                     );

    dCHECK(int some::* volatile const                 );
    dCHECK(int some::* volatile const&                );
    dRVAL_(int some::* volatile const&&               );
//------------------------------------------------------------------------------
    dCHECK(const int some::*                          );
    dCHECK(const int some::*&                         );
    dRVAL_(const int some::*&&                        );
    
    dCHECK(const int some::* const                    );
    dCHECK(const int some::* const&                   );
    dRVAL_(const int some::* const&&                  );

    dCHECK(const int some::* volatile                 );
    dCHECK(const int some::* volatile&                );
    dRVAL_(const int some::* volatile&&               );

    dCHECK(const int some::* volatile const           );
    dCHECK(const int some::* volatile const&          );
    dRVAL_(const int some::* volatile const&&         );
//------------------------------------------------------------------------------
    dCHECK(volatile int some::*                       );
    dCHECK(volatile int some::*&                      );
    dRVAL_(volatile int some::*&&                     );

    dCHECK(volatile int some::* const                 );
    dCHECK(volatile int some::* const&                );
    dRVAL_(volatile int some::* const&&               );

    dCHECK(volatile int some::* volatile              );
    dCHECK(volatile int some::* volatile&             );
    dRVAL_(volatile int some::* volatile&&            );

    dCHECK(volatile int some::* volatile const        );
    dCHECK(volatile int some::* volatile const&       );
    dRVAL_(volatile int some::* volatile const&&      );
//------------------------------------------------------------------------------
    dCHECK(volatile const int some::*                 );
    dCHECK(volatile const int some::*&                );
    dRVAL_(volatile const int some::*&&               );

    dCHECK(volatile const int some::* const           );
    dCHECK(volatile const int some::* const&          );
    dRVAL_(volatile const int some::* const&&         );

    dCHECK(volatile const int some::* volatile        );
    dCHECK(volatile const int some::* volatile&       );
    dRVAL_(volatile const int some::* volatile&&      );

    dCHECK(volatile const int some::* volatile const  );
    dCHECK(volatile const int some::* volatile const& );
    dRVAL_(volatile const int some::* volatile const&&);
}

// --- member int stress
TEST_COMPONENT(013)
{
    #ifdef dHAS_USING_ALIAS
        using arr    = int[3];
        using foo    = int(bool);
        using pfoo   = int(*)(bool);
        using arrfoo = pfoo[3];
        using method = char (some::*)(float);
    #else
        typedef  int arr[3];
        typedef  int foo(bool);
        typedef  int(*pfoo)(bool);
        typedef  pfoo arrfoo[3];
        typedef  char (some::*method)(float);
    #endif

    dCHECK(arr some::*   );
    dCHECK(foo some::*   );
    dCHECK(arrfoo some::*);
    dCHECK(pfoo some::*  );
    dCHECK(method some::*);
}

#endif
//==============================================================================
//==============================================================================
#endif // !TEST_IS_SAME

