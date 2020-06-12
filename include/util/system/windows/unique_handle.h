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

#ifndef __UTIL_SYSTEM_WINDOWS_UNIQUE_HANDLE_H__
#define __UTIL_SYSTEM_WINDOWS_UNIQUE_HANDLE_H__
#include <tuple>
#include <utility>

namespace util::system::windows
{
    /// <summary>
    /// C++ wrapper around Win32 HANDLE using template TRAITS to handle specific behaviour with regard to close and invalid value
    /// </summary>
    /// <typeparam name="TRAITS">template traits used to determine invalid/closed value and close method</typeparam>
    template <typename TRAITS>
    class unique_handle final
    {
        using native_handle_type = typename TRAITS::native_handle_type;
    public:
        explicit unique_handle(native_handle_type handle = TRAITS::invalid())
            : m_handle(handle)
        {
        }
        unique_handle(unique_handle const&) = delete;
        unique_handle(unique_handle&& other) noexcept
            : m_handle(other.release())
        {
            static_cast<void>(other.reset());
        }
        ~unique_handle()
        {
            close();
        }
        /// <summary>
        /// returns the underlying native handle value, misuse of the value such
        /// as closing the handle could lead to undefined behaviour
        /// </summary>
        /// <returns>native handle type</returns>
        [[nodiscard]] native_handle_type get() const noexcept
        {
            return m_handle;
        }

        /// <summary>
        /// releases the current handle, it will be the callers responsibility to close the handle if open
        /// </summary>
        [[nodiscard]] native_handle_type release() noexcept
        {
            auto const handle = m_handle;
            static_cast<void>(reset());
            return handle;
        }
        /// <summary>
        /// resets the handle to value to the provided value closing the existing handle if open
        /// </summary>
        /// <returns>true if handle is open</returns>
        [[nodiscard]] bool reset(native_handle_type handle = TRAITS::invalid()) noexcept
        {
            if (m_handle == handle)
                return static_cast<bool>(*this);

            if (m_handle != TRAITS::invalid())
                close();
            m_handle = handle;
            return static_cast<bool>(*this);
        }

		/// <summary>
		/// swaps the values of the current object and other
		/// </summary>
		void swap(unique_handle<TRAITS>& other) noexcept
		{
			std::swap(m_handle, other.m_handle);
		}

        [[nodiscard]] explicit operator bool() const noexcept
        {
            return m_handle != TRAITS::invalid();
        }

#       if __cplusplus > 201703L || _MSVC_LANG > 201703L
        [[nodiscard]] auto operator<=>(unique_handle const& other) noexcept
        {
            return m_handle <=> other.m_handle;
        }
#       else
        [[nodicsard]] bool operator==(unique_handle const& other)
        {
            return m_handle == other.m_handle;
        }
        [[nodicsard]] bool operator!=( unique_handle const& other)
        {
            return !(*this == other);
        }
        [[nodicsard]] bool operator<(unique_handle const& other)
        {
            return m_handle < other.m_handle;
        }
        [[nodicsard]] bool operator>(unique_handle const& other)
        {
            return m_handle > other.m_handle;
        }
        [[nodicsard]] bool operator<=(unique_handle const& other)
        {
            return m_handle <= other.m_handle;
        }
        [[nodicsard]] bool operator>=(unique_handle const& other)
        {
            return m_handle >= other.m_handle;
        }

#       endif

        unique_handle& operator=(unique_handle const& other) = delete;
        unique_handle& operator=(unique_handle&& other) noexcept
        {
            if (this == &other)
                return *this;
            static_cast<void>(reset(other.release()));
            return *this;
        }
    private:
        native_handle_type m_handle;

        /// <summary>
        /// closes the current handle if open
        /// </summary>
        void close() noexcept
        {
            if (*this) 
                TRAITS::close(m_handle);
        }
    };

    /// <summary>
    /// swaps the values of the lhs and rhs 
    /// </summary>
    template <typename TRAITS>
	void swap(unique_handle<TRAITS>& lhs, unique_handle<TRAITS>& rhs) noexcept
	{
		lhs.swap(rhs);
	}

#   if __cplusplus > 201703L || _MSVC_LANG > 201703L

    template <typename TRAITS>
    [[nodiscard]] auto operator<=>(unique_handle<TRAITS> const& lhs, unique_handle<TRAITS> const& rhs)
    {
        return lhs.get() <=> rhs.get();
    }

#   else

    template <typename TRAITS>
    [[nodicsard]] bool operator==(unique_handle<TRAITS> const& lhs, unique_handle<TRAITS> const& rhs)
    {
        return lhs.get() == rhs.get()
    }

    template <typename TRAITS>
    [[nodicsard]] bool operator!=(unique_handle<TRAITS> const& lhs, unique_handle<TRAITS> const& rhs)
    {
        return !(lhs.get() == rhs.get());
    }
    template <typename TRAITS>
    [[nodicsard]] bool operator<(unique_handle<TRAITS> const& lhs, unique_handle<TRAITS> const& rhs)
    {
        return lhs.get() < rhs.get();
    }
    template <typename TRAITS>
    [[nodicsard]] bool operator>(unique_handle<TRAITS> const& lhs, unique_handle<TRAITS> const& rhs)
    {
        return lhs.get() > rhs.get();
    }
    template <typename TRAITS>
    [[nodicsard]] bool operator<=(unique_handle<TRAITS> const& lhs, unique_handle<TRAITS> const& rhs)
    {
        return lhs.get() <= rhs.get();
    }
    template <typename TRAITS>
    [[nodicsard]] bool operator>=(unique_handle<TRAITS> const& lhs, unique_handle<TRAITS> const& rhs)
    {
        return lhs.get() >= rhs.get();
    }
#   endif

}

#endif