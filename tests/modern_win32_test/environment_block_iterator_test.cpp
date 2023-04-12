//
// Copyright (c) 2023 Terry Moreland
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

#pragma warning(disable : 26812)
#pragma warning(disable : 26495)
#include <gtest/gtest.h>
#pragma warning(default : 26812)
#pragma warning(default : 26495)

#include <modern_win32/environment_block.h>

using modern_win32::environment_block;
using modern_win32::environment_block_iterator;

class environment_block_iterator_test : public testing::TestWithParam<bool> {
    bool value_{false};
protected:
    void SetUp() override {
        value_ = GetParam();
    }

    [[nodiscard]]
    constexpr auto value() const noexcept {
        return value_;
    }
    [[nodiscard]]
    constexpr auto inherit_from_process() const noexcept {
        return value();
    }

    [[nodiscard]] static size_t get_expected_count(wchar_t const* environment_block) {
        
        size_t expected_count{0UL};
        bool done{false};
        bool previous_was_nul = false;
        while (!done) {
            if ((done = previous_was_nul && *environment_block == L'\0') == true) {
                break;
            }

            if (*environment_block == L'\0') {
                expected_count++;
                previous_was_nul = true;
            } else {
                previous_was_nul = false;
            }
            environment_block++;
        }
        return expected_count;
    }

};

INSTANTIATE_TEST_SUITE_P(inherit_process_values, environment_block_iterator_test, testing::Values(false, true));

TEST_P(environment_block_iterator_test, environment_block_begin_should_not_throw_exception) {
    ASSERT_NO_THROW({
        environment_block const env(inherit_from_process());
        std::ignore = env.begin();
    });
}


TEST_P(environment_block_iterator_test, environment_block_begin_should_return_valid_iterator) {
    environment_block const env(inherit_from_process());
    environment_block_iterator const iterator = env.begin();
    ASSERT_NE(iterator, env.end());
    std::wstring_view const value = *iterator;
    ASSERT_NE(value.size(), 0);
}

TEST_P(environment_block_iterator_test, environment_block_should_iterated_expected_number_of_times) {
    environment_block const env(inherit_from_process());

    auto const* native_ptr = static_cast<wchar_t const*>(env.native());

    size_t const expected_count = get_expected_count(native_ptr);
    size_t actual_count{0UL};
    for (auto const& value : env) {
        std::ignore = value;
        actual_count++;
    }

    ASSERT_EQ(actual_count, expected_count);
    
}
