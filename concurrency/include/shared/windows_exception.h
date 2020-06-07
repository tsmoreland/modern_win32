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

#ifndef __MORELAND_SHARED_WINDOWS_EXCEPTION_H__
#define __MORELAND_SHARED_WINDOWS_EXCEPTION_H__

#if _WIN32

#include <stdexcept>
#include <Windows.h>

namespace moreland::shared
{
    class windows_exception final : public std::exception
    {
        using error_code_type = decltype(GetLastError());
    public:
        explicit windows_exception(error_code_type const error, char const* message) 
            : std::exception(message)
            , m_error_code(error)
        {
        }
        explicit windows_exception(char const* message) 
            : std::exception(message)
            , m_error_code(GetLastError())
        {
        }
        explicit windows_exception() 
            : std::exception("An error occurred with Win32 function, please check error code for more details")
            , m_error_code(GetLastError())
        {
        }

        [[nodiscard]] error_code_type get_error_code() const noexcept 
        {
            return m_error_code;
        }
    private:
        error_code_type m_error_code;

    };

}

#endif
#endif

