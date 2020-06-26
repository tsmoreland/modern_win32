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

#ifndef __MODERN_WIN32_GUID_H__
#define __MODERN_WIN32_GUID_H__
#include <ostream>
#ifdef _WIN32


#include <Windows.h>
#include <string_view>

namespace modern_win32
{
    class guid final
    {
    public:
        explicit guid();
        explicit guid(GUID const& value) noexcept;
        explicit guid(char const* value);
        explicit guid(wchar_t const* value);

        [[nodiscard]] GUID get() const noexcept;

        static guid& empty();

        void swap(guid& other) noexcept;
        [[nodiscard]] bool operator==(guid const& other) const noexcept;
        [[nodiscard]] bool operator!=(guid const& other) const noexcept;

        friend std::ostream& operator<<(std::ostream& os, const guid& obj);
    private:
        GUID m_value{};
    };

    [[nodiscard]] std::string to_string(guid const& uid);
    void swap(guid& left, guid&right) noexcept;
    [[nodiscard]] bool operator==(guid const& left, guid const& right) noexcept;
    [[nodiscard]] bool operator!=(guid const& left, guid const& right) noexcept;

    [[nodiscard]] guid new_guid() noexcept;

}

#endif
#endif