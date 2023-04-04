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

#ifndef MODERN_WIN32_SHARED_WAIT_FOR_EXCEPTION_H
#define MODERN_WIN32_SHARED_WAIT_FOR_EXCEPTION_H

#if _WIN32

#include <exception>
#include <modern_win32/modern_win32_export.h>
#include <modern_win32/wait_for_result.h>

namespace modern_win32 {

    class wait_for_exception final : public std::exception {
        wait_for_result m_unexpected_result{};

    public:
        MODERN_WIN32_EXPORT explicit wait_for_exception();
        MODERN_WIN32_EXPORT explicit wait_for_exception(char const* message);
        MODERN_WIN32_EXPORT explicit wait_for_exception(wait_for_result const unexpected_result);
        MODERN_WIN32_EXPORT explicit wait_for_exception(wait_for_result const unexpected_result, char const* message);

        [[nodiscard]] constexpr wait_for_result unexpected_result() const noexcept {
            return m_unexpected_result;
        }
    }
} // namespace modern_win32


#endif
#endif