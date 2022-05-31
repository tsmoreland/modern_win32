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

#ifndef MODERN_WIN32_GUID_H_
#define MODERN_WIN32_GUID_H_
#include <ostream>
#ifdef _WIN32

#include <modern_win32/modern_win32_export.h>
#include <string_view>

#include <Windows.h>

namespace modern_win32 {
    class MODERN_WIN32_EXPORT guid final {
    public:
        explicit guid();
        explicit guid(GUID const& value) noexcept;
        explicit guid(char const* value);
        explicit guid(wchar_t const* value);

        [[nodiscard]] GUID get() const noexcept;

        static guid& zero();

        void swap(guid& other) noexcept;
        MODERN_WIN32_EXPORT friend bool operator==(guid const& left, guid const& right) noexcept;
        MODERN_WIN32_EXPORT friend bool operator!=(guid const& left, guid const& right) noexcept;

        MODERN_WIN32_EXPORT friend bool operator==(GUID const& left, guid const& right) noexcept;
        MODERN_WIN32_EXPORT friend bool operator!=(GUID const& left, guid const& right) noexcept;

        MODERN_WIN32_EXPORT friend bool operator==(guid const& left, GUID const& right) noexcept;
        MODERN_WIN32_EXPORT friend bool operator!=(guid const& left, GUID const& right) noexcept;

        MODERN_WIN32_EXPORT friend std::ostream& operator<<(std::ostream& os, const guid& obj);

        explicit operator GUID() const {
            return value_;
        }
        explicit operator bool() const {
            return *this != zero();
        }
        [[nodiscard]] constexpr bool empty() const {
            return static_cast<bool>(this);
        }

    private:
        GUID value_{};
    };

    [[nodiscard]] MODERN_WIN32_EXPORT std::string to_string(guid const& uid);
    [[nodiscard]] MODERN_WIN32_EXPORT std::wstring to_wstring(guid const& uid);
    MODERN_WIN32_EXPORT void swap(guid& left, guid& right) noexcept;
    [[nodiscard]] MODERN_WIN32_EXPORT guid new_guid() noexcept;

} // namespace modern_win32

#endif
#endif