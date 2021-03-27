
// [2019y-10m-24d][19:22:08] Idrisov Denis R.
// [2021y-02m-20d][18:40:18] Idrisov Denis R.
#include <mygtest/modern.hpp>

#ifdef TEST_TOOLS_DEMANGLE

#include <tools/types/demangle.hpp>

#define dTEST_COMPONENT tools, types
#define dTEST_METHOD demangle
#define dTEST_TAG tdd


#ifdef _MSC_VER
    // warning C4197: volatile const unsigned char: top-level volatile in cast is ignored
    #pragma warning(disable : 4197)
#endif

namespace me = ::tools;
//================================================================================
//=== check_demangle =============================================================
namespace
{
    template<class t, class s> void check_demangle(const s& etalon)
    {
        t obj = 0;
        (void) obj;

        const std::string name1
            = me::demangle(typeid(t).name());

        const std::string name2
            = me::demangle(typeid(obj).name());

        const std::string name3
            = me::demangle<t>();
        
        ASSERT_TRUE(name1 == name2)
            << "assert(name1 == name2):\n"
            << "name1 = " << name1 << '\n'
            << "name2 = " << name2 << '\n'
        ;
        ASSERT_TRUE(name1 == name3)
            << "assert(name1 == name3):\n"
            << "name1 = " << name1 << '\n'
            << "name3 = " << name3 << '\n'
        ;

        ASSERT_TRUE(name1 == etalon)
            << "assert(name1 == etalon):\n"
            << "name1 = "  << name1  << '\n'
            << "etalon = " << etalon << '\n'
        ;
    }

    template<class void_type> void check_demangle_void()
    {
        const std::string name
            = me::demangle(typeid(void_type).name());

        ASSERT_TRUE(name == "void")
            << "assert(name == 'void'):\n"
            << "name = " << name  <<  '\n'
        ;
    }

} // namespace

//================================================================================

// --- demangle primitive 
TEST_COMPONENT(000)
{
    check_demangle<short        >("short"        );
    check_demangle<long         >("long"         );
    check_demangle<int          >("int"          );
    check_demangle<bool         >("bool"         );
    check_demangle<char         >("char"         );
    check_demangle<wchar_t      >("wchar_t"      );
    check_demangle<signed char  >("signed char"  );
    check_demangle<unsigned char>("unsigned char");
    check_demangle<unsigned     >("unsigned int" );
}

// --- ignore const
TEST_COMPONENT(001)
{
    check_demangle<const short        >("short"        );
    check_demangle<const long         >("long"         );
    check_demangle<const int          >("int"          );
    check_demangle<const bool         >("bool"         );
    check_demangle<const char         >("char"         );
    check_demangle<const wchar_t      >("wchar_t"      );
    check_demangle<const signed char  >("signed char"  );
    check_demangle<const unsigned char>("unsigned char");
    check_demangle<const unsigned     >("unsigned int" );
}

// --- ignore volatile
TEST_COMPONENT(002)
{
    check_demangle<volatile short        >("short"        );
    check_demangle<volatile long         >("long"         );
    check_demangle<volatile int          >("int"          );
    check_demangle<volatile bool         >("bool"         );
    check_demangle<volatile char         >("char"         );
    check_demangle<volatile wchar_t      >("wchar_t"      );
    check_demangle<volatile signed char  >("signed char"  );
    check_demangle<volatile unsigned char>("unsigned char");
    check_demangle<volatile unsigned     >("unsigned int" );
}

// --- ignore volatile const
TEST_COMPONENT(003)
{
    check_demangle<volatile const short        >("short"        );
    check_demangle<volatile const long         >("long"         );
    check_demangle<volatile const int          >("int"          );
    check_demangle<volatile const bool         >("bool"         );
    check_demangle<volatile const char         >("char"         );
    check_demangle<volatile const wchar_t      >("wchar_t"      );
    check_demangle<volatile const signed char  >("signed char"  );
    check_demangle<volatile const unsigned char>("unsigned char");
    check_demangle<volatile const unsigned     >("unsigned int" );
}

// --- ignore reference
#ifdef dHAS_RVALUE_REFERENCES
TEST_COMPONENT(004)
{
    check_demangle<const short&         >("short"        );
    check_demangle<const long&          >("long"         );
    check_demangle<const int&           >("int"          );
    check_demangle<const bool&          >("bool"         );
    check_demangle<const char&          >("char"         );
    check_demangle<const wchar_t&       >("wchar_t"      );
    check_demangle<const signed char&   >("signed char"  );
    check_demangle<const unsigned char& >("unsigned char");
    check_demangle<const unsigned&      >("unsigned int" );
}

// --- ignore rvalue
TEST_COMPONENT(005)
{
    check_demangle<const short&&         >("short"        );
    check_demangle<const long&&          >("long"         );
    check_demangle<const int&&           >("int"          );
    check_demangle<const bool&&          >("bool"         );
    check_demangle<const char&&          >("char"         );
    check_demangle<const wchar_t&&       >("wchar_t"      );
    check_demangle<const signed char&&   >("signed char"  );
    check_demangle<const unsigned char&& >("unsigned char");
    check_demangle<const unsigned&&      >("unsigned int" );
}
#endif // !dHAS_RVALUE_REFERENCES

// --- demangle void
TEST_COMPONENT(006)
{
    // ignore const/volatile 
    check_demangle_void<void>();
    check_demangle_void<const void>();
    check_demangle_void<volatile void>();
    check_demangle_void<volatile const void>();
}

//================================================================================

#endif // !TEST_TOOLS_TYPE_DEMANGLE

