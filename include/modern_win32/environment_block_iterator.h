//
// Copyright (c) 2023 Terry Moreland
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

#ifndef MODERN_WIN32_ENVIRONMENT_BLOCK_ITERATOR_H
#define MODERN_WIN32_ENVIRONMENT_BLOCK_ITERATOR_H
#ifdef _WIN32

#include <iterator>
#include <modern_win32/modern_win32_export.h>
#include <string_view>

namespace modern_win32 {

    class environment_block;

    /**
     * \brief environment_block iterated, used to view environement variables present in the block
     */
    class environment_block_iterator final {
        int index_;
        std::wstring_view value_{};

    public:
        using iterator_concept [[maybe_unused]] = std::forward_iterator_tag;
        using difference_type                   = int;
        using value_type                        = std::wstring_view const;
        using pointer                           = value_type*;
        using reference                         = value_type&;

        /**
         * \brief instantiates a new iterator for container starting at index 0
         * \param container the container being interated
         */
        MODERN_WIN32_EXPORT explicit environment_block_iterator(environment_block const& container);

        /**
         * \brief instantiates the end iterator using index to identify it
         */
        MODERN_WIN32_EXPORT explicit environment_block_iterator();

        /**
         * \brief return the current value or empty
         * \return current value or empty string
         */
        constexpr reference operator*() const {
            return value_;
        }

        /**
         * \brief return reference to current value or empty
         * \return reference to current value or empty string
         */
        constexpr pointer operator->() const {
            return &value_;
        }

        /**
         * \brief pre-fix increment the iterator (++i)
         * \return incremented iterator
         */
        MODERN_WIN32_EXPORT environment_block_iterator& operator++();
        /**
         * \brief post-fix increment the iterator (i++)
         * \return  current iterator prior to update)
         */
        MODERN_WIN32_EXPORT environment_block_iterator& operator++(int);
        MODERN_WIN32_EXPORT environment_block_iterator& operator+=(int i);

        MODERN_WIN32_EXPORT difference_type operator+(environment_block_iterator const& other) const;
        MODERN_WIN32_EXPORT environment_block_iterator operator+(difference_type const other) const;
        MODERN_WIN32_EXPORT friend environment_block_iterator operator+(difference_type const value, environment_block_iterator const& other);

        MODERN_WIN32_EXPORT bool operator==(environment_block_iterator const& other) const noexcept;
        MODERN_WIN32_EXPORT bool operator!=(environment_block_iterator const& other) const noexcept;
        auto operator<=>(environment_block_iterator const& other) const {
            return index_ <=> other.index_;
        }

    private:
        explicit environment_block_iterator(int index, difference_type increment_by, std::wstring_view value);

        [[nodiscard]] bool has_next() const;
        void iterate_to_next();
    };

} // namespace modern_win32


#endif
#endif
