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

#ifndef __MODERN_WIN32_THREADING_THREAD_START_H__
#define __MODERN_WIN32_THREADING_THREAD_START_H__

#include <Windows.h>
#include <any>
#include <memory>

namespace modern_win32::threading
{
    class thread_start_base
    {
    public:
        using thread_parameter = void*;

        thread_start_base() = default;
        thread_start_base(thread_start_base&& other) noexcept = default;
        thread_start_base(thread_start_base const&) = delete;
        virtual ~thread_start_base() = default;

        thread_start_base& operator=(thread_start_base const&) = delete;
        thread_start_base& operator=(thread_start_base&&) noexcept = default;
        virtual DWORD run(thread_parameter const parameter) = 0;

        DWORD operator(thread_parameter const parameter)
        {
            return run(parameter);
        }
    protected:
        std::any m_state;
    };

    template <typename WORKER>
    class thread_start final : public thread_start_base
    {
    public:
        explicit thread_start(WORKER worker) 
        {
            m_state = worker;
        }

        explicit thread_start(thread_start_base&& other)
            : thread_start_base(std::move(other))
        {
        }
        explicit thread_start(thread_start_base const& threadStartBase) = delete;

        DWORD run(thread_parameter const parameter) final
        {
            auto worker = std::any_cast<WORKER>(m_state);
            return worker();
        }
    };


}


#endif
