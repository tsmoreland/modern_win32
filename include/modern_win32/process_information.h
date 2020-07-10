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
#include <memory>
#ifdef _WIN32

#include "null_handle.h"
#include <TlHelp32.h>
#include <tuple>

namespace modern_win32
{
    using process_handle = null_handle;
    using process_thread_handle = null_handle;

    class process_impl;

    class process_information final
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
        explicit process_information()
            : m_process_id{empty_process_id()}
            , m_process_thread_id{empty_process_thread_id()}
        {
        }
        /// <summary>Initializes an open process_information class based on <paramref name="process_information"/></summary>
        explicit process_information(native_handle_type const& process_information)
            : m_process_id{process_information.dwProcessId}
            , m_process_thread_id{process_information.dwThreadId}
            , m_process_handle{process_information.hProcess}
            , m_process_thread_handle{process_information.hThread}
        {
        }
        process_information(const process_information&) = delete;
        process_information& operator=(const process_information&) = delete;
        process_information(process_information&& other) noexcept 
        {
            auto [process_id, process_thread_id, process_handle, process_thread_handle] = other.release();
            m_process_id = process_id;
            m_process_thread_id = process_thread_id;
            static_cast<void>(m_process_handle.reset(process_handle));
            static_cast<void>(m_process_thread_handle.reset(process_thread_handle));
        }
        process_information& operator=(process_information&& other) noexcept 
        {
            if (*this == other)
                return *this;

            std::swap(*this, other);
            return *this;
        }
        ~process_information() 
        {
            close(); // done to match unique_handle but not really needed, default would be fine
        }

        [[nodiscard]] bool reset(deconstruct_type&& deconstructed)
        {
            if (*this == deconstructed)
                return static_cast<bool>(*this);

            close();
            auto [process_id, process_thread_id, process_handle, process_thread_handle] = std::move(deconstructed);
            m_process_id = process_id;
            m_process_thread_id = process_thread_id;
            static_cast<void>(m_process_handle.reset(process_handle));
            static_cast<void>(m_process_thread_handle.reset(process_thread_handle));

            return static_cast<bool>(*this);
        }
        [[nodiscard]] bool reset(native_handle_type const& handle)
        {
            if (*this == handle)
                return static_cast<bool>(*this);

            close(); // no check for open needed, handled by the handle classes
            m_process_id = handle.dwProcessId;
            m_process_thread_id = handle.dwThreadId;
            static_cast<void>(m_process_handle.reset(handle.hProcess));
            static_cast<void>(m_process_thread_handle.reset(handle.hThread));

            return static_cast<bool>(*this);
        }
        [[nodiscard]] deconstruct_type release()
        {
            auto deconstructed = std::make_tuple(m_native_process_id, m_native_process_thread_id, m_process_handle.release(), m_process_thread_handle.release());
            m_native_process_id = empty_process_thread_id();
            m_native_process_thread_id = empty_process_id();
            return deconstructed;
        }

        friend bool operator==(process_information const& lhs, process_information const& rhs)
        {
            return &lhs == &rhs ||
                lhs.m_process_id == rhs.m_process_id &&
                lhs.m_process_thread_id == rhs.m_process__thread_id &&
                lhs.m_process_handle == rhs.m_process_handle &&
                lhs.m_process_thread_handle == rhs.m_process_thread_handle;
        }
        friend bool operator!=(process_information const& lhs, process_information const& rhs)
        {
            return !(lhs == rhs);
        }
        friend bool operator==(process_information const& lhs, PROCESS_INFORMATION const& rhs)
        {
            return lhs.m_process_id == rhs.dwProcessId &&
                lhs.m_process_thread_id == rhs.dwThreadId &&
                lhs.m_process_handle.get() == rhs.hProcess &&
                lhs.m_process_thread_handle.get() == rhs.hThread;
        }
        friend bool operator!=(process_information const& lhs, PROCESS_INFORMATION const& rhs)
        {
            return !(lhs == rhs);
        }
        friend bool operator==(PROCESS_INFORMATION const& lhs, process_information const& rhs)
        {
            return operator==(rhs, lhs);
        }
        friend bool operator!=(PROCESS_INFORMATION const& lhs, process_information const& rhs)
        {
            return !(lhs == rhs);
        }
        friend bool operator==(process_information const& lhs, deconstruct_type const& rhs)
        {
            return lhs.m_process_id == std::get<native_process_id>(rhs) &&
                lhs.m_process_thread_id == std::get<native_process_thread_id>(rhs) &&
                lhs.m_process_handle.get() == std::get<native_process_handle_type>(rhs) &&
                lhs.m_process_thread_handle.get() == std::get<native_process_thread_handle_type>(rhs);
        }
        friend bool operator!=(process_information const& lhs, deconstruct_type const& rhs)
        {
            return !(lhs == rhs);
        }
        friend bool operator==(deconstruct_type const& lhs, process_information const& rhs)
        {
            return (rhs == lhs);
        }
        friend bool operator!=(deconstruct_type const& lhs, process_information const& rhs)
        {
            return !(lhs == rhs);
        }

        /// <summary>
        /// Returns true if process handle is not invalid and process id is non-empty
        /// </summary>
        /// <remarks>process thread handle is ignored for this check as it is dependent on the process</remarks>
        [[nodiscard]] explicit operator bool() const noexcept
        {
            return static_cast<bool>(m_process_handle) && 
                m_process_thread_handle && m_process_id != empty_process_id();
        }

        friend void swap(process_information& lhs, process_information& rhs) noexcept
        {
            using std::swap;
            swap(lhs.m_process_id, rhs.m_process_id);
            swap(lhs.m_process_thread_id, rhs.m_process_thread_id);
            swap(lhs.m_process_handle, rhs.m_process_handle);
            swap(lhs.m_process_thread_handle, rhs.m_process_thread_handle);
        }

    private:
        native_process_id m_process_id;
        native_process_thread_id m_process_thread_id;
        process_handle m_process_handle;
        process_thread_handle m_process_thread_handle;
        
        void close()
        {
            if (*this)
            {
                m_process_id = empty_process_id();
                m_process_thread_id = empty_process_thread_id();
                static_cast<void>(m_process_handle.reset());
                static_cast<void>(m_process_thread_handle.reset());
            }
        }

    };
}

#endif
#endif
