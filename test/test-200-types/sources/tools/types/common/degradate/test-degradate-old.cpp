// [2021y-02m-20d][18:40:18] Idrisov Denis R.
// [2021y-03m-17d][20:49:29] Idrisov Denis R.
// [2021y-04m-10d][03:53:55] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_DEGRADATE

#define dTEST_COMPONENT tools, types, common
#define dTEST_METHOD degradate
#define dTEST_TAG old

#include <tools/types/common.hpp>
#include <string>

namespace me = ::tools;
//==============================================================================
//=== make_test ================================================================
namespace
{
    #define dVAL(a) \
        typename me::degradate<a>::type

    #define dEXPRESSION(a,b) \
        dTRAIT::is_same<dVAL(a), b>::value 

    #ifdef dHAS_STATIC_ASSERT
        #define make_test(src, etalon)               \
            static_assert(                           \
                dEXPRESSION(src, etalon),            \
                "tools::degradate<" #src ">::type "  \
                "must be '" #etalon "'"              \
            )
    #else
        #define make_test(a, etalon)    \
            dSTATIC_ASSERT(             \
                ERROR_MUST_BE,          \
                dEXPRESSION(a, etalon)  \
            )
    #endif

    #ifdef dHAS_RVALUE_REFERENCE
        #define make_rval(a,b) make_test(a,b)
    #else
        #define make_rval(a, b) \
            typedef void dummy_t
    #endif

    make_test(int       , int);
    make_test(const int , int);
    make_test(const int&, int);

}//namespace

//==============================================================================
//=== stringed(char) ===========================================================
namespace
{
    make_test(signed char        , signed char   ); 
    make_test(unsigned char      , unsigned char ); 

    make_test(const char         , char          ); // 00
    make_test(char               , char          ); // 01
                                                              
    make_rval(const std::string&&, std::string   ); // 02   
    make_rval(std::string&&      , std::string   ); // 03
    make_test(const std::string& , std::string   ); // 04
    make_test(std::string&       , std::string   ); // 05
    make_test(const std::string  , std::string   ); // 06
    make_test(std::string        , std::string   ); // 07
                                                              
    make_rval(char*const&&       , char*         ); // 09
    make_rval(char*&&            , char*         ); // 10      
    make_test(char*const&        , char*         ); // 11      
    make_test(char*&             , char*         ); // 12      
    make_test(char*const         , char*         ); // 13      
    make_test(char*              , char*         ); // 14      
                                                              
    make_rval(const char*const&& , const char*   ); // 15      
    make_rval(const char*&&      , const char*   ); // 16      
    make_test(const char*const&  , const char*   ); // 17      
    make_test(const char*&       , const char*   ); // 18      
    make_test(const char*const   , const char*   ); // 19      
    make_test(const char*        , const char*   ); // 20      
                                                              
    make_rval(const char(&&)[255], char[255]     ); // 21      
    make_rval(char(&&)[255]      , char[255]     ); // 22      
    make_test(const char(&)[255] , char[255]     ); // 23      
    make_test(char(&)[255]       , char[255]     ); // 24      
    make_test(const char[255]    , char[255]     ); // 25      
    make_test(char[255]          , char[255]     ); // 26      
    
    #ifdef dHAS_ARRAY_EMPTY_SIZE
    make_rval(const char(&&)[]   , char[]        ); // 27        
    make_rval(char(&&)[]         , char[]        ); // 28        
    make_test(const char(&)[]    , char[]        ); // 29        
    make_test(char(&)[]          , char[]        ); // 30        
    make_test(const char[]       , char[]        ); // 31        
    make_test(char[]             , char[]        ); // 32        
    #endif

    #ifdef dHAS_ZERO_SIZE_ARRAY
    dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        make_test(const char(&&)[0]  , char[0]       ); // 33        invalid types
        make_test(char(&&)[0]        , char[0]       ); // 34        invalid types
        make_test(const char(&)[0]   , char[0]       ); // 35        invalid types
        make_test(char(&)[0]         , char[0]       ); // 36        invalid types
        make_test(const char[0]      , char[0]       ); // 37        invalid types
        make_test(char[0]            , char[0]       ); // 38        invalid types
    dPRAGMA_POP
    #endif // !dHAS_ZERO_SIZE_ARRAY

}//namespace

//==============================================================================
//=== stringed(wchar_t) ========================================================
namespace 
{
    make_test(const wchar_t         , wchar_t          ); // 00
    make_test(wchar_t               , wchar_t          ); // 01
                                                              
    make_rval(const std::wstring&&  , std::wstring     ); // 02   
    make_rval(std::wstring&&        , std::wstring     ); // 03
    make_test(const std::wstring&   , std::wstring     ); // 04
    make_test(std::wstring&         , std::wstring     ); // 05
    make_test(const std::wstring    , std::wstring     ); // 06
    make_test(std::wstring          , std::wstring     ); // 07
                                                              
    make_rval(wchar_t*const&&       , wchar_t*         ); // 09
    make_rval(wchar_t*&&            , wchar_t*         ); // 10      
    make_test(wchar_t*const&        , wchar_t*         ); // 11      
    make_test(wchar_t*&             , wchar_t*         ); // 12      
    make_test(wchar_t*const         , wchar_t*         ); // 13      
    make_test(wchar_t*              , wchar_t*         ); // 14      
                                                              
    make_rval(const wchar_t*const&& , const wchar_t*   ); // 15      
    make_rval(const wchar_t*&&      , const wchar_t*   ); // 16      
    make_test(const wchar_t*const&  , const wchar_t*   ); // 17      
    make_test(const wchar_t*&       , const wchar_t*   ); // 18      
    make_test(const wchar_t*const   , const wchar_t*   ); // 19      
    make_test(const wchar_t*        , const wchar_t*   ); // 20      
                                                              
    make_rval(const wchar_t(&&)[255], wchar_t[255]     ); // 21      
    make_rval(wchar_t(&&)[255]      , wchar_t[255]     ); // 22      
    make_test(const wchar_t(&)[255] , wchar_t[255]     ); // 23      
    make_test(wchar_t(&)[255]       , wchar_t[255]     ); // 24      
    make_test(const wchar_t[255]    , wchar_t[255]     ); // 25      
    make_test(wchar_t[255]          , wchar_t[255]     ); // 26      
                  
    #ifdef dHAS_ARRAY_EMPTY_SIZE
    make_rval(const wchar_t(&&)[]   , wchar_t[]        ); // 27        
    make_rval(wchar_t(&&)[]         , wchar_t[]        ); // 28        
    make_test(const wchar_t(&)[]    , wchar_t[]        ); // 29        
    make_test(wchar_t(&)[]          , wchar_t[]        ); // 30        
    make_test(const wchar_t[]       , wchar_t[]        ); // 31        
    make_test(wchar_t[]             , wchar_t[]        ); // 32        
    #endif

    #ifdef dHAS_ZERO_SIZE_ARRAY
    dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        make_test(const wchar_t(&&)[0]  , wchar_t[0]       ); // 33        invalid types
        make_test(wchar_t(&&)[0]        , wchar_t[0]       ); // 34        invalid types
        make_test(const wchar_t(&)[0]   , wchar_t[0]       ); // 35        invalid types
        make_test(wchar_t(&)[0]         , wchar_t[0]       ); // 36        invalid types
        make_test(const wchar_t[0]      , wchar_t[0]       ); // 37        invalid types
        make_test(wchar_t[0]            , wchar_t[0]       ); // 38        invalid types
    dPRAGMA_POP
    #endif

} // namespace

//==============================================================================
//=== stringed(int) ============================================================
namespace
{
    typedef ::std::basic_string<int> 
        string_t;

    make_test(const int         , int          ); // 00
    make_test(int               , int          ); // 01
                                                              
    make_rval(const string_t&&  , string_t     ); // 02   
    make_rval(string_t&&        , string_t     ); // 03
    make_test(const string_t&   , string_t     ); // 04
    make_test(string_t&         , string_t     ); // 05
    make_test(const string_t    , string_t     ); // 06
    make_test(string_t          , string_t     ); // 07
                                                              
    make_rval(int*const&&       , int*         ); // 09
    make_rval(int*&&            , int*         ); // 10      
    make_test(int*const&        , int*         ); // 11      
    make_test(int*&             , int*         ); // 12      
    make_test(int*const         , int*         ); // 13      
    make_test(int*              , int*         ); // 14      
                                                              
    make_rval(const int*const&& , const int*   ); // 15      
    make_rval(const int*&&      , const int*   ); // 16      
    make_test(const int*const&  , const int*   ); // 17      
    make_test(const int*&       , const int*   ); // 18      
    make_test(const int*const   , const int*   ); // 19      
    make_test(const int*        , const int*   ); // 20      
                                                              
    make_rval(const int(&&)[255], int[255]     ); // 21      
    make_rval(int(&&)[255]      , int[255]     ); // 22      
    make_test(const int(&)[255] , int[255]     ); // 23      
    make_test(int(&)[255]       , int[255]     ); // 24      
    make_test(const int[255]    , int[255]     ); // 25      
    make_test(int[255]          , int[255]     ); // 26      
                            
    #ifdef dHAS_ARRAY_EMPTY_SIZE
    make_rval(const int(&&)[]   , int[]        ); // 27        
    make_rval(int(&&)[]         , int[]        ); // 28        
    make_test(const int(&)[]    , int[]        ); // 29        
    make_test(int(&)[]          , int[]        ); // 30        
    make_test(const int[]       , int[]        ); // 31        
    make_test(int[]             , int[]        ); // 32        
    #endif
                
    #ifdef dHAS_ZERO_SIZE_ARRAY
    dPRAGMA_PUSH_WARNING_ZERO_SIZE_ARRAY
        make_test(const int(&&)[0]  , int[0]       ); // 33        invalid types
        make_test(int(&&)[0]        , int[0]       ); // 34        invalid types
        make_test(const int(&)[0]   , int[0]       ); // 35        invalid types
        make_test(int(&)[0]         , int[0]       ); // 36        invalid types
        make_test(const int[0]      , int[0]       ); // 37        invalid types
        make_test(int[0]            , int[0]       ); // 38        invalid types
    dPRAGMA_POP
    #endif

} // namespace

//==============================================================================
//==============================================================================

TEST_COMPONENT(000){}

//==============================================================================
//==============================================================================
#endif // !TEST_TOOLS_DEGRADATE

