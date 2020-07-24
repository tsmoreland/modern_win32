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

#include <filesystem>
#include <sstream>
#include <vector>
#include <modern_win32/access_denied_exception.h>
#include <modern_win32/process.h>
#include <modern_win32/process_enums.h>
#include <modern_win32/process_startup_info.h>
#include <modern_win32/wait_for.h>
#include <modern_win32/windows_error.h>

#include "impl/process_impl.h"

namespace modern_win32
{

process::process(process_id_type const& id)
    : m_id{id}
{
    if (id == 0UL)
        throw std::invalid_argument("id cannot be 0");
}
process::process(process_id_type const& id, process_access_rights const access_rights, bool const inherit_handles)
    : process(m_id)
{
    m_handle = impl::get_process_handle(m_id, access_rights, inherit_handles);
}
process::process(native_handle_type const& handle)
    : m_handle{handle}
    , m_id{0UL}
{
    if (handle == process_handle::invalid())
        return;

    m_id = impl::get_process_id(handle);

}
process::process(process_id_type const& id, native_handle_type const& handle)
    : m_handle{handle}
    , m_id{id}
{
    if (handle == process_handle::invalid() && m_id != 0UL)
        throw std::invalid_argument("id must be zero if handle is invalid");
    if (handle != process_handle::invalid() && m_id == 0UL)
        throw std::invalid_argument("id must be provided if handle is not invalid");
}
process::process(deconstruct_type const& id_handle_pair)
    : process(id_handle_pair.first, id_handle_pair.second)
{
}
process::process(process&& other) noexcept
{
    auto [id, handle] = other.release();
    m_id = id;
    m_handle = handle;
}

process& process::operator=(process&& other) noexcept
{
    if (*this == other)
        return *this;

    m_handle = std::move(other.m_handle);
    m_id = other.m_id;
    other.m_id = 0;

    return *this;
}

bool operator==(process const& first, process const& second)
{
    return first.m_handle == second.m_handle && first.m_id == second.m_id;
}
bool operator!=(process const& first, process const& second)
{
    return !(first == second);
}

process::operator bool() const noexcept
{
    if (static_cast<bool>(m_handle))
        return true;
    if (m_id != 0UL) {
        return static_cast<bool>(impl::get_process_handle(m_id, combine(process_access_rights::process_query_information, process_access_rights::synchronize)));
    }
    return false;
}

void swap(process& first, process& second) noexcept
{
    using std::swap;
    swap(first.m_handle, second.m_handle);
    swap(first.m_id, second.m_id);
}

bool process::reset(deconstruct_type const& process)
{
    auto [id, handle] = process;

    if (m_handle.native_handle() == handle)
        return static_cast<bool>(*this);

    close();
    m_id = id;
    return m_handle.reset(handle);
}

bool process::reset(native_handle_type const handle)
{
    if (m_handle.native_handle() == handle)
        return static_cast<bool>(*this);

    close();

    return m_handle.reset(handle);
}

process::deconstruct_type process::release()
{
    process_id_type id{};
    std::swap(m_id, id);
    return make_deconstruct_type(id, m_handle.release());
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
    return m_id;
}

bool process::is_running() const
{
    if (!static_cast<bool>(*this))
        return false;

    auto const [isRunning, exit_code] = impl::get_running_details(m_handle);
    static_cast<void>(exit_code);
    return isRunning;
}

bool process::has_exited() const
{
    return !is_running();
}


std::optional<process_priority> process::get_priority() const
{
    if (!static_cast<bool>(*this))
        return std::nullopt;

    if (static_cast<bool>(m_handle))
        return impl::get_process_priority(m_handle);

    auto const handle = impl::get_process_handle(m_id, process_access_rights::process_query_information);
    return impl::get_process_priority(handle);
}

std::optional<process::exit_code_type> process::get_exit_code() const
{
    if (!static_cast<bool>(m_handle))
        return std::nullopt;

    auto const [isRunning, exit_code] = impl::get_running_details(m_handle.native_handle());
    return isRunning
        ? std::nullopt
        : std::optional(exit_code);
}

void process::wait_for_exit() const
{
    if (!static_cast<bool>(*this))
        return;

    if (static_cast<bool>(m_handle)) {
        impl::wait_for_exit(m_handle);
        return;
    }

    static_cast<void>(wait_one(m_handle));
}

bool process::wait_for_exit(std::chrono::milliseconds const& timeout) const 
{
    if (!static_cast<bool>(*this))
        return true;

    if (static_cast<bool>(m_handle))
        return impl::wait_for_exit(m_handle, timeout);

    auto const handle = impl::get_process_handle(m_id, combine(process_access_rights::process_query_information, process_access_rights::synchronize));
    return impl::wait_for_exit(handle, timeout);
}

void process::close() noexcept
{
    if (*this)
        static_cast<void>(m_handle.reset());

}

process open_process(process_id_type const& process_id, process_access_rights const access_rights, bool const inherit_handles)
{
    process process{process_id};

    if (static_cast<bool>(process))
        return process;

    windows_error_details const error{};
    switch (error) {
    case windows_error::error_invalid_parameter:
        throw std::invalid_argument("invalid process id");
    case windows_error::error_access_denied:
        throw access_denied_exception();
    default:
        throw windows_exception(error.native_error_code());
    }
}

template <typename TCHAR>
std::vector<TCHAR>&& build_environment_block(typename process_startup_info<TCHAR>::environment_variable_container const& maybe_environment_map)
{
    std::vector<TCHAR> environment_block;
    if (!maybe_environment_map.has_value())
        return std::move(environment_block);

    auto& environment_map = maybe_environment_map.value();
    auto const nul_char = TCHAR(0);
    auto const equals_char = TCHAR('=');

    using std::copy;
    using std::back_inserter;

    for (auto& pair : environment_map)
    {
        copy(begin(pair.first), end(pair.first), back_inserter(environment_block));
        environment_block.push_back(equals_char);
        copy(begin(pair.second), end(pair.second), back_inserter(environment_block));
        environment_block.push_back(nul_char);
    }
    if (!environment_block.empty())
        environment_block.push_back(nul_char);

    return std::move(environment_block);
}

template <typename TCHAR>
[[nodiscard]] bool create_process_t(TCHAR* command_line, bool inherit_handles, 
    std::vector<TCHAR>& environment_block, TCHAR const* directory, 
    process_startup_info<TCHAR> const& startup_info, PROCESS_INFORMATION& process_information)
{
    return false;
}

template <>
[[nodiscard]] bool create_process_t(char* command_line, bool const inherit_handles, 
    std::vector<char>& environment_block, char const* directory, 
    process_startup_info<char> const& startup_info, PROCESS_INFORMATION& process_information)
{
    auto native_startup_info = startup_info.build_native_startup_info<STARTUPINFOA>();
    return CreateProcessA(
        nullptr,
        command_line, 
        nullptr, 
        nullptr, 
        inherit_handles ? TRUE : FALSE, 
        to_underlying_type(startup_info.build_creation_options()), 
        environment_block.empty() ? static_cast<void*>(nullptr) : static_cast<void*>(&environment_block[0]),
        directory,
        &native_startup_info, 
        &process_information) == TRUE;
}
template <>
[[nodiscard]] bool create_process_t(wchar_t* command_line, bool const inherit_handles, 
    std::vector<wchar_t>& environment_block, wchar_t const* directory, 
    process_startup_info<wchar_t> const& startup_info, PROCESS_INFORMATION& process_information)
{
    auto native_startup_info = startup_info.build_native_startup_info<STARTUPINFOW>();
    return CreateProcessW(
        nullptr,
        command_line, 
        nullptr, 
        nullptr, 
        inherit_handles ? TRUE : FALSE, 
        to_underlying_type(startup_info.build_creation_options()), 
        environment_block.empty() ? static_cast<void*>(nullptr) : static_cast<void*>(&environment_block[0]),
        directory,
        &native_startup_info, 
        &process_information) == TRUE;
}

template <typename TCHAR>
process start_process(process_startup_info<TCHAR> const& startup_info)
{
    std::filesystem::path const filename(startup_info.filename);
    if (!exists(filename))
        throw std::filesystem::filesystem_error("filename not found", std::error_code(static_cast<int>(windows_error::error_file_not_found), std::iostream_category()));

    auto command_buffer = startup_info.build_command_buffer();

    PROCESS_INFORMATION process_information{};

    auto environment_block = build_environment_block<TCHAR>(startup_info.environment);

    auto const result = create_process_t<TCHAR>(
        command_buffer.get(), 
        startup_info.inherit_handles,
        environment_block,
        startup_info.directory.empty() ? nullptr : startup_info.directory.c_str(), // working directory,
        startup_info,
        process_information);

    if (!result)
        throw windows_exception();

    CloseHandle(process_information.hThread);
    return process(process_information.dwProcessId, process_information.hProcess);
}

process start_process(char const* filename, char const* arguments)
{
    auto const startup_info = process_startup_info_builder<char>()
        .with_filename(filename)
        .with_arguments(arguments)
        .build();
    return start_process(startup_info);
}

process start_process(wchar_t const* filename, wchar_t const* arguments)
{
    auto const startup_info = process_startup_info_builder<wchar_t>()
        .with_filename(filename)
        .with_arguments(arguments)
        .build();
    return start_process<wchar_t>(startup_info);

}

}
