//
// Copyright (c) 2022 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#ifndef MODERN_WIN32_WAIT_FOR_H_
#define MODERN_WIN32_WAIT_FOR_H_
#ifdef _WIN32

#include <chrono>
#include <modern_win32/modern_win32_export.h>
#include <modern_win32/shared/chrono_extensions.h>
#include <modern_win32/wait_for_result.h>
#include <optional>

#include <Windows.h>

namespace modern_win32 {
    /// <summary>
    /// converts <paramref name="result"/> to matching value from <see cref="wait_for_result"/>
    /// </summary>
    /// <param name="result">value to convert</param>
    /// <returns>value from <see cref="wait_for_result"/></returns>
    [[nodiscard]] constexpr wait_for_result to_wait_for_result(wait_result const& result) {
        switch (result) {
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

    /// <summary>
    /// convert timeout to time in milliseconds as NUMERIC type if less than
    /// maximum value of NUMERIC; otherwise, maximum value
    /// </summary>
    /// <typeparam name="NUMERIC">NUMERIC type to convert to</typeparam>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="timeout">value to convert</param>
    /// <returns>
    /// time in milliseconds as NUMERIC type if less than maximum value of NUMERIC;
    /// otherwise, maximum value
    /// </returns>
    template <typename NUMERIC, class REP, class PERIOD>
    [[nodiscard]] constexpr auto to_numeric_milliseconds(std::chrono::duration<REP, PERIOD> const& timeout) -> NUMERIC {
        static_assert(std::is_arithmetic_v<NUMERIC>);
        // extra set of () around std::numeric_limits<>::max to circumvent windows max macro
        static_assert(
            (std::numeric_limits<NUMERIC>::max)() <= (std::numeric_limits<std::chrono::milliseconds::rep>::max)());

        using modern_win32::shared::to_milliseconds;
        using std::chrono::milliseconds;

        auto const timeout_in_milliseconds = to_milliseconds(timeout);
        return timeout_in_milliseconds.count()
                    >= static_cast<std::chrono::milliseconds::rep>((std::numeric_limits<NUMERIC>::max)())
                 ? (std::numeric_limits<NUMERIC>::max)()
                 : static_cast<NUMERIC>(timeout_in_milliseconds.count());
    }

    template <typename T, typename... ARGS>
    constexpr void add_to_array(HANDLE* first, T const& remaining, ARGS const&... args) {
        *first = remaining.native_handle();
        add_to_array(++first, args...);
    }
    constexpr void add_to_array(HANDLE*) {}

    /// <summary>
    /// wait for the provided handle to be signaled or optional interval to be reached
    /// </summary>
    /// <typeparam name="HANDLE"></typeparam>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="handle"></param>
    /// <param name="timeout">
    /// optional internal to wait for, if std::nullopt wait
    /// will only return when the handle is signaled
    /// </param>
    /// <param name="alertable">
    /// If this parameter is true and the thread is in the waiting state, the
    /// function returns when the system queues an I/O completion routine or
    /// APC, and the thread runs the routine or function. Otherwise, the
    /// function does not return, and the completion routine or APC function
    /// is not executed.
    /// </param>
    /// <returns>wait_for_result containing detials on how the wait was stopped</returns>
    template <typename HANDLE, class REP = long long, class PERIOD = std::milli>
    [[nodiscard]] auto wait_one(HANDLE const& handle,
        std::optional<std::chrono::duration<REP, PERIOD>> const& timeout = std::nullopt,
        bool const alertable                                             = false) noexcept -> wait_for_result {
        using modern_win32::shared::to_milliseconds;

        auto const timeout_value = timeout.has_value() ? to_numeric_milliseconds<DWORD>(timeout.value()) : INFINITE;

        return to_wait_for_result(
            WaitForSingleObjectEx(handle.native_handle(), timeout_value, alertable ? TRUE : FALSE));
    }

    /// <summary>
    /// wait for the provided handle to be signaled or optional interval to be reached
    /// </summary>
    /// <typeparam name="HANDLE"></typeparam>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="handle"></param>
    /// <param name="timeout">
    /// optional internal to wait for, if std::nullopt wait
    /// will only return when the handle is signaled
    /// </param>
    /// <param name="alertable">
    /// If this parameter is true and the thread is in the waiting state, the
    /// function returns when the system queues an I/O completion routine or
    /// APC, and the thread runs the routine or function. Otherwise, the
    /// function does not return, and the completion routine or APC function
    /// is not executed.
    /// </param>
    /// <returns>wait_for_result containing detials on how the wait was stopped</returns>
    template <typename HANDLE, class REP = long long, class PERIOD = std::milli>
    [[nodiscard]] auto wait_one(HANDLE const& handle, std::chrono::duration<REP, PERIOD> const& timeout,
        bool const alertable = false) noexcept -> wait_for_result {
        return wait_one(handle, std::optional(timeout), alertable);
    }

    /// <summary>
    /// wait for all of the provided handles to be signaled or optional interval to be reached
    /// </summary>
    /// <typeparam name="...HANDLES"></typeparam>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="args"></param>
    /// <param name="timeout">
    /// optional internal to wait for, if std::nullopt wait
    /// will only return when all handles are signaled
    /// </param>
    /// <param name="alertable">
    /// If this parameter is true and the thread is in the waiting state, the
    /// function returns when the system queues an I/O completion routine or
    /// APC, and the thread runs the routine or function. Otherwise, the
    /// function does not return, and the completion routine or APC function
    /// is not executed.
    /// </param>
    /// <returns>wait_for_result containing detials on how the wait was stopped</returns>
    template <typename... HANDLES, class REP = long long, class PERIOD = std::milli>
    [[nodiscard]] auto wait_all(HANDLES const&... args,
        std::optional<std::chrono::duration<REP, PERIOD>> const& timeout, bool const alertable = false) noexcept
        -> wait_for_result {
        auto const timeout_value = timeout.has_value() ? to_numeric_milliseconds<DWORD>(timeout.value()) : INFINITE;
        static_assert(sizeof...(HANDLES) < static_cast<size_t>(MAXIMUM_WAIT_OBJECTS));
        HANDLE handles[sizeof...(HANDLES)];
        add_to_array(handles, args...);
        return to_wait_for_result(
            WaitForMultipleObjectsEx(sizeof...(HANDLES), handles, true, timeout_value, alertable ? TRUE : FALSE));
    }

    /// <summary>
    /// wait for all of the provided handles to be signaled or optional interval to be reached
    /// </summary>
    /// <typeparam name="...HANDLES"></typeparam>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="args"></param>
    /// <param name="timeout">
    /// optional internal to wait for, if std::nullopt wait
    /// will only return when all handles are signaled
    /// </param>
    /// <param name="alertable">
    /// If this parameter is true and the thread is in the waiting state, the
    /// function returns when the system queues an I/O completion routine or
    /// APC, and the thread runs the routine or function. Otherwise, the
    /// function does not return, and the completion routine or APC function
    /// is not executed.
    /// </param>
    /// <returns>wait_for_result containing detials on how the wait was stopped</returns>
    template <typename... HANDLES, class REP = long long, class PERIOD = std::milli>
    [[nodiscard]] auto wait_all(HANDLES const&... args, std::chrono::duration<REP, PERIOD> const& timeout,
        bool const alertable = false) noexcept -> wait_for_result {
        return wait_all(args, std::optional(timeout), alertable);
    }

    /// <summary>
    /// wait for any of the provided handles to be signaled or optional interval to be reached
    /// </summary>
    /// <typeparam name="...HANDLES"></typeparam>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="args">compile time array of HANDLE objects to be waited on</param>
    /// <param name="timeout">
    /// optional internal to wait for, if std::nullopt wait
    /// will only return when any handle is signaled
    /// </param>
    /// <param name="alertable">
    /// If this parameter is true and the thread is in the waiting state, the
    /// function returns when the system queues an I/O completion routine or
    /// APC, and the thread runs the routine or function. Otherwise, the
    /// function does not return, and the completion routine or APC function
    /// is not executed.
    /// </param>
    /// <returns>wait_for_result containing detials on how the wait was stopped</returns>
    template <typename... HANDLES, class REP = long long, class PERIOD = std::milli>
    [[nodiscard]] auto wait_any(HANDLES const&... args,
        std::optional<std::chrono::duration<REP, PERIOD>> const& timeout = std::nullopt,
        bool const alertable = false) noexcept -> std::tuple<wait_for_result, std::optional<HANDLE>> {
        using modern_win32::shared::to_milliseconds;

        auto const timeout_value =
            timeout.has_value() ? to_numeric_milliseconds<DWORD>(to_milliseconds(timeout.value())) : INFINITE;

        static_assert(sizeof...(HANDLES) < static_cast<size_t>(MAXIMUM_WAIT_OBJECTS));
        HANDLE handles[sizeof...(HANDLES)];
        add_to_array(handles, args...);

        auto const native_result =
            WaitForMultipleObjectsEx(sizeof...(HANDLES), handles, false, timeout_value, alertable ? TRUE : FALSE);

        switch (auto const result = to_wait_for_result(native_result)) {
        case wait_for_result::object:
            if (auto const index = native_result - WAIT_OBJECT_0; index >= 0 && index < sizeof...(HANDLES)) {
                return make_tuple(result, std::optional(handles[index]));
            }
            return std::make_tuple(result, std::nullopt);
        case wait_for_result::abandonded:
            if (auto const index = native_result - WAIT_ABANDONED_0; index >= 0 && index < sizeof...(HANDLES)) {
                return make_tuple(result, std::optional(handles[index]));
            }
            return std::make_tuple(result, std::nullopt);
        default:
            return std::make_tuple(result, std::nullopt);
        }
    }

    /// <summary>
    /// wait for any of the provided handles to be signaled or optional interval to be reached
    /// </summary>
    /// <typeparam name="...HANDLES"></typeparam>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="args">compile time array of HANDLE objects to be waited on</param>
    /// <param name="timeout">
    /// optional internal to wait for, if std::nullopt wait
    /// will only return when any handle is signaled
    /// </param>
    /// <param name="alertable">
    /// If this parameter is true and the thread is in the waiting state, the
    /// function returns when the system queues an I/O completion routine or
    /// APC, and the thread runs the routine or function. Otherwise, the
    /// function does not return, and the completion routine or APC function
    /// is not executed.
    /// </param>
    /// <returns>wait_for_result containing detials on how the wait was stopped</returns>
    template <typename... HANDLES, class REP = long long, class PERIOD = std::milli>
    [[nodiscard]] auto wait_any(HANDLES const&... args,
        std::chrono::duration<REP, PERIOD> const& timeout = std::nullopt, bool const alertable = false) noexcept
        -> std::tuple<wait_for_result, std::optional<HANDLE>> {
        return wait_any(args, std::optional(timeout), alertable);
    }

    /// <summary>
    /// returns true if result is <see cref="wait_for_result::object"/>; otherwise false
    /// throws exception if result is error
    /// </summary>
    /// <param name="result">result value to check</param>
    /// <returns>true if result is <see cref="wait_for_result::object"/>; otherwise false</returns>
    /// <exception cref="windows_exception">if result is <see cref="wait_for_result::failed"/></exception>
    /// <exception cref="std::runtime_error">if result is <see cref="wait_for_result::abandonded"/></exception>
    [[nodiscard]] MODERN_WIN32_EXPORT bool is_complete(wait_for_result const& result);

} // namespace modern_win32

#endif
#endif