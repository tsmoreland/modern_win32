//
// Copyright © 2021 Terry Moreland
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

#ifndef MODERN_WIN32_PROCESS_MODULE_H_
#define MODERN_WIN32_PROCESS_MODULE_H_ // NOLINT(clang-diagnostic-unused-macros)
#ifdef _WIN32

#include <modern_win32/modern_win32_export.h>
#include <string>

#include <Windows.h>

namespace modern_win32 {


    class process_module final {
        HANDLE process_{};
        HMODULE module_{};

    public:
        using native_process_handle_type = HANDLE;
        using native_module_handle_type  = HMODULE;

        /// <summary>
        /// returns the module name
        /// </summary>
        /// <returns>the module name</returns>
        /// <exception cref="windows_exception">if WIN32 API fails</exception>
        [[nodiscard]] MODERN_WIN32_EXPORT std::wstring get_name() const;

        /// <summary>
        /// returns the modules full path as a string
        /// </summary>
        /// <returns>the modules full path as a string</returns>
        /// <exception cref="windows_exception">if WIN32 API fails</exception>
        [[nodiscard]] MODERN_WIN32_EXPORT std::wstring get_filename() const;

        /// <summary>
        /// instantiates a new process_module
        /// </summary>
        /// <param name="process">process that owns module, this is a non-owning handle, ownership handled
        /// elsewhere</param> <param name="module">native module handle reference</param> <remarks> module will not be
        /// closed on destruction of this object, it is expected that this object is created by EnumProcessModulesEx
        /// </remarks>
        MODERN_WIN32_EXPORT explicit process_module(
            native_process_handle_type process, native_module_handle_type module);

        [[nodiscard]] constexpr native_process_handle_type process_handle() const noexcept {
            return process_;
        }

        [[nodiscard]] constexpr native_module_handle_type module_handle() const noexcept {
            return module_;
        }
    };

} // namespace modern_win32


#endif
#endif
