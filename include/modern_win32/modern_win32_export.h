//
// Copyright © 2021 Terry Moreland
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

#ifndef MODERN_WIN32_EXPORT_H_
#define MODERN_WIN32_EXPORT_H_

#ifdef _WIN32
#ifdef MODERN_WIN32_STATIC_DEFINE
#  define MODERN_WIN32_EXPORT
#  define MODERN_WIN32_NO_EXPORT
#else

#  ifndef MODERN_WIN32_EXPORT
#    ifdef MODERN_WIN32_EXPORTS
        /* We are building this library */
#      define MODERN_WIN32_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MODERN_WIN32_EXPORT __declspec(dllimport)
#    endif
#  endif

#endif
#else
#  define MODERN_WIN32_EXPORT
#endif

#endif
