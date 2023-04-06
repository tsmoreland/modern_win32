//
// Copyright (c) 2023 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#pragma warning(disable : 26812)
#pragma warning(disable : 26495)
#include <gtest/gtest.h>
#pragma warning(default : 26812)
#pragma warning(default : 26495)

#include <modern_win32/environment_block.h>

using modern_win32::environment_block;

TEST(environment_block, constructor_does_not_throw_When_inherit_is_true) {

    ASSERT_NO_THROW({ environment_block const eb(true); });
}

TEST(environment_block, native_returns_non_null_when_inherit_is_true) {

    environment_block const eb(true);
    auto const native_eb = eb.native();

    ASSERT_NE(native_eb, nullptr);
}


TEST(environment_block, constructor_does_not_throw_When_inherit_is_false) {

    ASSERT_NO_THROW({ environment_block const eb(false); });
}

TEST(environment_block, native_returns_non_null_when_inherit_is_false) {

    environment_block const eb(false);
    auto const native_eb = eb.native();

    ASSERT_NE(native_eb, nullptr);
}
