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

#ifndef __MODERN_WIN32_PROCESS_INFORMATION_H__
#define __MODERN_WIN32_PROCESS_INFORMATION_H__
#ifdef _WIN32

#include <modern_win32/null_handle.h>
#include <modern_win32/modern_win32_export.h>
#include <modern_win32/windows_exception.h>
#include <modern_win32/process.h>
#include <chrono>
#include <optional>
#include <tuple>

namespace modern_win32
{
    using process_handle = null_handle;
    using process_thread_handle = null_handle;

    class MODERN_WIN32_EXPORT process_information final
    {
    public:
        using native_handle_type = PROCESS_INFORMATION;
        using native_process_handle_type = process::native_handle_type;
        using native_process_thread_handle_type = process_thread_handle::native_handle_type;
        using modern_handle_type = process_handle;
        using exit_code_type = process::exit_code_type;
        using thread_exit_code_type = unsigned long;
        using native_process_thread_id = decltype(PROCESS_INFORMATION::dwThreadId);
        using deconstruct_type = std::tuple<process_id_type, native_process_thread_id, process_handle::native_handle_type, process_thread_handle::native_handle_type>;

        /// <summary>Initializes an empty process_information class</summary>
        explicit process_information();
        /// <summary>Initializes an open process_information class based on <paramref name="process_information"/></summary>
        explicit process_information(native_handle_type const& process_information);
        /// <summary>copy constructor not supported</summary>
        process_information(const process_information&) = delete;
        /// <summary>
        /// moves the contents of <paramref name="other"/> into this newly crated object
        /// resetting <paramref name="other"/> in the process
        /// </summary>
        process_information(process_information&& other) noexcept;
        ~process_information();

        /// <summary>returns the member details as a <see cref="native_handle_type"/></summary>
        [[nodiscard]] native_handle_type native_handle() const;
        /// <summary>returns the <see cref="native_process_handle_type"/> object for the process</summary>
        [[nodiscard]] native_process_handle_type get_native_process_handle() const noexcept;
        /// <summary>returns the <see cref="native_process_thread_handle_type"/> object for the process</summary>
        [[nodiscard]] native_process_thread_handle_type get_native_process_thread_handle() const noexcept;
        /// <summary>returns the process identifier (PID)</summary>
        [[nodiscard]] std::optional<process_id_type> get_process_id() const;
        /// <summary>returns the process thread id</summary>
        [[nodiscard]] native_process_thread_id get_native_process_thread_id() const noexcept;

        /// <summary>returns a reference to the managed process handle</summary>
        [[nodiscard]] process_handle& get_process_handle() noexcept;

        /// <summary>returns a reference to the managed process thread handle</summary>
        [[nodiscard]] process_thread_handle& get_process_thread_handle() noexcept;

        /// <summary>returns true if a process is currently owned and is running; otherwise, false</summary>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        [[nodiscard]] bool is_running() const;

        /// <summary>
        /// Returns the process exit code if it is no longer running; otherwise <see cref="std::nullopt"/>
        /// </summary>
        /// <returns>process exit code if process has exited</returns>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        [[nodiscard]] std::optional<exit_code_type> get_exit_code() const;

        /// <summary>waits for process to exit</summary>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        /// <exception cref="std::runtime_exception">
        /// if process_information was incorectly built from mutex which was abandoned
        /// </exception>
        void wait_for_exit() const;

        /// <summary>
        /// waits until process has exited or <paramref name="timeout"/> milliseconds have elapsed
        /// </summary>
        /// <param name="timeout">number of milliseconds to wait for process to exit</param>
        /// <returns>true if process has exited; otherwise, false</returns>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        /// <exception cref="std::runtime_exception">
        /// if process_information was incorectly built from mutex which was abandoned
        /// </exception>
        [[nodiscard]] bool wait_for_exit(std::chrono::milliseconds const& timeout) const; 

        /// <summary>replaces the managed object</summary>
        /// <returns>true if the replacement represents a valid process; otherwise, false</returns>
        [[nodiscard]] bool reset(deconstruct_type&& deconstructed);
        /// <summary>replaces the managed object</summary>
        /// <returns>true if the replacement represents a valid process; otherwise, false</returns>
        [[nodiscard]] bool reset(native_handle_type const& handle);        
        /// <summary>
        /// releases the ownership of the managed process if any,
        /// returning the contents as a <see cref="deconstruct_type"/> 
        /// </summary>
        /// <returns><see cref="deconstruct_type"/> containing the contents of the managed object</returns>
        [[nodiscard]] deconstruct_type release();

        process_information& operator=(const process_information&) = delete;
        process_information& operator=(process_information&& other) noexcept;
        MODERN_WIN32_EXPORT friend bool operator==(process_information const& lhs, process_information const& rhs);
        MODERN_WIN32_EXPORT friend bool operator!=(process_information const& lhs, process_information const& rhs);
        MODERN_WIN32_EXPORT friend bool operator==(process_information const& lhs, PROCESS_INFORMATION const& rhs);
        MODERN_WIN32_EXPORT friend bool operator!=(process_information const& lhs, PROCESS_INFORMATION const& rhs);
        MODERN_WIN32_EXPORT friend bool operator==(PROCESS_INFORMATION const& lhs, process_information const& rhs);
        MODERN_WIN32_EXPORT friend bool operator!=(PROCESS_INFORMATION const& lhs, process_information const& rhs);
        MODERN_WIN32_EXPORT friend bool operator==(process_information const& lhs, deconstruct_type const& rhs);
        MODERN_WIN32_EXPORT friend bool operator!=(process_information const& lhs, deconstruct_type const& rhs);
        MODERN_WIN32_EXPORT friend bool operator==(deconstruct_type const& lhs, process_information const& rhs);
        MODERN_WIN32_EXPORT friend bool operator!=(deconstruct_type const& lhs, process_information const& rhs);

        /// <summary>
        /// Returns true if process handle is not invalid and process id is non-empty
        /// </summary>
        /// <remarks>process thread handle is ignored for this check as it is dependent on the process</remarks>
        [[nodiscard]] explicit operator bool() const noexcept;

        /// <summary>swaps the value of <paramref name="lhs"/> and <paramref name="rhs"/></summary>
        MODERN_WIN32_EXPORT friend void swap(process_information& lhs, process_information& rhs) noexcept;

    private:
        native_process_thread_id m_process_thread_id;
#       pragma warning(push)
#       pragma warning(disable : 4251)
        process m_process;
        process_thread_handle m_process_thread_handle;
#       pragma warning(pop)
        
        void close();
    };
}

#endif
#endif
