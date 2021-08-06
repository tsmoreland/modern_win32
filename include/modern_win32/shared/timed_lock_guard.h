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

#ifndef MODERN_WIN32_SHARED_TIMED_LOCK_GUARD_H_
#define MODERN_WIN32_SHARED_TIMED_LOCK_GUARD_H_

#include <chrono>

namespace modern_win32::shared
{
    template <class MUTEX>
    class timed_lock_guard final
    {
        MUTEX& mutex_;
        bool locked_{ false };
    public:
        using mutext_type = MUTEX;

        /// <summary>
        /// Checks whether *this owns a locked mutex or not.
        /// </summary>
        /// <returns>true if *this has an associated mutex and has acquired shared ownership of it, false otherwise.</returns>
        [[nodiscard]]
        constexpr bool owns_lock() const noexcept
        {
            return locked_;
        }

        template <class REP, class PERIOD>
        explicit timed_lock_guard(MUTEX& mutex, std::chrono::duration<REP, PERIOD> timeout)
            : mutex_{ mutex }
            , locked_{ mutex.try_lock_for(timeout) }
        {
        }
        ~timed_lock_guard()
        {
            if (locked_) {
                mutex_.unlock();
            }
        }
        timed_lock_guard(timed_lock_guard const&) = delete;
        timed_lock_guard(timed_lock_guard &&) noexcept = delete;
        timed_lock_guard& operator=(timed_lock_guard const&) = delete;
        timed_lock_guard& operator=(timed_lock_guard &&) noexcept = delete;


    };

}

#endif