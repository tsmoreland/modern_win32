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

#ifndef __MODERN_wait_for_H__
#define __MODERN_wait_for_H__
#ifdef _WIN32

#include <Windows.h>
#include <chrono>
#include <modern_win32/windows_exception.h>

namespace modern_win32
{
    using wait_result = decltype(WaitForSingleObject(std::declval<HANDLE>(), std::declval<DWORD>()));

    enum class wait_for_result : wait_result
    {
        object = WAIT_OBJECT_0,
        abandonded = WAIT_ABANDONED,
        failed = WAIT_FAILED,
        timeout = WAIT_TIMEOUT,
    };

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

#       define max(a,b) (a) > (b) ? (a) : (b);  // NOLINT(cppcoreguidelines-macro-usage)
    }

    constexpr void add_to_array(HANDLE *){}

    template <typename T, typename... ARGS>
    constexpr void add_to_array(HANDLE * first, T const & remaining, ARGS const & ... args) 
    {
        *first = remaining.native_handle();
        add_to_array(++first, args...);
    }

    template <typename... UNIQUE_HANDLES>
    bool wait_all(UNIQUE_HANDLES const & ... args) 
    {
        static_assert(sizeof...(UNIQUE_HANDLES) < static_cast<size_t>(MAXIMUM_WAIT_OBJECTS));
        HANDLE handles[sizeof...(UNIQUE_HANDLES)];
        add_to_array(handles, args...);
        WaitForMultipleObjects(sizeof...(UNIQUE_HANDLES), handles, true, INFINITE);
        return true;
    }

    [[nodiscard]] inline bool wait_for_single_object_to_bool(wait_result const& result)
    {
        switch (result)
        {
        case WAIT_OBJECT_0:
            return true;
        case WAIT_FAILED:
            throw windows_exception("an error occurred attempting to wait");
        case WAIT_ABANDONED:
            throw std::runtime_error("handle represented a mutex which was abondoned rather than process");
        case WAIT_TIMEOUT:
        default:
            return false;
        }
    }



}

#endif
#endif