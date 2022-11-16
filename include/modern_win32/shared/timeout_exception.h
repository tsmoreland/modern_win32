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

#ifndef MODERN_WIN32_SHARED_TIMEOUT_EXCEPTION_H_
#define MODERN_WIN32_SHARED_TIMEOUT_EXCEPTION_H_

#include <chrono>
#include <exception>
#include <optional>

namespace modern_win32::shared {

    class timeout_exception : public std::exception {
        using base = std::exception;
        std::optional<std::chrono::milliseconds> timeout_{};

    public:
        /// <summary>
        /// Returns optional containing timeout if provided; otherwise nullopt
        /// </summary>
        /// <returns>optional containing timeout if provided; otherwise nullopt</returns>
        [[nodiscard]] constexpr decltype(timeout_) timeout() const noexcept {
            return timeout_;
        }


        template <class REP, class PERIOD>
        explicit timeout_exception() : base() {}
        template <class REP, class PERIOD>
        explicit timeout_exception(std::chrono::duration<REP, PERIOD> timeout)
            : base(), timeout_{std::optional(std::chrono::duration_cast<std::chrono::milliseconds>(timeout))} {}

        template <class REP, class PERIOD>
        explicit timeout_exception(char const* const message, std::chrono::duration<REP, PERIOD> timeout)
            : base(message), timeout_{std::optional(std::chrono::duration_cast<std::chrono::milliseconds>(timeout))} {}
    };

} // namespace modern_win32::shared

#endif
