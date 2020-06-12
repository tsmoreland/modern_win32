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

#ifndef __UTIL_TEST_CONTEXT_H__
#define __UTIL_TEST_CONTEXT_H__

#include "common.h"
#include <util/concurrency/synchronization/event.h>

namespace util::test
{
    class context final
    {
        using event_type = util::concurrency::synchronization::event_type;
    public:
        
        explicit context(std::chrono::milliseconds const time_out)
        {
            m_future_countdown = std::async(std::launch::async,
                [this, time_out]()
                {
                    fail_if_not_complete_after(time_out, m_complete, m_timed_out);
                });
        }
        context(context const& other) = delete;
        context(context&& other) noexcept = delete;
        ~context() 
        {
            m_future_countdown.wait();
        }

        [[nodiscard]] bool get_timed_out() const
        {
            return m_timed_out;
        }
        [[nodiscard]] bool get_complete() const
        {
            return m_complete;
        }

        void set_complete(bool const value) 
        {
            m_complete = value;
        }

        template <event_type EVENT_TYPE>
        [[nodiscard]] static bool get_second_wait_result(util::concurrency::synchronization::event<EVENT_TYPE>& event)
        {
            auto signaled = event.set();
            EXPECT_TRUE(signaled);

            signaled = event.wait_one(); 
            EXPECT_TRUE(signaled);

            return event.wait_one(std::chrono::milliseconds(50));
        }

        __declspec(property(get = get_complete, put = set_complete)) bool complete;

        context& operator=(context const& other) = delete;
        context& operator=(context&& other) noexcept = delete;
    private:

        bool m_timed_out{false};
        bool m_complete{false};
        std::future<void> m_future_countdown;
    };
    
}

#endif