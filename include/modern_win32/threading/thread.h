//
// Copyright � 2020 Terry Moreland
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
#include <modern_win32/threading/thread_start.h>
#include <modern_win32/windows_exception.h>
#include <modern_win32/modern_win32_export.h>
#include <chrono>
#include <optional>
#include <memory>
#include <string>

namespace modern_win32::threading
{
    using thread_handle = null_handle;

    /// <summary>
    /// Sets the description (or name) of the thread represented by this objet to <parmref name="name"/>
    /// </summary>
    /// <param name="handle">native handle for the thread</param>
    /// <param name="name">the name to apply to the thread represented by this object</param>
    /// <returns>true on success; otherwise, false</returns>
    /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
    [[nodiscard]] MODERN_WIN32_EXPORT bool set_thread_name(thread_handle::native_handle_type const handle, wchar_t const* name);

    /// <summary>
    /// Sets the description (or name) of the thread represented by this objet to <parmref name="name"/>
    /// </summary>
    /// <param name="handle">native handle for the thread</param>
    /// <param name="name">the name to apply to the thread represented by this object</param>
    /// <returns>true on success; otherwise, false</returns>
    /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
    [[nodiscard]] MODERN_WIN32_EXPORT bool set_thread_name(thread_handle::native_handle_type const handle, char const* name);

    /// <summary>
    /// returns the current name for the thread represented by this object
    /// </summary>
    /// <param name="handle">native handle for the thread</param>
    /// <returns>optional containing the thread name on success; otherwise <see cref="std::nullopt"/></returns>
    /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
    [[nodiscard]] MODERN_WIN32_EXPORT std::optional<std::wstring> get_thread_name(thread_handle::native_handle_type const handle);

    class MODERN_WIN32_EXPORT thread final
    {
    public:
        using native_handle_type = thread_handle::native_handle_type;
        using modern_handle_type = thread_handle;
        using thread_worker = void (*)();
        using thread_parameter = void*;
        using thread_proc = DWORD (*)(thread_parameter);
        using native_thread_id = DWORD;

        explicit thread(std::unique_ptr<thread_start> worker);
        explicit thread(modern_handle_type&& handle);
        explicit thread(native_handle_type const& handle = thread_handle::invalid());
        thread(thread&& other) noexcept;
        thread(thread const&) = delete;
        ~thread() = default;

        /// <summary>
        /// Sets the description (or name) of the thread represented by this objet to <parmref name="name"/>
        /// </summary>
        /// <param name="name">the name to apply to the thread represented by this object</param>
        /// <returns>true on success; otherwise, false</returns>
        /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
        [[nodiscard]] bool set_name(wchar_t const* name) const;

        /// <summary>
        /// Sets the description (or name) of the thread represented by this objet to <parmref name="name"/>
        /// </summary>
        /// <param name="name">the name to apply to the thread represented by this object</param>
        /// <returns>true on success; otherwise, false</returns>
        /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
        [[nodiscard]] bool set_name(char const* name) const;

        /// <summary>
        /// returns the current name for the thread represented by this object
        /// </summary>
        /// <returns>optional containing the thread name on success; otherwise <see cref="std::nullopt"/></returns>
        /// <remarks>only works on Windows Server 2016+ or Windows 10 1607+</remarks>
        [[nodiscard]] std::optional<std::wstring> get_name() const;

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
        [[nodiscard]] bool start(thread_proc const worker, thread_parameter const parameter);

        /// <summary>
        /// starts the thread using <paramref name="worker"/> if not already running
        /// </summary>
        /// <param name="worker"><see cref="thread_start"/> used to run the thread</param>
        /// <returns>true if thread is started; otherwise, false</returns>
        /// <remarks>
        /// thread does not maintain lifetime of thread_start it is up to the caller to ensure that object exists until the thread completes
        /// </remarks>
        [[nodiscard]] bool start(thread_start* const worker);

        /// <summary>
        /// starts the thread usnig provided thread_start
        /// </summary>
        /// <returns>true if thread is started; otherwise, false</returns>
        [[nodiscard]] bool start();

        /// <summary>
        /// Blocks the calling thread until the thread represented by this instance terminates.
        /// </summary>
        void join() const;

        /// <summary>
        /// Blocks the calling thread until the thread represented by this instance terminates
        /// or the specified time elapses
        /// </summary>
        [[nodiscard]] bool join(std::chrono::milliseconds const& timeout) const;

        /// <summary>
        /// returns running state of the thread represented by this object
        /// </summary>
        /// <returns>true if thread is still active; otherwise, false</returns>
        /// <exception cref="windows_exceptionl">thrown if Win32 API GetExitCodeThread returns zero</exception>
        [[nodiscard]] bool is_running() const;

        thread& operator=(thread const&) = delete;
        thread& operator=(thread&& other) noexcept; 

        MODERN_WIN32_EXPORT friend void swap(thread& lhs, thread& rhs) noexcept;

    private:
#       pragma warning(push)
#       pragma warning(disable : 4251)
        modern_handle_type m_handle{};
        native_thread_id m_thread_id{};
        std::unique_ptr<thread_start> m_thread_start;
#       pragma warning(pop)

        static DWORD __stdcall thread_adapter(void* state);
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
    [[nodiscard]] MODERN_WIN32_EXPORT thread start_thread(thread::thread_proc const worker, thread::thread_parameter const parameter);

    /// <summary>
    /// starts the thread using <paramref name="worker"/> if not already running
    /// </summary>
    /// <param name="worker"><see cref="thread_start"/> used to run the thread</param>
    /// <returns>the running thread</returns>
    /// <exception cref="windows_exception">thrown if unable to create thread</exception>
    /// <remarks>
    /// thread does not maintain lifetime of thread_start it is up to the caller to ensure that object exists until the thread completes
    /// </remarks>
    [[nodiscard]] MODERN_WIN32_EXPORT thread start_thread(thread_start* const worker);

}

#endif
#endif
