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

#ifndef MODERN_WIN32_THREADING_THREAD_START_H_
#define MODERN_WIN32_THREADING_THREAD_START_H_
#ifdef _WIN32

#include <Windows.h>
#include <any>

namespace modern_win32::threading
{
    class thread_start
    {
    public:
        thread_start() = default;
        explicit thread_start(std::any state) 
            : state_(std::move(state))
        {
        }
        thread_start(thread_start&& other) noexcept = default;
        thread_start(thread_start const&) = delete;
        virtual ~thread_start() = default;

        thread_start& operator=(thread_start const&) = delete;
        thread_start& operator=(thread_start&&) noexcept = default;
        virtual void operator()() = 0;

        friend class thread;
    protected:
        [[nodiscard]]
        std::any const& get_state() const
        {
            return state_;
        }
    private:
        std::any state_;

        using thread_parameter = void*;
        static DWORD thread_proc(thread_parameter const this_ptr)
        {
            auto * that = static_cast<thread_start*>(this_ptr);
            if (that == nullptr)
                return 1;
            that->operator()();
            return 0;
        }
    };

    template <typename WORKER>
    class anonymous_thread_start final : public thread_start
    {
    public:
        explicit anonymous_thread_start(WORKER worker) 
            : thread_start(std::move(worker))
        {
        }

        explicit anonymous_thread_start(thread_start&& other)
            : thread_start(std::move(other))
        {
        }
        explicit anonymous_thread_start(thread_start const& threadStartBase) = delete;

        void operator()() override
        {
            auto worker = std::any_cast<WORKER>(get_state());
            worker();
        }
    };


}

#endif
#endif
