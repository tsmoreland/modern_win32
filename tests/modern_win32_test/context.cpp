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

#include "context.h"
#include <future>
#pragma warning(disable : 26812)
#pragma warning(disable : 26495)
#include <gtest/gtest.h>
#pragma warning(default : 26812)
#pragma warning(default : 26495)

namespace modern_win32::test
{

void wait_for(bool const& complete, std::chrono::milliseconds const& interval) 
{
    auto const start = std::chrono::steady_clock::now();
    while ( (std::chrono::steady_clock::now() - start) < interval)
        if (!complete)
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void fail_if_not_complete_after(std::chrono::milliseconds timeout, bool const& complete, bool& timed_out)
{
    wait_for(complete, timeout);
    if (!complete) {
        timed_out = false;
        FAIL() << "test timeout out";
    }
}

}