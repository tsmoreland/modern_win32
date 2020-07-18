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

#ifndef __MODERN_WIN32_PROCESS_PRIORITY_H__
#define __MODERN_WIN32_PROCESS_PRIORITY_H__
#ifdef _WIN32

#include <Windows.h>
#include <type_traits>

namespace modern_win32
{
    using native_process_priority_type = decltype(GetPriorityClass(std::declval<HANDLE>()));

    enum class process_priority : native_process_priority_type
    {
        /// <summary>
        /// Process that has priority above normal but below high
        /// </summary>
        above_normal = 0x00008000,
        /// <summary>
        /// Process that has priority above idle but below NORMAL.
        /// </summary>
        below_normal = 0x00004000,
        /// <summary>
        /// Process that performs time-critical tasks that must be executed
        /// immediately for it to run correctly.  The threads of a
        /// high-priority class process preempt the threads of normal or idle
        /// priority class processes. An example is the Task List, which must
        /// respond quickly when called by the user, regardless of the load on
        /// the operating system. Use extreme care when using the high-priority
        /// class, because a high-priority class CPU-bound application can use
        /// nearly all available cycles.
        /// </summary>
        high = 0x00000080,
        
        /// <summary>
        /// Process whose threads run only when the system is idle and are
        /// preempted by the threads of any process running in a higher
        /// priority class. An example is a screen saver. The idle priority
        /// class is inherited by child processes.
        /// </summary>
        idle = 0x00000040,
        
        /// <summary>
        /// Process with no special scheduling needs.
        /// </summary>
        normal = 0x00000020,
        
        /// <summary>
        /// Process that has the highest possible priority. The threads of a
        /// real-time priority class process preempt the threads of all other
        /// processes, including operating system processes performing important
        /// tasks. For example, a real-time process that executes for more than
        /// a very brief interval can cause disk caches not to flush or cause
        /// the mouse to be unresponsive.
        /// </summary>
        realtime = 0x00000100
    };
}

#endif
#endif