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

#pragma warning(disable : 26812 26495)
#include <gtest/gtest.h>
#pragma warning(default : 26812 26495)

#include "timer_test.h"
#include <chrono>
#include <modern_win32/threading/timer.h>
#include <modern_win32/threading/event.h>
#include "context.h"
#include "simple_object.h"

using std::chrono::milliseconds;
using modern_win32::threading::manual_reset_event;
using modern_win32::threading::delayed_callback;
using modern_win32::threading::synchronization_timer;

using modern_win32::test::simple_object;
using modern_win32::test::fake_timer_traits;

class delayed_callback_test : public modern_win32::test::timer_test
{
};

TEST(delayed_callback_test, constructor__does_not_throw__when_state_is_trivial)
{
    ASSERT_NO_THROW({
        delayed_callback<int> delay([](int&) { /* ... */ }, 3);
    });
}

TEST(delayed_callback_test, constructor__does_not_throw__when_state_is_reference)
{
    simple_object bar{};

    ASSERT_NO_THROW({
        delayed_callback<std::reference_wrapper<simple_object>> delay([](std::reference_wrapper<simple_object>&) {  /* ... */ }, std::reference_wrapper(bar));
    });
}

TEST_P(delayed_callback_test, start__throws_invalid_argument__when_due_time_is_less_than_zero)
{
    try {
        delayed_callback<int> delay([](int&) { /* ... */ }, 3);
        delay.start(value());
        FAIL();
    } catch (std::invalid_argument const& e) {
        ASSERT_EQ(e.what(), std::string_view("due_time must be greater than or equal to zero"));
    }
}

TEST(delayed_callback_test, start__begins_timer__when_arguments_are_greater_than_or_equal_to_zero)
{
    manual_reset_event callback_event{ false };
    bool called{ false };
    constexpr int expected_state = 3;
    auto callback = [&called, &callback_event, expected_state](int const& state) {
        if (state == expected_state) {
            called = true;
            std::ignore = callback_event.set();
        }
    };

    delayed_callback<int, decltype(callback)> timer(callback, expected_state);

    timer.start(100ms);

    std::ignore = callback_event.wait_one(5s);
    ASSERT_TRUE(called);
}

TEST(delayed_callback_test, start__creates_new_thread__when_is_running_true)
{
    auto callback = [](int&) { /* ... */ };
    delayed_callback<int, decltype(callback), fake_timer_traits> timer(callback, 3);

    timer.start(50s);

    auto const expected = timer.timer_thread_id();
    
    timer.start(50s);

    auto const actual = timer.timer_thread_id();

    ASSERT_NE(actual.value_or(1), expected.value_or(1));
}

TEST(delayed_callback_test, stop__calls_cancel_waitable_timer__always)
{
    auto callback = [](int&) { /* ... */ };
    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;

    fake_timer_traits::reset();
    delayed_callback_t timer(callback, 3);

    timer.stop();

    ASSERT_EQ(fake_timer_traits::cancel_waitable_timer_call_count(), 1);
}

TEST(delayed_callback_test, stop__returns_false__when_cancel_waitable_timer_returns_false_and_timer_is_running)
{
    auto callback = [](int&) { /* ... */ };
    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;

    fake_timer_traits::reset();
    fake_timer_traits::get_cancel_waitable_timer_result() = [](fake_timer_traits::native_handle_type) {
        return false;
    };
    delayed_callback_t timer(callback, 3);

    timer.start(10s);
    auto const actual = timer.stop();

    ASSERT_FALSE(actual);
}

TEST(delayed_callback_test, stop__returns_true__when_cancel_waitable_timer_returns_true_and_timer_is_running)
{
    auto callback = [](int&) { /* ... */ };
    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;

    fake_timer_traits::reset();
    fake_timer_traits::get_cancel_waitable_timer_result() = [](fake_timer_traits::native_handle_type) {
        return true;
    };
    delayed_callback_t timer(callback, 3);

    timer.start(10s);
    auto const actual = timer.stop();

    ASSERT_TRUE(actual);
}

TEST(delayed_callback_test, stop__returns_false__when_cancel_waitable_timer_returns_false_and_timer_is_not_running)
{
    auto callback = [](int&) { /* ... */ };
    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;

    fake_timer_traits::reset();
    fake_timer_traits::get_cancel_waitable_timer_result() = [](fake_timer_traits::native_handle_type) {
        return false; 
    };
    delayed_callback_t timer(callback, 3);

    auto const actual = timer.stop();

    ASSERT_FALSE(actual);
}

TEST(delayed_callback_test, stop__returns_true__when_cancel_waitable_timer_returns_true_and_timer_is_not_running)
{
    auto callback = [](int&) { /* ... */ };
    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;

    fake_timer_traits::reset();
    fake_timer_traits::get_cancel_waitable_timer_result() = [](fake_timer_traits::native_handle_type) {
        return true; 
    };
    delayed_callback_t timer(callback, 3);

    auto const actual = timer.stop();

    ASSERT_TRUE(actual);
}

TEST(delayed_callback_test, is_running__returns_false__before_start_is_called)
{
    delayed_callback<int> const delay([](int&) { /* ... */ }, 3);

    ASSERT_TRUE(!delay.is_running());
}

TEST(delayed_callback_test, is_running__returns_true__after_start_is_called_and_before_stop_is_called)
{
    delayed_callback<int> delay([](int&) { /* ... */ }, 3);
    delay.start(100ms);
    auto const actual = delay.is_running();

    ASSERT_TRUE(actual);
}

TEST(delayed_callback_test, is_running__returns_false__after_stop_is_called)
{
    delayed_callback<int> delay([](int&) { /* ... */ }, 3);
    delay.start(100ms);
    delay.stop();

    ASSERT_TRUE(!delay.is_running());
}

TEST(delayed_callback_test, native_handle__returns_valid_handle__when_constructor_does_not_throw)
{
    auto callback = [](int&) { /* ... */ };
    using timer_t = delayed_callback<int, decltype(callback), fake_timer_traits>;

    fake_timer_traits::reset();
    timer_t const timer(callback, 3);

    ASSERT_NE(timer.native_handle(), fake_timer_traits::invalid());
}

TEST(delayed_callback_test, timer_thread_id__has_value__when_is_running)
{
    delayed_callback<int> timer([](int&) { /* ... */ }, 3);
    timer.start(100ms);
    auto const has_value = timer.timer_thread_id().has_value();

    ASSERT_TRUE(has_value);
}
TEST(delayed_callback_test, timer_thread_id__does_not_have_value__when_not_running)
{
    delayed_callback<int> const timer([](int&) { /* ... */ }, 3);
    auto const has_value = timer.timer_thread_id().has_value();

    ASSERT_FALSE(has_value);
}

TEST(delayed_callback_test, operator_equals__returns_true__when_timer_handles_equal)
{
    fake_timer_traits::reset();
    auto callback = [](int&) { /* ... */ };

    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;
    delayed_callback_t const first(callback, 3);
    delayed_callback_t const second(callback, 3);

    ASSERT_TRUE(first == second);
}

TEST(delayed_callback_test, operator_equals__returns_false__when_timer_handles_not_equal)
{
    fake_timer_traits::reset();
    auto callback = [](int&) { /* ... */ };

    int handle_value = 1;
    fake_timer_traits::get_create_result() = [&handle_value]() {
        return handle_value++;
    };

    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;

    delayed_callback_t const first(callback, 3);
    delayed_callback_t const second(callback, 3);

    ASSERT_FALSE(first == second);

}

TEST(delayed_callback_test, operator_not_equals__returns_false__when_timer_handles_equal)
{
    fake_timer_traits::reset();
    auto callback = [](int&) { /* ... */ };

    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;

    delayed_callback_t const first(callback, 3);
    delayed_callback_t const second(callback, 3);

    ASSERT_FALSE(first != second);
}

TEST(delayed_callback_test, operator_not_equals__returns_true__when_timer_handles_not_equal)
{
    fake_timer_traits::reset();
    auto callback = [](int&) { /* ... */ };

    int handle_value = 1;
    fake_timer_traits::get_create_result() = [&handle_value]() {
        return handle_value++;
    };
    using delayed_callback_t = delayed_callback<int, decltype(callback), fake_timer_traits>;
    delayed_callback_t const first(callback, 3);
    delayed_callback_t const second(callback, 3);

    ASSERT_TRUE(first != second);
}

INSTANTIATE_TEST_SUITE_P(data_driven, delayed_callback_test, testing::Values(-50ms, -100ms));
