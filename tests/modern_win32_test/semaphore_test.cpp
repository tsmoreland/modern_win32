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
#include <modern_win32/threading/semaphore.h>
#include "context.h"

using modern_win32::threading::semaphore;
using modern_win32::windows_exception;

TEST(sempahore_test, constructor__throws_windows_exception__when_initial_count_negative)
{
    ASSERT_THROW({ 
        semaphore s( -1, 10);

    }, std::invalid_argument);
}
TEST(sempahore_test, constructor__throws_windows_exception__when_maximum_count_negative)
{
    ASSERT_THROW({ 
        semaphore s( 0, -1);

    }, std::invalid_argument);
}


TEST(sempahore_test, constructor__throws_windows_exception__when_maximum_count_less_than_initial_count)
{
    ASSERT_THROW({ 
        semaphore s( 5, 1);

    }, std::invalid_argument);
}
