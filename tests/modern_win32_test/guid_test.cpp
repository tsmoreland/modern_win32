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

TEST(guid, empty_equals_expected_all_zero_value)
{
    guid const all_zero("00000000-0000-0000-0000-000000000000");

    bool const equal = all_zero == guid::zero();

    ASSERT_TRUE(equal);
}

TEST(guid, new_guid_produces_different_values) 
{
    guid const first = modern_win32::new_guid();
    guid const second = modern_win32::new_guid();
    guid const third = modern_win32::new_guid();

    bool const first_equals_second  = first == second;
    bool const second_equals_third  = second == third;
    bool const first_equals_third  = first == third;

    ASSERT_FALSE(first_equals_second);
    ASSERT_FALSE(second_equals_third);
    ASSERT_FALSE(first_equals_third);
}

TEST(guid, get_returns_correct_string)
{
    std::string const raw_value = "D6DF7ECC-05BA-4778-A6D9-3DB0ACE208C6";
    guid const value(raw_value.c_str()); 

    std::string const as_string = modern_win32::to_string(value);

    ASSERT_EQ(raw_value, as_string);
}

TEST(guid, get_returns_correct_wstring)
{
    std::wstring const raw_value = L"D6DF7ECC-05BA-4778-A6D9-3DB0ACE208C6";
    guid const value(raw_value.c_str()); 

    std::wstring const as_string = modern_win32::to_wstring(value);

    ASSERT_EQ(raw_value, as_string);
}

