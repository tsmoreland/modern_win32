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

#include <modern_win32/threading/thread.h>
#include <modern_win32/module_handle.h>
#include <modern_win32/naive_stack_allocator.h>
#include <modern_win32/string.h>
#include <modern_win32/string_conversion.h>
#include <modern_win32/wait_for.h>

namespace modern_win32::threading
{

    thread::thread(std::unique_ptr<thread_start> worker)
        : handle_(thread_handle::invalid())
        , thread_start_(std::move(worker))
    {
        if (thread_start_ == nullptr)
            throw std::invalid_argument("provided thread_start is null");
    }
    thread::thread(modern_handle_type&& handle)
        : handle_(handle.release())
    {
    }
    thread::thread(native_handle_type const& handle /* = thread_handle::invalid() */)
        : handle_(handle)
    {
    }
    thread::thread(thread&& other) noexcept
        : handle_{other.handle_.release()}
        , thread_id_{other.thread_id_}
        , thread_start_(std::move(other.thread_start_))
    {
        other.thread_id_ = native_thread_id{};
    }

    bool thread::set_name(wchar_t const* name) const
    {
        if (!is_running())
            return false;
        return set_thread_name(handle_.native_handle(), name);
    }

    bool thread::set_name(char const* name) const
    {
        if (!is_running())
            return false;
        return set_thread_name(handle_.native_handle(), name);
    }

    std::optional<std::wstring> thread::get_name() const
    {
        if (!is_running())
            return std::nullopt;
        return get_thread_name(handle_.native_handle());
    }


    thread start_thread(thread::thread_proc const worker, thread::thread_parameter parameter)
    {
        thread new_thread;
        if (!new_thread.start(worker, parameter))
            throw windows_exception();
        return new_thread;
    }

    thread start_thread(thread_start* const worker)
    {
        thread new_thread;
        if (!new_thread.start(worker))
            throw windows_exception();
        return new_thread;
    }

    bool thread::start(thread_proc worker, thread_parameter parameter) 
    {
        if (is_running() || thread_start_ != nullptr)
            return false;
        return handle_.reset(CreateThread(nullptr, 0, worker, parameter, 0, &thread_id_));  // NOLINT(clang-diagnostic-microsoft-cast)
    }

    bool thread::start(thread_start* worker) 
    {
        if (is_running() || thread_start_ != nullptr)
            return false;

        return handle_.reset(CreateThread(nullptr, 0, thread_start::thread_proc, static_cast<thread_parameter>(worker), 0, &thread_id_));  // NOLINT(clang-diagnostic-microsoft-cast)
    }

    bool thread::start()
    {
        if (is_running() || thread_start_ == nullptr)
            return false;
        return handle_.reset(CreateThread(nullptr, 0, thread_start::thread_proc, thread_start_.get(), 0, &thread_id_));  // NOLINT(clang-diagnostic-microsoft-cast)
    }

    void thread::join() const
    {
        if (is_running())
            static_cast<void>(wait_one(handle_));
    }

    bool thread::join(std::chrono::milliseconds const& timeout) const
    {
        if (!is_running())
            return false;
        return is_complete(wait_one(handle_, timeout));
    }

    bool thread::is_running() const
    {
        if (!static_cast<bool>(handle_))
            return false;

        DWORD exit_code;
        if (GetExitCodeThread(handle_.native_handle(), &exit_code) != TRUE)
            throw windows_exception();
        return exit_code == STILL_ACTIVE;
    }

    thread& thread::operator=(thread&& other) noexcept 
    {
        if (this == &other)
            return *this;

        std::swap(*this, other);

        static_cast<void>(other.handle_.reset());
        other.thread_id_ = native_thread_id{};

        return *this;
    }

    void swap(thread& lhs, thread& rhs) noexcept
    {
        using std::swap;
        swap(lhs.handle_, rhs.handle_);
        swap(lhs.thread_id_, rhs.thread_id_);
        swap(lhs.thread_start_, rhs.thread_start_);
    }

    DWORD __stdcall thread::thread_adapter(void* state)
    {
        auto const worker = static_cast<thread_worker>(state);  // NOLINT(clang-diagnostic-microsoft-cast)
        if (worker == nullptr)
            return 1;
        worker();
        return 0;
    }

    bool set_thread_name(thread_handle::native_handle_type const handle, wchar_t const* name) 
    {
        using set_thread_description_delegate = HRESULT (WINAPI *)(HANDLE, PCWSTR);
        auto const maybe_kernel_base = get_module("KernelBase.dll");
        if (!maybe_kernel_base.has_value())
            return false;

        auto const& kernel_base = maybe_kernel_base.value();

        if (!static_cast<bool>(kernel_base))
            return false;

        auto const set_name_delegate = reinterpret_cast<set_thread_description_delegate>(GetProcAddress(kernel_base.native_handle(), "SetThreadDescription"));
        if (set_name_delegate == nullptr)
            return false;

        auto const hr = set_name_delegate(handle, name);
        return SUCCEEDED(hr);
    }

    bool set_thread_name(thread_handle::native_handle_type const handle, char const* name) 
    {
        auto const wide_name = convert::to_wstring(name);
        return set_thread_name(handle, wide_name.c_str());
    }

    std::optional<std::wstring> get_thread_name(thread_handle::native_handle_type const handle) 
    {
        using get_thread_description_delegate = HRESULT (WINAPI *)(HANDLE, PWSTR*);
        auto const maybe_kernel_base = get_module("KernelBase.dll");
        if (!maybe_kernel_base.has_value())
            return std::nullopt;

        auto const& kernel_base = maybe_kernel_base.value();
        auto const get_name_delegate = reinterpret_cast<get_thread_description_delegate>(GetProcAddress(kernel_base.native_handle(), "GetThreadDescription"));
        if (get_name_delegate == nullptr)
            return std::nullopt;

        PWSTR data{};
        if (auto const hr = get_name_delegate(handle, &data); SUCCEEDED(hr))
        {
            std::wstring name(data);
            LocalFree(data);
            return std::optional(name);
        }

        return std::nullopt;
    }

}