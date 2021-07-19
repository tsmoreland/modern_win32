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
#include <Windows.h>
#include <modern_win32/null_handle.h>
#include <modern_win32/windows_exception.h>

namespace modern_win32::threading
{
    struct SEMAPHORE_TRAITS
    {
        using modern_handle_type = modern_win32::null_handle;
    };

    template <typename TRAITS = SEMAPHORE_TRAITS>
    class semaphore final
    {
        using modern_handle_type = SEMAPHORE_TRAITS::modern_handle_type;

        modern_handle_type semaphore_{};

    public:

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
        /// </exception
        explicit semaphore(int initial_count, int maximum_count)
            : semaphore_{ CreateSemaphoreA(nullptr, initial_count, maximum_count, nullptr) }
        {
            if (!static_cast<bool>(semaphore_)) {
                throw windows_exception();
            }
        }

        semaphore(semaphore const&) = delete;
        semaphore& operator=(semaphore const&) = delete;
    };
}

#endif
#endif
