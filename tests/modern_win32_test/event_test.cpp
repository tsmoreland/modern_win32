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

#pragma warning(push)
#pragma warning(disable : 26495 26812)
#include <gtest/gtest.h>
#pragma warning(pop)
#include <modern_win32/threading/event.h>
#include "context.h"

using modern_win32::threading::auto_reset_event;
using modern_win32::threading::manual_reset_event;

using modern_win32::test::context;
constexpr auto TEST_TIMOUT = std::chrono::milliseconds(250);

TEST(auto_reset_event, is_reset_after_wait) 
{
    // Arrange
    context context{TEST_TIMOUT};
    auto_reset_event event{false};

    // Act
    auto const signalled = context::get_second_wait_result(event);
    context.complete = true;

    // Assert
    ASSERT_TRUE(!signalled && !context.get_timed_out());
}

TEST(manual_reset_event, is_reset_after_wait) 
{
    // Arrange
    context context{TEST_TIMOUT};
    manual_reset_event event{false};

    // Act
    auto const signalled = context::get_second_wait_result(event);
    context.complete = true;

    // Assert
    ASSERT_TRUE(signalled && !context.get_timed_out());
}

