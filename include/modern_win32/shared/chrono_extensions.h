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

#ifndef MODERN_WIN32_SHARED_CHRONO_EXTENSIONS_H_
#define MODERN_WIN32_SHARED_CHRONO_EXTENSIONS_H_

#include <chrono>

namespace modern_win32::shared
{

    /// <summary>
    /// converts value to duration in milliseconds
    /// </summary>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="value">value to convert</param>
    /// <returns>value as duration in milliseconds</returns>
    /// <remarks>
    /// conversion from smaller period will result in loss of precision
    /// </remarks>
    template <class REP, class PERIOD>
    [[nodiscard]]
    constexpr auto to_milliseconds(std::chrono::duration<REP, PERIOD> value) ->
        std::chrono::duration<REP, PERIOD>
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(value);
    }

    /// <summary>
    /// converts value to duration in milliseconds
    /// </summary>
    /// <typeparam name="REP">
    /// an arithmetic type representing the number of ticks
    /// </typeparam>
    /// <typeparam name="PERIOD">
    /// Period (until C++17)typename Period::type (since C++17), a std::ratio
    /// representing the tick period (i.e. the number of seconds per tick)
    /// </typeparam>
    /// <param name="value">value to convert</param>
    /// <returns>value as duration in milliseconds</returns>
    /// <remarks>
    /// conversion from smaller period will result in loss of precision
    /// </remarks>
    template <class REP, class PERIOD>
    [[nodiscard]]
    constexpr auto to_seconds(std::chrono::duration<REP, PERIOD> value) ->
        std::chrono::duration<REP, PERIOD>
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(value);
    }

}


#endif
