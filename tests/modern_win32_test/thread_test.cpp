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

#pragma warning(push, 2)
#include <gtest/gtest.h>
#pragma warning(pop)
#include <chrono>
#include <modern_win32/threading/thread.h>
#include <modern_win32/threading/event.h>
#include "context.h"
#include <vector>

using std::chrono::milliseconds;
using namespace modern_win32::threading;

using modern_win32::test::context;
constexpr auto TEST_TIMOUT = std::chrono::milliseconds(250);

TEST(thread, thread_throws_invalid_argument_on_null_worker)
{
    std::unique_ptr<thread_start> worker;
    ASSERT_THROW(thread(std::move(worker)), std::invalid_argument);
}

TEST(thread, start_launches_thread)
{
    context ctx{TEST_TIMOUT};
    manual_reset_event thread_exit(false);
    auto parameter = std::make_tuple(&ctx, &thread_exit);
    thread const task = start_thread(
        [](thread::thread_parameter const state) -> DWORD
        {
            auto const* param = static_cast<std::tuple<context*, manual_reset_event*>*>(state);
            EXPECT_NE(param, nullptr);
            if (param == nullptr)
                return 1;
            auto [context_ptr, thread_exit_ptr] = *param;
            EXPECT_NE(context_ptr, nullptr);
            EXPECT_NE(thread_exit_ptr, nullptr);
            context_ptr->complete = true;
            static_cast<void>(thread_exit_ptr->set());
            return 0UL;
        }, &parameter);

    EXPECT_TRUE(thread_exit.wait_one());
    ASSERT_TRUE(ctx.complete && !ctx.get_timed_out());
}

TEST(thread, anonymous_thread_start_runs_lambda)
{
    context ctx{TEST_TIMOUT};
    auto worker = context::get_anonymous_thread_start(ctx);
    thread_start& generic_worker = worker;
    generic_worker();

    ASSERT_TRUE(ctx.complete && !ctx.get_timed_out());
}

TEST(thread, start_launches_anonymous_thread_start)
{
    context ctx{TEST_TIMOUT};
    auto worker = context::get_anonymous_thread_start(ctx);

    thread const task = start_thread(&worker);
    task.join();

    ASSERT_TRUE(ctx.complete && !ctx.get_timed_out());
}

TEST(thread, is_running_true_for_running_thread)
{
    context ctx{TEST_TIMOUT};
    manual_reset_event thread_started(false);
    manual_reset_event thread_exit(false);
    auto worker = modern_win32::threading::anonymous_thread_start(
        [&ctx, &thread_exit, &thread_started]()
        {
            EXPECT_TRUE(thread_started.set());
            ctx.complete = true;
            EXPECT_TRUE(thread_exit.wait_one());
        });

    thread const task = start_thread(&worker);
    EXPECT_TRUE(thread_started.wait_one());
    std::this_thread::sleep_for(milliseconds(15)); // by time for thread to start
    ASSERT_TRUE(task.is_running());

    EXPECT_TRUE(thread_exit.set());
    EXPECT_TRUE(ctx.complete && !ctx.get_timed_out());
}

TEST(thread, is_running_false_if_not_started)
{
    context ctx{TEST_TIMOUT};
    thread const task(context::get_custom_thread_start(ctx));
    ASSERT_FALSE(task.is_running());
    ctx.complete = true;
}

TEST(thread, is_running_false_after_exit)
{
    context ctx{TEST_TIMOUT};
    thread task(context::get_custom_thread_start(ctx));
    static_cast<void>(task.start());
    task.join();

    ASSERT_FALSE(task.is_running());
    ASSERT_TRUE(ctx.complete && !ctx.get_timed_out());
}

TEST(thread, join_waits_for_thread_exit)
{
    context ctx{TEST_TIMOUT};
    auto worker = context::get_anonymous_thread_start(ctx);
    thread const task = start_thread(&worker);
    EXPECT_TRUE(task.is_running());

    task.join();

    ASSERT_FALSE(task.is_running());
    EXPECT_TRUE(ctx.complete && !ctx.get_timed_out());
}

TEST(thread, start_launches_unique_anonymous_thread_start)
{
    context ctx{TEST_TIMOUT};
    thread task(context::get_custom_thread_start(ctx));

    static_cast<void>(task.start());
    task.join();

    ASSERT_TRUE(ctx.complete && !ctx.get_timed_out());
}

TEST(thread, set_thread_updates_description)
{
    // arrange
    std::wstring const expected_name{L"set_thread_updates_description"};
    EXPECT_TRUE(set_thread_name(GetCurrentThread(), expected_name.c_str()));

    // act
    PWSTR actual_name{};
    EXPECT_TRUE(SUCCEEDED(GetThreadDescription(GetCurrentThread(), &actual_name)));

    // assert
    ASSERT_EQ(expected_name, actual_name);
}

TEST(thread, get_thread_name_returns_value)
{
    // arrange
    std::wstring const expected_name{L"get_thread_name_returns_value"};
    EXPECT_TRUE(SUCCEEDED(SetThreadDescription(GetCurrentThread(), expected_name.c_str())));

    // act
    auto const maybe_actual_name = get_thread_name(GetCurrentThread());

    ASSERT_TRUE(maybe_actual_name.has_value());
}

TEST(thread, get_thread_name_returns_correct_value)
{
    // arrange
    std::wstring const expected_name{L"get_thread_name_returns_correct_value-name"};
    EXPECT_TRUE(SUCCEEDED(SetThreadDescription(GetCurrentThread(), expected_name.c_str())));

    // act
    auto const maybe_actual_name = get_thread_name(GetCurrentThread());

    ASSERT_EQ(expected_name, maybe_actual_name.value());
}
