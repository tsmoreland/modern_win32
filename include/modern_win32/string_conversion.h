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
#ifdef _WIN32

#include <Windows.h>
#include <string>
#include <string_view>
#include <modern_win32/windows_exception.h>

namespace modern_win32::convert
{

    template <class ALLOC = std::allocator<wchar_t>>
    [[nodiscard]] inline std::basic_string<wchar_t, std::char_traits<wchar_t>, ALLOC> to_wstring(char const* value)
    {
        using string_custom_alloc = std::basic_string<wchar_t, std::char_traits<wchar_t>, ALLOC>;
        if (value == nullptr)
            return L"";

        std::string_view const value_view{value};
        auto const size_needed = MultiByteToWideChar(CP_UTF8, 0, value, static_cast<int>(value_view.size()), nullptr, 0);

        string_custom_alloc output(static_cast<typename string_custom_alloc::size_type>(size_needed), 0);
        if (0 != MultiByteToWideChar(CP_UTF8, 0, value, static_cast<int>(value_view.size()), &output[0], static_cast<std::wstring::size_type>(size_needed)))
            throw modern_win32::windows_exception();
        return output;
    }

    template <class ALLOC = std::allocator<wchar_t>>
    [[nodiscard]] constexpr std::basic_string<wchar_t, std::char_traits<wchar_t>, ALLOC> to_wstring(std::string const& value)
    {
        return to_wstring<ALLOC>(value.c_str());
    }

    template <class ALLOC = std::allocator<char>>
    [[nodiscard]] std::basic_string<char, std::char_traits<char>, ALLOC> to_string(wchar_t const* value)
    {
        using string_custom_alloc = std::basic_string<char, std::char_traits<char>, ALLOC>;
        if (value == nullptr)
            return "";

        std::wstring_view const value_view(value);
        auto const size_needed = WideCharToMultiByte(CP_UTF8, 0, value, static_cast<int>(value_view.size()), nullptr, 0, nullptr, nullptr);

        string_custom_alloc output(static_cast<typename string_custom_alloc::size_type>(size_needed), 0);
        if (0 != WideCharToMultiByte(CP_UTF8, 0, value, static_cast<int>(value_view.size()), &output[0], static_cast<std::wstring::size_type>(size_needed), nullptr, nullptr))
            throw modern_win32::windows_exception();
        return output;
    }

    template <class ALLOC = std::allocator<char>>
    [[nodiscard]] constexpr std::basic_string<char, std::char_traits<char>, ALLOC> to_string(std::wstring const& value)
    {
        return to_string<ALLOC>(value.c_str());
    }

#   if __cplusplus > 201703L || _MSVC_LANG > 201703L

#   endif


}
#endif
#endif
