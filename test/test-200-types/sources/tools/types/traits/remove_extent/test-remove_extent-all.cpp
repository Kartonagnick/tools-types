// [2021y-04m-02d][00:01:30] Idrisov Denis R.
// [2021y-04m-04d][02:49:47] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_REMOVE_EXTENSION

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD remove_extent
#define dTEST_TAG all

#include <tools/types/traits.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #define dVAL(a) \
        typename me::remove_extent<a>::type

    #define dEXPRESSION(a,b) \
        me::is_same<dVAL(a), b>::value 

    #define dTEST_TRUE(a,b)       \
        dSTATIC_ASSERT(           \
            ERROR_MUST_BE_TRUE,   \
            dEXPRESSION(a,b)      \
        )

    #ifdef dHAS_RVALUE_REFERENCE
        #define dTEST_RVAL(a,b) dTEST_TRUE(a,b)
    #else
        #define dTEST_RVAL(a,b) void()
    #endif

    struct some;

} // namespace

//==============================================================================
//==============================================================================
// --- char/ char&/ char&&
TEST_COMPONENT(000)
{
    dTEST_TRUE(char           , char            );
    dTEST_TRUE(const char     , const char      );
    dTEST_TRUE(volatile char  , volatile char   );

    dTEST_TRUE(char&          , char&           );
    dTEST_TRUE(const char&    , const char&     );
    dTEST_TRUE(volatile char& , volatile char&  );

    dTEST_RVAL(char&&         , char&&          );
    dTEST_RVAL(const char&&   , const char&&    );
    dTEST_RVAL(volatile char&&, volatile char&& );
}

// --- pointers*
TEST_COMPONENT(001)
{
    dTEST_TRUE(char*                                , char*               );
    dTEST_TRUE(const char*                          , const char*         );
    dTEST_TRUE(volatile char*                       , volatile char*      );
    dTEST_TRUE(volatile const char*                 , volatile const char*);
//------------------------------------------------------------------------------
    dTEST_TRUE(char* const                          , char* const               );
    dTEST_TRUE(const char* const                    , const char* const         );
    dTEST_TRUE(volatile char* const                 , volatile char* const      );
    dTEST_TRUE(volatile const char* const           , volatile const char* const);
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile                       , char* volatile               );
    dTEST_TRUE(const char* volatile                 , const char* volatile         );
    dTEST_TRUE(volatile char* volatile              , volatile char* volatile      );
    dTEST_TRUE(volatile const char* volatile        , volatile const char* volatile);
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile const                 , char* volatile const               );
    dTEST_TRUE(const char* volatile const           , const char* volatile const         );
    dTEST_TRUE(volatile char* volatile const        , volatile char* volatile const      );
    dTEST_TRUE(volatile const char* volatile const  , volatile const char* volatile const);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char*&                               , char*&                               );
    dTEST_TRUE(const char*&                         , const char*&                         );
    dTEST_TRUE(volatile char*&                      , volatile char*&                      );
    dTEST_TRUE(volatile const char*&                , volatile const char*&                );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* const&                         , char* const&                         );
    dTEST_TRUE(const char* const&                   , const char* const&                   );
    dTEST_TRUE(volatile char* const&                , volatile char* const&                );
    dTEST_TRUE(volatile const char* const&          , volatile const char* const&          );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile&                      , char* volatile&                      );
    dTEST_TRUE(const char* volatile&                , const char* volatile&                );
    dTEST_TRUE(volatile char* volatile&             , volatile char* volatile&             );
    dTEST_TRUE(volatile const char* volatile&       , volatile const char* volatile&       );
//------------------------------------------------------------------------------           
    dTEST_TRUE(char* volatile const&                , char* volatile const&                );
    dTEST_TRUE(const char* volatile const&          , const char* volatile const&          );
    dTEST_TRUE(volatile char* volatile const&       , volatile char* volatile const&       );
    dTEST_TRUE(volatile const char* volatile const& , volatile const char* volatile const& );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_RVAL(char*&&                              , char*&&                              );
    dTEST_RVAL(const char*&&                        , const char*&&                        );
    dTEST_RVAL(volatile char*&&                     , volatile char*&&                     );
    dTEST_RVAL(volatile const char*&&               , volatile const char*&&               );
//------------------------------------------------------------------------------
    dTEST_RVAL(char* const&&                        , char* const&&                        );
    dTEST_RVAL(const char* const&&                  , const char* const&&                  );
    dTEST_RVAL(volatile char* const&&               , volatile char* const&&               );
    dTEST_RVAL(volatile const char* const&&         , volatile const char* const&&         );
//------------------------------------------------------------------------------
    dTEST_RVAL(char* volatile&&                     , char* volatile&&                     );
    dTEST_RVAL(const char* volatile&&               , const char* volatile&&               );
    dTEST_RVAL(volatile char* volatile&&            , volatile char* volatile&&            );
    dTEST_RVAL(volatile const char* volatile&&      , volatile const char* volatile&&      );
//------------------------------------------------------------------------------
    dTEST_RVAL(char* volatile const&&               , char* volatile const&&               );
    dTEST_RVAL(const char* volatile const&&         , const char* volatile const&&         );
    dTEST_RVAL(volatile char* volatile const&&      , volatile char* volatile const&&      );
    dTEST_RVAL(volatile const char* volatile const&&, volatile const char* volatile const&&);
}

// --- pointers**
TEST_COMPONENT(002)
{
    dTEST_TRUE(char**                                , char**                );
    dTEST_TRUE(const char**                          , const char**          );
    dTEST_TRUE(volatile char**                       , volatile char**       );
    dTEST_TRUE(volatile const char**                 , volatile const char** );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** const                          , char** const                );
    dTEST_TRUE(const char** const                    , const char** const          );
    dTEST_TRUE(volatile char** const                 , volatile char** const       );
    dTEST_TRUE(volatile const char** const           , volatile const char** const );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile                       , char** volatile                );
    dTEST_TRUE(const char** volatile                 , const char** volatile          );
    dTEST_TRUE(volatile char** volatile              , volatile char** volatile       );
    dTEST_TRUE(volatile const char** volatile        , volatile const char** volatile );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile const                 , char** volatile const                );
    dTEST_TRUE(const char** volatile const           , const char** volatile const          );
    dTEST_TRUE(volatile char** volatile const        , volatile char** volatile const       );
    dTEST_TRUE(volatile const char** volatile const  , volatile const char** volatile const );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char**&                               , char**&                              );
    dTEST_TRUE(const char**&                         , const char**&                        );
    dTEST_TRUE(volatile char**&                      , volatile char**&                     );
    dTEST_TRUE(volatile const char**&                , volatile const char**&               );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** const&                         , char** const&                        );
    dTEST_TRUE(const char** const&                   , const char** const&                  );
    dTEST_TRUE(volatile char** const&                , volatile char** const&               );
    dTEST_TRUE(volatile const char** const&          , volatile const char** const&         );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile&                      , char** volatile&                     );
    dTEST_TRUE(const char** volatile&                , const char** volatile&               );
    dTEST_TRUE(volatile char** volatile&             , volatile char** volatile&            );
    dTEST_TRUE(volatile const char** volatile&       , volatile const char** volatile&      );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile const&                , char** volatile const&               );
    dTEST_TRUE(const char** volatile const&          , const char** volatile const&         );
    dTEST_TRUE(volatile char** volatile const&       , volatile char** volatile const&      );
    dTEST_TRUE(volatile const char** volatile const& , volatile const char** volatile const&);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_RVAL(char**&&                              , char**&&                              );
    dTEST_RVAL(const char**&&                        , const char**&&                        );
    dTEST_RVAL(volatile char**&&                     , volatile char**&&                     );
    dTEST_RVAL(volatile const char**&&               , volatile const char**&&               );
//------------------------------------------------------------------------------
    dTEST_RVAL(char** const&&                        , char** const&&                        );
    dTEST_RVAL(const char** const&&                  , const char** const&&                  );
    dTEST_RVAL(volatile char** const&&               , volatile char** const&&               );
    dTEST_RVAL(volatile const char** const&&         , volatile const char** const&&         );
//------------------------------------------------------------------------------
    dTEST_RVAL(char** volatile&&                     , char** volatile&&                     );
    dTEST_RVAL(const char** volatile&&               , const char** volatile&&               );
    dTEST_RVAL(volatile char** volatile&&            , volatile char** volatile&&            );
    dTEST_RVAL(volatile const char** volatile&&      , volatile const char** volatile&&      );
//------------------------------------------------------------------------------
    dTEST_RVAL(char** volatile const&&               , char** volatile const&&               );
    dTEST_RVAL(const char** volatile const&&         , const char** volatile const&&         );
    dTEST_RVAL(volatile char** volatile const&&      , volatile char** volatile const&&      );
    dTEST_RVAL(volatile const char** volatile const&&, volatile const char** volatile const&&);
}

// --- pointers stress
TEST_COMPONENT(003)
{
    dTEST_TRUE(char** const                     , char** const        );
    dTEST_TRUE(char* const* const               , char* const* const  );
    dTEST_TRUE(char* const* const&              , char* const* const& );

    dTEST_RVAL(char* const** const&&            , char* const** const&&            );
    dTEST_RVAL(char*** const* const** const&&   , char*** const* const** const&&   );
    dTEST_RVAL(char*** volatile* const** const&&, char*** volatile* const** const&&);
    dTEST_RVAL(char*** const* volatile** const&&, char*** const* volatile** const&&);
}

// --- arrays[255]
TEST_COMPONENT(004)
{
    dTEST_TRUE(char[255]                       , char         );
    dTEST_TRUE(char(&)[255]                    , char(&)[255] );
    dTEST_RVAL(char(&&)[255]                   , char(&&)[255]);
    dTEST_TRUE(char(*)[255]                    , char(*)[255] );
    dTEST_TRUE(char(*&)[255]                   , char(*&)[255]);
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[255]                 , const char         );
    dTEST_TRUE(const char(&)[255]              , const char(&)[255] );
    dTEST_RVAL(const char(&&)[255]             , const char(&&)[255]);
    dTEST_TRUE(const char(*)[255]              , const char(*)[255] );
    dTEST_TRUE(const char(*&)[255]             , const char(*&)[255]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[255]              , volatile char         );
    dTEST_TRUE(volatile char(&)[255]           , volatile char(&)[255] );
    dTEST_RVAL(volatile char(&&)[255]          , volatile char(&&)[255]);
    dTEST_TRUE(volatile char(*)[255]           , volatile char(*)[255] );
    dTEST_TRUE(volatile char(*&)[255]          , volatile char(*&)[255]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[255]        , volatile const char         );
    dTEST_TRUE(volatile const char(&)[255]     , volatile const char(&)[255] );
    dTEST_RVAL(volatile const char(&&)[255]    , volatile const char(&&)[255]);
    dTEST_TRUE(volatile const char(*)[255]     , volatile const char(*)[255] );
    dTEST_TRUE(volatile const char(*&)[255]    , volatile const char(*&)[255]);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char[1][2][3]                   , char[2][3]       );
    dTEST_TRUE(char(&)[1][2][3]                , char(&)[1][2][3] );
    dTEST_RVAL(char(&&)[1][2][3]               , char(&&)[1][2][3]);
    dTEST_TRUE(char(*)[1][2][3]                , char(*)[1][2][3] );
    dTEST_TRUE(char(*&)[1][2][3]               , char(*&)[1][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[1][2][3]             , const char[2][3]       );
    dTEST_TRUE(const char(&)[1][2][3]          , const char(&)[1][2][3] );
    dTEST_RVAL(const char(&&)[1][2][3]         , const char(&&)[1][2][3]);
    dTEST_TRUE(const char(*)[1][2][3]          , const char(*)[1][2][3] );
    dTEST_TRUE(const char(*&)[1][2][3]         , const char(*&)[1][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[1][2][3]          , volatile char[2][3]       );
    dTEST_TRUE(volatile char(&)[1][2][3]       , volatile char(&)[1][2][3] );
    dTEST_RVAL(volatile char(&&)[1][2][3]      , volatile char(&&)[1][2][3]);
    dTEST_TRUE(volatile char(*)[1][2][3]       , volatile char(*)[1][2][3] );
    dTEST_TRUE(volatile char(*&)[1][2][3]      , volatile char(*&)[1][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[1][2][3]    , volatile const char[2][3]       );
    dTEST_TRUE(volatile const char(&)[1][2][3] , volatile const char(&)[1][2][3] );
    dTEST_RVAL(volatile const char(&&)[1][2][3], volatile const char(&&)[1][2][3]);
    dTEST_TRUE(volatile const char(*)[1][2][3] , volatile const char(*)[1][2][3] );
    dTEST_TRUE(volatile const char(*&)[1][2][3], volatile const char(*&)[1][2][3]);
}

// --- arrays[]
#ifdef dHAS_ARRAY_EMPTY_SIZE
TEST_COMPONENT(005)
{
    dTEST_TRUE(wchar_t[]                      , wchar_t   );
    dTEST_TRUE(char[]                         , char      );
    dTEST_TRUE(char(&)[]                      , char(&)[] );
    dTEST_RVAL(char(&&)[]                     , char(&&)[]);
    dTEST_TRUE(char(*)[]                      , char(*)[] );
    dTEST_TRUE(char(*&)[]                     , char(*&)[]);
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[]                   , const char      );
    dTEST_TRUE(const char(&)[]                , const char(&)[] );
    dTEST_RVAL(const char(&&)[]               , const char(&&)[]);
    dTEST_TRUE(const char(*)[]                , const char(*)[] );
    dTEST_TRUE(const char(*&)[]               , const char(*&)[]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[]                , volatile char      );
    dTEST_TRUE(volatile char(&)[]             , volatile char(&)[] );
    dTEST_RVAL(volatile char(&&)[]            , volatile char(&&)[]);
    dTEST_TRUE(volatile char(*)[]             , volatile char(*)[] );
    dTEST_TRUE(volatile char(*&)[]            , volatile char(*&)[]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[]          , volatile const char      );
    dTEST_TRUE(volatile const char(&)[]       , volatile const char(&)[] );
    dTEST_RVAL(volatile const char(&&)[]      , volatile const char(&&)[]);
    dTEST_TRUE(volatile const char(*)[]       , volatile const char(*)[] );
    dTEST_TRUE(volatile const char(*&)[]      , volatile const char(*&)[]);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char[][2][3]                   , char[2][3]      );
    dTEST_TRUE(char(&)[][2][3]                , char(&)[][2][3] );
    dTEST_RVAL(char(&&)[][2][3]               , char(&&)[][2][3]);
    dTEST_TRUE(char(*)[][2][3]                , char(*)[][2][3] );
    dTEST_TRUE(char(*&)[][2][3]               , char(*&)[][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[][2][3]             , const char[2][3]      );
    dTEST_TRUE(const char(&)[][2][3]          , const char(&)[][2][3] );
    dTEST_RVAL(const char(&&)[][2][3]         , const char(&&)[][2][3]);
    dTEST_TRUE(const char(*)[][2][3]          , const char(*)[][2][3] );
    dTEST_TRUE(const char(*&)[][2][3]         , const char(*&)[][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[][2][3]          , volatile char[2][3]      );
    dTEST_TRUE(volatile char(&)[][2][3]       , volatile char(&)[][2][3] );
    dTEST_RVAL(volatile char(&&)[][2][3]      , volatile char(&&)[][2][3]);
    dTEST_TRUE(volatile char(*)[][2][3]       , volatile char(*)[][2][3] );
    dTEST_TRUE(volatile char(*&)[][2][3]      , volatile char(*&)[][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[][2][3]    , volatile const char[2][3]      );
    dTEST_TRUE(volatile const char(&)[][2][3] , volatile const char(&)[][2][3] );
    dTEST_RVAL(volatile const char(&&)[][2][3], volatile const char(&&)[][2][3]);
    dTEST_TRUE(volatile const char(*)[][2][3] , volatile const char(*)[][2][3] );
    dTEST_TRUE(volatile const char(*&)[][2][3], volatile const char(*&)[][2][3]);
}
#endif

// --- arrays stress
TEST_COMPONENT(006)
{
    dTEST_TRUE(char*[1][2][3]     , char*[2][3]        );
    dTEST_TRUE(char*(*)[1][2][3]  , char*(*)[1][2][3]  );
    dTEST_TRUE(char*(&)[1][2][3]  , char*(&)[1][2][3]  );
    dTEST_TRUE(char*(*&)[1][2][3] , char*(*&)[1][2][3] );
//------------------------------------------------------------------------------
    dTEST_TRUE(const char* const(*&)[1][2][3]                       , const char* const(*&)[1][2][3]                       );
    dTEST_TRUE(const char* const(**&)[1][2][3]                      , const char* const(**&)[1][2][3]                      );
    dTEST_TRUE(const char* const(* const* const&)[1][2][3]          , const char* const(* const* const&)[1][2][3]          );
    dTEST_TRUE(const char* const(* volatile* const&)[1][2][3]       , const char* const(* volatile* const&)[1][2][3]       );
    dTEST_RVAL(volatile char* const(* volatile* volatile&&)[1][2][3], volatile char* const(* volatile* volatile&&)[1][2][3]);

    dTEST_TRUE(const char* const(* const* const)[1][2][3]         , const char* const(* const* const)[1][2][3]         );
    dTEST_TRUE(const char* const(* volatile* const)[1][2][3]      , const char* const(* volatile* const)[1][2][3]      );
    dTEST_TRUE(volatile char* const(* volatile* volatile)[1][2][3], volatile char* const(* volatile* volatile)[1][2][3]);
}

// --- arrays[0]
#ifdef dHAS_ZERO_ARRAY
TEST_COMPONENT(007)
{
    dTEST_TRUE(wchar_t[0]                      , wchar_t );
    dTEST_TRUE(char[0]                         , char    );
    dTEST_TRUE(char(&)[0]                      , char(&)[0] );
    dTEST_RVAL(char(&&)[0]                     , char(&&)[0]);
    dTEST_TRUE(char(*)[0]                      , char(*)[0] );
    dTEST_TRUE(char(*&)[0]                     , char(*&)[0]);
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[0]                   , char    );
    dTEST_TRUE(const char(&)[0]                , const char(&)[0] );
    dTEST_RVAL(const char(&&)[0]               , const char(&&)[0]);
    dTEST_TRUE(const char(*)[0]                , const char(*)[0] );
    dTEST_TRUE(const char(*&)[0]               , const char(*&)[0]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[0]                , char    );
    dTEST_TRUE(volatile char(&)[0]             , volatile char(&)[0] );
    dTEST_RVAL(volatile char(&&)[0]            , volatile char(&&)[0]);
    dTEST_TRUE(volatile char(*)[0]             , volatile char(*)[0] );
    dTEST_TRUE(volatile char(*&)[0]            , volatile char(*&)[0]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[0]          , char    );
    dTEST_TRUE(volatile const char(&)[0]       , volatile const char(&)[0] );
    dTEST_RVAL(volatile const char(&&)[0]      , volatile const char(&&)[0]);
    dTEST_TRUE(volatile const char(*)[0]       , volatile const char(*)[0] );
    dTEST_TRUE(volatile const char(*&)[0]      , volatile const char(*&)[0]);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char[0][2][3]                   , char[2][3]    );
    dTEST_TRUE(char(&)[0][2][3]                , char(&)[0][2][3] );
    dTEST_RVAL(char(&&)[0][2][3]               , char(&&)[0][2][3]);
    dTEST_TRUE(char(*)[0][2][3]                , char(*)[0][2][3] );
    dTEST_TRUE(char(*&)[0][2][3]               , char(*&)[0][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[0][2][3]             , char[2][3]    );
    dTEST_TRUE(const char(&)[0][2][3]          , const char(&)[0][2][3] );
    dTEST_RVAL(const char(&&)[0][2][3]         , const char(&&)[0][2][3]);
    dTEST_TRUE(const char(*)[0][2][3]          , const char(*)[0][2][3] );
    dTEST_TRUE(const char(*&)[0][2][3]         , const char(*&)[0][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[0][2][3]          , char[2][3]    );
    dTEST_TRUE(volatile char(&)[0][2][3]       , volatile char(&)[0][2][3] );
    dTEST_RVAL(volatile char(&&)[0][2][3]      , volatile char(&&)[0][2][3]);
    dTEST_TRUE(volatile char(*)[0][2][3]       , volatile char(*)[0][2][3] );
    dTEST_TRUE(volatile char(*&)[0][2][3]      , volatile char(*&)[0][2][3]);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[0][2][3]    , const char[2][3]    );
    dTEST_TRUE(volatile const char(&)[0][2][3] , volatile const char(&)[0][2][3] );
    dTEST_RVAL(volatile const char(&&)[0][2][3], volatile const char(&&)[0][2][3]);
    dTEST_TRUE(volatile const char(*)[0][2][3] , volatile const char(*)[0][2][3] );
    dTEST_TRUE(volatile const char(*&)[0][2][3], volatile const char(*&)[0][2][3]);
}
#endif // !dHAS_ZERO_ARRAY

// --- functions int()
TEST_COMPONENT(008)
{
    dTEST_TRUE(int()                    , int()     );
    dTEST_TRUE(int(&)()                 , int(&)()  );
    dTEST_RVAL(int(&&)()                , int(&&)() );
                                        
    dTEST_TRUE(int(*)()                 , int(*)()                );
    dTEST_TRUE(int(* const)()           , int(* const)()          );
    dTEST_TRUE(int(* volatile)()        , int(* volatile)()       );
    dTEST_TRUE(int(* volatile const)()  , int(* volatile const)() );
                                        
    dTEST_TRUE(int(*&)()                , int(*&)()                );
    dTEST_TRUE(int(* const&)()          , int(* const&)()          );
    dTEST_TRUE(int(* volatile&)()       , int(* volatile&)()       );
    dTEST_TRUE(int(* volatile const&)() , int(* volatile const&)() );
                                        
    dTEST_RVAL(int(*&&)()               , int(*&&)()               );
    dTEST_RVAL(int(* const&&)()         , int(* const&&)()         );
    dTEST_RVAL(int(* volatile&&)()      , int(* volatile&&)()      );
    dTEST_RVAL(int(* volatile const&&)(), int(* volatile const&&)());
}

// --- function-pointers
TEST_COMPONENT(009)
{                  
    dTEST_TRUE(int(* const*&)(bool, char)                   , int(* const*&)(bool, char)                   );
    dTEST_TRUE(int(** const*&)(bool, char)                  , int(** const*&)(bool, char)                  );
    dTEST_TRUE(int(* const* const*&)(bool, char)            , int(* const* const*&)(bool, char)            );
    dTEST_TRUE(int(* volatile* volatile*&)(bool, char)      , int(* volatile* volatile*&)(bool, char)      );
    dTEST_TRUE(int(* volatile* volatile const*&)(bool, char), int(* volatile* volatile const*&)(bool, char));
}

// --- abominable int() const
#ifdef dHAS_ABOMINABLE
TEST_COMPONENT(010)
{
    dTEST_TRUE(int()                   , int()                  );
    dTEST_TRUE(int() const             , int() const            );
                                       
    dTEST_TRUE(int() volatile          , int() volatile         );
    dTEST_TRUE(int() volatile const    , int() volatile const   );
                                       
    dTEST_TRUE(int() &                 , int() &                );
    dTEST_TRUE(int() const &           , int() const &          );
    dTEST_TRUE(int() volatile &        , int() volatile &       );
    dTEST_TRUE(int() volatile const &  , int() volatile const & );
                                       
    dTEST_RVAL(int() &&                , int() &&               );
    dTEST_RVAL(int() const &&          , int() const &&         );
    dTEST_RVAL(int() volatile &&       , int() volatile &&      );
    dTEST_RVAL(int() volatile const && , int() volatile const &&);
}
#endif

// --- method int(some::*)()
TEST_COMPONENT(011)
{
    dTEST_TRUE(int(some::*)()                 , int(some::*)()   );
    dTEST_TRUE(int(some::*&)()                , int(some::*&)()  );
    dTEST_RVAL(int(some::*&&)()               , int(some::*&&)() );
                                       
    dTEST_TRUE(int(some::* const)()           , int(some::* const)()           );
    dTEST_TRUE(int(some::* volatile)()        , int(some::* volatile)()        );
    dTEST_TRUE(int(some::* volatile const)()  , int(some::* volatile const)()  );

    dTEST_TRUE(int(some::* const&)()          , int(some::* const&)()          );
    dTEST_TRUE(int(some::* volatile&)()       , int(some::* volatile&)()       );
    dTEST_TRUE(int(some::* volatile const&)() , int(some::* volatile const&)() );

    dTEST_RVAL(int(some::* const&&)()         , int(some::* const&&)()         );
    dTEST_RVAL(int(some::* volatile&&)()      , int(some::* volatile&&)()      );
    dTEST_RVAL(int(some::* volatile const&&)(), int(some::* volatile const&&)());
}

// --- member int
TEST_COMPONENT(012)
{
    dTEST_TRUE(int some::*                                , int some::*                 );
    dTEST_TRUE(int some::*&                               , int some::*&                );
    dTEST_RVAL(int some::*&&                              , int some::*&&               );

    dTEST_TRUE(int some::* const                          , int some::* const           );
    dTEST_TRUE(int some::* const&                         , int some::* const&          );
    dTEST_RVAL(int some::* const&&                        , int some::* const&&         );

    dTEST_TRUE(int some::* volatile                       , int some::* volatile        );
    dTEST_TRUE(int some::* volatile&                      , int some::* volatile&       );
    dTEST_RVAL(int some::* volatile&&                     , int some::* volatile&&      );

    dTEST_TRUE(int some::* volatile const                 , int some::* volatile const  );
    dTEST_TRUE(int some::* volatile const&                , int some::* volatile const& );
    dTEST_RVAL(int some::* volatile const&&               , int some::* volatile const&&);
//------------------------------------------------------------------------------
    dTEST_TRUE(const int some::*                          , const int some::*                 );
    dTEST_TRUE(const int some::*&                         , const int some::*&                );
    dTEST_RVAL(const int some::*&&                        , const int some::*&&               );

    dTEST_TRUE(const int some::* const                    , const int some::* const           );
    dTEST_TRUE(const int some::* const&                   , const int some::* const&          );
    dTEST_RVAL(const int some::* const&&                  , const int some::* const&&         );

    dTEST_TRUE(const int some::* volatile                 , const int some::* volatile        );
    dTEST_TRUE(const int some::* volatile&                , const int some::* volatile&       );
    dTEST_RVAL(const int some::* volatile&&               , const int some::* volatile&&      );

    dTEST_TRUE(const int some::* volatile const           , const int some::* volatile const  );
    dTEST_TRUE(const int some::* volatile const&          , const int some::* volatile const& );
    dTEST_RVAL(const int some::* volatile const&&         , const int some::* volatile const&&);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile int some::*                       , volatile int some::*                 );
    dTEST_TRUE(volatile int some::*&                      , volatile int some::*&                );
    dTEST_RVAL(volatile int some::*&&                     , volatile int some::*&&               );

    dTEST_TRUE(volatile int some::* const                 , volatile int some::* const           );
    dTEST_TRUE(volatile int some::* const&                , volatile int some::* const&          );
    dTEST_RVAL(volatile int some::* const&&               , volatile int some::* const&&         );

    dTEST_TRUE(volatile int some::* volatile              , volatile int some::* volatile        );
    dTEST_TRUE(volatile int some::* volatile&             , volatile int some::* volatile&       );
    dTEST_RVAL(volatile int some::* volatile&&            , volatile int some::* volatile&&      );

    dTEST_TRUE(volatile int some::* volatile const        , volatile int some::* volatile const  );
    dTEST_TRUE(volatile int some::* volatile const&       , volatile int some::* volatile const& );
    dTEST_RVAL(volatile int some::* volatile const&&      , volatile int some::* volatile const&&);
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const int some::*                 , volatile const int some::*                 );
    dTEST_TRUE(volatile const int some::*&                , volatile const int some::*&                );
    dTEST_RVAL(volatile const int some::*&&               , volatile const int some::*&&               );

    dTEST_TRUE(volatile const int some::* const           , volatile const int some::* const           );
    dTEST_TRUE(volatile const int some::* const&          , volatile const int some::* const&          );
    dTEST_RVAL(volatile const int some::* const&&         , volatile const int some::* const&&         );

    dTEST_TRUE(volatile const int some::* volatile        , volatile const int some::* volatile        );
    dTEST_TRUE(volatile const int some::* volatile&       , volatile const int some::* volatile&       );
    dTEST_RVAL(volatile const int some::* volatile&&      , volatile const int some::* volatile&&      );

    dTEST_TRUE(volatile const int some::* volatile const  , volatile const int some::* volatile const  );
    dTEST_TRUE(volatile const int some::* volatile const& , volatile const int some::* volatile const& );
    dTEST_RVAL(volatile const int some::* volatile const&&, volatile const int some::* volatile const&&);
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

    dTEST_TRUE(arr some::*   , arr some::*   );
    dTEST_TRUE(foo some::*   , foo some::*   );
    dTEST_TRUE(arrfoo some::*, arrfoo some::*);
    dTEST_TRUE(pfoo some::*  , pfoo some::*  );
    dTEST_TRUE(method some::*, method some::*);
}

//==============================================================================
//==============================================================================
#endif // !TEST_REMOVE_EXTENSION

