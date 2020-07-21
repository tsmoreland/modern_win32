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

#include <sstream>
#include <modern_win32/access_denied_exception.h>
#include <modern_win32/process.h>
#include <modern_win32/process_enums.h>
#include <modern_win32/process_startup_info.h>
#include <modern_win32/wait_for.h>
#include <modern_win32/windows_error.h>

namespace modern_win32
{

using running_details = std::tuple<bool, process::exit_code_type>;

[[nodiscard]] running_details get_running_details(process::native_handle_type const process_handle)
{
    process::exit_code_type exit_code{};
    auto const getExitProcessSuccess = GetExitCodeProcess(process_handle, &exit_code);
    if (!getExitProcessSuccess)
        throw windows_exception("Unable to get exit code for the requested process");

    using std::make_tuple;
    return exit_code == STILL_ACTIVE
        ? make_tuple(true, 0UL)
        : make_tuple(false, exit_code);
}

process_id_type get_process_id(process::native_handle_type const handle)
{
    auto const id = GetProcessId(handle);
    if (id != 0)
        return id;

    windows_error_details const error_details;

    auto [is_running, exit_code] = get_running_details(handle);
    if (!is_running)
        return 0;

    throw windows_exception(error_details);
}

process::process(native_handle_type const& handle)
    : m_handle{handle}
    , m_id{0UL}
{
    if (handle == process_handle::invalid())
        return;

    m_id = modern_win32::get_process_id(handle);

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
    return static_cast<bool>(m_handle);
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
    if (!static_cast<bool>(m_handle))
        return false;

    auto const [isRunning, exit_code] = get_running_details(m_handle.native_handle());
    static_cast<void>(exit_code);
    return isRunning;
}

bool process::has_exited() const
{
    return !is_running();
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

    static_cast<void>(wait_one(m_handle));
}

bool process::wait_for_exit(std::chrono::milliseconds const& timeout) const 
{
    if (!is_running())
        return true;

    return is_complete(wait_one(m_handle, timeout));
}

void process::close() noexcept
{
    if (*this)
        static_cast<void>(m_handle.reset());

}

process open(process_id_type const process_id, process_access_rights const access_rights, bool const inherit_handles)
{
    process process{OpenProcess(static_cast<DWORD>(access_rights), inherit_handles ? TRUE : FALSE, process_id)};

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

template <typename TCHAR, typename CREATE_PROCESS>
process start(process_startup_info<TCHAR> const& startup_info)
{
    std::filesystem::path const filename(startup_info.filename);
    if (!exists(filename))
        throw std::filesystem::filesystem_error("filename not found", std::error_code(static_cast<int>(windows_error::error_file_not_found), std::iostream_category()));

    auto native_startup_info = startup_info.starup.build_native_startup_info();
    auto command_buffer = startup_info.build_command_buffer();

    PROCESS_INFORMATION process_information{};

    auto const result = create_process(
        filename.c_str(), 
        command_buffer.get(), 
        nullptr, // process attributes
        nullptr, // thread attributes
        startup_info.inhherit_handles,
        to_underlying_type(startup_info.build_creation_options()), 
        nullptr, // environment
        nullptr, // working directory,
        &startup_info,
        &process_information);

    if (result != TRUE)
        throw windows_exception();

    CloseHandle(process_information.hThread);
    return process(process_information.dwProcessId, process_information.hProcess);
}

template <typename TCHAR, typename STARTUPINFO, typename CREATE_PROCESS>
process start(std::filesystem::path const& filename, TCHAR const* arguments, CREATE_PROCESS create_process, bool inherit_handles, process_priority priority, STARTUPINFO& startup_info)
{
    if (!exists(filename))
        throw std::filesystem::filesystem_error("filename not found", std::error_code(static_cast<int>(windows_error::error_file_not_found), std::iostream_category()));

    PROCESS_INFORMATION process_information{};

    std::basic_stringstream<TCHAR> builder;
    builder << filename << " " << arguments;
    std::basic_string<TCHAR> command_line = builder.str();
    auto command_buffer = std::make_unique<TCHAR[]>(command_line.size() + 1); // null terminator

    std::copy(command_line.begin(), command_line.end(), command_buffer.get());

    auto create_flags = static_cast<std::underlying_type<process_priority>::type>(priority);

    // leaving here for now - but this should be movoed along with priority out to a process_startup_info class that mirrors the C# equivalent, if nothing else it'll
    // save adding endless options to this constructor
    create_flags |=  static_cast<std::underlying_type<process_creation_options>::type>(process_creation_options::create_no_window); 

    auto const result = create_process(
        filename.c_str(), 
        command_buffer.get(), 
        nullptr, // process attributes
        nullptr, // thread attributes
        inherit_handles, 
        create_flags,
        nullptr, // environment
        nullptr, // working directory,
        &startup_info,
        &process_information);

    if (result != TRUE)
        throw windows_exception();

    CloseHandle(process_information.hThread);
    return process(process_information.dwProcessId, process_information.hProcess);
}

process start(std::filesystem::path const& filename, char const* arguments)
{
    if (!exists(filename))
        throw std::filesystem::filesystem_error("filename not found", std::error_code(static_cast<int>(windows_error::error_file_not_found), std::iostream_category()));

    STARTUPINFOA startup_info{};
    startup_info.cb = sizeof(startup_info);

    return start(filename.string(), arguments, CreateProcessA, true, process_priority::normal, startup_info);
}

process start(std::filesystem::path const& filename, wchar_t const* arguments)
{
    if (!exists(filename))
        throw std::filesystem::filesystem_error("filename not found", std::error_code(static_cast<int>(windows_error::error_file_not_found), std::iostream_category()));

    STARTUPINFOW startup_info{};
    startup_info.cb = sizeof(startup_info);
    return start(filename.wstring(), arguments, CreateProcessW, true, process_priority::normal, startup_info);
}

}
