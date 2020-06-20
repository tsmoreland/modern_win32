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

#pragma warning(push, 2)
#include <gtest/gtest.h>
#pragma warning(pop)
#include <chrono>
#include <modern_win32/threading/thread.h>
#include <modern_win32/threading/event.h>
#include "context.h"

using std::chrono::milliseconds;
using modern_win32::threading::thread;
using modern_win32::threading::start_thread;
using modern_win32::threading::manual_reset_event;

using util::test::context;
constexpr auto TEST_TIMOUT = std::chrono::milliseconds(250);

TEST(thread, start_launches_thread)
{
    context ctx{TEST_TIMOUT};
    manual_reset_event thread_exit(false);
    auto parameter = std::make_tuple(&ctx, &thread_exit);
    thread task = start_thread(
        [](thread::thread_parameter state) -> DWORD
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

    EXPECT_TRUE(thread_exit.wait_one(milliseconds(250)));
    ASSERT_TRUE(ctx.complete && !ctx.get_timed_out());
}
