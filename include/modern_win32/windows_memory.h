//
// Copyright (c) 2022 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//


#ifndef MODERN_WIN32_WINDOWS_MEMORY_H_
#define MODERN_WIN32_WINDOWS_MEMORY_H_ // NOLINT(clang-diagnostic-unused-macros)
#ifdef _WIN32

#include <memory>

#include <Windows.h>

namespace modern_win32 {

    /// <summary>
    /// custom deleter used with unique_heap_ptr
    /// </summary>
    struct heap_deleter final {
        /// <summary>
        /// release memory used by resource
        /// </summary>
        /// <param name="resource">the resource to release</param>
        inline void operator()(void* resource) const {
            if (resource) {
                HeapFree(GetProcessHeap(), 0, resource);
            }
        }
    };

    /// <summary>
    /// extended unique_ptr using HeapAlloc and HeapFree to allocate memory for
    /// primitive types
    /// </summary>
    /// <typeparam name="T">primitive type to allocate for</typeparam>
    template <typename T>
    class unique_heap_ptr final : public std::unique_ptr<T, heap_deleter> {
        using base = std::unique_ptr<T, heap_deleter>;

    public:
        constexpr explicit unique_heap_ptr() = default;
        explicit unique_heap_ptr(SIZE_T size) : base(static_cast<T*>(HeapAlloc(GetProcessHeap(), 0, size))) {}
    };

    /// <summary>
    /// extended unique_ptr using HeapAlloc and HeapFree to allocate memory for
    /// primitive types
    /// </summary>
    /// <typeparam name="T">primitive type to allocate for</typeparam>
    template <class T>
    class unique_heap_array final : public std::unique_ptr<T[], heap_deleter> {
        using base = std::unique_ptr<T[], heap_deleter>;

    public:
        constexpr explicit unique_heap_array() = default;

        /// <summary>
        /// allocates count number of T items using HeapAlloc
        /// </summary>
        /// <param name="count">number of items to allocate</param>
        /// <remarks>total allocation size will be count * sizeof(T)</remarks>
        explicit unique_heap_array(SIZE_T count)
            : base(static_cast<T*>(HeapAlloc(GetProcessHeap(), 0, count * sizeof(T)))) {}
    };
} // namespace modern_win32


#endif
#endif
