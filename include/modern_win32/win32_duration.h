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

#ifndef __MODERN_WIN32_DURATION_H__
#define __MODERN_WIN32_DURATION_H__
#ifdef _WIN32

#include <Windows.h>
#include <chrono>

namespace modern_win32
{
    constexpr auto get_infinity_in_ms()
    {
        // same as std::chrono::millisecond::rep, done to show it can be done this way
        using millisecond_rep = decltype(std::declval<std::chrono::milliseconds>().count());
        return std::chrono::duration<millisecond_rep>(INFINITE);
    }

    constexpr auto convert_timeout(std::chrono::milliseconds const& timeout)
    {
#       undef max // disable so we can use numerical_limits
        return (timeout >= get_infinity_in_ms())
            ? INFINITE
            : static_cast<DWORD>(timeout.count());

#       define max(a,b) (a) > (b) ? (a) : (b);
    }
}

#endif
#endif