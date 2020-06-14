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

#ifndef __MODERN_WIN32_THREADING_THREAD_H__
#define __MODERN_WIN32_THREADING_THREAD_H__

#include <modern_win32/null_handle.h>
#include <modern_win32/module_handle.h>
#include <modern_win32/windows_exception.h>
#include <chrono>

namespace modern_win32::threading
{
    template <typename WORKER>
    class thread final
    {
        using thread_worker = void (*)();
    public:
        using native_thread_id = DWORD;

        explicit thread(WORKER worker)
            : m_worker(worker)
        {
        }
        thread(thread&& other) noexcept
            : m_handle{other.m_handle.release()}
            , m_worker{other.m_worker}
            , m_thread_id{other.m_thread_id}
        {
            other.m_worker = nullptr;
            other.m_thread_id = native_thread_id{};
        }
        thread(thread const&) = delete;
        ~thread() = default;

        void set_name(wchar_t const* name) const
        {
            if (!is_running())
                return;

            using set_thread_description_delegate = HRESULT (WINAPI *)(HANDLE, PCWSTR);
            auto const maybe_kernel_base = get_module("KernelBase.dll");
            if (!maybe_kernel_base.has_value())
                return;

            auto const& kernel_base = maybe_kernel_base.value();

            if (!static_cast<bool>(kernel_base))
                return;

            auto const set_name_delegate = reinterpret_cast<set_thread_description_delegate>(GetProcAddress(kernel_base.get(), "SetThreadDescription"));
            if (set_name_delegate == nullptr)
                return;

            set_name_delegate(m_handle.get(), name);
        }
        void start() 
        {
            if (is_running())
                return;
            m_handle = CreateThread(nullptr, 0, thread_adapter, this, 0, &m_thread_id);
        }
        void join() const
        {
            if (is_running())
                WaitForSingleObject(m_handle.get(), 0);
        }
        [[nodiscard]] bool join(std::chrono::milliseconds const& timeout) const
        {
            if (!is_running())
                return false;

            auto const native_timeout = timeout.count() > static_cast<std::chrono::milliseconds::rep>(INFINITE)
                ? INFINITE
                : static_cast<DWORD>(timeout.count());

            auto const result = WaitForSingleObject(m_handle.get(), native_timeout);
            if (result == WAIT_FAILED)
                throw windows_exception();

            return result == WAIT_OBJECT_0;
        }

        [[nodiscard]] bool is_running() const
        {
            return static_cast<bool>(m_handle);
        }

        thread& operator=(thread const&) = delete;
        thread& operator=(thread&& other) noexcept 
        {
            if (this == &other)
                return *this;

            std::swap(m_handle, other.m_handle);
            static_cast<void>(other.m_handle.reset());

            m_worker = other.m_worker;
            other.m_worker = nullptr;

            m_thread_id = other.m_thread_id;
            other.m_thread_id = native_thread_id{};

            return *this;
        }
    private:
        null_handle m_handle{};
        thread_worker m_worker;
        native_thread_id m_thread_id{};

        static DWORD __stdcall thread_adapter(void* args)
        {
            auto * const that = static_cast<thread<WORKER>>(args);
            if (that == nullptr)
                return 1;

            auto worker = that.m_worker;
            if (worker == nullptr)
                return 0;
            worker();
            return 0;
        }
    };
}


#endif
