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

#ifndef MODERN_WIN32_NAIVE_STACK_ALLOCATOR_
#define MODERN_WIN32_NAIVE_STACK_ALLOCATOR_

#include <memory>
#include <type_traits>

namespace modern_win32
{
    template <class TYPE>
    constexpr std::size_t calculate_capacity()
    {
        // assuming 2048 bytes capacity
        return 2048 / sizeof(TYPE);
    }

    template <class TYPE, size_t CAPACITY = calculate_capacity<TYPE>()>
    class naive_stack_allocator final
    {
    public:
        static_assert(!std::is_const_v<TYPE>, 
            "The C++ Standard forbids containers of const elements "
            "because allocator<const T> is ill-formed.");

        //static constexpr std::size_t CAPACITY = calculate_capacity<TYPE>();
        using value_type = TYPE;

        explicit naive_stack_allocator() noexcept
            : allocator_(std::allocator<TYPE>())
        {
        }
        template <class ALTERNATE_TYPE>
        explicit naive_stack_allocator (naive_stack_allocator<ALTERNATE_TYPE, CAPACITY> const&) noexcept
        {
        }

        [[nodiscard]]
        TYPE* allocate(std::size_t const size)
        {
            if (size == 0)
                return nullptr;

            if (size > CAPACITY || position_ + size > CAPACITY)
                return allocator_.allocate(size);

            auto* result = &buffer_[position_];
            position_ += size;
            return result;
        }
        void deallocate(TYPE* const value_ptr, std::size_t size)
        {
            if (value_ptr >= buffer_ + CAPACITY || value_ptr < buffer_)
                allocator_.deallocate(value_ptr, size);
        }

        template<class OTHER>
        struct rebind
        {
            using other = naive_stack_allocator<OTHER, CAPACITY>;
        };

    private:
        TYPE buffer_[CAPACITY]{};
        std::allocator<TYPE> allocator_;
        std::size_t position_{};
    };

    template <class T, class U, size_t CAPACITY>
    constexpr bool operator== (const naive_stack_allocator<T, CAPACITY>&, const naive_stack_allocator<U, CAPACITY>&) noexcept
    {
        return true;
    }

    template <class T, class U, size_t CAPACITY>
    constexpr bool operator!= (const naive_stack_allocator<T, CAPACITY>&, const naive_stack_allocator<U, CAPACITY>&) noexcept
    {
        return false;
    }

    template <typename TCHAR>
    using naive_basic_string = std::basic_string<TCHAR, std::char_traits<TCHAR>, naive_stack_allocator<TCHAR, 64>>;
    using naive_string = naive_basic_string<char>;
    using naive_wstring = naive_basic_string<wchar_t>;

}

#endif