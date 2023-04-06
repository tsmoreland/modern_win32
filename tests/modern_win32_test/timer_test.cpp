//
// Copyright (c) 2022 Terry Moreland
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

#include "timer_test.h"


namespace modern_win32::test
{

    constexpr auto get_default_create_result() -> fake_timer_traits::native_handle_type
    {
        return static_cast<fake_timer_traits::native_handle_type>(3);
    }
    constexpr auto get_default_set_waitable_timer_result(fake_timer_traits::native_handle_type , LARGE_INTEGER&, LONG, PTIMERAPCROUTINE, void*, bool const)
        -> bool
    {
        return true;
    }
    constexpr auto get_default_cancel_waitable_timer_result(fake_timer_traits::native_handle_type) -> bool
    {
        return true;
    }


    std::function<int()> fake_timer_traits::get_create_result_ = get_default_create_result;  // NOLINT(clang-diagnostic-exit-time-destructors)
    fake_timer_traits::set_waitable_timer_type fake_timer_traits::get_set_waitable_timer_result_ = get_default_set_waitable_timer_result; // NOLINT(clang-diagnostic-exit-time-destructors)
    fake_timer_traits::cancel_waitable_timer_type fake_timer_traits::get_cancel_waitable_timer_result_ = get_default_cancel_waitable_timer_result; // NOLINT(clang-diagnostic-exit-time-destructors)

    int fake_timer_traits::create_call_count_ = 0;
    int fake_timer_traits::cancel_waitable_timer_call_count_ = 0;
    int fake_timer_traits::set_waitable_timer_call_count_ = 0;

    auto fake_timer_traits::set_waitable_timer(native_handle_type handle, LARGE_INTEGER& due_time,
        LONG period, _In_opt_ PTIMERAPCROUTINE callback, void* state, bool const restore)
        -> bool
    {
        set_waitable_timer_call_count_++;
        return get_set_waitable_timer_result_(handle, due_time, period, callback, state, restore);
    }

    auto fake_timer_traits::cancel_waitable_timer(native_handle_type handle) -> bool
    {
        cancel_waitable_timer_call_count_++;
        return get_cancel_waitable_timer_result_(handle);
    }

    void fake_timer_traits::reset()
    {
        get_create_result_ = get_default_create_result;  // NOLINT(clang-diagnostic-exit-time-destructors)
        get_set_waitable_timer_result_ = get_default_set_waitable_timer_result; // NOLINT(clang-diagnostic-exit-time-destructors)
        get_cancel_waitable_timer_result_ = get_default_cancel_waitable_timer_result; // NOLINT(clang-diagnostic-exit-time-destructors)
        create_call_count_ = 0;
        cancel_waitable_timer_call_count_ = 0;
        set_waitable_timer_call_count_ = 0;
    }
}
