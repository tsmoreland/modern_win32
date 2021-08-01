//
// Copyright © 2021 Terry Moreland
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

#ifndef MODERN_WIN32_THREADING_TIMER_
#define MODERN_WIN32_THREADING_TIMER_

#ifdef _WIN32

#include <Windows.h>
#include <modern_win32/modern_win32_export.h>
#include "modern_win32/null_handle.h"
#include <modern_win32/threading/thread.h>
#include <modern_win32/threading/event.h>
#include <chrono>
#include <modern_win32/windows_exception.h>
#include <shared_mutex>

namespace modern_win32::threading
{
    struct MODERN_WIN32_EXPORT timer_traits
    {
        using modern_handle_type = modern_win32::null_handle;
        using native_handle_type = modern_win32::null_handle::native_handle_type;

        [[nodiscard]]
        static auto create(bool manual_reset) -> native_handle_type;

        [[nodiscard]]
        static auto set_waitable_timer(
            native_handle_type handle,
            LARGE_INTEGER& due_time,
            LONG period,
            _In_opt_ PTIMERAPCROUTINE callback,
            void *state,
            bool const restore) -> bool;

        [[nodiscard]]
        static bool cancel_waitable_timer(native_handle_type handle);
    };

    template <typename T, std::enable_if<std::is_move_constructible_v<T> && std::is_move_assignable_v<T>>>
    [[nodiscard]]
    T&& move_if_supported(T& value)
    {
        return std::move(value);
    }

    /*
    template <typename T, std::enable_if<!std::is_move_constructible_v<T> || !std::is_move_assignable_v<T>>>
    [[nodiscard]]
    T& move_if_supported(T& value)
    {
        return value;
    }
    */

    // not really but it's not working yet so marking as deprecated until it is
    template <bool MANUAL_RESET, typename STATE, class TIMER_CALLBACK = void (*)(STATE&), typename TRAITS = timer_traits>
    class timer final
    {
        using modern_handle_type = typename TRAITS::modern_handle_type;

        modern_handle_type handle_;
        TIMER_CALLBACK callback_;
        STATE state_;
        std::optional<thread> callback_thread_{};
        std::optional<std::pair<std::chrono::milliseconds, std::chrono::milliseconds>> timer_settings_{};
        std::atomic<bool> shutdown_{};
        std::shared_mutex lock_{};
        manual_reset_event shutdown_event_{ false };
    public:

        /// <summary>
        /// Starts the timer 
        /// </summary>
        /// <param name="due_time">time before first callback is performed</param>
        /// <param name="period">period between subsequent callbacks</param>
        /// <exception cref="modern_win32::windows_exception">if internal API fails</exception>
        /// <exception cref="modern_win32::windows_exception">if internal API fails</exception>
        void start(std::chrono::milliseconds const& due_time, std::chrono::milliseconds const& period)
        {
            // timer already active
            std::lock_guard lock{ lock_ };

            if (is_running()) {
                return;
            }

            if (due_time < std::chrono::milliseconds(0)) {
                throw std::invalid_argument("due_time must be greater than or equal to zero");
            }
            if (period < std::chrono::milliseconds(0)) {
                throw std::invalid_argument("period must be greater than or equal to zero");
            }

            timer_settings_ = std::make_pair(due_time, period);

            callback_thread_ = std::optional(start_thread(&timer::notification_thread_worker,
                static_cast<thread::thread_parameter>(this)));

        }

        void stop()
        {
            std::lock_guard lock{ lock_ };

            std::ignore = TRAITS::cancel_waitable_timer(handle_.native_handle());

            shutdown_ = true;
            std::ignore = shutdown_event_.set();
        }

        [[nodiscard]]
        bool is_running() const
        {
            return !shutdown_ && callback_thread_.has_value() && callback_thread_.value().is_running();
        }

        explicit timer(TIMER_CALLBACK callback, STATE const& state)
            : handle_{ TRAITS::create(MANUAL_RESET) }
            , callback_{ callback }
            , state_{ state }
        {
        }
        explicit timer(TIMER_CALLBACK&& callback, STATE const& state)
            : handle_{ TRAITS::create(MANUAL_RESET) }
            , callback_{ std::move(callback) }
            , state_{ state }
        {
        }
        explicit timer(TIMER_CALLBACK callback, STATE&& state)
            : handle_{ TRAITS::create(MANUAL_RESET) }
            , callback_{ callback }
            , state_{ std::move(state) }
        {
        }

        ~timer()
        {
            stop();
        }

        timer(timer&& other) noexcept
            : handle_{ other.handle_.release() }
            , callback_{ other.callback_ }
            //, state_{ (other.state_) }
            , state_{ }
            , callback_thread_{ std::move(other.callback_thread_) }
            , timer_settings_{ std::move(other.timer_settings_) }
            , shutdown_{ other.shutdown_.load() }
            , lock_{ }
            , shutdown_event_{ std::move(other.shutdown_event_) }
        {
            other.shutdown_ = true;
        }
        timer& operator=(timer&& other) noexcept
        {
            if (&other == this) {
                return *this;
            }
            std::ignore = handle_.reset(other.handle_.release());
            callback_ = other.callback_;
            state_ = other.state_;

            callback_thread_ = std::move(other.callback_thread_);
            timer_settings_ = std::move(other.timer_settings_);
            shutdown_ = std::move(other.shutdown_);
            lock_ = other.lock_;
            shutdown_event_ = std::move(other.shutdown_event_);

            other.shutdown_ = true;

            return *this;
        }

        timer(timer const&) = delete;
        timer& operator=(timer const&) = delete;

        /// <summary>
        /// swaps the contents of this with other
        /// </summary>
        /// <param name="other">instance to swap values with</param>
        void swap(timer& other) noexcept
        {
            if (&this == &other) {
                return;
            }

            std::lock_guard this_lock{ lock_ };
            std::lock_guard other_lock{ other.lock_ };

            swap(handle_, other.handle_);
            std::swap(callback_, other.callback_);
            std::swap(state_, other.state_);
            swap(callback_thread_, other.callback_thread_);
            swap(timer_settings_, other.timer_settings_);
            swap(shutdown_, other.shutdown_);
            swap(lock_, other.lock_);
            swap(shutdown_event_, other.shutdown_event_);
        }

#       if __cplusplus > 201703L 
        friend auto operator<=>(timer const& first, timer const& second) noexcept
        {
            return first.handle_ <=> second.handle_;
        }

#       else
        friend bool operator<(timer const& first, timer const& second)
        {
            return first.handle_ < second.handle_;
        }
        friend bool operator>(timer const& first, timer const& second)
        {
            return first.handle_ > second.handle_;
        }
        friend bool operator<=(timer const& first, timer const& second)
        {
            return first.handle_ <= second.handle_;
        }
        friend bool operator>=(timer const& first, timer const& second)
        {
            return first.handle_ >= second.handle_;
        }

#       endif

        friend bool operator==(timer const& first, timer const& second)
        {
            return first.handle_ == second.handle_;
        }
        friend bool operator!=(timer const& first, timer const& second)
        {
            return !(first == second);
        }

    private:

        static void CALLBACK timer_proc(void* state, DWORD, DWORD)
        {
            
            if (auto* timer_object = static_cast<timer*>(state);
                timer_object != nullptr) {
                timer_object->callback_(timer_object->state_);
                if constexpr (MANUAL_RESET) {
                    timer_object->stop();
                }
            }
        }
        static DWORD __stdcall notification_thread_worker(thread::thread_parameter state)
        {
            auto self = static_cast<timer*>(state);

            if (self == nullptr) {
                return 1UL;
            }


            if (std::shared_lock lock(self->lock_);
                !self->shutdown_)
            {
                
                if (!self->timer_settings_.has_value()) {
                    return 2UL;
                }
                auto [due_time, poll_period] = self->timer_settings_.value();
                if (LARGE_INTEGER due = to_large_integer(due_time);
                    !TRAITS::set_waitable_timer(
                        self->handle_.native_handle(),
                        due,
                        static_cast<long>(poll_period.count() * 1000),
                        timer::timer_proc,
                        state,
                        false)) {
                    throw windows_exception();
                }
            }

            while (!self->shutdown_) {
                std::ignore = self->shutdown_event_.wait_one(std::chrono::milliseconds(500), true);
            }

            return 0UL;
        }

        static LARGE_INTEGER to_large_integer(std::chrono::milliseconds const& value)
        {
            auto const converted_time_value = value.count() * -10000;
            LARGE_INTEGER output_value;
            output_value.LowPart = static_cast<DWORD>(converted_time_value & 0xFFFFFFFF);
            output_value.HighPart = converted_time_value >>32;
            return output_value;
        }
    };

    template <typename STATE, class TIMER_CALLBACK = void(*)(STATE&), typename TRAITS = timer_traits>
    using delayed_callback = timer<false, STATE, TIMER_CALLBACK, TRAITS>;

    template <typename STATE, class TIMER_CALLBACK = void(*)(STATE&), typename TRAITS = timer_traits>
    using synchronization_timer = timer<true, STATE, TIMER_CALLBACK, TRAITS>;


    /// <summary>
    /// swaps the values of left and right
    /// </summary>
    /// <typeparam name="STATE">manual reset flag </typeparam>
    /// <typeparam name="TIMER_CALLBACK"></typeparam>
    /// <typeparam name="TRAITS"></typeparam>
    /// <param name="left">one of the values to be swapped</param>
    /// <param name="right">one of the values to be swapped</param>
    template <bool MANUAL_RESET, typename STATE, class TIMER_CALLBACK = void(*)(STATE&), typename TRAITS = timer_traits>
    void swap(timer<MANUAL_RESET, STATE, TIMER_CALLBACK, TRAITS> left, timer<MANUAL_RESET, STATE, TIMER_CALLBACK, TRAITS> right)
    {
        left.swap(right);
    }

}


#endif
#endif