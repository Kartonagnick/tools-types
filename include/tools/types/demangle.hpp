// [2019y-10m-24d][19:22:08] Idrisov Denis R.
// [2020y-09m-04d][00:00:00] Idrisov Denis R.
// [2021y-02m-20d][18:40:18] Idrisov Denis R.
//==============================================================================
#pragma once
#ifndef dTOOLS_DEMANGLE_USED_ 
#define dTOOLS_DEMANGLE_USED_ 1

#include <tools/features.hpp>
#include <tools/assert.hpp>
#include <typeinfo>
#include <string>

#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW__)
    #include <cxxabi.h>
    #include <cstdlib>
#endif
//==============================================================================
//=== demangle =================================================================
namespace tools
{
    #if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW__)

        // name - is result of 'typeid(type).name()'
        inline ::std::string demangle(const char* name)
        {
            dASSERT(name);
            int status = -4;
            char* res = ::abi::__cxa_demangle(name, NULL, NULL, &status);

            ::std::string result;
            if(status == 0)
                result = res,
                ::free(res);
            else
                result = name;

            return result;
        }

        template<class t> ::std::string demangle() 
        {
            return ::tools::demangle(typeid(t).name());
        }

    #else

        // name - is result of 'typeid(type).name()'
        inline const char* demangle(const char* name) dNOEXCEPT
        { 
            dASSERT(name);
            return name; 
        }

        template<class t> const char* demangle() dNOEXCEPT
        {
            return typeid(t).name();
        }

    #endif
    
} // namespace tools

//==============================================================================
//==============================================================================
#endif // !dTOOLS_DEMANGLE_USED_
