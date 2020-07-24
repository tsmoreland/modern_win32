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

#include "modern_win32/process.h"

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

}

#endif
#endif