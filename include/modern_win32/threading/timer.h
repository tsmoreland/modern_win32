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

#ifndef MODERN_WIN32_THREADING_TIMER_
#define MODERN_WIN32_THREADING_TIMER_

#ifdef _WIN32

#include <Windows.h>
#include <modern_win32/modern_win32_export.h>
#include "modern_win32/null_handle.h"

namespace modern_win32::threading
{
    struct MODERN_WIN32_EXPORT timer_traits
    {
        using modern_handle_type = modern_win32::null_handle;
        using native_handle_type = modern_win32::null_handle::native_handle_type;


        [[nodiscard]]
        static auto create(bool manual_reset) -> native_handle_type;

        // start handled by SetWaitableTimer
        // stop handled by CancelWaitableTimer
    };

    template <bool MANUAL_RESET, class TIMER_CALLBACK, typename STATE, typename TRAITS=timer_traits>
    class timer final
    {
        using modern_handle_type = typename TRAITS::modern_handle_type;

        modern_handle_type handle_;
        TIMER_CALLBACK const& callback_;
        STATE& state_;
    public:

        explicit timer(TIMER_CALLBACK const& callback, STATE& state)
            : handle_{ TRAITS::create(MANUAL_RESET) }
            , callback_{ callback }
        {
        }

        timer(timer&& other) noexcept
            : handle_{ other.handle_.release() }
        {
        }
        timer& operator=(timer&& other) noexcept
        {
            if (&other == this) {
                return *this;
            }
            std::ignore = handle_.reset(other.handle_.release());

            return *this;
        }
        timer(timer const&) = delete;
        timer& operator=(timer const&) = delete;

    private:

        static void timer_proc(void* state, DWORD timer_low_value, DWORD timer_high_value)
        {
            auto* timer_object = static_cast<timer*>(state);
            if (timer_object == nullptr) {
                // ??? exception not ideal here but what else can we do?
            }

            timer_object->callback_(state_);
        }

    };

}


#endif
#endif