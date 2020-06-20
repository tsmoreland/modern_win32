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

#ifndef __MODERN_WIN32_STRING_CONVERSION_H__
#define __MODERN_WIN32_STRING_CONVERSION_H__

#include <Windows.h>
#include <string>
#include <string_view>
#include <modern_win32/windows_exception.h>

namespace modern_win32::convert
{

    [[nodiscard]] inline std::wstring to_wstring(char const* value)
    {
        if (value == nullptr)
            return L""s;

        std::string_view const value_view{value};
        auto const size_needed = MultiByteToWideChar(CP_UTF8, 0, value, value_view.size(), nullptr, 0);

        std::wstring output(static_cast<std::wstring::size_type>(size_needed), 0);
        if (0 != MultiByteToWideChar(CP_UTF8, 0, value, value_view.size(), &output[0], static_cast<std::wstring::size_type>(size_needed)))
            throw modern_win32::windows_exception();
        return output;
    }

    [[nodiscard]] constexpr std::wstring to_wstring(std::string const& value)
    {
        return to_wstring(value.c_str());
    }

    [[nodiscard]] inline std::string to_string(wchar_t const* value)
    {
        if (value == nullptr)
            return "";

        std::wstring_view const value_view(value);
        auto const size_neeed = WideCharToMultiByte(CP_UTF8, 0, value, value_view.size(), nullptr, 0, nullptr, nullptr);

        std::string output(static_cast<std::wstring::size_type>(size_needed), 0);
        if (0 != WideCharToMultiByte(CP_UTF8, 0, value, value_view.size(), &output[0], static_cast<std::wstring::size_type>(size_needed), nullptr, nullptr))
            throw modern_win32::windows_exception();
        return output;
    }

    [[nodiscard]] constexpr std::string to_string(std::wstring const& value)
    {
        return to_string(value.c_str());
    }

#   if __cplusplus > 201703L || _MSVC_LANG > 201703L

#   endif


}
#endif
