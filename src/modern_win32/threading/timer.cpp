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

#include <modern_win32/threading/timer.h>
#include <modern_win32/windows_exception.h>

namespace modern_win32::threading
{
    auto timer_traits::create(bool manual_reset) -> native_handle_type
    {
        auto const handle = CreateWaitableTimerW(nullptr, manual_reset ? TRUE : FALSE, nullptr);
        if (handle == nullptr) {
            throw windows_exception();
        }
        return handle;
    }

    auto timer_traits::set_waitable_timer(
            native_handle_type handle,
            LARGE_INTEGER& due_time,
            LONG period,
            _In_opt_ PTIMERAPCROUTINE callback,
            void *state,
            bool const restore) -> bool
    {
        return SetWaitableTimer(handle, &due_time, period, callback, state, restore ? TRUE : FALSE) == TRUE;
    }

    bool timer_traits::cancel_waitable_timer(native_handle_type handle)
    {
        return CancelWaitableTimer(handle) == TRUE;
    }
}
