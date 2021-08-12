
// Copyright © 2021 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#ifndef MODERN_WIN32_WINDOWS_ERROR_H_
#define MODERN_WIN32_WINDOWS_ERROR_H_
#ifdef _WIN32

#include <Windows.h>
#include <optional>
#include <modern_win32/modern_win32_export.h>

namespace modern_win32
{
    enum class windows_error : unsigned long
    {
        /// <summary>
        /// out of range value used when there is no appropriate value
        /// </summary>
        unknown = (std::numeric_limits<unsigned long>::max)(),

#       ifdef NO_ERROR
        none = NO_ERROR,
#       else
        none = 0L,
#       endif

        /// <summary>Incorrect function.</summary>
#       ifdef ERROR_INVALID_FUNCTION
        error_invalid_function = ERROR_INVALID_FUNCTION,
#       else
        error_invalid_function = 1L,
#       endif

        /// <summary>The system cannot find the file specified.</summary>
#       ifdef ERROR_FILE_NOT_FOUND
        error_file_not_found = ERROR_FILE_NOT_FOUND,
#       else
        error_file_not_found = 2L,
#       endif

        /// <summary>The system cannot find the path specified.</summary>
#       ifdef ERROR_PATH_NOT_FOUND
        error_path_not_found = ERROR_PATH_NOT_FOUND,
#       else
        error_path_not_found = 3L,
#       endif

        /// <summary>The system cannot open the file.</summary>
#       ifdef ERROR_TOO_MANY_OPEN_FILES
        error_too_many_open_files = ERROR_TOO_MANY_OPEN_FILES,
#       else
        error_too_many_open_files = 4L,
#       endif

        /// <summary>Access is denied.</summary>
#       ifdef ERROR_ACCESS_DENIED
        error_access_denied = ERROR_ACCESS_DENIED,
#       else
        error_access_denied = 5L,
#       endif

        /// <summary>The handle is invalid.</summary>
#       ifdef ERROR_INVALID_HANDLE
        error_invalid_handle = ERROR_INVALID_HANDLE,
#       else
        error_invalid_handle = 6L,
#       endif

        /// <summary>The storage control blocks were destroyed.</summary>
#       ifdef ERROR_ARENA_TRASHED
        error_arena_trashed = ERROR_ARENA_TRASHED,
#       else
        error_arena_trashed = 7L,
#       endif

        /// <summary>Not enough memory resources are available to process this command.</summary>
#       ifdef ERROR_NOT_ENOUGH_MEMORY
        error_not_enough_memory = ERROR_NOT_ENOUGH_MEMORY,
#       else
        error_not_enough_memory = 8L,
#       endif

        /// <summary>The storage control block address is invalid.</summary>
#       ifdef ERROR_INVALID_BLOCK
        error_invalid_block = ERROR_INVALID_BLOCK,
#       else
        error_invalid_block = 9L,
#       endif

        /// <summary>The environment is incorrect.</summary>
#       ifdef ERROR_BAD_ENVIRONMENT
        error_bad_environment = ERROR_BAD_ENVIRONMENT,
#       else
        error_bad_environment = 10L,
#       endif

        /// <summary>An attempt was made to load a program with an incorrect format.</summary>
#       ifdef ERROR_BAD_FORMAT
        error_bad_format = ERROR_BAD_FORMAT,
#       else
        error_bad_format = 11L,
#       endif

        /// <summary>The access code is invalid.</summary>
#       ifdef ERROR_INVALID_ACCESS
        error_invalid_access = ERROR_INVALID_ACCESS,
#       else
        error_invalid_access = 12L,
#       endif

        /// <summary>The data is invalid.</summary>
#       ifdef ERROR_INVALID_DATA
        error_invalid_data = ERROR_INVALID_DATA,
#       else
        error_invalid_data = 13L,
#       endif

        /// <summary>Not enough memory resources are available to complete this operation.</summary>
#       ifdef ERROR_OUTOFMEMORY
        error_outofmemory = ERROR_OUTOFMEMORY,
#       else
        error_outofmemory = 14L,
#       endif

        /// <summary>The system cannot find the drive specified.</summary>
#       ifdef ERROR_INVALID_DRIVE
        error_invalid_drive = ERROR_INVALID_DRIVE,
#       else
        error_invalid_drive = 15L,
#       endif

        /// <summary>The directory cannot be removed.</summary>
#       ifdef ERROR_CURRENT_DIRECTORY
        error_current_directory = ERROR_CURRENT_DIRECTORY,
#       else
        error_current_directory = 16L,
#       endif

        /// <summary>The system cannot move the file to a different disk drive.</summary>
#       ifdef ERROR_NOT_SAME_DEVICE
        error_not_same_device = ERROR_NOT_SAME_DEVICE,
#       else
        error_not_same_device = 17L,
#       endif

        /// <summary>There are no more files.</summary>
#       ifdef ERROR_NO_MORE_FILES
        error_no_more_files = ERROR_NO_MORE_FILES,
#       else
        error_no_more_files = 18L,
#       endif

        /// <summary>The media is write protected.</summary>
#       ifdef ERROR_WRITE_PROTECT
        error_write_protect = ERROR_WRITE_PROTECT,
#       else
        error_write_protect = 19L,
#       endif

#       ifdef ERROR_BAD_UNIT
        /// <summary>The system cannot find the device specified.</summary>
        error_bad_unit = ERROR_BAD_UNIT,
#       else
#       endif

        /// <summary>The device is not ready.</summary>
#       ifdef ERROR_NOT_READY
        error_not_ready = ERROR_NOT_READY,
#       else
        error_not_ready = 20L,
#       endif

#       ifdef ERROR_BAD_COMMAND
        /// <summary>The device does not recognize the command.</summary>
        error_bad_command = ERROR_BAD_COMMAND,
#       else
#       endif

#       ifdef ERROR_CRC
        /// <summary>Data error (cyclic redundancy check).</summary>
        error_crc = ERROR_CRC,
#       else
#       endif

#       ifdef ERROR_BAD_LENGTH
        /// <summary>The program issued a command but the command length is incorrect.</summary>
        error_bad_length = ERROR_BAD_LENGTH,
#       else
#       endif
        /// <summary>The drive cannot locate a specific area or track on the disk.</summary>
#       ifdef ERROR_SEEK
        error_seek = ERROR_SEEK,
#       else
#       endif
        /// <summary>The specified disk or diskette cannot be accessed.</summary>
#       ifdef ERROR_NOT_DOS_DISK
        error_not_dos_disk = ERROR_NOT_DOS_DISK,
#       else
#       endif
        /// <summary>The drive cannot find the sector requested.</summary>
#       ifdef ERROR_SECTOR_NOT_FOUND
        error_sector_not_found = ERROR_SECTOR_NOT_FOUND,
#       else
#       endif
        /// <summary>The printer is out of paper.</summary>
#       ifdef ERROR_OUT_OF_PAPER
        error_out_of_paper = ERROR_OUT_OF_PAPER,
#       else
#       endif
        /// <summary>The system cannot write to the specified device.</summary>
#       ifdef ERROR_WRITE_FAULT
        error_write_fault = ERROR_WRITE_FAULT,
#       else
#       endif
        /// <summary>The system cannot read from the specified device.</summary>
#       ifdef ERROR_READ_FAULT
        error_read_fault = ERROR_READ_FAULT,
#       else
#       endif
        /// <summary>A device attached to the system is not functioning.</summary>
#       ifdef ERROR_GEN_FAILURE
        error_gen_failure = ERROR_GEN_FAILURE,
#       else
#       endif
        /// <summary>The process cannot access the file because it is being used by another process.</summary>
#       ifdef ERROR_SHARING_VIOLATION
        error_sharing_violation = ERROR_SHARING_VIOLATION,
#       else
#       endif
        /// <summary>The process cannot access the file because another process has locked a portion of the file.</summary>
#       ifdef ERROR_LOCK_VIOLATION
        error_lock_violation = ERROR_LOCK_VIOLATION,
#       else
#       endif
        /// <summary>The wrong diskette is in the drive.</summary>
        /// <summary>Insert %2 (Volume Serial Number: %3) into drive %1.</summary>
#       ifdef ERROR_WRONG_DISK
        error_wrong_disk = ERROR_WRONG_DISK,
#       else
#       endif
        /// <summary>Too many files opened for sharing.</summary>
#       ifdef ERROR_SHARING_BUFFER_EXCEEDED
        error_sharing_buffer_exceeded = ERROR_SHARING_BUFFER_EXCEEDED,
#       else
#       endif
        /// <summary>Reached the end of the file.</summary>
#       ifdef ERROR_HANDLE_EOF
        error_handle_eof = ERROR_HANDLE_EOF,
#       else
#       endif
        /// <summary>The disk is full.</summary>
#       ifdef ERROR_HANDLE_DISK_FULL
        error_handle_disk_full = ERROR_HANDLE_DISK_FULL,
#       else
#       endif
        /// <summary>The request is not supported.</summary>
#       ifdef ERROR_NOT_SUPPORTED
        error_not_supported = ERROR_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>Windows cannot find the network path. Verify that the network path is correct and the destination computer is not busy or turned off. If Windows still cannot find the network path, contact your network administrator.</summary>
#       ifdef ERROR_REM_NOT_LIST
        error_rem_not_list = ERROR_REM_NOT_LIST,
#       else
#       endif
        /// <summary>You were not connected because a duplicate name exists on the network. If joining a domain, go to System in Control Panel to change the computer name and try again. If joining a workgroup, choose another workgroup name.</summary>
#       ifdef ERROR_DUP_NAME
        error_dup_name = ERROR_DUP_NAME,
#       else
#       endif
        /// <summary>The network path was not found.</summary>
#       ifdef ERROR_BAD_NETPATH
        error_bad_netpath = ERROR_BAD_NETPATH,
#       else
#       endif
        /// <summary>The network is busy.</summary>
#       ifdef ERROR_NETWORK_BUSY
        error_network_busy = ERROR_NETWORK_BUSY,
#       else
#       endif
        /// <summary>The specified network resource or device is no longer available.</summary>
#       ifdef ERROR_DEV_NOT_EXIST
        error_dev_not_exist = ERROR_DEV_NOT_EXIST,
#       else
#       endif
        /// <summary>The network BIOS command limit has been reached.</summary>
#       ifdef ERROR_TOO_MANY_CMDS
        error_too_many_cmds = ERROR_TOO_MANY_CMDS,
#       else
#       endif
        /// <summary>A network adapter hardware error occurred.</summary>
#       ifdef ERROR_ADAP_HDW_ERR
        error_adap_hdw_err = ERROR_ADAP_HDW_ERR,
#       else
#       endif
        /// <summary>The specified server cannot perform the requested operation.</summary>
#       ifdef ERROR_BAD_NET_RESP
        error_bad_net_resp = ERROR_BAD_NET_RESP,
#       else
#       endif
        /// <summary>An unexpected network error occurred.</summary>
#       ifdef ERROR_UNEXP_NET_ERR
        error_unexp_net_err = ERROR_UNEXP_NET_ERR,
#       else
#       endif
        /// <summary>The remote adapter is not compatible.</summary>
#       ifdef ERROR_BAD_REM_ADAP
        error_bad_rem_adap = ERROR_BAD_REM_ADAP,
#       else
#       endif
        /// <summary>The printer queue is full.</summary>
#       ifdef ERROR_PRINTQ_FULL
        error_printq_full = ERROR_PRINTQ_FULL,
#       else
#       endif
        /// <summary>Space to store the file waiting to be printed is not available on the server.</summary>
#       ifdef ERROR_NO_SPOOL_SPACE
        error_no_spool_space = ERROR_NO_SPOOL_SPACE,
#       else
#       endif
        /// <summary>Your file waiting to be printed was deleted.</summary>
#       ifdef ERROR_PRINT_CANCELLED
        error_print_cancelled = ERROR_PRINT_CANCELLED,
#       else
#       endif
        /// <summary>The specified network name is no longer available.</summary>
#       ifdef ERROR_NETNAME_DELETED
        error_netname_deleted = ERROR_NETNAME_DELETED,
#       else
#       endif
        /// <summary>Network access is denied.</summary>
#       ifdef ERROR_NETWORK_ACCESS_DENIED
        error_network_access_denied = ERROR_NETWORK_ACCESS_DENIED,
#       else
#       endif
        /// <summary>The network resource type is not correct.</summary>
#       ifdef ERROR_BAD_DEV_TYPE
        error_bad_dev_type = ERROR_BAD_DEV_TYPE,
#       else
#       endif
        /// <summary>The network name cannot be found.</summary>
#       ifdef ERROR_BAD_NET_NAME
        error_bad_net_name = ERROR_BAD_NET_NAME,
#       else
#       endif
        /// <summary>The name limit for the local computer network adapter card was exceeded.</summary>
#       ifdef ERROR_TOO_MANY_NAMES
        error_too_many_names = ERROR_TOO_MANY_NAMES,
#       else
#       endif
        /// <summary>The network BIOS session limit was exceeded.</summary>
#       ifdef ERROR_TOO_MANY_SESS
        error_too_many_sess = ERROR_TOO_MANY_SESS,
#       else
#       endif
        /// <summary>The remote server has been paused or is in the process of being started.</summary>
#       ifdef ERROR_SHARING_PAUSED
        error_sharing_paused = ERROR_SHARING_PAUSED,
#       else
#       endif
        /// <summary>No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.</summary>
#       ifdef ERROR_REQ_NOT_ACCEP
        error_req_not_accep = ERROR_REQ_NOT_ACCEP,
#       else
#       endif
        /// <summary>The specified printer or disk device has been paused.</summary>
#       ifdef ERROR_REDIR_PAUSED
        error_redir_paused = ERROR_REDIR_PAUSED,
#       else
#       endif
        /// <summary>The file exists.</summary>
#       ifdef ERROR_FILE_EXISTS
        error_file_exists = ERROR_FILE_EXISTS,
#       else
#       endif
        /// <summary>The directory or file cannot be created.</summary>
#       ifdef ERROR_CANNOT_MAKE
        error_cannot_make = ERROR_CANNOT_MAKE,
#       else
#       endif
        /// <summary>Fail on INT 24.</summary>
#       ifdef ERROR_FAIL_I24
        error_fail_i24 = ERROR_FAIL_I24,
#       else
#       endif
        /// <summary>Storage to process this request is not available.</summary>
#       ifdef ERROR_OUT_OF_STRUCTURES
        error_out_of_structures = ERROR_OUT_OF_STRUCTURES,
#       else
#       endif
        /// <summary>The local device name is already in use.</summary>
#       ifdef ERROR_ALREADY_ASSIGNED
        error_already_assigned = ERROR_ALREADY_ASSIGNED,
#       else
#       endif
        /// <summary>The specified network password is not correct.</summary>
#       ifdef ERROR_INVALID_PASSWORD
        error_invalid_password = ERROR_INVALID_PASSWORD,
#       else
#       endif
        /// <summary>The parameter is incorrect.</summary>
#       ifdef ERROR_INVALID_PARAMETER
        error_invalid_parameter = ERROR_INVALID_PARAMETER,
#       else
#       endif
        /// <summary>A write fault occurred on the network.</summary>
#       ifdef ERROR_NET_WRITE_FAULT
        error_net_write_fault = ERROR_NET_WRITE_FAULT,
#       else
#       endif
        /// <summary>The system cannot start another process at this time.</summary>
#       ifdef ERROR_NO_PROC_SLOTS
        error_no_proc_slots = ERROR_NO_PROC_SLOTS,
#       else
#       endif
        /// <summary>Cannot create another system semaphore.</summary>
#       ifdef ERROR_TOO_MANY_SEMAPHORES
        error_too_many_semaphores = ERROR_TOO_MANY_SEMAPHORES,
#       else
#       endif
        /// <summary>The exclusive semaphore is owned by another process.</summary>
#       ifdef ERROR_EXCL_SEM_ALREADY_OWNED
        error_excl_sem_already_owned = ERROR_EXCL_SEM_ALREADY_OWNED,
#       else
#       endif
        /// <summary>The semaphore is set and cannot be closed.</summary>
#       ifdef ERROR_SEM_IS_SET
        error_sem_is_set = ERROR_SEM_IS_SET,
#       else
#       endif
        /// <summary>The semaphore cannot be set again.</summary>
#       ifdef ERROR_TOO_MANY_SEM_REQUESTS
        error_too_many_sem_requests = ERROR_TOO_MANY_SEM_REQUESTS,
#       else
#       endif
        /// <summary>Cannot request exclusive semaphores at interrupt time.</summary>
#       ifdef ERROR_INVALID_AT_INTERRUPT_TIME
        error_invalid_at_interrupt_time = ERROR_INVALID_AT_INTERRUPT_TIME,
#       else
#       endif
        /// <summary>The previous ownership of this semaphore has ended.</summary>
#       ifdef ERROR_SEM_OWNER_DIED
        error_sem_owner_died = ERROR_SEM_OWNER_DIED,
#       else
#       endif
        /// <summary>Insert the diskette for drive %1.</summary>
#       ifdef ERROR_SEM_USER_LIMIT
        error_sem_user_limit = ERROR_SEM_USER_LIMIT,
#       else
#       endif
        /// <summary>The program stopped because an alternate diskette was not inserted.</summary>
#       ifdef ERROR_DISK_CHANGE
        error_disk_change = ERROR_DISK_CHANGE,
#       else
#       endif
        /// <summary>The disk is in use or locked by another process.</summary>
#       ifdef ERROR_DRIVE_LOCKED
        error_drive_locked = ERROR_DRIVE_LOCKED,
#       else
#       endif
        /// <summary>The pipe has been ended.</summary>
#       ifdef ERROR_BROKEN_PIPE
        error_broken_pipe = ERROR_BROKEN_PIPE,
#       else
#       endif
        /// <summary>The system cannot open the device or file specified.</summary>
#       ifdef ERROR_OPEN_FAILED
        error_open_failed = ERROR_OPEN_FAILED,
#       else
#       endif
        /// <summary>The file name is too long.</summary>
#       ifdef ERROR_BUFFER_OVERFLOW
        error_buffer_overflow = ERROR_BUFFER_OVERFLOW,
#       else
#       endif
        /// <summary>There is not enough space on the disk.</summary>
#       ifdef ERROR_DISK_FULL
        error_disk_full = ERROR_DISK_FULL,
#       else
#       endif
        /// <summary>No more internal file identifiers available.</summary>
#       ifdef ERROR_NO_MORE_SEARCH_HANDLES
        error_no_more_search_handles = ERROR_NO_MORE_SEARCH_HANDLES,
#       else
#       endif
        /// <summary>The target internal file identifier is incorrect.</summary>
#       ifdef ERROR_INVALID_TARGET_HANDLE
        error_invalid_target_handle = ERROR_INVALID_TARGET_HANDLE,
#       else
#       endif
        /// <summary>The IOCTL call made by the application program is not correct.</summary>
#       ifdef ERROR_INVALID_CATEGORY
        error_invalid_category = ERROR_INVALID_CATEGORY,
#       else
#       endif
        /// <summary>The verify-on-write switch parameter value is not correct.</summary>
#       ifdef ERROR_INVALID_VERIFY_SWITCH
        error_invalid_verify_switch = ERROR_INVALID_VERIFY_SWITCH,
#       else
#       endif
        /// <summary>The system does not support the command requested.</summary>
#       ifdef ERROR_BAD_DRIVER_LEVEL
        error_bad_driver_level = ERROR_BAD_DRIVER_LEVEL,
#       else
#       endif
        /// <summary>This function is not supported on this system.</summary>
#       ifdef ERROR_CALL_NOT_IMPLEMENTED
        error_call_not_implemented = ERROR_CALL_NOT_IMPLEMENTED,
#       else
#       endif
        /// <summary>The semaphore timeout period has expired.</summary>
#       ifdef ERROR_SEM_TIMEOUT
        error_sem_timeout = ERROR_SEM_TIMEOUT,
#       else
#       endif
        /// <summary>The data area passed to a system call is too small.</summary>
#       ifdef ERROR_INSUFFICIENT_BUFFER
        error_insufficient_buffer = ERROR_INSUFFICIENT_BUFFER,
#       else
#       endif
        /// <summary>The filename, directory name, or volume label syntax is incorrect.</summary>
#       ifdef ERROR_INVALID_NAME
        error_invalid_name = ERROR_INVALID_NAME,
#       else
#       endif
        /// <summary>The system call level is not correct.</summary>
#       ifdef ERROR_INVALID_LEVEL
        error_invalid_level = ERROR_INVALID_LEVEL,
#       else
#       endif
        /// <summary>The disk has no volume label.</summary>
#       ifdef ERROR_NO_VOLUME_LABEL
        error_no_volume_label = ERROR_NO_VOLUME_LABEL,
#       else
#       endif
        /// <summary>The specified module could not be found.</summary>
#       ifdef ERROR_MOD_NOT_FOUND
        error_mod_not_found = ERROR_MOD_NOT_FOUND,
#       else
#       endif
        /// <summary>The specified procedure could not be found.</summary>
#       ifdef ERROR_PROC_NOT_FOUND
        error_proc_not_found = ERROR_PROC_NOT_FOUND,
#       else
#       endif
        /// <summary>There are no child processes to wait for.</summary>
#       ifdef ERROR_WAIT_NO_CHILDREN
        error_wait_no_children = ERROR_WAIT_NO_CHILDREN,
#       else
#       endif
        /// <summary>The %1 application cannot be run in Win32 mode.</summary>
#       ifdef ERROR_CHILD_NOT_COMPLETE
        error_child_not_complete = ERROR_CHILD_NOT_COMPLETE,
#       else
#       endif
        /// <summary>Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.</summary>
#       ifdef ERROR_DIRECT_ACCESS_HANDLE
        error_direct_access_handle = ERROR_DIRECT_ACCESS_HANDLE,
#       else
#       endif
        /// <summary>An attempt was made to move the file pointer before the beginning of the file.</summary>
#       ifdef ERROR_NEGATIVE_SEEK
        error_negative_seek = ERROR_NEGATIVE_SEEK,
#       else
#       endif
        /// <summary>The file pointer cannot be set on the specified device or file.</summary>
#       ifdef ERROR_SEEK_ON_DEVICE
        error_seek_on_device = ERROR_SEEK_ON_DEVICE,
#       else
#       endif
        /// <summary>A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.</summary>
#       ifdef ERROR_IS_JOIN_TARGET
        error_is_join_target = ERROR_IS_JOIN_TARGET,
#       else
#       endif
        /// <summary>An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.</summary>
#       ifdef ERROR_IS_JOINED
        error_is_joined = ERROR_IS_JOINED,
#       else
#       endif
        /// <summary>An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.</summary>
#       ifdef ERROR_IS_SUBSTED
        error_is_substed = ERROR_IS_SUBSTED,
#       else
#       endif
        /// <summary>The system tried to delete the JOIN of a drive that is not joined.</summary>
#       ifdef ERROR_NOT_JOINED
        error_not_joined = ERROR_NOT_JOINED,
#       else
#       endif
        /// <summary>The system tried to delete the substitution of a drive that is not substituted.</summary>
#       ifdef ERROR_NOT_SUBSTED
        error_not_substed = ERROR_NOT_SUBSTED,
#       else
#       endif
        /// <summary>The system tried to join a drive to a directory on a joined drive.</summary>
#       ifdef ERROR_JOIN_TO_JOIN
        error_join_to_join = ERROR_JOIN_TO_JOIN,
#       else
#       endif
        /// <summary>The system tried to substitute a drive to a directory on a substituted drive.</summary>
#       ifdef ERROR_SUBST_TO_SUBST
        error_subst_to_subst = ERROR_SUBST_TO_SUBST,
#       else
#       endif
        /// <summary>The system tried to join a drive to a directory on a substituted drive.</summary>
#       ifdef ERROR_JOIN_TO_SUBST
        error_join_to_subst = ERROR_JOIN_TO_SUBST,
#       else
#       endif
        /// <summary>The system tried to SUBST a drive to a directory on a joined drive.</summary>
#       ifdef ERROR_SUBST_TO_JOIN
        error_subst_to_join = ERROR_SUBST_TO_JOIN,
#       else
#       endif
        /// <summary>The system cannot perform a JOIN or SUBST at this time.</summary>
#       ifdef ERROR_BUSY_DRIVE
        error_busy_drive = ERROR_BUSY_DRIVE,
#       else
#       endif
        /// <summary>The system cannot join or substitute a drive to or for a directory on the same drive.</summary>
#       ifdef ERROR_SAME_DRIVE
        error_same_drive = ERROR_SAME_DRIVE,
#       else
#       endif
        /// <summary>The directory is not a subdirectory of the root directory.</summary>
#       ifdef ERROR_DIR_NOT_ROOT
        error_dir_not_root = ERROR_DIR_NOT_ROOT,
#       else
#       endif
        /// <summary>The directory is not empty.</summary>
#       ifdef ERROR_DIR_NOT_EMPTY
        error_dir_not_empty = ERROR_DIR_NOT_EMPTY,
#       else
#       endif
        /// <summary>The path specified is being used in a substitute.</summary>
#       ifdef ERROR_IS_SUBST_PATH
        error_is_subst_path = ERROR_IS_SUBST_PATH,
#       else
#       endif
        /// <summary>Not enough resources are available to process this command.</summary>
#       ifdef ERROR_IS_JOIN_PATH
        error_is_join_path = ERROR_IS_JOIN_PATH,
#       else
#       endif
        /// <summary>The path specified cannot be used at this time.</summary>
#       ifdef ERROR_PATH_BUSY
        error_path_busy = ERROR_PATH_BUSY,
#       else
#       endif
        /// <summary>An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.</summary>
#       ifdef ERROR_IS_SUBST_TARGET
        error_is_subst_target = ERROR_IS_SUBST_TARGET,
#       else
#       endif
        /// <summary>System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.</summary>
#       ifdef ERROR_SYSTEM_TRACE
        error_system_trace = ERROR_SYSTEM_TRACE,
#       else
#       endif
        /// <summary>The number of specified semaphore events for DosMuxSemWait is not correct.</summary>
#       ifdef ERROR_INVALID_EVENT_COUNT
        error_invalid_event_count = ERROR_INVALID_EVENT_COUNT,
#       else
#       endif
        /// <summary>DosMuxSemWait did not execute; too many semaphores are already set.</summary>
#       ifdef ERROR_TOO_MANY_MUXWAITERS
        error_too_many_muxwaiters = ERROR_TOO_MANY_MUXWAITERS,
#       else
#       endif
        /// <summary>The DosMuxSemWait list is not correct.</summary>
#       ifdef ERROR_INVALID_LIST_FORMAT
        error_invalid_list_format = ERROR_INVALID_LIST_FORMAT,
#       else
#       endif
        /// <summary>The volume label you entered exceeds the label character limit of the target file system.</summary>
#       ifdef ERROR_LABEL_TOO_LONG
        error_label_too_long = ERROR_LABEL_TOO_LONG,
#       else
#       endif
        /// <summary>Cannot create another thread.</summary>
#       ifdef ERROR_TOO_MANY_TCBS
        error_too_many_tcbs = ERROR_TOO_MANY_TCBS,
#       else
#       endif
        /// <summary>The recipient process has refused the signal.</summary>
#       ifdef ERROR_SIGNAL_REFUSED
        error_signal_refused = ERROR_SIGNAL_REFUSED,
#       else
#       endif
        /// <summary>The segment is already discarded and cannot be locked.</summary>
#       ifdef ERROR_DISCARDED
        error_discarded = ERROR_DISCARDED,
#       else
#       endif
        /// <summary>The segment is already unlocked.</summary>
#       ifdef ERROR_NOT_LOCKED
        error_not_locked = ERROR_NOT_LOCKED,
#       else
#       endif
        /// <summary>The address for the thread ID is not correct.</summary>
#       ifdef ERROR_BAD_THREADID_ADDR
        error_bad_threadid_addr = ERROR_BAD_THREADID_ADDR,
#       else
#       endif
        /// <summary>One or more arguments are not correct.</summary>
#       ifdef ERROR_BAD_ARGUMENTS
        error_bad_arguments = ERROR_BAD_ARGUMENTS,
#       else
#       endif
        /// <summary>The specified path is invalid.</summary>
#       ifdef ERROR_BAD_PATHNAME
        error_bad_pathname = ERROR_BAD_PATHNAME,
#       else
#       endif
        /// <summary>A signal is already pending.</summary>
#       ifdef ERROR_SIGNAL_PENDING
        error_signal_pending = ERROR_SIGNAL_PENDING,
#       else
#       endif
        /// <summary>No more threads can be created in the system.</summary>
#       ifdef ERROR_MAX_THRDS_REACHED
        error_max_thrds_reached = ERROR_MAX_THRDS_REACHED,
#       else
#       endif
        /// <summary>Unable to lock a region of a file.</summary>
#       ifdef ERROR_LOCK_FAILED
        error_lock_failed = ERROR_LOCK_FAILED,
#       else
#       endif
        /// <summary>The requested resource is in use.</summary>
#       ifdef ERROR_BUSY
        error_busy = ERROR_BUSY,
#       else
#       endif
        /// <summary>Device's command support detection is in progress.</summary>
#       ifdef ERROR_DEVICE_SUPPORT_IN_PROGRESS
        error_device_support_in_progress = ERROR_DEVICE_SUPPORT_IN_PROGRESS,
#       else
#       endif
        /// <summary>A lock request was not outstanding for the supplied cancel region.</summary>
#       ifdef ERROR_CANCEL_VIOLATION
        error_cancel_violation = ERROR_CANCEL_VIOLATION,
#       else
#       endif
        /// <summary>The file system does not support atomic changes to the lock type.</summary>
#       ifdef ERROR_ATOMIC_LOCKS_NOT_SUPPORTED
        error_atomic_locks_not_supported = ERROR_ATOMIC_LOCKS_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The system detected a segment number that was not correct.</summary>
#       ifdef ERROR_INVALID_SEGMENT_NUMBER
        error_invalid_segment_number = ERROR_INVALID_SEGMENT_NUMBER,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_INVALID_ORDINAL
        error_invalid_ordinal = ERROR_INVALID_ORDINAL,
#       else
#       endif
        /// <summary>Cannot create a file when that file already exists.</summary>
#       ifdef ERROR_ALREADY_EXISTS
        error_already_exists = ERROR_ALREADY_EXISTS,
#       else
#       endif
        /// <summary>The flag passed is not correct.</summary>
#       ifdef ERROR_INVALID_FLAG_NUMBER
        error_invalid_flag_number = ERROR_INVALID_FLAG_NUMBER,
#       else
#       endif
        /// <summary>The specified system semaphore name was not found.</summary>
#       ifdef ERROR_SEM_NOT_FOUND
        error_sem_not_found = ERROR_SEM_NOT_FOUND,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_INVALID_STARTING_CODESEG
        error_invalid_starting_codeseg = ERROR_INVALID_STARTING_CODESEG,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_INVALID_STACKSEG
        error_invalid_stackseg = ERROR_INVALID_STACKSEG,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_INVALID_MODULETYPE
        error_invalid_moduletype = ERROR_INVALID_MODULETYPE,
#       else
#       endif
        /// <summary>Cannot run %1 in Win32 mode.</summary>
#       ifdef ERROR_INVALID_EXE_SIGNATURE
        error_invalid_exe_signature = ERROR_INVALID_EXE_SIGNATURE,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_EXE_MARKED_INVALID
        error_exe_marked_invalid = ERROR_EXE_MARKED_INVALID,
#       else
#       endif
        /// <summary>%1 is not a valid Win32 application.</summary>
#       ifdef ERROR_BAD_EXE_FORMAT
        error_bad_exe_format = ERROR_BAD_EXE_FORMAT,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_ITERATED_DATA_EXCEEDS_64k
        error_iterated_data_exceeds_64k = ERROR_ITERATED_DATA_EXCEEDS_64k,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_INVALID_MINALLOCSIZE
        error_invalid_minallocsize = ERROR_INVALID_MINALLOCSIZE,
#       else
#       endif
        /// <summary>The operating system cannot run this application program.</summary>
#       ifdef ERROR_DYNLINK_FROM_INVALID_RING
        error_dynlink_from_invalid_ring = ERROR_DYNLINK_FROM_INVALID_RING,
#       else
#       endif
        /// <summary>The operating system is not presently configured to run this application.</summary>
#       ifdef ERROR_IOPL_NOT_ENABLED
        error_iopl_not_enabled = ERROR_IOPL_NOT_ENABLED,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_INVALID_SEGDPL
        error_invalid_segdpl = ERROR_INVALID_SEGDPL,
#       else
#       endif
        /// <summary>The operating system cannot run this application program.</summary>
#       ifdef ERROR_AUTODATASEG_EXCEEDS_64k
        error_autodataseg_exceeds_64k = ERROR_AUTODATASEG_EXCEEDS_64k,
#       else
#       endif
        /// <summary>The code segment cannot be greater than or equal to 64K.</summary>
#       ifdef ERROR_RING2SEG_MUST_BE_MOVABLE
        error_ring2seg_must_be_movable = ERROR_RING2SEG_MUST_BE_MOVABLE,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_RELOC_CHAIN_XEEDS_SEGLIM
        error_reloc_chain_xeeds_seglim = ERROR_RELOC_CHAIN_XEEDS_SEGLIM,
#       else
#       endif
        /// <summary>The operating system cannot run %1.</summary>
#       ifdef ERROR_INFLOOP_IN_RELOC_CHAIN
        error_infloop_in_reloc_chain = ERROR_INFLOOP_IN_RELOC_CHAIN,
#       else
#       endif
        /// <summary>The system could not find the environment option that was entered.</summary>
#       ifdef ERROR_ENVVAR_NOT_FOUND
        error_envvar_not_found = ERROR_ENVVAR_NOT_FOUND,
#       else
#       endif
        /// <summary>No process in the command subtree has a signal handler.</summary>
#       ifdef ERROR_NO_SIGNAL_SENT
        error_no_signal_sent = ERROR_NO_SIGNAL_SENT,
#       else
#       endif
        /// <summary>The filename or extension is too long.</summary>
#       ifdef ERROR_FILENAME_EXCED_RANGE
        error_filename_exced_range = ERROR_FILENAME_EXCED_RANGE,
#       else
#       endif
        /// <summary>The ring 2 stack is in use.</summary>
#       ifdef ERROR_RING2_STACK_IN_USE
        error_ring2_stack_in_use = ERROR_RING2_STACK_IN_USE,
#       else
#       endif
        /// <summary>The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.</summary>
#       ifdef ERROR_META_EXPANSION_TOO_LONG
        error_meta_expansion_too_long = ERROR_META_EXPANSION_TOO_LONG,
#       else
#       endif
        /// <summary>The signal being posted is not correct.</summary>
#       ifdef ERROR_INVALID_SIGNAL_NUMBER
        error_invalid_signal_number = ERROR_INVALID_SIGNAL_NUMBER,
#       else
#       endif
        /// <summary>The signal handler cannot be set.</summary>
#       ifdef ERROR_THREAD_1_INACTIVE
        error_thread_1_inactive = ERROR_THREAD_1_INACTIVE,
#       else
#       endif
        /// <summary>The segment is locked and cannot be reallocated.</summary>
#       ifdef ERROR_LOCKED
        error_locked = ERROR_LOCKED,
#       else
#       endif
        /// <summary>Too many dynamic-link modules are attached to this program or dynamic-link module.</summary>
#       ifdef ERROR_TOO_MANY_MODULES
        error_too_many_modules = ERROR_TOO_MANY_MODULES,
#       else
#       endif
        /// <summary>Cannot nest calls to LoadModule.</summary>
#       ifdef ERROR_NESTING_NOT_ALLOWED
        error_nesting_not_allowed = ERROR_NESTING_NOT_ALLOWED,
#       else
#       endif
        /// <summary>This version of %1 is not compatible with the version of Windows you're running. Check your computer's system information and then contact the software publisher.</summary>
#       ifdef ERROR_EXE_MACHINE_TYPE_MISMATCH
        error_exe_machine_type_mismatch = ERROR_EXE_MACHINE_TYPE_MISMATCH,
#       else
#       endif
        /// <summary>The image file %1 is signed, unable to modify.</summary>
#       ifdef ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY
        error_exe_cannot_modify_signed_binary = ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY,
#       else
#       endif
        /// <summary>The image file %1 is strong signed, unable to modify.</summary>
#       ifdef ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY
        error_exe_cannot_modify_strong_signed_binary = ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY,
#       else
#       endif
        /// <summary>This file is checked out or locked for editing by another user.</summary>
#       ifdef ERROR_FILE_CHECKED_OUT
        error_file_checked_out = ERROR_FILE_CHECKED_OUT,
#       else
#       endif
        /// <summary>The file must be checked out before saving changes.</summary>
#       ifdef ERROR_CHECKOUT_REQUIRED
        error_checkout_required = ERROR_CHECKOUT_REQUIRED,
#       else
#       endif
        /// <summary>The file type being saved or retrieved has been blocked.</summary>
#       ifdef ERROR_BAD_FILE_TYPE
        error_bad_file_type = ERROR_BAD_FILE_TYPE,
#       else
#       endif
        /// <summary>The file size exceeds the limit allowed and cannot be saved.</summary>
#       ifdef ERROR_FILE_TOO_LARGE
        error_file_too_large = ERROR_FILE_TOO_LARGE,
#       else
#       endif
        /// <summary>Access Denied. Before opening files in this location, you must first add the web site to your trusted sites list, browse to the web site, and select the option to login automatically.</summary>
#       ifdef ERROR_FORMS_AUTH_REQUIRED
        error_forms_auth_required = ERROR_FORMS_AUTH_REQUIRED,
#       else
#       endif
        /// <summary>Operation did not complete successfully because the file contains a virus or potentially unwanted software.</summary>
#       ifdef ERROR_VIRUS_INFECTED
        error_virus_infected = ERROR_VIRUS_INFECTED,
#       else
#       endif
        /// <summary>This file contains a virus or potentially unwanted software and cannot be opened. Due to the nature of this virus or potentially unwanted software, the file has been removed from this location.</summary>
#       ifdef ERROR_VIRUS_DELETED
        error_virus_deleted = ERROR_VIRUS_DELETED,
#       else
#       endif
        /// <summary>The pipe is local.</summary>
#       ifdef ERROR_PIPE_LOCAL
        error_pipe_local = ERROR_PIPE_LOCAL,
#       else
#       endif
        /// <summary>The pipe state is invalid.</summary>
#       ifdef ERROR_BAD_PIPE
        error_bad_pipe = ERROR_BAD_PIPE,
#       else
#       endif
        /// <summary>All pipe instances are busy.</summary>
#       ifdef ERROR_PIPE_BUSY
        error_pipe_busy = ERROR_PIPE_BUSY,
#       else
#       endif
        /// <summary>The pipe is being closed.</summary>
#       ifdef ERROR_NO_DATA
        error_no_data = ERROR_NO_DATA,
#       else
#       endif
        /// <summary>No process is on the other end of the pipe.</summary>
#       ifdef ERROR_PIPE_NOT_CONNECTED
        error_pipe_not_connected = ERROR_PIPE_NOT_CONNECTED,
#       else
#       endif
        /// <summary>More data is available.</summary>
#       ifdef ERROR_MORE_DATA
        error_more_data = ERROR_MORE_DATA,
#       else
#       endif
        /// <summary>The action requested resulted in no work being done. Error-style clean-up has been performed.</summary>
#       ifdef ERROR_NO_WORK_DONE
        error_no_work_done = ERROR_NO_WORK_DONE,
#       else
#       endif
        /// <summary>The session was canceled.</summary>
#       ifdef ERROR_VC_DISCONNECTED
        error_vc_disconnected = ERROR_VC_DISCONNECTED,
#       else
#       endif
        /// <summary>The specified extended attribute name was invalid.</summary>
#       ifdef ERROR_INVALID_EA_NAME
        error_invalid_ea_name = ERROR_INVALID_EA_NAME,
#       else
#       endif
        /// <summary>The extended attributes are inconsistent.</summary>
#       ifdef ERROR_EA_LIST_INCONSISTENT
        error_ea_list_inconsistent = ERROR_EA_LIST_INCONSISTENT,
#       else
#       endif
        /// <summary>The wait operation timed out.</summary>
#       ifdef WAIT_TIMEOUT
        wait_timeout = WAIT_TIMEOUT,
#       else
#       endif
        /// <summary>No more data is available.</summary>
#       ifdef ERROR_NO_MORE_ITEMS
        error_no_more_items = ERROR_NO_MORE_ITEMS,
#       else
#       endif
        /// <summary>The copy functions cannot be used.</summary>
#       ifdef ERROR_CANNOT_COPY
        error_cannot_copy = ERROR_CANNOT_COPY,
#       else
#       endif
        /// <summary>The directory name is invalid.</summary>
#       ifdef ERROR_DIRECTORY
        error_directory = ERROR_DIRECTORY,
#       else
#       endif
        /// <summary>The extended attributes did not fit in the buffer.</summary>
#       ifdef ERROR_EAS_DIDNT_FIT
        error_eas_didnt_fit = ERROR_EAS_DIDNT_FIT,
#       else
#       endif
        /// <summary>The extended attribute file on the mounted file system is corrupt.</summary>
#       ifdef ERROR_EA_FILE_CORRUPT
        error_ea_file_corrupt = ERROR_EA_FILE_CORRUPT,
#       else
#       endif
        /// <summary>The extended attribute table file is full.</summary>
#       ifdef ERROR_EA_TABLE_FULL
        error_ea_table_full = ERROR_EA_TABLE_FULL,
#       else
#       endif
        /// <summary>The specified extended attribute handle is invalid.</summary>
#       ifdef ERROR_INVALID_EA_HANDLE
        error_invalid_ea_handle = ERROR_INVALID_EA_HANDLE,
#       else
#       endif
        /// <summary>The mounted file system does not support extended attributes.</summary>
#       ifdef ERROR_EAS_NOT_SUPPORTED
        error_eas_not_supported = ERROR_EAS_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>Attempt to release mutex not owned by caller.</summary>
#       ifdef ERROR_NOT_OWNER
        error_not_owner = ERROR_NOT_OWNER,
#       else
#       endif
        /// <summary>Too many posts were made to a semaphore.</summary>
#       ifdef ERROR_TOO_MANY_POSTS
        error_too_many_posts = ERROR_TOO_MANY_POSTS,
#       else
#       endif
        /// <summary>Only part of a ReadProcessMemory or WriteProcessMemory request was completed.</summary>
#       ifdef ERROR_PARTIAL_COPY
        error_partial_copy = ERROR_PARTIAL_COPY,
#       else
#       endif
        /// <summary>The oplock request is denied.</summary>
#       ifdef ERROR_OPLOCK_NOT_GRANTED
        error_oplock_not_granted = ERROR_OPLOCK_NOT_GRANTED,
#       else
#       endif
        /// <summary>An invalid oplock acknowledgment was received by the system.</summary>
#       ifdef ERROR_INVALID_OPLOCK_PROTOCOL
        error_invalid_oplock_protocol = ERROR_INVALID_OPLOCK_PROTOCOL,
#       else
#       endif
        /// <summary>The volume is too fragmented to complete this operation.</summary>
#       ifdef ERROR_DISK_TOO_FRAGMENTED
        error_disk_too_fragmented = ERROR_DISK_TOO_FRAGMENTED,
#       else
#       endif
        /// <summary>The file cannot be opened because it is in the process of being deleted.</summary>
#       ifdef ERROR_DELETE_PENDING
        error_delete_pending = ERROR_DELETE_PENDING,
#       else
#       endif
        /// <summary>Short name settings may not be changed on this volume due to the global registry setting.</summary>
#       ifdef ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING
        error_incompatible_with_global_short_name_registry_setting = ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING,
#       else
#       endif
        /// <summary>Short names are not enabled on this volume.</summary>
#       ifdef ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME
        error_short_names_not_enabled_on_volume = ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME,
#       else
#       endif
        /// <summary>The security stream for the given volume is in an inconsistent state.</summary>
        /// <summary>Please run CHKDSK on the volume.</summary>
#       ifdef ERROR_SECURITY_STREAM_IS_INCONSISTENT
        error_security_stream_is_inconsistent = ERROR_SECURITY_STREAM_IS_INCONSISTENT,
#       else
#       endif
        /// <summary>A requested file lock operation cannot be processed due to an invalid byte range.</summary>
#       ifdef ERROR_INVALID_LOCK_RANGE
        error_invalid_lock_range = ERROR_INVALID_LOCK_RANGE,
#       else
#       endif
        /// <summary>The subsystem needed to support the image type is not present.</summary>
#       ifdef ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT
        error_image_subsystem_not_present = ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT,
#       else
#       endif
        /// <summary>The specified file already has a notification GUID associated with it.</summary>
#       ifdef ERROR_NOTIFICATION_GUID_ALREADY_DEFINED
        error_notification_guid_already_defined = ERROR_NOTIFICATION_GUID_ALREADY_DEFINED,
#       else
#       endif
        /// <summary>An invalid exception handler routine has been detected.</summary>
#       ifdef ERROR_INVALID_EXCEPTION_HANDLER
        error_invalid_exception_handler = ERROR_INVALID_EXCEPTION_HANDLER,
#       else
#       endif
        /// <summary>Duplicate privileges were specified for the token.</summary>
#       ifdef ERROR_DUPLICATE_PRIVILEGES
        error_duplicate_privileges = ERROR_DUPLICATE_PRIVILEGES,
#       else
#       endif
        /// <summary>No ranges for the specified operation were able to be processed.</summary>
#       ifdef ERROR_NO_RANGES_PROCESSED
        error_no_ranges_processed = ERROR_NO_RANGES_PROCESSED,
#       else
#       endif
        /// <summary>Operation is not allowed on a file system internal file.</summary>
#       ifdef ERROR_NOT_ALLOWED_ON_SYSTEM_FILE
        error_not_allowed_on_system_file = ERROR_NOT_ALLOWED_ON_SYSTEM_FILE,
#       else
#       endif
        /// <summary>The physical resources of this disk have been exhausted.</summary>
#       ifdef ERROR_DISK_RESOURCES_EXHAUSTED
        error_disk_resources_exhausted = ERROR_DISK_RESOURCES_EXHAUSTED,
#       else
#       endif
        /// <summary>The token representing the data is invalid.</summary>
#       ifdef ERROR_INVALID_TOKEN
        error_invalid_token = ERROR_INVALID_TOKEN,
#       else
#       endif
        /// <summary>The device does not support the command feature.</summary>
#       ifdef ERROR_DEVICE_FEATURE_NOT_SUPPORTED
        error_device_feature_not_supported = ERROR_DEVICE_FEATURE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The system cannot find message text for message number 0x%1 in the message file for %2.</summary>
#       ifdef ERROR_MR_MID_NOT_FOUND
        error_mr_mid_not_found = ERROR_MR_MID_NOT_FOUND,
#       else
#       endif
        /// <summary>The scope specified was not found.</summary>
#       ifdef ERROR_SCOPE_NOT_FOUND
        error_scope_not_found = ERROR_SCOPE_NOT_FOUND,
#       else
#       endif
        /// <summary>The Central Access Policy specified is not defined on the target machine.</summary>
#       ifdef ERROR_UNDEFINED_SCOPE
        error_undefined_scope = ERROR_UNDEFINED_SCOPE,
#       else
#       endif
        /// <summary>The Central Access Policy obtained from Active Directory is invalid.</summary>
#       ifdef ERROR_INVALID_CAP
        error_invalid_cap = ERROR_INVALID_CAP,
#       else
#       endif
        /// <summary>The device is unreachable.</summary>
#       ifdef ERROR_DEVICE_UNREACHABLE
        error_device_unreachable = ERROR_DEVICE_UNREACHABLE,
#       else
#       endif
        /// <summary>The target device has insufficient resources to complete the operation.</summary>
#       ifdef ERROR_DEVICE_NO_RESOURCES
        error_device_no_resources = ERROR_DEVICE_NO_RESOURCES,
#       else
#       endif
        /// <summary>A data integrity checksum error occurred. Data in the file stream is corrupt.</summary>
#       ifdef ERROR_DATA_CHECKSUM_ERROR
        error_data_checksum_error = ERROR_DATA_CHECKSUM_ERROR,
#       else
#       endif
        /// <summary>An attempt was made to modify both a KERNEL and normal Extended Attribute (EA) in the same operation.</summary>
#       ifdef ERROR_INTERMIXED_KERNEL_EA_OPERATION
        error_intermixed_kernel_ea_operation = ERROR_INTERMIXED_KERNEL_EA_OPERATION,
#       else
#       endif
        /// <summary>Device does not support file-level TRIM.</summary>
#       ifdef ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED
        error_file_level_trim_not_supported = ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The command specified a data offset that does not align to the device's granularity/alignment.</summary>
#       ifdef ERROR_OFFSET_ALIGNMENT_VIOLATION
        error_offset_alignment_violation = ERROR_OFFSET_ALIGNMENT_VIOLATION,
#       else
#       endif
        /// <summary>The command specified an invalid field in its parameter list.</summary>
#       ifdef ERROR_INVALID_FIELD_IN_PARAMETER_LIST
        error_invalid_field_in_parameter_list = ERROR_INVALID_FIELD_IN_PARAMETER_LIST,
#       else
#       endif
        /// <summary>An operation is currently in progress with the device.</summary>
#       ifdef ERROR_OPERATION_IN_PROGRESS
        error_operation_in_progress = ERROR_OPERATION_IN_PROGRESS,
#       else
#       endif
        /// <summary>An attempt was made to send down the command via an invalid path to the target device.</summary>
#       ifdef ERROR_BAD_DEVICE_PATH
        error_bad_device_path = ERROR_BAD_DEVICE_PATH,
#       else
#       endif
        /// <summary>The command specified a number of descriptors that exceeded the maximum supported by the device.</summary>
#       ifdef ERROR_TOO_MANY_DESCRIPTORS
        error_too_many_descriptors = ERROR_TOO_MANY_DESCRIPTORS,
#       else
#       endif
        /// <summary>Scrub is disabled on the specified file.</summary>
#       ifdef ERROR_SCRUB_DATA_DISABLED
        error_scrub_data_disabled = ERROR_SCRUB_DATA_DISABLED,
#       else
#       endif
        /// <summary>The storage device does not provide redundancy.</summary>
#       ifdef ERROR_NOT_REDUNDANT_STORAGE
        error_not_redundant_storage = ERROR_NOT_REDUNDANT_STORAGE,
#       else
#       endif
        /// <summary>An operation is not supported on a resident file.</summary>
#       ifdef ERROR_RESIDENT_FILE_NOT_SUPPORTED
        error_resident_file_not_supported = ERROR_RESIDENT_FILE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>An operation is not supported on a compressed file.</summary>
#       ifdef ERROR_COMPRESSED_FILE_NOT_SUPPORTED
        error_compressed_file_not_supported = ERROR_COMPRESSED_FILE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>An operation is not supported on a directory.</summary>
#       ifdef ERROR_DIRECTORY_NOT_SUPPORTED
        error_directory_not_supported = ERROR_DIRECTORY_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The specified copy of the requested data could not be read.</summary>
#       ifdef ERROR_NOT_READ_FROM_COPY
        error_not_read_from_copy = ERROR_NOT_READ_FROM_COPY,
#       else
#       endif
        /// <summary>The specified data could not be written to any of the copies.</summary>
#       ifdef ERROR_FT_WRITE_FAILURE
        error_ft_write_failure = ERROR_FT_WRITE_FAILURE,
#       else
#       endif
        /// <summary>One or more copies of data on this device may be out of sync. No writes may be performed until a data integrity scan is completed.</summary>
#       ifdef ERROR_FT_DI_SCAN_REQUIRED
        error_ft_di_scan_required = ERROR_FT_DI_SCAN_REQUIRED,
#       else
#       endif
        /// <summary>The supplied kernel information version is invalid.</summary>
#       ifdef ERROR_INVALID_KERNEL_INFO_VERSION
        error_invalid_kernel_info_version = ERROR_INVALID_KERNEL_INFO_VERSION,
#       else
#       endif
        /// <summary>The supplied PEP information version is invalid.</summary>
#       ifdef ERROR_INVALID_PEP_INFO_VERSION
        error_invalid_pep_info_version = ERROR_INVALID_PEP_INFO_VERSION,
#       else
#       endif
        /// <summary>This object is not externally backed by any provider.</summary>
#       ifdef ERROR_OBJECT_NOT_EXTERNALLY_BACKED
        error_object_not_externally_backed = ERROR_OBJECT_NOT_EXTERNALLY_BACKED,
#       else
#       endif
        /// <summary>The external backing provider is not recognized.</summary>
#       ifdef ERROR_EXTERNAL_BACKING_PROVIDER_UNKNOWN
        error_external_backing_provider_unknown = ERROR_EXTERNAL_BACKING_PROVIDER_UNKNOWN,
#       else
#       endif
        /// <summary>Compressing this object would not save space.</summary>
#       ifdef ERROR_COMPRESSION_NOT_BENEFICIAL
        error_compression_not_beneficial = ERROR_COMPRESSION_NOT_BENEFICIAL,
#       else
#       endif
        /// <summary>The request failed due to a storage topology ID mismatch.</summary>
#       ifdef ERROR_STORAGE_TOPOLOGY_ID_MISMATCH
        error_storage_topology_id_mismatch = ERROR_STORAGE_TOPOLOGY_ID_MISMATCH,
#       else
#       endif
        /// <summary>The operation was blocked by parental controls.</summary>
#       ifdef ERROR_BLOCKED_BY_PARENTAL_CONTROLS
        error_blocked_by_parental_controls = ERROR_BLOCKED_BY_PARENTAL_CONTROLS,
#       else
#       endif
        /// <summary>A file system block being referenced has already reached the maximum reference count and can't be referenced any further.</summary>
#       ifdef ERROR_BLOCK_TOO_MANY_REFERENCES
        error_block_too_many_references = ERROR_BLOCK_TOO_MANY_REFERENCES,
#       else
#       endif
        /// <summary>The requested operation failed because the file stream is marked to disallow writes.</summary>
#       ifdef ERROR_MARKED_TO_DISALLOW_WRITES
        error_marked_to_disallow_writes = ERROR_MARKED_TO_DISALLOW_WRITES,
#       else
#       endif
        /// <summary>The requested operation failed with an architecture-specific failure code.</summary>
#       ifdef ERROR_ENCLAVE_FAILURE
        error_enclave_failure = ERROR_ENCLAVE_FAILURE,
#       else
#       endif
        /// <summary>No action was taken as a system reboot is required.</summary>
#       ifdef ERROR_FAIL_NOACTION_REBOOT
        error_fail_noaction_reboot = ERROR_FAIL_NOACTION_REBOOT,
#       else
#       endif
        /// <summary>The shutdown operation failed.</summary>
#       ifdef ERROR_FAIL_SHUTDOWN
        error_fail_shutdown = ERROR_FAIL_SHUTDOWN,
#       else
#       endif
        /// <summary>The restart operation failed.</summary>
#       ifdef ERROR_FAIL_RESTART
        error_fail_restart = ERROR_FAIL_RESTART,
#       else
#       endif
        /// <summary>The maximum number of sessions has been reached.</summary>
#       ifdef ERROR_MAX_SESSIONS_REACHED
        error_max_sessions_reached = ERROR_MAX_SESSIONS_REACHED,
#       else
#       endif
        /// <summary>Windows Information Protection policy does not allow access to this network resource.</summary>
#       ifdef ERROR_NETWORK_ACCESS_DENIED_EDP
        error_network_access_denied_edp = ERROR_NETWORK_ACCESS_DENIED_EDP,
#       else
#       endif
        /// <summary>The device hint name buffer is too small to receive the remaining name.</summary>
#       ifdef ERROR_DEVICE_HINT_NAME_BUFFER_TOO_SMALL
        error_device_hint_name_buffer_too_small = ERROR_DEVICE_HINT_NAME_BUFFER_TOO_SMALL,
#       else
#       endif
        /// <summary>The requested operation was blocked by Windows Information Protection policy. For more information, contact your system administrator.</summary>
#       ifdef ERROR_EDP_POLICY_DENIES_OPERATION
        error_edp_policy_denies_operation = ERROR_EDP_POLICY_DENIES_OPERATION,
#       else
#       endif
        /// <summary>The requested operation cannot be performed because hardware or software configuration of the device does not comply with Windows Information Protection under Lock policy. Please, verify that user PIN has been created. For more information, contact your system administrator.</summary>
#       ifdef ERROR_EDP_DPL_POLICY_CANT_BE_SATISFIED
        error_edp_dpl_policy_cant_be_satisfied = ERROR_EDP_DPL_POLICY_CANT_BE_SATISFIED,
#       else
#       endif
        /// <summary>The cloud sync root metadata is corrupted.</summary>
#       ifdef ERROR_CLOUD_FILE_SYNC_ROOT_METADATA_CORRUPT
        error_cloud_file_sync_root_metadata_corrupt = ERROR_CLOUD_FILE_SYNC_ROOT_METADATA_CORRUPT,
#       else
#       endif
        /// <summary>The device is in maintenance mode.</summary>
#       ifdef ERROR_DEVICE_IN_MAINTENANCE
        error_device_in_maintenance = ERROR_DEVICE_IN_MAINTENANCE,
#       else
#       endif
        /// <summary>This operation is not supported on a DAX volume.</summary>
#       ifdef ERROR_NOT_SUPPORTED_ON_DAX
        error_not_supported_on_dax = ERROR_NOT_SUPPORTED_ON_DAX,
#       else
#       endif
        /// <summary>The volume has active DAX mappings.</summary>
#       ifdef ERROR_DAX_MAPPING_EXISTS
        error_dax_mapping_exists = ERROR_DAX_MAPPING_EXISTS,
#       else
#       endif
        /// <summary>The cloud file provider is not running.</summary>
#       ifdef ERROR_CLOUD_FILE_PROVIDER_NOT_RUNNING
        error_cloud_file_provider_not_running = ERROR_CLOUD_FILE_PROVIDER_NOT_RUNNING,
#       else
#       endif
        /// <summary>The cloud file metadata is corrupt and unreadable.</summary>
#       ifdef ERROR_CLOUD_FILE_METADATA_CORRUPT
        error_cloud_file_metadata_corrupt = ERROR_CLOUD_FILE_METADATA_CORRUPT,
#       else
#       endif
        /// <summary>The cloud file metadata is too large.</summary>
#       ifdef ERROR_CLOUD_FILE_METADATA_TOO_LARGE
        error_cloud_file_metadata_too_large = ERROR_CLOUD_FILE_METADATA_TOO_LARGE,
#       else
#       endif
        /// <summary>The cloud file property is too large.</summary>
#       ifdef ERROR_CLOUD_FILE_PROPERTY_BLOB_TOO_LARGE
        error_cloud_file_property_blob_too_large = ERROR_CLOUD_FILE_PROPERTY_BLOB_TOO_LARGE,
#       else
#       endif
        /// <summary>The cloud file property is possibly corrupt. The on-disk checksum does not match the computed checksum.</summary>
#       ifdef ERROR_CLOUD_FILE_PROPERTY_BLOB_CHECKSUM_MISMATCH
        error_cloud_file_property_blob_checksum_mismatch = ERROR_CLOUD_FILE_PROPERTY_BLOB_CHECKSUM_MISMATCH,
#       else
#       endif
        /// <summary>The process creation has been blocked.</summary>
#       ifdef ERROR_CHILD_PROCESS_BLOCKED
        error_child_process_blocked = ERROR_CHILD_PROCESS_BLOCKED,
#       else
#       endif
        /// <summary>The storage device has lost data or persistence.</summary>
#       ifdef ERROR_STORAGE_LOST_DATA_PERSISTENCE
        error_storage_lost_data_persistence = ERROR_STORAGE_LOST_DATA_PERSISTENCE,
#       else
#       endif
        /// <summary>The provider that supports file system virtualization is temporarily unavailable.</summary>
#       ifdef ERROR_FILE_SYSTEM_VIRTUALIZATION_UNAVAILABLE
        error_file_system_virtualization_unavailable = ERROR_FILE_SYSTEM_VIRTUALIZATION_UNAVAILABLE,
#       else
#       endif
        /// <summary>The metadata for file system virtualization is corrupt and unreadable.</summary>
#       ifdef ERROR_FILE_SYSTEM_VIRTUALIZATION_METADATA_CORRUPT
        error_file_system_virtualization_metadata_corrupt = ERROR_FILE_SYSTEM_VIRTUALIZATION_METADATA_CORRUPT,
#       else
#       endif
        /// <summary>The provider that supports file system virtualization is too busy to complete this operation.</summary>
#       ifdef ERROR_FILE_SYSTEM_VIRTUALIZATION_BUSY
        error_file_system_virtualization_busy = ERROR_FILE_SYSTEM_VIRTUALIZATION_BUSY,
#       else
#       endif
        /// <summary>The provider that supports file system virtualization is unknown.</summary>
#       ifdef ERROR_FILE_SYSTEM_VIRTUALIZATION_PROVIDER_UNKNOWN
        error_file_system_virtualization_provider_unknown = ERROR_FILE_SYSTEM_VIRTUALIZATION_PROVIDER_UNKNOWN,
#       else
#       endif
        /// <summary>GDI handles were potentially leaked by the application.</summary>
#       ifdef ERROR_GDI_HANDLE_LEAK
        error_gdi_handle_leak = ERROR_GDI_HANDLE_LEAK,
#       else
#       endif
        /// <summary>The maximum number of cloud file properties has been reached.</summary>
#       ifdef ERROR_CLOUD_FILE_TOO_MANY_PROPERTY_BLOBS
        error_cloud_file_too_many_property_blobs = ERROR_CLOUD_FILE_TOO_MANY_PROPERTY_BLOBS,
#       else
#       endif
        /// <summary>The version of the cloud file property store is not supported.</summary>
#       ifdef ERROR_CLOUD_FILE_PROPERTY_VERSION_NOT_SUPPORTED
        error_cloud_file_property_version_not_supported = ERROR_CLOUD_FILE_PROPERTY_VERSION_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The file is not a cloud file.</summary>
#       ifdef ERROR_NOT_A_CLOUD_FILE
        error_not_a_cloud_file = ERROR_NOT_A_CLOUD_FILE,
#       else
#       endif
        /// <summary>The file is not in sync with the cloud.</summary>
#       ifdef ERROR_CLOUD_FILE_NOT_IN_SYNC
        error_cloud_file_not_in_sync = ERROR_CLOUD_FILE_NOT_IN_SYNC,
#       else
#       endif
        /// <summary>The cloud sync root is already connected with another cloud sync provider.</summary>
#       ifdef ERROR_CLOUD_FILE_ALREADY_CONNECTED
        error_cloud_file_already_connected = ERROR_CLOUD_FILE_ALREADY_CONNECTED,
#       else
#       endif
        /// <summary>The operation is not supported by the cloud sync provider.</summary>
#       ifdef ERROR_CLOUD_FILE_NOT_SUPPORTED
        error_cloud_file_not_supported = ERROR_CLOUD_FILE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The cloud operation is invalid.</summary>
#       ifdef ERROR_CLOUD_FILE_INVALID_REQUEST
        error_cloud_file_invalid_request = ERROR_CLOUD_FILE_INVALID_REQUEST,
#       else
#       endif
        /// <summary>The cloud operation is not supported on a read-only volume.</summary>
#       ifdef ERROR_CLOUD_FILE_READ_ONLY_VOLUME
        error_cloud_file_read_only_volume = ERROR_CLOUD_FILE_READ_ONLY_VOLUME,
#       else
#       endif
        /// <summary>The operation is reserved for a connected cloud sync provider.</summary>
#       ifdef ERROR_CLOUD_FILE_CONNECTED_PROVIDER_ONLY
        error_cloud_file_connected_provider_only = ERROR_CLOUD_FILE_CONNECTED_PROVIDER_ONLY,
#       else
#       endif
        /// <summary>The cloud sync provider failed to validate the downloaded data.</summary>
#       ifdef ERROR_CLOUD_FILE_VALIDATION_FAILED
        error_cloud_file_validation_failed = ERROR_CLOUD_FILE_VALIDATION_FAILED,
#       else
#       endif
        /// <summary>You can't connect to the file share because it's not secure. This share requires the obsolete SMB1 protocol, which is unsafe and could expose your system to attack.</summary>
        /// <summary>Your system requires SMB2 or higher. For more info on resolving this issue, see: https://go.microsoft.com/fwlink/?linkid=852747</summary>
#       ifdef ERROR_SMB1_NOT_AVAILABLE
        error_smb1_not_available = ERROR_SMB1_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>The virtualization operation is not allowed on the file in its current state.</summary>
#       ifdef ERROR_FILE_SYSTEM_VIRTUALIZATION_INVALID_OPERATION
        error_file_system_virtualization_invalid_operation = ERROR_FILE_SYSTEM_VIRTUALIZATION_INVALID_OPERATION,
#       else
#       endif
        /// <summary>The cloud sync provider failed user authentication.</summary>
#       ifdef ERROR_CLOUD_FILE_AUTHENTICATION_FAILED
        error_cloud_file_authentication_failed = ERROR_CLOUD_FILE_AUTHENTICATION_FAILED,
#       else
#       endif
        /// <summary>The cloud sync provider failed to perform the operation due to low system resources.</summary>
#       ifdef ERROR_CLOUD_FILE_INSUFFICIENT_RESOURCES
        error_cloud_file_insufficient_resources = ERROR_CLOUD_FILE_INSUFFICIENT_RESOURCES,
#       else
#       endif
        /// <summary>The cloud sync provider failed to perform the operation due to network being unavailable.</summary>
#       ifdef ERROR_CLOUD_FILE_NETWORK_UNAVAILABLE
        error_cloud_file_network_unavailable = ERROR_CLOUD_FILE_NETWORK_UNAVAILABLE,
#       else
#       endif
        /// <summary>The cloud operation was unsuccessful.</summary>
#       ifdef ERROR_CLOUD_FILE_UNSUCCESSFUL
        error_cloud_file_unsuccessful = ERROR_CLOUD_FILE_UNSUCCESSFUL,
#       else
#       endif
        /// <summary>The operation is only supported on files under a cloud sync root.</summary>
#       ifdef ERROR_CLOUD_FILE_NOT_UNDER_SYNC_ROOT
        error_cloud_file_not_under_sync_root = ERROR_CLOUD_FILE_NOT_UNDER_SYNC_ROOT,
#       else
#       endif
        /// <summary>The operation cannot be performed on cloud files in use.</summary>
#       ifdef ERROR_CLOUD_FILE_IN_USE
        error_cloud_file_in_use = ERROR_CLOUD_FILE_IN_USE,
#       else
#       endif
        /// <summary>The operation cannot be performed on pinned cloud files.</summary>
#       ifdef ERROR_CLOUD_FILE_PINNED
        error_cloud_file_pinned = ERROR_CLOUD_FILE_PINNED,
#       else
#       endif
        /// <summary>The cloud operation was aborted.</summary>
#       ifdef ERROR_CLOUD_FILE_REQUEST_ABORTED
        error_cloud_file_request_aborted = ERROR_CLOUD_FILE_REQUEST_ABORTED,
#       else
#       endif
        /// <summary>The cloud file's property store is corrupt.</summary>
#       ifdef ERROR_CLOUD_FILE_PROPERTY_CORRUPT
        error_cloud_file_property_corrupt = ERROR_CLOUD_FILE_PROPERTY_CORRUPT,
#       else
#       endif
        /// <summary>Access to the cloud file is denied.</summary>
#       ifdef ERROR_CLOUD_FILE_ACCESS_DENIED
        error_cloud_file_access_denied = ERROR_CLOUD_FILE_ACCESS_DENIED,
#       else
#       endif
        /// <summary>The cloud operation cannot be performed on a file with incompatible hardlinks.</summary>
#       ifdef ERROR_CLOUD_FILE_INCOMPATIBLE_HARDLINKS
        error_cloud_file_incompatible_hardlinks = ERROR_CLOUD_FILE_INCOMPATIBLE_HARDLINKS,
#       else
#       endif
        /// <summary>The operation failed due to a conflicting cloud file property lock.</summary>
#       ifdef ERROR_CLOUD_FILE_PROPERTY_LOCK_CONFLICT
        error_cloud_file_property_lock_conflict = ERROR_CLOUD_FILE_PROPERTY_LOCK_CONFLICT,
#       else
#       endif
        /// <summary>The cloud operation was canceled by user.</summary>
#       ifdef ERROR_CLOUD_FILE_REQUEST_CANCELED
        error_cloud_file_request_canceled = ERROR_CLOUD_FILE_REQUEST_CANCELED,
#       else
#       endif
        /// <summary>An externally encrypted syskey has been configured, but the system no longer supports this feature.  Please see https://go.microsoft.com/fwlink/?linkid=851152 for more information.</summary>
#       ifdef ERROR_EXTERNAL_SYSKEY_NOT_SUPPORTED
        error_external_syskey_not_supported = ERROR_EXTERNAL_SYSKEY_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The thread is already in background processing mode.</summary>
#       ifdef ERROR_THREAD_MODE_ALREADY_BACKGROUND
        error_thread_mode_already_background = ERROR_THREAD_MODE_ALREADY_BACKGROUND,
#       else
#       endif
        /// <summary>The thread is not in background processing mode.</summary>
#       ifdef ERROR_THREAD_MODE_NOT_BACKGROUND
        error_thread_mode_not_background = ERROR_THREAD_MODE_NOT_BACKGROUND,
#       else
#       endif
        /// <summary>The process is already in background processing mode.</summary>
#       ifdef ERROR_PROCESS_MODE_ALREADY_BACKGROUND
        error_process_mode_already_background = ERROR_PROCESS_MODE_ALREADY_BACKGROUND,
#       else
#       endif
        /// <summary>The process is not in background processing mode.</summary>
#       ifdef ERROR_PROCESS_MODE_NOT_BACKGROUND
        error_process_mode_not_background = ERROR_PROCESS_MODE_NOT_BACKGROUND,
#       else
#       endif
        /// <summary>The cloud file provider exited unexpectedly.</summary>
#       ifdef ERROR_CLOUD_FILE_PROVIDER_TERMINATED
        error_cloud_file_provider_terminated = ERROR_CLOUD_FILE_PROVIDER_TERMINATED,
#       else
#       endif
        /// <summary>The file is not a cloud sync root.</summary>
#       ifdef ERROR_NOT_A_CLOUD_SYNC_ROOT
        error_not_a_cloud_sync_root = ERROR_NOT_A_CLOUD_SYNC_ROOT,
#       else
#       endif
        /// <summary>The read or write operation to an encrypted file could not be completed because the file can only be accessed when the device is unlocked.</summary>
#       ifdef ERROR_FILE_PROTECTED_UNDER_DPL
        error_file_protected_under_dpl = ERROR_FILE_PROTECTED_UNDER_DPL,
#       else
#       endif
        /// <summary>The volume is not cluster aligned on the disk.</summary>
#       ifdef ERROR_VOLUME_NOT_CLUSTER_ALIGNED
        error_volume_not_cluster_aligned = ERROR_VOLUME_NOT_CLUSTER_ALIGNED,
#       else
#       endif
        /// <summary>No physically aligned free space was found on the volume.</summary>
#       ifdef ERROR_NO_PHYSICALLY_ALIGNED_FREE_SPACE_FOUND
        error_no_physically_aligned_free_space_found = ERROR_NO_PHYSICALLY_ALIGNED_FREE_SPACE_FOUND,
#       else
#       endif
        /// <summary>The APPX file can not be accessed because it is not encrypted as expected.</summary>
#       ifdef ERROR_APPX_FILE_NOT_ENCRYPTED
        error_appx_file_not_encrypted = ERROR_APPX_FILE_NOT_ENCRYPTED,
#       else
#       endif
        /// <summary>A read or write of raw encrypted data cannot be performed because the file is not encrypted.</summary>
#       ifdef ERROR_RWRAW_ENCRYPTED_FILE_NOT_ENCRYPTED
        error_rwraw_encrypted_file_not_encrypted = ERROR_RWRAW_ENCRYPTED_FILE_NOT_ENCRYPTED,
#       else
#       endif
        /// <summary>An invalid file offset in the encrypted data info block was passed for read or write operation of file's raw encrypted data.</summary>
#       ifdef ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILEOFFSET
        error_rwraw_encrypted_invalid_edatainfo_fileoffset = ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILEOFFSET,
#       else
#       endif
        /// <summary>An invalid offset and length combination in the encrypted data info block was passed for read or write operation of file's raw encrypted data.</summary>
#       ifdef ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILERANGE
        error_rwraw_encrypted_invalid_edatainfo_filerange = ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILERANGE,
#       else
#       endif
        /// <summary>An invalid parameter in the encrypted data info block was passed for read or write operation of file's raw encrypted data.</summary>
#       ifdef ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_PARAMETER
        error_rwraw_encrypted_invalid_edatainfo_parameter = ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_PARAMETER,
#       else
#       endif
        /// <summary>The Windows Subsystem for Linux has not been enabled.</summary>
#       ifdef ERROR_LINUX_SUBSYSTEM_NOT_PRESENT
        error_linux_subsystem_not_present = ERROR_LINUX_SUBSYSTEM_NOT_PRESENT,
#       else
#       endif
        /// <summary>The specified data could not be read from any of the copies.</summary>
#       ifdef ERROR_FT_READ_FAILURE
        error_ft_read_failure = ERROR_FT_READ_FAILURE,
#       else
#       endif
        /// <summary>The specified storage reserve ID is invalid.</summary>
#       ifdef ERROR_STORAGE_RESERVE_ID_INVALID
        error_storage_reserve_id_invalid = ERROR_STORAGE_RESERVE_ID_INVALID,
#       else
#       endif
        /// <summary>The specified storage reserve does not exist.</summary>
#       ifdef ERROR_STORAGE_RESERVE_DOES_NOT_EXIST
        error_storage_reserve_does_not_exist = ERROR_STORAGE_RESERVE_DOES_NOT_EXIST,
#       else
#       endif
        /// <summary>The specified storage reserve already exists.</summary>
#       ifdef ERROR_STORAGE_RESERVE_ALREADY_EXISTS
        error_storage_reserve_already_exists = ERROR_STORAGE_RESERVE_ALREADY_EXISTS,
#       else
#       endif
        /// <summary>The specified storage reserve is not empty.</summary>
#       ifdef ERROR_STORAGE_RESERVE_NOT_EMPTY
        error_storage_reserve_not_empty = ERROR_STORAGE_RESERVE_NOT_EMPTY,
#       else
#       endif
        /// <summary>This operation requires a DAX volume.</summary>
#       ifdef ERROR_NOT_A_DAX_VOLUME
        error_not_a_dax_volume = ERROR_NOT_A_DAX_VOLUME,
#       else
#       endif
        /// <summary>This stream is not DAX mappable.</summary>
#       ifdef ERROR_NOT_DAX_MAPPABLE
        error_not_dax_mappable = ERROR_NOT_DAX_MAPPABLE,
#       else
#       endif
        /// <summary>Operation cannot be performed on a time critical thread.</summary>
#       ifdef ERROR_TIME_SENSITIVE_THREAD
        error_time_sensitive_thread = ERROR_TIME_SENSITIVE_THREAD,
#       else
#       endif
        /// <summary>User data protection is not supported for the current or provided user.</summary>
#       ifdef ERROR_DPL_NOT_SUPPORTED_FOR_USER
        error_dpl_not_supported_for_user = ERROR_DPL_NOT_SUPPORTED_FOR_USER,
#       else
#       endif
        /// <summary>This directory contains entries whose names differ only in case.</summary>
#       ifdef ERROR_CASE_DIFFERING_NAMES_IN_DIR
        error_case_differing_names_in_dir = ERROR_CASE_DIFFERING_NAMES_IN_DIR,
#       else
#       endif
        /// <summary>The file cannot be safely opened because it is not supported by this version of Windows.</summary>
#       ifdef ERROR_FILE_NOT_SUPPORTED
        error_file_not_supported = ERROR_FILE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The cloud operation was not completed before the time-out period expired.</summary>
#       ifdef ERROR_CLOUD_FILE_REQUEST_TIMEOUT
        error_cloud_file_request_timeout = ERROR_CLOUD_FILE_REQUEST_TIMEOUT,
#       else
#       endif
        /// <summary>A task queue is required for this operation but none is available.</summary>
#       ifdef ERROR_NO_TASK_QUEUE
        error_no_task_queue = ERROR_NO_TASK_QUEUE,
#       else
#       endif
        /// <summary>Failed loading a valid version of srcsrv.dll.</summary>
#       ifdef ERROR_SRC_SRV_DLL_LOAD_FAILED
        error_src_srv_dll_load_failed = ERROR_SRC_SRV_DLL_LOAD_FAILED,
#       else
#       endif
        /// <summary>This operation is not supported with BTT enabled.</summary>
#       ifdef ERROR_NOT_SUPPORTED_WITH_BTT
        error_not_supported_with_btt = ERROR_NOT_SUPPORTED_WITH_BTT,
#       else
#       endif

#       ifdef ERROR_ENCRYPTION_DISABLED
        /// <summary>This operation cannot be performed because encryption is currently disabled.</summary>
        error_encryption_disabled = ERROR_ENCRYPTION_DISABLED,
#       else
#       endif

#       ifdef ERROR_ENCRYPTING_METADATA_DISALLOWED
        /// <summary>This encryption operation cannot be performed on filesystem metadata.</summary>
        error_encrypting_metadata_disallowed = ERROR_ENCRYPTING_METADATA_DISALLOWED,
#       else
#       endif

#       ifdef ERROR_CANT_CLEAR_ENCRYPTION_FLAG
        /// <summary>Encryption cannot be cleared on this file/directory because it still has an encrypted attribute.</summary>
        error_cant_clear_encryption_flag = ERROR_CANT_CLEAR_ENCRYPTION_FLAG,
#       else
#       endif

#       ifdef ERROR_NO_SUCH_DEVICE
        /// <summary>A device which does not exist was specified.</summary>
        error_no_such_device = ERROR_NO_SUCH_DEVICE,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_NOT_DEVUNLOCKED
        /// <summary>Neither developer unlocked mode nor side loading mode is enabled on the device.</summary>
        error_capauthz_not_devunlocked = ERROR_CAPAUTHZ_NOT_DEVUNLOCKED,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_CHANGE_TYPE
        /// <summary>Can not change application type during upgrade or re-provision.</summary>
        error_capauthz_change_type = ERROR_CAPAUTHZ_CHANGE_TYPE,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_NOT_PROVISIONED
        /// <summary>The application has not been provisioned.</summary>
        error_capauthz_not_provisioned = ERROR_CAPAUTHZ_NOT_PROVISIONED,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_NOT_AUTHORIZED
        /// <summary>The requested capability can not be authorized for this application.</summary>
        error_capauthz_not_authorized = ERROR_CAPAUTHZ_NOT_AUTHORIZED,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_NO_POLICY
        /// <summary>There is no capability authorization policy on the device.</summary>
        error_capauthz_no_policy = ERROR_CAPAUTHZ_NO_POLICY,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_DB_CORRUPTED
        /// <summary>The capability authorization database has been corrupted.</summary>
        error_capauthz_db_corrupted = ERROR_CAPAUTHZ_DB_CORRUPTED,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_SCCD_INVALID_CATALOG
        /// <summary>The custom capability's SCCD has an invalid catalog.</summary>
        error_capauthz_sccd_invalid_catalog = ERROR_CAPAUTHZ_SCCD_INVALID_CATALOG,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_SCCD_NO_AUTH_ENTITY
        /// <summary>None of the authorized entity elements in the SCCD matched the app being installed; either the PFNs don't match, or the element's signature hash doesn't validate.</summary>
        error_capauthz_sccd_no_auth_entity = ERROR_CAPAUTHZ_SCCD_NO_AUTH_ENTITY,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_SCCD_PARSE_ERROR
        /// <summary>The custom capability's SCCD failed to parse.</summary>
        error_capauthz_sccd_parse_error = ERROR_CAPAUTHZ_SCCD_PARSE_ERROR,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_SCCD_DEV_MODE_REQUIRED
        /// <summary>The custom capability's SCCD requires developer mode.</summary>
        error_capauthz_sccd_dev_mode_required = ERROR_CAPAUTHZ_SCCD_DEV_MODE_REQUIRED,
#       else
#       endif

#       ifdef ERROR_CAPAUTHZ_SCCD_NO_CAPABILITY_MATCH
        /// <summary>There not all declared custom capabilities are found in the SCCD.</summary>
        error_capauthz_sccd_no_capability_match = ERROR_CAPAUTHZ_SCCD_NO_CAPABILITY_MATCH,
#       else
#       endif

#       ifdef ERROR_PNP_QUERY_REMOVE_DEVICE_TIMEOUT
        /// <summary>The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in its device stack. The system may need to be rebooted to complete the request.</summary>
        error_pnp_query_remove_device_timeout = ERROR_PNP_QUERY_REMOVE_DEVICE_TIMEOUT,
#       else
#       endif

#       ifdef ERROR_PNP_QUERY_REMOVE_RELATED_DEVICE_TIMEOUT
        /// <summary>The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in the device stack of a related device. The system may need to be rebooted to complete the operation.</summary>
        error_pnp_query_remove_related_device_timeout = ERROR_PNP_QUERY_REMOVE_RELATED_DEVICE_TIMEOUT,
#       else
#       endif

#       ifdef ERROR_PNP_QUERY_REMOVE_UNRELATED_DEVICE_TIMEOUT
        /// <summary>The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in the device stack of an unrelated device. The system may need to be rebooted to complete the operation.</summary>
        error_pnp_query_remove_unrelated_device_timeout = ERROR_PNP_QUERY_REMOVE_UNRELATED_DEVICE_TIMEOUT,
#       else
#       endif

#       ifdef ERROR_DEVICE_HARDWARE_ERROR
        /// <summary>The request failed due to a fatal device hardware error.</summary>
        error_device_hardware_error = ERROR_DEVICE_HARDWARE_ERROR,
#       else
#       endif

#       ifdef ERROR_INVALID_ADDRESS
        /// <summary>Attempt to access invalid address.</summary>
        error_invalid_address = ERROR_INVALID_ADDRESS,
#       else
#       endif

        /// <summary>Driver Verifier Volatile settings cannot be set when CFG is enabled.</summary>
        error_vrf_cfg_enabled = 1183L, //ERROR_VRF_CFG_ENABLED,

        /// <summary>An attempt was made to access a partition that has begun termination.</summary>
#       ifdef ERROR_PARTITION_TERMINATING
        error_partition_terminating = ERROR_PARTITION_TERMINATING,
#       else
#       endif
        /// <summary>User profile cannot be loaded.</summary>
#       ifdef ERROR_USER_PROFILE_LOAD
        error_user_profile_load = ERROR_USER_PROFILE_LOAD,
#       else
#       endif
        /// <summary>**** Available SYSTEM error codes ****</summary>
        /// <summary>Arithmetic result exceeded 32 bits.</summary>
#       ifdef ERROR_ARITHMETIC_OVERFLOW
        error_arithmetic_overflow = ERROR_ARITHMETIC_OVERFLOW,
#       else
#       endif
        /// <summary>There is a process on other end of the pipe.</summary>
#       ifdef ERROR_PIPE_CONNECTED
        error_pipe_connected = ERROR_PIPE_CONNECTED,
#       else
#       endif
        /// <summary>Waiting for a process to open the other end of the pipe.</summary>
#       ifdef ERROR_PIPE_LISTENING
        error_pipe_listening = ERROR_PIPE_LISTENING,
#       else
#       endif
        /// <summary>Application verifier has found an error in the current process.</summary>
#       ifdef ERROR_VERIFIER_STOP
        error_verifier_stop = ERROR_VERIFIER_STOP,
#       else
#       endif
        /// <summary>An error occurred in the ABIOS subsystem.</summary>
#       ifdef ERROR_ABIOS_ERROR
        error_abios_error = ERROR_ABIOS_ERROR,
#       else
#       endif
        /// <summary>A warning occurred in the WX86 subsystem.</summary>
#       ifdef ERROR_WX86_WARNING
        error_wx86_warning = ERROR_WX86_WARNING,
#       else
#       endif
        /// <summary>An error occurred in the WX86 subsystem.</summary>
#       ifdef ERROR_WX86_ERROR
        error_wx86_error = ERROR_WX86_ERROR,
#       else
#       endif
        /// <summary>An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.</summary>
#       ifdef ERROR_TIMER_NOT_CANCELED
        error_timer_not_canceled = ERROR_TIMER_NOT_CANCELED,
#       else
#       endif
        /// <summary>Unwind exception code.</summary>
#       ifdef ERROR_UNWIND
        error_unwind = ERROR_UNWIND,
#       else
#       endif
        /// <summary>An invalid or unaligned stack was encountered during an unwind operation.</summary>
#       ifdef ERROR_BAD_STACK
        error_bad_stack = ERROR_BAD_STACK,
#       else
#       endif
        /// <summary>An invalid unwind target was encountered during an unwind operation.</summary>
#       ifdef ERROR_INVALID_UNWIND_TARGET
        error_invalid_unwind_target = ERROR_INVALID_UNWIND_TARGET,
#       else
#       endif
        /// <summary>Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort</summary>
#       ifdef ERROR_INVALID_PORT_ATTRIBUTES
        error_invalid_port_attributes = ERROR_INVALID_PORT_ATTRIBUTES,
#       else
#       endif
        /// <summary>Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.</summary>
#       ifdef ERROR_PORT_MESSAGE_TOO_LONG
        error_port_message_too_long = ERROR_PORT_MESSAGE_TOO_LONG,
#       else
#       endif
        /// <summary>An attempt was made to lower a quota limit below the current usage.</summary>
#       ifdef ERROR_INVALID_QUOTA_LOWER
        error_invalid_quota_lower = ERROR_INVALID_QUOTA_LOWER,
#       else
#       endif
        /// <summary>An attempt was made to attach to a device that was already attached to another device.</summary>
#       ifdef ERROR_DEVICE_ALREADY_ATTACHED
        error_device_already_attached = ERROR_DEVICE_ALREADY_ATTACHED,
#       else
#       endif
        /// <summary>An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.</summary>
#       ifdef ERROR_INSTRUCTION_MISALIGNMENT
        error_instruction_misalignment = ERROR_INSTRUCTION_MISALIGNMENT,
#       else
#       endif
        /// <summary>Profiling not started.</summary>
#       ifdef ERROR_PROFILING_NOT_STARTED
        error_profiling_not_started = ERROR_PROFILING_NOT_STARTED,
#       else
#       endif
        /// <summary>Profiling not stopped.</summary>
#       ifdef ERROR_PROFILING_NOT_STOPPED
        error_profiling_not_stopped = ERROR_PROFILING_NOT_STOPPED,
#       else
#       endif
        /// <summary>The passed ACL did not contain the minimum required information.</summary>
#       ifdef ERROR_COULD_NOT_INTERPRET
        error_could_not_interpret = ERROR_COULD_NOT_INTERPRET,
#       else
#       endif
        /// <summary>The number of active profiling objects is at the maximum and no more may be started.</summary>
#       ifdef ERROR_PROFILING_AT_LIMIT
        error_profiling_at_limit = ERROR_PROFILING_AT_LIMIT,
#       else
#       endif
        /// <summary>Used to indicate that an operation cannot continue without blocking for I/O.</summary>
#       ifdef ERROR_CANT_WAIT
        error_cant_wait = ERROR_CANT_WAIT,
#       else
#       endif
        /// <summary>Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.</summary>
#       ifdef ERROR_CANT_TERMINATE_SELF
        error_cant_terminate_self = ERROR_CANT_TERMINATE_SELF,
#       else
#       endif
        /// <summary>If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.</summary>
        /// <summary>In this case information is lost, however, the filter correctly handles the exception.</summary>
#       ifdef ERROR_UNEXPECTED_MM_CREATE_ERR
        error_unexpected_mm_create_err = ERROR_UNEXPECTED_MM_CREATE_ERR,
#       else
#       endif
        /// <summary>If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.</summary>
        /// <summary>In this case information is lost, however, the filter correctly handles the exception.</summary>
#       ifdef ERROR_UNEXPECTED_MM_MAP_ERROR
        error_unexpected_mm_map_error = ERROR_UNEXPECTED_MM_MAP_ERROR,
#       else
#       endif
        /// <summary>If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.</summary>
        /// <summary>In this case information is lost, however, the filter correctly handles the exception.</summary>
#       ifdef ERROR_UNEXPECTED_MM_EXTEND_ERR
        error_unexpected_mm_extend_err = ERROR_UNEXPECTED_MM_EXTEND_ERR,
#       else
#       endif
        /// <summary>A malformed function table was encountered during an unwind operation.</summary>
#       ifdef ERROR_BAD_FUNCTION_TABLE
        error_bad_function_table = ERROR_BAD_FUNCTION_TABLE,
#       else
#       endif
        /// <summary>Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system.</summary>
        /// <summary>This causes the protection attempt to fail, which may cause a file creation attempt to fail.</summary>
#       ifdef ERROR_NO_GUID_TRANSLATION
        error_no_guid_translation = ERROR_NO_GUID_TRANSLATION,
#       else
#       endif
        /// <summary>Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.</summary>
#       ifdef ERROR_INVALID_LDT_SIZE
        error_invalid_ldt_size = ERROR_INVALID_LDT_SIZE,
#       else
#       endif
        /// <summary>Indicates that the starting value for the LDT information was not an integral multiple of the selector size.</summary>
#       ifdef ERROR_INVALID_LDT_OFFSET
        error_invalid_ldt_offset = ERROR_INVALID_LDT_OFFSET,
#       else
#       endif
        /// <summary>Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.</summary>
#       ifdef ERROR_INVALID_LDT_DESCRIPTOR
        error_invalid_ldt_descriptor = ERROR_INVALID_LDT_DESCRIPTOR,
#       else
#       endif
        /// <summary>Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.</summary>
#       ifdef ERROR_TOO_MANY_THREADS
        error_too_many_threads = ERROR_TOO_MANY_THREADS,
#       else
#       endif
        /// <summary>An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.</summary>
#       ifdef ERROR_THREAD_NOT_IN_PROCESS
        error_thread_not_in_process = ERROR_THREAD_NOT_IN_PROCESS,
#       else
#       endif
        /// <summary>Page file quota was exceeded.</summary>
#       ifdef ERROR_PAGEFILE_QUOTA_EXCEEDED
        error_pagefile_quota_exceeded = ERROR_PAGEFILE_QUOTA_EXCEEDED,
#       else
#       endif
        /// <summary>The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.</summary>
#       ifdef ERROR_LOGON_SERVER_CONFLICT
        error_logon_server_conflict = ERROR_LOGON_SERVER_CONFLICT,
#       else
#       endif
        /// <summary>The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.</summary>
#       ifdef ERROR_SYNCHRONIZATION_REQUIRED
        error_synchronization_required = ERROR_SYNCHRONIZATION_REQUIRED,
#       else
#       endif
        /// <summary>The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.</summary>
#       ifdef ERROR_NET_OPEN_FAILED
        error_net_open_failed = ERROR_NET_OPEN_FAILED,
#       else
#       endif
        /// <summary>{Privilege Failed}</summary>
        /// <summary>The I/O permissions for the process could not be changed.</summary>
#       ifdef ERROR_IO_PRIVILEGE_FAILED
        error_io_privilege_failed = ERROR_IO_PRIVILEGE_FAILED,
#       else
#       endif
        /// <summary>{Application Exit by CTRL+C}</summary>
        /// <summary>The application terminated as a result of a CTRL+C.</summary>
#       ifdef ERROR_CONTROL_C_EXIT
        error_control_c_exit = ERROR_CONTROL_C_EXIT,
#       else
#       endif

#       ifdef ERROR_MISSING_SYSTEMFILE
        /// <summary>The required system file %hs is bad or missing.</summary>
        error_missing_systemfile = ERROR_MISSING_SYSTEMFILE,
#       else
#       endif

#       ifdef ERROR_UNHANDLED_EXCEPTION
        /// <summary>The exception %s (0x%08lx) occurred in the application at location 0x%08lx.</summary>
        error_unhandled_exception = ERROR_UNHANDLED_EXCEPTION,
#       else
#       endif

#       ifdef ERROR_APP_INIT_FAILURE
        /// <summary>The application was unable to start correctly (0x%lx). Click OK to close the application.</summary>
        error_app_init_failure = ERROR_APP_INIT_FAILURE,
#       else
#       endif

#       ifdef ERROR_PAGEFILE_CREATE_FAILED
        /// <summary>The creation of the paging file %hs failed (%lx). The requested size was %ld.</summary>
        error_pagefile_create_failed = ERROR_PAGEFILE_CREATE_FAILED,
#       else
#       endif

#       ifdef ERROR_INVALID_IMAGE_HASH
        /// <summary>Windows cannot verify the digital signature for this file. A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.</summary>
        error_invalid_image_hash = ERROR_INVALID_IMAGE_HASH,
#       else
#       endif

#       ifdef ERROR_NO_PAGEFILE
        /// <summary>No paging file was specified in the system configuration.</summary>
        error_no_pagefile = ERROR_NO_PAGEFILE,
#       else
#       endif

#       ifdef ERROR_ILLEGAL_FLOAT_CONTEXT
        /// <summary>A real-mode application issued a floating-point instruction and floating-point hardware is not present.</summary>
        error_illegal_float_context = ERROR_ILLEGAL_FLOAT_CONTEXT,
#       else
#       endif
        /// <summary>An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.</summary>
#       ifdef ERROR_NO_EVENT_PAIR
        error_no_event_pair = ERROR_NO_EVENT_PAIR,
#       else
#       endif
        /// <summary>A Windows Server has an incorrect configuration.</summary>
#       ifdef ERROR_DOMAIN_CTRLR_CONFIG_ERROR
        error_domain_ctrlr_config_error = ERROR_DOMAIN_CTRLR_CONFIG_ERROR,
#       else
#       endif
        /// <summary>An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.</summary>
#       ifdef ERROR_ILLEGAL_CHARACTER
        error_illegal_character = ERROR_ILLEGAL_CHARACTER,
#       else
#       endif
        /// <summary>The Unicode character is not defined in the Unicode character set installed on the system.</summary>
#       ifdef ERROR_UNDEFINED_CHARACTER
        error_undefined_character = ERROR_UNDEFINED_CHARACTER,
#       else
#       endif
        /// <summary>The paging file cannot be created on a floppy diskette.</summary>
#       ifdef ERROR_FLOPPY_VOLUME
        error_floppy_volume = ERROR_FLOPPY_VOLUME,
#       else
#       endif
        /// <summary>The system BIOS failed to connect a system interrupt to the device or bus for which the device is connected.</summary>
#       ifdef ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT
        error_bios_failed_to_connect_interrupt = ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT,
#       else
#       endif
        /// <summary>This operation is only allowed for the Primary Domain Controller of the domain.</summary>
#       ifdef ERROR_BACKUP_CONTROLLER
        error_backup_controller = ERROR_BACKUP_CONTROLLER,
#       else
#       endif
        /// <summary>An attempt was made to acquire a mutant such that its maximum count would have been exceeded.</summary>
#       ifdef ERROR_MUTANT_LIMIT_EXCEEDED
        error_mutant_limit_exceeded = ERROR_MUTANT_LIMIT_EXCEEDED,
#       else
#       endif
        /// <summary>A volume has been accessed for which a file system driver is required that has not yet been loaded.</summary>
#       ifdef ERROR_FS_DRIVER_REQUIRED
        error_fs_driver_required = ERROR_FS_DRIVER_REQUIRED,
#       else
#       endif
        /// <summary>The registry cannot load the hive (file) or its log or alternate. It is corrupt, absent, or not writable.</summary>
#       ifdef ERROR_CANNOT_LOAD_REGISTRY_FILE
        error_cannot_load_registry_file = ERROR_CANNOT_LOAD_REGISTRY_FILE,
#       else
#       endif
        /// <summary>{Unexpected Failure in DebugActiveProcess}</summary>
        /// <summary>An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.</summary>
#       ifdef ERROR_DEBUG_ATTACH_FAILED
        error_debug_attach_failed = ERROR_DEBUG_ATTACH_FAILED,
#       else
#       endif
        /// <summary>The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x).</summary>
#       ifdef ERROR_SYSTEM_PROCESS_TERMINATED
        error_system_process_terminated = ERROR_SYSTEM_PROCESS_TERMINATED,
#       else
#       endif
        /// <summary>{Data Not Accepted}</summary>
        /// <summary>The TDI client could not handle the data received during an indication.</summary>
#       ifdef ERROR_DATA_NOT_ACCEPTED
        error_data_not_accepted = ERROR_DATA_NOT_ACCEPTED,
#       else
#       endif
        /// <summary>NTVDM encountered a hard error.</summary>
#       ifdef ERROR_VDM_HARD_ERROR
        error_vdm_hard_error = ERROR_VDM_HARD_ERROR,
#       else
#       endif
        /// <summary>{Cancel Timeout}</summary>
        /// <summary>The driver %hs failed to complete a cancelled I/O request in the allotted time.</summary>
#       ifdef ERROR_DRIVER_CANCEL_TIMEOUT
        error_driver_cancel_timeout = ERROR_DRIVER_CANCEL_TIMEOUT,
#       else
#       endif
        /// <summary>{Reply Message Mismatch}</summary>
        /// <summary>An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.</summary>
#       ifdef ERROR_REPLY_MESSAGE_MISMATCH
        error_reply_message_mismatch = ERROR_REPLY_MESSAGE_MISMATCH,
#       else
#       endif
        /// <summary>{Delayed Write Failed}</summary>
        /// <summary>Windows was unable to save all the data for the file %hs. The data has been lost.</summary>
        /// <summary>This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.</summary>
#       ifdef ERROR_LOST_WRITEBEHIND_DATA
        error_lost_writebehind_data = ERROR_LOST_WRITEBEHIND_DATA,
#       else
#       endif
        /// <summary>The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.</summary>
#       ifdef ERROR_CLIENT_SERVER_PARAMETERS_INVALID
        error_client_server_parameters_invalid = ERROR_CLIENT_SERVER_PARAMETERS_INVALID,
#       else
#       endif
        /// <summary>The stream is not a tiny stream.</summary>
#       ifdef ERROR_NOT_TINY_STREAM
        error_not_tiny_stream = ERROR_NOT_TINY_STREAM,
#       else
#       endif
        /// <summary>The request must be handled by the stack overflow code.</summary>
#       ifdef ERROR_STACK_OVERFLOW_READ
        error_stack_overflow_read = ERROR_STACK_OVERFLOW_READ,
#       else
#       endif
        /// <summary>Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.</summary>
#       ifdef ERROR_CONVERT_TO_LARGE
        error_convert_to_large = ERROR_CONVERT_TO_LARGE,
#       else
#       endif
        /// <summary>The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.</summary>
#       ifdef ERROR_FOUND_OUT_OF_SCOPE
        error_found_out_of_scope = ERROR_FOUND_OUT_OF_SCOPE,
#       else
#       endif
        /// <summary>The bucket array must be grown. Retry transaction after doing so.</summary>
#       ifdef ERROR_ALLOCATE_BUCKET
        error_allocate_bucket = ERROR_ALLOCATE_BUCKET,
#       else
#       endif
        /// <summary>The user/kernel marshalling buffer has overflowed.</summary>
#       ifdef ERROR_MARSHALL_OVERFLOW
        error_marshall_overflow = ERROR_MARSHALL_OVERFLOW,
#       else
#       endif
        /// <summary>The supplied variant structure contains invalid data.</summary>
#       ifdef ERROR_INVALID_VARIANT
        error_invalid_variant = ERROR_INVALID_VARIANT,
#       else
#       endif
        /// <summary>The specified buffer contains ill-formed data.</summary>
#       ifdef ERROR_BAD_COMPRESSION_BUFFER
        error_bad_compression_buffer = ERROR_BAD_COMPRESSION_BUFFER,
#       else
#       endif
        /// <summary>{Audit Failed}</summary>
        /// <summary>An attempt to generate a security audit failed.</summary>
#       ifdef ERROR_AUDIT_FAILED
        error_audit_failed = ERROR_AUDIT_FAILED,
#       else
#       endif
        /// <summary>The timer resolution was not previously set by the current process.</summary>
#       ifdef ERROR_TIMER_RESOLUTION_NOT_SET
        error_timer_resolution_not_set = ERROR_TIMER_RESOLUTION_NOT_SET,
#       else
#       endif
        /// <summary>There is insufficient account information to log you on.</summary>
#       ifdef ERROR_INSUFFICIENT_LOGON_INFO
        error_insufficient_logon_info = ERROR_INSUFFICIENT_LOGON_INFO,
#       else
#       endif
        /// <summary>{Invalid DLL Entrypoint}</summary>
        /// <summary>The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state.</summary>
        /// <summary>The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.</summary>
#       ifdef ERROR_BAD_DLL_ENTRYPOINT
        error_bad_dll_entrypoint = ERROR_BAD_DLL_ENTRYPOINT,
#       else
#       endif
        /// <summary>{Invalid Service Callback Entrypoint}</summary>
        /// <summary>The %hs service is not written correctly. The stack pointer has been left in an inconsistent state.</summary>
        /// <summary>The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.</summary>
#       ifdef ERROR_BAD_SERVICE_ENTRYPOINT
        error_bad_service_entrypoint = ERROR_BAD_SERVICE_ENTRYPOINT,
#       else
#       endif
        /// <summary>There is an IP address conflict with another system on the network</summary>
#       ifdef ERROR_IP_ADDRESS_CONFLICT1
        error_ip_address_conflict1 = ERROR_IP_ADDRESS_CONFLICT1,
#       else
#       endif
        /// <summary>There is an IP address conflict with another system on the network</summary>
#       ifdef ERROR_IP_ADDRESS_CONFLICT2
        error_ip_address_conflict2 = ERROR_IP_ADDRESS_CONFLICT2,
#       else
#       endif
        /// <summary>{Low On Registry Space}</summary>
        /// <summary>The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.</summary>
#       ifdef ERROR_REGISTRY_QUOTA_LIMIT
        error_registry_quota_limit = ERROR_REGISTRY_QUOTA_LIMIT,
#       else
#       endif
        /// <summary>A callback return system service cannot be executed when no callback is active.</summary>
#       ifdef ERROR_NO_CALLBACK_ACTIVE
        error_no_callback_active = ERROR_NO_CALLBACK_ACTIVE,
#       else
#       endif
        /// <summary>The password provided is too short to meet the policy of your user account.</summary>
        /// <summary>Please choose a longer password.</summary>
#       ifdef ERROR_PWD_TOO_SHORT
        error_pwd_too_short = ERROR_PWD_TOO_SHORT,
#       else
#       endif
        /// <summary>The policy of your user account does not allow you to change passwords too frequently.</summary>
        /// <summary>This is done to prevent users from changing back to a familiar, but potentially discovered, password.</summary>
        /// <summary>If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.</summary>
#       ifdef ERROR_PWD_TOO_RECENT
        error_pwd_too_recent = ERROR_PWD_TOO_RECENT,
#       else
#       endif
        /// <summary>You have attempted to change your password to one that you have used in the past.</summary>
        /// <summary>The policy of your user account does not allow this. Please select a password that you have not previously used.</summary>
#       ifdef ERROR_PWD_HISTORY_CONFLICT
        error_pwd_history_conflict = ERROR_PWD_HISTORY_CONFLICT,
#       else
#       endif
        /// <summary>The specified compression format is unsupported.</summary>
#       ifdef ERROR_UNSUPPORTED_COMPRESSION
        error_unsupported_compression = ERROR_UNSUPPORTED_COMPRESSION,
#       else
#       endif
        /// <summary>The specified hardware profile configuration is invalid.</summary>
#       ifdef ERROR_INVALID_HW_PROFILE
        error_invalid_hw_profile = ERROR_INVALID_HW_PROFILE,
#       else
#       endif
        /// <summary>The specified Plug and Play registry device path is invalid.</summary>
#       ifdef ERROR_INVALID_PLUGPLAY_DEVICE_PATH
        error_invalid_plugplay_device_path = ERROR_INVALID_PLUGPLAY_DEVICE_PATH,
#       else
#       endif
        /// <summary>The specified quota list is internally inconsistent with its descriptor.</summary>
#       ifdef ERROR_QUOTA_LIST_INCONSISTENT
        error_quota_list_inconsistent = ERROR_QUOTA_LIST_INCONSISTENT,
#       else
#       endif
        /// <summary>{Windows Evaluation Notification}</summary>
        /// <summary>The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.</summary>
#       ifdef ERROR_EVALUATION_EXPIRATION
        error_evaluation_expiration = ERROR_EVALUATION_EXPIRATION,
#       else
#       endif
        /// <summary>{Illegal System DLL Relocation}</summary>
        /// <summary>The system DLL %hs was relocated in memory. The application will not run properly.</summary>
        /// <summary>The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL.</summary>
#       ifdef ERROR_ILLEGAL_DLL_RELOCATION
        error_illegal_dll_relocation = ERROR_ILLEGAL_DLL_RELOCATION,
#       else
#       endif
        /// <summary>{DLL Initialization Failed}</summary>
        /// <summary>The application failed to initialize because the window station is shutting down.</summary>
#       ifdef ERROR_DLL_INIT_FAILED_LOGOFF
        error_dll_init_failed_logoff = ERROR_DLL_INIT_FAILED_LOGOFF,
#       else
#       endif
        /// <summary>The validation process needs to continue on to the next step.</summary>
#       ifdef ERROR_VALIDATE_CONTINUE
        error_validate_continue = ERROR_VALIDATE_CONTINUE,
#       else
#       endif
        /// <summary>There are no more matches for the current index enumeration.</summary>
#       ifdef ERROR_NO_MORE_MATCHES
        error_no_more_matches = ERROR_NO_MORE_MATCHES,
#       else
#       endif
        /// <summary>The range could not be added to the range list because of a conflict.</summary>
#       ifdef ERROR_RANGE_LIST_CONFLICT
        error_range_list_conflict = ERROR_RANGE_LIST_CONFLICT,
#       else
#       endif
        /// <summary>The server process is running under a SID different than that required by client.</summary>
#       ifdef ERROR_SERVER_SID_MISMATCH
        error_server_sid_mismatch = ERROR_SERVER_SID_MISMATCH,
#       else
#       endif
        /// <summary>A group marked use for deny only cannot be enabled.</summary>
#       ifdef ERROR_CANT_ENABLE_DENY_ONLY
        error_cant_enable_deny_only = ERROR_CANT_ENABLE_DENY_ONLY,
#       else
#       endif
        /// <summary>{EXCEPTION}</summary>
        /// <summary>Multiple floating point faults.</summary>
#       ifdef ERROR_FLOAT_MULTIPLE_FAULTS
        error_float_multiple_faults = ERROR_FLOAT_MULTIPLE_FAULTS,
#       else
#       endif
        /// <summary>{EXCEPTION}</summary>
        /// <summary>Multiple floating point traps.</summary>
#       ifdef ERROR_FLOAT_MULTIPLE_TRAPS
        error_float_multiple_traps = ERROR_FLOAT_MULTIPLE_TRAPS,
#       else
#       endif
        /// <summary>The requested interface is not supported.</summary>
#       ifdef ERROR_NOINTERFACE
        error_nointerface = ERROR_NOINTERFACE,
#       else
#       endif
        /// <summary>{System Standby Failed}</summary>
        /// <summary>The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.</summary>
#       ifdef ERROR_DRIVER_FAILED_SLEEP
        error_driver_failed_sleep = ERROR_DRIVER_FAILED_SLEEP,
#       else
#       endif
        /// <summary>The system file %1 has become corrupt and has been replaced.</summary>
#       ifdef ERROR_CORRUPT_SYSTEM_FILE
        error_corrupt_system_file = ERROR_CORRUPT_SYSTEM_FILE,
#       else
#       endif
        /// <summary>{Virtual Memory Minimum Too Low}</summary>
        /// <summary>Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file.</summary>
        /// <summary>During this process, memory requests for some applications may be denied. For more information, see Help.</summary>
#       ifdef ERROR_COMMITMENT_MINIMUM
        error_commitment_minimum = ERROR_COMMITMENT_MINIMUM,
#       else
#       endif
        /// <summary>A device was removed so enumeration must be restarted.</summary>
#       ifdef ERROR_PNP_RESTART_ENUMERATION
        error_pnp_restart_enumeration = ERROR_PNP_RESTART_ENUMERATION,
#       else
#       endif
        /// <summary>{Fatal System Error}</summary>
        /// <summary>The system image %s is not properly signed.</summary>
        /// <summary>The file has been replaced with the signed file.</summary>
        /// <summary>The system has been shut down.</summary>
#       ifdef ERROR_SYSTEM_IMAGE_BAD_SIGNATURE
        error_system_image_bad_signature = ERROR_SYSTEM_IMAGE_BAD_SIGNATURE,
#       else
#       endif
        /// <summary>Device will not start without a reboot.</summary>
#       ifdef ERROR_PNP_REBOOT_REQUIRED
        error_pnp_reboot_required = ERROR_PNP_REBOOT_REQUIRED,
#       else
#       endif
        /// <summary>There is not enough power to complete the requested operation.</summary>
#       ifdef ERROR_INSUFFICIENT_POWER
        error_insufficient_power = ERROR_INSUFFICIENT_POWER,
#       else
#       endif
        /// <summary> ERROR_MULTIPLE_FAULT_VIOLATION</summary>
#       ifdef ERROR_MULTIPLE_FAULT_VIOLATION
        error_multiple_fault_violation = ERROR_MULTIPLE_FAULT_VIOLATION,
#       else
#       endif
        /// <summary>The system is in the process of shutting down.</summary>
#       ifdef ERROR_SYSTEM_SHUTDOWN
        error_system_shutdown = ERROR_SYSTEM_SHUTDOWN,
#       else
#       endif
        /// <summary>An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.</summary>
#       ifdef ERROR_PORT_NOT_SET
        error_port_not_set = ERROR_PORT_NOT_SET,
#       else
#       endif
        /// <summary>This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.</summary>
#       ifdef ERROR_DS_VERSION_CHECK_FAILURE
        error_ds_version_check_failure = ERROR_DS_VERSION_CHECK_FAILURE,
#       else
#       endif
        /// <summary>The specified range could not be found in the range list.</summary>
#       ifdef ERROR_RANGE_NOT_FOUND
        error_range_not_found = ERROR_RANGE_NOT_FOUND,
#       else
#       endif
        /// <summary>The driver was not loaded because the system is booting into safe mode.</summary>
#       ifdef ERROR_NOT_SAFE_MODE_DRIVER
        error_not_safe_mode_driver = ERROR_NOT_SAFE_MODE_DRIVER,
#       else
#       endif
        /// <summary>The driver was not loaded because it failed its initialization call.</summary>
#       ifdef ERROR_FAILED_DRIVER_ENTRY
        error_failed_driver_entry = ERROR_FAILED_DRIVER_ENTRY,
#       else
#       endif
        /// <summary>The "%hs" encountered an error while applying power or reading the device configuration.</summary>
        /// <summary>This may be caused by a failure of your hardware or by a poor connection.</summary>
#       ifdef ERROR_DEVICE_ENUMERATION_ERROR
        error_device_enumeration_error = ERROR_DEVICE_ENUMERATION_ERROR,
#       else
#       endif
        /// <summary>The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.</summary>
#       ifdef ERROR_MOUNT_POINT_NOT_RESOLVED
        error_mount_point_not_resolved = ERROR_MOUNT_POINT_NOT_RESOLVED,
#       else
#       endif
        /// <summary>The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.</summary>
#       ifdef ERROR_INVALID_DEVICE_OBJECT_PARAMETER
        error_invalid_device_object_parameter = ERROR_INVALID_DEVICE_OBJECT_PARAMETER,
#       else
#       endif
        /// <summary>A Machine Check Error has occurred. Please check the system eventlog for additional information.</summary>
#       ifdef ERROR_MCA_OCCURED
        error_mca_occured = ERROR_MCA_OCCURED,
#       else
#       endif
        /// <summary>There was error [%2] processing the driver database.</summary>
#       ifdef ERROR_DRIVER_DATABASE_ERROR
        error_driver_database_error = ERROR_DRIVER_DATABASE_ERROR,
#       else
#       endif
        /// <summary>System hive size has exceeded its limit.</summary>
#       ifdef ERROR_SYSTEM_HIVE_TOO_LARGE
        error_system_hive_too_large = ERROR_SYSTEM_HIVE_TOO_LARGE,
#       else
#       endif
        /// <summary>The driver could not be loaded because a previous version of the driver is still in memory.</summary>
#       ifdef ERROR_DRIVER_FAILED_PRIOR_UNLOAD
        error_driver_failed_prior_unload = ERROR_DRIVER_FAILED_PRIOR_UNLOAD,
#       else
#       endif
        /// <summary>{Volume Shadow Copy Service}</summary>
        /// <summary>Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.</summary>
#       ifdef ERROR_VOLSNAP_PREPARE_HIBERNATE
        error_volsnap_prepare_hibernate = ERROR_VOLSNAP_PREPARE_HIBERNATE,
#       else
#       endif
        /// <summary>The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.</summary>
#       ifdef ERROR_HIBERNATION_FAILURE
        error_hibernation_failure = ERROR_HIBERNATION_FAILURE,
#       else
#       endif
        /// <summary>The password provided is too long to meet the policy of your user account.</summary>
        /// <summary>Please choose a shorter password.</summary>
#       ifdef ERROR_PWD_TOO_LONG
        error_pwd_too_long = ERROR_PWD_TOO_LONG,
#       else
#       endif
        /// <summary>The requested operation could not be completed due to a file system limitation</summary>
#       ifdef ERROR_FILE_SYSTEM_LIMITATION
        error_file_system_limitation = ERROR_FILE_SYSTEM_LIMITATION,
#       else
#       endif
        /// <summary>An assertion failure has occurred.</summary>
#       ifdef ERROR_ASSERTION_FAILURE
        error_assertion_failure = ERROR_ASSERTION_FAILURE,
#       else
#       endif
        /// <summary>An error occurred in the ACPI subsystem.</summary>
#       ifdef ERROR_ACPI_ERROR
        error_acpi_error = ERROR_ACPI_ERROR,
#       else
#       endif
        /// <summary>WOW Assertion Error.</summary>
#       ifdef ERROR_WOW_ASSERTION
        error_wow_assertion = ERROR_WOW_ASSERTION,
#       else
#       endif
        /// <summary>A device is missing in the system BIOS MPS table. This device will not be used.</summary>
        /// <summary>Please contact your system vendor for system BIOS update.</summary>
#       ifdef ERROR_PNP_BAD_MPS_TABLE
        error_pnp_bad_mps_table = ERROR_PNP_BAD_MPS_TABLE,
#       else
#       endif
        /// <summary>A translator failed to translate resources.</summary>
#       ifdef ERROR_PNP_TRANSLATION_FAILED
        error_pnp_translation_failed = ERROR_PNP_TRANSLATION_FAILED,
#       else
#       endif
        /// <summary>A IRQ translator failed to translate resources.</summary>
#       ifdef ERROR_PNP_IRQ_TRANSLATION_FAILED
        error_pnp_irq_translation_failed = ERROR_PNP_IRQ_TRANSLATION_FAILED,
#       else
#       endif
        /// <summary>Driver %2 returned invalid ID for a child device (%3).</summary>
#       ifdef ERROR_PNP_INVALID_ID
        error_pnp_invalid_id = ERROR_PNP_INVALID_ID,
#       else
#       endif
        /// <summary>{Kernel Debugger Awakened}</summary>
        /// <summary>the system debugger was awakened by an interrupt.</summary>
#       ifdef ERROR_WAKE_SYSTEM_DEBUGGER
        error_wake_system_debugger = ERROR_WAKE_SYSTEM_DEBUGGER,
#       else
#       endif
        /// <summary>{Handles Closed}</summary>
        /// <summary>Handles to objects have been automatically closed as a result of the requested operation.</summary>
#       ifdef ERROR_HANDLES_CLOSED
        error_handles_closed = ERROR_HANDLES_CLOSED,
#       else
#       endif
        /// <summary>{Too Much Information}</summary>
        /// <summary>The specified access control list (ACL) contained more information than was expected.</summary>
#       ifdef ERROR_EXTRANEOUS_INFORMATION
        error_extraneous_information = ERROR_EXTRANEOUS_INFORMATION,
#       else
#       endif
        /// <summary>This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.</summary>
        /// <summary>The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).</summary>
#       ifdef ERROR_RXACT_COMMIT_NECESSARY
        error_rxact_commit_necessary = ERROR_RXACT_COMMIT_NECESSARY,
#       else
#       endif
        /// <summary>{Media Changed}</summary>
        /// <summary>The media may have changed.</summary>
#       ifdef ERROR_MEDIA_CHECK
        error_media_check = ERROR_MEDIA_CHECK,
#       else
#       endif
        /// <summary>{GUID Substitution}</summary>
        /// <summary>During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found.</summary>
        /// <summary>A substitute prefix was used, which will not compromise system security. However, this may provide a more restrictive access than intended.</summary>
#       ifdef ERROR_GUID_SUBSTITUTION_MADE
        error_guid_substitution_made = ERROR_GUID_SUBSTITUTION_MADE,
#       else
#       endif
        /// <summary>The create operation stopped after reaching a symbolic link</summary>
#       ifdef ERROR_STOPPED_ON_SYMLINK
        error_stopped_on_symlink = ERROR_STOPPED_ON_SYMLINK,
#       else
#       endif
        /// <summary>A long jump has been executed.</summary>
#       ifdef ERROR_LONGJUMP
        error_longjump = ERROR_LONGJUMP,
#       else
#       endif
        /// <summary>The Plug and Play query operation was not successful.</summary>
#       ifdef ERROR_PLUGPLAY_QUERY_VETOED
        error_plugplay_query_vetoed = ERROR_PLUGPLAY_QUERY_VETOED,
#       else
#       endif
        /// <summary>A frame consolidation has been executed.</summary>
#       ifdef ERROR_UNWIND_CONSOLIDATE
        error_unwind_consolidate = ERROR_UNWIND_CONSOLIDATE,
#       else
#       endif
        /// <summary>Registry hive (file) %hs was corrupted and it has been recovered. Some data might have been lost.</summary>
#       ifdef ERROR_REGISTRY_HIVE_RECOVERED
        error_registry_hive_recovered = ERROR_REGISTRY_HIVE_RECOVERED,
#       else
#       endif
        /// <summary>The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?</summary>
#       ifdef ERROR_DLL_MIGHT_BE_INSECURE
        error_dll_might_be_insecure = ERROR_DLL_MIGHT_BE_INSECURE,
#       else
#       endif
        /// <summary>The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?</summary>
#       ifdef ERROR_DLL_MIGHT_BE_INCOMPATIBLE
        error_dll_might_be_incompatible = ERROR_DLL_MIGHT_BE_INCOMPATIBLE,
#       else
#       endif
        /// <summary>Debugger did not handle the exception.</summary>
#       ifdef ERROR_DBG_EXCEPTION_NOT_HANDLED
        error_dbg_exception_not_handled = ERROR_DBG_EXCEPTION_NOT_HANDLED,
#       else
#       endif
        /// <summary>Debugger will reply later.</summary>
#       ifdef ERROR_DBG_REPLY_LATER
        error_dbg_reply_later = ERROR_DBG_REPLY_LATER,
#       else
#       endif
        /// <summary>Debugger cannot provide handle.</summary>
#       ifdef ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE
        error_dbg_unable_to_provide_handle = ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE,
#       else
#       endif
        /// <summary>Debugger terminated thread.</summary>
#       ifdef ERROR_DBG_TERMINATE_THREAD
        error_dbg_terminate_thread = ERROR_DBG_TERMINATE_THREAD,
#       else
#       endif
        /// <summary>Debugger terminated process.</summary>
#       ifdef ERROR_DBG_TERMINATE_PROCESS
        error_dbg_terminate_process = ERROR_DBG_TERMINATE_PROCESS,
#       else
#       endif
        /// <summary>Debugger got control C.</summary>
#       ifdef ERROR_DBG_CONTROL_C
        error_dbg_control_c = ERROR_DBG_CONTROL_C,
#       else
#       endif
        /// <summary>Debugger printed exception on control C.</summary>
#       ifdef ERROR_DBG_PRINTEXCEPTION_C
        error_dbg_printexception_c = ERROR_DBG_PRINTEXCEPTION_C,
#       else
#       endif
        /// <summary>Debugger received RIP exception.</summary>
#       ifdef ERROR_DBG_RIPEXCEPTION
        error_dbg_ripexception = ERROR_DBG_RIPEXCEPTION,
#       else
#       endif
        /// <summary>Debugger received control break.</summary>
#       ifdef ERROR_DBG_CONTROL_BREAK
        error_dbg_control_break = ERROR_DBG_CONTROL_BREAK,
#       else
#       endif
        /// <summary>Debugger command communication exception.</summary>
#       ifdef ERROR_DBG_COMMAND_EXCEPTION
        error_dbg_command_exception = ERROR_DBG_COMMAND_EXCEPTION,
#       else
#       endif
        /// <summary>{Object Exists}</summary>
        /// <summary>An attempt was made to create an object and the object name already existed.</summary>
#       ifdef ERROR_OBJECT_NAME_EXISTS
        error_object_name_exists = ERROR_OBJECT_NAME_EXISTS,
#       else
#       endif
        /// <summary>{Thread Suspended}</summary>
        /// <summary>A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.</summary>
#       ifdef ERROR_THREAD_WAS_SUSPENDED
        error_thread_was_suspended = ERROR_THREAD_WAS_SUSPENDED,
#       else
#       endif
        /// <summary>{Image Relocated}</summary>
        /// <summary>An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.</summary>
#       ifdef ERROR_IMAGE_NOT_AT_BASE
        error_image_not_at_base = ERROR_IMAGE_NOT_AT_BASE,
#       else
#       endif
        /// <summary>This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.</summary>
#       ifdef ERROR_RXACT_STATE_CREATED
        error_rxact_state_created = ERROR_RXACT_STATE_CREATED,
#       else
#       endif
        /// <summary>{Segment Load}</summary>
        /// <summary>A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image.</summary>
        /// <summary>An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.</summary>
#       ifdef ERROR_SEGMENT_NOTIFICATION
        error_segment_notification = ERROR_SEGMENT_NOTIFICATION,
#       else
#       endif
        /// <summary>{Invalid Current Directory}</summary>
        /// <summary>The process cannot switch to the startup current directory %hs.</summary>
        /// <summary>Select OK to set current directory to %hs, or select CANCEL to exit.</summary>
#       ifdef ERROR_BAD_CURRENT_DIRECTORY
        error_bad_current_directory = ERROR_BAD_CURRENT_DIRECTORY,
#       else
#       endif
        /// <summary>{Redundant Read}</summary>
        /// <summary>To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy.</summary>
        /// <summary>This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.</summary>
#       ifdef ERROR_FT_READ_RECOVERY_FROM_BACKUP
        error_ft_read_recovery_from_backup = ERROR_FT_READ_RECOVERY_FROM_BACKUP,
#       else
#       endif
        /// <summary>{Redundant Write}</summary>
        /// <summary>To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information.</summary>
        /// <summary>This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.</summary>
#       ifdef ERROR_FT_WRITE_RECOVERY
        error_ft_write_recovery = ERROR_FT_WRITE_RECOVERY,
#       else
#       endif
        /// <summary>{Machine Type Mismatch}</summary>
        /// <summary>The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.</summary>
#       ifdef ERROR_IMAGE_MACHINE_TYPE_MISMATCH
        error_image_machine_type_mismatch = ERROR_IMAGE_MACHINE_TYPE_MISMATCH,
#       else
#       endif
        /// <summary>{Partial Data Received}</summary>
        /// <summary>The network transport returned partial data to its client. The remaining data will be sent later.</summary>
#       ifdef ERROR_RECEIVE_PARTIAL
        error_receive_partial = ERROR_RECEIVE_PARTIAL,
#       else
#       endif
        /// <summary>{Expedited Data Received}</summary>
        /// <summary>The network transport returned data to its client that was marked as expedited by the remote system.</summary>
#       ifdef ERROR_RECEIVE_EXPEDITED
        error_receive_expedited = ERROR_RECEIVE_EXPEDITED,
#       else
#       endif
        /// <summary>{Partial Expedited Data Received}</summary>
        /// <summary>The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.</summary>
#       ifdef ERROR_RECEIVE_PARTIAL_EXPEDITED
        error_receive_partial_expedited = ERROR_RECEIVE_PARTIAL_EXPEDITED,
#       else
#       endif
        /// <summary>{TDI Event Done}</summary>
        /// <summary>The TDI indication has completed successfully.</summary>
#       ifdef ERROR_EVENT_DONE
        error_event_done = ERROR_EVENT_DONE,
#       else
#       endif
        /// <summary>{TDI Event Pending}</summary>
        /// <summary>The TDI indication has entered the pending state.</summary>
#       ifdef ERROR_EVENT_PENDING
        error_event_pending = ERROR_EVENT_PENDING,
#       else
#       endif
        /// <summary>Checking file system on %wZ</summary>
#       ifdef ERROR_CHECKING_FILE_SYSTEM
        error_checking_file_system = ERROR_CHECKING_FILE_SYSTEM,
#       else
#       endif
        /// <summary>{Fatal Application Exit}</summary>
        /// <summary>%hs</summary>
#       ifdef ERROR_FATAL_APP_EXIT
        error_fatal_app_exit = ERROR_FATAL_APP_EXIT,
#       else
#       endif
        /// <summary>The specified registry key is referenced by a predefined handle.</summary>
#       ifdef ERROR_PREDEFINED_HANDLE
        error_predefined_handle = ERROR_PREDEFINED_HANDLE,
#       else
#       endif
        /// <summary>{Page Unlocked}</summary>
        /// <summary>The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.</summary>
#       ifdef ERROR_WAS_UNLOCKED
        error_was_unlocked = ERROR_WAS_UNLOCKED,
#       else
#       endif
        /// <summary>%hs</summary>
#       ifdef ERROR_SERVICE_NOTIFICATION
        error_service_notification = ERROR_SERVICE_NOTIFICATION,
#       else
#       endif
        /// <summary>{Page Locked}</summary>
        /// <summary>One of the pages to lock was already locked.</summary>
#       ifdef ERROR_WAS_LOCKED
        error_was_locked = ERROR_WAS_LOCKED,
#       else
#       endif
        /// <summary>Application popup: %1 : %2</summary>
#       ifdef ERROR_LOG_HARD_ERROR
        error_log_hard_error = ERROR_LOG_HARD_ERROR,
#       else
#       endif
        /// <summary> ERROR_ALREADY_WIN32</summary>
#       ifdef ERROR_ALREADY_WIN32
        error_already_win32 = ERROR_ALREADY_WIN32,
#       else
#       endif
        /// <summary>{Machine Type Mismatch}</summary>
        /// <summary>The image file %hs is valid, but is for a machine type other than the current machine.</summary>
#       ifdef ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE
        error_image_machine_type_mismatch_exe = ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE,
#       else
#       endif
        /// <summary>A yield execution was performed and no thread was available to run.</summary>
#       ifdef ERROR_NO_YIELD_PERFORMED
        error_no_yield_performed = ERROR_NO_YIELD_PERFORMED,
#       else
#       endif
        /// <summary>The resumable flag to a timer API was ignored.</summary>
#       ifdef ERROR_TIMER_RESUME_IGNORED
        error_timer_resume_ignored = ERROR_TIMER_RESUME_IGNORED,
#       else
#       endif
        /// <summary>The arbiter has deferred arbitration of these resources to its parent</summary>
#       ifdef ERROR_ARBITRATION_UNHANDLED
        error_arbitration_unhandled = ERROR_ARBITRATION_UNHANDLED,
#       else
#       endif
        /// <summary>The inserted CardBus device cannot be started because of a configuration error on "%hs".</summary>
#       ifdef ERROR_CARDBUS_NOT_SUPPORTED
        error_cardbus_not_supported = ERROR_CARDBUS_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.</summary>
#       ifdef ERROR_MP_PROCESSOR_MISMATCH
        error_mp_processor_mismatch = ERROR_MP_PROCESSOR_MISMATCH,
#       else
#       endif
        /// <summary>The system was put into hibernation.</summary>
#       ifdef ERROR_HIBERNATED
        error_hibernated = ERROR_HIBERNATED,
#       else
#       endif
        /// <summary>The system was resumed from hibernation.</summary>
#       ifdef ERROR_RESUME_HIBERNATION
        error_resume_hibernation = ERROR_RESUME_HIBERNATION,
#       else
#       endif
        /// <summary>Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].</summary>
#       ifdef ERROR_FIRMWARE_UPDATED
        error_firmware_updated = ERROR_FIRMWARE_UPDATED,
#       else
#       endif
        /// <summary>A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.</summary>
#       ifdef ERROR_DRIVERS_LEAKING_LOCKED_PAGES
        error_drivers_leaking_locked_pages = ERROR_DRIVERS_LEAKING_LOCKED_PAGES,
#       else
#       endif
        /// <summary>The system has awoken</summary>
#       ifdef ERROR_WAKE_SYSTEM
        error_wake_system = ERROR_WAKE_SYSTEM,
#       else
#       endif
        /// <summary> ERROR_WAIT_1</summary>
#       ifdef ERROR_WAIT_1
        error_wait_1 = ERROR_WAIT_1,
#       else
#       endif
        /// <summary> ERROR_WAIT_2</summary>
#       ifdef ERROR_WAIT_2
        error_wait_2 = ERROR_WAIT_2,
#       else
#       endif
        /// <summary> ERROR_WAIT_3</summary>
#       ifdef ERROR_WAIT_3
        error_wait_3 = ERROR_WAIT_3,
#       else
#       endif
        /// <summary> ERROR_WAIT_63</summary>
#       ifdef ERROR_WAIT_63
        error_wait_63 = ERROR_WAIT_63,
#       else
#       endif
        /// <summary> ERROR_ABANDONED_WAIT_0</summary>
#       ifdef ERROR_ABANDONED_WAIT_0
        error_abandoned_wait_0 = ERROR_ABANDONED_WAIT_0,
#       else
#       endif
        /// <summary> ERROR_ABANDONED_WAIT_63</summary>
#       ifdef ERROR_ABANDONED_WAIT_63
        error_abandoned_wait_63 = ERROR_ABANDONED_WAIT_63,
#       else
#       endif
        /// <summary> ERROR_USER_APC</summary>
#       ifdef ERROR_USER_APC
        error_user_apc = ERROR_USER_APC,
#       else
#       endif
        /// <summary> ERROR_KERNEL_APC</summary>
#       ifdef ERROR_KERNEL_APC
        error_kernel_apc = ERROR_KERNEL_APC,
#       else
#       endif
        /// <summary> ERROR_ALERTED</summary>
#       ifdef ERROR_ALERTED
        error_alerted = ERROR_ALERTED,
#       else
#       endif
        /// <summary>The requested operation requires elevation.</summary>
#       ifdef ERROR_ELEVATION_REQUIRED
        error_elevation_required = ERROR_ELEVATION_REQUIRED,
#       else
#       endif
        /// <summary>A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.</summary>
#       ifdef ERROR_REPARSE
        error_reparse = ERROR_REPARSE,
#       else
#       endif
        /// <summary>An open/create operation completed while an oplock break is underway.</summary>
#       ifdef ERROR_OPLOCK_BREAK_IN_PROGRESS
        error_oplock_break_in_progress = ERROR_OPLOCK_BREAK_IN_PROGRESS,
#       else
#       endif
        /// <summary>A new volume has been mounted by a file system.</summary>
#       ifdef ERROR_VOLUME_MOUNTED
        error_volume_mounted = ERROR_VOLUME_MOUNTED,
#       else
#       endif
        /// <summary>This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.</summary>
        /// <summary>The commit has now been completed.</summary>
#       ifdef ERROR_RXACT_COMMITTED
        error_rxact_committed = ERROR_RXACT_COMMITTED,
#       else
#       endif
        /// <summary>This indicates that a notify change request has been completed due to closing the handle which made the notify change request.</summary>
#       ifdef ERROR_NOTIFY_CLEANUP
        error_notify_cleanup = ERROR_NOTIFY_CLEANUP,
#       else
#       endif
        /// <summary>{Connect Failure on Primary Transport}</summary>
        /// <summary>An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed.</summary>
        /// <summary>The computer WAS able to connect on a secondary transport.</summary>
#       ifdef ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED
        error_primary_transport_connect_failed = ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED,
#       else
#       endif
        /// <summary>Page fault was a transition fault.</summary>
#       ifdef ERROR_PAGE_FAULT_TRANSITION
        error_page_fault_transition = ERROR_PAGE_FAULT_TRANSITION,
#       else
#       endif
        /// <summary>Page fault was a demand zero fault.</summary>
#       ifdef ERROR_PAGE_FAULT_DEMAND_ZERO
        error_page_fault_demand_zero = ERROR_PAGE_FAULT_DEMAND_ZERO,
#       else
#       endif
        /// <summary>Page fault was a demand zero fault.</summary>
#       ifdef ERROR_PAGE_FAULT_COPY_ON_WRITE
        error_page_fault_copy_on_write = ERROR_PAGE_FAULT_COPY_ON_WRITE,
#       else
#       endif
        /// <summary>Page fault was a demand zero fault.</summary>
#       ifdef ERROR_PAGE_FAULT_GUARD_PAGE
        error_page_fault_guard_page = ERROR_PAGE_FAULT_GUARD_PAGE,
#       else
#       endif
        /// <summary>Page fault was satisfied by reading from a secondary storage device.</summary>
#       ifdef ERROR_PAGE_FAULT_PAGING_FILE
        error_page_fault_paging_file = ERROR_PAGE_FAULT_PAGING_FILE,
#       else
#       endif
        /// <summary>Cached page was locked during operation.</summary>
#       ifdef ERROR_CACHE_PAGE_LOCKED
        error_cache_page_locked = ERROR_CACHE_PAGE_LOCKED,
#       else
#       endif
        /// <summary>Crash dump exists in paging file.</summary>
#       ifdef ERROR_CRASH_DUMP
        error_crash_dump = ERROR_CRASH_DUMP,
#       else
#       endif
        /// <summary>Specified buffer contains all zeros.</summary>
#       ifdef ERROR_BUFFER_ALL_ZEROS
        error_buffer_all_zeros = ERROR_BUFFER_ALL_ZEROS,
#       else
#       endif
        /// <summary>A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.</summary>
#       ifdef ERROR_REPARSE_OBJECT
        error_reparse_object = ERROR_REPARSE_OBJECT,
#       else
#       endif
        /// <summary>The device has succeeded a query-stop and its resource requirements have changed.</summary>
#       ifdef ERROR_RESOURCE_REQUIREMENTS_CHANGED
        error_resource_requirements_changed = ERROR_RESOURCE_REQUIREMENTS_CHANGED,
#       else
#       endif
        /// <summary>The translator has translated these resources into the global space and no further translations should be performed.</summary>
#       ifdef ERROR_TRANSLATION_COMPLETE
        error_translation_complete = ERROR_TRANSLATION_COMPLETE,
#       else
#       endif
        /// <summary>A process being terminated has no threads to terminate.</summary>
#       ifdef ERROR_NOTHING_TO_TERMINATE
        error_nothing_to_terminate = ERROR_NOTHING_TO_TERMINATE,
#       else
#       endif
        /// <summary>The specified process is not part of a job.</summary>
#       ifdef ERROR_PROCESS_NOT_IN_JOB
        error_process_not_in_job = ERROR_PROCESS_NOT_IN_JOB,
#       else
#       endif
        /// <summary>The specified process is part of a job.</summary>
#       ifdef ERROR_PROCESS_IN_JOB
        error_process_in_job = ERROR_PROCESS_IN_JOB,
#       else
#       endif
        /// <summary>{Volume Shadow Copy Service}</summary>
        /// <summary>The system is now ready for hibernation.</summary>
#       ifdef ERROR_VOLSNAP_HIBERNATE_READY
        error_volsnap_hibernate_ready = ERROR_VOLSNAP_HIBERNATE_READY,
#       else
#       endif
        /// <summary>A file system or file system filter driver has successfully completed an FsFilter operation.</summary>
#       ifdef ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY
        error_fsfilter_op_completed_successfully = ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY,
#       else
#       endif
        /// <summary>The specified interrupt vector was already connected.</summary>
#       ifdef ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED
        error_interrupt_vector_already_connected = ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED,
#       else
#       endif
        /// <summary>The specified interrupt vector is still connected.</summary>
#       ifdef ERROR_INTERRUPT_STILL_CONNECTED
        error_interrupt_still_connected = ERROR_INTERRUPT_STILL_CONNECTED,
#       else
#       endif
        /// <summary>An operation is blocked waiting for an oplock.</summary>
#       ifdef ERROR_WAIT_FOR_OPLOCK
        error_wait_for_oplock = ERROR_WAIT_FOR_OPLOCK,
#       else
#       endif
        /// <summary>Debugger handled exception</summary>
#       ifdef ERROR_DBG_EXCEPTION_HANDLED
        error_dbg_exception_handled = ERROR_DBG_EXCEPTION_HANDLED,
#       else
#       endif
        /// <summary>Debugger continued</summary>
#       ifdef ERROR_DBG_CONTINUE
        error_dbg_continue = ERROR_DBG_CONTINUE,
#       else
#       endif
        /// <summary>An exception occurred in a user mode callback and the kernel callback frame should be removed.</summary>
#       ifdef ERROR_CALLBACK_POP_STACK
        error_callback_pop_stack = ERROR_CALLBACK_POP_STACK,
#       else
#       endif
        /// <summary>Compression is disabled for this volume.</summary>
#       ifdef ERROR_COMPRESSION_DISABLED
        error_compression_disabled = ERROR_COMPRESSION_DISABLED,
#       else
#       endif
        /// <summary>The data provider cannot fetch backwards through a result set.</summary>
#       ifdef ERROR_CANTFETCHBACKWARDS
        error_cantfetchbackwards = ERROR_CANTFETCHBACKWARDS,
#       else
#       endif
        /// <summary>The data provider cannot scroll backwards through a result set.</summary>
#       ifdef ERROR_CANTSCROLLBACKWARDS
        error_cantscrollbackwards = ERROR_CANTSCROLLBACKWARDS,
#       else
#       endif
        /// <summary>The data provider requires that previously fetched data is released before asking for more data.</summary>
#       ifdef ERROR_ROWSNOTRELEASED
        error_rowsnotreleased = ERROR_ROWSNOTRELEASED,
#       else
#       endif
        /// <summary>The data provider was not able to interpret the flags set for a column binding in an accessor.</summary>
#       ifdef ERROR_BAD_ACCESSOR_FLAGS
        error_bad_accessor_flags = ERROR_BAD_ACCESSOR_FLAGS,
#       else
#       endif
        /// <summary>One or more errors occurred while processing the request.</summary>
#       ifdef ERROR_ERRORS_ENCOUNTERED
        error_errors_encountered = ERROR_ERRORS_ENCOUNTERED,
#       else
#       endif
        /// <summary>The implementation is not capable of performing the request.</summary>
#       ifdef ERROR_NOT_CAPABLE
        error_not_capable = ERROR_NOT_CAPABLE,
#       else
#       endif
        /// <summary>The client of a component requested an operation which is not valid given the state of the component instance.</summary>
#       ifdef ERROR_REQUEST_OUT_OF_SEQUENCE
        error_request_out_of_sequence = ERROR_REQUEST_OUT_OF_SEQUENCE,
#       else
#       endif
        /// <summary>A version number could not be parsed.</summary>
#       ifdef ERROR_VERSION_PARSE_ERROR
        error_version_parse_error = ERROR_VERSION_PARSE_ERROR,
#       else
#       endif
        /// <summary>The iterator's start position is invalid.</summary>
#       ifdef ERROR_BADSTARTPOSITION
        error_badstartposition = ERROR_BADSTARTPOSITION,
#       else
#       endif
        /// <summary>The hardware has reported an uncorrectable memory error.</summary>
#       ifdef ERROR_MEMORY_HARDWARE
        error_memory_hardware = ERROR_MEMORY_HARDWARE,
#       else
#       endif
        /// <summary>The attempted operation required self healing to be enabled.</summary>
#       ifdef ERROR_DISK_REPAIR_DISABLED
        error_disk_repair_disabled = ERROR_DISK_REPAIR_DISABLED,
#       else
#       endif
        /// <summary>The Desktop heap encountered an error while allocating session memory. There is more information in the system event log.</summary>
#       ifdef ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE
        error_insufficient_resource_for_specified_shared_section_size = ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE,
#       else
#       endif
        /// <summary>The system power state is transitioning from %2 to %3.</summary>
#       ifdef ERROR_SYSTEM_POWERSTATE_TRANSITION
        error_system_powerstate_transition = ERROR_SYSTEM_POWERSTATE_TRANSITION,
#       else
#       endif
        /// <summary>The system power state is transitioning from %2 to %3 but could enter %4.</summary>
#       ifdef ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION
        error_system_powerstate_complex_transition = ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION,
#       else
#       endif
        /// <summary>A thread is getting dispatched with MCA EXCEPTION because of MCA.</summary>
#       ifdef ERROR_MCA_EXCEPTION
        error_mca_exception = ERROR_MCA_EXCEPTION,
#       else
#       endif
        /// <summary>Access to %1 is monitored by policy rule %2.</summary>
#       ifdef ERROR_ACCESS_AUDIT_BY_POLICY
        error_access_audit_by_policy = ERROR_ACCESS_AUDIT_BY_POLICY,
#       else
#       endif
        /// <summary>Access to %1 has been restricted by your Administrator by policy rule %2.</summary>
#       ifdef ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY
        error_access_disabled_no_safer_ui_by_policy = ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY,
#       else
#       endif
        /// <summary>A valid hibernation file has been invalidated and should be abandoned.</summary>
#       ifdef ERROR_ABANDON_HIBERFILE
        error_abandon_hiberfile = ERROR_ABANDON_HIBERFILE,
#       else
#       endif
        /// <summary>This error may be caused by network connectivity issues. Please try to save this file elsewhere.</summary>
#       ifdef ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED
        error_lost_writebehind_data_network_disconnected = ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED,
#       else
#       endif
        /// <summary>This error was returned by the server on which the file exists. Please try to save this file elsewhere.</summary>
#       ifdef ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR
        error_lost_writebehind_data_network_server_error = ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR,
#       else
#       endif
        /// <summary>This error may be caused if the device has been removed or the media is write-protected.</summary>
#       ifdef ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR
        error_lost_writebehind_data_local_disk_error = ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR,
#       else
#       endif
        /// <summary>The resources required for this device conflict with the MCFG table.</summary>
#       ifdef ERROR_BAD_MCFG_TABLE
        error_bad_mcfg_table = ERROR_BAD_MCFG_TABLE,
#       else
#       endif
        /// <summary>Please schedule to take the volume offline so that it can be repaired.</summary>
#       ifdef ERROR_DISK_REPAIR_REDIRECTED
        error_disk_repair_redirected = ERROR_DISK_REPAIR_REDIRECTED,
#       else
#       endif
        /// <summary>The volume repair was not successful.</summary>
#       ifdef ERROR_DISK_REPAIR_UNSUCCESSFUL
        error_disk_repair_unsuccessful = ERROR_DISK_REPAIR_UNSUCCESSFUL,
#       else
#       endif
        /// <summary>One of the volume corruption logs is full. Further corruptions that may be detected won't be logged.</summary>
#       ifdef ERROR_CORRUPT_LOG_OVERFULL
        error_corrupt_log_overfull = ERROR_CORRUPT_LOG_OVERFULL,
#       else
#       endif
        /// <summary>One of the volume corruption logs is internally corrupted and needs to be recreated. The volume may contain undetected corruptions and must be scanned.</summary>
#       ifdef ERROR_CORRUPT_LOG_CORRUPTED
        error_corrupt_log_corrupted = ERROR_CORRUPT_LOG_CORRUPTED,
#       else
#       endif
        /// <summary>One of the volume corruption logs is unavailable for being operated on.</summary>
#       ifdef ERROR_CORRUPT_LOG_UNAVAILABLE
        error_corrupt_log_unavailable = ERROR_CORRUPT_LOG_UNAVAILABLE,
#       else
#       endif
        /// <summary>One of the volume corruption logs was deleted while still having corruption records in them. The volume contains detected corruptions and must be scanned.</summary>
#       ifdef ERROR_CORRUPT_LOG_DELETED_FULL
        error_corrupt_log_deleted_full = ERROR_CORRUPT_LOG_DELETED_FULL,
#       else
#       endif
        /// <summary>One of the volume corruption logs was cleared by chkdsk and no longer contains real corruptions.</summary>
#       ifdef ERROR_CORRUPT_LOG_CLEARED
        error_corrupt_log_cleared = ERROR_CORRUPT_LOG_CLEARED,
#       else
#       endif
        /// <summary>Orphaned files exist on the volume but could not be recovered because no more new names could be created in the recovery directory. Files must be moved from the recovery directory.</summary>
#       ifdef ERROR_ORPHAN_NAME_EXHAUSTED
        error_orphan_name_exhausted = ERROR_ORPHAN_NAME_EXHAUSTED,
#       else
#       endif
        /// <summary>The oplock that was associated with this handle is now associated with a different handle.</summary>
#       ifdef ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE
        error_oplock_switched_to_new_handle = ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE,
#       else
#       endif
        /// <summary>An oplock of the requested level cannot be granted.  An oplock of a lower level may be available.</summary>
#       ifdef ERROR_CANNOT_GRANT_REQUESTED_OPLOCK
        error_cannot_grant_requested_oplock = ERROR_CANNOT_GRANT_REQUESTED_OPLOCK,
#       else
#       endif
        /// <summary>The operation did not complete successfully because it would cause an oplock to be broken. The caller has requested that existing oplocks not be broken.</summary>
#       ifdef ERROR_CANNOT_BREAK_OPLOCK
        error_cannot_break_oplock = ERROR_CANNOT_BREAK_OPLOCK,
#       else
#       endif
        /// <summary>The handle with which this oplock was associated has been closed.  The oplock is now broken.</summary>
#       ifdef ERROR_OPLOCK_HANDLE_CLOSED
        error_oplock_handle_closed = ERROR_OPLOCK_HANDLE_CLOSED,
#       else
#       endif
        /// <summary>The specified access control entry (ACE) does not contain a condition.</summary>
#       ifdef ERROR_NO_ACE_CONDITION
        error_no_ace_condition = ERROR_NO_ACE_CONDITION,
#       else
#       endif
        /// <summary>The specified access control entry (ACE) contains an invalid condition.</summary>
#       ifdef ERROR_INVALID_ACE_CONDITION
        error_invalid_ace_condition = ERROR_INVALID_ACE_CONDITION,
#       else
#       endif
        /// <summary>Access to the specified file handle has been revoked.</summary>
#       ifdef ERROR_FILE_HANDLE_REVOKED
        error_file_handle_revoked = ERROR_FILE_HANDLE_REVOKED,
#       else
#       endif
        /// <summary>An image file was mapped at a different address from the one specified in the image file but fixups will still be automatically performed on the image.</summary>
#       ifdef ERROR_IMAGE_AT_DIFFERENT_BASE
        error_image_at_different_base = ERROR_IMAGE_AT_DIFFERENT_BASE,
#       else
#       endif
        /// <summary>The read or write operation to an encrypted file could not be completed because the file has not been opened for data access.</summary>
#       ifdef ERROR_ENCRYPTED_IO_NOT_POSSIBLE
        error_encrypted_io_not_possible = ERROR_ENCRYPTED_IO_NOT_POSSIBLE,
#       else
#       endif
        /// <summary>File metadata optimization is already in progress.</summary>
#       ifdef ERROR_FILE_METADATA_OPTIMIZATION_IN_PROGRESS
        error_file_metadata_optimization_in_progress = ERROR_FILE_METADATA_OPTIMIZATION_IN_PROGRESS,
#       else
#       endif
        /// <summary>The requested operation failed due to quota operation is still in progress.</summary>
#       ifdef ERROR_QUOTA_ACTIVITY
        error_quota_activity = ERROR_QUOTA_ACTIVITY,
#       else
#       endif
        /// <summary>Access to the specified handle has been revoked.</summary>
#       ifdef ERROR_HANDLE_REVOKED
        error_handle_revoked = ERROR_HANDLE_REVOKED,
#       else
#       endif
        /// <summary>The callback function must be invoked inline.</summary>
#       ifdef ERROR_CALLBACK_INVOKE_INLINE
        error_callback_invoke_inline = ERROR_CALLBACK_INVOKE_INLINE,
#       else
#       endif
        /// <summary>The specified CPU Set IDs are invalid.</summary>
#       ifdef ERROR_CPU_SET_INVALID
        error_cpu_set_invalid = ERROR_CPU_SET_INVALID,
#       else
#       endif
        /// <summary>The specified enclave has not yet been terminated.</summary>
#       ifdef ERROR_ENCLAVE_NOT_TERMINATED
        error_enclave_not_terminated = ERROR_ENCLAVE_NOT_TERMINATED,
#       else
#       endif
        /// <summary>An attempt was made to access protected memory in violation of its secure access policy.</summary>
#       ifdef ERROR_ENCLAVE_VIOLATION
        error_enclave_violation = ERROR_ENCLAVE_VIOLATION,
#       else
#       endif
        /// <summary>**** Available SYSTEM error codes ****</summary>
        /// <summary>Access to the extended attribute was denied.</summary>
#       ifdef ERROR_EA_ACCESS_DENIED
        error_ea_access_denied = ERROR_EA_ACCESS_DENIED,
#       else
#       endif
        /// <summary>The I/O operation has been aborted because of either a thread exit or an application request.</summary>
#       ifdef ERROR_OPERATION_ABORTED
        error_operation_aborted = ERROR_OPERATION_ABORTED,
#       else
#       endif
        /// <summary>Overlapped I/O event is not in a signaled state.</summary>
#       ifdef ERROR_IO_INCOMPLETE
        error_io_incomplete = ERROR_IO_INCOMPLETE,
#       else
#       endif
        /// <summary>Overlapped I/O operation is in progress.</summary>
#       ifdef ERROR_IO_PENDING
        error_io_pending = ERROR_IO_PENDING,
#       else
#       endif
        /// <summary>Invalid access to memory location.</summary>
#       ifdef ERROR_NOACCESS
        error_noaccess = ERROR_NOACCESS,
#       else
#       endif
        /// <summary>Error performing inpage operation.</summary>
#       ifdef ERROR_SWAPERROR
        error_swaperror = ERROR_SWAPERROR,
#       else
#       endif
        /// <summary>Recursion too deep; the stack overflowed.</summary>
#       ifdef ERROR_STACK_OVERFLOW
        error_stack_overflow = ERROR_STACK_OVERFLOW,
#       else
#       endif
        /// <summary>The window cannot act on the sent message.</summary>
#       ifdef ERROR_INVALID_MESSAGE
        error_invalid_message = ERROR_INVALID_MESSAGE,
#       else
#       endif
        /// <summary>Cannot complete this function.</summary>
#       ifdef ERROR_CAN_NOT_COMPLETE
        error_can_not_complete = ERROR_CAN_NOT_COMPLETE,
#       else
#       endif
        /// <summary>Invalid flags.</summary>
#       ifdef ERROR_INVALID_FLAGS
        error_invalid_flags = ERROR_INVALID_FLAGS,
#       else
#       endif
        /// <summary>
        /// The volume does not contain a recognized file system.
        /// Please make sure that all required file system drivers are loaded and that the volume is not corrupted.
        /// </summary>
#       ifdef ERROR_UNRECOGNIZED_VOLUME
        error_unrecognized_volume = ERROR_UNRECOGNIZED_VOLUME,
#       else
#       endif
        /// <summary>The volume for a file has been externally altered so that the opened file is no longer valid.</summary>
#       ifdef ERROR_FILE_INVALID
        error_file_invalid = ERROR_FILE_INVALID,
#       else
#       endif
        /// <summary>The requested operation cannot be performed in full-screen mode.</summary>
#       ifdef ERROR_FULLSCREEN_MODE
        error_fullscreen_mode = ERROR_FULLSCREEN_MODE,
#       else
#       endif
        /// <summary>An attempt was made to reference a token that does not exist.</summary>
#       ifdef ERROR_NO_TOKEN
        error_no_token = ERROR_NO_TOKEN,
#       else
#       endif
        /// <summary>The configuration registry database is corrupt.</summary>
#       ifdef ERROR_BADDB
        error_baddb = ERROR_BADDB,
#       else
#       endif
        /// <summary>The configuration registry key is invalid.</summary>
#       ifdef ERROR_BADKEY
        error_badkey = ERROR_BADKEY,
#       else
#       endif
        /// <summary>The configuration registry key could not be opened.</summary>
#       ifdef ERROR_CANTOPEN
        error_cantopen = ERROR_CANTOPEN,
#       else
#       endif
        /// <summary>The configuration registry key could not be read.</summary>
#       ifdef ERROR_CANTREAD
        error_cantread = ERROR_CANTREAD,
#       else
#       endif
        /// <summary>The configuration registry key could not be written.</summary>
#       ifdef ERROR_CANTWRITE
        error_cantwrite = ERROR_CANTWRITE,
#       else
#       endif
        /// <summary>One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.</summary>
#       ifdef ERROR_REGISTRY_RECOVERED
        error_registry_recovered = ERROR_REGISTRY_RECOVERED,
#       else
#       endif
        /// <summary>
        /// The registry is corrupted. The structure of one of the files containing registry data is corrupted,
        /// or the system's memory image of the file is corrupted, or the file could not be recovered because
        /// the alternate copy or log was absent or corrupted.
        /// </summary>
#       ifdef ERROR_REGISTRY_CORRUPT
        error_registry_corrupt = ERROR_REGISTRY_CORRUPT,
#       else
#       endif
        /// <summary>An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.</summary>
#       ifdef ERROR_REGISTRY_IO_FAILED
        error_registry_io_failed = ERROR_REGISTRY_IO_FAILED,
#       else
#       endif
        /// <summary>The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.</summary>
#       ifdef ERROR_NOT_REGISTRY_FILE
        error_not_registry_file = ERROR_NOT_REGISTRY_FILE,
#       else
#       endif
        /// <summary>Illegal operation attempted on a registry key that has been marked for deletion.</summary>
#       ifdef ERROR_KEY_DELETED
        error_key_deleted = ERROR_KEY_DELETED,
#       else
#       endif
        /// <summary>System could not allocate the required space in a registry log.</summary>
#       ifdef ERROR_NO_LOG_SPACE
        error_no_log_space = ERROR_NO_LOG_SPACE,
#       else
#       endif
        /// <summary>Cannot create a symbolic link in a registry key that already has subkeys or values.</summary>
#       ifdef ERROR_KEY_HAS_CHILDREN
        error_key_has_children = ERROR_KEY_HAS_CHILDREN,
#       else
#       endif
        /// <summary>Cannot create a stable subkey under a volatile parent key.</summary>
#       ifdef ERROR_CHILD_MUST_BE_VOLATILE
        error_child_must_be_volatile = ERROR_CHILD_MUST_BE_VOLATILE,
#       else
#       endif
        /// <summary>A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes.</summary>
#       ifdef ERROR_NOTIFY_ENUM_DIR
        error_notify_enum_dir = ERROR_NOTIFY_ENUM_DIR,
#       else
#       endif
        /// <summary>A stop control has been sent to a service that other running services are dependent on.</summary>
#       ifdef ERROR_DEPENDENT_SERVICES_RUNNING
        error_dependent_services_running = ERROR_DEPENDENT_SERVICES_RUNNING,
#       else
#       endif
        /// <summary>The requested control is not valid for this service.</summary>
#       ifdef ERROR_INVALID_SERVICE_CONTROL
        error_invalid_service_control = ERROR_INVALID_SERVICE_CONTROL,
#       else
#       endif
        /// <summary>The service did not respond to the start or control request in a timely fashion.</summary>
#       ifdef ERROR_SERVICE_REQUEST_TIMEOUT
        error_service_request_timeout = ERROR_SERVICE_REQUEST_TIMEOUT,
#       else
#       endif
        /// <summary>A thread could not be created for the service.</summary>
#       ifdef ERROR_SERVICE_NO_THREAD
        error_service_no_thread = ERROR_SERVICE_NO_THREAD,
#       else
#       endif
        /// <summary>The service database is locked.</summary>
#       ifdef ERROR_SERVICE_DATABASE_LOCKED
        error_service_database_locked = ERROR_SERVICE_DATABASE_LOCKED,
#       else
#       endif
        /// <summary>An instance of the service is already running.</summary>
#       ifdef ERROR_SERVICE_ALREADY_RUNNING
        error_service_already_running = ERROR_SERVICE_ALREADY_RUNNING,
#       else
#       endif
        /// <summary>The account name is invalid or does not exist, or the password is invalid for the account name specified.</summary>
#       ifdef ERROR_INVALID_SERVICE_ACCOUNT
        error_invalid_service_account = ERROR_INVALID_SERVICE_ACCOUNT,
#       else
#       endif
        /// <summary>The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.</summary>
#       ifdef ERROR_SERVICE_DISABLED
        error_service_disabled = ERROR_SERVICE_DISABLED,
#       else
#       endif
        /// <summary>Circular service dependency was specified.</summary>
#       ifdef ERROR_CIRCULAR_DEPENDENCY
        error_circular_dependency = ERROR_CIRCULAR_DEPENDENCY,
#       else
#       endif
        /// <summary>The specified service does not exist as an installed service.</summary>
#       ifdef ERROR_SERVICE_DOES_NOT_EXIST
        error_service_does_not_exist = ERROR_SERVICE_DOES_NOT_EXIST,
#       else
#       endif
        /// <summary>The service cannot accept control messages at this time.</summary>
#       ifdef ERROR_SERVICE_CANNOT_ACCEPT_CTRL
        error_service_cannot_accept_ctrl = ERROR_SERVICE_CANNOT_ACCEPT_CTRL,
#       else
#       endif
        /// <summary>The service has not been started.</summary>
#       ifdef ERROR_SERVICE_NOT_ACTIVE
        error_service_not_active = ERROR_SERVICE_NOT_ACTIVE,
#       else
#       endif
        /// <summary>The service process could not connect to the service controller.</summary>
#       ifdef ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
        error_failed_service_controller_connect = ERROR_FAILED_SERVICE_CONTROLLER_CONNECT,
#       else
#       endif
        /// <summary>An exception occurred in the service when handling the control request.</summary>
#       ifdef ERROR_EXCEPTION_IN_SERVICE
        error_exception_in_service = ERROR_EXCEPTION_IN_SERVICE,
#       else
#       endif
        /// <summary>The database specified does not exist.</summary>
#       ifdef ERROR_DATABASE_DOES_NOT_EXIST
        error_database_does_not_exist = ERROR_DATABASE_DOES_NOT_EXIST,
#       else
#       endif
        /// <summary>The service has returned a service-specific error code.</summary>
#       ifdef ERROR_SERVICE_SPECIFIC_ERROR
        error_service_specific_error = ERROR_SERVICE_SPECIFIC_ERROR,
#       else
#       endif
        /// <summary>The process terminated unexpectedly.</summary>
#       ifdef ERROR_PROCESS_ABORTED
        error_process_aborted = ERROR_PROCESS_ABORTED,
#       else
#       endif
        /// <summary>The dependency service or group failed to start.</summary>
#       ifdef ERROR_SERVICE_DEPENDENCY_FAIL
        error_service_dependency_fail = ERROR_SERVICE_DEPENDENCY_FAIL,
#       else
#       endif
        /// <summary>The service did not start due to a logon failure.</summary>
#       ifdef ERROR_SERVICE_LOGON_FAILED
        error_service_logon_failed = ERROR_SERVICE_LOGON_FAILED,
#       else
#       endif
        /// <summary>After starting, the service hung in a start-pending state.</summary>
#       ifdef ERROR_SERVICE_START_HANG
        error_service_start_hang = ERROR_SERVICE_START_HANG,
#       else
#       endif
        /// <summary>The specified service database lock is invalid.</summary>
#       ifdef ERROR_INVALID_SERVICE_LOCK
        error_invalid_service_lock = ERROR_INVALID_SERVICE_LOCK,
#       else
#       endif
        /// <summary>The specified service has been marked for deletion.</summary>
#       ifdef ERROR_SERVICE_MARKED_FOR_DELETE
        error_service_marked_for_delete = ERROR_SERVICE_MARKED_FOR_DELETE,
#       else
#       endif
        /// <summary>The specified service already exists.</summary>
#       ifdef ERROR_SERVICE_EXISTS
        error_service_exists = ERROR_SERVICE_EXISTS,
#       else
#       endif
        /// <summary>The system is currently running with the last-known-good configuration.</summary>
#       ifdef ERROR_ALREADY_RUNNING_LKG
        error_already_running_lkg = ERROR_ALREADY_RUNNING_LKG,
#       else
#       endif
        /// <summary>The dependency service does not exist or has been marked for deletion.</summary>
#       ifdef ERROR_SERVICE_DEPENDENCY_DELETED
        error_service_dependency_deleted = ERROR_SERVICE_DEPENDENCY_DELETED,
#       else
#       endif
        /// <summary>The current boot has already been accepted for use as the last-known-good control set.</summary>
#       ifdef ERROR_BOOT_ALREADY_ACCEPTED
        error_boot_already_accepted = ERROR_BOOT_ALREADY_ACCEPTED,
#       else
#       endif
        /// <summary>No attempts to start the service have been made since the last boot.</summary>
#       ifdef ERROR_SERVICE_NEVER_STARTED
        error_service_never_started = ERROR_SERVICE_NEVER_STARTED,
#       else
#       endif
        /// <summary>The name is already in use as either a service name or a service display name.</summary>
#       ifdef ERROR_DUPLICATE_SERVICE_NAME
        error_duplicate_service_name = ERROR_DUPLICATE_SERVICE_NAME,
#       else
#       endif
        /// <summary>The account specified for this service is different from the account specified for other services running in the same process.</summary>
#       ifdef ERROR_DIFFERENT_SERVICE_ACCOUNT
        error_different_service_account = ERROR_DIFFERENT_SERVICE_ACCOUNT,
#       else
#       endif
        /// <summary>Failure actions can only be set for Win32 services, not for drivers.</summary>
#       ifdef ERROR_CANNOT_DETECT_DRIVER_FAILURE
        error_cannot_detect_driver_failure = ERROR_CANNOT_DETECT_DRIVER_FAILURE,
#       else
#       endif
        /// <summary>This service runs in the same process as the service control manager.</summary>
        /// <summary>Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.</summary>
#       ifdef ERROR_CANNOT_DETECT_PROCESS_ABORT
        error_cannot_detect_process_abort = ERROR_CANNOT_DETECT_PROCESS_ABORT,
#       else
#       endif
        /// <summary>No recovery program has been configured for this service.</summary>
#       ifdef ERROR_NO_RECOVERY_PROGRAM
        error_no_recovery_program = ERROR_NO_RECOVERY_PROGRAM,
#       else
#       endif
        /// <summary>The executable program that this service is configured to run in does not implement the service.</summary>
#       ifdef ERROR_SERVICE_NOT_IN_EXE
        error_service_not_in_exe = ERROR_SERVICE_NOT_IN_EXE,
#       else
#       endif
        /// <summary>This service cannot be started in Safe Mode</summary>
#       ifdef ERROR_NOT_SAFEBOOT_SERVICE
        error_not_safeboot_service = ERROR_NOT_SAFEBOOT_SERVICE,
#       else
#       endif
        /// <summary>The physical end of the tape has been reached.</summary>
#       ifdef ERROR_END_OF_MEDIA
        error_end_of_media = ERROR_END_OF_MEDIA,
#       else
#       endif
        /// <summary>A tape access reached a filemark.</summary>
#       ifdef ERROR_FILEMARK_DETECTED
        error_filemark_detected = ERROR_FILEMARK_DETECTED,
#       else
#       endif
        /// <summary>The beginning of the tape or a partition was encountered.</summary>
#       ifdef ERROR_BEGINNING_OF_MEDIA
        error_beginning_of_media = ERROR_BEGINNING_OF_MEDIA,
#       else
#       endif
        /// <summary>A tape access reached the end of a set of files.</summary>
#       ifdef ERROR_SETMARK_DETECTED
        error_setmark_detected = ERROR_SETMARK_DETECTED,
#       else
#       endif
        /// <summary>No more data is on the tape.</summary>
#       ifdef ERROR_NO_DATA_DETECTED
        error_no_data_detected = ERROR_NO_DATA_DETECTED,
#       else
#       endif
        /// <summary>Tape could not be partitioned.</summary>
#       ifdef ERROR_PARTITION_FAILURE
        error_partition_failure = ERROR_PARTITION_FAILURE,
#       else
#       endif
        /// <summary>When accessing a new tape of a multivolume partition, the current block size is incorrect.</summary>
#       ifdef ERROR_INVALID_BLOCK_LENGTH
        error_invalid_block_length = ERROR_INVALID_BLOCK_LENGTH,
#       else
#       endif
        /// <summary>Tape partition information could not be found when loading a tape.</summary>
#       ifdef ERROR_DEVICE_NOT_PARTITIONED
        error_device_not_partitioned = ERROR_DEVICE_NOT_PARTITIONED,
#       else
#       endif
        /// <summary>Unable to lock the media eject mechanism.</summary>
#       ifdef ERROR_UNABLE_TO_LOCK_MEDIA
        error_unable_to_lock_media = ERROR_UNABLE_TO_LOCK_MEDIA,
#       else
#       endif
        /// <summary>Unable to unload the media.</summary>
#       ifdef ERROR_UNABLE_TO_UNLOAD_MEDIA
        error_unable_to_unload_media = ERROR_UNABLE_TO_UNLOAD_MEDIA,
#       else
#       endif
        /// <summary>The media in the drive may have changed.</summary>
#       ifdef ERROR_MEDIA_CHANGED
        error_media_changed = ERROR_MEDIA_CHANGED,
#       else
#       endif
        /// <summary>The I/O bus was reset.</summary>
#       ifdef ERROR_BUS_RESET
        error_bus_reset = ERROR_BUS_RESET,
#       else
#       endif
        /// <summary>No media in drive.</summary>
#       ifdef ERROR_NO_MEDIA_IN_DRIVE
        error_no_media_in_drive = ERROR_NO_MEDIA_IN_DRIVE,
#       else
#       endif
        /// <summary>No mapping for the Unicode character exists in the target multi-byte code page.</summary>
#       ifdef ERROR_NO_UNICODE_TRANSLATION
        error_no_unicode_translation = ERROR_NO_UNICODE_TRANSLATION,
#       else
#       endif
        /// <summary>A dynamic link library (DLL) initialization routine failed.</summary>
#       ifdef ERROR_DLL_INIT_FAILED
        error_dll_init_failed = ERROR_DLL_INIT_FAILED,
#       else
#       endif
        /// <summary>A system shutdown is in progress.</summary>
#       ifdef ERROR_SHUTDOWN_IN_PROGRESS
        error_shutdown_in_progress = ERROR_SHUTDOWN_IN_PROGRESS,
#       else
#       endif
        /// <summary>Unable to abort the system shutdown because no shutdown was in progress.</summary>
#       ifdef ERROR_NO_SHUTDOWN_IN_PROGRESS
        error_no_shutdown_in_progress = ERROR_NO_SHUTDOWN_IN_PROGRESS,
#       else
#       endif
        /// <summary>The request could not be performed because of an I/O device error.</summary>
#       ifdef ERROR_IO_DEVICE
        error_io_device = ERROR_IO_DEVICE,
#       else
#       endif
        /// <summary>No serial device was successfully initialized. The serial driver will unload.</summary>
#       ifdef ERROR_SERIAL_NO_DEVICE
        error_serial_no_device = ERROR_SERIAL_NO_DEVICE,
#       else
#       endif
        /// <summary>Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened.</summary>
#       ifdef ERROR_IRQ_BUSY
        error_irq_busy = ERROR_IRQ_BUSY,
#       else
#       endif
        /// <summary>A serial I/O operation was completed by another write to the serial port.</summary>
        /// <summary>(The IOCTL_SERIAL_XOFF_COUNTER reached zero.)</summary>
#       ifdef ERROR_MORE_WRITES
        error_more_writes = ERROR_MORE_WRITES,
#       else
#       endif
        /// <summary>A serial I/O operation completed because the timeout period expired.</summary>
        /// <summary>(The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)</summary>
#       ifdef ERROR_COUNTER_TIMEOUT
        error_counter_timeout = ERROR_COUNTER_TIMEOUT,
#       else
#       endif
        /// <summary>No ID address mark was found on the floppy disk.</summary>
#       ifdef ERROR_FLOPPY_ID_MARK_NOT_FOUND
        error_floppy_id_mark_not_found = ERROR_FLOPPY_ID_MARK_NOT_FOUND,
#       else
#       endif
        /// <summary>Mismatch between the floppy disk sector ID field and the floppy disk controller track address.</summary>
#       ifdef ERROR_FLOPPY_WRONG_CYLINDER
        error_floppy_wrong_cylinder = ERROR_FLOPPY_WRONG_CYLINDER,
#       else
#       endif
        /// <summary>The floppy disk controller reported an error that is not recognized by the floppy disk driver.</summary>
#       ifdef ERROR_FLOPPY_UNKNOWN_ERROR
        error_floppy_unknown_error = ERROR_FLOPPY_UNKNOWN_ERROR,
#       else
#       endif
        /// <summary>The floppy disk controller returned inconsistent results in its registers.</summary>
#       ifdef ERROR_FLOPPY_BAD_REGISTERS
        error_floppy_bad_registers = ERROR_FLOPPY_BAD_REGISTERS,
#       else
#       endif
        /// <summary>While accessing the hard disk, a recalibrate operation failed, even after retries.</summary>
#       ifdef ERROR_DISK_RECALIBRATE_FAILED
        error_disk_recalibrate_failed = ERROR_DISK_RECALIBRATE_FAILED,
#       else
#       endif
        /// <summary>While accessing the hard disk, a disk operation failed even after retries.</summary>
#       ifdef ERROR_DISK_OPERATION_FAILED
        error_disk_operation_failed = ERROR_DISK_OPERATION_FAILED,
#       else
#       endif
        /// <summary>While accessing the hard disk, a disk controller reset was needed, but even that failed.</summary>
#       ifdef ERROR_DISK_RESET_FAILED
        error_disk_reset_failed = ERROR_DISK_RESET_FAILED,
#       else
#       endif
        /// <summary>Physical end of tape encountered.</summary>
#       ifdef ERROR_EOM_OVERFLOW
        error_eom_overflow = ERROR_EOM_OVERFLOW,
#       else
#       endif
        /// <summary>Not enough server memory resources are available to process this command.</summary>
#       ifdef ERROR_NOT_ENOUGH_SERVER_MEMORY
        error_not_enough_server_memory = ERROR_NOT_ENOUGH_SERVER_MEMORY,
#       else
#       endif
        /// <summary>A potential deadlock condition has been detected.</summary>
#       ifdef ERROR_POSSIBLE_DEADLOCK
        error_possible_deadlock = ERROR_POSSIBLE_DEADLOCK,
#       else
#       endif
        /// <summary>The base address or the file offset specified does not have the proper alignment.</summary>
#       ifdef ERROR_MAPPED_ALIGNMENT
        error_mapped_alignment = ERROR_MAPPED_ALIGNMENT,
#       else
#       endif
        /// <summary>An attempt to change the system power state was vetoed by another application or driver.</summary>
#       ifdef ERROR_SET_POWER_STATE_VETOED
        error_set_power_state_vetoed = ERROR_SET_POWER_STATE_VETOED,
#       else
#       endif
        /// <summary>The system BIOS failed an attempt to change the system power state.</summary>
#       ifdef ERROR_SET_POWER_STATE_FAILED
        error_set_power_state_failed = ERROR_SET_POWER_STATE_FAILED,
#       else
#       endif
        /// <summary>An attempt was made to create more links on a file than the file system supports.</summary>
#       ifdef ERROR_TOO_MANY_LINKS
        error_too_many_links = ERROR_TOO_MANY_LINKS,
#       else
#       endif
        /// <summary>The specified program requires a newer version of Windows.</summary>
#       ifdef ERROR_OLD_WIN_VERSION
        error_old_win_version = ERROR_OLD_WIN_VERSION,
#       else
#       endif
        /// <summary>The specified program is not a Windows or MS-DOS program.</summary>
#       ifdef ERROR_APP_WRONG_OS
        error_app_wrong_os = ERROR_APP_WRONG_OS,
#       else
#       endif
        /// <summary>Cannot start more than one instance of the specified program.</summary>
#       ifdef ERROR_SINGLE_INSTANCE_APP
        error_single_instance_app = ERROR_SINGLE_INSTANCE_APP,
#       else
#       endif
        /// <summary>The specified program was written for an earlier version of Windows.</summary>
#       ifdef ERROR_RMODE_APP
        error_rmode_app = ERROR_RMODE_APP,
#       else
#       endif
        /// <summary>One of the library files needed to run this application is damaged.</summary>
#       ifdef ERROR_INVALID_DLL
        error_invalid_dll = ERROR_INVALID_DLL,
#       else
#       endif
        /// <summary>No application is associated with the specified file for this operation.</summary>
#       ifdef ERROR_NO_ASSOCIATION
        error_no_association = ERROR_NO_ASSOCIATION,
#       else
#       endif
        /// <summary>An error occurred in sending the command to the application.</summary>
#       ifdef ERROR_DDE_FAIL
        error_dde_fail = ERROR_DDE_FAIL,
#       else
#       endif
        /// <summary>One of the library files needed to run this application cannot be found.</summary>
#       ifdef ERROR_DLL_NOT_FOUND
        error_dll_not_found = ERROR_DLL_NOT_FOUND,
#       else
#       endif
        /// <summary>The current process has used all of its system allowance of handles for Window Manager objects.</summary>
#       ifdef ERROR_NO_MORE_USER_HANDLES
        error_no_more_user_handles = ERROR_NO_MORE_USER_HANDLES,
#       else
#       endif
        /// <summary>The message can be used only with synchronous operations.</summary>
#       ifdef ERROR_MESSAGE_SYNC_ONLY
        error_message_sync_only = ERROR_MESSAGE_SYNC_ONLY,
#       else
#       endif
        /// <summary>The indicated source element has no media.</summary>
#       ifdef ERROR_SOURCE_ELEMENT_EMPTY
        error_source_element_empty = ERROR_SOURCE_ELEMENT_EMPTY,
#       else
#       endif
        /// <summary>The indicated destination element already contains media.</summary>
#       ifdef ERROR_DESTINATION_ELEMENT_FULL
        error_destination_element_full = ERROR_DESTINATION_ELEMENT_FULL,
#       else
#       endif
        /// <summary>The indicated element does not exist.</summary>
#       ifdef ERROR_ILLEGAL_ELEMENT_ADDRESS
        error_illegal_element_address = ERROR_ILLEGAL_ELEMENT_ADDRESS,
#       else
#       endif
        /// <summary>The indicated element is part of a magazine that is not present.</summary>
#       ifdef ERROR_MAGAZINE_NOT_PRESENT
        error_magazine_not_present = ERROR_MAGAZINE_NOT_PRESENT,
#       else
#       endif
        /// <summary>The indicated device requires reinitialization due to hardware errors.</summary>
#       ifdef ERROR_DEVICE_REINITIALIZATION_NEEDED
        error_device_reinitialization_needed = ERROR_DEVICE_REINITIALIZATION_NEEDED,
#       else
#       endif
        /// <summary>The device has indicated that cleaning is required before further operations are attempted.</summary>
#       ifdef ERROR_DEVICE_REQUIRES_CLEANING
        error_device_requires_cleaning = ERROR_DEVICE_REQUIRES_CLEANING,
#       else
#       endif
        /// <summary>The device has indicated that its door is open.</summary>
#       ifdef ERROR_DEVICE_DOOR_OPEN
        error_device_door_open = ERROR_DEVICE_DOOR_OPEN,
#       else
#       endif
        /// <summary>The device is not connected.</summary>
#       ifdef ERROR_DEVICE_NOT_CONNECTED
        error_device_not_connected = ERROR_DEVICE_NOT_CONNECTED,
#       else
#       endif
        /// <summary>Element not found.</summary>
#       ifdef ERROR_NOT_FOUND
        error_not_found = ERROR_NOT_FOUND,
#       else
#       endif
        /// <summary>There was no match for the specified key in the index.</summary>
#       ifdef ERROR_NO_MATCH
        error_no_match = ERROR_NO_MATCH,
#       else
#       endif
        /// <summary>The property set specified does not exist on the object.</summary>
#       ifdef ERROR_SET_NOT_FOUND
        error_set_not_found = ERROR_SET_NOT_FOUND,
#       else
#       endif
        /// <summary>The point passed to GetMouseMovePoints is not in the buffer.</summary>
#       ifdef ERROR_POINT_NOT_FOUND
        error_point_not_found = ERROR_POINT_NOT_FOUND,
#       else
#       endif
        /// <summary>The tracking (workstation) service is not running.</summary>
#       ifdef ERROR_NO_TRACKING_SERVICE
        error_no_tracking_service = ERROR_NO_TRACKING_SERVICE,
#       else
#       endif
        /// <summary>The Volume ID could not be found.</summary>
#       ifdef ERROR_NO_VOLUME_ID
        error_no_volume_id = ERROR_NO_VOLUME_ID,
#       else
#       endif
        /// <summary>Unable to remove the file to be replaced.</summary>
#       ifdef ERROR_UNABLE_TO_REMOVE_REPLACED
        error_unable_to_remove_replaced = ERROR_UNABLE_TO_REMOVE_REPLACED,
#       else
#       endif
        /// <summary>Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name.</summary>
#       ifdef ERROR_UNABLE_TO_MOVE_REPLACEMENT
        error_unable_to_move_replacement = ERROR_UNABLE_TO_MOVE_REPLACEMENT,
#       else
#       endif
        /// <summary>Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name.</summary>

#       ifdef ERROR_UNABLE_TO_MOVE_REPLACEMENT_2
        error_unable_to_move_replacement_2 = ERROR_UNABLE_TO_MOVE_REPLACEMENT_2,
#       else
#       endif
        /// <summary>The volume change journal is being deleted.</summary>

#       ifdef ERROR_JOURNAL_DELETE_IN_PROGRESS
        error_journal_delete_in_progress = ERROR_JOURNAL_DELETE_IN_PROGRESS,
#       else
#       endif
        /// <summary>The volume change journal is not active.</summary>

#       ifdef ERROR_JOURNAL_NOT_ACTIVE
        error_journal_not_active = ERROR_JOURNAL_NOT_ACTIVE,
#       else
#       endif
        /// <summary>A file was found, but it may not be the correct file.</summary>

#       ifdef ERROR_POTENTIAL_FILE_FOUND
        error_potential_file_found = ERROR_POTENTIAL_FILE_FOUND,
#       else
#       endif
        /// <summary>The journal entry has been deleted from the journal.</summary>

#       ifdef ERROR_JOURNAL_ENTRY_DELETED
        error_journal_entry_deleted = ERROR_JOURNAL_ENTRY_DELETED,
#       else
#       endif
        /// <summary>A system shutdown has already been scheduled.</summary>

#       ifdef ERROR_SHUTDOWN_IS_SCHEDULED
        error_shutdown_is_scheduled = ERROR_SHUTDOWN_IS_SCHEDULED,
#       else
#       endif
        /// <summary>The system shutdown cannot be initiated because there are other users logged on to the computer.</summary>

#       ifdef ERROR_SHUTDOWN_USERS_LOGGED_ON
        error_shutdown_users_logged_on = ERROR_SHUTDOWN_USERS_LOGGED_ON,
#       else
#       endif
        /// <summary>The specified device name is invalid.</summary>

#       ifdef ERROR_BAD_DEVICE
        error_bad_device = ERROR_BAD_DEVICE,
#       else
#       endif
        /// <summary>The device is not currently connected but it is a remembered connection.</summary>

#       ifdef ERROR_CONNECTION_UNAVAIL
        error_connection_unavail = ERROR_CONNECTION_UNAVAIL,
#       else
#       endif
        /// <summary>The local device name has a remembered connection to another network resource.</summary>

#       ifdef ERROR_DEVICE_ALREADY_REMEMBERED
        error_device_already_remembered = ERROR_DEVICE_ALREADY_REMEMBERED,
#       else
#       endif
        /// <summary>The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator.</summary>

#       ifdef ERROR_NO_NET_OR_BAD_PATH
        error_no_net_or_bad_path = ERROR_NO_NET_OR_BAD_PATH,
#       else
#       endif
        /// <summary>The specified network provider name is invalid.</summary>

#       ifdef ERROR_BAD_PROVIDER
        error_bad_provider = ERROR_BAD_PROVIDER,
#       else
#       endif
        /// <summary>Unable to open the network connection profile.</summary>

#       ifdef ERROR_CANNOT_OPEN_PROFILE
        error_cannot_open_profile = ERROR_CANNOT_OPEN_PROFILE,
#       else
#       endif
        /// <summary>The network connection profile is corrupted.</summary>

#       ifdef ERROR_BAD_PROFILE
        error_bad_profile = ERROR_BAD_PROFILE,
#       else
#       endif
        /// <summary>Cannot enumerate a noncontainer.</summary>

#       ifdef ERROR_NOT_CONTAINER
        error_not_container = ERROR_NOT_CONTAINER,
#       else
#       endif
        /// <summary>An extended error has occurred.</summary>

#       ifdef ERROR_EXTENDED_ERROR
        error_extended_error = ERROR_EXTENDED_ERROR,
#       else
#       endif
        /// <summary>The format of the specified group name is invalid.</summary>

#       ifdef ERROR_INVALID_GROUPNAME
        error_invalid_groupname = ERROR_INVALID_GROUPNAME,
#       else
#       endif
        /// <summary>The format of the specified computer name is invalid.</summary>

#       ifdef ERROR_INVALID_COMPUTERNAME
        error_invalid_computername = ERROR_INVALID_COMPUTERNAME,
#       else
#       endif
        /// <summary>The format of the specified event name is invalid.</summary>

#       ifdef ERROR_INVALID_EVENTNAME
        error_invalid_eventname = ERROR_INVALID_EVENTNAME,
#       else
#       endif
        /// <summary>The format of the specified domain name is invalid.</summary>

#       ifdef ERROR_INVALID_DOMAINNAME
        error_invalid_domainname = ERROR_INVALID_DOMAINNAME,
#       else
#       endif
        /// <summary>The format of the specified service name is invalid.</summary>

#       ifdef ERROR_INVALID_SERVICENAME
        error_invalid_servicename = ERROR_INVALID_SERVICENAME,
#       else
#       endif
        /// <summary>The format of the specified network name is invalid.</summary>

#       ifdef ERROR_INVALID_NETNAME
        error_invalid_netname = ERROR_INVALID_NETNAME,
#       else
#       endif
        /// <summary>The format of the specified share name is invalid.</summary>

#       ifdef ERROR_INVALID_SHARENAME
        error_invalid_sharename = ERROR_INVALID_SHARENAME,
#       else
#       endif
        /// <summary>The format of the specified password is invalid.</summary>

#       ifdef ERROR_INVALID_PASSWORDNAME
        error_invalid_passwordname = ERROR_INVALID_PASSWORDNAME,
#       else
#       endif
        /// <summary>The format of the specified message name is invalid.</summary>

#       ifdef ERROR_INVALID_MESSAGENAME
        error_invalid_messagename = ERROR_INVALID_MESSAGENAME,
#       else
#       endif
        /// <summary>The format of the specified message destination is invalid.</summary>

#       ifdef ERROR_INVALID_MESSAGEDEST
        error_invalid_messagedest = ERROR_INVALID_MESSAGEDEST,
#       else
#       endif
        /// <summary>Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.</summary>

#       ifdef ERROR_SESSION_CREDENTIAL_CONFLICT
        error_session_credential_conflict = ERROR_SESSION_CREDENTIAL_CONFLICT,
#       else
#       endif
        /// <summary>An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.</summary>

#       ifdef ERROR_REMOTE_SESSION_LIMIT_EXCEEDED
        error_remote_session_limit_exceeded = ERROR_REMOTE_SESSION_LIMIT_EXCEEDED,
#       else
#       endif
        /// <summary>The workgroup or domain name is already in use by another computer on the network.</summary>

#       ifdef ERROR_DUP_DOMAINNAME
        error_dup_domainname = ERROR_DUP_DOMAINNAME,
#       else
#       endif
        /// <summary>The network is not present or not started.</summary>

#       ifdef ERROR_NO_NETWORK
        error_no_network = ERROR_NO_NETWORK,
#       else
#       endif
        /// <summary>The operation was canceled by the user.</summary>

#       ifdef ERROR_CANCELLED
        error_cancelled = ERROR_CANCELLED,
#       else
#       endif
        /// <summary>The requested operation cannot be performed on a file with a user-mapped section open.</summary>

#       ifdef ERROR_USER_MAPPED_FILE
        error_user_mapped_file = ERROR_USER_MAPPED_FILE,
#       else
#       endif
        /// <summary>The remote computer refused the network connection.</summary>

#       ifdef ERROR_CONNECTION_REFUSED
        error_connection_refused = ERROR_CONNECTION_REFUSED,
#       else
#       endif
        /// <summary>The network connection was gracefully closed.</summary>

#       ifdef ERROR_GRACEFUL_DISCONNECT
        error_graceful_disconnect = ERROR_GRACEFUL_DISCONNECT,
#       else
#       endif
        /// <summary>The network transport endpoint already has an address associated with it.</summary>

#       ifdef ERROR_ADDRESS_ALREADY_ASSOCIATED
        error_address_already_associated = ERROR_ADDRESS_ALREADY_ASSOCIATED,
#       else
#       endif
        /// <summary>An address has not yet been associated with the network endpoint.</summary>

#       ifdef ERROR_ADDRESS_NOT_ASSOCIATED
        error_address_not_associated = ERROR_ADDRESS_NOT_ASSOCIATED,
#       else
#       endif
        /// <summary>An operation was attempted on a nonexistent network connection.</summary>

#       ifdef ERROR_CONNECTION_INVALID
        error_connection_invalid = ERROR_CONNECTION_INVALID,
#       else
#       endif
        /// <summary>An invalid operation was attempted on an active network connection.</summary>

#       ifdef ERROR_CONNECTION_ACTIVE
        error_connection_active = ERROR_CONNECTION_ACTIVE,
#       else
#       endif
        /// <summary>The network location cannot be reached. For information about network troubleshooting, see Windows Help.</summary>

#       ifdef ERROR_NETWORK_UNREACHABLE
        error_network_unreachable = ERROR_NETWORK_UNREACHABLE,
#       else
#       endif
        /// <summary>The network location cannot be reached. For information about network troubleshooting, see Windows Help.</summary>

#       ifdef ERROR_HOST_UNREACHABLE
        error_host_unreachable = ERROR_HOST_UNREACHABLE,
#       else
#       endif
        /// <summary>The network location cannot be reached. For information about network troubleshooting, see Windows Help.</summary>

#       ifdef ERROR_PROTOCOL_UNREACHABLE
        error_protocol_unreachable = ERROR_PROTOCOL_UNREACHABLE,
#       else
#       endif
        /// <summary>No service is operating at the destination network endpoint on the remote system.</summary>

#       ifdef ERROR_PORT_UNREACHABLE
        error_port_unreachable = ERROR_PORT_UNREACHABLE,
#       else
#       endif
        /// <summary>The request was aborted.</summary>

#       ifdef ERROR_REQUEST_ABORTED
        error_request_aborted = ERROR_REQUEST_ABORTED,
#       else
#       endif
        /// <summary>The network connection was aborted by the local system.</summary>

#       ifdef ERROR_CONNECTION_ABORTED
        error_connection_aborted = ERROR_CONNECTION_ABORTED,
#       else
#       endif
        /// <summary>The operation could not be completed. A retry should be performed.</summary>

#       ifdef ERROR_RETRY
        error_retry = ERROR_RETRY,
#       else
#       endif
        /// <summary>A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.</summary>

#       ifdef ERROR_CONNECTION_COUNT_LIMIT
        error_connection_count_limit = ERROR_CONNECTION_COUNT_LIMIT,
#       else
#       endif
        /// <summary>Attempting to log in during an unauthorized time of day for this account.</summary>

#       ifdef ERROR_LOGIN_TIME_RESTRICTION
        error_login_time_restriction = ERROR_LOGIN_TIME_RESTRICTION,
#       else
#       endif
        /// <summary>The account is not authorized to log in from this station.</summary>

#       ifdef ERROR_LOGIN_WKSTA_RESTRICTION
        error_login_wksta_restriction = ERROR_LOGIN_WKSTA_RESTRICTION,
#       else
#       endif
        /// <summary>The network address could not be used for the operation requested.</summary>

#       ifdef ERROR_INCORRECT_ADDRESS
        error_incorrect_address = ERROR_INCORRECT_ADDRESS,
#       else
#       endif
        /// <summary>The service is already registered.</summary>

#       ifdef ERROR_ALREADY_REGISTERED
        error_already_registered = ERROR_ALREADY_REGISTERED,
#       else
#       endif
        /// <summary>The specified service does not exist.</summary>

#       ifdef ERROR_SERVICE_NOT_FOUND
        error_service_not_found = ERROR_SERVICE_NOT_FOUND,
#       else
#       endif
        /// <summary>The operation being requested was not performed because the user has not been authenticated.</summary>

#       ifdef ERROR_NOT_AUTHENTICATED
        error_not_authenticated = ERROR_NOT_AUTHENTICATED,
#       else
#       endif
        /// <summary>The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist.</summary>

#       ifdef ERROR_NOT_LOGGED_ON
        error_not_logged_on = ERROR_NOT_LOGGED_ON,
#       else
#       endif
        /// <summary>Continue with work in progress.</summary>

#       ifdef ERROR_CONTINUE
        error_continue = ERROR_CONTINUE,
#       else
#       endif
        /// <summary>An attempt was made to perform an initialization operation when initialization has already been completed.</summary>

#       ifdef ERROR_ALREADY_INITIALIZED
        error_already_initialized = ERROR_ALREADY_INITIALIZED,
#       else
#       endif
        /// <summary>No more local devices.</summary>

#       ifdef ERROR_NO_MORE_DEVICES
        error_no_more_devices = ERROR_NO_MORE_DEVICES,
#       else
#       endif
        /// <summary>The specified site does not exist.</summary>

#       ifdef ERROR_NO_SUCH_SITE
        error_no_such_site = ERROR_NO_SUCH_SITE,
#       else
#       endif
        /// <summary>A domain controller with the specified name already exists.</summary>

#       ifdef ERROR_DOMAIN_CONTROLLER_EXISTS
        error_domain_controller_exists = ERROR_DOMAIN_CONTROLLER_EXISTS,
#       else
#       endif
        /// <summary>This operation is supported only when you are connected to the server.</summary>

#       ifdef ERROR_ONLY_IF_CONNECTED
        error_only_if_connected = ERROR_ONLY_IF_CONNECTED,
#       else
#       endif
        /// <summary>The group policy framework should call the extension even if there are no changes.</summary>

#       ifdef ERROR_OVERRIDE_NOCHANGES
        error_override_nochanges = ERROR_OVERRIDE_NOCHANGES,
#       else
#       endif
        /// <summary>The specified user does not have a valid profile.</summary>

#       ifdef ERROR_BAD_USER_PROFILE
        error_bad_user_profile = ERROR_BAD_USER_PROFILE,
#       else
#       endif
        /// <summary>This operation is not supported on a computer running Windows Server 2003 for Small Business Server</summary>

#       ifdef ERROR_NOT_SUPPORTED_ON_SBS
        error_not_supported_on_sbs = ERROR_NOT_SUPPORTED_ON_SBS,
#       else
#       endif
        /// <summary>The server machine is shutting down.</summary>

#       ifdef ERROR_SERVER_SHUTDOWN_IN_PROGRESS
        error_server_shutdown_in_progress = ERROR_SERVER_SHUTDOWN_IN_PROGRESS,
#       else
#       endif
        /// <summary>The remote system is not available. For information about network troubleshooting, see Windows Help.</summary>

#       ifdef ERROR_HOST_DOWN
        error_host_down = ERROR_HOST_DOWN,
#       else
#       endif
        /// <summary>The security identifier provided is not from an account domain.</summary>

#       ifdef ERROR_NON_ACCOUNT_SID
        error_non_account_sid = ERROR_NON_ACCOUNT_SID,
#       else
#       endif
        /// <summary>The security identifier provided does not have a domain component.</summary>

#       ifdef ERROR_NON_DOMAIN_SID
        error_non_domain_sid = ERROR_NON_DOMAIN_SID,
#       else
#       endif
        /// <summary>AppHelp dialog canceled thus preventing the application from starting.</summary>

#       ifdef ERROR_APPHELP_BLOCK
        error_apphelp_block = ERROR_APPHELP_BLOCK,
#       else
#       endif
        /// <summary>This program is blocked by group policy. For more information, contact your system administrator.</summary>

#       ifdef ERROR_ACCESS_DISABLED_BY_POLICY
        error_access_disabled_by_policy = ERROR_ACCESS_DISABLED_BY_POLICY,
#       else
#       endif
        /// <summary>A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific.</summary>

#       ifdef ERROR_REG_NAT_CONSUMPTION
        error_reg_nat_consumption = ERROR_REG_NAT_CONSUMPTION,
#       else
#       endif
        /// <summary>The share is currently offline or does not exist.</summary>

#       ifdef ERROR_CSCSHARE_OFFLINE
        error_cscshare_offline = ERROR_CSCSHARE_OFFLINE,
#       else
#       endif
        /// <summary>The Kerberos protocol encountered an error while validating the KDC certificate during smartcard logon. There is more information in the system event log.</summary>

#       ifdef ERROR_PKINIT_FAILURE
        error_pkinit_failure = ERROR_PKINIT_FAILURE,
#       else
#       endif
        /// <summary>The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.</summary>

#       ifdef ERROR_SMARTCARD_SUBSYSTEM_FAILURE
        error_smartcard_subsystem_failure = ERROR_SMARTCARD_SUBSYSTEM_FAILURE,
#       else
#       endif
        /// <summary>The system cannot contact a domain controller to service the authentication request. Please try again later.</summary>

#       ifdef ERROR_DOWNGRADE_DETECTED
        error_downgrade_detected = ERROR_DOWNGRADE_DETECTED,
#       else
#       endif
        /// <summary>Do not use ID's 1266 - 1270 as the symbolicNames have been moved to SEC_E_*</summary>
        /// <summary>The machine is locked and cannot be shut down without the force option.</summary>

#       ifdef ERROR_MACHINE_LOCKED
        error_machine_locked = ERROR_MACHINE_LOCKED,
#       else
#       endif
        /// <summary>You can't access this shared folder because your organization's security policies block unauthenticated guest access. These policies help protect your PC from unsafe or malicious devices on the network.</summary>

#       ifdef ERROR_SMB_GUEST_LOGON_BLOCKED
        error_smb_guest_logon_blocked = ERROR_SMB_GUEST_LOGON_BLOCKED,
#       else
#       endif
        /// <summary>An application-defined callback gave invalid data when called.</summary>

#       ifdef ERROR_CALLBACK_SUPPLIED_INVALID_DATA
        error_callback_supplied_invalid_data = ERROR_CALLBACK_SUPPLIED_INVALID_DATA,
#       else
#       endif
        /// <summary>The group policy framework should call the extension in the synchronous foreground policy refresh.</summary>

#       ifdef ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED
        error_sync_foreground_refresh_required = ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED,
#       else
#       endif
        /// <summary>This driver has been blocked from loading</summary>

#       ifdef ERROR_DRIVER_BLOCKED
        error_driver_blocked = ERROR_DRIVER_BLOCKED,
#       else
#       endif
        /// <summary>A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.</summary>

#       ifdef ERROR_INVALID_IMPORT_OF_NON_DLL
        error_invalid_import_of_non_dll = ERROR_INVALID_IMPORT_OF_NON_DLL,
#       else
#       endif
        /// <summary>Windows cannot open this program since it has been disabled.</summary>

#       ifdef ERROR_ACCESS_DISABLED_WEBBLADE
        error_access_disabled_webblade = ERROR_ACCESS_DISABLED_WEBBLADE,
#       else
#       endif
        /// <summary>Windows cannot open this program because the license enforcement system has been tampered with or become corrupted.</summary>

#       ifdef ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER
        error_access_disabled_webblade_tamper = ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER,
#       else
#       endif
        /// <summary>A transaction recover failed.</summary>

#       ifdef ERROR_RECOVERY_FAILURE
        error_recovery_failure = ERROR_RECOVERY_FAILURE,
#       else
#       endif
        /// <summary>The current thread has already been converted to a fiber.</summary>

#       ifdef ERROR_ALREADY_FIBER
        error_already_fiber = ERROR_ALREADY_FIBER,
#       else
#       endif
        /// <summary>The current thread has already been converted from a fiber.</summary>

#       ifdef ERROR_ALREADY_THREAD
        error_already_thread = ERROR_ALREADY_THREAD,
#       else
#       endif
        /// <summary>The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.</summary>

#       ifdef ERROR_STACK_BUFFER_OVERRUN
        error_stack_buffer_overrun = ERROR_STACK_BUFFER_OVERRUN,
#       else
#       endif
        /// <summary>Data present in one of the parameters is more than the function can operate on.</summary>

#       ifdef ERROR_PARAMETER_QUOTA_EXCEEDED
        error_parameter_quota_exceeded = ERROR_PARAMETER_QUOTA_EXCEEDED,
#       else
#       endif
        /// <summary>An attempt to do an operation on a debug object failed because the object is in the process of being deleted.</summary>

#       ifdef ERROR_DEBUGGER_INACTIVE
        error_debugger_inactive = ERROR_DEBUGGER_INACTIVE,
#       else
#       endif
        /// <summary>An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.</summary>

#       ifdef ERROR_DELAY_LOAD_FAILED
        error_delay_load_failed = ERROR_DELAY_LOAD_FAILED,
#       else
#       endif
        /// <summary>%1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.</summary>

#       ifdef ERROR_VDM_DISALLOWED
        error_vdm_disallowed = ERROR_VDM_DISALLOWED,
#       else
#       endif
        /// <summary>Insufficient information exists to identify the cause of failure.</summary>

#       ifdef ERROR_UNIDENTIFIED_ERROR
        error_unidentified_error = ERROR_UNIDENTIFIED_ERROR,
#       else
#       endif
        /// <summary>The parameter passed to a C runtime function is incorrect.</summary>

#       ifdef ERROR_INVALID_CRUNTIME_PARAMETER
        error_invalid_cruntime_parameter = ERROR_INVALID_CRUNTIME_PARAMETER,
#       else
#       endif
        /// <summary>The operation occurred beyond the valid data length of the file.</summary>

#       ifdef ERROR_BEYOND_VDL
        error_beyond_vdl = ERROR_BEYOND_VDL,
#       else
#       endif
        /// <summary>The service start failed since one or more services in the same process have an incompatible service SID type setting. A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type. If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service.</summary>

#       ifdef ERROR_INCOMPATIBLE_SERVICE_SID_TYPE
        error_incompatible_service_sid_type = ERROR_INCOMPATIBLE_SERVICE_SID_TYPE,
#       else
#       endif
        /// <summary>The process hosting the driver for this device has been terminated.</summary>

#       ifdef ERROR_DRIVER_PROCESS_TERMINATED
        error_driver_process_terminated = ERROR_DRIVER_PROCESS_TERMINATED,
#       else
#       endif
        /// <summary>An operation attempted to exceed an implementation-defined limit.</summary>

#       ifdef ERROR_IMPLEMENTATION_LIMIT
        error_implementation_limit = ERROR_IMPLEMENTATION_LIMIT,
#       else
#       endif
        /// <summary>Either the target process, or the target thread's containing process, is a protected process.</summary>
#       ifdef ERROR_PROCESS_IS_PROTECTED
        error_process_is_protected = ERROR_PROCESS_IS_PROTECTED,
#       else
#       endif

        /// <summary>The service notification client is lagging too far behind the current state of services in the machine.</summary>
#       ifdef ERROR_SERVICE_NOTIFY_CLIENT_LAGGING
        error_service_notify_client_lagging = ERROR_SERVICE_NOTIFY_CLIENT_LAGGING,
#       else
#       endif

        /// <summary>
        /// The requested file operation failed because the storage quota was exceeded.
        /// To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator.
        /// </summary>
#       ifdef ERROR_DISK_QUOTA_EXCEEDED
        error_disk_quota_exceeded = ERROR_DISK_QUOTA_EXCEEDED,
#       else
#       endif

        /// <summary>The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator.</summary>
#       ifdef ERROR_CONTENT_BLOCKED
        error_content_blocked = ERROR_CONTENT_BLOCKED,
#       else
#       endif

        /// <summary>
        /// A privilege that the service requires to function properly does not exist in the service account configuration.
        /// You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration.
        /// </summary>
#       ifdef ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE
        error_incompatible_service_privilege = ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE,
#       else
#       endif
        /// <summary>A thread involved in this operation appears to be unresponsive.</summary>

#       ifdef ERROR_APP_HANG
        error_app_hang = ERROR_APP_HANG,
#       else
#       endif
        /// <summary>Indicates a particular Security ID may not be assigned as the label of an object.</summary>
#       ifdef ERROR_INVALID_LABEL
        error_invalid_label = ERROR_INVALID_LABEL,
#       else
#       endif

        /// <summary>Not all privileges or groups referenced are assigned to the caller.</summary>
#       ifdef ERROR_NOT_ALL_ASSIGNED
        error_not_all_assigned = ERROR_NOT_ALL_ASSIGNED,
#       else
#       endif

        /// <summary>Some mapping between account names and security IDs was not done.</summary>
#       ifdef ERROR_SOME_NOT_MAPPED
        error_some_not_mapped = ERROR_SOME_NOT_MAPPED,
#       else
#       endif

        /// <summary>No system quota limits are specifically set for this account.</summary>
#       ifdef ERROR_NO_QUOTAS_FOR_ACCOUNT
        error_no_quotas_for_account = ERROR_NO_QUOTAS_FOR_ACCOUNT,
#       else
#       endif

        /// <summary>No encryption key is available. A well-known encryption key was returned.</summary>
#       ifdef ERROR_LOCAL_USER_SESSION_KEY
        error_local_user_session_key = ERROR_LOCAL_USER_SESSION_KEY,
#       else
#       endif
        /// <summary>The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.</summary>

#       ifdef ERROR_NULL_LM_PASSWORD
        error_null_lm_password = ERROR_NULL_LM_PASSWORD,
#       else
#       endif
        /// <summary>The revision level is unknown.</summary>

#       ifdef ERROR_UNKNOWN_REVISION
        error_unknown_revision = ERROR_UNKNOWN_REVISION,
#       else
#       endif
        /// <summary>Indicates two revision levels are incompatible.</summary>

#       ifdef ERROR_REVISION_MISMATCH
        error_revision_mismatch = ERROR_REVISION_MISMATCH,
#       else
#       endif
        /// <summary>This security ID may not be assigned as the owner of this object.</summary>

#       ifdef ERROR_INVALID_OWNER
        error_invalid_owner = ERROR_INVALID_OWNER,
#       else
#       endif
        /// <summary>This security ID may not be assigned as the primary group of an object.</summary>

#       ifdef ERROR_INVALID_PRIMARY_GROUP
        error_invalid_primary_group = ERROR_INVALID_PRIMARY_GROUP,
#       else
#       endif
        /// <summary>An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.</summary>

#       ifdef ERROR_NO_IMPERSONATION_TOKEN
        error_no_impersonation_token = ERROR_NO_IMPERSONATION_TOKEN,
#       else
#       endif
        /// <summary>The group may not be disabled.</summary>

#       ifdef ERROR_CANT_DISABLE_MANDATORY
        error_cant_disable_mandatory = ERROR_CANT_DISABLE_MANDATORY,
#       else
#       endif
        /// <summary>We can't sign you in with this credential because your domain isn't available. Make sure your device is connected to your organization's network and try again. If you previously signed in on this device with another credential, you can sign in with that credential.</summary>

#       ifdef ERROR_NO_LOGON_SERVERS
        error_no_logon_servers = ERROR_NO_LOGON_SERVERS,
#       else
#       endif
        /// <summary>A specified logon session does not exist. It may already have been terminated.</summary>

#       ifdef ERROR_NO_SUCH_LOGON_SESSION
        error_no_such_logon_session = ERROR_NO_SUCH_LOGON_SESSION,
#       else
#       endif
        /// <summary>A specified privilege does not exist.</summary>

#       ifdef ERROR_NO_SUCH_PRIVILEGE
        error_no_such_privilege = ERROR_NO_SUCH_PRIVILEGE,
#       else
#       endif
        /// <summary>A required privilege is not held by the client.</summary>

#       ifdef ERROR_PRIVILEGE_NOT_HELD
        error_privilege_not_held = ERROR_PRIVILEGE_NOT_HELD,
#       else
#       endif
        /// <summary>The name provided is not a properly formed account name.</summary>

#       ifdef ERROR_INVALID_ACCOUNT_NAME
        error_invalid_account_name = ERROR_INVALID_ACCOUNT_NAME,
#       else
#       endif
        /// <summary>The specified account already exists.</summary>

#       ifdef ERROR_USER_EXISTS
        error_user_exists = ERROR_USER_EXISTS,
#       else
#       endif
        /// <summary>The specified account does not exist.</summary>

#       ifdef ERROR_NO_SUCH_USER
        error_no_such_user = ERROR_NO_SUCH_USER,
#       else
#       endif
        /// <summary>The specified group already exists.</summary>

#       ifdef ERROR_GROUP_EXISTS
        error_group_exists = ERROR_GROUP_EXISTS,
#       else
#       endif
        /// <summary>The specified group does not exist.</summary>

#       ifdef ERROR_NO_SUCH_GROUP
        error_no_such_group = ERROR_NO_SUCH_GROUP,
#       else
#       endif
        /// <summary>Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.</summary>

#       ifdef ERROR_MEMBER_IN_GROUP
        error_member_in_group = ERROR_MEMBER_IN_GROUP,
#       else
#       endif
        /// <summary>The specified user account is not a member of the specified group account.</summary>

#       ifdef ERROR_MEMBER_NOT_IN_GROUP
        error_member_not_in_group = ERROR_MEMBER_NOT_IN_GROUP,
#       else
#       endif
        /// <summary>This operation is disallowed as it could result in an administration account being disabled, deleted or unable to logon.</summary>

#       ifdef ERROR_LAST_ADMIN
        error_last_admin = ERROR_LAST_ADMIN,
#       else
#       endif
        /// <summary>Unable to update the password. The value provided as the current password is incorrect.</summary>

#       ifdef ERROR_WRONG_PASSWORD
        error_wrong_password = ERROR_WRONG_PASSWORD,
#       else
#       endif
        /// <summary>Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.</summary>

#       ifdef ERROR_ILL_FORMED_PASSWORD
        error_ill_formed_password = ERROR_ILL_FORMED_PASSWORD,
#       else
#       endif
        /// <summary>Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain.</summary>

#       ifdef ERROR_PASSWORD_RESTRICTION
        error_password_restriction = ERROR_PASSWORD_RESTRICTION,
#       else
#       endif
        /// <summary>The user name or password is incorrect.</summary>

#       ifdef ERROR_LOGON_FAILURE
        error_logon_failure = ERROR_LOGON_FAILURE,
#       else
#       endif
        /// <summary>Account restrictions are preventing this user from signing in. For example: blank passwords aren't allowed, sign-in times are limited, or a policy restriction has been enforced.</summary>

#       ifdef ERROR_ACCOUNT_RESTRICTION
        error_account_restriction = ERROR_ACCOUNT_RESTRICTION,
#       else
#       endif
        /// <summary>Your account has time restrictions that keep you from signing in right now.</summary>

#       ifdef ERROR_INVALID_LOGON_HOURS
        error_invalid_logon_hours = ERROR_INVALID_LOGON_HOURS,
#       else
#       endif
        /// <summary>This user isn't allowed to sign in to this computer.</summary>

#       ifdef ERROR_INVALID_WORKSTATION
        error_invalid_workstation = ERROR_INVALID_WORKSTATION,
#       else
#       endif
        /// <summary>The password for this account has expired.</summary>

#       ifdef ERROR_PASSWORD_EXPIRED
        error_password_expired = ERROR_PASSWORD_EXPIRED,
#       else
#       endif
        /// <summary>This user can't sign in because this account is currently disabled.</summary>

#       ifdef ERROR_ACCOUNT_DISABLED
        error_account_disabled = ERROR_ACCOUNT_DISABLED,
#       else
#       endif
        /// <summary>No mapping between account names and security IDs was done.</summary>

#       ifdef ERROR_NONE_MAPPED
        error_none_mapped = ERROR_NONE_MAPPED,
#       else
#       endif
        /// <summary>Too many local user identifiers (LUIDs) were requested at one time.</summary>

#       ifdef ERROR_TOO_MANY_LUIDS_REQUESTED
        error_too_many_luids_requested = ERROR_TOO_MANY_LUIDS_REQUESTED,
#       else
#       endif
        /// <summary>No more local user identifiers (LUIDs) are available.</summary>

#       ifdef ERROR_LUIDS_EXHAUSTED
        error_luids_exhausted = ERROR_LUIDS_EXHAUSTED,
#       else
#       endif
        /// <summary>The subauthority part of a security ID is invalid for this particular use.</summary>

#       ifdef ERROR_INVALID_SUB_AUTHORITY
        error_invalid_sub_authority = ERROR_INVALID_SUB_AUTHORITY,
#       else
#       endif
        /// <summary>The access control list (ACL) structure is invalid.</summary>

#       ifdef ERROR_INVALID_ACL
        error_invalid_acl = ERROR_INVALID_ACL,
#       else
#       endif
        /// <summary>The security ID structure is invalid.</summary>

#       ifdef ERROR_INVALID_SID
        error_invalid_sid = ERROR_INVALID_SID,
#       else
#       endif
        /// <summary>The security descriptor structure is invalid.</summary>

#       ifdef ERROR_INVALID_SECURITY_DESCR
        error_invalid_security_descr = ERROR_INVALID_SECURITY_DESCR,
#       else
#       endif
        /// <summary>The inherited access control list (ACL) or access control entry (ACE) could not be built.</summary>

#       ifdef ERROR_BAD_INHERITANCE_ACL
        error_bad_inheritance_acl = ERROR_BAD_INHERITANCE_ACL,
#       else
#       endif
        /// <summary>The server is currently disabled.</summary>

#       ifdef ERROR_SERVER_DISABLED
        error_server_disabled = ERROR_SERVER_DISABLED,
#       else
#       endif
        /// <summary>The server is currently enabled.</summary>

#       ifdef ERROR_SERVER_NOT_DISABLED
        error_server_not_disabled = ERROR_SERVER_NOT_DISABLED,
#       else
#       endif
        /// <summary>The value provided was an invalid value for an identifier authority.</summary>

#       ifdef ERROR_INVALID_ID_AUTHORITY
        error_invalid_id_authority = ERROR_INVALID_ID_AUTHORITY,
#       else
#       endif
        /// <summary>No more memory is available for security information updates.</summary>

#       ifdef ERROR_ALLOTTED_SPACE_EXCEEDED
        error_allotted_space_exceeded = ERROR_ALLOTTED_SPACE_EXCEEDED,
#       else
#       endif
        /// <summary>The specified attributes are invalid, or incompatible with the attributes for the group as a whole.</summary>

#       ifdef ERROR_INVALID_GROUP_ATTRIBUTES
        error_invalid_group_attributes = ERROR_INVALID_GROUP_ATTRIBUTES,
#       else
#       endif
        /// <summary>Either a required impersonation level was not provided, or the provided impersonation level is invalid.</summary>

#       ifdef ERROR_BAD_IMPERSONATION_LEVEL
        error_bad_impersonation_level = ERROR_BAD_IMPERSONATION_LEVEL,
#       else
#       endif
        /// <summary>Cannot open an anonymous level security token.</summary>

#       ifdef ERROR_CANT_OPEN_ANONYMOUS
        error_cant_open_anonymous = ERROR_CANT_OPEN_ANONYMOUS,
#       else
#       endif
        /// <summary>The validation information class requested was invalid.</summary>

#       ifdef ERROR_BAD_VALIDATION_CLASS
        error_bad_validation_class = ERROR_BAD_VALIDATION_CLASS,
#       else
#       endif
        /// <summary>The type of the token is inappropriate for its attempted use.</summary>

#       ifdef ERROR_BAD_TOKEN_TYPE
        error_bad_token_type = ERROR_BAD_TOKEN_TYPE,
#       else
#       endif
        /// <summary>Unable to perform a security operation on an object that has no associated security.</summary>

#       ifdef ERROR_NO_SECURITY_ON_OBJECT
        error_no_security_on_object = ERROR_NO_SECURITY_ON_OBJECT,
#       else
#       endif
        /// <summary>Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.</summary>

#       ifdef ERROR_CANT_ACCESS_DOMAIN_INFO
        error_cant_access_domain_info = ERROR_CANT_ACCESS_DOMAIN_INFO,
#       else
#       endif
        /// <summary>The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.</summary>

#       ifdef ERROR_INVALID_SERVER_STATE
        error_invalid_server_state = ERROR_INVALID_SERVER_STATE,
#       else
#       endif
        /// <summary>The domain was in the wrong state to perform the security operation.</summary>

#       ifdef ERROR_INVALID_DOMAIN_STATE
        error_invalid_domain_state = ERROR_INVALID_DOMAIN_STATE,
#       else
#       endif
        /// <summary>This operation is only allowed for the Primary Domain Controller of the domain.</summary>

#       ifdef ERROR_INVALID_DOMAIN_ROLE
        error_invalid_domain_role = ERROR_INVALID_DOMAIN_ROLE,
#       else
#       endif
        /// <summary>The specified domain either does not exist or could not be contacted.</summary>

#       ifdef ERROR_NO_SUCH_DOMAIN
        error_no_such_domain = ERROR_NO_SUCH_DOMAIN,
#       else
#       endif
        /// <summary>The specified domain already exists.</summary>

#       ifdef ERROR_DOMAIN_EXISTS
        error_domain_exists = ERROR_DOMAIN_EXISTS,
#       else
#       endif
        /// <summary>An attempt was made to exceed the limit on the number of domains per server.</summary>

#       ifdef ERROR_DOMAIN_LIMIT_EXCEEDED
        error_domain_limit_exceeded = ERROR_DOMAIN_LIMIT_EXCEEDED,
#       else
#       endif
        /// <summary>Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.</summary>

#       ifdef ERROR_INTERNAL_DB_CORRUPTION
        error_internal_db_corruption = ERROR_INTERNAL_DB_CORRUPTION,
#       else
#       endif
        /// <summary>An internal error occurred.</summary>

#       ifdef ERROR_INTERNAL_ERROR
        error_internal_error = ERROR_INTERNAL_ERROR,
#       else
#       endif
        /// <summary>Generic access types were contained in an access mask which should already be mapped to nongeneric types.</summary>

#       ifdef ERROR_GENERIC_NOT_MAPPED
        error_generic_not_mapped = ERROR_GENERIC_NOT_MAPPED,
#       else
#       endif
        /// <summary>A security descriptor is not in the right format (absolute or self-relative).</summary>

#       ifdef ERROR_BAD_DESCRIPTOR_FORMAT
        error_bad_descriptor_format = ERROR_BAD_DESCRIPTOR_FORMAT,
#       else
#       endif
        /// <summary>The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.</summary>

#       ifdef ERROR_NOT_LOGON_PROCESS
        error_not_logon_process = ERROR_NOT_LOGON_PROCESS,
#       else
#       endif
        /// <summary>Cannot start a new logon session with an ID that is already in use.</summary>

#       ifdef ERROR_LOGON_SESSION_EXISTS
        error_logon_session_exists = ERROR_LOGON_SESSION_EXISTS,
#       else
#       endif
        /// <summary>A specified authentication package is unknown.</summary>

#       ifdef ERROR_NO_SUCH_PACKAGE
        error_no_such_package = ERROR_NO_SUCH_PACKAGE,
#       else
#       endif
        /// <summary>The logon session is not in a state that is consistent with the requested operation.</summary>

#       ifdef ERROR_BAD_LOGON_SESSION_STATE
        error_bad_logon_session_state = ERROR_BAD_LOGON_SESSION_STATE,
#       else
#       endif
        /// <summary>The logon session ID is already in use.</summary>

#       ifdef ERROR_LOGON_SESSION_COLLISION
        error_logon_session_collision = ERROR_LOGON_SESSION_COLLISION,
#       else
#       endif
        /// <summary>A logon request contained an invalid logon type value.</summary>

#       ifdef ERROR_INVALID_LOGON_TYPE
        error_invalid_logon_type = ERROR_INVALID_LOGON_TYPE,
#       else
#       endif
        /// <summary>Unable to impersonate using a named pipe until data has been read from that pipe.</summary>

#       ifdef ERROR_CANNOT_IMPERSONATE
        error_cannot_impersonate = ERROR_CANNOT_IMPERSONATE,
#       else
#       endif
        /// <summary>The transaction state of a registry subtree is incompatible with the requested operation.</summary>

#       ifdef ERROR_RXACT_INVALID_STATE
        error_rxact_invalid_state = ERROR_RXACT_INVALID_STATE,
#       else
#       endif
        /// <summary>An internal security database corruption has been encountered.</summary>

#       ifdef ERROR_RXACT_COMMIT_FAILURE
        error_rxact_commit_failure = ERROR_RXACT_COMMIT_FAILURE,
#       else
#       endif
        /// <summary>Cannot perform this operation on built-in accounts.</summary>

#       ifdef ERROR_SPECIAL_ACCOUNT
        error_special_account = ERROR_SPECIAL_ACCOUNT,
#       else
#       endif
        /// <summary>Cannot perform this operation on this built-in special group.</summary>

#       ifdef ERROR_SPECIAL_GROUP
        error_special_group = ERROR_SPECIAL_GROUP,
#       else
#       endif
        /// <summary>Cannot perform this operation on this built-in special user.</summary>

#       ifdef ERROR_SPECIAL_USER
        error_special_user = ERROR_SPECIAL_USER,
#       else
#       endif
        /// <summary>The user cannot be removed from a group because the group is currently the user's primary group.</summary>

#       ifdef ERROR_MEMBERS_PRIMARY_GROUP
        error_members_primary_group = ERROR_MEMBERS_PRIMARY_GROUP,
#       else
#       endif
        /// <summary>The token is already in use as a primary token.</summary>

#       ifdef ERROR_TOKEN_ALREADY_IN_USE
        error_token_already_in_use = ERROR_TOKEN_ALREADY_IN_USE,
#       else
#       endif
        /// <summary>The specified local group does not exist.</summary>

#       ifdef ERROR_NO_SUCH_ALIAS
        error_no_such_alias = ERROR_NO_SUCH_ALIAS,
#       else
#       endif
        /// <summary>The specified account name is not a member of the group.</summary>

#       ifdef ERROR_MEMBER_NOT_IN_ALIAS
        error_member_not_in_alias = ERROR_MEMBER_NOT_IN_ALIAS,
#       else
#       endif
        /// <summary>The specified account name is already a member of the group.</summary>

#       ifdef ERROR_MEMBER_IN_ALIAS
        error_member_in_alias = ERROR_MEMBER_IN_ALIAS,
#       else
#       endif
        /// <summary>The specified local group already exists.</summary>

#       ifdef ERROR_ALIAS_EXISTS
        error_alias_exists = ERROR_ALIAS_EXISTS,
#       else
#       endif
        /// <summary>Logon failure: the user has not been granted the requested logon type at this computer.</summary>

#       ifdef ERROR_LOGON_NOT_GRANTED
        error_logon_not_granted = ERROR_LOGON_NOT_GRANTED,
#       else
#       endif
        /// <summary>The maximum number of secrets that may be stored in a single system has been exceeded.</summary>

#       ifdef ERROR_TOO_MANY_SECRETS
        error_too_many_secrets = ERROR_TOO_MANY_SECRETS,
#       else
#       endif
        /// <summary>The length of a secret exceeds the maximum length allowed.</summary>

#       ifdef ERROR_SECRET_TOO_LONG
        error_secret_too_long = ERROR_SECRET_TOO_LONG,
#       else
#       endif
        /// <summary>The local security authority database contains an internal inconsistency.</summary>

#       ifdef ERROR_INTERNAL_DB_ERROR
        error_internal_db_error = ERROR_INTERNAL_DB_ERROR,
#       else
#       endif
        /// <summary>During a logon attempt, the user's security context accumulated too many security IDs.</summary>

#       ifdef ERROR_TOO_MANY_CONTEXT_IDS
        error_too_many_context_ids = ERROR_TOO_MANY_CONTEXT_IDS,
#       else
#       endif
        /// <summary>Logon failure: the user has not been granted the requested logon type at this computer.</summary>

#       ifdef ERROR_LOGON_TYPE_NOT_GRANTED
        error_logon_type_not_granted = ERROR_LOGON_TYPE_NOT_GRANTED,
#       else
#       endif
        /// <summary>A cross-encrypted password is necessary to change a user password.</summary>

#       ifdef ERROR_NT_CROSS_ENCRYPTION_REQUIRED
        error_nt_cross_encryption_required = ERROR_NT_CROSS_ENCRYPTION_REQUIRED,
#       else
#       endif
        /// <summary>A member could not be added to or removed from the local group because the member does not exist.</summary>

#       ifdef ERROR_NO_SUCH_MEMBER
        error_no_such_member = ERROR_NO_SUCH_MEMBER,
#       else
#       endif
        /// <summary>A new member could not be added to a local group because the member has the wrong account type.</summary>

#       ifdef ERROR_INVALID_MEMBER
        error_invalid_member = ERROR_INVALID_MEMBER,
#       else
#       endif
        /// <summary>Too many security IDs have been specified.</summary>

#       ifdef ERROR_TOO_MANY_SIDS
        error_too_many_sids = ERROR_TOO_MANY_SIDS,
#       else
#       endif
        /// <summary>A cross-encrypted password is necessary to change this user password.</summary>

#       ifdef ERROR_LM_CROSS_ENCRYPTION_REQUIRED
        error_lm_cross_encryption_required = ERROR_LM_CROSS_ENCRYPTION_REQUIRED,
#       else
#       endif
        /// <summary>Indicates an ACL contains no inheritable components.</summary>

#       ifdef ERROR_NO_INHERITANCE
        error_no_inheritance = ERROR_NO_INHERITANCE,
#       else
#       endif
        /// <summary>The file or directory is corrupted and unreadable.</summary>

#       ifdef ERROR_FILE_CORRUPT
        error_file_corrupt = ERROR_FILE_CORRUPT,
#       else
#       endif
        /// <summary>The disk structure is corrupted and unreadable.</summary>

#       ifdef ERROR_DISK_CORRUPT
        error_disk_corrupt = ERROR_DISK_CORRUPT,
#       else
#       endif
        /// <summary>There is no user session key for the specified logon session.</summary>
#       ifdef ERROR_NO_USER_SESSION_KEY
        error_no_user_session_key = ERROR_NO_USER_SESSION_KEY,
#       else
#       endif

        /// <summary>The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept.</summary>
#       ifdef ERROR_LICENSE_QUOTA_EXCEEDED
        error_license_quota_exceeded = ERROR_LICENSE_QUOTA_EXCEEDED,
#       else
#       endif

        /// <summary>The target account name is incorrect.</summary>
#       ifdef ERROR_WRONG_TARGET_NAME
        error_wrong_target_name = ERROR_WRONG_TARGET_NAME,
#       else
#       endif

        /// <summary>Mutual Authentication failed. The server's password is out of date at the domain controller.</summary>
#       ifdef ERROR_MUTUAL_AUTH_FAILED
        error_mutual_auth_failed = ERROR_MUTUAL_AUTH_FAILED,
#       else
#       endif

        /// <summary>There is a time and/or date difference between the client and server.</summary>
#       ifdef ERROR_TIME_SKEW
        error_time_skew = ERROR_TIME_SKEW,
#       else
#       endif

        /// <summary>This operation cannot be performed on the current domain.</summary>
#       ifdef ERROR_CURRENT_DOMAIN_NOT_ALLOWED
        error_current_domain_not_allowed = ERROR_CURRENT_DOMAIN_NOT_ALLOWED,
#       else
#       endif

        /// <summary>Invalid window handle.</summary>
#       ifdef ERROR_INVALID_WINDOW_HANDLE
        error_invalid_window_handle = ERROR_INVALID_WINDOW_HANDLE,
#       else
#       endif

        /// <summary>Invalid menu handle.</summary>
#       ifdef ERROR_INVALID_MENU_HANDLE
        error_invalid_menu_handle = ERROR_INVALID_MENU_HANDLE,
#       else
#       endif

        /// <summary>Invalid cursor handle.</summary>
#       ifdef ERROR_INVALID_CURSOR_HANDLE
        error_invalid_cursor_handle = ERROR_INVALID_CURSOR_HANDLE,
#       else
#       endif

        /// <summary>Invalid accelerator table handle.</summary>
#       ifdef ERROR_INVALID_ACCEL_HANDLE
        error_invalid_accel_handle = ERROR_INVALID_ACCEL_HANDLE,
#       else
#       endif

        /// <summary>Invalid hook handle.</summary>
#       ifdef ERROR_INVALID_HOOK_HANDLE
        error_invalid_hook_handle = ERROR_INVALID_HOOK_HANDLE,
#       else
#       endif

        /// <summary>Invalid handle to a multiple-window position structure.</summary>
#       ifdef ERROR_INVALID_DWP_HANDLE
        error_invalid_dwp_handle = ERROR_INVALID_DWP_HANDLE,
#       else
#       endif

        /// <summary>Cannot create a top-level child window.</summary>
#       ifdef ERROR_TLW_WITH_WSCHILD
        error_tlw_with_wschild = ERROR_TLW_WITH_WSCHILD,
#       else
#       endif

        /// <summary>Cannot find window class.</summary>
#       ifdef ERROR_CANNOT_FIND_WND_CLASS
        error_cannot_find_wnd_class = ERROR_CANNOT_FIND_WND_CLASS,
#       else
#       endif

        /// <summary>Invalid window; it belongs to other thread.</summary>
#       ifdef ERROR_WINDOW_OF_OTHER_THREAD
        error_window_of_other_thread = ERROR_WINDOW_OF_OTHER_THREAD,
#       else
#       endif

        /// <summary>Hot key is already registered.</summary>
#       ifdef ERROR_HOTKEY_ALREADY_REGISTERED
        error_hotkey_already_registered = ERROR_HOTKEY_ALREADY_REGISTERED,
#       else
#       endif

        /// <summary>Class already exists.</summary>
#       ifdef ERROR_CLASS_ALREADY_EXISTS
        error_class_already_exists = ERROR_CLASS_ALREADY_EXISTS,
#       else
#       endif

        /// <summary>Class does not exist.</summary>
#       ifdef ERROR_CLASS_DOES_NOT_EXIST
        error_class_does_not_exist = ERROR_CLASS_DOES_NOT_EXIST,
#       else
#       endif
        /// <summary>Class still has open windows.</summary>

#       ifdef ERROR_CLASS_HAS_WINDOWS
        error_class_has_windows = ERROR_CLASS_HAS_WINDOWS,
#       else
#       endif
        /// <summary>Invalid index.</summary>

#       ifdef ERROR_INVALID_INDEX
        error_invalid_index = ERROR_INVALID_INDEX,
#       else
#       endif
        /// <summary>Invalid icon handle.</summary>

#       ifdef ERROR_INVALID_ICON_HANDLE
        error_invalid_icon_handle = ERROR_INVALID_ICON_HANDLE,
#       else
#       endif
        /// <summary>Using private DIALOG window words.</summary>

#       ifdef ERROR_PRIVATE_DIALOG_INDEX
        error_private_dialog_index = ERROR_PRIVATE_DIALOG_INDEX,
#       else
#       endif
        /// <summary>The list box identifier was not found.</summary>

#       ifdef ERROR_LISTBOX_ID_NOT_FOUND
        error_listbox_id_not_found = ERROR_LISTBOX_ID_NOT_FOUND,
#       else
#       endif
        /// <summary>No wildcards were found.</summary>

#       ifdef ERROR_NO_WILDCARD_CHARACTERS
        error_no_wildcard_characters = ERROR_NO_WILDCARD_CHARACTERS,
#       else
#       endif
        /// <summary>Thread does not have a clipboard open.</summary>

#       ifdef ERROR_CLIPBOARD_NOT_OPEN
        error_clipboard_not_open = ERROR_CLIPBOARD_NOT_OPEN,
#       else
#       endif
        /// <summary>Hot key is not registered.</summary>

#       ifdef ERROR_HOTKEY_NOT_REGISTERED
        error_hotkey_not_registered = ERROR_HOTKEY_NOT_REGISTERED,
#       else
#       endif
        /// <summary>The window is not a valid dialog window.</summary>

#       ifdef ERROR_WINDOW_NOT_DIALOG
        error_window_not_dialog = ERROR_WINDOW_NOT_DIALOG,
#       else
#       endif
        /// <summary>Control ID not found.</summary>

#       ifdef ERROR_CONTROL_ID_NOT_FOUND
        error_control_id_not_found = ERROR_CONTROL_ID_NOT_FOUND,
#       else
#       endif
        /// <summary>Invalid message for a combo box because it does not have an edit control.</summary>

#       ifdef ERROR_INVALID_COMBOBOX_MESSAGE
        error_invalid_combobox_message = ERROR_INVALID_COMBOBOX_MESSAGE,
#       else
#       endif
        /// <summary>The window is not a combo box.</summary>

#       ifdef ERROR_WINDOW_NOT_COMBOBOX
        error_window_not_combobox = ERROR_WINDOW_NOT_COMBOBOX,
#       else
#       endif
        /// <summary>Height must be less than 256.</summary>

#       ifdef ERROR_INVALID_EDIT_HEIGHT
        error_invalid_edit_height = ERROR_INVALID_EDIT_HEIGHT,
#       else
#       endif
        /// <summary>Invalid device context (DC) handle.</summary>

#       ifdef ERROR_DC_NOT_FOUND
        error_dc_not_found = ERROR_DC_NOT_FOUND,
#       else
#       endif
        /// <summary>Invalid hook procedure type.</summary>

#       ifdef ERROR_INVALID_HOOK_FILTER
        error_invalid_hook_filter = ERROR_INVALID_HOOK_FILTER,
#       else
#       endif
        /// <summary>Invalid hook procedure.</summary>

#       ifdef ERROR_INVALID_FILTER_PROC
        error_invalid_filter_proc = ERROR_INVALID_FILTER_PROC,
#       else
#       endif
        /// <summary>Cannot set nonlocal hook without a module handle.</summary>

#       ifdef ERROR_HOOK_NEEDS_HMOD
        error_hook_needs_hmod = ERROR_HOOK_NEEDS_HMOD,
#       else
#       endif
        /// <summary>This hook procedure can only be set globally.</summary>

#       ifdef ERROR_GLOBAL_ONLY_HOOK
        error_global_only_hook = ERROR_GLOBAL_ONLY_HOOK,
#       else
#       endif
        /// <summary>The journal hook procedure is already installed.</summary>

#       ifdef ERROR_JOURNAL_HOOK_SET
        error_journal_hook_set = ERROR_JOURNAL_HOOK_SET,
#       else
#       endif
        /// <summary>The hook procedure is not installed.</summary>

#       ifdef ERROR_HOOK_NOT_INSTALLED
        error_hook_not_installed = ERROR_HOOK_NOT_INSTALLED,
#       else
#       endif
        /// <summary>Invalid message for single-selection list box.</summary>

#       ifdef ERROR_INVALID_LB_MESSAGE
        error_invalid_lb_message = ERROR_INVALID_LB_MESSAGE,
#       else
#       endif
        /// <summary>LB_SETCOUNT sent to non-lazy list box.</summary>

#       ifdef ERROR_SETCOUNT_ON_BAD_LB
        error_setcount_on_bad_lb = ERROR_SETCOUNT_ON_BAD_LB,
#       else
#       endif
        /// <summary>This list box does not support tab stops.</summary>

#       ifdef ERROR_LB_WITHOUT_TABSTOPS
        error_lb_without_tabstops = ERROR_LB_WITHOUT_TABSTOPS,
#       else
#       endif
        /// <summary>Cannot destroy object created by another thread.</summary>

#       ifdef ERROR_DESTROY_OBJECT_OF_OTHER_THREAD
        error_destroy_object_of_other_thread = ERROR_DESTROY_OBJECT_OF_OTHER_THREAD,
#       else
#       endif
        /// <summary>Child windows cannot have menus.</summary>

#       ifdef ERROR_CHILD_WINDOW_MENU
        error_child_window_menu = ERROR_CHILD_WINDOW_MENU,
#       else
#       endif
        /// <summary>The window does not have a system menu.</summary>

#       ifdef ERROR_NO_SYSTEM_MENU
        error_no_system_menu = ERROR_NO_SYSTEM_MENU,
#       else
#       endif
        /// <summary>Invalid message box style.</summary>

#       ifdef ERROR_INVALID_MSGBOX_STYLE
        error_invalid_msgbox_style = ERROR_INVALID_MSGBOX_STYLE,
#       else
#       endif
        /// <summary>Invalid system-wide (SPI_*) parameter.</summary>

#       ifdef ERROR_INVALID_SPI_VALUE
        error_invalid_spi_value = ERROR_INVALID_SPI_VALUE,
#       else
#       endif
        /// <summary>Screen already locked.</summary>

#       ifdef ERROR_SCREEN_ALREADY_LOCKED
        error_screen_already_locked = ERROR_SCREEN_ALREADY_LOCKED,
#       else
#       endif
        /// <summary>All handles to windows in a multiple-window position structure must have the same parent.</summary>

#       ifdef ERROR_HWNDS_HAVE_DIFF_PARENT
        error_hwnds_have_diff_parent = ERROR_HWNDS_HAVE_DIFF_PARENT,
#       else
#       endif
        /// <summary>The window is not a child window.</summary>

#       ifdef ERROR_NOT_CHILD_WINDOW
        error_not_child_window = ERROR_NOT_CHILD_WINDOW,
#       else
#       endif
        /// <summary>Invalid GW_* command.</summary>

#       ifdef ERROR_INVALID_GW_COMMAND
        error_invalid_gw_command = ERROR_INVALID_GW_COMMAND,
#       else
#       endif
        /// <summary>Invalid thread identifier.</summary>

#       ifdef ERROR_INVALID_THREAD_ID
        error_invalid_thread_id = ERROR_INVALID_THREAD_ID,
#       else
#       endif
        /// <summary>Cannot process a message from a window that is not a multiple document interface (MDI) window.</summary>

#       ifdef ERROR_NON_MDICHILD_WINDOW
        error_non_mdichild_window = ERROR_NON_MDICHILD_WINDOW,
#       else
#       endif
        /// <summary>Popup menu already active.</summary>

#       ifdef ERROR_POPUP_ALREADY_ACTIVE
        error_popup_already_active = ERROR_POPUP_ALREADY_ACTIVE,
#       else
#       endif
        /// <summary>The window does not have scroll bars.</summary>

#       ifdef ERROR_NO_SCROLLBARS
        error_no_scrollbars = ERROR_NO_SCROLLBARS,
#       else
#       endif
        /// <summary>Scroll bar range cannot be greater than MAXLONG.</summary>

#       ifdef ERROR_INVALID_SCROLLBAR_RANGE
        error_invalid_scrollbar_range = ERROR_INVALID_SCROLLBAR_RANGE,
#       else
#       endif
        /// <summary>Cannot show or remove the window in the way specified.</summary>

#       ifdef ERROR_INVALID_SHOWWIN_COMMAND
        error_invalid_showwin_command = ERROR_INVALID_SHOWWIN_COMMAND,
#       else
#       endif
        /// <summary>Insufficient system resources exist to complete the requested service.</summary>

#       ifdef ERROR_NO_SYSTEM_RESOURCES
        error_no_system_resources = ERROR_NO_SYSTEM_RESOURCES,
#       else
#       endif
        /// <summary>Insufficient system resources exist to complete the requested service.</summary>

#       ifdef ERROR_NONPAGED_SYSTEM_RESOURCES
        error_nonpaged_system_resources = ERROR_NONPAGED_SYSTEM_RESOURCES,
#       else
#       endif
        /// <summary>Insufficient system resources exist to complete the requested service.</summary>

#       ifdef ERROR_PAGED_SYSTEM_RESOURCES
        error_paged_system_resources = ERROR_PAGED_SYSTEM_RESOURCES,
#       else
#       endif
        /// <summary>Insufficient quota to complete the requested service.</summary>

#       ifdef ERROR_WORKING_SET_QUOTA
        error_working_set_quota = ERROR_WORKING_SET_QUOTA,
#       else
#       endif
        /// <summary>Insufficient quota to complete the requested service.</summary>

#       ifdef ERROR_PAGEFILE_QUOTA
        error_pagefile_quota = ERROR_PAGEFILE_QUOTA,
#       else
#       endif
        /// <summary>The paging file is too small for this operation to complete.</summary>

#       ifdef ERROR_COMMITMENT_LIMIT
        error_commitment_limit = ERROR_COMMITMENT_LIMIT,
#       else
#       endif
        /// <summary>A menu item was not found.</summary>

#       ifdef ERROR_MENU_ITEM_NOT_FOUND
        error_menu_item_not_found = ERROR_MENU_ITEM_NOT_FOUND,
#       else
#       endif
        /// <summary>Invalid keyboard layout handle.</summary>

#       ifdef ERROR_INVALID_KEYBOARD_HANDLE
        error_invalid_keyboard_handle = ERROR_INVALID_KEYBOARD_HANDLE,
#       else
#       endif
        /// <summary>Hook type not allowed.</summary>

#       ifdef ERROR_HOOK_TYPE_NOT_ALLOWED
        error_hook_type_not_allowed = ERROR_HOOK_TYPE_NOT_ALLOWED,
#       else
#       endif
        /// <summary>This operation requires an interactive window station.</summary>

#       ifdef ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION
        error_requires_interactive_windowstation = ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION,
#       else
#       endif
        /// <summary>This operation returned because the timeout period expired.</summary>

#       ifdef ERROR_TIMEOUT
        error_timeout = ERROR_TIMEOUT,
#       else
#       endif
        /// <summary>Invalid monitor handle.</summary>

#       ifdef ERROR_INVALID_MONITOR_HANDLE
        error_invalid_monitor_handle = ERROR_INVALID_MONITOR_HANDLE,
#       else
#       endif
        /// <summary>Incorrect size argument.</summary>

#       ifdef ERROR_INCORRECT_SIZE
        error_incorrect_size = ERROR_INCORRECT_SIZE,
#       else
#       endif
        /// <summary>The symbolic link cannot be followed because its type is disabled.</summary>

#       ifdef ERROR_SYMLINK_CLASS_DISABLED
        error_symlink_class_disabled = ERROR_SYMLINK_CLASS_DISABLED,
#       else
#       endif
        /// <summary>This application does not support the current operation on symbolic links.</summary>

#       ifdef ERROR_SYMLINK_NOT_SUPPORTED
        error_symlink_not_supported = ERROR_SYMLINK_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>Windows was unable to parse the requested XML data.</summary>

#       ifdef ERROR_XML_PARSE_ERROR
        error_xml_parse_error = ERROR_XML_PARSE_ERROR,
#       else
#       endif
        /// <summary>An error was encountered while processing an XML digital signature.</summary>

#       ifdef ERROR_XMLDSIG_ERROR
        error_xmldsig_error = ERROR_XMLDSIG_ERROR,
#       else
#       endif
        /// <summary>This application must be restarted.</summary>

#       ifdef ERROR_RESTART_APPLICATION
        error_restart_application = ERROR_RESTART_APPLICATION,
#       else
#       endif
        /// <summary>The caller made the connection request in the wrong routing compartment.</summary>

#       ifdef ERROR_WRONG_COMPARTMENT
        error_wrong_compartment = ERROR_WRONG_COMPARTMENT,
#       else
#       endif
        /// <summary>There was an AuthIP failure when attempting to connect to the remote host.</summary>

#       ifdef ERROR_AUTHIP_FAILURE
        error_authip_failure = ERROR_AUTHIP_FAILURE,
#       else
#       endif
        /// <summary>Insufficient NVRAM resources exist to complete the requested service. A reboot might be required.</summary>

#       ifdef ERROR_NO_NVRAM_RESOURCES
        error_no_nvram_resources = ERROR_NO_NVRAM_RESOURCES,
#       else
#       endif
        /// <summary>Unable to finish the requested operation because the specified process is not a GUI process.</summary>

#       ifdef ERROR_NOT_GUI_PROCESS
        error_not_gui_process = ERROR_NOT_GUI_PROCESS,
#       else
#       endif
        /// <summary>The event log file is corrupted.</summary>

#       ifdef ERROR_EVENTLOG_FILE_CORRUPT
        error_eventlog_file_corrupt = ERROR_EVENTLOG_FILE_CORRUPT,
#       else
#       endif
        /// <summary>No event log file could be opened, so the event logging service did not start.</summary>

#       ifdef ERROR_EVENTLOG_CANT_START
        error_eventlog_cant_start = ERROR_EVENTLOG_CANT_START,
#       else
#       endif
        /// <summary>The event log file is full.</summary>

#       ifdef ERROR_LOG_FILE_FULL
        error_log_file_full = ERROR_LOG_FILE_FULL,
#       else
#       endif
        /// <summary>The event log file has changed between read operations.</summary>

#       ifdef ERROR_EVENTLOG_FILE_CHANGED
        error_eventlog_file_changed = ERROR_EVENTLOG_FILE_CHANGED,
#       else
#       endif
        /// <summary>The specified Job already has a container assigned to it.</summary>

#       ifdef ERROR_CONTAINER_ASSIGNED
        error_container_assigned = ERROR_CONTAINER_ASSIGNED,
#       else
#       endif
        /// <summary>The specified Job does not have a container assigned to it.</summary>

#       ifdef ERROR_JOB_NO_CONTAINER
        error_job_no_container = ERROR_JOB_NO_CONTAINER,
#       else
#       endif
        /// <summary>The specified task name is invalid.</summary>

#       ifdef ERROR_INVALID_TASK_NAME
        error_invalid_task_name = ERROR_INVALID_TASK_NAME,
#       else
#       endif
        /// <summary>The specified task index is invalid.</summary>

#       ifdef ERROR_INVALID_TASK_INDEX
        error_invalid_task_index = ERROR_INVALID_TASK_INDEX,
#       else
#       endif
        /// <summary>The specified thread is already joining a task.</summary>

#       ifdef ERROR_THREAD_ALREADY_IN_TASK
        error_thread_already_in_task = ERROR_THREAD_ALREADY_IN_TASK,
#       else
#       endif
        /// <summary>The Windows Installer Service could not be accessed. This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance.</summary>

#       ifdef ERROR_INSTALL_SERVICE_FAILURE
        error_install_service_failure = ERROR_INSTALL_SERVICE_FAILURE,
#       else
#       endif
        /// <summary>User cancelled installation.</summary>

#       ifdef ERROR_INSTALL_USEREXIT
        error_install_userexit = ERROR_INSTALL_USEREXIT,
#       else
#       endif
        /// <summary>Fatal error during installation.</summary>

#       ifdef ERROR_INSTALL_FAILURE
        error_install_failure = ERROR_INSTALL_FAILURE,
#       else
#       endif
        /// <summary>Installation suspended, incomplete.</summary>

#       ifdef ERROR_INSTALL_SUSPEND
        error_install_suspend = ERROR_INSTALL_SUSPEND,
#       else
#       endif
        /// <summary>This action is only valid for products that are currently installed.</summary>

#       ifdef ERROR_UNKNOWN_PRODUCT
        error_unknown_product = ERROR_UNKNOWN_PRODUCT,
#       else
#       endif
        /// <summary>Feature ID not registered.</summary>

#       ifdef ERROR_UNKNOWN_FEATURE
        error_unknown_feature = ERROR_UNKNOWN_FEATURE,
#       else
#       endif
        /// <summary>Component ID not registered.</summary>

#       ifdef ERROR_UNKNOWN_COMPONENT
        error_unknown_component = ERROR_UNKNOWN_COMPONENT,
#       else
#       endif
        /// <summary>Unknown property.</summary>

#       ifdef ERROR_UNKNOWN_PROPERTY
        error_unknown_property = ERROR_UNKNOWN_PROPERTY,
#       else
#       endif
        /// <summary>Handle is in an invalid state.</summary>

#       ifdef ERROR_INVALID_HANDLE_STATE
        error_invalid_handle_state = ERROR_INVALID_HANDLE_STATE,
#       else
#       endif
        /// <summary>The configuration data for this product is corrupt. Contact your support personnel.</summary>

#       ifdef ERROR_BAD_CONFIGURATION
        error_bad_configuration = ERROR_BAD_CONFIGURATION,
#       else
#       endif
        /// <summary>Component qualifier not present.</summary>

#       ifdef ERROR_INDEX_ABSENT
        error_index_absent = ERROR_INDEX_ABSENT,
#       else
#       endif
        /// <summary>The installation source for this product is not available. Verify that the source exists and that you can access it.</summary>

#       ifdef ERROR_INSTALL_SOURCE_ABSENT
        error_install_source_absent = ERROR_INSTALL_SOURCE_ABSENT,
#       else
#       endif
        /// <summary>This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.</summary>

#       ifdef ERROR_INSTALL_PACKAGE_VERSION
        error_install_package_version = ERROR_INSTALL_PACKAGE_VERSION,
#       else
#       endif
        /// <summary>Product is uninstalled.</summary>

#       ifdef ERROR_PRODUCT_UNINSTALLED
        error_product_uninstalled = ERROR_PRODUCT_UNINSTALLED,
#       else
#       endif
        /// <summary>SQL query syntax invalid or unsupported.</summary>

#       ifdef ERROR_BAD_QUERY_SYNTAX
        error_bad_query_syntax = ERROR_BAD_QUERY_SYNTAX,
#       else
#       endif
        /// <summary>Record field does not exist.</summary>

#       ifdef ERROR_INVALID_FIELD
        error_invalid_field = ERROR_INVALID_FIELD,
#       else
#       endif
        /// <summary>The device has been removed.</summary>

#       ifdef ERROR_DEVICE_REMOVED
        error_device_removed = ERROR_DEVICE_REMOVED,
#       else
#       endif
        /// <summary>Another installation is already in progress. Complete that installation before proceeding with this install.</summary>

#       ifdef ERROR_INSTALL_ALREADY_RUNNING
        error_install_already_running = ERROR_INSTALL_ALREADY_RUNNING,
#       else
#       endif
        /// <summary>This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.</summary>

#       ifdef ERROR_INSTALL_PACKAGE_OPEN_FAILED
        error_install_package_open_failed = ERROR_INSTALL_PACKAGE_OPEN_FAILED,
#       else
#       endif
        /// <summary>This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package.</summary>

#       ifdef ERROR_INSTALL_PACKAGE_INVALID
        error_install_package_invalid = ERROR_INSTALL_PACKAGE_INVALID,
#       else
#       endif
        /// <summary>There was an error starting the Windows Installer service user interface. Contact your support personnel.</summary>

#       ifdef ERROR_INSTALL_UI_FAILURE
        error_install_ui_failure = ERROR_INSTALL_UI_FAILURE,
#       else
#       endif
        /// <summary>Error opening installation log file. Verify that the specified log file location exists and that you can write to it.</summary>

#       ifdef ERROR_INSTALL_LOG_FAILURE
        error_install_log_failure = ERROR_INSTALL_LOG_FAILURE,
#       else
#       endif
        /// <summary>The language of this installation package is not supported by your system.</summary>

#       ifdef ERROR_INSTALL_LANGUAGE_UNSUPPORTED
        error_install_language_unsupported = ERROR_INSTALL_LANGUAGE_UNSUPPORTED,
#       else
#       endif
        /// <summary>Error applying transforms. Verify that the specified transform paths are valid.</summary>

#       ifdef ERROR_INSTALL_TRANSFORM_FAILURE
        error_install_transform_failure = ERROR_INSTALL_TRANSFORM_FAILURE,
#       else
#       endif
        /// <summary>This installation is forbidden by system policy. Contact your system administrator.</summary>

#       ifdef ERROR_INSTALL_PACKAGE_REJECTED
        error_install_package_rejected = ERROR_INSTALL_PACKAGE_REJECTED,
#       else
#       endif
        /// <summary>Function could not be executed.</summary>

#       ifdef ERROR_FUNCTION_NOT_CALLED
        error_function_not_called = ERROR_FUNCTION_NOT_CALLED,
#       else
#       endif
        /// <summary>Function failed during execution.</summary>

#       ifdef ERROR_FUNCTION_FAILED
        error_function_failed = ERROR_FUNCTION_FAILED,
#       else
#       endif
        /// <summary>Invalid or unknown table specified.</summary>

#       ifdef ERROR_INVALID_TABLE
        error_invalid_table = ERROR_INVALID_TABLE,
#       else
#       endif
        /// <summary>Data supplied is of wrong type.</summary>

#       ifdef ERROR_DATATYPE_MISMATCH
        error_datatype_mismatch = ERROR_DATATYPE_MISMATCH,
#       else
#       endif
        /// <summary>Data of this type is not supported.</summary>

#       ifdef ERROR_UNSUPPORTED_TYPE
        error_unsupported_type = ERROR_UNSUPPORTED_TYPE,
#       else
#       endif
        /// <summary>The Windows Installer service failed to start. Contact your support personnel.</summary>

#       ifdef ERROR_CREATE_FAILED
        error_create_failed = ERROR_CREATE_FAILED,
#       else
#       endif
        /// <summary>The Temp folder is on a drive that is full or is inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder.</summary>

#       ifdef ERROR_INSTALL_TEMP_UNWRITABLE
        error_install_temp_unwritable = ERROR_INSTALL_TEMP_UNWRITABLE,
#       else
#       endif
        /// <summary>This installation package is not supported by this processor type. Contact your product vendor.</summary>

#       ifdef ERROR_INSTALL_PLATFORM_UNSUPPORTED
        error_install_platform_unsupported = ERROR_INSTALL_PLATFORM_UNSUPPORTED,
#       else
#       endif
        /// <summary>Component not used on this computer.</summary>

#       ifdef ERROR_INSTALL_NOTUSED
        error_install_notused = ERROR_INSTALL_NOTUSED,
#       else
#       endif
        /// <summary>This update package could not be opened. Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package.</summary>

#       ifdef ERROR_PATCH_PACKAGE_OPEN_FAILED
        error_patch_package_open_failed = ERROR_PATCH_PACKAGE_OPEN_FAILED,
#       else
#       endif
        /// <summary>This update package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer update package.</summary>

#       ifdef ERROR_PATCH_PACKAGE_INVALID
        error_patch_package_invalid = ERROR_PATCH_PACKAGE_INVALID,
#       else
#       endif
        /// <summary>This update package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.</summary>

#       ifdef ERROR_PATCH_PACKAGE_UNSUPPORTED
        error_patch_package_unsupported = ERROR_PATCH_PACKAGE_UNSUPPORTED,
#       else
#       endif
        /// <summary>Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.</summary>

#       ifdef ERROR_PRODUCT_VERSION
        error_product_version = ERROR_PRODUCT_VERSION,
#       else
#       endif
        /// <summary>Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.</summary>

#       ifdef ERROR_INVALID_COMMAND_LINE
        error_invalid_command_line = ERROR_INVALID_COMMAND_LINE,
#       else
#       endif
        /// <summary>Only administrators have permission to add, remove, or configure server software during a Terminal services remote session. If you want to install or configure software on the server, contact your network administrator.</summary>

#       ifdef ERROR_INSTALL_REMOTE_DISALLOWED
        error_install_remote_disallowed = ERROR_INSTALL_REMOTE_DISALLOWED,
#       else
#       endif
        /// <summary>The requested operation completed successfully. The system will be restarted so the changes can take effect.</summary>

#       ifdef ERROR_SUCCESS_REBOOT_INITIATED
        error_success_reboot_initiated = ERROR_SUCCESS_REBOOT_INITIATED,
#       else
#       endif
        /// <summary>The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade.</summary>

#       ifdef ERROR_PATCH_TARGET_NOT_FOUND
        error_patch_target_not_found = ERROR_PATCH_TARGET_NOT_FOUND,
#       else
#       endif
        /// <summary>The update package is not permitted by software restriction policy.</summary>

#       ifdef ERROR_PATCH_PACKAGE_REJECTED
        error_patch_package_rejected = ERROR_PATCH_PACKAGE_REJECTED,
#       else
#       endif
        /// <summary>One or more customizations are not permitted by software restriction policy.</summary>

#       ifdef ERROR_INSTALL_TRANSFORM_REJECTED
        error_install_transform_rejected = ERROR_INSTALL_TRANSFORM_REJECTED,
#       else
#       endif
        /// <summary>The Windows Installer does not permit installation from a Remote Desktop Connection.</summary>

#       ifdef ERROR_INSTALL_REMOTE_PROHIBITED
        error_install_remote_prohibited = ERROR_INSTALL_REMOTE_PROHIBITED,
#       else
#       endif
        /// <summary>Uninstallation of the update package is not supported.</summary>

#       ifdef ERROR_PATCH_REMOVAL_UNSUPPORTED
        error_patch_removal_unsupported = ERROR_PATCH_REMOVAL_UNSUPPORTED,
#       else
#       endif
        /// <summary>The update is not applied to this product.</summary>

#       ifdef ERROR_UNKNOWN_PATCH
        error_unknown_patch = ERROR_UNKNOWN_PATCH,
#       else
#       endif
        /// <summary>No valid sequence could be found for the set of updates.</summary>

#       ifdef ERROR_PATCH_NO_SEQUENCE
        error_patch_no_sequence = ERROR_PATCH_NO_SEQUENCE,
#       else
#       endif
        /// <summary>Update removal was disallowed by policy.</summary>

#       ifdef ERROR_PATCH_REMOVAL_DISALLOWED
        error_patch_removal_disallowed = ERROR_PATCH_REMOVAL_DISALLOWED,
#       else
#       endif
        /// <summary>The XML update data is invalid.</summary>

#       ifdef ERROR_INVALID_PATCH_XML
        error_invalid_patch_xml = ERROR_INVALID_PATCH_XML,
#       else
#       endif
        /// <summary>Windows Installer does not permit updating of managed advertised products. At least one feature of the product must be installed before applying the update.</summary>

#       ifdef ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT
        error_patch_managed_advertised_product = ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT,
#       else
#       endif
        /// <summary>The Windows Installer service is not accessible in Safe Mode. Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state.</summary>

#       ifdef ERROR_INSTALL_SERVICE_SAFEBOOT
        error_install_service_safeboot = ERROR_INSTALL_SERVICE_SAFEBOOT,
#       else
#       endif
        /// <summary>A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately.</summary>

#       ifdef ERROR_FAIL_FAST_EXCEPTION
        error_fail_fast_exception = ERROR_FAIL_FAST_EXCEPTION,
#       else
#       endif
        /// <summary>The app that you are trying to run is not supported on this version of Windows.</summary>

#       ifdef ERROR_INSTALL_REJECTED
        error_install_rejected = ERROR_INSTALL_REJECTED,
#       else
#       endif
        /// <summary>The operation was blocked as the process prohibits dynamic code generation.</summary>

#       ifdef ERROR_DYNAMIC_CODE_BLOCKED
        error_dynamic_code_blocked = ERROR_DYNAMIC_CODE_BLOCKED,
#       else
#       endif
        /// <summary>The objects are not identical.</summary>

#       ifdef ERROR_NOT_SAME_OBJECT
        error_not_same_object = ERROR_NOT_SAME_OBJECT,
#       else
#       endif
        /// <summary>The specified image file was blocked from loading because it does not enable a feature required by the process: Control Flow Guard.</summary>

#       ifdef ERROR_STRICT_CFG_VIOLATION
        error_strict_cfg_violation = ERROR_STRICT_CFG_VIOLATION,
#       else
#       endif
        /// <summary>The thread context could not be updated because this has been restricted for the process.</summary>

#       ifdef ERROR_SET_CONTEXT_DENIED
        error_set_context_denied = ERROR_SET_CONTEXT_DENIED,
#       else
#       endif
        /// <summary>An invalid cross-partition private file/section access was attempted.</summary>

#       ifdef ERROR_CROSS_PARTITION_VIOLATION
        error_cross_partition_violation = ERROR_CROSS_PARTITION_VIOLATION,
#       else
#       endif
        /// <summary>The string binding is invalid.</summary>

#       ifdef RPC_S_INVALID_STRING_BINDING
        rpc_s_invalid_string_binding = RPC_S_INVALID_STRING_BINDING,
#       else
#       endif
        /// <summary>The binding handle is not the correct type.</summary>

#       ifdef RPC_S_WRONG_KIND_OF_BINDING
        rpc_s_wrong_kind_of_binding = RPC_S_WRONG_KIND_OF_BINDING,
#       else
#       endif
        /// <summary>The binding handle is invalid.</summary>

#       ifdef RPC_S_INVALID_BINDING
        rpc_s_invalid_binding = RPC_S_INVALID_BINDING,
#       else
#       endif
        /// <summary>The RPC protocol sequence is not supported.</summary>

#       ifdef RPC_S_PROTSEQ_NOT_SUPPORTED
        rpc_s_protseq_not_supported = RPC_S_PROTSEQ_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The RPC protocol sequence is invalid.</summary>

#       ifdef RPC_S_INVALID_RPC_PROTSEQ
        rpc_s_invalid_rpc_protseq = RPC_S_INVALID_RPC_PROTSEQ,
#       else
#       endif
        /// <summary>The string universal unique identifier (UUID) is invalid.</summary>

#       ifdef RPC_S_INVALID_STRING_UUID
        rpc_s_invalid_string_uuid = RPC_S_INVALID_STRING_UUID,
#       else
#       endif
        /// <summary>The endpoint format is invalid.</summary>

#       ifdef RPC_S_INVALID_ENDPOINT_FORMAT
        rpc_s_invalid_endpoint_format = RPC_S_INVALID_ENDPOINT_FORMAT,
#       else
#       endif
        /// <summary>The network address is invalid.</summary>

#       ifdef RPC_S_INVALID_NET_ADDR
        rpc_s_invalid_net_addr = RPC_S_INVALID_NET_ADDR,
#       else
#       endif
        /// <summary>No endpoint was found.</summary>

#       ifdef RPC_S_NO_ENDPOINT_FOUND
        rpc_s_no_endpoint_found = RPC_S_NO_ENDPOINT_FOUND,
#       else
#       endif
        /// <summary>The timeout value is invalid.</summary>

#       ifdef RPC_S_INVALID_TIMEOUT
        rpc_s_invalid_timeout = RPC_S_INVALID_TIMEOUT,
#       else
#       endif
        /// <summary>The object universal unique identifier (UUID) was not found.</summary>

#       ifdef RPC_S_OBJECT_NOT_FOUND
        rpc_s_object_not_found = RPC_S_OBJECT_NOT_FOUND,
#       else
#       endif
        /// <summary>The object universal unique identifier (UUID) has already been registered.</summary>

#       ifdef RPC_S_ALREADY_REGISTERED
        rpc_s_already_registered = RPC_S_ALREADY_REGISTERED,
#       else
#       endif
        /// <summary>The type universal unique identifier (UUID) has already been registered.</summary>

#       ifdef RPC_S_TYPE_ALREADY_REGISTERED
        rpc_s_type_already_registered = RPC_S_TYPE_ALREADY_REGISTERED,
#       else
#       endif
        /// <summary>The RPC server is already listening.</summary>

#       ifdef RPC_S_ALREADY_LISTENING
        rpc_s_already_listening = RPC_S_ALREADY_LISTENING,
#       else
#       endif
        /// <summary>No protocol sequences have been registered.</summary>

#       ifdef RPC_S_NO_PROTSEQS_REGISTERED
        rpc_s_no_protseqs_registered = RPC_S_NO_PROTSEQS_REGISTERED,
#       else
#       endif
        /// <summary>The RPC server is not listening.</summary>

#       ifdef RPC_S_NOT_LISTENING
        rpc_s_not_listening = RPC_S_NOT_LISTENING,
#       else
#       endif
        /// <summary>The manager type is unknown.</summary>

#       ifdef RPC_S_UNKNOWN_MGR_TYPE
        rpc_s_unknown_mgr_type = RPC_S_UNKNOWN_MGR_TYPE,
#       else
#       endif
        /// <summary>The interface is unknown.</summary>

#       ifdef RPC_S_UNKNOWN_IF
        rpc_s_unknown_if = RPC_S_UNKNOWN_IF,
#       else
#       endif
        /// <summary>There are no bindings.</summary>

#       ifdef RPC_S_NO_BINDINGS
        rpc_s_no_bindings = RPC_S_NO_BINDINGS,
#       else
#       endif
        /// <summary>There are no protocol sequences.</summary>

#       ifdef RPC_S_NO_PROTSEQS
        rpc_s_no_protseqs = RPC_S_NO_PROTSEQS,
#       else
#       endif
        /// <summary>The endpoint cannot be created.</summary>

#       ifdef RPC_S_CANT_CREATE_ENDPOINT
        rpc_s_cant_create_endpoint = RPC_S_CANT_CREATE_ENDPOINT,
#       else
#       endif
        /// <summary>Not enough resources are available to complete this operation.</summary>

#       ifdef RPC_S_OUT_OF_RESOURCES
        rpc_s_out_of_resources = RPC_S_OUT_OF_RESOURCES,
#       else
#       endif
        /// <summary>The RPC server is unavailable.</summary>

#       ifdef RPC_S_SERVER_UNAVAILABLE
        rpc_s_server_unavailable = RPC_S_SERVER_UNAVAILABLE,
#       else
#       endif
        /// <summary>The RPC server is too busy to complete this operation.</summary>

#       ifdef RPC_S_SERVER_TOO_BUSY
        rpc_s_server_too_busy = RPC_S_SERVER_TOO_BUSY,
#       else
#       endif
        /// <summary>The network options are invalid.</summary>

#       ifdef RPC_S_INVALID_NETWORK_OPTIONS
        rpc_s_invalid_network_options = RPC_S_INVALID_NETWORK_OPTIONS,
#       else
#       endif
        /// <summary>There are no remote procedure calls active on this thread.</summary>

#       ifdef RPC_S_NO_CALL_ACTIVE
        rpc_s_no_call_active = RPC_S_NO_CALL_ACTIVE,
#       else
#       endif
        /// <summary>The remote procedure call failed.</summary>

#       ifdef RPC_S_CALL_FAILED
        rpc_s_call_failed = RPC_S_CALL_FAILED,
#       else
#       endif
        /// <summary>The remote procedure call failed and did not execute.</summary>

#       ifdef RPC_S_CALL_FAILED_DNE
        rpc_s_call_failed_dne = RPC_S_CALL_FAILED_DNE,
#       else
#       endif
        /// <summary>A remote procedure call (RPC) protocol error occurred.</summary>

#       ifdef RPC_S_PROTOCOL_ERROR
        rpc_s_protocol_error = RPC_S_PROTOCOL_ERROR,
#       else
#       endif
        /// <summary>Access to the HTTP proxy is denied.</summary>

#       ifdef RPC_S_PROXY_ACCESS_DENIED
        rpc_s_proxy_access_denied = RPC_S_PROXY_ACCESS_DENIED,
#       else
#       endif
        /// <summary>The transfer syntax is not supported by the RPC server.</summary>

#       ifdef RPC_S_UNSUPPORTED_TRANS_SYN
        rpc_s_unsupported_trans_syn = RPC_S_UNSUPPORTED_TRANS_SYN,
#       else
#       endif
        /// <summary>The universal unique identifier (UUID) type is not supported.</summary>

#       ifdef RPC_S_UNSUPPORTED_TYPE
        rpc_s_unsupported_type = RPC_S_UNSUPPORTED_TYPE,
#       else
#       endif
        /// <summary>The tag is invalid.</summary>

#       ifdef RPC_S_INVALID_TAG
        rpc_s_invalid_tag = RPC_S_INVALID_TAG,
#       else
#       endif
        /// <summary>The array bounds are invalid.</summary>

#       ifdef RPC_S_INVALID_BOUND
        rpc_s_invalid_bound = RPC_S_INVALID_BOUND,
#       else
#       endif
        /// <summary>The binding does not contain an entry name.</summary>

#       ifdef RPC_S_NO_ENTRY_NAME
        rpc_s_no_entry_name = RPC_S_NO_ENTRY_NAME,
#       else
#       endif
        /// <summary>The name syntax is invalid.</summary>

#       ifdef RPC_S_INVALID_NAME_SYNTAX
        rpc_s_invalid_name_syntax = RPC_S_INVALID_NAME_SYNTAX,
#       else
#       endif
        /// <summary>The name syntax is not supported.</summary>

#       ifdef RPC_S_UNSUPPORTED_NAME_SYNTAX
        rpc_s_unsupported_name_syntax = RPC_S_UNSUPPORTED_NAME_SYNTAX,
#       else
#       endif
        /// <summary>No network address is available to use to construct a universal unique identifier (UUID).</summary>

#       ifdef RPC_S_UUID_NO_ADDRESS
        rpc_s_uuid_no_address = RPC_S_UUID_NO_ADDRESS,
#       else
#       endif
        /// <summary>The endpoint is a duplicate.</summary>

#       ifdef RPC_S_DUPLICATE_ENDPOINT
        rpc_s_duplicate_endpoint = RPC_S_DUPLICATE_ENDPOINT,
#       else
#       endif
        /// <summary>The authentication type is unknown.</summary>

#       ifdef RPC_S_UNKNOWN_AUTHN_TYPE
        rpc_s_unknown_authn_type = RPC_S_UNKNOWN_AUTHN_TYPE,
#       else
#       endif
        /// <summary>The maximum number of calls is too small.</summary>

#       ifdef RPC_S_MAX_CALLS_TOO_SMALL
        rpc_s_max_calls_too_small = RPC_S_MAX_CALLS_TOO_SMALL,
#       else
#       endif
        /// <summary>The string is too long.</summary>

#       ifdef RPC_S_STRING_TOO_LONG
        rpc_s_string_too_long = RPC_S_STRING_TOO_LONG,
#       else
#       endif
        /// <summary>The RPC protocol sequence was not found.</summary>

#       ifdef RPC_S_PROTSEQ_NOT_FOUND
        rpc_s_protseq_not_found = RPC_S_PROTSEQ_NOT_FOUND,
#       else
#       endif
        /// <summary>The procedure number is out of range.</summary>

#       ifdef RPC_S_PROCNUM_OUT_OF_RANGE
        rpc_s_procnum_out_of_range = RPC_S_PROCNUM_OUT_OF_RANGE,
#       else
#       endif
        /// <summary>The binding does not contain any authentication information.</summary>

#       ifdef RPC_S_BINDING_HAS_NO_AUTH
        rpc_s_binding_has_no_auth = RPC_S_BINDING_HAS_NO_AUTH,
#       else
#       endif
        /// <summary>The authentication service is unknown.</summary>

#       ifdef RPC_S_UNKNOWN_AUTHN_SERVICE
        rpc_s_unknown_authn_service = RPC_S_UNKNOWN_AUTHN_SERVICE,
#       else
#       endif
        /// <summary>The authentication level is unknown.</summary>

#       ifdef RPC_S_UNKNOWN_AUTHN_LEVEL
        rpc_s_unknown_authn_level = RPC_S_UNKNOWN_AUTHN_LEVEL,
#       else
#       endif
        /// <summary>The security context is invalid.</summary>

#       ifdef RPC_S_INVALID_AUTH_IDENTITY
        rpc_s_invalid_auth_identity = RPC_S_INVALID_AUTH_IDENTITY,
#       else
#       endif
        /// <summary>The authorization service is unknown.</summary>

#       ifdef RPC_S_UNKNOWN_AUTHZ_SERVICE
        rpc_s_unknown_authz_service = RPC_S_UNKNOWN_AUTHZ_SERVICE,
#       else
#       endif
        /// <summary>The entry is invalid.</summary>

#       ifdef EPT_S_INVALID_ENTRY
        ept_s_invalid_entry = EPT_S_INVALID_ENTRY,
#       else
#       endif
        /// <summary>The server endpoint cannot perform the operation.</summary>

#       ifdef EPT_S_CANT_PERFORM_OP
        ept_s_cant_perform_op = EPT_S_CANT_PERFORM_OP,
#       else
#       endif
        /// <summary>There are no more endpoints available from the endpoint mapper.</summary>

#       ifdef EPT_S_NOT_REGISTERED
        ept_s_not_registered = EPT_S_NOT_REGISTERED,
#       else
#       endif
        /// <summary>No interfaces have been exported.</summary>

#       ifdef RPC_S_NOTHING_TO_EXPORT
        rpc_s_nothing_to_export = RPC_S_NOTHING_TO_EXPORT,
#       else
#       endif
        /// <summary>The entry name is incomplete.</summary>

#       ifdef RPC_S_INCOMPLETE_NAME
        rpc_s_incomplete_name = RPC_S_INCOMPLETE_NAME,
#       else
#       endif
        /// <summary>The version option is invalid.</summary>

#       ifdef RPC_S_INVALID_VERS_OPTION
        rpc_s_invalid_vers_option = RPC_S_INVALID_VERS_OPTION,
#       else
#       endif
        /// <summary>There are no more members.</summary>

#       ifdef RPC_S_NO_MORE_MEMBERS
        rpc_s_no_more_members = RPC_S_NO_MORE_MEMBERS,
#       else
#       endif
        /// <summary>There is nothing to unexport.</summary>

#       ifdef RPC_S_NOT_ALL_OBJS_UNEXPORTED
        rpc_s_not_all_objs_unexported = RPC_S_NOT_ALL_OBJS_UNEXPORTED,
#       else
#       endif
        /// <summary>The interface was not found.</summary>

#       ifdef RPC_S_INTERFACE_NOT_FOUND
        rpc_s_interface_not_found = RPC_S_INTERFACE_NOT_FOUND,
#       else
#       endif
        /// <summary>The entry already exists.</summary>

#       ifdef RPC_S_ENTRY_ALREADY_EXISTS
        rpc_s_entry_already_exists = RPC_S_ENTRY_ALREADY_EXISTS,
#       else
#       endif
        /// <summary>The entry is not found.</summary>

#       ifdef RPC_S_ENTRY_NOT_FOUND
        rpc_s_entry_not_found = RPC_S_ENTRY_NOT_FOUND,
#       else
#       endif
        /// <summary>The name service is unavailable.</summary>

#       ifdef RPC_S_NAME_SERVICE_UNAVAILABLE
        rpc_s_name_service_unavailable = RPC_S_NAME_SERVICE_UNAVAILABLE,
#       else
#       endif
        /// <summary>The network address family is invalid.</summary>

#       ifdef RPC_S_INVALID_NAF_ID
        rpc_s_invalid_naf_id = RPC_S_INVALID_NAF_ID,
#       else
#       endif
        /// <summary>The requested operation is not supported.</summary>

#       ifdef RPC_S_CANNOT_SUPPORT
        rpc_s_cannot_support = RPC_S_CANNOT_SUPPORT,
#       else
#       endif
        /// <summary>No security context is available to allow impersonation.</summary>

#       ifdef RPC_S_NO_CONTEXT_AVAILABLE
        rpc_s_no_context_available = RPC_S_NO_CONTEXT_AVAILABLE,
#       else
#       endif
        /// <summary>An internal error occurred in a remote procedure call (RPC).</summary>

#       ifdef RPC_S_INTERNAL_ERROR
        rpc_s_internal_error = RPC_S_INTERNAL_ERROR,
#       else
#       endif
        /// <summary>The RPC server attempted an integer division by zero.</summary>

#       ifdef RPC_S_ZERO_DIVIDE
        rpc_s_zero_divide = RPC_S_ZERO_DIVIDE,
#       else
#       endif
        /// <summary>An addressing error occurred in the RPC server.</summary>

#       ifdef RPC_S_ADDRESS_ERROR
        rpc_s_address_error = RPC_S_ADDRESS_ERROR,
#       else
#       endif
        /// <summary>A floating-point operation at the RPC server caused a division by zero.</summary>

#       ifdef RPC_S_FP_DIV_ZERO
        rpc_s_fp_div_zero = RPC_S_FP_DIV_ZERO,
#       else
#       endif
        /// <summary>A floating-point underflow occurred at the RPC server.</summary>

#       ifdef RPC_S_FP_UNDERFLOW
        rpc_s_fp_underflow = RPC_S_FP_UNDERFLOW,
#       else
#       endif
        /// <summary>A floating-point overflow occurred at the RPC server.</summary>

#       ifdef RPC_S_FP_OVERFLOW
        rpc_s_fp_overflow = RPC_S_FP_OVERFLOW,
#       else
#       endif
        /// <summary>The list of RPC servers available for the binding of auto handles has been exhausted.</summary>

#       ifdef RPC_X_NO_MORE_ENTRIES
        rpc_x_no_more_entries = RPC_X_NO_MORE_ENTRIES,
#       else
#       endif
        /// <summary>Unable to open the character translation table file.</summary>

#       ifdef RPC_X_SS_CHAR_TRANS_OPEN_FAIL
        rpc_x_ss_char_trans_open_fail = RPC_X_SS_CHAR_TRANS_OPEN_FAIL,
#       else
#       endif
        /// <summary>The file containing the character translation table has fewer than 512 bytes.</summary>

#       ifdef RPC_X_SS_CHAR_TRANS_SHORT_FILE
        rpc_x_ss_char_trans_short_file = RPC_X_SS_CHAR_TRANS_SHORT_FILE,
#       else
#       endif
        /// <summary>A null context handle was passed from the client to the host during a remote procedure call.</summary>

#       ifdef RPC_X_SS_IN_NULL_CONTEXT
        rpc_x_ss_in_null_context = RPC_X_SS_IN_NULL_CONTEXT,
#       else
#       endif
        /// <summary>The context handle changed during a remote procedure call.</summary>

#       ifdef RPC_X_SS_CONTEXT_DAMAGED
        rpc_x_ss_context_damaged = RPC_X_SS_CONTEXT_DAMAGED,
#       else
#       endif
        /// <summary>The binding handles passed to a remote procedure call do not match.</summary>

#       ifdef RPC_X_SS_HANDLES_MISMATCH
        rpc_x_ss_handles_mismatch = RPC_X_SS_HANDLES_MISMATCH,
#       else
#       endif
        /// <summary>The stub is unable to get the remote procedure call handle.</summary>

#       ifdef RPC_X_SS_CANNOT_GET_CALL_HANDLE
        rpc_x_ss_cannot_get_call_handle = RPC_X_SS_CANNOT_GET_CALL_HANDLE,
#       else
#       endif
        /// <summary>A null reference pointer was passed to the stub.</summary>

#       ifdef RPC_X_NULL_REF_POINTER
        rpc_x_null_ref_pointer = RPC_X_NULL_REF_POINTER,
#       else
#       endif
        /// <summary>The enumeration value is out of range.</summary>

#       ifdef RPC_X_ENUM_VALUE_OUT_OF_RANGE
        rpc_x_enum_value_out_of_range = RPC_X_ENUM_VALUE_OUT_OF_RANGE,
#       else
#       endif
        /// <summary>The byte count is too small.</summary>

#       ifdef RPC_X_BYTE_COUNT_TOO_SMALL
        rpc_x_byte_count_too_small = RPC_X_BYTE_COUNT_TOO_SMALL,
#       else
#       endif
        /// <summary>The stub received bad data.</summary>

#       ifdef RPC_X_BAD_STUB_DATA
        rpc_x_bad_stub_data = RPC_X_BAD_STUB_DATA,
#       else
#       endif
        /// <summary>The supplied user buffer is not valid for the requested operation.</summary>

#       ifdef ERROR_INVALID_USER_BUFFER
        error_invalid_user_buffer = ERROR_INVALID_USER_BUFFER,
#       else
#       endif
        /// <summary>The disk media is not recognized. It may not be formatted.</summary>

#       ifdef ERROR_UNRECOGNIZED_MEDIA
        error_unrecognized_media = ERROR_UNRECOGNIZED_MEDIA,
#       else
#       endif
        /// <summary>The workstation does not have a trust secret.</summary>

#       ifdef ERROR_NO_TRUST_LSA_SECRET
        error_no_trust_lsa_secret = ERROR_NO_TRUST_LSA_SECRET,
#       else
#       endif
        /// <summary>The security database on the server does not have a computer account for this workstation trust relationship.</summary>

#       ifdef ERROR_NO_TRUST_SAM_ACCOUNT
        error_no_trust_sam_account = ERROR_NO_TRUST_SAM_ACCOUNT,
#       else
#       endif
        /// <summary>The trust relationship between the primary domain and the trusted domain failed.</summary>

#       ifdef ERROR_TRUSTED_DOMAIN_FAILURE
        error_trusted_domain_failure = ERROR_TRUSTED_DOMAIN_FAILURE,
#       else
#       endif
        /// <summary>The trust relationship between this workstation and the primary domain failed.</summary>

#       ifdef ERROR_TRUSTED_RELATIONSHIP_FAILURE
        error_trusted_relationship_failure = ERROR_TRUSTED_RELATIONSHIP_FAILURE,
#       else
#       endif
        /// <summary>The network logon failed.</summary>

#       ifdef ERROR_TRUST_FAILURE
        error_trust_failure = ERROR_TRUST_FAILURE,
#       else
#       endif
        /// <summary>A remote procedure call is already in progress for this thread.</summary>

#       ifdef RPC_S_CALL_IN_PROGRESS
        rpc_s_call_in_progress = RPC_S_CALL_IN_PROGRESS,
#       else
#       endif
        /// <summary>An attempt was made to logon, but the network logon service was not started.</summary>

#       ifdef ERROR_NETLOGON_NOT_STARTED
        error_netlogon_not_started = ERROR_NETLOGON_NOT_STARTED,
#       else
#       endif
        /// <summary>The user's account has expired.</summary>

#       ifdef ERROR_ACCOUNT_EXPIRED
        error_account_expired = ERROR_ACCOUNT_EXPIRED,
#       else
#       endif
        /// <summary>The redirector is in use and cannot be unloaded.</summary>

#       ifdef ERROR_REDIRECTOR_HAS_OPEN_HANDLES
        error_redirector_has_open_handles = ERROR_REDIRECTOR_HAS_OPEN_HANDLES,
#       else
#       endif
        /// <summary>The specified printer driver is already installed.</summary>

#       ifdef ERROR_PRINTER_DRIVER_ALREADY_INSTALLED
        error_printer_driver_already_installed = ERROR_PRINTER_DRIVER_ALREADY_INSTALLED,
#       else
#       endif
        /// <summary>The specified port is unknown.</summary>

#       ifdef ERROR_UNKNOWN_PORT
        error_unknown_port = ERROR_UNKNOWN_PORT,
#       else
#       endif
        /// <summary>The printer driver is unknown.</summary>

#       ifdef ERROR_UNKNOWN_PRINTER_DRIVER
        error_unknown_printer_driver = ERROR_UNKNOWN_PRINTER_DRIVER,
#       else
#       endif
        /// <summary>The print processor is unknown.</summary>

#       ifdef ERROR_UNKNOWN_PRINTPROCESSOR
        error_unknown_printprocessor = ERROR_UNKNOWN_PRINTPROCESSOR,
#       else
#       endif
        /// <summary>The specified separator file is invalid.</summary>

#       ifdef ERROR_INVALID_SEPARATOR_FILE
        error_invalid_separator_file = ERROR_INVALID_SEPARATOR_FILE,
#       else
#       endif
        /// <summary>The specified priority is invalid.</summary>

#       ifdef ERROR_INVALID_PRIORITY
        error_invalid_priority = ERROR_INVALID_PRIORITY,
#       else
#       endif
        /// <summary>The printer name is invalid.</summary>

#       ifdef ERROR_INVALID_PRINTER_NAME
        error_invalid_printer_name = ERROR_INVALID_PRINTER_NAME,
#       else
#       endif
        /// <summary>The printer already exists.</summary>

#       ifdef ERROR_PRINTER_ALREADY_EXISTS
        error_printer_already_exists = ERROR_PRINTER_ALREADY_EXISTS,
#       else
#       endif
        /// <summary>The printer command is invalid.</summary>

#       ifdef ERROR_INVALID_PRINTER_COMMAND
        error_invalid_printer_command = ERROR_INVALID_PRINTER_COMMAND,
#       else
#       endif
        /// <summary>The specified datatype is invalid.</summary>

#       ifdef ERROR_INVALID_DATATYPE
        error_invalid_datatype = ERROR_INVALID_DATATYPE,
#       else
#       endif
        /// <summary>The environment specified is invalid.</summary>

#       ifdef ERROR_INVALID_ENVIRONMENT
        error_invalid_environment = ERROR_INVALID_ENVIRONMENT,
#       else
#       endif
        /// <summary>There are no more bindings.</summary>

#       ifdef RPC_S_NO_MORE_BINDINGS
        rpc_s_no_more_bindings = RPC_S_NO_MORE_BINDINGS,
#       else
#       endif
        /// <summary>The account used is an interdomain trust account. Use your global user account or local user account to access this server.</summary>

#       ifdef ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT
        error_nologon_interdomain_trust_account = ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT,
#       else
#       endif
        /// <summary>The account used is a computer account. Use your global user account or local user account to access this server.</summary>

#       ifdef ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT
        error_nologon_workstation_trust_account = ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT,
#       else
#       endif
        /// <summary>The account used is a server trust account. Use your global user account or local user account to access this server.</summary>

#       ifdef ERROR_NOLOGON_SERVER_TRUST_ACCOUNT
        error_nologon_server_trust_account = ERROR_NOLOGON_SERVER_TRUST_ACCOUNT,
#       else
#       endif
        /// <summary>The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.</summary>

#       ifdef ERROR_DOMAIN_TRUST_INCONSISTENT
        error_domain_trust_inconsistent = ERROR_DOMAIN_TRUST_INCONSISTENT,
#       else
#       endif
        /// <summary>The server is in use and cannot be unloaded.</summary>

#       ifdef ERROR_SERVER_HAS_OPEN_HANDLES
        error_server_has_open_handles = ERROR_SERVER_HAS_OPEN_HANDLES,
#       else
#       endif
        /// <summary>The specified image file did not contain a resource section.</summary>

#       ifdef ERROR_RESOURCE_DATA_NOT_FOUND
        error_resource_data_not_found = ERROR_RESOURCE_DATA_NOT_FOUND,
#       else
#       endif
        /// <summary>The specified resource type cannot be found in the image file.</summary>

#       ifdef ERROR_RESOURCE_TYPE_NOT_FOUND
        error_resource_type_not_found = ERROR_RESOURCE_TYPE_NOT_FOUND,
#       else
#       endif
        /// <summary>The specified resource name cannot be found in the image file.</summary>

#       ifdef ERROR_RESOURCE_NAME_NOT_FOUND
        error_resource_name_not_found = ERROR_RESOURCE_NAME_NOT_FOUND,
#       else
#       endif
        /// <summary>The specified resource language ID cannot be found in the image file.</summary>

#       ifdef ERROR_RESOURCE_LANG_NOT_FOUND
        error_resource_lang_not_found = ERROR_RESOURCE_LANG_NOT_FOUND,
#       else
#       endif
        /// <summary>Not enough quota is available to process this command.</summary>

#       ifdef ERROR_NOT_ENOUGH_QUOTA
        error_not_enough_quota = ERROR_NOT_ENOUGH_QUOTA,
#       else
#       endif
        /// <summary>No interfaces have been registered.</summary>

#       ifdef RPC_S_NO_INTERFACES
        rpc_s_no_interfaces = RPC_S_NO_INTERFACES,
#       else
#       endif
        /// <summary>The remote procedure call was cancelled.</summary>

#       ifdef RPC_S_CALL_CANCELLED
        rpc_s_call_cancelled = RPC_S_CALL_CANCELLED,
#       else
#       endif
        /// <summary>The binding handle does not contain all required information.</summary>

#       ifdef RPC_S_BINDING_INCOMPLETE
        rpc_s_binding_incomplete = RPC_S_BINDING_INCOMPLETE,
#       else
#       endif
        /// <summary>A communications failure occurred during a remote procedure call.</summary>

#       ifdef RPC_S_COMM_FAILURE
        rpc_s_comm_failure = RPC_S_COMM_FAILURE,
#       else
#       endif
        /// <summary>The requested authentication level is not supported.</summary>

#       ifdef RPC_S_UNSUPPORTED_AUTHN_LEVEL
        rpc_s_unsupported_authn_level = RPC_S_UNSUPPORTED_AUTHN_LEVEL,
#       else
#       endif
        /// <summary>No principal name registered.</summary>

#       ifdef RPC_S_NO_PRINC_NAME
        rpc_s_no_princ_name = RPC_S_NO_PRINC_NAME,
#       else
#       endif
        /// <summary>The error specified is not a valid Windows RPC error code.</summary>

#       ifdef RPC_S_NOT_RPC_ERROR
        rpc_s_not_rpc_error = RPC_S_NOT_RPC_ERROR,
#       else
#       endif
        /// <summary>A UUID that is valid only on this computer has been allocated.</summary>

#       ifdef RPC_S_UUID_LOCAL_ONLY
        rpc_s_uuid_local_only = RPC_S_UUID_LOCAL_ONLY,
#       else
#       endif
        /// <summary>A security package specific error occurred.</summary>

#       ifdef RPC_S_SEC_PKG_ERROR
        rpc_s_sec_pkg_error = RPC_S_SEC_PKG_ERROR,
#       else
#       endif
        /// <summary>Thread is not canceled.</summary>

#       ifdef RPC_S_NOT_CANCELLED
        rpc_s_not_cancelled = RPC_S_NOT_CANCELLED,
#       else
#       endif
        /// <summary>Invalid operation on the encoding/decoding handle.</summary>

#       ifdef RPC_X_INVALID_ES_ACTION
        rpc_x_invalid_es_action = RPC_X_INVALID_ES_ACTION,
#       else
#       endif
        /// <summary>Incompatible version of the serializing package.</summary>

#       ifdef RPC_X_WRONG_ES_VERSION
        rpc_x_wrong_es_version = RPC_X_WRONG_ES_VERSION,
#       else
#       endif
        /// <summary>Incompatible version of the RPC stub.</summary>

#       ifdef RPC_X_WRONG_STUB_VERSION
        rpc_x_wrong_stub_version = RPC_X_WRONG_STUB_VERSION,
#       else
#       endif
        /// <summary>The RPC pipe object is invalid or corrupted.</summary>

#       ifdef RPC_X_INVALID_PIPE_OBJECT
        rpc_x_invalid_pipe_object = RPC_X_INVALID_PIPE_OBJECT,
#       else
#       endif
        /// <summary>An invalid operation was attempted on an RPC pipe object.</summary>

#       ifdef RPC_X_WRONG_PIPE_ORDER
        rpc_x_wrong_pipe_order = RPC_X_WRONG_PIPE_ORDER,
#       else
#       endif
        /// <summary>Unsupported RPC pipe version.</summary>

#       ifdef RPC_X_WRONG_PIPE_VERSION
        rpc_x_wrong_pipe_version = RPC_X_WRONG_PIPE_VERSION,
#       else
#       endif
        /// <summary>HTTP proxy server rejected the connection because the cookie authentication failed.</summary>

#       ifdef RPC_S_COOKIE_AUTH_FAILED
        rpc_s_cookie_auth_failed = RPC_S_COOKIE_AUTH_FAILED,
#       else
#       endif
        /// <summary>The RPC server is suspended, and could not be resumed for this request. The call did not execute.</summary>

#       ifdef RPC_S_DO_NOT_DISTURB
        rpc_s_do_not_disturb = RPC_S_DO_NOT_DISTURB,
#       else
#       endif
        /// <summary>The RPC call contains too many handles to be transmitted in a single request.</summary>

#       ifdef RPC_S_SYSTEM_HANDLE_COUNT_EXCEEDED
        rpc_s_system_handle_count_exceeded = RPC_S_SYSTEM_HANDLE_COUNT_EXCEEDED,
#       else
#       endif
        /// <summary>The RPC call contains a handle that differs from the declared handle type.</summary>

#       ifdef RPC_S_SYSTEM_HANDLE_TYPE_MISMATCH
        rpc_s_system_handle_type_mismatch = RPC_S_SYSTEM_HANDLE_TYPE_MISMATCH,
#       else
#       endif
        /// <summary>The group member was not found.</summary>

#       ifdef RPC_S_GROUP_MEMBER_NOT_FOUND
        rpc_s_group_member_not_found = RPC_S_GROUP_MEMBER_NOT_FOUND,
#       else
#       endif
        /// <summary>The endpoint mapper database entry could not be created.</summary>

#       ifdef EPT_S_CANT_CREATE
        ept_s_cant_create = EPT_S_CANT_CREATE,
#       else
#       endif
        /// <summary>The object universal unique identifier (UUID) is the nil UUID.</summary>

#       ifdef RPC_S_INVALID_OBJECT
        rpc_s_invalid_object = RPC_S_INVALID_OBJECT,
#       else
#       endif
        /// <summary>The specified time is invalid.</summary>

#       ifdef ERROR_INVALID_TIME
        error_invalid_time = ERROR_INVALID_TIME,
#       else
#       endif
        /// <summary>The specified form name is invalid.</summary>

#       ifdef ERROR_INVALID_FORM_NAME
        error_invalid_form_name = ERROR_INVALID_FORM_NAME,
#       else
#       endif
        /// <summary>The specified form size is invalid.</summary>

#       ifdef ERROR_INVALID_FORM_SIZE
        error_invalid_form_size = ERROR_INVALID_FORM_SIZE,
#       else
#       endif
        /// <summary>The specified printer handle is already being waited on</summary>

#       ifdef ERROR_ALREADY_WAITING
        error_already_waiting = ERROR_ALREADY_WAITING,
#       else
#       endif
        /// <summary>The specified printer has been deleted.</summary>

#       ifdef ERROR_PRINTER_DELETED
        error_printer_deleted = ERROR_PRINTER_DELETED,
#       else
#       endif
        /// <summary>The state of the printer is invalid.</summary>

#       ifdef ERROR_INVALID_PRINTER_STATE
        error_invalid_printer_state = ERROR_INVALID_PRINTER_STATE,
#       else
#       endif
        /// <summary>The user's password must be changed before signing in.</summary>

#       ifdef ERROR_PASSWORD_MUST_CHANGE
        error_password_must_change = ERROR_PASSWORD_MUST_CHANGE,
#       else
#       endif
        /// <summary>Could not find the domain controller for this domain.</summary>

#       ifdef ERROR_DOMAIN_CONTROLLER_NOT_FOUND
        error_domain_controller_not_found = ERROR_DOMAIN_CONTROLLER_NOT_FOUND,
#       else
#       endif
        /// <summary>The referenced account is currently locked out and may not be logged on to.</summary>

#       ifdef ERROR_ACCOUNT_LOCKED_OUT
        error_account_locked_out = ERROR_ACCOUNT_LOCKED_OUT,
#       else
#       endif
        /// <summary>The object exporter specified was not found.</summary>

#       ifdef OR_INVALID_OXID
        or_invalid_oxid = OR_INVALID_OXID,
#       else
#       endif
        /// <summary>The object specified was not found.</summary>

#       ifdef OR_INVALID_OID
        or_invalid_oid = OR_INVALID_OID,
#       else
#       endif

        /// <summary>The object resolver set specified was not found.</summary>
#       ifdef OR_INVALID_SET
        or_invalid_set = OR_INVALID_SET,
#       else
#       endif
        /// <summary>Some data remains to be sent in the request buffer.</summary>
#       ifdef RPC_S_SEND_INCOMPLETE
        rpc_s_send_incomplete = RPC_S_SEND_INCOMPLETE,
#       else
#       endif
        /// <summary>Invalid asynchronous remote procedure call handle.</summary>
#       ifdef RPC_S_INVALID_ASYNC_HANDLE
        rpc_s_invalid_async_handle = RPC_S_INVALID_ASYNC_HANDLE,
#       else
#       endif
        /// <summary>Invalid asynchronous RPC call handle for this operation.</summary>
#       ifdef RPC_S_INVALID_ASYNC_CALL
        rpc_s_invalid_async_call = RPC_S_INVALID_ASYNC_CALL,
#       else
#       endif
        /// <summary>The RPC pipe object has already been closed.</summary>
#       ifdef RPC_X_PIPE_CLOSED
        rpc_x_pipe_closed = RPC_X_PIPE_CLOSED,
#       else
#       endif
        /// <summary>The RPC call completed before all pipes were processed.</summary>
#       ifdef RPC_X_PIPE_DISCIPLINE_ERROR
        rpc_x_pipe_discipline_error = RPC_X_PIPE_DISCIPLINE_ERROR,
#       else
#       endif
        /// <summary>No more data is available from the RPC pipe.</summary>
#       ifdef RPC_X_PIPE_EMPTY
        rpc_x_pipe_empty = RPC_X_PIPE_EMPTY,
#       else
#       endif
        /// <summary>No site name is available for this machine.</summary>
#       ifdef ERROR_NO_SITENAME
        error_no_sitename = ERROR_NO_SITENAME,
#       else
#       endif
        /// <summary>The file cannot be accessed by the system.</summary>
#       ifdef ERROR_CANT_ACCESS_FILE
        error_cant_access_file = ERROR_CANT_ACCESS_FILE,
#       else
#       endif
        /// <summary>The name of the file cannot be resolved by the system.</summary>
#       ifdef ERROR_CANT_RESOLVE_FILENAME
        error_cant_resolve_filename = ERROR_CANT_RESOLVE_FILENAME,
#       else
#       endif
        /// <summary>The entry is not of the expected type.</summary>
#       ifdef RPC_S_ENTRY_TYPE_MISMATCH
        rpc_s_entry_type_mismatch = RPC_S_ENTRY_TYPE_MISMATCH,
#       else
#       endif
        /// <summary>Not all object UUIDs could be exported to the specified entry.</summary>
#       ifdef RPC_S_NOT_ALL_OBJS_EXPORTED
        rpc_s_not_all_objs_exported = RPC_S_NOT_ALL_OBJS_EXPORTED,
#       else
#       endif
        /// <summary>Interface could not be exported to the specified entry.</summary>
#       ifdef RPC_S_INTERFACE_NOT_EXPORTED
        rpc_s_interface_not_exported = RPC_S_INTERFACE_NOT_EXPORTED,
#       else
#       endif
        /// <summary>The specified profile entry could not be added.</summary>
#       ifdef RPC_S_PROFILE_NOT_ADDED
        rpc_s_profile_not_added = RPC_S_PROFILE_NOT_ADDED,
#       else
#       endif
        /// <summary>The specified profile element could not be added.</summary>
#       ifdef RPC_S_PRF_ELT_NOT_ADDED
        rpc_s_prf_elt_not_added = RPC_S_PRF_ELT_NOT_ADDED,
#       else
#       endif
        /// <summary>The specified profile element could not be removed.</summary>
#       ifdef RPC_S_PRF_ELT_NOT_REMOVED
        rpc_s_prf_elt_not_removed = RPC_S_PRF_ELT_NOT_REMOVED,
#       else
#       endif
        /// <summary>The group element could not be added.</summary>
#       ifdef RPC_S_GRP_ELT_NOT_ADDED
        rpc_s_grp_elt_not_added = RPC_S_GRP_ELT_NOT_ADDED,
#       else
#       endif
        /// <summary>The group element could not be removed.</summary>
#       ifdef RPC_S_GRP_ELT_NOT_REMOVED
        rpc_s_grp_elt_not_removed = RPC_S_GRP_ELT_NOT_REMOVED,
#       else
#       endif
        /// <summary>The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.</summary>
#       ifdef ERROR_KM_DRIVER_BLOCKED
        error_km_driver_blocked = ERROR_KM_DRIVER_BLOCKED,
#       else
#       endif
        /// <summary>The context has expired and can no longer be used.</summary>
#       ifdef ERROR_CONTEXT_EXPIRED
        error_context_expired = ERROR_CONTEXT_EXPIRED,
#       else
#       endif
        /// <summary>The current user's delegated trust creation quota has been exceeded.</summary>
#       ifdef ERROR_PER_USER_TRUST_QUOTA_EXCEEDED
        error_per_user_trust_quota_exceeded = ERROR_PER_USER_TRUST_QUOTA_EXCEEDED,
#       else
#       endif
        /// <summary>The total delegated trust creation quota has been exceeded.</summary>
#       ifdef ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED
        error_all_user_trust_quota_exceeded = ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED,
#       else
#       endif
        /// <summary>The current user's delegated trust deletion quota has been exceeded.</summary>
#       ifdef ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED
        error_user_delete_trust_quota_exceeded = ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED,
#       else
#       endif
        /// <summary>The computer you are signing into is protected by an authentication firewall. The specified account is not allowed to authenticate to the computer.</summary>
#       ifdef ERROR_AUTHENTICATION_FIREWALL_FAILED
        error_authentication_firewall_failed = ERROR_AUTHENTICATION_FIREWALL_FAILED,
#       else
#       endif
        /// <summary>Remote connections to the Print Spooler are blocked by a policy set on your machine.</summary>
#       ifdef ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED
        error_remote_print_connections_blocked = ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED,
#       else
#       endif
        /// <summary>Authentication failed because NTLM authentication has been disabled.</summary>
#       ifdef ERROR_NTLM_BLOCKED
        error_ntlm_blocked = ERROR_NTLM_BLOCKED,
#       else
#       endif
        /// <summary>Logon Failure: EAS policy requires that the user change their password before this operation can be performed.</summary>
#       ifdef ERROR_PASSWORD_CHANGE_REQUIRED
        error_password_change_required = ERROR_PASSWORD_CHANGE_REQUIRED,
#       else
#       endif
        /// <summary>An administrator has restricted sign in. To sign in, make sure your device is connected to the Internet, and have your administrator sign in first.</summary>
#       ifdef ERROR_LOST_MODE_LOGON_RESTRICTION
        error_lost_mode_logon_restriction = ERROR_LOST_MODE_LOGON_RESTRICTION,
#       else
#       endif
        /// <summary>The pixel format is invalid.</summary>
#       ifdef ERROR_INVALID_PIXEL_FORMAT
        error_invalid_pixel_format = ERROR_INVALID_PIXEL_FORMAT,
#       else
#       endif
        /// <summary>The specified driver is invalid.</summary>
#       ifdef ERROR_BAD_DRIVER
        error_bad_driver = ERROR_BAD_DRIVER,
#       else
#       endif
        /// <summary>The window style or class attribute is invalid for this operation.</summary>
#       ifdef ERROR_INVALID_WINDOW_STYLE
        error_invalid_window_style = ERROR_INVALID_WINDOW_STYLE,
#       else
#       endif
        /// <summary>The requested metafile operation is not supported.</summary>
#       ifdef ERROR_METAFILE_NOT_SUPPORTED
        error_metafile_not_supported = ERROR_METAFILE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The requested transformation operation is not supported.</summary>
#       ifdef ERROR_TRANSFORM_NOT_SUPPORTED
        error_transform_not_supported = ERROR_TRANSFORM_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The requested clipping operation is not supported.</summary>
#       ifdef ERROR_CLIPPING_NOT_SUPPORTED
        error_clipping_not_supported = ERROR_CLIPPING_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The specified color management module is invalid.</summary>
#       ifdef ERROR_INVALID_CMM
        error_invalid_cmm = ERROR_INVALID_CMM,
#       else
#       endif
        /// <summary>The specified color profile is invalid.</summary>
#       ifdef ERROR_INVALID_PROFILE
        error_invalid_profile = ERROR_INVALID_PROFILE,
#       else
#       endif
        /// <summary>The specified tag was not found.</summary>
#       ifdef ERROR_TAG_NOT_FOUND
        error_tag_not_found = ERROR_TAG_NOT_FOUND,
#       else
#       endif
        /// <summary>A required tag is not present.</summary>
#       ifdef ERROR_TAG_NOT_PRESENT
        error_tag_not_present = ERROR_TAG_NOT_PRESENT,
#       else
#       endif
        /// <summary>The specified tag is already present.</summary>
#       ifdef ERROR_DUPLICATE_TAG
        error_duplicate_tag = ERROR_DUPLICATE_TAG,
#       else
#       endif
        /// <summary>The specified color profile is not associated with the specified device.</summary>
#       ifdef ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE
        error_profile_not_associated_with_device = ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE,
#       else
#       endif
        /// <summary>The specified color profile was not found.</summary>
#       ifdef ERROR_PROFILE_NOT_FOUND
        error_profile_not_found = ERROR_PROFILE_NOT_FOUND,
#       else
#       endif
        /// <summary>The specified color space is invalid.</summary>
#       ifdef ERROR_INVALID_COLORSPACE
        error_invalid_colorspace = ERROR_INVALID_COLORSPACE,
#       else
#       endif
        /// <summary>Image Color Management is not enabled.</summary>
#       ifdef ERROR_ICM_NOT_ENABLED
        error_icm_not_enabled = ERROR_ICM_NOT_ENABLED,
#       else
#       endif
        /// <summary>There was an error while deleting the color transform.</summary>
#       ifdef ERROR_DELETING_ICM_XFORM
        error_deleting_icm_xform = ERROR_DELETING_ICM_XFORM,
#       else
#       endif
        /// <summary>The specified color transform is invalid.</summary>
#       ifdef ERROR_INVALID_TRANSFORM
        error_invalid_transform = ERROR_INVALID_TRANSFORM,
#       else
#       endif
        /// <summary>The specified transform does not match the bitmap's color space.</summary>

#       ifdef ERROR_COLORSPACE_MISMATCH
        error_colorspace_mismatch = ERROR_COLORSPACE_MISMATCH,
#       else
#       endif
        /// <summary>The specified named color index is not present in the profile.</summary>

#       ifdef ERROR_INVALID_COLORINDEX
        error_invalid_colorindex = ERROR_INVALID_COLORINDEX,
#       else
#       endif
        /// <summary>The specified profile is intended for a device of a different type than the specified device.</summary>

#       ifdef ERROR_PROFILE_DOES_NOT_MATCH_DEVICE
        error_profile_does_not_match_device = ERROR_PROFILE_DOES_NOT_MATCH_DEVICE,
#       else
#       endif
        /// <summary>The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.</summary>

#       ifdef ERROR_CONNECTED_OTHER_PASSWORD
        error_connected_other_password = ERROR_CONNECTED_OTHER_PASSWORD,
#       else
#       endif
        /// <summary>The network connection was made successfully using default credentials.</summary>

#       ifdef ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT
        error_connected_other_password_default = ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT,
#       else
#       endif
        /// <summary>The specified username is invalid.</summary>

#       ifdef ERROR_BAD_USERNAME
        error_bad_username = ERROR_BAD_USERNAME,
#       else
#       endif
        /// <summary>This network connection does not exist.</summary>

#       ifdef ERROR_NOT_CONNECTED
        error_not_connected = ERROR_NOT_CONNECTED,
#       else
#       endif
        /// <summary>This network connection has files open or requests pending.</summary>

#       ifdef ERROR_OPEN_FILES
        error_open_files = ERROR_OPEN_FILES,
#       else
#       endif
        /// <summary>Active connections still exist.</summary>

#       ifdef ERROR_ACTIVE_CONNECTIONS
        error_active_connections = ERROR_ACTIVE_CONNECTIONS,
#       else
#       endif
        /// <summary>The device is in use by an active process and cannot be disconnected.</summary>

#       ifdef ERROR_DEVICE_IN_USE
        error_device_in_use = ERROR_DEVICE_IN_USE,
#       else
#       endif
        /// <summary>The specified print monitor is unknown.</summary>

#       ifdef ERROR_UNKNOWN_PRINT_MONITOR
        error_unknown_print_monitor = ERROR_UNKNOWN_PRINT_MONITOR,
#       else
#       endif
        /// <summary>The specified printer driver is currently in use.</summary>

#       ifdef ERROR_PRINTER_DRIVER_IN_USE
        error_printer_driver_in_use = ERROR_PRINTER_DRIVER_IN_USE,
#       else
#       endif
        /// <summary>The spool file was not found.</summary>

#       ifdef ERROR_SPOOL_FILE_NOT_FOUND
        error_spool_file_not_found = ERROR_SPOOL_FILE_NOT_FOUND,
#       else
#       endif
        /// <summary>A StartDocPrinter call was not issued.</summary>

#       ifdef ERROR_SPL_NO_STARTDOC
        error_spl_no_startdoc = ERROR_SPL_NO_STARTDOC,
#       else
#       endif
        /// <summary>An AddJob call was not issued.</summary>

#       ifdef ERROR_SPL_NO_ADDJOB
        error_spl_no_addjob = ERROR_SPL_NO_ADDJOB,
#       else
#       endif
        /// <summary>The specified print processor has already been installed.</summary>

#       ifdef ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED
        error_print_processor_already_installed = ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED,
#       else
#       endif
        /// <summary>The specified print monitor has already been installed.</summary>

#       ifdef ERROR_PRINT_MONITOR_ALREADY_INSTALLED
        error_print_monitor_already_installed = ERROR_PRINT_MONITOR_ALREADY_INSTALLED,
#       else
#       endif
        /// <summary>The specified print monitor does not have the required functions.</summary>

#       ifdef ERROR_INVALID_PRINT_MONITOR
        error_invalid_print_monitor = ERROR_INVALID_PRINT_MONITOR,
#       else
#       endif
        /// <summary>The specified print monitor is currently in use.</summary>

#       ifdef ERROR_PRINT_MONITOR_IN_USE
        error_print_monitor_in_use = ERROR_PRINT_MONITOR_IN_USE,
#       else
#       endif
        /// <summary>The requested operation is not allowed when there are jobs queued to the printer.</summary>

#       ifdef ERROR_PRINTER_HAS_JOBS_QUEUED
        error_printer_has_jobs_queued = ERROR_PRINTER_HAS_JOBS_QUEUED,
#       else
#       endif
        /// <summary>The requested operation is successful. Changes will not be effective until the system is rebooted.</summary>

#       ifdef ERROR_SUCCESS_REBOOT_REQUIRED
        error_success_reboot_required = ERROR_SUCCESS_REBOOT_REQUIRED,
#       else
#       endif
        /// <summary>The requested operation is successful. Changes will not be effective until the service is restarted.</summary>

#       ifdef ERROR_SUCCESS_RESTART_REQUIRED
        error_success_restart_required = ERROR_SUCCESS_RESTART_REQUIRED,
#       else
#       endif
        /// <summary>No printers were found.</summary>

#       ifdef ERROR_PRINTER_NOT_FOUND
        error_printer_not_found = ERROR_PRINTER_NOT_FOUND,
#       else
#       endif
        /// <summary>The printer driver is known to be unreliable.</summary>

#       ifdef ERROR_PRINTER_DRIVER_WARNED
        error_printer_driver_warned = ERROR_PRINTER_DRIVER_WARNED,
#       else
#       endif
        /// <summary>The printer driver is known to harm the system.</summary>

#       ifdef ERROR_PRINTER_DRIVER_BLOCKED
        error_printer_driver_blocked = ERROR_PRINTER_DRIVER_BLOCKED,
#       else
#       endif
        /// <summary>The specified printer driver package is currently in use.</summary>

#       ifdef ERROR_PRINTER_DRIVER_PACKAGE_IN_USE
        error_printer_driver_package_in_use = ERROR_PRINTER_DRIVER_PACKAGE_IN_USE,
#       else
#       endif
        /// <summary>Unable to find a core driver package that is required by the printer driver package.</summary>

#       ifdef ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND
        error_core_driver_package_not_found = ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND,
#       else
#       endif
        /// <summary>The requested operation failed. A system reboot is required to roll back changes made.</summary>

#       ifdef ERROR_FAIL_REBOOT_REQUIRED
        error_fail_reboot_required = ERROR_FAIL_REBOOT_REQUIRED,
#       else
#       endif
        /// <summary>The requested operation failed. A system reboot has been initiated to roll back changes made.</summary>

#       ifdef ERROR_FAIL_REBOOT_INITIATED
        error_fail_reboot_initiated = ERROR_FAIL_REBOOT_INITIATED,
#       else
#       endif
        /// <summary>The specified printer driver was not found on the system and needs to be downloaded.</summary>

#       ifdef ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED
        error_printer_driver_download_needed = ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED,
#       else
#       endif
        /// <summary>The requested print job has failed to print. A print system update requires the job to be resubmitted.</summary>

#       ifdef ERROR_PRINT_JOB_RESTART_REQUIRED
        error_print_job_restart_required = ERROR_PRINT_JOB_RESTART_REQUIRED,
#       else
#       endif
        /// <summary>The printer driver does not contain a valid manifest, or contains too many manifests.</summary>

#       ifdef ERROR_INVALID_PRINTER_DRIVER_MANIFEST
        error_invalid_printer_driver_manifest = ERROR_INVALID_PRINTER_DRIVER_MANIFEST,
#       else
#       endif
        /// <summary>The specified printer cannot be shared.</summary>

#       ifdef ERROR_PRINTER_NOT_SHAREABLE
        error_printer_not_shareable = ERROR_PRINTER_NOT_SHAREABLE,
#       else
#       endif
        /// <summary>The operation was paused.</summary>

#       ifdef ERROR_REQUEST_PAUSED
        error_request_paused = ERROR_REQUEST_PAUSED,
#       else
#       endif
        /// <summary>The condition supplied for the app execution request was not satisfied, so the request was not performed.</summary>

#       ifdef ERROR_APPEXEC_CONDITION_NOT_SATISFIED
        error_appexec_condition_not_satisfied = ERROR_APPEXEC_CONDITION_NOT_SATISFIED,
#       else
#       endif
        /// <summary>The supplied handle has been invalidated and may not be used for the requested operation.</summary>

#       ifdef ERROR_APPEXEC_HANDLE_INVALIDATED
        error_appexec_handle_invalidated = ERROR_APPEXEC_HANDLE_INVALIDATED,
#       else
#       endif
        /// <summary>The supplied host generation has been invalidated and may not be used for the requested operation.</summary>

#       ifdef ERROR_APPEXEC_INVALID_HOST_GENERATION
        error_appexec_invalid_host_generation = ERROR_APPEXEC_INVALID_HOST_GENERATION,
#       else
#       endif
        /// <summary>An attempt to register a process failed because the target host was not in a valid state to receive process registrations.</summary>

#       ifdef ERROR_APPEXEC_UNEXPECTED_PROCESS_REGISTRATION
        error_appexec_unexpected_process_registration = ERROR_APPEXEC_UNEXPECTED_PROCESS_REGISTRATION,
#       else
#       endif
        /// <summary>The host is not in a valid state to support the execution request.</summary>

#       ifdef ERROR_APPEXEC_INVALID_HOST_STATE
        error_appexec_invalid_host_state = ERROR_APPEXEC_INVALID_HOST_STATE,
#       else
#       endif
        /// <summary>The operation was not completed because a required resource donor was not found for the host.</summary>

#       ifdef ERROR_APPEXEC_NO_DONOR
        error_appexec_no_donor = ERROR_APPEXEC_NO_DONOR,
#       else
#       endif
        /// <summary>The operation was not completed because an unexpected host ID was encountered.</summary>

#       ifdef ERROR_APPEXEC_HOST_ID_MISMATCH
        error_appexec_host_id_mismatch = ERROR_APPEXEC_HOST_ID_MISMATCH,
#       else
#       endif
        /// <summary>The operation was not completed because the specified user was not known to the service.</summary>

#       ifdef ERROR_APPEXEC_UNKNOWN_USER
        error_appexec_unknown_user = ERROR_APPEXEC_UNKNOWN_USER,
#       else
#       endif

        /// <summary>Reissue the given operation as a cached IO operation</summary>

#       ifdef ERROR_IO_REISSUE_AS_CACHED
        error_io_reissue_as_cached = ERROR_IO_REISSUE_AS_CACHED,
#       else
#       endif

        /// <summary>WINS encountered an error while processing the command.</summary>

#       ifdef ERROR_WINS_INTERNAL
        error_wins_internal = ERROR_WINS_INTERNAL,
#       else
#       endif
        /// <summary>The local WINS cannot be deleted.</summary>

#       ifdef ERROR_CAN_NOT_DEL_LOCAL_WINS
        error_can_not_del_local_wins = ERROR_CAN_NOT_DEL_LOCAL_WINS,
#       else
#       endif
        /// <summary>The importation from the file failed.</summary>

#       ifdef ERROR_STATIC_INIT
        error_static_init = ERROR_STATIC_INIT,
#       else
#       endif
        /// <summary>The backup failed. Was a full backup done before?</summary>

#       ifdef ERROR_INC_BACKUP
        error_inc_backup = ERROR_INC_BACKUP,
#       else
#       endif
        /// <summary>The backup failed. Check the directory to which you are backing the database.</summary>

#       ifdef ERROR_FULL_BACKUP
        error_full_backup = ERROR_FULL_BACKUP,
#       else
#       endif
        /// <summary>The name does not exist in the WINS database.</summary>

#       ifdef ERROR_REC_NON_EXISTENT
        error_rec_non_existent = ERROR_REC_NON_EXISTENT,
#       else
#       endif
        /// <summary>Replication with a nonconfigured partner is not allowed.</summary>

#       ifdef ERROR_RPL_NOT_ALLOWED
        error_rpl_not_allowed = ERROR_RPL_NOT_ALLOWED,
#       else
#       endif
        /// <summary>The version of the supplied content information is not supported.</summary>

#       ifdef PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED
        peerdist_error_contentinfo_version_unsupported = PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED,
#       else
#       endif
        /// <summary>The supplied content information is malformed.</summary>

#       ifdef PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO
        peerdist_error_cannot_parse_contentinfo = PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO,
#       else
#       endif
        /// <summary>The requested data cannot be found in local or peer caches.</summary>

#       ifdef PEERDIST_ERROR_MISSING_DATA
        peerdist_error_missing_data = PEERDIST_ERROR_MISSING_DATA,
#       else
#       endif
        /// <summary>No more data is available or required.</summary>

#       ifdef PEERDIST_ERROR_NO_MORE
        peerdist_error_no_more = PEERDIST_ERROR_NO_MORE,
#       else
#       endif
        /// <summary>The supplied object has not been initialized.</summary>

#       ifdef PEERDIST_ERROR_NOT_INITIALIZED
        peerdist_error_not_initialized = PEERDIST_ERROR_NOT_INITIALIZED,
#       else
#       endif
        /// <summary>The supplied object has already been initialized.</summary>

#       ifdef PEERDIST_ERROR_ALREADY_INITIALIZED
        peerdist_error_already_initialized = PEERDIST_ERROR_ALREADY_INITIALIZED,
#       else
#       endif
        /// <summary>A shutdown operation is already in progress.</summary>

#       ifdef PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS
        peerdist_error_shutdown_in_progress = PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS,
#       else
#       endif
        /// <summary>The supplied object has already been invalidated.</summary>

#       ifdef PEERDIST_ERROR_INVALIDATED
        peerdist_error_invalidated = PEERDIST_ERROR_INVALIDATED,
#       else
#       endif
        /// <summary>An element already exists and was not replaced.</summary>

#       ifdef PEERDIST_ERROR_ALREADY_EXISTS
        peerdist_error_already_exists = PEERDIST_ERROR_ALREADY_EXISTS,
#       else
#       endif
        /// <summary>Can not cancel the requested operation as it has already been completed.</summary>

#       ifdef PEERDIST_ERROR_OPERATION_NOTFOUND
        peerdist_error_operation_notfound = PEERDIST_ERROR_OPERATION_NOTFOUND,
#       else
#       endif
        /// <summary>Can not perform the requested operation because it has already been carried out.</summary>

#       ifdef PEERDIST_ERROR_ALREADY_COMPLETED
        peerdist_error_already_completed = PEERDIST_ERROR_ALREADY_COMPLETED,
#       else
#       endif
        /// <summary>An operation accessed data beyond the bounds of valid data.</summary>

#       ifdef PEERDIST_ERROR_OUT_OF_BOUNDS
        peerdist_error_out_of_bounds = PEERDIST_ERROR_OUT_OF_BOUNDS,
#       else
#       endif
        /// <summary>The requested version is not supported.</summary>

#       ifdef PEERDIST_ERROR_VERSION_UNSUPPORTED
        peerdist_error_version_unsupported = PEERDIST_ERROR_VERSION_UNSUPPORTED,
#       else
#       endif
        /// <summary>A configuration value is invalid.</summary>

#       ifdef PEERDIST_ERROR_INVALID_CONFIGURATION
        peerdist_error_invalid_configuration = PEERDIST_ERROR_INVALID_CONFIGURATION,
#       else
#       endif
        /// <summary>The SKU is not licensed.</summary>

#       ifdef PEERDIST_ERROR_NOT_LICENSED
        peerdist_error_not_licensed = PEERDIST_ERROR_NOT_LICENSED,
#       else
#       endif
        /// <summary>PeerDist Service is still initializing and will be available shortly.</summary>

#       ifdef PEERDIST_ERROR_SERVICE_UNAVAILABLE
        peerdist_error_service_unavailable = PEERDIST_ERROR_SERVICE_UNAVAILABLE,
#       else
#       endif
        /// <summary>Communication with one or more computers will be temporarily blocked due to recent errors.</summary>

#       ifdef PEERDIST_ERROR_TRUST_FAILURE
        peerdist_error_trust_failure = PEERDIST_ERROR_TRUST_FAILURE,
#       else
#       endif
        /// <summary>The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address.</summary>

#       ifdef ERROR_DHCP_ADDRESS_CONFLICT
        error_dhcp_address_conflict = ERROR_DHCP_ADDRESS_CONFLICT,
#       else
#       endif
        /// <summary>The GUID passed was not recognized as valid by a WMI data provider.</summary>

#       ifdef ERROR_WMI_GUID_NOT_FOUND
        error_wmi_guid_not_found = ERROR_WMI_GUID_NOT_FOUND,
#       else
#       endif
        /// <summary>The instance name passed was not recognized as valid by a WMI data provider.</summary>

#       ifdef ERROR_WMI_INSTANCE_NOT_FOUND
        error_wmi_instance_not_found = ERROR_WMI_INSTANCE_NOT_FOUND,
#       else
#       endif
        /// <summary>The data item ID passed was not recognized as valid by a WMI data provider.</summary>

#       ifdef ERROR_WMI_ITEMID_NOT_FOUND
        error_wmi_itemid_not_found = ERROR_WMI_ITEMID_NOT_FOUND,
#       else
#       endif
        /// <summary>The WMI request could not be completed and should be retried.</summary>

#       ifdef ERROR_WMI_TRY_AGAIN
        error_wmi_try_again = ERROR_WMI_TRY_AGAIN,
#       else
#       endif
        /// <summary>The WMI data provider could not be located.</summary>

#       ifdef ERROR_WMI_DP_NOT_FOUND
        error_wmi_dp_not_found = ERROR_WMI_DP_NOT_FOUND,
#       else
#       endif
        /// <summary>The WMI data provider references an instance set that has not been registered.</summary>

#       ifdef ERROR_WMI_UNRESOLVED_INSTANCE_REF
        error_wmi_unresolved_instance_ref = ERROR_WMI_UNRESOLVED_INSTANCE_REF,
#       else
#       endif
        /// <summary>The WMI data block or event notification has already been enabled.</summary>

#       ifdef ERROR_WMI_ALREADY_ENABLED
        error_wmi_already_enabled = ERROR_WMI_ALREADY_ENABLED,
#       else
#       endif
        /// <summary>The WMI data block is no longer available.</summary>

#       ifdef ERROR_WMI_GUID_DISCONNECTED
        error_wmi_guid_disconnected = ERROR_WMI_GUID_DISCONNECTED,
#       else
#       endif
        /// <summary>The WMI data service is not available.</summary>

#       ifdef ERROR_WMI_SERVER_UNAVAILABLE
        error_wmi_server_unavailable = ERROR_WMI_SERVER_UNAVAILABLE,
#       else
#       endif
        /// <summary>The WMI data provider failed to carry out the request.</summary>

#       ifdef ERROR_WMI_DP_FAILED
        error_wmi_dp_failed = ERROR_WMI_DP_FAILED,
#       else
#       endif
        /// <summary>The WMI MOF information is not valid.</summary>

#       ifdef ERROR_WMI_INVALID_MOF
        error_wmi_invalid_mof = ERROR_WMI_INVALID_MOF,
#       else
#       endif
        /// <summary>The WMI registration information is not valid.</summary>

#       ifdef ERROR_WMI_INVALID_REGINFO
        error_wmi_invalid_reginfo = ERROR_WMI_INVALID_REGINFO,
#       else
#       endif
        /// <summary>The WMI data block or event notification has already been disabled.</summary>

#       ifdef ERROR_WMI_ALREADY_DISABLED
        error_wmi_already_disabled = ERROR_WMI_ALREADY_DISABLED,
#       else
#       endif
        /// <summary>The WMI data item or data block is read only.</summary>

#       ifdef ERROR_WMI_READ_ONLY
        error_wmi_read_only = ERROR_WMI_READ_ONLY,
#       else
#       endif
        /// <summary>The WMI data item or data block could not be changed.</summary>

#       ifdef ERROR_WMI_SET_FAILURE
        error_wmi_set_failure = ERROR_WMI_SET_FAILURE,
#       else
#       endif
        /// <summary>This operation is only valid in the context of an app container.</summary>

#       ifdef ERROR_NOT_APPCONTAINER
        error_not_appcontainer = ERROR_NOT_APPCONTAINER,
#       else
#       endif
        /// <summary>This application can only run in the context of an app container.</summary>

#       ifdef ERROR_APPCONTAINER_REQUIRED
        error_appcontainer_required = ERROR_APPCONTAINER_REQUIRED,
#       else
#       endif
        /// <summary>This functionality is not supported in the context of an app container.</summary>

#       ifdef ERROR_NOT_SUPPORTED_IN_APPCONTAINER
        error_not_supported_in_appcontainer = ERROR_NOT_SUPPORTED_IN_APPCONTAINER,
#       else
#       endif
        /// <summary>The length of the SID supplied is not a valid length for app container SIDs.</summary>

#       ifdef ERROR_INVALID_PACKAGE_SID_LENGTH
        error_invalid_package_sid_length = ERROR_INVALID_PACKAGE_SID_LENGTH,
#       else
#       endif

        /// <summary>The media identifier does not represent a valid medium.</summary>

#       ifdef ERROR_INVALID_MEDIA
        error_invalid_media = ERROR_INVALID_MEDIA,
#       else
#       endif
        /// <summary>The library identifier does not represent a valid library.</summary>

#       ifdef ERROR_INVALID_LIBRARY
        error_invalid_library = ERROR_INVALID_LIBRARY,
#       else
#       endif
        /// <summary>The media pool identifier does not represent a valid media pool.</summary>

#       ifdef ERROR_INVALID_MEDIA_POOL
        error_invalid_media_pool = ERROR_INVALID_MEDIA_POOL,
#       else
#       endif
        /// <summary>The drive and medium are not compatible or exist in different libraries.</summary>

#       ifdef ERROR_DRIVE_MEDIA_MISMATCH
        error_drive_media_mismatch = ERROR_DRIVE_MEDIA_MISMATCH,
#       else
#       endif
        /// <summary>The medium currently exists in an offline library and must be online to perform this operation.</summary>

#       ifdef ERROR_MEDIA_OFFLINE
        error_media_offline = ERROR_MEDIA_OFFLINE,
#       else
#       endif
        /// <summary>The operation cannot be performed on an offline library.</summary>

#       ifdef ERROR_LIBRARY_OFFLINE
        error_library_offline = ERROR_LIBRARY_OFFLINE,
#       else
#       endif
        /// <summary>The library, drive, or media pool is empty.</summary>

#       ifdef ERROR_EMPTY
        error_empty = ERROR_EMPTY,
#       else
#       endif
        /// <summary>The library, drive, or media pool must be empty to perform this operation.</summary>

#       ifdef ERROR_NOT_EMPTY
        error_not_empty = ERROR_NOT_EMPTY,
#       else
#       endif
        /// <summary>No media is currently available in this media pool or library.</summary>

#       ifdef ERROR_MEDIA_UNAVAILABLE
        error_media_unavailable = ERROR_MEDIA_UNAVAILABLE,
#       else
#       endif
        /// <summary>A resource required for this operation is disabled.</summary>

#       ifdef ERROR_RESOURCE_DISABLED
        error_resource_disabled = ERROR_RESOURCE_DISABLED,
#       else
#       endif
        /// <summary>The media identifier does not represent a valid cleaner.</summary>

#       ifdef ERROR_INVALID_CLEANER
        error_invalid_cleaner = ERROR_INVALID_CLEANER,
#       else
#       endif
        /// <summary>The drive cannot be cleaned or does not support cleaning.</summary>

#       ifdef ERROR_UNABLE_TO_CLEAN
        error_unable_to_clean = ERROR_UNABLE_TO_CLEAN,
#       else
#       endif
        /// <summary>The object identifier does not represent a valid object.</summary>

#       ifdef ERROR_OBJECT_NOT_FOUND
        error_object_not_found = ERROR_OBJECT_NOT_FOUND,
#       else
#       endif
        /// <summary>Unable to read from or write to the database.</summary>

#       ifdef ERROR_DATABASE_FAILURE
        error_database_failure = ERROR_DATABASE_FAILURE,
#       else
#       endif
        /// <summary>The database is full.</summary>

#       ifdef ERROR_DATABASE_FULL
        error_database_full = ERROR_DATABASE_FULL,
#       else
#       endif
        /// <summary>The medium is not compatible with the device or media pool.</summary>

#       ifdef ERROR_MEDIA_INCOMPATIBLE
        error_media_incompatible = ERROR_MEDIA_INCOMPATIBLE,
#       else
#       endif
        /// <summary>The resource required for this operation does not exist.</summary>

#       ifdef ERROR_RESOURCE_NOT_PRESENT
        error_resource_not_present = ERROR_RESOURCE_NOT_PRESENT,
#       else
#       endif
        /// <summary>The operation identifier is not valid.</summary>

#       ifdef ERROR_INVALID_OPERATION
        error_invalid_operation = ERROR_INVALID_OPERATION,
#       else
#       endif
        /// <summary>The media is not mounted or ready for use.</summary>

#       ifdef ERROR_MEDIA_NOT_AVAILABLE
        error_media_not_available = ERROR_MEDIA_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>The device is not ready for use.</summary>

#       ifdef ERROR_DEVICE_NOT_AVAILABLE
        error_device_not_available = ERROR_DEVICE_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>The operator or administrator has refused the request.</summary>

#       ifdef ERROR_REQUEST_REFUSED
        error_request_refused = ERROR_REQUEST_REFUSED,
#       else
#       endif
        /// <summary>The drive identifier does not represent a valid drive.</summary>

#       ifdef ERROR_INVALID_DRIVE_OBJECT
        error_invalid_drive_object = ERROR_INVALID_DRIVE_OBJECT,
#       else
#       endif
        /// <summary>Library is full. No slot is available for use.</summary>

#       ifdef ERROR_LIBRARY_FULL
        error_library_full = ERROR_LIBRARY_FULL,
#       else
#       endif
        /// <summary>The transport cannot access the medium.</summary>

#       ifdef ERROR_MEDIUM_NOT_ACCESSIBLE
        error_medium_not_accessible = ERROR_MEDIUM_NOT_ACCESSIBLE,
#       else
#       endif
        /// <summary>Unable to load the medium into the drive.</summary>

#       ifdef ERROR_UNABLE_TO_LOAD_MEDIUM
        error_unable_to_load_medium = ERROR_UNABLE_TO_LOAD_MEDIUM,
#       else
#       endif
        /// <summary>Unable to retrieve the drive status.</summary>

#       ifdef ERROR_UNABLE_TO_INVENTORY_DRIVE
        error_unable_to_inventory_drive = ERROR_UNABLE_TO_INVENTORY_DRIVE,
#       else
#       endif
        /// <summary>Unable to retrieve the slot status.</summary>

#       ifdef ERROR_UNABLE_TO_INVENTORY_SLOT
        error_unable_to_inventory_slot = ERROR_UNABLE_TO_INVENTORY_SLOT,
#       else
#       endif
        /// <summary>Unable to retrieve status about the transport.</summary>

#       ifdef ERROR_UNABLE_TO_INVENTORY_TRANSPORT
        error_unable_to_inventory_transport = ERROR_UNABLE_TO_INVENTORY_TRANSPORT,
#       else
#       endif
        /// <summary>Cannot use the transport because it is already in use.</summary>

#       ifdef ERROR_TRANSPORT_FULL
        error_transport_full = ERROR_TRANSPORT_FULL,
#       else
#       endif
        /// <summary>Unable to open or close the inject/eject port.</summary>

#       ifdef ERROR_CONTROLLING_IEPORT
        error_controlling_ieport = ERROR_CONTROLLING_IEPORT,
#       else
#       endif
        /// <summary>Unable to eject the medium because it is in a drive.</summary>

#       ifdef ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA
        error_unable_to_eject_mounted_media = ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA,
#       else
#       endif
        /// <summary>A cleaner slot is already reserved.</summary>

#       ifdef ERROR_CLEANER_SLOT_SET
        error_cleaner_slot_set = ERROR_CLEANER_SLOT_SET,
#       else
#       endif
        /// <summary>A cleaner slot is not reserved.</summary>

#       ifdef ERROR_CLEANER_SLOT_NOT_SET
        error_cleaner_slot_not_set = ERROR_CLEANER_SLOT_NOT_SET,
#       else
#       endif
        /// <summary>The cleaner cartridge has performed the maximum number of drive cleanings.</summary>

#       ifdef ERROR_CLEANER_CARTRIDGE_SPENT
        error_cleaner_cartridge_spent = ERROR_CLEANER_CARTRIDGE_SPENT,
#       else
#       endif
        /// <summary>Unexpected on-medium identifier.</summary>

#       ifdef ERROR_UNEXPECTED_OMID
        error_unexpected_omid = ERROR_UNEXPECTED_OMID,
#       else
#       endif
        /// <summary>The last remaining item in this group or resource cannot be deleted.</summary>

#       ifdef ERROR_CANT_DELETE_LAST_ITEM
        error_cant_delete_last_item = ERROR_CANT_DELETE_LAST_ITEM,
#       else
#       endif
        /// <summary>The message provided exceeds the maximum size allowed for this parameter.</summary>

#       ifdef ERROR_MESSAGE_EXCEEDS_MAX_SIZE
        error_message_exceeds_max_size = ERROR_MESSAGE_EXCEEDS_MAX_SIZE,
#       else
#       endif
        /// <summary>The volume contains system or paging files.</summary>

#       ifdef ERROR_VOLUME_CONTAINS_SYS_FILES
        error_volume_contains_sys_files = ERROR_VOLUME_CONTAINS_SYS_FILES,
#       else
#       endif
        /// <summary>The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.</summary>

#       ifdef ERROR_INDIGENOUS_TYPE
        error_indigenous_type = ERROR_INDIGENOUS_TYPE,
#       else
#       endif
        /// <summary>This offline media cannot be mounted on this system since no enabled drives are present which can be used.</summary>

#       ifdef ERROR_NO_SUPPORTING_DRIVES
        error_no_supporting_drives = ERROR_NO_SUPPORTING_DRIVES,
#       else
#       endif
        /// <summary>A cleaner cartridge is present in the tape library.</summary>

#       ifdef ERROR_CLEANER_CARTRIDGE_INSTALLED
        error_cleaner_cartridge_installed = ERROR_CLEANER_CARTRIDGE_INSTALLED,
#       else
#       endif
        /// <summary>Cannot use the inject/eject port because it is not empty.</summary>

#       ifdef ERROR_IEPORT_FULL
        error_ieport_full = ERROR_IEPORT_FULL,
#       else
#       endif
        /// <summary>This file is currently not available for use on this computer.</summary>

#       ifdef ERROR_FILE_OFFLINE
        error_file_offline = ERROR_FILE_OFFLINE,
#       else
#       endif
        /// <summary>The remote storage service is not operational at this time.</summary>

#       ifdef ERROR_REMOTE_STORAGE_NOT_ACTIVE
        error_remote_storage_not_active = ERROR_REMOTE_STORAGE_NOT_ACTIVE,
#       else
#       endif
        /// <summary>The remote storage service encountered a media error.</summary>

#       ifdef ERROR_REMOTE_STORAGE_MEDIA_ERROR
        error_remote_storage_media_error = ERROR_REMOTE_STORAGE_MEDIA_ERROR,
#       else
#       endif
        /// <summary>The file or directory is not a reparse point.</summary>

#       ifdef ERROR_NOT_A_REPARSE_POINT
        error_not_a_reparse_point = ERROR_NOT_A_REPARSE_POINT,
#       else
#       endif
        /// <summary>The reparse point attribute cannot be set because it conflicts with an existing attribute.</summary>

#       ifdef ERROR_REPARSE_ATTRIBUTE_CONFLICT
        error_reparse_attribute_conflict = ERROR_REPARSE_ATTRIBUTE_CONFLICT,
#       else
#       endif
        /// <summary>The data present in the reparse point buffer is invalid.</summary>

#       ifdef ERROR_INVALID_REPARSE_DATA
        error_invalid_reparse_data = ERROR_INVALID_REPARSE_DATA,
#       else
#       endif
        /// <summary>The tag present in the reparse point buffer is invalid.</summary>

#       ifdef ERROR_REPARSE_TAG_INVALID
        error_reparse_tag_invalid = ERROR_REPARSE_TAG_INVALID,
#       else
#       endif
        /// <summary>There is a mismatch between the tag specified in the request and the tag present in the reparse point.</summary>

#       ifdef ERROR_REPARSE_TAG_MISMATCH
        error_reparse_tag_mismatch = ERROR_REPARSE_TAG_MISMATCH,
#       else
#       endif
        /// <summary>The object manager encountered a reparse point while retrieving an object.</summary>

#       ifdef ERROR_REPARSE_POINT_ENCOUNTERED
        error_reparse_point_encountered = ERROR_REPARSE_POINT_ENCOUNTERED,
#       else
#       endif
        /// <summary>Fast Cache data not found.</summary>

#       ifdef ERROR_APP_DATA_NOT_FOUND
        error_app_data_not_found = ERROR_APP_DATA_NOT_FOUND,
#       else
#       endif
        /// <summary>Fast Cache data expired.</summary>

#       ifdef ERROR_APP_DATA_EXPIRED
        error_app_data_expired = ERROR_APP_DATA_EXPIRED,
#       else
#       endif
        /// <summary>Fast Cache data corrupt.</summary>

#       ifdef ERROR_APP_DATA_CORRUPT
        error_app_data_corrupt = ERROR_APP_DATA_CORRUPT,
#       else
#       endif
        /// <summary>Fast Cache data has exceeded its max size and cannot be updated.</summary>

#       ifdef ERROR_APP_DATA_LIMIT_EXCEEDED
        error_app_data_limit_exceeded = ERROR_APP_DATA_LIMIT_EXCEEDED,
#       else
#       endif
        /// <summary>Fast Cache has been ReArmed and requires a reboot until it can be updated.</summary>

#       ifdef ERROR_APP_DATA_REBOOT_REQUIRED
        error_app_data_reboot_required = ERROR_APP_DATA_REBOOT_REQUIRED,
#       else
#       endif
        /// <summary>Secure Boot detected that rollback of protected data has been attempted.</summary>

#       ifdef ERROR_SECUREBOOT_ROLLBACK_DETECTED
        error_secureboot_rollback_detected = ERROR_SECUREBOOT_ROLLBACK_DETECTED,
#       else
#       endif
        /// <summary>The value is protected by Secure Boot policy and cannot be modified or deleted.</summary>

#       ifdef ERROR_SECUREBOOT_POLICY_VIOLATION
        error_secureboot_policy_violation = ERROR_SECUREBOOT_POLICY_VIOLATION,
#       else
#       endif
        /// <summary>The Secure Boot policy is invalid.</summary>

#       ifdef ERROR_SECUREBOOT_INVALID_POLICY
        error_secureboot_invalid_policy = ERROR_SECUREBOOT_INVALID_POLICY,
#       else
#       endif
        /// <summary>A new Secure Boot policy did not contain the current publisher on its update list.</summary>

#       ifdef ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND
        error_secureboot_policy_publisher_not_found = ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND,
#       else
#       endif
        /// <summary>The Secure Boot policy is either not signed or is signed by a non-trusted signer.</summary>

#       ifdef ERROR_SECUREBOOT_POLICY_NOT_SIGNED
        error_secureboot_policy_not_signed = ERROR_SECUREBOOT_POLICY_NOT_SIGNED,
#       else
#       endif
        /// <summary>Secure Boot is not enabled on this machine.</summary>

#       ifdef ERROR_SECUREBOOT_NOT_ENABLED
        error_secureboot_not_enabled = ERROR_SECUREBOOT_NOT_ENABLED,
#       else
#       endif
        /// <summary>Secure Boot requires that certain files and drivers are not replaced by other files or drivers.</summary>

#       ifdef ERROR_SECUREBOOT_FILE_REPLACED
        error_secureboot_file_replaced = ERROR_SECUREBOOT_FILE_REPLACED,
#       else
#       endif
        /// <summary>The Secure Boot Supplemental Policy file was not authorized on this machine.</summary>

#       ifdef ERROR_SECUREBOOT_POLICY_NOT_AUTHORIZED
        error_secureboot_policy_not_authorized = ERROR_SECUREBOOT_POLICY_NOT_AUTHORIZED,
#       else
#       endif
        /// <summary>The Supplemental Policy is not recognized on this device.</summary>

#       ifdef ERROR_SECUREBOOT_POLICY_UNKNOWN
        error_secureboot_policy_unknown = ERROR_SECUREBOOT_POLICY_UNKNOWN,
#       else
#       endif
        /// <summary>The Antirollback version was not found in the Secure Boot Policy.</summary>

#       ifdef ERROR_SECUREBOOT_POLICY_MISSING_ANTIROLLBACKVERSION
        error_secureboot_policy_missing_antirollbackversion = ERROR_SECUREBOOT_POLICY_MISSING_ANTIROLLBACKVERSION,
#       else
#       endif
        /// <summary>The Platform ID specified in the Secure Boot policy does not match the Platform ID on this device.</summary>

#       ifdef ERROR_SECUREBOOT_PLATFORM_ID_MISMATCH
        error_secureboot_platform_id_mismatch = ERROR_SECUREBOOT_PLATFORM_ID_MISMATCH,
#       else
#       endif
        /// <summary>The Secure Boot policy file has an older Antirollback Version than this device.</summary>

#       ifdef ERROR_SECUREBOOT_POLICY_ROLLBACK_DETECTED
        error_secureboot_policy_rollback_detected = ERROR_SECUREBOOT_POLICY_ROLLBACK_DETECTED,
#       else
#       endif
        /// <summary>The Secure Boot policy file does not match the upgraded legacy policy.</summary>

#       ifdef ERROR_SECUREBOOT_POLICY_UPGRADE_MISMATCH
        error_secureboot_policy_upgrade_mismatch = ERROR_SECUREBOOT_POLICY_UPGRADE_MISMATCH,
#       else
#       endif
        /// <summary>The Secure Boot policy file is required but could not be found.</summary>

#       ifdef ERROR_SECUREBOOT_REQUIRED_POLICY_FILE_MISSING
        error_secureboot_required_policy_file_missing = ERROR_SECUREBOOT_REQUIRED_POLICY_FILE_MISSING,
#       else
#       endif
        /// <summary>Supplemental Secure Boot policy file can not be loaded as a base Secure Boot policy.</summary>

#       ifdef ERROR_SECUREBOOT_NOT_BASE_POLICY
        error_secureboot_not_base_policy = ERROR_SECUREBOOT_NOT_BASE_POLICY,
#       else
#       endif
        /// <summary>Base Secure Boot policy file can not be loaded as a Supplemental Secure Boot policy.</summary>

#       ifdef ERROR_SECUREBOOT_NOT_SUPPLEMENTAL_POLICY
        error_secureboot_not_supplemental_policy = ERROR_SECUREBOOT_NOT_SUPPLEMENTAL_POLICY,
#       else
#       endif
        /// <summary>The copy offload read operation is not supported by a filter.</summary>

#       ifdef ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED
        error_offload_read_flt_not_supported = ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The copy offload write operation is not supported by a filter.</summary>

#       ifdef ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED
        error_offload_write_flt_not_supported = ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The copy offload read operation is not supported for the file.</summary>

#       ifdef ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED
        error_offload_read_file_not_supported = ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The copy offload write operation is not supported for the file.</summary>

#       ifdef ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED
        error_offload_write_file_not_supported = ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>This file is currently associated with a different stream id.</summary>

#       ifdef ERROR_ALREADY_HAS_STREAM_ID
        error_already_has_stream_id = ERROR_ALREADY_HAS_STREAM_ID,
#       else
#       endif
        /// <summary>The volume must undergo garbage collection.</summary>

#       ifdef ERROR_SMR_GARBAGE_COLLECTION_REQUIRED
        error_smr_garbage_collection_required = ERROR_SMR_GARBAGE_COLLECTION_REQUIRED,
#       else
#       endif
        /// <summary>The WOF driver encountered a corruption in WIM image's Header.</summary>

#       ifdef ERROR_WOF_WIM_HEADER_CORRUPT
        error_wof_wim_header_corrupt = ERROR_WOF_WIM_HEADER_CORRUPT,
#       else
#       endif
        /// <summary>The WOF driver encountered a corruption in WIM image's Resource Table.</summary>

#       ifdef ERROR_WOF_WIM_RESOURCE_TABLE_CORRUPT
        error_wof_wim_resource_table_corrupt = ERROR_WOF_WIM_RESOURCE_TABLE_CORRUPT,
#       else
#       endif
        /// <summary>The WOF driver encountered a corruption in the compressed file's Resource Table.</summary>

#       ifdef ERROR_WOF_FILE_RESOURCE_TABLE_CORRUPT
        error_wof_file_resource_table_corrupt = ERROR_WOF_FILE_RESOURCE_TABLE_CORRUPT,
#       else
#       endif
        /// <summary>Single Instance Storage is not available on this volume.</summary>

#       ifdef ERROR_VOLUME_NOT_SIS_ENABLED
        error_volume_not_sis_enabled = ERROR_VOLUME_NOT_SIS_ENABLED,
#       else
#       endif
        /// <summary>System Integrity detected that policy rollback has been attempted.</summary>

#       ifdef ERROR_SYSTEM_INTEGRITY_ROLLBACK_DETECTED
        error_system_integrity_rollback_detected = ERROR_SYSTEM_INTEGRITY_ROLLBACK_DETECTED,
#       else
#       endif
        /// <summary>Your organization used Device Guard to block this app. Contact your support person for more info.</summary>

#       ifdef ERROR_SYSTEM_INTEGRITY_POLICY_VIOLATION
        error_system_integrity_policy_violation = ERROR_SYSTEM_INTEGRITY_POLICY_VIOLATION,
#       else
#       endif
        /// <summary>The System Integrity policy is invalid.</summary>

#       ifdef ERROR_SYSTEM_INTEGRITY_INVALID_POLICY
        error_system_integrity_invalid_policy = ERROR_SYSTEM_INTEGRITY_INVALID_POLICY,
#       else
#       endif
        /// <summary>The System Integrity policy is either not signed or is signed by a non-trusted signer.</summary>

#       ifdef ERROR_SYSTEM_INTEGRITY_POLICY_NOT_SIGNED
        error_system_integrity_policy_not_signed = ERROR_SYSTEM_INTEGRITY_POLICY_NOT_SIGNED,
#       else
#       endif
        /// <summary>The number of System Integrity policies is out of limit.</summary>

#       ifdef ERROR_SYSTEM_INTEGRITY_TOO_MANY_POLICIES
        error_system_integrity_too_many_policies = ERROR_SYSTEM_INTEGRITY_TOO_MANY_POLICIES,
#       else
#       endif
        /// <summary>The Code Integrity supplemental policy is not authorized by a Code Integrity base policy.</summary>

#       ifdef ERROR_SYSTEM_INTEGRITY_SUPPLEMENTAL_POLICY_NOT_AUTHORIZED
        error_system_integrity_supplemental_policy_not_authorized = ERROR_SYSTEM_INTEGRITY_SUPPLEMENTAL_POLICY_NOT_AUTHORIZED,
#       else
#       endif
        /// <summary>Virtual Secure Mode (VSM) is not initialized. The hypervisor or VSM may not be present or enabled.</summary>

#       ifdef ERROR_VSM_NOT_INITIALIZED
        error_vsm_not_initialized = ERROR_VSM_NOT_INITIALIZED,
#       else
#       endif
        /// <summary>The hypervisor is not protecting DMA because an IOMMU is not present or not enabled in the BIOS.</summary>

#       ifdef ERROR_VSM_DMA_PROTECTION_NOT_IN_USE
        error_vsm_dma_protection_not_in_use = ERROR_VSM_DMA_PROTECTION_NOT_IN_USE,
#       else
#       endif

        /// <summary>The Platform Manifest file was not authorized on this machine.</summary>

#       ifdef ERROR_PLATFORM_MANIFEST_NOT_AUTHORIZED
        error_platform_manifest_not_authorized = ERROR_PLATFORM_MANIFEST_NOT_AUTHORIZED,
#       else
#       endif
        /// <summary>The Platform Manifest file was not valid.</summary>

#       ifdef ERROR_PLATFORM_MANIFEST_INVALID
        error_platform_manifest_invalid = ERROR_PLATFORM_MANIFEST_INVALID,
#       else
#       endif
        /// <summary>The file is not authorized on this platform because an entry was not found in the Platform Manifest.</summary>

#       ifdef ERROR_PLATFORM_MANIFEST_FILE_NOT_AUTHORIZED
        error_platform_manifest_file_not_authorized = ERROR_PLATFORM_MANIFEST_FILE_NOT_AUTHORIZED,
#       else
#       endif
        /// <summary>The catalog is not authorized on this platform because an entry was not found in the Platform Manifest.</summary>

#       ifdef ERROR_PLATFORM_MANIFEST_CATALOG_NOT_AUTHORIZED
        error_platform_manifest_catalog_not_authorized = ERROR_PLATFORM_MANIFEST_CATALOG_NOT_AUTHORIZED,
#       else
#       endif
        /// <summary>The file is not authorized on this platform because a Binary ID was not found in the embedded signature.</summary>

#       ifdef ERROR_PLATFORM_MANIFEST_BINARY_ID_NOT_FOUND
        error_platform_manifest_binary_id_not_found = ERROR_PLATFORM_MANIFEST_BINARY_ID_NOT_FOUND,
#       else
#       endif
        /// <summary>No active Platform Manifest exists on this system.</summary>

#       ifdef ERROR_PLATFORM_MANIFEST_NOT_ACTIVE
        error_platform_manifest_not_active = ERROR_PLATFORM_MANIFEST_NOT_ACTIVE,
#       else
#       endif
        /// <summary>The Platform Manifest file was not properly signed.</summary>

#       ifdef ERROR_PLATFORM_MANIFEST_NOT_SIGNED
        error_platform_manifest_not_signed = ERROR_PLATFORM_MANIFEST_NOT_SIGNED,
#       else
#       endif
        /// <summary>The operation cannot be completed because other resources are dependent on this resource.</summary>

#       ifdef ERROR_DEPENDENT_RESOURCE_EXISTS
        error_dependent_resource_exists = ERROR_DEPENDENT_RESOURCE_EXISTS,
#       else
#       endif
        /// <summary>The cluster resource dependency cannot be found.</summary>

#       ifdef ERROR_DEPENDENCY_NOT_FOUND
        error_dependency_not_found = ERROR_DEPENDENCY_NOT_FOUND,
#       else
#       endif
        /// <summary>The cluster resource cannot be made dependent on the specified resource because it is already dependent.</summary>

#       ifdef ERROR_DEPENDENCY_ALREADY_EXISTS
        error_dependency_already_exists = ERROR_DEPENDENCY_ALREADY_EXISTS,
#       else
#       endif
        /// <summary>The cluster resource is not online.</summary>

#       ifdef ERROR_RESOURCE_NOT_ONLINE
        error_resource_not_online = ERROR_RESOURCE_NOT_ONLINE,
#       else
#       endif
        /// <summary>A cluster node is not available for this operation.</summary>

#       ifdef ERROR_HOST_NODE_NOT_AVAILABLE
        error_host_node_not_available = ERROR_HOST_NODE_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>The cluster resource is not available.</summary>

#       ifdef ERROR_RESOURCE_NOT_AVAILABLE
        error_resource_not_available = ERROR_RESOURCE_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>The cluster resource could not be found.</summary>

#       ifdef ERROR_RESOURCE_NOT_FOUND
        error_resource_not_found = ERROR_RESOURCE_NOT_FOUND,
#       else
#       endif
        /// <summary>The cluster is being shut down.</summary>

#       ifdef ERROR_SHUTDOWN_CLUSTER
        error_shutdown_cluster = ERROR_SHUTDOWN_CLUSTER,
#       else
#       endif
        /// <summary>A cluster node cannot be evicted from the cluster unless the node is down or it is the last node.</summary>

#       ifdef ERROR_CANT_EVICT_ACTIVE_NODE
        error_cant_evict_active_node = ERROR_CANT_EVICT_ACTIVE_NODE,
#       else
#       endif
        /// <summary>The object already exists.</summary>

#       ifdef ERROR_OBJECT_ALREADY_EXISTS
        error_object_already_exists = ERROR_OBJECT_ALREADY_EXISTS,
#       else
#       endif
        /// <summary>The object is already in the list.</summary>

#       ifdef ERROR_OBJECT_IN_LIST
        error_object_in_list = ERROR_OBJECT_IN_LIST,
#       else
#       endif
        /// <summary>The cluster group is not available for any new requests.</summary>

#       ifdef ERROR_GROUP_NOT_AVAILABLE
        error_group_not_available = ERROR_GROUP_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>The cluster group could not be found.</summary>

#       ifdef ERROR_GROUP_NOT_FOUND
        error_group_not_found = ERROR_GROUP_NOT_FOUND,
#       else
#       endif
        /// <summary>The operation could not be completed because the cluster group is not online.</summary>

#       ifdef ERROR_GROUP_NOT_ONLINE
        error_group_not_online = ERROR_GROUP_NOT_ONLINE,
#       else
#       endif
        /// <summary>The operation failed because either the specified cluster node is not the owner of the resource, or the node is not a possible owner of the resource.</summary>

#       ifdef ERROR_HOST_NODE_NOT_RESOURCE_OWNER
        error_host_node_not_resource_owner = ERROR_HOST_NODE_NOT_RESOURCE_OWNER,
#       else
#       endif
        /// <summary>The operation failed because either the specified cluster node is not the owner of the group, or the node is not a possible owner of the group.</summary>

#       ifdef ERROR_HOST_NODE_NOT_GROUP_OWNER
        error_host_node_not_group_owner = ERROR_HOST_NODE_NOT_GROUP_OWNER,
#       else
#       endif
        /// <summary>The cluster resource could not be created in the specified resource monitor.</summary>

#       ifdef ERROR_RESMON_CREATE_FAILED
        error_resmon_create_failed = ERROR_RESMON_CREATE_FAILED,
#       else
#       endif
        /// <summary>The cluster resource could not be brought online by the resource monitor.</summary>

#       ifdef ERROR_RESMON_ONLINE_FAILED
        error_resmon_online_failed = ERROR_RESMON_ONLINE_FAILED,
#       else
#       endif
        /// <summary>The operation could not be completed because the cluster resource is online.</summary>

#       ifdef ERROR_RESOURCE_ONLINE
        error_resource_online = ERROR_RESOURCE_ONLINE,
#       else
#       endif
        /// <summary>The cluster resource could not be deleted or brought offline because it is the quorum resource.</summary>

#       ifdef ERROR_QUORUM_RESOURCE
        error_quorum_resource = ERROR_QUORUM_RESOURCE,
#       else
#       endif
        /// <summary>The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource.</summary>

#       ifdef ERROR_NOT_QUORUM_CAPABLE
        error_not_quorum_capable = ERROR_NOT_QUORUM_CAPABLE,
#       else
#       endif
        /// <summary>The cluster software is shutting down.</summary>

#       ifdef ERROR_CLUSTER_SHUTTING_DOWN
        error_cluster_shutting_down = ERROR_CLUSTER_SHUTTING_DOWN,
#       else
#       endif
        /// <summary>The group or resource is not in the correct state to perform the requested operation.</summary>

#       ifdef ERROR_INVALID_STATE
        error_invalid_state = ERROR_INVALID_STATE,
#       else
#       endif
        /// <summary>The properties were stored but not all changes will take effect until the next time the resource is brought online.</summary>

#       ifdef ERROR_RESOURCE_PROPERTIES_STORED
        error_resource_properties_stored = ERROR_RESOURCE_PROPERTIES_STORED,
#       else
#       endif
        /// <summary>The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class.</summary>

#       ifdef ERROR_NOT_QUORUM_CLASS
        error_not_quorum_class = ERROR_NOT_QUORUM_CLASS,
#       else
#       endif
        /// <summary>The cluster resource could not be deleted since it is a core resource.</summary>

#       ifdef ERROR_CORE_RESOURCE
        error_core_resource = ERROR_CORE_RESOURCE,
#       else
#       endif
        /// <summary>The quorum resource failed to come online.</summary>

#       ifdef ERROR_QUORUM_RESOURCE_ONLINE_FAILED
        error_quorum_resource_online_failed = ERROR_QUORUM_RESOURCE_ONLINE_FAILED,
#       else
#       endif
        /// <summary>The quorum log could not be created or mounted successfully.</summary>

#       ifdef ERROR_QUORUMLOG_OPEN_FAILED
        error_quorumlog_open_failed = ERROR_QUORUMLOG_OPEN_FAILED,
#       else
#       endif
        /// <summary>The cluster log is corrupt.</summary>

#       ifdef ERROR_CLUSTERLOG_CORRUPT
        error_clusterlog_corrupt = ERROR_CLUSTERLOG_CORRUPT,
#       else
#       endif
        /// <summary>The record could not be written to the cluster log since it exceeds the maximum size.</summary>

#       ifdef ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE
        error_clusterlog_record_exceeds_maxsize = ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE,
#       else
#       endif
        /// <summary>The cluster log exceeds its maximum size.</summary>

#       ifdef ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE
        error_clusterlog_exceeds_maxsize = ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE,
#       else
#       endif
        /// <summary>No checkpoint record was found in the cluster log.</summary>

#       ifdef ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND
        error_clusterlog_chkpoint_not_found = ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND,
#       else
#       endif
        /// <summary>The minimum required disk space needed for logging is not available.</summary>

#       ifdef ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE
        error_clusterlog_not_enough_space = ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE,
#       else
#       endif
        /// <summary>The cluster node failed to take control of the quorum resource because the resource is owned by another active node.</summary>

#       ifdef ERROR_QUORUM_OWNER_ALIVE
        error_quorum_owner_alive = ERROR_QUORUM_OWNER_ALIVE,
#       else
#       endif
        /// <summary>A cluster network is not available for this operation.</summary>

#       ifdef ERROR_NETWORK_NOT_AVAILABLE
        error_network_not_available = ERROR_NETWORK_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>A cluster node is not available for this operation.</summary>

#       ifdef ERROR_NODE_NOT_AVAILABLE
        error_node_not_available = ERROR_NODE_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>All cluster nodes must be running to perform this operation.</summary>

#       ifdef ERROR_ALL_NODES_NOT_AVAILABLE
        error_all_nodes_not_available = ERROR_ALL_NODES_NOT_AVAILABLE,
#       else
#       endif
        /// <summary>A cluster resource failed.</summary>

#       ifdef ERROR_RESOURCE_FAILED
        error_resource_failed = ERROR_RESOURCE_FAILED,
#       else
#       endif
        /// <summary>The cluster node is not valid.</summary>

#       ifdef ERROR_CLUSTER_INVALID_NODE
        error_cluster_invalid_node = ERROR_CLUSTER_INVALID_NODE,
#       else
#       endif
        /// <summary>The cluster node already exists.</summary>

#       ifdef ERROR_CLUSTER_NODE_EXISTS
        error_cluster_node_exists = ERROR_CLUSTER_NODE_EXISTS,
#       else
#       endif
        /// <summary>A node is in the process of joining the cluster.</summary>

#       ifdef ERROR_CLUSTER_JOIN_IN_PROGRESS
        error_cluster_join_in_progress = ERROR_CLUSTER_JOIN_IN_PROGRESS,
#       else
#       endif
        /// <summary>The cluster node was not found.</summary>

#       ifdef ERROR_CLUSTER_NODE_NOT_FOUND
        error_cluster_node_not_found = ERROR_CLUSTER_NODE_NOT_FOUND,
#       else
#       endif
        /// <summary>The cluster local node information was not found.</summary>

#       ifdef ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND
        error_cluster_local_node_not_found = ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND,
#       else
#       endif
        /// <summary>The cluster network already exists.</summary>

#       ifdef ERROR_CLUSTER_NETWORK_EXISTS
        error_cluster_network_exists = ERROR_CLUSTER_NETWORK_EXISTS,
#       else
#       endif
        /// <summary>The cluster network was not found.</summary>

#       ifdef ERROR_CLUSTER_NETWORK_NOT_FOUND
        error_cluster_network_not_found = ERROR_CLUSTER_NETWORK_NOT_FOUND,
#       else
#       endif
        /// <summary>The cluster network interface already exists.</summary>

#       ifdef ERROR_CLUSTER_NETINTERFACE_EXISTS
        error_cluster_netinterface_exists = ERROR_CLUSTER_NETINTERFACE_EXISTS,
#       else
#       endif
        /// <summary>The cluster network interface was not found.</summary>

#       ifdef ERROR_CLUSTER_NETINTERFACE_NOT_FOUND
        error_cluster_netinterface_not_found = ERROR_CLUSTER_NETINTERFACE_NOT_FOUND,
#       else
#       endif
        /// <summary>The cluster request is not valid for this object.</summary>

#       ifdef ERROR_CLUSTER_INVALID_REQUEST
        error_cluster_invalid_request = ERROR_CLUSTER_INVALID_REQUEST,
#       else
#       endif
        /// <summary>The cluster network provider is not valid.</summary>

#       ifdef ERROR_CLUSTER_INVALID_NETWORK_PROVIDER
        error_cluster_invalid_network_provider = ERROR_CLUSTER_INVALID_NETWORK_PROVIDER,
#       else
#       endif
        /// <summary>The cluster node is down.</summary>

#       ifdef ERROR_CLUSTER_NODE_DOWN
        error_cluster_node_down = ERROR_CLUSTER_NODE_DOWN,
#       else
#       endif
        /// <summary>The cluster node is not reachable.</summary>

#       ifdef ERROR_CLUSTER_NODE_UNREACHABLE
        error_cluster_node_unreachable = ERROR_CLUSTER_NODE_UNREACHABLE,
#       else
#       endif
        /// <summary>The cluster node is not a member of the cluster.</summary>

#       ifdef ERROR_CLUSTER_NODE_NOT_MEMBER
        error_cluster_node_not_member = ERROR_CLUSTER_NODE_NOT_MEMBER,
#       else
#       endif
        /// <summary>A cluster join operation is not in progress.</summary>

#       ifdef ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS
        error_cluster_join_not_in_progress = ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS,
#       else
#       endif
        /// <summary>The cluster network is not valid.</summary>

#       ifdef ERROR_CLUSTER_INVALID_NETWORK
        error_cluster_invalid_network = ERROR_CLUSTER_INVALID_NETWORK,
#       else
#       endif
        /// <summary>The cluster node is up.</summary>

#       ifdef ERROR_CLUSTER_NODE_UP
        error_cluster_node_up = ERROR_CLUSTER_NODE_UP,
#       else
#       endif
        /// <summary>The cluster IP address is already in use.</summary>

#       ifdef ERROR_CLUSTER_IPADDR_IN_USE
        error_cluster_ipaddr_in_use = ERROR_CLUSTER_IPADDR_IN_USE,
#       else
#       endif
        /// <summary>The cluster node is not paused.</summary>

#       ifdef ERROR_CLUSTER_NODE_NOT_PAUSED
        error_cluster_node_not_paused = ERROR_CLUSTER_NODE_NOT_PAUSED,
#       else
#       endif
        /// <summary>No cluster security context is available.</summary>

#       ifdef ERROR_CLUSTER_NO_SECURITY_CONTEXT
        error_cluster_no_security_context = ERROR_CLUSTER_NO_SECURITY_CONTEXT,
#       else
#       endif
        /// <summary>The cluster network is not configured for internal cluster communication.</summary>

#       ifdef ERROR_CLUSTER_NETWORK_NOT_INTERNAL
        error_cluster_network_not_internal = ERROR_CLUSTER_NETWORK_NOT_INTERNAL,
#       else
#       endif
        /// <summary>The cluster node is already up.</summary>

#       ifdef ERROR_CLUSTER_NODE_ALREADY_UP
        error_cluster_node_already_up = ERROR_CLUSTER_NODE_ALREADY_UP,
#       else
#       endif
        /// <summary>The cluster node is already down.</summary>

#       ifdef ERROR_CLUSTER_NODE_ALREADY_DOWN
        error_cluster_node_already_down = ERROR_CLUSTER_NODE_ALREADY_DOWN,
#       else
#       endif
        /// <summary>The cluster network is already online.</summary>

#       ifdef ERROR_CLUSTER_NETWORK_ALREADY_ONLINE
        error_cluster_network_already_online = ERROR_CLUSTER_NETWORK_ALREADY_ONLINE,
#       else
#       endif
        /// <summary>The cluster network is already offline.</summary>

#       ifdef ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE
        error_cluster_network_already_offline = ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE,
#       else
#       endif
        /// <summary>The cluster node is already a member of the cluster.</summary>

#       ifdef ERROR_CLUSTER_NODE_ALREADY_MEMBER
        error_cluster_node_already_member = ERROR_CLUSTER_NODE_ALREADY_MEMBER,
#       else
#       endif
        /// <summary>The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.</summary>

#       ifdef ERROR_CLUSTER_LAST_INTERNAL_NETWORK
        error_cluster_last_internal_network = ERROR_CLUSTER_LAST_INTERNAL_NETWORK,
#       else
#       endif
        /// <summary>One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.</summary>

#       ifdef ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS
        error_cluster_network_has_dependents = ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS,
#       else
#       endif
        /// <summary>This operation cannot currently be performed on the cluster group containing the quorum resource.</summary>

#       ifdef ERROR_INVALID_OPERATION_ON_QUORUM
        error_invalid_operation_on_quorum = ERROR_INVALID_OPERATION_ON_QUORUM,
#       else
#       endif
        /// <summary>The cluster quorum resource is not allowed to have any dependencies.</summary>

#       ifdef ERROR_DEPENDENCY_NOT_ALLOWED
        error_dependency_not_allowed = ERROR_DEPENDENCY_NOT_ALLOWED,
#       else
#       endif
        /// <summary>The cluster node is paused.</summary>

#       ifdef ERROR_CLUSTER_NODE_PAUSED
        error_cluster_node_paused = ERROR_CLUSTER_NODE_PAUSED,
#       else
#       endif
        /// <summary>The cluster resource cannot be brought online. The owner node cannot run this resource.</summary>

#       ifdef ERROR_NODE_CANT_HOST_RESOURCE
        error_node_cant_host_resource = ERROR_NODE_CANT_HOST_RESOURCE,
#       else
#       endif
        /// <summary>The cluster node is not ready to perform the requested operation.</summary>

#       ifdef ERROR_CLUSTER_NODE_NOT_READY
        error_cluster_node_not_ready = ERROR_CLUSTER_NODE_NOT_READY,
#       else
#       endif
        /// <summary>The cluster node is shutting down.</summary>

#       ifdef ERROR_CLUSTER_NODE_SHUTTING_DOWN
        error_cluster_node_shutting_down = ERROR_CLUSTER_NODE_SHUTTING_DOWN,
#       else
#       endif
        /// <summary>The cluster join operation was aborted.</summary>

#       ifdef ERROR_CLUSTER_JOIN_ABORTED
        error_cluster_join_aborted = ERROR_CLUSTER_JOIN_ABORTED,
#       else
#       endif
        /// <summary>The node failed to join the cluster because the joining node and other nodes in the cluster have incompatible operating system versions. To get more information about operating system versions of the cluster, run the Validate a Configuration Wizard or the Test-Cluster Windows PowerShell cmdlet.</summary>

#       ifdef ERROR_CLUSTER_INCOMPATIBLE_VERSIONS
        error_cluster_incompatible_versions = ERROR_CLUSTER_INCOMPATIBLE_VERSIONS,
#       else
#       endif
        /// <summary>This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.</summary>

#       ifdef ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED
        error_cluster_maxnum_of_resources_exceeded = ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED,
#       else
#       endif
        /// <summary>The system configuration changed during the cluster join or form operation. The join or form operation was aborted.</summary>

#       ifdef ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED
        error_cluster_system_config_changed = ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED,
#       else
#       endif
        /// <summary>The specified resource type was not found.</summary>

#       ifdef ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND
        error_cluster_resource_type_not_found = ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND,
#       else
#       endif
        /// <summary>The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.</summary>

#       ifdef ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED
        error_cluster_restype_not_supported = ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED,
#       else
#       endif
        /// <summary>The specified resource name is not supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.</summary>

#       ifdef ERROR_CLUSTER_RESNAME_NOT_FOUND
        error_cluster_resname_not_found = ERROR_CLUSTER_RESNAME_NOT_FOUND,
#       else
#       endif
        /// <summary>No authentication package could be registered with the RPC server.</summary>

#       ifdef ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED
        error_cluster_no_rpc_packages_registered = ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED,
#       else
#       endif
        /// <summary>You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.</summary>

#       ifdef ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST
        error_cluster_owner_not_in_preflist = ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST,
#       else
#       endif
        /// <summary>The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.</summary>

#       ifdef ERROR_CLUSTER_DATABASE_SEQMISMATCH
        error_cluster_database_seqmismatch = ERROR_CLUSTER_DATABASE_SEQMISMATCH,
#       else
#       endif
        /// <summary>The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.</summary>

#       ifdef ERROR_RESMON_INVALID_STATE
        error_resmon_invalid_state = ERROR_RESMON_INVALID_STATE,
#       else
#       endif
        /// <summary>A non locker code got a request to reserve the lock for making global updates.</summary>

#       ifdef ERROR_CLUSTER_GUM_NOT_LOCKER
        error_cluster_gum_not_locker = ERROR_CLUSTER_GUM_NOT_LOCKER,
#       else
#       endif
        /// <summary>The quorum disk could not be located by the cluster service.</summary>

#       ifdef ERROR_QUORUM_DISK_NOT_FOUND
        error_quorum_disk_not_found = ERROR_QUORUM_DISK_NOT_FOUND,
#       else
#       endif
        /// <summary>The backed up cluster database is possibly corrupt.</summary>

#       ifdef ERROR_DATABASE_BACKUP_CORRUPT
        error_database_backup_corrupt = ERROR_DATABASE_BACKUP_CORRUPT,
#       else
#       endif
        /// <summary>A DFS root already exists in this cluster node.</summary>

#       ifdef ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT
        error_cluster_node_already_has_dfs_root = ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT,
#       else
#       endif
        /// <summary>An attempt to modify a resource property failed because it conflicts with another existing property.</summary>

#       ifdef ERROR_RESOURCE_PROPERTY_UNCHANGEABLE
        error_resource_property_unchangeable = ERROR_RESOURCE_PROPERTY_UNCHANGEABLE,
#       else
#       endif
        /// <summary>This operation is not supported on a cluster without an Administrator Access Point.</summary>

#       ifdef ERROR_NO_ADMIN_ACCESS_POINT
        error_no_admin_access_point = ERROR_NO_ADMIN_ACCESS_POINT,
#       else
#       endif

        /*
         Codes from 4300 through 5889 overlap with codes in ds\published\inc\apperr2.w.
         Do not add any more error codes in that range.
        */

        /// <summary>An operation was attempted that is incompatible with the current membership state of the node.</summary>

#       ifdef ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE
        error_cluster_membership_invalid_state = ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE,
#       else
#       endif
        /// <summary>The quorum resource does not contain the quorum log.</summary>

#       ifdef ERROR_CLUSTER_QUORUMLOG_NOT_FOUND
        error_cluster_quorumlog_not_found = ERROR_CLUSTER_QUORUMLOG_NOT_FOUND,
#       else
#       endif
        /// <summary>The membership engine requested shutdown of the cluster service on this node.</summary>

#       ifdef ERROR_CLUSTER_MEMBERSHIP_HALT
        error_cluster_membership_halt = ERROR_CLUSTER_MEMBERSHIP_HALT,
#       else
#       endif
        /// <summary>The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node.</summary>

#       ifdef ERROR_CLUSTER_INSTANCE_ID_MISMATCH
        error_cluster_instance_id_mismatch = ERROR_CLUSTER_INSTANCE_ID_MISMATCH,
#       else
#       endif
        /// <summary>A matching cluster network for the specified IP address could not be found.</summary>

#       ifdef ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP
        error_cluster_network_not_found_for_ip = ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP,
#       else
#       endif
        /// <summary>The actual data type of the property did not match the expected data type of the property.</summary>

#       ifdef ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH
        error_cluster_property_data_type_mismatch = ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH,
#       else
#       endif
        /// <summary>The cluster node was evicted from the cluster successfully, but the node was not cleaned up. To determine what cleanup steps failed and how to recover, see the Failover Clustering application event log using Event Viewer.</summary>

#       ifdef ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP
        error_cluster_evict_without_cleanup = ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP,
#       else
#       endif
        /// <summary>Two or more parameter values specified for a resource's properties are in conflict.</summary>

#       ifdef ERROR_CLUSTER_PARAMETER_MISMATCH
        error_cluster_parameter_mismatch = ERROR_CLUSTER_PARAMETER_MISMATCH,
#       else
#       endif
        /// <summary>This computer cannot be made a member of a cluster.</summary>

#       ifdef ERROR_NODE_CANNOT_BE_CLUSTERED
        error_node_cannot_be_clustered = ERROR_NODE_CANNOT_BE_CLUSTERED,
#       else
#       endif
        /// <summary>This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed.</summary>

#       ifdef ERROR_CLUSTER_WRONG_OS_VERSION
        error_cluster_wrong_os_version = ERROR_CLUSTER_WRONG_OS_VERSION,
#       else
#       endif
        /// <summary>A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster.</summary>

#       ifdef ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME
        error_cluster_cant_create_dup_cluster_name = ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME,
#       else
#       endif
        /// <summary>The cluster configuration action has already been committed.</summary>

#       ifdef ERROR_CLUSCFG_ALREADY_COMMITTED
        error_cluscfg_already_committed = ERROR_CLUSCFG_ALREADY_COMMITTED,
#       else
#       endif
        /// <summary>The cluster configuration action could not be rolled back.</summary>

#       ifdef ERROR_CLUSCFG_ROLLBACK_FAILED
        error_cluscfg_rollback_failed = ERROR_CLUSCFG_ROLLBACK_FAILED,
#       else
#       endif
        /// <summary>The drive letter assigned to a system disk on one node conflicted with the drive letter assigned to a disk on another node.</summary>

#       ifdef ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT
        error_cluscfg_system_disk_drive_letter_conflict = ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT,
#       else
#       endif

        /// <summary>One or more nodes in the cluster are running a version of Windows that does not support this operation.</summary>
#       ifdef ERROR_CLUSTER_OLD_VERSION
        error_cluster_old_version = ERROR_CLUSTER_OLD_VERSION,
#       else            
        error_cluster_old_version = 5904L,
#       endif

#       ifdef ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME
        /// <summary>The name of the corresponding computer account doesn't match the Network Name for this resource.</summary>
        error_cluster_mismatched_computer_acct_name = ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NO_NET_ADAPTERS
        /// <summary>No network adapters are available.</summary>
        error_cluster_no_net_adapters = ERROR_CLUSTER_NO_NET_ADAPTERS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_POISONED
        /// <summary>The cluster node has been poisoned.</summary>
        error_cluster_poisoned = ERROR_CLUSTER_POISONED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_GROUP_MOVING
        /// <summary>The group is unable to accept the request since it is moving to another node.</summary>
        error_cluster_group_moving = ERROR_CLUSTER_GROUP_MOVING,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_TYPE_BUSY
        /// <summary>The resource type cannot accept the request since is too busy performing another operation.</summary>
        error_cluster_resource_type_busy = ERROR_CLUSTER_RESOURCE_TYPE_BUSY,
#       else
#       endif

#       ifdef ERROR_RESOURCE_CALL_TIMED_OUT
        /// <summary>The call to the cluster resource DLL timed out.</summary>
        error_resource_call_timed_out = ERROR_RESOURCE_CALL_TIMED_OUT,
#       else
#       endif

#       ifdef ERROR_INVALID_CLUSTER_IPV6_ADDRESS
        /// <summary>The address is not valid for an IPv6 Address resource. A global IPv6 address is required, and it must match a cluster network. Compatibility addresses are not permitted.</summary>
        error_invalid_cluster_ipv6_address = ERROR_INVALID_CLUSTER_IPV6_ADDRESS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION
        /// <summary>An internal cluster error occurred. A call to an invalid function was attempted.</summary>
        error_cluster_internal_invalid_function = ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION,
#       else
#       endif

#       ifdef ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS
        /// <summary>A parameter value is out of acceptable range.</summary>
        error_cluster_parameter_out_of_bounds = ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_PARTIAL_SEND
        /// <summary>A network error occurred while sending data to another node in the cluster. The number of bytes transmitted was less than required.</summary>
        error_cluster_partial_send = ERROR_CLUSTER_PARTIAL_SEND,
#       else
#       endif

#       ifdef ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION
        /// <summary>An invalid cluster registry operation was attempted.</summary>
        error_cluster_registry_invalid_function = ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION,
#       else
#       endif

#       ifdef ERROR_CLUSTER_INVALID_STRING_TERMINATION
        /// <summary>An input string of characters is not properly terminated.</summary>
        error_cluster_invalid_string_termination = ERROR_CLUSTER_INVALID_STRING_TERMINATION,
#       else
#       endif

#       ifdef ERROR_CLUSTER_INVALID_STRING_FORMAT
        /// <summary>An input string of characters is not in a valid format for the data it represents.</summary>
        error_cluster_invalid_string_format = ERROR_CLUSTER_INVALID_STRING_FORMAT,
#       else
#       endif

#       ifdef ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS
        /// <summary>An internal cluster error occurred. A cluster database transaction was attempted while a transaction was already in progress.</summary>
        error_cluster_database_transaction_in_progress = ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS
        /// <summary>An internal cluster error occurred. There was an attempt to commit a cluster database transaction while no transaction was in progress.</summary>
        error_cluster_database_transaction_not_in_progress = ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NULL_DATA
        /// <summary>An internal cluster error occurred. Data was not properly initialized.</summary>
        error_cluster_null_data = ERROR_CLUSTER_NULL_DATA,
#       else
#       endif

#       ifdef ERROR_CLUSTER_PARTIAL_READ
        /// <summary>An error occurred while reading from a stream of data. An unexpected number of bytes was returned.</summary>
        error_cluster_partial_read = ERROR_CLUSTER_PARTIAL_READ,
#       else
#       endif

#       ifdef ERROR_CLUSTER_PARTIAL_WRITE
        /// <summary>An error occurred while writing to a stream of data. The required number of bytes could not be written.</summary>
        error_cluster_partial_write = ERROR_CLUSTER_PARTIAL_WRITE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_CANT_DESERIALIZE_DATA
        /// <summary>An error occurred while deserializing a stream of cluster data.</summary>
        error_cluster_cant_deserialize_data = ERROR_CLUSTER_CANT_DESERIALIZE_DATA,
#       else
#       endif

#       ifdef ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT
        /// <summary>One or more property values for this resource are in conflict with one or more property values associated with its dependent resource(s).</summary>
        error_dependent_resource_property_conflict = ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NO_QUORUM
        /// <summary>A quorum of cluster nodes was not present to form a cluster.</summary>
        error_cluster_no_quorum = ERROR_CLUSTER_NO_QUORUM,
#       else
#       endif

#       ifdef ERROR_CLUSTER_INVALID_IPV6_NETWORK
        /// <summary>The cluster network is not valid for an IPv6 Address resource, or it does not match the configured address.</summary>
        error_cluster_invalid_ipv6_network = ERROR_CLUSTER_INVALID_IPV6_NETWORK,
#       else
#       endif

#       ifdef ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK
        /// <summary>The cluster network is not valid for an IPv6 Tunnel resource. Check the configuration of the IP Address resource on which the IPv6 Tunnel resource depends.</summary>
        error_cluster_invalid_ipv6_tunnel_network = ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK,
#       else
#       endif

#       ifdef ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP
        /// <summary>Quorum resource cannot reside in the Available Storage group.</summary>
        error_quorum_not_allowed_in_this_group = ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP,
#       else
#       endif

#       ifdef ERROR_DEPENDENCY_TREE_TOO_COMPLEX
        /// <summary>The dependencies for this resource are nested too deeply.</summary>
        error_dependency_tree_too_complex = ERROR_DEPENDENCY_TREE_TOO_COMPLEX,
#       else
#       endif

#       ifdef ERROR_EXCEPTION_IN_RESOURCE_CALL
        /// <summary>The call into the resource DLL raised an unhandled exception.</summary>
        error_exception_in_resource_call = ERROR_EXCEPTION_IN_RESOURCE_CALL,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RHS_FAILED_INITIALIZATION
        /// <summary>The RHS process failed to initialize.</summary>
        error_cluster_rhs_failed_initialization = ERROR_CLUSTER_RHS_FAILED_INITIALIZATION,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NOT_INSTALLED
        /// <summary>The Failover Clustering feature is not installed on this node.</summary>
        error_cluster_not_installed = ERROR_CLUSTER_NOT_INSTALLED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE
        /// <summary>The resources must be online on the same node for this operation</summary>
        error_cluster_resources_must_be_online_on_the_same_node = ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_MAX_NODES_IN_CLUSTER
        /// <summary>A new node can not be added since this cluster is already at its maximum number of nodes.</summary>
        error_cluster_max_nodes_in_cluster = ERROR_CLUSTER_MAX_NODES_IN_CLUSTER,
#       else
#       endif

#       ifdef ERROR_CLUSTER_TOO_MANY_NODES
        /// <summary>This cluster can not be created since the specified number of nodes exceeds the maximum allowed limit.</summary>
        error_cluster_too_many_nodes = ERROR_CLUSTER_TOO_MANY_NODES,
#       else
#       endif

#       ifdef ERROR_CLUSTER_OBJECT_ALREADY_USED
        /// <summary>An attempt to use the specified cluster name failed because an enabled computer object with the given name already exists in the domain.</summary>
        error_cluster_object_already_used = ERROR_CLUSTER_OBJECT_ALREADY_USED,
#       else
#       endif

#       ifdef ERROR_NONCORE_GROUPS_FOUND
        /// <summary>This cluster cannot be destroyed. It has non-core application groups which must be deleted before the cluster can be destroyed.</summary>
        error_noncore_groups_found = ERROR_NONCORE_GROUPS_FOUND,
#       else
#       endif

#       ifdef ERROR_FILE_SHARE_RESOURCE_CONFLICT
        /// <summary>File share associated with file share witness resource cannot be hosted by this cluster or any of its nodes.</summary>
        error_file_share_resource_conflict = ERROR_FILE_SHARE_RESOURCE_CONFLICT,
#       else
#       endif

#       ifdef ERROR_CLUSTER_EVICT_INVALID_REQUEST
        /// <summary>If it is the last node in the cluster, destroy cluster command should be used.</summary>
        error_cluster_evict_invalid_request = ERROR_CLUSTER_EVICT_INVALID_REQUEST,
#       else
#       endif

#       ifdef ERROR_CLUSTER_SINGLETON_RESOURCE
        /// <summary>Only one instance of this resource type is allowed in the cluster.</summary>
        error_cluster_singleton_resource = ERROR_CLUSTER_SINGLETON_RESOURCE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE
        /// <summary>Only one instance of this resource type is allowed per resource group.</summary>
        error_cluster_group_singleton_resource = ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED
        /// <summary>The resource failed to come online due to the failure of one or more provider resources.</summary>
        error_cluster_resource_provider_failed = ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR
        /// <summary>The resource has indicated that it cannot come online on any node.</summary>
        error_cluster_resource_configuration_error = ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR,
#       else
#       endif

#       ifdef ERROR_CLUSTER_GROUP_BUSY
        /// <summary>The current operation cannot be performed on this group at this time.</summary>
        error_cluster_group_busy = ERROR_CLUSTER_GROUP_BUSY,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NOT_SHARED_VOLUME
        /// <summary>The directory or file is not located on a cluster shared volume.</summary>
        error_cluster_not_shared_volume = ERROR_CLUSTER_NOT_SHARED_VOLUME,
#       else
#       endif

#       ifdef ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR
        /// <summary>The Security Descriptor does not meet the requirements for a cluster.</summary>
        error_cluster_invalid_security_descriptor = ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR,
#       else
#       endif

#       ifdef ERROR_CLUSTER_SHARED_VOLUMES_IN_USE
        /// <summary>Those resources must be moved to available storage in order for operation to succeed.</summary>
        error_cluster_shared_volumes_in_use = ERROR_CLUSTER_SHARED_VOLUMES_IN_USE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_USE_SHARED_VOLUMES_API
        /// <summary>Use shared volume APIs to perform desired operation.</summary>
        error_cluster_use_shared_volumes_api = ERROR_CLUSTER_USE_SHARED_VOLUMES_API,
#       else
#       endif

#       ifdef ERROR_CLUSTER_BACKUP_IN_PROGRESS
        /// <summary>Back up is in progress. Please wait for backup completion before trying this operation again.</summary>
        error_cluster_backup_in_progress = ERROR_CLUSTER_BACKUP_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_NON_CSV_PATH
        /// <summary>The path does not belong to a cluster shared volume.</summary>
        error_non_csv_path = ERROR_NON_CSV_PATH,
#       else
#       endif

#       ifdef ERROR_CSV_VOLUME_NOT_LOCAL
        /// <summary>The cluster shared volume is not locally mounted on this node.</summary>
        error_csv_volume_not_local = ERROR_CSV_VOLUME_NOT_LOCAL,
#       else
#       endif

#       ifdef ERROR_CLUSTER_WATCHDOG_TERMINATING
        /// <summary>The cluster watchdog is terminating.</summary>
        error_cluster_watchdog_terminating = ERROR_CLUSTER_WATCHDOG_TERMINATING,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES
        /// <summary>A resource vetoed a move between two nodes because they are incompatible.</summary>
        error_cluster_resource_vetoed_move_incompatible_nodes = ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES,
#       else
#       endif

#       ifdef ERROR_CLUSTER_INVALID_NODE_WEIGHT
        /// <summary>The request is invalid either because node weight cannot be changed while the cluster is in disk-only quorum mode, or because changing the node weight would violate the minimum cluster quorum requirements.</summary>
        error_cluster_invalid_node_weight = ERROR_CLUSTER_INVALID_NODE_WEIGHT,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_VETOED_CALL
        /// <summary>The resource vetoed the call.</summary>
        error_cluster_resource_vetoed_call = ERROR_CLUSTER_RESOURCE_VETOED_CALL,
#       else
#       endif

#       ifdef ERROR_RESMON_SYSTEM_RESOURCES_LACKING
        /// <summary>Resource could not start or run because it could not reserve sufficient system resources.</summary>
        error_resmon_system_resources_lacking = ERROR_RESMON_SYSTEM_RESOURCES_LACKING,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION
        /// <summary>A resource vetoed a move between two nodes because the destination currently does not have enough resources to complete the operation.</summary>
        error_cluster_resource_vetoed_move_not_enough_resources_on_destination = ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE
        /// <summary>A resource vetoed a move between two nodes because the source currently does not have enough resources to complete the operation.</summary>
        error_cluster_resource_vetoed_move_not_enough_resources_on_source = ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_GROUP_QUEUED
        /// <summary>The requested operation can not be completed because the group is queued for an operation.</summary>
        error_cluster_group_queued = ERROR_CLUSTER_GROUP_QUEUED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_LOCKED_STATUS
        /// <summary>The requested operation can not be completed because a resource has locked status.</summary>
        error_cluster_resource_locked_status = ERROR_CLUSTER_RESOURCE_LOCKED_STATUS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED
        /// <summary>The resource cannot move to another node because a cluster shared volume vetoed the operation.</summary>
        error_cluster_shared_volume_failover_not_allowed = ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS
        /// <summary>A node drain is already in progress.</summary>
        error_cluster_node_drain_in_progress = ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_DISK_NOT_CONNECTED
        /// <summary>Clustered storage is not connected to the node.</summary>
        error_cluster_disk_not_connected = ERROR_CLUSTER_DISK_NOT_CONNECTED,
#       else
#       endif

#       ifdef ERROR_DISK_NOT_CSV_CAPABLE
        /// <summary>The disk is not configured in a way to be used with CSV. CSV disks must have at least one partition that is formatted with NTFS or REFS.</summary>
        error_disk_not_csv_capable = ERROR_DISK_NOT_CSV_CAPABLE,
#       else
#       endif

#       ifdef ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE
        /// <summary>The resource must be part of the Available Storage group to complete this action.</summary>
        error_resource_not_in_available_storage = ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED
        /// <summary>CSVFS failed operation as volume is in redirected mode.</summary>
        error_cluster_shared_volume_redirected = ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED
        /// <summary>CSVFS failed operation as volume is not in redirected mode.</summary>
        error_cluster_shared_volume_not_redirected = ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES
        /// <summary>Cluster properties cannot be returned at this time.</summary>
        error_cluster_cannot_return_properties = ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES
        /// <summary>The clustered disk resource contains software snapshot diff area that are not supported for Cluster Shared Volumes.</summary>
        error_cluster_resource_contains_unsupported_diff_area_for_shared_volumes = ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES,
#       else
#       endif


#       ifdef ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE
        /// <summary>The operation cannot be completed because the resource is in maintenance mode.</summary>
        error_cluster_resource_is_in_maintenance_mode = ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_AFFINITY_CONFLICT
        /// <summary>The operation cannot be completed because of cluster affinity conflicts</summary>
        error_cluster_affinity_conflict = ERROR_CLUSTER_AFFINITY_CONFLICT,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE
        /// <summary>The operation cannot be completed because the resource is a replica virtual machine.</summary>
        error_cluster_resource_is_replica_virtual_machine = ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_UPGRADE_INCOMPATIBLE_VERSIONS
        /// <summary>The Cluster Functional Level could not be increased because not all nodes in the cluster support the updated version.</summary>
        error_cluster_upgrade_incompatible_versions = ERROR_CLUSTER_UPGRADE_INCOMPATIBLE_VERSIONS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_UPGRADE_FIX_QUORUM_NOT_SUPPORTED
        /// <summary>
        /// Updating the cluster functional level failed because the cluster is running in fix quorum mode. 
        /// Start additional nodes which are members of the cluster until the cluster reaches quorum and the cluster will automatically
        /// switch out of fix quorum mode, or stop and restart the cluster without the FixQuorum switch. Once the cluster is out
        /// of fix quorum mode retry the Update-ClusterFunctionalLevel PowerShell cmdlet to update the cluster functional level.
        /// </summary>
        error_cluster_upgrade_fix_quorum_not_supported = ERROR_CLUSTER_UPGRADE_FIX_QUORUM_NOT_SUPPORTED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_UPGRADE_RESTART_REQUIRED
        /// <summary>
        /// The cluster functional level has been successfully updated but not all features are available yet. Restart the cluster by
        /// using the Stop-Cluster PowerShell cmdlet followed by the Start-Cluster PowerShell cmdlet and all cluster features will 
        /// be available. 
        /// </summary>
        error_cluster_upgrade_restart_required = ERROR_CLUSTER_UPGRADE_RESTART_REQUIRED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_UPGRADE_IN_PROGRESS
        /// <summary>The cluster is currently performing a version upgrade.</summary>
        error_cluster_upgrade_in_progress = ERROR_CLUSTER_UPGRADE_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_CLUSTER_UPGRADE_INCOMPLETE
        /// <summary>The cluster did not successfully complete the version upgrade.</summary>
        error_cluster_upgrade_incomplete = ERROR_CLUSTER_UPGRADE_INCOMPLETE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NODE_IN_GRACE_PERIOD
        /// <summary>The cluster node is in grace period.</summary>
        error_cluster_node_in_grace_period = ERROR_CLUSTER_NODE_IN_GRACE_PERIOD,
#       else
#       endif

#       ifdef ERROR_CLUSTER_CSV_IO_PAUSE_TIMEOUT
        /// <summary>The operation has failed because CSV volume was not able to recover in time specified on this file object.</summary>
        error_cluster_csv_io_pause_timeout = ERROR_CLUSTER_CSV_IO_PAUSE_TIMEOUT,
#       else
#       endif

#       ifdef ERROR_NODE_NOT_ACTIVE_CLUSTER_MEMBER
        /// <summary>The operation failed because the requested node is not currently part of active cluster membership.</summary>
        error_node_not_active_cluster_member = ERROR_NODE_NOT_ACTIVE_CLUSTER_MEMBER,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_NOT_MONITORED
        /// <summary>The operation failed because the requested cluster resource is currently unmonitored.</summary>
        error_cluster_resource_not_monitored = ERROR_CLUSTER_RESOURCE_NOT_MONITORED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_DOES_NOT_SUPPORT_UNMONITORED
        /// <summary>The operation failed because a resource does not support running in an unmonitored state.</summary>
        error_cluster_resource_does_not_support_unmonitored = ERROR_CLUSTER_RESOURCE_DOES_NOT_SUPPORT_UNMONITORED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_RESOURCE_IS_REPLICATED
        /// <summary>The operation cannot be completed because a resource participates in replication.</summary>
        error_cluster_resource_is_replicated = ERROR_CLUSTER_RESOURCE_IS_REPLICATED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NODE_ISOLATED
        /// <summary>The operation failed because the requested cluster node has been isolated</summary>
        error_cluster_node_isolated = ERROR_CLUSTER_NODE_ISOLATED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_NODE_QUARANTINED
        /// <summary>The operation failed because the requested cluster node has been quarantined</summary>
        error_cluster_node_quarantined = ERROR_CLUSTER_NODE_QUARANTINED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_DATABASE_UPDATE_CONDITION_FAILED
        /// <summary>The operation failed because the specified database update condition was not met</summary>
        error_cluster_database_update_condition_failed = ERROR_CLUSTER_DATABASE_UPDATE_CONDITION_FAILED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_SPACE_DEGRADED
        /// <summary>A clustered space is in a degraded condition and the requested action cannot be completed at this time.</summary>
        error_cluster_space_degraded = ERROR_CLUSTER_SPACE_DEGRADED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_TOKEN_DELEGATION_NOT_SUPPORTED
        /// <summary>The operation failed because token delegation for this control is not supported.</summary>
        error_cluster_token_delegation_not_supported = ERROR_CLUSTER_TOKEN_DELEGATION_NOT_SUPPORTED,
#       else
#       endif

#       ifdef ERROR_CLUSTER_CSV_INVALID_HANDLE
        /// <summary>The operation has failed because CSV has invalidated this file object.</summary>
        error_cluster_csv_invalid_handle = ERROR_CLUSTER_CSV_INVALID_HANDLE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_CSV_SUPPORTED_ONLY_ON_COORDINATOR
        /// <summary>This operation is supported only on the CSV coordinator node.</summary>
        error_cluster_csv_supported_only_on_coordinator = ERROR_CLUSTER_CSV_SUPPORTED_ONLY_ON_COORDINATOR,
#       else
#       endif

#       ifdef ERROR_GROUPSET_NOT_AVAILABLE
        /// <summary>The cluster group set is not available for any further requests.</summary>
        error_groupset_not_available = ERROR_GROUPSET_NOT_AVAILABLE,
#       else
#       endif


#       ifdef ERROR_GROUPSET_NOT_FOUND
        /// <summary>The cluster group set could not be found.</summary>
        error_groupset_not_found = ERROR_GROUPSET_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_GROUPSET_CANT_PROVIDE
        /// <summary>The action cannot be completed at this time because the cluster group set would fall below quorum and not be able to act as a provider.</summary>
        error_groupset_cant_provide = ERROR_GROUPSET_CANT_PROVIDE,
#       else
#       endif

#       ifdef ERROR_CLUSTER_FAULT_DOMAIN_PARENT_NOT_FOUND
        /// <summary>The specified parent fault domain is not found.</summary>
        error_cluster_fault_domain_parent_not_found = ERROR_CLUSTER_FAULT_DOMAIN_PARENT_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_CLUSTER_FAULT_DOMAIN_INVALID_HIERARCHY
        /// <summary>The fault domain cannot be a child of the parent specified.</summary>
        error_cluster_fault_domain_invalid_hierarchy = ERROR_CLUSTER_FAULT_DOMAIN_INVALID_HIERARCHY,
#       else
#       endif

#       ifdef ERROR_CLUSTER_FAULT_DOMAIN_FAILED_S2D_VALIDATION
        /// <summary>Storage Spaces Direct has rejected the proposed fault domain changes because it impacts the fault tolerance of the storage.</summary>
        error_cluster_fault_domain_failed_s2d_validation = ERROR_CLUSTER_FAULT_DOMAIN_FAILED_S2D_VALIDATION,
#       else
#       endif


#       ifdef ERROR_CLUSTER_FAULT_DOMAIN_S2D_CONNECTIVITY_LOSS
        /// <summary>Storage Spaces Direct has rejected the proposed fault domain changes because it reduces the storage connected to the system.</summary>
        error_cluster_fault_domain_s2d_connectivity_loss = ERROR_CLUSTER_FAULT_DOMAIN_S2D_CONNECTIVITY_LOSS,
#       else
#       endif


#       ifdef ERROR_CLUSTER_INVALID_INFRASTRUCTURE_FILESERVER_NAME
        /// <summary>Cluster infrastructure file server creation failed because a valid non-empty file server name was not provided.</summary>
        error_cluster_invalid_infrastructure_fileserver_name = ERROR_CLUSTER_INVALID_INFRASTRUCTURE_FILESERVER_NAME,
#       else
#       endif


#       ifdef ERROR_CLUSTERSET_MANAGEMENT_CLUSTER_UNREACHABLE
        /// <summary>The action cannot be completed because the cluster set management cluster is unreachable.</summary>
        error_clusterset_management_cluster_unreachable = ERROR_CLUSTERSET_MANAGEMENT_CLUSTER_UNREACHABLE,
#       else
#       endif

#       ifdef ERROR_ENCRYPTION_FAILED
        /// <summary>The specified file could not be encrypted.</summary>
        error_encryption_failed = ERROR_ENCRYPTION_FAILED,
#       else
#       endif

#       ifdef ERROR_DECRYPTION_FAILED
        /// <summary>The specified file could not be decrypted.</summary>
        error_decryption_failed = ERROR_DECRYPTION_FAILED,
#       else
#       endif

#       ifdef ERROR_FILE_ENCRYPTED
        /// <summary>The specified file is encrypted and the user does not have the ability to decrypt it.</summary>
        error_file_encrypted = ERROR_FILE_ENCRYPTED,
#       else
#       endif

#       ifdef ERROR_NO_RECOVERY_POLICY
        /// <summary>There is no valid encryption recovery policy configured for this system.</summary>
        error_no_recovery_policy = ERROR_NO_RECOVERY_POLICY,
#       else
#       endif

#       ifdef ERROR_NO_EFS
        /// <summary>The required encryption driver is not loaded for this system.</summary>
        error_no_efs = ERROR_NO_EFS,
#       else
#       endif

#       ifdef ERROR_WRONG_EFS
        /// <summary>The file was encrypted with a different encryption driver than is currently loaded.</summary>
        error_wrong_efs = ERROR_WRONG_EFS,
#       else
#       endif

#       ifdef ERROR_NO_USER_KEYS
        /// <summary>There are no EFS keys defined for the user.</summary>
        error_no_user_keys = ERROR_NO_USER_KEYS,
#       else
#       endif

#       ifdef ERROR_FILE_NOT_ENCRYPTED
        /// <summary>The specified file is not encrypted.</summary>
        error_file_not_encrypted = ERROR_FILE_NOT_ENCRYPTED,
#       else
#       endif

#       ifdef ERROR_NOT_EXPORT_FORMAT
        /// <summary>The specified file is not in the defined EFS export format.</summary>
        error_not_export_format = ERROR_NOT_EXPORT_FORMAT,
#       else
#       endif

#       ifdef ERROR_FILE_READ_ONLY
        /// <summary>The specified file is read only.</summary>
        error_file_read_only = ERROR_FILE_READ_ONLY,
#       else
#       endif

#       ifdef ERROR_DIR_EFS_DISALLOWED
        /// <summary>The directory has been disabled for encryption.</summary>
        error_dir_efs_disallowed = ERROR_DIR_EFS_DISALLOWED,
#       else
#       endif

#       ifdef ERROR_EFS_SERVER_NOT_TRUSTED
        /// <summary>The server is not trusted for remote encryption operation.</summary>
        error_efs_server_not_trusted = ERROR_EFS_SERVER_NOT_TRUSTED,
#       else
#       endif

#       ifdef ERROR_BAD_RECOVERY_POLICY
        /// <summary>Recovery policy configured for this system contains invalid recovery certificate.</summary>
        error_bad_recovery_policy = ERROR_BAD_RECOVERY_POLICY,
#       else
#       endif

#       ifdef ERROR_EFS_ALG_BLOB_TOO_BIG
        /// <summary>The encryption algorithm used on the source file needs a bigger key buffer than the one on the destination file.</summary>
        error_efs_alg_blob_too_big = ERROR_EFS_ALG_BLOB_TOO_BIG,
#       else
#       endif

#       ifdef ERROR_VOLUME_NOT_SUPPORT_EFS
        /// <summary>The disk partition does not support file encryption.</summary>
        error_volume_not_support_efs = ERROR_VOLUME_NOT_SUPPORT_EFS,
#       else
#       endif

#       ifdef ERROR_EFS_DISABLED
        /// <summary>This machine is disabled for file encryption.</summary>
        error_efs_disabled = ERROR_EFS_DISABLED,
#       else
#       endif

#       ifdef ERROR_EFS_VERSION_NOT_SUPPORT
        /// <summary>A newer system is required to decrypt this encrypted file.</summary>
        error_efs_version_not_support = ERROR_EFS_VERSION_NOT_SUPPORT,
#       else
#       endif

#       ifdef ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE
        /// <summary>The remote server sent an invalid response for a file being opened with Client Side Encryption.</summary>
        error_cs_encryption_invalid_server_response = ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE,
#       else
#       endif

#       ifdef ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER
        /// <summary>Client Side Encryption is not supported by the remote server even though it claims to support it.</summary>
        error_cs_encryption_unsupported_server = ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER,
#       else
#       endif

#       ifdef ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE
        /// <summary>File is encrypted and should be opened in Client Side Encryption mode.</summary>
        error_cs_encryption_existing_encrypted_file = ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE,
#       else
#       endif

#       ifdef ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE
        /// <summary>A new encrypted file is being created and a $EFS needs to be provided.</summary>
        error_cs_encryption_new_encrypted_file = ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE,
#       else
#       endif

#       ifdef ERROR_CS_ENCRYPTION_FILE_NOT_CSE
        /// <summary>The SMB client requested a CSE FSCTL on a non-CSE file.</summary>
        error_cs_encryption_file_not_cse = ERROR_CS_ENCRYPTION_FILE_NOT_CSE,
#       else
#       endif

#       ifdef ERROR_ENCRYPTION_POLICY_DENIES_OPERATION
        /// <summary>The requested operation was blocked by policy. For more information, contact your system administrator.</summary>
        error_encryption_policy_denies_operation = ERROR_ENCRYPTION_POLICY_DENIES_OPERATION,
#       else
#       endif

#       ifdef ERROR_WIP_ENCRYPTION_FAILED
        /// <summary>The specified file could not be encrypted with Windows Information Protection.</summary>
        error_wip_encryption_failed = ERROR_WIP_ENCRYPTION_FAILED,
#       else
#       endif

#       ifdef ERROR_NO_BROWSER_SERVERS_FOUND
        /// <summary>The list of servers for this workgroup is not currently available</summary>
        error_no_browser_servers_found = ERROR_NO_BROWSER_SERVERS_FOUND,
#       else
#       endif

#       ifdef SCHED_E_SERVICE_NOT_LOCALSYSTEM
        /// <summary>The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts.</summary>
        sched_e_service_not_localsystem = SCHED_E_SERVICE_NOT_LOCALSYSTEM,
#       else
#       endif

#       ifdef ERROR_LOG_SECTOR_INVALID
        /// <summary>Log service encountered an invalid log sector.</summary>
        error_log_sector_invalid = ERROR_LOG_SECTOR_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_SECTOR_PARITY_INVALID
        /// <summary>Log service encountered a log sector with invalid block parity.</summary>
        error_log_sector_parity_invalid = ERROR_LOG_SECTOR_PARITY_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_SECTOR_REMAPPED
        /// <summary>Log service encountered a remapped log sector.</summary>
        error_log_sector_remapped = ERROR_LOG_SECTOR_REMAPPED,
#       else
#       endif

#       ifdef ERROR_LOG_BLOCK_INCOMPLETE
        /// <summary>Log service encountered a partial or incomplete log block.</summary>
        error_log_block_incomplete = ERROR_LOG_BLOCK_INCOMPLETE,
#       else
#       endif

#       ifdef ERROR_LOG_INVALID_RANGE
        /// <summary>Log service encountered an attempt access data outside the active log range.</summary>
        error_log_invalid_range = ERROR_LOG_INVALID_RANGE,
#       else
#       endif

#       ifdef ERROR_LOG_BLOCKS_EXHAUSTED
        /// <summary>Log service user marshalling buffers are exhausted.</summary>
        error_log_blocks_exhausted = ERROR_LOG_BLOCKS_EXHAUSTED,
#       else
#       endif

#       ifdef ERROR_LOG_READ_CONTEXT_INVALID
        /// <summary>Log service encountered an attempt read from a marshalling area with an invalid read context.</summary>
        error_log_read_context_invalid = ERROR_LOG_READ_CONTEXT_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_RESTART_INVALID
        /// <summary>Log service encountered an invalid log restart area.</summary>
        error_log_restart_invalid = ERROR_LOG_RESTART_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_BLOCK_VERSION
        /// <summary>Log service encountered an invalid log block version.</summary>
        error_log_block_version = ERROR_LOG_BLOCK_VERSION,
#       else
#       endif

#       ifdef ERROR_LOG_BLOCK_INVALID
        /// <summary>Log service encountered an invalid log block.</summary>
        error_log_block_invalid = ERROR_LOG_BLOCK_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_READ_MODE_INVALID
        /// <summary>Log service encountered an attempt to read the log with an invalid read mode.</summary>
        error_log_read_mode_invalid = ERROR_LOG_READ_MODE_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_NO_RESTART
        /// <summary>Log service encountered a log stream with no restart area.</summary>
        error_log_no_restart = ERROR_LOG_NO_RESTART,
#       else
#       endif

#       ifdef ERROR_LOG_METADATA_CORRUPT
        /// <summary>Log service encountered a corrupted metadata file.</summary>
        error_log_metadata_corrupt = ERROR_LOG_METADATA_CORRUPT,
#       else
#       endif

#       ifdef ERROR_LOG_METADATA_INVALID
        /// <summary>Log service encountered a metadata file that could not be created by the log file system.</summary>
        error_log_metadata_invalid = ERROR_LOG_METADATA_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_METADATA_INCONSISTENT
        /// <summary>Log service encountered a metadata file with inconsistent data.</summary>
        error_log_metadata_inconsistent = ERROR_LOG_METADATA_INCONSISTENT,
#       else
#       endif

#       ifdef ERROR_LOG_RESERVATION_INVALID
        /// <summary>Log service encountered an attempt to erroneous allocate or dispose reservation space.</summary>
        error_log_reservation_invalid = ERROR_LOG_RESERVATION_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_CANT_DELETE
        /// <summary>Log service cannot delete log file or file system container.</summary>
        error_log_cant_delete = ERROR_LOG_CANT_DELETE,
#       else
#       endif

#       ifdef ERROR_LOG_CONTAINER_LIMIT_EXCEEDED
        /// <summary>Log service has reached the maximum allowable containers allocated to a log file.</summary>
        error_log_container_limit_exceeded = ERROR_LOG_CONTAINER_LIMIT_EXCEEDED,
#       else
#       endif

#       ifdef ERROR_LOG_START_OF_LOG
        /// <summary>Log service has attempted to read or write backward past the start of the log.</summary>
        error_log_start_of_log = ERROR_LOG_START_OF_LOG,
#       else
#       endif

#       ifdef ERROR_LOG_POLICY_ALREADY_INSTALLED
        /// <summary>Log policy could not be installed because a policy of the same type is already present.</summary>
        error_log_policy_already_installed = ERROR_LOG_POLICY_ALREADY_INSTALLED,
#       else
#       endif

#       ifdef ERROR_LOG_POLICY_NOT_INSTALLED
        /// <summary>Log policy in question was not installed at the time of the request.</summary>
        error_log_policy_not_installed = ERROR_LOG_POLICY_NOT_INSTALLED,
#       else
#       endif

#       ifdef ERROR_LOG_POLICY_INVALID
        /// <summary>The installed set of policies on the log is invalid.</summary>
        error_log_policy_invalid = ERROR_LOG_POLICY_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_POLICY_CONFLICT
        /// <summary>A policy on the log in question prevented the operation from completing.</summary>
        error_log_policy_conflict = ERROR_LOG_POLICY_CONFLICT,
#       else
#       endif

#       ifdef ERROR_LOG_PINNED_ARCHIVE_TAIL
        /// <summary>Log space cannot be reclaimed because the log is pinned by the archive tail.</summary>
        error_log_pinned_archive_tail = ERROR_LOG_PINNED_ARCHIVE_TAIL,
#       else
#       endif

#       ifdef ERROR_LOG_RECORD_NONEXISTENT
        /// <summary>Log record is not a record in the log file.</summary>
        error_log_record_nonexistent = ERROR_LOG_RECORD_NONEXISTENT,
#       else
#       endif

#       ifdef ERROR_LOG_RECORDS_RESERVED_INVALID
        /// <summary>Number of reserved log records or the adjustment of the number of reserved log records is invalid.</summary>
        error_log_records_reserved_invalid = ERROR_LOG_RECORDS_RESERVED_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_SPACE_RESERVED_INVALID
        /// <summary>Reserved log space or the adjustment of the log space is invalid.</summary>
        error_log_space_reserved_invalid = ERROR_LOG_SPACE_RESERVED_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_TAIL_INVALID
        /// <summary>An new or existing archive tail or base of the active log is invalid.</summary>
        error_log_tail_invalid = ERROR_LOG_TAIL_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_FULL
        /// <summary>Log space is exhausted.</summary>
        error_log_full = ERROR_LOG_FULL,
#       else
#       endif

#       ifdef ERROR_COULD_NOT_RESIZE_LOG
        /// <summary>The log could not be set to the requested size.</summary>
        error_could_not_resize_log = ERROR_COULD_NOT_RESIZE_LOG,
#       else
#       endif

#       ifdef ERROR_LOG_MULTIPLEXED
        /// <summary>Log is multiplexed, no direct writes to the physical log is allowed.</summary>
        error_log_multiplexed = ERROR_LOG_MULTIPLEXED,
#       else
#       endif

#       ifdef ERROR_LOG_DEDICATED
        /// <summary>The operation failed because the log is a dedicated log.</summary>
        error_log_dedicated = ERROR_LOG_DEDICATED,
#       else
#       endif

#       ifdef ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS
        /// <summary>The operation requires an archive context.</summary>
        error_log_archive_not_in_progress = ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_LOG_ARCHIVE_IN_PROGRESS
        /// <summary>Log archival is in progress.</summary>
        error_log_archive_in_progress = ERROR_LOG_ARCHIVE_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_LOG_EPHEMERAL
        /// <summary>The operation requires a non-ephemeral log, but the log is ephemeral.</summary>
        error_log_ephemeral = ERROR_LOG_EPHEMERAL,
#       else
#       endif

#       ifdef ERROR_LOG_NOT_ENOUGH_CONTAINERS
        /// <summary>The log must have at least two containers before it can be read from or written to.</summary>
        error_log_not_enough_containers = ERROR_LOG_NOT_ENOUGH_CONTAINERS,
#       else
#       endif

#       ifdef ERROR_LOG_CLIENT_ALREADY_REGISTERED
        /// <summary>A log client has already registered on the stream.</summary>
        error_log_client_already_registered = ERROR_LOG_CLIENT_ALREADY_REGISTERED,
#       else
#       endif

#       ifdef ERROR_LOG_CLIENT_NOT_REGISTERED
        /// <summary>A log client has not been registered on the stream.</summary>
        error_log_client_not_registered = ERROR_LOG_CLIENT_NOT_REGISTERED,
#       else
#       endif

#       ifdef ERROR_LOG_FULL_HANDLER_IN_PROGRESS
        /// <summary>A request has already been made to handle the log full condition.</summary>
        error_log_full_handler_in_progress = ERROR_LOG_FULL_HANDLER_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_LOG_CONTAINER_READ_FAILED
        /// <summary>Log service encountered an error when attempting to read from a log container.</summary>
        error_log_container_read_failed = ERROR_LOG_CONTAINER_READ_FAILED,
#       else
#       endif

#       ifdef ERROR_LOG_CONTAINER_WRITE_FAILED
        /// <summary>Log service encountered an error when attempting to write to a log container.</summary>
        error_log_container_write_failed = ERROR_LOG_CONTAINER_WRITE_FAILED,
#       else
#       endif

#       ifdef ERROR_LOG_CONTAINER_OPEN_FAILED
        /// <summary>Log service encountered an error when attempting open a log container.</summary>
        error_log_container_open_failed = ERROR_LOG_CONTAINER_OPEN_FAILED,
#       else
#       endif

#       ifdef ERROR_LOG_CONTAINER_STATE_INVALID
        /// <summary>Log service encountered an invalid container state when attempting a requested action.</summary>
        error_log_container_state_invalid = ERROR_LOG_CONTAINER_STATE_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_STATE_INVALID
        /// <summary>Log service is not in the correct state to perform a requested action.</summary>
        error_log_state_invalid = ERROR_LOG_STATE_INVALID,
#       else
#       endif

#       ifdef ERROR_LOG_PINNED
        /// <summary>Log space cannot be reclaimed because the log is pinned.</summary>
        error_log_pinned = ERROR_LOG_PINNED,
#       else
#       endif

#       ifdef ERROR_LOG_METADATA_FLUSH_FAILED
        /// <summary>Log metadata flush failed.</summary>
        error_log_metadata_flush_failed = ERROR_LOG_METADATA_FLUSH_FAILED,
#       else
#       endif

#       ifdef ERROR_LOG_INCONSISTENT_SECURITY
        /// <summary>Security on the log and its containers is inconsistent.</summary>
        error_log_inconsistent_security = ERROR_LOG_INCONSISTENT_SECURITY,
#       else
#       endif

#       ifdef ERROR_LOG_APPENDED_FLUSH_FAILED
        /// <summary>Records were appended to the log or reservation changes were made, but the log could not be flushed.</summary>
        error_log_appended_flush_failed = ERROR_LOG_APPENDED_FLUSH_FAILED,
#       else
#       endif

#       ifdef ERROR_LOG_PINNED_RESERVATION
        /// <summary>The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available.</summary>
        error_log_pinned_reservation = ERROR_LOG_PINNED_RESERVATION,
#       else
#       endif

#       ifdef ERROR_INVALID_TRANSACTION
        /// <summary>The transaction handle associated with this operation is not valid.</summary>
        error_invalid_transaction = ERROR_INVALID_TRANSACTION,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_NOT_ACTIVE
        /// <summary>The requested operation was made in the context of a transaction that is no longer active.</summary>
        error_transaction_not_active = ERROR_TRANSACTION_NOT_ACTIVE,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_REQUEST_NOT_VALID
        /// <summary>The requested operation is not valid on the Transaction object in its current state.</summary>
        error_transaction_request_not_valid = ERROR_TRANSACTION_REQUEST_NOT_VALID,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_NOT_REQUESTED
        /// <summary>The caller has called a response API, but the response is not expected because the TM did not issue the corresponding request to the caller.</summary>
        error_transaction_not_requested = ERROR_TRANSACTION_NOT_REQUESTED,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_ALREADY_ABORTED
        /// <summary>It is too late to perform the requested operation, since the Transaction has already been aborted.</summary>
        error_transaction_already_aborted = ERROR_TRANSACTION_ALREADY_ABORTED,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_ALREADY_COMMITTED
        /// <summary>It is too late to perform the requested operation, since the Transaction has already been committed.</summary>
        error_transaction_already_committed = ERROR_TRANSACTION_ALREADY_COMMITTED,
#       else
#       endif

#       ifdef ERROR_TM_INITIALIZATION_FAILED
        /// <summary>The Transaction Manager was unable to be successfully initialized. Transacted operations are not supported.</summary>
        error_tm_initialization_failed = ERROR_TM_INITIALIZATION_FAILED,
#       else
#       endif

#       ifdef ERROR_RESOURCEMANAGER_READ_ONLY
        /// <summary>The specified ResourceManager made no changes or updates to the resource under this transaction.</summary>
        error_resourcemanager_read_only = ERROR_RESOURCEMANAGER_READ_ONLY,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_NOT_JOINED
        /// <summary>The resource manager has attempted to prepare a transaction that it has not successfully joined.</summary>
        error_transaction_not_joined = ERROR_TRANSACTION_NOT_JOINED,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_SUPERIOR_EXISTS
        /// <summary>The Transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allow.</summary>
        error_transaction_superior_exists = ERROR_TRANSACTION_SUPERIOR_EXISTS,
#       else
#       endif

#       ifdef ERROR_CRM_PROTOCOL_ALREADY_EXISTS
        /// <summary>The RM tried to register a protocol that already exists.</summary>
        error_crm_protocol_already_exists = ERROR_CRM_PROTOCOL_ALREADY_EXISTS,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_PROPAGATION_FAILED
        /// <summary>The attempt to propagate the Transaction failed.</summary>
        error_transaction_propagation_failed = ERROR_TRANSACTION_PROPAGATION_FAILED,
#       else
#       endif

#       ifdef ERROR_CRM_PROTOCOL_NOT_FOUND
        /// <summary>The requested propagation protocol was not registered as a CRM.</summary>
        error_crm_protocol_not_found = ERROR_CRM_PROTOCOL_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER
        /// <summary>The buffer passed in to PushTransaction or PullTransaction is not in a valid format.</summary>
        error_transaction_invalid_marshall_buffer = ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER,
#       else
#       endif

#       ifdef ERROR_CURRENT_TRANSACTION_NOT_VALID
        /// <summary>The current transaction context associated with the thread is not a valid handle to a transaction object.</summary>
        error_current_transaction_not_valid = ERROR_CURRENT_TRANSACTION_NOT_VALID,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_NOT_FOUND
        /// <summary>The specified Transaction object could not be opened, because it was not found.</summary>
        error_transaction_not_found = ERROR_TRANSACTION_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_RESOURCEMANAGER_NOT_FOUND
        /// <summary>The specified ResourceManager object could not be opened, because it was not found.</summary>
        error_resourcemanager_not_found = ERROR_RESOURCEMANAGER_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_ENLISTMENT_NOT_FOUND
        /// <summary>The specified Enlistment object could not be opened, because it was not found.</summary>
        error_enlistment_not_found = ERROR_ENLISTMENT_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_TRANSACTIONMANAGER_NOT_FOUND
        /// <summary>The specified TransactionManager object could not be opened, because it was not found.</summary>
        error_transactionmanager_not_found = ERROR_TRANSACTIONMANAGER_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_TRANSACTIONMANAGER_NOT_ONLINE
        /// <summary>The object specified could not be created or opened, because its associated TransactionManager is not online.  The TransactionManager must be brought fully Online by calling RecoverTransactionManager to recover to the end of its LogFile before objects in its Transaction or ResourceManager namespaces can be opened.  In addition, errors in writing records to its LogFile can cause a TransactionManager to go offline.</summary>
        error_transactionmanager_not_online = ERROR_TRANSACTIONMANAGER_NOT_ONLINE,
#       else
#       endif

#       ifdef ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION
        /// <summary>The specified TransactionManager was unable to create the objects contained in its logfile in the Ob namespace. Therefore, the TransactionManager was unable to recover.</summary>
        error_transactionmanager_recovery_name_collision = ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_NOT_ROOT
        /// <summary>The call to create a superior Enlistment on this Transaction object could not be completed, because the Transaction object specified for the enlistment is a subordinate branch of the Transaction. Only the root of the Transaction can be enlisted on as a superior.</summary>
        error_transaction_not_root = ERROR_TRANSACTION_NOT_ROOT,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_OBJECT_EXPIRED
        /// <summary>Because the associated transaction manager or resource manager has been closed, the handle is no longer valid.</summary>
        error_transaction_object_expired = ERROR_TRANSACTION_OBJECT_EXPIRED,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED
        /// <summary>The specified operation could not be performed on this Superior enlistment, because the enlistment was not created with the corresponding completion response in the NotificationMask.</summary>
        error_transaction_response_not_enlisted = ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_RECORD_TOO_LONG
        /// <summary>The specified operation could not be performed, because the record that would be logged was too long. This can occur because of two conditions: either there are too many Enlistments on this Transaction, or the combined RecoveryInformation being logged on behalf of those Enlistments is too long.</summary>
        error_transaction_record_too_long = ERROR_TRANSACTION_RECORD_TOO_LONG,
#       else
#       endif

#       ifdef ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED
        /// <summary>Implicit transaction are not supported.</summary>
        error_implicit_transaction_not_supported = ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_INTEGRITY_VIOLATED
        /// <summary>The kernel transaction manager had to abort or forget the transaction because it blocked forward progress.</summary>
        error_transaction_integrity_violated = ERROR_TRANSACTION_INTEGRITY_VIOLATED,
#       else
#       endif

#       ifdef ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH
        /// <summary>The TransactionManager identity that was supplied did not match the one recorded in the TransactionManager's log file.</summary>
        error_transactionmanager_identity_mismatch = ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH,
#       else
#       endif

#       ifdef ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT
        /// <summary>This snapshot operation cannot continue because a transactional resource manager cannot be frozen in its current state.  Please try again.</summary>
        error_rm_cannot_be_frozen_for_snapshot = ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_MUST_WRITETHROUGH
        /// <summary>The transaction cannot be enlisted on with the specified EnlistmentMask, because the transaction has already completed the PrePrepare phase.  In order to ensure correctness, the ResourceManager must switch to a write-through mode and cease caching data within this transaction.  Enlisting for only subsequent transaction phases may still succeed.</summary>
        error_transaction_must_writethrough = ERROR_TRANSACTION_MUST_WRITETHROUGH,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_NO_SUPERIOR
        /// <summary>The transaction does not have a superior enlistment.</summary>
        error_transaction_no_superior = ERROR_TRANSACTION_NO_SUPERIOR,
#       else
#       endif

#       ifdef ERROR_HEURISTIC_DAMAGE_POSSIBLE
        /// <summary>The attempt to commit the Transaction completed, but it is possible that some portion of the transaction tree did not commit successfully due to heuristics.  Therefore it is possible that some data modified in the transaction may not have committed, resulting in transactional inconsistency.  If possible, check the consistency of the associated data.</summary>
        error_heuristic_damage_possible = ERROR_HEURISTIC_DAMAGE_POSSIBLE,
#       else
#       endif

#       ifdef ERROR_TRANSACTIONAL_CONFLICT
        /// <summary>The function attempted to use a name that is reserved for use by another transaction.</summary>
        error_transactional_conflict = ERROR_TRANSACTIONAL_CONFLICT,
#       else
#       endif

#       ifdef ERROR_RM_NOT_ACTIVE
        /// <summary>Transaction support within the specified resource manager is not started or was shut down due to an error.</summary>
        error_rm_not_active = ERROR_RM_NOT_ACTIVE,
#       else
#       endif

#       ifdef ERROR_RM_METADATA_CORRUPT
        /// <summary>The metadata of the RM has been corrupted. The RM will not function.</summary>
        error_rm_metadata_corrupt = ERROR_RM_METADATA_CORRUPT,
#       else
#       endif

#       ifdef ERROR_DIRECTORY_NOT_RM
        /// <summary>The specified directory does not contain a resource manager.</summary>
        error_directory_not_rm = ERROR_DIRECTORY_NOT_RM,
#       else
#       endif

#       ifdef ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE
        /// <summary>The remote server or share does not support transacted file operations.</summary>
        error_transactions_unsupported_remote = ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE,
#       else
#       endif

#       ifdef ERROR_LOG_RESIZE_INVALID_SIZE
        /// <summary>The requested log size is invalid.</summary>
        error_log_resize_invalid_size = ERROR_LOG_RESIZE_INVALID_SIZE,
#       else
#       endif

#       ifdef ERROR_OBJECT_NO_LONGER_EXISTS
        /// <summary>The object (file, stream, link) corresponding to the handle has been deleted by a Transaction Savepoint Rollback.</summary>
        error_object_no_longer_exists = ERROR_OBJECT_NO_LONGER_EXISTS,
#       else
#       endif

#       ifdef ERROR_STREAM_MINIVERSION_NOT_FOUND
        /// <summary>The specified file miniversion was not found for this transacted file open.</summary>
        error_stream_miniversion_not_found = ERROR_STREAM_MINIVERSION_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_STREAM_MINIVERSION_NOT_VALID
        /// <summary>The specified file miniversion was found but has been invalidated. Most likely cause is a transaction savepoint rollback.</summary>
        error_stream_miniversion_not_valid = ERROR_STREAM_MINIVERSION_NOT_VALID,
#       else
#       endif

#       ifdef ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION
        /// <summary>A miniversion may only be opened in the context of the transaction that created it.</summary>
        error_miniversion_inaccessible_from_specified_transaction = ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION,
#       else
#       endif

#       ifdef ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT
        /// <summary>It is not possible to open a miniversion with modify access.</summary>
        error_cant_open_miniversion_with_modify_intent = ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT,
#       else
#       endif

#       ifdef ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS
        /// <summary>It is not possible to create any more miniversions for this stream.</summary>
        error_cant_create_more_stream_miniversions = ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS,
#       else
#       endif

#       ifdef ERROR_REMOTE_FILE_VERSION_MISMATCH
        /// <summary>The remote server sent mismatching version number or Fid for a file opened with transactions.</summary>
        error_remote_file_version_mismatch = ERROR_REMOTE_FILE_VERSION_MISMATCH,
#       else
#       endif

#       ifdef ERROR_HANDLE_NO_LONGER_VALID
        /// <summary>The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint.</summary>
        error_handle_no_longer_valid = ERROR_HANDLE_NO_LONGER_VALID,
#       else
#       endif

#       ifdef ERROR_NO_TXF_METADATA
        /// <summary>There is no transaction metadata on the file.</summary>
        error_no_txf_metadata = ERROR_NO_TXF_METADATA,
#       else
#       endif

#       ifdef ERROR_LOG_CORRUPTION_DETECTED
        /// <summary>The log data is corrupt.</summary>
        error_log_corruption_detected = ERROR_LOG_CORRUPTION_DETECTED,
#       else
#       endif

#       ifdef ERROR_CANT_RECOVER_WITH_HANDLE_OPEN
        /// <summary>The file can't be recovered because there is a handle still open on it.</summary>
        error_cant_recover_with_handle_open = ERROR_CANT_RECOVER_WITH_HANDLE_OPEN,
#       else
#       endif

#       ifdef ERROR_RM_DISCONNECTED
        /// <summary>The transaction outcome is unavailable because the resource manager responsible for it has disconnected.</summary>
        error_rm_disconnected = ERROR_RM_DISCONNECTED,
#       else
#       endif

#       ifdef ERROR_ENLISTMENT_NOT_SUPERIOR
        /// <summary>The request was rejected because the enlistment in question is not a superior enlistment.</summary>
        error_enlistment_not_superior = ERROR_ENLISTMENT_NOT_SUPERIOR,
#       else
#       endif

#       ifdef ERROR_RECOVERY_NOT_NEEDED
        /// <summary>The transactional resource manager is already consistent. Recovery is not needed.</summary>
        error_recovery_not_needed = ERROR_RECOVERY_NOT_NEEDED,
#       else
#       endif

#       ifdef ERROR_RM_ALREADY_STARTED
        /// <summary>The transactional resource manager has already been started.</summary>
        error_rm_already_started = ERROR_RM_ALREADY_STARTED,
#       else
#       endif

#       ifdef ERROR_FILE_IDENTITY_NOT_PERSISTENT
        /// <summary>The file cannot be opened transactionally, because its identity depends on the outcome of an unresolved transaction.</summary>
        error_file_identity_not_persistent = ERROR_FILE_IDENTITY_NOT_PERSISTENT,
#       else
#       endif

#       ifdef ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY
        /// <summary>The operation cannot be performed because another transaction is depending on the fact that this property will not change.</summary>
        error_cant_break_transactional_dependency = ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY,
#       else
#       endif

#       ifdef ERROR_CANT_CROSS_RM_BOUNDARY
        /// <summary>The operation would involve a single file with two transactional resource managers and is therefore not allowed.</summary>
        error_cant_cross_rm_boundary = ERROR_CANT_CROSS_RM_BOUNDARY,
#       else
#       endif

#       ifdef ERROR_TXF_DIR_NOT_EMPTY
        /// <summary>The $Txf directory must be empty for this operation to succeed.</summary>
        error_txf_dir_not_empty = ERROR_TXF_DIR_NOT_EMPTY,
#       else
#       endif

#       ifdef ERROR_INDOUBT_TRANSACTIONS_EXIST
        /// <summary>The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed.</summary>
        error_indoubt_transactions_exist = ERROR_INDOUBT_TRANSACTIONS_EXIST,
#       else
#       endif

#       ifdef ERROR_TM_VOLATILE
        /// <summary>The operation could not be completed because the transaction manager does not have a log.</summary>
        error_tm_volatile = ERROR_TM_VOLATILE,
#       else
#       endif

#       ifdef ERROR_ROLLBACK_TIMER_EXPIRED
        /// <summary>A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution.</summary>
        error_rollback_timer_expired = ERROR_ROLLBACK_TIMER_EXPIRED,
#       else
#       endif

#       ifdef ERROR_TXF_ATTRIBUTE_CORRUPT
        /// <summary>The transactional metadata attribute on the file or directory is corrupt and unreadable.</summary>
        error_txf_attribute_corrupt = ERROR_TXF_ATTRIBUTE_CORRUPT,
#       else
#       endif

#       ifdef ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION
        /// <summary>The encryption operation could not be completed because a transaction is active.</summary>
        error_efs_not_allowed_in_transaction = ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION,
#       else
#       endif

#       ifdef ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED
        /// <summary>This object is not allowed to be opened in a transaction.</summary>
        error_transactional_open_not_allowed = ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED,
#       else
#       endif

#       ifdef ERROR_LOG_GROWTH_FAILED
        /// <summary>An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log.</summary>
        error_log_growth_failed = ERROR_LOG_GROWTH_FAILED,
#       else
#       endif

#       ifdef ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE
        /// <summary>Memory mapping (creating a mapped section) a remote file under a transaction is not supported.</summary>
        error_transacted_mapping_unsupported_remote = ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE,
#       else
#       endif

#       ifdef ERROR_TXF_METADATA_ALREADY_PRESENT
        /// <summary>Transaction metadata is already present on this file and cannot be superseded.</summary>
        error_txf_metadata_already_present = ERROR_TXF_METADATA_ALREADY_PRESENT,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET
        /// <summary>A transaction scope could not be entered because the scope handler has not been initialized.</summary>
        error_transaction_scope_callbacks_not_set = ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_REQUIRED_PROMOTION
        /// <summary>Promotion was required in order to allow the resource manager to enlist, but the transaction was set to disallow it.</summary>
        error_transaction_required_promotion = ERROR_TRANSACTION_REQUIRED_PROMOTION,
#       else
#       endif

#       ifdef ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION
        /// <summary>This file is open for modification in an unresolved transaction and may be opened for execute only by a transacted reader.</summary>
        error_cannot_execute_file_in_transaction = ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION,
#       else
#       endif

#       ifdef ERROR_TRANSACTIONS_NOT_FROZEN
        /// <summary>The request to thaw frozen transactions was ignored because transactions had not previously been frozen.</summary>
        error_transactions_not_frozen = ERROR_TRANSACTIONS_NOT_FROZEN,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_FREEZE_IN_PROGRESS
        /// <summary>Transactions cannot be frozen because a freeze is already in progress.</summary>
        error_transaction_freeze_in_progress = ERROR_TRANSACTION_FREEZE_IN_PROGRESS,
#       else
#       endif

#       ifdef ERROR_NOT_SNAPSHOT_VOLUME
        /// <summary>The target volume is not a snapshot volume. This operation is only valid on a volume mounted as a snapshot.</summary>
        error_not_snapshot_volume = ERROR_NOT_SNAPSHOT_VOLUME,
#       else
#       endif

#       ifdef ERROR_NO_SAVEPOINT_WITH_OPEN_FILES
        /// <summary>The savepoint operation failed because files are open on the transaction. This is not permitted.</summary>
        error_no_savepoint_with_open_files = ERROR_NO_SAVEPOINT_WITH_OPEN_FILES,
#       else
#       endif

#       ifdef ERROR_DATA_LOST_REPAIR
        /// <summary>Windows has discovered corruption in a file, and that file has since been repaired. Data loss may have occurred.</summary>
        error_data_lost_repair = ERROR_DATA_LOST_REPAIR,
#       else
#       endif

#       ifdef ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION
        /// <summary>The sparse operation could not be completed because a transaction is active on the file.</summary>
        error_sparse_not_allowed_in_transaction = ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION,
#       else
#       endif

#       ifdef ERROR_TM_IDENTITY_MISMATCH
        /// <summary>The call to create a TransactionManager object failed because the Tm Identity stored in the logfile does not match the Tm Identity that was passed in as an argument.</summary>
        error_tm_identity_mismatch = ERROR_TM_IDENTITY_MISMATCH,
#       else
#       endif

#       ifdef ERROR_FLOATED_SECTION
        /// <summary>I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data.</summary>
        error_floated_section = ERROR_FLOATED_SECTION,
#       else
#       endif

#       ifdef ERROR_CANNOT_ACCEPT_TRANSACTED_WORK
        /// <summary>The transactional resource manager cannot currently accept transacted work due to a transient condition such as low resources.</summary>
        error_cannot_accept_transacted_work = ERROR_CANNOT_ACCEPT_TRANSACTED_WORK,
#       else
#       endif

#       ifdef ERROR_CANNOT_ABORT_TRANSACTIONS
        /// <summary>The transactional resource manager had too many transactions outstanding that could not be aborted. The transactional resource manger has been shut down.</summary>
        error_cannot_abort_transactions = ERROR_CANNOT_ABORT_TRANSACTIONS,
#       else
#       endif

#       ifdef ERROR_BAD_CLUSTERS
        /// <summary>The operation could not be completed due to bad clusters on disk.</summary>
        error_bad_clusters = ERROR_BAD_CLUSTERS,
#       else
#       endif

#       ifdef ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION
        /// <summary>The compression operation could not be completed because a transaction is active on the file.</summary>
        error_compression_not_allowed_in_transaction = ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION,
#       else
#       endif

#       ifdef ERROR_VOLUME_DIRTY
        /// <summary>The operation could not be completed because the volume is dirty. Please run chkdsk and try again.</summary>
        error_volume_dirty = ERROR_VOLUME_DIRTY,
#       else
#       endif

#       ifdef ERROR_NO_LINK_TRACKING_IN_TRANSACTION
        /// <summary>The link tracking operation could not be completed because a transaction is active.</summary>
        error_no_link_tracking_in_transaction = ERROR_NO_LINK_TRACKING_IN_TRANSACTION,
#       else
#       endif

#       ifdef ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION
        /// <summary>This operation cannot be performed in a transaction.</summary>
        error_operation_not_supported_in_transaction = ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION,
#       else
#       endif

#       ifdef ERROR_EXPIRED_HANDLE
        /// <summary>The handle is no longer properly associated with its transaction.  It may have been opened in a transactional resource manager that was subsequently forced to restart.  Please close the handle and open a new one.</summary>
        error_expired_handle = ERROR_EXPIRED_HANDLE,
#       else
#       endif

#       ifdef ERROR_TRANSACTION_NOT_ENLISTED
        /// <summary>The specified operation could not be performed because the resource manager is not enlisted in the transaction.</summary>
        error_transaction_not_enlisted = ERROR_TRANSACTION_NOT_ENLISTED,
#       else
#       endif

#       ifdef ERROR_CTX_WINSTATION_NAME_INVALID
        /// <summary>The specified session name is invalid.</summary>
        error_ctx_winstation_name_invalid = ERROR_CTX_WINSTATION_NAME_INVALID,
#       else
#       endif

#       ifdef ERROR_CTX_INVALID_PD
        /// <summary>The specified protocol driver is invalid.</summary>
        error_ctx_invalid_pd = ERROR_CTX_INVALID_PD,
#       else
#       endif

#       ifdef ERROR_CTX_PD_NOT_FOUND
        /// <summary>The specified protocol driver was not found in the system path.</summary>
        error_ctx_pd_not_found = ERROR_CTX_PD_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_CTX_WD_NOT_FOUND
        /// <summary>The specified terminal connection driver was not found in the system path.</summary>
        error_ctx_wd_not_found = ERROR_CTX_WD_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY
        /// <summary>A registry key for event logging could not be created for this session.</summary>
        error_ctx_cannot_make_eventlog_entry = ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY,
#       else
#       endif

#       ifdef ERROR_CTX_SERVICE_NAME_COLLISION
        /// <summary>A service with the same name already exists on the system.</summary>
        error_ctx_service_name_collision = ERROR_CTX_SERVICE_NAME_COLLISION,
#       else
#       endif

#       ifdef ERROR_CTX_CLOSE_PENDING
        /// <summary>A close operation is pending on the session.</summary>
        error_ctx_close_pending = ERROR_CTX_CLOSE_PENDING,
#       else
#       endif

#       ifdef ERROR_CTX_NO_OUTBUF
        /// <summary>There are no free output buffers available.</summary>
        error_ctx_no_outbuf = ERROR_CTX_NO_OUTBUF,
#       else
#       endif

#       ifdef ERROR_CTX_MODEM_INF_NOT_FOUND
        /// <summary>The MODEM.INF file was not found.</summary>
        error_ctx_modem_inf_not_found = ERROR_CTX_MODEM_INF_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_CTX_INVALID_MODEMNAME
        /// <summary>The modem name was not found in MODEM.INF.</summary>
        error_ctx_invalid_modemname = ERROR_CTX_INVALID_MODEMNAME,
#       else
#       endif

#       ifdef ERROR_CTX_MODEM_RESPONSE_ERROR
        /// <summary>The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem.</summary>
        error_ctx_modem_response_error = ERROR_CTX_MODEM_RESPONSE_ERROR,
#       else
#       endif

#       ifdef ERROR_CTX_MODEM_RESPONSE_TIMEOUT
        /// <summary>The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on.</summary>
        error_ctx_modem_response_timeout = ERROR_CTX_MODEM_RESPONSE_TIMEOUT,
#       else
#       endif
            
#       ifdef ERROR_CTX_MODEM_RESPONSE_NO_CARRIER
        /// <summary>Carrier detect has failed or carrier has been dropped due to disconnect.</summary>
        error_ctx_modem_response_no_carrier = ERROR_CTX_MODEM_RESPONSE_NO_CARRIER,
#       else
#       endif

#       ifdef ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE
        /// <summary>Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional.</summary>
        error_ctx_modem_response_no_dialtone = ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE,
#       else
#       endif

#       ifdef ERROR_CTX_MODEM_RESPONSE_BUSY
        /// <summary>Busy signal detected at remote site on callback.</summary>
        error_ctx_modem_response_busy = ERROR_CTX_MODEM_RESPONSE_BUSY,
#       else
#       endif

#       ifdef ERROR_CTX_MODEM_RESPONSE_VOICE
        /// <summary>Voice detected at remote site on callback.</summary>
        error_ctx_modem_response_voice = ERROR_CTX_MODEM_RESPONSE_VOICE,
#       else
#       endif

#       ifdef ERROR_CTX_TD_ERROR
        /// <summary>Transport driver error</summary>
        error_ctx_td_error = ERROR_CTX_TD_ERROR,
#       else
#       endif

#       ifdef ERROR_CTX_WINSTATION_NOT_FOUND
        /// <summary>The specified session cannot be found.</summary>
        error_ctx_winstation_not_found = ERROR_CTX_WINSTATION_NOT_FOUND,
#       else
#       endif

#       ifdef ERROR_CTX_WINSTATION_ALREADY_EXISTS
        /// <summary>The specified session name is already in use.</summary>
        error_ctx_winstation_already_exists = ERROR_CTX_WINSTATION_ALREADY_EXISTS,
#       else
#       endif

#       ifdef ERROR_CTX_WINSTATION_BUSY
        /// <summary>The task you are trying to do can't be completed because Remote Desktop Services is currently busy. Please try again in a few minutes. Other users should still be able to log on.</summary>
        error_ctx_winstation_busy = ERROR_CTX_WINSTATION_BUSY,
#       else
#       endif

#       ifdef ERROR_CTX_BAD_VIDEO_MODE
        /// <summary>An attempt has been made to connect to a session whose video mode is not supported by the current client.</summary>
        error_ctx_bad_video_mode = ERROR_CTX_BAD_VIDEO_MODE,
#       else
#       endif

#       ifdef ERROR_CTX_GRAPHICS_INVALID
        /// <summary>The application attempted to enable DOS graphics mode. DOS graphics mode is not supported.</summary>
        error_ctx_graphics_invalid = ERROR_CTX_GRAPHICS_INVALID,
#       else
#       endif
            
#       ifdef ERROR_CTX_LOGON_DISABLED
        /// <summary>Your interactive logon privilege has been disabled. Please contact your administrator.</summary>
        error_ctx_logon_disabled = ERROR_CTX_LOGON_DISABLED,
#       else
#       endif

#       ifdef ERROR_CTX_NOT_CONSOLE
        /// <summary>The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access.</summary>
        error_ctx_not_console = ERROR_CTX_NOT_CONSOLE,
#       else
#       endif

#       ifdef ERROR_CTX_CLIENT_QUERY_TIMEOUT
        /// <summary>The client failed to respond to the server connect message.</summary>
        error_ctx_client_query_timeout = ERROR_CTX_CLIENT_QUERY_TIMEOUT,
#       else
#       endif

#       ifdef ERROR_CTX_CONSOLE_DISCONNECT
        /// <summary>Disconnecting the console session is not supported.</summary>
        error_ctx_console_disconnect = ERROR_CTX_CONSOLE_DISCONNECT,
#       else
#       endif

#       ifdef ERROR_CTX_CONSOLE_CONNECT
        /// <summary>Reconnecting a disconnected session to the console is not supported.</summary>
        error_ctx_console_connect = ERROR_CTX_CONSOLE_CONNECT,
#       else
#       endif

#       ifdef ERROR_CTX_SHADOW_DENIED
        /// <summary>The request to control another session remotely was denied.</summary>
        error_ctx_shadow_denied = ERROR_CTX_SHADOW_DENIED,
#       else
#       endif

#       ifdef ERROR_CTX_WINSTATION_ACCESS_DENIED
        /// <summary>The requested session access is denied.</summary>
        error_ctx_winstation_access_denied = ERROR_CTX_WINSTATION_ACCESS_DENIED,
#       else
#       endif

#       ifdef ERROR_CTX_INVALID_WD
        /// <summary>The specified terminal connection driver is invalid.</summary>
        error_ctx_invalid_wd = ERROR_CTX_INVALID_WD,
#       else
#       endif

#       ifdef ERROR_CTX_SHADOW_INVALID
        /// <summary>This may be because the session is disconnected or does not currently have a user logged on.</summary>
        error_ctx_shadow_invalid = ERROR_CTX_SHADOW_INVALID,
#       else
#       endif

#       ifdef ERROR_CTX_SHADOW_DISABLED
        /// <summary>The requested session is not configured to allow remote control.</summary>
        error_ctx_shadow_disabled = ERROR_CTX_SHADOW_DISABLED,
#       else
#       endif

#       ifdef ERROR_CTX_CLIENT_LICENSE_IN_USE
        /// <summary>Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user. Please call your system administrator to obtain a unique license number.</summary>
        error_ctx_client_license_in_use = ERROR_CTX_CLIENT_LICENSE_IN_USE,
#       else
#       endif

#       ifdef ERROR_CTX_CLIENT_LICENSE_NOT_SET
        /// <summary>Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client. Please contact your system administrator.</summary>
        error_ctx_client_license_not_set = ERROR_CTX_CLIENT_LICENSE_NOT_SET,
#       else
#       endif

#       ifdef ERROR_CTX_LICENSE_NOT_AVAILABLE
        /// <summary>The number of connections to this computer is limited and all connections are in use right now. Try connecting later or contact your system administrator.</summary>
        error_ctx_license_not_available = ERROR_CTX_LICENSE_NOT_AVAILABLE,
#       else
#       endif

#       ifdef ERROR_CTX_LICENSE_CLIENT_INVALID
        /// <summary>The client you are using is not licensed to use this system. Your logon request is denied.</summary>
        error_ctx_license_client_invalid = ERROR_CTX_LICENSE_CLIENT_INVALID,
#       else
#       endif

#       ifdef ERROR_CTX_LICENSE_EXPIRED
        /// <summary>The system license has expired. Your logon request is denied.</summary>
        error_ctx_license_expired = ERROR_CTX_LICENSE_EXPIRED,
#       else
#       endif

#       ifdef ERROR_CTX_SHADOW_NOT_RUNNING
        /// <summary>Remote control could not be terminated because the specified session is not currently being remotely controlled.</summary>
        error_ctx_shadow_not_running = ERROR_CTX_SHADOW_NOT_RUNNING,
#       else
#       endif

#       ifdef ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE
        /// <summary>The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.</summary>
        error_ctx_shadow_ended_by_mode_change = ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE,
#       else
#       endif

#       ifdef ERROR_ACTIVATION_COUNT_EXCEEDED
        /// <summary>Activation has already been reset the maximum number of times for this installation. Your activation timer will not be cleared.</summary>
        error_activation_count_exceeded = ERROR_ACTIVATION_COUNT_EXCEEDED,
#       else
#       endif

#       ifdef ERROR_CTX_WINSTATIONS_DISABLED
        /// <summary>Remote logins are currently disabled.</summary>
        error_ctx_winstations_disabled = ERROR_CTX_WINSTATIONS_DISABLED,
#       else
#       endif

#       ifdef ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED
        /// <summary>You do not have the proper encryption level to access this Session.</summary>
        error_ctx_encryption_level_required = ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED,
#       else
#       endif

#       ifdef ERROR_CTX_SESSION_IN_USE
        /// <summary>The user %s/%s is currently logged on to this computer. Only the current user or an administrator can log on to this computer.</summary>
        error_ctx_session_in_use = ERROR_CTX_SESSION_IN_USE,
#       else
#       endif

#       ifdef ERROR_CTX_NO_FORCE_LOGOFF
        /// <summary>The user %s/%s is already logged on to the console of this computer. You do not have permission to log in at this time. To resolve this issue, contact %s/%s and have them log off.</summary>
        error_ctx_no_force_logoff = ERROR_CTX_NO_FORCE_LOGOFF,
#       else
#       endif

#       ifdef ERROR_CTX_ACCOUNT_RESTRICTION
        /// <summary>Unable to log you on because of an account restriction.</summary>
        error_ctx_account_restriction = ERROR_CTX_ACCOUNT_RESTRICTION,
#       else
#       endif

#       ifdef ERROR_RDP_PROTOCOL_ERROR
        /// <summary>The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.</summary>
        error_rdp_protocol_error = ERROR_RDP_PROTOCOL_ERROR,
#       else
#       endif

#       ifdef ERROR_CTX_CDM_CONNECT
        /// <summary>The Client Drive Mapping Service Has Connected on Terminal Connection.</summary>
        error_ctx_cdm_connect = ERROR_CTX_CDM_CONNECT,
#       else
#       endif

#       ifdef ERROR_CTX_CDM_DISCONNECT
        /// <summary>The Client Drive Mapping Service Has Disconnected on Terminal Connection.</summary>
        error_ctx_cdm_disconnect = ERROR_CTX_CDM_DISCONNECT,
#       else
#       endif

#       ifdef ERROR_CTX_SECURITY_LAYER_ERROR
        /// <summary>The Terminal Server security layer detected an error in the protocol stream and has disconnected the client.</summary>
        error_ctx_security_layer_error = ERROR_CTX_SECURITY_LAYER_ERROR,
#       else
#       endif

#       ifdef ERROR_TS_INCOMPATIBLE_SESSIONS
        /// <summary>The target session is incompatible with the current session.</summary>
        error_ts_incompatible_sessions = ERROR_TS_INCOMPATIBLE_SESSIONS,
#       else
#       endif

#       ifdef ERROR_TS_VIDEO_SUBSYSTEM_ERROR
        /// <summary>Windows can't connect to your session because a problem occurred in the Windows video subsystem. Try connecting again later, or contact the server administrator for assistance.</summary>
        error_ts_video_subsystem_error = ERROR_TS_VIDEO_SUBSYSTEM_ERROR,
#       else
#       endif
    };

    using native_windows_error = decltype(GetLastError());

    class MODERN_WIN32_EXPORT windows_error_details final 
    {
    public:

        explicit windows_error_details() noexcept;
        explicit windows_error_details(windows_error const error_code) noexcept;
        explicit windows_error_details(native_windows_error const error_code) noexcept;

        /// <summary>
        /// Returns the native windows error code value
        /// </summary>
        /// <returns>native windows error code value</returns>
        [[nodiscard]]
        native_windows_error native_error_code() const noexcept;

        /// <summary>
        /// Returns true if native_error_code is NO_ERROR
        /// </summary>
        /// <returns>true if native_error_code is NO_ERROR</returns>
        explicit operator bool() const noexcept;

        /// <summary>
        /// Returns the <see cref="windows_error"/> formed using the original native error code if a match is found; otherwise <see cref="windows_error::unknown"/>
        /// </summary>
        /// <returns><see cref="windows_error"/> formed using the original native error code if a match is found; otherwise <see cref="windows_error::unknown"/></returns>
        [[nodiscard]]
        windows_error get() const noexcept;


        /// <summary>
        /// <see cref="get()"/>
        /// </summary>
        operator windows_error() const noexcept;
    private:
        native_windows_error native_error_code_;
    };

}

#endif
#endif
