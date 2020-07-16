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

#include <modern_win32/process.h>

#include "modern_win32/wait_for.h"

namespace modern_win32
{

process::process(native_handle_type const& handle)
    : m_handle(handle)
{
    if (handle == process_handle::invalid())
        return;
}
process::process(process&& other) noexcept
    : m_handle{other.release()}
{
}

process& process::operator=(process&& other) noexcept
{
    if (*this == other)
        return *this;

    swap(m_handle, other.m_handle);
    return *this;
}

bool operator==(process const& first, process const& second)
{
    return first.m_handle == second.m_handle;
}
bool operator!=(process const& first, process const& second)
{
    return !(first == second);
}

process::operator bool() const noexcept
{
    return static_cast<bool>(m_handle);
}

void swap(process& first, process& second) noexcept
{
    swap(first.m_handle, second.m_handle);
}

bool process::reset(native_handle_type const& handle)
{
    if (m_handle.native_handle() == handle)
        return static_cast<bool>(*this);

    close();
    return m_handle.reset(handle);
}

process::native_handle_type process::release()
{
    return m_handle.release();
}

process::native_handle_type process::native_handle() const noexcept
{
    return m_handle.native_handle();
}

process_handle& process::get() noexcept
{
    return m_handle;
}

std::optional<process_id_type> process::get_process_id() const
{
    if (!static_cast<bool>(*this))
        return std::nullopt;

    auto const process_id = GetProcessId(m_handle.native_handle());
    if (process_id == 0)
        throw windows_exception("Error occurred retrieving process id");
    return std::optional(process_id);
}

bool process::is_running() const
{
    if (!static_cast<bool>(m_handle))
        return false;

    auto const [isRunning, exit_code] = get_running_details(m_handle.native_handle());
    static_cast<void>(exit_code);
    return isRunning;
}

template <typename ENUM_TYPE>
constexpr auto to_native_enum_value(ENUM_TYPE const& enum_value) {

    return static_cast<typename std::underlying_type<ENUM_TYPE>::type>(enum_value);
}

std::optional<process_priority> process::get_priority() const
{
    if (!static_cast<bool>(m_handle))
        return std::nullopt;

    auto const native_priority = GetPriorityClass(m_handle.native_handle());
    if (native_priority == 0)
        throw windows_exception();

    // could be replaced by simple cast but it's an excuse to have the constexpr demonstrating
    // getting the raw value
    switch (native_priority)
    {
    case to_native_enum_value(process_priority::above_normal):
        return std::optional(process_priority::above_normal);

    case to_native_enum_value(process_priority::below_normal):
        return std::optional(process_priority::below_normal);

    case to_native_enum_value(process_priority::idle):
        return std::optional(process_priority::idle);

    case to_native_enum_value(process_priority::realtime):
        return std::optional(process_priority::realtime);

    case to_native_enum_value(process_priority::normal):
    default:
        return std::optional(process_priority::normal);
    }
}

std::optional<process::exit_code_type> process::get_exit_code() const
{
    if (!static_cast<bool>(m_handle))
        return std::nullopt;

    auto const [isRunning, exit_code] = get_running_details(m_handle.native_handle());
    return isRunning
        ? std::nullopt
        : std::optional(exit_code);
}

void process::wait_for_exit() const
{
    if (!is_running())
        return;
    static_cast<void>(wait_for_single_object_to_bool(WaitForSingleObject(m_handle.native_handle(), INFINITE)));
}

bool process::wait_for_exit(std::chrono::milliseconds const& timeout) const 
{
    if (!is_running())
        return true;

    auto const native_timeout = convert_timeout(timeout);
    return wait_for_single_object_to_bool(WaitForSingleObject(m_handle.native_handle(), native_timeout));
}

void process::close() noexcept
{
    if (*this)
        static_cast<void>(m_handle.reset());

}
process::running_details process::get_running_details(native_handle_type process_handle)
{
    exit_code_type exit_code{};
    auto const getExitProcessSuccess = GetExitCodeProcess(process_handle, &exit_code);
    if (!getExitProcessSuccess)
        throw windows_exception("Unable to get exit code for the requested process");

    using std::make_tuple;
    return exit_code == STILL_ACTIVE
        ? make_tuple(true, 0UL)
        : make_tuple(false, exit_code);
}

}
