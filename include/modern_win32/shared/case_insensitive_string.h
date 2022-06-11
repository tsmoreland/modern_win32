//
// Copyright © 2021 Terry Moreland
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

#ifndef MODERN_WIN32_SHARED_CASE_INSENSITIVE_CHARACTER_TRAITS
#define MODERN_WIN32_SHARED_CASE_INSENSITIVE_CHARACTER_TRAITS 

#include <string>
#include <string_view>

namespace modern_win32::shared {
    template <typename TCHARACTER>
    class case_insensitive_char_traits : public std::char_traits<TCHARACTER> {
    public:
        [[nodiscard]] static bool eq(TCHARACTER const& left, TCHARACTER const& right) noexcept {
            return to_upper(left) == to_upper(right);
        }
        [[nodiscard]] static bool ne(TCHARACTER const& left, TCHARACTER const& right) noexcept {
            return to_upper(left) != to_upper(right);
        }

        [[nodiscard]] static bool lt(TCHARACTER const& left, TCHARACTER const& right) noexcept {
            return to_upper(left) < to_upper(right);
        }
        [[nodiscard]] static int compare(_In_reads_(count) TCHARACTER const* first1,
            _In_reads_(count) TCHARACTER const* first2, size_t count) noexcept {
            for (; 0 < count; --count, ++first1, ++first2) {
                auto const upper_first1 = to_upper(*first1);
                auto const upper_first2 = to_upper(*first2);
                if (upper_first1 != upper_first2) {
                    return upper_first1 < upper_first2 ? -1 : +1;
                }
            }

            return 0;
        }

        [[nodiscard]] static wchar_t const* find(
            _In_reads_(count) TCHARACTER const* first, const size_t count, TCHARACTER const& ch) noexcept {
            auto mutable_count = count;
            while (mutable_count-- > 0 && to_upper(*first) != to_upper(ch)) {
                ++first;
            }
            return first;
        }

    private:
        static int to_upper(int ch) {
            static_assert(
                !std::is_same_v<TCHARACTER,
                    char8_t> && !std::is_same_v<TCHARACTER, char16_t> && !std::is_same_v<TCHARACTER, char32_t>,
                "unicode strings not supported due to lack of toupper method");

            if constexpr (std::is_same_v<TCHARACTER, wchar_t>) {
                return static_cast<int>(towupper(static_cast<wint_t>(ch)));
            } else {
                return toupper(ch);
            }
        }
    };

    using case_insensitive_string  = std::basic_string<char, case_insensitive_char_traits<char>>;
    using case_insensitive_wstring = std::basic_string<wchar_t, case_insensitive_char_traits<wchar_t>>;

    using case_insensitive_string_view  = std::basic_string_view<char, case_insensitive_char_traits<char>>;
    using case_insensitive_wstring_view = std::basic_string_view<wchar_t, case_insensitive_char_traits<wchar_t>>;

} // namespace modern_win32::shared

#endif
