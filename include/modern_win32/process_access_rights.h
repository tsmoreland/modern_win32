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

#ifndef __MODERN_WIN32_PROCESS_ACCESS_RIGHTS_H__
#define __MODERN_WIN32_PROCESS_ACCESS_RIGHTS_H__
#ifdef _WIN32

#include <Windows.h>

namespace modern_win32
{
    /// <summary>
    /// The following table lists the process-specific access rights.
    /// </summary>
    enum class process_access_rights : unsigned long
    {
        /// <Summary>
        /// All possible access rights for a process object.Windows Server 2003 and Windows XP:
        /// The size of the PROCESS_ALL_ACCESS flag increased on Windows Server 2008 and Windows Vista.
        /// If an application compiled for Windows Server 2008 and Windows Vista is run on
        /// Windows Server 2003 or Windows XP, the PROCESS_ALL_ACCESS flag is too large and the function
        /// specifying this flag fails with ERROR_ACCESS_DENIED. To avoid this problem, specify the minimum
        /// set of access rights required for the operation. If PROCESS_ALL_ACCESS must be used,
        /// set _WIN32_WINNT to the minimum operating system targeted by your application
        /// (for example, #define _WIN32_WINNT _WIN32_WINNT_WINXP). For more information,
        /// see Using the Windows Headers.
        /// </summary>
        process_all_access = PROCESS_ALL_ACCESS,
        /// <Summary>
        /// (0x0080) Required to create a process.
        /// </summary>
        process_create_process = PROCESS_CREATE_PROCESS,
        /// <Summary>
        /// (0x0002) Required to create a thread.
        /// </summary>
        process_create_thread = PROCESS_CREATE_THREAD,
        /// <Summary>
        /// (0x0040) Required to duplicate a handle using DuplicateHandle.
        /// </summary>
        process_dup_handle = PROCESS_DUP_HANDLE,
        /// <Summary>
        /// (0x0400) Required to retrieve certain information about a process, such as
        /// its token, exit code, and priority class (see OpenProcessToken).
        /// </summary>
        process_query_information = PROCESS_QUERY_INFORMATION,
        /// <Summary>
        /// (0x1000) Required to retrieve certain information about a process
        /// (see GetExitCodeProcess, GetPriorityClass, IsProcessInJob, QueryFullProcessImageName).
        /// A handle that has the PROCESS_QUERY_INFORMATION access right is automatically granted
        /// PROCESS_QUERY_LIMITED_INFORMATION.
        /// Windows Server 2003 and Windows XP: This access right is not supported.
        /// </summary>
        process_query_limited_information = PROCESS_QUERY_LIMITED_INFORMATION,
        /// <Summary>
        /// (0x0200) Required to set certain information about a process, such as its priority
        /// class (see SetPriorityClass).
        /// </summary>
        process_set_information = PROCESS_SET_INFORMATION,
        /// <Summary>
        /// (0x0100) Required to set memory limits using SetProcessWorkingSetSize.
        /// </summary>
        process_set_quota = PROCESS_SET_QUOTA,
        /// <Summary>
        /// (0x0800) Required to suspend or resume a process.
        /// </summary>
        process_suspend_resume = PROCESS_SUSPEND_RESUME,
        /// <Summary>
        /// (0x0001) Required to terminate a process using TerminateProcess.
        /// </summary>
        process_terminate = PROCESS_TERMINATE,
        /// <Summary>
        /// (0x0008) Required to perform an operation on the address space of a process
        /// (see VirtualProtectEx and WriteProcessMemory).
        /// </summary>
        process_vm_operation = PROCESS_VM_OPERATION,
        /// <Summary>
        /// (0x0010) Required to read memory in a process using ReadProcessMemory.
        /// </summary>
        process_vm_read = PROCESS_VM_READ,
        /// <Summary>
        /// (0x0020) Required to write to memory in a process using WriteProcessMemory.
        /// </summary>
        process_vm_write = PROCESS_VM_WRITE,
        /// <Summary>
        /// (0x00100000L) Required to wait for the process to terminate using the wait functions.
        /// </summary>
        synchronize = SYNCHRONIZE,
    };

    /// <summary>
    /// combine <paramref name="first"/> and <paramref name="second"/> using logical or
    /// </summary>
    /// <returns>result of logical or operation</returns>
    [[nodiscard]] constexpr process_access_rights operator|(process_access_rights first, process_access_rights second)
    {
        return static_cast<process_access_rights>(static_cast<unsigned long>(first) | static_cast<unsigned long>(second));
    }

    /// <summary>
    /// combine <paramref name="first"/> and <paramref name="second"/> using logical and 
    /// </summary>
    /// <returns>result of logical and operation</returns>
    [[nodiscard]] constexpr process_access_rights operator&(process_access_rights first, process_access_rights second)
    {
        return static_cast<process_access_rights>(static_cast<unsigned long>(first) & static_cast<unsigned long>(second));
    }
}

#endif
#endif