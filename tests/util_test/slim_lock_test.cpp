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

#include <gtest/gtest.h>
#include "concurrency/synchronization/slim_lock.h"
#include <future>
#include <chrono>

using util::concurrency::synchronization::slim_lock;

TEST(slim_lock, shared_lock_allows_multiple_threads)
{
    //arrange
    slim_lock lock{};
    auto complete{false};
    auto timed_out{false};

    auto const timeout = std::async(std::launch::async,
        [&complete, &timed_out]()
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            if (!complete) {
                timed_out = false;
                FAIL() << "slim locks did not complete in time";
            }
        });

    // act
    auto thread_one = std::async(std::launch::async, 
        [&lock]() {

            std::shared_lock guard(lock);
            return true;
        });

    auto thread_two = std::async(std::launch::async, 
        [&lock]() {
            std::shared_lock guard(lock);
            return true;
        });

    complete = thread_one.get() && thread_two.get();

    ASSERT_TRUE(complete && !timed_out);

    timeout.wait();
}

TEST(slim_lock, exclusive_lock_only_allows_one)
{
    slim_lock lock{};
    auto complete{false};
    auto timed_out{false};
    auto i{0};
    std::string name;

    // arrange
    auto const timeout = std::async(std::launch::async,
        [&complete, &timed_out]()
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            if (!complete) {
                timed_out = false;
                FAIL() << "slim locks did not complete in time";
            }
        });

    // act
    auto const thread_one = std::async(std::launch::async,
        [&lock, &name]()
        {
            std::lock_guard guard(lock);
            if (name.empty())
                name += "thread_one";
        });

    auto const thread_two = std::async(std::launch::async,
        [&lock, &name]()
        {
            std::lock_guard guard(lock);
            if (name.empty())
                name += "thread_two";
        });

    thread_one.wait();
    thread_two.wait();
    complete = true;

    // assert
    // one or the other but not a combinatino of both, in theory if we're not using a write lock that could maybe happen
    // probably a better way to verify this but offhand I'm not sure of what it may be
    ASSERT_TRUE(name == "thread_one" || name == "thread_two");

    timeout.wait();
}
