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

#ifndef __MODERN_WIN32_SHARED_WINDOWS_EXCEPTION_H__
#define __MODERN_WIN32_SHARED_WINDOWS_EXCEPTION_H__

#if _WIN32

#include <system_error>
#include <Windows.h>
#include <modern_win32/windows_error.h>

namespace modern_win32
{
    /// <summary>
    /// wrapper around system_error which constructs error value from GetLastError result
    /// </summary>
    class windows_exception final : public std::system_error
    {
    public:
        explicit windows_exception() 
            : windows_exception(GetLastError())
        {
        }
        explicit windows_exception(char const* message) 
            : windows_exception(GetLastError(), message)
        {
        }
        explicit windows_exception(native_windows_error const error_code) 
            : std::system_error(error_code, std::system_category())
            , m_error(error_code)
        {
        }
        explicit windows_exception(native_windows_error const error_code, char const* message) 
            : std::system_error(error_code, std::system_category(), message)
            , m_error(error_code)
        {
        }
        explicit windows_exception(windows_error_details const& error) 
            : std::system_error(error.native_error_code(), std::system_category())
            , m_error(error)
        {
        }
        explicit windows_exception(windows_error_details const& error, char const* message) 
            : std::system_error(error.native_error_code(), std::system_category(), message)
            , m_error(error)
        {
        }
        explicit windows_exception(windows_error const error) 
            : std::system_error(static_cast<native_windows_error>(error), std::system_category())
            , m_error(error)
        {
        }
        explicit windows_exception(windows_error const error, char const* message) 
            : std::system_error(static_cast<native_windows_error>(error), std::system_category(), message)
            , m_error(error)
        {
        }
    private:
        windows_error_details m_error;
    };

}

#endif
#endif

