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

#include <modern_win32/threading/slim_lock.h>

namespace modern_win32::threading
{

slim_lock::slim_lock() 
{
    InitializeSRWLock(&m_lock);
}

slim_lock::slim_lock(slim_lock&& other) noexcept 
    : m_lock(other.m_lock)
{
    InitializeSRWLock(&other.m_lock);
}

void slim_lock::lock() noexcept
{
    AcquireSRWLockExclusive(&m_lock);
}

bool slim_lock::try_lock() noexcept
{
    return TryAcquireSRWLockExclusive(&m_lock) != 0;
}

void slim_lock::unlock() noexcept
{
    ReleaseSRWLockExclusive(&m_lock);
}
void slim_lock::lock_shared() noexcept
{
    AcquireSRWLockShared(&m_lock);
}
bool slim_lock::try_lock_shared() noexcept
{
    return TryAcquireSRWLockShared(&m_lock) != 0;
}
void slim_lock::unlock_shared() noexcept
{
    ReleaseSRWLockShared(&m_lock);
}

slim_lock::native_handle_type slim_lock::native_handle() noexcept
{
    return &m_lock;
}

slim_lock& slim_lock::operator=(slim_lock&& other) noexcept 
{
    if (this == &other)
        return *this;

    unlock();
    unlock_shared();

    m_lock = other.m_lock;
    
    other.m_lock = SRWLOCK{};
    InitializeSRWLock(&other.m_lock);

    return *this;
}

}