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
#include <modern_win32/shared_utilities.h>
#include <Psapi.h>

#include "impl/process_impl.h"

namespace modern_win32
{

    process::process(process_id_type const& id)
        : id_{id}
    {
        if (id == 0UL)
            throw std::invalid_argument("id cannot be 0");
    }
    process::process(process_id_type const& id, process_access_rights const access_rights, bool const inherit_handles)
        : process(id)
    {
        static_cast<void>(handle_.reset(impl::get_process_handle(id_, access_rights, inherit_handles).release()));
    }
    process::process(native_handle_type const& handle)
        : handle_{handle}
        , id_{0UL}
    {
        if (handle == process_handle::invalid())
            return;

        id_ = impl::get_process_id(handle);

    }
    process::process(process_id_type const& id, native_handle_type const& handle)
        : handle_{handle}
        , id_{id}
    {
        if (handle == process_handle::invalid() && id_ != 0UL)
            throw std::invalid_argument("id must be zero if handle is invalid");
        if (handle != process_handle::invalid() && id_ == 0UL)
            throw std::invalid_argument("id must be provided if handle is not invalid");
    }
    process::process(deconstruct_type const& id_handle_pair)
        : process(id_handle_pair.first, id_handle_pair.second)
    {
    }
    process::process(process&& other) noexcept
    {
        auto [id, handle] = other.release();
        id_ = id;
        static_cast<void>(handle_.reset(handle));
    }

    process& process::operator=(process&& other) noexcept
    {
        if (*this == other)
            return *this;

        static_cast<void>(handle_.reset(other.handle_.release()));
        id_ = other.id_;
        other.id_ = 0;

        return *this;
    }

    bool operator==(process const& first, process const& second)
    {
        return first.handle_ == second.handle_ && first.id_ == second.id_;
    }
    bool operator!=(process const& first, process const& second)
    {
        return !(first == second);
    }

    process::operator bool() const noexcept
    {
        if (static_cast<bool>(handle_))
            return true;
        if (id_ != 0UL) {
            return static_cast<bool>(impl::get_process_handle(id_, combine(process_access_rights::process_query_information, process_access_rights::synchronize)));
        }
        return false;
    }

    void swap(process& first, process& second) noexcept
    {
        using std::swap;
        swap(first.handle_, second.handle_);
        swap(first.id_, second.id_);
    }

    bool process::reset(deconstruct_type const& process)
    {
        auto [id, handle] = process;

        if (handle_.native_handle() == handle)
            return static_cast<bool>(*this);

        close();
        id_ = id;
        return handle_.reset(handle);
    }

    bool process::reset(native_handle_type const handle)
    {
        if (handle_.native_handle() == handle)
            return static_cast<bool>(*this);

        close();

        return handle_.reset(handle);
    }

    process::deconstruct_type process::release()
    {
        process_id_type id{};
        std::swap(id_, id);
        return make_deconstruct_type(id, handle_.release());
    }

    process::native_handle_type process::native_handle() const noexcept
    {
        return handle_.native_handle();
    }

    process_handle& process::get() noexcept
    {
        return handle_;
    }

    std::optional<process_id_type> process::get_process_id() const
    {
        return id_;
    }

    bool process::is_running() const
    {
        if (!static_cast<bool>(*this))
            return false;

        auto const [isRunning, exit_code] = impl::get_running_details(handle_);
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

        if (static_cast<bool>(handle_))
            return impl::get_process_priority(handle_);

        auto const handle = impl::get_process_handle(id_, process_access_rights::process_query_information);
        return impl::get_process_priority(handle);
    }

    std::optional<process::exit_code_type> process::get_exit_code() const
    {
        if (!static_cast<bool>(handle_))
            return std::nullopt;

        auto const [isRunning, exit_code] = impl::get_running_details(handle_.native_handle());
        return isRunning
            ? std::nullopt
            : std::optional(exit_code);
    }

    void process::wait_for_exit() const
    {
        if (!static_cast<bool>(*this))
            return;

        if (static_cast<bool>(handle_)) {
            impl::wait_for_exit(handle_);
            return;
        }

        static_cast<void>(wait_one(handle_));
    }

    bool process::wait_for_exit(std::chrono::milliseconds const& timeout) const 
    {
        if (!static_cast<bool>(*this))
            return true;

        if (static_cast<bool>(handle_))
            return impl::wait_for_exit(handle_, timeout);

        auto const handle = impl::get_process_handle(id_, combine(process_access_rights::process_query_information, process_access_rights::synchronize));
        return impl::wait_for_exit(handle, timeout);
    }

    void process::close() noexcept
    {
        if (*this)
            static_cast<void>(handle_.reset());

    }

    process_module process::get_primary_module() const
    {
        return get_modules(1)[0];
    }

    std::vector<process_module> process::get_modules(DWORD max_count /*= 1024*/) const
    {
        if (!static_cast<bool>(handle_)) {
            throw windows_exception(ERROR_PROC_NOT_FOUND);
        }
        if (max_count == 0) {
            throw std::invalid_argument("max_count must be greater than 0");
        }

        std::vector<process_module> modules;

        std::unique_ptr<HMODULE[]> const module_handles = std::make_unique<HMODULE[]>(max_count);
        DWORD bytes_required;
        if (EnumProcessModules(handle_.native_handle(), module_handles.get(), sizeof(HMODULE), &bytes_required) == 0) {
            throw windows_exception();
        }

        if (bytes_required == 0) {
            throw windows_exception(ERROR_PROC_NOT_FOUND); // maybe a better choice here, ideally this should never happen, 
        }

        for (auto index = 0ULL, upper_bound = bytes_required / sizeof(HMODULE); index < upper_bound; index++) {
            modules.emplace_back(handle_.native_handle(), module_handles[index]);
        }

        return modules;
    }

    process open_process(process_id_type const& id, process_access_rights const access_rights, bool const inherit_handles)
    {
        process process{id, access_rights, inherit_handles};

        if (static_cast<bool>(process))
            return process;

        windows_error_details const error{};
        switch (error) {  // NOLINT(clang-diagnostic-switch-enum)
        case windows_error::error_invalid_parameter:
            throw std::invalid_argument("invalid process id");
        case windows_error::error_access_denied:
            throw access_denied_exception();
        default:
            throw windows_exception(error.native_error_code());
        }
    }

    process start_process(ansi_process_startup_info const& startup_info)
    {
        return impl::start_process<char>(startup_info);
    }
    process start_process(wide_process_startup_info const& startup_info)
    {
        return impl::start_process<wchar_t>(startup_info);
    }

    process start_process(char const* filename, char const* arguments)
    {
        process_startup_info<char> const startup_info = ansi_process_startup_info_builder()
            .with_filename(filename)
            .with_arguments(arguments)
            .build();
        return start_process(startup_info);
    }

    process start_process(wchar_t const* filename, wchar_t const* arguments)
    {
        process_startup_info<wchar_t> const startup_info = wide_process_startup_info_builder()
            .with_filename(filename)
            .with_arguments(arguments)
            .build();
        return start_process(startup_info);

    }

}
