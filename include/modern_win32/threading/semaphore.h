//
// Copyright © 2021 Terry Moreland
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

#ifndef MODERN_WIN32_THREADING_SEMAPHORE_H_
#define MODERN_WIN32_THREADING_SEMAPHORE_H_

#ifdef _WIN32

#include <stdexcept>
#include <string>
#include <sstream>
#include <modern_win32/modern_win32_export.h>
#include <modern_win32/null_handle.h>
#include <modern_win32/wait_for.h>
#include <modern_win32/windows_exception.h>

namespace modern_win32::threading
{
    struct MODERN_WIN32_EXPORT semaphore_traits
    {
        using modern_handle_type = modern_win32::null_handle;
        using native_handle_type = modern_win32::null_handle::native_handle_type;

        [[nodiscard]]
        static auto create(int const initial_count, int const maximum_count) -> native_handle_type;

        [[nodiscard]]
        static auto release(modern_handle_type handle, int count) -> bool;
    };

    template <typename TRAITS = semaphore_traits>
    class semaphore final
    {
        using modern_handle_type = typename TRAITS::modern_handle_type;

        modern_handle_type handle_{};
        int maximum_count_;

    public:

        /// <summary>
        /// wait for event to be signaled
        /// </summary>
        /// <param name="timeout">
        /// The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the specified objects are signaled or the interval elapses.
        /// If  zero, the function does not enter a wait state if the specified objects are not signaled; it always returns immediately.
        /// If maximum value or maximum value of DWORD, the function will return only when the specified objects are signaled.
        /// </param>
        /// <returns>true if event was signaled; otherwise, false</returns>
        /// <exception cref="windows_exception">if wait fails</exception>
        [[nodiscard]]
        bool wait_one(std::chrono::milliseconds const timeout = get_infinity_in_ms()) const 
        {
            return is_complete(modern_win32::wait_one(handle_, timeout));
        }

        /// <summary>
        /// Increases the semaphore count by a specified amount.
        /// </summary>
        /// <param name="count">
        /// The amount by which the semaphore object's current count is to be increased. 
        /// The value must be greater than zero. If the specified amount would cause the 
        /// semaphore's count to exceed the maximum count that was specified when the 
        /// semaphore was created, the count is not changed and the function returns false
        /// </param>
        /// <exception cref="std::invalid_argument">
        /// if count is less than or equal to zero, or greater than maximum value
        /// </exception>
        void release(int count)
        {
            if (count <= 0 || count > maximum_count_) {
                throw std::invalid_argument((std::string("invalid count value") + std::to_string(count)).c_str());
            }

            if (!TRAITS::release(handle_.native_handle(), count)) {
                throw windows_exception();
            }
        }

        /// <summary>
        /// Swaps the values this and other.
        /// </summary>
        void swap(semaphore& other) noexcept
        {
            using std::swap;
            swap(handle_, other.handle_);
            swap(maximum_count_, other.maximum_count_);
        }

        /// <summary>
        /// Instantiates a new instance of the semaphore class.
        /// </summary>
        /// <param name="initial_count">
        /// The initial count for the semaphore object. This value must be 
        /// greater than or equal to zero and less than or equal to 
        /// maximum_count. The state of a semaphore is signaled when its 
        /// count is greater than zero and nonsignaled when it is zero. 
        /// The count is decreased by one whenever a wait function 
        /// releases a thread that was waiting for the semaphore
        /// </param>
        /// <param name="maximum_count">
        /// The maximum count for the semaphore object. This value must 
        /// be greater than zero.
        /// </param>
        /// <exception cref="std::invalid_argument">
        /// If initial_count is less than or equal to 0, or greater than maximum_count.
        /// If maximum_count is less than or equal to 0
        /// </exception>
        explicit semaphore(int const initial_count, int const maximum_count)
            : handle_{ TRAITS::create(initial_count, maximum_count) }
            , maximum_count_{ maximum_count }
        {
        }

        ~semaphore() = default;
        semaphore(semaphore&& other) noexcept
            : handle_{ other.handle_.release() }
            , maximum_count_{ other.maximum_count_ }
        {
            other.maximum_count_ = 0;
        }
        semaphore& operator=(semaphore&& other) noexcept
        {
            if (&other == this) {
                return *this;
            }

            std::ignore = handle_.reset(other.handle_.release());
            maximum_count_ = other.maximum_count_;

            other.maximum_count_ = 0;

            return *this;
        }
        semaphore(semaphore const&) = delete;
        semaphore& operator=(semaphore const&) = delete;

#       if __cplusplus > 201703L || _MSVC_LANG > 201703L
        [[nodiscard]]
        auto operator<=>(semaphore const& other)
        {
            return handle_ <=> other.handle_;
        }

#       else
        [[nodiscard]]
        bool operator<(semaphore const& other)
        {
            return handle_ < other.handle_;
        }

        [[nodiscard]]
        bool operator<=(semaphore const& other)
        {
            return !(other.handle_ < handle_);
        }

        [[nodiscard]]
        bool operator>(semaphore const& other)
        {
            return other.handle_ < handle_;
        }

        [[nodiscard]]
        bool operator>=(semaphore const& other)
        {
            return !(handle_ < other.handle_);
        }

        [[nodiscard]]
        bool operator==(semaphore const& other)
        {
            return handle_ == other.handle_;
        }

        [[nodiscard]]
        bool operator!=(semaphore const& other)
        {
            return !(handle_ == other.handle_);
        }
#       endif
    };

#   if __cplusplus > 201703L || _MSVC_LANG > 201703L 
    template <typename TRAITS = semaphore_traits>
    [[nodiscard]]
    auto operator<=>(semaphore<TRAITS> const& lhs, semaphore<TRAITS> const& rhs)
    {
        return lhs.operator<=>(rhs);
    }

#   else
    template <typename TRAITS = semaphore_traits>
    [[nodiscard]]
    bool operator<(semaphore<TRAITS> const& lhs, semaphore<TRAITS> const& rhs)
    {
        return lhs.operator<(rhs);
    }

    template <typename TRAITS = semaphore_traits>
    [[nodiscard]]
    bool operator<=(semaphore<TRAITS> const& lhs, semaphore<TRAITS> const& rhs)
    {
        return lhs.operator<=(rhs);
    }

    template <typename TRAITS = semaphore_traits>
    [[nodiscard]]
    bool operator>(semaphore<TRAITS> const& lhs, semaphore<TRAITS> const& rhs)
    {
        return lhs.operator>(rhs);
    }

    template <typename TRAITS = semaphore_traits>
    [[nodiscard]]
    bool operator>=(semaphore<TRAITS> const& lhs, semaphore<TRAITS> const& rhs)
    {
        return lhs.operator>=(rhs);
    }

    template <typename TRAITS = semaphore_traits>
    [[nodiscard]]
    bool operator==(semaphore<TRAITS> const& lhs, semaphore<TRAITS> const& rhs)
    {
        return lhs.operator==(rhs);
    }

    template <typename TRAITS = semaphore_traits>
    [[nodiscard]]
    bool operator!=(semaphore<TRAITS> const& lhs, semaphore<TRAITS> const& rhs)
    {
        return lhs.operator!=(rhs);
    }
#   endif

    /// <summary>
    /// Swaps the values lhs and rhs.
    /// </summary>
    template <typename TRAITS = semaphore_traits>
    void swap(semaphore<TRAITS>& lhs, semaphore<TRAITS>& rhs) noexcept
    {
        lhs.swap(rhs);
    }
}

#endif
#endif
