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
    
#include <modern_win32/process_information.h>
#include <memory>
#include "shared.h"

namespace modern_win32
{

process_information::process_information()
    : m_process_id{empty_process_id()}
    , m_process_thread_id{empty_process_thread_id()}
{
}
/// <summary>Initializes an open process_information class based on <paramref name="process_information"/></summary>
process_information::process_information(native_handle_type const& process_information)
    : m_process_id{process_information.dwProcessId}
    , m_process_thread_id{process_information.dwThreadId}
    , m_process_handle{process_information.hProcess}
    , m_process_thread_handle{process_information.hThread}
{
}
process_information::process_information(process_information&& other) noexcept 
{
    auto [process_id, process_thread_id, process_handle, process_thread_handle] = other.release();
    m_process_id = process_id;
    m_process_thread_id = process_thread_id;
    static_cast<void>(m_process_handle.reset(process_handle));
    static_cast<void>(m_process_thread_handle.reset(process_thread_handle));
}
process_information& process_information::operator=(process_information&& other) noexcept 
{
    if (*this == other)
        return *this;

    std::swap(*this, other);
    return *this;
}
process_information::~process_information() 
{
    close(); // done to match unique_handle but not really needed, default would be fine
}

process_information::native_handle_type process_information::native_handle() const noexcept
{
    native_handle_type process_information;
    process_information.hProcess = m_process_handle.native_handle();
    process_information.hThread = m_process_thread_handle.native_handle();
    process_information.dwProcessId = m_process_id;
    process_information.dwThreadId = m_process_thread_id;
    return process_information;
}
process_information::native_process_handle_type process_information::get_native_process_handle() const noexcept
{
    return m_process_handle.native_handle();
}
process_information::native_process_thread_handle_type process_information::get_native_process_thread_handle() const noexcept
{
    return m_process_thread_handle.native_handle();
}
process_information::native_process_id process_information::get_native_process_id() const noexcept
{
    return m_process_id;
}
process_information::native_process_thread_id process_information::get_native_process_thread_id() const noexcept
{
    return m_process_thread_id;
}
process_handle& process_information::get_process_handle() noexcept
{
    return m_process_handle;
}
process_thread_handle& process_information::get_process_thread_handle() noexcept
{
    return m_process_thread_handle;
}

bool process_information::is_running() const 
{
    if (!static_cast<bool>(m_process_handle))
        return false;

    auto const [isRunning, exit_code] = get_running_details(m_process_handle.native_handle());
    static_cast<void>(exit_code);
    return isRunning;
}

void process_information::wait_for_exit() const
{
    if (!is_running())
        return;
    static_cast<void>(wait_for_single_object_to_bool(WaitForSingleObject(m_process_handle.native_handle(), INFINITE)));
}
bool process_information::wait_for_exit(std::chrono::milliseconds const& timeout) const
{
    if (!is_running())
        return true;

    auto const native_timeout = convert_timeout(timeout);
    return wait_for_single_object_to_bool(WaitForSingleObject(m_process_handle.native_handle(), native_timeout));
}

std::optional<process_information::native_process_exit_code> process_information::get_exit_code() const
{
    if (!static_cast<bool>(m_process_handle))
        return std::nullopt;

    auto const [isRunning, exit_code] = get_running_details(m_process_handle.native_handle());
    return isRunning
        ? std::nullopt
        : std::optional(exit_code);
}

bool process_information::reset(deconstruct_type&& deconstructed)
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
bool process_information::reset(native_handle_type const& handle)
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
process_information::deconstruct_type process_information::release()
{
    auto deconstructed = std::make_tuple(m_process_id, m_process_thread_id, m_process_handle.release(), m_process_thread_handle.release());
    m_process_id = empty_process_thread_id();
    m_process_thread_id = empty_process_id();
    return deconstructed;
}

bool operator==(process_information const& lhs, process_information const& rhs)
{
    return &lhs == &rhs ||
        lhs.m_process_id == rhs.m_process_id &&
        lhs.m_process_thread_id == rhs.m_process_thread_id &&
        lhs.m_process_handle == rhs.m_process_handle &&
        lhs.m_process_thread_handle == rhs.m_process_thread_handle;
}
bool operator!=(process_information const& lhs, process_information const& rhs)
{
    return !(lhs == rhs);
}
bool operator==(process_information const& lhs, PROCESS_INFORMATION const& rhs)
{
    return lhs.m_process_id == rhs.dwProcessId &&
        lhs.m_process_thread_id == rhs.dwThreadId &&
        lhs.m_process_handle.native_handle() == rhs.hProcess &&
        lhs.m_process_thread_handle.native_handle() == rhs.hThread;
}
bool operator!=(process_information const& lhs, PROCESS_INFORMATION const& rhs)
{
    return !(lhs == rhs);
}
bool operator==(PROCESS_INFORMATION const& lhs, process_information const& rhs)
{
    return operator==(rhs, lhs);
}
bool operator!=(PROCESS_INFORMATION const& lhs, process_information const& rhs)
{
    return !(lhs == rhs);
}
bool operator==(process_information const& lhs, process_information::deconstruct_type const& rhs)
{
    return lhs.m_process_id == std::get<0>(rhs) &&
        lhs.m_process_thread_id == std::get<1>(rhs) &&
        lhs.m_process_handle.native_handle() == std::get<2>(rhs) &&
        lhs.m_process_thread_handle.native_handle() == std::get<3>(rhs);
}
bool operator!=(process_information const& lhs, process_information::deconstruct_type const& rhs)
{
    return !(lhs == rhs);
}
bool operator==(process_information::deconstruct_type const& lhs, process_information const& rhs)
{
    return (rhs == lhs);
}
bool operator!=(process_information::deconstruct_type const& lhs, process_information const& rhs)
{
    return !(lhs == rhs);
}

process_information::operator bool() const noexcept
{
    return static_cast<bool>(m_process_handle) && 
        m_process_thread_handle && m_process_id != empty_process_id();
}

void swap(process_information& lhs, process_information& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_process_id, rhs.m_process_id);
    swap(lhs.m_process_thread_id, rhs.m_process_thread_id);
    swap(lhs.m_process_handle, rhs.m_process_handle);
    swap(lhs.m_process_thread_handle, rhs.m_process_thread_handle);
}

void process_information::close()
{
    if (*this)
    {
        m_process_id = empty_process_id();
        m_process_thread_id = empty_process_thread_id();
        static_cast<void>(m_process_handle.reset());
        static_cast<void>(m_process_thread_handle.reset());
    }
}

process_information::running_details process_information::get_running_details(native_process_handle_type process_handle) 
{
    native_process_exit_code exit_code{};
    auto const getExitProcessSuccess = GetExitCodeProcess(process_handle, &exit_code);
    if (!getExitProcessSuccess)
        throw windows_exception("Unable to get exit code for the requested process");

    using std::make_tuple;
    return exit_code == STILL_ACTIVE
        ? make_tuple(true, 0UL)
        : make_tuple(false, exit_code);
}

bool process_information::wait_for_single_object_to_bool(wait_result const& result)
{
    switch (result)
    {
    case WAIT_OBJECT_0:
        return true;
    case WAIT_FAILED:
        throw windows_exception("an error occurred attempting to wait");
    case WAIT_ABANDONED:
        throw std::runtime_error("handle represented a mutex which was abondoned rather than process");
    case WAIT_TIMEOUT:
    default:
        return false;
    }
}

}