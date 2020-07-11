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

#include "null_handle.h"
#include <tuple>
#include <modern_win32/modern_win32_export.h>

namespace modern_win32
{
    using process_handle = null_handle;
    using process_thread_handle = null_handle;

    class process_impl;

    class MODERN_WIN32_EXPORT process_information final
    {
    public:
        using native_handle_type = PROCESS_INFORMATION;
        using native_process_handle_type = typename process_handle::native_handle_type;
        using native_process_thread_handle_type = typename process_thread_handle::native_handle_type;
        using modern_handle_type = process_handle;
        using native_process_id = decltype(PROCESS_INFORMATION::dwProcessId);
        using native_process_thread_id = decltype(PROCESS_INFORMATION::dwThreadId);
        using deconstruct_type = std::tuple<native_process_id, native_process_thread_id, process_handle::native_handle_type, process_thread_handle::native_handle_type>;
        
        /// <summary>Returns a value representing an empty or invalid process id</summary>
        static constexpr native_process_id empty_process_id()
        {
            return 0UL;
        }
        /// <summary>Returns a value representing an empty or invalid process id</summary>
        static constexpr native_process_thread_id empty_process_thread_id()
        {
            return 0UL;
        }

        /// <summary>Initializes an empty process_information class</summary>
        explicit process_information();
        /// <summary>Initializes an open process_information class based on <paramref name="process_information"/></summary>
        explicit process_information(native_handle_type const& process_information);
        /// <summary>copy constructor not supported</summary>
        process_information(const process_information&) = delete;
        /// <summary>
        /// moves the contents of <paramref name="other"> into this newly crated object
        /// resetting <paramref name="other"> in the process
        /// </summary>
        process_information(process_information&& other) noexcept;
        ~process_information();

        /// <summary>returns the member details as a <see cref="native_handle_type"></summary>
        [[nodiscard]] native_handle_type native_handle() const noexcept;
        /// <summary>returns the <see cref="native_process_handle_type"> object for the process</summary>
        [[nodiscard]] native_process_handle_type get_native_process_handle() const noexcept;
        /// <summary>returns the <see cref="native_process_thread_handle_type"> object for the process</summary>
        [[nodiscard]] native_process_thread_handle_type get_native_process_thread_handle() const noexcept;
        /// <summary>returns the process identifier (PID)</summary>
        [[nodiscard]] native_process_id get_native_process_id() const noexcept;
        /// <summary>returns the process thread id</summary>
        [[nodiscard]] native_process_thread_id get_native_process_thread_id() const noexcept;

        /// <summary>returns a reference to the managed process handle</summary>
        [[nodiscard]] process_handle& get_process_handle() noexcept;

        /// <summary>returns a reference to the managed process thread handle</summary
        [[nodiscard]] process_thread_handle& get_process_thread_handle() noexcept;

        /// <summary>replaces the managed object</summary>
        /// <returns>true if the replacement represents a valid process; otherwise, false</returns>
        [[nodiscard]] bool reset(deconstruct_type&& deconstructed);
        /// <summary>replaces the managed object</summary>
        /// <returns>true if the replacement represents a valid process; otherwise, false</returns>
        [[nodiscard]] bool reset(native_handle_type const& handle);        
        /// <summary>
        /// releases the ownership of the managed process if any,
        /// returning the contents as a <see cref="deconstruct_type"> 
        /// </summary>
        /// <returns><see cref="deconstruct_type"> containing the contents of the managed object</returns>
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
        native_process_id m_process_id;
        native_process_thread_id m_process_thread_id;
        process_handle m_process_handle;
        process_thread_handle m_process_thread_handle;
        
        void close();
    };
}

#endif
#endif
