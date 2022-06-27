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

#ifndef MODERN_WIN32_ENVIRONMENT_H
#define MODERN_WIN32_ENVIRONMENT_H
#ifdef _WIN32

#include <map>
#include <modern_win32/modern_win32_export.h>
#include <string>


namespace modern_win32 {
    template <typename TCHAR>
    using environment_map = std::map<std::basic_string<TCHAR>, std::basic_string<TCHAR>>;

    /// <summary>
    /// attempts to retrieve all system and user environment variables storing them in <parmref name="environment"/>
    /// </summary>
    /// <typeparam name="TCHAR">character type</typeparam>
    /// <param name="environment">on success stores all system and user environment variables</param>
    /// <returns>on success true; otherwise false</returns>
    template <typename TCHAR>
    [[nodiscard]] bool try_get_all_environment_variables(environment_map<TCHAR>& environment);

    /// <summary>
    /// attempts to retrieve all system and user environment variables storing them in <parmref name="environment"/>
    /// </summary>
    /// <typeparam name="TCHAR">character type</typeparam>
    /// <param name="environment">on success stores all system and user environment variables</param>
    /// <returns>on success true; otherwise false</returns>
    template <>
    [[nodiscard]] MODERN_WIN32_EXPORT bool try_get_all_environment_variables(environment_map<char>& environment);

    /// <summary>
    /// attempts to retrieve all system and user environment variables storing them in <parmref name="environment"/>
    /// </summary>
    /// <typeparam name="TCHAR">character type</typeparam>
    /// <param name="environment">on success stores all system and user environment variables</param>
    /// <returns>on success true; otherwise false</returns>
    template <>
    [[nodiscard]] MODERN_WIN32_EXPORT bool try_get_all_environment_variables(environment_map<wchar_t>& environment);

    /// <summary>
    /// attempts to retrieve all system and user environment variables storing them in <parmref name="environment"/>
    /// </summary>
    /// <typeparam name="TCHAR">character type</typeparam>
    /// <param name="environment">on success stores all system and user environment variables</param>
    /// <returns>on success true; otherwise false</returns>
    template <typename TCHAR>
    [[nodiscard]] bool try_get_all_environment_variables(environment_map<TCHAR>& environment) {
        return false;
    }

    /*
    template <typename TCHAR>
    class environment_block final
    {
    public:
        explicit environment_block() = default;

    private:
        environment_map m_environment{};
    };
    */


} // namespace modern_win32

#endif
#endif