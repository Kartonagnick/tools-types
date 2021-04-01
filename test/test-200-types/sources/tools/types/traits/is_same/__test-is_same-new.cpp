// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-29d][22:26:12] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_SAME

#include <tools/features.hpp>
#ifdef dHAS_CPP11

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_same
#define dTEST_TAG new

#include <tools/types/traits.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    #define dEXPRESSION(a) \
        me::is_same<a,a>::value 

    #define dTEST_TRUE(a)         \
        dSTATIC_ASSERT(           \
            ERROR_MUST_BE_SAMPLE, \
            dEXPRESSION(a)        \
        )

    struct some;

} // namespace

//==============================================================================
//==============================================================================
// --- char/ char&/ char&&
TEST_COMPONENT(000)
{
    dTEST_TRUE(char            );
    dTEST_TRUE(const char      );
    dTEST_TRUE(volatile char   );

    dTEST_TRUE(char&           );
    dTEST_TRUE(const char&     );
    dTEST_TRUE(volatile char&  );

    dTEST_TRUE(char&&          );
    dTEST_TRUE(const char&&    );
    dTEST_TRUE(volatile char&& );
}
// --- pointers*
TEST_COMPONENT(001)
{
    //        |    before                           |
    dTEST_TRUE(char*                                );
    dTEST_TRUE(const char*                          );
    dTEST_TRUE(volatile char*                       );
    dTEST_TRUE(volatile const char*                 );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* const                          );
    dTEST_TRUE(const char* const                    );
    dTEST_TRUE(volatile char* const                 );
    dTEST_TRUE(volatile const char* const           );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile                       );
    dTEST_TRUE(const char* volatile                 );
    dTEST_TRUE(volatile char* volatile              );
    dTEST_TRUE(volatile const char* volatile        );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile const                 );
    dTEST_TRUE(const char* volatile const           );
    dTEST_TRUE(volatile char* volatile const        );
    dTEST_TRUE(volatile const char* volatile const  );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char*&                               );
    dTEST_TRUE(const char*&                         );
    dTEST_TRUE(volatile char*&                      );
    dTEST_TRUE(volatile const char*&                );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* const&                         );
    dTEST_TRUE(const char* const&                   );
    dTEST_TRUE(volatile char* const&                );
    dTEST_TRUE(volatile const char* const&          );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile&                      );
    dTEST_TRUE(const char* volatile&                );
    dTEST_TRUE(volatile char* volatile&             );
    dTEST_TRUE(volatile const char* volatile&       );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile const&                );
    dTEST_TRUE(const char* volatile const&          );
    dTEST_TRUE(volatile char* volatile const&       );
    dTEST_TRUE(volatile const char* volatile const& );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char*&&                              );
    dTEST_TRUE(const char*&&                        );
    dTEST_TRUE(volatile char*&&                     );
    dTEST_TRUE(volatile const char*&&               );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* const&&                        );
    dTEST_TRUE(const char* const&&                  );
    dTEST_TRUE(volatile char* const&&               );
    dTEST_TRUE(volatile const char* const&&         );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile&&                     );
    dTEST_TRUE(const char* volatile&&               );
    dTEST_TRUE(volatile char* volatile&&            );
    dTEST_TRUE(volatile const char* volatile&&      );
//------------------------------------------------------------------------------
    dTEST_TRUE(char* volatile const&&               );
    dTEST_TRUE(const char* volatile const&&         );
    dTEST_TRUE(volatile char* volatile const&&      );
    dTEST_TRUE(volatile const char* volatile const&&);
}

// --- pointers**
TEST_COMPONENT(002)
{
    dTEST_TRUE(char**                               );
    dTEST_TRUE(const char**                         );
    dTEST_TRUE(volatile char**                      );
    dTEST_TRUE(volatile const char**                );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** const                         );
    dTEST_TRUE(const char** const                   );
    dTEST_TRUE(volatile char** const                );
    dTEST_TRUE(volatile const char** const          );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile                      );
    dTEST_TRUE(const char** volatile                );
    dTEST_TRUE(volatile char** volatile             );
    dTEST_TRUE(volatile const char** volatile       );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile const                );
    dTEST_TRUE(const char** volatile const          );
    dTEST_TRUE(volatile char** volatile const       );
    dTEST_TRUE(volatile const char** volatile const );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char**&                              );
    dTEST_TRUE(const char**&                        );
    dTEST_TRUE(volatile char**&                     );
    dTEST_TRUE(volatile const char**&               );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** const&                        );
    dTEST_TRUE(const char** const&                  );
    dTEST_TRUE(volatile char** const&               );
    dTEST_TRUE(volatile const char** const&         );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile&                     );
    dTEST_TRUE(const char** volatile&               );
    dTEST_TRUE(volatile char** volatile&            );
    dTEST_TRUE(volatile const char** volatile&      );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile const&               );
    dTEST_TRUE(const char** volatile const&         );
    dTEST_TRUE(volatile char** volatile const&      );
    dTEST_TRUE(volatile const char** volatile const&);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char**&&                               );
    dTEST_TRUE(const char**&&                         );
    dTEST_TRUE(volatile char**&&                      );
    dTEST_TRUE(volatile const char**&&                );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** const&&                         );
    dTEST_TRUE(const char** const&&                   );
    dTEST_TRUE(volatile char** const&&                );
    dTEST_TRUE(volatile const char** const&&          );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile&&                      );
    dTEST_TRUE(const char** volatile&&                );
    dTEST_TRUE(volatile char** volatile&&             );
    dTEST_TRUE(volatile const char** volatile&&       );
//------------------------------------------------------------------------------
    dTEST_TRUE(char** volatile const&&                );
    dTEST_TRUE(const char** volatile const&&          );
    dTEST_TRUE(volatile char** volatile const&&       );
    dTEST_TRUE(volatile const char** volatile const&& );
}

// --- pointers stress
TEST_COMPONENT(003)
{
    dTEST_TRUE(char** const                     );
    dTEST_TRUE(char* const* const               );
    dTEST_TRUE(char* const* const&              );
    dTEST_TRUE(char* const** const&&            );
    dTEST_TRUE(char*** const* const** const&&   );
    dTEST_TRUE(char*** volatile* const** const&&);
    dTEST_TRUE(char*** const* volatile** const&&);
}

// --- arrays[255]
TEST_COMPONENT(004)
{
    dTEST_TRUE(char[255]                       );
    dTEST_TRUE(char(&)[255]                    );
    dTEST_TRUE(char(&&)[255]                   );
    dTEST_TRUE(char(*)[255]                    );
    dTEST_TRUE(char(*&)[255]                   );
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[255]                 );
    dTEST_TRUE(const char(&)[255]              );
    dTEST_TRUE(const char(&&)[255]             );
    dTEST_TRUE(const char(*)[255]              );
    dTEST_TRUE(const char(*&)[255]             );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[255]              );
    dTEST_TRUE(volatile char(&)[255]           );
    dTEST_TRUE(volatile char(&&)[255]          );
    dTEST_TRUE(volatile char(*)[255]           );
    dTEST_TRUE(volatile char(*&)[255]          );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[255]        );
    dTEST_TRUE(volatile const char(&)[255]     );
    dTEST_TRUE(volatile const char(&&)[255]    );
    dTEST_TRUE(volatile const char(*)[255]     );
    dTEST_TRUE(volatile const char(*&)[255]    );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char[1][2][3]                   );
    dTEST_TRUE(char(&)[1][2][3]                );
    dTEST_TRUE(char(&&)[1][2][3]               );
    dTEST_TRUE(char(*)[1][2][3]                );
    dTEST_TRUE(char(*&)[1][2][3]               );
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[1][2][3]             );
    dTEST_TRUE(const char(&)[1][2][3]          );
    dTEST_TRUE(const char(&&)[1][2][3]         );
    dTEST_TRUE(const char(*)[1][2][3]          );
    dTEST_TRUE(const char(*&)[1][2][3]         );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[1][2][3]          );
    dTEST_TRUE(volatile char(&)[1][2][3]       );
    dTEST_TRUE(volatile char(&&)[1][2][3]      );
    dTEST_TRUE(volatile char(*)[1][2][3]       );
    dTEST_TRUE(volatile char(*&)[1][2][3]      );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[1][2][3]    );
    dTEST_TRUE(volatile const char(&)[1][2][3] );
    dTEST_TRUE(volatile const char(&&)[1][2][3]);
    dTEST_TRUE(volatile const char(*)[1][2][3] );
    dTEST_TRUE(volatile const char(*&)[1][2][3]);
}

// --- arrays[]
TEST_COMPONENT(005)
{
    dTEST_TRUE(wchar_t[]                      );
    dTEST_TRUE(char[]                         );
    dTEST_TRUE(char(&)[]                      );
    dTEST_TRUE(char(&&)[]                     );
    dTEST_TRUE(char(*)[]                      );
    dTEST_TRUE(char(*&)[]                     );
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[]                   );
    dTEST_TRUE(const char(&)[]                );
    dTEST_TRUE(const char(&&)[]               );
    dTEST_TRUE(const char(*)[]                );
    dTEST_TRUE(const char(*&)[]               );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[]                );
    dTEST_TRUE(volatile char(&)[]             );
    dTEST_TRUE(volatile char(&&)[]            );
    dTEST_TRUE(volatile char(*)[]             );
    dTEST_TRUE(volatile char(*&)[]            );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[]          );
    dTEST_TRUE(volatile const char(&)[]       );
    dTEST_TRUE(volatile const char(&&)[]      );
    dTEST_TRUE(volatile const char(*)[]       );
    dTEST_TRUE(volatile const char(*&)[]      );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char[][2][3]                   );
    dTEST_TRUE(char(&)[][2][3]                );
    dTEST_TRUE(char(&&)[][2][3]               );
    dTEST_TRUE(char(*)[][2][3]                );
    dTEST_TRUE(char(*&)[][2][3]               );
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[][2][3]             );
    dTEST_TRUE(const char(&)[][2][3]          );
    dTEST_TRUE(const char(&&)[][2][3]         );
    dTEST_TRUE(const char(*)[][2][3]          );
    dTEST_TRUE(const char(*&)[][2][3]         );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[][2][3]          );
    dTEST_TRUE(volatile char(&)[][2][3]       );
    dTEST_TRUE(volatile char(&&)[][2][3]      );
    dTEST_TRUE(volatile char(*)[][2][3]       );
    dTEST_TRUE(volatile char(*&)[][2][3]      );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[][2][3]    );
    dTEST_TRUE(volatile const char(&)[][2][3] );
    dTEST_TRUE(volatile const char(&&)[][2][3]);
    dTEST_TRUE(volatile const char(*)[][2][3] );
    dTEST_TRUE(volatile const char(*&)[][2][3]);
}


// --- arrays stress
TEST_COMPONENT(006)
{
    dTEST_TRUE(char*[1][2][3]                                       );
    dTEST_TRUE(char*(*)[1][2][3]                                    );
    dTEST_TRUE(char*(&)[1][2][3]                                    );
    dTEST_TRUE(char*(*&)[1][2][3]                                   );
//------------------------------------------------------------------------------
    dTEST_TRUE(const char* const(*&)[1][2][3]                       );
    dTEST_TRUE(const char* const(**&)[1][2][3]                      );
    dTEST_TRUE(const char* const(* const* const&)[1][2][3]          );
    dTEST_TRUE(const char* const(* volatile* const&)[1][2][3]       );
    dTEST_TRUE(volatile char* const(* volatile* volatile&&)[1][2][3]);
}

// --- arrays[0]
#ifdef dHAS_ZERO_ARRAY
TEST_COMPONENT(007)
{
    dTEST_TRUE(wchar_t[0]                      );
    dTEST_TRUE(char[0]                         );
    dTEST_TRUE(char(&)[0]                      );
    dTEST_TRUE(char(&&)[0]                     );
    dTEST_TRUE(char(*)[0]                      );
    dTEST_TRUE(char(*&)[0]                     );
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[0]                   );
    dTEST_TRUE(const char(&)[0]                );
    dTEST_TRUE(const char(&&)[0]               );
    dTEST_TRUE(const char(*)[0]                );
    dTEST_TRUE(const char(*&)[0]               );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[0]                );
    dTEST_TRUE(volatile char(&)[0]             );
    dTEST_TRUE(volatile char(&&)[0]            );
    dTEST_TRUE(volatile char(*)[0]             );
    dTEST_TRUE(volatile char(*&)[0]            );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[0]          );
    dTEST_TRUE(volatile const char(&)[0]       );
    dTEST_TRUE(volatile const char(&&)[0]      );
    dTEST_TRUE(volatile const char(*)[0]       );
    dTEST_TRUE(volatile const char(*&)[0]      );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_TRUE(char[0][2][3]                   );
    dTEST_TRUE(char(&)[0][2][3]                );
    dTEST_TRUE(char(&&)[0][2][3]               );
    dTEST_TRUE(char(*)[0][2][3]                );
    dTEST_TRUE(char(*&)[0][2][3]               );
//------------------------------------------------------------------------------
    dTEST_TRUE(const char[0][2][3]             );
    dTEST_TRUE(const char(&)[0][2][3]          );
    dTEST_TRUE(const char(&&)[0][2][3]         );
    dTEST_TRUE(const char(*)[0][2][3]          );
    dTEST_TRUE(const char(*&)[0][2][3]         );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile char[0][2][3]          );
    dTEST_TRUE(volatile char(&)[0][2][3]       );
    dTEST_TRUE(volatile char(&&)[0][2][3]      );
    dTEST_TRUE(volatile char(*)[0][2][3]       );
    dTEST_TRUE(volatile char(*&)[0][2][3]      );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const char[0][2][3]    );
    dTEST_TRUE(volatile const char(&)[0][2][3] );
    dTEST_TRUE(volatile const char(&&)[0][2][3]);
    dTEST_TRUE(volatile const char(*)[0][2][3] );
    dTEST_TRUE(volatile const char(*&)[0][2][3]);
}
#endif // !dHAS_ZERO_ARRAY

// --- functions int()
TEST_COMPONENT(008)
{
    dTEST_TRUE(int()                    );
    dTEST_TRUE(int(&)()                 );
    dTEST_TRUE(int(&&)()                );
    
    dTEST_TRUE(int(*)()                 );
    dTEST_TRUE(int(* const)()           );
    dTEST_TRUE(int(* volatile)()        );
    dTEST_TRUE(int(* volatile const)()  );
    
    dTEST_TRUE(int(*&)()                );
    dTEST_TRUE(int(* const&)()          );
    dTEST_TRUE(int(* volatile&)()       );
    dTEST_TRUE(int(* volatile const&)() );
    
    dTEST_TRUE(int(*&&)()               );
    dTEST_TRUE(int(* const&&)()         );
    dTEST_TRUE(int(* volatile&&)()      );
    dTEST_TRUE(int(* volatile const&&)());
}

// --- function-pointers
TEST_COMPONENT(009)
{                  
    dTEST_TRUE(int(* const*&)(bool, char)                   );
    dTEST_TRUE(int(** const*&)(bool, char)                  );
    dTEST_TRUE(int(* const* const*&)(bool, char)            );
    dTEST_TRUE(int(* volatile* volatile*&)(bool, char)      );
    dTEST_TRUE(int(* volatile* volatile const*&)(bool, char));
}

// --- abominable int() const
TEST_COMPONENT(010)
{
    dTEST_TRUE(int()                   );
    dTEST_TRUE(int() const             );
    
    dTEST_TRUE(int() volatile          );
    dTEST_TRUE(int() volatile const    );

    dTEST_TRUE(int() &                 );
    dTEST_TRUE(int() const &           );
    dTEST_TRUE(int() volatile &        );
    dTEST_TRUE(int() volatile const &  );

    dTEST_TRUE(int() &&                );
    dTEST_TRUE(int() const &&          );
    dTEST_TRUE(int() volatile &&       );
    dTEST_TRUE(int() volatile const && );
}

// --- method int(some::*)()
TEST_COMPONENT(011)
{
    dTEST_TRUE(int(some::*)()                 );
    dTEST_TRUE(int(some::*&)()                );
    dTEST_TRUE(int(some::*&&)()               );

    dTEST_TRUE(int(some::* const)()           );
    dTEST_TRUE(int(some::* volatile)()        );
    dTEST_TRUE(int(some::* volatile const)()  );

    dTEST_TRUE(int(some::* const&)()          );
    dTEST_TRUE(int(some::* volatile&)()       );
    dTEST_TRUE(int(some::* volatile const&)() );

    dTEST_TRUE(int(some::* const&&)()         );
    dTEST_TRUE(int(some::* volatile&&)()      );
    dTEST_TRUE(int(some::* volatile const&&)());
}

// --- member int
TEST_COMPONENT(012)
{
    dTEST_TRUE(int some::*                                );
    dTEST_TRUE(int some::*&                               );
    dTEST_TRUE(int some::*&&                              );

    dTEST_TRUE(int some::* const                          );
    dTEST_TRUE(int some::* const&                         );
    dTEST_TRUE(int some::* const&&                        );

    dTEST_TRUE(int some::* volatile                       );
    dTEST_TRUE(int some::* volatile&                      );
    dTEST_TRUE(int some::* volatile&&                     );

    dTEST_TRUE(int some::* volatile const                 );
    dTEST_TRUE(int some::* volatile const&                );
    dTEST_TRUE(int some::* volatile const&&               );
//------------------------------------------------------------------------------
    dTEST_TRUE(const int some::*                          );
    dTEST_TRUE(const int some::*&                         );
    dTEST_TRUE(const int some::*&&                        );
    
    dTEST_TRUE(const int some::* const                    );
    dTEST_TRUE(const int some::* const&                   );
    dTEST_TRUE(const int some::* const&&                  );

    dTEST_TRUE(const int some::* volatile                 );
    dTEST_TRUE(const int some::* volatile&                );
    dTEST_TRUE(const int some::* volatile&&               );

    dTEST_TRUE(const int some::* volatile const           );
    dTEST_TRUE(const int some::* volatile const&          );
    dTEST_TRUE(const int some::* volatile const&&         );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile int some::*                       );
    dTEST_TRUE(volatile int some::*&                      );
    dTEST_TRUE(volatile int some::*&&                     );

    dTEST_TRUE(volatile int some::* const                 );
    dTEST_TRUE(volatile int some::* const&                );
    dTEST_TRUE(volatile int some::* const&&               );

    dTEST_TRUE(volatile int some::* volatile              );
    dTEST_TRUE(volatile int some::* volatile&             );
    dTEST_TRUE(volatile int some::* volatile&&            );

    dTEST_TRUE(volatile int some::* volatile const        );
    dTEST_TRUE(volatile int some::* volatile const&       );
    dTEST_TRUE(volatile int some::* volatile const&&      );
//------------------------------------------------------------------------------
    dTEST_TRUE(volatile const int some::*                 );
    dTEST_TRUE(volatile const int some::*&                );
    dTEST_TRUE(volatile const int some::*&&               );

    dTEST_TRUE(volatile const int some::* const           );
    dTEST_TRUE(volatile const int some::* const&          );
    dTEST_TRUE(volatile const int some::* const&&         );

    dTEST_TRUE(volatile const int some::* volatile        );
    dTEST_TRUE(volatile const int some::* volatile&       );
    dTEST_TRUE(volatile const int some::* volatile&&      );

    dTEST_TRUE(volatile const int some::* volatile const  );
    dTEST_TRUE(volatile const int some::* volatile const& );
    dTEST_TRUE(volatile const int some::* volatile const&&);
}

// --- member int stress
TEST_COMPONENT(013)
{
    using arr    = int[3];
    using foo    = int(bool);
    using pfoo   = int(*)(bool);
    using arrfoo = pfoo[3];

    using method1 = char (some::*)(float);

    dTEST_TRUE(arr some::*    );
    dTEST_TRUE(foo some::*    );
    dTEST_TRUE(arrfoo some::* );
    dTEST_TRUE(pfoo some::*   );
    dTEST_TRUE(method1 some::*);
}

//==============================================================================
//==============================================================================
#endif // !dHAS_CPP11
#endif // !TEST_IS_SAME

