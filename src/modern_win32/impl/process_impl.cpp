//
// Copyright (c) 2022 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#include "process_impl.h"

#include <modern_win32/wait_for.h>
#include <modern_win32/wait_for_exception.h>
#include <modern_win32/windows_exception.h>

namespace modern_win32::impl {

    [[nodiscard]] running_details get_running_details(process::native_handle_type const process_handle) {
        process::exit_code_type exit_code{};

        if (auto const get_exit_process_success = GetExitCodeProcess(process_handle, &exit_code);
            !get_exit_process_success) {
            throw windows_exception("Unable to get exit code for the requested process");
        }

        using std::make_tuple;
        return exit_code == STILL_ACTIVE ? make_tuple(true, 0UL) : make_tuple(false, exit_code);
    }
    [[nodiscard]] running_details get_running_details(process_handle const& process_handle) {
        return get_running_details(process_handle.native_handle());
    }

    [[nodiscard]] process_id_type get_process_id(process::native_handle_type const handle) {
        if (auto const id = GetProcessId(handle); id != 0) {
            return id;
        }

        windows_error_details const error_details;
        if (auto [is_running, exit_code] = get_running_details(handle); !is_running) {
            return 0;
        }

        throw windows_exception(error_details);
    }
    [[nodiscard]] process_handle get_process_handle(
        process_id_type const& id, process_access_rights const& access_rights, bool const inherit_handles) {
        return process_handle{OpenProcess(to_underlying_type(access_rights), inherit_handles ? TRUE : FALSE, id)};
    }
    [[nodiscard]] std::optional<process_priority> get_process_priority(process_handle const& process_handle) {
        if (!static_cast<bool>(process_handle))
            return std::nullopt;

        auto const native_priority = GetPriorityClass(process_handle.native_handle());
        if (native_priority == 0)
            return std::nullopt;

        // could be replaced by simple cast but it's an excuse to have the constexpr demonstrating
        // getting the raw value
        switch (native_priority) {
        case to_native_enum_value(process_priority::above_normal):
            return {process_priority::above_normal};

        case to_native_enum_value(process_priority::below_normal):
            return {process_priority::below_normal};

        case to_native_enum_value(process_priority::idle):
            return {process_priority::idle};

        case to_native_enum_value(process_priority::realtime):
            return {process_priority::realtime};

        case to_native_enum_value(process_priority::normal):
        default:
            return {process_priority::normal};
        }
    }


    void wait_for_exit(process_handle const& process_handle) {
        if (!is_running(process_handle)) {
            return;
        }

        bool done = false;
        while (!done) {
            using std::literals::chrono_literals::operator""ms;
            switch (wait_for_result const result = wait_one(process_handle, 500ms); result) {
            case wait_for_result::object:
                done = true;
                break;
            case wait_for_result::abandonded:
            case wait_for_result::io_completion:
            case wait_for_result::failed:
                throw wait_for_exception(result);
            case wait_for_result::timeout:
            default:
                std::this_thread::sleep_for(250ms);
                break;
            }
        }

        static_cast<void>(wait_one(process_handle));
    }

    bool wait_for_exit(process_handle const& process_handle, std::chrono::milliseconds const& timeout) {
        if (!is_running(process_handle))
            return true;

        return is_complete(wait_one(process_handle, timeout));
    }

    bool is_running(process_handle const& process_handle) {
        if (!static_cast<bool>(process_handle))
            return false;

        auto const [isRunning, exit_code] = impl::get_running_details(process_handle);
        static_cast<void>(exit_code);
        return isRunning;
    }

    bool has_exited(process_handle const& process_handle) {
        return !is_running(process_handle);
    }

    std::optional<process::exit_code_type> get_exit_code(process_handle const& process_handle) {
        if (!static_cast<bool>(process_handle))
            return std::nullopt;

        auto const [isRunning, exit_code] = impl::get_running_details(process_handle.native_handle());
        return isRunning ? std::nullopt : std::optional(exit_code);
    }

} // namespace modern_win32::impl
