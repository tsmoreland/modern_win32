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

#ifndef __MORELAND_CONCURRENCY_SYNCHRONIZATION_EVENT_H__
#define __MORELAND_CONCURRENCY_SYNCHRONIZATION_EVENT_H__

#include <chrono>
#include <stdexcept>
#include <system/windows/null_handle.h>
#include <shared/template_utilities.h>

#ifdef _WIN32

#include <Windows.h>
#include <shared/windows_exception.h>

namespace moreland::concurrency::synchronization
{
    enum class event_type
    {
        manual_reset,
        auto_reset,
    };

    constexpr auto get_infinity_in_ms()
    {
        return std::chrono::duration<long long>(std::numeric_limits<long long>::infinity());
    }

    template <event_type EVENT_TYPE>
    class event final
    {
    private:
        using modern_handle_type = typename moreland::system::windows::null_handle;
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
       
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        // ReSharper disable once CppMemberFunctionMayBeConst it shouldn't be const because the state of the event is changing
        [[nodiscard]] bool set() noexcept
        {
            return SetEvent(m_event.get()) != 0;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        // ReSharper disable once CppMemberFunctionMayBeConst it shouldn't be const because the state of the event is changing
        [[nodiscard]] bool clear() noexcept
        {
            return ResetEvent(m_event.get()) != 0;
        }

        [[nodiscard]] bool wait_one(std::chrono::milliseconds const timeout = get_infinity_in_ms()) const noexcept
        {
            return WaitForSingleObject(m_event.get(), convert_timeout(timeout)) == WAIT_OBJECT_0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="EVENTS"></typeparam>
        /// <param name="events"></param>
        /// <param name="timeout"></param>
        /// <returns>true if all events have been set and no failure has occurred</returns>
        /// <exception cref="moreland::shared::windows_exception">if wait fails</exception>
        /// <exception cref="moreland::shared::runtime_error">if any handle has been abandonded details</exception>
        template <typename... EVENTS>
        static bool wait_all(EVENTS const&... events, std::chrono::milliseconds const timeout = get_infinity_in_ms())
        {
            return wait(events..., true, timeout) != WAIT_TIMEOUT;
        }
        /// <summary>
        /// waits for events to be set or timeout
        /// </summary>
        /// <typeparam name="EVENTS">variadic array of </typeparam>
        /// <param name="events"></param>
        /// <param name="timeout"></param>
        /// <returns></returns>
        /// <exception cref="moreland::shared::windows_exception">if wait fails</exception>
        /// <exception cref="moreland::shared::runtime_error">if any handle has been abandonded details</exception>
        template <typename... EVENTS>
        static DWORD wait_any(EVENTS const&... events, std::chrono::milliseconds const timeout = get_infinity_in_ms())
        {
            return wait(events..., false, timeout) - WAIT_OBJECT_0; // index within EVENTS of the event which was set
        }

        event& operator=(event const& other) = delete;
        event& operator=(event&& other) noexcept
        {
            if (this == &other)
                return *this;
            static_cast<void>(m_event.reset(other.m_event.release()));
            return *this;
        }
        ~event() = default;

    private:
        modern_handle_type m_event;

        static constexpr DWORD convert_timeout(std::chrono::milliseconds const timeout)
        {
            #undef max
            if constexpr(timeout == get_infinity_in_ms() || static_cast<decltype(std::declval<std::chrono::milliseconds>().count())>(std::numeric_limits<DWORD>::max()) > timeout) {
                return INFINITE;
            } else {
                return static_cast<DWORD>(timeout.count());
            }
        }
        template <typename... EVENTS>
        static DWORD wait(EVENTS const&... events, bool const wait_all, std::chrono::milliseconds const timeout)
        {
            modern_handle_type::native_handle_type native_handles[sizeof...(events)];
            shared::pack(native_handles, events..., [](auto& e) {return e.get();});

            auto const result = WaitForMultipleObjects(sizeof...(events), native_handles, wait_all ? TRUE : FALSE, convert_timeout(timeout));
            if (result == WAIT_FAILED) 
                throw shared::windows_exception("Error occurred waiting for handles");

            if (WAIT_ABANDONED <= result && WAIT_ABANDONED+sizeof...(events) > result)
                throw std::runtime_error("handle has been abandoned");
            return result;
        }
    };


}

#endif
#endif