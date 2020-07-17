
// Copyright © 2020 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#ifndef __MODERN_WIN32_WINDOWS_ERROR_H__
#define __MODERN_WIN32_WINDOWS_ERROR_H__
#ifdef _WIN32

#include <errhandlingapi.h>
#include <winerror.h>
#include <optional>
#include <tuple>
#include <type_traits>

namespace modern_win32
{
    enum class windows_error
    {
        none = NO_ERROR,

        /// <summary>Incorrect function.</summary>
        error_invalid_function = ERROR_INVALID_FUNCTION,

        /// <summary>The system cannot find the file specified.</summary>
        error_file_not_found = ERROR_FILE_NOT_FOUND,
        /// <summary>The system cannot find the path specified.</summary>
        error_path_not_found = ERROR_PATH_NOT_FOUND,
        /// <summary>The system cannot open the file.</summary>
        error_too_many_open_files = ERROR_TOO_MANY_OPEN_FILES,
        /// <summary>Access is denied.</summary>
        error_access_denied = ERROR_ACCESS_DENIED,
        /// <summary>The handle is invalid.</summary>
        error_invalid_handle = ERROR_INVALID_HANDLE,
        /// <summary>The storage control blocks were destroyed.</summary>
        error_arena_trashed = ERROR_ARENA_TRASHED,
        /// <summary>Not enough memory resources are available to process this command.</summary>
        error_not_enough_memory = ERROR_NOT_ENOUGH_MEMORY,
        /// <summary>The storage control block address is invalid.</summary>
        error_invalid_block = ERROR_INVALID_BLOCK,
        /// <summary>The environment is incorrect.</summary>
        error_bad_environment = ERROR_BAD_ENVIRONMENT,
        /// <summary>An attempt was made to load a program with an incorrect format.</summary>
        error_bad_format = ERROR_BAD_FORMAT,
        /// <summary>The access code is invalid.</summary>
        error_invalid_access = ERROR_INVALID_ACCESS,
        /// <summary>The data is invalid.</summary>
        error_invalid_data = ERROR_INVALID_DATA,
        /// <summary>Not enough memory resources are available to complete this operation.</summary>
        error_outofmemory = ERROR_OUTOFMEMORY,
        /// <summary>The system cannot find the drive specified.</summary>
        error_invalid_drive = ERROR_INVALID_DRIVE,
        /// <summary>The directory cannot be removed.</summary>
        error_current_directory = ERROR_CURRENT_DIRECTORY,
        /// <summary>The system cannot move the file to a different disk drive.</summary>
        error_not_same_device = ERROR_NOT_SAME_DEVICE,
        /// <summary>There are no more files.</summary>
        error_no_more_files = ERROR_NO_MORE_FILES,
        /// <summary>The media is write protected.</summary>
        error_write_protect = ERROR_WRITE_PROTECT,
        /// <summary>The system cannot find the device specified.</summary>
        error_bad_unit = ERROR_BAD_UNIT,
        /// <summary>The device is not ready.</summary>
        error_not_ready = ERROR_NOT_READY,
        /// <summary>The device does not recognize the command.</summary>
        error_bad_command = ERROR_BAD_COMMAND,
        /// <summary>Data error (cyclic redundancy check).</summary>
        error_crc = ERROR_CRC,
        /// <summary>The program issued a command but the command length is incorrect.</summary>
        error_bad_length = ERROR_BAD_LENGTH,
        /// <summary>The drive cannot locate a specific area or track on the disk.</summary>
        error_seek = ERROR_SEEK,
        /// <summary>The specified disk or diskette cannot be accessed.</summary>
        error_not_dos_disk = ERROR_NOT_DOS_DISK,
        /// <summary>The drive cannot find the sector requested.</summary>
        error_sector_not_found = ERROR_SECTOR_NOT_FOUND,
        /// <summary>The printer is out of paper.</summary>
        error_out_of_paper = ERROR_OUT_OF_PAPER,
        /// <summary>The system cannot write to the specified device.</summary>
        error_write_fault = ERROR_WRITE_FAULT,
        /// <summary>The system cannot read from the specified device.</summary>
        error_read_fault = ERROR_READ_FAULT,
        /// <summary>A device attached to the system is not functioning.</summary>
        error_gen_failure = ERROR_GEN_FAILURE,
        /// <summary>The process cannot access the file because it is being used by another process.</summary>
        error_sharing_violation = ERROR_SHARING_VIOLATION,
        /// <summary>The process cannot access the file because another process has locked a portion of the file.</summary>
        error_lock_violation = ERROR_LOCK_VIOLATION,
        /// <summary>The wrong diskette is in the drive.</summary>
        /// <summary>Insert %2 (Volume Serial Number: %3) into drive %1.</summary>
        error_wrong_disk = ERROR_WRONG_DISK,
        /// <summary>Too many files opened for sharing.</summary>
        error_sharing_buffer_exceeded = ERROR_SHARING_BUFFER_EXCEEDED,
        /// <summary>Reached the end of the file.</summary>
        error_handle_eof = ERROR_HANDLE_EOF,
        /// <summary>The disk is full.</summary>
        error_handle_disk_full = ERROR_HANDLE_DISK_FULL,
        /// <summary>The request is not supported.</summary>
        error_not_supported = ERROR_NOT_SUPPORTED,
        /// <summary>Windows cannot find the network path. Verify that the network path is correct and the destination computer is not busy or turned off. If Windows still cannot find the network path, contact your network administrator.</summary>
        error_rem_not_list = ERROR_REM_NOT_LIST,
        /// <summary>You were not connected because a duplicate name exists on the network. If joining a domain, go to System in Control Panel to change the computer name and try again. If joining a workgroup, choose another workgroup name.</summary>
        error_dup_name = ERROR_DUP_NAME,
        /// <summary>The network path was not found.</summary>
        error_bad_netpath = ERROR_BAD_NETPATH,
        /// <summary>The network is busy.</summary>
        error_network_busy = ERROR_NETWORK_BUSY,
        /// <summary>The specified network resource or device is no longer available.</summary>
        error_dev_not_exist = ERROR_DEV_NOT_EXIST,
        /// <summary>The network BIOS command limit has been reached.</summary>
        error_too_many_cmds = ERROR_TOO_MANY_CMDS,
        /// <summary>A network adapter hardware error occurred.</summary>
        error_adap_hdw_err = ERROR_ADAP_HDW_ERR,
        /// <summary>The specified server cannot perform the requested operation.</summary>
        error_bad_net_resp = ERROR_BAD_NET_RESP,
        /// <summary>An unexpected network error occurred.</summary>
        error_unexp_net_err = ERROR_UNEXP_NET_ERR,
        /// <summary>The remote adapter is not compatible.</summary>
        error_bad_rem_adap = ERROR_BAD_REM_ADAP,
        /// <summary>The printer queue is full.</summary>
        error_printq_full = ERROR_PRINTQ_FULL,
        /// <summary>Space to store the file waiting to be printed is not available on the server.</summary>
        error_no_spool_space = ERROR_NO_SPOOL_SPACE,
        /// <summary>Your file waiting to be printed was deleted.</summary>
        error_print_cancelled = ERROR_PRINT_CANCELLED,
        /// <summary>The specified network name is no longer available.</summary>
        error_netname_deleted = ERROR_NETNAME_DELETED,
        /// <summary>Network access is denied.</summary>
        error_network_access_denied = ERROR_NETWORK_ACCESS_DENIED,
        /// <summary>The network resource type is not correct.</summary>
        error_bad_dev_type = ERROR_BAD_DEV_TYPE,
        /// <summary>The network name cannot be found.</summary>
        error_bad_net_name = ERROR_BAD_NET_NAME,
        /// <summary>The name limit for the local computer network adapter card was exceeded.</summary>
        error_too_many_names = ERROR_TOO_MANY_NAMES,
        /// <summary>The network BIOS session limit was exceeded.</summary>
        error_too_many_sess = ERROR_TOO_MANY_SESS,
        /// <summary>The remote server has been paused or is in the process of being started.</summary>
        error_sharing_paused = ERROR_SHARING_PAUSED,
        /// <summary>No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.</summary>
        error_req_not_accep = ERROR_REQ_NOT_ACCEP,
        /// <summary>The specified printer or disk device has been paused.</summary>
        error_redir_paused = ERROR_REDIR_PAUSED,
        /// <summary>The file exists.</summary>
        error_file_exists = ERROR_FILE_EXISTS,
        /// <summary>The directory or file cannot be created.</summary>
        error_cannot_make = ERROR_CANNOT_MAKE,
        /// <summary>Fail on INT 24.</summary>
        error_fail_i24 = ERROR_FAIL_I24,
        /// <summary>Storage to process this request is not available.</summary>
        error_out_of_structures = ERROR_OUT_OF_STRUCTURES,
        /// <summary>The local device name is already in use.</summary>
        error_already_assigned = ERROR_ALREADY_ASSIGNED,
        /// <summary>The specified network password is not correct.</summary>
        error_invalid_password = ERROR_INVALID_PASSWORD,
        /// <summary>The parameter is incorrect.</summary>
        error_invalid_parameter = ERROR_INVALID_PARAMETER,
        /// <summary>A write fault occurred on the network.</summary>
        error_net_write_fault = ERROR_NET_WRITE_FAULT,
        /// <summary>The system cannot start another process at this time.</summary>
        error_no_proc_slots = ERROR_NO_PROC_SLOTS,
        /// <summary>Cannot create another system semaphore.</summary>
        error_too_many_semaphores = ERROR_TOO_MANY_SEMAPHORES,
        /// <summary>The exclusive semaphore is owned by another process.</summary>
        error_excl_sem_already_owned = ERROR_EXCL_SEM_ALREADY_OWNED,
        /// <summary>The semaphore is set and cannot be closed.</summary>
        error_sem_is_set = ERROR_SEM_IS_SET,
        /// <summary>The semaphore cannot be set again.</summary>
        error_too_many_sem_requests = ERROR_TOO_MANY_SEM_REQUESTS,
        /// <summary>Cannot request exclusive semaphores at interrupt time.</summary>
        error_invalid_at_interrupt_time = ERROR_INVALID_AT_INTERRUPT_TIME,
        /// <summary>The previous ownership of this semaphore has ended.</summary>
        error_sem_owner_died = ERROR_SEM_OWNER_DIED,
        /// <summary>Insert the diskette for drive %1.</summary>
        error_sem_user_limit = ERROR_SEM_USER_LIMIT,
        /// <summary>The program stopped because an alternate diskette was not inserted.</summary>
        error_disk_change = ERROR_DISK_CHANGE,
        /// <summary>The disk is in use or locked by another process.</summary>
        error_drive_locked = ERROR_DRIVE_LOCKED,
        /// <summary>The pipe has been ended.</summary>
        error_broken_pipe = ERROR_BROKEN_PIPE,
        /// <summary>The system cannot open the device or file specified.</summary>
        error_open_failed = ERROR_OPEN_FAILED,
        /// <summary>The file name is too long.</summary>
        error_buffer_overflow = ERROR_BUFFER_OVERFLOW,
        /// <summary>There is not enough space on the disk.</summary>
        error_disk_full = ERROR_DISK_FULL,
        /// <summary>No more internal file identifiers available.</summary>
        error_no_more_search_handles = ERROR_NO_MORE_SEARCH_HANDLES,
        /// <summary>The target internal file identifier is incorrect.</summary>
        error_invalid_target_handle = ERROR_INVALID_TARGET_HANDLE,
        /// <summary>The IOCTL call made by the application program is not correct.</summary>
        error_invalid_category = ERROR_INVALID_CATEGORY,
        /// <summary>The verify-on-write switch parameter value is not correct.</summary>
        error_invalid_verify_switch = ERROR_INVALID_VERIFY_SWITCH,
        /// <summary>The system does not support the command requested.</summary>
        error_bad_driver_level = ERROR_BAD_DRIVER_LEVEL,
        /// <summary>This function is not supported on this system.</summary>
        error_call_not_implemented = ERROR_CALL_NOT_IMPLEMENTED,
        /// <summary>The semaphore timeout period has expired.</summary>
        error_sem_timeout = ERROR_SEM_TIMEOUT,
        /// <summary>The data area passed to a system call is too small.</summary>
        error_insufficient_buffer = ERROR_INSUFFICIENT_BUFFER,
        /// <summary>The filename, directory name, or volume label syntax is incorrect.</summary>
        error_invalid_name = ERROR_INVALID_NAME,
        /// <summary>The system call level is not correct.</summary>
        error_invalid_level = ERROR_INVALID_LEVEL,
        /// <summary>The disk has no volume label.</summary>
        error_no_volume_label = ERROR_NO_VOLUME_LABEL,
        /// <summary>The specified module could not be found.</summary>
        error_mod_not_found = ERROR_MOD_NOT_FOUND,
        /// <summary>The specified procedure could not be found.</summary>
        error_proc_not_found = ERROR_PROC_NOT_FOUND,
        /// <summary>There are no child processes to wait for.</summary>
        error_wait_no_children = ERROR_WAIT_NO_CHILDREN,
        /// <summary>The %1 application cannot be run in Win32 mode.</summary>
        error_child_not_complete = ERROR_CHILD_NOT_COMPLETE,
        /// <summary>Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.</summary>
        error_direct_access_handle = ERROR_DIRECT_ACCESS_HANDLE,
        /// <summary>An attempt was made to move the file pointer before the beginning of the file.</summary>
        error_negative_seek = ERROR_NEGATIVE_SEEK,
        /// <summary>The file pointer cannot be set on the specified device or file.</summary>
        error_seek_on_device = ERROR_SEEK_ON_DEVICE,
        /// <summary>A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.</summary>
        error_is_join_target = ERROR_IS_JOIN_TARGET,
        /// <summary>An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.</summary>
        error_is_joined = ERROR_IS_JOINED,
        /// <summary>An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.</summary>
        error_is_substed = ERROR_IS_SUBSTED,
        /// <summary>The system tried to delete the JOIN of a drive that is not joined.</summary>
        error_not_joined = ERROR_NOT_JOINED,
        /// <summary>The system tried to delete the substitution of a drive that is not substituted.</summary>
        error_not_substed = ERROR_NOT_SUBSTED,
        /// <summary>The system tried to join a drive to a directory on a joined drive.</summary>
        error_join_to_join = ERROR_JOIN_TO_JOIN,
        /// <summary>The system tried to substitute a drive to a directory on a substituted drive.</summary>
        error_subst_to_subst = ERROR_SUBST_TO_SUBST,
        /// <summary>The system tried to join a drive to a directory on a substituted drive.</summary>
        error_join_to_subst = ERROR_JOIN_TO_SUBST,
        /// <summary>The system tried to SUBST a drive to a directory on a joined drive.</summary>
        error_subst_to_join = ERROR_SUBST_TO_JOIN,
        /// <summary>The system cannot perform a JOIN or SUBST at this time.</summary>
        error_busy_drive = ERROR_BUSY_DRIVE,
        /// <summary>The system cannot join or substitute a drive to or for a directory on the same drive.</summary>
        error_same_drive = ERROR_SAME_DRIVE,
        /// <summary>The directory is not a subdirectory of the root directory.</summary>
        error_dir_not_root = ERROR_DIR_NOT_ROOT,
        /// <summary>The directory is not empty.</summary>
        error_dir_not_empty = ERROR_DIR_NOT_EMPTY,
        /// <summary>The path specified is being used in a substitute.</summary>
        error_is_subst_path = ERROR_IS_SUBST_PATH,
        /// <summary>Not enough resources are available to process this command.</summary>
        error_is_join_path = ERROR_IS_JOIN_PATH,
        /// <summary>The path specified cannot be used at this time.</summary>
        error_path_busy = ERROR_PATH_BUSY,
        /// <summary>An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.</summary>
        error_is_subst_target = ERROR_IS_SUBST_TARGET,
        /// <summary>System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.</summary>
        error_system_trace = ERROR_SYSTEM_TRACE,
        /// <summary>The number of specified semaphore events for DosMuxSemWait is not correct.</summary>
        error_invalid_event_count = ERROR_INVALID_EVENT_COUNT,
        /// <summary>DosMuxSemWait did not execute; too many semaphores are already set.</summary>
        error_too_many_muxwaiters = ERROR_TOO_MANY_MUXWAITERS,
        /// <summary>The DosMuxSemWait list is not correct.</summary>
        error_invalid_list_format = ERROR_INVALID_LIST_FORMAT,
        /// <summary>The volume label you entered exceeds the label character limit of the target file system.</summary>
        error_label_too_long = ERROR_LABEL_TOO_LONG,
        /// <summary>Cannot create another thread.</summary>
        error_too_many_tcbs = ERROR_TOO_MANY_TCBS,
        /// <summary>The recipient process has refused the signal.</summary>
        error_signal_refused = ERROR_SIGNAL_REFUSED,
        /// <summary>The segment is already discarded and cannot be locked.</summary>
        error_discarded = ERROR_DISCARDED,
        /// <summary>The segment is already unlocked.</summary>
        error_not_locked = ERROR_NOT_LOCKED,
        /// <summary>The address for the thread ID is not correct.</summary>
        error_bad_threadid_addr = ERROR_BAD_THREADID_ADDR,
        /// <summary>One or more arguments are not correct.</summary>
        error_bad_arguments = ERROR_BAD_ARGUMENTS,
        /// <summary>The specified path is invalid.</summary>
        error_bad_pathname = ERROR_BAD_PATHNAME,
        /// <summary>A signal is already pending.</summary>
        error_signal_pending = ERROR_SIGNAL_PENDING,
        /// <summary>No more threads can be created in the system.</summary>
        error_max_thrds_reached = ERROR_MAX_THRDS_REACHED,
        /// <summary>Unable to lock a region of a file.</summary>
        error_lock_failed = ERROR_LOCK_FAILED,
        /// <summary>The requested resource is in use.</summary>
        error_busy = ERROR_BUSY,
        /// <summary>Device's command support detection is in progress.</summary>
        error_device_support_in_progress = ERROR_DEVICE_SUPPORT_IN_PROGRESS,
        /// <summary>A lock request was not outstanding for the supplied cancel region.</summary>
        error_cancel_violation = ERROR_CANCEL_VIOLATION,
        /// <summary>The file system does not support atomic changes to the lock type.</summary>
        error_atomic_locks_not_supported = ERROR_ATOMIC_LOCKS_NOT_SUPPORTED,
        /// <summary>The system detected a segment number that was not correct.</summary>
        error_invalid_segment_number = ERROR_INVALID_SEGMENT_NUMBER,
        /// <summary>The operating system cannot run %1.</summary>
        error_invalid_ordinal = ERROR_INVALID_ORDINAL,
        /// <summary>Cannot create a file when that file already exists.</summary>
        error_already_exists = ERROR_ALREADY_EXISTS,
        /// <summary>The flag passed is not correct.</summary>
        error_invalid_flag_number = ERROR_INVALID_FLAG_NUMBER,
        /// <summary>The specified system semaphore name was not found.</summary>
        error_sem_not_found = ERROR_SEM_NOT_FOUND,
        /// <summary>The operating system cannot run %1.</summary>
        error_invalid_starting_codeseg = ERROR_INVALID_STARTING_CODESEG,
        /// <summary>The operating system cannot run %1.</summary>
        error_invalid_stackseg = ERROR_INVALID_STACKSEG,
        /// <summary>The operating system cannot run %1.</summary>
        error_invalid_moduletype = ERROR_INVALID_MODULETYPE,
        /// <summary>Cannot run %1 in Win32 mode.</summary>
        error_invalid_exe_signature = ERROR_INVALID_EXE_SIGNATURE,
        /// <summary>The operating system cannot run %1.</summary>
        error_exe_marked_invalid = ERROR_EXE_MARKED_INVALID,
        /// <summary>%1 is not a valid Win32 application.</summary>
        error_bad_exe_format = ERROR_BAD_EXE_FORMAT,
        /// <summary>The operating system cannot run %1.</summary>
        error_iterated_data_exceeds_64k = ERROR_ITERATED_DATA_EXCEEDS_64k,
        /// <summary>The operating system cannot run %1.</summary>
        error_invalid_minallocsize = ERROR_INVALID_MINALLOCSIZE,
        /// <summary>The operating system cannot run this application program.</summary>
        error_dynlink_from_invalid_ring = ERROR_DYNLINK_FROM_INVALID_RING,
        /// <summary>The operating system is not presently configured to run this application.</summary>
        error_iopl_not_enabled = ERROR_IOPL_NOT_ENABLED,
        /// <summary>The operating system cannot run %1.</summary>
        error_invalid_segdpl = ERROR_INVALID_SEGDPL,
        /// <summary>The operating system cannot run this application program.</summary>
        error_autodataseg_exceeds_64k = ERROR_AUTODATASEG_EXCEEDS_64k,
        /// <summary>The code segment cannot be greater than or equal to 64K.</summary>
        error_ring2seg_must_be_movable = ERROR_RING2SEG_MUST_BE_MOVABLE,
        /// <summary>The operating system cannot run %1.</summary>
        error_reloc_chain_xeeds_seglim = ERROR_RELOC_CHAIN_XEEDS_SEGLIM,
        /// <summary>The operating system cannot run %1.</summary>
        error_infloop_in_reloc_chain = ERROR_INFLOOP_IN_RELOC_CHAIN,
        /// <summary>The system could not find the environment option that was entered.</summary>
        error_envvar_not_found = ERROR_ENVVAR_NOT_FOUND,
        /// <summary>No process in the command subtree has a signal handler.</summary>
        error_no_signal_sent = ERROR_NO_SIGNAL_SENT,
        /// <summary>The filename or extension is too long.</summary>
        error_filename_exced_range = ERROR_FILENAME_EXCED_RANGE,
        /// <summary>The ring 2 stack is in use.</summary>
        error_ring2_stack_in_use = ERROR_RING2_STACK_IN_USE,
        /// <summary>The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.</summary>
        error_meta_expansion_too_long = ERROR_META_EXPANSION_TOO_LONG,
        /// <summary>The signal being posted is not correct.</summary>
        error_invalid_signal_number = ERROR_INVALID_SIGNAL_NUMBER,
        /// <summary>The signal handler cannot be set.</summary>
        error_thread_1_inactive = ERROR_THREAD_1_INACTIVE,
        /// <summary>The segment is locked and cannot be reallocated.</summary>
        error_locked = ERROR_LOCKED,
        /// <summary>Too many dynamic-link modules are attached to this program or dynamic-link module.</summary>
        error_too_many_modules = ERROR_TOO_MANY_MODULES,
        /// <summary>Cannot nest calls to LoadModule.</summary>
        error_nesting_not_allowed = ERROR_NESTING_NOT_ALLOWED,
        /// <summary>This version of %1 is not compatible with the version of Windows you're running. Check your computer's system information and then contact the software publisher.</summary>
        error_exe_machine_type_mismatch = ERROR_EXE_MACHINE_TYPE_MISMATCH,
        /// <summary>The image file %1 is signed, unable to modify.</summary>
        error_exe_cannot_modify_signed_binary = ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY,
        /// <summary>The image file %1 is strong signed, unable to modify.</summary>
        error_exe_cannot_modify_strong_signed_binary = ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY,
        /// <summary>This file is checked out or locked for editing by another user.</summary>
        error_file_checked_out = ERROR_FILE_CHECKED_OUT,
        /// <summary>The file must be checked out before saving changes.</summary>
        error_checkout_required = ERROR_CHECKOUT_REQUIRED,
        /// <summary>The file type being saved or retrieved has been blocked.</summary>
        error_bad_file_type = ERROR_BAD_FILE_TYPE,
        /// <summary>The file size exceeds the limit allowed and cannot be saved.</summary>
        error_file_too_large = ERROR_FILE_TOO_LARGE,
        /// <summary>Access Denied. Before opening files in this location, you must first add the web site to your trusted sites list, browse to the web site, and select the option to login automatically.</summary>
        error_forms_auth_required = ERROR_FORMS_AUTH_REQUIRED,
        /// <summary>Operation did not complete successfully because the file contains a virus or potentially unwanted software.</summary>
        error_virus_infected = ERROR_VIRUS_INFECTED,
        /// <summary>This file contains a virus or potentially unwanted software and cannot be opened. Due to the nature of this virus or potentially unwanted software, the file has been removed from this location.</summary>
        error_virus_deleted = ERROR_VIRUS_DELETED,
        /// <summary>The pipe is local.</summary>
        error_pipe_local = ERROR_PIPE_LOCAL,
        /// <summary>The pipe state is invalid.</summary>
        error_bad_pipe = ERROR_BAD_PIPE,
        /// <summary>All pipe instances are busy.</summary>
        error_pipe_busy = ERROR_PIPE_BUSY,
        /// <summary>The pipe is being closed.</summary>
        error_no_data = ERROR_NO_DATA,
        /// <summary>No process is on the other end of the pipe.</summary>
        error_pipe_not_connected = ERROR_PIPE_NOT_CONNECTED,
        /// <summary>More data is available.</summary>
        error_more_data = ERROR_MORE_DATA,
        /// <summary>The action requested resulted in no work being done. Error-style clean-up has been performed.</summary>
        error_no_work_done = ERROR_NO_WORK_DONE,
        /// <summary>The session was canceled.</summary>
        error_vc_disconnected = ERROR_VC_DISCONNECTED,
        /// <summary>The specified extended attribute name was invalid.</summary>
        error_invalid_ea_name = ERROR_INVALID_EA_NAME,
        /// <summary>The extended attributes are inconsistent.</summary>
        error_ea_list_inconsistent = ERROR_EA_LIST_INCONSISTENT,
        /// <summary>The wait operation timed out.</summary>
        wait_timeout = WAIT_TIMEOUT,
        /// <summary>No more data is available.</summary>
        error_no_more_items = ERROR_NO_MORE_ITEMS,
        /// <summary>The copy functions cannot be used.</summary>
        error_cannot_copy = ERROR_CANNOT_COPY,
        /// <summary>The directory name is invalid.</summary>
        error_directory = ERROR_DIRECTORY,
        /// <summary>The extended attributes did not fit in the buffer.</summary>
        error_eas_didnt_fit = ERROR_EAS_DIDNT_FIT,
        /// <summary>The extended attribute file on the mounted file system is corrupt.</summary>
        error_ea_file_corrupt = ERROR_EA_FILE_CORRUPT,
        /// <summary>The extended attribute table file is full.</summary>
        error_ea_table_full = ERROR_EA_TABLE_FULL,
        /// <summary>The specified extended attribute handle is invalid.</summary>
        error_invalid_ea_handle = ERROR_INVALID_EA_HANDLE,
        /// <summary>The mounted file system does not support extended attributes.</summary>
        error_eas_not_supported = ERROR_EAS_NOT_SUPPORTED,
        /// <summary>Attempt to release mutex not owned by caller.</summary>
        error_not_owner = ERROR_NOT_OWNER,
        /// <summary>Too many posts were made to a semaphore.</summary>
        error_too_many_posts = ERROR_TOO_MANY_POSTS,
        /// <summary>Only part of a ReadProcessMemory or WriteProcessMemory request was completed.</summary>
        error_partial_copy = ERROR_PARTIAL_COPY,
        /// <summary>The oplock request is denied.</summary>
        error_oplock_not_granted = ERROR_OPLOCK_NOT_GRANTED,
        /// <summary>An invalid oplock acknowledgment was received by the system.</summary>
        error_invalid_oplock_protocol = ERROR_INVALID_OPLOCK_PROTOCOL,
        /// <summary>The volume is too fragmented to complete this operation.</summary>
        error_disk_too_fragmented = ERROR_DISK_TOO_FRAGMENTED,
        /// <summary>The file cannot be opened because it is in the process of being deleted.</summary>
        error_delete_pending = ERROR_DELETE_PENDING,
        /// <summary>Short name settings may not be changed on this volume due to the global registry setting.</summary>
        error_incompatible_with_global_short_name_registry_setting = ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING,
        /// <summary>Short names are not enabled on this volume.</summary>
        error_short_names_not_enabled_on_volume = ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME,
        /// <summary>The security stream for the given volume is in an inconsistent state.</summary>
        /// <summary>Please run CHKDSK on the volume.</summary>
        error_security_stream_is_inconsistent = ERROR_SECURITY_STREAM_IS_INCONSISTENT,
        /// <summary>A requested file lock operation cannot be processed due to an invalid byte range.</summary>
        error_invalid_lock_range = ERROR_INVALID_LOCK_RANGE,
        /// <summary>The subsystem needed to support the image type is not present.</summary>
        error_image_subsystem_not_present = ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT,
        /// <summary>The specified file already has a notification GUID associated with it.</summary>
        error_notification_guid_already_defined = ERROR_NOTIFICATION_GUID_ALREADY_DEFINED,
        /// <summary>An invalid exception handler routine has been detected.</summary>
        error_invalid_exception_handler = ERROR_INVALID_EXCEPTION_HANDLER,
        /// <summary>Duplicate privileges were specified for the token.</summary>
        error_duplicate_privileges = ERROR_DUPLICATE_PRIVILEGES,
        /// <summary>No ranges for the specified operation were able to be processed.</summary>
        error_no_ranges_processed = ERROR_NO_RANGES_PROCESSED,
        /// <summary>Operation is not allowed on a file system internal file.</summary>
        error_not_allowed_on_system_file = ERROR_NOT_ALLOWED_ON_SYSTEM_FILE,
        /// <summary>The physical resources of this disk have been exhausted.</summary>
        error_disk_resources_exhausted = ERROR_DISK_RESOURCES_EXHAUSTED,
        /// <summary>The token representing the data is invalid.</summary>
        error_invalid_token = ERROR_INVALID_TOKEN,
        /// <summary>The device does not support the command feature.</summary>
        error_device_feature_not_supported = ERROR_DEVICE_FEATURE_NOT_SUPPORTED,
        /// <summary>The system cannot find message text for message number 0x%1 in the message file for %2.</summary>
        error_mr_mid_not_found = ERROR_MR_MID_NOT_FOUND,
        /// <summary>The scope specified was not found.</summary>
        error_scope_not_found = ERROR_SCOPE_NOT_FOUND,
        /// <summary>The Central Access Policy specified is not defined on the target machine.</summary>
        error_undefined_scope = ERROR_UNDEFINED_SCOPE,
        /// <summary>The Central Access Policy obtained from Active Directory is invalid.</summary>
        error_invalid_cap = ERROR_INVALID_CAP,
        /// <summary>The device is unreachable.</summary>
        error_device_unreachable = ERROR_DEVICE_UNREACHABLE,
        /// <summary>The target device has insufficient resources to complete the operation.</summary>
        error_device_no_resources = ERROR_DEVICE_NO_RESOURCES,
        /// <summary>A data integrity checksum error occurred. Data in the file stream is corrupt.</summary>
        error_data_checksum_error = ERROR_DATA_CHECKSUM_ERROR,
        /// <summary>An attempt was made to modify both a KERNEL and normal Extended Attribute (EA) in the same operation.</summary>
        error_intermixed_kernel_ea_operation = ERROR_INTERMIXED_KERNEL_EA_OPERATION,
        /// <summary>Device does not support file-level TRIM.</summary>
        error_file_level_trim_not_supported = ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED,
        /// <summary>The command specified a data offset that does not align to the device's granularity/alignment.</summary>
        error_offset_alignment_violation = ERROR_OFFSET_ALIGNMENT_VIOLATION,
        /// <summary>The command specified an invalid field in its parameter list.</summary>
        error_invalid_field_in_parameter_list = ERROR_INVALID_FIELD_IN_PARAMETER_LIST,
        /// <summary>An operation is currently in progress with the device.</summary>
        error_operation_in_progress = ERROR_OPERATION_IN_PROGRESS,
        /// <summary>An attempt was made to send down the command via an invalid path to the target device.</summary>
        error_bad_device_path = ERROR_BAD_DEVICE_PATH,
        /// <summary>The command specified a number of descriptors that exceeded the maximum supported by the device.</summary>
        error_too_many_descriptors = ERROR_TOO_MANY_DESCRIPTORS,
        /// <summary>Scrub is disabled on the specified file.</summary>
        error_scrub_data_disabled = ERROR_SCRUB_DATA_DISABLED,
        /// <summary>The storage device does not provide redundancy.</summary>
        error_not_redundant_storage = ERROR_NOT_REDUNDANT_STORAGE,
        /// <summary>An operation is not supported on a resident file.</summary>
        error_resident_file_not_supported = ERROR_RESIDENT_FILE_NOT_SUPPORTED,
        /// <summary>An operation is not supported on a compressed file.</summary>
        error_compressed_file_not_supported = ERROR_COMPRESSED_FILE_NOT_SUPPORTED,
        /// <summary>An operation is not supported on a directory.</summary>
        error_directory_not_supported = ERROR_DIRECTORY_NOT_SUPPORTED,
        /// <summary>The specified copy of the requested data could not be read.</summary>
        error_not_read_from_copy = ERROR_NOT_READ_FROM_COPY,
        /// <summary>The specified data could not be written to any of the copies.</summary>
        error_ft_write_failure = ERROR_FT_WRITE_FAILURE,
        /// <summary>One or more copies of data on this device may be out of sync. No writes may be performed until a data integrity scan is completed.</summary>
        error_ft_di_scan_required = ERROR_FT_DI_SCAN_REQUIRED,
        /// <summary>The supplied kernel information version is invalid.</summary>
        error_invalid_kernel_info_version = ERROR_INVALID_KERNEL_INFO_VERSION,
        /// <summary>The supplied PEP information version is invalid.</summary>
        error_invalid_pep_info_version = ERROR_INVALID_PEP_INFO_VERSION,
        /// <summary>This object is not externally backed by any provider.</summary>
        error_object_not_externally_backed = ERROR_OBJECT_NOT_EXTERNALLY_BACKED,
        /// <summary>The external backing provider is not recognized.</summary>
        error_external_backing_provider_unknown = ERROR_EXTERNAL_BACKING_PROVIDER_UNKNOWN,
        /// <summary>Compressing this object would not save space.</summary>
        error_compression_not_beneficial = ERROR_COMPRESSION_NOT_BENEFICIAL,
        /// <summary>The request failed due to a storage topology ID mismatch.</summary>
        error_storage_topology_id_mismatch = ERROR_STORAGE_TOPOLOGY_ID_MISMATCH,
        /// <summary>The operation was blocked by parental controls.</summary>
        error_blocked_by_parental_controls = ERROR_BLOCKED_BY_PARENTAL_CONTROLS,
        /// <summary>A file system block being referenced has already reached the maximum reference count and can't be referenced any further.</summary>
        error_block_too_many_references = ERROR_BLOCK_TOO_MANY_REFERENCES,
        /// <summary>The requested operation failed because the file stream is marked to disallow writes.</summary>
        error_marked_to_disallow_writes = ERROR_MARKED_TO_DISALLOW_WRITES,
        /// <summary>The requested operation failed with an architecture-specific failure code.</summary>
        error_enclave_failure = ERROR_ENCLAVE_FAILURE,
        /// <summary>No action was taken as a system reboot is required.</summary>
        error_fail_noaction_reboot = ERROR_FAIL_NOACTION_REBOOT,
        /// <summary>The shutdown operation failed.</summary>
        error_fail_shutdown = ERROR_FAIL_SHUTDOWN,
        /// <summary>The restart operation failed.</summary>
        error_fail_restart = ERROR_FAIL_RESTART,
        /// <summary>The maximum number of sessions has been reached.</summary>
        error_max_sessions_reached = ERROR_MAX_SESSIONS_REACHED,
        /// <summary>Windows Information Protection policy does not allow access to this network resource.</summary>
        error_network_access_denied_edp = ERROR_NETWORK_ACCESS_DENIED_EDP,
        /// <summary>The device hint name buffer is too small to receive the remaining name.</summary>
        error_device_hint_name_buffer_too_small = ERROR_DEVICE_HINT_NAME_BUFFER_TOO_SMALL,
        /// <summary>The requested operation was blocked by Windows Information Protection policy. For more information, contact your system administrator.</summary>
        error_edp_policy_denies_operation = ERROR_EDP_POLICY_DENIES_OPERATION,
        /// <summary>The requested operation cannot be performed because hardware or software configuration of the device does not comply with Windows Information Protection under Lock policy. Please, verify that user PIN has been created. For more information, contact your system administrator.</summary>
        error_edp_dpl_policy_cant_be_satisfied = ERROR_EDP_DPL_POLICY_CANT_BE_SATISFIED,
        /// <summary>The cloud sync root metadata is corrupted.</summary>
        error_cloud_file_sync_root_metadata_corrupt = ERROR_CLOUD_FILE_SYNC_ROOT_METADATA_CORRUPT,
        /// <summary>The device is in maintenance mode.</summary>
        error_device_in_maintenance = ERROR_DEVICE_IN_MAINTENANCE,
        /// <summary>This operation is not supported on a DAX volume.</summary>
        error_not_supported_on_dax = ERROR_NOT_SUPPORTED_ON_DAX,
        /// <summary>The volume has active DAX mappings.</summary>
        error_dax_mapping_exists = ERROR_DAX_MAPPING_EXISTS,
        /// <summary>The cloud file provider is not running.</summary>
        error_cloud_file_provider_not_running = ERROR_CLOUD_FILE_PROVIDER_NOT_RUNNING,
        /// <summary>The cloud file metadata is corrupt and unreadable.</summary>
        error_cloud_file_metadata_corrupt = ERROR_CLOUD_FILE_METADATA_CORRUPT,
        /// <summary>The cloud file metadata is too large.</summary>
        error_cloud_file_metadata_too_large = ERROR_CLOUD_FILE_METADATA_TOO_LARGE,
        /// <summary>The cloud file property is too large.</summary>
        error_cloud_file_property_blob_too_large = ERROR_CLOUD_FILE_PROPERTY_BLOB_TOO_LARGE,
        /// <summary>The cloud file property is possibly corrupt. The on-disk checksum does not match the computed checksum.</summary>
        error_cloud_file_property_blob_checksum_mismatch = ERROR_CLOUD_FILE_PROPERTY_BLOB_CHECKSUM_MISMATCH,
        /// <summary>The process creation has been blocked.</summary>
        error_child_process_blocked = ERROR_CHILD_PROCESS_BLOCKED,
        /// <summary>The storage device has lost data or persistence.</summary>
        error_storage_lost_data_persistence = ERROR_STORAGE_LOST_DATA_PERSISTENCE,
        /// <summary>The provider that supports file system virtualization is temporarily unavailable.</summary>
        error_file_system_virtualization_unavailable = ERROR_FILE_SYSTEM_VIRTUALIZATION_UNAVAILABLE,
        /// <summary>The metadata for file system virtualization is corrupt and unreadable.</summary>
        error_file_system_virtualization_metadata_corrupt = ERROR_FILE_SYSTEM_VIRTUALIZATION_METADATA_CORRUPT,
        /// <summary>The provider that supports file system virtualization is too busy to complete this operation.</summary>
        error_file_system_virtualization_busy = ERROR_FILE_SYSTEM_VIRTUALIZATION_BUSY,
        /// <summary>The provider that supports file system virtualization is unknown.</summary>
        error_file_system_virtualization_provider_unknown = ERROR_FILE_SYSTEM_VIRTUALIZATION_PROVIDER_UNKNOWN,
        /// <summary>GDI handles were potentially leaked by the application.</summary>
        error_gdi_handle_leak = ERROR_GDI_HANDLE_LEAK,
        /// <summary>The maximum number of cloud file properties has been reached.</summary>
        error_cloud_file_too_many_property_blobs = ERROR_CLOUD_FILE_TOO_MANY_PROPERTY_BLOBS,
        /// <summary>The version of the cloud file property store is not supported.</summary>
        error_cloud_file_property_version_not_supported = ERROR_CLOUD_FILE_PROPERTY_VERSION_NOT_SUPPORTED,
        /// <summary>The file is not a cloud file.</summary>
        error_not_a_cloud_file = ERROR_NOT_A_CLOUD_FILE,
        /// <summary>The file is not in sync with the cloud.</summary>
        error_cloud_file_not_in_sync = ERROR_CLOUD_FILE_NOT_IN_SYNC,
        /// <summary>The cloud sync root is already connected with another cloud sync provider.</summary>
        error_cloud_file_already_connected = ERROR_CLOUD_FILE_ALREADY_CONNECTED,
        /// <summary>The operation is not supported by the cloud sync provider.</summary>
        error_cloud_file_not_supported = ERROR_CLOUD_FILE_NOT_SUPPORTED,
        /// <summary>The cloud operation is invalid.</summary>
        error_cloud_file_invalid_request = ERROR_CLOUD_FILE_INVALID_REQUEST,
        /// <summary>The cloud operation is not supported on a read-only volume.</summary>
        error_cloud_file_read_only_volume = ERROR_CLOUD_FILE_READ_ONLY_VOLUME,
        /// <summary>The operation is reserved for a connected cloud sync provider.</summary>
        error_cloud_file_connected_provider_only = ERROR_CLOUD_FILE_CONNECTED_PROVIDER_ONLY,
        /// <summary>The cloud sync provider failed to validate the downloaded data.</summary>
        error_cloud_file_validation_failed = ERROR_CLOUD_FILE_VALIDATION_FAILED,
        /// <summary>You can't connect to the file share because it's not secure. This share requires the obsolete SMB1 protocol, which is unsafe and could expose your system to attack.</summary>
        /// <summary>Your system requires SMB2 or higher. For more info on resolving this issue, see: https://go.microsoft.com/fwlink/?linkid=852747</summary>
        error_smb1_not_available = ERROR_SMB1_NOT_AVAILABLE,
        /// <summary>The virtualization operation is not allowed on the file in its current state.</summary>
        error_file_system_virtualization_invalid_operation = ERROR_FILE_SYSTEM_VIRTUALIZATION_INVALID_OPERATION,
        /// <summary>The cloud sync provider failed user authentication.</summary>
        error_cloud_file_authentication_failed = ERROR_CLOUD_FILE_AUTHENTICATION_FAILED,
        /// <summary>The cloud sync provider failed to perform the operation due to low system resources.</summary>
        error_cloud_file_insufficient_resources = ERROR_CLOUD_FILE_INSUFFICIENT_RESOURCES,
        /// <summary>The cloud sync provider failed to perform the operation due to network being unavailable.</summary>
        error_cloud_file_network_unavailable = ERROR_CLOUD_FILE_NETWORK_UNAVAILABLE,
        /// <summary>The cloud operation was unsuccessful.</summary>
        error_cloud_file_unsuccessful = ERROR_CLOUD_FILE_UNSUCCESSFUL,
        /// <summary>The operation is only supported on files under a cloud sync root.</summary>
        error_cloud_file_not_under_sync_root = ERROR_CLOUD_FILE_NOT_UNDER_SYNC_ROOT,
        /// <summary>The operation cannot be performed on cloud files in use.</summary>
        error_cloud_file_in_use = ERROR_CLOUD_FILE_IN_USE,
        /// <summary>The operation cannot be performed on pinned cloud files.</summary>
        error_cloud_file_pinned = ERROR_CLOUD_FILE_PINNED,
        /// <summary>The cloud operation was aborted.</summary>
        error_cloud_file_request_aborted = ERROR_CLOUD_FILE_REQUEST_ABORTED,
        /// <summary>The cloud file's property store is corrupt.</summary>
        error_cloud_file_property_corrupt = ERROR_CLOUD_FILE_PROPERTY_CORRUPT,
        /// <summary>Access to the cloud file is denied.</summary>
        error_cloud_file_access_denied = ERROR_CLOUD_FILE_ACCESS_DENIED,
        /// <summary>The cloud operation cannot be performed on a file with incompatible hardlinks.</summary>
        error_cloud_file_incompatible_hardlinks = ERROR_CLOUD_FILE_INCOMPATIBLE_HARDLINKS,
        /// <summary>The operation failed due to a conflicting cloud file property lock.</summary>
        error_cloud_file_property_lock_conflict = ERROR_CLOUD_FILE_PROPERTY_LOCK_CONFLICT,
        /// <summary>The cloud operation was canceled by user.</summary>
        error_cloud_file_request_canceled = ERROR_CLOUD_FILE_REQUEST_CANCELED,
        /// <summary>An externally encrypted syskey has been configured, but the system no longer supports this feature.  Please see https://go.microsoft.com/fwlink/?linkid=851152 for more information.</summary>
        error_external_syskey_not_supported = ERROR_EXTERNAL_SYSKEY_NOT_SUPPORTED,
        /// <summary>The thread is already in background processing mode.</summary>
        error_thread_mode_already_background = ERROR_THREAD_MODE_ALREADY_BACKGROUND,
        /// <summary>The thread is not in background processing mode.</summary>
        error_thread_mode_not_background = ERROR_THREAD_MODE_NOT_BACKGROUND,
        /// <summary>The process is already in background processing mode.</summary>
        error_process_mode_already_background = ERROR_PROCESS_MODE_ALREADY_BACKGROUND,
        /// <summary>The process is not in background processing mode.</summary>
        error_process_mode_not_background = ERROR_PROCESS_MODE_NOT_BACKGROUND,
        /// <summary>The cloud file provider exited unexpectedly.</summary>
        error_cloud_file_provider_terminated = ERROR_CLOUD_FILE_PROVIDER_TERMINATED,
        /// <summary>The file is not a cloud sync root.</summary>
        error_not_a_cloud_sync_root = ERROR_NOT_A_CLOUD_SYNC_ROOT,
        /// <summary>The read or write operation to an encrypted file could not be completed because the file can only be accessed when the device is unlocked.</summary>
        error_file_protected_under_dpl = ERROR_FILE_PROTECTED_UNDER_DPL,
        /// <summary>The volume is not cluster aligned on the disk.</summary>
        error_volume_not_cluster_aligned = ERROR_VOLUME_NOT_CLUSTER_ALIGNED,
        /// <summary>No physically aligned free space was found on the volume.</summary>
        error_no_physically_aligned_free_space_found = ERROR_NO_PHYSICALLY_ALIGNED_FREE_SPACE_FOUND,
        /// <summary>The APPX file can not be accessed because it is not encrypted as expected.</summary>
        error_appx_file_not_encrypted = ERROR_APPX_FILE_NOT_ENCRYPTED,
        /// <summary>A read or write of raw encrypted data cannot be performed because the file is not encrypted.</summary>
        error_rwraw_encrypted_file_not_encrypted = ERROR_RWRAW_ENCRYPTED_FILE_NOT_ENCRYPTED,
        /// <summary>An invalid file offset in the encrypted data info block was passed for read or write operation of file's raw encrypted data.</summary>
        error_rwraw_encrypted_invalid_edatainfo_fileoffset = ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILEOFFSET,
        /// <summary>An invalid offset and length combination in the encrypted data info block was passed for read or write operation of file's raw encrypted data.</summary>
        error_rwraw_encrypted_invalid_edatainfo_filerange = ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILERANGE,
        /// <summary>An invalid parameter in the encrypted data info block was passed for read or write operation of file's raw encrypted data.</summary>
        error_rwraw_encrypted_invalid_edatainfo_parameter = ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_PARAMETER,
        /// <summary>The Windows Subsystem for Linux has not been enabled.</summary>
        error_linux_subsystem_not_present = ERROR_LINUX_SUBSYSTEM_NOT_PRESENT,
        /// <summary>The specified data could not be read from any of the copies.</summary>
        error_ft_read_failure = ERROR_FT_READ_FAILURE,
        /// <summary>The specified storage reserve ID is invalid.</summary>
        error_storage_reserve_id_invalid = ERROR_STORAGE_RESERVE_ID_INVALID,
        /// <summary>The specified storage reserve does not exist.</summary>
        error_storage_reserve_does_not_exist = ERROR_STORAGE_RESERVE_DOES_NOT_EXIST,
        /// <summary>The specified storage reserve already exists.</summary>
        error_storage_reserve_already_exists = ERROR_STORAGE_RESERVE_ALREADY_EXISTS,
        /// <summary>The specified storage reserve is not empty.</summary>
        error_storage_reserve_not_empty = ERROR_STORAGE_RESERVE_NOT_EMPTY,
        /// <summary>This operation requires a DAX volume.</summary>
        error_not_a_dax_volume = ERROR_NOT_A_DAX_VOLUME,
        /// <summary>This stream is not DAX mappable.</summary>
        error_not_dax_mappable = ERROR_NOT_DAX_MAPPABLE,
        /// <summary>Operation cannot be performed on a time critical thread.</summary>
        error_time_sensitive_thread = ERROR_TIME_SENSITIVE_THREAD,
        /// <summary>User data protection is not supported for the current or provided user.</summary>
        error_dpl_not_supported_for_user = ERROR_DPL_NOT_SUPPORTED_FOR_USER,
        /// <summary>This directory contains entries whose names differ only in case.</summary>
        error_case_differing_names_in_dir = ERROR_CASE_DIFFERING_NAMES_IN_DIR,
        /// <summary>The file cannot be safely opened because it is not supported by this version of Windows.</summary>
        error_file_not_supported = ERROR_FILE_NOT_SUPPORTED,
        /// <summary>The cloud operation was not completed before the time-out period expired.</summary>
        error_cloud_file_request_timeout = ERROR_CLOUD_FILE_REQUEST_TIMEOUT,
        /// <summary>A task queue is required for this operation but none is available.</summary>
        error_no_task_queue = ERROR_NO_TASK_QUEUE,
        /// <summary>Failed loading a valid version of srcsrv.dll.</summary>
        error_src_srv_dll_load_failed = ERROR_SRC_SRV_DLL_LOAD_FAILED,
        /// <summary>This operation is not supported with BTT enabled.</summary>
        error_not_supported_with_btt = ERROR_NOT_SUPPORTED_WITH_BTT,
        /// <summary>This operation cannot be performed because encryption is currently disabled.</summary>
        error_encryption_disabled = ERROR_ENCRYPTION_DISABLED,
        /// <summary>This encryption operation cannot be performed on filesystem metadata.</summary>
        error_encrypting_metadata_disallowed = ERROR_ENCRYPTING_METADATA_DISALLOWED,
        /// <summary>Encryption cannot be cleared on this file/directory because it still has an encrypted attribute.</summary>
        error_cant_clear_encryption_flag = ERROR_CANT_CLEAR_ENCRYPTION_FLAG,
        /// <summary>A device which does not exist was specified.</summary>
        error_no_such_device = ERROR_NO_SUCH_DEVICE,

        /// <summary>Neither developer unlocked mode nor side loading mode is enabled on the device.</summary>
        error_capauthz_not_devunlocked = ERROR_CAPAUTHZ_NOT_DEVUNLOCKED,
        /// <summary>Can not change application type during upgrade or re-provision.</summary>
        error_capauthz_change_type = ERROR_CAPAUTHZ_CHANGE_TYPE,
        /// <summary>The application has not been provisioned.</summary>
        error_capauthz_not_provisioned = ERROR_CAPAUTHZ_NOT_PROVISIONED,
        /// <summary>The requested capability can not be authorized for this application.</summary>
        error_capauthz_not_authorized = ERROR_CAPAUTHZ_NOT_AUTHORIZED,
        /// <summary>There is no capability authorization policy on the device.</summary>
        error_capauthz_no_policy = ERROR_CAPAUTHZ_NO_POLICY,
        /// <summary>The capability authorization database has been corrupted.</summary>
        error_capauthz_db_corrupted = ERROR_CAPAUTHZ_DB_CORRUPTED,
        /// <summary>The custom capability's SCCD has an invalid catalog.</summary>
        error_capauthz_sccd_invalid_catalog = ERROR_CAPAUTHZ_SCCD_INVALID_CATALOG,
        /// <summary>None of the authorized entity elements in the SCCD matched the app being installed; either the PFNs don't match, or the element's signature hash doesn't validate.</summary>
        error_capauthz_sccd_no_auth_entity = ERROR_CAPAUTHZ_SCCD_NO_AUTH_ENTITY,
        /// <summary>The custom capability's SCCD failed to parse.</summary>
        error_capauthz_sccd_parse_error = ERROR_CAPAUTHZ_SCCD_PARSE_ERROR,
        /// <summary>The custom capability's SCCD requires developer mode.</summary>
        error_capauthz_sccd_dev_mode_required = ERROR_CAPAUTHZ_SCCD_DEV_MODE_REQUIRED,
        /// <summary>There not all declared custom capabilities are found in the SCCD.</summary>
        error_capauthz_sccd_no_capability_match = ERROR_CAPAUTHZ_SCCD_NO_CAPABILITY_MATCH,
        /// <summary>**** Available SYSTEM error codes ****</summary>
        /// <summary>The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in its device stack. The system may need to be rebooted to complete the request.</summary>
        error_pnp_query_remove_device_timeout = ERROR_PNP_QUERY_REMOVE_DEVICE_TIMEOUT,
        /// <summary>The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in the device stack of a related device. The system may need to be rebooted to complete the operation.</summary>
        error_pnp_query_remove_related_device_timeout = ERROR_PNP_QUERY_REMOVE_RELATED_DEVICE_TIMEOUT,
        /// <summary>The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in the device stack of an unrelated device. The system may need to be rebooted to complete the operation.</summary>
        error_pnp_query_remove_unrelated_device_timeout = ERROR_PNP_QUERY_REMOVE_UNRELATED_DEVICE_TIMEOUT,
        /// <summary>The request failed due to a fatal device hardware error.</summary>
        error_device_hardware_error = ERROR_DEVICE_HARDWARE_ERROR,
        /// <summary>Attempt to access invalid address.</summary>
        error_invalid_address = ERROR_INVALID_ADDRESS,
        /// <summary>Driver Verifier Volatile settings cannot be set when CFG is enabled.</summary>
        error_vrf_cfg_enabled = ERROR_VRF_CFG_ENABLED,
        /// <summary>An attempt was made to access a partition that has begun termination.</summary>
        error_partition_terminating = ERROR_PARTITION_TERMINATING,
        /// <summary>User profile cannot be loaded.</summary>
        error_user_profile_load = ERROR_USER_PROFILE_LOAD,
        /// <summary>**** Available SYSTEM error codes ****</summary>
        /// <summary>Arithmetic result exceeded 32 bits.</summary>
        error_arithmetic_overflow = ERROR_ARITHMETIC_OVERFLOW,
        /// <summary>There is a process on other end of the pipe.</summary>
        error_pipe_connected = ERROR_PIPE_CONNECTED,
        /// <summary>Waiting for a process to open the other end of the pipe.</summary>
        error_pipe_listening = ERROR_PIPE_LISTENING,
        /// <summary>Application verifier has found an error in the current process.</summary>
        error_verifier_stop = ERROR_VERIFIER_STOP,
        /// <summary>An error occurred in the ABIOS subsystem.</summary>
        error_abios_error = ERROR_ABIOS_ERROR,
        /// <summary>A warning occurred in the WX86 subsystem.</summary>
        error_wx86_warning = ERROR_WX86_WARNING,
        /// <summary>An error occurred in the WX86 subsystem.</summary>
        error_wx86_error = ERROR_WX86_ERROR,
        /// <summary>An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.</summary>
        error_timer_not_canceled = ERROR_TIMER_NOT_CANCELED,
        /// <summary>Unwind exception code.</summary>
        error_unwind = ERROR_UNWIND,
        /// <summary>An invalid or unaligned stack was encountered during an unwind operation.</summary>
        error_bad_stack = ERROR_BAD_STACK,
        /// <summary>An invalid unwind target was encountered during an unwind operation.</summary>
        error_invalid_unwind_target = ERROR_INVALID_UNWIND_TARGET,
        /// <summary>Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort</summary>
        error_invalid_port_attributes = ERROR_INVALID_PORT_ATTRIBUTES,
        /// <summary>Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.</summary>
        error_port_message_too_long = ERROR_PORT_MESSAGE_TOO_LONG,
        /// <summary>An attempt was made to lower a quota limit below the current usage.</summary>
        error_invalid_quota_lower = ERROR_INVALID_QUOTA_LOWER,
        /// <summary>An attempt was made to attach to a device that was already attached to another device.</summary>
        error_device_already_attached = ERROR_DEVICE_ALREADY_ATTACHED,
        /// <summary>An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.</summary>
        error_instruction_misalignment = ERROR_INSTRUCTION_MISALIGNMENT,
        /// <summary>Profiling not started.</summary>
        error_profiling_not_started = ERROR_PROFILING_NOT_STARTED,
        /// <summary>Profiling not stopped.</summary>
        error_profiling_not_stopped = ERROR_PROFILING_NOT_STOPPED,
        /// <summary>The passed ACL did not contain the minimum required information.</summary>
        error_could_not_interpret = ERROR_COULD_NOT_INTERPRET,
        /// <summary>The number of active profiling objects is at the maximum and no more may be started.</summary>
        error_profiling_at_limit = ERROR_PROFILING_AT_LIMIT,
        /// <summary>Used to indicate that an operation cannot continue without blocking for I/O.</summary>
        error_cant_wait = ERROR_CANT_WAIT,
        /// <summary>Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.</summary>
        error_cant_terminate_self = ERROR_CANT_TERMINATE_SELF,
        /// <summary>If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.</summary>
        /// <summary>In this case information is lost, however, the filter correctly handles the exception.</summary>
        error_unexpected_mm_create_err = ERROR_UNEXPECTED_MM_CREATE_ERR,
        /// <summary>If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.</summary>
        /// <summary>In this case information is lost, however, the filter correctly handles the exception.</summary>
        error_unexpected_mm_map_error = ERROR_UNEXPECTED_MM_MAP_ERROR,
        /// <summary>If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.</summary>
        /// <summary>In this case information is lost, however, the filter correctly handles the exception.</summary>
        error_unexpected_mm_extend_err = ERROR_UNEXPECTED_MM_EXTEND_ERR,
        /// <summary>A malformed function table was encountered during an unwind operation.</summary>
        error_bad_function_table = ERROR_BAD_FUNCTION_TABLE,
        /// <summary>Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system.</summary>
        /// <summary>This causes the protection attempt to fail, which may cause a file creation attempt to fail.</summary>
        error_no_guid_translation = ERROR_NO_GUID_TRANSLATION,
        /// <summary>Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.</summary>
        error_invalid_ldt_size = ERROR_INVALID_LDT_SIZE,
        /// <summary>Indicates that the starting value for the LDT information was not an integral multiple of the selector size.</summary>
        error_invalid_ldt_offset = ERROR_INVALID_LDT_OFFSET,
        /// <summary>Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.</summary>
        error_invalid_ldt_descriptor = ERROR_INVALID_LDT_DESCRIPTOR,
        /// <summary>Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.</summary>
        error_too_many_threads = ERROR_TOO_MANY_THREADS,
        /// <summary>An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.</summary>
        error_thread_not_in_process = ERROR_THREAD_NOT_IN_PROCESS,
        /// <summary>Page file quota was exceeded.</summary>
        error_pagefile_quota_exceeded = ERROR_PAGEFILE_QUOTA_EXCEEDED,
        /// <summary>The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.</summary>
        error_logon_server_conflict = ERROR_LOGON_SERVER_CONFLICT,
        /// <summary>The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.</summary>
        error_synchronization_required = ERROR_SYNCHRONIZATION_REQUIRED,
        /// <summary>The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.</summary>
        error_net_open_failed = ERROR_NET_OPEN_FAILED,
        /// <summary>{Privilege Failed}</summary>
        /// <summary>The I/O permissions for the process could not be changed.</summary>
        error_io_privilege_failed = ERROR_IO_PRIVILEGE_FAILED,
        /// <summary>{Application Exit by CTRL+C}</summary>
        /// <summary>The application terminated as a result of a CTRL+C.</summary>
        error_control_c_exit = ERROR_CONTROL_C_EXIT,
        /// <summary>{Missing System File}</summary>
        /// <summary>The required system file %hs is bad or missing.</summary>
        error_missing_systemfile = ERROR_MISSING_SYSTEMFILE,
        /// <summary>{Application Error}</summary>
        /// <summary>The exception %s (0x%08lx) occurred in the application at location 0x%08lx.</summary>
        error_unhandled_exception = ERROR_UNHANDLED_EXCEPTION,
        /// <summary>{Application Error}</summary>
        /// <summary>The application was unable to start correctly (0x%lx). Click OK to close the application.</summary>
        error_app_init_failure = ERROR_APP_INIT_FAILURE,
        /// <summary>{Unable to Create Paging File}</summary>
        /// <summary>The creation of the paging file %hs failed (%lx). The requested size was %ld.</summary>
        error_pagefile_create_failed = ERROR_PAGEFILE_CREATE_FAILED,
        /// <summary>Windows cannot verify the digital signature for this file. A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.</summary>
        error_invalid_image_hash = ERROR_INVALID_IMAGE_HASH,
        /// <summary>{No Paging File Specified}</summary>
        /// <summary>No paging file was specified in the system configuration.</summary>
        error_no_pagefile = ERROR_NO_PAGEFILE,
        /// <summary>{EXCEPTION}</summary>
        /// <summary>A real-mode application issued a floating-point instruction and floating-point hardware is not present.</summary>
        error_illegal_float_context = ERROR_ILLEGAL_FLOAT_CONTEXT,
        /// <summary>An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.</summary>
        error_no_event_pair = ERROR_NO_EVENT_PAIR,
        /// <summary>A Windows Server has an incorrect configuration.</summary>
        error_domain_ctrlr_config_error = ERROR_DOMAIN_CTRLR_CONFIG_ERROR,
        /// <summary>An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.</summary>
        error_illegal_character = ERROR_ILLEGAL_CHARACTER,
        /// <summary>The Unicode character is not defined in the Unicode character set installed on the system.</summary>
        error_undefined_character = ERROR_UNDEFINED_CHARACTER,
        /// <summary>The paging file cannot be created on a floppy diskette.</summary>
        error_floppy_volume = ERROR_FLOPPY_VOLUME,
        /// <summary>The system BIOS failed to connect a system interrupt to the device or bus for which the device is connected.</summary>
        error_bios_failed_to_connect_interrupt = ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT,
        /// <summary>This operation is only allowed for the Primary Domain Controller of the domain.</summary>
        error_backup_controller = ERROR_BACKUP_CONTROLLER,
        /// <summary>An attempt was made to acquire a mutant such that its maximum count would have been exceeded.</summary>
        error_mutant_limit_exceeded = ERROR_MUTANT_LIMIT_EXCEEDED,
        /// <summary>A volume has been accessed for which a file system driver is required that has not yet been loaded.</summary>
        error_fs_driver_required = ERROR_FS_DRIVER_REQUIRED,
        /// <summary>The registry cannot load the hive (file) or its log or alternate. It is corrupt, absent, or not writable.</summary>
        error_cannot_load_registry_file = ERROR_CANNOT_LOAD_REGISTRY_FILE,
        /// <summary>{Unexpected Failure in DebugActiveProcess}</summary>
        /// <summary>An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.</summary>
        error_debug_attach_failed = ERROR_DEBUG_ATTACH_FAILED,
        /// <summary>The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x).</summary>
        error_system_process_terminated = ERROR_SYSTEM_PROCESS_TERMINATED,
        /// <summary>{Data Not Accepted}</summary>
        /// <summary>The TDI client could not handle the data received during an indication.</summary>
        error_data_not_accepted = ERROR_DATA_NOT_ACCEPTED,
        /// <summary>NTVDM encountered a hard error.</summary>
        error_vdm_hard_error = ERROR_VDM_HARD_ERROR,
        /// <summary>{Cancel Timeout}</summary>
        /// <summary>The driver %hs failed to complete a cancelled I/O request in the allotted time.</summary>
        error_driver_cancel_timeout = ERROR_DRIVER_CANCEL_TIMEOUT,
        /// <summary>{Reply Message Mismatch}</summary>
        /// <summary>An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.</summary>
        error_reply_message_mismatch = ERROR_REPLY_MESSAGE_MISMATCH,
        /// <summary>{Delayed Write Failed}</summary>
        /// <summary>Windows was unable to save all the data for the file %hs. The data has been lost.</summary>
        /// <summary>This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.</summary>
        error_lost_writebehind_data = ERROR_LOST_WRITEBEHIND_DATA,
        /// <summary>The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.</summary>
        error_client_server_parameters_invalid = ERROR_CLIENT_SERVER_PARAMETERS_INVALID,
        /// <summary>The stream is not a tiny stream.</summary>
        error_not_tiny_stream = ERROR_NOT_TINY_STREAM,
        /// <summary>The request must be handled by the stack overflow code.</summary>
        error_stack_overflow_read = ERROR_STACK_OVERFLOW_READ,
        /// <summary>Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.</summary>
        error_convert_to_large = ERROR_CONVERT_TO_LARGE,
        /// <summary>The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.</summary>
        error_found_out_of_scope = ERROR_FOUND_OUT_OF_SCOPE,
        /// <summary>The bucket array must be grown. Retry transaction after doing so.</summary>
        error_allocate_bucket = ERROR_ALLOCATE_BUCKET,
        /// <summary>The user/kernel marshalling buffer has overflowed.</summary>
        error_marshall_overflow = ERROR_MARSHALL_OVERFLOW,
        /// <summary>The supplied variant structure contains invalid data.</summary>
        error_invalid_variant = ERROR_INVALID_VARIANT,
        /// <summary>The specified buffer contains ill-formed data.</summary>
        error_bad_compression_buffer = ERROR_BAD_COMPRESSION_BUFFER,
        /// <summary>{Audit Failed}</summary>
        /// <summary>An attempt to generate a security audit failed.</summary>
        error_audit_failed = ERROR_AUDIT_FAILED,
        /// <summary>The timer resolution was not previously set by the current process.</summary>
        error_timer_resolution_not_set = ERROR_TIMER_RESOLUTION_NOT_SET,
        /// <summary>There is insufficient account information to log you on.</summary>
        error_insufficient_logon_info = ERROR_INSUFFICIENT_LOGON_INFO,
        /// <summary>{Invalid DLL Entrypoint}</summary>
        /// <summary>The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state.</summary>
        /// <summary>The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.</summary>
        error_bad_dll_entrypoint = ERROR_BAD_DLL_ENTRYPOINT,
        /// <summary>{Invalid Service Callback Entrypoint}</summary>
        /// <summary>The %hs service is not written correctly. The stack pointer has been left in an inconsistent state.</summary>
        /// <summary>The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.</summary>
        error_bad_service_entrypoint = ERROR_BAD_SERVICE_ENTRYPOINT,
        /// <summary>There is an IP address conflict with another system on the network</summary>
        error_ip_address_conflict1 = ERROR_IP_ADDRESS_CONFLICT1,
        /// <summary>There is an IP address conflict with another system on the network</summary>
        error_ip_address_conflict2 = ERROR_IP_ADDRESS_CONFLICT2,
        /// <summary>{Low On Registry Space}</summary>
        /// <summary>The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.</summary>
        error_registry_quota_limit = ERROR_REGISTRY_QUOTA_LIMIT,
        /// <summary>A callback return system service cannot be executed when no callback is active.</summary>
        error_no_callback_active = ERROR_NO_CALLBACK_ACTIVE,
        /// <summary>The password provided is too short to meet the policy of your user account.</summary>
        /// <summary>Please choose a longer password.</summary>
        error_pwd_too_short = ERROR_PWD_TOO_SHORT,
        /// <summary>The policy of your user account does not allow you to change passwords too frequently.</summary>
        /// <summary>This is done to prevent users from changing back to a familiar, but potentially discovered, password.</summary>
        /// <summary>If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.</summary>
        error_pwd_too_recent = ERROR_PWD_TOO_RECENT,
        /// <summary>You have attempted to change your password to one that you have used in the past.</summary>
        /// <summary>The policy of your user account does not allow this. Please select a password that you have not previously used.</summary>
        error_pwd_history_conflict = ERROR_PWD_HISTORY_CONFLICT,
        /// <summary>The specified compression format is unsupported.</summary>
        error_unsupported_compression = ERROR_UNSUPPORTED_COMPRESSION,
        /// <summary>The specified hardware profile configuration is invalid.</summary>
        error_invalid_hw_profile = ERROR_INVALID_HW_PROFILE,
        /// <summary>The specified Plug and Play registry device path is invalid.</summary>
        error_invalid_plugplay_device_path = ERROR_INVALID_PLUGPLAY_DEVICE_PATH,
        /// <summary>The specified quota list is internally inconsistent with its descriptor.</summary>
        error_quota_list_inconsistent = ERROR_QUOTA_LIST_INCONSISTENT,
        /// <summary>{Windows Evaluation Notification}</summary>
        /// <summary>The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.</summary>
        error_evaluation_expiration = ERROR_EVALUATION_EXPIRATION,
        /// <summary>{Illegal System DLL Relocation}</summary>
        /// <summary>The system DLL %hs was relocated in memory. The application will not run properly.</summary>
        /// <summary>The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL.</summary>
        error_illegal_dll_relocation = ERROR_ILLEGAL_DLL_RELOCATION,
        /// <summary>{DLL Initialization Failed}</summary>
        /// <summary>The application failed to initialize because the window station is shutting down.</summary>
        error_dll_init_failed_logoff = ERROR_DLL_INIT_FAILED_LOGOFF,
        /// <summary>The validation process needs to continue on to the next step.</summary>
        error_validate_continue = ERROR_VALIDATE_CONTINUE,
        /// <summary>There are no more matches for the current index enumeration.</summary>
        error_no_more_matches = ERROR_NO_MORE_MATCHES,
        /// <summary>The range could not be added to the range list because of a conflict.</summary>
        error_range_list_conflict = ERROR_RANGE_LIST_CONFLICT,
        /// <summary>The server process is running under a SID different than that required by client.</summary>
        error_server_sid_mismatch = ERROR_SERVER_SID_MISMATCH,
        /// <summary>A group marked use for deny only cannot be enabled.</summary>
        error_cant_enable_deny_only = ERROR_CANT_ENABLE_DENY_ONLY,
        /// <summary>{EXCEPTION}</summary>
        /// <summary>Multiple floating point faults.</summary>
        error_float_multiple_faults = ERROR_FLOAT_MULTIPLE_FAULTS,
        /// <summary>{EXCEPTION}</summary>
        /// <summary>Multiple floating point traps.</summary>
        error_float_multiple_traps = ERROR_FLOAT_MULTIPLE_TRAPS,
        /// <summary>The requested interface is not supported.</summary>
        error_nointerface = ERROR_NOINTERFACE,
        /// <summary>{System Standby Failed}</summary>
        /// <summary>The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.</summary>
        error_driver_failed_sleep = ERROR_DRIVER_FAILED_SLEEP,
        /// <summary>The system file %1 has become corrupt and has been replaced.</summary>
        error_corrupt_system_file = ERROR_CORRUPT_SYSTEM_FILE,
        /// <summary>{Virtual Memory Minimum Too Low}</summary>
        /// <summary>Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file.</summary>
        /// <summary>During this process, memory requests for some applications may be denied. For more information, see Help.</summary>
        error_commitment_minimum = ERROR_COMMITMENT_MINIMUM,
        /// <summary>A device was removed so enumeration must be restarted.</summary>
        error_pnp_restart_enumeration = ERROR_PNP_RESTART_ENUMERATION,
        /// <summary>{Fatal System Error}</summary>
        /// <summary>The system image %s is not properly signed.</summary>
        /// <summary>The file has been replaced with the signed file.</summary>
        /// <summary>The system has been shut down.</summary>
        error_system_image_bad_signature = ERROR_SYSTEM_IMAGE_BAD_SIGNATURE,
        /// <summary>Device will not start without a reboot.</summary>
        error_pnp_reboot_required = ERROR_PNP_REBOOT_REQUIRED,
        /// <summary>There is not enough power to complete the requested operation.</summary>
        error_insufficient_power = ERROR_INSUFFICIENT_POWER,
        /// <summary> ERROR_MULTIPLE_FAULT_VIOLATION</summary>
        error_multiple_fault_violation = ERROR_MULTIPLE_FAULT_VIOLATION,
        /// <summary>The system is in the process of shutting down.</summary>
        error_system_shutdown = ERROR_SYSTEM_SHUTDOWN,
        /// <summary>An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.</summary>
        error_port_not_set = ERROR_PORT_NOT_SET,
        /// <summary>This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.</summary>
        error_ds_version_check_failure = ERROR_DS_VERSION_CHECK_FAILURE,
        /// <summary>The specified range could not be found in the range list.</summary>
        error_range_not_found = ERROR_RANGE_NOT_FOUND,
        /// <summary>The driver was not loaded because the system is booting into safe mode.</summary>
        error_not_safe_mode_driver = ERROR_NOT_SAFE_MODE_DRIVER,
        /// <summary>The driver was not loaded because it failed its initialization call.</summary>
        error_failed_driver_entry = ERROR_FAILED_DRIVER_ENTRY,
        /// <summary>The "%hs" encountered an error while applying power or reading the device configuration.</summary>
        /// <summary>This may be caused by a failure of your hardware or by a poor connection.</summary>
        error_device_enumeration_error = ERROR_DEVICE_ENUMERATION_ERROR,
        /// <summary>The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.</summary>
        error_mount_point_not_resolved = ERROR_MOUNT_POINT_NOT_RESOLVED,
        /// <summary>The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.</summary>
        error_invalid_device_object_parameter = ERROR_INVALID_DEVICE_OBJECT_PARAMETER,
        /// <summary>A Machine Check Error has occurred. Please check the system eventlog for additional information.</summary>
        error_mca_occured = ERROR_MCA_OCCURED,
        /// <summary>There was error [%2] processing the driver database.</summary>
        error_driver_database_error = ERROR_DRIVER_DATABASE_ERROR,
        /// <summary>System hive size has exceeded its limit.</summary>
        error_system_hive_too_large = ERROR_SYSTEM_HIVE_TOO_LARGE,
        /// <summary>The driver could not be loaded because a previous version of the driver is still in memory.</summary>
        error_driver_failed_prior_unload = ERROR_DRIVER_FAILED_PRIOR_UNLOAD,
        /// <summary>{Volume Shadow Copy Service}</summary>
        /// <summary>Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.</summary>
        error_volsnap_prepare_hibernate = ERROR_VOLSNAP_PREPARE_HIBERNATE,
        /// <summary>The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.</summary>
        error_hibernation_failure = ERROR_HIBERNATION_FAILURE,
        /// <summary>The password provided is too long to meet the policy of your user account.</summary>
        /// <summary>Please choose a shorter password.</summary>
        error_pwd_too_long = ERROR_PWD_TOO_LONG,
        /// <summary>The requested operation could not be completed due to a file system limitation</summary>
        error_file_system_limitation = ERROR_FILE_SYSTEM_LIMITATION,
        /// <summary>An assertion failure has occurred.</summary>
        error_assertion_failure = ERROR_ASSERTION_FAILURE,
        /// <summary>An error occurred in the ACPI subsystem.</summary>
        error_acpi_error = ERROR_ACPI_ERROR,
        /// <summary>WOW Assertion Error.</summary>
        error_wow_assertion = ERROR_WOW_ASSERTION,
        /// <summary>A device is missing in the system BIOS MPS table. This device will not be used.</summary>
        /// <summary>Please contact your system vendor for system BIOS update.</summary>
        error_pnp_bad_mps_table = ERROR_PNP_BAD_MPS_TABLE,
        /// <summary>A translator failed to translate resources.</summary>
        error_pnp_translation_failed = ERROR_PNP_TRANSLATION_FAILED,
        /// <summary>A IRQ translator failed to translate resources.</summary>
        error_pnp_irq_translation_failed = ERROR_PNP_IRQ_TRANSLATION_FAILED,
        /// <summary>Driver %2 returned invalid ID for a child device (%3).</summary>
        error_pnp_invalid_id = ERROR_PNP_INVALID_ID,
        /// <summary>{Kernel Debugger Awakened}</summary>
        /// <summary>the system debugger was awakened by an interrupt.</summary>
        error_wake_system_debugger = ERROR_WAKE_SYSTEM_DEBUGGER,
        /// <summary>{Handles Closed}</summary>
        /// <summary>Handles to objects have been automatically closed as a result of the requested operation.</summary>
        error_handles_closed = ERROR_HANDLES_CLOSED,
        /// <summary>{Too Much Information}</summary>
        /// <summary>The specified access control list (ACL) contained more information than was expected.</summary>
        error_extraneous_information = ERROR_EXTRANEOUS_INFORMATION,
        /// <summary>This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.</summary>
        /// <summary>The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).</summary>
        error_rxact_commit_necessary = ERROR_RXACT_COMMIT_NECESSARY,
        /// <summary>{Media Changed}</summary>
        /// <summary>The media may have changed.</summary>
        error_media_check = ERROR_MEDIA_CHECK,
        /// <summary>{GUID Substitution}</summary>
        /// <summary>During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found.</summary>
        /// <summary>A substitute prefix was used, which will not compromise system security. However, this may provide a more restrictive access than intended.</summary>
        error_guid_substitution_made = ERROR_GUID_SUBSTITUTION_MADE,
        /// <summary>The create operation stopped after reaching a symbolic link</summary>
        error_stopped_on_symlink = ERROR_STOPPED_ON_SYMLINK,
        /// <summary>A long jump has been executed.</summary>
        error_longjump = ERROR_LONGJUMP,
        /// <summary>The Plug and Play query operation was not successful.</summary>
        error_plugplay_query_vetoed = ERROR_PLUGPLAY_QUERY_VETOED,
        /// <summary>A frame consolidation has been executed.</summary>
        error_unwind_consolidate = ERROR_UNWIND_CONSOLIDATE,
        /// <summary>Registry hive (file) %hs was corrupted and it has been recovered. Some data might have been lost.</summary>
        error_registry_hive_recovered = ERROR_REGISTRY_HIVE_RECOVERED,
        /// <summary>The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?</summary>
        error_dll_might_be_insecure = ERROR_DLL_MIGHT_BE_INSECURE,
        /// <summary>The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?</summary>
        error_dll_might_be_incompatible = ERROR_DLL_MIGHT_BE_INCOMPATIBLE,
        /// <summary>Debugger did not handle the exception.</summary>
        error_dbg_exception_not_handled = ERROR_DBG_EXCEPTION_NOT_HANDLED,
        /// <summary>Debugger will reply later.</summary>
        error_dbg_reply_later = ERROR_DBG_REPLY_LATER,
        /// <summary>Debugger cannot provide handle.</summary>
        error_dbg_unable_to_provide_handle = ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE,
        /// <summary>Debugger terminated thread.</summary>
        error_dbg_terminate_thread = ERROR_DBG_TERMINATE_THREAD,
        /// <summary>Debugger terminated process.</summary>
        error_dbg_terminate_process = ERROR_DBG_TERMINATE_PROCESS,
        /// <summary>Debugger got control C.</summary>
        error_dbg_control_c = ERROR_DBG_CONTROL_C,
        /// <summary>Debugger printed exception on control C.</summary>
        error_dbg_printexception_c = ERROR_DBG_PRINTEXCEPTION_C,
        /// <summary>Debugger received RIP exception.</summary>
        error_dbg_ripexception = ERROR_DBG_RIPEXCEPTION,
        /// <summary>Debugger received control break.</summary>
        error_dbg_control_break = ERROR_DBG_CONTROL_BREAK,
        /// <summary>Debugger command communication exception.</summary>
        error_dbg_command_exception = ERROR_DBG_COMMAND_EXCEPTION,
        /// <summary>{Object Exists}</summary>
        /// <summary>An attempt was made to create an object and the object name already existed.</summary>
        error_object_name_exists = ERROR_OBJECT_NAME_EXISTS,
        /// <summary>{Thread Suspended}</summary>
        /// <summary>A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.</summary>
        error_thread_was_suspended = ERROR_THREAD_WAS_SUSPENDED,
        /// <summary>{Image Relocated}</summary>
        /// <summary>An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.</summary>
        error_image_not_at_base = ERROR_IMAGE_NOT_AT_BASE,
        /// <summary>This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.</summary>
        error_rxact_state_created = ERROR_RXACT_STATE_CREATED,
        /// <summary>{Segment Load}</summary>
        /// <summary>A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image.</summary>
        /// <summary>An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.</summary>
        error_segment_notification = ERROR_SEGMENT_NOTIFICATION,
        /// <summary>{Invalid Current Directory}</summary>
        /// <summary>The process cannot switch to the startup current directory %hs.</summary>
        /// <summary>Select OK to set current directory to %hs, or select CANCEL to exit.</summary>
        error_bad_current_directory = ERROR_BAD_CURRENT_DIRECTORY,
        /// <summary>{Redundant Read}</summary>
        /// <summary>To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy.</summary>
        /// <summary>This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.</summary>
        error_ft_read_recovery_from_backup = ERROR_FT_READ_RECOVERY_FROM_BACKUP,
        /// <summary>{Redundant Write}</summary>
        /// <summary>To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information.</summary>
        /// <summary>This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.</summary>
        error_ft_write_recovery = ERROR_FT_WRITE_RECOVERY,
        /// <summary>{Machine Type Mismatch}</summary>
        /// <summary>The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.</summary>
        error_image_machine_type_mismatch = ERROR_IMAGE_MACHINE_TYPE_MISMATCH,
        /// <summary>{Partial Data Received}</summary>
        /// <summary>The network transport returned partial data to its client. The remaining data will be sent later.</summary>
        error_receive_partial = ERROR_RECEIVE_PARTIAL,
        /// <summary>{Expedited Data Received}</summary>
        /// <summary>The network transport returned data to its client that was marked as expedited by the remote system.</summary>
        error_receive_expedited = ERROR_RECEIVE_EXPEDITED,
        /// <summary>{Partial Expedited Data Received}</summary>
        /// <summary>The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.</summary>
        error_receive_partial_expedited = ERROR_RECEIVE_PARTIAL_EXPEDITED,
        /// <summary>{TDI Event Done}</summary>
        /// <summary>The TDI indication has completed successfully.</summary>
        error_event_done = ERROR_EVENT_DONE,
        /// <summary>{TDI Event Pending}</summary>
        /// <summary>The TDI indication has entered the pending state.</summary>
        error_event_pending = ERROR_EVENT_PENDING,
        /// <summary>Checking file system on %wZ</summary>
        error_checking_file_system = ERROR_CHECKING_FILE_SYSTEM,
        /// <summary>{Fatal Application Exit}</summary>
        /// <summary>%hs</summary>
        error_fatal_app_exit = ERROR_FATAL_APP_EXIT,
        /// <summary>The specified registry key is referenced by a predefined handle.</summary>
        error_predefined_handle = ERROR_PREDEFINED_HANDLE,
        /// <summary>{Page Unlocked}</summary>
        /// <summary>The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.</summary>
        error_was_unlocked = ERROR_WAS_UNLOCKED,
        /// <summary>%hs</summary>
        error_service_notification = ERROR_SERVICE_NOTIFICATION,
        /// <summary>{Page Locked}</summary>
        /// <summary>One of the pages to lock was already locked.</summary>
        error_was_locked = ERROR_WAS_LOCKED,
        /// <summary>Application popup: %1 : %2</summary>
        error_log_hard_error = ERROR_LOG_HARD_ERROR,
        /// <summary> ERROR_ALREADY_WIN32</summary>
        error_already_win32 = ERROR_ALREADY_WIN32,
        /// <summary>{Machine Type Mismatch}</summary>
        /// <summary>The image file %hs is valid, but is for a machine type other than the current machine.</summary>
        error_image_machine_type_mismatch_exe = ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE,
        /// <summary>A yield execution was performed and no thread was available to run.</summary>
        error_no_yield_performed = ERROR_NO_YIELD_PERFORMED,
        /// <summary>The resumable flag to a timer API was ignored.</summary>
        error_timer_resume_ignored = ERROR_TIMER_RESUME_IGNORED,
        /// <summary>The arbiter has deferred arbitration of these resources to its parent</summary>
        error_arbitration_unhandled = ERROR_ARBITRATION_UNHANDLED,
        /// <summary>The inserted CardBus device cannot be started because of a configuration error on "%hs".</summary>
        error_cardbus_not_supported = ERROR_CARDBUS_NOT_SUPPORTED,
        /// <summary>The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.</summary>
        error_mp_processor_mismatch = ERROR_MP_PROCESSOR_MISMATCH,
        /// <summary>The system was put into hibernation.</summary>
        error_hibernated = ERROR_HIBERNATED,
        /// <summary>The system was resumed from hibernation.</summary>
        error_resume_hibernation = ERROR_RESUME_HIBERNATION,
        /// <summary>Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].</summary>
        error_firmware_updated = ERROR_FIRMWARE_UPDATED,
        /// <summary>A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.</summary>
        error_drivers_leaking_locked_pages = ERROR_DRIVERS_LEAKING_LOCKED_PAGES,
        /// <summary>The system has awoken</summary>
        error_wake_system = ERROR_WAKE_SYSTEM,
        /// <summary> ERROR_WAIT_1</summary>
        error_wait_1 = ERROR_WAIT_1,
        /// <summary> ERROR_WAIT_2</summary>
        error_wait_2 = ERROR_WAIT_2,
        /// <summary> ERROR_WAIT_3</summary>
        error_wait_3 = ERROR_WAIT_3,
        /// <summary> ERROR_WAIT_63</summary>
        error_wait_63 = ERROR_WAIT_63,
        /// <summary> ERROR_ABANDONED_WAIT_0</summary>
        error_abandoned_wait_0 = ERROR_ABANDONED_WAIT_0,
        /// <summary> ERROR_ABANDONED_WAIT_63</summary>
        error_abandoned_wait_63 = ERROR_ABANDONED_WAIT_63,
        /// <summary> ERROR_USER_APC</summary>
        error_user_apc = ERROR_USER_APC,
        /// <summary> ERROR_KERNEL_APC</summary>
        error_kernel_apc = ERROR_KERNEL_APC,
        /// <summary> ERROR_ALERTED</summary>
        error_alerted = ERROR_ALERTED,
        /// <summary>The requested operation requires elevation.</summary>
        error_elevation_required = ERROR_ELEVATION_REQUIRED,
        /// <summary>A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.</summary>
        error_reparse = ERROR_REPARSE,
        /// <summary>An open/create operation completed while an oplock break is underway.</summary>
        error_oplock_break_in_progress = ERROR_OPLOCK_BREAK_IN_PROGRESS,
        /// <summary>A new volume has been mounted by a file system.</summary>
        error_volume_mounted = ERROR_VOLUME_MOUNTED,
        /// <summary>This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.</summary>
        /// <summary>The commit has now been completed.</summary>
        error_rxact_committed = ERROR_RXACT_COMMITTED,
        /// <summary>This indicates that a notify change request has been completed due to closing the handle which made the notify change request.</summary>
        error_notify_cleanup = ERROR_NOTIFY_CLEANUP,
        /// <summary>{Connect Failure on Primary Transport}</summary>
        /// <summary>An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed.</summary>
        /// <summary>The computer WAS able to connect on a secondary transport.</summary>
        error_primary_transport_connect_failed = ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED,
        /// <summary>Page fault was a transition fault.</summary>
        error_page_fault_transition = ERROR_PAGE_FAULT_TRANSITION,
        /// <summary>Page fault was a demand zero fault.</summary>
        error_page_fault_demand_zero = ERROR_PAGE_FAULT_DEMAND_ZERO,
        /// <summary>Page fault was a demand zero fault.</summary>
        error_page_fault_copy_on_write = ERROR_PAGE_FAULT_COPY_ON_WRITE,
        /// <summary>Page fault was a demand zero fault.</summary>
        error_page_fault_guard_page = ERROR_PAGE_FAULT_GUARD_PAGE,
        /// <summary>Page fault was satisfied by reading from a secondary storage device.</summary>
        error_page_fault_paging_file = ERROR_PAGE_FAULT_PAGING_FILE,
        /// <summary>Cached page was locked during operation.</summary>
        error_cache_page_locked = ERROR_CACHE_PAGE_LOCKED,
        /// <summary>Crash dump exists in paging file.</summary>
        error_crash_dump = ERROR_CRASH_DUMP,
        /// <summary>Specified buffer contains all zeros.</summary>
        error_buffer_all_zeros = ERROR_BUFFER_ALL_ZEROS,
        /// <summary>A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.</summary>
        error_reparse_object = ERROR_REPARSE_OBJECT,
        /// <summary>The device has succeeded a query-stop and its resource requirements have changed.</summary>
        error_resource_requirements_changed = ERROR_RESOURCE_REQUIREMENTS_CHANGED,
        /// <summary>The translator has translated these resources into the global space and no further translations should be performed.</summary>
        error_translation_complete = ERROR_TRANSLATION_COMPLETE,
        /// <summary>A process being terminated has no threads to terminate.</summary>
        error_nothing_to_terminate = ERROR_NOTHING_TO_TERMINATE,
        /// <summary>The specified process is not part of a job.</summary>
        error_process_not_in_job = ERROR_PROCESS_NOT_IN_JOB,
        /// <summary>The specified process is part of a job.</summary>
        error_process_in_job = ERROR_PROCESS_IN_JOB,
        /// <summary>{Volume Shadow Copy Service}</summary>
        /// <summary>The system is now ready for hibernation.</summary>
        error_volsnap_hibernate_ready = ERROR_VOLSNAP_HIBERNATE_READY,
        /// <summary>A file system or file system filter driver has successfully completed an FsFilter operation.</summary>
        error_fsfilter_op_completed_successfully = ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY,
        /// <summary>The specified interrupt vector was already connected.</summary>
        error_interrupt_vector_already_connected = ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED,
        /// <summary>The specified interrupt vector is still connected.</summary>
        error_interrupt_still_connected = ERROR_INTERRUPT_STILL_CONNECTED,
        /// <summary>An operation is blocked waiting for an oplock.</summary>
        error_wait_for_oplock = ERROR_WAIT_FOR_OPLOCK,
        /// <summary>Debugger handled exception</summary>
        error_dbg_exception_handled = ERROR_DBG_EXCEPTION_HANDLED,
        /// <summary>Debugger continued</summary>
        error_dbg_continue = ERROR_DBG_CONTINUE,
        /// <summary>An exception occurred in a user mode callback and the kernel callback frame should be removed.</summary>
        error_callback_pop_stack = ERROR_CALLBACK_POP_STACK,
        /// <summary>Compression is disabled for this volume.</summary>
        error_compression_disabled = ERROR_COMPRESSION_DISABLED,
        /// <summary>The data provider cannot fetch backwards through a result set.</summary>
        error_cantfetchbackwards = ERROR_CANTFETCHBACKWARDS,
        /// <summary>The data provider cannot scroll backwards through a result set.</summary>
        error_cantscrollbackwards = ERROR_CANTSCROLLBACKWARDS,
        /// <summary>The data provider requires that previously fetched data is released before asking for more data.</summary>
        error_rowsnotreleased = ERROR_ROWSNOTRELEASED,
        /// <summary>The data provider was not able to interpret the flags set for a column binding in an accessor.</summary>
        error_bad_accessor_flags = ERROR_BAD_ACCESSOR_FLAGS,
        /// <summary>One or more errors occurred while processing the request.</summary>
        error_errors_encountered = ERROR_ERRORS_ENCOUNTERED,
        /// <summary>The implementation is not capable of performing the request.</summary>
        error_not_capable = ERROR_NOT_CAPABLE,
        /// <summary>The client of a component requested an operation which is not valid given the state of the component instance.</summary>
        error_request_out_of_sequence = ERROR_REQUEST_OUT_OF_SEQUENCE,
        /// <summary>A version number could not be parsed.</summary>
        error_version_parse_error = ERROR_VERSION_PARSE_ERROR,
        /// <summary>The iterator's start position is invalid.</summary>
        error_badstartposition = ERROR_BADSTARTPOSITION,
        /// <summary>The hardware has reported an uncorrectable memory error.</summary>
        error_memory_hardware = ERROR_MEMORY_HARDWARE,
        /// <summary>The attempted operation required self healing to be enabled.</summary>
        error_disk_repair_disabled = ERROR_DISK_REPAIR_DISABLED,
        /// <summary>The Desktop heap encountered an error while allocating session memory. There is more information in the system event log.</summary>
        error_insufficient_resource_for_specified_shared_section_size = ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE,
        /// <summary>The system power state is transitioning from %2 to %3.</summary>
        error_system_powerstate_transition = ERROR_SYSTEM_POWERSTATE_TRANSITION,
        /// <summary>The system power state is transitioning from %2 to %3 but could enter %4.</summary>
        error_system_powerstate_complex_transition = ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION,
        /// <summary>A thread is getting dispatched with MCA EXCEPTION because of MCA.</summary>
        error_mca_exception = ERROR_MCA_EXCEPTION,
        /// <summary>Access to %1 is monitored by policy rule %2.</summary>
        error_access_audit_by_policy = ERROR_ACCESS_AUDIT_BY_POLICY,
        /// <summary>Access to %1 has been restricted by your Administrator by policy rule %2.</summary>
        error_access_disabled_no_safer_ui_by_policy = ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY,
        /// <summary>A valid hibernation file has been invalidated and should be abandoned.</summary>
        error_abandon_hiberfile = ERROR_ABANDON_HIBERFILE,
        /// <summary>This error may be caused by network connectivity issues. Please try to save this file elsewhere.</summary>
        error_lost_writebehind_data_network_disconnected = ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED,
        /// <summary>This error was returned by the server on which the file exists. Please try to save this file elsewhere.</summary>
        error_lost_writebehind_data_network_server_error = ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR,
        /// <summary>This error may be caused if the device has been removed or the media is write-protected.</summary>
        error_lost_writebehind_data_local_disk_error = ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR,
        /// <summary>The resources required for this device conflict with the MCFG table.</summary>
        error_bad_mcfg_table = ERROR_BAD_MCFG_TABLE,
        /// <summary>Please schedule to take the volume offline so that it can be repaired.</summary>
        error_disk_repair_redirected = ERROR_DISK_REPAIR_REDIRECTED,
        /// <summary>The volume repair was not successful.</summary>
        error_disk_repair_unsuccessful = ERROR_DISK_REPAIR_UNSUCCESSFUL,
        /// <summary>One of the volume corruption logs is full. Further corruptions that may be detected won't be logged.</summary>
        error_corrupt_log_overfull = ERROR_CORRUPT_LOG_OVERFULL,
        /// <summary>One of the volume corruption logs is internally corrupted and needs to be recreated. The volume may contain undetected corruptions and must be scanned.</summary>
        error_corrupt_log_corrupted = ERROR_CORRUPT_LOG_CORRUPTED,
        /// <summary>One of the volume corruption logs is unavailable for being operated on.</summary>
        error_corrupt_log_unavailable = ERROR_CORRUPT_LOG_UNAVAILABLE,
        /// <summary>One of the volume corruption logs was deleted while still having corruption records in them. The volume contains detected corruptions and must be scanned.</summary>
        error_corrupt_log_deleted_full = ERROR_CORRUPT_LOG_DELETED_FULL,
        /// <summary>One of the volume corruption logs was cleared by chkdsk and no longer contains real corruptions.</summary>
        error_corrupt_log_cleared = ERROR_CORRUPT_LOG_CLEARED,
        /// <summary>Orphaned files exist on the volume but could not be recovered because no more new names could be created in the recovery directory. Files must be moved from the recovery directory.</summary>
        error_orphan_name_exhausted = ERROR_ORPHAN_NAME_EXHAUSTED,
        /// <summary>The oplock that was associated with this handle is now associated with a different handle.</summary>
        error_oplock_switched_to_new_handle = ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE,
        /// <summary>An oplock of the requested level cannot be granted.  An oplock of a lower level may be available.</summary>
        error_cannot_grant_requested_oplock = ERROR_CANNOT_GRANT_REQUESTED_OPLOCK,
        /// <summary>The operation did not complete successfully because it would cause an oplock to be broken. The caller has requested that existing oplocks not be broken.</summary>
        error_cannot_break_oplock = ERROR_CANNOT_BREAK_OPLOCK,
        /// <summary>The handle with which this oplock was associated has been closed.  The oplock is now broken.</summary>
        error_oplock_handle_closed = ERROR_OPLOCK_HANDLE_CLOSED,
        /// <summary>The specified access control entry (ACE) does not contain a condition.</summary>
        error_no_ace_condition = ERROR_NO_ACE_CONDITION,
        /// <summary>The specified access control entry (ACE) contains an invalid condition.</summary>
        error_invalid_ace_condition = ERROR_INVALID_ACE_CONDITION,
        /// <summary>Access to the specified file handle has been revoked.</summary>
        error_file_handle_revoked = ERROR_FILE_HANDLE_REVOKED,
        /// <summary>An image file was mapped at a different address from the one specified in the image file but fixups will still be automatically performed on the image.</summary>
        error_image_at_different_base = ERROR_IMAGE_AT_DIFFERENT_BASE,
        /// <summary>The read or write operation to an encrypted file could not be completed because the file has not been opened for data access.</summary>
        error_encrypted_io_not_possible = ERROR_ENCRYPTED_IO_NOT_POSSIBLE,
        /// <summary>File metadata optimization is already in progress.</summary>
        error_file_metadata_optimization_in_progress = ERROR_FILE_METADATA_OPTIMIZATION_IN_PROGRESS,
        /// <summary>The requested operation failed due to quota operation is still in progress.</summary>
        error_quota_activity = ERROR_QUOTA_ACTIVITY,
        /// <summary>Access to the specified handle has been revoked.</summary>
        error_handle_revoked = ERROR_HANDLE_REVOKED,
        /// <summary>The callback function must be invoked inline.</summary>
        error_callback_invoke_inline = ERROR_CALLBACK_INVOKE_INLINE,
        /// <summary>The specified CPU Set IDs are invalid.</summary>
        error_cpu_set_invalid = ERROR_CPU_SET_INVALID,
        /// <summary>The specified enclave has not yet been terminated.</summary>
        error_enclave_not_terminated = ERROR_ENCLAVE_NOT_TERMINATED,
        /// <summary>An attempt was made to access protected memory in violation of its secure access policy.</summary>
        error_enclave_violation = ERROR_ENCLAVE_VIOLATION,
        /// <summary>**** Available SYSTEM error codes ****</summary>
        /// <summary>Access to the extended attribute was denied.</summary>
        error_ea_access_denied = ERROR_EA_ACCESS_DENIED,
        /// <summary>The I/O operation has been aborted because of either a thread exit or an application request.</summary>
        error_operation_aborted = ERROR_OPERATION_ABORTED,
        /// <summary>Overlapped I/O event is not in a signaled state.</summary>
        error_io_incomplete = ERROR_IO_INCOMPLETE,
        /// <summary>Overlapped I/O operation is in progress.</summary>
        error_io_pending = ERROR_IO_PENDING,
        /// <summary>Invalid access to memory location.</summary>
        error_noaccess = ERROR_NOACCESS,
        /// <summary>Error performing inpage operation.</summary>
        error_swaperror = ERROR_SWAPERROR,
        /// <summary>Recursion too deep; the stack overflowed.</summary>
        error_stack_overflow = ERROR_STACK_OVERFLOW,
        /// <summary>The window cannot act on the sent message.</summary>
        error_invalid_message = ERROR_INVALID_MESSAGE,
        /// <summary>Cannot complete this function.</summary>
        error_can_not_complete = ERROR_CAN_NOT_COMPLETE,
        /// <summary>Invalid flags.</summary>
        error_invalid_flags = ERROR_INVALID_FLAGS,
        /// <summary>
        /// The volume does not contain a recognized file system.
        /// Please make sure that all required file system drivers are loaded and that the volume is not corrupted.
        /// </summary>
        error_unrecognized_volume = ERROR_UNRECOGNIZED_VOLUME,
        /// <summary>The volume for a file has been externally altered so that the opened file is no longer valid.</summary>
        error_file_invalid = ERROR_FILE_INVALID,
        /// <summary>The requested operation cannot be performed in full-screen mode.</summary>
        error_fullscreen_mode = ERROR_FULLSCREEN_MODE,
        /// <summary>An attempt was made to reference a token that does not exist.</summary>
        error_no_token = ERROR_NO_TOKEN,
        /// <summary>The configuration registry database is corrupt.</summary>
        error_baddb = ERROR_BADDB,
        /// <summary>The configuration registry key is invalid.</summary>
        error_badkey = ERROR_BADKEY,
        /// <summary>The configuration registry key could not be opened.</summary>
        error_cantopen = ERROR_CANTOPEN,
        /// <summary>The configuration registry key could not be read.</summary>
        error_cantread = ERROR_CANTREAD,
        /// <summary>The configuration registry key could not be written.</summary>
        error_cantwrite = ERROR_CANTWRITE,
        /// <summary>One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.</summary>
        error_registry_recovered = ERROR_REGISTRY_RECOVERED,
        /// <summary>
        /// The registry is corrupted. The structure of one of the files containing registry data is corrupted,
        /// or the system's memory image of the file is corrupted, or the file could not be recovered because
        /// the alternate copy or log was absent or corrupted.
        /// </summary>
        error_registry_corrupt = ERROR_REGISTRY_CORRUPT,
        /// <summary>An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.</summary>
        error_registry_io_failed = ERROR_REGISTRY_IO_FAILED,
        /// <summary>The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.</summary>
        error_not_registry_file = ERROR_NOT_REGISTRY_FILE,
        /// <summary>Illegal operation attempted on a registry key that has been marked for deletion.</summary>
        error_key_deleted = ERROR_KEY_DELETED,
        /// <summary>System could not allocate the required space in a registry log.</summary>
        error_no_log_space = ERROR_NO_LOG_SPACE,
        /// <summary>Cannot create a symbolic link in a registry key that already has subkeys or values.</summary>
        error_key_has_children = ERROR_KEY_HAS_CHILDREN,
        /// <summary>Cannot create a stable subkey under a volatile parent key.</summary>
        error_child_must_be_volatile = ERROR_CHILD_MUST_BE_VOLATILE,
        /// <summary>A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes.</summary>
        error_notify_enum_dir = ERROR_NOTIFY_ENUM_DIR,
        /// <summary>A stop control has been sent to a service that other running services are dependent on.</summary>
        error_dependent_services_running = ERROR_DEPENDENT_SERVICES_RUNNING,
        /// <summary>The requested control is not valid for this service.</summary>
        error_invalid_service_control = ERROR_INVALID_SERVICE_CONTROL,
        /// <summary>The service did not respond to the start or control request in a timely fashion.</summary>
        error_service_request_timeout = ERROR_SERVICE_REQUEST_TIMEOUT,
        /// <summary>A thread could not be created for the service.</summary>
        error_service_no_thread = ERROR_SERVICE_NO_THREAD,
        /// <summary>The service database is locked.</summary>
        error_service_database_locked = ERROR_SERVICE_DATABASE_LOCKED,
        /// <summary>An instance of the service is already running.</summary>
        error_service_already_running = ERROR_SERVICE_ALREADY_RUNNING,
        /// <summary>The account name is invalid or does not exist, or the password is invalid for the account name specified.</summary>
        error_invalid_service_account = ERROR_INVALID_SERVICE_ACCOUNT,
        /// <summary>The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.</summary>
        error_service_disabled = ERROR_SERVICE_DISABLED,
        /// <summary>Circular service dependency was specified.</summary>
        error_circular_dependency = ERROR_CIRCULAR_DEPENDENCY,
        /// <summary>The specified service does not exist as an installed service.</summary>
        error_service_does_not_exist = ERROR_SERVICE_DOES_NOT_EXIST,
        /// <summary>The service cannot accept control messages at this time.</summary>
        error_service_cannot_accept_ctrl = ERROR_SERVICE_CANNOT_ACCEPT_CTRL,
        /// <summary>The service has not been started.</summary>
        error_service_not_active = ERROR_SERVICE_NOT_ACTIVE,
        /// <summary>The service process could not connect to the service controller.</summary>
        error_failed_service_controller_connect = ERROR_FAILED_SERVICE_CONTROLLER_CONNECT,
        /// <summary>An exception occurred in the service when handling the control request.</summary>
        error_exception_in_service = ERROR_EXCEPTION_IN_SERVICE,
        /// <summary>The database specified does not exist.</summary>
        error_database_does_not_exist = ERROR_DATABASE_DOES_NOT_EXIST,
        /// <summary>The service has returned a service-specific error code.</summary>
        error_service_specific_error = ERROR_SERVICE_SPECIFIC_ERROR,
        /// <summary>The process terminated unexpectedly.</summary>
        error_process_aborted = ERROR_PROCESS_ABORTED,
        /// <summary>The dependency service or group failed to start.</summary>
        error_service_dependency_fail = ERROR_SERVICE_DEPENDENCY_FAIL,
        /// <summary>The service did not start due to a logon failure.</summary>
        error_service_logon_failed = ERROR_SERVICE_LOGON_FAILED,
        /// <summary>After starting, the service hung in a start-pending state.</summary>
        error_service_start_hang = ERROR_SERVICE_START_HANG,
        /// <summary>The specified service database lock is invalid.</summary>
        error_invalid_service_lock = ERROR_INVALID_SERVICE_LOCK,
        /// <summary>The specified service has been marked for deletion.</summary>
        error_service_marked_for_delete = ERROR_SERVICE_MARKED_FOR_DELETE,
        /// <summary>The specified service already exists.</summary>
        error_service_exists = ERROR_SERVICE_EXISTS,
        /// <summary>The system is currently running with the last-known-good configuration.</summary>
        error_already_running_lkg = ERROR_ALREADY_RUNNING_LKG,
        /// <summary>The dependency service does not exist or has been marked for deletion.</summary>
        error_service_dependency_deleted = ERROR_SERVICE_DEPENDENCY_DELETED,
        /// <summary>The current boot has already been accepted for use as the last-known-good control set.</summary>
        error_boot_already_accepted = ERROR_BOOT_ALREADY_ACCEPTED,
        /// <summary>No attempts to start the service have been made since the last boot.</summary>
        error_service_never_started = ERROR_SERVICE_NEVER_STARTED,
        /// <summary>The name is already in use as either a service name or a service display name.</summary>
        error_duplicate_service_name = ERROR_DUPLICATE_SERVICE_NAME,
        /// <summary>The account specified for this service is different from the account specified for other services running in the same process.</summary>
        error_different_service_account = ERROR_DIFFERENT_SERVICE_ACCOUNT,
        /// <summary>Failure actions can only be set for Win32 services, not for drivers.</summary>
        error_cannot_detect_driver_failure = ERROR_CANNOT_DETECT_DRIVER_FAILURE,
        /// <summary>This service runs in the same process as the service control manager.</summary>
        /// <summary>Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.</summary>
        error_cannot_detect_process_abort = ERROR_CANNOT_DETECT_PROCESS_ABORT,
        /// <summary>No recovery program has been configured for this service.</summary>
        error_no_recovery_program = ERROR_NO_RECOVERY_PROGRAM,
        /// <summary>The executable program that this service is configured to run in does not implement the service.</summary>
        error_service_not_in_exe = ERROR_SERVICE_NOT_IN_EXE,
        /// <summary>This service cannot be started in Safe Mode</summary>
        error_not_safeboot_service = ERROR_NOT_SAFEBOOT_SERVICE,
        /// <summary>The physical end of the tape has been reached.</summary>
        error_end_of_media = ERROR_END_OF_MEDIA,
        /// <summary>A tape access reached a filemark.</summary>
        error_filemark_detected = ERROR_FILEMARK_DETECTED,
        /// <summary>The beginning of the tape or a partition was encountered.</summary>
        error_beginning_of_media = ERROR_BEGINNING_OF_MEDIA,
        /// <summary>A tape access reached the end of a set of files.</summary>
        error_setmark_detected = ERROR_SETMARK_DETECTED,
        /// <summary>No more data is on the tape.</summary>
        error_no_data_detected = ERROR_NO_DATA_DETECTED,
        /// <summary>Tape could not be partitioned.</summary>
        error_partition_failure = ERROR_PARTITION_FAILURE,
        /// <summary>When accessing a new tape of a multivolume partition, the current block size is incorrect.</summary>
        error_invalid_block_length = ERROR_INVALID_BLOCK_LENGTH,
        /// <summary>Tape partition information could not be found when loading a tape.</summary>
        error_device_not_partitioned = ERROR_DEVICE_NOT_PARTITIONED,
        /// <summary>Unable to lock the media eject mechanism.</summary>
        error_unable_to_lock_media = ERROR_UNABLE_TO_LOCK_MEDIA,
        /// <summary>Unable to unload the media.</summary>
        error_unable_to_unload_media = ERROR_UNABLE_TO_UNLOAD_MEDIA,
        /// <summary>The media in the drive may have changed.</summary>
        error_media_changed = ERROR_MEDIA_CHANGED,
        /// <summary>The I/O bus was reset.</summary>
        error_bus_reset = ERROR_BUS_RESET,
        /// <summary>No media in drive.</summary>
        error_no_media_in_drive = ERROR_NO_MEDIA_IN_DRIVE,
        /// <summary>No mapping for the Unicode character exists in the target multi-byte code page.</summary>
        error_no_unicode_translation = ERROR_NO_UNICODE_TRANSLATION,
        /// <summary>A dynamic link library (DLL) initialization routine failed.</summary>
        error_dll_init_failed = ERROR_DLL_INIT_FAILED,
        /// <summary>A system shutdown is in progress.</summary>
        error_shutdown_in_progress = ERROR_SHUTDOWN_IN_PROGRESS,
        /// <summary>Unable to abort the system shutdown because no shutdown was in progress.</summary>
        error_no_shutdown_in_progress = ERROR_NO_SHUTDOWN_IN_PROGRESS,
        /// <summary>The request could not be performed because of an I/O device error.</summary>
        error_io_device = ERROR_IO_DEVICE,
        /// <summary>No serial device was successfully initialized. The serial driver will unload.</summary>
        error_serial_no_device = ERROR_SERIAL_NO_DEVICE,
        /// <summary>Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened.</summary>
        error_irq_busy = ERROR_IRQ_BUSY,
        /// <summary>A serial I/O operation was completed by another write to the serial port.</summary>
        /// <summary>(The IOCTL_SERIAL_XOFF_COUNTER reached zero.)</summary>
        error_more_writes = ERROR_MORE_WRITES,
        /// <summary>A serial I/O operation completed because the timeout period expired.</summary>
        /// <summary>(The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)</summary>
        error_counter_timeout = ERROR_COUNTER_TIMEOUT,
        /// <summary>No ID address mark was found on the floppy disk.</summary>
        error_floppy_id_mark_not_found = ERROR_FLOPPY_ID_MARK_NOT_FOUND,
        /// <summary>Mismatch between the floppy disk sector ID field and the floppy disk controller track address.</summary>
        error_floppy_wrong_cylinder = ERROR_FLOPPY_WRONG_CYLINDER,
        /// <summary>The floppy disk controller reported an error that is not recognized by the floppy disk driver.</summary>
        error_floppy_unknown_error = ERROR_FLOPPY_UNKNOWN_ERROR,
        /// <summary>The floppy disk controller returned inconsistent results in its registers.</summary>
        error_floppy_bad_registers = ERROR_FLOPPY_BAD_REGISTERS,
        /// <summary>While accessing the hard disk, a recalibrate operation failed, even after retries.</summary>
        error_disk_recalibrate_failed = ERROR_DISK_RECALIBRATE_FAILED,
        /// <summary>While accessing the hard disk, a disk operation failed even after retries.</summary>
        error_disk_operation_failed = ERROR_DISK_OPERATION_FAILED,
        /// <summary>While accessing the hard disk, a disk controller reset was needed, but even that failed.</summary>
        error_disk_reset_failed = ERROR_DISK_RESET_FAILED,
        /// <summary>Physical end of tape encountered.</summary>
        error_eom_overflow = ERROR_EOM_OVERFLOW,
        /// <summary>Not enough server memory resources are available to process this command.</summary>
        error_not_enough_server_memory = ERROR_NOT_ENOUGH_SERVER_MEMORY,
        /// <summary>A potential deadlock condition has been detected.</summary>
        error_possible_deadlock = ERROR_POSSIBLE_DEADLOCK,
        /// <summary>The base address or the file offset specified does not have the proper alignment.</summary>
        error_mapped_alignment = ERROR_MAPPED_ALIGNMENT,
        /// <summary>An attempt to change the system power state was vetoed by another application or driver.</summary>
        error_set_power_state_vetoed = ERROR_SET_POWER_STATE_VETOED,
        /// <summary>The system BIOS failed an attempt to change the system power state.</summary>
        error_set_power_state_failed = ERROR_SET_POWER_STATE_FAILED,
        /// <summary>An attempt was made to create more links on a file than the file system supports.</summary>
        error_too_many_links = ERROR_TOO_MANY_LINKS,
        /// <summary>The specified program requires a newer version of Windows.</summary>
        error_old_win_version = ERROR_OLD_WIN_VERSION,
        /// <summary>The specified program is not a Windows or MS-DOS program.</summary>
        error_app_wrong_os = ERROR_APP_WRONG_OS,
        /// <summary>Cannot start more than one instance of the specified program.</summary>
        error_single_instance_app = ERROR_SINGLE_INSTANCE_APP,
        /// <summary>The specified program was written for an earlier version of Windows.</summary>
        error_rmode_app = ERROR_RMODE_APP,
        /// <summary>One of the library files needed to run this application is damaged.</summary>
        error_invalid_dll = ERROR_INVALID_DLL,
        /// <summary>No application is associated with the specified file for this operation.</summary>
        error_no_association = ERROR_NO_ASSOCIATION,
        /// <summary>An error occurred in sending the command to the application.</summary>
        error_dde_fail = ERROR_DDE_FAIL,
        /// <summary>One of the library files needed to run this application cannot be found.</summary>
        error_dll_not_found = ERROR_DLL_NOT_FOUND,
        /// <summary>The current process has used all of its system allowance of handles for Window Manager objects.</summary>
        error_no_more_user_handles = ERROR_NO_MORE_USER_HANDLES,
        /// <summary>The message can be used only with synchronous operations.</summary>
        error_message_sync_only = ERROR_MESSAGE_SYNC_ONLY,
        /// <summary>The indicated source element has no media.</summary>
        error_source_element_empty = ERROR_SOURCE_ELEMENT_EMPTY,
        /// <summary>The indicated destination element already contains media.</summary>
        error_destination_element_full = ERROR_DESTINATION_ELEMENT_FULL,
        /// <summary>The indicated element does not exist.</summary>
        error_illegal_element_address = ERROR_ILLEGAL_ELEMENT_ADDRESS,
        /// <summary>The indicated element is part of a magazine that is not present.</summary>
        error_magazine_not_present = ERROR_MAGAZINE_NOT_PRESENT,
        /// <summary>The indicated device requires reinitialization due to hardware errors.</summary>
        error_device_reinitialization_needed = ERROR_DEVICE_REINITIALIZATION_NEEDED,
        /// <summary>The device has indicated that cleaning is required before further operations are attempted.</summary>
        error_device_requires_cleaning = ERROR_DEVICE_REQUIRES_CLEANING,
        /// <summary>The device has indicated that its door is open.</summary>
        error_device_door_open = ERROR_DEVICE_DOOR_OPEN,
        /// <summary>The device is not connected.</summary>
        error_device_not_connected = ERROR_DEVICE_NOT_CONNECTED,
        /// <summary>Element not found.</summary>
        error_not_found = ERROR_NOT_FOUND,
        /// <summary>There was no match for the specified key in the index.</summary>
        error_no_match = ERROR_NO_MATCH,
        /// <summary>The property set specified does not exist on the object.</summary>
        error_set_not_found = ERROR_SET_NOT_FOUND,
        /// <summary>The point passed to GetMouseMovePoints is not in the buffer.</summary>
        error_point_not_found = ERROR_POINT_NOT_FOUND,
        /// <summary>The tracking (workstation) service is not running.</summary>
        error_no_tracking_service = ERROR_NO_TRACKING_SERVICE,
        /// <summary>The Volume ID could not be found.</summary>
        error_no_volume_id = ERROR_NO_VOLUME_ID,
        /// <summary>Unable to remove the file to be replaced.</summary>
        error_unable_to_remove_replaced = ERROR_UNABLE_TO_REMOVE_REPLACED,
        /// <summary>Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name.</summary>
        error_unable_to_move_replacement = ERROR_UNABLE_TO_MOVE_REPLACEMENT,
        /// <summary>Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name.</summary>

        error_unable_to_move_replacement_2 = ERROR_UNABLE_TO_MOVE_REPLACEMENT_2,
        /// <summary>The volume change journal is being deleted.</summary>

        error_journal_delete_in_progress = ERROR_JOURNAL_DELETE_IN_PROGRESS,
        /// <summary>The volume change journal is not active.</summary>

        error_journal_not_active = ERROR_JOURNAL_NOT_ACTIVE,
        /// <summary>A file was found, but it may not be the correct file.</summary>

        error_potential_file_found = ERROR_POTENTIAL_FILE_FOUND,
        /// <summary>The journal entry has been deleted from the journal.</summary>

        error_journal_entry_deleted = ERROR_JOURNAL_ENTRY_DELETED,
        /// <summary>A system shutdown has already been scheduled.</summary>

        error_shutdown_is_scheduled = ERROR_SHUTDOWN_IS_SCHEDULED,
        /// <summary>The system shutdown cannot be initiated because there are other users logged on to the computer.</summary>

        error_shutdown_users_logged_on = ERROR_SHUTDOWN_USERS_LOGGED_ON,
        /// <summary>The specified device name is invalid.</summary>

        error_bad_device = ERROR_BAD_DEVICE,
        /// <summary>The device is not currently connected but it is a remembered connection.</summary>

        error_connection_unavail = ERROR_CONNECTION_UNAVAIL,
        /// <summary>The local device name has a remembered connection to another network resource.</summary>

        error_device_already_remembered = ERROR_DEVICE_ALREADY_REMEMBERED,
        /// <summary>The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator.</summary>

        error_no_net_or_bad_path = ERROR_NO_NET_OR_BAD_PATH,
        /// <summary>The specified network provider name is invalid.</summary>

        error_bad_provider = ERROR_BAD_PROVIDER,
        /// <summary>Unable to open the network connection profile.</summary>

        error_cannot_open_profile = ERROR_CANNOT_OPEN_PROFILE,
        /// <summary>The network connection profile is corrupted.</summary>

        error_bad_profile = ERROR_BAD_PROFILE,
        /// <summary>Cannot enumerate a noncontainer.</summary>

        error_not_container = ERROR_NOT_CONTAINER,
        /// <summary>An extended error has occurred.</summary>

        error_extended_error = ERROR_EXTENDED_ERROR,
        /// <summary>The format of the specified group name is invalid.</summary>

        error_invalid_groupname = ERROR_INVALID_GROUPNAME,
        /// <summary>The format of the specified computer name is invalid.</summary>

        error_invalid_computername = ERROR_INVALID_COMPUTERNAME,
        /// <summary>The format of the specified event name is invalid.</summary>

        error_invalid_eventname = ERROR_INVALID_EVENTNAME,
        /// <summary>The format of the specified domain name is invalid.</summary>

        error_invalid_domainname = ERROR_INVALID_DOMAINNAME,
        /// <summary>The format of the specified service name is invalid.</summary>

        error_invalid_servicename = ERROR_INVALID_SERVICENAME,
        /// <summary>The format of the specified network name is invalid.</summary>

        error_invalid_netname = ERROR_INVALID_NETNAME,
        /// <summary>The format of the specified share name is invalid.</summary>

        error_invalid_sharename = ERROR_INVALID_SHARENAME,
        /// <summary>The format of the specified password is invalid.</summary>

        error_invalid_passwordname = ERROR_INVALID_PASSWORDNAME,
        /// <summary>The format of the specified message name is invalid.</summary>

        error_invalid_messagename = ERROR_INVALID_MESSAGENAME,
        /// <summary>The format of the specified message destination is invalid.</summary>

        error_invalid_messagedest = ERROR_INVALID_MESSAGEDEST,
        /// <summary>Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.</summary>

        error_session_credential_conflict = ERROR_SESSION_CREDENTIAL_CONFLICT,
        /// <summary>An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.</summary>

        error_remote_session_limit_exceeded = ERROR_REMOTE_SESSION_LIMIT_EXCEEDED,
        /// <summary>The workgroup or domain name is already in use by another computer on the network.</summary>

        error_dup_domainname = ERROR_DUP_DOMAINNAME,
        /// <summary>The network is not present or not started.</summary>

        error_no_network = ERROR_NO_NETWORK,
        /// <summary>The operation was canceled by the user.</summary>

        error_cancelled = ERROR_CANCELLED,
        /// <summary>The requested operation cannot be performed on a file with a user-mapped section open.</summary>

        error_user_mapped_file = ERROR_USER_MAPPED_FILE,
        /// <summary>The remote computer refused the network connection.</summary>

        error_connection_refused = ERROR_CONNECTION_REFUSED,
        /// <summary>The network connection was gracefully closed.</summary>

        error_graceful_disconnect = ERROR_GRACEFUL_DISCONNECT,
        /// <summary>The network transport endpoint already has an address associated with it.</summary>

        error_address_already_associated = ERROR_ADDRESS_ALREADY_ASSOCIATED,
        /// <summary>An address has not yet been associated with the network endpoint.</summary>

        error_address_not_associated = ERROR_ADDRESS_NOT_ASSOCIATED,
        /// <summary>An operation was attempted on a nonexistent network connection.</summary>

        error_connection_invalid = ERROR_CONNECTION_INVALID,
        /// <summary>An invalid operation was attempted on an active network connection.</summary>

        error_connection_active = ERROR_CONNECTION_ACTIVE,
        /// <summary>The network location cannot be reached. For information about network troubleshooting, see Windows Help.</summary>

        error_network_unreachable = ERROR_NETWORK_UNREACHABLE,
        /// <summary>The network location cannot be reached. For information about network troubleshooting, see Windows Help.</summary>

        error_host_unreachable = ERROR_HOST_UNREACHABLE,
        /// <summary>The network location cannot be reached. For information about network troubleshooting, see Windows Help.</summary>

        error_protocol_unreachable = ERROR_PROTOCOL_UNREACHABLE,
        /// <summary>No service is operating at the destination network endpoint on the remote system.</summary>

        error_port_unreachable = ERROR_PORT_UNREACHABLE,
        /// <summary>The request was aborted.</summary>

        error_request_aborted = ERROR_REQUEST_ABORTED,
        /// <summary>The network connection was aborted by the local system.</summary>

        error_connection_aborted = ERROR_CONNECTION_ABORTED,
        /// <summary>The operation could not be completed. A retry should be performed.</summary>

        error_retry = ERROR_RETRY,
        /// <summary>A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.</summary>

        error_connection_count_limit = ERROR_CONNECTION_COUNT_LIMIT,
        /// <summary>Attempting to log in during an unauthorized time of day for this account.</summary>

        error_login_time_restriction = ERROR_LOGIN_TIME_RESTRICTION,
        /// <summary>The account is not authorized to log in from this station.</summary>

        error_login_wksta_restriction = ERROR_LOGIN_WKSTA_RESTRICTION,
        /// <summary>The network address could not be used for the operation requested.</summary>

        error_incorrect_address = ERROR_INCORRECT_ADDRESS,
        /// <summary>The service is already registered.</summary>

        error_already_registered = ERROR_ALREADY_REGISTERED,
        /// <summary>The specified service does not exist.</summary>

        error_service_not_found = ERROR_SERVICE_NOT_FOUND,
        /// <summary>The operation being requested was not performed because the user has not been authenticated.</summary>

        error_not_authenticated = ERROR_NOT_AUTHENTICATED,
        /// <summary>The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist.</summary>

        error_not_logged_on = ERROR_NOT_LOGGED_ON,
        /// <summary>Continue with work in progress.</summary>

        error_continue = ERROR_CONTINUE,
        /// <summary>An attempt was made to perform an initialization operation when initialization has already been completed.</summary>

        error_already_initialized = ERROR_ALREADY_INITIALIZED,
        /// <summary>No more local devices.</summary>

        error_no_more_devices = ERROR_NO_MORE_DEVICES,
        /// <summary>The specified site does not exist.</summary>

        error_no_such_site = ERROR_NO_SUCH_SITE,
        /// <summary>A domain controller with the specified name already exists.</summary>

        error_domain_controller_exists = ERROR_DOMAIN_CONTROLLER_EXISTS,
        /// <summary>This operation is supported only when you are connected to the server.</summary>

        error_only_if_connected = ERROR_ONLY_IF_CONNECTED,
        /// <summary>The group policy framework should call the extension even if there are no changes.</summary>

        error_override_nochanges = ERROR_OVERRIDE_NOCHANGES,
        /// <summary>The specified user does not have a valid profile.</summary>

        error_bad_user_profile = ERROR_BAD_USER_PROFILE,
        /// <summary>This operation is not supported on a computer running Windows Server 2003 for Small Business Server</summary>

        error_not_supported_on_sbs = ERROR_NOT_SUPPORTED_ON_SBS,
        /// <summary>The server machine is shutting down.</summary>

        error_server_shutdown_in_progress = ERROR_SERVER_SHUTDOWN_IN_PROGRESS,
        /// <summary>The remote system is not available. For information about network troubleshooting, see Windows Help.</summary>

        error_host_down = ERROR_HOST_DOWN,
        /// <summary>The security identifier provided is not from an account domain.</summary>

        error_non_account_sid = ERROR_NON_ACCOUNT_SID,
        /// <summary>The security identifier provided does not have a domain component.</summary>

        error_non_domain_sid = ERROR_NON_DOMAIN_SID,
        /// <summary>AppHelp dialog canceled thus preventing the application from starting.</summary>

        error_apphelp_block = ERROR_APPHELP_BLOCK,
        /// <summary>This program is blocked by group policy. For more information, contact your system administrator.</summary>

        error_access_disabled_by_policy = ERROR_ACCESS_DISABLED_BY_POLICY,
        /// <summary>A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific.</summary>

        error_reg_nat_consumption = ERROR_REG_NAT_CONSUMPTION,
        /// <summary>The share is currently offline or does not exist.</summary>

        error_cscshare_offline = ERROR_CSCSHARE_OFFLINE,
        /// <summary>The Kerberos protocol encountered an error while validating the KDC certificate during smartcard logon. There is more information in the system event log.</summary>

        error_pkinit_failure = ERROR_PKINIT_FAILURE,
        /// <summary>The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.</summary>

        error_smartcard_subsystem_failure = ERROR_SMARTCARD_SUBSYSTEM_FAILURE,
        /// <summary>The system cannot contact a domain controller to service the authentication request. Please try again later.</summary>

        error_downgrade_detected = ERROR_DOWNGRADE_DETECTED,
        /// <summary>Do not use ID's 1266 - 1270 as the symbolicNames have been moved to SEC_E_*</summary>
        /// <summary>The machine is locked and cannot be shut down without the force option.</summary>

        error_machine_locked = ERROR_MACHINE_LOCKED,
        /// <summary>You can't access this shared folder because your organization's security policies block unauthenticated guest access. These policies help protect your PC from unsafe or malicious devices on the network.</summary>

        error_smb_guest_logon_blocked = ERROR_SMB_GUEST_LOGON_BLOCKED,
        /// <summary>An application-defined callback gave invalid data when called.</summary>

        error_callback_supplied_invalid_data = ERROR_CALLBACK_SUPPLIED_INVALID_DATA,
        /// <summary>The group policy framework should call the extension in the synchronous foreground policy refresh.</summary>

        error_sync_foreground_refresh_required = ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED,
        /// <summary>This driver has been blocked from loading</summary>

        error_driver_blocked = ERROR_DRIVER_BLOCKED,
        /// <summary>A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.</summary>

        error_invalid_import_of_non_dll = ERROR_INVALID_IMPORT_OF_NON_DLL,
        /// <summary>Windows cannot open this program since it has been disabled.</summary>

        error_access_disabled_webblade = ERROR_ACCESS_DISABLED_WEBBLADE,
        /// <summary>Windows cannot open this program because the license enforcement system has been tampered with or become corrupted.</summary>

        error_access_disabled_webblade_tamper = ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER,
        /// <summary>A transaction recover failed.</summary>

        error_recovery_failure = ERROR_RECOVERY_FAILURE,
        /// <summary>The current thread has already been converted to a fiber.</summary>

        error_already_fiber = ERROR_ALREADY_FIBER,
        /// <summary>The current thread has already been converted from a fiber.</summary>

        error_already_thread = ERROR_ALREADY_THREAD,
        /// <summary>The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.</summary>

        error_stack_buffer_overrun = ERROR_STACK_BUFFER_OVERRUN,
        /// <summary>Data present in one of the parameters is more than the function can operate on.</summary>

        error_parameter_quota_exceeded = ERROR_PARAMETER_QUOTA_EXCEEDED,
        /// <summary>An attempt to do an operation on a debug object failed because the object is in the process of being deleted.</summary>

        error_debugger_inactive = ERROR_DEBUGGER_INACTIVE,
        /// <summary>An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.</summary>

        error_delay_load_failed = ERROR_DELAY_LOAD_FAILED,
        /// <summary>%1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.</summary>

        error_vdm_disallowed = ERROR_VDM_DISALLOWED,
        /// <summary>Insufficient information exists to identify the cause of failure.</summary>

        error_unidentified_error = ERROR_UNIDENTIFIED_ERROR,
        /// <summary>The parameter passed to a C runtime function is incorrect.</summary>

        error_invalid_cruntime_parameter = ERROR_INVALID_CRUNTIME_PARAMETER,
        /// <summary>The operation occurred beyond the valid data length of the file.</summary>

        error_beyond_vdl = ERROR_BEYOND_VDL,
        /// <summary>The service start failed since one or more services in the same process have an incompatible service SID type setting. A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type. If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service.</summary>

        error_incompatible_service_sid_type = ERROR_INCOMPATIBLE_SERVICE_SID_TYPE,
        /// <summary>The process hosting the driver for this device has been terminated.</summary>

        error_driver_process_terminated = ERROR_DRIVER_PROCESS_TERMINATED,
        /// <summary>An operation attempted to exceed an implementation-defined limit.</summary>

        error_implementation_limit = ERROR_IMPLEMENTATION_LIMIT,
        /// <summary>Either the target process, or the target thread's containing process, is a protected process.</summary>
        error_process_is_protected = ERROR_PROCESS_IS_PROTECTED,

        /// <summary>The service notification client is lagging too far behind the current state of services in the machine.</summary>
        error_service_notify_client_lagging = ERROR_SERVICE_NOTIFY_CLIENT_LAGGING,

        /// <summary>
        /// The requested file operation failed because the storage quota was exceeded.
        /// To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator.
        /// </summary>
        error_disk_quota_exceeded = ERROR_DISK_QUOTA_EXCEEDED,

        /// <summary>The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator.</summary>
        error_content_blocked = ERROR_CONTENT_BLOCKED,

        /// <summary>
        /// A privilege that the service requires to function properly does not exist in the service account configuration.
        /// You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration.
        /// </summary>
        error_incompatible_service_privilege = ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE,
        /// <summary>A thread involved in this operation appears to be unresponsive.</summary>

        error_app_hang = ERROR_APP_HANG,
        /// <summary>Indicates a particular Security ID may not be assigned as the label of an object.</summary>
        error_invalid_label = ERROR_INVALID_LABEL,

        /// <summary>Not all privileges or groups referenced are assigned to the caller.</summary>
        error_not_all_assigned = ERROR_NOT_ALL_ASSIGNED,

        /// <summary>Some mapping between account names and security IDs was not done.</summary>
        error_some_not_mapped = ERROR_SOME_NOT_MAPPED,

        /// <summary>No system quota limits are specifically set for this account.</summary>
        error_no_quotas_for_account = ERROR_NO_QUOTAS_FOR_ACCOUNT,

        /// <summary>No encryption key is available. A well-known encryption key was returned.</summary>
        error_local_user_session_key = ERROR_LOCAL_USER_SESSION_KEY,
        /// <summary>The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.</summary>

        error_null_lm_password = ERROR_NULL_LM_PASSWORD,
        /// <summary>The revision level is unknown.</summary>

        error_unknown_revision = ERROR_UNKNOWN_REVISION,
        /// <summary>Indicates two revision levels are incompatible.</summary>

        error_revision_mismatch = ERROR_REVISION_MISMATCH,
        /// <summary>This security ID may not be assigned as the owner of this object.</summary>

        error_invalid_owner = ERROR_INVALID_OWNER,
        /// <summary>This security ID may not be assigned as the primary group of an object.</summary>

        error_invalid_primary_group = ERROR_INVALID_PRIMARY_GROUP,
        /// <summary>An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.</summary>

        error_no_impersonation_token = ERROR_NO_IMPERSONATION_TOKEN,
        /// <summary>The group may not be disabled.</summary>

        error_cant_disable_mandatory = ERROR_CANT_DISABLE_MANDATORY,
        /// <summary>We can't sign you in with this credential because your domain isn't available. Make sure your device is connected to your organization's network and try again. If you previously signed in on this device with another credential, you can sign in with that credential.</summary>

        error_no_logon_servers = ERROR_NO_LOGON_SERVERS,
        /// <summary>A specified logon session does not exist. It may already have been terminated.</summary>

        error_no_such_logon_session = ERROR_NO_SUCH_LOGON_SESSION,
        /// <summary>A specified privilege does not exist.</summary>

        error_no_such_privilege = ERROR_NO_SUCH_PRIVILEGE,
        /// <summary>A required privilege is not held by the client.</summary>

        error_privilege_not_held = ERROR_PRIVILEGE_NOT_HELD,
        /// <summary>The name provided is not a properly formed account name.</summary>

        error_invalid_account_name = ERROR_INVALID_ACCOUNT_NAME,
        /// <summary>The specified account already exists.</summary>

        error_user_exists = ERROR_USER_EXISTS,
        /// <summary>The specified account does not exist.</summary>

        error_no_such_user = ERROR_NO_SUCH_USER,
        /// <summary>The specified group already exists.</summary>

        error_group_exists = ERROR_GROUP_EXISTS,
        /// <summary>The specified group does not exist.</summary>

        error_no_such_group = ERROR_NO_SUCH_GROUP,
        /// <summary>Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.</summary>

        error_member_in_group = ERROR_MEMBER_IN_GROUP,
        /// <summary>The specified user account is not a member of the specified group account.</summary>

        error_member_not_in_group = ERROR_MEMBER_NOT_IN_GROUP,
        /// <summary>This operation is disallowed as it could result in an administration account being disabled, deleted or unable to logon.</summary>

        error_last_admin = ERROR_LAST_ADMIN,
        /// <summary>Unable to update the password. The value provided as the current password is incorrect.</summary>

        error_wrong_password = ERROR_WRONG_PASSWORD,
        /// <summary>Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.</summary>

        error_ill_formed_password = ERROR_ILL_FORMED_PASSWORD,
        /// <summary>Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain.</summary>

        error_password_restriction = ERROR_PASSWORD_RESTRICTION,
        /// <summary>The user name or password is incorrect.</summary>

        error_logon_failure = ERROR_LOGON_FAILURE,
        /// <summary>Account restrictions are preventing this user from signing in. For example: blank passwords aren't allowed, sign-in times are limited, or a policy restriction has been enforced.</summary>

        error_account_restriction = ERROR_ACCOUNT_RESTRICTION,
        /// <summary>Your account has time restrictions that keep you from signing in right now.</summary>

        error_invalid_logon_hours = ERROR_INVALID_LOGON_HOURS,
        /// <summary>This user isn't allowed to sign in to this computer.</summary>

        error_invalid_workstation = ERROR_INVALID_WORKSTATION,
        /// <summary>The password for this account has expired.</summary>

        error_password_expired = ERROR_PASSWORD_EXPIRED,
        /// <summary>This user can't sign in because this account is currently disabled.</summary>

        error_account_disabled = ERROR_ACCOUNT_DISABLED,
        /// <summary>No mapping between account names and security IDs was done.</summary>

        error_none_mapped = ERROR_NONE_MAPPED,
        /// <summary>Too many local user identifiers (LUIDs) were requested at one time.</summary>

        error_too_many_luids_requested = ERROR_TOO_MANY_LUIDS_REQUESTED,
        /// <summary>No more local user identifiers (LUIDs) are available.</summary>

        error_luids_exhausted = ERROR_LUIDS_EXHAUSTED,
        /// <summary>The subauthority part of a security ID is invalid for this particular use.</summary>

        error_invalid_sub_authority = ERROR_INVALID_SUB_AUTHORITY,
        /// <summary>The access control list (ACL) structure is invalid.</summary>

        error_invalid_acl = ERROR_INVALID_ACL,
        /// <summary>The security ID structure is invalid.</summary>

        error_invalid_sid = ERROR_INVALID_SID,
        /// <summary>The security descriptor structure is invalid.</summary>

        error_invalid_security_descr = ERROR_INVALID_SECURITY_DESCR,
        /// <summary>The inherited access control list (ACL) or access control entry (ACE) could not be built.</summary>

        error_bad_inheritance_acl = ERROR_BAD_INHERITANCE_ACL,
        /// <summary>The server is currently disabled.</summary>

        error_server_disabled = ERROR_SERVER_DISABLED,
        /// <summary>The server is currently enabled.</summary>

        error_server_not_disabled = ERROR_SERVER_NOT_DISABLED,
        /// <summary>The value provided was an invalid value for an identifier authority.</summary>

        error_invalid_id_authority = ERROR_INVALID_ID_AUTHORITY,
        /// <summary>No more memory is available for security information updates.</summary>

        error_allotted_space_exceeded = ERROR_ALLOTTED_SPACE_EXCEEDED,
        /// <summary>The specified attributes are invalid, or incompatible with the attributes for the group as a whole.</summary>

        error_invalid_group_attributes = ERROR_INVALID_GROUP_ATTRIBUTES,
        /// <summary>Either a required impersonation level was not provided, or the provided impersonation level is invalid.</summary>

        error_bad_impersonation_level = ERROR_BAD_IMPERSONATION_LEVEL,
        /// <summary>Cannot open an anonymous level security token.</summary>

        error_cant_open_anonymous = ERROR_CANT_OPEN_ANONYMOUS,
        /// <summary>The validation information class requested was invalid.</summary>

        error_bad_validation_class = ERROR_BAD_VALIDATION_CLASS,
        /// <summary>The type of the token is inappropriate for its attempted use.</summary>

        error_bad_token_type = ERROR_BAD_TOKEN_TYPE,
        /// <summary>Unable to perform a security operation on an object that has no associated security.</summary>

        error_no_security_on_object = ERROR_NO_SECURITY_ON_OBJECT,
        /// <summary>Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.</summary>

        error_cant_access_domain_info = ERROR_CANT_ACCESS_DOMAIN_INFO,
        /// <summary>The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.</summary>

        error_invalid_server_state = ERROR_INVALID_SERVER_STATE,
        /// <summary>The domain was in the wrong state to perform the security operation.</summary>

        error_invalid_domain_state = ERROR_INVALID_DOMAIN_STATE,
        /// <summary>This operation is only allowed for the Primary Domain Controller of the domain.</summary>

        error_invalid_domain_role = ERROR_INVALID_DOMAIN_ROLE,
        /// <summary>The specified domain either does not exist or could not be contacted.</summary>

        error_no_such_domain = ERROR_NO_SUCH_DOMAIN,
        /// <summary>The specified domain already exists.</summary>

        error_domain_exists = ERROR_DOMAIN_EXISTS,
        /// <summary>An attempt was made to exceed the limit on the number of domains per server.</summary>

        error_domain_limit_exceeded = ERROR_DOMAIN_LIMIT_EXCEEDED,
        /// <summary>Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.</summary>

        error_internal_db_corruption = ERROR_INTERNAL_DB_CORRUPTION,
        /// <summary>An internal error occurred.</summary>

        error_internal_error = ERROR_INTERNAL_ERROR,
        /// <summary>Generic access types were contained in an access mask which should already be mapped to nongeneric types.</summary>

        error_generic_not_mapped = ERROR_GENERIC_NOT_MAPPED,
        /// <summary>A security descriptor is not in the right format (absolute or self-relative).</summary>

        error_bad_descriptor_format = ERROR_BAD_DESCRIPTOR_FORMAT,
        /// <summary>The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.</summary>

        error_not_logon_process = ERROR_NOT_LOGON_PROCESS,
        /// <summary>Cannot start a new logon session with an ID that is already in use.</summary>

        error_logon_session_exists = ERROR_LOGON_SESSION_EXISTS,
        /// <summary>A specified authentication package is unknown.</summary>

        error_no_such_package = ERROR_NO_SUCH_PACKAGE,
        /// <summary>The logon session is not in a state that is consistent with the requested operation.</summary>

        error_bad_logon_session_state = ERROR_BAD_LOGON_SESSION_STATE,
        /// <summary>The logon session ID is already in use.</summary>

        error_logon_session_collision = ERROR_LOGON_SESSION_COLLISION,
        /// <summary>A logon request contained an invalid logon type value.</summary>

        error_invalid_logon_type = ERROR_INVALID_LOGON_TYPE,
        /// <summary>Unable to impersonate using a named pipe until data has been read from that pipe.</summary>

        error_cannot_impersonate = ERROR_CANNOT_IMPERSONATE,
        /// <summary>The transaction state of a registry subtree is incompatible with the requested operation.</summary>

        error_rxact_invalid_state = ERROR_RXACT_INVALID_STATE,
        /// <summary>An internal security database corruption has been encountered.</summary>

        error_rxact_commit_failure = ERROR_RXACT_COMMIT_FAILURE,
        /// <summary>Cannot perform this operation on built-in accounts.</summary>

        error_special_account = ERROR_SPECIAL_ACCOUNT,
        /// <summary>Cannot perform this operation on this built-in special group.</summary>

        error_special_group = ERROR_SPECIAL_GROUP,
        /// <summary>Cannot perform this operation on this built-in special user.</summary>

        error_special_user = ERROR_SPECIAL_USER,
        /// <summary>The user cannot be removed from a group because the group is currently the user's primary group.</summary>

        error_members_primary_group = ERROR_MEMBERS_PRIMARY_GROUP,
        /// <summary>The token is already in use as a primary token.</summary>

        error_token_already_in_use = ERROR_TOKEN_ALREADY_IN_USE,
        /// <summary>The specified local group does not exist.</summary>

        error_no_such_alias = ERROR_NO_SUCH_ALIAS,
        /// <summary>The specified account name is not a member of the group.</summary>

        error_member_not_in_alias = ERROR_MEMBER_NOT_IN_ALIAS,
        /// <summary>The specified account name is already a member of the group.</summary>

        error_member_in_alias = ERROR_MEMBER_IN_ALIAS,
        /// <summary>The specified local group already exists.</summary>

        error_alias_exists = ERROR_ALIAS_EXISTS,
        /// <summary>Logon failure: the user has not been granted the requested logon type at this computer.</summary>

        error_logon_not_granted = ERROR_LOGON_NOT_GRANTED,
        /// <summary>The maximum number of secrets that may be stored in a single system has been exceeded.</summary>

        error_too_many_secrets = ERROR_TOO_MANY_SECRETS,
        /// <summary>The length of a secret exceeds the maximum length allowed.</summary>

        error_secret_too_long = ERROR_SECRET_TOO_LONG,
        /// <summary>The local security authority database contains an internal inconsistency.</summary>

        error_internal_db_error = ERROR_INTERNAL_DB_ERROR,
        /// <summary>During a logon attempt, the user's security context accumulated too many security IDs.</summary>

        error_too_many_context_ids = ERROR_TOO_MANY_CONTEXT_IDS,
        /// <summary>Logon failure: the user has not been granted the requested logon type at this computer.</summary>

        error_logon_type_not_granted = ERROR_LOGON_TYPE_NOT_GRANTED,
        /// <summary>A cross-encrypted password is necessary to change a user password.</summary>

        error_nt_cross_encryption_required = ERROR_NT_CROSS_ENCRYPTION_REQUIRED,
        /// <summary>A member could not be added to or removed from the local group because the member does not exist.</summary>

        error_no_such_member = ERROR_NO_SUCH_MEMBER,
        /// <summary>A new member could not be added to a local group because the member has the wrong account type.</summary>

        error_invalid_member = ERROR_INVALID_MEMBER,
        /// <summary>Too many security IDs have been specified.</summary>

        error_too_many_sids = ERROR_TOO_MANY_SIDS,
        /// <summary>A cross-encrypted password is necessary to change this user password.</summary>

        error_lm_cross_encryption_required = ERROR_LM_CROSS_ENCRYPTION_REQUIRED,
        /// <summary>Indicates an ACL contains no inheritable components.</summary>

        error_no_inheritance = ERROR_NO_INHERITANCE,
        /// <summary>The file or directory is corrupted and unreadable.</summary>

        error_file_corrupt = ERROR_FILE_CORRUPT,
        /// <summary>The disk structure is corrupted and unreadable.</summary>

        error_disk_corrupt = ERROR_DISK_CORRUPT,
        /// <summary>There is no user session key for the specified logon session.</summary>
        error_no_user_session_key = ERROR_NO_USER_SESSION_KEY,

        /// <summary>The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept.</summary>
        error_license_quota_exceeded = ERROR_LICENSE_QUOTA_EXCEEDED,

        /// <summary>The target account name is incorrect.</summary>
        error_wrong_target_name = ERROR_WRONG_TARGET_NAME,

        /// <summary>Mutual Authentication failed. The server's password is out of date at the domain controller.</summary>
        error_mutual_auth_failed = ERROR_MUTUAL_AUTH_FAILED,

        /// <summary>There is a time and/or date difference between the client and server.</summary>
        error_time_skew = ERROR_TIME_SKEW,

        /// <summary>This operation cannot be performed on the current domain.</summary>
        error_current_domain_not_allowed = ERROR_CURRENT_DOMAIN_NOT_ALLOWED,

        /// <summary>Invalid window handle.</summary>
        error_invalid_window_handle = ERROR_INVALID_WINDOW_HANDLE,

        /// <summary>Invalid menu handle.</summary>
        error_invalid_menu_handle = ERROR_INVALID_MENU_HANDLE,

        /// <summary>Invalid cursor handle.</summary>
        error_invalid_cursor_handle = ERROR_INVALID_CURSOR_HANDLE,

        /// <summary>Invalid accelerator table handle.</summary>
        error_invalid_accel_handle = ERROR_INVALID_ACCEL_HANDLE,

        /// <summary>Invalid hook handle.</summary>
        error_invalid_hook_handle = ERROR_INVALID_HOOK_HANDLE,

        /// <summary>Invalid handle to a multiple-window position structure.</summary>
        error_invalid_dwp_handle = ERROR_INVALID_DWP_HANDLE,

        /// <summary>Cannot create a top-level child window.</summary>
        error_tlw_with_wschild = ERROR_TLW_WITH_WSCHILD,

        /// <summary>Cannot find window class.</summary>
        error_cannot_find_wnd_class = ERROR_CANNOT_FIND_WND_CLASS,

        /// <summary>Invalid window; it belongs to other thread.</summary>
        error_window_of_other_thread = ERROR_WINDOW_OF_OTHER_THREAD,

        /// <summary>Hot key is already registered.</summary>
        error_hotkey_already_registered = ERROR_HOTKEY_ALREADY_REGISTERED,

        /// <summary>Class already exists.</summary>
        error_class_already_exists = ERROR_CLASS_ALREADY_EXISTS,

        /// <summary>Class does not exist.</summary>
        error_class_does_not_exist = ERROR_CLASS_DOES_NOT_EXIST,
        /// <summary>Class still has open windows.</summary>

        error_class_has_windows = ERROR_CLASS_HAS_WINDOWS,
        /// <summary>Invalid index.</summary>

        error_invalid_index = ERROR_INVALID_INDEX,
        /// <summary>Invalid icon handle.</summary>

        error_invalid_icon_handle = ERROR_INVALID_ICON_HANDLE,
        /// <summary>Using private DIALOG window words.</summary>

        error_private_dialog_index = ERROR_PRIVATE_DIALOG_INDEX,
        /// <summary>The list box identifier was not found.</summary>

        error_listbox_id_not_found = ERROR_LISTBOX_ID_NOT_FOUND,
        /// <summary>No wildcards were found.</summary>

        error_no_wildcard_characters = ERROR_NO_WILDCARD_CHARACTERS,
        /// <summary>Thread does not have a clipboard open.</summary>

        error_clipboard_not_open = ERROR_CLIPBOARD_NOT_OPEN,
        /// <summary>Hot key is not registered.</summary>

        error_hotkey_not_registered = ERROR_HOTKEY_NOT_REGISTERED,
        /// <summary>The window is not a valid dialog window.</summary>

        error_window_not_dialog = ERROR_WINDOW_NOT_DIALOG,
        /// <summary>Control ID not found.</summary>

        error_control_id_not_found = ERROR_CONTROL_ID_NOT_FOUND,
        /// <summary>Invalid message for a combo box because it does not have an edit control.</summary>

        error_invalid_combobox_message = ERROR_INVALID_COMBOBOX_MESSAGE,
        /// <summary>The window is not a combo box.</summary>

        error_window_not_combobox = ERROR_WINDOW_NOT_COMBOBOX,
        /// <summary>Height must be less than 256.</summary>

        error_invalid_edit_height = ERROR_INVALID_EDIT_HEIGHT,
        /// <summary>Invalid device context (DC) handle.</summary>

        error_dc_not_found = ERROR_DC_NOT_FOUND,
        /// <summary>Invalid hook procedure type.</summary>

        error_invalid_hook_filter = ERROR_INVALID_HOOK_FILTER,
        /// <summary>Invalid hook procedure.</summary>

        error_invalid_filter_proc = ERROR_INVALID_FILTER_PROC,
        /// <summary>Cannot set nonlocal hook without a module handle.</summary>

        error_hook_needs_hmod = ERROR_HOOK_NEEDS_HMOD,
        /// <summary>This hook procedure can only be set globally.</summary>

        error_global_only_hook = ERROR_GLOBAL_ONLY_HOOK,
        /// <summary>The journal hook procedure is already installed.</summary>

        error_journal_hook_set = ERROR_JOURNAL_HOOK_SET,
        /// <summary>The hook procedure is not installed.</summary>

        error_hook_not_installed = ERROR_HOOK_NOT_INSTALLED,
        /// <summary>Invalid message for single-selection list box.</summary>

        error_invalid_lb_message = ERROR_INVALID_LB_MESSAGE,
        /// <summary>LB_SETCOUNT sent to non-lazy list box.</summary>

        error_setcount_on_bad_lb = ERROR_SETCOUNT_ON_BAD_LB,
        /// <summary>This list box does not support tab stops.</summary>

        error_lb_without_tabstops = ERROR_LB_WITHOUT_TABSTOPS,
        /// <summary>Cannot destroy object created by another thread.</summary>

        error_destroy_object_of_other_thread = ERROR_DESTROY_OBJECT_OF_OTHER_THREAD,
        /// <summary>Child windows cannot have menus.</summary>

        error_child_window_menu = ERROR_CHILD_WINDOW_MENU,
        /// <summary>The window does not have a system menu.</summary>

        error_no_system_menu = ERROR_NO_SYSTEM_MENU,
        /// <summary>Invalid message box style.</summary>

        error_invalid_msgbox_style = ERROR_INVALID_MSGBOX_STYLE,
        /// <summary>Invalid system-wide (SPI_*) parameter.</summary>

        error_invalid_spi_value = ERROR_INVALID_SPI_VALUE,
        /// <summary>Screen already locked.</summary>

        error_screen_already_locked = ERROR_SCREEN_ALREADY_LOCKED,
        /// <summary>All handles to windows in a multiple-window position structure must have the same parent.</summary>

        error_hwnds_have_diff_parent = ERROR_HWNDS_HAVE_DIFF_PARENT,
        /// <summary>The window is not a child window.</summary>

        error_not_child_window = ERROR_NOT_CHILD_WINDOW,
        /// <summary>Invalid GW_* command.</summary>

        error_invalid_gw_command = ERROR_INVALID_GW_COMMAND,
        /// <summary>Invalid thread identifier.</summary>

        error_invalid_thread_id = ERROR_INVALID_THREAD_ID,
        /// <summary>Cannot process a message from a window that is not a multiple document interface (MDI) window.</summary>

        error_non_mdichild_window = ERROR_NON_MDICHILD_WINDOW,
        /// <summary>Popup menu already active.</summary>

        error_popup_already_active = ERROR_POPUP_ALREADY_ACTIVE,
        /// <summary>The window does not have scroll bars.</summary>

        error_no_scrollbars = ERROR_NO_SCROLLBARS,
        /// <summary>Scroll bar range cannot be greater than MAXLONG.</summary>

        error_invalid_scrollbar_range = ERROR_INVALID_SCROLLBAR_RANGE,
        /// <summary>Cannot show or remove the window in the way specified.</summary>

        error_invalid_showwin_command = ERROR_INVALID_SHOWWIN_COMMAND,
        /// <summary>Insufficient system resources exist to complete the requested service.</summary>

        error_no_system_resources = ERROR_NO_SYSTEM_RESOURCES,
        /// <summary>Insufficient system resources exist to complete the requested service.</summary>

        error_nonpaged_system_resources = ERROR_NONPAGED_SYSTEM_RESOURCES,
        /// <summary>Insufficient system resources exist to complete the requested service.</summary>

        error_paged_system_resources = ERROR_PAGED_SYSTEM_RESOURCES,
        /// <summary>Insufficient quota to complete the requested service.</summary>

        error_working_set_quota = ERROR_WORKING_SET_QUOTA,
        /// <summary>Insufficient quota to complete the requested service.</summary>

        error_pagefile_quota = ERROR_PAGEFILE_QUOTA,
        /// <summary>The paging file is too small for this operation to complete.</summary>

        error_commitment_limit = ERROR_COMMITMENT_LIMIT,
        /// <summary>A menu item was not found.</summary>

        error_menu_item_not_found = ERROR_MENU_ITEM_NOT_FOUND,
        /// <summary>Invalid keyboard layout handle.</summary>

        error_invalid_keyboard_handle = ERROR_INVALID_KEYBOARD_HANDLE,
        /// <summary>Hook type not allowed.</summary>

        error_hook_type_not_allowed = ERROR_HOOK_TYPE_NOT_ALLOWED,
        /// <summary>This operation requires an interactive window station.</summary>

        error_requires_interactive_windowstation = ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION,
        /// <summary>This operation returned because the timeout period expired.</summary>

        error_timeout = ERROR_TIMEOUT,
        /// <summary>Invalid monitor handle.</summary>

        error_invalid_monitor_handle = ERROR_INVALID_MONITOR_HANDLE,
        /// <summary>Incorrect size argument.</summary>

        error_incorrect_size = ERROR_INCORRECT_SIZE,
        /// <summary>The symbolic link cannot be followed because its type is disabled.</summary>

        error_symlink_class_disabled = ERROR_SYMLINK_CLASS_DISABLED,
        /// <summary>This application does not support the current operation on symbolic links.</summary>

        error_symlink_not_supported = ERROR_SYMLINK_NOT_SUPPORTED,
        /// <summary>Windows was unable to parse the requested XML data.</summary>

        error_xml_parse_error = ERROR_XML_PARSE_ERROR,
        /// <summary>An error was encountered while processing an XML digital signature.</summary>

        error_xmldsig_error = ERROR_XMLDSIG_ERROR,
        /// <summary>This application must be restarted.</summary>

        error_restart_application = ERROR_RESTART_APPLICATION,
        /// <summary>The caller made the connection request in the wrong routing compartment.</summary>

        error_wrong_compartment = ERROR_WRONG_COMPARTMENT,
        /// <summary>There was an AuthIP failure when attempting to connect to the remote host.</summary>

        error_authip_failure = ERROR_AUTHIP_FAILURE,
        /// <summary>Insufficient NVRAM resources exist to complete the requested service. A reboot might be required.</summary>

        error_no_nvram_resources = ERROR_NO_NVRAM_RESOURCES,
        /// <summary>Unable to finish the requested operation because the specified process is not a GUI process.</summary>

        error_not_gui_process = ERROR_NOT_GUI_PROCESS,
        /// <summary>The event log file is corrupted.</summary>

        error_eventlog_file_corrupt = ERROR_EVENTLOG_FILE_CORRUPT,
        /// <summary>No event log file could be opened, so the event logging service did not start.</summary>

        error_eventlog_cant_start = ERROR_EVENTLOG_CANT_START,
        /// <summary>The event log file is full.</summary>

        error_log_file_full = ERROR_LOG_FILE_FULL,
        /// <summary>The event log file has changed between read operations.</summary>

        error_eventlog_file_changed = ERROR_EVENTLOG_FILE_CHANGED,
        /// <summary>The specified Job already has a container assigned to it.</summary>

        error_container_assigned = ERROR_CONTAINER_ASSIGNED,
        /// <summary>The specified Job does not have a container assigned to it.</summary>

        error_job_no_container = ERROR_JOB_NO_CONTAINER,
        /// <summary>The specified task name is invalid.</summary>

        error_invalid_task_name = ERROR_INVALID_TASK_NAME,
        /// <summary>The specified task index is invalid.</summary>

        error_invalid_task_index = ERROR_INVALID_TASK_INDEX,
        /// <summary>The specified thread is already joining a task.</summary>

        error_thread_already_in_task = ERROR_THREAD_ALREADY_IN_TASK,
        /// <summary>The Windows Installer Service could not be accessed. This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance.</summary>

        error_install_service_failure = ERROR_INSTALL_SERVICE_FAILURE,
        /// <summary>User cancelled installation.</summary>

        error_install_userexit = ERROR_INSTALL_USEREXIT,
        /// <summary>Fatal error during installation.</summary>

        error_install_failure = ERROR_INSTALL_FAILURE,
        /// <summary>Installation suspended, incomplete.</summary>

        error_install_suspend = ERROR_INSTALL_SUSPEND,
        /// <summary>This action is only valid for products that are currently installed.</summary>

        error_unknown_product = ERROR_UNKNOWN_PRODUCT,
        /// <summary>Feature ID not registered.</summary>

        error_unknown_feature = ERROR_UNKNOWN_FEATURE,
        /// <summary>Component ID not registered.</summary>

        error_unknown_component = ERROR_UNKNOWN_COMPONENT,
        /// <summary>Unknown property.</summary>

        error_unknown_property = ERROR_UNKNOWN_PROPERTY,
        /// <summary>Handle is in an invalid state.</summary>

        error_invalid_handle_state = ERROR_INVALID_HANDLE_STATE,
        /// <summary>The configuration data for this product is corrupt. Contact your support personnel.</summary>

        error_bad_configuration = ERROR_BAD_CONFIGURATION,
        /// <summary>Component qualifier not present.</summary>

        error_index_absent = ERROR_INDEX_ABSENT,
        /// <summary>The installation source for this product is not available. Verify that the source exists and that you can access it.</summary>

        error_install_source_absent = ERROR_INSTALL_SOURCE_ABSENT,
        /// <summary>This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.</summary>

        error_install_package_version = ERROR_INSTALL_PACKAGE_VERSION,
        /// <summary>Product is uninstalled.</summary>

        error_product_uninstalled = ERROR_PRODUCT_UNINSTALLED,
        /// <summary>SQL query syntax invalid or unsupported.</summary>

        error_bad_query_syntax = ERROR_BAD_QUERY_SYNTAX,
        /// <summary>Record field does not exist.</summary>

        error_invalid_field = ERROR_INVALID_FIELD,
        /// <summary>The device has been removed.</summary>

        error_device_removed = ERROR_DEVICE_REMOVED,
        /// <summary>Another installation is already in progress. Complete that installation before proceeding with this install.</summary>

        error_install_already_running = ERROR_INSTALL_ALREADY_RUNNING,
        /// <summary>This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.</summary>

        error_install_package_open_failed = ERROR_INSTALL_PACKAGE_OPEN_FAILED,
        /// <summary>This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package.</summary>

        error_install_package_invalid = ERROR_INSTALL_PACKAGE_INVALID,
        /// <summary>There was an error starting the Windows Installer service user interface. Contact your support personnel.</summary>

        error_install_ui_failure = ERROR_INSTALL_UI_FAILURE,
        /// <summary>Error opening installation log file. Verify that the specified log file location exists and that you can write to it.</summary>

        error_install_log_failure = ERROR_INSTALL_LOG_FAILURE,
        /// <summary>The language of this installation package is not supported by your system.</summary>

        error_install_language_unsupported = ERROR_INSTALL_LANGUAGE_UNSUPPORTED,
        /// <summary>Error applying transforms. Verify that the specified transform paths are valid.</summary>

        error_install_transform_failure = ERROR_INSTALL_TRANSFORM_FAILURE,
        /// <summary>This installation is forbidden by system policy. Contact your system administrator.</summary>

        error_install_package_rejected = ERROR_INSTALL_PACKAGE_REJECTED,
        /// <summary>Function could not be executed.</summary>

        error_function_not_called = ERROR_FUNCTION_NOT_CALLED,
        /// <summary>Function failed during execution.</summary>

        error_function_failed = ERROR_FUNCTION_FAILED,
        /// <summary>Invalid or unknown table specified.</summary>

        error_invalid_table = ERROR_INVALID_TABLE,
        /// <summary>Data supplied is of wrong type.</summary>

        error_datatype_mismatch = ERROR_DATATYPE_MISMATCH,
        /// <summary>Data of this type is not supported.</summary>

        error_unsupported_type = ERROR_UNSUPPORTED_TYPE,
        /// <summary>The Windows Installer service failed to start. Contact your support personnel.</summary>

        error_create_failed = ERROR_CREATE_FAILED,
        /// <summary>The Temp folder is on a drive that is full or is inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder.</summary>

        error_install_temp_unwritable = ERROR_INSTALL_TEMP_UNWRITABLE,
        /// <summary>This installation package is not supported by this processor type. Contact your product vendor.</summary>

        error_install_platform_unsupported = ERROR_INSTALL_PLATFORM_UNSUPPORTED,
        /// <summary>Component not used on this computer.</summary>

        error_install_notused = ERROR_INSTALL_NOTUSED,
        /// <summary>This update package could not be opened. Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package.</summary>

        error_patch_package_open_failed = ERROR_PATCH_PACKAGE_OPEN_FAILED,
        /// <summary>This update package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer update package.</summary>

        error_patch_package_invalid = ERROR_PATCH_PACKAGE_INVALID,
        /// <summary>This update package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.</summary>

        error_patch_package_unsupported = ERROR_PATCH_PACKAGE_UNSUPPORTED,
        /// <summary>Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.</summary>

        error_product_version = ERROR_PRODUCT_VERSION,
        /// <summary>Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.</summary>

        error_invalid_command_line = ERROR_INVALID_COMMAND_LINE,
        /// <summary>Only administrators have permission to add, remove, or configure server software during a Terminal services remote session. If you want to install or configure software on the server, contact your network administrator.</summary>

        error_install_remote_disallowed = ERROR_INSTALL_REMOTE_DISALLOWED,
        /// <summary>The requested operation completed successfully. The system will be restarted so the changes can take effect.</summary>

        error_success_reboot_initiated = ERROR_SUCCESS_REBOOT_INITIATED,
        /// <summary>The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade.</summary>

        error_patch_target_not_found = ERROR_PATCH_TARGET_NOT_FOUND,
        /// <summary>The update package is not permitted by software restriction policy.</summary>

        error_patch_package_rejected = ERROR_PATCH_PACKAGE_REJECTED,
        /// <summary>One or more customizations are not permitted by software restriction policy.</summary>

        error_install_transform_rejected = ERROR_INSTALL_TRANSFORM_REJECTED,
        /// <summary>The Windows Installer does not permit installation from a Remote Desktop Connection.</summary>

        error_install_remote_prohibited = ERROR_INSTALL_REMOTE_PROHIBITED,
        /// <summary>Uninstallation of the update package is not supported.</summary>

        error_patch_removal_unsupported = ERROR_PATCH_REMOVAL_UNSUPPORTED,
        /// <summary>The update is not applied to this product.</summary>

        error_unknown_patch = ERROR_UNKNOWN_PATCH,
        /// <summary>No valid sequence could be found for the set of updates.</summary>

        error_patch_no_sequence = ERROR_PATCH_NO_SEQUENCE,
        /// <summary>Update removal was disallowed by policy.</summary>

        error_patch_removal_disallowed = ERROR_PATCH_REMOVAL_DISALLOWED,
        /// <summary>The XML update data is invalid.</summary>

        error_invalid_patch_xml = ERROR_INVALID_PATCH_XML,
        /// <summary>Windows Installer does not permit updating of managed advertised products. At least one feature of the product must be installed before applying the update.</summary>

        error_patch_managed_advertised_product = ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT,
        /// <summary>The Windows Installer service is not accessible in Safe Mode. Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state.</summary>

        error_install_service_safeboot = ERROR_INSTALL_SERVICE_SAFEBOOT,
        /// <summary>A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately.</summary>

        error_fail_fast_exception = ERROR_FAIL_FAST_EXCEPTION,
        /// <summary>The app that you are trying to run is not supported on this version of Windows.</summary>

        error_install_rejected = ERROR_INSTALL_REJECTED,
        /// <summary>The operation was blocked as the process prohibits dynamic code generation.</summary>

        error_dynamic_code_blocked = ERROR_DYNAMIC_CODE_BLOCKED,
        /// <summary>The objects are not identical.</summary>

        error_not_same_object = ERROR_NOT_SAME_OBJECT,
        /// <summary>The specified image file was blocked from loading because it does not enable a feature required by the process: Control Flow Guard.</summary>

        error_strict_cfg_violation = ERROR_STRICT_CFG_VIOLATION,
        /// <summary>The thread context could not be updated because this has been restricted for the process.</summary>

        error_set_context_denied = ERROR_SET_CONTEXT_DENIED,
        /// <summary>An invalid cross-partition private file/section access was attempted.</summary>

        error_cross_partition_violation = ERROR_CROSS_PARTITION_VIOLATION,
        /// <summary>The string binding is invalid.</summary>

        rpc_s_invalid_string_binding = RPC_S_INVALID_STRING_BINDING,
        /// <summary>The binding handle is not the correct type.</summary>

        rpc_s_wrong_kind_of_binding = RPC_S_WRONG_KIND_OF_BINDING,
        /// <summary>The binding handle is invalid.</summary>

        rpc_s_invalid_binding = RPC_S_INVALID_BINDING,
        /// <summary>The RPC protocol sequence is not supported.</summary>

        rpc_s_protseq_not_supported = RPC_S_PROTSEQ_NOT_SUPPORTED,
        /// <summary>The RPC protocol sequence is invalid.</summary>

        rpc_s_invalid_rpc_protseq = RPC_S_INVALID_RPC_PROTSEQ,
        /// <summary>The string universal unique identifier (UUID) is invalid.</summary>

        rpc_s_invalid_string_uuid = RPC_S_INVALID_STRING_UUID,
        /// <summary>The endpoint format is invalid.</summary>

        rpc_s_invalid_endpoint_format = RPC_S_INVALID_ENDPOINT_FORMAT,
        /// <summary>The network address is invalid.</summary>

        rpc_s_invalid_net_addr = RPC_S_INVALID_NET_ADDR,
        /// <summary>No endpoint was found.</summary>

        rpc_s_no_endpoint_found = RPC_S_NO_ENDPOINT_FOUND,
        /// <summary>The timeout value is invalid.</summary>

        rpc_s_invalid_timeout = RPC_S_INVALID_TIMEOUT,
        /// <summary>The object universal unique identifier (UUID) was not found.</summary>

        rpc_s_object_not_found = RPC_S_OBJECT_NOT_FOUND,
        /// <summary>The object universal unique identifier (UUID) has already been registered.</summary>

        rpc_s_already_registered = RPC_S_ALREADY_REGISTERED,
        /// <summary>The type universal unique identifier (UUID) has already been registered.</summary>

        rpc_s_type_already_registered = RPC_S_TYPE_ALREADY_REGISTERED,
        /// <summary>The RPC server is already listening.</summary>

        rpc_s_already_listening = RPC_S_ALREADY_LISTENING,
        /// <summary>No protocol sequences have been registered.</summary>

        rpc_s_no_protseqs_registered = RPC_S_NO_PROTSEQS_REGISTERED,
        /// <summary>The RPC server is not listening.</summary>

        rpc_s_not_listening = RPC_S_NOT_LISTENING,
        /// <summary>The manager type is unknown.</summary>

        rpc_s_unknown_mgr_type = RPC_S_UNKNOWN_MGR_TYPE,
        /// <summary>The interface is unknown.</summary>

        rpc_s_unknown_if = RPC_S_UNKNOWN_IF,
        /// <summary>There are no bindings.</summary>

        rpc_s_no_bindings = RPC_S_NO_BINDINGS,
        /// <summary>There are no protocol sequences.</summary>

        rpc_s_no_protseqs = RPC_S_NO_PROTSEQS,
        /// <summary>The endpoint cannot be created.</summary>

        rpc_s_cant_create_endpoint = RPC_S_CANT_CREATE_ENDPOINT,
        /// <summary>Not enough resources are available to complete this operation.</summary>

        rpc_s_out_of_resources = RPC_S_OUT_OF_RESOURCES,
        /// <summary>The RPC server is unavailable.</summary>

        rpc_s_server_unavailable = RPC_S_SERVER_UNAVAILABLE,
        /// <summary>The RPC server is too busy to complete this operation.</summary>

        rpc_s_server_too_busy = RPC_S_SERVER_TOO_BUSY,
        /// <summary>The network options are invalid.</summary>

        rpc_s_invalid_network_options = RPC_S_INVALID_NETWORK_OPTIONS,
        /// <summary>There are no remote procedure calls active on this thread.</summary>

        rpc_s_no_call_active = RPC_S_NO_CALL_ACTIVE,
        /// <summary>The remote procedure call failed.</summary>

        rpc_s_call_failed = RPC_S_CALL_FAILED,
        /// <summary>The remote procedure call failed and did not execute.</summary>

        rpc_s_call_failed_dne = RPC_S_CALL_FAILED_DNE,
        /// <summary>A remote procedure call (RPC) protocol error occurred.</summary>

        rpc_s_protocol_error = RPC_S_PROTOCOL_ERROR,
        /// <summary>Access to the HTTP proxy is denied.</summary>

        rpc_s_proxy_access_denied = RPC_S_PROXY_ACCESS_DENIED,
        /// <summary>The transfer syntax is not supported by the RPC server.</summary>

        rpc_s_unsupported_trans_syn = RPC_S_UNSUPPORTED_TRANS_SYN,
        /// <summary>The universal unique identifier (UUID) type is not supported.</summary>

        rpc_s_unsupported_type = RPC_S_UNSUPPORTED_TYPE,
        /// <summary>The tag is invalid.</summary>

        rpc_s_invalid_tag = RPC_S_INVALID_TAG,
        /// <summary>The array bounds are invalid.</summary>

        rpc_s_invalid_bound = RPC_S_INVALID_BOUND,
        /// <summary>The binding does not contain an entry name.</summary>

        rpc_s_no_entry_name = RPC_S_NO_ENTRY_NAME,
        /// <summary>The name syntax is invalid.</summary>

        rpc_s_invalid_name_syntax = RPC_S_INVALID_NAME_SYNTAX,
        /// <summary>The name syntax is not supported.</summary>

        rpc_s_unsupported_name_syntax = RPC_S_UNSUPPORTED_NAME_SYNTAX,
        /// <summary>No network address is available to use to construct a universal unique identifier (UUID).</summary>

        rpc_s_uuid_no_address = RPC_S_UUID_NO_ADDRESS,
        /// <summary>The endpoint is a duplicate.</summary>

        rpc_s_duplicate_endpoint = RPC_S_DUPLICATE_ENDPOINT,
        /// <summary>The authentication type is unknown.</summary>

        rpc_s_unknown_authn_type = RPC_S_UNKNOWN_AUTHN_TYPE,
        /// <summary>The maximum number of calls is too small.</summary>

        rpc_s_max_calls_too_small = RPC_S_MAX_CALLS_TOO_SMALL,
        /// <summary>The string is too long.</summary>

        rpc_s_string_too_long = RPC_S_STRING_TOO_LONG,
        /// <summary>The RPC protocol sequence was not found.</summary>

        rpc_s_protseq_not_found = RPC_S_PROTSEQ_NOT_FOUND,
        /// <summary>The procedure number is out of range.</summary>

        rpc_s_procnum_out_of_range = RPC_S_PROCNUM_OUT_OF_RANGE,
        /// <summary>The binding does not contain any authentication information.</summary>

        rpc_s_binding_has_no_auth = RPC_S_BINDING_HAS_NO_AUTH,
        /// <summary>The authentication service is unknown.</summary>

        rpc_s_unknown_authn_service = RPC_S_UNKNOWN_AUTHN_SERVICE,
        /// <summary>The authentication level is unknown.</summary>

        rpc_s_unknown_authn_level = RPC_S_UNKNOWN_AUTHN_LEVEL,
        /// <summary>The security context is invalid.</summary>

        rpc_s_invalid_auth_identity = RPC_S_INVALID_AUTH_IDENTITY,
        /// <summary>The authorization service is unknown.</summary>

        rpc_s_unknown_authz_service = RPC_S_UNKNOWN_AUTHZ_SERVICE,
        /// <summary>The entry is invalid.</summary>

        ept_s_invalid_entry = EPT_S_INVALID_ENTRY,
        /// <summary>The server endpoint cannot perform the operation.</summary>

        ept_s_cant_perform_op = EPT_S_CANT_PERFORM_OP,
        /// <summary>There are no more endpoints available from the endpoint mapper.</summary>

        ept_s_not_registered = EPT_S_NOT_REGISTERED,
        /// <summary>No interfaces have been exported.</summary>

        rpc_s_nothing_to_export = RPC_S_NOTHING_TO_EXPORT,
        /// <summary>The entry name is incomplete.</summary>

        rpc_s_incomplete_name = RPC_S_INCOMPLETE_NAME,
        /// <summary>The version option is invalid.</summary>

        rpc_s_invalid_vers_option = RPC_S_INVALID_VERS_OPTION,
        /// <summary>There are no more members.</summary>

        rpc_s_no_more_members = RPC_S_NO_MORE_MEMBERS,
        /// <summary>There is nothing to unexport.</summary>

        rpc_s_not_all_objs_unexported = RPC_S_NOT_ALL_OBJS_UNEXPORTED,
        /// <summary>The interface was not found.</summary>

        rpc_s_interface_not_found = RPC_S_INTERFACE_NOT_FOUND,
        /// <summary>The entry already exists.</summary>

        rpc_s_entry_already_exists = RPC_S_ENTRY_ALREADY_EXISTS,
        /// <summary>The entry is not found.</summary>

        rpc_s_entry_not_found = RPC_S_ENTRY_NOT_FOUND,
        /// <summary>The name service is unavailable.</summary>

        rpc_s_name_service_unavailable = RPC_S_NAME_SERVICE_UNAVAILABLE,
        /// <summary>The network address family is invalid.</summary>

        rpc_s_invalid_naf_id = RPC_S_INVALID_NAF_ID,
        /// <summary>The requested operation is not supported.</summary>

        rpc_s_cannot_support = RPC_S_CANNOT_SUPPORT,
        /// <summary>No security context is available to allow impersonation.</summary>

        rpc_s_no_context_available = RPC_S_NO_CONTEXT_AVAILABLE,
        /// <summary>An internal error occurred in a remote procedure call (RPC).</summary>

        rpc_s_internal_error = RPC_S_INTERNAL_ERROR,
        /// <summary>The RPC server attempted an integer division by zero.</summary>

        rpc_s_zero_divide = RPC_S_ZERO_DIVIDE,
        /// <summary>An addressing error occurred in the RPC server.</summary>

        rpc_s_address_error = RPC_S_ADDRESS_ERROR,
        /// <summary>A floating-point operation at the RPC server caused a division by zero.</summary>

        rpc_s_fp_div_zero = RPC_S_FP_DIV_ZERO,
        /// <summary>A floating-point underflow occurred at the RPC server.</summary>

        rpc_s_fp_underflow = RPC_S_FP_UNDERFLOW,
        /// <summary>A floating-point overflow occurred at the RPC server.</summary>

        rpc_s_fp_overflow = RPC_S_FP_OVERFLOW,
        /// <summary>The list of RPC servers available for the binding of auto handles has been exhausted.</summary>

        rpc_x_no_more_entries = RPC_X_NO_MORE_ENTRIES,
        /// <summary>Unable to open the character translation table file.</summary>

        rpc_x_ss_char_trans_open_fail = RPC_X_SS_CHAR_TRANS_OPEN_FAIL,
        /// <summary>The file containing the character translation table has fewer than 512 bytes.</summary>

        rpc_x_ss_char_trans_short_file = RPC_X_SS_CHAR_TRANS_SHORT_FILE,
        /// <summary>A null context handle was passed from the client to the host during a remote procedure call.</summary>

        rpc_x_ss_in_null_context = RPC_X_SS_IN_NULL_CONTEXT,
        /// <summary>The context handle changed during a remote procedure call.</summary>

        rpc_x_ss_context_damaged = RPC_X_SS_CONTEXT_DAMAGED,
        /// <summary>The binding handles passed to a remote procedure call do not match.</summary>

        rpc_x_ss_handles_mismatch = RPC_X_SS_HANDLES_MISMATCH,
        /// <summary>The stub is unable to get the remote procedure call handle.</summary>

        rpc_x_ss_cannot_get_call_handle = RPC_X_SS_CANNOT_GET_CALL_HANDLE,
        /// <summary>A null reference pointer was passed to the stub.</summary>

        rpc_x_null_ref_pointer = RPC_X_NULL_REF_POINTER,
        /// <summary>The enumeration value is out of range.</summary>

        rpc_x_enum_value_out_of_range = RPC_X_ENUM_VALUE_OUT_OF_RANGE,
        /// <summary>The byte count is too small.</summary>

        rpc_x_byte_count_too_small = RPC_X_BYTE_COUNT_TOO_SMALL,
        /// <summary>The stub received bad data.</summary>

        rpc_x_bad_stub_data = RPC_X_BAD_STUB_DATA,
        /// <summary>The supplied user buffer is not valid for the requested operation.</summary>

        error_invalid_user_buffer = ERROR_INVALID_USER_BUFFER,
        /// <summary>The disk media is not recognized. It may not be formatted.</summary>

        error_unrecognized_media = ERROR_UNRECOGNIZED_MEDIA,
        /// <summary>The workstation does not have a trust secret.</summary>

        error_no_trust_lsa_secret = ERROR_NO_TRUST_LSA_SECRET,
        /// <summary>The security database on the server does not have a computer account for this workstation trust relationship.</summary>

        error_no_trust_sam_account = ERROR_NO_TRUST_SAM_ACCOUNT,
        /// <summary>The trust relationship between the primary domain and the trusted domain failed.</summary>

        error_trusted_domain_failure = ERROR_TRUSTED_DOMAIN_FAILURE,
        /// <summary>The trust relationship between this workstation and the primary domain failed.</summary>

        error_trusted_relationship_failure = ERROR_TRUSTED_RELATIONSHIP_FAILURE,
        /// <summary>The network logon failed.</summary>

        error_trust_failure = ERROR_TRUST_FAILURE,
        /// <summary>A remote procedure call is already in progress for this thread.</summary>

        rpc_s_call_in_progress = RPC_S_CALL_IN_PROGRESS,
        /// <summary>An attempt was made to logon, but the network logon service was not started.</summary>

        error_netlogon_not_started = ERROR_NETLOGON_NOT_STARTED,
        /// <summary>The user's account has expired.</summary>

        error_account_expired = ERROR_ACCOUNT_EXPIRED,
        /// <summary>The redirector is in use and cannot be unloaded.</summary>

        error_redirector_has_open_handles = ERROR_REDIRECTOR_HAS_OPEN_HANDLES,
        /// <summary>The specified printer driver is already installed.</summary>

        error_printer_driver_already_installed = ERROR_PRINTER_DRIVER_ALREADY_INSTALLED,
        /// <summary>The specified port is unknown.</summary>

        error_unknown_port = ERROR_UNKNOWN_PORT,
        /// <summary>The printer driver is unknown.</summary>

        error_unknown_printer_driver = ERROR_UNKNOWN_PRINTER_DRIVER,
        /// <summary>The print processor is unknown.</summary>

        error_unknown_printprocessor = ERROR_UNKNOWN_PRINTPROCESSOR,
        /// <summary>The specified separator file is invalid.</summary>

        error_invalid_separator_file = ERROR_INVALID_SEPARATOR_FILE,
        /// <summary>The specified priority is invalid.</summary>

        error_invalid_priority = ERROR_INVALID_PRIORITY,
        /// <summary>The printer name is invalid.</summary>

        error_invalid_printer_name = ERROR_INVALID_PRINTER_NAME,
        /// <summary>The printer already exists.</summary>

        error_printer_already_exists = ERROR_PRINTER_ALREADY_EXISTS,
        /// <summary>The printer command is invalid.</summary>

        error_invalid_printer_command = ERROR_INVALID_PRINTER_COMMAND,
        /// <summary>The specified datatype is invalid.</summary>

        error_invalid_datatype = ERROR_INVALID_DATATYPE,
        /// <summary>The environment specified is invalid.</summary>

        error_invalid_environment = ERROR_INVALID_ENVIRONMENT,
        /// <summary>There are no more bindings.</summary>

        rpc_s_no_more_bindings = RPC_S_NO_MORE_BINDINGS,
        /// <summary>The account used is an interdomain trust account. Use your global user account or local user account to access this server.</summary>

        error_nologon_interdomain_trust_account = ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT,
        /// <summary>The account used is a computer account. Use your global user account or local user account to access this server.</summary>

        error_nologon_workstation_trust_account = ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT,
        /// <summary>The account used is a server trust account. Use your global user account or local user account to access this server.</summary>

        error_nologon_server_trust_account = ERROR_NOLOGON_SERVER_TRUST_ACCOUNT,
        /// <summary>The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.</summary>

        error_domain_trust_inconsistent = ERROR_DOMAIN_TRUST_INCONSISTENT,
        /// <summary>The server is in use and cannot be unloaded.</summary>

        error_server_has_open_handles = ERROR_SERVER_HAS_OPEN_HANDLES,
        /// <summary>The specified image file did not contain a resource section.</summary>

        error_resource_data_not_found = ERROR_RESOURCE_DATA_NOT_FOUND,
        /// <summary>The specified resource type cannot be found in the image file.</summary>

        error_resource_type_not_found = ERROR_RESOURCE_TYPE_NOT_FOUND,
        /// <summary>The specified resource name cannot be found in the image file.</summary>

        error_resource_name_not_found = ERROR_RESOURCE_NAME_NOT_FOUND,
        /// <summary>The specified resource language ID cannot be found in the image file.</summary>

        error_resource_lang_not_found = ERROR_RESOURCE_LANG_NOT_FOUND,
        /// <summary>Not enough quota is available to process this command.</summary>

        error_not_enough_quota = ERROR_NOT_ENOUGH_QUOTA,
        /// <summary>No interfaces have been registered.</summary>

        rpc_s_no_interfaces = RPC_S_NO_INTERFACES,
        /// <summary>The remote procedure call was cancelled.</summary>

        rpc_s_call_cancelled = RPC_S_CALL_CANCELLED,
        /// <summary>The binding handle does not contain all required information.</summary>

        rpc_s_binding_incomplete = RPC_S_BINDING_INCOMPLETE,
        /// <summary>A communications failure occurred during a remote procedure call.</summary>

        rpc_s_comm_failure = RPC_S_COMM_FAILURE,
        /// <summary>The requested authentication level is not supported.</summary>

        rpc_s_unsupported_authn_level = RPC_S_UNSUPPORTED_AUTHN_LEVEL,
        /// <summary>No principal name registered.</summary>

        rpc_s_no_princ_name = RPC_S_NO_PRINC_NAME,
        /// <summary>The error specified is not a valid Windows RPC error code.</summary>

        rpc_s_not_rpc_error = RPC_S_NOT_RPC_ERROR,
        /// <summary>A UUID that is valid only on this computer has been allocated.</summary>

        rpc_s_uuid_local_only = RPC_S_UUID_LOCAL_ONLY,
        /// <summary>A security package specific error occurred.</summary>

        rpc_s_sec_pkg_error = RPC_S_SEC_PKG_ERROR,
        /// <summary>Thread is not canceled.</summary>

        rpc_s_not_cancelled = RPC_S_NOT_CANCELLED,
        /// <summary>Invalid operation on the encoding/decoding handle.</summary>

        rpc_x_invalid_es_action = RPC_X_INVALID_ES_ACTION,
        /// <summary>Incompatible version of the serializing package.</summary>

        rpc_x_wrong_es_version = RPC_X_WRONG_ES_VERSION,
        /// <summary>Incompatible version of the RPC stub.</summary>

        rpc_x_wrong_stub_version = RPC_X_WRONG_STUB_VERSION,
        /// <summary>The RPC pipe object is invalid or corrupted.</summary>

        rpc_x_invalid_pipe_object = RPC_X_INVALID_PIPE_OBJECT,
        /// <summary>An invalid operation was attempted on an RPC pipe object.</summary>

        rpc_x_wrong_pipe_order = RPC_X_WRONG_PIPE_ORDER,
        /// <summary>Unsupported RPC pipe version.</summary>

        rpc_x_wrong_pipe_version = RPC_X_WRONG_PIPE_VERSION,
        /// <summary>HTTP proxy server rejected the connection because the cookie authentication failed.</summary>

        rpc_s_cookie_auth_failed = RPC_S_COOKIE_AUTH_FAILED,
        /// <summary>The RPC server is suspended, and could not be resumed for this request. The call did not execute.</summary>

        rpc_s_do_not_disturb = RPC_S_DO_NOT_DISTURB,
        /// <summary>The RPC call contains too many handles to be transmitted in a single request.</summary>

        rpc_s_system_handle_count_exceeded = RPC_S_SYSTEM_HANDLE_COUNT_EXCEEDED,
        /// <summary>The RPC call contains a handle that differs from the declared handle type.</summary>

        rpc_s_system_handle_type_mismatch = RPC_S_SYSTEM_HANDLE_TYPE_MISMATCH,
        /// <summary>The group member was not found.</summary>

        rpc_s_group_member_not_found = RPC_S_GROUP_MEMBER_NOT_FOUND,
        /// <summary>The endpoint mapper database entry could not be created.</summary>

        ept_s_cant_create = EPT_S_CANT_CREATE,
        /// <summary>The object universal unique identifier (UUID) is the nil UUID.</summary>

        rpc_s_invalid_object = RPC_S_INVALID_OBJECT,
        /// <summary>The specified time is invalid.</summary>

        error_invalid_time = ERROR_INVALID_TIME,
        /// <summary>The specified form name is invalid.</summary>

        error_invalid_form_name = ERROR_INVALID_FORM_NAME,
        /// <summary>The specified form size is invalid.</summary>

        error_invalid_form_size = ERROR_INVALID_FORM_SIZE,
        /// <summary>The specified printer handle is already being waited on</summary>

        error_already_waiting = ERROR_ALREADY_WAITING,
        /// <summary>The specified printer has been deleted.</summary>

        error_printer_deleted = ERROR_PRINTER_DELETED,
        /// <summary>The state of the printer is invalid.</summary>

        error_invalid_printer_state = ERROR_INVALID_PRINTER_STATE,
        /// <summary>The user's password must be changed before signing in.</summary>

        error_password_must_change = ERROR_PASSWORD_MUST_CHANGE,
        /// <summary>Could not find the domain controller for this domain.</summary>

        error_domain_controller_not_found = ERROR_DOMAIN_CONTROLLER_NOT_FOUND,
        /// <summary>The referenced account is currently locked out and may not be logged on to.</summary>

        error_account_locked_out = ERROR_ACCOUNT_LOCKED_OUT,
        /// <summary>The object exporter specified was not found.</summary>

        or_invalid_oxid = OR_INVALID_OXID,
        /// <summary>The object specified was not found.</summary>

        or_invalid_oid = OR_INVALID_OID,
        /// <summary>The object resolver set specified was not found.</summary>

        or_invalid_set = OR_INVALID_SET,
        /// <summary>Some data remains to be sent in the request buffer.</summary>

        rpc_s_send_incomplete = RPC_S_SEND_INCOMPLETE,
        /// <summary>Invalid asynchronous remote procedure call handle.</summary>

        rpc_s_invalid_async_handle = RPC_S_INVALID_ASYNC_HANDLE,
        /// <summary>Invalid asynchronous RPC call handle for this operation.</summary>

        rpc_s_invalid_async_call = RPC_S_INVALID_ASYNC_CALL,
        /// <summary>The RPC pipe object has already been closed.</summary>

        rpc_x_pipe_closed = RPC_X_PIPE_CLOSED,
        /// <summary>The RPC call completed before all pipes were processed.</summary>

        rpc_x_pipe_discipline_error = RPC_X_PIPE_DISCIPLINE_ERROR,
        /// <summary>No more data is available from the RPC pipe.</summary>

        rpc_x_pipe_empty = RPC_X_PIPE_EMPTY,
        /// <summary>No site name is available for this machine.</summary>

        error_no_sitename = ERROR_NO_SITENAME,
        /// <summary>The file cannot be accessed by the system.</summary>

        error_cant_access_file = ERROR_CANT_ACCESS_FILE,
        /// <summary>The name of the file cannot be resolved by the system.</summary>

        error_cant_resolve_filename = ERROR_CANT_RESOLVE_FILENAME,
        /// <summary>The entry is not of the expected type.</summary>

        rpc_s_entry_type_mismatch = RPC_S_ENTRY_TYPE_MISMATCH,
        /// <summary>Not all object UUIDs could be exported to the specified entry.</summary>

        rpc_s_not_all_objs_exported = RPC_S_NOT_ALL_OBJS_EXPORTED,
        /// <summary>Interface could not be exported to the specified entry.</summary>

        rpc_s_interface_not_exported = RPC_S_INTERFACE_NOT_EXPORTED,
        /// <summary>The specified profile entry could not be added.</summary>

        rpc_s_profile_not_added = RPC_S_PROFILE_NOT_ADDED,
        /// <summary>The specified profile element could not be added.</summary>

        rpc_s_prf_elt_not_added = RPC_S_PRF_ELT_NOT_ADDED,
        /// <summary>The specified profile element could not be removed.</summary>

        rpc_s_prf_elt_not_removed = RPC_S_PRF_ELT_NOT_REMOVED,
        /// <summary>The group element could not be added.</summary>

        rpc_s_grp_elt_not_added = RPC_S_GRP_ELT_NOT_ADDED,
        /// <summary>The group element could not be removed.</summary>

        rpc_s_grp_elt_not_removed = RPC_S_GRP_ELT_NOT_REMOVED,
        /// <summary>The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.</summary>

        error_km_driver_blocked = ERROR_KM_DRIVER_BLOCKED,
        /// <summary>The context has expired and can no longer be used.</summary>

        error_context_expired = ERROR_CONTEXT_EXPIRED,
        /// <summary>The current user's delegated trust creation quota has been exceeded.</summary>

        error_per_user_trust_quota_exceeded = ERROR_PER_USER_TRUST_QUOTA_EXCEEDED,
        /// <summary>The total delegated trust creation quota has been exceeded.</summary>

        error_all_user_trust_quota_exceeded = ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED,
        /// <summary>The current user's delegated trust deletion quota has been exceeded.</summary>

        error_user_delete_trust_quota_exceeded = ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED,
        /// <summary>The computer you are signing into is protected by an authentication firewall. The specified account is not allowed to authenticate to the computer.</summary>

        error_authentication_firewall_failed = ERROR_AUTHENTICATION_FIREWALL_FAILED,
        /// <summary>Remote connections to the Print Spooler are blocked by a policy set on your machine.</summary>

        error_remote_print_connections_blocked = ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED,
        /// <summary>Authentication failed because NTLM authentication has been disabled.</summary>

        error_ntlm_blocked = ERROR_NTLM_BLOCKED,
        /// <summary>Logon Failure: EAS policy requires that the user change their password before this operation can be performed.</summary>

        error_password_change_required = ERROR_PASSWORD_CHANGE_REQUIRED,
        /// <summary>An administrator has restricted sign in. To sign in, make sure your device is connected to the Internet, and have your administrator sign in first.</summary>

        error_lost_mode_logon_restriction = ERROR_LOST_MODE_LOGON_RESTRICTION,
        /// <summary>The pixel format is invalid.</summary>

        error_invalid_pixel_format = ERROR_INVALID_PIXEL_FORMAT,
        /// <summary>The specified driver is invalid.</summary>

        error_bad_driver = ERROR_BAD_DRIVER,
        /// <summary>The window style or class attribute is invalid for this operation.</summary>

        error_invalid_window_style = ERROR_INVALID_WINDOW_STYLE,
        /// <summary>The requested metafile operation is not supported.</summary>

        error_metafile_not_supported = ERROR_METAFILE_NOT_SUPPORTED,
        /// <summary>The requested transformation operation is not supported.</summary>

        error_transform_not_supported = ERROR_TRANSFORM_NOT_SUPPORTED,
        /// <summary>The requested clipping operation is not supported.</summary>

        error_clipping_not_supported = ERROR_CLIPPING_NOT_SUPPORTED,
        /// <summary>The specified color management module is invalid.</summary>

        error_invalid_cmm = ERROR_INVALID_CMM,
        /// <summary>The specified color profile is invalid.</summary>

        error_invalid_profile = ERROR_INVALID_PROFILE,
        /// <summary>The specified tag was not found.</summary>

        error_tag_not_found = ERROR_TAG_NOT_FOUND,
        /// <summary>A required tag is not present.</summary>

        error_tag_not_present = ERROR_TAG_NOT_PRESENT,
        /// <summary>The specified tag is already present.</summary>

        error_duplicate_tag = ERROR_DUPLICATE_TAG,
        /// <summary>The specified color profile is not associated with the specified device.</summary>

        error_profile_not_associated_with_device = ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE,
        /// <summary>The specified color profile was not found.</summary>

        error_profile_not_found = ERROR_PROFILE_NOT_FOUND,
        /// <summary>The specified color space is invalid.</summary>

        error_invalid_colorspace = ERROR_INVALID_COLORSPACE,
        /// <summary>Image Color Management is not enabled.</summary>

        error_icm_not_enabled = ERROR_ICM_NOT_ENABLED,
        /// <summary>There was an error while deleting the color transform.</summary>

        error_deleting_icm_xform = ERROR_DELETING_ICM_XFORM,
        /// <summary>The specified color transform is invalid.</summary>

        error_invalid_transform = ERROR_INVALID_TRANSFORM,
        /// <summary>The specified transform does not match the bitmap's color space.</summary>

        error_colorspace_mismatch = ERROR_COLORSPACE_MISMATCH,
        /// <summary>The specified named color index is not present in the profile.</summary>

        error_invalid_colorindex = ERROR_INVALID_COLORINDEX,
        /// <summary>The specified profile is intended for a device of a different type than the specified device.</summary>

        error_profile_does_not_match_device = ERROR_PROFILE_DOES_NOT_MATCH_DEVICE,
        /// <summary>The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.</summary>

        error_connected_other_password = ERROR_CONNECTED_OTHER_PASSWORD,
        /// <summary>The network connection was made successfully using default credentials.</summary>

        error_connected_other_password_default = ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT,
        /// <summary>The specified username is invalid.</summary>

        error_bad_username = ERROR_BAD_USERNAME,
        /// <summary>This network connection does not exist.</summary>

        error_not_connected = ERROR_NOT_CONNECTED,
        /// <summary>This network connection has files open or requests pending.</summary>

        error_open_files = ERROR_OPEN_FILES,
        /// <summary>Active connections still exist.</summary>

        error_active_connections = ERROR_ACTIVE_CONNECTIONS,
        /// <summary>The device is in use by an active process and cannot be disconnected.</summary>

        error_device_in_use = ERROR_DEVICE_IN_USE,
        /// <summary>The specified print monitor is unknown.</summary>

        error_unknown_print_monitor = ERROR_UNKNOWN_PRINT_MONITOR,
        /// <summary>The specified printer driver is currently in use.</summary>

        error_printer_driver_in_use = ERROR_PRINTER_DRIVER_IN_USE,
        /// <summary>The spool file was not found.</summary>

        error_spool_file_not_found = ERROR_SPOOL_FILE_NOT_FOUND,
        /// <summary>A StartDocPrinter call was not issued.</summary>

        error_spl_no_startdoc = ERROR_SPL_NO_STARTDOC,
        /// <summary>An AddJob call was not issued.</summary>

        error_spl_no_addjob = ERROR_SPL_NO_ADDJOB,
        /// <summary>The specified print processor has already been installed.</summary>

        error_print_processor_already_installed = ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED,
        /// <summary>The specified print monitor has already been installed.</summary>

        error_print_monitor_already_installed = ERROR_PRINT_MONITOR_ALREADY_INSTALLED,
        /// <summary>The specified print monitor does not have the required functions.</summary>

        error_invalid_print_monitor = ERROR_INVALID_PRINT_MONITOR,
        /// <summary>The specified print monitor is currently in use.</summary>

        error_print_monitor_in_use = ERROR_PRINT_MONITOR_IN_USE,
        /// <summary>The requested operation is not allowed when there are jobs queued to the printer.</summary>

        error_printer_has_jobs_queued = ERROR_PRINTER_HAS_JOBS_QUEUED,
        /// <summary>The requested operation is successful. Changes will not be effective until the system is rebooted.</summary>

        error_success_reboot_required = ERROR_SUCCESS_REBOOT_REQUIRED,
        /// <summary>The requested operation is successful. Changes will not be effective until the service is restarted.</summary>

        error_success_restart_required = ERROR_SUCCESS_RESTART_REQUIRED,
        /// <summary>No printers were found.</summary>

        error_printer_not_found = ERROR_PRINTER_NOT_FOUND,
        /// <summary>The printer driver is known to be unreliable.</summary>

        error_printer_driver_warned = ERROR_PRINTER_DRIVER_WARNED,
        /// <summary>The printer driver is known to harm the system.</summary>

        error_printer_driver_blocked = ERROR_PRINTER_DRIVER_BLOCKED,
        /// <summary>The specified printer driver package is currently in use.</summary>

        error_printer_driver_package_in_use = ERROR_PRINTER_DRIVER_PACKAGE_IN_USE,
        /// <summary>Unable to find a core driver package that is required by the printer driver package.</summary>

        error_core_driver_package_not_found = ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND,
        /// <summary>The requested operation failed. A system reboot is required to roll back changes made.</summary>

        error_fail_reboot_required = ERROR_FAIL_REBOOT_REQUIRED,
        /// <summary>The requested operation failed. A system reboot has been initiated to roll back changes made.</summary>

        error_fail_reboot_initiated = ERROR_FAIL_REBOOT_INITIATED,
        /// <summary>The specified printer driver was not found on the system and needs to be downloaded.</summary>

        error_printer_driver_download_needed = ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED,
        /// <summary>The requested print job has failed to print. A print system update requires the job to be resubmitted.</summary>

        error_print_job_restart_required = ERROR_PRINT_JOB_RESTART_REQUIRED,
        /// <summary>The printer driver does not contain a valid manifest, or contains too many manifests.</summary>

        error_invalid_printer_driver_manifest = ERROR_INVALID_PRINTER_DRIVER_MANIFEST,
        /// <summary>The specified printer cannot be shared.</summary>

        error_printer_not_shareable = ERROR_PRINTER_NOT_SHAREABLE,
        /// <summary>The operation was paused.</summary>

        error_request_paused = ERROR_REQUEST_PAUSED,
        /// <summary>The condition supplied for the app execution request was not satisfied, so the request was not performed.</summary>

        error_appexec_condition_not_satisfied = ERROR_APPEXEC_CONDITION_NOT_SATISFIED,
        /// <summary>The supplied handle has been invalidated and may not be used for the requested operation.</summary>

        error_appexec_handle_invalidated = ERROR_APPEXEC_HANDLE_INVALIDATED,
        /// <summary>The supplied host generation has been invalidated and may not be used for the requested operation.</summary>

        error_appexec_invalid_host_generation = ERROR_APPEXEC_INVALID_HOST_GENERATION,
        /// <summary>An attempt to register a process failed because the target host was not in a valid state to receive process registrations.</summary>

        error_appexec_unexpected_process_registration = ERROR_APPEXEC_UNEXPECTED_PROCESS_REGISTRATION,
        /// <summary>The host is not in a valid state to support the execution request.</summary>

        error_appexec_invalid_host_state = ERROR_APPEXEC_INVALID_HOST_STATE,
        /// <summary>The operation was not completed because a required resource donor was not found for the host.</summary>

        error_appexec_no_donor = ERROR_APPEXEC_NO_DONOR,
        /// <summary>The operation was not completed because an unexpected host ID was encountered.</summary>

        error_appexec_host_id_mismatch = ERROR_APPEXEC_HOST_ID_MISMATCH,
        /// <summary>The operation was not completed because the specified user was not known to the service.</summary>

        error_appexec_unknown_user = ERROR_APPEXEC_UNKNOWN_USER,

        /// <summary>Reissue the given operation as a cached IO operation</summary>

        error_io_reissue_as_cached = ERROR_IO_REISSUE_AS_CACHED,

        /// <summary>WINS encountered an error while processing the command.</summary>

        error_wins_internal = ERROR_WINS_INTERNAL,
        /// <summary>The local WINS cannot be deleted.</summary>

        error_can_not_del_local_wins = ERROR_CAN_NOT_DEL_LOCAL_WINS,
        /// <summary>The importation from the file failed.</summary>

        error_static_init = ERROR_STATIC_INIT,
        /// <summary>The backup failed. Was a full backup done before?</summary>

        error_inc_backup = ERROR_INC_BACKUP,
        /// <summary>The backup failed. Check the directory to which you are backing the database.</summary>

        error_full_backup = ERROR_FULL_BACKUP,
        /// <summary>The name does not exist in the WINS database.</summary>

        error_rec_non_existent = ERROR_REC_NON_EXISTENT,
        /// <summary>Replication with a nonconfigured partner is not allowed.</summary>

        error_rpl_not_allowed = ERROR_RPL_NOT_ALLOWED,
        /// <summary>The version of the supplied content information is not supported.</summary>

        peerdist_error_contentinfo_version_unsupported = PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED,
        /// <summary>The supplied content information is malformed.</summary>

        peerdist_error_cannot_parse_contentinfo = PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO,
        /// <summary>The requested data cannot be found in local or peer caches.</summary>

        peerdist_error_missing_data = PEERDIST_ERROR_MISSING_DATA,
        /// <summary>No more data is available or required.</summary>

        peerdist_error_no_more = PEERDIST_ERROR_NO_MORE,
        /// <summary>The supplied object has not been initialized.</summary>

        peerdist_error_not_initialized = PEERDIST_ERROR_NOT_INITIALIZED,
        /// <summary>The supplied object has already been initialized.</summary>

        peerdist_error_already_initialized = PEERDIST_ERROR_ALREADY_INITIALIZED,
        /// <summary>A shutdown operation is already in progress.</summary>

        peerdist_error_shutdown_in_progress = PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS,
        /// <summary>The supplied object has already been invalidated.</summary>

        peerdist_error_invalidated = PEERDIST_ERROR_INVALIDATED,
        /// <summary>An element already exists and was not replaced.</summary>

        peerdist_error_already_exists = PEERDIST_ERROR_ALREADY_EXISTS,
        /// <summary>Can not cancel the requested operation as it has already been completed.</summary>

        peerdist_error_operation_notfound = PEERDIST_ERROR_OPERATION_NOTFOUND,
        /// <summary>Can not perform the requested operation because it has already been carried out.</summary>

        peerdist_error_already_completed = PEERDIST_ERROR_ALREADY_COMPLETED,
        /// <summary>An operation accessed data beyond the bounds of valid data.</summary>

        peerdist_error_out_of_bounds = PEERDIST_ERROR_OUT_OF_BOUNDS,
        /// <summary>The requested version is not supported.</summary>

        peerdist_error_version_unsupported = PEERDIST_ERROR_VERSION_UNSUPPORTED,
        /// <summary>A configuration value is invalid.</summary>

        peerdist_error_invalid_configuration = PEERDIST_ERROR_INVALID_CONFIGURATION,
        /// <summary>The SKU is not licensed.</summary>

        peerdist_error_not_licensed = PEERDIST_ERROR_NOT_LICENSED,
        /// <summary>PeerDist Service is still initializing and will be available shortly.</summary>

        peerdist_error_service_unavailable = PEERDIST_ERROR_SERVICE_UNAVAILABLE,
        /// <summary>Communication with one or more computers will be temporarily blocked due to recent errors.</summary>

        peerdist_error_trust_failure = PEERDIST_ERROR_TRUST_FAILURE,
        /// <summary>The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address.</summary>

        error_dhcp_address_conflict = ERROR_DHCP_ADDRESS_CONFLICT,
        /// <summary>The GUID passed was not recognized as valid by a WMI data provider.</summary>

        error_wmi_guid_not_found = ERROR_WMI_GUID_NOT_FOUND,
        /// <summary>The instance name passed was not recognized as valid by a WMI data provider.</summary>

        error_wmi_instance_not_found = ERROR_WMI_INSTANCE_NOT_FOUND,
        /// <summary>The data item ID passed was not recognized as valid by a WMI data provider.</summary>

        error_wmi_itemid_not_found = ERROR_WMI_ITEMID_NOT_FOUND,
        /// <summary>The WMI request could not be completed and should be retried.</summary>

        error_wmi_try_again = ERROR_WMI_TRY_AGAIN,
        /// <summary>The WMI data provider could not be located.</summary>

        error_wmi_dp_not_found = ERROR_WMI_DP_NOT_FOUND,
        /// <summary>The WMI data provider references an instance set that has not been registered.</summary>

        error_wmi_unresolved_instance_ref = ERROR_WMI_UNRESOLVED_INSTANCE_REF,
        /// <summary>The WMI data block or event notification has already been enabled.</summary>

        error_wmi_already_enabled = ERROR_WMI_ALREADY_ENABLED,
        /// <summary>The WMI data block is no longer available.</summary>

        error_wmi_guid_disconnected = ERROR_WMI_GUID_DISCONNECTED,
        /// <summary>The WMI data service is not available.</summary>

        error_wmi_server_unavailable = ERROR_WMI_SERVER_UNAVAILABLE,
        /// <summary>The WMI data provider failed to carry out the request.</summary>

        error_wmi_dp_failed = ERROR_WMI_DP_FAILED,
        /// <summary>The WMI MOF information is not valid.</summary>

        error_wmi_invalid_mof = ERROR_WMI_INVALID_MOF,
        /// <summary>The WMI registration information is not valid.</summary>

        error_wmi_invalid_reginfo = ERROR_WMI_INVALID_REGINFO,
        /// <summary>The WMI data block or event notification has already been disabled.</summary>

        error_wmi_already_disabled = ERROR_WMI_ALREADY_DISABLED,
        /// <summary>The WMI data item or data block is read only.</summary>

        error_wmi_read_only = ERROR_WMI_READ_ONLY,
        /// <summary>The WMI data item or data block could not be changed.</summary>

        error_wmi_set_failure = ERROR_WMI_SET_FAILURE,
        /// <summary>This operation is only valid in the context of an app container.</summary>

        error_not_appcontainer = ERROR_NOT_APPCONTAINER,
        /// <summary>This application can only run in the context of an app container.</summary>

        error_appcontainer_required = ERROR_APPCONTAINER_REQUIRED,
        /// <summary>This functionality is not supported in the context of an app container.</summary>

        error_not_supported_in_appcontainer = ERROR_NOT_SUPPORTED_IN_APPCONTAINER,
        /// <summary>The length of the SID supplied is not a valid length for app container SIDs.</summary>

        error_invalid_package_sid_length = ERROR_INVALID_PACKAGE_SID_LENGTH,

        /// <summary>The media identifier does not represent a valid medium.</summary>

        error_invalid_media = ERROR_INVALID_MEDIA,
        /// <summary>The library identifier does not represent a valid library.</summary>

        error_invalid_library = ERROR_INVALID_LIBRARY,
        /// <summary>The media pool identifier does not represent a valid media pool.</summary>

        error_invalid_media_pool = ERROR_INVALID_MEDIA_POOL,
        /// <summary>The drive and medium are not compatible or exist in different libraries.</summary>

        error_drive_media_mismatch = ERROR_DRIVE_MEDIA_MISMATCH,
        /// <summary>The medium currently exists in an offline library and must be online to perform this operation.</summary>

        error_media_offline = ERROR_MEDIA_OFFLINE,
        /// <summary>The operation cannot be performed on an offline library.</summary>

        error_library_offline = ERROR_LIBRARY_OFFLINE,
        /// <summary>The library, drive, or media pool is empty.</summary>

        error_empty = ERROR_EMPTY,
        /// <summary>The library, drive, or media pool must be empty to perform this operation.</summary>

        error_not_empty = ERROR_NOT_EMPTY,
        /// <summary>No media is currently available in this media pool or library.</summary>

        error_media_unavailable = ERROR_MEDIA_UNAVAILABLE,
        /// <summary>A resource required for this operation is disabled.</summary>

        error_resource_disabled = ERROR_RESOURCE_DISABLED,
        /// <summary>The media identifier does not represent a valid cleaner.</summary>

        error_invalid_cleaner = ERROR_INVALID_CLEANER,
        /// <summary>The drive cannot be cleaned or does not support cleaning.</summary>

        error_unable_to_clean = ERROR_UNABLE_TO_CLEAN,
        /// <summary>The object identifier does not represent a valid object.</summary>

        error_object_not_found = ERROR_OBJECT_NOT_FOUND,
        /// <summary>Unable to read from or write to the database.</summary>

        error_database_failure = ERROR_DATABASE_FAILURE,
        /// <summary>The database is full.</summary>

        error_database_full = ERROR_DATABASE_FULL,
        /// <summary>The medium is not compatible with the device or media pool.</summary>

        error_media_incompatible = ERROR_MEDIA_INCOMPATIBLE,
        /// <summary>The resource required for this operation does not exist.</summary>

        error_resource_not_present = ERROR_RESOURCE_NOT_PRESENT,
        /// <summary>The operation identifier is not valid.</summary>

        error_invalid_operation = ERROR_INVALID_OPERATION,
        /// <summary>The media is not mounted or ready for use.</summary>

        error_media_not_available = ERROR_MEDIA_NOT_AVAILABLE,
        /// <summary>The device is not ready for use.</summary>

        error_device_not_available = ERROR_DEVICE_NOT_AVAILABLE,
        /// <summary>The operator or administrator has refused the request.</summary>

        error_request_refused = ERROR_REQUEST_REFUSED,
        /// <summary>The drive identifier does not represent a valid drive.</summary>

        error_invalid_drive_object = ERROR_INVALID_DRIVE_OBJECT,
        /// <summary>Library is full. No slot is available for use.</summary>

        error_library_full = ERROR_LIBRARY_FULL,
        /// <summary>The transport cannot access the medium.</summary>

        error_medium_not_accessible = ERROR_MEDIUM_NOT_ACCESSIBLE,
        /// <summary>Unable to load the medium into the drive.</summary>

        error_unable_to_load_medium = ERROR_UNABLE_TO_LOAD_MEDIUM,
        /// <summary>Unable to retrieve the drive status.</summary>

        error_unable_to_inventory_drive = ERROR_UNABLE_TO_INVENTORY_DRIVE,
        /// <summary>Unable to retrieve the slot status.</summary>

        error_unable_to_inventory_slot = ERROR_UNABLE_TO_INVENTORY_SLOT,
        /// <summary>Unable to retrieve status about the transport.</summary>

        error_unable_to_inventory_transport = ERROR_UNABLE_TO_INVENTORY_TRANSPORT,
        /// <summary>Cannot use the transport because it is already in use.</summary>

        error_transport_full = ERROR_TRANSPORT_FULL,
        /// <summary>Unable to open or close the inject/eject port.</summary>

        error_controlling_ieport = ERROR_CONTROLLING_IEPORT,
        /// <summary>Unable to eject the medium because it is in a drive.</summary>

        error_unable_to_eject_mounted_media = ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA,
        /// <summary>A cleaner slot is already reserved.</summary>

        error_cleaner_slot_set = ERROR_CLEANER_SLOT_SET,
        /// <summary>A cleaner slot is not reserved.</summary>

        error_cleaner_slot_not_set = ERROR_CLEANER_SLOT_NOT_SET,
        /// <summary>The cleaner cartridge has performed the maximum number of drive cleanings.</summary>

        error_cleaner_cartridge_spent = ERROR_CLEANER_CARTRIDGE_SPENT,
        /// <summary>Unexpected on-medium identifier.</summary>

        error_unexpected_omid = ERROR_UNEXPECTED_OMID,
        /// <summary>The last remaining item in this group or resource cannot be deleted.</summary>

        error_cant_delete_last_item = ERROR_CANT_DELETE_LAST_ITEM,
        /// <summary>The message provided exceeds the maximum size allowed for this parameter.</summary>

        error_message_exceeds_max_size = ERROR_MESSAGE_EXCEEDS_MAX_SIZE,
        /// <summary>The volume contains system or paging files.</summary>

        error_volume_contains_sys_files = ERROR_VOLUME_CONTAINS_SYS_FILES,
        /// <summary>The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.</summary>

        error_indigenous_type = ERROR_INDIGENOUS_TYPE,
        /// <summary>This offline media cannot be mounted on this system since no enabled drives are present which can be used.</summary>

        error_no_supporting_drives = ERROR_NO_SUPPORTING_DRIVES,
        /// <summary>A cleaner cartridge is present in the tape library.</summary>

        error_cleaner_cartridge_installed = ERROR_CLEANER_CARTRIDGE_INSTALLED,
        /// <summary>Cannot use the inject/eject port because it is not empty.</summary>

        error_ieport_full = ERROR_IEPORT_FULL,
        /// <summary>This file is currently not available for use on this computer.</summary>

        error_file_offline = ERROR_FILE_OFFLINE,
        /// <summary>The remote storage service is not operational at this time.</summary>

        error_remote_storage_not_active = ERROR_REMOTE_STORAGE_NOT_ACTIVE,
        /// <summary>The remote storage service encountered a media error.</summary>

        error_remote_storage_media_error = ERROR_REMOTE_STORAGE_MEDIA_ERROR,
        /// <summary>The file or directory is not a reparse point.</summary>

        error_not_a_reparse_point = ERROR_NOT_A_REPARSE_POINT,
        /// <summary>The reparse point attribute cannot be set because it conflicts with an existing attribute.</summary>

        error_reparse_attribute_conflict = ERROR_REPARSE_ATTRIBUTE_CONFLICT,
        /// <summary>The data present in the reparse point buffer is invalid.</summary>

        error_invalid_reparse_data = ERROR_INVALID_REPARSE_DATA,
        /// <summary>The tag present in the reparse point buffer is invalid.</summary>

        error_reparse_tag_invalid = ERROR_REPARSE_TAG_INVALID,
        /// <summary>There is a mismatch between the tag specified in the request and the tag present in the reparse point.</summary>

        error_reparse_tag_mismatch = ERROR_REPARSE_TAG_MISMATCH,
        /// <summary>The object manager encountered a reparse point while retrieving an object.</summary>

        error_reparse_point_encountered = ERROR_REPARSE_POINT_ENCOUNTERED,
        /// <summary>Fast Cache data not found.</summary>

        error_app_data_not_found = ERROR_APP_DATA_NOT_FOUND,
        /// <summary>Fast Cache data expired.</summary>

        error_app_data_expired = ERROR_APP_DATA_EXPIRED,
        /// <summary>Fast Cache data corrupt.</summary>

        error_app_data_corrupt = ERROR_APP_DATA_CORRUPT,
        /// <summary>Fast Cache data has exceeded its max size and cannot be updated.</summary>

        error_app_data_limit_exceeded = ERROR_APP_DATA_LIMIT_EXCEEDED,
        /// <summary>Fast Cache has been ReArmed and requires a reboot until it can be updated.</summary>

        error_app_data_reboot_required = ERROR_APP_DATA_REBOOT_REQUIRED,
        /// <summary>Secure Boot detected that rollback of protected data has been attempted.</summary>

        error_secureboot_rollback_detected = ERROR_SECUREBOOT_ROLLBACK_DETECTED,
        /// <summary>The value is protected by Secure Boot policy and cannot be modified or deleted.</summary>

        error_secureboot_policy_violation = ERROR_SECUREBOOT_POLICY_VIOLATION,
        /// <summary>The Secure Boot policy is invalid.</summary>

        error_secureboot_invalid_policy = ERROR_SECUREBOOT_INVALID_POLICY,
        /// <summary>A new Secure Boot policy did not contain the current publisher on its update list.</summary>

        error_secureboot_policy_publisher_not_found = ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND,
        /// <summary>The Secure Boot policy is either not signed or is signed by a non-trusted signer.</summary>

        error_secureboot_policy_not_signed = ERROR_SECUREBOOT_POLICY_NOT_SIGNED,
        /// <summary>Secure Boot is not enabled on this machine.</summary>

        error_secureboot_not_enabled = ERROR_SECUREBOOT_NOT_ENABLED,
        /// <summary>Secure Boot requires that certain files and drivers are not replaced by other files or drivers.</summary>

        error_secureboot_file_replaced = ERROR_SECUREBOOT_FILE_REPLACED,
        /// <summary>The Secure Boot Supplemental Policy file was not authorized on this machine.</summary>

        error_secureboot_policy_not_authorized = ERROR_SECUREBOOT_POLICY_NOT_AUTHORIZED,
        /// <summary>The Supplemental Policy is not recognized on this device.</summary>

        error_secureboot_policy_unknown = ERROR_SECUREBOOT_POLICY_UNKNOWN,
        /// <summary>The Antirollback version was not found in the Secure Boot Policy.</summary>

        error_secureboot_policy_missing_antirollbackversion = ERROR_SECUREBOOT_POLICY_MISSING_ANTIROLLBACKVERSION,
        /// <summary>The Platform ID specified in the Secure Boot policy does not match the Platform ID on this device.</summary>

        error_secureboot_platform_id_mismatch = ERROR_SECUREBOOT_PLATFORM_ID_MISMATCH,
        /// <summary>The Secure Boot policy file has an older Antirollback Version than this device.</summary>

        error_secureboot_policy_rollback_detected = ERROR_SECUREBOOT_POLICY_ROLLBACK_DETECTED,
        /// <summary>The Secure Boot policy file does not match the upgraded legacy policy.</summary>

        error_secureboot_policy_upgrade_mismatch = ERROR_SECUREBOOT_POLICY_UPGRADE_MISMATCH,
        /// <summary>The Secure Boot policy file is required but could not be found.</summary>

        error_secureboot_required_policy_file_missing = ERROR_SECUREBOOT_REQUIRED_POLICY_FILE_MISSING,
        /// <summary>Supplemental Secure Boot policy file can not be loaded as a base Secure Boot policy.</summary>

        error_secureboot_not_base_policy = ERROR_SECUREBOOT_NOT_BASE_POLICY,
        /// <summary>Base Secure Boot policy file can not be loaded as a Supplemental Secure Boot policy.</summary>

        error_secureboot_not_supplemental_policy = ERROR_SECUREBOOT_NOT_SUPPLEMENTAL_POLICY,
        /// <summary>The copy offload read operation is not supported by a filter.</summary>

        error_offload_read_flt_not_supported = ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED,
        /// <summary>The copy offload write operation is not supported by a filter.</summary>

        error_offload_write_flt_not_supported = ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED,
        /// <summary>The copy offload read operation is not supported for the file.</summary>

        error_offload_read_file_not_supported = ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED,
        /// <summary>The copy offload write operation is not supported for the file.</summary>

        error_offload_write_file_not_supported = ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED,
        /// <summary>This file is currently associated with a different stream id.</summary>

        error_already_has_stream_id = ERROR_ALREADY_HAS_STREAM_ID,
        /// <summary>The volume must undergo garbage collection.</summary>

        error_smr_garbage_collection_required = ERROR_SMR_GARBAGE_COLLECTION_REQUIRED,
        /// <summary>The WOF driver encountered a corruption in WIM image's Header.</summary>

        error_wof_wim_header_corrupt = ERROR_WOF_WIM_HEADER_CORRUPT,
        /// <summary>The WOF driver encountered a corruption in WIM image's Resource Table.</summary>

        error_wof_wim_resource_table_corrupt = ERROR_WOF_WIM_RESOURCE_TABLE_CORRUPT,
        /// <summary>The WOF driver encountered a corruption in the compressed file's Resource Table.</summary>

        error_wof_file_resource_table_corrupt = ERROR_WOF_FILE_RESOURCE_TABLE_CORRUPT,
        /// <summary>Single Instance Storage is not available on this volume.</summary>

        error_volume_not_sis_enabled = ERROR_VOLUME_NOT_SIS_ENABLED,
        /// <summary>System Integrity detected that policy rollback has been attempted.</summary>

        error_system_integrity_rollback_detected = ERROR_SYSTEM_INTEGRITY_ROLLBACK_DETECTED,
        /// <summary>Your organization used Device Guard to block this app. Contact your support person for more info.</summary>

        error_system_integrity_policy_violation = ERROR_SYSTEM_INTEGRITY_POLICY_VIOLATION,
        /// <summary>The System Integrity policy is invalid.</summary>

        error_system_integrity_invalid_policy = ERROR_SYSTEM_INTEGRITY_INVALID_POLICY,
        /// <summary>The System Integrity policy is either not signed or is signed by a non-trusted signer.</summary>

        error_system_integrity_policy_not_signed = ERROR_SYSTEM_INTEGRITY_POLICY_NOT_SIGNED,
        /// <summary>The number of System Integrity policies is out of limit.</summary>

        error_system_integrity_too_many_policies = ERROR_SYSTEM_INTEGRITY_TOO_MANY_POLICIES,
        /// <summary>The Code Integrity supplemental policy is not authorized by a Code Integrity base policy.</summary>

        error_system_integrity_supplemental_policy_not_authorized = ERROR_SYSTEM_INTEGRITY_SUPPLEMENTAL_POLICY_NOT_AUTHORIZED,
        /// <summary>Virtual Secure Mode (VSM) is not initialized. The hypervisor or VSM may not be present or enabled.</summary>

        error_vsm_not_initialized = ERROR_VSM_NOT_INITIALIZED,
        /// <summary>The hypervisor is not protecting DMA because an IOMMU is not present or not enabled in the BIOS.</summary>

        error_vsm_dma_protection_not_in_use = ERROR_VSM_DMA_PROTECTION_NOT_IN_USE,

        /// <summary>The Platform Manifest file was not authorized on this machine.</summary>

        error_platform_manifest_not_authorized = ERROR_PLATFORM_MANIFEST_NOT_AUTHORIZED,
        /// <summary>The Platform Manifest file was not valid.</summary>

        error_platform_manifest_invalid = ERROR_PLATFORM_MANIFEST_INVALID,
        /// <summary>The file is not authorized on this platform because an entry was not found in the Platform Manifest.</summary>

        error_platform_manifest_file_not_authorized = ERROR_PLATFORM_MANIFEST_FILE_NOT_AUTHORIZED,
        /// <summary>The catalog is not authorized on this platform because an entry was not found in the Platform Manifest.</summary>

        error_platform_manifest_catalog_not_authorized = ERROR_PLATFORM_MANIFEST_CATALOG_NOT_AUTHORIZED,
        /// <summary>The file is not authorized on this platform because a Binary ID was not found in the embedded signature.</summary>

        error_platform_manifest_binary_id_not_found = ERROR_PLATFORM_MANIFEST_BINARY_ID_NOT_FOUND,
        /// <summary>No active Platform Manifest exists on this system.</summary>

        error_platform_manifest_not_active = ERROR_PLATFORM_MANIFEST_NOT_ACTIVE,
        /// <summary>The Platform Manifest file was not properly signed.</summary>

        error_platform_manifest_not_signed = ERROR_PLATFORM_MANIFEST_NOT_SIGNED,
        /// <summary>The operation cannot be completed because other resources are dependent on this resource.</summary>

        error_dependent_resource_exists = ERROR_DEPENDENT_RESOURCE_EXISTS,
        /// <summary>The cluster resource dependency cannot be found.</summary>

        error_dependency_not_found = ERROR_DEPENDENCY_NOT_FOUND,
        /// <summary>The cluster resource cannot be made dependent on the specified resource because it is already dependent.</summary>

        error_dependency_already_exists = ERROR_DEPENDENCY_ALREADY_EXISTS,
        /// <summary>The cluster resource is not online.</summary>

        error_resource_not_online = ERROR_RESOURCE_NOT_ONLINE,
        /// <summary>A cluster node is not available for this operation.</summary>

        error_host_node_not_available = ERROR_HOST_NODE_NOT_AVAILABLE,
        /// <summary>The cluster resource is not available.</summary>

        error_resource_not_available = ERROR_RESOURCE_NOT_AVAILABLE,
        /// <summary>The cluster resource could not be found.</summary>

        error_resource_not_found = ERROR_RESOURCE_NOT_FOUND,
        /// <summary>The cluster is being shut down.</summary>

        error_shutdown_cluster = ERROR_SHUTDOWN_CLUSTER,
        /// <summary>A cluster node cannot be evicted from the cluster unless the node is down or it is the last node.</summary>

        error_cant_evict_active_node = ERROR_CANT_EVICT_ACTIVE_NODE,
        /// <summary>The object already exists.</summary>

        error_object_already_exists = ERROR_OBJECT_ALREADY_EXISTS,
        /// <summary>The object is already in the list.</summary>

        error_object_in_list = ERROR_OBJECT_IN_LIST,
        /// <summary>The cluster group is not available for any new requests.</summary>

        error_group_not_available = ERROR_GROUP_NOT_AVAILABLE,
        /// <summary>The cluster group could not be found.</summary>

        error_group_not_found = ERROR_GROUP_NOT_FOUND,
        /// <summary>The operation could not be completed because the cluster group is not online.</summary>

        error_group_not_online = ERROR_GROUP_NOT_ONLINE,
        /// <summary>The operation failed because either the specified cluster node is not the owner of the resource, or the node is not a possible owner of the resource.</summary>

        error_host_node_not_resource_owner = ERROR_HOST_NODE_NOT_RESOURCE_OWNER,
        /// <summary>The operation failed because either the specified cluster node is not the owner of the group, or the node is not a possible owner of the group.</summary>

        error_host_node_not_group_owner = ERROR_HOST_NODE_NOT_GROUP_OWNER,
        /// <summary>The cluster resource could not be created in the specified resource monitor.</summary>

        error_resmon_create_failed = ERROR_RESMON_CREATE_FAILED,
        /// <summary>The cluster resource could not be brought online by the resource monitor.</summary>

        error_resmon_online_failed = ERROR_RESMON_ONLINE_FAILED,
        /// <summary>The operation could not be completed because the cluster resource is online.</summary>

        error_resource_online = ERROR_RESOURCE_ONLINE,
        /// <summary>The cluster resource could not be deleted or brought offline because it is the quorum resource.</summary>

        error_quorum_resource = ERROR_QUORUM_RESOURCE,
        /// <summary>The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource.</summary>

        error_not_quorum_capable = ERROR_NOT_QUORUM_CAPABLE,
        /// <summary>The cluster software is shutting down.</summary>

        error_cluster_shutting_down = ERROR_CLUSTER_SHUTTING_DOWN,
        /// <summary>The group or resource is not in the correct state to perform the requested operation.</summary>

        error_invalid_state = ERROR_INVALID_STATE,
        /// <summary>The properties were stored but not all changes will take effect until the next time the resource is brought online.</summary>

        error_resource_properties_stored = ERROR_RESOURCE_PROPERTIES_STORED,
        /// <summary>The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class.</summary>

        error_not_quorum_class = ERROR_NOT_QUORUM_CLASS,
        /// <summary>The cluster resource could not be deleted since it is a core resource.</summary>

        error_core_resource = ERROR_CORE_RESOURCE,
        /// <summary>The quorum resource failed to come online.</summary>

        error_quorum_resource_online_failed = ERROR_QUORUM_RESOURCE_ONLINE_FAILED,
        /// <summary>The quorum log could not be created or mounted successfully.</summary>

        error_quorumlog_open_failed = ERROR_QUORUMLOG_OPEN_FAILED,
        /// <summary>The cluster log is corrupt.</summary>

        error_clusterlog_corrupt = ERROR_CLUSTERLOG_CORRUPT,
        /// <summary>The record could not be written to the cluster log since it exceeds the maximum size.</summary>

        error_clusterlog_record_exceeds_maxsize = ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE,
        /// <summary>The cluster log exceeds its maximum size.</summary>

        error_clusterlog_exceeds_maxsize = ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE,
        /// <summary>No checkpoint record was found in the cluster log.</summary>

        error_clusterlog_chkpoint_not_found = ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND,
        /// <summary>The minimum required disk space needed for logging is not available.</summary>

        error_clusterlog_not_enough_space = ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE,
        /// <summary>The cluster node failed to take control of the quorum resource because the resource is owned by another active node.</summary>

        error_quorum_owner_alive = ERROR_QUORUM_OWNER_ALIVE,
        /// <summary>A cluster network is not available for this operation.</summary>

        error_network_not_available = ERROR_NETWORK_NOT_AVAILABLE,
        /// <summary>A cluster node is not available for this operation.</summary>

        error_node_not_available = ERROR_NODE_NOT_AVAILABLE,
        /// <summary>All cluster nodes must be running to perform this operation.</summary>

        error_all_nodes_not_available = ERROR_ALL_NODES_NOT_AVAILABLE,
        /// <summary>A cluster resource failed.</summary>

        error_resource_failed = ERROR_RESOURCE_FAILED,
        /// <summary>The cluster node is not valid.</summary>

        error_cluster_invalid_node = ERROR_CLUSTER_INVALID_NODE,
        /// <summary>The cluster node already exists.</summary>

        error_cluster_node_exists = ERROR_CLUSTER_NODE_EXISTS,
        /// <summary>A node is in the process of joining the cluster.</summary>

        error_cluster_join_in_progress = ERROR_CLUSTER_JOIN_IN_PROGRESS,
        /// <summary>The cluster node was not found.</summary>

        error_cluster_node_not_found = ERROR_CLUSTER_NODE_NOT_FOUND,
        /// <summary>The cluster local node information was not found.</summary>

        error_cluster_local_node_not_found = ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND,
        /// <summary>The cluster network already exists.</summary>

        error_cluster_network_exists = ERROR_CLUSTER_NETWORK_EXISTS,
        /// <summary>The cluster network was not found.</summary>

        error_cluster_network_not_found = ERROR_CLUSTER_NETWORK_NOT_FOUND,
        /// <summary>The cluster network interface already exists.</summary>

        error_cluster_netinterface_exists = ERROR_CLUSTER_NETINTERFACE_EXISTS,
        /// <summary>The cluster network interface was not found.</summary>

        error_cluster_netinterface_not_found = ERROR_CLUSTER_NETINTERFACE_NOT_FOUND,
        /// <summary>The cluster request is not valid for this object.</summary>

        error_cluster_invalid_request = ERROR_CLUSTER_INVALID_REQUEST,
        /// <summary>The cluster network provider is not valid.</summary>

        error_cluster_invalid_network_provider = ERROR_CLUSTER_INVALID_NETWORK_PROVIDER,
        /// <summary>The cluster node is down.</summary>

        error_cluster_node_down = ERROR_CLUSTER_NODE_DOWN,
        /// <summary>The cluster node is not reachable.</summary>

        error_cluster_node_unreachable = ERROR_CLUSTER_NODE_UNREACHABLE,
        /// <summary>The cluster node is not a member of the cluster.</summary>

        error_cluster_node_not_member = ERROR_CLUSTER_NODE_NOT_MEMBER,
        /// <summary>A cluster join operation is not in progress.</summary>

        error_cluster_join_not_in_progress = ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS,
        /// <summary>The cluster network is not valid.</summary>

        error_cluster_invalid_network = ERROR_CLUSTER_INVALID_NETWORK,
        /// <summary>The cluster node is up.</summary>

        error_cluster_node_up = ERROR_CLUSTER_NODE_UP,
        /// <summary>The cluster IP address is already in use.</summary>

        error_cluster_ipaddr_in_use = ERROR_CLUSTER_IPADDR_IN_USE,
        /// <summary>The cluster node is not paused.</summary>

        error_cluster_node_not_paused = ERROR_CLUSTER_NODE_NOT_PAUSED,
        /// <summary>No cluster security context is available.</summary>

        error_cluster_no_security_context = ERROR_CLUSTER_NO_SECURITY_CONTEXT,
        /// <summary>The cluster network is not configured for internal cluster communication.</summary>

        error_cluster_network_not_internal = ERROR_CLUSTER_NETWORK_NOT_INTERNAL,
        /// <summary>The cluster node is already up.</summary>

        error_cluster_node_already_up = ERROR_CLUSTER_NODE_ALREADY_UP,
        /// <summary>The cluster node is already down.</summary>

        error_cluster_node_already_down = ERROR_CLUSTER_NODE_ALREADY_DOWN,
        /// <summary>The cluster network is already online.</summary>

        error_cluster_network_already_online = ERROR_CLUSTER_NETWORK_ALREADY_ONLINE,
        /// <summary>The cluster network is already offline.</summary>

        error_cluster_network_already_offline = ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE,
        /// <summary>The cluster node is already a member of the cluster.</summary>

        error_cluster_node_already_member = ERROR_CLUSTER_NODE_ALREADY_MEMBER,
        /// <summary>The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.</summary>

        error_cluster_last_internal_network = ERROR_CLUSTER_LAST_INTERNAL_NETWORK,
        /// <summary>One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.</summary>

        error_cluster_network_has_dependents = ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS,
        /// <summary>This operation cannot currently be performed on the cluster group containing the quorum resource.</summary>

        error_invalid_operation_on_quorum = ERROR_INVALID_OPERATION_ON_QUORUM,
        /// <summary>The cluster quorum resource is not allowed to have any dependencies.</summary>

        error_dependency_not_allowed = ERROR_DEPENDENCY_NOT_ALLOWED,
        /// <summary>The cluster node is paused.</summary>

        error_cluster_node_paused = ERROR_CLUSTER_NODE_PAUSED,
        /// <summary>The cluster resource cannot be brought online. The owner node cannot run this resource.</summary>

        error_node_cant_host_resource = ERROR_NODE_CANT_HOST_RESOURCE,
        /// <summary>The cluster node is not ready to perform the requested operation.</summary>

        error_cluster_node_not_ready = ERROR_CLUSTER_NODE_NOT_READY,
        /// <summary>The cluster node is shutting down.</summary>

        error_cluster_node_shutting_down = ERROR_CLUSTER_NODE_SHUTTING_DOWN,
        /// <summary>The cluster join operation was aborted.</summary>

        error_cluster_join_aborted = ERROR_CLUSTER_JOIN_ABORTED,
        /// <summary>The node failed to join the cluster because the joining node and other nodes in the cluster have incompatible operating system versions. To get more information about operating system versions of the cluster, run the Validate a Configuration Wizard or the Test-Cluster Windows PowerShell cmdlet.</summary>

        error_cluster_incompatible_versions = ERROR_CLUSTER_INCOMPATIBLE_VERSIONS,
        /// <summary>This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.</summary>

        error_cluster_maxnum_of_resources_exceeded = ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED,
        /// <summary>The system configuration changed during the cluster join or form operation. The join or form operation was aborted.</summary>

        error_cluster_system_config_changed = ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED,
        /// <summary>The specified resource type was not found.</summary>

        error_cluster_resource_type_not_found = ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND,
        /// <summary>The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.</summary>

        error_cluster_restype_not_supported = ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED,
        /// <summary>The specified resource name is not supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.</summary>

        error_cluster_resname_not_found = ERROR_CLUSTER_RESNAME_NOT_FOUND,
        /// <summary>No authentication package could be registered with the RPC server.</summary>

        error_cluster_no_rpc_packages_registered = ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED,
        /// <summary>You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.</summary>

        error_cluster_owner_not_in_preflist = ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST,
        /// <summary>The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.</summary>

        error_cluster_database_seqmismatch = ERROR_CLUSTER_DATABASE_SEQMISMATCH,
        /// <summary>The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.</summary>

        error_resmon_invalid_state = ERROR_RESMON_INVALID_STATE,
        /// <summary>A non locker code got a request to reserve the lock for making global updates.</summary>

        error_cluster_gum_not_locker = ERROR_CLUSTER_GUM_NOT_LOCKER,
        /// <summary>The quorum disk could not be located by the cluster service.</summary>

        error_quorum_disk_not_found = ERROR_QUORUM_DISK_NOT_FOUND,
        /// <summary>The backed up cluster database is possibly corrupt.</summary>

        error_database_backup_corrupt = ERROR_DATABASE_BACKUP_CORRUPT,
        /// <summary>A DFS root already exists in this cluster node.</summary>

        error_cluster_node_already_has_dfs_root = ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT,
        /// <summary>An attempt to modify a resource property failed because it conflicts with another existing property.</summary>

        error_resource_property_unchangeable = ERROR_RESOURCE_PROPERTY_UNCHANGEABLE,
        /// <summary>This operation is not supported on a cluster without an Administrator Access Point.</summary>

        error_no_admin_access_point = ERROR_NO_ADMIN_ACCESS_POINT,

        /*
         Codes from 4300 through 5889 overlap with codes in ds\published\inc\apperr2.w.
         Do not add any more error codes in that range.
        */

        /// <summary>An operation was attempted that is incompatible with the current membership state of the node.</summary>

        error_cluster_membership_invalid_state = ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE,
        /// <summary>The quorum resource does not contain the quorum log.</summary>

        error_cluster_quorumlog_not_found = ERROR_CLUSTER_QUORUMLOG_NOT_FOUND,
        /// <summary>The membership engine requested shutdown of the cluster service on this node.</summary>

        error_cluster_membership_halt = ERROR_CLUSTER_MEMBERSHIP_HALT,
        /// <summary>The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node.</summary>

        error_cluster_instance_id_mismatch = ERROR_CLUSTER_INSTANCE_ID_MISMATCH,
        /// <summary>A matching cluster network for the specified IP address could not be found.</summary>

        error_cluster_network_not_found_for_ip = ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP,
        /// <summary>The actual data type of the property did not match the expected data type of the property.</summary>

        error_cluster_property_data_type_mismatch = ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH,
        /// <summary>The cluster node was evicted from the cluster successfully, but the node was not cleaned up. To determine what cleanup steps failed and how to recover, see the Failover Clustering application event log using Event Viewer.</summary>

        error_cluster_evict_without_cleanup = ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP,
        /// <summary>Two or more parameter values specified for a resource's properties are in conflict.</summary>

        error_cluster_parameter_mismatch = ERROR_CLUSTER_PARAMETER_MISMATCH,
        /// <summary>This computer cannot be made a member of a cluster.</summary>

        error_node_cannot_be_clustered = ERROR_NODE_CANNOT_BE_CLUSTERED,
        /// <summary>This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed.</summary>

        error_cluster_wrong_os_version = ERROR_CLUSTER_WRONG_OS_VERSION,
        /// <summary>A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster.</summary>

        error_cluster_cant_create_dup_cluster_name = ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME,
        /// <summary>The cluster configuration action has already been committed.</summary>

        error_cluscfg_already_committed = ERROR_CLUSCFG_ALREADY_COMMITTED,
        /// <summary>The cluster configuration action could not be rolled back.</summary>

        error_cluscfg_rollback_failed = ERROR_CLUSCFG_ROLLBACK_FAILED,
        /// <summary>The drive letter assigned to a system disk on one node conflicted with the drive letter assigned to a disk on another node.</summary>

        error_cluscfg_system_disk_drive_letter_conflict = ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT,
        /// <summary>One or more nodes in the cluster are running a version of Windows that does not support this operation.</summary>

        error_cluster_old_version = ERROR_CLUSTER_OLD_VERSION,
        /// <summary>The name of the corresponding computer account doesn't match the Network Name for this resource.</summary>

        error_cluster_mismatched_computer_acct_name = ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME,
        /// <summary>No network adapters are available.</summary>

        error_cluster_no_net_adapters = ERROR_CLUSTER_NO_NET_ADAPTERS,
        /// <summary>The cluster node has been poisoned.</summary>

        error_cluster_poisoned = ERROR_CLUSTER_POISONED,
        /// <summary>The group is unable to accept the request since it is moving to another node.</summary>

        error_cluster_group_moving = ERROR_CLUSTER_GROUP_MOVING,
        /// <summary>The resource type cannot accept the request since is too busy performing another operation.</summary>

        error_cluster_resource_type_busy = ERROR_CLUSTER_RESOURCE_TYPE_BUSY,
        /// <summary>The call to the cluster resource DLL timed out.</summary>

        error_resource_call_timed_out = ERROR_RESOURCE_CALL_TIMED_OUT,
        /// <summary>The address is not valid for an IPv6 Address resource. A global IPv6 address is required, and it must match a cluster network. Compatibility addresses are not permitted.</summary>

        error_invalid_cluster_ipv6_address = ERROR_INVALID_CLUSTER_IPV6_ADDRESS,
        /// <summary>An internal cluster error occurred. A call to an invalid function was attempted.</summary>

        error_cluster_internal_invalid_function = ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION,
        /// <summary>A parameter value is out of acceptable range.</summary>

        error_cluster_parameter_out_of_bounds = ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS,
        /// <summary>A network error occurred while sending data to another node in the cluster. The number of bytes transmitted was less than required.</summary>

        error_cluster_partial_send = ERROR_CLUSTER_PARTIAL_SEND,
        /// <summary>An invalid cluster registry operation was attempted.</summary>

        error_cluster_registry_invalid_function = ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION,
        /// <summary>An input string of characters is not properly terminated.</summary>

        error_cluster_invalid_string_termination = ERROR_CLUSTER_INVALID_STRING_TERMINATION,
        /// <summary>An input string of characters is not in a valid format for the data it represents.</summary>

        error_cluster_invalid_string_format = ERROR_CLUSTER_INVALID_STRING_FORMAT,
        /// <summary>An internal cluster error occurred. A cluster database transaction was attempted while a transaction was already in progress.</summary>

        error_cluster_database_transaction_in_progress = ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS,
        /// <summary>An internal cluster error occurred. There was an attempt to commit a cluster database transaction while no transaction was in progress.</summary>

        error_cluster_database_transaction_not_in_progress = ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS,
        /// <summary>An internal cluster error occurred. Data was not properly initialized.</summary>

        error_cluster_null_data = ERROR_CLUSTER_NULL_DATA,
        /// <summary>An error occurred while reading from a stream of data. An unexpected number of bytes was returned.</summary>

        error_cluster_partial_read = ERROR_CLUSTER_PARTIAL_READ,
        /// <summary>An error occurred while writing to a stream of data. The required number of bytes could not be written.</summary>

        error_cluster_partial_write = ERROR_CLUSTER_PARTIAL_WRITE,
        /// <summary>An error occurred while deserializing a stream of cluster data.</summary>

        error_cluster_cant_deserialize_data = ERROR_CLUSTER_CANT_DESERIALIZE_DATA,
        /// <summary>One or more property values for this resource are in conflict with one or more property values associated with its dependent resource(s).</summary>

        error_dependent_resource_property_conflict = ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT,
        /// <summary>A quorum of cluster nodes was not present to form a cluster.</summary>

        error_cluster_no_quorum = ERROR_CLUSTER_NO_QUORUM,
        /// <summary>The cluster network is not valid for an IPv6 Address resource, or it does not match the configured address.</summary>

        error_cluster_invalid_ipv6_network = ERROR_CLUSTER_INVALID_IPV6_NETWORK,
        /// <summary>The cluster network is not valid for an IPv6 Tunnel resource. Check the configuration of the IP Address resource on which the IPv6 Tunnel resource depends.</summary>

        error_cluster_invalid_ipv6_tunnel_network = ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK,
        /// <summary>Quorum resource cannot reside in the Available Storage group.</summary>

        error_quorum_not_allowed_in_this_group = ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP,
        /// <summary>The dependencies for this resource are nested too deeply.</summary>

        error_dependency_tree_too_complex = ERROR_DEPENDENCY_TREE_TOO_COMPLEX,
        /// <summary>The call into the resource DLL raised an unhandled exception.</summary>

        error_exception_in_resource_call = ERROR_EXCEPTION_IN_RESOURCE_CALL,
        /// <summary>The RHS process failed to initialize.</summary>

        error_cluster_rhs_failed_initialization = ERROR_CLUSTER_RHS_FAILED_INITIALIZATION,
        /// <summary>The Failover Clustering feature is not installed on this node.</summary>

        error_cluster_not_installed = ERROR_CLUSTER_NOT_INSTALLED,
        /// <summary>The resources must be online on the same node for this operation</summary>

        error_cluster_resources_must_be_online_on_the_same_node = ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE,
        /// <summary>A new node can not be added since this cluster is already at its maximum number of nodes.</summary>

        error_cluster_max_nodes_in_cluster = ERROR_CLUSTER_MAX_NODES_IN_CLUSTER,
        /// <summary>This cluster can not be created since the specified number of nodes exceeds the maximum allowed limit.</summary>

        error_cluster_too_many_nodes = ERROR_CLUSTER_TOO_MANY_NODES,
        /// <summary>An attempt to use the specified cluster name failed because an enabled computer object with the given name already exists in the domain.</summary>

        error_cluster_object_already_used = ERROR_CLUSTER_OBJECT_ALREADY_USED,
        /// <summary>This cluster cannot be destroyed. It has non-core application groups which must be deleted before the cluster can be destroyed.</summary>

        error_noncore_groups_found = ERROR_NONCORE_GROUPS_FOUND,
        /// <summary>File share associated with file share witness resource cannot be hosted by this cluster or any of its nodes.</summary>

        error_file_share_resource_conflict = ERROR_FILE_SHARE_RESOURCE_CONFLICT,
        /// <summary>Eviction of this node is invalid at this time. Due to quorum requirements node eviction will result in cluster shutdown.</summary>
        /// <summary>If it is the last node in the cluster, destroy cluster command should be used.</summary>

        error_cluster_evict_invalid_request = ERROR_CLUSTER_EVICT_INVALID_REQUEST,
        /// <summary>Only one instance of this resource type is allowed in the cluster.</summary>

        error_cluster_singleton_resource = ERROR_CLUSTER_SINGLETON_RESOURCE,
        /// <summary>Only one instance of this resource type is allowed per resource group.</summary>

        error_cluster_group_singleton_resource = ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE,
        /// <summary>The resource failed to come online due to the failure of one or more provider resources.</summary>

        error_cluster_resource_provider_failed = ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED,
        /// <summary>The resource has indicated that it cannot come online on any node.</summary>

        error_cluster_resource_configuration_error = ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR,
        /// <summary>The current operation cannot be performed on this group at this time.</summary>

        error_cluster_group_busy = ERROR_CLUSTER_GROUP_BUSY,
        /// <summary>The directory or file is not located on a cluster shared volume.</summary>

        error_cluster_not_shared_volume = ERROR_CLUSTER_NOT_SHARED_VOLUME,
        /// <summary>The Security Descriptor does not meet the requirements for a cluster.</summary>

        error_cluster_invalid_security_descriptor = ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR,
        /// <summary>There is one or more shared volumes resources configured in the cluster.</summary>
        /// <summary>Those resources must be moved to available storage in order for operation to succeed.</summary>

        error_cluster_shared_volumes_in_use = ERROR_CLUSTER_SHARED_VOLUMES_IN_USE,
        /// <summary>This group or resource cannot be directly manipulated.</summary>
        /// <summary>Use shared volume APIs to perform desired operation.</summary>

        error_cluster_use_shared_volumes_api = ERROR_CLUSTER_USE_SHARED_VOLUMES_API,
        /// <summary>Back up is in progress. Please wait for backup completion before trying this operation again.</summary>

        error_cluster_backup_in_progress = ERROR_CLUSTER_BACKUP_IN_PROGRESS,
        /// <summary>The path does not belong to a cluster shared volume.</summary>

        error_non_csv_path = ERROR_NON_CSV_PATH,
        /// <summary>The cluster shared volume is not locally mounted on this node.</summary>

        error_csv_volume_not_local = ERROR_CSV_VOLUME_NOT_LOCAL,
        /// <summary>The cluster watchdog is terminating.</summary>

        error_cluster_watchdog_terminating = ERROR_CLUSTER_WATCHDOG_TERMINATING,
        /// <summary>A resource vetoed a move between two nodes because they are incompatible.</summary>

        error_cluster_resource_vetoed_move_incompatible_nodes = ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES,
        /// <summary>The request is invalid either because node weight cannot be changed while the cluster is in disk-only quorum mode, or because changing the node weight would violate the minimum cluster quorum requirements.</summary>

        error_cluster_invalid_node_weight = ERROR_CLUSTER_INVALID_NODE_WEIGHT,
        /// <summary>The resource vetoed the call.</summary>

        error_cluster_resource_vetoed_call = ERROR_CLUSTER_RESOURCE_VETOED_CALL,
        /// <summary>Resource could not start or run because it could not reserve sufficient system resources.</summary>

        error_resmon_system_resources_lacking = ERROR_RESMON_SYSTEM_RESOURCES_LACKING,
        /// <summary>A resource vetoed a move between two nodes because the destination currently does not have enough resources to complete the operation.</summary>

        error_cluster_resource_vetoed_move_not_enough_resources_on_destination = ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION,

        /// <summary>A resource vetoed a move between two nodes because the source currently does not have enough resources to complete the operation.</summary>

        error_cluster_resource_vetoed_move_not_enough_resources_on_source = ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE,

        /// <summary>The requested operation can not be completed because the group is queued for an operation.</summary>

        error_cluster_group_queued = ERROR_CLUSTER_GROUP_QUEUED,

        /// <summary>The requested operation can not be completed because a resource has locked status.</summary>

        error_cluster_resource_locked_status = ERROR_CLUSTER_RESOURCE_LOCKED_STATUS,

        /// <summary>The resource cannot move to another node because a cluster shared volume vetoed the operation.</summary>

        error_cluster_shared_volume_failover_not_allowed = ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED,

        /// <summary>A node drain is already in progress.</summary>

        error_cluster_node_drain_in_progress = ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS,

        /// <summary>Clustered storage is not connected to the node.</summary>

        error_cluster_disk_not_connected = ERROR_CLUSTER_DISK_NOT_CONNECTED,

        /// <summary>The disk is not configured in a way to be used with CSV. CSV disks must have at least one partition that is formatted with NTFS or REFS.</summary>

        error_disk_not_csv_capable = ERROR_DISK_NOT_CSV_CAPABLE,

        /// <summary>The resource must be part of the Available Storage group to complete this action.</summary>

        error_resource_not_in_available_storage = ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE,

        /// <summary>CSVFS failed operation as volume is in redirected mode.</summary>

        error_cluster_shared_volume_redirected = ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED,

        /// <summary>CSVFS failed operation as volume is not in redirected mode.</summary>

        error_cluster_shared_volume_not_redirected = ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED,

        /// <summary>Cluster properties cannot be returned at this time.</summary>

        error_cluster_cannot_return_properties = ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES,

        /// <summary>The clustered disk resource contains software snapshot diff area that are not supported for Cluster Shared Volumes.</summary>

        error_cluster_resource_contains_unsupported_diff_area_for_shared_volumes = ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES,

        /// <summary>The operation cannot be completed because the resource is in maintenance mode.</summary>

        error_cluster_resource_is_in_maintenance_mode = ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE,

        /// <summary>The operation cannot be completed because of cluster affinity conflicts</summary>

        error_cluster_affinity_conflict = ERROR_CLUSTER_AFFINITY_CONFLICT,

        /// <summary>The operation cannot be completed because the resource is a replica virtual machine.</summary>

        error_cluster_resource_is_replica_virtual_machine = ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE,
        /// <summary>The Cluster Functional Level could not be increased because not all nodes in the cluster support the updated version.</summary>

        error_cluster_upgrade_incompatible_versions = ERROR_CLUSTER_UPGRADE_INCOMPATIBLE_VERSIONS,

        /// <summary>
        /// Updating the cluster functional level failed because the cluster is running in fix quorum mode. 
        /// Start additional nodes which are members of the cluster until the cluster reaches quorum and the cluster will automatically
        /// switch out of fix quorum mode, or stop and restart the cluster without the FixQuorum switch. Once the cluster is out
        /// of fix quorum mode retry the Update-ClusterFunctionalLevel PowerShell cmdlet to update the cluster functional level.
        /// </summary>
        error_cluster_upgrade_fix_quorum_not_supported = ERROR_CLUSTER_UPGRADE_FIX_QUORUM_NOT_SUPPORTED,

        /// <summary>
        /// The cluster functional level has been successfully updated but not all features are available yet. Restart the cluster by
        /// using the Stop-Cluster PowerShell cmdlet followed by the Start-Cluster PowerShell cmdlet and all cluster features will 
        /// be available. 
        /// </summary>
        error_cluster_upgrade_restart_required = ERROR_CLUSTER_UPGRADE_RESTART_REQUIRED,
        /// <summary>The cluster is currently performing a version upgrade.</summary>

        error_cluster_upgrade_in_progress = ERROR_CLUSTER_UPGRADE_IN_PROGRESS,
        /// <summary>The cluster did not successfully complete the version upgrade.</summary>

        error_cluster_upgrade_incomplete = ERROR_CLUSTER_UPGRADE_INCOMPLETE,
        /// <summary>The cluster node is in grace period.</summary>

        error_cluster_node_in_grace_period = ERROR_CLUSTER_NODE_IN_GRACE_PERIOD,

        /// <summary>The operation has failed because CSV volume was not able to recover in time specified on this file object.</summary>

        error_cluster_csv_io_pause_timeout = ERROR_CLUSTER_CSV_IO_PAUSE_TIMEOUT,

        /// <summary>The operation failed because the requested node is not currently part of active cluster membership.</summary>

        error_node_not_active_cluster_member = ERROR_NODE_NOT_ACTIVE_CLUSTER_MEMBER,

        /// <summary>The operation failed because the requested cluster resource is currently unmonitored.</summary>

        error_cluster_resource_not_monitored = ERROR_CLUSTER_RESOURCE_NOT_MONITORED,

        /// <summary>The operation failed because a resource does not support running in an unmonitored state.</summary>

        error_cluster_resource_does_not_support_unmonitored = ERROR_CLUSTER_RESOURCE_DOES_NOT_SUPPORT_UNMONITORED,

        /// <summary>The operation cannot be completed because a resource participates in replication.</summary>

        error_cluster_resource_is_replicated = ERROR_CLUSTER_RESOURCE_IS_REPLICATED,

        /// <summary>The operation failed because the requested cluster node has been isolated</summary>

        error_cluster_node_isolated = ERROR_CLUSTER_NODE_ISOLATED,

        /// <summary>The operation failed because the requested cluster node has been quarantined</summary>

        error_cluster_node_quarantined = ERROR_CLUSTER_NODE_QUARANTINED,

        /// <summary>The operation failed because the specified database update condition was not met</summary>

        error_cluster_database_update_condition_failed = ERROR_CLUSTER_DATABASE_UPDATE_CONDITION_FAILED,

        /// <summary>A clustered space is in a degraded condition and the requested action cannot be completed at this time.</summary>

        error_cluster_space_degraded = ERROR_CLUSTER_SPACE_DEGRADED,

        /// <summary>The operation failed because token delegation for this control is not supported.</summary>

        error_cluster_token_delegation_not_supported = ERROR_CLUSTER_TOKEN_DELEGATION_NOT_SUPPORTED,

        /// <summary>The operation has failed because CSV has invalidated this file object.</summary>

        error_cluster_csv_invalid_handle = ERROR_CLUSTER_CSV_INVALID_HANDLE,

        /// <summary>This operation is supported only on the CSV coordinator node.</summary>

        error_cluster_csv_supported_only_on_coordinator = ERROR_CLUSTER_CSV_SUPPORTED_ONLY_ON_COORDINATOR,

        /// <summary>The cluster group set is not available for any further requests.</summary>

        error_groupset_not_available = ERROR_GROUPSET_NOT_AVAILABLE,

        /// <summary>The cluster group set could not be found.</summary>

        error_groupset_not_found = ERROR_GROUPSET_NOT_FOUND,

        /// <summary>The action cannot be completed at this time because the cluster group set would fall below quorum and not be able to act as a provider.</summary>

        error_groupset_cant_provide = ERROR_GROUPSET_CANT_PROVIDE,

        /// <summary>The specified parent fault domain is not found.</summary>

        error_cluster_fault_domain_parent_not_found = ERROR_CLUSTER_FAULT_DOMAIN_PARENT_NOT_FOUND,

        /// <summary>The fault domain cannot be a child of the parent specified.</summary>

        error_cluster_fault_domain_invalid_hierarchy = ERROR_CLUSTER_FAULT_DOMAIN_INVALID_HIERARCHY,

        /// <summary>Storage Spaces Direct has rejected the proposed fault domain changes because it impacts the fault tolerance of the storage.</summary>

        error_cluster_fault_domain_failed_s2d_validation = ERROR_CLUSTER_FAULT_DOMAIN_FAILED_S2D_VALIDATION,

        /// <summary>Storage Spaces Direct has rejected the proposed fault domain changes because it reduces the storage connected to the system.</summary>

        error_cluster_fault_domain_s2d_connectivity_loss = ERROR_CLUSTER_FAULT_DOMAIN_S2D_CONNECTIVITY_LOSS,

        /// <summary>Cluster infrastructure file server creation failed because a valid non-empty file server name was not provided.</summary>

        error_cluster_invalid_infrastructure_fileserver_name = ERROR_CLUSTER_INVALID_INFRASTRUCTURE_FILESERVER_NAME,

        /// <summary>The action cannot be completed because the cluster set management cluster is unreachable.</summary>

        error_clusterset_management_cluster_unreachable = ERROR_CLUSTERSET_MANAGEMENT_CLUSTER_UNREACHABLE,

        /// <summary>The specified file could not be encrypted.</summary>

        error_encryption_failed = ERROR_ENCRYPTION_FAILED,
        /// <summary>The specified file could not be decrypted.</summary>

        error_decryption_failed = ERROR_DECRYPTION_FAILED,
        /// <summary>The specified file is encrypted and the user does not have the ability to decrypt it.</summary>

        error_file_encrypted = ERROR_FILE_ENCRYPTED,
        /// <summary>There is no valid encryption recovery policy configured for this system.</summary>

        error_no_recovery_policy = ERROR_NO_RECOVERY_POLICY,
        /// <summary>The required encryption driver is not loaded for this system.</summary>

        error_no_efs = ERROR_NO_EFS,
        /// <summary>The file was encrypted with a different encryption driver than is currently loaded.</summary>

        error_wrong_efs = ERROR_WRONG_EFS,
        /// <summary>There are no EFS keys defined for the user.</summary>

        error_no_user_keys = ERROR_NO_USER_KEYS,
        /// <summary>The specified file is not encrypted.</summary>

        error_file_not_encrypted = ERROR_FILE_NOT_ENCRYPTED,
        /// <summary>The specified file is not in the defined EFS export format.</summary>

        error_not_export_format = ERROR_NOT_EXPORT_FORMAT,
        /// <summary>The specified file is read only.</summary>

        error_file_read_only = ERROR_FILE_READ_ONLY,
        /// <summary>The directory has been disabled for encryption.</summary>

        error_dir_efs_disallowed = ERROR_DIR_EFS_DISALLOWED,
        /// <summary>The server is not trusted for remote encryption operation.</summary>

        error_efs_server_not_trusted = ERROR_EFS_SERVER_NOT_TRUSTED,
        /// <summary>Recovery policy configured for this system contains invalid recovery certificate.</summary>

        error_bad_recovery_policy = ERROR_BAD_RECOVERY_POLICY,
        /// <summary>The encryption algorithm used on the source file needs a bigger key buffer than the one on the destination file.</summary>

        error_efs_alg_blob_too_big = ERROR_EFS_ALG_BLOB_TOO_BIG,
        /// <summary>The disk partition does not support file encryption.</summary>

        error_volume_not_support_efs = ERROR_VOLUME_NOT_SUPPORT_EFS,
        /// <summary>This machine is disabled for file encryption.</summary>

        error_efs_disabled = ERROR_EFS_DISABLED,
        /// <summary>A newer system is required to decrypt this encrypted file.</summary>

        error_efs_version_not_support = ERROR_EFS_VERSION_NOT_SUPPORT,
        /// <summary>The remote server sent an invalid response for a file being opened with Client Side Encryption.</summary>

        error_cs_encryption_invalid_server_response = ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE,
        /// <summary>Client Side Encryption is not supported by the remote server even though it claims to support it.</summary>

        error_cs_encryption_unsupported_server = ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER,
        /// <summary>File is encrypted and should be opened in Client Side Encryption mode.</summary>

        error_cs_encryption_existing_encrypted_file = ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE,
        /// <summary>A new encrypted file is being created and a $EFS needs to be provided.</summary>

        error_cs_encryption_new_encrypted_file = ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE,
        /// <summary>The SMB client requested a CSE FSCTL on a non-CSE file.</summary>

        error_cs_encryption_file_not_cse = ERROR_CS_ENCRYPTION_FILE_NOT_CSE,
        /// <summary>The requested operation was blocked by policy. For more information, contact your system administrator.</summary>

        error_encryption_policy_denies_operation = ERROR_ENCRYPTION_POLICY_DENIES_OPERATION,
        /// <summary>The specified file could not be encrypted with Windows Information Protection.</summary>

        error_wip_encryption_failed = ERROR_WIP_ENCRYPTION_FAILED,
        /// <summary>The list of servers for this workgroup is not currently available</summary>

        error_no_browser_servers_found = ERROR_NO_BROWSER_SERVERS_FOUND,

        /// <summary>The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts.</summary>

        sched_e_service_not_localsystem = SCHED_E_SERVICE_NOT_LOCALSYSTEM,
        /// <summary>Log service encountered an invalid log sector.</summary>

        error_log_sector_invalid = ERROR_LOG_SECTOR_INVALID,
        /// <summary>Log service encountered a log sector with invalid block parity.</summary>

        error_log_sector_parity_invalid = ERROR_LOG_SECTOR_PARITY_INVALID,
        /// <summary>Log service encountered a remapped log sector.</summary>

        error_log_sector_remapped = ERROR_LOG_SECTOR_REMAPPED,
        /// <summary>Log service encountered a partial or incomplete log block.</summary>

        error_log_block_incomplete = ERROR_LOG_BLOCK_INCOMPLETE,
        /// <summary>Log service encountered an attempt access data outside the active log range.</summary>

        error_log_invalid_range = ERROR_LOG_INVALID_RANGE,
        /// <summary>Log service user marshalling buffers are exhausted.</summary>

        error_log_blocks_exhausted = ERROR_LOG_BLOCKS_EXHAUSTED,
        /// <summary>Log service encountered an attempt read from a marshalling area with an invalid read context.</summary>

        error_log_read_context_invalid = ERROR_LOG_READ_CONTEXT_INVALID,
        /// <summary>Log service encountered an invalid log restart area.</summary>

        error_log_restart_invalid = ERROR_LOG_RESTART_INVALID,
        /// <summary>Log service encountered an invalid log block version.</summary>

        error_log_block_version = ERROR_LOG_BLOCK_VERSION,
        /// <summary>Log service encountered an invalid log block.</summary>

        error_log_block_invalid = ERROR_LOG_BLOCK_INVALID,
        /// <summary>Log service encountered an attempt to read the log with an invalid read mode.</summary>

        error_log_read_mode_invalid = ERROR_LOG_READ_MODE_INVALID,
        /// <summary>Log service encountered a log stream with no restart area.</summary>

        error_log_no_restart = ERROR_LOG_NO_RESTART,
        /// <summary>Log service encountered a corrupted metadata file.</summary>

        error_log_metadata_corrupt = ERROR_LOG_METADATA_CORRUPT,
        /// <summary>Log service encountered a metadata file that could not be created by the log file system.</summary>

        error_log_metadata_invalid = ERROR_LOG_METADATA_INVALID,
        /// <summary>Log service encountered a metadata file with inconsistent data.</summary>

        error_log_metadata_inconsistent = ERROR_LOG_METADATA_INCONSISTENT,
        /// <summary>Log service encountered an attempt to erroneous allocate or dispose reservation space.</summary>

        error_log_reservation_invalid = ERROR_LOG_RESERVATION_INVALID,
        /// <summary>Log service cannot delete log file or file system container.</summary>

        error_log_cant_delete = ERROR_LOG_CANT_DELETE,
        /// <summary>Log service has reached the maximum allowable containers allocated to a log file.</summary>

        error_log_container_limit_exceeded = ERROR_LOG_CONTAINER_LIMIT_EXCEEDED,
        /// <summary>Log service has attempted to read or write backward past the start of the log.</summary>

        error_log_start_of_log = ERROR_LOG_START_OF_LOG,
        /// <summary>Log policy could not be installed because a policy of the same type is already present.</summary>

        error_log_policy_already_installed = ERROR_LOG_POLICY_ALREADY_INSTALLED,
        /// <summary>Log policy in question was not installed at the time of the request.</summary>

        error_log_policy_not_installed = ERROR_LOG_POLICY_NOT_INSTALLED,
        /// <summary>The installed set of policies on the log is invalid.</summary>

        error_log_policy_invalid = ERROR_LOG_POLICY_INVALID,
        /// <summary>A policy on the log in question prevented the operation from completing.</summary>

        error_log_policy_conflict = ERROR_LOG_POLICY_CONFLICT,
        /// <summary>Log space cannot be reclaimed because the log is pinned by the archive tail.</summary>

        error_log_pinned_archive_tail = ERROR_LOG_PINNED_ARCHIVE_TAIL,
        /// <summary>Log record is not a record in the log file.</summary>

        error_log_record_nonexistent = ERROR_LOG_RECORD_NONEXISTENT,
        /// <summary>Number of reserved log records or the adjustment of the number of reserved log records is invalid.</summary>

        error_log_records_reserved_invalid = ERROR_LOG_RECORDS_RESERVED_INVALID,
        /// <summary>Reserved log space or the adjustment of the log space is invalid.</summary>

        error_log_space_reserved_invalid = ERROR_LOG_SPACE_RESERVED_INVALID,
        /// <summary>An new or existing archive tail or base of the active log is invalid.</summary>

        error_log_tail_invalid = ERROR_LOG_TAIL_INVALID,
        /// <summary>Log space is exhausted.</summary>

        error_log_full = ERROR_LOG_FULL,
        /// <summary>The log could not be set to the requested size.</summary>

        error_could_not_resize_log = ERROR_COULD_NOT_RESIZE_LOG,
        /// <summary>Log is multiplexed, no direct writes to the physical log is allowed.</summary>

        error_log_multiplexed = ERROR_LOG_MULTIPLEXED,
        /// <summary>The operation failed because the log is a dedicated log.</summary>

        error_log_dedicated = ERROR_LOG_DEDICATED,
        /// <summary>The operation requires an archive context.</summary>

        error_log_archive_not_in_progress = ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS,
        /// <summary>Log archival is in progress.</summary>

        error_log_archive_in_progress = ERROR_LOG_ARCHIVE_IN_PROGRESS,
        /// <summary>The operation requires a non-ephemeral log, but the log is ephemeral.</summary>

        error_log_ephemeral = ERROR_LOG_EPHEMERAL,
        /// <summary>The log must have at least two containers before it can be read from or written to.</summary>

        error_log_not_enough_containers = ERROR_LOG_NOT_ENOUGH_CONTAINERS,
        /// <summary>A log client has already registered on the stream.</summary>

        error_log_client_already_registered = ERROR_LOG_CLIENT_ALREADY_REGISTERED,
        /// <summary>A log client has not been registered on the stream.</summary>

        error_log_client_not_registered = ERROR_LOG_CLIENT_NOT_REGISTERED,
        /// <summary>A request has already been made to handle the log full condition.</summary>

        error_log_full_handler_in_progress = ERROR_LOG_FULL_HANDLER_IN_PROGRESS,
        /// <summary>Log service encountered an error when attempting to read from a log container.</summary>

        error_log_container_read_failed = ERROR_LOG_CONTAINER_READ_FAILED,
        /// <summary>Log service encountered an error when attempting to write to a log container.</summary>

        error_log_container_write_failed = ERROR_LOG_CONTAINER_WRITE_FAILED,
        /// <summary>Log service encountered an error when attempting open a log container.</summary>

        error_log_container_open_failed = ERROR_LOG_CONTAINER_OPEN_FAILED,
        /// <summary>Log service encountered an invalid container state when attempting a requested action.</summary>

        error_log_container_state_invalid = ERROR_LOG_CONTAINER_STATE_INVALID,
        /// <summary>Log service is not in the correct state to perform a requested action.</summary>

        error_log_state_invalid = ERROR_LOG_STATE_INVALID,
        /// <summary>Log space cannot be reclaimed because the log is pinned.</summary>

        error_log_pinned = ERROR_LOG_PINNED,
        /// <summary>Log metadata flush failed.</summary>

        error_log_metadata_flush_failed = ERROR_LOG_METADATA_FLUSH_FAILED,
        /// <summary>Security on the log and its containers is inconsistent.</summary>

        error_log_inconsistent_security = ERROR_LOG_INCONSISTENT_SECURITY,
        /// <summary>Records were appended to the log or reservation changes were made, but the log could not be flushed.</summary>

        error_log_appended_flush_failed = ERROR_LOG_APPENDED_FLUSH_FAILED,
        /// <summary>The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available.</summary>

        error_log_pinned_reservation = ERROR_LOG_PINNED_RESERVATION,
        /// <summary>The transaction handle associated with this operation is not valid.</summary>

        error_invalid_transaction = ERROR_INVALID_TRANSACTION,
        /// <summary>The requested operation was made in the context of a transaction that is no longer active.</summary>

        error_transaction_not_active = ERROR_TRANSACTION_NOT_ACTIVE,
        /// <summary>The requested operation is not valid on the Transaction object in its current state.</summary>

        error_transaction_request_not_valid = ERROR_TRANSACTION_REQUEST_NOT_VALID,
        /// <summary>The caller has called a response API, but the response is not expected because the TM did not issue the corresponding request to the caller.</summary>

        error_transaction_not_requested = ERROR_TRANSACTION_NOT_REQUESTED,
        /// <summary>It is too late to perform the requested operation, since the Transaction has already been aborted.</summary>

        error_transaction_already_aborted = ERROR_TRANSACTION_ALREADY_ABORTED,
        /// <summary>It is too late to perform the requested operation, since the Transaction has already been committed.</summary>

        error_transaction_already_committed = ERROR_TRANSACTION_ALREADY_COMMITTED,
        /// <summary>The Transaction Manager was unable to be successfully initialized. Transacted operations are not supported.</summary>

        error_tm_initialization_failed = ERROR_TM_INITIALIZATION_FAILED,
        /// <summary>The specified ResourceManager made no changes or updates to the resource under this transaction.</summary>

        error_resourcemanager_read_only = ERROR_RESOURCEMANAGER_READ_ONLY,
        /// <summary>The resource manager has attempted to prepare a transaction that it has not successfully joined.</summary>

        error_transaction_not_joined = ERROR_TRANSACTION_NOT_JOINED,
        /// <summary>The Transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allow.</summary>

        error_transaction_superior_exists = ERROR_TRANSACTION_SUPERIOR_EXISTS,
        /// <summary>The RM tried to register a protocol that already exists.</summary>

        error_crm_protocol_already_exists = ERROR_CRM_PROTOCOL_ALREADY_EXISTS,
        /// <summary>The attempt to propagate the Transaction failed.</summary>

        error_transaction_propagation_failed = ERROR_TRANSACTION_PROPAGATION_FAILED,
        /// <summary>The requested propagation protocol was not registered as a CRM.</summary>

        error_crm_protocol_not_found = ERROR_CRM_PROTOCOL_NOT_FOUND,
        /// <summary>The buffer passed in to PushTransaction or PullTransaction is not in a valid format.</summary>

        error_transaction_invalid_marshall_buffer = ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER,
        /// <summary>The current transaction context associated with the thread is not a valid handle to a transaction object.</summary>

        error_current_transaction_not_valid = ERROR_CURRENT_TRANSACTION_NOT_VALID,
        /// <summary>The specified Transaction object could not be opened, because it was not found.</summary>

        error_transaction_not_found = ERROR_TRANSACTION_NOT_FOUND,
        /// <summary>The specified ResourceManager object could not be opened, because it was not found.</summary>

        error_resourcemanager_not_found = ERROR_RESOURCEMANAGER_NOT_FOUND,
        /// <summary>The specified Enlistment object could not be opened, because it was not found.</summary>

        error_enlistment_not_found = ERROR_ENLISTMENT_NOT_FOUND,
        /// <summary>The specified TransactionManager object could not be opened, because it was not found.</summary>

        error_transactionmanager_not_found = ERROR_TRANSACTIONMANAGER_NOT_FOUND,
        /// <summary>The object specified could not be created or opened, because its associated TransactionManager is not online.  The TransactionManager must be brought fully Online by calling RecoverTransactionManager to recover to the end of its LogFile before objects in its Transaction or ResourceManager namespaces can be opened.  In addition, errors in writing records to its LogFile can cause a TransactionManager to go offline.</summary>

        error_transactionmanager_not_online = ERROR_TRANSACTIONMANAGER_NOT_ONLINE,
        /// <summary>The specified TransactionManager was unable to create the objects contained in its logfile in the Ob namespace. Therefore, the TransactionManager was unable to recover.</summary>

        error_transactionmanager_recovery_name_collision = ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION,
        /// <summary>The call to create a superior Enlistment on this Transaction object could not be completed, because the Transaction object specified for the enlistment is a subordinate branch of the Transaction. Only the root of the Transaction can be enlisted on as a superior.</summary>

        error_transaction_not_root = ERROR_TRANSACTION_NOT_ROOT,
        /// <summary>Because the associated transaction manager or resource manager has been closed, the handle is no longer valid.</summary>

        error_transaction_object_expired = ERROR_TRANSACTION_OBJECT_EXPIRED,
        /// <summary>The specified operation could not be performed on this Superior enlistment, because the enlistment was not created with the corresponding completion response in the NotificationMask.</summary>

        error_transaction_response_not_enlisted = ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED,
        /// <summary>The specified operation could not be performed, because the record that would be logged was too long. This can occur because of two conditions: either there are too many Enlistments on this Transaction, or the combined RecoveryInformation being logged on behalf of those Enlistments is too long.</summary>

        error_transaction_record_too_long = ERROR_TRANSACTION_RECORD_TOO_LONG,
        /// <summary>Implicit transaction are not supported.</summary>

        error_implicit_transaction_not_supported = ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED,
        /// <summary>The kernel transaction manager had to abort or forget the transaction because it blocked forward progress.</summary>

        error_transaction_integrity_violated = ERROR_TRANSACTION_INTEGRITY_VIOLATED,
        /// <summary>The TransactionManager identity that was supplied did not match the one recorded in the TransactionManager's log file.</summary>

        error_transactionmanager_identity_mismatch = ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH,
        /// <summary>This snapshot operation cannot continue because a transactional resource manager cannot be frozen in its current state.  Please try again.</summary>

        error_rm_cannot_be_frozen_for_snapshot = ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT,
        /// <summary>The transaction cannot be enlisted on with the specified EnlistmentMask, because the transaction has already completed the PrePrepare phase.  In order to ensure correctness, the ResourceManager must switch to a write-through mode and cease caching data within this transaction.  Enlisting for only subsequent transaction phases may still succeed.</summary>

        error_transaction_must_writethrough = ERROR_TRANSACTION_MUST_WRITETHROUGH,
        /// <summary>The transaction does not have a superior enlistment.</summary>

        error_transaction_no_superior = ERROR_TRANSACTION_NO_SUPERIOR,
        /// <summary>The attempt to commit the Transaction completed, but it is possible that some portion of the transaction tree did not commit successfully due to heuristics.  Therefore it is possible that some data modified in the transaction may not have committed, resulting in transactional inconsistency.  If possible, check the consistency of the associated data.</summary>

        error_heuristic_damage_possible = ERROR_HEURISTIC_DAMAGE_POSSIBLE,
        /// <summary>The function attempted to use a name that is reserved for use by another transaction.</summary>

        error_transactional_conflict = ERROR_TRANSACTIONAL_CONFLICT,
        /// <summary>Transaction support within the specified resource manager is not started or was shut down due to an error.</summary>

        error_rm_not_active = ERROR_RM_NOT_ACTIVE,
        /// <summary>The metadata of the RM has been corrupted. The RM will not function.</summary>

        error_rm_metadata_corrupt = ERROR_RM_METADATA_CORRUPT,
        /// <summary>The specified directory does not contain a resource manager.</summary>

        error_directory_not_rm = ERROR_DIRECTORY_NOT_RM,
        /// <summary>The remote server or share does not support transacted file operations.</summary>

        error_transactions_unsupported_remote = ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE,
        /// <summary>The requested log size is invalid.</summary>

        error_log_resize_invalid_size = ERROR_LOG_RESIZE_INVALID_SIZE,
        /// <summary>The object (file, stream, link) corresponding to the handle has been deleted by a Transaction Savepoint Rollback.</summary>

        error_object_no_longer_exists = ERROR_OBJECT_NO_LONGER_EXISTS,
        /// <summary>The specified file miniversion was not found for this transacted file open.</summary>

        error_stream_miniversion_not_found = ERROR_STREAM_MINIVERSION_NOT_FOUND,
        /// <summary>The specified file miniversion was found but has been invalidated. Most likely cause is a transaction savepoint rollback.</summary>

        error_stream_miniversion_not_valid = ERROR_STREAM_MINIVERSION_NOT_VALID,
        /// <summary>A miniversion may only be opened in the context of the transaction that created it.</summary>

        error_miniversion_inaccessible_from_specified_transaction = ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION,
        /// <summary>It is not possible to open a miniversion with modify access.</summary>

        error_cant_open_miniversion_with_modify_intent = ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT,
        /// <summary>It is not possible to create any more miniversions for this stream.</summary>

        error_cant_create_more_stream_miniversions = ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS,
        /// <summary>The remote server sent mismatching version number or Fid for a file opened with transactions.</summary>

        error_remote_file_version_mismatch = ERROR_REMOTE_FILE_VERSION_MISMATCH,
        /// <summary>The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint.</summary>

        error_handle_no_longer_valid = ERROR_HANDLE_NO_LONGER_VALID,
        /// <summary>There is no transaction metadata on the file.</summary>

        error_no_txf_metadata = ERROR_NO_TXF_METADATA,
        /// <summary>The log data is corrupt.</summary>

        error_log_corruption_detected = ERROR_LOG_CORRUPTION_DETECTED,
        /// <summary>The file can't be recovered because there is a handle still open on it.</summary>

        error_cant_recover_with_handle_open = ERROR_CANT_RECOVER_WITH_HANDLE_OPEN,
        /// <summary>The transaction outcome is unavailable because the resource manager responsible for it has disconnected.</summary>

        error_rm_disconnected = ERROR_RM_DISCONNECTED,
        /// <summary>The request was rejected because the enlistment in question is not a superior enlistment.</summary>

        error_enlistment_not_superior = ERROR_ENLISTMENT_NOT_SUPERIOR,
        /// <summary>The transactional resource manager is already consistent. Recovery is not needed.</summary>

        error_recovery_not_needed = ERROR_RECOVERY_NOT_NEEDED,
        /// <summary>The transactional resource manager has already been started.</summary>

        error_rm_already_started = ERROR_RM_ALREADY_STARTED,
        /// <summary>The file cannot be opened transactionally, because its identity depends on the outcome of an unresolved transaction.</summary>

        error_file_identity_not_persistent = ERROR_FILE_IDENTITY_NOT_PERSISTENT,
        /// <summary>The operation cannot be performed because another transaction is depending on the fact that this property will not change.</summary>

        error_cant_break_transactional_dependency = ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY,
        /// <summary>The operation would involve a single file with two transactional resource managers and is therefore not allowed.</summary>

        error_cant_cross_rm_boundary = ERROR_CANT_CROSS_RM_BOUNDARY,
        /// <summary>The $Txf directory must be empty for this operation to succeed.</summary>

        error_txf_dir_not_empty = ERROR_TXF_DIR_NOT_EMPTY,
        /// <summary>The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed.</summary>

        error_indoubt_transactions_exist = ERROR_INDOUBT_TRANSACTIONS_EXIST,
        /// <summary>The operation could not be completed because the transaction manager does not have a log.</summary>

        error_tm_volatile = ERROR_TM_VOLATILE,
        /// <summary>A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution.</summary>

        error_rollback_timer_expired = ERROR_ROLLBACK_TIMER_EXPIRED,
        /// <summary>The transactional metadata attribute on the file or directory is corrupt and unreadable.</summary>

        error_txf_attribute_corrupt = ERROR_TXF_ATTRIBUTE_CORRUPT,
        /// <summary>The encryption operation could not be completed because a transaction is active.</summary>

        error_efs_not_allowed_in_transaction = ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION,
        /// <summary>This object is not allowed to be opened in a transaction.</summary>

        error_transactional_open_not_allowed = ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED,
        /// <summary>An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log.</summary>

        error_log_growth_failed = ERROR_LOG_GROWTH_FAILED,
        /// <summary>Memory mapping (creating a mapped section) a remote file under a transaction is not supported.</summary>

        error_transacted_mapping_unsupported_remote = ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE,
        /// <summary>Transaction metadata is already present on this file and cannot be superseded.</summary>

        error_txf_metadata_already_present = ERROR_TXF_METADATA_ALREADY_PRESENT,
        /// <summary>A transaction scope could not be entered because the scope handler has not been initialized.</summary>

        error_transaction_scope_callbacks_not_set = ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET,
        /// <summary>Promotion was required in order to allow the resource manager to enlist, but the transaction was set to disallow it.</summary>

        error_transaction_required_promotion = ERROR_TRANSACTION_REQUIRED_PROMOTION,
        /// <summary>This file is open for modification in an unresolved transaction and may be opened for execute only by a transacted reader.</summary>

        error_cannot_execute_file_in_transaction = ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION,
        /// <summary>The request to thaw frozen transactions was ignored because transactions had not previously been frozen.</summary>

        error_transactions_not_frozen = ERROR_TRANSACTIONS_NOT_FROZEN,
        /// <summary>Transactions cannot be frozen because a freeze is already in progress.</summary>

        error_transaction_freeze_in_progress = ERROR_TRANSACTION_FREEZE_IN_PROGRESS,
        /// <summary>The target volume is not a snapshot volume. This operation is only valid on a volume mounted as a snapshot.</summary>

        error_not_snapshot_volume = ERROR_NOT_SNAPSHOT_VOLUME,
        /// <summary>The savepoint operation failed because files are open on the transaction. This is not permitted.</summary>

        error_no_savepoint_with_open_files = ERROR_NO_SAVEPOINT_WITH_OPEN_FILES,
        /// <summary>Windows has discovered corruption in a file, and that file has since been repaired. Data loss may have occurred.</summary>

        error_data_lost_repair = ERROR_DATA_LOST_REPAIR,
        /// <summary>The sparse operation could not be completed because a transaction is active on the file.</summary>

        error_sparse_not_allowed_in_transaction = ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION,
        /// <summary>The call to create a TransactionManager object failed because the Tm Identity stored in the logfile does not match the Tm Identity that was passed in as an argument.</summary>

        error_tm_identity_mismatch = ERROR_TM_IDENTITY_MISMATCH,
        /// <summary>I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data.</summary>

        error_floated_section = ERROR_FLOATED_SECTION,
        /// <summary>The transactional resource manager cannot currently accept transacted work due to a transient condition such as low resources.</summary>

        error_cannot_accept_transacted_work = ERROR_CANNOT_ACCEPT_TRANSACTED_WORK,
        /// <summary>The transactional resource manager had too many transactions outstanding that could not be aborted. The transactional resource manger has been shut down.</summary>

        error_cannot_abort_transactions = ERROR_CANNOT_ABORT_TRANSACTIONS,
        /// <summary>The operation could not be completed due to bad clusters on disk.</summary>

        error_bad_clusters = ERROR_BAD_CLUSTERS,
        /// <summary>The compression operation could not be completed because a transaction is active on the file.</summary>

        error_compression_not_allowed_in_transaction = ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION,
        /// <summary>The operation could not be completed because the volume is dirty. Please run chkdsk and try again.</summary>

        error_volume_dirty = ERROR_VOLUME_DIRTY,
        /// <summary>The link tracking operation could not be completed because a transaction is active.</summary>

        error_no_link_tracking_in_transaction = ERROR_NO_LINK_TRACKING_IN_TRANSACTION,
        /// <summary>This operation cannot be performed in a transaction.</summary>

        error_operation_not_supported_in_transaction = ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION,
        /// <summary>The handle is no longer properly associated with its transaction.  It may have been opened in a transactional resource manager that was subsequently forced to restart.  Please close the handle and open a new one.</summary>

        error_expired_handle = ERROR_EXPIRED_HANDLE,
        /// <summary>The specified operation could not be performed because the resource manager is not enlisted in the transaction.</summary>

        error_transaction_not_enlisted = ERROR_TRANSACTION_NOT_ENLISTED,
        /// <summary>The specified session name is invalid.</summary>

        error_ctx_winstation_name_invalid = ERROR_CTX_WINSTATION_NAME_INVALID,
        /// <summary>The specified protocol driver is invalid.</summary>

        error_ctx_invalid_pd = ERROR_CTX_INVALID_PD,
        /// <summary>The specified protocol driver was not found in the system path.</summary>

        error_ctx_pd_not_found = ERROR_CTX_PD_NOT_FOUND,
        /// <summary>The specified terminal connection driver was not found in the system path.</summary>

        error_ctx_wd_not_found = ERROR_CTX_WD_NOT_FOUND,
        /// <summary>A registry key for event logging could not be created for this session.</summary>

        error_ctx_cannot_make_eventlog_entry = ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY,
        /// <summary>A service with the same name already exists on the system.</summary>

        error_ctx_service_name_collision = ERROR_CTX_SERVICE_NAME_COLLISION,

        /// <summary>A close operation is pending on the session.</summary>
        error_ctx_close_pending = ERROR_CTX_CLOSE_PENDING,
        /// <summary>There are no free output buffers available.</summary>
        error_ctx_no_outbuf = ERROR_CTX_NO_OUTBUF,
        /// <summary>The MODEM.INF file was not found.</summary>
        error_ctx_modem_inf_not_found = ERROR_CTX_MODEM_INF_NOT_FOUND,
        /// <summary>The modem name was not found in MODEM.INF.</summary>
        error_ctx_invalid_modemname = ERROR_CTX_INVALID_MODEMNAME,
        /// <summary>The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem.</summary>
        error_ctx_modem_response_error = ERROR_CTX_MODEM_RESPONSE_ERROR,
        /// <summary>The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on.</summary>
        error_ctx_modem_response_timeout = ERROR_CTX_MODEM_RESPONSE_TIMEOUT,
        /// <summary>Carrier detect has failed or carrier has been dropped due to disconnect.</summary>
        error_ctx_modem_response_no_carrier = ERROR_CTX_MODEM_RESPONSE_NO_CARRIER,
        /// <summary>Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional.</summary>
        error_ctx_modem_response_no_dialtone = ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE,
        /// <summary>Busy signal detected at remote site on callback.</summary>
        error_ctx_modem_response_busy = ERROR_CTX_MODEM_RESPONSE_BUSY,
        /// <summary>Voice detected at remote site on callback.</summary>
        error_ctx_modem_response_voice = ERROR_CTX_MODEM_RESPONSE_VOICE,
        /// <summary>Transport driver error</summary>
        error_ctx_td_error = ERROR_CTX_TD_ERROR,
        /// <summary>The specified session cannot be found.</summary>
        error_ctx_winstation_not_found = ERROR_CTX_WINSTATION_NOT_FOUND,
        /// <summary>The specified session name is already in use.</summary>
        error_ctx_winstation_already_exists = ERROR_CTX_WINSTATION_ALREADY_EXISTS,
        /// <summary>The task you are trying to do can't be completed because Remote Desktop Services is currently busy. Please try again in a few minutes. Other users should still be able to log on.</summary>
        error_ctx_winstation_busy = ERROR_CTX_WINSTATION_BUSY,
        /// <summary>An attempt has been made to connect to a session whose video mode is not supported by the current client.</summary>
        error_ctx_bad_video_mode = ERROR_CTX_BAD_VIDEO_MODE,
        /// <summary>The application attempted to enable DOS graphics mode. DOS graphics mode is not supported.</summary>
        error_ctx_graphics_invalid = ERROR_CTX_GRAPHICS_INVALID,
        /// <summary>Your interactive logon privilege has been disabled. Please contact your administrator.</summary>
        error_ctx_logon_disabled = ERROR_CTX_LOGON_DISABLED,
        /// <summary>The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access.</summary>
        error_ctx_not_console = ERROR_CTX_NOT_CONSOLE,
        /// <summary>The client failed to respond to the server connect message.</summary>
        error_ctx_client_query_timeout = ERROR_CTX_CLIENT_QUERY_TIMEOUT,
        /// <summary>Disconnecting the console session is not supported.</summary>
        error_ctx_console_disconnect = ERROR_CTX_CONSOLE_DISCONNECT,
        /// <summary>Reconnecting a disconnected session to the console is not supported.</summary>
        error_ctx_console_connect = ERROR_CTX_CONSOLE_CONNECT,
        /// <summary>The request to control another session remotely was denied.</summary>
        error_ctx_shadow_denied = ERROR_CTX_SHADOW_DENIED,
        /// <summary>The requested session access is denied.</summary>
        error_ctx_winstation_access_denied = ERROR_CTX_WINSTATION_ACCESS_DENIED,
        /// <summary>The specified terminal connection driver is invalid.</summary>
        error_ctx_invalid_wd = ERROR_CTX_INVALID_WD,
        /// <summary>The requested session cannot be controlled remotely.</summary>
        /// <summary>This may be because the session is disconnected or does not currently have a user logged on.</summary>
        error_ctx_shadow_invalid = ERROR_CTX_SHADOW_INVALID,
        /// <summary>The requested session is not configured to allow remote control.</summary>
        error_ctx_shadow_disabled = ERROR_CTX_SHADOW_DISABLED,
        /// <summary>Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user. Please call your system administrator to obtain a unique license number.</summary>
        error_ctx_client_license_in_use = ERROR_CTX_CLIENT_LICENSE_IN_USE,
        /// <summary>Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client. Please contact your system administrator.</summary>
        error_ctx_client_license_not_set = ERROR_CTX_CLIENT_LICENSE_NOT_SET,
        /// <summary>The number of connections to this computer is limited and all connections are in use right now. Try connecting later or contact your system administrator.</summary>
        error_ctx_license_not_available = ERROR_CTX_LICENSE_NOT_AVAILABLE,
        /// <summary>The client you are using is not licensed to use this system. Your logon request is denied.</summary>
        error_ctx_license_client_invalid = ERROR_CTX_LICENSE_CLIENT_INVALID,
        /// <summary>The system license has expired. Your logon request is denied.</summary>
        error_ctx_license_expired = ERROR_CTX_LICENSE_EXPIRED,
        /// <summary>Remote control could not be terminated because the specified session is not currently being remotely controlled.</summary>
        error_ctx_shadow_not_running = ERROR_CTX_SHADOW_NOT_RUNNING,
        /// <summary>The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.</summary>
        error_ctx_shadow_ended_by_mode_change = ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE,
        /// <summary>Activation has already been reset the maximum number of times for this installation. Your activation timer will not be cleared.</summary>
        error_activation_count_exceeded = ERROR_ACTIVATION_COUNT_EXCEEDED,
        /// <summary>Remote logins are currently disabled.</summary>
        error_ctx_winstations_disabled = ERROR_CTX_WINSTATIONS_DISABLED,
        /// <summary>You do not have the proper encryption level to access this Session.</summary>
        error_ctx_encryption_level_required = ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED,
        /// <summary>The user %s\\%s is currently logged on to this computer. Only the current user or an administrator can log on to this computer.</summary>
        error_ctx_session_in_use = ERROR_CTX_SESSION_IN_USE,
        /// <summary>The user %s\\%s is already logged on to the console of this computer. You do not have permission to log in at this time. To resolve this issue, contact %s\\%s and have them log off.</summary>
        error_ctx_no_force_logoff = ERROR_CTX_NO_FORCE_LOGOFF,
        /// <summary>Unable to log you on because of an account restriction.</summary>
        error_ctx_account_restriction = ERROR_CTX_ACCOUNT_RESTRICTION,
        /// <summary>The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.</summary>
        error_rdp_protocol_error = ERROR_RDP_PROTOCOL_ERROR,
        /// <summary>The Client Drive Mapping Service Has Connected on Terminal Connection.</summary>
        error_ctx_cdm_connect = ERROR_CTX_CDM_CONNECT,
        /// <summary>The Client Drive Mapping Service Has Disconnected on Terminal Connection.</summary>
        error_ctx_cdm_disconnect = ERROR_CTX_CDM_DISCONNECT,
        /// <summary>The Terminal Server security layer detected an error in the protocol stream and has disconnected the client.</summary>
        error_ctx_security_layer_error = ERROR_CTX_SECURITY_LAYER_ERROR,
        /// <summary>The target session is incompatible with the current session.</summary>
        error_ts_incompatible_sessions = ERROR_TS_INCOMPATIBLE_SESSIONS,
        /// <summary>Windows can't connect to your session because a problem occurred in the Windows video subsystem. Try connecting again later, or contact the server administrator for assistance.</summary>
        error_ts_video_subsystem_error = ERROR_TS_VIDEO_SUBSYSTEM_ERROR,
    };

}

#endif
#endif
