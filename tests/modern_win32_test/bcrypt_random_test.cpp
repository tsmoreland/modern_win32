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

#pragma warning(push, 1)
#include <gtest/gtest.h>
#pragma warning(pop)

#include "modern_win32/bcrypt_random.h"

using modern_win32::bcrypt_get_random_bytes;

TEST(bcrypt_random, bcrypt_get_random_bytes_returns_different_returns_true_on_success)
{
    int first{};
    auto const result = bcrypt_get_random_bytes(reinterpret_cast<byte*>(&first), sizeof(first));

    ASSERT_TRUE(result);
}

TEST(bcrypt_random, get_bytes_returns_different_value_after_subsequent_calls)
{

    int first{};
    int second{};
    static_cast<void>(bcrypt_get_random_bytes(reinterpret_cast<byte*>(&first), sizeof(first)));
    static_cast<void>(bcrypt_get_random_bytes(reinterpret_cast<byte*>(&second), sizeof(second)));

    ASSERT_NE(first, second);
}
