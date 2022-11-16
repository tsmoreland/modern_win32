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

#ifndef MODERN_WIN32_SHARED_UTILITIES_H_
#define MODERN_WIN32_SHARED_UTILITIES_H_

namespace modern_win32 {
    template <typename DESTINATION_TYPE, typename SOURCE_TYPE, typename CONVERTER, typename... ARGS>
    void pack(DESTINATION_TYPE* left, SOURCE_TYPE const& right, ARGS const&... args, CONVERTER converter) {
        *left = converter(right);
        pack(++left, args..., converter);
    }

    template <typename DESTINATION_TYPE, typename SOURCE_TYPE, typename CONVERTER, typename... ARGS>
    void pack(DESTINATION_TYPE* left, CONVERTER converter) {}


    template <typename ENUM, typename... ENUMPARAMS>
    constexpr auto combine(ENUM first, ENUM second, ENUMPARAMS... remaining) {
        return first | combine(second, remaining);
    }

    template <typename ENUM, typename... ENUMPARAMS>
    constexpr auto combine(ENUM first, ENUM second) {
        return first | second;
    }

} // namespace modern_win32

#endif