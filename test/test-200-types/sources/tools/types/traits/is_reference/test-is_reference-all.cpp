// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-29d][22:26:12] Idrisov Denis R.
// [2021y-04m-02d][00:01:30] Idrisov Denis R.
// [2021y-04m-04d][02:49:47] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_REFERENCE

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_reference
#define dTEST_TAG all

#include <tools/types/traits.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #define dEXPRESSION(a,v) \
        me::is_reference<a>::value == v

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
                              
    dCHECK(char&          , true);
    dCHECK(const char&    , true);
    dCHECK(volatile char& , true);
                              
    dRVAL_(char&&         , true);
    dRVAL_(const char&&   , true);
    dRVAL_(volatile char&&, true);
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
    dCHECK(char*&                               , true);
    dCHECK(const char*&                         , true);
    dCHECK(volatile char*&                      , true);
    dCHECK(volatile const char*&                , true);
//------------------------------------------------------------------------------
    dCHECK(char* const&                         , true);
    dCHECK(const char* const&                   , true);
    dCHECK(volatile char* const&                , true);
    dCHECK(volatile const char* const&          , true);
//------------------------------------------------------------------------------
    dCHECK(char* volatile&                      , true);
    dCHECK(const char* volatile&                , true);
    dCHECK(volatile char* volatile&             , true);
    dCHECK(volatile const char* volatile&       , true);
//------------------------------------------------------------------------------
    dCHECK(char* volatile const&                , true);
    dCHECK(const char* volatile const&          , true);
    dCHECK(volatile char* volatile const&       , true);
    dCHECK(volatile const char* volatile const& , true);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dRVAL_(char*&&                              , true);
    dRVAL_(const char*&&                        , true);
    dRVAL_(volatile char*&&                     , true);
    dRVAL_(volatile const char*&&               , true);
//------------------------------------------------------------------------------
    dRVAL_(char* const&&                        , true);
    dRVAL_(const char* const&&                  , true);
    dRVAL_(volatile char* const&&               , true);
    dRVAL_(volatile const char* const&&         , true);
//------------------------------------------------------------------------------
    dRVAL_(char* volatile&&                     , true);
    dRVAL_(const char* volatile&&               , true);
    dRVAL_(volatile char* volatile&&            , true);
    dRVAL_(volatile const char* volatile&&      , true);
//------------------------------------------------------------------------------
    dRVAL_(char* volatile const&&               , true);
    dRVAL_(const char* volatile const&&         , true);
    dRVAL_(volatile char* volatile const&&      , true);
    dRVAL_(volatile const char* volatile const&&, true);
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
    dCHECK(char**&                               , true);
    dCHECK(const char**&                         , true);
    dCHECK(volatile char**&                      , true);
    dCHECK(volatile const char**&                , true);
//------------------------------------------------------------------------------
    dCHECK(char** const&                         , true);
    dCHECK(const char** const&                   , true);
    dCHECK(volatile char** const&                , true);
    dCHECK(volatile const char** const&          , true);
//------------------------------------------------------------------------------
    dCHECK(char** volatile&                      , true);
    dCHECK(const char** volatile&                , true);
    dCHECK(volatile char** volatile&             , true);
    dCHECK(volatile const char** volatile&       , true);
//------------------------------------------------------------------------------
    dCHECK(char** volatile const&                , true);
    dCHECK(const char** volatile const&          , true);
    dCHECK(volatile char** volatile const&       , true);
    dCHECK(volatile const char** volatile const& , true);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dRVAL_(char**&&                              , true);
    dRVAL_(const char**&&                        , true);
    dRVAL_(volatile char**&&                     , true);
    dRVAL_(volatile const char**&&               , true);
//------------------------------------------------------------------------------
    dRVAL_(char** const&&                        , true);
    dRVAL_(const char** const&&                  , true);
    dRVAL_(volatile char** const&&               , true);
    dRVAL_(volatile const char** const&&         , true);
//------------------------------------------------------------------------------
    dRVAL_(char** volatile&&                     , true);
    dRVAL_(const char** volatile&&               , true);
    dRVAL_(volatile char** volatile&&            , true);
    dRVAL_(volatile const char** volatile&&      , true);
//------------------------------------------------------------------------------
    dRVAL_(char** volatile const&&               , true);
    dRVAL_(const char** volatile const&&         , true);
    dRVAL_(volatile char** volatile const&&      , true);
    dRVAL_(volatile const char** volatile const&&, true);
}

// --- pointers stress
TEST_COMPONENT(003)
{
    dCHECK(char** const                     , false);
    dCHECK(char* const* const               , false);
    dCHECK(char* const* const&              , true);

    dRVAL_(char* const** const&&            , true);
    dRVAL_(char*** const* const** const&&   , true);
    dRVAL_(char*** volatile* const** const&&, true);
    dRVAL_(char*** const* volatile** const&&, true);
}

// --- arrays[255]
TEST_COMPONENT(004)
{
    dCHECK(char[255]                       , false);
    dCHECK(char(&)[255]                    , true);
    dRVAL_(char(&&)[255]                   , true);
    dCHECK(char(*)[255]                    , false);
    dCHECK(char(*&)[255]                   , true);
//------------------------------------------------------------------------------
    dCHECK(const char[255]                 , false);
    dCHECK(const char(&)[255]              , true);
    dRVAL_(const char(&&)[255]             , true);
    dCHECK(const char(*)[255]              , false);
    dCHECK(const char(*&)[255]             , true);
//------------------------------------------------------------------------------
    dCHECK(volatile char[255]              , false);
    dCHECK(volatile char(&)[255]           , true);
    dRVAL_(volatile char(&&)[255]          , true);
    dCHECK(volatile char(*)[255]           , false);
    dCHECK(volatile char(*&)[255]          , true);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[255]        , false);
    dCHECK(volatile const char(&)[255]     , true);
    dRVAL_(volatile const char(&&)[255]    , true);
    dCHECK(volatile const char(*)[255]     , false);
    dCHECK(volatile const char(*&)[255]    , true);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char[1][2][3]                   , false);
    dCHECK(char(&)[1][2][3]                , true);
    dRVAL_(char(&&)[1][2][3]               , true);
    dCHECK(char(*)[1][2][3]                , false);
    dCHECK(char(*&)[1][2][3]               , true);
//------------------------------------------------------------------------------
    dCHECK(const char[1][2][3]             , false);
    dCHECK(const char(&)[1][2][3]          , true);
    dRVAL_(const char(&&)[1][2][3]         , true);
    dCHECK(const char(*)[1][2][3]          , false);
    dCHECK(const char(*&)[1][2][3]         , true);
//------------------------------------------------------------------------------
    dCHECK(volatile char[1][2][3]          , false);
    dCHECK(volatile char(&)[1][2][3]       , true);
    dRVAL_(volatile char(&&)[1][2][3]      , true);
    dCHECK(volatile char(*)[1][2][3]       , false);
    dCHECK(volatile char(*&)[1][2][3]      , true);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[1][2][3]    , false);
    dCHECK(volatile const char(&)[1][2][3] , true);
    dRVAL_(volatile const char(&&)[1][2][3], true);
    dCHECK(volatile const char(*)[1][2][3] , false);
    dCHECK(volatile const char(*&)[1][2][3], true);
}

// --- arrays[]
#ifdef dHAS_ARRAY_EMPTY_SIZE
TEST_COMPONENT(005)
{
    dCHECK(wchar_t[]                      , false);
    dCHECK(char[]                         , false);
    dCHECK(char(&)[]                      , true);
    dRVAL_(char(&&)[]                     , true);
    dCHECK(char(*)[]                      , false);
    dCHECK(char(*&)[]                     , true);
//------------------------------------------------------------------------------
    dCHECK(const char[]                   , false);
    dCHECK(const char(&)[]                , true);
    dRVAL_(const char(&&)[]               , true);
    dCHECK(const char(*)[]                , false);
    dCHECK(const char(*&)[]               , true);
//------------------------------------------------------------------------------
    dCHECK(volatile char[]                , false);
    dCHECK(volatile char(&)[]             , true);
    dRVAL_(volatile char(&&)[]            , true);
    dCHECK(volatile char(*)[]             , false);
    dCHECK(volatile char(*&)[]            , true);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[]          , false);
    dCHECK(volatile const char(&)[]       , true);
    dRVAL_(volatile const char(&&)[]      , true);
    dCHECK(volatile const char(*)[]       , false);
    dCHECK(volatile const char(*&)[]      , true);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char[][2][3]                   , false);
    dCHECK(char(&)[][2][3]                , true);
    dRVAL_(char(&&)[][2][3]               , true);
    dCHECK(char(*)[][2][3]                , false);
    dCHECK(char(*&)[][2][3]               , true);
//------------------------------------------------------------------------------
    dCHECK(const char[][2][3]             , false);
    dCHECK(const char(&)[][2][3]          , true);
    dRVAL_(const char(&&)[][2][3]         , true);
    dCHECK(const char(*)[][2][3]          , false);
    dCHECK(const char(*&)[][2][3]         , true);
//------------------------------------------------------------------------------
    dCHECK(volatile char[][2][3]          , false);
    dCHECK(volatile char(&)[][2][3]       , true);
    dRVAL_(volatile char(&&)[][2][3]      , true);
    dCHECK(volatile char(*)[][2][3]       , false);
    dCHECK(volatile char(*&)[][2][3]      , true);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[][2][3]    , false);
    dCHECK(volatile const char(&)[][2][3] , true);
    dRVAL_(volatile const char(&&)[][2][3], true);
    dCHECK(volatile const char(*)[][2][3] , false);
    dCHECK(volatile const char(*&)[][2][3], true);
}
#endif

// --- arrays stress
TEST_COMPONENT(006)
{
    dCHECK(char*[1][2][3]                                       , false);
    dCHECK(char*(*)[1][2][3]                                    , false);
    dCHECK(char*(&)[1][2][3]                                    , true);
    dCHECK(char*(*&)[1][2][3]                                   , true);
//------------------------------------------------------------------------------
    dCHECK(const char* const(*&)[1][2][3]                       , true);
    dCHECK(const char* const(**&)[1][2][3]                      , true);
    dCHECK(const char* const(* const* const&)[1][2][3]          , true);
    dCHECK(const char* const(* volatile* const&)[1][2][3]       , true);
    dRVAL_(volatile char* const(* volatile* volatile&&)[1][2][3], true);
}

// --- arrays[0]
#ifdef dHAS_ZERO_ARRAY
TEST_COMPONENT(007)
{
    dCHECK(wchar_t[0]                      , false);
    dCHECK(char[0]                         , false);
    dCHECK(char(&)[0]                      , true);
    dRVAL_(char(&&)[0]                     , true);
    dCHECK(char(*)[0]                      , false);
    dCHECK(char(*&)[0]                     , true);
//------------------------------------------------------------------------------
    dCHECK(const char[0]                   , false);
    dCHECK(const char(&)[0]                , true);
    dRVAL_(const char(&&)[0]               , true);
    dCHECK(const char(*)[0]                , false);
    dCHECK(const char(*&)[0]               , true);
//------------------------------------------------------------------------------
    dCHECK(volatile char[0]                , false);
    dCHECK(volatile char(&)[0]             , true);
    dRVAL_(volatile char(&&)[0]            , true);
    dCHECK(volatile char(*)[0]             , false);
    dCHECK(volatile char(*&)[0]            , true);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[0]          , false);
    dCHECK(volatile const char(&)[0]       , true);
    dRVAL_(volatile const char(&&)[0]      , true);
    dCHECK(volatile const char(*)[0]       , false);
    dCHECK(volatile const char(*&)[0]      , true);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char[0][2][3]                   , false);
    dCHECK(char(&)[0][2][3]                , true);
    dRVAL_(char(&&)[0][2][3]               , true);
    dCHECK(char(*)[0][2][3]                , false);
    dCHECK(char(*&)[0][2][3]               , true);
//------------------------------------------------------------------------------
    dCHECK(const char[0][2][3]             , false);
    dCHECK(const char(&)[0][2][3]          , true);
    dRVAL_(const char(&&)[0][2][3]         , true);
    dCHECK(const char(*)[0][2][3]          , false);
    dCHECK(const char(*&)[0][2][3]         , true);
//------------------------------------------------------------------------------
    dCHECK(volatile char[0][2][3]          , false);
    dCHECK(volatile char(&)[0][2][3]       , true);
    dRVAL_(volatile char(&&)[0][2][3]      , true);
    dCHECK(volatile char(*)[0][2][3]       , false);
    dCHECK(volatile char(*&)[0][2][3]      , true);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[0][2][3]    , false);
    dCHECK(volatile const char(&)[0][2][3] , true);
    dRVAL_(volatile const char(&&)[0][2][3], true);
    dCHECK(volatile const char(*)[0][2][3] , false);
    dCHECK(volatile const char(*&)[0][2][3], true);
}
#endif // !dHAS_ZERO_ARRAY

// --- functions int()
TEST_COMPONENT(008)
{
    dCHECK(int()                    , false);
    dCHECK(int(&)()                 , true);
    dRVAL_(int(&&)()                , true);
    
    dCHECK(int(*)()                 , false);
    dCHECK(int(* const)()           , false);
    dCHECK(int(* volatile)()        , false);
    dCHECK(int(* volatile const)()  , false);
    
    dCHECK(int(*&)()                , true);
    dCHECK(int(* const&)()          , true);
    dCHECK(int(* volatile&)()       , true);
    dCHECK(int(* volatile const&)() , true);
    
    dRVAL_(int(*&&)()               , true);
    dRVAL_(int(* const&&)()         , true);
    dRVAL_(int(* volatile&&)()      , true);
    dRVAL_(int(* volatile const&&)(), true);
}

// --- function-pointers
TEST_COMPONENT(009)
{                  
    dCHECK(int(* const*&)(bool, char)                   , true);
    dCHECK(int(** const*&)(bool, char)                  , true);
    dCHECK(int(* const* const*&)(bool, char)            , true);
    dCHECK(int(* volatile* volatile*&)(bool, char)      , true);
    dCHECK(int(* volatile* volatile const*&)(bool, char), true);
}

// --- abominable int() const
#ifdef dHAS_ABOMINABLE
TEST_COMPONENT(010)
{
    dCHECK(int()                   , false);
    dCHECK(int() const             , false);

    dCHECK(int() volatile          , false);
    dCHECK(int() volatile const    , false);

    dCHECK(int() &                 , false);
    dCHECK(int() const &           , false);
    dCHECK(int() volatile &        , false);
    dCHECK(int() volatile const &  , false);

    dRVAL_(int() &&                , false);
    dRVAL_(int() const &&          , false);
    dRVAL_(int() volatile &&       , false);
    dRVAL_(int() volatile const && , false);
}
#endif

// --- method int(some::*)()
TEST_COMPONENT(011)
{
    dCHECK(int(some::*)()                 , false);
    dCHECK(int(some::*&)()                , true);
    dRVAL_(int(some::*&&)()               , true);
                                          
    dCHECK(int(some::* const)()           , false);
    dCHECK(int(some::* volatile)()        , false);
    dCHECK(int(some::* volatile const)()  , false);

    dCHECK(int(some::* const&)()          , true);
    dCHECK(int(some::* volatile&)()       , true);
    dCHECK(int(some::* volatile const&)() , true);

    dRVAL_(int(some::* const&&)()         , true);
    dRVAL_(int(some::* volatile&&)()      , true);
    dRVAL_(int(some::* volatile const&&)(), true);
}

// --- member int
TEST_COMPONENT(012)
{
    dCHECK(int some::*                                , false);
    dCHECK(int some::*&                               , true);
    dRVAL_(int some::*&&                              , true);

    dCHECK(int some::* const                          , false);
    dCHECK(int some::* const&                         , true);
    dRVAL_(int some::* const&&                        , true);

    dCHECK(int some::* volatile                       , false);
    dCHECK(int some::* volatile&                      , true);
    dRVAL_(int some::* volatile&&                     , true);

    dCHECK(int some::* volatile const                 , false);
    dCHECK(int some::* volatile const&                , true);
    dRVAL_(int some::* volatile const&&               , true);
//------------------------------------------------------------------------------
    dCHECK(const int some::*                          , false);
    dCHECK(const int some::*&                         , true);
    dRVAL_(const int some::*&&                        , true);
                                                      
    dCHECK(const int some::* const                    , false);
    dCHECK(const int some::* const&                   , true);
    dRVAL_(const int some::* const&&                  , true);

    dCHECK(const int some::* volatile                 , false);
    dCHECK(const int some::* volatile&                , true);
    dRVAL_(const int some::* volatile&&               , true);

    dCHECK(const int some::* volatile const           , false);
    dCHECK(const int some::* volatile const&          , true);
    dRVAL_(const int some::* volatile const&&         , true);
//------------------------------------------------------------------------------
    dCHECK(volatile int some::*                       , false);
    dCHECK(volatile int some::*&                      , true);
    dRVAL_(volatile int some::*&&                     , true);
                                                      
    dCHECK(volatile int some::* const                 , false);
    dCHECK(volatile int some::* const&                , true);
    dRVAL_(volatile int some::* const&&               , true);
                                                      
    dCHECK(volatile int some::* volatile              , false);
    dCHECK(volatile int some::* volatile&             , true);
    dRVAL_(volatile int some::* volatile&&            , true);
                                                      
    dCHECK(volatile int some::* volatile const        , false);
    dCHECK(volatile int some::* volatile const&       , true);
    dRVAL_(volatile int some::* volatile const&&      , true);
//------------------------------------------------------------------------------
    dCHECK(volatile const int some::*                 , false);
    dCHECK(volatile const int some::*&                , true);
    dRVAL_(volatile const int some::*&&               , true);
                                                      
    dCHECK(volatile const int some::* const           , false);
    dCHECK(volatile const int some::* const&          , true);
    dRVAL_(volatile const int some::* const&&         , true);
                                                      
    dCHECK(volatile const int some::* volatile        , false);
    dCHECK(volatile const int some::* volatile&       , true);
    dRVAL_(volatile const int some::* volatile&&      , true);
                                                      
    dCHECK(volatile const int some::* volatile const  , false);
    dCHECK(volatile const int some::* volatile const& , true);
    dRVAL_(volatile const int some::* volatile const&&, true);
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

    dCHECK(arr some::*   , false);
    dCHECK(foo some::*   , false);
    dCHECK(arrfoo some::*, false);
    dCHECK(pfoo some::*  , false);
    dCHECK(method some::*, false);
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_REFERENCE

