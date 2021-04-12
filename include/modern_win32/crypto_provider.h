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

#ifndef MODERN_WIN32_CRYPTO_PROVIDER_
#define MODERN_WIN32_CRYPTO_PROVIDER_  // NOLINT(clang-diagnostic-unused-macros)
#ifdef _WIN32

#include <Windows.h>
#include <modern_win32/modern_win32_export.h>

#pragma comment (lib, "bcrypt")

namespace modern_win32
{

    /// <summary>
    /// generates a random number.
    /// </summary>
    /// <param name="data">
    /// The address of a buffer that receives the random number.
    /// The size of this buffer is specified by the length parameter
    /// .</param>
    /// <param name="length">The size, in bytes, of the data buffer.</param>
    /// <returns>returns true on success; otherwise, false</returns>
    [[nodiscard]]
    MODERN_WIN32_EXPORT bool bcrypt_get_random_bytes(byte* data, unsigned long length) noexcept;

}

#endif
#endif

