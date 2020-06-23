//
// Copyright © 2020 Terry Moreland
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

#ifndef __MODERN_WIN32_CONCURRENCY_SYNCHRONIZATION_SLIM_LOCK_H__
#define __MODERN_WIN32_CONCURRENCY_SYNCHRONIZATION_SLIM_LOCK_H__

#ifdef _WIN32

#include <Windows.h>
#include <synchapi.h>

#endif

#include <shared_mutex>

namespace modern_win32::threading
{

#ifdef _WIN32

    /// <summary>
    /// modern C++ wrapper around SRWLOCK intended to mirror std::shared_mutex such that it be used by both
    /// std::lock_guard and std::shared_lock to provide RAII release of the lock
    /// </summary>
    class slim_lock final
    {
        using native_handle_type = PSRWLOCK;

    public:
        explicit slim_lock() 
        {
            InitializeSRWLock(&m_lock);
        }
        slim_lock(slim_lock const&) = delete;
        slim_lock(slim_lock&& other) noexcept 
            : m_lock(other.m_lock)
        {
            other.m_lock = SRWLOCK{};
            InitializeSRWLock(&other.m_lock);
        }
        ~slim_lock() noexcept = default;

        /// <summary>
        /// Acquires a slim reader/writer (SRW) lock in exclusive mode.
        /// </summary>
        void lock() noexcept
        {
            AcquireSRWLockExclusive(&m_lock);
        }
        /// <summary>
        /// Attempts to acquire a slim reader/writer (SRW) lock in exclusive mode. If the call is successful, the calling thread takes ownership of the lock.
        /// </summary>
        /// <returns>true if lock has been obtained; otherwise, false</returns>
        [[nodiscard]] bool try_lock() noexcept
        {
            return TryAcquireSRWLockExclusive(&m_lock) != 0;
        }
        /// <summary>
        /// Releases an SRW lock that was opened in exclusive mode.
        /// </summary>
        void unlock() noexcept
        {
            ReleaseSRWLockExclusive(&m_lock);
        }
        /// <summary>
        /// Acquires an SRW lock in shared mode.
        /// </summary>
        void lock_shared() noexcept
        {
            AcquireSRWLockShared(&m_lock);
        }
        /// <summary>
        /// Attempts to acquire a slim reader/writer (SRW) lock in shared mode. If the call is successful, the calling thread takes ownership of the lock.
        /// </summary>
        /// <returns>true if lock has been obtained; otherwise, false</returns>
        [[nodiscard]] bool try_lock_shared() noexcept
        {
            return TryAcquireSRWLockShared(&m_lock) != 0;
        }
        /// <summary>
        /// Releases an SRW lock that was opened in shared mode.
        /// </summary>
        /// <returns></returns>
        void unlock_shared() noexcept
        {
            ReleaseSRWLockShared(&m_lock);
        }

        /// <summary>
        /// returns the underlying implementation-defined native handle object
        /// </summary>
        [[nodiscard]] native_handle_type native_handle() noexcept
        {
            return &m_lock;
        }

        slim_lock& operator=(slim_lock const&) = delete;
        slim_lock& operator=(slim_lock&& other) noexcept 
        {
            if (this == &other)
                return *this;

            // TODO: add method to check if locked and unlock appropriate type, this may be handled along with recursive support
            unlock();
            unlock_shared();

            m_lock = other.m_lock;
            
            other.m_lock = SRWLOCK{};
            InitializeSRWLock(&other.m_lock);

            return *this;
        }
    private:
        SRWLOCK m_lock{};
    };

#else

    using slim_lock = std::shared_mutex;

#endif

    using shared_slim_lock = std::shared_lock<slim_lock>;
    using unique_slim_lock = std::unique_lock<slim_lock>;
    using slim_lock_guard = std::lock_guard<slim_lock>;

}

#endif
