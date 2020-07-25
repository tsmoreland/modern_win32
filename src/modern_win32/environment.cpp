//
// Copyright © 2020 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 

#include <modern_win32/environment.h>
#include <Windows.h>
#include <processenv.h>
#include <memory>

namespace modern_win32
{


template <>
bool try_get_all_environment_variables(environment_map<char>& environment)
{
#   ifdef UNICODE
#   undef GetEnvironmentStrings
    auto deleter = [](char*& character) { FreeEnvironmentStringsA(character); };
    auto env_block = std::unique_ptr<char, decltype(deleter)>{GetEnvironmentStrings(), deleter};
#   define GetEnvironmentStrings GetEnvironmentStringsW  // NOLINT(cppcoreguidelines-macro-usage) -- re-enabling GetEnvironmentStrings macro
#   else 
    auto deleter = [](char* character) { FreeEnvironmentStringsA(character); };
    auto env_block = std::unique_ptr<char, decltype(free)>{GetEnvironmentStrings(), deleter};
#   endif



    return true;
}

template <>
bool try_get_all_environment_variables(environment_map<wchar_t>& environment)
{
    auto deleter = [](wchar_t*& character) { FreeEnvironmentStringsW(character); };
    auto env_block = std::unique_ptr<wchar_t, decltype(deleter)>{GetEnvironmentStringsW(), deleter};

    return true;
}

}