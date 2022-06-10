//
// Copyright © 2020 Terry Moreland
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

#include <memory>
#include <modern_win32/environment.h>
#include <modern_win32/string.h>
#include <optional>
#include <processenv.h>
#include <string>
#include <string_view>

#include <Windows.h>


namespace modern_win32 {

    template <typename TCHAR>
    [[nodiscard]] environment_map<TCHAR> to_environment_map(TCHAR const* environment_block) {
        environment_map<TCHAR> environment;
        if (environment_block == nullptr)
            return environment;

        using size_type    = typename std::basic_string<TCHAR>::size_type;
        size_type position = 0;

        bool done = false;
        while (!done) {

            auto const equals = TCHAR('=');
            auto const nul    = TCHAR('\0');

            auto const key_view = get_sub_string_view(&environment_block[position], equals);
            if (!key_view.has_value())
                return environment;
            position += key_view.value().size() + 1;
            auto const value_view = get_sub_string_view(&environment_block[position], nul);
            if (!value_view.has_value())
                return environment;
            position += value_view.value().size() + 1;

            std::basic_string<TCHAR> key{std::begin(key_view.value()), std::end(key_view.value())};
            std::basic_string<TCHAR> value{std::begin(value_view.value()), std::end(value_view.value())};

            environment[key] = value;
            done             = environment_block[position + 1] == nul;
        }

        return environment;
    }

    template <>
    bool try_get_all_environment_variables(environment_map<char>& environment) {
#ifdef UNICODE
#undef GetEnvironmentStrings
        auto deleter         = [](char*& character) { FreeEnvironmentStringsA(character); };
        auto const env_block = std::unique_ptr<char, decltype(deleter)>{GetEnvironmentStrings(), deleter};
#define GetEnvironmentStrings \
    GetEnvironmentStringsW // NOLINT(cppcoreguidelines-macro-usage, clang-diagnostic-unused-macros) -- re-enabling
                           // GetEnvironmentStrings macro
#else
        auto deleter         = [](char* character) { FreeEnvironmentStringsA(character); };
        auto const env_block = std::unique_ptr<char, decltype(deleter)>{GetEnvironmentStringsA(), deleter};
#endif

        if (env_block == nullptr)
            return false;

        environment = to_environment_map(env_block.get());

        return true;
    }

    template <>
    bool try_get_all_environment_variables(environment_map<wchar_t>&) {
        auto deleter         = [](wchar_t*& character) { FreeEnvironmentStringsW(character); };
        auto const env_block = std::unique_ptr<wchar_t, decltype(deleter)>{GetEnvironmentStringsW(), deleter};
        if (env_block == nullptr)
            return false;

        return true;
    }

} // namespace modern_win32