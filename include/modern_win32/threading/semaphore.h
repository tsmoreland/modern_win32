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
#include <Windows.h>
#include <modern_win32/null_handle.h>
#include <modern_win32/windows_exception.h>

namespace modern_win32::threading
{
    struct SEMAPHORE_TRAITS
    {
        using modern_handle_type = modern_win32::null_handle;

        static auto release(modern_handle_type handle, int count) 
        {
            return ReleaseSemaphore(handle.native_handle(), count, nullptr) == TRUE;
        }

        static auto get_error_details() 
        {
            return modern_win32::windows_error_details();
        }
    };

    template <typename TRAITS = SEMAPHORE_TRAITS>
    class semaphore final
    {
        using modern_handle_type = SEMAPHORE_TRAITS::modern_handle_type;

        modern_handle_type handle_{};
        int maximum_count_;

    public:

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
        explicit semaphore(int initial_count, int maximum_count)
            : handle_{ CreateSemaphoreA(nullptr, initial_count, maximum_count, nullptr) }
            , maximum_count_{ maximum_count }
        {
            if (static_cast<bool>(handle_)) {
                return;
            }

            windows_error_details const error = TRAITS::get_error_details();

            if (error.get() == windows_error::error_invalid_parameter) {
                std::stringstream builder{};
                builder << "Invalid arguments, either initial " << initial_count << " or maximum " << maximum_count << " count is out of range";
                throw std::invalid_argument(builder.str().c_str());
            }

            throw windows_exception(error.native_error_code());
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
            std::ignore = handle_.reset(other.handle_.release());
            maximum_count_ = other.maximum_count_;

            other.maximum_count_ = 0;

            return *this;
        }
        semaphore(semaphore const&) = delete;
        semaphore& operator=(semaphore const&) = delete;
    };
}

#endif
#endif
