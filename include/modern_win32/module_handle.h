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

#ifndef MODERN_WIN32_MODULE_H_
#define MODERN_WIN32_MODULE_H_
#include <tuple>
#ifdef _WIN32

#include <modern_win32/unique_handle.h>
#include <optional>

#include <Windows.h>

namespace modern_win32 {
    struct module_traits final {
        using native_handle_type = HMODULE;

        static constexpr native_handle_type invalid() {
            return nullptr;
        }
        static void close(native_handle_type const handle) {
            FreeLibrary(handle);
        }
    };
    using module_handle = unique_handle<module_traits>;

    inline std::optional<module_handle> get_module(char const* module_name) {
        module_traits::native_handle_type native_handle;
        return GetModuleHandleExA(0, module_name, &native_handle) == TRUE ? std::optional(module_handle{native_handle})
                                                                          : std::nullopt;
    }
    inline std::optional<module_handle> get_module(wchar_t const* module_name) {
        module_traits::native_handle_type native_handle;
        return GetModuleHandleExW(0, module_name, &native_handle) == TRUE ? std::optional(module_handle{native_handle})
                                                                          : std::nullopt;
    }

} // namespace modern_win32

#endif
#endif
