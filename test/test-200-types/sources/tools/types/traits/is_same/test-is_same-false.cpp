// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-29d][22:26:12] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_IS_SAME

#define dTEST_COMPONENT tools, types, traits
#define dTEST_METHOD is_same
#define dTEST_TAG false

#include <tools/types/traits.hpp>
namespace me = ::tools;
//==============================================================================
//=== TDD ======================================================================
namespace
{
    template<class t> struct add_ptr_
        { typedef t* type; };
    template<class t> struct add_ptr_<t&>
        { typedef t* type; };

    #ifdef dHAS_RVALUE_REFERENCES
    template<class t> struct add_ptr_<t&&>
        { typedef t* type; };
    #endif

    #ifdef dHAS_ABOMINABLE
    template<class r> struct add_ptr_<r()>
        { typedef r(*type)(); };
    template<class r> struct add_ptr_<r()const>
        { typedef r* type; };
    template<class r> struct add_ptr_<r()volatile>
        { typedef r* type; };
    template<class r> struct add_ptr_<r()volatile const>
        { typedef r* type; };

    template<class r> struct add_ptr_<r()&>
        { typedef r(*type)(); };
    template<class r> struct add_ptr_<r() const&>
        { typedef r* type; };
    template<class r> struct add_ptr_<r() volatile&>
        { typedef r* type; };
    template<class r> struct add_ptr_<r() volatile const&>
        { typedef r* type; };

    template<class r> struct add_ptr_<r()&&>
        { typedef r(*type)(); };
    template<class r> struct add_ptr_<r() const&&>
        { typedef r* type; };
    template<class r> struct add_ptr_<r() volatile&&>
        { typedef r* type; };
    template<class r> struct add_ptr_<r() volatile const&&>
        { typedef r* type; };
    #endif

    #define dEXPRESSION(a) \
        !me::is_same<a, typename add_ptr_<a>::type >::value 

    #define dTEST_FALSE(a)        \
        dSTATIC_ASSERT(           \
            ERROR_MUST_BE_SAMPLE, \
            dEXPRESSION(a)        \
        )

    #ifdef dHAS_RVALUE_REFERENCE
        #define dTST_RVALUE(a) dTEST_FALSE(a)
    #else
        #define dTST_RVALUE(a) void()
    #endif

    struct some;

} // namespace

//==============================================================================
//==============================================================================
// --- char/ char&/ char&&
TEST_COMPONENT(000)
{
    dTEST_FALSE(char            );
    dTEST_FALSE(const char      );
    dTEST_FALSE(volatile char   );

    dTEST_FALSE(char&           );
    dTEST_FALSE(const char&     );
    dTEST_FALSE(volatile char&  );

    dTST_RVALUE(char&&          );
    dTST_RVALUE(const char&&    );
    dTST_RVALUE(volatile char&& );
}
// --- pointers*
TEST_COMPONENT(001)
{
    dTEST_FALSE(char*                                );
    dTEST_FALSE(const char*                          );
    dTEST_FALSE(volatile char*                       );
    dTEST_FALSE(volatile const char*                 );
//------------------------------------------------------------------------------
    dTEST_FALSE(char* const                          );
    dTEST_FALSE(const char* const                    );
    dTEST_FALSE(volatile char* const                 );
    dTEST_FALSE(volatile const char* const           );
//------------------------------------------------------------------------------
    dTEST_FALSE(char* volatile                       );
    dTEST_FALSE(const char* volatile                 );
    dTEST_FALSE(volatile char* volatile              );
    dTEST_FALSE(volatile const char* volatile        );
//------------------------------------------------------------------------------
    dTEST_FALSE(char* volatile const                 );
    dTEST_FALSE(const char* volatile const           );
    dTEST_FALSE(volatile char* volatile const        );
    dTEST_FALSE(volatile const char* volatile const  );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_FALSE(char*&                               );
    dTEST_FALSE(const char*&                         );
    dTEST_FALSE(volatile char*&                      );
    dTEST_FALSE(volatile const char*&                );
//------------------------------------------------------------------------------
    dTEST_FALSE(char* const&                         );
    dTEST_FALSE(const char* const&                   );
    dTEST_FALSE(volatile char* const&                );
    dTEST_FALSE(volatile const char* const&          );
//------------------------------------------------------------------------------
    dTEST_FALSE(char* volatile&                      );
    dTEST_FALSE(const char* volatile&                );
    dTEST_FALSE(volatile char* volatile&             );
    dTEST_FALSE(volatile const char* volatile&       );
//------------------------------------------------------------------------------
    dTEST_FALSE(char* volatile const&                );
    dTEST_FALSE(const char* volatile const&          );
    dTEST_FALSE(volatile char* volatile const&       );
    dTEST_FALSE(volatile const char* volatile const& );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTST_RVALUE(char*&&                              );
    dTST_RVALUE(const char*&&                        );
    dTST_RVALUE(volatile char*&&                     );
    dTST_RVALUE(volatile const char*&&               );
//------------------------------------------------------------------------------
    dTST_RVALUE(char* const&&                        );
    dTST_RVALUE(const char* const&&                  );
    dTST_RVALUE(volatile char* const&&               );
    dTST_RVALUE(volatile const char* const&&         );
//------------------------------------------------------------------------------
    dTST_RVALUE(char* volatile&&                     );
    dTST_RVALUE(const char* volatile&&               );
    dTST_RVALUE(volatile char* volatile&&            );
    dTST_RVALUE(volatile const char* volatile&&      );
//------------------------------------------------------------------------------
    dTST_RVALUE(char* volatile const&&               );
    dTST_RVALUE(const char* volatile const&&         );
    dTST_RVALUE(volatile char* volatile const&&      );
    dTST_RVALUE(volatile const char* volatile const&&);
}

// --- pointers**
TEST_COMPONENT(002)
{
    dTEST_FALSE(char**                               );
    dTEST_FALSE(const char**                         );
    dTEST_FALSE(volatile char**                      );
    dTEST_FALSE(volatile const char**                );
//------------------------------------------------------------------------------
    dTEST_FALSE(char** const                         );
    dTEST_FALSE(const char** const                   );
    dTEST_FALSE(volatile char** const                );
    dTEST_FALSE(volatile const char** const          );
//------------------------------------------------------------------------------
    dTEST_FALSE(char** volatile                      );
    dTEST_FALSE(const char** volatile                );
    dTEST_FALSE(volatile char** volatile             );
    dTEST_FALSE(volatile const char** volatile       );
//------------------------------------------------------------------------------
    dTEST_FALSE(char** volatile const                );
    dTEST_FALSE(const char** volatile const          );
    dTEST_FALSE(volatile char** volatile const       );
    dTEST_FALSE(volatile const char** volatile const );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_FALSE(char**&                              );
    dTEST_FALSE(const char**&                        );
    dTEST_FALSE(volatile char**&                     );
    dTEST_FALSE(volatile const char**&               );
//------------------------------------------------------------------------------
    dTEST_FALSE(char** const&                        );
    dTEST_FALSE(const char** const&                  );
    dTEST_FALSE(volatile char** const&               );
    dTEST_FALSE(volatile const char** const&         );
//------------------------------------------------------------------------------
    dTEST_FALSE(char** volatile&                     );
    dTEST_FALSE(const char** volatile&               );
    dTEST_FALSE(volatile char** volatile&            );
    dTEST_FALSE(volatile const char** volatile&      );
//------------------------------------------------------------------------------
    dTEST_FALSE(char** volatile const&               );
    dTEST_FALSE(const char** volatile const&         );
    dTEST_FALSE(volatile char** volatile const&      );
    dTEST_FALSE(volatile const char** volatile const&);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTST_RVALUE(char**&&                               );
    dTST_RVALUE(const char**&&                         );
    dTST_RVALUE(volatile char**&&                      );
    dTST_RVALUE(volatile const char**&&                );
//------------------------------------------------------------------------------
    dTST_RVALUE(char** const&&                         );
    dTST_RVALUE(const char** const&&                   );
    dTST_RVALUE(volatile char** const&&                );
    dTST_RVALUE(volatile const char** const&&          );
//------------------------------------------------------------------------------
    dTST_RVALUE(char** volatile&&                      );
    dTST_RVALUE(const char** volatile&&                );
    dTST_RVALUE(volatile char** volatile&&             );
    dTST_RVALUE(volatile const char** volatile&&       );
//------------------------------------------------------------------------------
    dTST_RVALUE(char** volatile const&&                );
    dTST_RVALUE(const char** volatile const&&          );
    dTST_RVALUE(volatile char** volatile const&&       );
    dTST_RVALUE(volatile const char** volatile const&& );
}

// --- pointers stress
TEST_COMPONENT(003)
{
    dTEST_FALSE(char** const                     );
    dTEST_FALSE(char* const* const               );
    dTEST_FALSE(char* const* const&              );
    dTST_RVALUE(char* const** const&&            );
    dTST_RVALUE(char*** const* const** const&&   );
    dTST_RVALUE(char*** volatile* const** const&&);
    dTST_RVALUE(char*** const* volatile** const&&);
}

// --- arrays[255]
TEST_COMPONENT(004)
{
    dTEST_FALSE(char[255]                       );
    dTEST_FALSE(char(&)[255]                    );
    dTST_RVALUE(char(&&)[255]                   );
    dTEST_FALSE(char(*)[255]                    );
    dTEST_FALSE(char(*&)[255]                   );
//------------------------------------------------------------------------------
    dTEST_FALSE(const char[255]                 );
    dTEST_FALSE(const char(&)[255]              );
    dTST_RVALUE(const char(&&)[255]             );
    dTEST_FALSE(const char(*)[255]              );
    dTEST_FALSE(const char(*&)[255]             );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile char[255]              );
    dTEST_FALSE(volatile char(&)[255]           );
    dTST_RVALUE(volatile char(&&)[255]          );
    dTEST_FALSE(volatile char(*)[255]           );
    dTEST_FALSE(volatile char(*&)[255]          );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile const char[255]        );
    dTEST_FALSE(volatile const char(&)[255]     );
    dTST_RVALUE(volatile const char(&&)[255]    );
    dTEST_FALSE(volatile const char(*)[255]     );
    dTEST_FALSE(volatile const char(*&)[255]    );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_FALSE(char[1][2][3]                   );
    dTEST_FALSE(char(&)[1][2][3]                );
    dTST_RVALUE(char(&&)[1][2][3]               );
    dTEST_FALSE(char(*)[1][2][3]                );
    dTEST_FALSE(char(*&)[1][2][3]               );
//------------------------------------------------------------------------------
    dTEST_FALSE(const char[1][2][3]             );
    dTEST_FALSE(const char(&)[1][2][3]          );
    dTST_RVALUE(const char(&&)[1][2][3]         );
    dTEST_FALSE(const char(*)[1][2][3]          );
    dTEST_FALSE(const char(*&)[1][2][3]         );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile char[1][2][3]          );
    dTEST_FALSE(volatile char(&)[1][2][3]       );
    dTST_RVALUE(volatile char(&&)[1][2][3]      );
    dTEST_FALSE(volatile char(*)[1][2][3]       );
    dTEST_FALSE(volatile char(*&)[1][2][3]      );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile const char[1][2][3]    );
    dTEST_FALSE(volatile const char(&)[1][2][3] );
    dTST_RVALUE(volatile const char(&&)[1][2][3]);
    dTEST_FALSE(volatile const char(*)[1][2][3] );
    dTEST_FALSE(volatile const char(*&)[1][2][3]);
}

// --- arrays[]
#ifdef dHAS_ARRAY_EMPTY_SIZE
TEST_COMPONENT(005)
{
    dTEST_FALSE(wchar_t[]                      );
    dTEST_FALSE(char[]                         );
    dTEST_FALSE(char(&)[]                      );
    dTST_RVALUE(char(&&)[]                     );
    dTEST_FALSE(char(*)[]                      );
    dTEST_FALSE(char(*&)[]                     );
//------------------------------------------------------------------------------
    dTEST_FALSE(const char[]                   );
    dTEST_FALSE(const char(&)[]                );
    dTST_RVALUE(const char(&&)[]               );
    dTEST_FALSE(const char(*)[]                );
    dTEST_FALSE(const char(*&)[]               );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile char[]                );
    dTEST_FALSE(volatile char(&)[]             );
    dTST_RVALUE(volatile char(&&)[]            );
    dTEST_FALSE(volatile char(*)[]             );
    dTEST_FALSE(volatile char(*&)[]            );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile const char[]          );
    dTEST_FALSE(volatile const char(&)[]       );
    dTST_RVALUE(volatile const char(&&)[]      );
    dTEST_FALSE(volatile const char(*)[]       );
    dTEST_FALSE(volatile const char(*&)[]      );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_FALSE(char[][2][3]                   );
    dTEST_FALSE(char(&)[][2][3]                );
    dTST_RVALUE(char(&&)[][2][3]               );
    dTEST_FALSE(char(*)[][2][3]                );
    dTEST_FALSE(char(*&)[][2][3]               );
//------------------------------------------------------------------------------
    dTEST_FALSE(const char[][2][3]             );
    dTEST_FALSE(const char(&)[][2][3]          );
    dTST_RVALUE(const char(&&)[][2][3]         );
    dTEST_FALSE(const char(*)[][2][3]          );
    dTEST_FALSE(const char(*&)[][2][3]         );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile char[][2][3]          );
    dTEST_FALSE(volatile char(&)[][2][3]       );
    dTST_RVALUE(volatile char(&&)[][2][3]      );
    dTEST_FALSE(volatile char(*)[][2][3]       );
    dTEST_FALSE(volatile char(*&)[][2][3]      );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile const char[][2][3]    );
    dTEST_FALSE(volatile const char(&)[][2][3] );
    dTST_RVALUE(volatile const char(&&)[][2][3]);
    dTEST_FALSE(volatile const char(*)[][2][3] );
    dTEST_FALSE(volatile const char(*&)[][2][3]);
}
#endif

// --- arrays stress
TEST_COMPONENT(006)
{
    dTEST_FALSE(char*[1][2][3]                                       );
    dTEST_FALSE(char*(*)[1][2][3]                                    );
    dTEST_FALSE(char*(&)[1][2][3]                                    );
    dTEST_FALSE(char*(*&)[1][2][3]                                   );
//------------------------------------------------------------------------------
    dTEST_FALSE(const char* const(*&)[1][2][3]                       );
    dTEST_FALSE(const char* const(**&)[1][2][3]                      );
    dTEST_FALSE(const char* const(* const* const&)[1][2][3]          );
    dTEST_FALSE(const char* const(* volatile* const&)[1][2][3]       );
    dTST_RVALUE(volatile char* const(* volatile* volatile&&)[1][2][3]);
}

// --- arrays[0]
#ifdef dHAS_ZERO_ARRAY
TEST_COMPONENT(007)
{
    dTEST_FALSE(wchar_t[0]                      );
    dTEST_FALSE(char[0]                         );
    dTEST_FALSE(char(&)[0]                      );
    dTST_RVALUE(char(&&)[0]                     );
    dTEST_FALSE(char(*)[0]                      );
    dTEST_FALSE(char(*&)[0]                     );
//------------------------------------------------------------------------------
    dTEST_FALSE(const char[0]                   );
    dTEST_FALSE(const char(&)[0]                );
    dTST_RVALUE(const char(&&)[0]               );
    dTEST_FALSE(const char(*)[0]                );
    dTEST_FALSE(const char(*&)[0]               );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile char[0]                );
    dTEST_FALSE(volatile char(&)[0]             );
    dTST_RVALUE(volatile char(&&)[0]            );
    dTEST_FALSE(volatile char(*)[0]             );
    dTEST_FALSE(volatile char(*&)[0]            );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile const char[0]          );
    dTEST_FALSE(volatile const char(&)[0]       );
    dTST_RVALUE(volatile const char(&&)[0]      );
    dTEST_FALSE(volatile const char(*)[0]       );
    dTEST_FALSE(volatile const char(*&)[0]      );
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    dTEST_FALSE(char[0][2][3]                   );
    dTEST_FALSE(char(&)[0][2][3]                );
    dTST_RVALUE(char(&&)[0][2][3]               );
    dTEST_FALSE(char(*)[0][2][3]                );
    dTEST_FALSE(char(*&)[0][2][3]               );
//------------------------------------------------------------------------------
    dTEST_FALSE(const char[0][2][3]             );
    dTEST_FALSE(const char(&)[0][2][3]          );
    dTST_RVALUE(const char(&&)[0][2][3]         );
    dTEST_FALSE(const char(*)[0][2][3]          );
    dTEST_FALSE(const char(*&)[0][2][3]         );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile char[0][2][3]          );
    dTEST_FALSE(volatile char(&)[0][2][3]       );
    dTST_RVALUE(volatile char(&&)[0][2][3]      );
    dTEST_FALSE(volatile char(*)[0][2][3]       );
    dTEST_FALSE(volatile char(*&)[0][2][3]      );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile const char[0][2][3]    );
    dTEST_FALSE(volatile const char(&)[0][2][3] );
    dTST_RVALUE(volatile const char(&&)[0][2][3]);
    dTEST_FALSE(volatile const char(*)[0][2][3] );
    dTEST_FALSE(volatile const char(*&)[0][2][3]);
}
#endif // !dHAS_ZERO_ARRAY

// --- functions int()
TEST_COMPONENT(008)
{
    dTEST_FALSE(int()                    );
    dTEST_FALSE(int(&)()                 );
    dTST_RVALUE(int(&&)()                );
    
    dTEST_FALSE(int(*)()                 );
    dTEST_FALSE(int(* const)()           );
    dTEST_FALSE(int(* volatile)()        );
    dTEST_FALSE(int(* volatile const)()  );
    
    dTEST_FALSE(int(*&)()                );
    dTEST_FALSE(int(* const&)()          );
    dTEST_FALSE(int(* volatile&)()       );
    dTEST_FALSE(int(* volatile const&)() );
    
    dTST_RVALUE(int(*&&)()               );
    dTST_RVALUE(int(* const&&)()         );
    dTST_RVALUE(int(* volatile&&)()      );
    dTST_RVALUE(int(* volatile const&&)());
}

// --- function-pointers
TEST_COMPONENT(009)
{                  
    dTEST_FALSE(int(* const*&)(bool, char)                   );
    dTEST_FALSE(int(** const*&)(bool, char)                  );
    dTEST_FALSE(int(* const* const*&)(bool, char)            );
    dTEST_FALSE(int(* volatile* volatile*&)(bool, char)      );
    dTEST_FALSE(int(* volatile* volatile const*&)(bool, char));
}

// --- abominable int() const
#ifdef dHAS_ABOMINABLE
TEST_COMPONENT(010)
{
    dTEST_FALSE(int()                   );
    dTEST_FALSE(int() const             );
    
    dTEST_FALSE(int() volatile          );
    dTEST_FALSE(int() volatile const    );

    dTEST_FALSE(int() &                 );
    dTEST_FALSE(int() const &           );
    dTEST_FALSE(int() volatile &        );
    dTEST_FALSE(int() volatile const &  );

    dTEST_FALSE(int() &&                );
    dTEST_FALSE(int() const &&          );
    dTEST_FALSE(int() volatile &&       );
    dTEST_FALSE(int() volatile const && );
}
#endif

// --- method int(some::*)()
TEST_COMPONENT(011)
{
    dTEST_FALSE(int(some::*)()                 );
    dTEST_FALSE(int(some::*&)()                );
    dTST_RVALUE(int(some::*&&)()               );

    dTEST_FALSE(int(some::* const)()           );
    dTEST_FALSE(int(some::* volatile)()        );
    dTEST_FALSE(int(some::* volatile const)()  );

    dTEST_FALSE(int(some::* const&)()          );
    dTEST_FALSE(int(some::* volatile&)()       );
    dTEST_FALSE(int(some::* volatile const&)() );

    dTST_RVALUE(int(some::* const&&)()         );
    dTST_RVALUE(int(some::* volatile&&)()      );
    dTST_RVALUE(int(some::* volatile const&&)());
}

// --- member int
TEST_COMPONENT(012)
{
    dTEST_FALSE(int some::*                                );
    dTEST_FALSE(int some::*&                               );
    dTST_RVALUE(int some::*&&                              );

    dTEST_FALSE(int some::* const                          );
    dTEST_FALSE(int some::* const&                         );
    dTST_RVALUE(int some::* const&&                        );

    dTEST_FALSE(int some::* volatile                       );
    dTEST_FALSE(int some::* volatile&                      );
    dTST_RVALUE(int some::* volatile&&                     );

    dTEST_FALSE(int some::* volatile const                 );
    dTEST_FALSE(int some::* volatile const&                );
    dTST_RVALUE(int some::* volatile const&&               );
//------------------------------------------------------------------------------
    dTEST_FALSE(const int some::*                          );
    dTEST_FALSE(const int some::*&                         );
    dTST_RVALUE(const int some::*&&                        );
    
    dTEST_FALSE(const int some::* const                    );
    dTEST_FALSE(const int some::* const&                   );
    dTST_RVALUE(const int some::* const&&                  );

    dTEST_FALSE(const int some::* volatile                 );
    dTEST_FALSE(const int some::* volatile&                );
    dTST_RVALUE(const int some::* volatile&&               );

    dTEST_FALSE(const int some::* volatile const           );
    dTEST_FALSE(const int some::* volatile const&          );
    dTST_RVALUE(const int some::* volatile const&&         );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile int some::*                       );
    dTEST_FALSE(volatile int some::*&                      );
    dTST_RVALUE(volatile int some::*&&                     );

    dTEST_FALSE(volatile int some::* const                 );
    dTEST_FALSE(volatile int some::* const&                );
    dTST_RVALUE(volatile int some::* const&&               );

    dTEST_FALSE(volatile int some::* volatile              );
    dTEST_FALSE(volatile int some::* volatile&             );
    dTST_RVALUE(volatile int some::* volatile&&            );

    dTEST_FALSE(volatile int some::* volatile const        );
    dTEST_FALSE(volatile int some::* volatile const&       );
    dTST_RVALUE(volatile int some::* volatile const&&      );
//------------------------------------------------------------------------------
    dTEST_FALSE(volatile const int some::*                 );
    dTEST_FALSE(volatile const int some::*&                );
    dTST_RVALUE(volatile const int some::*&&               );

    dTEST_FALSE(volatile const int some::* const           );
    dTEST_FALSE(volatile const int some::* const&          );
    dTST_RVALUE(volatile const int some::* const&&         );

    dTEST_FALSE(volatile const int some::* volatile        );
    dTEST_FALSE(volatile const int some::* volatile&       );
    dTST_RVALUE(volatile const int some::* volatile&&      );

    dTEST_FALSE(volatile const int some::* volatile const  );
    dTEST_FALSE(volatile const int some::* volatile const& );
    dTST_RVALUE(volatile const int some::* volatile const&&);
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

    dTEST_FALSE(arr some::*   );
    dTEST_FALSE(foo some::*   );
    dTEST_FALSE(arrfoo some::*);
    dTEST_FALSE(pfoo some::*  );
    dTEST_FALSE(method some::*);
}

//==============================================================================
//==============================================================================
#endif // !TEST_IS_SAME

