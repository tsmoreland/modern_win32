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

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <modern_win32/environment_block.h>
#include <modern_win32/environment_block_iterator.h>

namespace modern_win32 {

    constexpr auto max_index = 65'535;
    auto const* g_empty_string = L"";


    environment_block_iterator::environment_block_iterator(environment_block const& container) : index_{0} {
        if (auto const* start = static_cast<wchar_t const*>(container.native()); *start == L'\0' && *(start + 1) == L'\0') {
            index_ = max_index;
        } else {
            value_ = std::wstring_view(start);
        }
    }

    environment_block_iterator::environment_block_iterator() : index_{max_index} {
    }

    environment_block_iterator::environment_block_iterator(int index, environment_block_iterator::difference_type increment_by, std::wstring_view value)
        : index_{index}, value_{value} {

        while (increment_by-- > 0) {
            iterate_to_next();
        }
    }


    environment_block_iterator& environment_block_iterator::operator++() {
        iterate_to_next();
        return *this;
    }

    environment_block_iterator environment_block_iterator::operator++(int) {
        iterate_to_next();
        return *this;
    }

    environment_block_iterator& environment_block_iterator::operator+=(int i) {
        while (i-- > 0) {
            iterate_to_next();
        }
        return *this;
    }

    environment_block_iterator::difference_type environment_block_iterator::operator+(
        environment_block_iterator const& other) const {

        return index_ + other.index_;
    }

    environment_block_iterator environment_block_iterator::operator+(difference_type const other) const {
        return environment_block_iterator(index_, other, value_);
    }

    bool environment_block_iterator::operator==(environment_block_iterator const& other) const noexcept {
        if (index_ == other.index_ && index_ == max_index) {
            return true;
        } 

        return index_ == other.index_ && value_.data() == other.value_.data();
    }
    bool environment_block_iterator::operator!=(environment_block_iterator const& other) const noexcept {
        return !operator==(other);
    }


    bool environment_block_iterator::has_next() const {
        if (index_ == max_index) {
            return false;
        }

        // environment block ends with 2 nul characters
        auto const* start = value_.data() + value_.size();
        return *(start + 1) != L'\0';
    }

    void environment_block_iterator::iterate_to_next() {
        if (!has_next()) {
            index_ = max_index;
            value_ = g_empty_string;
            return;
        }
        index_++;
        auto const* start = value_.data() + value_.size();
        value_ = std::wstring_view(start + 1); 
    }

    environment_block_iterator operator+(environment_block_iterator::difference_type const value,
        environment_block_iterator const& other) {

        return other + value;
    }
} // namespace modern_win32
