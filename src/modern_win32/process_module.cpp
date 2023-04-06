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

#include "modern_win32/process_module.h"
#include "modern_win32/windows_exception.h"

#include <Psapi.h>
#include <memory>

namespace modern_win32 {

    [[nodiscard]] std::wstring get_module_filename(HANDLE process, HMODULE module, DWORD size) {

        auto buffer       = std::make_unique<WCHAR[]>(size);
        auto const length = GetModuleFileNameExW(process, module, buffer.get(), size - 1);
        if (length == 0) {
            throw windows_exception();
        }

        if (length >= size) {
            buffer.reset();
            return get_module_filename(process, module, length + 1);
        }
        return {buffer.get()};
    }

    std::wstring process_module::get_name() const {
        WCHAR name[MAX_PATH + 1]{};
        if (auto const result = GetModuleBaseNameW(process_, module_, name, MAX_PATH); result == 0) {
            throw windows_exception();
        }

        return name;
    }

    std::wstring process_module::get_filename() const {
        return get_module_filename(process_, module_, MAX_PATH + 1);
    }

    process_module::process_module(native_process_handle_type process, native_module_handle_type module)
        : process_{process}, module_{module} {}


} // namespace modern_win32
