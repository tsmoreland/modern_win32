//
// Copyright (c) 2023 Terry Moreland
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

#ifndef MODERN_WIN32_WAIT_FOR_RESULT_H
#define MODERN_WIN32_WAIT_FOR_RESULT_H
#ifdef _WIN32

#include <Windows.h>

namespace modern_win32 {
    using wait_result = decltype(WaitForSingleObject(std::declval<HANDLE>(), std::declval<DWORD>()));

    enum class wait_for_result : wait_result {
        object        = WAIT_OBJECT_0,
        abandonded    = WAIT_ABANDONED,
        io_completion = WAIT_IO_COMPLETION,
        failed        = WAIT_FAILED,
        timeout       = WAIT_TIMEOUT,
    };

} // namespace modern_win32

#endif
#endif
