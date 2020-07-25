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

#ifndef __MODERN_WIN32_PRIVATE_PROCESS_IMPL_H___
#define __MODERN_WIN32_PRIVATE_PROCESS_IMPL_H___

#ifdef _WIN32

#include <filesystem>
#include <vector>
#include <modern_win32/process.h>
#include <modern_win32/process_startup_info.h>
#include <modern_win32/windows_exception.h>

namespace modern_win32::impl
{
    template <typename ENUM_TYPE>
    constexpr auto to_native_enum_value(ENUM_TYPE const& enum_value)
    {
        return static_cast<typename std::underlying_type<ENUM_TYPE>::type>(enum_value);
    }

    using running_details = std::tuple<bool, process::exit_code_type>;

    [[nodiscard]] running_details get_running_details(process::native_handle_type const process_handle);
    [[nodiscard]] running_details get_running_details(process_handle const& process_handle);
    [[nodiscard]] process_id_type get_process_id(process::native_handle_type const handle);
    [[nodiscard]] process_handle get_process_handle(process_id_type const& id, process_access_rights const& access_rights, bool const inherit_handles = false);
    [[nodiscard]] std::optional<process_priority> get_process_priority(process_handle const& process_handle);
    void wait_for_exit(process_handle const& process_handle);
    [[nodiscard]] bool wait_for_exit(process_handle const& process_handle, std::chrono::milliseconds const& timeout); 
    [[nodiscard]] bool is_running(process_handle const& process_handle); 
    [[nodiscard]] std::optional<process::exit_code_type> get_exit_code(process_handle const& process_handle);

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
    [[nodiscard]] inline bool create_process_t(char* command_line, bool const inherit_handles, 
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
    [[nodiscard]] inline bool create_process_t(wchar_t* command_line, bool const inherit_handles, 
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

        auto environment_block = impl::build_environment_block<TCHAR>(startup_info.environment);

        auto const result = impl::create_process_t<TCHAR>(
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
}

#endif
#endif