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
#ifdef _WIN32

#include <modern_win32/null_handle.h>
#include <modern_win32/module_handle.h>
#include <modern_win32/windows_exception.h>
#include <modern_win32/threading/thread_start.h>
#include <modern_win32/naive_stack_allocator.h>
#include <modern_win32/string_conversion.h>
#include <chrono>

namespace modern_win32::threading
{
    using thread_handle = null_handle;

    class thread final
    {
    public:
        using native_handle_type = typename thread_handle::native_handle_type;
        using modern_handle_type = thread_handle;
        using thread_worker = void (*)();
        using thread_parameter = void*;
        using thread_proc = DWORD (*)(thread_parameter);
        using native_thread_id = DWORD;

        explicit thread(std::unique_ptr<thread_start> worker)
            : m_handle(thread_handle::invalid())
            , m_thread_start(std::move(worker))
        {
            if (m_thread_start == nullptr)
                throw std::invalid_argument("provided thread_start is null");
        }
        explicit thread(modern_handle_type&& handle)
            : m_handle(handle.release())
        {
        }
        explicit thread(native_handle_type const& handle = thread_handle::invalid())
            : m_handle(handle)
        {
        }
        thread(thread&& other) noexcept
            : m_handle{other.m_handle.release()}
            , m_thread_id{other.m_thread_id}
        {
            other.m_thread_id = native_thread_id{};
        }
        thread(thread const&) = delete;
        ~thread() = default;

        /// <summary>
        /// Sets the description (or name) of the thread represented by this objet to <parmref name="name"/>
        /// </summary>
        /// <param name="name">the name to apply to the thread represented by this object</param>
        /// <returns>true on success; otherwise, false</returns>
        /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
        [[nodiscard]] bool set_name(wchar_t const* name) const
        {
            if (!is_running())
                return false;

            using set_thread_description_delegate = HRESULT (WINAPI *)(HANDLE, PCWSTR);
            auto const maybe_kernel_base = get_module("KernelBase.dll");
            if (!maybe_kernel_base.has_value())
                return false;

            auto const& kernel_base = maybe_kernel_base.value();

            if (!static_cast<bool>(kernel_base))
                return false;

            auto const set_name_delegate = reinterpret_cast<set_thread_description_delegate>(GetProcAddress(kernel_base.get(), "SetThreadDescription"));
            if (set_name_delegate == nullptr)
                return false;

            auto const hr = set_name_delegate(m_handle.get(), name);
            return SUCCEEDED(hr);
        }

        /// <summary>
        /// Sets the description (or name) of the thread represented by this objet to <parmref name="name"/>
        /// </summary>
        /// <param name="name">the name to apply to the thread represented by this object</param>
        /// <returns>true on success; otherwise, false</returns>
        /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
        [[nodiscard]] bool set_name(char const* name) const
        {
            auto const wide_name = convert::to_wstring<naive_stack_allocator<wchar_t>>(name);
            return set_name(wide_name.c_str());
        }

        /// <summary>
        /// returns the current name for the thread represented by this object
        /// </summary>
        /// <returns>optional containing the thread name on success; otherwise <see cref="std::nullopt"/></returns>
        /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
        [[nodiscard]] std::optional<std::wstring> get_name() const
        {
            if (!is_running())
                return std::nullopt;

            using get_thread_description_delegate = HRESULT (WINAPI *)(HANDLE, PWSTR*);
            auto const maybe_kernel_base = get_module("KernelBase.dll");
            if (!maybe_kernel_base.has_value())
                return std::nullopt;

            auto const& kernel_base = maybe_kernel_base.value();
            auto const get_name_delegate = reinterpret_cast<get_thread_description_delegate>(GetProcAddress(kernel_base.get(), "GetThreadDescription"));
            if (get_name_delegate == nullptr)
                return std::nullopt;

            PWSTR data{};
            if (auto const hr = get_name_delegate(m_handle.get(), &data); SUCCEEDED(hr))
            {
                std::wstring name(data);
                LocalFree(data);
                return name;
            }

            return std::nullopt;
        }

        /// <summary>
        /// starts the thread using <paramref name="worker"/> if not already running
        /// </summary>
        /// <typeparam name="WORKER"></typeparam>
        /// <param name="worker">must be castable to thread_worker</param>
        /// <returns>true if thread is started; otherwise, false</returns>
        /// <remarks>
        /// thread is referred to as stateless because it cannot capture any variables (if using lambda)
        /// nor can it be passed state
        /// </remarks>
        template <typename WORKER>
        [[nodiscard]] bool start_stateless(WORKER worker) 
        {
            static_assert(std::is_convertible<decltype(worker), thread_worker>::value, "WORKER must be assignable to thread_worker");
            if (is_running() || m_thread_start != nullptr)
                return false;
            return m_handle.reset(CreateThread(nullptr, 0, thread_adapter, static_cast<thread_worker>(worker), 0, &m_thread_id));  // NOLINT(clang-diagnostic-microsoft-cast)
        }
        /// <summary>
        /// starts the thread using <paramref name="worker"/> if not already running
        /// </summary>
        /// <typeparam name="WORKER"></typeparam>
        /// <param name="worker">method to execute in new thread, must return DWORD and take thread_parameter</param>
        /// <param name="parameter">parameter to use in thread creation</param>
        /// <returns>true if thread is started; otherwise, false</returns>
        [[nodiscard]] bool start(thread_proc const worker, thread_parameter const parameter) 
        {
            if (is_running() || m_thread_start != nullptr)
                return false;
            return m_handle.reset(CreateThread(nullptr, 0, worker, parameter, 0, &m_thread_id));  // NOLINT(clang-diagnostic-microsoft-cast)
        }
        /// <summary>
        /// starts the thread using <paramref name="worker"/> if not already running
        /// </summary>
        /// <param name="worker"><see cref="thread_start"/> used to run the thread</param>
        /// <returns>true if thread is started; otherwise, false</returns>
        /// <remarks>
        /// thread does not maintain lifetime of thread_start it is up to the caller to ensure that object exists until the thread completes
        /// </remarks>
        [[nodiscard]] bool start(thread_start* const worker) 
        {
            if (is_running() || m_thread_start != nullptr)
                return false;

            return m_handle.reset(CreateThread(nullptr, 0, thread_start::thread_proc, static_cast<thread_parameter>(worker), 0, &m_thread_id));  // NOLINT(clang-diagnostic-microsoft-cast)
        }
        /// <summary>
        /// starts the thread usnig provided thread_start
        /// </summary>
        /// <returns>true if thread is started; otherwise, false</returns>
        bool start()
        {
            if (is_running() || m_thread_start == nullptr)
                return false;
            return m_handle.reset(CreateThread(nullptr, 0, thread_start::thread_proc, m_thread_start.get(), 0, &m_thread_id));  // NOLINT(clang-diagnostic-microsoft-cast)
        }
        void join() const
        {
            if (is_running())
                WaitForSingleObject(m_handle.get(), INFINITE);
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

        /// <summary>
        /// returns running state of the thread represented by this object
        /// </summary>
        /// <returns>true if thread is still active; otherwise, false</returns>
        /// <exception cref="windows_exceptionl">thrown if Win32 API GetExitCodeThread returns zero</exception>
        [[nodiscard]] bool is_running() const
        {
            if (!static_cast<bool>(m_handle))
                return false;

            DWORD exit_code;
            if (GetExitCodeThread(m_handle.get(), &exit_code) != TRUE)
                throw windows_exception();
            return exit_code == STILL_ACTIVE;
        }

        thread& operator=(thread const&) = delete;
        thread& operator=(thread&& other) noexcept 
        {
            if (this == &other)
                return *this;

            std::swap(m_handle, other.m_handle);
            static_cast<void>(other.m_handle.reset());

            m_thread_id = other.m_thread_id;
            other.m_thread_id = native_thread_id{};

            return *this;
        }
    private:
        modern_handle_type m_handle{};
        native_thread_id m_thread_id{};
        std::unique_ptr<thread_start> m_thread_start;

        static DWORD __stdcall thread_adapter(void* state)
        {
            auto const worker = static_cast<thread_worker>(state);  // NOLINT(clang-diagnostic-microsoft-cast)
            if (worker == nullptr)
                return 1;
            worker();
            return 0;
        }
    };

    /// <summary>
    /// starts a new thread running <paramref name="worker"/>
    /// </summary>
    /// <typeparam name="WORKER">runnable type</typeparam>
    /// <param name="worker">runnable object to execute in a new thread</param>
    /// <returns>the running thread</returns>
    /// <exception cref="windows_exception">thrown if unable to create thread</exception>
    template <typename WORKER>
    auto start_stateless_thread(WORKER worker)
    {
        static_assert(std::is_invocable<decltype(worker)>::value, "WORKER must be invokable");
        static_assert(std::is_convertible<decltype(worker), thread::thread_worker>::value, "WORKER must be assignable to thread_worker");
        thread new_thread;
        if (!new_thread.start(worker))
            throw windows_exception();
        return new_thread;
    }

    /// <summary>
    /// starts a new thread running <paramref name="worker"/> taking <paramref name="parameter"/>
    /// </summary>
    /// <param name="worker">worker to run in new thread</param>
    /// <param name="parameter">parameter passed to thread</param>
    /// <returns>the running thread</returns>
    /// <exception cref="windows_exception">thrown if unable to create thread</exception>
    inline auto start_thread(thread::thread_proc const worker, thread::thread_parameter const parameter)
    {
        thread new_thread;
        if (!new_thread.start(worker, parameter))
            throw windows_exception();
        return new_thread;
    }

    /// <summary>
    /// starts the thread using <paramref name="worker"/> if not already running
    /// </summary>
    /// <param name="worker"><see cref="thread_start"/> used to run the thread</param>
    /// <returns>the running thread</returns>
    /// <exception cref="windows_exception">thrown if unable to create thread</exception>
    /// <remarks>
    /// thread does not maintain lifetime of thread_start it is up to the caller to ensure that object exists until the thread completes
    /// </remarks>
    inline auto start_thread(thread_start* const worker)
    {
        thread new_thread;
        if (!new_thread.start(worker))
            throw windows_exception();
        return new_thread;
    }

}

#endif
#endif
