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

#ifndef MODERN_WIN32_TEST_TIMER_TEST_H_
#define MODERN_WIN32_TEST_TIMER_TEST_H_ // NOLINT(clang-diagnostic-unused-macros)

#pragma warning(disable : 26812 26495)
#include <gtest/gtest.h>
#pragma warning(default : 26812 26495)

#include <Windows.h>
#include <chrono>

#pragma warning(disable : 4455)
using std::literals::chrono_literals::operator ""ms;
using std::literals::chrono_literals::operator ""s;

namespace modern_win32::test
{
    class timer_test : public testing::TestWithParam<std::chrono::milliseconds>
    {
        std::chrono::milliseconds value_{ 0ms };
    public:
        void SetUp() override
        {
            value_ = GetParam();
        }

    protected:
        [[nodiscard]]
        auto value() const noexcept -> std::chrono::milliseconds const&
        {
            return value_;
        }
    };

    class fake_handle
    {
        int value_;
    public:
        using native_handle_type = int;

        constexpr explicit fake_handle(native_handle_type const value) noexcept
            : value_(value)
        {
            
        }

        [[nodiscard]]
        constexpr native_handle_type& native_handle() noexcept
        {
            return value_;
        }
        [[nodiscard]]
        constexpr native_handle_type const& native_handle() const noexcept
        {
            return value_;
        }

        [[nodiscard]]
        inline native_handle_type release()
        {
            auto const value = value_;
            value_ = 0;
            return value;
        }

        [[nodiscard]]
        inline bool reset(native_handle_type value)
        {
            value_ = value;
            return value_ != 0;
        }

        [[nodiscard]]
        static constexpr auto invalid() noexcept -> native_handle_type
        {
            return 0;
        }

        explicit operator bool() const 
        {
            return value_ != 0;
        }

        [[nodiscard]]
        friend bool operator==(fake_handle const& left, fake_handle const& right)
        {
            return left.value_ == right.value_;
        }
        [[nodiscard]]
        friend bool operator!=(fake_handle const& left, fake_handle const& right)
        {
            return !(left == right);
        }

    };

    class fake_timer_traits
    {
        // destruction of these may not be realiable as they're static but it's for unit testing purposes only so we'll ignore for now
        using get_create_result_type = std::function<int()>;
        using set_waitable_timer_type = std::function<bool(int, LARGE_INTEGER&, LONG, PTIMERAPCROUTINE, void*, bool const)>;
        using cancel_waitable_timer_type = std::function<bool(int)>;

        static get_create_result_type get_create_result_;
        static set_waitable_timer_type get_set_waitable_timer_result_;
        static cancel_waitable_timer_type get_cancel_waitable_timer_result_;

        static int create_call_count_;
        static int cancel_waitable_timer_call_count_;
        static int set_waitable_timer_call_count_;

    public:
        using modern_handle_type = fake_handle;
        using native_handle_type = int;

        [[nodiscard]]
        static constexpr auto invalid() -> decltype(fake_handle::invalid())
        {
            return fake_handle::invalid();
        }

        [[nodiscard]]
        static inline auto create(bool) -> native_handle_type
        {
            create_call_count_++;
            return get_create_result_();
        }

        [[nodiscard]]
        static auto set_waitable_timer(
            native_handle_type,
            LARGE_INTEGER&,
            LONG,
            _In_opt_ PTIMERAPCROUTINE,
            void*,
            bool const) -> bool;

        [[nodiscard]]
        static auto cancel_waitable_timer(native_handle_type) -> bool;

        [[nodiscard]]
        static constexpr get_create_result_type& get_create_result()
        {
            return get_create_result_;
        }

        [[nodiscard]]
        static constexpr set_waitable_timer_type& get_set_waitable_timer_result()
        {
            return get_set_waitable_timer_result_;
        }

        [[nodiscard]]
        static constexpr cancel_waitable_timer_type& get_cancel_waitable_timer_result()
        {
            return get_cancel_waitable_timer_result_;
        }

        [[nodiscard]]
        static constexpr int const& create_call_count() noexcept
        {
            return create_call_count_;
        }
        [[nodiscard]]
        static constexpr int const& cancel_waitable_timer_call_count() noexcept
        {
            return cancel_waitable_timer_call_count_;
        }
        [[nodiscard]]
        static constexpr int const& set_waitable_timer_call_count() noexcept
        {
            return set_waitable_timer_call_count_;
        }

        static void reset();
    };

}

#endif
