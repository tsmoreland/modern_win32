//
// Copyright © 2021 Terry Moreland
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

#ifndef MODERN_WIN32_PROCESS_ENUMS_H
#define MODERN_WIN32_PROCESS_ENUMS_H
#ifdef _WIN32

#include <type_traits>

namespace modern_win32 {
    using native_process_priority_type = decltype(GetPriorityClass(std::declval<HANDLE>()));

    enum class process_priority : native_process_priority_type {
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

    template <typename ENUM>
    [[nodiscard]] constexpr auto to_underlying_type(ENUM enum_value) {
        return static_cast<std::underlying_type_t<ENUM>>(enum_value);
    }

    /// <summary>
    /// The following table lists the process-specific access rights.
    /// </summary>
    enum class process_access_rights : unsigned long {
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

    _BITMASK_OPS(process_access_rights);

    /// <summary>
    /// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags
    /// </summary>
    enum class process_creation_options : unsigned long {
        none = 0,

        /// <summary>
        /// The child processes of a process associated with a job are not associated with the job.
        /// If the calling process is not associated with a job, this constant has no effect. If the calling process is
        /// associated with a job, the job must set the JOB_OBJECT_LIMIT_BREAKAWAY_OK limit.
        /// </summary>
        create_breakaway_from_job = 0x01000000,
        /// <summary>
        /// The new process does not inherit the error mode of the calling process. Instead, the new process gets the
        /// default error mode. This feature is particularly useful for multithreaded shell applications that run with
        /// hard errors disabled. The default behavior is for the new process to inherit the error mode of the caller.
        /// Setting this flag changes that default behavior.
        /// </summary>
        create_default_error_mode = 0x04000000,
        /// <summary>
        /// The new process has a new console, instead of inheriting its parent's console (the default). For more
        /// information, see Creation of a Console. This flag cannot be used with DETACHED_PROCESS.
        /// </summary>
        create_new_console = 0x00000010,
        /// <summary>
        /// The new process is the root process of a new process group. The process group includes all processes that
        /// are descendants of this root process. The process identifier of the new process group is the same as the
        /// process identifier, which is returned in the lpProcessInformation parameter. Process groups are used by the
        /// GenerateConsoleCtrlEvent function to enable sending a CTRL+BREAK signal to a group of console processes. If
        /// this flag is specified, CTRL+C signals will be disabled for all processes within the new process group. This
        /// flag is ignored if specified with CREATE_NEW_CONSOLE.
        /// </summary>
        create_new_process_group = 0x00000200,
        /// <summary>
        /// The process is a console application that is being run without a console window. Therefore, the console
        /// handle for the application is not set. This flag is ignored if the application is not a console application,
        /// or if it is used with either CREATE_NEW_CONSOLE or DETACHED_PROCESS.
        /// </summary>
        create_no_window = 0x08000000,
        /// <summary>
        /// The process is to be run as a protected process. The system restricts access to protected processes and the
        /// threads of protected processes. For more information on how processes can interact with protected processes,
        /// see Process Security and Access Rights. To activate a protected process, the binary must have a special
        /// signature. This signature is provided by Microsoft but not currently available for non-Microsoft binaries.
        /// There are currently four protected processes: media foundation, audio engine, Windows error reporting, and
        /// system. Components that load into these binaries must also be signed. Multimedia companies can leverage the
        /// first two protected processes. For more information, see Overview of the Protected Media Path. Windows
        /// Server 2003 and Windows XP: This value is not supported.
        /// </summary>
        create_protected_process = 0x00040000,
        /// <summary>
        /// Allows the caller to execute a child process that bypasses the process restrictions that would normally be
        /// applied automatically to the process.
        /// </summary>
        create_preserve_code_authz_level = 0x02000000,
        /// <summary>
        /// This flag allows secure processes, that run in the Virtualization-Based Security environment, to launch.
        /// </summary>
        create_secure_process = 0x00400000,
        /// <summary>
        /// This flag is valid only when starting a 16-bit Windows-based application. If set, the new process runs in a
        /// private Virtual DOS Machine (VDM). By default, all 16-bit Windows-based applications run as threads in a
        /// single, shared VDM. The advantage of running separately is that a crash only terminates the single VDM; any
        /// other programs running in distinct VDMs continue to function normally. Also, 16-bit Windows-based
        /// applications that are run in separate VDMs have separate input queues. That means that if one application
        /// stops responding momentarily, applications in separate VDMs continue to receive input. The disadvantage of
        /// running separately is that it takes significantly more memory to do so. You should use this flag only if the
        /// user requests that 16-bit applications should run in their own VDM.
        /// </summary>
        create_separate_wow_vdm = 0x00000800,
        /// <summary>
        /// The flag is valid only when starting a 16-bit Windows-based application. If the DefaultSeparateVDM switch in
        /// the Windows section of WIN.INI is TRUE, this flag overrides the switch. The new process is run in the shared
        /// Virtual DOS Machine.
        /// </summary>
        create_shared_wow_vdm = 0x00001000,
        /// <summary>
        /// The primary thread of the new process is created in a suspended state, and does not run until the
        /// ResumeThread function is called.
        /// </summary>
        create_suspended = 0x00000004,
        /// <summary>
        /// If this flag is set, the environment block pointed to by lpEnvironment uses Unicode characters. Otherwise,
        /// the environment block uses ANSI characters.
        /// </summary>
        create_unicode_environment = 0x00000400,
        /// <summary>
        /// The calling thread starts and debugs the new process. It can receive all related debug events using the
        /// WaitForDebugEvent function.
        /// </summary>
        debug_only_this_process = 0x00000002,
        /// <summary>
        /// The calling thread starts and debugs the new process and all child processes created by the new process. It
        /// can receive all related debug events using the WaitForDebugEvent function. A process that uses DEBUG_PROCESS
        /// becomes the root of a debugging chain. This continues until another process in the chain is created with
        /// DEBUG_PROCESS. If this flag is combined with DEBUG_ONLY_THIS_PROCESS, the caller debugs only the new
        /// process, not any child processes.
        /// </summary>
        debug_process = 0x00000001,
        /// <summary>
        /// For console processes, the new process does not inherit its parent's console (the default). The new process
        /// can call the AllocConsole function at a later time to create a console. For more information, see Creation
        /// of a Console. This value cannot be used with CREATE_NEW_CONSOLE.
        /// </summary>
        detached_process = 0x00000008,
        /// <summary>
        /// The process is created with extended startup information; the lpStartupInfo parameter specifies a
        /// STARTUPINFOEX structure. Windows Server 2003 and Windows XP: This value is not supported.
        /// </summary>
        extended_startupinfo_present = 0x00080000,
        /// <summary>
        /// The process inherits its parent's affinity. If the parent process has threads in more than one processor
        /// group, the new process inherits the group-relative affinity of an arbitrary group in use by the parent.
        /// Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP: This value is not supported.
        /// </summary>
        inherit_parent_affinity = 0x00010000,
    };

    _BITMASK_OPS(process_creation_options);

    /// <summary>
    /// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfoa
    /// </summary>
    enum class process_startup_options : unsigned long {
        none = 0,

        /// <summary>
        /// Indicates that the cursor is in feedback mode for two seconds after CreateProcess is called. The Working in
        /// Background cursor is displayed (see the Pointers tab in the Mouse control panel utility). If during those
        /// two seconds the process makes the first GUI call, the system gives five more seconds to the process. If
        /// during those five seconds the process shows a window, the system gives five more seconds to the process to
        /// finish drawing the window.
        ///
        /// The system turns the feedback cursor off after the first call to GetMessage, regardless of whether the
        /// process is drawing.
        /// </summary>
        force_on_feedback = 0x00000040,

        /// <summary>
        /// Indicates that the feedback cursor is forced off while the process is starting. The Normal Select cursor is
        /// displayed.
        /// </summary>
        force_off_feedback = 0x00000080,

        /// <summary>
        /// Indicates that any windows created by the process cannot be pinned on the taskbar.
        /// This flag must be combined with titleisappid.
        /// </summary>
        prevent_pinning = 0x00002000,

        /// <summary>
        /// Indicates that the process should be run in full-screen mode, rather than in windowed mode.
        /// This flag is only valid for console applications running on an x86 computer.
        /// </summary>
        run_fullscreen = 0x00000020,

        /// <summary>
        /// The lpTitle member contains an AppUserModelID. This identifier controls how the taskbar and Start menu
        /// present the application, and enables it to be associated with the correct shortcuts and Jump Lists.
        /// Generally, applications will use the SetCurrentProcessExplicitAppUserModelID and
        /// GetCurrentProcessExplicitAppUserModelID functions instead of setting this flag. For more information, see
        /// Application User Model IDs. If preventpinning is used, application windows cannot be pinned on the taskbar.
        /// The use of any AppUserModelID-related window properties by the application overrides this setting for that
        /// window only. This flag cannot be used with titleislinkname.
        /// </summary>
        title_is_appid = 0x00001000,

        /// <summary>
        /// The lpTitle member contains the path of the shortcut file (.lnk) that the user invoked to start this
        /// process. This is typically set by the shell when a .lnk file pointing to the launched application is
        /// invoked. Most applications will not need to set this value. This flag cannot be used with
        /// STARTF_TITLEISAPPID.
        /// </summary>
        title_is_linkname = 0x00000800,

        /// <summary>
        /// The command line came from an untrusted source. For more information, see Remarks.
        /// </summary>
        untrusted_source = 0x00008000,

        /// <summary>
        /// The dwXCountChars and dwYCountChars members contain additional information.
        /// </summary>
        use_count_chars = 0x00000008,

        /// <summary>
        /// The dwFillAttribute member contains additional information.
        /// </summary>
        use_fill_attribute = 0x00000010,

        /// <summary>
        /// The hStdInput member contains additional information.
        /// This flag cannot be used with STARTF_USESTDHANDLES.
        /// </summary>
        use_hotkey = 0x00000200,

        /// <summary>
        /// The dwX and dwY members contain additional information.
        /// </summary>
        use_position = 0x00000004,

        /// <summary>
        /// The wShowWindow member contains additional information.
        /// </summary>
        use_show_window = 0x00000001,

        /// <summary>
        /// The dwXSize and dwYSize members contain additional information.
        /// </summary>
        use_size = 0x00000002,

        /// <summary>
        /// The hStdInput, hStdOutput, and hStdError members contain additional information.
        /// If this flag is specified when calling one of the process creation functions, the handles must be
        /// inheritable and the function's bInheritHandles parameter must be set to TRUE. For more information, see
        /// Handle Inheritance. If this flag is specified when calling the GetStartupInfo function, these members are
        /// either the handle value specified during process creation or INVALID_HANDLE_VALUE. Handles must be closed
        /// with CloseHandle when they are no longer needed. This flag cannot be used with STARTF_USEHOTKEY.
        /// </summary>
        use_standard_handles = 0x00000100,
    };

    _BITMASK_OPS(process_startup_options);

} // namespace modern_win32

#endif
#endif