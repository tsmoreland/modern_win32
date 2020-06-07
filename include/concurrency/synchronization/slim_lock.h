//
// Copyright � 2020 Terry Moreland
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

#ifndef __SLIM_LOCK_H__
#define __SLIM_LOCK_H__

#ifdef _WIN32

#include <Windows.h>
#include <synchapi.h>

#else

#endif

#include <algorithm>
#include <optional>
#include <shared_mutex>

namespace moreland::concurrency::synchronization
{

    template <typename LOCK>
    class lock_guard final
    {
        using unlock_action = void (LOCK::*)();
    public:
        explicit lock_guard(LOCK* lock, unlock_action const unlock)
            : m_lock(lock)
            , m_unlock(unlock)
        {
        }
        lock_guard(lock_guard const&) = delete;
        lock_guard(lock_guard&& other) noexcept
            : m_lock{other.m_lock}
            , m_unlock{other.m_unlock}
        {
            other.m_lock = nullptr;
            other.m_unlock = nullptr;
        }
        ~lock_guard() 
        {
            if (m_lock != nullptr && m_unlock != nullptr)
                (m_lock->*m_unlock)();
        }

        lock_guard& operator=(lock_guard const&) = delete;
        lock_guard& operator=(lock_guard&& other) = delete;

    private:
        LOCK* m_lock;
        unlock_action m_unlock;
    };

#ifdef _WIN32

    class slim_lock final
    {
    public:
        explicit slim_lock() 
        {
            InitializeSRWLock(&m_lock);
        }
        slim_lock(slim_lock const&) = delete;
        slim_lock(slim_lock&&) noexcept = delete;
        ~slim_lock() = default;

        [[nodiscard]] SRWLOCK const& get_value() const noexcept
        {
            return m_lock;
        }
        lock_guard<slim_lock> enter_write_lock()
        {
            enter_exclusive_lock();
            return lock_guard<slim_lock>(this, &slim_lock::exit_exclusive_lock);
        }
        lock_guard<slim_lock> enter_read_lock()
        {
            enter_shared_lock();
            return lock_guard<slim_lock>(this, &slim_lock::exit_shared_lock);
        }

        std::optional<lock_guard<slim_lock>> try_enter_write_lock()
        {
            return try_enter_exclusive_lock()
                ? std::optional<lock_guard<slim_lock>>(std::in_place, this, &slim_lock::exit_exclusive_lock)
                : std::nullopt;
        }
        std::optional<lock_guard<slim_lock>> try_enter_read_lock()
        {
            return (try_enter_shared_lock())
                ? std::optional<lock_guard<slim_lock>>(std::in_place, this, &slim_lock::exit_shared_lock)
                : std::nullopt;
        }

        slim_lock& operator=(slim_lock const&) = delete;
        slim_lock& operator=(slim_lock&&) noexcept = delete;
    private:
        SRWLOCK m_lock{};

        void enter_exclusive_lock() noexcept
        {
            AcquireSRWLockExclusive(&m_lock);
        }
        void exit_exclusive_lock() noexcept
        {
            ReleaseSRWLockExclusive(&m_lock);
        }
        void enter_shared_lock() noexcept
        {
            AcquireSRWLockShared(&m_lock);
        }
        void exit_shared_lock() noexcept
        {
            ReleaseSRWLockShared(&m_lock);
        }
        bool try_enter_exclusive_lock() noexcept
        {
            return TryAcquireSRWLockExclusive(&m_lock) == TRUE;
        }
        bool try_enter_shared_lock() noexcept
        {
            return TryAcquireSRWLockShared(&m_lock) == TRUE;
        }
    };

#else
    class slim_lock final 
    {
    public:
        [[nodiscard]] std::shared_timed_mutex const& get_value() const noexcept
        {
            return m_mutex;
        }
        lock_guard<slim_lock> enter_write_lock()
        {
            m_mutex.lock();
            return lock_guard<slim_lock>(this, &slim_lock::exit_exclusive_lock);
        }
        lock_guard<slim_lock> enter_read_lock()
        {
            m_mutex.lock_shared();
            return lock_guard<slim_lock>(this, &slim_lock::exit_shared_lock);
        }
        std::optional<lock_guard<slim_lock>> try_enter_write_lock()
        {
            return m_mutex.try_lock()
                ? std::optional<lock_guard<slim_lock>>(std::in_place, this, &slim_lock::exit_exclusive_lock)
                : std::nullopt;
        }
        std::optional<lock_guard<slim_lock>> try_enter_read_lock()
        {
            return m_mutex.try_lock_shared()
                ? std::optional<lock_guard<slim_lock>>(std::in_place, this, &slim_lock::exit_shared_lock)
                : std::nullopt;
        }


    private:
        std::shared_timed_mutex m_mutex{};

        void exit_exclusive_lock() noexcept
        {
            m_mutex.unlock();
        }
        void exit_shared_lock() noexcept
        {
            m_mutex.unlock_shared();
        }
    };
#endif


}
#endif
