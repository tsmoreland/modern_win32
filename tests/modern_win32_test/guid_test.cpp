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
#include <modern_win32/guid.h>
#include "context.h"

using modern_win32::guid;

TEST(guid, constructor_no_throw_when_string_valid)
{
    char const* value = "83066E5E-D9FE-40D2-B68C-548B2131B65C";
    ASSERT_NO_THROW({guid id(value);});
}
TEST(guid, constructor_throw_when_string_nullptr)
{
    char const* value = nullptr;
    ASSERT_THROW({guid id(value);}, std::invalid_argument);
}
TEST(guid, constructor_no_throw_when_wide_string_valid)
{
    wchar_t const* value = L"83066E5E-D9FE-40D2-B68C-548B2131B65C";
    ASSERT_NO_THROW({guid id(value);});
}
TEST(guid, constructor_throw_when_wide_string_nullptr)
{
    wchar_t const* value = nullptr;
    ASSERT_THROW({guid id(value);}, std::invalid_argument);
}
TEST(guid, constructor_throw_when_string_invalid)
{
    char const* value = "invalid guid";
    ASSERT_THROW({guid id(value);}, std::invalid_argument);
}
TEST(guid, constructor_throw_when_wide_string_invalid)
{
    wchar_t const* value = L"invalid guid";
    ASSERT_THROW({guid id(value);}, std::invalid_argument);
}

TEST(guid, equals_returns_true_for_matching_values)
{
    char const* value = "83066E5E-D9FE-40D2-B68C-548B2131B65C";
    guid const id_one(value);
    guid const id_two(value);

    bool const are_equal = id_one == id_two;

    ASSERT_TRUE(are_equal);
}

TEST(guid, equals_returns_false_for_non_matching_values)
{
    guid const id_one("83066E5E-D9FE-40D2-B68C-548B2131B65C");
    guid const id_two("6CCE5066-427E-4B32-AA77-DEDA5519F786");

    bool const are_equal = id_one == id_two;

    ASSERT_FALSE(are_equal);
}