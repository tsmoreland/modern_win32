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
        io_completion = WAIT_IO_COMPLETION,
        failed = WAIT_FAILED,
        timeout = WAIT_TIMEOUT,
    };

    /// <summary>
    /// converts <paramref name="result"/> to matching value from <see cref="wait_for_result"/>
    /// </summary>
    /// <param name="result">value to convert</param>
    /// <returns>value from <see cref="wait_for_result"/></returns>
    [[nodiscard]] inline wait_for_result to_wait_for_result(wait_result const& result)
    {
        switch (result)
        {
        case WAIT_FAILED:
            return wait_for_result::failed;
        case WAIT_TIMEOUT:
            return wait_for_result::timeout;
        case WAIT_IO_COMPLETION:
            return wait_for_result::io_completion;
        case WAIT_ABANDONED:
            return wait_for_result::abandonded;
        case WAIT_OBJECT_0:
            return wait_for_result::object;
        default:
            if (WAIT_OBJECT_0 >= result && result < WAIT_OBJECT_0 + MAXIMUM_WAIT_OBJECTS)
                return wait_for_result::object;
            else
                return wait_for_result::abandonded;
        }

    }


    constexpr auto get_infinity_in_ms()
    {
        // same as std::chrono::millisecond::rep, done to show it can be done this way
        using millisecond_rep = decltype(std::declval<std::chrono::milliseconds>().count());
        return std::chrono::duration<millisecond_rep>(INFINITE);
    }

    constexpr auto to_dword(std::chrono::milliseconds const& timeout)
    {
#       undef max // disable so we can use numerical_limits
        return (timeout >= get_infinity_in_ms())
            ? INFINITE
            : static_cast<DWORD>(timeout.count());

#       define max(a,b) (a) > (b) ? (a) : (b);  // NOLINT(cppcoreguidelines-macro-usage)
    }

    template <typename NUMERIC>
    constexpr auto as(std::chrono::milliseconds const& timeout)
    {
        static_assert(std::is_arithmetic<NUMERIC>::value);

#       undef max // disable so we can use numerical_limits
        using millisecond_rep = decltype(std::declval<std::chrono::milliseconds>().count());
        if (timeout > static_cast<millisecond_rep>(std::numeric_limits<NUMERIC>::max())) {
            return std::numeric_limits<NUMERIC>::max();
        } else
            return static_cast<NUMERIC>(timeout.count());
#       define max(a,b) (a) > (b) ? (a) : (b);  // NOLINT(cppcoreguidelines-macro-usage)
    }

    constexpr void add_to_array(HANDLE *){}

    template <typename T, typename... ARGS>
    constexpr void add_to_array(HANDLE * first, T const & remaining, ARGS const & ... args) 
    {
        *first = remaining.native_handle();
        add_to_array(++first, args...);
    }

    template <typename... HANDLES>
    [[nodiscard]] auto wait_all(std::chrono::milliseconds const& timeout, HANDLES const & ... args)  noexcept
    {
        static_assert(sizeof...(HANDLES) < static_cast<size_t>(MAXIMUM_WAIT_OBJECTS));
        HANDLE handles[sizeof...(HANDLES)];
        add_to_array(handles, args...);
        return to_wait_for_result(WaitForMultipleObjects(sizeof...(HANDLES), handles, true, as<DWORD>(timeout)));
    }
    template <typename... HANDLES>
    [[nodiscard]] auto wait_all(HANDLES const & ... args) noexcept
    {
        using std::chrono::milliseconds;
        return wait_all(static_cast<milliseconds::rep>(INFINITE), args...);
    }

    template <typename... HANDLES>
    [[nodiscard]] auto wait_any(std::chrono::milliseconds const& timeout, HANDLES const & ... args) noexcept
    {
        static_assert(sizeof...(HANDLES) < static_cast<size_t>(MAXIMUM_WAIT_OBJECTS));
        HANDLE handles[sizeof...(HANDLES)];
        add_to_array(handles, args...);

        auto const native_result = WaitForMultipleObjects(sizeof...(HANDLES), handles, false, as<DWORD>(timeout));
        auto const result = to_wait_for_result(native_result);

        switch (result) {
        case wait_for_result::object:
            if (auto const index = native_result - WAIT_OBJECT_0;
                index >= 0 && index < sizeof...(HANDLES)) {
                return make_tuple(result, std::optional(handles[index]));
            }
            return std::make_tuple(result, std::nullopt);
        case wait_for_result::abandonded:
            if (auto const index = native_result - WAIT_ABANDONED_0; 
                index >= 0 && index < sizeof...(HANDLES)) {
                return make_tuple(result, std::optional(handles[index]));
            }
            return std::make_tuple(result, std::nullopt);
        default:
            return std::make_tuple(result, std::nullopt);
        }
    }
    template <typename... HANDLES>
    [[nodiscard]] auto wait_any(HANDLES const & ... args) noexcept
    {
        using std::chrono::milliseconds;
        return wait_any(static_cast<milliseconds::rep>(INFINITE), args...);
    }

    constexpr bool to_bool(wait_for_result const& result)
    {
        return result == wait_for_result::object;
    }



}

#endif
#endif