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

#include <modern_win32/guid.h>
#include <algorithm>
#include <memory>
#include <modern_win32/com_exception.h>
#include <modern_win32/module_handle.h>

namespace modern_win32
{

template <typename TCHAR>
GUID from_string(TCHAR const* value, char const* method_name)
{
    if (value == nullptr)
        throw std::invalid_argument("value is null");

    auto const maybe_shell32 = get_module("Shell32.dll");
    if (!maybe_shell32.has_value())
        throw std::runtime_error("Unable to load Shell32.dll");

    using guid_from_string = BOOL (WINAPI *)(TCHAR const*, LPGUID);
    auto const& shell32 = maybe_shell32.value();
    auto const guid_from_string_delegate = reinterpret_cast<guid_from_string>(GetProcAddress(shell32.get(), method_name));
    if (guid_from_string_delegate == nullptr)
        throw std::runtime_error("GUIDFromString method not found");

    GUID output;
    if (guid_from_string_delegate(value, &output) != TRUE)
        throw std::invalid_argument("Unable to parse value into GUID");

    return output;
}


guid::guid() 
    : m_value(empty().get())
{
    if (auto const hr = CoCreateGuid(&m_value); FAILED(hr)) 
        throw com_exception(hr);
}

guid::guid(GUID const& value) noexcept
    : m_value(value)
{
}

guid::guid(char const* value)
{
    if (value == nullptr)
        throw std::invalid_argument("value is null");

    m_value = from_string(value, "GUIDFromStringA");
}
guid::guid(wchar_t const* value)
{
    if (value == nullptr)
        throw std::invalid_argument("value is null");
    m_value = from_string(value, "GUIDFromStringW");

}

guid& guid::empty()
{
    static guid empty{};
    return empty;
}

GUID guid::get() const noexcept
{
    return m_value;
}

void guid::swap(guid& other) noexcept
{
    std::swap(m_value, other.m_value);
}

bool guid::operator==(guid const& other) const noexcept
{
    return m_value == other.m_value;
}
bool guid::operator!=(guid const& other) const noexcept
{
    return !operator==(other);
}

std::wstring to_wstring(guid const& uid)
{
    std::wstring value{};
    value.reserve(std::size(L"00000000-0000-0000-0000-000000000000"));
    if (StringFromGUID2(uid.get(), &value[0], static_cast<int>(value.size())) == 0)
        return L"********-****-****-****-************";
    return value;
}
std::string to_string(guid const& uid)
{
    auto value = to_wstring(uid);
    std::string value_a{};


    std::transform(std::begin(value), std::end(value), std::back_inserter(value_a),
        [](auto const& wide_char) {
            const wchar_t ascii_upper_bound = 127;
            const wchar_t ascii_lower_bound = 0;
            return wide_char > ascii_upper_bound || wide_char < ascii_lower_bound
                ? '?'
                : static_cast<char>(wide_char);
        });
    return "";
}
void swap(guid& left, guid&right) noexcept
{
    left.swap(right);
}
bool operator==(guid const& left, guid const& right) noexcept
{
    return left.operator==(right);
}

bool operator!=(guid const& left, guid const& right) noexcept
{
    return left.operator!=(right);
}
std::ostream& operator<<(std::ostream& os, const guid& obj)
{
    return os << to_string(obj);
}

[[nodiscard]] guid new_guid() noexcept
{
    return guid();
}



}
