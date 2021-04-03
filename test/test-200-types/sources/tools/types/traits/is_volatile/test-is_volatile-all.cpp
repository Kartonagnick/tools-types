// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-29d][22:26:12] Idrisov Denis R.
// [2021y-04m-04d][02:49:47] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_VOLATILE

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_volatile
#define dTEST_TAG all

#include <tools/types/traits.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #define dEXPRESSION(a,v) \
        me::is_volatile<a>::value == v

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
    dCHECK(unsigned char           , false);
    dCHECK(const unsigned char     , false);
    dCHECK(volatile unsigned char  , true);
                              
    dCHECK(unsigned char&          , false);
    dCHECK(const unsigned char&    , false);
    dCHECK(volatile unsigned char& , false);
                              
    dRVAL_(unsigned char&&         , false);
    dRVAL_(const unsigned char&&   , false);
    dRVAL_(volatile unsigned char&&, false);
//------------------------------------------------------------------------------
    dCHECK(signed char             , false);
    dCHECK(const signed char       , false);
    dCHECK(volatile signed char    , true);
                                   
    dCHECK(signed char&            , false);
    dCHECK(const signed char&      , false);
    dCHECK(volatile signed char&   , false);
                                   
    dRVAL_(signed char&&           , false);
    dRVAL_(const signed char&&     , false);
    dRVAL_(volatile signed char&&  , false);
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
    dCHECK(char* volatile                       , true);
    dCHECK(const char* volatile                 , true);
    dCHECK(volatile char* volatile              , true);
    dCHECK(volatile const char* volatile        , true);
//------------------------------------------------------------------------------
    dCHECK(char* volatile const                 , true);
    dCHECK(const char* volatile const           , true);
    dCHECK(volatile char* volatile const        , true);
    dCHECK(volatile const char* volatile const  , true);
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
    dCHECK(char** volatile                       , true);
    dCHECK(const char** volatile                 , true);
    dCHECK(volatile char** volatile              , true);
    dCHECK(volatile const char** volatile        , true);
//------------------------------------------------------------------------------
    dCHECK(char** volatile const                 , true);
    dCHECK(const char** volatile const           , true);
    dCHECK(volatile char** volatile const        , true);
    dCHECK(volatile const char** volatile const  , true);
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
    dCHECK(char[255]                       , false);
    dCHECK(char(&)[255]                    , false);
    dRVAL_(char(&&)[255]                   , false);
    dCHECK(char(*)[255]                    , false);
    dCHECK(char(*&)[255]                   , false);
//------------------------------------------------------------------------------
    dCHECK(const char[255]                 , false);
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
    dCHECK(char[1][2][3]                   , false);
    dCHECK(char(&)[1][2][3]                , false);
    dRVAL_(char(&&)[1][2][3]               , false);
    dCHECK(char(*)[1][2][3]                , false);
    dCHECK(char(*&)[1][2][3]               , false);
//------------------------------------------------------------------------------
    dCHECK(const char[1][2][3]             , false);
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
    dCHECK(wchar_t[]                      , false);
    dCHECK(char[]                         , false);
    dCHECK(char(&)[]                      , false);
    dRVAL_(char(&&)[]                     , false);
    dCHECK(char(*)[]                      , false);
    dCHECK(char(*&)[]                     , false);
//------------------------------------------------------------------------------
    dCHECK(const char[]                   , false);
    dCHECK(const char(&)[]                , false);
    dRVAL_(const char(&&)[]               , false);
    dCHECK(const char(*)[]                , false);
    dCHECK(const char(*&)[]               , false);
//------------------------------------------------------------------------------
    dCHECK(volatile char[]                , true);
    dCHECK(volatile char(&)[]             , false);
    dRVAL_(volatile char(&&)[]            , false);
    dCHECK(volatile char(*)[]             , false);
    dCHECK(volatile char(*&)[]            , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[]          , true);
    dCHECK(volatile const char(&)[]       , false);
    dRVAL_(volatile const char(&&)[]      , false);
    dCHECK(volatile const char(*)[]       , false);
    dCHECK(volatile const char(*&)[]      , false);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char[][2][3]                   , false);
    dCHECK(char(&)[][2][3]                , false);
    dRVAL_(char(&&)[][2][3]               , false);
    dCHECK(char(*)[][2][3]                , false);
    dCHECK(char(*&)[][2][3]               , false);
//------------------------------------------------------------------------------
    dCHECK(const char[][2][3]             , false);
    dCHECK(const char(&)[][2][3]          , false);
    dRVAL_(const char(&&)[][2][3]         , false);
    dCHECK(const char(*)[][2][3]          , false);
    dCHECK(const char(*&)[][2][3]         , false);
//------------------------------------------------------------------------------
    dCHECK(volatile char[][2][3]          , true);
    dCHECK(volatile char(&)[][2][3]       , false);
    dRVAL_(volatile char(&&)[][2][3]      , false);
    dCHECK(volatile char(*)[][2][3]       , false);
    dCHECK(volatile char(*&)[][2][3]      , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[][2][3]    , true);
    dCHECK(volatile const char(&)[][2][3] , false);
    dRVAL_(volatile const char(&&)[][2][3], false);
    dCHECK(volatile const char(*)[][2][3] , false);
    dCHECK(volatile const char(*&)[][2][3], false);
}
#endif

// --- arrays stress
TEST_COMPONENT(006)
{
    dCHECK(char*[1][2][3]                                       , false);
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

// --- arrays[0]
#ifdef dHAS_ZERO_ARRAY
TEST_COMPONENT(007)
{
    dCHECK(wchar_t[0]                      , false);
    dCHECK(char[0]                         , false);
    dCHECK(char(&)[0]                      , false);
    dRVAL_(char(&&)[0]                     , false);
    dCHECK(char(*)[0]                      , false);
    dCHECK(char(*&)[0]                     , false);
//------------------------------------------------------------------------------
    dCHECK(const char[0]                   , false);
    dCHECK(const char(&)[0]                , false);
    dRVAL_(const char(&&)[0]               , false);
    dCHECK(const char(*)[0]                , false);
    dCHECK(const char(*&)[0]               , false);
//------------------------------------------------------------------------------
    dCHECK(volatile char[0]                , true);
    dCHECK(volatile char(&)[0]             , false);
    dRVAL_(volatile char(&&)[0]            , false);
    dCHECK(volatile char(*)[0]             , false);
    dCHECK(volatile char(*&)[0]            , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[0]          , true);
    dCHECK(volatile const char(&)[0]       , false);
    dRVAL_(volatile const char(&&)[0]      , false);
    dCHECK(volatile const char(*)[0]       , false);
    dCHECK(volatile const char(*&)[0]      , false);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dCHECK(char[0][2][3]                   , false);
    dCHECK(char(&)[0][2][3]                , false);
    dRVAL_(char(&&)[0][2][3]               , false);
    dCHECK(char(*)[0][2][3]                , false);
    dCHECK(char(*&)[0][2][3]               , false);
//------------------------------------------------------------------------------
    dCHECK(const char[0][2][3]             , false);
    dCHECK(const char(&)[0][2][3]          , false);
    dRVAL_(const char(&&)[0][2][3]         , false);
    dCHECK(const char(*)[0][2][3]          , false);
    dCHECK(const char(*&)[0][2][3]         , false);
//------------------------------------------------------------------------------
    dCHECK(volatile char[0][2][3]          , true);
    dCHECK(volatile char(&)[0][2][3]       , false);
    dRVAL_(volatile char(&&)[0][2][3]      , false);
    dCHECK(volatile char(*)[0][2][3]       , false);
    dCHECK(volatile char(*&)[0][2][3]      , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const char[0][2][3]    , true);
    dCHECK(volatile const char(&)[0][2][3] , false);
    dRVAL_(volatile const char(&&)[0][2][3], false);
    dCHECK(volatile const char(*)[0][2][3] , false);
    dCHECK(volatile const char(*&)[0][2][3], false);
}
#endif // !dHAS_ZERO_ARRAY

// --- functions int()
TEST_COMPONENT(008)
{
    dCHECK(int()                    , false);
    dCHECK(int(&)()                 , false);
    dRVAL_(int(&&)()                , false);

    dCHECK(int(*)()                 , false);
    dCHECK(int(* const)()           , false);
    dCHECK(int(* volatile)()        , true);
    dCHECK(int(* volatile const)()  , true);

    dCHECK(int(*&)()                , false);
    dCHECK(int(* const&)()          , false);
    dCHECK(int(* volatile&)()       , false);
    dCHECK(int(* volatile const&)() , false);

    dRVAL_(int(*&&)()               , false);
    dRVAL_(int(* const&&)()         , false);
    dRVAL_(int(* volatile&&)()      , false);
    dRVAL_(int(* volatile const&&)(), false);
}

// --- function-pointers
TEST_COMPONENT(009)
{                  
    dCHECK(int(* const*&)(bool, char)                   , false);
    dCHECK(int(** const*&)(bool, char)                  , false);
    dCHECK(int(* const* const*&)(bool, char)            , false);
    dCHECK(int(* volatile* volatile*&)(bool, char)      , false);
    dCHECK(int(* volatile* volatile const*&)(bool, char), false);
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
    dCHECK(int(some::*&)()                , false);
    dRVAL_(int(some::*&&)()               , false);
                                          
    dCHECK(int(some::* const)()           , false);
    dCHECK(int(some::* volatile)()        , true);
    dCHECK(int(some::* volatile const)()  , true);
                                          
    dCHECK(int(some::* const&)()          , false);
    dCHECK(int(some::* volatile&)()       , false);
    dCHECK(int(some::* volatile const&)() , false);
                                          
    dRVAL_(int(some::* const&&)()         , false);
    dRVAL_(int(some::* volatile&&)()      , false);
    dRVAL_(int(some::* volatile const&&)(), false);
}

// --- member int
TEST_COMPONENT(012)
{
    dCHECK(int some::*                                , false);
    dCHECK(int some::*&                               , false);
    dRVAL_(int some::*&&                              , false);
                                                      
    dCHECK(int some::* const                          , false);
    dCHECK(int some::* const&                         , false);
    dRVAL_(int some::* const&&                        , false);
                                                      
    dCHECK(int some::* volatile                       , true);
    dCHECK(int some::* volatile&                      , false);
    dRVAL_(int some::* volatile&&                     , false);
                                                      
    dCHECK(int some::* volatile const                 , true);
    dCHECK(int some::* volatile const&                , false);
    dRVAL_(int some::* volatile const&&               , false);
//------------------------------------------------------------------------------
    dCHECK(const int some::*                          , false);
    dCHECK(const int some::*&                         , false);
    dRVAL_(const int some::*&&                        , false);
                                                      
    dCHECK(const int some::* const                    , false);
    dCHECK(const int some::* const&                   , false);
    dRVAL_(const int some::* const&&                  , false);
                                                      
    dCHECK(const int some::* volatile                 , true);
    dCHECK(const int some::* volatile&                , false);
    dRVAL_(const int some::* volatile&&               , false);
                                                      
    dCHECK(const int some::* volatile const           , true);
    dCHECK(const int some::* volatile const&          , false);
    dRVAL_(const int some::* volatile const&&         , false);
//------------------------------------------------------------------------------
    dCHECK(volatile int some::*                       , false);
    dCHECK(volatile int some::*&                      , false);
    dRVAL_(volatile int some::*&&                     , false);
                                                      
    dCHECK(volatile int some::* const                 , false);
    dCHECK(volatile int some::* const&                , false);
    dRVAL_(volatile int some::* const&&               , false);
                                                      
    dCHECK(volatile int some::* volatile              , true);
    dCHECK(volatile int some::* volatile&             , false);
    dRVAL_(volatile int some::* volatile&&            , false);
                                                      
    dCHECK(volatile int some::* volatile const        , true);
    dCHECK(volatile int some::* volatile const&       , false);
    dRVAL_(volatile int some::* volatile const&&      , false);
//------------------------------------------------------------------------------
    dCHECK(volatile const int some::*                 , false);
    dCHECK(volatile const int some::*&                , false);
    dRVAL_(volatile const int some::*&&               , false);
                                                      
    dCHECK(volatile const int some::* const           , false);
    dCHECK(volatile const int some::* const&          , false);
    dRVAL_(volatile const int some::* const&&         , false);
                                                      
    dCHECK(volatile const int some::* volatile        , true);
    dCHECK(volatile const int some::* volatile&       , false);
    dRVAL_(volatile const int some::* volatile&&      , false);
                                                      
    dCHECK(volatile const int some::* volatile const  , true);
    dCHECK(volatile const int some::* volatile const& , false);
    dRVAL_(volatile const int some::* volatile const&&, false);
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
#endif // !TEST_IS_VOLATILE

