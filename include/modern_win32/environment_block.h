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

#ifndef MODERN_WIN32_ENVIRONMENT_BLOCK_H
#define MODERN_WIN32_ENVIRONMENT_BLOCK_H
#ifdef _WIN32


#include <modern_win32/environment_block_iterator.h>
#include <modern_win32/modern_win32_export.h>

namespace modern_win32 {

    class environment_block final {
    public:
        using native_environment_block = void*;
        using iterator = environment_block_iterator;

        /**
         * \brief Instantiates a new instance of environment_block with provided environment block
         * \param inherit_from_current_process if true then environment of current process is included in the block
         */
        MODERN_WIN32_EXPORT explicit environment_block(bool const inherit_from_current_process);

        /**
         * \brief Instantiates a new instance of environment_block with provided environment block
         * \param environment environment block provided by CreateEnvironmentBlock
         *                   cleanup of this block will be handled by this instance
         *                   cleanup of this block will be handled by this instance
         */
        constexpr explicit environment_block(native_environment_block&& environment) : environment_{environment} {}

        MODERN_WIN32_EXPORT ~environment_block();

        [[nodiscard]] constexpr auto native() const noexcept {
            return environment_;
        }

        /**
         * \return Iterator to the first element.
         */
        [[nodiscard]] MODERN_WIN32_EXPORT iterator begin() const noexcept;

        /**
         * \return Iterator to the element following the last element.
         */
        [[nodiscard]] MODERN_WIN32_EXPORT iterator end() const noexcept;

        /**
         * \brief swap the values of this and that
         */
        MODERN_WIN32_EXPORT void swap(environment_block& that) noexcept;

        environment_block(environment_block const&)            = delete;
        environment_block(environment_block&&)                 = default;
        environment_block& operator=(environment_block const&) = delete;
        environment_block& operator=(environment_block&&)      = default;

    private:
        native_environment_block environment_{nullptr};
    };

    MODERN_WIN32_EXPORT void swap(environment_block& lhs, environment_block& rhs) noexcept;

} // namespace modern_win32

#endif
#endif
