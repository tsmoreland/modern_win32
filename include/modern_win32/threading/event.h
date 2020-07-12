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

#ifndef __MODERN_WIN32_CONCURRENCY_SYNCHRONIZATION_EVENT_H__
#define __MODERN_WIN32_CONCURRENCY_SYNCHRONIZATION_EVENT_H__

#ifdef _WIN32

#include <chrono>
#include <stdexcept>
#include <modern_win32/null_handle.h>
#include <modern_win32/template_utilities.h>
#include <modern_win32/win32_duration.h>

#include <Windows.h>
#include <modern_win32/windows_exception.h>

namespace modern_win32::threading
{
    enum class event_type
    {
        manual_reset,
        auto_reset,
    };

    template <event_type EVENT_TYPE>
    class event final
    {
        using modern_handle_type = typename modern_win32::null_handle;
    public:
        explicit event(bool const initial_state) noexcept
            : m_event{CreateEvent(nullptr, EVENT_TYPE == event_type::manual_reset, initial_state ? TRUE : FALSE, nullptr)}
        {
        }
        event(event const& other) = delete;
        event(event&& other) noexcept
            : m_event(other.m_event.release())
        {
        }
        ~event() = default;
       
        /// <summary>
        /// Sets the event object to the signaled state.
        /// </summary>
        /// <returns>true on success; otherwise, false</returns>
        // ReSharper disable once CppMemberFunctionMayBeConst it shouldn't be const because the state of the event is changing
        [[nodiscard]] bool set() noexcept
        {
            return SetEvent(m_event.native_handle()) != 0;
        }
        /// <summary>
        /// Sets the event object to the nonsignaled state.
        /// </summary>
        /// <returns>true on success; otherwise, false</returns>
        // ReSharper disable once CppMemberFunctionMayBeConst it shouldn't be const because the state of the event is changing
        [[nodiscard]] bool clear() noexcept
        {
            return ResetEvent(m_event.native_handle()) != 0;
        }

        /// <summary>
        /// wait for event to be signaled
        /// </summary>
        /// <param name="timeout">
        /// The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the specified objects are signaled or the interval elapses.
        /// If  zero, the function does not enter a wait state if the specified objects are not signaled; it always returns immediately.
        /// If maximum value or maximum value of DWORD, the function will return only when the specified objects are signaled.
        /// </param>
        /// <returns>true if event was signaled; otherwise, false</returns>
        /// <exception cref="windows_exception">if wait fails</exception>
        [[nodiscard]] bool wait_one(std::chrono::milliseconds const timeout = get_infinity_in_ms()) const 
        {
            auto const result = WaitForSingleObject(m_event.native_handle(), convert_timeout(timeout)); 

            if (result == WAIT_FAILED)
                throw windows_exception();

            return result == WAIT_OBJECT_0;
        }

        /// <summary>
        /// waits for all events to be set or timeout
        /// </summary>
        /// <typeparam name="EVENTS"></typeparam>
        /// <param name="events">the number of events to wait on</param>
        /// <param name="timeout">
        /// The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the specified objects are signaled or the interval elapses.
        /// If  zero, the function does not enter a wait state if the specified objects are not signaled; it always returns immediately.
        /// If maximum value or maximum value of DWORD, the function will return only when the specified objects are signaled.
        /// </param>
        /// <returns>true if all events have been set and no failure has occurred</returns>
        /// <exception cref="windows_exception">if wait fails</exception>
        /// <exception cref="runtime_error">if any handle has been abandonded details</exception>
        template <typename... EVENTS>
        static bool wait_all(EVENTS const&... events, std::chrono::milliseconds const timeout = get_infinity_in_ms())
        {
            return wait(events..., true, timeout) != WAIT_TIMEOUT;
        }
        /// <summary>
        /// waits for events to be set or timeout
        /// </summary>
        /// <typeparam name="EVENTS">variadic array of </typeparam>
        /// <param name="events">the number of events to wait on</param>
        /// The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the specified objects are signaled or the interval elapses.
        /// If  zero, the function does not enter a wait state if the specified objects are not signaled; it always returns immediately.
        /// If maximum value or maximum value of DWORD, the function will return only when the specified objects are signaled.
        /// <returns>index within <paramref name="events"/> of first event to be set</returns>
        /// <exception cref="util::shared::windows_exception">if wait fails</exception>
        /// <exception cref="util::shared::runtime_error">if any handle has been abandonded details</exception>
        template <typename... EVENTS>
        static DWORD wait_any(EVENTS const&... events, std::chrono::milliseconds const timeout = get_infinity_in_ms())
        {
            return wait(events..., false, timeout) - WAIT_OBJECT_0; // index within EVENTS of the event which was set
        }

        /// <summary>
        /// Swaps the values this and other.
        /// </summary>
        void swap(event& other) noexcept
        {
            using std::swap;
            swap(m_event, other.m_event);
        }

        event& operator=(event const& other) = delete;
        event& operator=(event&& other) noexcept
        {
            if (this == &other)
                return *this;
            static_cast<void>(m_event.reset(other.m_event.release()));
            return *this;
        }

#       if __cplusplus > 201703L || _MSVC_LANG > 201703L
        [[nodiscard]] auto operator<=>(event const& other)
        {
            return m_event <=> other.m_event;
        }

#       else
        [[nodiscard]] bool operator<(event const& other)
        {
            return m_event < other.m_event;
        }

        [[nodiscard]] bool operator<=(event const& other)
        {
            return !(other.m_event < m_event);
        }

        [[nodiscard]] bool operator>(event const& other)
        {
            return other.m_event < m_event;
        }

        [[nodiscard]] bool operator>=(event const& other)
        {
            return !(m_event < other.m_event);
        }

        [[nodiscard]] bool operator==(event const& other)
        {
            return m_event == other.m_event;
        }

        [[nodiscard]] bool operator!=(event const& other)
        {
            return !(m_event == other.m_event);
        }
#       endif

    private:
        modern_handle_type m_event;

        template <typename... EVENTS>
        static DWORD wait(EVENTS const&... events, bool const wait_all, std::chrono::milliseconds const timeout)
        {
            modern_handle_type::native_handle_type native_handles[sizeof...(events)];
            pack(native_handles, events..., [](auto& e) {return e.native_handle();});

            auto const result = WaitForMultipleObjects(sizeof...(events), native_handles, wait_all ? TRUE : FALSE, convert_timeout(timeout));
            if (result == WAIT_FAILED) 
                throw windows_exception();

            if (WAIT_ABANDONED <= result && WAIT_ABANDONED+sizeof...(events) > result)
                throw std::runtime_error("handle has been abandoned");
            return result;
        }
    };


#   if __cplusplus > 201703L || _MSVC_LANG > 201703L 
    template <event_type EVENT_TYPE>
    [[nodiscard]] auto operator<=>(event<EVENT_TYPE> const& lhs, event<EVENT_TYPE> const& rhs)
    {
        return lhs.operator<=>(rhs);
    }

#   else
    template <event_type EVENT_TYPE>
    [[nodiscard]] bool operator<(event<EVENT_TYPE> const& lhs, event<EVENT_TYPE> const& rhs)
    {
        return lhs.operator<(rhs);
    }

    template <event_type EVENT_TYPE>
    [[nodiscard]] bool operator<=(event<EVENT_TYPE> const& lhs, event<EVENT_TYPE> const& rhs)
    {
        return lhs.operator<=(rhs);
    }

    template <event_type EVENT_TYPE>
    [[nodiscard]] bool operator>(event<EVENT_TYPE> const& lhs, event<EVENT_TYPE> const& rhs)
    {
        return lhs.operator>(rhs);
    }

    template <event_type EVENT_TYPE>
    [[nodiscard]] bool operator>=(event<EVENT_TYPE> const& lhs, event<EVENT_TYPE> const& rhs)
    {
        return lhs.operator>=(rhs);
    }

    template <event_type EVENT_TYPE>
    [[nodiscard]] bool operator==(event<EVENT_TYPE> const& lhs, event<EVENT_TYPE> const& rhs)
    {
        return lhs.operator==(rhs);
    }

    template <event_type EVENT_TYPE>
    [[nodiscard]] bool operator!=(event<EVENT_TYPE> const& lhs, event<EVENT_TYPE> const& rhs)
    {
        return lhs.operator!=(rhs);
    }
#   endif

    /// <summary>
    /// Swaps the values lhs and rhs.
    /// </summary>
    template <event_type EVENT_TYPE>
    void swap(event<EVENT_TYPE>& lhs, event<EVENT_TYPE>& rhs) noexcept
    {
        lhs.swap(rhs);
    }

    using auto_reset_event = event<event_type::auto_reset>;
    using manual_reset_event = event<event_type::manual_reset>;

}

#endif
#endif