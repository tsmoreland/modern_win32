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

#include <modern_win32/threading/semaphore.h>
#include <modern_win32/windows_exception.h>

namespace modern_win32::threading
{
    auto semaphore_traits::create(int const initial_count, int const maximum_count) -> native_handle_type
    {
        auto const handle = CreateSemaphoreA(nullptr, initial_count, maximum_count, nullptr);

        if (handle != nullptr) {
            return handle;
        }

        windows_error_details const error = modern_win32::windows_error_details();

        if (error.get() == windows_error::error_invalid_parameter) {

            std::stringstream builder{};
            builder << "Invalid arguments, either initial " << initial_count << " or maximum " << maximum_count << " count is out of range";
            throw std::invalid_argument(builder.str().c_str());
        }

        throw windows_exception(error.native_error_code());
    }

    auto semaphore_traits::release(modern_handle_type handle, int count) -> bool
    {
        return ReleaseSemaphore(handle.native_handle(), count, nullptr) == TRUE;
    }
}
