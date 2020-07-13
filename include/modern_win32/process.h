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

#ifndef __MODERN_WIN32_PROCESS_H__
#define __MODERN_WIN32_PROCESS_H__
#ifdef _WIN32

#include <modern_win32/null_handle.h>
#include <modern_win32/modern_win32_export.h>
#include <modern_win32/windows_exception.h>

#include <chrono>
#include <optional>
#include <tuple>
#include <Windows.h>

namespace modern_win32
{
    using process_handle = null_handle;
    using process_id_type = decltype(PROCESS_INFORMATION::dwProcessId);

    class MODERN_WIN32_EXPORT process final
    {
    public:
        using native_handle_type = process_handle::native_handle_type;
        using exit_code_type = unsigned long;

        explicit process(native_handle_type const& handle);
        process(process const&) = delete;
        process(process&& other) noexcept;
        ~process() = default;

        process& operator=(process const&) = delete;
        process& operator=(process&& other) noexcept;

        MODERN_WIN32_EXPORT friend bool operator==(process const& first, process const& second);
        MODERN_WIN32_EXPORT friend bool operator!=(process const& first, process const& second);

        /// <summary>
        /// Returns true if process handle is not invalid
        /// </summary>
        [[nodiscard]] explicit operator bool() const noexcept;

        /// <summary>swaps the value of <paramref name="lhs"/> and <paramref name="rhs"/></summary>
        MODERN_WIN32_EXPORT friend void swap(process& first, process& second) noexcept;

        /// <summary>replaces the managed object</summary>
        /// <returns>true if the replacement represents a valid process; otherwise, false</returns>
        [[nodiscard]] bool reset(native_handle_type const& handle);        

        /// <summary>
        /// releases the ownership of the process handle if any,
        /// </summary>
        /// <returns><see cref="native_handle_type"/> containing the contents of the managed object</returns>
        [[nodiscard]] native_handle_type release();

        /// <summary>
        /// Returns the underlying implementation-defined native handle object.
        /// </summary>
        /// <returns>implementation-defined native handle object.</returns>
        [[nodiscard]] native_handle_type native_handle() const noexcept;

        /// <summary>
        /// Returns a reference to the managed handle object.
        /// </summary>
        /// <returns>reference to the managed handle object.</returns>
        [[nodiscard]] process_handle& get() noexcept;

        /// <summary>
        /// Retrieves the process identifier of the process.
        /// </summary>
        /// <returns>the process identifier of the process, if found; otherise <see cref="std::nullopt/></returns>
        /// <exception cref="windows_exception">if call to native GetProcessId fails</exception>
        [[nodiscard]] std::optional<process_id_type> get_process_id() const;

        /// <summary>returns true if a process is currently owned and is running; otherwise, false</summary>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        [[nodiscard]] bool is_running() const;

        /// <summary>
        /// Returns the process exit code if it is no longer running; otherwise <see cref="std::nullopt"/>
        /// </summary>
        /// <returns>process exit code if process has exited</returns>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        [[nodiscard]] std::optional<exit_code_type> get_exit_code() const;

        /// <summary>waits for process to exit</summary
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        /// <exception cref="std::runtime_exception">
        /// if process_information was incorectly built from mutex which was abandoned
        /// </exception>
        void wait_for_exit() const;

        /// <summary>
        /// waits until process has exited or <paramref name="timeout"> milliseconds have elapsed
        /// </summary>
        /// <param name="timeout">number of milliseconds to wait for process to exit</param>
        /// <returns>true if process has exited; otherwise, false</returns>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        /// <exception cref="std::runtime_exception">
        /// if process_information was incorectly built from mutex which was abandoned
        /// </exception>
        [[nodiscard]] bool wait_for_exit(std::chrono::milliseconds const& timeout) const; 

    private:
        using running_details = std::tuple<bool, exit_code_type>;
        using wait_result = decltype(WaitForSingleObject(std::declval<native_handle_type>(), std::declval<DWORD>()));

#       pragma warning(push)
#       pragma warning(disable : 4251)
        process_handle m_handle;
#       pragma warning(pop)

        void close() noexcept;
        [[nodiscard]] static running_details get_running_details(native_handle_type process_handle);
    };

}

#endif
#endif