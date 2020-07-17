
// Copyright © 2020 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 

#ifndef __MODERN_WIN32_WINDOWS_ERROR_H__
#define __MODERN_WIN32_WINDOWS_ERROR_H__
#ifdef _WIN32

#include <winerror.h>

namespace modern_win32
{
    enum class windows_error
    {
        none = NO_ERROR,

// Incorrect function.
ERROR_INVALID_FUNCTION           1L    // dderror

// The system cannot find the file specified.
ERROR_FILE_NOT_FOUND             2L
// The system cannot find the path specified.
ERROR_PATH_NOT_FOUND             3L
// The system cannot open the file.
ERROR_TOO_MANY_OPEN_FILES        4L
// Access is denied.
ERROR_ACCESS_DENIED              5L
// The handle is invalid.
ERROR_INVALID_HANDLE             6L
// The storage control blocks were destroyed.
ERROR_ARENA_TRASHED              7L
// Not enough memory resources are available to process this command.
ERROR_NOT_ENOUGH_MEMORY          8L    // dderror
// The storage control block address is invalid.
ERROR_INVALID_BLOCK              9L
// The environment is incorrect.
ERROR_BAD_ENVIRONMENT            10L
// An attempt was made to load a program with an incorrect format.
ERROR_BAD_FORMAT                 11L
// The access code is invalid.
ERROR_INVALID_ACCESS             12L
// The data is invalid.
ERROR_INVALID_DATA               13L
// Not enough memory resources are available to complete this operation.
ERROR_OUTOFMEMORY                14L
// The system cannot find the drive specified.
ERROR_INVALID_DRIVE              15L
// The directory cannot be removed.
ERROR_CURRENT_DIRECTORY          16L
// The system cannot move the file to a different disk drive.
ERROR_NOT_SAME_DEVICE            17L
// There are no more files.
ERROR_NO_MORE_FILES              18L
// The media is write protected.
ERROR_WRITE_PROTECT              19L
// The system cannot find the device specified.
ERROR_BAD_UNIT                   20L
// The device is not ready.
ERROR_NOT_READY                  21L
// The device does not recognize the command.
ERROR_BAD_COMMAND                22L
// Data error (cyclic redundancy check).
ERROR_CRC                        23L
// The program issued a command but the command length is incorrect.
ERROR_BAD_LENGTH                 24L
// The drive cannot locate a specific area or track on the disk.
ERROR_SEEK                       25L
// The specified disk or diskette cannot be accessed.
ERROR_NOT_DOS_DISK               26L
// The drive cannot find the sector requested.
ERROR_SECTOR_NOT_FOUND           27L
// The printer is out of paper.
ERROR_OUT_OF_PAPER               28L
// The system cannot write to the specified device.
ERROR_WRITE_FAULT                29L
// The system cannot read from the specified device.
ERROR_READ_FAULT                 30L
// A device attached to the system is not functioning.
ERROR_GEN_FAILURE                31L
// The process cannot access the file because it is being used by another process.
ERROR_SHARING_VIOLATION          32L
// The process cannot access the file because another process has locked a portion of the file.
ERROR_LOCK_VIOLATION             33L
// The wrong diskette is in the drive.
// Insert %2 (Volume Serial Number: %3) into drive %1.
ERROR_WRONG_DISK                 34L
// Too many files opened for sharing.
ERROR_SHARING_BUFFER_EXCEEDED    36L
// Reached the end of the file.
ERROR_HANDLE_EOF                 38L
// The disk is full.
ERROR_HANDLE_DISK_FULL           39L
// The request is not supported.
ERROR_NOT_SUPPORTED              50L
// Windows cannot find the network path. Verify that the network path is correct and the destination computer is not busy or turned off. If Windows still cannot find the network path, contact your network administrator.
ERROR_REM_NOT_LIST               51L
// You were not connected because a duplicate name exists on the network. If joining a domain, go to System in Control Panel to change the computer name and try again. If joining a workgroup, choose another workgroup name.
ERROR_DUP_NAME                   52L
// The network path was not found.
ERROR_BAD_NETPATH                53L
// The network is busy.
ERROR_NETWORK_BUSY               54L
// The specified network resource or device is no longer available.
ERROR_DEV_NOT_EXIST              55L    // dderror
// The network BIOS command limit has been reached.
ERROR_TOO_MANY_CMDS              56L
// A network adapter hardware error occurred.
ERROR_ADAP_HDW_ERR               57L
// The specified server cannot perform the requested operation.
ERROR_BAD_NET_RESP               58L
// An unexpected network error occurred.
ERROR_UNEXP_NET_ERR              59L
// The remote adapter is not compatible.
ERROR_BAD_REM_ADAP               60L
// The printer queue is full.
ERROR_PRINTQ_FULL                61L
// Space to store the file waiting to be printed is not available on the server.
ERROR_NO_SPOOL_SPACE             62L
// Your file waiting to be printed was deleted.
ERROR_PRINT_CANCELLED            63L
// The specified network name is no longer available.
ERROR_NETNAME_DELETED            64L
// Network access is denied.
ERROR_NETWORK_ACCESS_DENIED      65L
// The network resource type is not correct.
ERROR_BAD_DEV_TYPE               66L
// The network name cannot be found.
ERROR_BAD_NET_NAME               67L
// The name limit for the local computer network adapter card was exceeded.
ERROR_TOO_MANY_NAMES             68L
// The network BIOS session limit was exceeded.
ERROR_TOO_MANY_SESS              69L
// The remote server has been paused or is in the process of being started.
ERROR_SHARING_PAUSED             70L
// No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.
ERROR_REQ_NOT_ACCEP              71L
// The specified printer or disk device has been paused.
ERROR_REDIR_PAUSED               72L
// The file exists.
ERROR_FILE_EXISTS                80L
// The directory or file cannot be created.
ERROR_CANNOT_MAKE                82L
// Fail on INT 24.
ERROR_FAIL_I24                   83L
// Storage to process this request is not available.
ERROR_OUT_OF_STRUCTURES          84L
// The local device name is already in use.
ERROR_ALREADY_ASSIGNED           85L
// The specified network password is not correct.
ERROR_INVALID_PASSWORD           86L
// The parameter is incorrect.
ERROR_INVALID_PARAMETER          87L    // dderror
// A write fault occurred on the network.
ERROR_NET_WRITE_FAULT            88L
// The system cannot start another process at this time.
ERROR_NO_PROC_SLOTS              89L
// Cannot create another system semaphore.
ERROR_TOO_MANY_SEMAPHORES        100L
// The exclusive semaphore is owned by another process.
ERROR_EXCL_SEM_ALREADY_OWNED     101L
// The semaphore is set and cannot be closed.
ERROR_SEM_IS_SET                 102L
// The semaphore cannot be set again.
ERROR_TOO_MANY_SEM_REQUESTS      103L
// Cannot request exclusive semaphores at interrupt time.
ERROR_INVALID_AT_INTERRUPT_TIME  104L
// The previous ownership of this semaphore has ended.
ERROR_SEM_OWNER_DIED             105L
// Insert the diskette for drive %1.
ERROR_SEM_USER_LIMIT             106L
// The program stopped because an alternate diskette was not inserted.
ERROR_DISK_CHANGE                107L
// The disk is in use or locked by another process.
ERROR_DRIVE_LOCKED               108L
// The pipe has been ended.
ERROR_BROKEN_PIPE                109L
// The system cannot open the device or file specified.
ERROR_OPEN_FAILED                110L
// The file name is too long.
ERROR_BUFFER_OVERFLOW            111L
// There is not enough space on the disk.
ERROR_DISK_FULL                  112L
// No more internal file identifiers available.
ERROR_NO_MORE_SEARCH_HANDLES     113L
// The target internal file identifier is incorrect.
ERROR_INVALID_TARGET_HANDLE      114L
// The IOCTL call made by the application program is not correct.
ERROR_INVALID_CATEGORY           117L
// The verify-on-write switch parameter value is not correct.
ERROR_INVALID_VERIFY_SWITCH      118L
// The system does not support the command requested.
ERROR_BAD_DRIVER_LEVEL           119L
// This function is not supported on this system.
ERROR_CALL_NOT_IMPLEMENTED       120L
// The semaphore timeout period has expired.
ERROR_SEM_TIMEOUT                121L
// The data area passed to a system call is too small.
ERROR_INSUFFICIENT_BUFFER        122L    // dderror
// The filename, directory name, or volume label syntax is incorrect.
ERROR_INVALID_NAME               123L    // dderror
// The system call level is not correct.
ERROR_INVALID_LEVEL              124L
// The disk has no volume label.
ERROR_NO_VOLUME_LABEL            125L
// The specified module could not be found.
ERROR_MOD_NOT_FOUND              126L
// The specified procedure could not be found.
ERROR_PROC_NOT_FOUND             127L
// There are no child processes to wait for.
ERROR_WAIT_NO_CHILDREN           128L
// The %1 application cannot be run in Win32 mode.
ERROR_CHILD_NOT_COMPLETE         129L
// Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.
ERROR_DIRECT_ACCESS_HANDLE       130L
// An attempt was made to move the file pointer before the beginning of the file.
ERROR_NEGATIVE_SEEK              131L
// The file pointer cannot be set on the specified device or file.
ERROR_SEEK_ON_DEVICE             132L
// A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.
ERROR_IS_JOIN_TARGET             133L
// An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.
ERROR_IS_JOINED                  134L
// An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.
ERROR_IS_SUBSTED                 135L
// The system tried to delete the JOIN of a drive that is not joined.
ERROR_NOT_JOINED                 136L
// The system tried to delete the substitution of a drive that is not substituted.
ERROR_NOT_SUBSTED                137L
// The system tried to join a drive to a directory on a joined drive.
ERROR_JOIN_TO_JOIN               138L
// The system tried to substitute a drive to a directory on a substituted drive.
ERROR_SUBST_TO_SUBST             139L
// The system tried to join a drive to a directory on a substituted drive.
ERROR_JOIN_TO_SUBST              140L
// The system tried to SUBST a drive to a directory on a joined drive.
ERROR_SUBST_TO_JOIN              141L
// The system cannot perform a JOIN or SUBST at this time.
ERROR_BUSY_DRIVE                 142L
// The system cannot join or substitute a drive to or for a directory on the same drive.
ERROR_SAME_DRIVE                 143L
// The directory is not a subdirectory of the root directory.
ERROR_DIR_NOT_ROOT               144L
// The directory is not empty.
ERROR_DIR_NOT_EMPTY              145L
// The path specified is being used in a substitute.
ERROR_IS_SUBST_PATH              146L
// Not enough resources are available to process this command.
ERROR_IS_JOIN_PATH               147L
// The path specified cannot be used at this time.
ERROR_PATH_BUSY                  148L
// An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.
ERROR_IS_SUBST_TARGET            149L
// System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.
ERROR_SYSTEM_TRACE               150L
// The number of specified semaphore events for DosMuxSemWait is not correct.
ERROR_INVALID_EVENT_COUNT        151L
// DosMuxSemWait did not execute; too many semaphores are already set.
ERROR_TOO_MANY_MUXWAITERS        152L
// The DosMuxSemWait list is not correct.
ERROR_INVALID_LIST_FORMAT        153L
// The volume label you entered exceeds the label character limit of the target file system.
ERROR_LABEL_TOO_LONG             154L
// Cannot create another thread.
ERROR_TOO_MANY_TCBS              155L
// The recipient process has refused the signal.
ERROR_SIGNAL_REFUSED             156L
// The segment is already discarded and cannot be locked.
ERROR_DISCARDED                  157L
// The segment is already unlocked.
ERROR_NOT_LOCKED                 158L
// The address for the thread ID is not correct.
ERROR_BAD_THREADID_ADDR          159L
// One or more arguments are not correct.
ERROR_BAD_ARGUMENTS              160L
// The specified path is invalid.
ERROR_BAD_PATHNAME               161L
// A signal is already pending.
ERROR_SIGNAL_PENDING             162L
// No more threads can be created in the system.
ERROR_MAX_THRDS_REACHED          164L
// Unable to lock a region of a file.
ERROR_LOCK_FAILED                167L
// The requested resource is in use.
ERROR_BUSY                       170L    // dderror
// Device's command support detection is in progress.
ERROR_DEVICE_SUPPORT_IN_PROGRESS 171L
// A lock request was not outstanding for the supplied cancel region.
ERROR_CANCEL_VIOLATION           173L
// The file system does not support atomic changes to the lock type.
ERROR_ATOMIC_LOCKS_NOT_SUPPORTED 174L
// The system detected a segment number that was not correct.
ERROR_INVALID_SEGMENT_NUMBER     180L
// The operating system cannot run %1.
ERROR_INVALID_ORDINAL            182L
// Cannot create a file when that file already exists.
ERROR_ALREADY_EXISTS             183L
// The flag passed is not correct.
ERROR_INVALID_FLAG_NUMBER        186L
// The specified system semaphore name was not found.
ERROR_SEM_NOT_FOUND              187L
// The operating system cannot run %1.
ERROR_INVALID_STARTING_CODESEG   188L
// The operating system cannot run %1.
ERROR_INVALID_STACKSEG           189L
// The operating system cannot run %1.
ERROR_INVALID_MODULETYPE         190L
// Cannot run %1 in Win32 mode.
ERROR_INVALID_EXE_SIGNATURE      191L
// The operating system cannot run %1.
ERROR_EXE_MARKED_INVALID         192L
// %1 is not a valid Win32 application.
ERROR_BAD_EXE_FORMAT             193L
// The operating system cannot run %1.
ERROR_ITERATED_DATA_EXCEEDS_64k  194L
// The operating system cannot run %1.
ERROR_INVALID_MINALLOCSIZE       195L
// The operating system cannot run this application program.
ERROR_DYNLINK_FROM_INVALID_RING  196L
// The operating system is not presently configured to run this application.
ERROR_IOPL_NOT_ENABLED           197L
// The operating system cannot run %1.
ERROR_INVALID_SEGDPL             198L
// The operating system cannot run this application program.
ERROR_AUTODATASEG_EXCEEDS_64k    199L
// The code segment cannot be greater than or equal to 64K.
ERROR_RING2SEG_MUST_BE_MOVABLE   200L
// The operating system cannot run %1.
ERROR_RELOC_CHAIN_XEEDS_SEGLIM   201L
// The operating system cannot run %1.
ERROR_INFLOOP_IN_RELOC_CHAIN     202L
// The system could not find the environment option that was entered.
ERROR_ENVVAR_NOT_FOUND           203L
// No process in the command subtree has a signal handler.
ERROR_NO_SIGNAL_SENT             205L
// The filename or extension is too long.
ERROR_FILENAME_EXCED_RANGE       206L
// The ring 2 stack is in use.
ERROR_RING2_STACK_IN_USE         207L
// The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.
ERROR_META_EXPANSION_TOO_LONG    208L
// The signal being posted is not correct.
ERROR_INVALID_SIGNAL_NUMBER      209L
// The signal handler cannot be set.
ERROR_THREAD_1_INACTIVE          210L
// The segment is locked and cannot be reallocated.
ERROR_LOCKED                     212L
// Too many dynamic-link modules are attached to this program or dynamic-link module.
ERROR_TOO_MANY_MODULES           214L
// Cannot nest calls to LoadModule.
ERROR_NESTING_NOT_ALLOWED        215L
// This version of %1 is not compatible with the version of Windows you're running. Check your computer's system information and then contact the software publisher.
ERROR_EXE_MACHINE_TYPE_MISMATCH  216L
// The image file %1 is signed, unable to modify.
ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY 217L
// The image file %1 is strong signed, unable to modify.
ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY 218L
// This file is checked out or locked for editing by another user.
ERROR_FILE_CHECKED_OUT           220L
// The file must be checked out before saving changes.
ERROR_CHECKOUT_REQUIRED          221L
// The file type being saved or retrieved has been blocked.
ERROR_BAD_FILE_TYPE              222L
// The file size exceeds the limit allowed and cannot be saved.
ERROR_FILE_TOO_LARGE             223L
// Access Denied. Before opening files in this location, you must first add the web site to your trusted sites list, browse to the web site, and select the option to login automatically.
ERROR_FORMS_AUTH_REQUIRED        224L
// Operation did not complete successfully because the file contains a virus or potentially unwanted software.
ERROR_VIRUS_INFECTED             225L
// This file contains a virus or potentially unwanted software and cannot be opened. Due to the nature of this virus or potentially unwanted software, the file has been removed from this location.
ERROR_VIRUS_DELETED              226L
// The pipe is local.
ERROR_PIPE_LOCAL                 229L
// The pipe state is invalid.
ERROR_BAD_PIPE                   230L
// All pipe instances are busy.
ERROR_PIPE_BUSY                  231L
// The pipe is being closed.
ERROR_NO_DATA                    232L
// No process is on the other end of the pipe.
ERROR_PIPE_NOT_CONNECTED         233L
// More data is available.
ERROR_MORE_DATA                  234L    // dderror
// The action requested resulted in no work being done. Error-style clean-up has been performed.
ERROR_NO_WORK_DONE               235L
// The session was canceled.
ERROR_VC_DISCONNECTED            240L
// The specified extended attribute name was invalid.
ERROR_INVALID_EA_NAME            254L
// The extended attributes are inconsistent.
ERROR_EA_LIST_INCONSISTENT       255L
// The wait operation timed out.
WAIT_TIMEOUT                     258L    // dderror
// No more data is available.
ERROR_NO_MORE_ITEMS              259L
// The copy functions cannot be used.
ERROR_CANNOT_COPY                266L
// The directory name is invalid.
ERROR_DIRECTORY                  267L
// The extended attributes did not fit in the buffer.
ERROR_EAS_DIDNT_FIT              275L
// The extended attribute file on the mounted file system is corrupt.
ERROR_EA_FILE_CORRUPT            276L
// The extended attribute table file is full.
ERROR_EA_TABLE_FULL              277L
// The specified extended attribute handle is invalid.
ERROR_INVALID_EA_HANDLE          278L
// The mounted file system does not support extended attributes.
ERROR_EAS_NOT_SUPPORTED          282L
// Attempt to release mutex not owned by caller.
ERROR_NOT_OWNER                  288L
// Too many posts were made to a semaphore.
ERROR_TOO_MANY_POSTS             298L
// Only part of a ReadProcessMemory or WriteProcessMemory request was completed.
ERROR_PARTIAL_COPY               299L
// The oplock request is denied.
ERROR_OPLOCK_NOT_GRANTED         300L
// An invalid oplock acknowledgment was received by the system.
ERROR_INVALID_OPLOCK_PROTOCOL    301L
// The volume is too fragmented to complete this operation.
ERROR_DISK_TOO_FRAGMENTED        302L
// The file cannot be opened because it is in the process of being deleted.
ERROR_DELETE_PENDING             303L
// Short name settings may not be changed on this volume due to the global registry setting.
ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING 304L
// Short names are not enabled on this volume.
ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME 305L
// The security stream for the given volume is in an inconsistent state.
// Please run CHKDSK on the volume.
ERROR_SECURITY_STREAM_IS_INCONSISTENT 306L
// A requested file lock operation cannot be processed due to an invalid byte range.
ERROR_INVALID_LOCK_RANGE         307L
// The subsystem needed to support the image type is not present.
ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT 308L
// The specified file already has a notification GUID associated with it.
ERROR_NOTIFICATION_GUID_ALREADY_DEFINED 309L
// An invalid exception handler routine has been detected.
ERROR_INVALID_EXCEPTION_HANDLER  310L
// Duplicate privileges were specified for the token.
ERROR_DUPLICATE_PRIVILEGES       311L
// No ranges for the specified operation were able to be processed.
ERROR_NO_RANGES_PROCESSED        312L
// Operation is not allowed on a file system internal file.
ERROR_NOT_ALLOWED_ON_SYSTEM_FILE 313L
// The physical resources of this disk have been exhausted.
ERROR_DISK_RESOURCES_EXHAUSTED   314L
// The token representing the data is invalid.
ERROR_INVALID_TOKEN              315L
// The device does not support the command feature.
ERROR_DEVICE_FEATURE_NOT_SUPPORTED 316L
// The system cannot find message text for message number 0x%1 in the message file for %2.
ERROR_MR_MID_NOT_FOUND           317L
// The scope specified was not found.
ERROR_SCOPE_NOT_FOUND            318L
// The Central Access Policy specified is not defined on the target machine.
ERROR_UNDEFINED_SCOPE            319L
// The Central Access Policy obtained from Active Directory is invalid.
ERROR_INVALID_CAP                320L
// The device is unreachable.
ERROR_DEVICE_UNREACHABLE         321L
// The target device has insufficient resources to complete the operation.
ERROR_DEVICE_NO_RESOURCES        322L
// A data integrity checksum error occurred. Data in the file stream is corrupt.
ERROR_DATA_CHECKSUM_ERROR        323L
// An attempt was made to modify both a KERNEL and normal Extended Attribute (EA) in the same operation.
ERROR_INTERMIXED_KERNEL_EA_OPERATION 324L
// Device does not support file-level TRIM.
ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED 326L
// The command specified a data offset that does not align to the device's granularity/alignment.
ERROR_OFFSET_ALIGNMENT_VIOLATION 327L
// The command specified an invalid field in its parameter list.
ERROR_INVALID_FIELD_IN_PARAMETER_LIST 328L
// An operation is currently in progress with the device.
ERROR_OPERATION_IN_PROGRESS      329L
// An attempt was made to send down the command via an invalid path to the target device.
ERROR_BAD_DEVICE_PATH            330L
// The command specified a number of descriptors that exceeded the maximum supported by the device.
ERROR_TOO_MANY_DESCRIPTORS       331L
// Scrub is disabled on the specified file.
ERROR_SCRUB_DATA_DISABLED        332L
// The storage device does not provide redundancy.
ERROR_NOT_REDUNDANT_STORAGE      333L
// An operation is not supported on a resident file.
ERROR_RESIDENT_FILE_NOT_SUPPORTED 334L
// An operation is not supported on a compressed file.
ERROR_COMPRESSED_FILE_NOT_SUPPORTED 335L
// An operation is not supported on a directory.
ERROR_DIRECTORY_NOT_SUPPORTED    336L
// The specified copy of the requested data could not be read.
ERROR_NOT_READ_FROM_COPY         337L
// The specified data could not be written to any of the copies.
ERROR_FT_WRITE_FAILURE           338L
// One or more copies of data on this device may be out of sync. No writes may be performed until a data integrity scan is completed.
ERROR_FT_DI_SCAN_REQUIRED        339L
// The supplied kernel information version is invalid.
ERROR_INVALID_KERNEL_INFO_VERSION 340L
// The supplied PEP information version is invalid.
ERROR_INVALID_PEP_INFO_VERSION   341L
// This object is not externally backed by any provider.
ERROR_OBJECT_NOT_EXTERNALLY_BACKED 342L
// The external backing provider is not recognized.
ERROR_EXTERNAL_BACKING_PROVIDER_UNKNOWN 343L
// Compressing this object would not save space.
ERROR_COMPRESSION_NOT_BENEFICIAL 344L
// The request failed due to a storage topology ID mismatch.
ERROR_STORAGE_TOPOLOGY_ID_MISMATCH 345L
// The operation was blocked by parental controls.
ERROR_BLOCKED_BY_PARENTAL_CONTROLS 346L
// A file system block being referenced has already reached the maximum reference count and can't be referenced any further.
ERROR_BLOCK_TOO_MANY_REFERENCES  347L
// The requested operation failed because the file stream is marked to disallow writes.
ERROR_MARKED_TO_DISALLOW_WRITES  348L
// The requested operation failed with an architecture-specific failure code.
ERROR_ENCLAVE_FAILURE            349L
// No action was taken as a system reboot is required.
ERROR_FAIL_NOACTION_REBOOT       350L
// The shutdown operation failed.
ERROR_FAIL_SHUTDOWN              351L
// The restart operation failed.
ERROR_FAIL_RESTART               352L
// The maximum number of sessions has been reached.
ERROR_MAX_SESSIONS_REACHED       353L
// Windows Information Protection policy does not allow access to this network resource.
ERROR_NETWORK_ACCESS_DENIED_EDP  354L
// The device hint name buffer is too small to receive the remaining name.
ERROR_DEVICE_HINT_NAME_BUFFER_TOO_SMALL 355L
// The requested operation was blocked by Windows Information Protection policy. For more information, contact your system administrator.
ERROR_EDP_POLICY_DENIES_OPERATION 356L
// The requested operation cannot be performed because hardware or software configuration of the device does not comply with Windows Information Protection under Lock policy. Please, verify that user PIN has been created. For more information, contact your system administrator.
ERROR_EDP_DPL_POLICY_CANT_BE_SATISFIED 357L
// The cloud sync root metadata is corrupted.
ERROR_CLOUD_FILE_SYNC_ROOT_METADATA_CORRUPT 358L
// The device is in maintenance mode.
ERROR_DEVICE_IN_MAINTENANCE      359L
// This operation is not supported on a DAX volume.
ERROR_NOT_SUPPORTED_ON_DAX       360L
// The volume has active DAX mappings.
ERROR_DAX_MAPPING_EXISTS         361L
// The cloud file provider is not running.
ERROR_CLOUD_FILE_PROVIDER_NOT_RUNNING 362L
// The cloud file metadata is corrupt and unreadable.
ERROR_CLOUD_FILE_METADATA_CORRUPT 363L
// The cloud file metadata is too large.
ERROR_CLOUD_FILE_METADATA_TOO_LARGE 364L
// The cloud file property is too large.
ERROR_CLOUD_FILE_PROPERTY_BLOB_TOO_LARGE 365L
// The cloud file property is possibly corrupt. The on-disk checksum does not match the computed checksum.
ERROR_CLOUD_FILE_PROPERTY_BLOB_CHECKSUM_MISMATCH 366L
// The process creation has been blocked.
ERROR_CHILD_PROCESS_BLOCKED      367L
// The storage device has lost data or persistence.
ERROR_STORAGE_LOST_DATA_PERSISTENCE 368L
// The provider that supports file system virtualization is temporarily unavailable.
ERROR_FILE_SYSTEM_VIRTUALIZATION_UNAVAILABLE 369L
// The metadata for file system virtualization is corrupt and unreadable.
ERROR_FILE_SYSTEM_VIRTUALIZATION_METADATA_CORRUPT 370L
// The provider that supports file system virtualization is too busy to complete this operation.
ERROR_FILE_SYSTEM_VIRTUALIZATION_BUSY 371L
// The provider that supports file system virtualization is unknown.
ERROR_FILE_SYSTEM_VIRTUALIZATION_PROVIDER_UNKNOWN 372L
// GDI handles were potentially leaked by the application.
ERROR_GDI_HANDLE_LEAK            373L
// The maximum number of cloud file properties has been reached.
ERROR_CLOUD_FILE_TOO_MANY_PROPERTY_BLOBS 374L
// The version of the cloud file property store is not supported.
ERROR_CLOUD_FILE_PROPERTY_VERSION_NOT_SUPPORTED 375L
// The file is not a cloud file.
ERROR_NOT_A_CLOUD_FILE           376L
// The file is not in sync with the cloud.
ERROR_CLOUD_FILE_NOT_IN_SYNC     377L
// The cloud sync root is already connected with another cloud sync provider.
ERROR_CLOUD_FILE_ALREADY_CONNECTED 378L
// The operation is not supported by the cloud sync provider.
ERROR_CLOUD_FILE_NOT_SUPPORTED   379L
// The cloud operation is invalid.
ERROR_CLOUD_FILE_INVALID_REQUEST 380L
// The cloud operation is not supported on a read-only volume.
ERROR_CLOUD_FILE_READ_ONLY_VOLUME 381L
// The operation is reserved for a connected cloud sync provider.
ERROR_CLOUD_FILE_CONNECTED_PROVIDER_ONLY 382L
// The cloud sync provider failed to validate the downloaded data.
ERROR_CLOUD_FILE_VALIDATION_FAILED 383L
// You can't connect to the file share because it's not secure. This share requires the obsolete SMB1 protocol, which is unsafe and could expose your system to attack.
// Your system requires SMB2 or higher. For more info on resolving this issue, see: https://go.microsoft.com/fwlink/?linkid=852747
ERROR_SMB1_NOT_AVAILABLE         384L
// The virtualization operation is not allowed on the file in its current state.
ERROR_FILE_SYSTEM_VIRTUALIZATION_INVALID_OPERATION 385L
// The cloud sync provider failed user authentication.
ERROR_CLOUD_FILE_AUTHENTICATION_FAILED 386L
// The cloud sync provider failed to perform the operation due to low system resources.
ERROR_CLOUD_FILE_INSUFFICIENT_RESOURCES 387L
// The cloud sync provider failed to perform the operation due to network being unavailable.
ERROR_CLOUD_FILE_NETWORK_UNAVAILABLE 388L
// The cloud operation was unsuccessful.
ERROR_CLOUD_FILE_UNSUCCESSFUL    389L
// The operation is only supported on files under a cloud sync root.
ERROR_CLOUD_FILE_NOT_UNDER_SYNC_ROOT 390L
// The operation cannot be performed on cloud files in use.
ERROR_CLOUD_FILE_IN_USE          391L
// The operation cannot be performed on pinned cloud files.
ERROR_CLOUD_FILE_PINNED          392L
// The cloud operation was aborted.
ERROR_CLOUD_FILE_REQUEST_ABORTED 393L
// The cloud file's property store is corrupt.
ERROR_CLOUD_FILE_PROPERTY_CORRUPT 394L
// Access to the cloud file is denied.
ERROR_CLOUD_FILE_ACCESS_DENIED   395L
// The cloud operation cannot be performed on a file with incompatible hardlinks.
ERROR_CLOUD_FILE_INCOMPATIBLE_HARDLINKS 396L
// The operation failed due to a conflicting cloud file property lock.
ERROR_CLOUD_FILE_PROPERTY_LOCK_CONFLICT 397L
// The cloud operation was canceled by user.
ERROR_CLOUD_FILE_REQUEST_CANCELED 398L
// An externally encrypted syskey has been configured, but the system no longer supports this feature.  Please see https://go.microsoft.com/fwlink/?linkid=851152 for more information.
ERROR_EXTERNAL_SYSKEY_NOT_SUPPORTED 399L
// The thread is already in background processing mode.
ERROR_THREAD_MODE_ALREADY_BACKGROUND 400L
// The thread is not in background processing mode.
ERROR_THREAD_MODE_NOT_BACKGROUND 401L
// The process is already in background processing mode.
ERROR_PROCESS_MODE_ALREADY_BACKGROUND 402L
// The process is not in background processing mode.
ERROR_PROCESS_MODE_NOT_BACKGROUND 403L
// The cloud file provider exited unexpectedly.
ERROR_CLOUD_FILE_PROVIDER_TERMINATED 404L
// The file is not a cloud sync root.
ERROR_NOT_A_CLOUD_SYNC_ROOT      405L
// The read or write operation to an encrypted file could not be completed because the file can only be accessed when the device is unlocked.
ERROR_FILE_PROTECTED_UNDER_DPL   406L
// The volume is not cluster aligned on the disk.
ERROR_VOLUME_NOT_CLUSTER_ALIGNED 407L
// No physically aligned free space was found on the volume.
ERROR_NO_PHYSICALLY_ALIGNED_FREE_SPACE_FOUND 408L
// The APPX file can not be accessed because it is not encrypted as expected.
ERROR_APPX_FILE_NOT_ENCRYPTED    409L
// A read or write of raw encrypted data cannot be performed because the file is not encrypted.
ERROR_RWRAW_ENCRYPTED_FILE_NOT_ENCRYPTED 410L
// An invalid file offset in the encrypted data info block was passed for read or write operation of file's raw encrypted data.
ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILEOFFSET 411L
// An invalid offset and length combination in the encrypted data info block was passed for read or write operation of file's raw encrypted data.
ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILERANGE 412L
// An invalid parameter in the encrypted data info block was passed for read or write operation of file's raw encrypted data.
ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_PARAMETER 413L
// The Windows Subsystem for Linux has not been enabled.
ERROR_LINUX_SUBSYSTEM_NOT_PRESENT 414L
// The specified data could not be read from any of the copies.
ERROR_FT_READ_FAILURE            415L
// The specified storage reserve ID is invalid.
ERROR_STORAGE_RESERVE_ID_INVALID 416L
// The specified storage reserve does not exist.
ERROR_STORAGE_RESERVE_DOES_NOT_EXIST 417L
// The specified storage reserve already exists.
ERROR_STORAGE_RESERVE_ALREADY_EXISTS 418L
// The specified storage reserve is not empty.
ERROR_STORAGE_RESERVE_NOT_EMPTY  419L
// This operation requires a DAX volume.
ERROR_NOT_A_DAX_VOLUME           420L
// This stream is not DAX mappable.
ERROR_NOT_DAX_MAPPABLE           421L
// Operation cannot be performed on a time critical thread.
ERROR_TIME_SENSITIVE_THREAD      422L
// User data protection is not supported for the current or provided user.
ERROR_DPL_NOT_SUPPORTED_FOR_USER 423L
// This directory contains entries whose names differ only in case.
ERROR_CASE_DIFFERING_NAMES_IN_DIR 424L
// The file cannot be safely opened because it is not supported by this version of Windows.
ERROR_FILE_NOT_SUPPORTED         425L
// The cloud operation was not completed before the time-out period expired.
ERROR_CLOUD_FILE_REQUEST_TIMEOUT 426L
// A task queue is required for this operation but none is available.
ERROR_NO_TASK_QUEUE              427L
// Failed loading a valid version of srcsrv.dll.
ERROR_SRC_SRV_DLL_LOAD_FAILED    428L
// This operation is not supported with BTT enabled.
ERROR_NOT_SUPPORTED_WITH_BTT     429L
// This operation cannot be performed because encryption is currently disabled.
ERROR_ENCRYPTION_DISABLED        430L
// This encryption operation cannot be performed on filesystem metadata.
ERROR_ENCRYPTING_METADATA_DISALLOWED 431L
// Encryption cannot be cleared on this file/directory because it still has an encrypted attribute.
ERROR_CANT_CLEAR_ENCRYPTION_FLAG 432L
// A device which does not exist was specified.
ERROR_NO_SUCH_DEVICE             433L

// Neither developer unlocked mode nor side loading mode is enabled on the device.
ERROR_CAPAUTHZ_NOT_DEVUNLOCKED   450L
// Can not change application type during upgrade or re-provision.
ERROR_CAPAUTHZ_CHANGE_TYPE       451L
// The application has not been provisioned.
ERROR_CAPAUTHZ_NOT_PROVISIONED   452L
// The requested capability can not be authorized for this application.
ERROR_CAPAUTHZ_NOT_AUTHORIZED    453L
// There is no capability authorization policy on the device.
ERROR_CAPAUTHZ_NO_POLICY         454L
// The capability authorization database has been corrupted.
ERROR_CAPAUTHZ_DB_CORRUPTED      455L
// The custom capability's SCCD has an invalid catalog.
ERROR_CAPAUTHZ_SCCD_INVALID_CATALOG 456L
// None of the authorized entity elements in the SCCD matched the app being installed; either the PFNs don't match, or the element's signature hash doesn't validate.
ERROR_CAPAUTHZ_SCCD_NO_AUTH_ENTITY 457L
// The custom capability's SCCD failed to parse.
ERROR_CAPAUTHZ_SCCD_PARSE_ERROR  458L
// The custom capability's SCCD requires developer mode.
ERROR_CAPAUTHZ_SCCD_DEV_MODE_REQUIRED 459L
// There not all declared custom capabilities are found in the SCCD.
ERROR_CAPAUTHZ_SCCD_NO_CAPABILITY_MATCH 460L
// **** Available SYSTEM error codes ****
// The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in its device stack. The system may need to be rebooted to complete the request.
ERROR_PNP_QUERY_REMOVE_DEVICE_TIMEOUT 480L
// The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in the device stack of a related device. The system may need to be rebooted to complete the operation.
ERROR_PNP_QUERY_REMOVE_RELATED_DEVICE_TIMEOUT 481L
// The operation timed out waiting for this device to complete a PnP query-remove request due to a potential hang in the device stack of an unrelated device. The system may need to be rebooted to complete the operation.
ERROR_PNP_QUERY_REMOVE_UNRELATED_DEVICE_TIMEOUT 482L
// The request failed due to a fatal device hardware error.
ERROR_DEVICE_HARDWARE_ERROR      483L
// Attempt to access invalid address.
ERROR_INVALID_ADDRESS            487L
// Driver Verifier Volatile settings cannot be set when CFG is enabled.
ERROR_VRF_CFG_ENABLED            1183L
// An attempt was made to access a partition that has begun termination.
ERROR_PARTITION_TERMINATING      1184L
// User profile cannot be loaded.
ERROR_USER_PROFILE_LOAD          500L
// **** Available SYSTEM error codes ****
// Arithmetic result exceeded 32 bits.
ERROR_ARITHMETIC_OVERFLOW        534L
// There is a process on other end of the pipe.
ERROR_PIPE_CONNECTED             535L
// Waiting for a process to open the other end of the pipe.
ERROR_PIPE_LISTENING             536L
// Application verifier has found an error in the current process.
ERROR_VERIFIER_STOP              537L
// An error occurred in the ABIOS subsystem.
ERROR_ABIOS_ERROR                538L
// A warning occurred in the WX86 subsystem.
ERROR_WX86_WARNING               539L
// An error occurred in the WX86 subsystem.
ERROR_WX86_ERROR                 540L
// An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.
ERROR_TIMER_NOT_CANCELED         541L
// Unwind exception code.
ERROR_UNWIND                     542L
// An invalid or unaligned stack was encountered during an unwind operation.
ERROR_BAD_STACK                  543L
// An invalid unwind target was encountered during an unwind operation.
ERROR_INVALID_UNWIND_TARGET      544L
// Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort
ERROR_INVALID_PORT_ATTRIBUTES    545L
// Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.
ERROR_PORT_MESSAGE_TOO_LONG      546L
// An attempt was made to lower a quota limit below the current usage.
ERROR_INVALID_QUOTA_LOWER        547L
// An attempt was made to attach to a device that was already attached to another device.
ERROR_DEVICE_ALREADY_ATTACHED    548L
// An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.
ERROR_INSTRUCTION_MISALIGNMENT   549L
// Profiling not started.
ERROR_PROFILING_NOT_STARTED      550L
// Profiling not stopped.
ERROR_PROFILING_NOT_STOPPED      551L
// The passed ACL did not contain the minimum required information.
ERROR_COULD_NOT_INTERPRET        552L
// The number of active profiling objects is at the maximum and no more may be started.
ERROR_PROFILING_AT_LIMIT         553L
// Used to indicate that an operation cannot continue without blocking for I/O.
ERROR_CANT_WAIT                  554L
// Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.
ERROR_CANT_TERMINATE_SELF        555L
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
// In this case information is lost, however, the filter correctly handles the exception.
ERROR_UNEXPECTED_MM_CREATE_ERR   556L
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
// In this case information is lost, however, the filter correctly handles the exception.
ERROR_UNEXPECTED_MM_MAP_ERROR    557L
// If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter.
// In this case information is lost, however, the filter correctly handles the exception.
ERROR_UNEXPECTED_MM_EXTEND_ERR   558L
// A malformed function table was encountered during an unwind operation.
ERROR_BAD_FUNCTION_TABLE         559L
// Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system.
// This causes the protection attempt to fail, which may cause a file creation attempt to fail.
ERROR_NO_GUID_TRANSLATION        560L
// Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.
ERROR_INVALID_LDT_SIZE           561L
// Indicates that the starting value for the LDT information was not an integral multiple of the selector size.
ERROR_INVALID_LDT_OFFSET         563L
// Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.
ERROR_INVALID_LDT_DESCRIPTOR     564L
// Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.
ERROR_TOO_MANY_THREADS           565L
// An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.
ERROR_THREAD_NOT_IN_PROCESS      566L
// Page file quota was exceeded.
ERROR_PAGEFILE_QUOTA_EXCEEDED    567L
// The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.
ERROR_LOGON_SERVER_CONFLICT      568L
// The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.
ERROR_SYNCHRONIZATION_REQUIRED   569L
// The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.
ERROR_NET_OPEN_FAILED            570L
// {Privilege Failed}
// The I/O permissions for the process could not be changed.
ERROR_IO_PRIVILEGE_FAILED        571L
// {Application Exit by CTRL+C}
// The application terminated as a result of a CTRL+C.
ERROR_CONTROL_C_EXIT             572L    // winnt
// {Missing System File}
// The required system file %hs is bad or missing.
ERROR_MISSING_SYSTEMFILE         573L
// {Application Error}
// The exception %s (0x%08lx) occurred in the application at location 0x%08lx.
ERROR_UNHANDLED_EXCEPTION        574L
// {Application Error}
// The application was unable to start correctly (0x%lx). Click OK to close the application.
ERROR_APP_INIT_FAILURE           575L
// {Unable to Create Paging File}
// The creation of the paging file %hs failed (%lx). The requested size was %ld.
ERROR_PAGEFILE_CREATE_FAILED     576L
// Windows cannot verify the digital signature for this file. A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.
ERROR_INVALID_IMAGE_HASH         577L
// {No Paging File Specified}
// No paging file was specified in the system configuration.
ERROR_NO_PAGEFILE                578L
// {EXCEPTION}
// A real-mode application issued a floating-point instruction and floating-point hardware is not present.
ERROR_ILLEGAL_FLOAT_CONTEXT      579L
// An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.
ERROR_NO_EVENT_PAIR              580L
// A Windows Server has an incorrect configuration.
ERROR_DOMAIN_CTRLR_CONFIG_ERROR  581L
// An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.
ERROR_ILLEGAL_CHARACTER          582L
// The Unicode character is not defined in the Unicode character set installed on the system.
ERROR_UNDEFINED_CHARACTER        583L
// The paging file cannot be created on a floppy diskette.
ERROR_FLOPPY_VOLUME              584L
// The system BIOS failed to connect a system interrupt to the device or bus for which the device is connected.
ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT 585L
// This operation is only allowed for the Primary Domain Controller of the domain.
ERROR_BACKUP_CONTROLLER          586L
// An attempt was made to acquire a mutant such that its maximum count would have been exceeded.
ERROR_MUTANT_LIMIT_EXCEEDED      587L
// A volume has been accessed for which a file system driver is required that has not yet been loaded.
ERROR_FS_DRIVER_REQUIRED         588L
// The registry cannot load the hive (file) or its log or alternate. It is corrupt, absent, or not writable.
ERROR_CANNOT_LOAD_REGISTRY_FILE  589L
// {Unexpected Failure in DebugActiveProcess}
// An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.
ERROR_DEBUG_ATTACH_FAILED        590L
// The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x).
ERROR_SYSTEM_PROCESS_TERMINATED  591L
// {Data Not Accepted}
// The TDI client could not handle the data received during an indication.
ERROR_DATA_NOT_ACCEPTED          592L
// NTVDM encountered a hard error.
ERROR_VDM_HARD_ERROR             593L
// {Cancel Timeout}
// The driver %hs failed to complete a cancelled I/O request in the allotted time.
ERROR_DRIVER_CANCEL_TIMEOUT      594L
// {Reply Message Mismatch}
// An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.
ERROR_REPLY_MESSAGE_MISMATCH     595L
// {Delayed Write Failed}
// Windows was unable to save all the data for the file %hs. The data has been lost.
// This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.
ERROR_LOST_WRITEBEHIND_DATA      596L
// The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.
ERROR_CLIENT_SERVER_PARAMETERS_INVALID 597L
// The stream is not a tiny stream.
ERROR_NOT_TINY_STREAM            598L
// The request must be handled by the stack overflow code.
ERROR_STACK_OVERFLOW_READ        599L
// Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.
ERROR_CONVERT_TO_LARGE           600L
// The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.
ERROR_FOUND_OUT_OF_SCOPE         601L
// The bucket array must be grown. Retry transaction after doing so.
ERROR_ALLOCATE_BUCKET            602L
// The user/kernel marshalling buffer has overflowed.
ERROR_MARSHALL_OVERFLOW          603L
// The supplied variant structure contains invalid data.
ERROR_INVALID_VARIANT            604L
// The specified buffer contains ill-formed data.
ERROR_BAD_COMPRESSION_BUFFER     605L
// {Audit Failed}
// An attempt to generate a security audit failed.
ERROR_AUDIT_FAILED               606L
// The timer resolution was not previously set by the current process.
ERROR_TIMER_RESOLUTION_NOT_SET   607L
// There is insufficient account information to log you on.
ERROR_INSUFFICIENT_LOGON_INFO    608L
// {Invalid DLL Entrypoint}
// The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state.
// The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.
ERROR_BAD_DLL_ENTRYPOINT         609L
// {Invalid Service Callback Entrypoint}
// The %hs service is not written correctly. The stack pointer has been left in an inconsistent state.
// The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.
ERROR_BAD_SERVICE_ENTRYPOINT     610L
// There is an IP address conflict with another system on the network
ERROR_IP_ADDRESS_CONFLICT1       611L
// There is an IP address conflict with another system on the network
ERROR_IP_ADDRESS_CONFLICT2       612L
// {Low On Registry Space}
// The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.
ERROR_REGISTRY_QUOTA_LIMIT       613L
// A callback return system service cannot be executed when no callback is active.
ERROR_NO_CALLBACK_ACTIVE         614L
// The password provided is too short to meet the policy of your user account.
// Please choose a longer password.
ERROR_PWD_TOO_SHORT              615L
// The policy of your user account does not allow you to change passwords too frequently.
// This is done to prevent users from changing back to a familiar, but potentially discovered, password.
// If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.
ERROR_PWD_TOO_RECENT             616L
// You have attempted to change your password to one that you have used in the past.
// The policy of your user account does not allow this. Please select a password that you have not previously used.
ERROR_PWD_HISTORY_CONFLICT       617L
// The specified compression format is unsupported.
ERROR_UNSUPPORTED_COMPRESSION    618L
// The specified hardware profile configuration is invalid.
ERROR_INVALID_HW_PROFILE         619L
// The specified Plug and Play registry device path is invalid.
ERROR_INVALID_PLUGPLAY_DEVICE_PATH 620L
// The specified quota list is internally inconsistent with its descriptor.
ERROR_QUOTA_LIST_INCONSISTENT    621L
// {Windows Evaluation Notification}
// The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.
ERROR_EVALUATION_EXPIRATION      622L
// {Illegal System DLL Relocation}
// The system DLL %hs was relocated in memory. The application will not run properly.
// The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL.
ERROR_ILLEGAL_DLL_RELOCATION     623L
// {DLL Initialization Failed}
// The application failed to initialize because the window station is shutting down.
ERROR_DLL_INIT_FAILED_LOGOFF     624L
// The validation process needs to continue on to the next step.
ERROR_VALIDATE_CONTINUE          625L
// There are no more matches for the current index enumeration.
ERROR_NO_MORE_MATCHES            626L
// The range could not be added to the range list because of a conflict.
ERROR_RANGE_LIST_CONFLICT        627L
// The server process is running under a SID different than that required by client.
ERROR_SERVER_SID_MISMATCH        628L
// A group marked use for deny only cannot be enabled.
ERROR_CANT_ENABLE_DENY_ONLY      629L
// {EXCEPTION}
// Multiple floating point faults.
ERROR_FLOAT_MULTIPLE_FAULTS      630L    // winnt
// {EXCEPTION}
// Multiple floating point traps.
ERROR_FLOAT_MULTIPLE_TRAPS       631L    // winnt
// The requested interface is not supported.
ERROR_NOINTERFACE                632L
// {System Standby Failed}
// The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.
ERROR_DRIVER_FAILED_SLEEP        633L
// The system file %1 has become corrupt and has been replaced.
ERROR_CORRUPT_SYSTEM_FILE        634L
// {Virtual Memory Minimum Too Low}
// Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file.
// During this process, memory requests for some applications may be denied. For more information, see Help.
ERROR_COMMITMENT_MINIMUM         635L
// A device was removed so enumeration must be restarted.
ERROR_PNP_RESTART_ENUMERATION    636L
// {Fatal System Error}
// The system image %s is not properly signed.
// The file has been replaced with the signed file.
// The system has been shut down.
ERROR_SYSTEM_IMAGE_BAD_SIGNATURE 637L
// Device will not start without a reboot.
ERROR_PNP_REBOOT_REQUIRED        638L
// There is not enough power to complete the requested operation.
ERROR_INSUFFICIENT_POWER         639L
//  ERROR_MULTIPLE_FAULT_VIOLATION
ERROR_MULTIPLE_FAULT_VIOLATION   640L
// The system is in the process of shutting down.
ERROR_SYSTEM_SHUTDOWN            641L
// An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.
ERROR_PORT_NOT_SET               642L
// This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.
ERROR_DS_VERSION_CHECK_FAILURE   643L
// The specified range could not be found in the range list.
ERROR_RANGE_NOT_FOUND            644L
// The driver was not loaded because the system is booting into safe mode.
ERROR_NOT_SAFE_MODE_DRIVER       646L
// The driver was not loaded because it failed its initialization call.
ERROR_FAILED_DRIVER_ENTRY        647L
// The "%hs" encountered an error while applying power or reading the device configuration.
// This may be caused by a failure of your hardware or by a poor connection.
ERROR_DEVICE_ENUMERATION_ERROR   648L
// The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.
ERROR_MOUNT_POINT_NOT_RESOLVED   649L
// The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.
ERROR_INVALID_DEVICE_OBJECT_PARAMETER 650L
// A Machine Check Error has occurred. Please check the system eventlog for additional information.
ERROR_MCA_OCCURED                651L
// There was error [%2] processing the driver database.
ERROR_DRIVER_DATABASE_ERROR      652L
// System hive size has exceeded its limit.
ERROR_SYSTEM_HIVE_TOO_LARGE      653L
// The driver could not be loaded because a previous version of the driver is still in memory.
ERROR_DRIVER_FAILED_PRIOR_UNLOAD 654L
// {Volume Shadow Copy Service}
// Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.
ERROR_VOLSNAP_PREPARE_HIBERNATE  655L
// The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.
ERROR_HIBERNATION_FAILURE        656L
// The password provided is too long to meet the policy of your user account.
// Please choose a shorter password.
ERROR_PWD_TOO_LONG               657L
// The requested operation could not be completed due to a file system limitation
ERROR_FILE_SYSTEM_LIMITATION     665L
// An assertion failure has occurred.
ERROR_ASSERTION_FAILURE          668L
// An error occurred in the ACPI subsystem.
ERROR_ACPI_ERROR                 669L
// WOW Assertion Error.
ERROR_WOW_ASSERTION              670L
// A device is missing in the system BIOS MPS table. This device will not be used.
// Please contact your system vendor for system BIOS update.
ERROR_PNP_BAD_MPS_TABLE          671L
// A translator failed to translate resources.
ERROR_PNP_TRANSLATION_FAILED     672L
// A IRQ translator failed to translate resources.
ERROR_PNP_IRQ_TRANSLATION_FAILED 673L
// Driver %2 returned invalid ID for a child device (%3).
ERROR_PNP_INVALID_ID             674L
// {Kernel Debugger Awakened}
// the system debugger was awakened by an interrupt.
ERROR_WAKE_SYSTEM_DEBUGGER       675L
// {Handles Closed}
// Handles to objects have been automatically closed as a result of the requested operation.
ERROR_HANDLES_CLOSED             676L
// {Too Much Information}
// The specified access control list (ACL) contained more information than was expected.
ERROR_EXTRANEOUS_INFORMATION     677L
// This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.
// The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).
ERROR_RXACT_COMMIT_NECESSARY     678L
// {Media Changed}
// The media may have changed.
ERROR_MEDIA_CHECK                679L
// {GUID Substitution}
// During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found.
// A substitute prefix was used, which will not compromise system security. However, this may provide a more restrictive access than intended.
ERROR_GUID_SUBSTITUTION_MADE     680L
// The create operation stopped after reaching a symbolic link
ERROR_STOPPED_ON_SYMLINK         681L
// A long jump has been executed.
ERROR_LONGJUMP                   682L
// The Plug and Play query operation was not successful.
ERROR_PLUGPLAY_QUERY_VETOED      683L
// A frame consolidation has been executed.
ERROR_UNWIND_CONSOLIDATE         684L
// Registry hive (file) %hs was corrupted and it has been recovered. Some data might have been lost.
ERROR_REGISTRY_HIVE_RECOVERED    685L
// The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?
ERROR_DLL_MIGHT_BE_INSECURE      686L
// The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?
ERROR_DLL_MIGHT_BE_INCOMPATIBLE  687L
// Debugger did not handle the exception.
ERROR_DBG_EXCEPTION_NOT_HANDLED  688L 
// Debugger will reply later.
ERROR_DBG_REPLY_LATER            689L
// Debugger cannot provide handle.
ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE 690L
// Debugger terminated thread.
ERROR_DBG_TERMINATE_THREAD       691L    // winnt
// Debugger terminated process.
ERROR_DBG_TERMINATE_PROCESS      692L    // winnt
// Debugger got control C.
ERROR_DBG_CONTROL_C              693L    // winnt
// Debugger printed exception on control C.
ERROR_DBG_PRINTEXCEPTION_C       694L
// Debugger received RIP exception.
ERROR_DBG_RIPEXCEPTION           695L
// Debugger received control break.
ERROR_DBG_CONTROL_BREAK          696L    // winnt
// Debugger command communication exception.
ERROR_DBG_COMMAND_EXCEPTION      697L    // winnt
// {Object Exists}
// An attempt was made to create an object and the object name already existed.
ERROR_OBJECT_NAME_EXISTS         698L
// {Thread Suspended}
// A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.
ERROR_THREAD_WAS_SUSPENDED       699L
// {Image Relocated}
// An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.
ERROR_IMAGE_NOT_AT_BASE          700L
// This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.
ERROR_RXACT_STATE_CREATED        701L
// {Segment Load}
// A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image.
// An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.
ERROR_SEGMENT_NOTIFICATION       702L    // winnt
// {Invalid Current Directory}
// The process cannot switch to the startup current directory %hs.
// Select OK to set current directory to %hs, or select CANCEL to exit.
ERROR_BAD_CURRENT_DIRECTORY      703L
// {Redundant Read}
// To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy.
// This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.
ERROR_FT_READ_RECOVERY_FROM_BACKUP 704L
// {Redundant Write}
// To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information.
// This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.
ERROR_FT_WRITE_RECOVERY          705L
// {Machine Type Mismatch}
// The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.
ERROR_IMAGE_MACHINE_TYPE_MISMATCH 706L
// {Partial Data Received}
// The network transport returned partial data to its client. The remaining data will be sent later.
ERROR_RECEIVE_PARTIAL            707L
// {Expedited Data Received}
// The network transport returned data to its client that was marked as expedited by the remote system.
ERROR_RECEIVE_EXPEDITED          708L
// {Partial Expedited Data Received}
// The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.
ERROR_RECEIVE_PARTIAL_EXPEDITED  709L
// {TDI Event Done}
// The TDI indication has completed successfully.
ERROR_EVENT_DONE                 710L
// {TDI Event Pending}
// The TDI indication has entered the pending state.
ERROR_EVENT_PENDING              711L
// Checking file system on %wZ
ERROR_CHECKING_FILE_SYSTEM       712L
// {Fatal Application Exit}
// %hs
ERROR_FATAL_APP_EXIT             713L
// The specified registry key is referenced by a predefined handle.
ERROR_PREDEFINED_HANDLE          714L
// {Page Unlocked}
// The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.
ERROR_WAS_UNLOCKED               715L
// %hs
ERROR_SERVICE_NOTIFICATION       716L
// {Page Locked}
// One of the pages to lock was already locked.
ERROR_WAS_LOCKED                 717L
// Application popup: %1 : %2
ERROR_LOG_HARD_ERROR             718L
//  ERROR_ALREADY_WIN32
ERROR_ALREADY_WIN32              719L
// {Machine Type Mismatch}
// The image file %hs is valid, but is for a machine type other than the current machine.
ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE 720L
// A yield execution was performed and no thread was available to run.
ERROR_NO_YIELD_PERFORMED         721L
// The resumable flag to a timer API was ignored.
ERROR_TIMER_RESUME_IGNORED       722L
// The arbiter has deferred arbitration of these resources to its parent
ERROR_ARBITRATION_UNHANDLED      723L
// The inserted CardBus device cannot be started because of a configuration error on "%hs".
ERROR_CARDBUS_NOT_SUPPORTED      724L
// The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.
ERROR_MP_PROCESSOR_MISMATCH      725L
// The system was put into hibernation.
ERROR_HIBERNATED                 726L    
// The system was resumed from hibernation.
ERROR_RESUME_HIBERNATION         727L    
// Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].
ERROR_FIRMWARE_UPDATED           728L
// A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.
ERROR_DRIVERS_LEAKING_LOCKED_PAGES 729L
// The system has awoken
ERROR_WAKE_SYSTEM                730L
//  ERROR_WAIT_1
ERROR_WAIT_1                     731L
//  ERROR_WAIT_2
ERROR_WAIT_2                     732L
//  ERROR_WAIT_3
ERROR_WAIT_3                     733L
//  ERROR_WAIT_63
ERROR_WAIT_63                    734L
//  ERROR_ABANDONED_WAIT_0
ERROR_ABANDONED_WAIT_0           735L    // winnt
//  ERROR_ABANDONED_WAIT_63
ERROR_ABANDONED_WAIT_63          736L
//  ERROR_USER_APC
ERROR_USER_APC                   737L    // winnt
//  ERROR_KERNEL_APC
ERROR_KERNEL_APC                 738L
//  ERROR_ALERTED
ERROR_ALERTED                    739L
// The requested operation requires elevation.
ERROR_ELEVATION_REQUIRED         740L
// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
ERROR_REPARSE                    741L
// An open/create operation completed while an oplock break is underway.
ERROR_OPLOCK_BREAK_IN_PROGRESS   742L
// A new volume has been mounted by a file system.
ERROR_VOLUME_MOUNTED             743L
// This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted.
// The commit has now been completed.
ERROR_RXACT_COMMITTED            744L
// This indicates that a notify change request has been completed due to closing the handle which made the notify change request.
ERROR_NOTIFY_CLEANUP             745L
// {Connect Failure on Primary Transport}
// An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed.
// The computer WAS able to connect on a secondary transport.
ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED 746L
// Page fault was a transition fault.
ERROR_PAGE_FAULT_TRANSITION      747L
// Page fault was a demand zero fault.
ERROR_PAGE_FAULT_DEMAND_ZERO     748L
// Page fault was a demand zero fault.
ERROR_PAGE_FAULT_COPY_ON_WRITE   749L
// Page fault was a demand zero fault.
ERROR_PAGE_FAULT_GUARD_PAGE      750L
// Page fault was satisfied by reading from a secondary storage device.
ERROR_PAGE_FAULT_PAGING_FILE     751L
// Cached page was locked during operation.
ERROR_CACHE_PAGE_LOCKED          752L
// Crash dump exists in paging file.
ERROR_CRASH_DUMP                 753L
// Specified buffer contains all zeros.
ERROR_BUFFER_ALL_ZEROS           754L
// A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
ERROR_REPARSE_OBJECT             755L
// The device has succeeded a query-stop and its resource requirements have changed.
ERROR_RESOURCE_REQUIREMENTS_CHANGED 756L
// The translator has translated these resources into the global space and no further translations should be performed.
ERROR_TRANSLATION_COMPLETE       757L
// A process being terminated has no threads to terminate.
ERROR_NOTHING_TO_TERMINATE       758L
// The specified process is not part of a job.
ERROR_PROCESS_NOT_IN_JOB         759L
// The specified process is part of a job.
ERROR_PROCESS_IN_JOB             760L
// {Volume Shadow Copy Service}
// The system is now ready for hibernation.
ERROR_VOLSNAP_HIBERNATE_READY    761L
// A file system or file system filter driver has successfully completed an FsFilter operation.
ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY 762L
// The specified interrupt vector was already connected.
ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED 763L
// The specified interrupt vector is still connected.
ERROR_INTERRUPT_STILL_CONNECTED  764L
// An operation is blocked waiting for an oplock.
ERROR_WAIT_FOR_OPLOCK            765L
// Debugger handled exception
ERROR_DBG_EXCEPTION_HANDLED      766L    // winnt
// Debugger continued
ERROR_DBG_CONTINUE               767L    // winnt
// An exception occurred in a user mode callback and the kernel callback frame should be removed.
ERROR_CALLBACK_POP_STACK         768L
// Compression is disabled for this volume.
ERROR_COMPRESSION_DISABLED       769L
// The data provider cannot fetch backwards through a result set.
ERROR_CANTFETCHBACKWARDS         770L
// The data provider cannot scroll backwards through a result set.
ERROR_CANTSCROLLBACKWARDS        771L
// The data provider requires that previously fetched data is released before asking for more data.
ERROR_ROWSNOTRELEASED            772L
// The data provider was not able to interpret the flags set for a column binding in an accessor.
ERROR_BAD_ACCESSOR_FLAGS         773L
// One or more errors occurred while processing the request.
ERROR_ERRORS_ENCOUNTERED         774L
// The implementation is not capable of performing the request.
ERROR_NOT_CAPABLE                775L
// The client of a component requested an operation which is not valid given the state of the component instance.
ERROR_REQUEST_OUT_OF_SEQUENCE    776L
// A version number could not be parsed.
ERROR_VERSION_PARSE_ERROR        777L
// The iterator's start position is invalid.
ERROR_BADSTARTPOSITION           778L
// The hardware has reported an uncorrectable memory error.
ERROR_MEMORY_HARDWARE            779L
// The attempted operation required self healing to be enabled.
ERROR_DISK_REPAIR_DISABLED       780L
// The Desktop heap encountered an error while allocating session memory. There is more information in the system event log.
ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE 781L
// The system power state is transitioning from %2 to %3.
ERROR_SYSTEM_POWERSTATE_TRANSITION 782L
// The system power state is transitioning from %2 to %3 but could enter %4.
ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION 783L
// A thread is getting dispatched with MCA EXCEPTION because of MCA.
ERROR_MCA_EXCEPTION              784L
// Access to %1 is monitored by policy rule %2.
ERROR_ACCESS_AUDIT_BY_POLICY     785L
// Access to %1 has been restricted by your Administrator by policy rule %2.
ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY 786L
// A valid hibernation file has been invalidated and should be abandoned.
ERROR_ABANDON_HIBERFILE          787L
// {Delayed Write Failed}
// Windows was unable to save all the data for the file %hs; the data has been lost.
// This error may be caused by network connectivity issues. Please try to save this file elsewhere.
ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED 788L
// {Delayed Write Failed}
// Windows was unable to save all the data for the file %hs; the data has been lost.
// This error was returned by the server on which the file exists. Please try to save this file elsewhere.
ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR 789L
// {Delayed Write Failed}
// Windows was unable to save all the data for the file %hs; the data has been lost.
// This error may be caused if the device has been removed or the media is write-protected.
ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR 790L
// The resources required for this device conflict with the MCFG table.
ERROR_BAD_MCFG_TABLE             791L
// The volume repair could not be performed while it is online.
// Please schedule to take the volume offline so that it can be repaired.
ERROR_DISK_REPAIR_REDIRECTED     792L
// The volume repair was not successful.
ERROR_DISK_REPAIR_UNSUCCESSFUL   793L
// One of the volume corruption logs is full. Further corruptions that may be detected won't be logged.
ERROR_CORRUPT_LOG_OVERFULL       794L
// One of the volume corruption logs is internally corrupted and needs to be recreated. The volume may contain undetected corruptions and must be scanned.
ERROR_CORRUPT_LOG_CORRUPTED      795L
// One of the volume corruption logs is unavailable for being operated on.
ERROR_CORRUPT_LOG_UNAVAILABLE    796L
// One of the volume corruption logs was deleted while still having corruption records in them. The volume contains detected corruptions and must be scanned.
ERROR_CORRUPT_LOG_DELETED_FULL   797L
// One of the volume corruption logs was cleared by chkdsk and no longer contains real corruptions.
ERROR_CORRUPT_LOG_CLEARED        798L
// Orphaned files exist on the volume but could not be recovered because no more new names could be created in the recovery directory. Files must be moved from the recovery directory.
ERROR_ORPHAN_NAME_EXHAUSTED      799L
// The oplock that was associated with this handle is now associated with a different handle.
ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE 800L
// An oplock of the requested level cannot be granted.  An oplock of a lower level may be available.
ERROR_CANNOT_GRANT_REQUESTED_OPLOCK 801L
// The operation did not complete successfully because it would cause an oplock to be broken. The caller has requested that existing oplocks not be broken.
ERROR_CANNOT_BREAK_OPLOCK        802L
// The handle with which this oplock was associated has been closed.  The oplock is now broken.
ERROR_OPLOCK_HANDLE_CLOSED       803L
// The specified access control entry (ACE) does not contain a condition.
ERROR_NO_ACE_CONDITION           804L
// The specified access control entry (ACE) contains an invalid condition.
ERROR_INVALID_ACE_CONDITION      805L
// Access to the specified file handle has been revoked.
ERROR_FILE_HANDLE_REVOKED        806L
// {Image Relocated}
// An image file was mapped at a different address from the one specified in the image file but fixups will still be automatically performed on the image.
ERROR_IMAGE_AT_DIFFERENT_BASE    807L
// The read or write operation to an encrypted file could not be completed because the file has not been opened for data access.
ERROR_ENCRYPTED_IO_NOT_POSSIBLE  808L
// File metadata optimization is already in progress.
ERROR_FILE_METADATA_OPTIMIZATION_IN_PROGRESS 809L
// The requested operation failed due to quota operation is still in progress.
ERROR_QUOTA_ACTIVITY             810L
// Access to the specified handle has been revoked.
ERROR_HANDLE_REVOKED             811L
// The callback function must be invoked inline.
ERROR_CALLBACK_INVOKE_INLINE     812L
// The specified CPU Set IDs are invalid.
ERROR_CPU_SET_INVALID            813L
// The specified enclave has not yet been terminated.
ERROR_ENCLAVE_NOT_TERMINATED     814L
// An attempt was made to access protected memory in violation of its secure access policy.
ERROR_ENCLAVE_VIOLATION          815L
// **** Available SYSTEM error codes ****
// Access to the extended attribute was denied.
ERROR_EA_ACCESS_DENIED           994L
// The I/O operation has been aborted because of either a thread exit or an application request.
ERROR_OPERATION_ABORTED          995L
// Overlapped I/O event is not in a signaled state.
ERROR_IO_INCOMPLETE              996L
// Overlapped I/O operation is in progress.
ERROR_IO_PENDING                 997L    // dderror
// Invalid access to memory location.
ERROR_NOACCESS                   998L
// Error performing inpage operation.
ERROR_SWAPERROR                  999L
// Recursion too deep; the stack overflowed.
ERROR_STACK_OVERFLOW             1001L
// The window cannot act on the sent message.
ERROR_INVALID_MESSAGE            1002L
// Cannot complete this function.
ERROR_CAN_NOT_COMPLETE           1003L
// Invalid flags.
ERROR_INVALID_FLAGS              1004L
// The volume does not contain a recognized file system.
// Please make sure that all required file system drivers are loaded and that the volume is not corrupted.
ERROR_UNRECOGNIZED_VOLUME        1005L
// The volume for a file has been externally altered so that the opened file is no longer valid.
ERROR_FILE_INVALID               1006L
// The requested operation cannot be performed in full-screen mode.
ERROR_FULLSCREEN_MODE            1007L
// An attempt was made to reference a token that does not exist.
ERROR_NO_TOKEN                   1008L
// The configuration registry database is corrupt.
ERROR_BADDB                      1009L
// The configuration registry key is invalid.
ERROR_BADKEY                     1010L
// The configuration registry key could not be opened.
ERROR_CANTOPEN                   1011L
// The configuration registry key could not be read.
ERROR_CANTREAD                   1012L
// The configuration registry key could not be written.
ERROR_CANTWRITE                  1013L
// One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.
ERROR_REGISTRY_RECOVERED         1014L
// The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted.
ERROR_REGISTRY_CORRUPT           1015L
// An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.
ERROR_REGISTRY_IO_FAILED         1016L
// The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.
ERROR_NOT_REGISTRY_FILE          1017L
// Illegal operation attempted on a registry key that has been marked for deletion.
ERROR_KEY_DELETED                1018L
// System could not allocate the required space in a registry log.
ERROR_NO_LOG_SPACE               1019L
// Cannot create a symbolic link in a registry key that already has subkeys or values.
ERROR_KEY_HAS_CHILDREN           1020L
// Cannot create a stable subkey under a volatile parent key.
ERROR_CHILD_MUST_BE_VOLATILE     1021L
// A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes.
ERROR_NOTIFY_ENUM_DIR            1022L
// A stop control has been sent to a service that other running services are dependent on.
ERROR_DEPENDENT_SERVICES_RUNNING 1051L
// The requested control is not valid for this service.
ERROR_INVALID_SERVICE_CONTROL    1052L
// The service did not respond to the start or control request in a timely fashion.
ERROR_SERVICE_REQUEST_TIMEOUT    1053L
// A thread could not be created for the service.
ERROR_SERVICE_NO_THREAD          1054L
// The service database is locked.
ERROR_SERVICE_DATABASE_LOCKED    1055L
// An instance of the service is already running.
ERROR_SERVICE_ALREADY_RUNNING    1056L
// The account name is invalid or does not exist, or the password is invalid for the account name specified.
ERROR_INVALID_SERVICE_ACCOUNT    1057L
// The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.
ERROR_SERVICE_DISABLED           1058L
// Circular service dependency was specified.
ERROR_CIRCULAR_DEPENDENCY        1059L
// The specified service does not exist as an installed service.
ERROR_SERVICE_DOES_NOT_EXIST     1060L
// The service cannot accept control messages at this time.
ERROR_SERVICE_CANNOT_ACCEPT_CTRL 1061L
// The service has not been started.
ERROR_SERVICE_NOT_ACTIVE         1062L
// The service process could not connect to the service controller.
ERROR_FAILED_SERVICE_CONTROLLER_CONNECT 1063L
// An exception occurred in the service when handling the control request.
ERROR_EXCEPTION_IN_SERVICE       1064L
// The database specified does not exist.
ERROR_DATABASE_DOES_NOT_EXIST    1065L
// The service has returned a service-specific error code.
ERROR_SERVICE_SPECIFIC_ERROR     1066L
// The process terminated unexpectedly.
ERROR_PROCESS_ABORTED            1067L
// The dependency service or group failed to start.
ERROR_SERVICE_DEPENDENCY_FAIL    1068L
// The service did not start due to a logon failure.
ERROR_SERVICE_LOGON_FAILED       1069L
// After starting, the service hung in a start-pending state.
ERROR_SERVICE_START_HANG         1070L
// The specified service database lock is invalid.
ERROR_INVALID_SERVICE_LOCK       1071L
// The specified service has been marked for deletion.
ERROR_SERVICE_MARKED_FOR_DELETE  1072L
// The specified service already exists.
ERROR_SERVICE_EXISTS             1073L
// The system is currently running with the last-known-good configuration.
ERROR_ALREADY_RUNNING_LKG        1074L
// The dependency service does not exist or has been marked for deletion.
ERROR_SERVICE_DEPENDENCY_DELETED 1075L
// The current boot has already been accepted for use as the last-known-good control set.
ERROR_BOOT_ALREADY_ACCEPTED      1076L
// No attempts to start the service have been made since the last boot.
ERROR_SERVICE_NEVER_STARTED      1077L
// The name is already in use as either a service name or a service display name.
ERROR_DUPLICATE_SERVICE_NAME     1078L
// The account specified for this service is different from the account specified for other services running in the same process.
ERROR_DIFFERENT_SERVICE_ACCOUNT  1079L
// Failure actions can only be set for Win32 services, not for drivers.
ERROR_CANNOT_DETECT_DRIVER_FAILURE 1080L
// This service runs in the same process as the service control manager.
// Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.
ERROR_CANNOT_DETECT_PROCESS_ABORT 1081L
// No recovery program has been configured for this service.
ERROR_NO_RECOVERY_PROGRAM        1082L
// The executable program that this service is configured to run in does not implement the service.
ERROR_SERVICE_NOT_IN_EXE         1083L
// This service cannot be started in Safe Mode
ERROR_NOT_SAFEBOOT_SERVICE       1084L
// The physical end of the tape has been reached.
ERROR_END_OF_MEDIA               1100L
// A tape access reached a filemark.
ERROR_FILEMARK_DETECTED          1101L
// The beginning of the tape or a partition was encountered.
ERROR_BEGINNING_OF_MEDIA         1102L
// A tape access reached the end of a set of files.
ERROR_SETMARK_DETECTED           1103L
// No more data is on the tape.
ERROR_NO_DATA_DETECTED           1104L
// Tape could not be partitioned.
ERROR_PARTITION_FAILURE          1105L
// When accessing a new tape of a multivolume partition, the current block size is incorrect.
ERROR_INVALID_BLOCK_LENGTH       1106L
// Tape partition information could not be found when loading a tape.
ERROR_DEVICE_NOT_PARTITIONED     1107L
// Unable to lock the media eject mechanism.
ERROR_UNABLE_TO_LOCK_MEDIA       1108L
// Unable to unload the media.
ERROR_UNABLE_TO_UNLOAD_MEDIA     1109L
// The media in the drive may have changed.
ERROR_MEDIA_CHANGED              1110L
// The I/O bus was reset.
ERROR_BUS_RESET                  1111L
// No media in drive.
ERROR_NO_MEDIA_IN_DRIVE          1112L
// No mapping for the Unicode character exists in the target multi-byte code page.
ERROR_NO_UNICODE_TRANSLATION     1113L
// A dynamic link library (DLL) initialization routine failed.
ERROR_DLL_INIT_FAILED            1114L
// A system shutdown is in progress.
ERROR_SHUTDOWN_IN_PROGRESS       1115L
// Unable to abort the system shutdown because no shutdown was in progress.
ERROR_NO_SHUTDOWN_IN_PROGRESS    1116L
// The request could not be performed because of an I/O device error.
ERROR_IO_DEVICE                  1117L
// No serial device was successfully initialized. The serial driver will unload.
ERROR_SERIAL_NO_DEVICE           1118L
// Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened.
ERROR_IRQ_BUSY                   1119L
// A serial I/O operation was completed by another write to the serial port.
// (The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
ERROR_MORE_WRITES                1120L
// A serial I/O operation completed because the timeout period expired.
// (The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)
ERROR_COUNTER_TIMEOUT            1121L
// No ID address mark was found on the floppy disk.
ERROR_FLOPPY_ID_MARK_NOT_FOUND   1122L
// Mismatch between the floppy disk sector ID field and the floppy disk controller track address.
ERROR_FLOPPY_WRONG_CYLINDER      1123L
// The floppy disk controller reported an error that is not recognized by the floppy disk driver.
ERROR_FLOPPY_UNKNOWN_ERROR       1124L
// The floppy disk controller returned inconsistent results in its registers.
ERROR_FLOPPY_BAD_REGISTERS       1125L
// While accessing the hard disk, a recalibrate operation failed, even after retries.
ERROR_DISK_RECALIBRATE_FAILED    1126L
// While accessing the hard disk, a disk operation failed even after retries.
ERROR_DISK_OPERATION_FAILED      1127L
// While accessing the hard disk, a disk controller reset was needed, but even that failed.
ERROR_DISK_RESET_FAILED          1128L
// Physical end of tape encountered.
ERROR_EOM_OVERFLOW               1129L
// Not enough server memory resources are available to process this command.
ERROR_NOT_ENOUGH_SERVER_MEMORY   1130L
// A potential deadlock condition has been detected.
ERROR_POSSIBLE_DEADLOCK          1131L
// The base address or the file offset specified does not have the proper alignment.
ERROR_MAPPED_ALIGNMENT           1132L
// An attempt to change the system power state was vetoed by another application or driver.
ERROR_SET_POWER_STATE_VETOED     1140L
// The system BIOS failed an attempt to change the system power state.
ERROR_SET_POWER_STATE_FAILED     1141L
// An attempt was made to create more links on a file than the file system supports.
ERROR_TOO_MANY_LINKS             1142L




// The specified program requires a newer version of Windows.

ERROR_OLD_WIN_VERSION            1150L






// The specified program is not a Windows or MS-DOS program.

ERROR_APP_WRONG_OS               1151L






// Cannot start more than one instance of the specified program.

ERROR_SINGLE_INSTANCE_APP        1152L






// The specified program was written for an earlier version of Windows.

ERROR_RMODE_APP                  1153L






// One of the library files needed to run this application is damaged.

ERROR_INVALID_DLL                1154L






// No application is associated with the specified file for this operation.

ERROR_NO_ASSOCIATION             1155L






// An error occurred in sending the command to the application.

ERROR_DDE_FAIL                   1156L






// One of the library files needed to run this application cannot be found.

ERROR_DLL_NOT_FOUND              1157L






// The current process has used all of its system allowance of handles for Window Manager objects.

ERROR_NO_MORE_USER_HANDLES       1158L






// The message can be used only with synchronous operations.

ERROR_MESSAGE_SYNC_ONLY          1159L






// The indicated source element has no media.

ERROR_SOURCE_ELEMENT_EMPTY       1160L






// The indicated destination element already contains media.

ERROR_DESTINATION_ELEMENT_FULL   1161L






// The indicated element does not exist.

ERROR_ILLEGAL_ELEMENT_ADDRESS    1162L






// The indicated element is part of a magazine that is not present.

ERROR_MAGAZINE_NOT_PRESENT       1163L






// The indicated device requires reinitialization due to hardware errors.

ERROR_DEVICE_REINITIALIZATION_NEEDED 1164L    // dderror






// The device has indicated that cleaning is required before further operations are attempted.

ERROR_DEVICE_REQUIRES_CLEANING   1165L






// The device has indicated that its door is open.

ERROR_DEVICE_DOOR_OPEN           1166L






// The device is not connected.

ERROR_DEVICE_NOT_CONNECTED       1167L






// Element not found.

ERROR_NOT_FOUND                  1168L






// There was no match for the specified key in the index.

ERROR_NO_MATCH                   1169L






// The property set specified does not exist on the object.

ERROR_SET_NOT_FOUND              1170L






// The point passed to GetMouseMovePoints is not in the buffer.

ERROR_POINT_NOT_FOUND            1171L






// The tracking (workstation) service is not running.

ERROR_NO_TRACKING_SERVICE        1172L






// The Volume ID could not be found.

ERROR_NO_VOLUME_ID               1173L






// Unable to remove the file to be replaced.

ERROR_UNABLE_TO_REMOVE_REPLACED  1175L






// Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name.

ERROR_UNABLE_TO_MOVE_REPLACEMENT 1176L






// Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name.

ERROR_UNABLE_TO_MOVE_REPLACEMENT_2 1177L






// The volume change journal is being deleted.

ERROR_JOURNAL_DELETE_IN_PROGRESS 1178L






// The volume change journal is not active.

ERROR_JOURNAL_NOT_ACTIVE         1179L






// A file was found, but it may not be the correct file.

ERROR_POTENTIAL_FILE_FOUND       1180L






// The journal entry has been deleted from the journal.

ERROR_JOURNAL_ENTRY_DELETED      1181L






// A system shutdown has already been scheduled.

ERROR_SHUTDOWN_IS_SCHEDULED      1190L






// The system shutdown cannot be initiated because there are other users logged on to the computer.

ERROR_SHUTDOWN_USERS_LOGGED_ON   1191L






// The specified device name is invalid.

ERROR_BAD_DEVICE                 1200L






// The device is not currently connected but it is a remembered connection.

ERROR_CONNECTION_UNAVAIL         1201L






// The local device name has a remembered connection to another network resource.

ERROR_DEVICE_ALREADY_REMEMBERED  1202L






// The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator.

ERROR_NO_NET_OR_BAD_PATH         1203L






// The specified network provider name is invalid.

ERROR_BAD_PROVIDER               1204L






// Unable to open the network connection profile.

ERROR_CANNOT_OPEN_PROFILE        1205L






// The network connection profile is corrupted.

ERROR_BAD_PROFILE                1206L






// Cannot enumerate a noncontainer.

ERROR_NOT_CONTAINER              1207L






// An extended error has occurred.

ERROR_EXTENDED_ERROR             1208L






// The format of the specified group name is invalid.

ERROR_INVALID_GROUPNAME          1209L






// The format of the specified computer name is invalid.

ERROR_INVALID_COMPUTERNAME       1210L






// The format of the specified event name is invalid.

ERROR_INVALID_EVENTNAME          1211L






// The format of the specified domain name is invalid.

ERROR_INVALID_DOMAINNAME         1212L






// The format of the specified service name is invalid.

ERROR_INVALID_SERVICENAME        1213L






// The format of the specified network name is invalid.

ERROR_INVALID_NETNAME            1214L






// The format of the specified share name is invalid.

ERROR_INVALID_SHARENAME          1215L






// The format of the specified password is invalid.

ERROR_INVALID_PASSWORDNAME       1216L






// The format of the specified message name is invalid.

ERROR_INVALID_MESSAGENAME        1217L






// The format of the specified message destination is invalid.

ERROR_INVALID_MESSAGEDEST        1218L






// Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.

ERROR_SESSION_CREDENTIAL_CONFLICT 1219L






// An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.

ERROR_REMOTE_SESSION_LIMIT_EXCEEDED 1220L






// The workgroup or domain name is already in use by another computer on the network.

ERROR_DUP_DOMAINNAME             1221L






// The network is not present or not started.

ERROR_NO_NETWORK                 1222L






// The operation was canceled by the user.

ERROR_CANCELLED                  1223L






// The requested operation cannot be performed on a file with a user-mapped section open.

ERROR_USER_MAPPED_FILE           1224L






// The remote computer refused the network connection.

ERROR_CONNECTION_REFUSED         1225L






// The network connection was gracefully closed.

ERROR_GRACEFUL_DISCONNECT        1226L






// The network transport endpoint already has an address associated with it.

ERROR_ADDRESS_ALREADY_ASSOCIATED 1227L






// An address has not yet been associated with the network endpoint.

ERROR_ADDRESS_NOT_ASSOCIATED     1228L






// An operation was attempted on a nonexistent network connection.

ERROR_CONNECTION_INVALID         1229L






// An invalid operation was attempted on an active network connection.

ERROR_CONNECTION_ACTIVE          1230L






// The network location cannot be reached. For information about network troubleshooting, see Windows Help.

ERROR_NETWORK_UNREACHABLE        1231L






// The network location cannot be reached. For information about network troubleshooting, see Windows Help.

ERROR_HOST_UNREACHABLE           1232L






// The network location cannot be reached. For information about network troubleshooting, see Windows Help.

ERROR_PROTOCOL_UNREACHABLE       1233L






// No service is operating at the destination network endpoint on the remote system.

ERROR_PORT_UNREACHABLE           1234L






// The request was aborted.

ERROR_REQUEST_ABORTED            1235L






// The network connection was aborted by the local system.

ERROR_CONNECTION_ABORTED         1236L






// The operation could not be completed. A retry should be performed.

ERROR_RETRY                      1237L






// A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.

ERROR_CONNECTION_COUNT_LIMIT     1238L






// Attempting to log in during an unauthorized time of day for this account.

ERROR_LOGIN_TIME_RESTRICTION     1239L






// The account is not authorized to log in from this station.

ERROR_LOGIN_WKSTA_RESTRICTION    1240L






// The network address could not be used for the operation requested.

ERROR_INCORRECT_ADDRESS          1241L






// The service is already registered.

ERROR_ALREADY_REGISTERED         1242L






// The specified service does not exist.

ERROR_SERVICE_NOT_FOUND          1243L






// The operation being requested was not performed because the user has not been authenticated.

ERROR_NOT_AUTHENTICATED          1244L






// The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist.

ERROR_NOT_LOGGED_ON              1245L






// Continue with work in progress.

ERROR_CONTINUE                   1246L    // dderror






// An attempt was made to perform an initialization operation when initialization has already been completed.

ERROR_ALREADY_INITIALIZED        1247L






// No more local devices.

ERROR_NO_MORE_DEVICES            1248L    // dderror






// The specified site does not exist.

ERROR_NO_SUCH_SITE               1249L






// A domain controller with the specified name already exists.

ERROR_DOMAIN_CONTROLLER_EXISTS   1250L






// This operation is supported only when you are connected to the server.

ERROR_ONLY_IF_CONNECTED          1251L






// The group policy framework should call the extension even if there are no changes.

ERROR_OVERRIDE_NOCHANGES         1252L






// The specified user does not have a valid profile.

ERROR_BAD_USER_PROFILE           1253L






// This operation is not supported on a computer running Windows Server 2003 for Small Business Server

ERROR_NOT_SUPPORTED_ON_SBS       1254L






// The server machine is shutting down.

ERROR_SERVER_SHUTDOWN_IN_PROGRESS 1255L






// The remote system is not available. For information about network troubleshooting, see Windows Help.

ERROR_HOST_DOWN                  1256L






// The security identifier provided is not from an account domain.

ERROR_NON_ACCOUNT_SID            1257L






// The security identifier provided does not have a domain component.

ERROR_NON_DOMAIN_SID             1258L






// AppHelp dialog canceled thus preventing the application from starting.

ERROR_APPHELP_BLOCK              1259L






// This program is blocked by group policy. For more information, contact your system administrator.

ERROR_ACCESS_DISABLED_BY_POLICY  1260L






// A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific.

ERROR_REG_NAT_CONSUMPTION        1261L






// The share is currently offline or does not exist.

ERROR_CSCSHARE_OFFLINE           1262L






// The Kerberos protocol encountered an error while validating the KDC certificate during smartcard logon. There is more information in the system event log.

ERROR_PKINIT_FAILURE             1263L






// The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.

ERROR_SMARTCARD_SUBSYSTEM_FAILURE 1264L






// The system cannot contact a domain controller to service the authentication request. Please try again later.

ERROR_DOWNGRADE_DETECTED         1265L


// Do not use ID's 1266 - 1270 as the symbolicNames have been moved to SEC_E_*






// The machine is locked and cannot be shut down without the force option.

ERROR_MACHINE_LOCKED             1271L






// You can't access this shared folder because your organization's security policies block unauthenticated guest access. These policies help protect your PC from unsafe or malicious devices on the network.

ERROR_SMB_GUEST_LOGON_BLOCKED    1272L






// An application-defined callback gave invalid data when called.

ERROR_CALLBACK_SUPPLIED_INVALID_DATA 1273L






// The group policy framework should call the extension in the synchronous foreground policy refresh.

ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED 1274L






// This driver has been blocked from loading

ERROR_DRIVER_BLOCKED             1275L






// A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.

ERROR_INVALID_IMPORT_OF_NON_DLL  1276L






// Windows cannot open this program since it has been disabled.

ERROR_ACCESS_DISABLED_WEBBLADE   1277L






// Windows cannot open this program because the license enforcement system has been tampered with or become corrupted.

ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER 1278L






// A transaction recover failed.

ERROR_RECOVERY_FAILURE           1279L






// The current thread has already been converted to a fiber.

ERROR_ALREADY_FIBER              1280L






// The current thread has already been converted from a fiber.

ERROR_ALREADY_THREAD             1281L






// The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.

ERROR_STACK_BUFFER_OVERRUN       1282L






// Data present in one of the parameters is more than the function can operate on.

ERROR_PARAMETER_QUOTA_EXCEEDED   1283L






// An attempt to do an operation on a debug object failed because the object is in the process of being deleted.

ERROR_DEBUGGER_INACTIVE          1284L






// An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.

ERROR_DELAY_LOAD_FAILED          1285L






// %1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.

ERROR_VDM_DISALLOWED             1286L






// Insufficient information exists to identify the cause of failure.

ERROR_UNIDENTIFIED_ERROR         1287L






// The parameter passed to a C runtime function is incorrect.

ERROR_INVALID_CRUNTIME_PARAMETER 1288L






// The operation occurred beyond the valid data length of the file.

ERROR_BEYOND_VDL                 1289L






// The service start failed since one or more services in the same process have an incompatible service SID type setting. A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type. If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service.

ERROR_INCOMPATIBLE_SERVICE_SID_TYPE 1290L






// The process hosting the driver for this device has been terminated.

ERROR_DRIVER_PROCESS_TERMINATED  1291L






// An operation attempted to exceed an implementation-defined limit.

ERROR_IMPLEMENTATION_LIMIT       1292L






// Either the target process, or the target thread's containing process, is a protected process.

ERROR_PROCESS_IS_PROTECTED       1293L






// The service notification client is lagging too far behind the current state of services in the machine.

ERROR_SERVICE_NOTIFY_CLIENT_LAGGING 1294L






// The requested file operation failed because the storage quota was exceeded.
// To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator.

ERROR_DISK_QUOTA_EXCEEDED        1295L






// The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator.

ERROR_CONTENT_BLOCKED            1296L






// A privilege that the service requires to function properly does not exist in the service account configuration.
// You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration.

ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE 1297L






// A thread involved in this operation appears to be unresponsive.

ERROR_APP_HANG                   1298L


///////////////////////////////////////////////////
//                                               //
//             SECURITY Error codes              //
//                                               //
//                 1299 to 1399                  //
///////////////////////////////////////////////////






// Indicates a particular Security ID may not be assigned as the label of an object.

ERROR_INVALID_LABEL              1299L






// Not all privileges or groups referenced are assigned to the caller.

ERROR_NOT_ALL_ASSIGNED           1300L






// Some mapping between account names and security IDs was not done.

ERROR_SOME_NOT_MAPPED            1301L






// No system quota limits are specifically set for this account.

ERROR_NO_QUOTAS_FOR_ACCOUNT      1302L






// No encryption key is available. A well-known encryption key was returned.

ERROR_LOCAL_USER_SESSION_KEY     1303L






// The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.

ERROR_NULL_LM_PASSWORD           1304L






// The revision level is unknown.

ERROR_UNKNOWN_REVISION           1305L






// Indicates two revision levels are incompatible.

ERROR_REVISION_MISMATCH          1306L






// This security ID may not be assigned as the owner of this object.

ERROR_INVALID_OWNER              1307L






// This security ID may not be assigned as the primary group of an object.

ERROR_INVALID_PRIMARY_GROUP      1308L






// An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.

ERROR_NO_IMPERSONATION_TOKEN     1309L






// The group may not be disabled.

ERROR_CANT_DISABLE_MANDATORY     1310L






// We can't sign you in with this credential because your domain isn't available. Make sure your device is connected to your organization's network and try again. If you previously signed in on this device with another credential, you can sign in with that credential.

ERROR_NO_LOGON_SERVERS           1311L






// A specified logon session does not exist. It may already have been terminated.

ERROR_NO_SUCH_LOGON_SESSION      1312L






// A specified privilege does not exist.

ERROR_NO_SUCH_PRIVILEGE          1313L






// A required privilege is not held by the client.

ERROR_PRIVILEGE_NOT_HELD         1314L






// The name provided is not a properly formed account name.

ERROR_INVALID_ACCOUNT_NAME       1315L






// The specified account already exists.

ERROR_USER_EXISTS                1316L






// The specified account does not exist.

ERROR_NO_SUCH_USER               1317L






// The specified group already exists.

ERROR_GROUP_EXISTS               1318L






// The specified group does not exist.

ERROR_NO_SUCH_GROUP              1319L






// Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.

ERROR_MEMBER_IN_GROUP            1320L






// The specified user account is not a member of the specified group account.

ERROR_MEMBER_NOT_IN_GROUP        1321L






// This operation is disallowed as it could result in an administration account being disabled, deleted or unable to logon.

ERROR_LAST_ADMIN                 1322L






// Unable to update the password. The value provided as the current password is incorrect.

ERROR_WRONG_PASSWORD             1323L






// Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.

ERROR_ILL_FORMED_PASSWORD        1324L






// Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain.

ERROR_PASSWORD_RESTRICTION       1325L






// The user name or password is incorrect.

ERROR_LOGON_FAILURE              1326L






// Account restrictions are preventing this user from signing in. For example: blank passwords aren't allowed, sign-in times are limited, or a policy restriction has been enforced.

ERROR_ACCOUNT_RESTRICTION        1327L






// Your account has time restrictions that keep you from signing in right now.

ERROR_INVALID_LOGON_HOURS        1328L






// This user isn't allowed to sign in to this computer.

ERROR_INVALID_WORKSTATION        1329L






// The password for this account has expired.

ERROR_PASSWORD_EXPIRED           1330L






// This user can't sign in because this account is currently disabled.

ERROR_ACCOUNT_DISABLED           1331L






// No mapping between account names and security IDs was done.

ERROR_NONE_MAPPED                1332L






// Too many local user identifiers (LUIDs) were requested at one time.

ERROR_TOO_MANY_LUIDS_REQUESTED   1333L






// No more local user identifiers (LUIDs) are available.

ERROR_LUIDS_EXHAUSTED            1334L






// The subauthority part of a security ID is invalid for this particular use.

ERROR_INVALID_SUB_AUTHORITY      1335L






// The access control list (ACL) structure is invalid.

ERROR_INVALID_ACL                1336L






// The security ID structure is invalid.

ERROR_INVALID_SID                1337L






// The security descriptor structure is invalid.

ERROR_INVALID_SECURITY_DESCR     1338L






// The inherited access control list (ACL) or access control entry (ACE) could not be built.

ERROR_BAD_INHERITANCE_ACL        1340L






// The server is currently disabled.

ERROR_SERVER_DISABLED            1341L






// The server is currently enabled.

ERROR_SERVER_NOT_DISABLED        1342L






// The value provided was an invalid value for an identifier authority.

ERROR_INVALID_ID_AUTHORITY       1343L






// No more memory is available for security information updates.

ERROR_ALLOTTED_SPACE_EXCEEDED    1344L






// The specified attributes are invalid, or incompatible with the attributes for the group as a whole.

ERROR_INVALID_GROUP_ATTRIBUTES   1345L






// Either a required impersonation level was not provided, or the provided impersonation level is invalid.

ERROR_BAD_IMPERSONATION_LEVEL    1346L






// Cannot open an anonymous level security token.

ERROR_CANT_OPEN_ANONYMOUS        1347L






// The validation information class requested was invalid.

ERROR_BAD_VALIDATION_CLASS       1348L






// The type of the token is inappropriate for its attempted use.

ERROR_BAD_TOKEN_TYPE             1349L






// Unable to perform a security operation on an object that has no associated security.

ERROR_NO_SECURITY_ON_OBJECT      1350L






// Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.

ERROR_CANT_ACCESS_DOMAIN_INFO    1351L






// The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.

ERROR_INVALID_SERVER_STATE       1352L






// The domain was in the wrong state to perform the security operation.

ERROR_INVALID_DOMAIN_STATE       1353L






// This operation is only allowed for the Primary Domain Controller of the domain.

ERROR_INVALID_DOMAIN_ROLE        1354L






// The specified domain either does not exist or could not be contacted.

ERROR_NO_SUCH_DOMAIN             1355L






// The specified domain already exists.

ERROR_DOMAIN_EXISTS              1356L






// An attempt was made to exceed the limit on the number of domains per server.

ERROR_DOMAIN_LIMIT_EXCEEDED      1357L






// Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.

ERROR_INTERNAL_DB_CORRUPTION     1358L






// An internal error occurred.

ERROR_INTERNAL_ERROR             1359L






// Generic access types were contained in an access mask which should already be mapped to nongeneric types.

ERROR_GENERIC_NOT_MAPPED         1360L






// A security descriptor is not in the right format (absolute or self-relative).

ERROR_BAD_DESCRIPTOR_FORMAT      1361L






// The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.

ERROR_NOT_LOGON_PROCESS          1362L






// Cannot start a new logon session with an ID that is already in use.

ERROR_LOGON_SESSION_EXISTS       1363L






// A specified authentication package is unknown.

ERROR_NO_SUCH_PACKAGE            1364L






// The logon session is not in a state that is consistent with the requested operation.

ERROR_BAD_LOGON_SESSION_STATE    1365L






// The logon session ID is already in use.

ERROR_LOGON_SESSION_COLLISION    1366L






// A logon request contained an invalid logon type value.

ERROR_INVALID_LOGON_TYPE         1367L






// Unable to impersonate using a named pipe until data has been read from that pipe.

ERROR_CANNOT_IMPERSONATE         1368L






// The transaction state of a registry subtree is incompatible with the requested operation.

ERROR_RXACT_INVALID_STATE        1369L






// An internal security database corruption has been encountered.

ERROR_RXACT_COMMIT_FAILURE       1370L






// Cannot perform this operation on built-in accounts.

ERROR_SPECIAL_ACCOUNT            1371L






// Cannot perform this operation on this built-in special group.

ERROR_SPECIAL_GROUP              1372L






// Cannot perform this operation on this built-in special user.

ERROR_SPECIAL_USER               1373L






// The user cannot be removed from a group because the group is currently the user's primary group.

ERROR_MEMBERS_PRIMARY_GROUP      1374L






// The token is already in use as a primary token.

ERROR_TOKEN_ALREADY_IN_USE       1375L






// The specified local group does not exist.

ERROR_NO_SUCH_ALIAS              1376L






// The specified account name is not a member of the group.

ERROR_MEMBER_NOT_IN_ALIAS        1377L






// The specified account name is already a member of the group.

ERROR_MEMBER_IN_ALIAS            1378L






// The specified local group already exists.

ERROR_ALIAS_EXISTS               1379L






// Logon failure: the user has not been granted the requested logon type at this computer.

ERROR_LOGON_NOT_GRANTED          1380L






// The maximum number of secrets that may be stored in a single system has been exceeded.

ERROR_TOO_MANY_SECRETS           1381L






// The length of a secret exceeds the maximum length allowed.

ERROR_SECRET_TOO_LONG            1382L






// The local security authority database contains an internal inconsistency.

ERROR_INTERNAL_DB_ERROR          1383L






// During a logon attempt, the user's security context accumulated too many security IDs.

ERROR_TOO_MANY_CONTEXT_IDS       1384L






// Logon failure: the user has not been granted the requested logon type at this computer.

ERROR_LOGON_TYPE_NOT_GRANTED     1385L






// A cross-encrypted password is necessary to change a user password.

ERROR_NT_CROSS_ENCRYPTION_REQUIRED 1386L






// A member could not be added to or removed from the local group because the member does not exist.

ERROR_NO_SUCH_MEMBER             1387L






// A new member could not be added to a local group because the member has the wrong account type.

ERROR_INVALID_MEMBER             1388L






// Too many security IDs have been specified.

ERROR_TOO_MANY_SIDS              1389L






// A cross-encrypted password is necessary to change this user password.

ERROR_LM_CROSS_ENCRYPTION_REQUIRED 1390L






// Indicates an ACL contains no inheritable components.

ERROR_NO_INHERITANCE             1391L






// The file or directory is corrupted and unreadable.

ERROR_FILE_CORRUPT               1392L






// The disk structure is corrupted and unreadable.

ERROR_DISK_CORRUPT               1393L






// There is no user session key for the specified logon session.

ERROR_NO_USER_SESSION_KEY        1394L






// The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept.

ERROR_LICENSE_QUOTA_EXCEEDED     1395L






// The target account name is incorrect.

ERROR_WRONG_TARGET_NAME          1396L






// Mutual Authentication failed. The server's password is out of date at the domain controller.

ERROR_MUTUAL_AUTH_FAILED         1397L






// There is a time and/or date difference between the client and server.

ERROR_TIME_SKEW                  1398L






// This operation cannot be performed on the current domain.

ERROR_CURRENT_DOMAIN_NOT_ALLOWED 1399L


///////////////////////////////////////////////////
//                                               //
//              WinUser Error codes              //
//                                               //
//                 1400 to 1499                  //
///////////////////////////////////////////////////






// Invalid window handle.

ERROR_INVALID_WINDOW_HANDLE      1400L






// Invalid menu handle.

ERROR_INVALID_MENU_HANDLE        1401L






// Invalid cursor handle.

ERROR_INVALID_CURSOR_HANDLE      1402L






// Invalid accelerator table handle.

ERROR_INVALID_ACCEL_HANDLE       1403L






// Invalid hook handle.

ERROR_INVALID_HOOK_HANDLE        1404L






// Invalid handle to a multiple-window position structure.

ERROR_INVALID_DWP_HANDLE         1405L






// Cannot create a top-level child window.

ERROR_TLW_WITH_WSCHILD           1406L






// Cannot find window class.

ERROR_CANNOT_FIND_WND_CLASS      1407L






// Invalid window; it belongs to other thread.

ERROR_WINDOW_OF_OTHER_THREAD     1408L






// Hot key is already registered.

ERROR_HOTKEY_ALREADY_REGISTERED  1409L






// Class already exists.

ERROR_CLASS_ALREADY_EXISTS       1410L






// Class does not exist.

ERROR_CLASS_DOES_NOT_EXIST       1411L






// Class still has open windows.

ERROR_CLASS_HAS_WINDOWS          1412L






// Invalid index.

ERROR_INVALID_INDEX              1413L






// Invalid icon handle.

ERROR_INVALID_ICON_HANDLE        1414L






// Using private DIALOG window words.

ERROR_PRIVATE_DIALOG_INDEX       1415L






// The list box identifier was not found.

ERROR_LISTBOX_ID_NOT_FOUND       1416L






// No wildcards were found.

ERROR_NO_WILDCARD_CHARACTERS     1417L






// Thread does not have a clipboard open.

ERROR_CLIPBOARD_NOT_OPEN         1418L






// Hot key is not registered.

ERROR_HOTKEY_NOT_REGISTERED      1419L






// The window is not a valid dialog window.

ERROR_WINDOW_NOT_DIALOG          1420L






// Control ID not found.

ERROR_CONTROL_ID_NOT_FOUND       1421L






// Invalid message for a combo box because it does not have an edit control.

ERROR_INVALID_COMBOBOX_MESSAGE   1422L






// The window is not a combo box.

ERROR_WINDOW_NOT_COMBOBOX        1423L






// Height must be less than 256.

ERROR_INVALID_EDIT_HEIGHT        1424L






// Invalid device context (DC) handle.

ERROR_DC_NOT_FOUND               1425L






// Invalid hook procedure type.

ERROR_INVALID_HOOK_FILTER        1426L






// Invalid hook procedure.

ERROR_INVALID_FILTER_PROC        1427L






// Cannot set nonlocal hook without a module handle.

ERROR_HOOK_NEEDS_HMOD            1428L






// This hook procedure can only be set globally.

ERROR_GLOBAL_ONLY_HOOK           1429L






// The journal hook procedure is already installed.

ERROR_JOURNAL_HOOK_SET           1430L






// The hook procedure is not installed.

ERROR_HOOK_NOT_INSTALLED         1431L






// Invalid message for single-selection list box.

ERROR_INVALID_LB_MESSAGE         1432L






// LB_SETCOUNT sent to non-lazy list box.

ERROR_SETCOUNT_ON_BAD_LB         1433L






// This list box does not support tab stops.

ERROR_LB_WITHOUT_TABSTOPS        1434L






// Cannot destroy object created by another thread.

ERROR_DESTROY_OBJECT_OF_OTHER_THREAD 1435L






// Child windows cannot have menus.

ERROR_CHILD_WINDOW_MENU          1436L






// The window does not have a system menu.

ERROR_NO_SYSTEM_MENU             1437L






// Invalid message box style.

ERROR_INVALID_MSGBOX_STYLE       1438L






// Invalid system-wide (SPI_*) parameter.

ERROR_INVALID_SPI_VALUE          1439L






// Screen already locked.

ERROR_SCREEN_ALREADY_LOCKED      1440L






// All handles to windows in a multiple-window position structure must have the same parent.

ERROR_HWNDS_HAVE_DIFF_PARENT     1441L






// The window is not a child window.

ERROR_NOT_CHILD_WINDOW           1442L






// Invalid GW_* command.

ERROR_INVALID_GW_COMMAND         1443L






// Invalid thread identifier.

ERROR_INVALID_THREAD_ID          1444L






// Cannot process a message from a window that is not a multiple document interface (MDI) window.

ERROR_NON_MDICHILD_WINDOW        1445L






// Popup menu already active.

ERROR_POPUP_ALREADY_ACTIVE       1446L






// The window does not have scroll bars.

ERROR_NO_SCROLLBARS              1447L






// Scroll bar range cannot be greater than MAXLONG.

ERROR_INVALID_SCROLLBAR_RANGE    1448L






// Cannot show or remove the window in the way specified.

ERROR_INVALID_SHOWWIN_COMMAND    1449L






// Insufficient system resources exist to complete the requested service.

ERROR_NO_SYSTEM_RESOURCES        1450L






// Insufficient system resources exist to complete the requested service.

ERROR_NONPAGED_SYSTEM_RESOURCES  1451L






// Insufficient system resources exist to complete the requested service.

ERROR_PAGED_SYSTEM_RESOURCES     1452L






// Insufficient quota to complete the requested service.

ERROR_WORKING_SET_QUOTA          1453L






// Insufficient quota to complete the requested service.

ERROR_PAGEFILE_QUOTA             1454L






// The paging file is too small for this operation to complete.

ERROR_COMMITMENT_LIMIT           1455L






// A menu item was not found.

ERROR_MENU_ITEM_NOT_FOUND        1456L






// Invalid keyboard layout handle.

ERROR_INVALID_KEYBOARD_HANDLE    1457L






// Hook type not allowed.

ERROR_HOOK_TYPE_NOT_ALLOWED      1458L






// This operation requires an interactive window station.

ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION 1459L






// This operation returned because the timeout period expired.

ERROR_TIMEOUT                    1460L






// Invalid monitor handle.

ERROR_INVALID_MONITOR_HANDLE     1461L






// Incorrect size argument.

ERROR_INCORRECT_SIZE             1462L






// The symbolic link cannot be followed because its type is disabled.

ERROR_SYMLINK_CLASS_DISABLED     1463L






// This application does not support the current operation on symbolic links.

ERROR_SYMLINK_NOT_SUPPORTED      1464L






// Windows was unable to parse the requested XML data.

ERROR_XML_PARSE_ERROR            1465L






// An error was encountered while processing an XML digital signature.

ERROR_XMLDSIG_ERROR              1466L






// This application must be restarted.

ERROR_RESTART_APPLICATION        1467L






// The caller made the connection request in the wrong routing compartment.

ERROR_WRONG_COMPARTMENT          1468L






// There was an AuthIP failure when attempting to connect to the remote host.

ERROR_AUTHIP_FAILURE             1469L






// Insufficient NVRAM resources exist to complete the requested service. A reboot might be required.

ERROR_NO_NVRAM_RESOURCES         1470L






// Unable to finish the requested operation because the specified process is not a GUI process.

ERROR_NOT_GUI_PROCESS            1471L


///////////////////////////////////////////////////
//                                               //
//             EventLog Error codes              //
//                                               //
//                 1500 to 1549                  //
///////////////////////////////////////////////////






// The event log file is corrupted.

ERROR_EVENTLOG_FILE_CORRUPT      1500L






// No event log file could be opened, so the event logging service did not start.

ERROR_EVENTLOG_CANT_START        1501L






// The event log file is full.

ERROR_LOG_FILE_FULL              1502L






// The event log file has changed between read operations.

ERROR_EVENTLOG_FILE_CHANGED      1503L






// The specified Job already has a container assigned to it.

ERROR_CONTAINER_ASSIGNED         1504L






// The specified Job does not have a container assigned to it.

ERROR_JOB_NO_CONTAINER           1505L


///////////////////////////////////////////////////
//                                               //
//            Class Scheduler Error codes        //
//                                               //
//                 1550 to 1599                  //
///////////////////////////////////////////////////






// The specified task name is invalid.

ERROR_INVALID_TASK_NAME          1550L






// The specified task index is invalid.

ERROR_INVALID_TASK_INDEX         1551L






// The specified thread is already joining a task.

ERROR_THREAD_ALREADY_IN_TASK     1552L


///////////////////////////////////////////////////
//                                               //
//                MSI Error codes                //
//                                               //
//                 1600 to 1699                  //
///////////////////////////////////////////////////






// The Windows Installer Service could not be accessed. This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance.

ERROR_INSTALL_SERVICE_FAILURE    1601L






// User cancelled installation.

ERROR_INSTALL_USEREXIT           1602L






// Fatal error during installation.

ERROR_INSTALL_FAILURE            1603L






// Installation suspended, incomplete.

ERROR_INSTALL_SUSPEND            1604L






// This action is only valid for products that are currently installed.

ERROR_UNKNOWN_PRODUCT            1605L






// Feature ID not registered.

ERROR_UNKNOWN_FEATURE            1606L






// Component ID not registered.

ERROR_UNKNOWN_COMPONENT          1607L






// Unknown property.

ERROR_UNKNOWN_PROPERTY           1608L






// Handle is in an invalid state.

ERROR_INVALID_HANDLE_STATE       1609L






// The configuration data for this product is corrupt. Contact your support personnel.

ERROR_BAD_CONFIGURATION          1610L






// Component qualifier not present.

ERROR_INDEX_ABSENT               1611L






// The installation source for this product is not available. Verify that the source exists and that you can access it.

ERROR_INSTALL_SOURCE_ABSENT      1612L






// This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.

ERROR_INSTALL_PACKAGE_VERSION    1613L






// Product is uninstalled.

ERROR_PRODUCT_UNINSTALLED        1614L






// SQL query syntax invalid or unsupported.

ERROR_BAD_QUERY_SYNTAX           1615L






// Record field does not exist.

ERROR_INVALID_FIELD              1616L






// The device has been removed.

ERROR_DEVICE_REMOVED             1617L






// Another installation is already in progress. Complete that installation before proceeding with this install.

ERROR_INSTALL_ALREADY_RUNNING    1618L






// This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.

ERROR_INSTALL_PACKAGE_OPEN_FAILED 1619L






// This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package.

ERROR_INSTALL_PACKAGE_INVALID    1620L






// There was an error starting the Windows Installer service user interface. Contact your support personnel.

ERROR_INSTALL_UI_FAILURE         1621L






// Error opening installation log file. Verify that the specified log file location exists and that you can write to it.

ERROR_INSTALL_LOG_FAILURE        1622L






// The language of this installation package is not supported by your system.

ERROR_INSTALL_LANGUAGE_UNSUPPORTED 1623L






// Error applying transforms. Verify that the specified transform paths are valid.

ERROR_INSTALL_TRANSFORM_FAILURE  1624L






// This installation is forbidden by system policy. Contact your system administrator.

ERROR_INSTALL_PACKAGE_REJECTED   1625L






// Function could not be executed.

ERROR_FUNCTION_NOT_CALLED        1626L






// Function failed during execution.

ERROR_FUNCTION_FAILED            1627L






// Invalid or unknown table specified.

ERROR_INVALID_TABLE              1628L






// Data supplied is of wrong type.

ERROR_DATATYPE_MISMATCH          1629L






// Data of this type is not supported.

ERROR_UNSUPPORTED_TYPE           1630L






// The Windows Installer service failed to start. Contact your support personnel.

ERROR_CREATE_FAILED              1631L






// The Temp folder is on a drive that is full or is inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder.

ERROR_INSTALL_TEMP_UNWRITABLE    1632L






// This installation package is not supported by this processor type. Contact your product vendor.

ERROR_INSTALL_PLATFORM_UNSUPPORTED 1633L






// Component not used on this computer.

ERROR_INSTALL_NOTUSED            1634L






// This update package could not be opened. Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package.

ERROR_PATCH_PACKAGE_OPEN_FAILED  1635L






// This update package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer update package.

ERROR_PATCH_PACKAGE_INVALID      1636L






// This update package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.

ERROR_PATCH_PACKAGE_UNSUPPORTED  1637L






// Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.

ERROR_PRODUCT_VERSION            1638L






// Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.

ERROR_INVALID_COMMAND_LINE       1639L






// Only administrators have permission to add, remove, or configure server software during a Terminal services remote session. If you want to install or configure software on the server, contact your network administrator.

ERROR_INSTALL_REMOTE_DISALLOWED  1640L






// The requested operation completed successfully. The system will be restarted so the changes can take effect.

ERROR_SUCCESS_REBOOT_INITIATED   1641L






// The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade.

ERROR_PATCH_TARGET_NOT_FOUND     1642L






// The update package is not permitted by software restriction policy.

ERROR_PATCH_PACKAGE_REJECTED     1643L






// One or more customizations are not permitted by software restriction policy.

ERROR_INSTALL_TRANSFORM_REJECTED 1644L






// The Windows Installer does not permit installation from a Remote Desktop Connection.

ERROR_INSTALL_REMOTE_PROHIBITED  1645L






// Uninstallation of the update package is not supported.

ERROR_PATCH_REMOVAL_UNSUPPORTED  1646L






// The update is not applied to this product.

ERROR_UNKNOWN_PATCH              1647L






// No valid sequence could be found for the set of updates.

ERROR_PATCH_NO_SEQUENCE          1648L






// Update removal was disallowed by policy.

ERROR_PATCH_REMOVAL_DISALLOWED   1649L






// The XML update data is invalid.

ERROR_INVALID_PATCH_XML          1650L






// Windows Installer does not permit updating of managed advertised products. At least one feature of the product must be installed before applying the update.

ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT 1651L






// The Windows Installer service is not accessible in Safe Mode. Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state.

ERROR_INSTALL_SERVICE_SAFEBOOT   1652L






// A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately.

ERROR_FAIL_FAST_EXCEPTION        1653L






// The app that you are trying to run is not supported on this version of Windows.

ERROR_INSTALL_REJECTED           1654L






// The operation was blocked as the process prohibits dynamic code generation.

ERROR_DYNAMIC_CODE_BLOCKED       1655L






// The objects are not identical.

ERROR_NOT_SAME_OBJECT            1656L






// The specified image file was blocked from loading because it does not enable a feature required by the process: Control Flow Guard.

ERROR_STRICT_CFG_VIOLATION       1657L






// The thread context could not be updated because this has been restricted for the process.

ERROR_SET_CONTEXT_DENIED         1660L






// An invalid cross-partition private file/section access was attempted.

ERROR_CROSS_PARTITION_VIOLATION  1661L


///////////////////////////////////////////////////
//                                               //
//               RPC Error codes                 //
//                                               //
//                 1700 to 1999                  //
///////////////////////////////////////////////////






// The string binding is invalid.

RPC_S_INVALID_STRING_BINDING     1700L






// The binding handle is not the correct type.

RPC_S_WRONG_KIND_OF_BINDING      1701L






// The binding handle is invalid.

RPC_S_INVALID_BINDING            1702L






// The RPC protocol sequence is not supported.

RPC_S_PROTSEQ_NOT_SUPPORTED      1703L






// The RPC protocol sequence is invalid.

RPC_S_INVALID_RPC_PROTSEQ        1704L






// The string universal unique identifier (UUID) is invalid.

RPC_S_INVALID_STRING_UUID        1705L






// The endpoint format is invalid.

RPC_S_INVALID_ENDPOINT_FORMAT    1706L






// The network address is invalid.

RPC_S_INVALID_NET_ADDR           1707L






// No endpoint was found.

RPC_S_NO_ENDPOINT_FOUND          1708L






// The timeout value is invalid.

RPC_S_INVALID_TIMEOUT            1709L






// The object universal unique identifier (UUID) was not found.

RPC_S_OBJECT_NOT_FOUND           1710L






// The object universal unique identifier (UUID) has already been registered.

RPC_S_ALREADY_REGISTERED         1711L






// The type universal unique identifier (UUID) has already been registered.

RPC_S_TYPE_ALREADY_REGISTERED    1712L






// The RPC server is already listening.

RPC_S_ALREADY_LISTENING          1713L






// No protocol sequences have been registered.

RPC_S_NO_PROTSEQS_REGISTERED     1714L






// The RPC server is not listening.

RPC_S_NOT_LISTENING              1715L






// The manager type is unknown.

RPC_S_UNKNOWN_MGR_TYPE           1716L






// The interface is unknown.

RPC_S_UNKNOWN_IF                 1717L






// There are no bindings.

RPC_S_NO_BINDINGS                1718L






// There are no protocol sequences.

RPC_S_NO_PROTSEQS                1719L






// The endpoint cannot be created.

RPC_S_CANT_CREATE_ENDPOINT       1720L






// Not enough resources are available to complete this operation.

RPC_S_OUT_OF_RESOURCES           1721L






// The RPC server is unavailable.

RPC_S_SERVER_UNAVAILABLE         1722L






// The RPC server is too busy to complete this operation.

RPC_S_SERVER_TOO_BUSY            1723L






// The network options are invalid.

RPC_S_INVALID_NETWORK_OPTIONS    1724L






// There are no remote procedure calls active on this thread.

RPC_S_NO_CALL_ACTIVE             1725L






// The remote procedure call failed.

RPC_S_CALL_FAILED                1726L






// The remote procedure call failed and did not execute.

RPC_S_CALL_FAILED_DNE            1727L






// A remote procedure call (RPC) protocol error occurred.

RPC_S_PROTOCOL_ERROR             1728L






// Access to the HTTP proxy is denied.

RPC_S_PROXY_ACCESS_DENIED        1729L






// The transfer syntax is not supported by the RPC server.

RPC_S_UNSUPPORTED_TRANS_SYN      1730L






// The universal unique identifier (UUID) type is not supported.

RPC_S_UNSUPPORTED_TYPE           1732L






// The tag is invalid.

RPC_S_INVALID_TAG                1733L






// The array bounds are invalid.

RPC_S_INVALID_BOUND              1734L






// The binding does not contain an entry name.

RPC_S_NO_ENTRY_NAME              1735L






// The name syntax is invalid.

RPC_S_INVALID_NAME_SYNTAX        1736L






// The name syntax is not supported.

RPC_S_UNSUPPORTED_NAME_SYNTAX    1737L






// No network address is available to use to construct a universal unique identifier (UUID).

RPC_S_UUID_NO_ADDRESS            1739L






// The endpoint is a duplicate.

RPC_S_DUPLICATE_ENDPOINT         1740L






// The authentication type is unknown.

RPC_S_UNKNOWN_AUTHN_TYPE         1741L






// The maximum number of calls is too small.

RPC_S_MAX_CALLS_TOO_SMALL        1742L






// The string is too long.

RPC_S_STRING_TOO_LONG            1743L






// The RPC protocol sequence was not found.

RPC_S_PROTSEQ_NOT_FOUND          1744L






// The procedure number is out of range.

RPC_S_PROCNUM_OUT_OF_RANGE       1745L






// The binding does not contain any authentication information.

RPC_S_BINDING_HAS_NO_AUTH        1746L






// The authentication service is unknown.

RPC_S_UNKNOWN_AUTHN_SERVICE      1747L






// The authentication level is unknown.

RPC_S_UNKNOWN_AUTHN_LEVEL        1748L






// The security context is invalid.

RPC_S_INVALID_AUTH_IDENTITY      1749L






// The authorization service is unknown.

RPC_S_UNKNOWN_AUTHZ_SERVICE      1750L






// The entry is invalid.

EPT_S_INVALID_ENTRY              1751L






// The server endpoint cannot perform the operation.

EPT_S_CANT_PERFORM_OP            1752L






// There are no more endpoints available from the endpoint mapper.

EPT_S_NOT_REGISTERED             1753L






// No interfaces have been exported.

RPC_S_NOTHING_TO_EXPORT          1754L






// The entry name is incomplete.

RPC_S_INCOMPLETE_NAME            1755L






// The version option is invalid.

RPC_S_INVALID_VERS_OPTION        1756L






// There are no more members.

RPC_S_NO_MORE_MEMBERS            1757L






// There is nothing to unexport.

RPC_S_NOT_ALL_OBJS_UNEXPORTED    1758L






// The interface was not found.

RPC_S_INTERFACE_NOT_FOUND        1759L






// The entry already exists.

RPC_S_ENTRY_ALREADY_EXISTS       1760L






// The entry is not found.

RPC_S_ENTRY_NOT_FOUND            1761L






// The name service is unavailable.

RPC_S_NAME_SERVICE_UNAVAILABLE   1762L






// The network address family is invalid.

RPC_S_INVALID_NAF_ID             1763L






// The requested operation is not supported.

RPC_S_CANNOT_SUPPORT             1764L






// No security context is available to allow impersonation.

RPC_S_NO_CONTEXT_AVAILABLE       1765L






// An internal error occurred in a remote procedure call (RPC).

RPC_S_INTERNAL_ERROR             1766L






// The RPC server attempted an integer division by zero.

RPC_S_ZERO_DIVIDE                1767L






// An addressing error occurred in the RPC server.

RPC_S_ADDRESS_ERROR              1768L






// A floating-point operation at the RPC server caused a division by zero.

RPC_S_FP_DIV_ZERO                1769L






// A floating-point underflow occurred at the RPC server.

RPC_S_FP_UNDERFLOW               1770L






// A floating-point overflow occurred at the RPC server.

RPC_S_FP_OVERFLOW                1771L






// The list of RPC servers available for the binding of auto handles has been exhausted.

RPC_X_NO_MORE_ENTRIES            1772L






// Unable to open the character translation table file.

RPC_X_SS_CHAR_TRANS_OPEN_FAIL    1773L






// The file containing the character translation table has fewer than 512 bytes.

RPC_X_SS_CHAR_TRANS_SHORT_FILE   1774L






// A null context handle was passed from the client to the host during a remote procedure call.

RPC_X_SS_IN_NULL_CONTEXT         1775L






// The context handle changed during a remote procedure call.

RPC_X_SS_CONTEXT_DAMAGED         1777L






// The binding handles passed to a remote procedure call do not match.

RPC_X_SS_HANDLES_MISMATCH        1778L






// The stub is unable to get the remote procedure call handle.

RPC_X_SS_CANNOT_GET_CALL_HANDLE  1779L






// A null reference pointer was passed to the stub.

RPC_X_NULL_REF_POINTER           1780L






// The enumeration value is out of range.

RPC_X_ENUM_VALUE_OUT_OF_RANGE    1781L






// The byte count is too small.

RPC_X_BYTE_COUNT_TOO_SMALL       1782L






// The stub received bad data.

RPC_X_BAD_STUB_DATA              1783L






// The supplied user buffer is not valid for the requested operation.

ERROR_INVALID_USER_BUFFER        1784L






// The disk media is not recognized. It may not be formatted.

ERROR_UNRECOGNIZED_MEDIA         1785L






// The workstation does not have a trust secret.

ERROR_NO_TRUST_LSA_SECRET        1786L






// The security database on the server does not have a computer account for this workstation trust relationship.

ERROR_NO_TRUST_SAM_ACCOUNT       1787L






// The trust relationship between the primary domain and the trusted domain failed.

ERROR_TRUSTED_DOMAIN_FAILURE     1788L






// The trust relationship between this workstation and the primary domain failed.

ERROR_TRUSTED_RELATIONSHIP_FAILURE 1789L






// The network logon failed.

ERROR_TRUST_FAILURE              1790L






// A remote procedure call is already in progress for this thread.

RPC_S_CALL_IN_PROGRESS           1791L






// An attempt was made to logon, but the network logon service was not started.

ERROR_NETLOGON_NOT_STARTED       1792L






// The user's account has expired.

ERROR_ACCOUNT_EXPIRED            1793L






// The redirector is in use and cannot be unloaded.

ERROR_REDIRECTOR_HAS_OPEN_HANDLES 1794L






// The specified printer driver is already installed.

ERROR_PRINTER_DRIVER_ALREADY_INSTALLED 1795L






// The specified port is unknown.

ERROR_UNKNOWN_PORT               1796L






// The printer driver is unknown.

ERROR_UNKNOWN_PRINTER_DRIVER     1797L






// The print processor is unknown.

ERROR_UNKNOWN_PRINTPROCESSOR     1798L






// The specified separator file is invalid.

ERROR_INVALID_SEPARATOR_FILE     1799L






// The specified priority is invalid.

ERROR_INVALID_PRIORITY           1800L






// The printer name is invalid.

ERROR_INVALID_PRINTER_NAME       1801L






// The printer already exists.

ERROR_PRINTER_ALREADY_EXISTS     1802L






// The printer command is invalid.

ERROR_INVALID_PRINTER_COMMAND    1803L






// The specified datatype is invalid.

ERROR_INVALID_DATATYPE           1804L






// The environment specified is invalid.

ERROR_INVALID_ENVIRONMENT        1805L






// There are no more bindings.

RPC_S_NO_MORE_BINDINGS           1806L






// The account used is an interdomain trust account. Use your global user account or local user account to access this server.

ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT 1807L






// The account used is a computer account. Use your global user account or local user account to access this server.

ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT 1808L






// The account used is a server trust account. Use your global user account or local user account to access this server.

ERROR_NOLOGON_SERVER_TRUST_ACCOUNT 1809L






// The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.

ERROR_DOMAIN_TRUST_INCONSISTENT  1810L






// The server is in use and cannot be unloaded.

ERROR_SERVER_HAS_OPEN_HANDLES    1811L






// The specified image file did not contain a resource section.

ERROR_RESOURCE_DATA_NOT_FOUND    1812L






// The specified resource type cannot be found in the image file.

ERROR_RESOURCE_TYPE_NOT_FOUND    1813L






// The specified resource name cannot be found in the image file.

ERROR_RESOURCE_NAME_NOT_FOUND    1814L






// The specified resource language ID cannot be found in the image file.

ERROR_RESOURCE_LANG_NOT_FOUND    1815L






// Not enough quota is available to process this command.

ERROR_NOT_ENOUGH_QUOTA           1816L






// No interfaces have been registered.

RPC_S_NO_INTERFACES              1817L






// The remote procedure call was cancelled.

RPC_S_CALL_CANCELLED             1818L






// The binding handle does not contain all required information.

RPC_S_BINDING_INCOMPLETE         1819L






// A communications failure occurred during a remote procedure call.

RPC_S_COMM_FAILURE               1820L






// The requested authentication level is not supported.

RPC_S_UNSUPPORTED_AUTHN_LEVEL    1821L






// No principal name registered.

RPC_S_NO_PRINC_NAME              1822L






// The error specified is not a valid Windows RPC error code.

RPC_S_NOT_RPC_ERROR              1823L






// A UUID that is valid only on this computer has been allocated.

RPC_S_UUID_LOCAL_ONLY            1824L






// A security package specific error occurred.

RPC_S_SEC_PKG_ERROR              1825L






// Thread is not canceled.

RPC_S_NOT_CANCELLED              1826L






// Invalid operation on the encoding/decoding handle.

RPC_X_INVALID_ES_ACTION          1827L






// Incompatible version of the serializing package.

RPC_X_WRONG_ES_VERSION           1828L






// Incompatible version of the RPC stub.

RPC_X_WRONG_STUB_VERSION         1829L






// The RPC pipe object is invalid or corrupted.

RPC_X_INVALID_PIPE_OBJECT        1830L






// An invalid operation was attempted on an RPC pipe object.

RPC_X_WRONG_PIPE_ORDER           1831L






// Unsupported RPC pipe version.

RPC_X_WRONG_PIPE_VERSION         1832L






// HTTP proxy server rejected the connection because the cookie authentication failed.

RPC_S_COOKIE_AUTH_FAILED         1833L






// The RPC server is suspended, and could not be resumed for this request. The call did not execute.

RPC_S_DO_NOT_DISTURB             1834L






// The RPC call contains too many handles to be transmitted in a single request.

RPC_S_SYSTEM_HANDLE_COUNT_EXCEEDED 1835L






// The RPC call contains a handle that differs from the declared handle type.

RPC_S_SYSTEM_HANDLE_TYPE_MISMATCH 1836L






// The group member was not found.

RPC_S_GROUP_MEMBER_NOT_FOUND     1898L






// The endpoint mapper database entry could not be created.

EPT_S_CANT_CREATE                1899L






// The object universal unique identifier (UUID) is the nil UUID.

RPC_S_INVALID_OBJECT             1900L






// The specified time is invalid.

ERROR_INVALID_TIME               1901L






// The specified form name is invalid.

ERROR_INVALID_FORM_NAME          1902L






// The specified form size is invalid.

ERROR_INVALID_FORM_SIZE          1903L






// The specified printer handle is already being waited on

ERROR_ALREADY_WAITING            1904L






// The specified printer has been deleted.

ERROR_PRINTER_DELETED            1905L






// The state of the printer is invalid.

ERROR_INVALID_PRINTER_STATE      1906L






// The user's password must be changed before signing in.

ERROR_PASSWORD_MUST_CHANGE       1907L






// Could not find the domain controller for this domain.

ERROR_DOMAIN_CONTROLLER_NOT_FOUND 1908L






// The referenced account is currently locked out and may not be logged on to.

ERROR_ACCOUNT_LOCKED_OUT         1909L






// The object exporter specified was not found.

OR_INVALID_OXID                  1910L






// The object specified was not found.

OR_INVALID_OID                   1911L






// The object resolver set specified was not found.

OR_INVALID_SET                   1912L






// Some data remains to be sent in the request buffer.

RPC_S_SEND_INCOMPLETE            1913L






// Invalid asynchronous remote procedure call handle.

RPC_S_INVALID_ASYNC_HANDLE       1914L






// Invalid asynchronous RPC call handle for this operation.

RPC_S_INVALID_ASYNC_CALL         1915L






// The RPC pipe object has already been closed.

RPC_X_PIPE_CLOSED                1916L






// The RPC call completed before all pipes were processed.

RPC_X_PIPE_DISCIPLINE_ERROR      1917L






// No more data is available from the RPC pipe.

RPC_X_PIPE_EMPTY                 1918L






// No site name is available for this machine.

ERROR_NO_SITENAME                1919L






// The file cannot be accessed by the system.

ERROR_CANT_ACCESS_FILE           1920L






// The name of the file cannot be resolved by the system.

ERROR_CANT_RESOLVE_FILENAME      1921L






// The entry is not of the expected type.

RPC_S_ENTRY_TYPE_MISMATCH        1922L






// Not all object UUIDs could be exported to the specified entry.

RPC_S_NOT_ALL_OBJS_EXPORTED      1923L






// Interface could not be exported to the specified entry.

RPC_S_INTERFACE_NOT_EXPORTED     1924L






// The specified profile entry could not be added.

RPC_S_PROFILE_NOT_ADDED          1925L






// The specified profile element could not be added.

RPC_S_PRF_ELT_NOT_ADDED          1926L






// The specified profile element could not be removed.

RPC_S_PRF_ELT_NOT_REMOVED        1927L






// The group element could not be added.

RPC_S_GRP_ELT_NOT_ADDED          1928L






// The group element could not be removed.

RPC_S_GRP_ELT_NOT_REMOVED        1929L






// The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.

ERROR_KM_DRIVER_BLOCKED          1930L






// The context has expired and can no longer be used.

ERROR_CONTEXT_EXPIRED            1931L






// The current user's delegated trust creation quota has been exceeded.

ERROR_PER_USER_TRUST_QUOTA_EXCEEDED 1932L






// The total delegated trust creation quota has been exceeded.

ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED 1933L






// The current user's delegated trust deletion quota has been exceeded.

ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED 1934L






// The computer you are signing into is protected by an authentication firewall. The specified account is not allowed to authenticate to the computer.

ERROR_AUTHENTICATION_FIREWALL_FAILED 1935L






// Remote connections to the Print Spooler are blocked by a policy set on your machine.

ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED 1936L






// Authentication failed because NTLM authentication has been disabled.

ERROR_NTLM_BLOCKED               1937L






// Logon Failure: EAS policy requires that the user change their password before this operation can be performed.

ERROR_PASSWORD_CHANGE_REQUIRED   1938L






// An administrator has restricted sign in. To sign in, make sure your device is connected to the Internet, and have your administrator sign in first.

ERROR_LOST_MODE_LOGON_RESTRICTION 1939L


///////////////////////////////////////////////////
//                                               //
//              OpenGL Error codes               //
//                                               //
//                 2000 to 2009                  //
///////////////////////////////////////////////////






// The pixel format is invalid.

ERROR_INVALID_PIXEL_FORMAT       2000L






// The specified driver is invalid.

ERROR_BAD_DRIVER                 2001L






// The window style or class attribute is invalid for this operation.

ERROR_INVALID_WINDOW_STYLE       2002L






// The requested metafile operation is not supported.

ERROR_METAFILE_NOT_SUPPORTED     2003L






// The requested transformation operation is not supported.

ERROR_TRANSFORM_NOT_SUPPORTED    2004L






// The requested clipping operation is not supported.

ERROR_CLIPPING_NOT_SUPPORTED     2005L


///////////////////////////////////////////////////
//                                               //
//       Image Color Management Error codes      //
//                                               //
//                 2010 to 2049                  //
///////////////////////////////////////////////////






// The specified color management module is invalid.

ERROR_INVALID_CMM                2010L






// The specified color profile is invalid.

ERROR_INVALID_PROFILE            2011L






// The specified tag was not found.

ERROR_TAG_NOT_FOUND              2012L






// A required tag is not present.

ERROR_TAG_NOT_PRESENT            2013L






// The specified tag is already present.

ERROR_DUPLICATE_TAG              2014L






// The specified color profile is not associated with the specified device.

ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE 2015L






// The specified color profile was not found.

ERROR_PROFILE_NOT_FOUND          2016L






// The specified color space is invalid.

ERROR_INVALID_COLORSPACE         2017L






// Image Color Management is not enabled.

ERROR_ICM_NOT_ENABLED            2018L






// There was an error while deleting the color transform.

ERROR_DELETING_ICM_XFORM         2019L






// The specified color transform is invalid.

ERROR_INVALID_TRANSFORM          2020L






// The specified transform does not match the bitmap's color space.

ERROR_COLORSPACE_MISMATCH        2021L






// The specified named color index is not present in the profile.

ERROR_INVALID_COLORINDEX         2022L






// The specified profile is intended for a device of a different type than the specified device.

ERROR_PROFILE_DOES_NOT_MATCH_DEVICE 2023L


///////////////////////////////////////////////////
//                                               //
//             Winnet32 Error codes              //
//                                               //
//                 2100 to 2999                  //
//                                               //
// The range 2100 through 2999 is reserved for   //
// network status codes. See lmerr.h for a       //
// complete listing                              //
///////////////////////////////////////////////////






// The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.

ERROR_CONNECTED_OTHER_PASSWORD   2108L






// The network connection was made successfully using default credentials.

ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT 2109L






// The specified username is invalid.

ERROR_BAD_USERNAME               2202L






// This network connection does not exist.

ERROR_NOT_CONNECTED              2250L






// This network connection has files open or requests pending.

ERROR_OPEN_FILES                 2401L






// Active connections still exist.

ERROR_ACTIVE_CONNECTIONS         2402L






// The device is in use by an active process and cannot be disconnected.

ERROR_DEVICE_IN_USE              2404L


///////////////////////////////////////////////////
//                                               //
//           Win32 Spooler Error codes           //
//                                               //
//                 3000 to 3049                  //
///////////////////////////////////////////////////






// The specified print monitor is unknown.

ERROR_UNKNOWN_PRINT_MONITOR      3000L






// The specified printer driver is currently in use.

ERROR_PRINTER_DRIVER_IN_USE      3001L






// The spool file was not found.

ERROR_SPOOL_FILE_NOT_FOUND       3002L






// A StartDocPrinter call was not issued.

ERROR_SPL_NO_STARTDOC            3003L






// An AddJob call was not issued.

ERROR_SPL_NO_ADDJOB              3004L






// The specified print processor has already been installed.

ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED 3005L






// The specified print monitor has already been installed.

ERROR_PRINT_MONITOR_ALREADY_INSTALLED 3006L






// The specified print monitor does not have the required functions.

ERROR_INVALID_PRINT_MONITOR      3007L






// The specified print monitor is currently in use.

ERROR_PRINT_MONITOR_IN_USE       3008L






// The requested operation is not allowed when there are jobs queued to the printer.

ERROR_PRINTER_HAS_JOBS_QUEUED    3009L






// The requested operation is successful. Changes will not be effective until the system is rebooted.

ERROR_SUCCESS_REBOOT_REQUIRED    3010L






// The requested operation is successful. Changes will not be effective until the service is restarted.

ERROR_SUCCESS_RESTART_REQUIRED   3011L






// No printers were found.

ERROR_PRINTER_NOT_FOUND          3012L






// The printer driver is known to be unreliable.

ERROR_PRINTER_DRIVER_WARNED      3013L






// The printer driver is known to harm the system.

ERROR_PRINTER_DRIVER_BLOCKED     3014L






// The specified printer driver package is currently in use.

ERROR_PRINTER_DRIVER_PACKAGE_IN_USE 3015L






// Unable to find a core driver package that is required by the printer driver package.

ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND 3016L






// The requested operation failed. A system reboot is required to roll back changes made.

ERROR_FAIL_REBOOT_REQUIRED       3017L






// The requested operation failed. A system reboot has been initiated to roll back changes made.

ERROR_FAIL_REBOOT_INITIATED      3018L






// The specified printer driver was not found on the system and needs to be downloaded.

ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED 3019L






// The requested print job has failed to print. A print system update requires the job to be resubmitted.

ERROR_PRINT_JOB_RESTART_REQUIRED 3020L






// The printer driver does not contain a valid manifest, or contains too many manifests.

ERROR_INVALID_PRINTER_DRIVER_MANIFEST 3021L






// The specified printer cannot be shared.

ERROR_PRINTER_NOT_SHAREABLE      3022L


///////////////////////////////////////////////////
//                                               //
//           CopyFile ext. Error codes           //
//                                               //
//                 3050 to 3059                  //
///////////////////////////////////////////////////






// The operation was paused.

ERROR_REQUEST_PAUSED             3050L


///////////////////////////////////////////////////
//                                               //
//           AppExec Error codes                 //
//                                               //
//                 3060 to 3079                  //
///////////////////////////////////////////////////






// The condition supplied for the app execution request was not satisfied, so the request was not performed.

ERROR_APPEXEC_CONDITION_NOT_SATISFIED 3060L






// The supplied handle has been invalidated and may not be used for the requested operation.

ERROR_APPEXEC_HANDLE_INVALIDATED 3061L






// The supplied host generation has been invalidated and may not be used for the requested operation.

ERROR_APPEXEC_INVALID_HOST_GENERATION 3062L






// An attempt to register a process failed because the target host was not in a valid state to receive process registrations.

ERROR_APPEXEC_UNEXPECTED_PROCESS_REGISTRATION 3063L






// The host is not in a valid state to support the execution request.

ERROR_APPEXEC_INVALID_HOST_STATE 3064L






// The operation was not completed because a required resource donor was not found for the host.

ERROR_APPEXEC_NO_DONOR           3065L






// The operation was not completed because an unexpected host ID was encountered.

ERROR_APPEXEC_HOST_ID_MISMATCH   3066L






// The operation was not completed because the specified user was not known to the service.

ERROR_APPEXEC_UNKNOWN_USER       3067L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 3080 to 3199                  //
///////////////////////////////////////////////////



//               the message range
//                 3200 to 3299
//      is reserved and used in isolation lib


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 3300 to 3899                  //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//                IO Error Codes                 //
//                                               //
//                 3900 to 3999                  //
///////////////////////////////////////////////////






// Reissue the given operation as a cached IO operation

ERROR_IO_REISSUE_AS_CACHED       3950L



///////////////////////////////////////////////////
//                                               //
//                Wins Error codes               //
//                                               //
//                 4000 to 4049                  //
///////////////////////////////////////////////////






// WINS encountered an error while processing the command.

ERROR_WINS_INTERNAL              4000L






// The local WINS cannot be deleted.

ERROR_CAN_NOT_DEL_LOCAL_WINS     4001L






// The importation from the file failed.

ERROR_STATIC_INIT                4002L






// The backup failed. Was a full backup done before?

ERROR_INC_BACKUP                 4003L






// The backup failed. Check the directory to which you are backing the database.

ERROR_FULL_BACKUP                4004L






// The name does not exist in the WINS database.

ERROR_REC_NON_EXISTENT           4005L






// Replication with a nonconfigured partner is not allowed.

ERROR_RPL_NOT_ALLOWED            4006L


///////////////////////////////////////////////////
//                                               //
//              PeerDist Error codes             //
//                                               //
//                 4050 to 4099                  //
///////////////////////////////////////////////////






// The version of the supplied content information is not supported.

PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED 4050L






// The supplied content information is malformed.

PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO 4051L






// The requested data cannot be found in local or peer caches.

PEERDIST_ERROR_MISSING_DATA      4052L






// No more data is available or required.

PEERDIST_ERROR_NO_MORE           4053L






// The supplied object has not been initialized.

PEERDIST_ERROR_NOT_INITIALIZED   4054L






// The supplied object has already been initialized.

PEERDIST_ERROR_ALREADY_INITIALIZED 4055L






// A shutdown operation is already in progress.

PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS 4056L






// The supplied object has already been invalidated.

PEERDIST_ERROR_INVALIDATED       4057L






// An element already exists and was not replaced.

PEERDIST_ERROR_ALREADY_EXISTS    4058L






// Can not cancel the requested operation as it has already been completed.

PEERDIST_ERROR_OPERATION_NOTFOUND 4059L






// Can not perform the requested operation because it has already been carried out.

PEERDIST_ERROR_ALREADY_COMPLETED 4060L






// An operation accessed data beyond the bounds of valid data.

PEERDIST_ERROR_OUT_OF_BOUNDS     4061L






// The requested version is not supported.

PEERDIST_ERROR_VERSION_UNSUPPORTED 4062L






// A configuration value is invalid.

PEERDIST_ERROR_INVALID_CONFIGURATION 4063L






// The SKU is not licensed.

PEERDIST_ERROR_NOT_LICENSED      4064L






// PeerDist Service is still initializing and will be available shortly.

PEERDIST_ERROR_SERVICE_UNAVAILABLE 4065L






// Communication with one or more computers will be temporarily blocked due to recent errors.

PEERDIST_ERROR_TRUST_FAILURE     4066L


///////////////////////////////////////////////////
//                                               //
//               DHCP Error codes                //
//                                               //
//                 4100 to 4149                  //
///////////////////////////////////////////////////






// The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address.

ERROR_DHCP_ADDRESS_CONFLICT      4100L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 4150 to 4199                  //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//               WMI Error codes                 //
//                                               //
//                 4200 to 4249                  //
///////////////////////////////////////////////////






// The GUID passed was not recognized as valid by a WMI data provider.

ERROR_WMI_GUID_NOT_FOUND         4200L






// The instance name passed was not recognized as valid by a WMI data provider.

ERROR_WMI_INSTANCE_NOT_FOUND     4201L






// The data item ID passed was not recognized as valid by a WMI data provider.

ERROR_WMI_ITEMID_NOT_FOUND       4202L






// The WMI request could not be completed and should be retried.

ERROR_WMI_TRY_AGAIN              4203L






// The WMI data provider could not be located.

ERROR_WMI_DP_NOT_FOUND           4204L






// The WMI data provider references an instance set that has not been registered.

ERROR_WMI_UNRESOLVED_INSTANCE_REF 4205L






// The WMI data block or event notification has already been enabled.

ERROR_WMI_ALREADY_ENABLED        4206L






// The WMI data block is no longer available.

ERROR_WMI_GUID_DISCONNECTED      4207L






// The WMI data service is not available.

ERROR_WMI_SERVER_UNAVAILABLE     4208L






// The WMI data provider failed to carry out the request.

ERROR_WMI_DP_FAILED              4209L






// The WMI MOF information is not valid.

ERROR_WMI_INVALID_MOF            4210L






// The WMI registration information is not valid.

ERROR_WMI_INVALID_REGINFO        4211L






// The WMI data block or event notification has already been disabled.

ERROR_WMI_ALREADY_DISABLED       4212L






// The WMI data item or data block is read only.

ERROR_WMI_READ_ONLY              4213L






// The WMI data item or data block could not be changed.

ERROR_WMI_SET_FAILURE            4214L


///////////////////////////////////////////////////
//                                               //
//      app container Specific Error Codes        //
//                                               //
//                 4250 to 4299                  //
///////////////////////////////////////////////////






// This operation is only valid in the context of an app container.

ERROR_NOT_APPCONTAINER           4250L






// This application can only run in the context of an app container.

ERROR_APPCONTAINER_REQUIRED      4251L






// This functionality is not supported in the context of an app container.

ERROR_NOT_SUPPORTED_IN_APPCONTAINER 4252L






// The length of the SID supplied is not a valid length for app container SIDs.

ERROR_INVALID_PACKAGE_SID_LENGTH 4253L

///////////////////////////////////////////////////
//                                               //
//        RSM (Media Services) Error codes       //
//                                               //
//                 4300 to 4349                  //
///////////////////////////////////////////////////






// The media identifier does not represent a valid medium.

ERROR_INVALID_MEDIA              4300L






// The library identifier does not represent a valid library.

ERROR_INVALID_LIBRARY            4301L






// The media pool identifier does not represent a valid media pool.

ERROR_INVALID_MEDIA_POOL         4302L






// The drive and medium are not compatible or exist in different libraries.

ERROR_DRIVE_MEDIA_MISMATCH       4303L






// The medium currently exists in an offline library and must be online to perform this operation.

ERROR_MEDIA_OFFLINE              4304L






// The operation cannot be performed on an offline library.

ERROR_LIBRARY_OFFLINE            4305L






// The library, drive, or media pool is empty.

ERROR_EMPTY                      4306L






// The library, drive, or media pool must be empty to perform this operation.

ERROR_NOT_EMPTY                  4307L






// No media is currently available in this media pool or library.

ERROR_MEDIA_UNAVAILABLE          4308L






// A resource required for this operation is disabled.

ERROR_RESOURCE_DISABLED          4309L






// The media identifier does not represent a valid cleaner.

ERROR_INVALID_CLEANER            4310L






// The drive cannot be cleaned or does not support cleaning.

ERROR_UNABLE_TO_CLEAN            4311L






// The object identifier does not represent a valid object.

ERROR_OBJECT_NOT_FOUND           4312L






// Unable to read from or write to the database.

ERROR_DATABASE_FAILURE           4313L






// The database is full.

ERROR_DATABASE_FULL              4314L






// The medium is not compatible with the device or media pool.

ERROR_MEDIA_INCOMPATIBLE         4315L






// The resource required for this operation does not exist.

ERROR_RESOURCE_NOT_PRESENT       4316L






// The operation identifier is not valid.

ERROR_INVALID_OPERATION          4317L






// The media is not mounted or ready for use.

ERROR_MEDIA_NOT_AVAILABLE        4318L






// The device is not ready for use.

ERROR_DEVICE_NOT_AVAILABLE       4319L






// The operator or administrator has refused the request.

ERROR_REQUEST_REFUSED            4320L






// The drive identifier does not represent a valid drive.

ERROR_INVALID_DRIVE_OBJECT       4321L






// Library is full. No slot is available for use.

ERROR_LIBRARY_FULL               4322L






// The transport cannot access the medium.

ERROR_MEDIUM_NOT_ACCESSIBLE      4323L






// Unable to load the medium into the drive.

ERROR_UNABLE_TO_LOAD_MEDIUM      4324L






// Unable to retrieve the drive status.

ERROR_UNABLE_TO_INVENTORY_DRIVE  4325L






// Unable to retrieve the slot status.

ERROR_UNABLE_TO_INVENTORY_SLOT   4326L






// Unable to retrieve status about the transport.

ERROR_UNABLE_TO_INVENTORY_TRANSPORT 4327L






// Cannot use the transport because it is already in use.

ERROR_TRANSPORT_FULL             4328L






// Unable to open or close the inject/eject port.

ERROR_CONTROLLING_IEPORT         4329L






// Unable to eject the medium because it is in a drive.

ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA 4330L






// A cleaner slot is already reserved.

ERROR_CLEANER_SLOT_SET           4331L






// A cleaner slot is not reserved.

ERROR_CLEANER_SLOT_NOT_SET       4332L






// The cleaner cartridge has performed the maximum number of drive cleanings.

ERROR_CLEANER_CARTRIDGE_SPENT    4333L






// Unexpected on-medium identifier.

ERROR_UNEXPECTED_OMID            4334L






// The last remaining item in this group or resource cannot be deleted.

ERROR_CANT_DELETE_LAST_ITEM      4335L






// The message provided exceeds the maximum size allowed for this parameter.

ERROR_MESSAGE_EXCEEDS_MAX_SIZE   4336L






// The volume contains system or paging files.

ERROR_VOLUME_CONTAINS_SYS_FILES  4337L






// The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.

ERROR_INDIGENOUS_TYPE            4338L






// This offline media cannot be mounted on this system since no enabled drives are present which can be used.

ERROR_NO_SUPPORTING_DRIVES       4339L






// A cleaner cartridge is present in the tape library.

ERROR_CLEANER_CARTRIDGE_INSTALLED 4340L






// Cannot use the inject/eject port because it is not empty.

ERROR_IEPORT_FULL                4341L


///////////////////////////////////////////////////
//                                               //
//       Remote Storage Service Error codes      //
//                                               //
//                 4350 to 4389                  //
///////////////////////////////////////////////////






// This file is currently not available for use on this computer.

ERROR_FILE_OFFLINE               4350L






// The remote storage service is not operational at this time.

ERROR_REMOTE_STORAGE_NOT_ACTIVE  4351L






// The remote storage service encountered a media error.

ERROR_REMOTE_STORAGE_MEDIA_ERROR 4352L


///////////////////////////////////////////////////
//                                               //
//           Reparse Point Error codes           //
//                                               //
//                 4390 to 4399                  //
///////////////////////////////////////////////////






// The file or directory is not a reparse point.

ERROR_NOT_A_REPARSE_POINT        4390L






// The reparse point attribute cannot be set because it conflicts with an existing attribute.

ERROR_REPARSE_ATTRIBUTE_CONFLICT 4391L






// The data present in the reparse point buffer is invalid.

ERROR_INVALID_REPARSE_DATA       4392L






// The tag present in the reparse point buffer is invalid.

ERROR_REPARSE_TAG_INVALID        4393L






// There is a mismatch between the tag specified in the request and the tag present in the reparse point.

ERROR_REPARSE_TAG_MISMATCH       4394L






// The object manager encountered a reparse point while retrieving an object.

ERROR_REPARSE_POINT_ENCOUNTERED  4395L


///////////////////////////////////////////////////
//                                               //
//         Fast Cache Specific Error Codes       //
//                                               //
//                 4400 to 4419                  //
///////////////////////////////////////////////////






// Fast Cache data not found.

ERROR_APP_DATA_NOT_FOUND         4400L






// Fast Cache data expired.

ERROR_APP_DATA_EXPIRED           4401L






// Fast Cache data corrupt.

ERROR_APP_DATA_CORRUPT           4402L






// Fast Cache data has exceeded its max size and cannot be updated.

ERROR_APP_DATA_LIMIT_EXCEEDED    4403L






// Fast Cache has been ReArmed and requires a reboot until it can be updated.

ERROR_APP_DATA_REBOOT_REQUIRED   4404L


///////////////////////////////////////////////////
//                                               //
//             SecureBoot Error codes            //
//                                               //
//                 4420 to 4439                  //
///////////////////////////////////////////////////






// Secure Boot detected that rollback of protected data has been attempted.

ERROR_SECUREBOOT_ROLLBACK_DETECTED 4420L






// The value is protected by Secure Boot policy and cannot be modified or deleted.

ERROR_SECUREBOOT_POLICY_VIOLATION 4421L






// The Secure Boot policy is invalid.

ERROR_SECUREBOOT_INVALID_POLICY  4422L






// A new Secure Boot policy did not contain the current publisher on its update list.

ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND 4423L






// The Secure Boot policy is either not signed or is signed by a non-trusted signer.

ERROR_SECUREBOOT_POLICY_NOT_SIGNED 4424L






// Secure Boot is not enabled on this machine.

ERROR_SECUREBOOT_NOT_ENABLED     4425L






// Secure Boot requires that certain files and drivers are not replaced by other files or drivers.

ERROR_SECUREBOOT_FILE_REPLACED   4426L






// The Secure Boot Supplemental Policy file was not authorized on this machine.

ERROR_SECUREBOOT_POLICY_NOT_AUTHORIZED 4427L






// The Supplemental Policy is not recognized on this device.

ERROR_SECUREBOOT_POLICY_UNKNOWN  4428L






// The Antirollback version was not found in the Secure Boot Policy.

ERROR_SECUREBOOT_POLICY_MISSING_ANTIROLLBACKVERSION 4429L






// The Platform ID specified in the Secure Boot policy does not match the Platform ID on this device.

ERROR_SECUREBOOT_PLATFORM_ID_MISMATCH 4430L






// The Secure Boot policy file has an older Antirollback Version than this device.

ERROR_SECUREBOOT_POLICY_ROLLBACK_DETECTED 4431L






// The Secure Boot policy file does not match the upgraded legacy policy.

ERROR_SECUREBOOT_POLICY_UPGRADE_MISMATCH 4432L






// The Secure Boot policy file is required but could not be found.

ERROR_SECUREBOOT_REQUIRED_POLICY_FILE_MISSING 4433L






// Supplemental Secure Boot policy file can not be loaded as a base Secure Boot policy.

ERROR_SECUREBOOT_NOT_BASE_POLICY 4434L






// Base Secure Boot policy file can not be loaded as a Supplemental Secure Boot policy.

ERROR_SECUREBOOT_NOT_SUPPLEMENTAL_POLICY 4435L


///////////////////////////////////////////////////
//                                               //
//       File System Specific Error Codes        //
//                                               //
//                 4440 to 4499                  //
///////////////////////////////////////////////////






// The copy offload read operation is not supported by a filter.

ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED 4440L






// The copy offload write operation is not supported by a filter.

ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED 4441L






// The copy offload read operation is not supported for the file.

ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED 4442L






// The copy offload write operation is not supported for the file.

ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED 4443L






// This file is currently associated with a different stream id.

ERROR_ALREADY_HAS_STREAM_ID      4444L






// The volume must undergo garbage collection.

ERROR_SMR_GARBAGE_COLLECTION_REQUIRED 4445L






// The WOF driver encountered a corruption in WIM image's Header.

ERROR_WOF_WIM_HEADER_CORRUPT     4446L






// The WOF driver encountered a corruption in WIM image's Resource Table.

ERROR_WOF_WIM_RESOURCE_TABLE_CORRUPT 4447L






// The WOF driver encountered a corruption in the compressed file's Resource Table.

ERROR_WOF_FILE_RESOURCE_TABLE_CORRUPT 4448L


///////////////////////////////////////////////////
//                                               //
//    Single Instance Store (SIS) Error codes    //
//                                               //
//                 4500 to 4549                  //
///////////////////////////////////////////////////






// Single Instance Storage is not available on this volume.

ERROR_VOLUME_NOT_SIS_ENABLED     4500L


///////////////////////////////////////////////////
//                                               //
//             System Integrity Error codes      //
//                                               //
//                 4550 to 4559                  //
///////////////////////////////////////////////////






// System Integrity detected that policy rollback has been attempted.

ERROR_SYSTEM_INTEGRITY_ROLLBACK_DETECTED 4550L






// Your organization used Device Guard to block this app. Contact your support person for more info.

ERROR_SYSTEM_INTEGRITY_POLICY_VIOLATION 4551L






// The System Integrity policy is invalid.

ERROR_SYSTEM_INTEGRITY_INVALID_POLICY 4552L






// The System Integrity policy is either not signed or is signed by a non-trusted signer.

ERROR_SYSTEM_INTEGRITY_POLICY_NOT_SIGNED 4553L






// The number of System Integrity policies is out of limit.

ERROR_SYSTEM_INTEGRITY_TOO_MANY_POLICIES 4554L






// The Code Integrity supplemental policy is not authorized by a Code Integrity base policy.

ERROR_SYSTEM_INTEGRITY_SUPPLEMENTAL_POLICY_NOT_AUTHORIZED 4555L


///////////////////////////////////////////////////
//                                               //
//             VSM Error codes                   //
//                                               //
//                 4560 to 4569                  //
///////////////////////////////////////////////////






// Virtual Secure Mode (VSM) is not initialized. The hypervisor or VSM may not be present or enabled.

ERROR_VSM_NOT_INITIALIZED        4560L






// The hypervisor is not protecting DMA because an IOMMU is not present or not enabled in the BIOS.

ERROR_VSM_DMA_PROTECTION_NOT_IN_USE 4561L

///////////////////////////////////////////////////
//                                               //
//         Platform Manifest Error Codes         //
//                                               //
//                 4570 to 4579                  //
///////////////////////////////////////////////////






// The Platform Manifest file was not authorized on this machine.

ERROR_PLATFORM_MANIFEST_NOT_AUTHORIZED 4570L






// The Platform Manifest file was not valid.

ERROR_PLATFORM_MANIFEST_INVALID  4571L






// The file is not authorized on this platform because an entry was not found in the Platform Manifest.

ERROR_PLATFORM_MANIFEST_FILE_NOT_AUTHORIZED 4572L






// The catalog is not authorized on this platform because an entry was not found in the Platform Manifest.

ERROR_PLATFORM_MANIFEST_CATALOG_NOT_AUTHORIZED 4573L






// The file is not authorized on this platform because a Binary ID was not found in the embedded signature.

ERROR_PLATFORM_MANIFEST_BINARY_ID_NOT_FOUND 4574L






// No active Platform Manifest exists on this system.

ERROR_PLATFORM_MANIFEST_NOT_ACTIVE 4575L






// The Platform Manifest file was not properly signed.

ERROR_PLATFORM_MANIFEST_NOT_SIGNED 4576L

///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 4580 to 4599                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//             Cluster Error codes               //
//                                               //
//                 5000 to 5999                  //
///////////////////////////////////////////////////






// The operation cannot be completed because other resources are dependent on this resource.

ERROR_DEPENDENT_RESOURCE_EXISTS  5001L






// The cluster resource dependency cannot be found.

ERROR_DEPENDENCY_NOT_FOUND       5002L






// The cluster resource cannot be made dependent on the specified resource because it is already dependent.

ERROR_DEPENDENCY_ALREADY_EXISTS  5003L






// The cluster resource is not online.

ERROR_RESOURCE_NOT_ONLINE        5004L






// A cluster node is not available for this operation.

ERROR_HOST_NODE_NOT_AVAILABLE    5005L






// The cluster resource is not available.

ERROR_RESOURCE_NOT_AVAILABLE     5006L






// The cluster resource could not be found.

ERROR_RESOURCE_NOT_FOUND         5007L






// The cluster is being shut down.

ERROR_SHUTDOWN_CLUSTER           5008L






// A cluster node cannot be evicted from the cluster unless the node is down or it is the last node.

ERROR_CANT_EVICT_ACTIVE_NODE     5009L






// The object already exists.

ERROR_OBJECT_ALREADY_EXISTS      5010L






// The object is already in the list.

ERROR_OBJECT_IN_LIST             5011L






// The cluster group is not available for any new requests.

ERROR_GROUP_NOT_AVAILABLE        5012L






// The cluster group could not be found.

ERROR_GROUP_NOT_FOUND            5013L






// The operation could not be completed because the cluster group is not online.

ERROR_GROUP_NOT_ONLINE           5014L






// The operation failed because either the specified cluster node is not the owner of the resource, or the node is not a possible owner of the resource.

ERROR_HOST_NODE_NOT_RESOURCE_OWNER 5015L






// The operation failed because either the specified cluster node is not the owner of the group, or the node is not a possible owner of the group.

ERROR_HOST_NODE_NOT_GROUP_OWNER  5016L






// The cluster resource could not be created in the specified resource monitor.

ERROR_RESMON_CREATE_FAILED       5017L






// The cluster resource could not be brought online by the resource monitor.

ERROR_RESMON_ONLINE_FAILED       5018L






// The operation could not be completed because the cluster resource is online.

ERROR_RESOURCE_ONLINE            5019L






// The cluster resource could not be deleted or brought offline because it is the quorum resource.

ERROR_QUORUM_RESOURCE            5020L






// The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource.

ERROR_NOT_QUORUM_CAPABLE         5021L






// The cluster software is shutting down.

ERROR_CLUSTER_SHUTTING_DOWN      5022L






// The group or resource is not in the correct state to perform the requested operation.

ERROR_INVALID_STATE              5023L






// The properties were stored but not all changes will take effect until the next time the resource is brought online.

ERROR_RESOURCE_PROPERTIES_STORED 5024L






// The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class.

ERROR_NOT_QUORUM_CLASS           5025L






// The cluster resource could not be deleted since it is a core resource.

ERROR_CORE_RESOURCE              5026L






// The quorum resource failed to come online.

ERROR_QUORUM_RESOURCE_ONLINE_FAILED 5027L






// The quorum log could not be created or mounted successfully.

ERROR_QUORUMLOG_OPEN_FAILED      5028L






// The cluster log is corrupt.

ERROR_CLUSTERLOG_CORRUPT         5029L






// The record could not be written to the cluster log since it exceeds the maximum size.

ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE 5030L






// The cluster log exceeds its maximum size.

ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE 5031L






// No checkpoint record was found in the cluster log.

ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND 5032L






// The minimum required disk space needed for logging is not available.

ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE 5033L






// The cluster node failed to take control of the quorum resource because the resource is owned by another active node.

ERROR_QUORUM_OWNER_ALIVE         5034L






// A cluster network is not available for this operation.

ERROR_NETWORK_NOT_AVAILABLE      5035L






// A cluster node is not available for this operation.

ERROR_NODE_NOT_AVAILABLE         5036L






// All cluster nodes must be running to perform this operation.

ERROR_ALL_NODES_NOT_AVAILABLE    5037L






// A cluster resource failed.

ERROR_RESOURCE_FAILED            5038L






// The cluster node is not valid.

ERROR_CLUSTER_INVALID_NODE       5039L






// The cluster node already exists.

ERROR_CLUSTER_NODE_EXISTS        5040L






// A node is in the process of joining the cluster.

ERROR_CLUSTER_JOIN_IN_PROGRESS   5041L






// The cluster node was not found.

ERROR_CLUSTER_NODE_NOT_FOUND     5042L






// The cluster local node information was not found.

ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND 5043L






// The cluster network already exists.

ERROR_CLUSTER_NETWORK_EXISTS     5044L






// The cluster network was not found.

ERROR_CLUSTER_NETWORK_NOT_FOUND  5045L






// The cluster network interface already exists.

ERROR_CLUSTER_NETINTERFACE_EXISTS 5046L






// The cluster network interface was not found.

ERROR_CLUSTER_NETINTERFACE_NOT_FOUND 5047L






// The cluster request is not valid for this object.

ERROR_CLUSTER_INVALID_REQUEST    5048L






// The cluster network provider is not valid.

ERROR_CLUSTER_INVALID_NETWORK_PROVIDER 5049L






// The cluster node is down.

ERROR_CLUSTER_NODE_DOWN          5050L






// The cluster node is not reachable.

ERROR_CLUSTER_NODE_UNREACHABLE   5051L






// The cluster node is not a member of the cluster.

ERROR_CLUSTER_NODE_NOT_MEMBER    5052L






// A cluster join operation is not in progress.

ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS 5053L






// The cluster network is not valid.

ERROR_CLUSTER_INVALID_NETWORK    5054L






// The cluster node is up.

ERROR_CLUSTER_NODE_UP            5056L






// The cluster IP address is already in use.

ERROR_CLUSTER_IPADDR_IN_USE      5057L






// The cluster node is not paused.

ERROR_CLUSTER_NODE_NOT_PAUSED    5058L






// No cluster security context is available.

ERROR_CLUSTER_NO_SECURITY_CONTEXT 5059L






// The cluster network is not configured for internal cluster communication.

ERROR_CLUSTER_NETWORK_NOT_INTERNAL 5060L






// The cluster node is already up.

ERROR_CLUSTER_NODE_ALREADY_UP    5061L






// The cluster node is already down.

ERROR_CLUSTER_NODE_ALREADY_DOWN  5062L






// The cluster network is already online.

ERROR_CLUSTER_NETWORK_ALREADY_ONLINE 5063L






// The cluster network is already offline.

ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE 5064L






// The cluster node is already a member of the cluster.

ERROR_CLUSTER_NODE_ALREADY_MEMBER 5065L






// The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.

ERROR_CLUSTER_LAST_INTERNAL_NETWORK 5066L






// One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.

ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS 5067L






// This operation cannot currently be performed on the cluster group containing the quorum resource.

ERROR_INVALID_OPERATION_ON_QUORUM 5068L






// The cluster quorum resource is not allowed to have any dependencies.

ERROR_DEPENDENCY_NOT_ALLOWED     5069L






// The cluster node is paused.

ERROR_CLUSTER_NODE_PAUSED        5070L






// The cluster resource cannot be brought online. The owner node cannot run this resource.

ERROR_NODE_CANT_HOST_RESOURCE    5071L






// The cluster node is not ready to perform the requested operation.

ERROR_CLUSTER_NODE_NOT_READY     5072L






// The cluster node is shutting down.

ERROR_CLUSTER_NODE_SHUTTING_DOWN 5073L






// The cluster join operation was aborted.

ERROR_CLUSTER_JOIN_ABORTED       5074L






// The node failed to join the cluster because the joining node and other nodes in the cluster have incompatible operating system versions. To get more information about operating system versions of the cluster, run the Validate a Configuration Wizard or the Test-Cluster Windows PowerShell cmdlet.

ERROR_CLUSTER_INCOMPATIBLE_VERSIONS 5075L






// This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.

ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED 5076L






// The system configuration changed during the cluster join or form operation. The join or form operation was aborted.

ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED 5077L






// The specified resource type was not found.

ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND 5078L






// The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.

ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED 5079L






// The specified resource name is not supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.

ERROR_CLUSTER_RESNAME_NOT_FOUND  5080L






// No authentication package could be registered with the RPC server.

ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED 5081L






// You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.

ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST 5082L






// The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.

ERROR_CLUSTER_DATABASE_SEQMISMATCH 5083L






// The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.

ERROR_RESMON_INVALID_STATE       5084L






// A non locker code got a request to reserve the lock for making global updates.

ERROR_CLUSTER_GUM_NOT_LOCKER     5085L






// The quorum disk could not be located by the cluster service.

ERROR_QUORUM_DISK_NOT_FOUND      5086L






// The backed up cluster database is possibly corrupt.

ERROR_DATABASE_BACKUP_CORRUPT    5087L






// A DFS root already exists in this cluster node.

ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT 5088L






// An attempt to modify a resource property failed because it conflicts with another existing property.

ERROR_RESOURCE_PROPERTY_UNCHANGEABLE 5089L






// This operation is not supported on a cluster without an Administrator Access Point.

ERROR_NO_ADMIN_ACCESS_POINT      5090L

/*
 Codes from 4300 through 5889 overlap with codes in ds\published\inc\apperr2.w.
 Do not add any more error codes in that range.
*/





// An operation was attempted that is incompatible with the current membership state of the node.

ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE 5890L






// The quorum resource does not contain the quorum log.

ERROR_CLUSTER_QUORUMLOG_NOT_FOUND 5891L






// The membership engine requested shutdown of the cluster service on this node.

ERROR_CLUSTER_MEMBERSHIP_HALT    5892L






// The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node.

ERROR_CLUSTER_INSTANCE_ID_MISMATCH 5893L






// A matching cluster network for the specified IP address could not be found.

ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP 5894L






// The actual data type of the property did not match the expected data type of the property.

ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH 5895L






// The cluster node was evicted from the cluster successfully, but the node was not cleaned up. To determine what cleanup steps failed and how to recover, see the Failover Clustering application event log using Event Viewer.

ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP 5896L






// Two or more parameter values specified for a resource's properties are in conflict.

ERROR_CLUSTER_PARAMETER_MISMATCH 5897L






// This computer cannot be made a member of a cluster.

ERROR_NODE_CANNOT_BE_CLUSTERED   5898L






// This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed.

ERROR_CLUSTER_WRONG_OS_VERSION   5899L






// A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster.

ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME 5900L






// The cluster configuration action has already been committed.

ERROR_CLUSCFG_ALREADY_COMMITTED  5901L






// The cluster configuration action could not be rolled back.

ERROR_CLUSCFG_ROLLBACK_FAILED    5902L






// The drive letter assigned to a system disk on one node conflicted with the drive letter assigned to a disk on another node.

ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT 5903L






// One or more nodes in the cluster are running a version of Windows that does not support this operation.

ERROR_CLUSTER_OLD_VERSION        5904L






// The name of the corresponding computer account doesn't match the Network Name for this resource.

ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME 5905L






// No network adapters are available.

ERROR_CLUSTER_NO_NET_ADAPTERS    5906L






// The cluster node has been poisoned.

ERROR_CLUSTER_POISONED           5907L






// The group is unable to accept the request since it is moving to another node.

ERROR_CLUSTER_GROUP_MOVING       5908L






// The resource type cannot accept the request since is too busy performing another operation.

ERROR_CLUSTER_RESOURCE_TYPE_BUSY 5909L






// The call to the cluster resource DLL timed out.

ERROR_RESOURCE_CALL_TIMED_OUT    5910L






// The address is not valid for an IPv6 Address resource. A global IPv6 address is required, and it must match a cluster network. Compatibility addresses are not permitted.

ERROR_INVALID_CLUSTER_IPV6_ADDRESS 5911L






// An internal cluster error occurred. A call to an invalid function was attempted.

ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION 5912L






// A parameter value is out of acceptable range.

ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS 5913L






// A network error occurred while sending data to another node in the cluster. The number of bytes transmitted was less than required.

ERROR_CLUSTER_PARTIAL_SEND       5914L






// An invalid cluster registry operation was attempted.

ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION 5915L






// An input string of characters is not properly terminated.

ERROR_CLUSTER_INVALID_STRING_TERMINATION 5916L






// An input string of characters is not in a valid format for the data it represents.

ERROR_CLUSTER_INVALID_STRING_FORMAT 5917L






// An internal cluster error occurred. A cluster database transaction was attempted while a transaction was already in progress.

ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS 5918L






// An internal cluster error occurred. There was an attempt to commit a cluster database transaction while no transaction was in progress.

ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS 5919L






// An internal cluster error occurred. Data was not properly initialized.

ERROR_CLUSTER_NULL_DATA          5920L






// An error occurred while reading from a stream of data. An unexpected number of bytes was returned.

ERROR_CLUSTER_PARTIAL_READ       5921L






// An error occurred while writing to a stream of data. The required number of bytes could not be written.

ERROR_CLUSTER_PARTIAL_WRITE      5922L






// An error occurred while deserializing a stream of cluster data.

ERROR_CLUSTER_CANT_DESERIALIZE_DATA 5923L






// One or more property values for this resource are in conflict with one or more property values associated with its dependent resource(s).

ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT 5924L






// A quorum of cluster nodes was not present to form a cluster.

ERROR_CLUSTER_NO_QUORUM          5925L






// The cluster network is not valid for an IPv6 Address resource, or it does not match the configured address.

ERROR_CLUSTER_INVALID_IPV6_NETWORK 5926L






// The cluster network is not valid for an IPv6 Tunnel resource. Check the configuration of the IP Address resource on which the IPv6 Tunnel resource depends.

ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK 5927L






// Quorum resource cannot reside in the Available Storage group.

ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP 5928L






// The dependencies for this resource are nested too deeply.

ERROR_DEPENDENCY_TREE_TOO_COMPLEX 5929L






// The call into the resource DLL raised an unhandled exception.

ERROR_EXCEPTION_IN_RESOURCE_CALL 5930L






// The RHS process failed to initialize.

ERROR_CLUSTER_RHS_FAILED_INITIALIZATION 5931L






// The Failover Clustering feature is not installed on this node.

ERROR_CLUSTER_NOT_INSTALLED      5932L






// The resources must be online on the same node for this operation

ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE 5933L






// A new node can not be added since this cluster is already at its maximum number of nodes.

ERROR_CLUSTER_MAX_NODES_IN_CLUSTER 5934L






// This cluster can not be created since the specified number of nodes exceeds the maximum allowed limit.

ERROR_CLUSTER_TOO_MANY_NODES     5935L






// An attempt to use the specified cluster name failed because an enabled computer object with the given name already exists in the domain.

ERROR_CLUSTER_OBJECT_ALREADY_USED 5936L






// This cluster cannot be destroyed. It has non-core application groups which must be deleted before the cluster can be destroyed.

ERROR_NONCORE_GROUPS_FOUND       5937L






// File share associated with file share witness resource cannot be hosted by this cluster or any of its nodes.

ERROR_FILE_SHARE_RESOURCE_CONFLICT 5938L






// Eviction of this node is invalid at this time. Due to quorum requirements node eviction will result in cluster shutdown.
// If it is the last node in the cluster, destroy cluster command should be used.

ERROR_CLUSTER_EVICT_INVALID_REQUEST 5939L






// Only one instance of this resource type is allowed in the cluster.

ERROR_CLUSTER_SINGLETON_RESOURCE 5940L






// Only one instance of this resource type is allowed per resource group.

ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE 5941L






// The resource failed to come online due to the failure of one or more provider resources.

ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED 5942L






// The resource has indicated that it cannot come online on any node.

ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR 5943L






// The current operation cannot be performed on this group at this time.

ERROR_CLUSTER_GROUP_BUSY         5944L






// The directory or file is not located on a cluster shared volume.

ERROR_CLUSTER_NOT_SHARED_VOLUME  5945L






// The Security Descriptor does not meet the requirements for a cluster.

ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR 5946L






// There is one or more shared volumes resources configured in the cluster.
// Those resources must be moved to available storage in order for operation to succeed.

ERROR_CLUSTER_SHARED_VOLUMES_IN_USE 5947L






// This group or resource cannot be directly manipulated.
// Use shared volume APIs to perform desired operation.

ERROR_CLUSTER_USE_SHARED_VOLUMES_API 5948L






// Back up is in progress. Please wait for backup completion before trying this operation again.

ERROR_CLUSTER_BACKUP_IN_PROGRESS 5949L






// The path does not belong to a cluster shared volume.

ERROR_NON_CSV_PATH               5950L






// The cluster shared volume is not locally mounted on this node.

ERROR_CSV_VOLUME_NOT_LOCAL       5951L






// The cluster watchdog is terminating.

ERROR_CLUSTER_WATCHDOG_TERMINATING 5952L






// A resource vetoed a move between two nodes because they are incompatible.

ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES 5953L






// The request is invalid either because node weight cannot be changed while the cluster is in disk-only quorum mode, or because changing the node weight would violate the minimum cluster quorum requirements.

ERROR_CLUSTER_INVALID_NODE_WEIGHT 5954L






// The resource vetoed the call.

ERROR_CLUSTER_RESOURCE_VETOED_CALL 5955L






// Resource could not start or run because it could not reserve sufficient system resources.

ERROR_RESMON_SYSTEM_RESOURCES_LACKING 5956L






// A resource vetoed a move between two nodes because the destination currently does not have enough resources to complete the operation.

ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION 5957L






// 
// A resource vetoed a move between two nodes because the source currently does not have enough resources to complete the operation.

ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE 5958L






// 
// The requested operation can not be completed because the group is queued for an operation.

ERROR_CLUSTER_GROUP_QUEUED       5959L






// 
// The requested operation can not be completed because a resource has locked status.

ERROR_CLUSTER_RESOURCE_LOCKED_STATUS 5960L






// 
// The resource cannot move to another node because a cluster shared volume vetoed the operation.

ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED 5961L






// 
// A node drain is already in progress.

ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS 5962L






// 
// Clustered storage is not connected to the node.

ERROR_CLUSTER_DISK_NOT_CONNECTED 5963L






// 
// The disk is not configured in a way to be used with CSV. CSV disks must have at least one partition that is formatted with NTFS or REFS.

ERROR_DISK_NOT_CSV_CAPABLE       5964L






// 
// The resource must be part of the Available Storage group to complete this action.

ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE 5965L






// 
// CSVFS failed operation as volume is in redirected mode.

ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED 5966L






// 
// CSVFS failed operation as volume is not in redirected mode.

ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED 5967L






// 
// Cluster properties cannot be returned at this time.

ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES 5968L






// 
// The clustered disk resource contains software snapshot diff area that are not supported for Cluster Shared Volumes.

ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES 5969L






// 
// The operation cannot be completed because the resource is in maintenance mode.

ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE 5970L






// 
// The operation cannot be completed because of cluster affinity conflicts

ERROR_CLUSTER_AFFINITY_CONFLICT  5971L






// 
// The operation cannot be completed because the resource is a replica virtual machine.

ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE 5972L






// 
// The Cluster Functional Level could not be increased because not all nodes in the cluster support the updated version.

ERROR_CLUSTER_UPGRADE_INCOMPATIBLE_VERSIONS 5973L






// 
// Updating the cluster functional level failed because the cluster is running in fix quorum mode.
// Start additional nodes which are members of the cluster until the cluster reaches quorum and the cluster will automatically
// switch out of fix quorum mode, or stop and restart the cluster without the FixQuorum switch. Once the cluster is out
// of fix quorum mode retry the Update-ClusterFunctionalLevel PowerShell cmdlet to update the cluster functional level.

ERROR_CLUSTER_UPGRADE_FIX_QUORUM_NOT_SUPPORTED 5974L






// 
// The cluster functional level has been successfully updated but not all features are available yet. Restart the cluster by
// using the Stop-Cluster PowerShell cmdlet followed by the Start-Cluster PowerShell cmdlet and all cluster features will
// be available.

ERROR_CLUSTER_UPGRADE_RESTART_REQUIRED 5975L






// 
// The cluster is currently performing a version upgrade.

ERROR_CLUSTER_UPGRADE_IN_PROGRESS 5976L






// 
// The cluster did not successfully complete the version upgrade.

ERROR_CLUSTER_UPGRADE_INCOMPLETE 5977L






// 
// The cluster node is in grace period.

ERROR_CLUSTER_NODE_IN_GRACE_PERIOD 5978L






// 
// The operation has failed because CSV volume was not able to recover in time specified on this file object.

ERROR_CLUSTER_CSV_IO_PAUSE_TIMEOUT 5979L






// 
// The operation failed because the requested node is not currently part of active cluster membership.

ERROR_NODE_NOT_ACTIVE_CLUSTER_MEMBER 5980L






// 
// The operation failed because the requested cluster resource is currently unmonitored.

ERROR_CLUSTER_RESOURCE_NOT_MONITORED 5981L






// 
// The operation failed because a resource does not support running in an unmonitored state.

ERROR_CLUSTER_RESOURCE_DOES_NOT_SUPPORT_UNMONITORED 5982L






// 
// The operation cannot be completed because a resource participates in replication.

ERROR_CLUSTER_RESOURCE_IS_REPLICATED 5983L






// 
// The operation failed because the requested cluster node has been isolated

ERROR_CLUSTER_NODE_ISOLATED      5984L






// 
// The operation failed because the requested cluster node has been quarantined

ERROR_CLUSTER_NODE_QUARANTINED   5985L






// 
// The operation failed because the specified database update condition was not met

ERROR_CLUSTER_DATABASE_UPDATE_CONDITION_FAILED 5986L






// 
// A clustered space is in a degraded condition and the requested action cannot be completed at this time.

ERROR_CLUSTER_SPACE_DEGRADED     5987L






// 
// The operation failed because token delegation for this control is not supported.

ERROR_CLUSTER_TOKEN_DELEGATION_NOT_SUPPORTED 5988L






// 
// The operation has failed because CSV has invalidated this file object.

ERROR_CLUSTER_CSV_INVALID_HANDLE 5989L






// 
// This operation is supported only on the CSV coordinator node.

ERROR_CLUSTER_CSV_SUPPORTED_ONLY_ON_COORDINATOR 5990L






// 
// The cluster group set is not available for any further requests.

ERROR_GROUPSET_NOT_AVAILABLE     5991L






// 
// The cluster group set could not be found.

ERROR_GROUPSET_NOT_FOUND         5992L






// 
// The action cannot be completed at this time because the cluster group set would fall below quorum and not be able to act as a provider.

ERROR_GROUPSET_CANT_PROVIDE      5993L






// 
// The specified parent fault domain is not found.

ERROR_CLUSTER_FAULT_DOMAIN_PARENT_NOT_FOUND 5994L






// 
// The fault domain cannot be a child of the parent specified.

ERROR_CLUSTER_FAULT_DOMAIN_INVALID_HIERARCHY 5995L






// 
// Storage Spaces Direct has rejected the proposed fault domain changes because it impacts the fault tolerance of the storage.

ERROR_CLUSTER_FAULT_DOMAIN_FAILED_S2D_VALIDATION 5996L






// 
// Storage Spaces Direct has rejected the proposed fault domain changes because it reduces the storage connected to the system.

ERROR_CLUSTER_FAULT_DOMAIN_S2D_CONNECTIVITY_LOSS 5997L






// 
// Cluster infrastructure file server creation failed because a valid non-empty file server name was not provided.

ERROR_CLUSTER_INVALID_INFRASTRUCTURE_FILESERVER_NAME 5998L






// 
// The action cannot be completed because the cluster set management cluster is unreachable.

ERROR_CLUSTERSET_MANAGEMENT_CLUSTER_UNREACHABLE 5999L


///////////////////////////////////////////////////
//                                               //
//               EFS Error codes                 //
//                                               //
//                 6000 to 6099                  //
///////////////////////////////////////////////////






// The specified file could not be encrypted.

ERROR_ENCRYPTION_FAILED          6000L






// The specified file could not be decrypted.

ERROR_DECRYPTION_FAILED          6001L






// The specified file is encrypted and the user does not have the ability to decrypt it.

ERROR_FILE_ENCRYPTED             6002L






// There is no valid encryption recovery policy configured for this system.

ERROR_NO_RECOVERY_POLICY         6003L






// The required encryption driver is not loaded for this system.

ERROR_NO_EFS                     6004L






// The file was encrypted with a different encryption driver than is currently loaded.

ERROR_WRONG_EFS                  6005L






// There are no EFS keys defined for the user.

ERROR_NO_USER_KEYS               6006L






// The specified file is not encrypted.

ERROR_FILE_NOT_ENCRYPTED         6007L






// The specified file is not in the defined EFS export format.

ERROR_NOT_EXPORT_FORMAT          6008L






// The specified file is read only.

ERROR_FILE_READ_ONLY             6009L






// The directory has been disabled for encryption.

ERROR_DIR_EFS_DISALLOWED         6010L






// The server is not trusted for remote encryption operation.

ERROR_EFS_SERVER_NOT_TRUSTED     6011L






// Recovery policy configured for this system contains invalid recovery certificate.

ERROR_BAD_RECOVERY_POLICY        6012L






// The encryption algorithm used on the source file needs a bigger key buffer than the one on the destination file.

ERROR_EFS_ALG_BLOB_TOO_BIG       6013L






// The disk partition does not support file encryption.

ERROR_VOLUME_NOT_SUPPORT_EFS     6014L






// This machine is disabled for file encryption.

ERROR_EFS_DISABLED               6015L






// A newer system is required to decrypt this encrypted file.

ERROR_EFS_VERSION_NOT_SUPPORT    6016L






// The remote server sent an invalid response for a file being opened with Client Side Encryption.

ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE 6017L






// Client Side Encryption is not supported by the remote server even though it claims to support it.

ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER 6018L






// File is encrypted and should be opened in Client Side Encryption mode.

ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE 6019L






// A new encrypted file is being created and a $EFS needs to be provided.

ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE 6020L






// The SMB client requested a CSE FSCTL on a non-CSE file.

ERROR_CS_ENCRYPTION_FILE_NOT_CSE 6021L






// The requested operation was blocked by policy. For more information, contact your system administrator.

ERROR_ENCRYPTION_POLICY_DENIES_OPERATION 6022L






// The specified file could not be encrypted with Windows Information Protection.

ERROR_WIP_ENCRYPTION_FAILED      6023L


///////////////////////////////////////////////////
//                                               //
//              BROWSER Error codes              //
//                                               //
//                 6100 to 6199                  //
///////////////////////////////////////////////////

// This message number is for historical purposes and cannot be changed or re-used.





// The list of servers for this workgroup is not currently available

ERROR_NO_BROWSER_SERVERS_FOUND   6118L


///////////////////////////////////////////////////
//                                               //
//            Task Scheduler Error codes         //
//            NET START must understand          //
//                                               //
//                 6200 to 6249                  //
///////////////////////////////////////////////////






// The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts.

SCHED_E_SERVICE_NOT_LOCALSYSTEM  6200L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 6250 to 6599                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//         Common Log (CLFS) Error codes         //
//                                               //
//                 6600 to 6699                  //
///////////////////////////////////////////////////






// Log service encountered an invalid log sector.

ERROR_LOG_SECTOR_INVALID         6600L






// Log service encountered a log sector with invalid block parity.

ERROR_LOG_SECTOR_PARITY_INVALID  6601L






// Log service encountered a remapped log sector.

ERROR_LOG_SECTOR_REMAPPED        6602L






// Log service encountered a partial or incomplete log block.

ERROR_LOG_BLOCK_INCOMPLETE       6603L






// Log service encountered an attempt access data outside the active log range.

ERROR_LOG_INVALID_RANGE          6604L






// Log service user marshalling buffers are exhausted.

ERROR_LOG_BLOCKS_EXHAUSTED       6605L






// Log service encountered an attempt read from a marshalling area with an invalid read context.

ERROR_LOG_READ_CONTEXT_INVALID   6606L






// Log service encountered an invalid log restart area.

ERROR_LOG_RESTART_INVALID        6607L






// Log service encountered an invalid log block version.

ERROR_LOG_BLOCK_VERSION          6608L






// Log service encountered an invalid log block.

ERROR_LOG_BLOCK_INVALID          6609L






// Log service encountered an attempt to read the log with an invalid read mode.

ERROR_LOG_READ_MODE_INVALID      6610L






// Log service encountered a log stream with no restart area.

ERROR_LOG_NO_RESTART             6611L






// Log service encountered a corrupted metadata file.

ERROR_LOG_METADATA_CORRUPT       6612L






// Log service encountered a metadata file that could not be created by the log file system.

ERROR_LOG_METADATA_INVALID       6613L






// Log service encountered a metadata file with inconsistent data.

ERROR_LOG_METADATA_INCONSISTENT  6614L






// Log service encountered an attempt to erroneous allocate or dispose reservation space.

ERROR_LOG_RESERVATION_INVALID    6615L






// Log service cannot delete log file or file system container.

ERROR_LOG_CANT_DELETE            6616L






// Log service has reached the maximum allowable containers allocated to a log file.

ERROR_LOG_CONTAINER_LIMIT_EXCEEDED 6617L






// Log service has attempted to read or write backward past the start of the log.

ERROR_LOG_START_OF_LOG           6618L






// Log policy could not be installed because a policy of the same type is already present.

ERROR_LOG_POLICY_ALREADY_INSTALLED 6619L






// Log policy in question was not installed at the time of the request.

ERROR_LOG_POLICY_NOT_INSTALLED   6620L






// The installed set of policies on the log is invalid.

ERROR_LOG_POLICY_INVALID         6621L






// A policy on the log in question prevented the operation from completing.

ERROR_LOG_POLICY_CONFLICT        6622L






// Log space cannot be reclaimed because the log is pinned by the archive tail.

ERROR_LOG_PINNED_ARCHIVE_TAIL    6623L






// Log record is not a record in the log file.

ERROR_LOG_RECORD_NONEXISTENT     6624L






// Number of reserved log records or the adjustment of the number of reserved log records is invalid.

ERROR_LOG_RECORDS_RESERVED_INVALID 6625L






// Reserved log space or the adjustment of the log space is invalid.

ERROR_LOG_SPACE_RESERVED_INVALID 6626L






// An new or existing archive tail or base of the active log is invalid.

ERROR_LOG_TAIL_INVALID           6627L






// Log space is exhausted.

ERROR_LOG_FULL                   6628L






// The log could not be set to the requested size.

ERROR_COULD_NOT_RESIZE_LOG       6629L






// Log is multiplexed, no direct writes to the physical log is allowed.

ERROR_LOG_MULTIPLEXED            6630L






// The operation failed because the log is a dedicated log.

ERROR_LOG_DEDICATED              6631L






// The operation requires an archive context.

ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS 6632L






// Log archival is in progress.

ERROR_LOG_ARCHIVE_IN_PROGRESS    6633L






// The operation requires a non-ephemeral log, but the log is ephemeral.

ERROR_LOG_EPHEMERAL              6634L






// The log must have at least two containers before it can be read from or written to.

ERROR_LOG_NOT_ENOUGH_CONTAINERS  6635L






// A log client has already registered on the stream.

ERROR_LOG_CLIENT_ALREADY_REGISTERED 6636L






// A log client has not been registered on the stream.

ERROR_LOG_CLIENT_NOT_REGISTERED  6637L






// A request has already been made to handle the log full condition.

ERROR_LOG_FULL_HANDLER_IN_PROGRESS 6638L






// Log service encountered an error when attempting to read from a log container.

ERROR_LOG_CONTAINER_READ_FAILED  6639L






// Log service encountered an error when attempting to write to a log container.

ERROR_LOG_CONTAINER_WRITE_FAILED 6640L






// Log service encountered an error when attempting open a log container.

ERROR_LOG_CONTAINER_OPEN_FAILED  6641L






// Log service encountered an invalid container state when attempting a requested action.

ERROR_LOG_CONTAINER_STATE_INVALID 6642L






// Log service is not in the correct state to perform a requested action.

ERROR_LOG_STATE_INVALID          6643L






// Log space cannot be reclaimed because the log is pinned.

ERROR_LOG_PINNED                 6644L






// Log metadata flush failed.

ERROR_LOG_METADATA_FLUSH_FAILED  6645L






// Security on the log and its containers is inconsistent.

ERROR_LOG_INCONSISTENT_SECURITY  6646L






// Records were appended to the log or reservation changes were made, but the log could not be flushed.

ERROR_LOG_APPENDED_FLUSH_FAILED  6647L






// The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available.

ERROR_LOG_PINNED_RESERVATION     6648L


///////////////////////////////////////////////////
//                                               //
//           Transaction (KTM) Error codes       //
//                                               //
//                 6700 to 6799                  //
///////////////////////////////////////////////////






// The transaction handle associated with this operation is not valid.

ERROR_INVALID_TRANSACTION        6700L






// The requested operation was made in the context of a transaction that is no longer active.

ERROR_TRANSACTION_NOT_ACTIVE     6701L






// The requested operation is not valid on the Transaction object in its current state.

ERROR_TRANSACTION_REQUEST_NOT_VALID 6702L






// The caller has called a response API, but the response is not expected because the TM did not issue the corresponding request to the caller.

ERROR_TRANSACTION_NOT_REQUESTED  6703L






// It is too late to perform the requested operation, since the Transaction has already been aborted.

ERROR_TRANSACTION_ALREADY_ABORTED 6704L






// It is too late to perform the requested operation, since the Transaction has already been committed.

ERROR_TRANSACTION_ALREADY_COMMITTED 6705L






// The Transaction Manager was unable to be successfully initialized. Transacted operations are not supported.

ERROR_TM_INITIALIZATION_FAILED   6706L






// The specified ResourceManager made no changes or updates to the resource under this transaction.

ERROR_RESOURCEMANAGER_READ_ONLY  6707L






// The resource manager has attempted to prepare a transaction that it has not successfully joined.

ERROR_TRANSACTION_NOT_JOINED     6708L






// The Transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allow.

ERROR_TRANSACTION_SUPERIOR_EXISTS 6709L






// The RM tried to register a protocol that already exists.

ERROR_CRM_PROTOCOL_ALREADY_EXISTS 6710L






// The attempt to propagate the Transaction failed.

ERROR_TRANSACTION_PROPAGATION_FAILED 6711L






// The requested propagation protocol was not registered as a CRM.

ERROR_CRM_PROTOCOL_NOT_FOUND     6712L






// The buffer passed in to PushTransaction or PullTransaction is not in a valid format.

ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER 6713L






// The current transaction context associated with the thread is not a valid handle to a transaction object.

ERROR_CURRENT_TRANSACTION_NOT_VALID 6714L






// The specified Transaction object could not be opened, because it was not found.

ERROR_TRANSACTION_NOT_FOUND      6715L






// The specified ResourceManager object could not be opened, because it was not found.

ERROR_RESOURCEMANAGER_NOT_FOUND  6716L






// The specified Enlistment object could not be opened, because it was not found.

ERROR_ENLISTMENT_NOT_FOUND       6717L






// The specified TransactionManager object could not be opened, because it was not found.

ERROR_TRANSACTIONMANAGER_NOT_FOUND 6718L






// The object specified could not be created or opened, because its associated TransactionManager is not online.  The TransactionManager must be brought fully Online by calling RecoverTransactionManager to recover to the end of its LogFile before objects in its Transaction or ResourceManager namespaces can be opened.  In addition, errors in writing records to its LogFile can cause a TransactionManager to go offline.

ERROR_TRANSACTIONMANAGER_NOT_ONLINE 6719L






// The specified TransactionManager was unable to create the objects contained in its logfile in the Ob namespace. Therefore, the TransactionManager was unable to recover.

ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION 6720L






// The call to create a superior Enlistment on this Transaction object could not be completed, because the Transaction object specified for the enlistment is a subordinate branch of the Transaction. Only the root of the Transaction can be enlisted on as a superior.

ERROR_TRANSACTION_NOT_ROOT       6721L






// Because the associated transaction manager or resource manager has been closed, the handle is no longer valid.

ERROR_TRANSACTION_OBJECT_EXPIRED 6722L






// The specified operation could not be performed on this Superior enlistment, because the enlistment was not created with the corresponding completion response in the NotificationMask.

ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED 6723L






// The specified operation could not be performed, because the record that would be logged was too long. This can occur because of two conditions: either there are too many Enlistments on this Transaction, or the combined RecoveryInformation being logged on behalf of those Enlistments is too long.

ERROR_TRANSACTION_RECORD_TOO_LONG 6724L






// Implicit transaction are not supported.

ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED 6725L






// The kernel transaction manager had to abort or forget the transaction because it blocked forward progress.

ERROR_TRANSACTION_INTEGRITY_VIOLATED 6726L






// The TransactionManager identity that was supplied did not match the one recorded in the TransactionManager's log file.

ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH 6727L






// This snapshot operation cannot continue because a transactional resource manager cannot be frozen in its current state.  Please try again.

ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT 6728L






// The transaction cannot be enlisted on with the specified EnlistmentMask, because the transaction has already completed the PrePrepare phase.  In order to ensure correctness, the ResourceManager must switch to a write-through mode and cease caching data within this transaction.  Enlisting for only subsequent transaction phases may still succeed.

ERROR_TRANSACTION_MUST_WRITETHROUGH 6729L






// The transaction does not have a superior enlistment.

ERROR_TRANSACTION_NO_SUPERIOR    6730L






// The attempt to commit the Transaction completed, but it is possible that some portion of the transaction tree did not commit successfully due to heuristics.  Therefore it is possible that some data modified in the transaction may not have committed, resulting in transactional inconsistency.  If possible, check the consistency of the associated data.

ERROR_HEURISTIC_DAMAGE_POSSIBLE  6731L


///////////////////////////////////////////////////
//                                               //
//        Transactional File Services (TxF)      //
//                  Error codes                  //
//                                               //
//                 6800 to 6899                  //
///////////////////////////////////////////////////






// The function attempted to use a name that is reserved for use by another transaction.

ERROR_TRANSACTIONAL_CONFLICT     6800L






// Transaction support within the specified resource manager is not started or was shut down due to an error.

ERROR_RM_NOT_ACTIVE              6801L






// The metadata of the RM has been corrupted. The RM will not function.

ERROR_RM_METADATA_CORRUPT        6802L






// The specified directory does not contain a resource manager.

ERROR_DIRECTORY_NOT_RM           6803L






// The remote server or share does not support transacted file operations.

ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE 6805L






// The requested log size is invalid.

ERROR_LOG_RESIZE_INVALID_SIZE    6806L






// The object (file, stream, link) corresponding to the handle has been deleted by a Transaction Savepoint Rollback.

ERROR_OBJECT_NO_LONGER_EXISTS    6807L






// The specified file miniversion was not found for this transacted file open.

ERROR_STREAM_MINIVERSION_NOT_FOUND 6808L






// The specified file miniversion was found but has been invalidated. Most likely cause is a transaction savepoint rollback.

ERROR_STREAM_MINIVERSION_NOT_VALID 6809L






// A miniversion may only be opened in the context of the transaction that created it.

ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION 6810L






// It is not possible to open a miniversion with modify access.

ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT 6811L






// It is not possible to create any more miniversions for this stream.

ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS 6812L






// The remote server sent mismatching version number or Fid for a file opened with transactions.

ERROR_REMOTE_FILE_VERSION_MISMATCH 6814L






// The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint.

ERROR_HANDLE_NO_LONGER_VALID     6815L






// There is no transaction metadata on the file.

ERROR_NO_TXF_METADATA            6816L






// The log data is corrupt.

ERROR_LOG_CORRUPTION_DETECTED    6817L






// The file can't be recovered because there is a handle still open on it.

ERROR_CANT_RECOVER_WITH_HANDLE_OPEN 6818L






// The transaction outcome is unavailable because the resource manager responsible for it has disconnected.

ERROR_RM_DISCONNECTED            6819L






// The request was rejected because the enlistment in question is not a superior enlistment.

ERROR_ENLISTMENT_NOT_SUPERIOR    6820L






// The transactional resource manager is already consistent. Recovery is not needed.

ERROR_RECOVERY_NOT_NEEDED        6821L






// The transactional resource manager has already been started.

ERROR_RM_ALREADY_STARTED         6822L






// The file cannot be opened transactionally, because its identity depends on the outcome of an unresolved transaction.

ERROR_FILE_IDENTITY_NOT_PERSISTENT 6823L






// The operation cannot be performed because another transaction is depending on the fact that this property will not change.

ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY 6824L






// The operation would involve a single file with two transactional resource managers and is therefore not allowed.

ERROR_CANT_CROSS_RM_BOUNDARY     6825L






// The $Txf directory must be empty for this operation to succeed.

ERROR_TXF_DIR_NOT_EMPTY          6826L






// The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed.

ERROR_INDOUBT_TRANSACTIONS_EXIST 6827L






// The operation could not be completed because the transaction manager does not have a log.

ERROR_TM_VOLATILE                6828L






// A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution.

ERROR_ROLLBACK_TIMER_EXPIRED     6829L






// The transactional metadata attribute on the file or directory is corrupt and unreadable.

ERROR_TXF_ATTRIBUTE_CORRUPT      6830L






// The encryption operation could not be completed because a transaction is active.

ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION 6831L






// This object is not allowed to be opened in a transaction.

ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED 6832L






// An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log.

ERROR_LOG_GROWTH_FAILED          6833L






// Memory mapping (creating a mapped section) a remote file under a transaction is not supported.

ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE 6834L






// Transaction metadata is already present on this file and cannot be superseded.

ERROR_TXF_METADATA_ALREADY_PRESENT 6835L






// A transaction scope could not be entered because the scope handler has not been initialized.

ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET 6836L






// Promotion was required in order to allow the resource manager to enlist, but the transaction was set to disallow it.

ERROR_TRANSACTION_REQUIRED_PROMOTION 6837L






// This file is open for modification in an unresolved transaction and may be opened for execute only by a transacted reader.

ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION 6838L






// The request to thaw frozen transactions was ignored because transactions had not previously been frozen.

ERROR_TRANSACTIONS_NOT_FROZEN    6839L






// Transactions cannot be frozen because a freeze is already in progress.

ERROR_TRANSACTION_FREEZE_IN_PROGRESS 6840L






// The target volume is not a snapshot volume. This operation is only valid on a volume mounted as a snapshot.

ERROR_NOT_SNAPSHOT_VOLUME        6841L






// The savepoint operation failed because files are open on the transaction. This is not permitted.

ERROR_NO_SAVEPOINT_WITH_OPEN_FILES 6842L






// Windows has discovered corruption in a file, and that file has since been repaired. Data loss may have occurred.

ERROR_DATA_LOST_REPAIR           6843L






// The sparse operation could not be completed because a transaction is active on the file.

ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION 6844L






// The call to create a TransactionManager object failed because the Tm Identity stored in the logfile does not match the Tm Identity that was passed in as an argument.

ERROR_TM_IDENTITY_MISMATCH       6845L






// I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data.

ERROR_FLOATED_SECTION            6846L






// The transactional resource manager cannot currently accept transacted work due to a transient condition such as low resources.

ERROR_CANNOT_ACCEPT_TRANSACTED_WORK 6847L






// The transactional resource manager had too many transactions outstanding that could not be aborted. The transactional resource manger has been shut down.

ERROR_CANNOT_ABORT_TRANSACTIONS  6848L






// The operation could not be completed due to bad clusters on disk.

ERROR_BAD_CLUSTERS               6849L






// The compression operation could not be completed because a transaction is active on the file.

ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION 6850L






// The operation could not be completed because the volume is dirty. Please run chkdsk and try again.

ERROR_VOLUME_DIRTY               6851L






// The link tracking operation could not be completed because a transaction is active.

ERROR_NO_LINK_TRACKING_IN_TRANSACTION 6852L






// This operation cannot be performed in a transaction.

ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION 6853L






// The handle is no longer properly associated with its transaction.  It may have been opened in a transactional resource manager that was subsequently forced to restart.  Please close the handle and open a new one.

ERROR_EXPIRED_HANDLE             6854L






// The specified operation could not be performed because the resource manager is not enlisted in the transaction.

ERROR_TRANSACTION_NOT_ENLISTED   6855L


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 6900 to 6999                  //
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//                                               //
//          Terminal Server Error codes          //
//                                               //
//                 7000 to 7099                  //
///////////////////////////////////////////////////






// The specified session name is invalid.

ERROR_CTX_WINSTATION_NAME_INVALID 7001L






// The specified protocol driver is invalid.

ERROR_CTX_INVALID_PD             7002L






// The specified protocol driver was not found in the system path.

ERROR_CTX_PD_NOT_FOUND           7003L






// The specified terminal connection driver was not found in the system path.

ERROR_CTX_WD_NOT_FOUND           7004L






// A registry key for event logging could not be created for this session.

ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY 7005L






// A service with the same name already exists on the system.

ERROR_CTX_SERVICE_NAME_COLLISION 7006L






// A close operation is pending on the session.

ERROR_CTX_CLOSE_PENDING          7007L






// There are no free output buffers available.

ERROR_CTX_NO_OUTBUF              7008L






// The MODEM.INF file was not found.

ERROR_CTX_MODEM_INF_NOT_FOUND    7009L






// The modem name was not found in MODEM.INF.

ERROR_CTX_INVALID_MODEMNAME      7010L






// The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem.

ERROR_CTX_MODEM_RESPONSE_ERROR   7011L






// The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on.

ERROR_CTX_MODEM_RESPONSE_TIMEOUT 7012L






// Carrier detect has failed or carrier has been dropped due to disconnect.

ERROR_CTX_MODEM_RESPONSE_NO_CARRIER 7013L






// Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional.

ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE 7014L






// Busy signal detected at remote site on callback.

ERROR_CTX_MODEM_RESPONSE_BUSY    7015L






// Voice detected at remote site on callback.

ERROR_CTX_MODEM_RESPONSE_VOICE   7016L






// Transport driver error

ERROR_CTX_TD_ERROR               7017L






// The specified session cannot be found.

ERROR_CTX_WINSTATION_NOT_FOUND   7022L






// The specified session name is already in use.

ERROR_CTX_WINSTATION_ALREADY_EXISTS 7023L






// The task you are trying to do can't be completed because Remote Desktop Services is currently busy. Please try again in a few minutes. Other users should still be able to log on.

ERROR_CTX_WINSTATION_BUSY        7024L






// An attempt has been made to connect to a session whose video mode is not supported by the current client.

ERROR_CTX_BAD_VIDEO_MODE         7025L






// The application attempted to enable DOS graphics mode. DOS graphics mode is not supported.

ERROR_CTX_GRAPHICS_INVALID       7035L






// Your interactive logon privilege has been disabled. Please contact your administrator.

ERROR_CTX_LOGON_DISABLED         7037L






// The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access.

ERROR_CTX_NOT_CONSOLE            7038L






// The client failed to respond to the server connect message.

ERROR_CTX_CLIENT_QUERY_TIMEOUT   7040L






// Disconnecting the console session is not supported.

ERROR_CTX_CONSOLE_DISCONNECT     7041L






// Reconnecting a disconnected session to the console is not supported.

ERROR_CTX_CONSOLE_CONNECT        7042L






// The request to control another session remotely was denied.

ERROR_CTX_SHADOW_DENIED          7044L






// The requested session access is denied.

ERROR_CTX_WINSTATION_ACCESS_DENIED 7045L






// The specified terminal connection driver is invalid.

ERROR_CTX_INVALID_WD             7049L






// The requested session cannot be controlled remotely.
// This may be because the session is disconnected or does not currently have a user logged on.

ERROR_CTX_SHADOW_INVALID         7050L






// The requested session is not configured to allow remote control.

ERROR_CTX_SHADOW_DISABLED        7051L






// Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user. Please call your system administrator to obtain a unique license number.

ERROR_CTX_CLIENT_LICENSE_IN_USE  7052L






// Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client. Please contact your system administrator.

ERROR_CTX_CLIENT_LICENSE_NOT_SET 7053L






// The number of connections to this computer is limited and all connections are in use right now. Try connecting later or contact your system administrator.

ERROR_CTX_LICENSE_NOT_AVAILABLE  7054L






// The client you are using is not licensed to use this system. Your logon request is denied.

ERROR_CTX_LICENSE_CLIENT_INVALID 7055L






// The system license has expired. Your logon request is denied.

ERROR_CTX_LICENSE_EXPIRED        7056L






// Remote control could not be terminated because the specified session is not currently being remotely controlled.

ERROR_CTX_SHADOW_NOT_RUNNING     7057L






// The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.

ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE 7058L






// Activation has already been reset the maximum number of times for this installation. Your activation timer will not be cleared.

ERROR_ACTIVATION_COUNT_EXCEEDED  7059L






// Remote logins are currently disabled.

ERROR_CTX_WINSTATIONS_DISABLED   7060L






// You do not have the proper encryption level to access this Session.

ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED 7061L






// The user %s\\%s is currently logged on to this computer. Only the current user or an administrator can log on to this computer.

ERROR_CTX_SESSION_IN_USE         7062L






// The user %s\\%s is already logged on to the console of this computer. You do not have permission to log in at this time. To resolve this issue, contact %s\\%s and have them log off.

ERROR_CTX_NO_FORCE_LOGOFF        7063L






// Unable to log you on because of an account restriction.

ERROR_CTX_ACCOUNT_RESTRICTION    7064L






// The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.

ERROR_RDP_PROTOCOL_ERROR         7065L






// The Client Drive Mapping Service Has Connected on Terminal Connection.

ERROR_CTX_CDM_CONNECT            7066L






// The Client Drive Mapping Service Has Disconnected on Terminal Connection.

ERROR_CTX_CDM_DISCONNECT         7067L






// The Terminal Server security layer detected an error in the protocol stream and has disconnected the client.

ERROR_CTX_SECURITY_LAYER_ERROR   7068L






// The target session is incompatible with the current session.

ERROR_TS_INCOMPATIBLE_SESSIONS   7069L






// Windows can't connect to your session because a problem occurred in the Windows video subsystem. Try connecting again later, or contact the server administrator for assistance.

ERROR_TS_VIDEO_SUBSYSTEM_ERROR   7070L

///////////////////////////////////////////////////
//                                               //
//          Windows Fabric Error Codes           //
//                                               //
//                 7100 to 7499                  //
//                                               //
//          defined in FabricCommon.idl          //
//                                               //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                                /
//           Traffic Control Error Codes          /
//                                                /
//                  7500 to 7999                  /
//                                                /
//            defined in: tcerror.h               /
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//           Active Directory Error codes        //
//                                               //
//                 8000 to 8999                  //
///////////////////////////////////////////////////

// *****************
// FACILITY_FILE_REPLICATION_SERVICE
// *****************





// The file replication service API was called incorrectly.

FRS_ERR_INVALID_API_SEQUENCE     8001L






// The file replication service cannot be started.

FRS_ERR_STARTING_SERVICE         8002L






// The file replication service cannot be stopped.

FRS_ERR_STOPPING_SERVICE         8003L






// The file replication service API terminated the request. The event log may have more information.

FRS_ERR_INTERNAL_API             8004L






// The file replication service terminated the request. The event log may have more information.

FRS_ERR_INTERNAL                 8005L






// The file replication service cannot be contacted. The event log may have more information.

FRS_ERR_SERVICE_COMM             8006L






// The file replication service cannot satisfy the request because the user has insufficient privileges. The event log may have more information.

FRS_ERR_INSUFFICIENT_PRIV        8007L






// The file replication service cannot satisfy the request because authenticated RPC is not available. The event log may have more information.

FRS_ERR_AUTHENTICATION           8008L






// The file replication service cannot satisfy the request because the user has insufficient privileges on the domain controller. The event log may have more information.

FRS_ERR_PARENT_INSUFFICIENT_PRIV 8009L






// The file replication service cannot satisfy the request because authenticated RPC is not available on the domain controller. The event log may have more information.

FRS_ERR_PARENT_AUTHENTICATION    8010L






// The file replication service cannot communicate with the file replication service on the domain controller. The event log may have more information.

FRS_ERR_CHILD_TO_PARENT_COMM     8011L






// The file replication service on the domain controller cannot communicate with the file replication service on this computer. The event log may have more information.

FRS_ERR_PARENT_TO_CHILD_COMM     8012L






// The file replication service cannot populate the system volume because of an internal error. The event log may have more information.

FRS_ERR_SYSVOL_POPULATE          8013L






// The file replication service cannot populate the system volume because of an internal timeout. The event log may have more information.

FRS_ERR_SYSVOL_POPULATE_TIMEOUT  8014L






// The file replication service cannot process the request. The system volume is busy with a previous request.

FRS_ERR_SYSVOL_IS_BUSY           8015L






// The file replication service cannot stop replicating the system volume because of an internal error. The event log may have more information.

FRS_ERR_SYSVOL_DEMOTE            8016L






// The file replication service detected an invalid parameter.

FRS_ERR_INVALID_SERVICE_PARAMETER 8017L

// *****************
// FACILITY DIRECTORY SERVICE
// *****************
DS_S_SUCCESS NO_ERROR





// An error occurred while installing the directory service. For more information, see the event log.

ERROR_DS_NOT_INSTALLED           8200L






// The directory service evaluated group memberships locally.

ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY 8201L






// The specified directory service attribute or value does not exist.

ERROR_DS_NO_ATTRIBUTE_OR_VALUE   8202L






// The attribute syntax specified to the directory service is invalid.

ERROR_DS_INVALID_ATTRIBUTE_SYNTAX 8203L






// The attribute type specified to the directory service is not defined.

ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED 8204L






// The specified directory service attribute or value already exists.

ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS 8205L






// The directory service is busy.

ERROR_DS_BUSY                    8206L






// The directory service is unavailable.

ERROR_DS_UNAVAILABLE             8207L






// The directory service was unable to allocate a relative identifier.

ERROR_DS_NO_RIDS_ALLOCATED       8208L






// The directory service has exhausted the pool of relative identifiers.

ERROR_DS_NO_MORE_RIDS            8209L






// The requested operation could not be performed because the directory service is not the master for that type of operation.

ERROR_DS_INCORRECT_ROLE_OWNER    8210L






// The directory service was unable to initialize the subsystem that allocates relative identifiers.

ERROR_DS_RIDMGR_INIT_ERROR       8211L






// The requested operation did not satisfy one or more constraints associated with the class of the object.

ERROR_DS_OBJ_CLASS_VIOLATION     8212L






// The directory service can perform the requested operation only on a leaf object.

ERROR_DS_CANT_ON_NON_LEAF        8213L






// The directory service cannot perform the requested operation on the RDN attribute of an object.

ERROR_DS_CANT_ON_RDN             8214L






// The directory service detected an attempt to modify the object class of an object.

ERROR_DS_CANT_MOD_OBJ_CLASS      8215L






// The requested cross-domain move operation could not be performed.

ERROR_DS_CROSS_DOM_MOVE_ERROR    8216L






// Unable to contact the global catalog server.

ERROR_DS_GC_NOT_AVAILABLE        8217L






// The policy object is shared and can only be modified at the root.

ERROR_SHARED_POLICY              8218L






// The policy object does not exist.

ERROR_POLICY_OBJECT_NOT_FOUND    8219L






// The requested policy information is only in the directory service.

ERROR_POLICY_ONLY_IN_DS          8220L






// A domain controller promotion is currently active.

ERROR_PROMOTION_ACTIVE           8221L






// A domain controller promotion is not currently active

ERROR_NO_PROMOTION_ACTIVE        8222L

// 8223 unused





// An operations error occurred.

ERROR_DS_OPERATIONS_ERROR        8224L






// A protocol error occurred.

ERROR_DS_PROTOCOL_ERROR          8225L






// The time limit for this request was exceeded.

ERROR_DS_TIMELIMIT_EXCEEDED      8226L






// The size limit for this request was exceeded.

ERROR_DS_SIZELIMIT_EXCEEDED      8227L






// The administrative limit for this request was exceeded.

ERROR_DS_ADMIN_LIMIT_EXCEEDED    8228L






// The compare response was false.

ERROR_DS_COMPARE_FALSE           8229L






// The compare response was true.

ERROR_DS_COMPARE_TRUE            8230L






// The requested authentication method is not supported by the server.

ERROR_DS_AUTH_METHOD_NOT_SUPPORTED 8231L






// A more secure authentication method is required for this server.

ERROR_DS_STRONG_AUTH_REQUIRED    8232L






// Inappropriate authentication.

ERROR_DS_INAPPROPRIATE_AUTH      8233L






// The authentication mechanism is unknown.

ERROR_DS_AUTH_UNKNOWN            8234L






// A referral was returned from the server.

ERROR_DS_REFERRAL                8235L






// The server does not support the requested critical extension.

ERROR_DS_UNAVAILABLE_CRIT_EXTENSION 8236L






// This request requires a secure connection.

ERROR_DS_CONFIDENTIALITY_REQUIRED 8237L






// Inappropriate matching.

ERROR_DS_INAPPROPRIATE_MATCHING  8238L






// A constraint violation occurred.

ERROR_DS_CONSTRAINT_VIOLATION    8239L






// There is no such object on the server.

ERROR_DS_NO_SUCH_OBJECT          8240L






// There is an alias problem.

ERROR_DS_ALIAS_PROBLEM           8241L






// An invalid dn syntax has been specified.

ERROR_DS_INVALID_DN_SYNTAX       8242L






// The object is a leaf object.

ERROR_DS_IS_LEAF                 8243L






// There is an alias dereferencing problem.

ERROR_DS_ALIAS_DEREF_PROBLEM     8244L






// The server is unwilling to process the request.

ERROR_DS_UNWILLING_TO_PERFORM    8245L






// A loop has been detected.

ERROR_DS_LOOP_DETECT             8246L






// There is a naming violation.

ERROR_DS_NAMING_VIOLATION        8247L






// The result set is too large.

ERROR_DS_OBJECT_RESULTS_TOO_LARGE 8248L






// The operation affects multiple DSAs

ERROR_DS_AFFECTS_MULTIPLE_DSAS   8249L






// The server is not operational.

ERROR_DS_SERVER_DOWN             8250L






// A local error has occurred.

ERROR_DS_LOCAL_ERROR             8251L






// An encoding error has occurred.

ERROR_DS_ENCODING_ERROR          8252L






// A decoding error has occurred.

ERROR_DS_DECODING_ERROR          8253L






// The search filter cannot be recognized.

ERROR_DS_FILTER_UNKNOWN          8254L






// One or more parameters are illegal.

ERROR_DS_PARAM_ERROR             8255L






// The specified method is not supported.

ERROR_DS_NOT_SUPPORTED           8256L






// No results were returned.

ERROR_DS_NO_RESULTS_RETURNED     8257L






// The specified control is not supported by the server.

ERROR_DS_CONTROL_NOT_FOUND       8258L






// A referral loop was detected by the client.

ERROR_DS_CLIENT_LOOP             8259L






// The preset referral limit was exceeded.

ERROR_DS_REFERRAL_LIMIT_EXCEEDED 8260L






// The search requires a SORT control.

ERROR_DS_SORT_CONTROL_MISSING    8261L






// The search results exceed the offset range specified.

ERROR_DS_OFFSET_RANGE_ERROR      8262L






// The directory service detected the subsystem that allocates relative identifiers is disabled. This can occur as a protective mechanism when the system determines a significant portion of relative identifiers (RIDs) have been exhausted. Please see http://go.microsoft.com/fwlink/?LinkId=228610 for recommended diagnostic steps and the procedure to re-enable account creation.

ERROR_DS_RIDMGR_DISABLED         8263L






// The root object must be the head of a naming context. The root object cannot have an instantiated parent.

ERROR_DS_ROOT_MUST_BE_NC         8301L






// The add replica operation cannot be performed. The naming context must be writeable in order to create the replica.

ERROR_DS_ADD_REPLICA_INHIBITED   8302L






// A reference to an attribute that is not defined in the schema occurred.

ERROR_DS_ATT_NOT_DEF_IN_SCHEMA   8303L






// The maximum size of an object has been exceeded.

ERROR_DS_MAX_OBJ_SIZE_EXCEEDED   8304L






// An attempt was made to add an object to the directory with a name that is already in use.

ERROR_DS_OBJ_STRING_NAME_EXISTS  8305L






// An attempt was made to add an object of a class that does not have an RDN defined in the schema.

ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA 8306L






// An attempt was made to add an object using an RDN that is not the RDN defined in the schema.

ERROR_DS_RDN_DOESNT_MATCH_SCHEMA 8307L






// None of the requested attributes were found on the objects.

ERROR_DS_NO_REQUESTED_ATTS_FOUND 8308L






// The user buffer is too small.

ERROR_DS_USER_BUFFER_TO_SMALL    8309L






// The attribute specified in the operation is not present on the object.

ERROR_DS_ATT_IS_NOT_ON_OBJ       8310L






// Illegal modify operation. Some aspect of the modification is not permitted.

ERROR_DS_ILLEGAL_MOD_OPERATION   8311L






// The specified object is too large.

ERROR_DS_OBJ_TOO_LARGE           8312L






// The specified instance type is not valid.

ERROR_DS_BAD_INSTANCE_TYPE       8313L






// The operation must be performed at a master DSA.

ERROR_DS_MASTERDSA_REQUIRED      8314L






// The object class attribute must be specified.

ERROR_DS_OBJECT_CLASS_REQUIRED   8315L






// A required attribute is missing.

ERROR_DS_MISSING_REQUIRED_ATT    8316L






// An attempt was made to modify an object to include an attribute that is not legal for its class.

ERROR_DS_ATT_NOT_DEF_FOR_CLASS   8317L






// The specified attribute is already present on the object.

ERROR_DS_ATT_ALREADY_EXISTS      8318L

// 8319 unused





// The specified attribute is not present, or has no values.

ERROR_DS_CANT_ADD_ATT_VALUES     8320L






// Multiple values were specified for an attribute that can have only one value.

ERROR_DS_SINGLE_VALUE_CONSTRAINT 8321L






// A value for the attribute was not in the acceptable range of values.

ERROR_DS_RANGE_CONSTRAINT        8322L






// The specified value already exists.

ERROR_DS_ATT_VAL_ALREADY_EXISTS  8323L






// The attribute cannot be removed because it is not present on the object.

ERROR_DS_CANT_REM_MISSING_ATT    8324L






// The attribute value cannot be removed because it is not present on the object.

ERROR_DS_CANT_REM_MISSING_ATT_VAL 8325L






// The specified root object cannot be a subref.

ERROR_DS_ROOT_CANT_BE_SUBREF     8326L






// Chaining is not permitted.

ERROR_DS_NO_CHAINING             8327L






// Chained evaluation is not permitted.

ERROR_DS_NO_CHAINED_EVAL         8328L






// The operation could not be performed because the object's parent is either uninstantiated or deleted.

ERROR_DS_NO_PARENT_OBJECT        8329L






// Having a parent that is an alias is not permitted. Aliases are leaf objects.

ERROR_DS_PARENT_IS_AN_ALIAS      8330L






// The object and parent must be of the same type, either both masters or both replicas.

ERROR_DS_CANT_MIX_MASTER_AND_REPS 8331L






// The operation cannot be performed because child objects exist. This operation can only be performed on a leaf object.

ERROR_DS_CHILDREN_EXIST          8332L






// Directory object not found.

ERROR_DS_OBJ_NOT_FOUND           8333L






// The aliased object is missing.

ERROR_DS_ALIASED_OBJ_MISSING     8334L






// The object name has bad syntax.

ERROR_DS_BAD_NAME_SYNTAX         8335L






// It is not permitted for an alias to refer to another alias.

ERROR_DS_ALIAS_POINTS_TO_ALIAS   8336L






// The alias cannot be dereferenced.

ERROR_DS_CANT_DEREF_ALIAS        8337L






// The operation is out of scope.

ERROR_DS_OUT_OF_SCOPE            8338L






// The operation cannot continue because the object is in the process of being removed.

ERROR_DS_OBJECT_BEING_REMOVED    8339L






// The DSA object cannot be deleted.

ERROR_DS_CANT_DELETE_DSA_OBJ     8340L






// A directory service error has occurred.

ERROR_DS_GENERIC_ERROR           8341L






// The operation can only be performed on an internal master DSA object.

ERROR_DS_DSA_MUST_BE_INT_MASTER  8342L






// The object must be of class DSA.

ERROR_DS_CLASS_NOT_DSA           8343L






// Insufficient access rights to perform the operation.

ERROR_DS_INSUFF_ACCESS_RIGHTS    8344L






// The object cannot be added because the parent is not on the list of possible superiors.

ERROR_DS_ILLEGAL_SUPERIOR        8345L






// Access to the attribute is not permitted because the attribute is owned by the Security Accounts Manager (SAM).

ERROR_DS_ATTRIBUTE_OWNED_BY_SAM  8346L






// The name has too many parts.

ERROR_DS_NAME_TOO_MANY_PARTS     8347L






// The name is too long.

ERROR_DS_NAME_TOO_LONG           8348L






// The name value is too long.

ERROR_DS_NAME_VALUE_TOO_LONG     8349L






// The directory service encountered an error parsing a name.

ERROR_DS_NAME_UNPARSEABLE        8350L






// The directory service cannot get the attribute type for a name.

ERROR_DS_NAME_TYPE_UNKNOWN       8351L






// The name does not identify an object; the name identifies a phantom.

ERROR_DS_NOT_AN_OBJECT           8352L






// The security descriptor is too short.

ERROR_DS_SEC_DESC_TOO_SHORT      8353L






// The security descriptor is invalid.

ERROR_DS_SEC_DESC_INVALID        8354L






// Failed to create name for deleted object.

ERROR_DS_NO_DELETED_NAME         8355L






// The parent of a new subref must exist.

ERROR_DS_SUBREF_MUST_HAVE_PARENT 8356L






// The object must be a naming context.

ERROR_DS_NCNAME_MUST_BE_NC       8357L






// It is not permitted to add an attribute which is owned by the system.

ERROR_DS_CANT_ADD_SYSTEM_ONLY    8358L






// The class of the object must be structural; you cannot instantiate an abstract class.

ERROR_DS_CLASS_MUST_BE_CONCRETE  8359L






// The schema object could not be found.

ERROR_DS_INVALID_DMD             8360L






// A local object with this GUID (dead or alive) already exists.

ERROR_DS_OBJ_GUID_EXISTS         8361L






// The operation cannot be performed on a back link.

ERROR_DS_NOT_ON_BACKLINK         8362L






// The cross reference for the specified naming context could not be found.

ERROR_DS_NO_CROSSREF_FOR_NC      8363L






// The operation could not be performed because the directory service is shutting down.

ERROR_DS_SHUTTING_DOWN           8364L






// The directory service request is invalid.

ERROR_DS_UNKNOWN_OPERATION       8365L






// The role owner attribute could not be read.

ERROR_DS_INVALID_ROLE_OWNER      8366L






// The requested FSMO operation failed. The current FSMO holder could not be contacted.

ERROR_DS_COULDNT_CONTACT_FSMO    8367L






// Modification of a DN across a naming context is not permitted.

ERROR_DS_CROSS_NC_DN_RENAME      8368L






// The attribute cannot be modified because it is owned by the system.

ERROR_DS_CANT_MOD_SYSTEM_ONLY    8369L






// Only the replicator can perform this function.

ERROR_DS_REPLICATOR_ONLY         8370L






// The specified class is not defined.

ERROR_DS_OBJ_CLASS_NOT_DEFINED   8371L






// The specified class is not a subclass.

ERROR_DS_OBJ_CLASS_NOT_SUBCLASS  8372L






// The name reference is invalid.

ERROR_DS_NAME_REFERENCE_INVALID  8373L






// A cross reference already exists.

ERROR_DS_CROSS_REF_EXISTS        8374L






// It is not permitted to delete a master cross reference.

ERROR_DS_CANT_DEL_MASTER_CROSSREF 8375L






// Subtree notifications are only supported on NC heads.

ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD 8376L






// Notification filter is too complex.

ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX 8377L






// Schema update failed: duplicate RDN.

ERROR_DS_DUP_RDN                 8378L






// Schema update failed: duplicate OID.

ERROR_DS_DUP_OID                 8379L






// Schema update failed: duplicate MAPI identifier.

ERROR_DS_DUP_MAPI_ID             8380L






// Schema update failed: duplicate schema-id GUID.

ERROR_DS_DUP_SCHEMA_ID_GUID      8381L






// Schema update failed: duplicate LDAP display name.

ERROR_DS_DUP_LDAP_DISPLAY_NAME   8382L






// Schema update failed: range-lower less than range upper.

ERROR_DS_SEMANTIC_ATT_TEST       8383L






// Schema update failed: syntax mismatch.

ERROR_DS_SYNTAX_MISMATCH         8384L






// Schema deletion failed: attribute is used in must-contain.

ERROR_DS_EXISTS_IN_MUST_HAVE     8385L






// Schema deletion failed: attribute is used in may-contain.

ERROR_DS_EXISTS_IN_MAY_HAVE      8386L






// Schema update failed: attribute in may-contain does not exist.

ERROR_DS_NONEXISTENT_MAY_HAVE    8387L






// Schema update failed: attribute in must-contain does not exist.

ERROR_DS_NONEXISTENT_MUST_HAVE   8388L






// Schema update failed: class in aux-class list does not exist or is not an auxiliary class.

ERROR_DS_AUX_CLS_TEST_FAIL       8389L






// Schema update failed: class in poss-superiors does not exist.

ERROR_DS_NONEXISTENT_POSS_SUP    8390L






// Schema update failed: class in subclassof list does not exist or does not satisfy hierarchy rules.

ERROR_DS_SUB_CLS_TEST_FAIL       8391L






// Schema update failed: Rdn-Att-Id has wrong syntax.

ERROR_DS_BAD_RDN_ATT_ID_SYNTAX   8392L






// Schema deletion failed: class is used as auxiliary class.

ERROR_DS_EXISTS_IN_AUX_CLS       8393L






// Schema deletion failed: class is used as sub class.

ERROR_DS_EXISTS_IN_SUB_CLS       8394L






// Schema deletion failed: class is used as poss superior.

ERROR_DS_EXISTS_IN_POSS_SUP      8395L






// Schema update failed in recalculating validation cache.

ERROR_DS_RECALCSCHEMA_FAILED     8396L






// The tree deletion is not finished. The request must be made again to continue deleting the tree.

ERROR_DS_TREE_DELETE_NOT_FINISHED 8397L






// The requested delete operation could not be performed.

ERROR_DS_CANT_DELETE             8398L






// Cannot read the governs class identifier for the schema record.

ERROR_DS_ATT_SCHEMA_REQ_ID       8399L






// The attribute schema has bad syntax.

ERROR_DS_BAD_ATT_SCHEMA_SYNTAX   8400L






// The attribute could not be cached.

ERROR_DS_CANT_CACHE_ATT          8401L






// The class could not be cached.

ERROR_DS_CANT_CACHE_CLASS        8402L






// The attribute could not be removed from the cache.

ERROR_DS_CANT_REMOVE_ATT_CACHE   8403L






// The class could not be removed from the cache.

ERROR_DS_CANT_REMOVE_CLASS_CACHE 8404L






// The distinguished name attribute could not be read.

ERROR_DS_CANT_RETRIEVE_DN        8405L






// No superior reference has been configured for the directory service. The directory service is therefore unable to issue referrals to objects outside this forest.

ERROR_DS_MISSING_SUPREF          8406L






// The instance type attribute could not be retrieved.

ERROR_DS_CANT_RETRIEVE_INSTANCE  8407L






// An internal error has occurred.

ERROR_DS_CODE_INCONSISTENCY      8408L






// A database error has occurred.

ERROR_DS_DATABASE_ERROR          8409L






// The attribute GOVERNSID is missing.

ERROR_DS_GOVERNSID_MISSING       8410L






// An expected attribute is missing.

ERROR_DS_MISSING_EXPECTED_ATT    8411L






// The specified naming context is missing a cross reference.

ERROR_DS_NCNAME_MISSING_CR_REF   8412L






// A security checking error has occurred.

ERROR_DS_SECURITY_CHECKING_ERROR 8413L






// The schema is not loaded.

ERROR_DS_SCHEMA_NOT_LOADED       8414L






// Schema allocation failed. Please check if the machine is running low on memory.

ERROR_DS_SCHEMA_ALLOC_FAILED     8415L






// Failed to obtain the required syntax for the attribute schema.

ERROR_DS_ATT_SCHEMA_REQ_SYNTAX   8416L






// The global catalog verification failed. The global catalog is not available or does not support the operation. Some part of the directory is currently not available.

ERROR_DS_GCVERIFY_ERROR          8417L






// The replication operation failed because of a schema mismatch between the servers involved.

ERROR_DS_DRA_SCHEMA_MISMATCH     8418L






// The DSA object could not be found.

ERROR_DS_CANT_FIND_DSA_OBJ       8419L






// The naming context could not be found.

ERROR_DS_CANT_FIND_EXPECTED_NC   8420L






// The naming context could not be found in the cache.

ERROR_DS_CANT_FIND_NC_IN_CACHE   8421L






// The child object could not be retrieved.

ERROR_DS_CANT_RETRIEVE_CHILD     8422L






// The modification was not permitted for security reasons.

ERROR_DS_SECURITY_ILLEGAL_MODIFY 8423L






// The operation cannot replace the hidden record.

ERROR_DS_CANT_REPLACE_HIDDEN_REC 8424L






// The hierarchy file is invalid.

ERROR_DS_BAD_HIERARCHY_FILE      8425L






// The attempt to build the hierarchy table failed.

ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED 8426L






// The directory configuration parameter is missing from the registry.

ERROR_DS_CONFIG_PARAM_MISSING    8427L






// The attempt to count the address book indices failed.

ERROR_DS_COUNTING_AB_INDICES_FAILED 8428L






// The allocation of the hierarchy table failed.

ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED 8429L






// The directory service encountered an internal failure.

ERROR_DS_INTERNAL_FAILURE        8430L






// The directory service encountered an unknown failure.

ERROR_DS_UNKNOWN_ERROR           8431L






// A root object requires a class of 'top'.

ERROR_DS_ROOT_REQUIRES_CLASS_TOP 8432L






// This directory server is shutting down, and cannot take ownership of new floating single-master operation roles.

ERROR_DS_REFUSING_FSMO_ROLES     8433L






// The directory service is missing mandatory configuration information, and is unable to determine the ownership of floating single-master operation roles.

ERROR_DS_MISSING_FSMO_SETTINGS   8434L






// The directory service was unable to transfer ownership of one or more floating single-master operation roles to other servers.

ERROR_DS_UNABLE_TO_SURRENDER_ROLES 8435L






// The replication operation failed.

ERROR_DS_DRA_GENERIC             8436L






// An invalid parameter was specified for this replication operation.

ERROR_DS_DRA_INVALID_PARAMETER   8437L






// The directory service is too busy to complete the replication operation at this time.

ERROR_DS_DRA_BUSY                8438L






// The distinguished name specified for this replication operation is invalid.

ERROR_DS_DRA_BAD_DN              8439L






// The naming context specified for this replication operation is invalid.

ERROR_DS_DRA_BAD_NC              8440L






// The distinguished name specified for this replication operation already exists.

ERROR_DS_DRA_DN_EXISTS           8441L






// The replication system encountered an internal error.

ERROR_DS_DRA_INTERNAL_ERROR      8442L






// The replication operation encountered a database inconsistency.

ERROR_DS_DRA_INCONSISTENT_DIT    8443L






// The server specified for this replication operation could not be contacted.

ERROR_DS_DRA_CONNECTION_FAILED   8444L






// The replication operation encountered an object with an invalid instance type.

ERROR_DS_DRA_BAD_INSTANCE_TYPE   8445L






// The replication operation failed to allocate memory.

ERROR_DS_DRA_OUT_OF_MEM          8446L






// The replication operation encountered an error with the mail system.

ERROR_DS_DRA_MAIL_PROBLEM        8447L






// The replication reference information for the target server already exists.

ERROR_DS_DRA_REF_ALREADY_EXISTS  8448L






// The replication reference information for the target server does not exist.

ERROR_DS_DRA_REF_NOT_FOUND       8449L






// The naming context cannot be removed because it is replicated to another server.

ERROR_DS_DRA_OBJ_IS_REP_SOURCE   8450L






// The replication operation encountered a database error.

ERROR_DS_DRA_DB_ERROR            8451L






// The naming context is in the process of being removed or is not replicated from the specified server.

ERROR_DS_DRA_NO_REPLICA          8452L






// Replication access was denied.

ERROR_DS_DRA_ACCESS_DENIED       8453L






// The requested operation is not supported by this version of the directory service.

ERROR_DS_DRA_NOT_SUPPORTED       8454L






// The replication remote procedure call was cancelled.

ERROR_DS_DRA_RPC_CANCELLED       8455L






// The source server is currently rejecting replication requests.

ERROR_DS_DRA_SOURCE_DISABLED     8456L






// The destination server is currently rejecting replication requests.

ERROR_DS_DRA_SINK_DISABLED       8457L






// The replication operation failed due to a collision of object names.

ERROR_DS_DRA_NAME_COLLISION      8458L






// The replication source has been reinstalled.

ERROR_DS_DRA_SOURCE_REINSTALLED  8459L






// The replication operation failed because a required parent object is missing.

ERROR_DS_DRA_MISSING_PARENT      8460L






// The replication operation was preempted.

ERROR_DS_DRA_PREEMPTED           8461L






// The replication synchronization attempt was abandoned because of a lack of updates.

ERROR_DS_DRA_ABANDON_SYNC        8462L






// The replication operation was terminated because the system is shutting down.

ERROR_DS_DRA_SHUTDOWN            8463L






// Synchronization attempt failed because the destination DC is currently waiting to synchronize new partial attributes from source. This condition is normal if a recent schema change modified the partial attribute set. The destination partial attribute set is not a subset of source partial attribute set.

ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET 8464L






// The replication synchronization attempt failed because a master replica attempted to sync from a partial replica.

ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA 8465L






// The server specified for this replication operation was contacted, but that server was unable to contact an additional server needed to complete the operation.

ERROR_DS_DRA_EXTN_CONNECTION_FAILED 8466L






// The version of the directory service schema of the source forest is not compatible with the version of directory service on this computer.

ERROR_DS_INSTALL_SCHEMA_MISMATCH 8467L






// Schema update failed: An attribute with the same link identifier already exists.

ERROR_DS_DUP_LINK_ID             8468L






// Name translation: Generic processing error.

ERROR_DS_NAME_ERROR_RESOLVING    8469L






// Name translation: Could not find the name or insufficient right to see name.

ERROR_DS_NAME_ERROR_NOT_FOUND    8470L






// Name translation: Input name mapped to more than one output name.

ERROR_DS_NAME_ERROR_NOT_UNIQUE   8471L






// Name translation: Input name found, but not the associated output format.

ERROR_DS_NAME_ERROR_NO_MAPPING   8472L






// Name translation: Unable to resolve completely, only the domain was found.

ERROR_DS_NAME_ERROR_DOMAIN_ONLY  8473L






// Name translation: Unable to perform purely syntactical mapping at the client without going out to the wire.

ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING 8474L






// Modification of a constructed attribute is not allowed.

ERROR_DS_CONSTRUCTED_ATT_MOD     8475L






// The OM-Object-Class specified is incorrect for an attribute with the specified syntax.

ERROR_DS_WRONG_OM_OBJ_CLASS      8476L






// The replication request has been posted; waiting for reply.

ERROR_DS_DRA_REPL_PENDING        8477L






// The requested operation requires a directory service, and none was available.

ERROR_DS_DS_REQUIRED             8478L






// The LDAP display name of the class or attribute contains non-ASCII characters.

ERROR_DS_INVALID_LDAP_DISPLAY_NAME 8479L






// The requested search operation is only supported for base searches.

ERROR_DS_NON_BASE_SEARCH         8480L






// The search failed to retrieve attributes from the database.

ERROR_DS_CANT_RETRIEVE_ATTS      8481L






// The schema update operation tried to add a backward link attribute that has no corresponding forward link.

ERROR_DS_BACKLINK_WITHOUT_LINK   8482L






// Source and destination of a cross-domain move do not agree on the object's epoch number. Either source or destination does not have the latest version of the object.

ERROR_DS_EPOCH_MISMATCH          8483L






// Source and destination of a cross-domain move do not agree on the object's current name. Either source or destination does not have the latest version of the object.

ERROR_DS_SRC_NAME_MISMATCH       8484L






// Source and destination for the cross-domain move operation are identical. Caller should use local move operation instead of cross-domain move operation.

ERROR_DS_SRC_AND_DST_NC_IDENTICAL 8485L






// Source and destination for a cross-domain move are not in agreement on the naming contexts in the forest. Either source or destination does not have the latest version of the Partitions container.

ERROR_DS_DST_NC_MISMATCH         8486L






// Destination of a cross-domain move is not authoritative for the destination naming context.

ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC 8487L






// Source and destination of a cross-domain move do not agree on the identity of the source object. Either source or destination does not have the latest version of the source object.

ERROR_DS_SRC_GUID_MISMATCH       8488L






// Object being moved across-domains is already known to be deleted by the destination server. The source server does not have the latest version of the source object.

ERROR_DS_CANT_MOVE_DELETED_OBJECT 8489L






// Another operation which requires exclusive access to the PDC FSMO is already in progress.

ERROR_DS_PDC_OPERATION_IN_PROGRESS 8490L






// A cross-domain move operation failed such that two versions of the moved object exist - one each in the source and destination domains. The destination object needs to be removed to restore the system to a consistent state.

ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD 8491L






// This object may not be moved across domain boundaries either because cross-domain moves for this class are disallowed, or the object has some special characteristics, e.g.: trust account or restricted RID, which prevent its move.

ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION 8492L






// Can't move objects with memberships across domain boundaries as once moved, this would violate the membership conditions of the account group. Remove the object from any account group memberships and retry.

ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS 8493L






// A naming context head must be the immediate child of another naming context head, not of an interior node.

ERROR_DS_NC_MUST_HAVE_NC_PARENT  8494L






// The directory cannot validate the proposed naming context name because it does not hold a replica of the naming context above the proposed naming context. Please ensure that the domain naming master role is held by a server that is configured as a global catalog server, and that the server is up to date with its replication partners. (Applies only to Windows 2000 Domain Naming masters)

ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE 8495L






// Destination domain must be in native mode.

ERROR_DS_DST_DOMAIN_NOT_NATIVE   8496L






// The operation cannot be performed because the server does not have an infrastructure container in the domain of interest.

ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER 8497L






// Cross-domain move of non-empty account groups is not allowed.

ERROR_DS_CANT_MOVE_ACCOUNT_GROUP 8498L






// Cross-domain move of non-empty resource groups is not allowed.

ERROR_DS_CANT_MOVE_RESOURCE_GROUP 8499L






// The search flags for the attribute are invalid. The ANR bit is valid only on attributes of Unicode or Teletex strings.

ERROR_DS_INVALID_SEARCH_FLAG     8500L






// Tree deletions starting at an object which has an NC head as a descendant are not allowed.

ERROR_DS_NO_TREE_DELETE_ABOVE_NC 8501L






// The directory service failed to lock a tree in preparation for a tree deletion because the tree was in use.

ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE 8502L






// The directory service failed to identify the list of objects to delete while attempting a tree deletion.

ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE 8503L






// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Please shutdown this system and reboot into Directory Services Restore Mode, check the event log for more detailed information.

ERROR_DS_SAM_INIT_FAILURE        8504L






// Only an administrator can modify the membership list of an administrative group.

ERROR_DS_SENSITIVE_GROUP_VIOLATION 8505L






// Cannot change the primary group ID of a domain controller account.

ERROR_DS_CANT_MOD_PRIMARYGROUPID 8506L






// An attempt is made to modify the base schema.

ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD 8507L






// Adding a new mandatory attribute to an existing class, deleting a mandatory attribute from an existing class, or adding an optional attribute to the special class Top that is not a backlink attribute (directly or through inheritance, for example, by adding or deleting an auxiliary class) is not allowed.

ERROR_DS_NONSAFE_SCHEMA_CHANGE   8508L






// Schema update is not allowed on this DC because the DC is not the schema FSMO Role Owner.

ERROR_DS_SCHEMA_UPDATE_DISALLOWED 8509L






// An object of this class cannot be created under the schema container. You can only create attribute-schema and class-schema objects under the schema container.

ERROR_DS_CANT_CREATE_UNDER_SCHEMA 8510L






// The replica/child install failed to get the objectVersion attribute on the schema container on the source DC. Either the attribute is missing on the schema container or the credentials supplied do not have permission to read it.

ERROR_DS_INSTALL_NO_SRC_SCH_VERSION 8511L






// The replica/child install failed to read the objectVersion attribute in the SCHEMA section of the file schema.ini in the system32 directory.

ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE 8512L






// The specified group type is invalid.

ERROR_DS_INVALID_GROUP_TYPE      8513L






// You cannot nest global groups in a mixed domain if the group is security-enabled.

ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN 8514L






// You cannot nest local groups in a mixed domain if the group is security-enabled.

ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN 8515L






// A global group cannot have a local group as a member.

ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER 8516L






// A global group cannot have a universal group as a member.

ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER 8517L






// A universal group cannot have a local group as a member.

ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER 8518L






// A global group cannot have a cross-domain member.

ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER 8519L






// A local group cannot have another cross domain local group as a member.

ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER 8520L






// A group with primary members cannot change to a security-disabled group.

ERROR_DS_HAVE_PRIMARY_MEMBERS    8521L






// The schema cache load failed to convert the string default SD on a class-schema object.

ERROR_DS_STRING_SD_CONVERSION_FAILED 8522L






// Only DSAs configured to be Global Catalog servers should be allowed to hold the Domain Naming Master FSMO role. (Applies only to Windows 2000 servers)

ERROR_DS_NAMING_MASTER_GC        8523L






// The DSA operation is unable to proceed because of a DNS lookup failure.

ERROR_DS_DNS_LOOKUP_FAILURE      8524L






// While processing a change to the DNS Host Name for an object, the Service Principal Name values could not be kept in sync.

ERROR_DS_COULDNT_UPDATE_SPNS     8525L






// The Security Descriptor attribute could not be read.

ERROR_DS_CANT_RETRIEVE_SD        8526L






// The object requested was not found, but an object with that key was found.

ERROR_DS_KEY_NOT_UNIQUE          8527L






// The syntax of the linked attribute being added is incorrect. Forward links can only have syntax 2.5.5.1, 2.5.5.7, and 2.5.5.14, and backlinks can only have syntax 2.5.5.1

ERROR_DS_WRONG_LINKED_ATT_SYNTAX 8528L






// Security Account Manager needs to get the boot password.

ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD 8529L






// Security Account Manager needs to get the boot key from floppy disk.

ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY 8530L






// Directory Service cannot start.

ERROR_DS_CANT_START              8531L






// Directory Services could not start.

ERROR_DS_INIT_FAILURE            8532L






// The connection between client and server requires packet privacy or better.

ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION 8533L






// The source domain may not be in the same forest as destination.

ERROR_DS_SOURCE_DOMAIN_IN_FOREST 8534L






// The destination domain must be in the forest.

ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST 8535L






// The operation requires that destination domain auditing be enabled.

ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED 8536L






// The operation couldn't locate a DC for the source domain.

ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN 8537L






// The source object must be a group or user.

ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER 8538L






// The source object's SID already exists in destination forest.

ERROR_DS_SRC_SID_EXISTS_IN_FOREST 8539L






// The source and destination object must be of the same type.

ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH 8540L






// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Click OK to shut down the system and reboot into Safe Mode. Check the event log for detailed information.

ERROR_SAM_INIT_FAILURE           8541L






// Schema information could not be included in the replication request.

ERROR_DS_DRA_SCHEMA_INFO_SHIP    8542L






// The replication operation could not be completed due to a schema incompatibility.

ERROR_DS_DRA_SCHEMA_CONFLICT     8543L






// The replication operation could not be completed due to a previous schema incompatibility.

ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT 8544L






// The replication update could not be applied because either the source or the destination has not yet received information regarding a recent cross-domain move operation.

ERROR_DS_DRA_OBJ_NC_MISMATCH     8545L






// The requested domain could not be deleted because there exist domain controllers that still host this domain.

ERROR_DS_NC_STILL_HAS_DSAS       8546L






// The requested operation can be performed only on a global catalog server.

ERROR_DS_GC_REQUIRED             8547L






// A local group can only be a member of other local groups in the same domain.

ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY 8548L






// Foreign security principals cannot be members of universal groups.

ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS 8549L






// The attribute is not allowed to be replicated to the GC because of security reasons.

ERROR_DS_CANT_ADD_TO_GC          8550L






// The checkpoint with the PDC could not be taken because there too many modifications being processed currently.

ERROR_DS_NO_CHECKPOINT_WITH_PDC  8551L






// The operation requires that source domain auditing be enabled.

ERROR_DS_SOURCE_AUDITING_NOT_ENABLED 8552L






// Security principal objects can only be created inside domain naming contexts.

ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC 8553L






// A Service Principal Name (SPN) could not be constructed because the provided hostname is not in the necessary format.

ERROR_DS_INVALID_NAME_FOR_SPN    8554L






// A Filter was passed that uses constructed attributes.

ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS 8555L






// The unicodePwd attribute value must be enclosed in double quotes.

ERROR_DS_UNICODEPWD_NOT_IN_QUOTES 8556L






// Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased.

ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED 8557L






// For security reasons, the operation must be run on the destination DC.

ERROR_DS_MUST_BE_RUN_ON_DST_DC   8558L






// For security reasons, the source DC must be NT4SP4 or greater.

ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER 8559L






// Critical Directory Service System objects cannot be deleted during tree delete operations. The tree delete may have been partially performed.

ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ 8560L






// Directory Services could not start because of the following error: %1.
// Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.

ERROR_DS_INIT_FAILURE_CONSOLE    8561L






// Security Accounts Manager initialization failed because of the following error: %1.
// Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.

ERROR_DS_SAM_INIT_FAILURE_CONSOLE 8562L






// The version of the operating system is incompatible with the current AD DS forest functional level or AD LDS Configuration Set functional level. You must upgrade to a new version of the operating system before this server can become an AD DS Domain Controller or add an AD LDS Instance in this AD DS Forest or AD LDS Configuration Set.

ERROR_DS_FOREST_VERSION_TOO_HIGH 8563L






// The version of the operating system installed is incompatible with the current domain functional level. You must upgrade to a new version of the operating system before this server can become a domain controller in this domain.

ERROR_DS_DOMAIN_VERSION_TOO_HIGH 8564L






// The version of the operating system installed on this server no longer supports the current AD DS Forest functional level or AD LDS Configuration Set functional level. You must raise the AD DS Forest functional level or AD LDS Configuration Set functional level before this server can become an AD DS Domain Controller or an AD LDS Instance in this Forest or Configuration Set.

ERROR_DS_FOREST_VERSION_TOO_LOW  8565L






// The version of the operating system installed on this server no longer supports the current domain functional level. You must raise the domain functional level before this server can become a domain controller in this domain.

ERROR_DS_DOMAIN_VERSION_TOO_LOW  8566L






// The version of the operating system installed on this server is incompatible with the functional level of the domain or forest.

ERROR_DS_INCOMPATIBLE_VERSION    8567L






// The functional level of the domain (or forest) cannot be raised to the requested value, because there exist one or more domain controllers in the domain (or forest) that are at a lower incompatible functional level.

ERROR_DS_LOW_DSA_VERSION         8568L






// The forest functional level cannot be raised to the requested value since one or more domains are still in mixed domain mode. All domains in the forest must be in native mode, for you to raise the forest functional level.

ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN 8569L






// The sort order requested is not supported.

ERROR_DS_NOT_SUPPORTED_SORT_ORDER 8570L






// The requested name already exists as a unique identifier.

ERROR_DS_NAME_NOT_UNIQUE         8571L






// The machine account was created pre-NT4. The account needs to be recreated.

ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4 8572L






// The database is out of version store.

ERROR_DS_OUT_OF_VERSION_STORE    8573L






// Unable to continue operation because multiple conflicting controls were used.

ERROR_DS_INCOMPATIBLE_CONTROLS_USED 8574L






// Unable to find a valid security descriptor reference domain for this partition.

ERROR_DS_NO_REF_DOMAIN           8575L






// Schema update failed: The link identifier is reserved.

ERROR_DS_RESERVED_LINK_ID        8576L






// Schema update failed: There are no link identifiers available.

ERROR_DS_LINK_ID_NOT_AVAILABLE   8577L






// An account group cannot have a universal group as a member.

ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER 8578L






// Rename or move operations on naming context heads or read-only objects are not allowed.

ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE 8579L






// Move operations on objects in the schema naming context are not allowed.

ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC 8580L






// A system flag has been set on the object and does not allow the object to be moved or renamed.

ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG 8581L






// This object is not allowed to change its grandparent container. Moves are not forbidden on this object, but are restricted to sibling containers.

ERROR_DS_MODIFYDN_WRONG_GRANDPARENT 8582L






// Unable to resolve completely, a referral to another forest is generated.

ERROR_DS_NAME_ERROR_TRUST_REFERRAL 8583L






// The requested action is not supported on standard server.

ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER 8584L






// Could not access a partition of the directory service located on a remote server. Make sure at least one server is running for the partition in question.

ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD 8585L






// The directory cannot validate the proposed naming context (or partition) name because it does not hold a replica nor can it contact a replica of the naming context above the proposed naming context. Please ensure that the parent naming context is properly registered in DNS, and at least one replica of this naming context is reachable by the Domain Naming master.

ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2 8586L






// The thread limit for this request was exceeded.

ERROR_DS_THREAD_LIMIT_EXCEEDED   8587L






// The Global catalog server is not in the closest site.

ERROR_DS_NOT_CLOSEST             8588L






// The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the corresponding server object in the local DS database has no serverReference attribute.

ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF 8589L






// The Directory Service failed to enter single user mode.

ERROR_DS_SINGLE_USER_MODE_FAILED 8590L






// The Directory Service cannot parse the script because of a syntax error.

ERROR_DS_NTDSCRIPT_SYNTAX_ERROR  8591L






// The Directory Service cannot process the script because of an error.

ERROR_DS_NTDSCRIPT_PROCESS_ERROR 8592L






// The directory service cannot perform the requested operation because the servers involved are of different replication epochs (which is usually related to a domain rename that is in progress).

ERROR_DS_DIFFERENT_REPL_EPOCHS   8593L






// The directory service binding must be renegotiated due to a change in the server extensions information.

ERROR_DS_DRS_EXTENSIONS_CHANGED  8594L






// Operation not allowed on a disabled cross ref.

ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR 8595L






// Schema update failed: No values for msDS-IntId are available.

ERROR_DS_NO_MSDS_INTID           8596L






// Schema update failed: Duplicate msDS-INtId. Retry the operation.

ERROR_DS_DUP_MSDS_INTID          8597L






// Schema deletion failed: attribute is used in rDNAttID.

ERROR_DS_EXISTS_IN_RDNATTID      8598L






// The directory service failed to authorize the request.

ERROR_DS_AUTHORIZATION_FAILED    8599L






// The Directory Service cannot process the script because it is invalid.

ERROR_DS_INVALID_SCRIPT          8600L






// The remote create cross reference operation failed on the Domain Naming Master FSMO. The operation's error is in the extended data.

ERROR_DS_REMOTE_CROSSREF_OP_FAILED 8601L






// A cross reference is in use locally with the same name.

ERROR_DS_CROSS_REF_BUSY          8602L






// The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the server's domain has been deleted from the forest.

ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN 8603L






// Writeable NCs prevent this DC from demoting.

ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC 8604L






// The requested object has a non-unique identifier and cannot be retrieved.

ERROR_DS_DUPLICATE_ID_FOUND      8605L






// Insufficient attributes were given to create an object. This object may not exist because it may have been deleted and already garbage collected.

ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT 8606L






// The group cannot be converted due to attribute restrictions on the requested group type.

ERROR_DS_GROUP_CONVERSION_ERROR  8607L






// Cross-domain move of non-empty basic application groups is not allowed.

ERROR_DS_CANT_MOVE_APP_BASIC_GROUP 8608L






// Cross-domain move of non-empty query based application groups is not allowed.

ERROR_DS_CANT_MOVE_APP_QUERY_GROUP 8609L






// The FSMO role ownership could not be verified because its directory partition has not replicated successfully with at least one replication partner.

ERROR_DS_ROLE_NOT_VERIFIED       8610L






// The target container for a redirection of a well known object container cannot already be a special container.

ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL 8611L






// The Directory Service cannot perform the requested operation because a domain rename operation is in progress.

ERROR_DS_DOMAIN_RENAME_IN_PROGRESS 8612L






// The directory service detected a child partition below the requested partition name. The partition hierarchy must be created in a top down method.

ERROR_DS_EXISTING_AD_CHILD_NC    8613L






// The directory service cannot replicate with this server because the time since the last replication with this server has exceeded the tombstone lifetime.

ERROR_DS_REPL_LIFETIME_EXCEEDED  8614L






// The requested operation is not allowed on an object under the system container.

ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER 8615L






// The LDAP servers network send queue has filled up because the client is not processing the results of its requests fast enough. No more requests will be processed until the client catches up. If the client does not catch up then it will be disconnected.

ERROR_DS_LDAP_SEND_QUEUE_FULL    8616L






// The scheduled replication did not take place because the system was too busy to execute the request within the schedule window. The replication queue is overloaded. Consider reducing the number of partners or decreasing the scheduled replication frequency.

ERROR_DS_DRA_OUT_SCHEDULE_WINDOW 8617L






// At this time, it cannot be determined if the branch replication policy is available on the hub domain controller. Please retry at a later time to account for replication latencies.

ERROR_DS_POLICY_NOT_KNOWN        8618L






// The site settings object for the specified site does not exist.

ERROR_NO_SITE_SETTINGS_OBJECT    8619L






// The local account store does not contain secret material for the specified account.

ERROR_NO_SECRETS                 8620L






// Could not find a writable domain controller in the domain.

ERROR_NO_WRITABLE_DC_FOUND       8621L






// The server object for the domain controller does not exist.

ERROR_DS_NO_SERVER_OBJECT        8622L






// The NTDS Settings object for the domain controller does not exist.

ERROR_DS_NO_NTDSA_OBJECT         8623L






// The requested search operation is not supported for ASQ searches.

ERROR_DS_NON_ASQ_SEARCH          8624L






// A required audit event could not be generated for the operation.

ERROR_DS_AUDIT_FAILURE           8625L






// The search flags for the attribute are invalid. The subtree index bit is valid only on single valued attributes.

ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE 8626L






// The search flags for the attribute are invalid. The tuple index bit is valid only on attributes of Unicode strings.

ERROR_DS_INVALID_SEARCH_FLAG_TUPLE 8627L






// The address books are nested too deeply. Failed to build the hierarchy table.

ERROR_DS_HIERARCHY_TABLE_TOO_DEEP 8628L






// The specified up-to-date-ness vector is corrupt.

ERROR_DS_DRA_CORRUPT_UTD_VECTOR  8629L






// The request to replicate secrets is denied.

ERROR_DS_DRA_SECRETS_DENIED      8630L






// Schema update failed: The MAPI identifier is reserved.

ERROR_DS_RESERVED_MAPI_ID        8631L






// Schema update failed: There are no MAPI identifiers available.

ERROR_DS_MAPI_ID_NOT_AVAILABLE   8632L






// The replication operation failed because the required attributes of the local krbtgt object are missing.

ERROR_DS_DRA_MISSING_KRBTGT_SECRET 8633L






// The domain name of the trusted domain already exists in the forest.

ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST 8634L






// The flat name of the trusted domain already exists in the forest.

ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST 8635L






// The User Principal Name (UPN) is invalid.

ERROR_INVALID_USER_PRINCIPAL_NAME 8636L






// OID mapped groups cannot have members.

ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS 8637L






// The specified OID cannot be found.

ERROR_DS_OID_NOT_FOUND           8638L






// The replication operation failed because the target object referred by a link value is recycled.

ERROR_DS_DRA_RECYCLED_TARGET     8639L






// The redirect operation failed because the target object is in a NC different from the domain NC of the current domain controller.

ERROR_DS_DISALLOWED_NC_REDIRECT  8640L






// The functional level of the AD LDS configuration set cannot be lowered to the requested value.

ERROR_DS_HIGH_ADLDS_FFL          8641L






// The functional level of the domain (or forest) cannot be lowered to the requested value.

ERROR_DS_HIGH_DSA_VERSION        8642L






// The functional level of the AD LDS configuration set cannot be raised to the requested value, because there exist one or more ADLDS instances that are at a lower incompatible functional level.

ERROR_DS_LOW_ADLDS_FFL           8643L






// The domain join cannot be completed because the SID of the domain you attempted to join was identical to the SID of this machine. This is a symptom of an improperly cloned operating system install.  You should run sysprep on this machine in order to generate a new machine SID. Please see http://go.microsoft.com/fwlink/?LinkId=168895 for more information.

ERROR_DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION 8644L






// The undelete operation failed because the Sam Account Name or Additional Sam Account Name of the object being undeleted conflicts with an existing live object.

ERROR_DS_UNDELETE_SAM_VALIDATION_FAILED 8645L






// The system is not authoritative for the specified account and therefore cannot complete the operation. Please retry the operation using the provider associated with this account. If this is an online provider please use the provider's online site.

ERROR_INCORRECT_ACCOUNT_TYPE     8646L






// The operation failed because SPN value provided for addition/modification is not unique forest-wide.

ERROR_DS_SPN_VALUE_NOT_UNIQUE_IN_FOREST 8647L






// The operation failed because UPN value provided for addition/modification is not unique forest-wide.

ERROR_DS_UPN_VALUE_NOT_UNIQUE_IN_FOREST 8648L






// The operation failed because the addition/modification referenced an inbound forest-wide trust that is not present.

ERROR_DS_MISSING_FOREST_TRUST    8649L






// The link value specified was not found, but a link value with that key was found.

ERROR_DS_VALUE_KEY_NOT_UNIQUE    8650L


///////////////////////////////////////////////////
//                                                /
//        End of Active Directory Error Codes     /
//                                                /
//                  8000 to  8999                 /
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//               DNS Error codes                 //
//                                               //
//                 9000 to 9999                  //
///////////////////////////////////////////////////

// =============================
// Facility DNS Error Messages
// =============================


//  DNS response codes.


DNS_ERROR_RESPONSE_CODES_BASE 9000

DNS_ERROR_RCODE_NO_ERROR NO_ERROR

DNS_ERROR_MASK 0x00002328 // 9000 or DNS_ERROR_RESPONSE_CODES_BASE

// DNS_ERROR_RCODE_FORMAT_ERROR          0x00002329





// DNS server unable to interpret format.

DNS_ERROR_RCODE_FORMAT_ERROR     9001L

// DNS_ERROR_RCODE_SERVER_FAILURE        0x0000232a





// DNS server failure.

DNS_ERROR_RCODE_SERVER_FAILURE   9002L

// DNS_ERROR_RCODE_NAME_ERROR            0x0000232b





// DNS name does not exist.

DNS_ERROR_RCODE_NAME_ERROR       9003L

// DNS_ERROR_RCODE_NOT_IMPLEMENTED       0x0000232c





// DNS request not supported by name server.

DNS_ERROR_RCODE_NOT_IMPLEMENTED  9004L

// DNS_ERROR_RCODE_REFUSED               0x0000232d





// DNS operation refused.

DNS_ERROR_RCODE_REFUSED          9005L

// DNS_ERROR_RCODE_YXDOMAIN              0x0000232e





// DNS name that ought not exist, does exist.

DNS_ERROR_RCODE_YXDOMAIN         9006L

// DNS_ERROR_RCODE_YXRRSET               0x0000232f





// DNS RR set that ought not exist, does exist.

DNS_ERROR_RCODE_YXRRSET          9007L

// DNS_ERROR_RCODE_NXRRSET               0x00002330





// DNS RR set that ought to exist, does not exist.

DNS_ERROR_RCODE_NXRRSET          9008L

// DNS_ERROR_RCODE_NOTAUTH               0x00002331





// DNS server not authoritative for zone.

DNS_ERROR_RCODE_NOTAUTH          9009L

// DNS_ERROR_RCODE_NOTZONE               0x00002332





// DNS name in update or prereq is not in zone.

DNS_ERROR_RCODE_NOTZONE          9010L

// DNS_ERROR_RCODE_BADSIG                0x00002338





// DNS signature failed to verify.

DNS_ERROR_RCODE_BADSIG           9016L

// DNS_ERROR_RCODE_BADKEY                0x00002339





// DNS bad key.

DNS_ERROR_RCODE_BADKEY           9017L

// DNS_ERROR_RCODE_BADTIME               0x0000233a





// DNS signature validity expired.

DNS_ERROR_RCODE_BADTIME          9018L

DNS_ERROR_RCODE_LAST DNS_ERROR_RCODE_BADTIME



// DNSSEC errors


DNS_ERROR_DNSSEC_BASE 9100






// Only the DNS server acting as the key master for the zone may perform this operation.

DNS_ERROR_KEYMASTER_REQUIRED     9101L






// This operation is not allowed on a zone that is signed or has signing keys.

DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE 9102L






// NSEC3 is not compatible with the RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC.

DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1 9103L






// The zone does not have enough signing keys. There must be at least one key signing key (KSK) and at least one zone signing key (ZSK).

DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS 9104L






// The specified algorithm is not supported.

DNS_ERROR_UNSUPPORTED_ALGORITHM  9105L






// The specified key size is not supported.

DNS_ERROR_INVALID_KEY_SIZE       9106L






// One or more of the signing keys for a zone are not accessible to the DNS server. Zone signing will not be operational until this error is resolved.

DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE 9107L






// The specified key storage provider does not support DPAPI++ data protection. Zone signing will not be operational until this error is resolved.

DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION 9108L






// An unexpected DPAPI++ error was encountered. Zone signing will not be operational until this error is resolved.

DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR 9109L






// An unexpected crypto error was encountered. Zone signing may not be operational until this error is resolved.

DNS_ERROR_UNEXPECTED_CNG_ERROR   9110L






// The DNS server encountered a signing key with an unknown version. Zone signing will not be operational until this error is resolved.

DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION 9111L






// The specified key service provider cannot be opened by the DNS server.

DNS_ERROR_KSP_NOT_ACCESSIBLE     9112L






// The DNS server cannot accept any more signing keys with the specified algorithm and KSK flag value for this zone.

DNS_ERROR_TOO_MANY_SKDS          9113L






// The specified rollover period is invalid.

DNS_ERROR_INVALID_ROLLOVER_PERIOD 9114L






// The specified initial rollover offset is invalid.

DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET 9115L






// The specified signing key is already in process of rolling over keys.

DNS_ERROR_ROLLOVER_IN_PROGRESS   9116L






// The specified signing key does not have a standby key to revoke.

DNS_ERROR_STANDBY_KEY_NOT_PRESENT 9117L






// This operation is not allowed on a zone signing key (ZSK).

DNS_ERROR_NOT_ALLOWED_ON_ZSK     9118L






// This operation is not allowed on an active signing key.

DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD 9119L






// The specified signing key is already queued for rollover.

DNS_ERROR_ROLLOVER_ALREADY_QUEUED 9120L






// This operation is not allowed on an unsigned zone.

DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE 9121L






// This operation could not be completed because the DNS server listed as the current key master for this zone is down or misconfigured. Resolve the problem on the current key master for this zone or use another DNS server to seize the key master role.

DNS_ERROR_BAD_KEYMASTER          9122L






// The specified signature validity period is invalid.

DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD 9123L






// The specified NSEC3 iteration count is higher than allowed by the minimum key length used in the zone.

DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT 9124L






// This operation could not be completed because the DNS server has been configured with DNSSEC features disabled. Enable DNSSEC on the DNS server.

DNS_ERROR_DNSSEC_IS_DISABLED     9125L






// This operation could not be completed because the XML stream received is empty or syntactically invalid.

DNS_ERROR_INVALID_XML            9126L






// This operation completed, but no trust anchors were added because all of the trust anchors received were either invalid, unsupported, expired, or would not become valid in less than 30 days.

DNS_ERROR_NO_VALID_TRUST_ANCHORS 9127L






// The specified signing key is not waiting for parental DS update.

DNS_ERROR_ROLLOVER_NOT_POKEABLE  9128L






// Hash collision detected during NSEC3 signing. Specify a different user-provided salt, or use a randomly generated salt, and attempt to sign the zone again.

DNS_ERROR_NSEC3_NAME_COLLISION   9129L






// NSEC is not compatible with the NSEC3-RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC3.

DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1 9130L



// Packet format


DNS_ERROR_PACKET_FMT_BASE 9500

// DNS_INFO_NO_RECORDS                   0x0000251d





// No records found for given DNS query.

DNS_INFO_NO_RECORDS              9501L

// DNS_ERROR_BAD_PACKET                  0x0000251e





// Bad DNS packet.

DNS_ERROR_BAD_PACKET             9502L

// DNS_ERROR_NO_PACKET                   0x0000251f





// No DNS packet.

DNS_ERROR_NO_PACKET              9503L

// DNS_ERROR_RCODE                       0x00002520





// DNS error, check rcode.

DNS_ERROR_RCODE                  9504L

// DNS_ERROR_UNSECURE_PACKET             0x00002521





// Unsecured DNS packet.

DNS_ERROR_UNSECURE_PACKET        9505L

DNS_STATUS_PACKET_UNSECURE DNS_ERROR_UNSECURE_PACKET

// DNS_REQUEST_PENDING                     0x00002522





// DNS query request is pending.

DNS_REQUEST_PENDING              9506L



// General API errors


DNS_ERROR_NO_MEMORY            ERROR_OUTOFMEMORY
DNS_ERROR_INVALID_NAME         ERROR_INVALID_NAME
DNS_ERROR_INVALID_DATA         ERROR_INVALID_DATA

DNS_ERROR_GENERAL_API_BASE 9550

// DNS_ERROR_INVALID_TYPE                0x0000254f





// Invalid DNS type.

DNS_ERROR_INVALID_TYPE           9551L

// DNS_ERROR_INVALID_IP_ADDRESS          0x00002550





// Invalid IP address.

DNS_ERROR_INVALID_IP_ADDRESS     9552L

// DNS_ERROR_INVALID_PROPERTY            0x00002551





// Invalid property.

DNS_ERROR_INVALID_PROPERTY       9553L

// DNS_ERROR_TRY_AGAIN_LATER             0x00002552





// Try DNS operation again later.

DNS_ERROR_TRY_AGAIN_LATER        9554L

// DNS_ERROR_NOT_UNIQUE                  0x00002553





// Record for given name and type is not unique.

DNS_ERROR_NOT_UNIQUE             9555L

// DNS_ERROR_NON_RFC_NAME                0x00002554





// DNS name does not comply with RFC specifications.

DNS_ERROR_NON_RFC_NAME           9556L

// DNS_STATUS_FQDN                       0x00002555





// DNS name is a fully-qualified DNS name.

DNS_STATUS_FQDN                  9557L

// DNS_STATUS_DOTTED_NAME                0x00002556





// DNS name is dotted (multi-label).

DNS_STATUS_DOTTED_NAME           9558L

// DNS_STATUS_SINGLE_PART_NAME           0x00002557





// DNS name is a single-part name.

DNS_STATUS_SINGLE_PART_NAME      9559L

// DNS_ERROR_INVALID_NAME_CHAR           0x00002558





// DNS name contains an invalid character.

DNS_ERROR_INVALID_NAME_CHAR      9560L

// DNS_ERROR_NUMERIC_NAME                0x00002559





// DNS name is entirely numeric.

DNS_ERROR_NUMERIC_NAME           9561L

// DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER  0x0000255A





// The operation requested is not permitted on a DNS root server.

DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER 9562L

// DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION  0x0000255B





// The record could not be created because this part of the DNS namespace has been delegated to another server.

DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION 9563L

// DNS_ERROR_CANNOT_FIND_ROOT_HINTS  0x0000255C





// The DNS server could not find a set of root hints.

DNS_ERROR_CANNOT_FIND_ROOT_HINTS 9564L

// DNS_ERROR_INCONSISTENT_ROOT_HINTS  0x0000255D





// The DNS server found root hints but they were not consistent across all adapters.

DNS_ERROR_INCONSISTENT_ROOT_HINTS 9565L

// DNS_ERROR_DWORD_VALUE_TOO_SMALL    0x0000255E





// The specified value is too small for this parameter.

DNS_ERROR_DWORD_VALUE_TOO_SMALL  9566L

// DNS_ERROR_DWORD_VALUE_TOO_LARGE    0x0000255F





// The specified value is too large for this parameter.

DNS_ERROR_DWORD_VALUE_TOO_LARGE  9567L

// DNS_ERROR_BACKGROUND_LOADING       0x00002560





// This operation is not allowed while the DNS server is loading zones in the background. Please try again later.

DNS_ERROR_BACKGROUND_LOADING     9568L

// DNS_ERROR_NOT_ALLOWED_ON_RODC      0x00002561





// The operation requested is not permitted on against a DNS server running on a read-only DC.

DNS_ERROR_NOT_ALLOWED_ON_RODC    9569L

// DNS_ERROR_NOT_ALLOWED_UNDER_DNAME   0x00002562





// No data is allowed to exist underneath a DNAME record.

DNS_ERROR_NOT_ALLOWED_UNDER_DNAME 9570L

// DNS_ERROR_DELEGATION_REQUIRED       0x00002563





// This operation requires credentials delegation.

DNS_ERROR_DELEGATION_REQUIRED    9571L

// DNS_ERROR_INVALID_POLICY_TABLE        0x00002564





// Name resolution policy table has been corrupted. DNS resolution will fail until it is fixed. Contact your network administrator.

DNS_ERROR_INVALID_POLICY_TABLE   9572L

// DNS_ERROR_ADDRESS_REQUIRED        0x00002565





// Not allowed to remove all addresses.

DNS_ERROR_ADDRESS_REQUIRED       9573L



// Zone errors


DNS_ERROR_ZONE_BASE 9600

// DNS_ERROR_ZONE_DOES_NOT_EXIST         0x00002581





// DNS zone does not exist.

DNS_ERROR_ZONE_DOES_NOT_EXIST    9601L

// DNS_ERROR_NO_ZONE_INFO                0x00002582





// DNS zone information not available.

DNS_ERROR_NO_ZONE_INFO           9602L

// DNS_ERROR_INVALID_ZONE_OPERATION      0x00002583





// Invalid operation for DNS zone.

DNS_ERROR_INVALID_ZONE_OPERATION 9603L

// DNS_ERROR_ZONE_CONFIGURATION_ERROR    0x00002584





// Invalid DNS zone configuration.

DNS_ERROR_ZONE_CONFIGURATION_ERROR 9604L

// DNS_ERROR_ZONE_HAS_NO_SOA_RECORD      0x00002585





// DNS zone has no start of authority (SOA) record.

DNS_ERROR_ZONE_HAS_NO_SOA_RECORD 9605L

// DNS_ERROR_ZONE_HAS_NO_NS_RECORDS      0x00002586





// DNS zone has no Name Server (NS) record.

DNS_ERROR_ZONE_HAS_NO_NS_RECORDS 9606L

// DNS_ERROR_ZONE_LOCKED                 0x00002587





// DNS zone is locked.

DNS_ERROR_ZONE_LOCKED            9607L

// DNS_ERROR_ZONE_CREATION_FAILED        0x00002588





// DNS zone creation failed.

DNS_ERROR_ZONE_CREATION_FAILED   9608L

// DNS_ERROR_ZONE_ALREADY_EXISTS         0x00002589





// DNS zone already exists.

DNS_ERROR_ZONE_ALREADY_EXISTS    9609L

// DNS_ERROR_AUTOZONE_ALREADY_EXISTS     0x0000258a





// DNS automatic zone already exists.

DNS_ERROR_AUTOZONE_ALREADY_EXISTS 9610L

// DNS_ERROR_INVALID_ZONE_TYPE           0x0000258b





// Invalid DNS zone type.

DNS_ERROR_INVALID_ZONE_TYPE      9611L

// DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP 0x0000258c





// Secondary DNS zone requires master IP address.

DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP 9612L

// DNS_ERROR_ZONE_NOT_SECONDARY          0x0000258d





// DNS zone not secondary.

DNS_ERROR_ZONE_NOT_SECONDARY     9613L

// DNS_ERROR_NEED_SECONDARY_ADDRESSES    0x0000258e





// Need secondary IP address.

DNS_ERROR_NEED_SECONDARY_ADDRESSES 9614L

// DNS_ERROR_WINS_INIT_FAILED            0x0000258f





// WINS initialization failed.

DNS_ERROR_WINS_INIT_FAILED       9615L

// DNS_ERROR_NEED_WINS_SERVERS           0x00002590





// Need WINS servers.

DNS_ERROR_NEED_WINS_SERVERS      9616L

// DNS_ERROR_NBSTAT_INIT_FAILED          0x00002591





// NBTSTAT initialization call failed.

DNS_ERROR_NBSTAT_INIT_FAILED     9617L

// DNS_ERROR_SOA_DELETE_INVALID          0x00002592





// Invalid delete of start of authority (SOA)

DNS_ERROR_SOA_DELETE_INVALID     9618L

// DNS_ERROR_FORWARDER_ALREADY_EXISTS    0x00002593





// A conditional forwarding zone already exists for that name.

DNS_ERROR_FORWARDER_ALREADY_EXISTS 9619L

// DNS_ERROR_ZONE_REQUIRES_MASTER_IP     0x00002594





// This zone must be configured with one or more master DNS server IP addresses.

DNS_ERROR_ZONE_REQUIRES_MASTER_IP 9620L

// DNS_ERROR_ZONE_IS_SHUTDOWN            0x00002595





// The operation cannot be performed because this zone is shut down.

DNS_ERROR_ZONE_IS_SHUTDOWN       9621L

// DNS_ERROR_ZONE_LOCKED_FOR_SIGNING     0x00002596





// This operation cannot be performed because the zone is currently being signed. Please try again later.

DNS_ERROR_ZONE_LOCKED_FOR_SIGNING 9622L



// Datafile errors


DNS_ERROR_DATAFILE_BASE 9650

// DNS                                   0x000025b3





// Primary DNS zone requires datafile.

DNS_ERROR_PRIMARY_REQUIRES_DATAFILE 9651L

// DNS                                   0x000025b4





// Invalid datafile name for DNS zone.

DNS_ERROR_INVALID_DATAFILE_NAME  9652L

// DNS                                   0x000025b5





// Failed to open datafile for DNS zone.

DNS_ERROR_DATAFILE_OPEN_FAILURE  9653L

// DNS                                   0x000025b6





// Failed to write datafile for DNS zone.

DNS_ERROR_FILE_WRITEBACK_FAILED  9654L

// DNS                                   0x000025b7





// Failure while reading datafile for DNS zone.

DNS_ERROR_DATAFILE_PARSING       9655L



// Database errors


DNS_ERROR_DATABASE_BASE 9700

// DNS_ERROR_RECORD_DOES_NOT_EXIST       0x000025e5





// DNS record does not exist.

DNS_ERROR_RECORD_DOES_NOT_EXIST  9701L

// DNS_ERROR_RECORD_FORMAT               0x000025e6





// DNS record format error.

DNS_ERROR_RECORD_FORMAT          9702L

// DNS_ERROR_NODE_CREATION_FAILED        0x000025e7





// Node creation failure in DNS.

DNS_ERROR_NODE_CREATION_FAILED   9703L

// DNS_ERROR_UNKNOWN_RECORD_TYPE         0x000025e8





// Unknown DNS record type.

DNS_ERROR_UNKNOWN_RECORD_TYPE    9704L

// DNS_ERROR_RECORD_TIMED_OUT            0x000025e9





// DNS record timed out.

DNS_ERROR_RECORD_TIMED_OUT       9705L

// DNS_ERROR_NAME_NOT_IN_ZONE            0x000025ea





// Name not in DNS zone.

DNS_ERROR_NAME_NOT_IN_ZONE       9706L

// DNS_ERROR_CNAME_LOOP                  0x000025eb





// CNAME loop detected.

DNS_ERROR_CNAME_LOOP             9707L

// DNS_ERROR_NODE_IS_CNAME               0x000025ec





// Node is a CNAME DNS record.

DNS_ERROR_NODE_IS_CNAME          9708L

// DNS_ERROR_CNAME_COLLISION             0x000025ed





// A CNAME record already exists for given name.

DNS_ERROR_CNAME_COLLISION        9709L

// DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT    0x000025ee





// Record only at DNS zone root.

DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT 9710L

// DNS_ERROR_RECORD_ALREADY_EXISTS       0x000025ef





// DNS record already exists.

DNS_ERROR_RECORD_ALREADY_EXISTS  9711L

// DNS_ERROR_SECONDARY_DATA              0x000025f0





// Secondary DNS zone data error.

DNS_ERROR_SECONDARY_DATA         9712L

// DNS_ERROR_NO_CREATE_CACHE_DATA        0x000025f1





// Could not create DNS cache data.

DNS_ERROR_NO_CREATE_CACHE_DATA   9713L

// DNS_ERROR_NAME_DOES_NOT_EXIST         0x000025f2





// DNS name does not exist.

DNS_ERROR_NAME_DOES_NOT_EXIST    9714L

// DNS_WARNING_PTR_CREATE_FAILED         0x000025f3





// Could not create pointer (PTR) record.

DNS_WARNING_PTR_CREATE_FAILED    9715L

// DNS_WARNING_DOMAIN_UNDELETED          0x000025f4





// DNS domain was undeleted.

DNS_WARNING_DOMAIN_UNDELETED     9716L

// DNS_ERROR_DS_UNAVAILABLE              0x000025f5





// The directory service is unavailable.

DNS_ERROR_DS_UNAVAILABLE         9717L

// DNS_ERROR_DS_ZONE_ALREADY_EXISTS      0x000025f6





// DNS zone already exists in the directory service.

DNS_ERROR_DS_ZONE_ALREADY_EXISTS 9718L

// DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE      0x000025f7





// DNS server not creating or reading the boot file for the directory service integrated DNS zone.

DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE 9719L

// DNS_ERROR_NODE_IS_DNAME               0x000025f8





// Node is a DNAME DNS record.

DNS_ERROR_NODE_IS_DNAME          9720L

// DNS_ERROR_DNAME_COLLISION             0x000025f9





// A DNAME record already exists for given name.

DNS_ERROR_DNAME_COLLISION        9721L

// DNS_ERROR_ALIAS_LOOP                  0x000025fa





// An alias loop has been detected with either CNAME or DNAME records.

DNS_ERROR_ALIAS_LOOP             9722L



// Operation errors


DNS_ERROR_OPERATION_BASE 9750

// DNS_INFO_AXFR_COMPLETE                0x00002617





// DNS AXFR (zone transfer) complete.

DNS_INFO_AXFR_COMPLETE           9751L

// DNS_ERROR_AXFR                        0x00002618





// DNS zone transfer failed.

DNS_ERROR_AXFR                   9752L

// DNS_INFO_ADDED_LOCAL_WINS             0x00002619





// Added local WINS server.

DNS_INFO_ADDED_LOCAL_WINS        9753L



// Secure update


DNS_ERROR_SECURE_BASE 9800

// DNS_STATUS_CONTINUE_NEEDED            0x00002649





// Secure update call needs to continue update request.

DNS_STATUS_CONTINUE_NEEDED       9801L



// Setup errors


DNS_ERROR_SETUP_BASE 9850

// DNS_ERROR_NO_TCPIP                    0x0000267b





// TCP/IP network protocol not installed.

DNS_ERROR_NO_TCPIP               9851L

// DNS_ERROR_NO_DNS_SERVERS              0x0000267c





// No DNS servers configured for local system.

DNS_ERROR_NO_DNS_SERVERS         9852L



// Directory partition (DP) errors


DNS_ERROR_DP_BASE 9900

// DNS_ERROR_DP_DOES_NOT_EXIST           0x000026ad





// The specified directory partition does not exist.

DNS_ERROR_DP_DOES_NOT_EXIST      9901L

// DNS_ERROR_DP_ALREADY_EXISTS           0x000026ae





// The specified directory partition already exists.

DNS_ERROR_DP_ALREADY_EXISTS      9902L

// DNS_ERROR_DP_NOT_ENLISTED             0x000026af





// This DNS server is not enlisted in the specified directory partition.

DNS_ERROR_DP_NOT_ENLISTED        9903L

// DNS_ERROR_DP_ALREADY_ENLISTED         0x000026b0





// This DNS server is already enlisted in the specified directory partition.

DNS_ERROR_DP_ALREADY_ENLISTED    9904L

// DNS_ERROR_DP_NOT_AVAILABLE            0x000026b1





// The directory partition is not available at this time. Please wait a few minutes and try again.

DNS_ERROR_DP_NOT_AVAILABLE       9905L

// DNS_ERROR_DP_FSMO_ERROR               0x000026b2





// The operation failed because the domain naming master FSMO role could not be reached. The domain controller holding the domain naming master FSMO role is down or unable to service the request or is not running Windows Server 2003 or later.

DNS_ERROR_DP_FSMO_ERROR          9906L


// DNS RRL errors from 9911 to 9920

// DNS_ERROR_RRL_NOT_ENABLED 0x000026B7





// The RRL is not enabled.

DNS_ERROR_RRL_NOT_ENABLED        9911L

// DNS_ERROR_RRL_INVALID_WINDOW_SIZE 0x000026B8





// The window size parameter is invalid. It should be greater than or equal to 1.

DNS_ERROR_RRL_INVALID_WINDOW_SIZE 9912L

// DNS_ERROR_RRL_INVALID_IPV4_PREFIX 0x000026B9





// The IPv4 prefix length parameter is invalid. It should be less than or equal to 32.

DNS_ERROR_RRL_INVALID_IPV4_PREFIX 9913L

// DNS_ERROR_RRL_INVALID_IPV6_PREFIX 0x000026BA





// The IPv6 prefix length parameter is invalid. It should be less than or equal to 128.

DNS_ERROR_RRL_INVALID_IPV6_PREFIX 9914L

// DNS_ERROR_RRL_INVALID_TC_RATE 0x000026BB





// The TC Rate parameter is invalid. It should be less than 10.

DNS_ERROR_RRL_INVALID_TC_RATE    9915L

// DNS_ERROR_RRL_INVALID_LEAK_RATE 0x000026BC





// The Leak Rate parameter is invalid. It should be either 0, or between 2 and 10.

DNS_ERROR_RRL_INVALID_LEAK_RATE  9916L

// DNS_ERROR_RRL_LEAK_RATE_LESSTHAN_TC_RATE 0x000026BD





// The Leak Rate or TC Rate parameter is invalid. Leak Rate should be greater than TC Rate.

DNS_ERROR_RRL_LEAK_RATE_LESSTHAN_TC_RATE 9917L



// DNS Virtualization errors from 9921 to 9950

// DNS_ERROR_VIRTUALIZATION_INSTANCE_ALREADY_EXISTS    0x000026c1





// The virtualization instance already exists.

DNS_ERROR_VIRTUALIZATION_INSTANCE_ALREADY_EXISTS 9921L

// DNS_ERROR_VIRTUALIZATION_INSTANCE_DOES_NOT_EXIST    0x000026c2





// The virtualization instance does not exist.

DNS_ERROR_VIRTUALIZATION_INSTANCE_DOES_NOT_EXIST 9922L

// DNS_ERROR_VIRTUALIZATION_TREE_LOCKED        0x000026c3





// The virtualization tree is locked.

DNS_ERROR_VIRTUALIZATION_TREE_LOCKED 9923L

// DNS_ERROR_INVAILD_VIRTUALIZATION_INSTANCE_NAME      0x000026c4





// Invalid virtualization instance name.

DNS_ERROR_INVAILD_VIRTUALIZATION_INSTANCE_NAME 9924L

// DNS_ERROR_DEFAULT_VIRTUALIZATION_INSTANCE   0x000026c5





// The default virtualization instance cannot be added, removed or modified.

DNS_ERROR_DEFAULT_VIRTUALIZATION_INSTANCE 9925L



// DNS ZoneScope errors from 9951 to 9970

// DNS_ERROR_ZONESCOPE_ALREADY_EXISTS               0x000026df





// The scope already exists for the zone.

DNS_ERROR_ZONESCOPE_ALREADY_EXISTS 9951L

// DNS_ERROR_ZONESCOPE_DOES_NOT_EXIST       0x000026e0





// The scope does not exist for the zone.

DNS_ERROR_ZONESCOPE_DOES_NOT_EXIST 9952L

// DNS_ERROR_DEFAULT_ZONESCOPE 0x000026e1





// The scope is the same as the default zone scope.

DNS_ERROR_DEFAULT_ZONESCOPE      9953L

// DNS_ERROR_INVALID_ZONESCOPE_NAME 0x000026e2





// The scope name contains invalid characters.

DNS_ERROR_INVALID_ZONESCOPE_NAME 9954L

// DNS_ERROR_NOT_ALLOWED_WITH_ZONESCOPES 0x000026e3





// Operation not allowed when the zone has scopes.

DNS_ERROR_NOT_ALLOWED_WITH_ZONESCOPES 9955L

// DNS_ERROR_LOAD_ZONESCOPE_FAILED 0x000026e4





// Failed to load zone scope.

DNS_ERROR_LOAD_ZONESCOPE_FAILED  9956L

// DNS_ERROR_ZONESCOPE_FILE_WRITEBACK_FAILED 0x000026e5





// Failed to write data file for DNS zone scope. Please verify the file exists and is writable.

DNS_ERROR_ZONESCOPE_FILE_WRITEBACK_FAILED 9957L

// DNS_ERROR_INVALID_SCOPE_NAME 0x000026e6





// The scope name contains invalid characters.

DNS_ERROR_INVALID_SCOPE_NAME     9958L

// DNS_ERROR_SCOPE_DOES_NOT_EXIST       0x000026e7





// The scope does not exist.

DNS_ERROR_SCOPE_DOES_NOT_EXIST   9959L

// DNS_ERROR_DEFAULT_SCOPE 0x000026e8





// The scope is the same as the default scope.

DNS_ERROR_DEFAULT_SCOPE          9960L

// DNS_ERROR_INVALID_SCOPE_OPERATION 0x000026e9





// The operation is invalid on the scope.

DNS_ERROR_INVALID_SCOPE_OPERATION 9961L

// DNS_ERROR_SCOPE_LOCKED 0x000026ea





// The scope is locked.

DNS_ERROR_SCOPE_LOCKED           9962L

// DNS_ERROR_SCOPE_ALREADY_EXISTS 0x000026eb





// The scope already exists.

DNS_ERROR_SCOPE_ALREADY_EXISTS   9963L



// DNS Policy errors from 9971 to 9999

// DNS_ERROR_POLICY_ALREADY_EXISTS 0x000026f3





// A policy with the same name already exists on this level (server level or zone level) on the DNS server.

DNS_ERROR_POLICY_ALREADY_EXISTS  9971L

// DNS_ERROR_POLICY_DOES_NOT_EXIST 0x000026f4





// No policy with this name exists on this level (server level or zone level) on the DNS server.

DNS_ERROR_POLICY_DOES_NOT_EXIST  9972L

// DNS_ERROR_POLICY_INVALID_CRITERIA 0x000026f5





// The criteria provided in the policy are invalid.

DNS_ERROR_POLICY_INVALID_CRITERIA 9973L

// DNS_ERROR_POLICY_INVALID_SETTINGS 0x000026f6





// At least one of the settings of this policy is invalid.

DNS_ERROR_POLICY_INVALID_SETTINGS 9974L

// DNS_ERROR_CLIENT_SUBNET_IS_ACCESSED 0x000026f7





// The client subnet cannot be deleted while it is being accessed by a policy.

DNS_ERROR_CLIENT_SUBNET_IS_ACCESSED 9975L

// DNS_ERROR_CLIENT_SUBNET_DOES_NOT_EXIST 0x000026f8





// The client subnet does not exist on the DNS server.

DNS_ERROR_CLIENT_SUBNET_DOES_NOT_EXIST 9976L

// DNS_ERROR_CLIENT_SUBNET_ALREADY_EXISTS 0x000026f9





// A client subnet with this name already exists on the DNS server.

DNS_ERROR_CLIENT_SUBNET_ALREADY_EXISTS 9977L

// DNS_ERROR_SUBNET_DOES_NOT_EXIST 0x000026fa





// The IP subnet specified does not exist in the client subnet.

DNS_ERROR_SUBNET_DOES_NOT_EXIST  9978L

// DNS_ERROR_SUBNET_ALREADY_EXISTS 0x000026fb





// The IP subnet that is being added, already exists in the client subnet.

DNS_ERROR_SUBNET_ALREADY_EXISTS  9979L

// DNS_ERROR_POLICY_LOCKED 0x000026fc





// The policy is locked.

DNS_ERROR_POLICY_LOCKED          9980L

// DNS_ERROR_POLICY_INVALID_WEIGHT 0x000026fd





// The weight of the scope in the policy is invalid.

DNS_ERROR_POLICY_INVALID_WEIGHT  9981L

// DNS_ERROR_POLICY_INVALID_NAME 0x000026fe





// The DNS policy name is invalid.

DNS_ERROR_POLICY_INVALID_NAME    9982L

// DNS_ERROR_POLICY_MISSING_CRITERIA 0x000026ff





// The policy is missing criteria.

DNS_ERROR_POLICY_MISSING_CRITERIA 9983L

// DNS_ERROR_INVALID_CLIENT_SUBNET_NAME 0x00002700





// The name of the the client subnet record is invalid.

DNS_ERROR_INVALID_CLIENT_SUBNET_NAME 9984L

// DNS_ERROR_POLICY_PROCESSING_ORDER_INVALID 0x00002701





// Invalid policy processing order.

DNS_ERROR_POLICY_PROCESSING_ORDER_INVALID 9985L

// DNS_ERROR_POLICY_SCOPE_MISSING 0x00002702





// The scope information has not been provided for a policy that requires it.

DNS_ERROR_POLICY_SCOPE_MISSING   9986L

// DNS_ERROR_POLICY_SCOPE_NOT_ALLOWED 0x00002703





// The scope information has been provided for a policy that does not require it.

DNS_ERROR_POLICY_SCOPE_NOT_ALLOWED 9987L

// DNS_ERROR_SERVERSCOPE_IS_REFERENCED 0x00002704





// The server scope cannot be deleted because it is referenced by a DNS Policy.

DNS_ERROR_SERVERSCOPE_IS_REFERENCED 9988L

// DNS_ERROR_ZONESCOPE_IS_REFERENCED 0x00002705





// The zone scope cannot be deleted because it is referenced by a DNS Policy.

DNS_ERROR_ZONESCOPE_IS_REFERENCED 9989L

// DNS_ERROR_POLICY_INVALID_CRITERIA_CLIENT_SUBNET 0x00002706





// The criterion client subnet provided in the policy is invalid.

DNS_ERROR_POLICY_INVALID_CRITERIA_CLIENT_SUBNET 9990L

// DNS_ERROR_POLICY_INVALID_CRITERIA_TRANSPORT_PROTOCOL 0x00002707





// The criterion transport protocol provided in the policy is invalid.

DNS_ERROR_POLICY_INVALID_CRITERIA_TRANSPORT_PROTOCOL 9991L

// DNS_ERROR_POLICY_INVALID_CRITERIA_NETWORK_PROTOCOL 0x00002708





// The criterion network protocol provided in the policy is invalid.

DNS_ERROR_POLICY_INVALID_CRITERIA_NETWORK_PROTOCOL 9992L

// DNS_ERROR_POLICY_INVALID_CRITERIA_INTERFACE 0x00002709





// The criterion interface provided in the policy is invalid.

DNS_ERROR_POLICY_INVALID_CRITERIA_INTERFACE 9993L

// DNS_ERROR_POLICY_INVALID_CRITERIA_FQDN 0x0000270A





// The criterion FQDN provided in the policy is invalid.

DNS_ERROR_POLICY_INVALID_CRITERIA_FQDN 9994L

// DNS_ERROR_POLICY_INVALID_CRITERIA_QUERY_TYPE 0x0000270B





// The criterion query type provided in the policy is invalid.

DNS_ERROR_POLICY_INVALID_CRITERIA_QUERY_TYPE 9995L

// DNS_ERROR_POLICY_INVALID_CRITERIA_TIME_OF_DAY 0x0000270C





// The criterion time of day provided in the policy is invalid.

DNS_ERROR_POLICY_INVALID_CRITERIA_TIME_OF_DAY 9996L




///////////////////////////////////////////////////
//                                               //
//             End of DNS Error Codes            //
//                                               //
//                  9000 to 9999                 //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//               WinSock Error Codes             //
//                                               //
//                 10000 to 11999                //
///////////////////////////////////////////////////


// WinSock error codes are also defined in WinSock.h
// and WinSock2.h, hence the IFDEF

#ifndef WSABASEERR
WSABASEERR 10000





// A blocking operation was interrupted by a call to WSACancelBlockingCall.

WSAEINTR                         10004L






// The file handle supplied is not valid.

WSAEBADF                         10009L






// An attempt was made to access a socket in a way forbidden by its access permissions.

WSAEACCES                        10013L






// The system detected an invalid pointer address in attempting to use a pointer argument in a call.

WSAEFAULT                        10014L






// An invalid argument was supplied.

WSAEINVAL                        10022L






// Too many open sockets.

WSAEMFILE                        10024L






// A non-blocking socket operation could not be completed immediately.

WSAEWOULDBLOCK                   10035L






// A blocking operation is currently executing.

WSAEINPROGRESS                   10036L






// An operation was attempted on a non-blocking socket that already had an operation in progress.

WSAEALREADY                      10037L






// An operation was attempted on something that is not a socket.

WSAENOTSOCK                      10038L






// A required address was omitted from an operation on a socket.

WSAEDESTADDRREQ                  10039L






// A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram into was smaller than the datagram itself.

WSAEMSGSIZE                      10040L






// A protocol was specified in the socket function call that does not support the semantics of the socket type requested.

WSAEPROTOTYPE                    10041L






// An unknown, invalid, or unsupported option or level was specified in a getsockopt or setsockopt call.

WSAENOPROTOOPT                   10042L






// The requested protocol has not been configured into the system, or no implementation for it exists.

WSAEPROTONOSUPPORT               10043L






// The support for the specified socket type does not exist in this address family.

WSAESOCKTNOSUPPORT               10044L






// The attempted operation is not supported for the type of object referenced.

WSAEOPNOTSUPP                    10045L






// The protocol family has not been configured into the system or no implementation for it exists.

WSAEPFNOSUPPORT                  10046L






// An address incompatible with the requested protocol was used.

WSAEAFNOSUPPORT                  10047L






// Only one usage of each socket address (protocol/network address/port) is normally permitted.

WSAEADDRINUSE                    10048L






// The requested address is not valid in its context.

WSAEADDRNOTAVAIL                 10049L






// A socket operation encountered a dead network.

WSAENETDOWN                      10050L






// A socket operation was attempted to an unreachable network.

WSAENETUNREACH                   10051L






// The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress.

WSAENETRESET                     10052L






// An established connection was aborted by the software in your host machine.

WSAECONNABORTED                  10053L






// An existing connection was forcibly closed by the remote host.

WSAECONNRESET                    10054L






// An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.

WSAENOBUFS                       10055L






// A connect request was made on an already connected socket.

WSAEISCONN                       10056L






// A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using a sendto call) no address was supplied.

WSAENOTCONN                      10057L






// A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call.

WSAESHUTDOWN                     10058L






// Too many references to some kernel object.

WSAETOOMANYREFS                  10059L






// A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.

WSAETIMEDOUT                     10060L






// No connection could be made because the target machine actively refused it.

WSAECONNREFUSED                  10061L






// Cannot translate name.

WSAELOOP                         10062L






// Name component or name was too long.

WSAENAMETOOLONG                  10063L






// A socket operation failed because the destination host was down.

WSAEHOSTDOWN                     10064L






// A socket operation was attempted to an unreachable host.

WSAEHOSTUNREACH                  10065L






// Cannot remove a directory that is not empty.

WSAENOTEMPTY                     10066L






// A Windows Sockets implementation may have a limit on the number of applications that may use it simultaneously.

WSAEPROCLIM                      10067L






// Ran out of quota.

WSAEUSERS                        10068L






// Ran out of disk quota.

WSAEDQUOT                        10069L






// File handle reference is no longer available.

WSAESTALE                        10070L






// Item is not available locally.

WSAEREMOTE                       10071L






// WSAStartup cannot function at this time because the underlying system it uses to provide network services is currently unavailable.

WSASYSNOTREADY                   10091L






// The Windows Sockets version requested is not supported.

WSAVERNOTSUPPORTED               10092L






// Either the application has not called WSAStartup, or WSAStartup failed.

WSANOTINITIALISED                10093L






// Returned by WSARecv or WSARecvFrom to indicate the remote party has initiated a graceful shutdown sequence.

WSAEDISCON                       10101L






// No more results can be returned by WSALookupServiceNext.

WSAENOMORE                       10102L






// A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.

WSAECANCELLED                    10103L






// The procedure call table is invalid.

WSAEINVALIDPROCTABLE             10104L






// The requested service provider is invalid.

WSAEINVALIDPROVIDER              10105L






// The requested service provider could not be loaded or initialized.

WSAEPROVIDERFAILEDINIT           10106L






// A system call has failed.

WSASYSCALLFAILURE                10107L






// No such service is known. The service cannot be found in the specified name space.

WSASERVICE_NOT_FOUND             10108L






// The specified class was not found.

WSATYPE_NOT_FOUND                10109L






// No more results can be returned by WSALookupServiceNext.

WSA_E_NO_MORE                    10110L






// A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.

WSA_E_CANCELLED                  10111L






// A database query failed because it was actively refused.

WSAEREFUSED                      10112L






// No such host is known.

WSAHOST_NOT_FOUND                11001L






// This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server.

WSATRY_AGAIN                     11002L






// A non-recoverable error occurred during a database lookup.

WSANO_RECOVERY                   11003L






// The requested name is valid, but no data of the requested type was found.

WSANO_DATA                       11004L






// At least one reserve has arrived.

WSA_QOS_RECEIVERS                11005L






// At least one path has arrived.

WSA_QOS_SENDERS                  11006L






// There are no senders.

WSA_QOS_NO_SENDERS               11007L






// There are no receivers.

WSA_QOS_NO_RECEIVERS             11008L






// Reserve has been confirmed.

WSA_QOS_REQUEST_CONFIRMED        11009L






// Error due to lack of resources.

WSA_QOS_ADMISSION_FAILURE        11010L






// Rejected for administrative reasons - bad credentials.

WSA_QOS_POLICY_FAILURE           11011L






// Unknown or conflicting style.

WSA_QOS_BAD_STYLE                11012L






// Problem with some part of the filterspec or providerspecific buffer in general.

WSA_QOS_BAD_OBJECT               11013L






// Problem with some part of the flowspec.

WSA_QOS_TRAFFIC_CTRL_ERROR       11014L






// General QOS error.

WSA_QOS_GENERIC_ERROR            11015L






// An invalid or unrecognized service type was found in the flowspec.

WSA_QOS_ESERVICETYPE             11016L






// An invalid or inconsistent flowspec was found in the QOS structure.

WSA_QOS_EFLOWSPEC                11017L






// Invalid QOS provider-specific buffer.

WSA_QOS_EPROVSPECBUF             11018L






// An invalid QOS filter style was used.

WSA_QOS_EFILTERSTYLE             11019L






// An invalid QOS filter type was used.

WSA_QOS_EFILTERTYPE              11020L






// An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.

WSA_QOS_EFILTERCOUNT             11021L






// An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.

WSA_QOS_EOBJLENGTH               11022L






// An incorrect number of flow descriptors was specified in the QOS structure.

WSA_QOS_EFLOWCOUNT               11023L






// An unrecognized object was found in the QOS provider-specific buffer.

WSA_QOS_EUNKOWNPSOBJ             11024L






// An invalid policy object was found in the QOS provider-specific buffer.

WSA_QOS_EPOLICYOBJ               11025L






// An invalid QOS flow descriptor was found in the flow descriptor list.

WSA_QOS_EFLOWDESC                11026L






// An invalid or inconsistent flowspec was found in the QOS provider specific buffer.

WSA_QOS_EPSFLOWSPEC              11027L






// An invalid FILTERSPEC was found in the QOS provider-specific buffer.

WSA_QOS_EPSFILTERSPEC            11028L






// An invalid shape discard mode object was found in the QOS provider specific buffer.

WSA_QOS_ESDMODEOBJ               11029L






// An invalid shaping rate object was found in the QOS provider-specific buffer.

WSA_QOS_ESHAPERATEOBJ            11030L






// A reserved policy element was found in the QOS provider-specific buffer.

WSA_QOS_RESERVED_PETYPE          11031L






// No such host is known securely.

WSA_SECURE_HOST_NOT_FOUND        11032L






// Name based IPSEC policy could not be added.

WSA_IPSEC_NAME_POLICY_ERROR      11033L

#endif // defined(WSABASEERR)

///////////////////////////////////////////////////
//                                               //
//           End of WinSock Error Codes          //
//                                               //
//                 10000 to 11999                //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//                  Available                    //
//                                               //
//                 12000 to 12999                //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//           Start of IPSec Error codes          //
//                                               //
//                 13000 to 13999                //
///////////////////////////////////////////////////






// The specified quick mode policy already exists.

ERROR_IPSEC_QM_POLICY_EXISTS     13000L






// The specified quick mode policy was not found.

ERROR_IPSEC_QM_POLICY_NOT_FOUND  13001L






// The specified quick mode policy is being used.

ERROR_IPSEC_QM_POLICY_IN_USE     13002L






// The specified main mode policy already exists.

ERROR_IPSEC_MM_POLICY_EXISTS     13003L






// The specified main mode policy was not found

ERROR_IPSEC_MM_POLICY_NOT_FOUND  13004L






// The specified main mode policy is being used.

ERROR_IPSEC_MM_POLICY_IN_USE     13005L






// The specified main mode filter already exists.

ERROR_IPSEC_MM_FILTER_EXISTS     13006L






// The specified main mode filter was not found.

ERROR_IPSEC_MM_FILTER_NOT_FOUND  13007L






// The specified transport mode filter already exists.

ERROR_IPSEC_TRANSPORT_FILTER_EXISTS 13008L






// The specified transport mode filter does not exist.

ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND 13009L






// The specified main mode authentication list exists.

ERROR_IPSEC_MM_AUTH_EXISTS       13010L






// The specified main mode authentication list was not found.

ERROR_IPSEC_MM_AUTH_NOT_FOUND    13011L






// The specified main mode authentication list is being used.

ERROR_IPSEC_MM_AUTH_IN_USE       13012L






// The specified default main mode policy was not found.

ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND 13013L






// The specified default main mode authentication list was not found.

ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND 13014L






// The specified default quick mode policy was not found.

ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND 13015L






// The specified tunnel mode filter exists.

ERROR_IPSEC_TUNNEL_FILTER_EXISTS 13016L






// The specified tunnel mode filter was not found.

ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND 13017L






// The Main Mode filter is pending deletion.

ERROR_IPSEC_MM_FILTER_PENDING_DELETION 13018L






// The transport filter is pending deletion.

ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION 13019L






// The tunnel filter is pending deletion.

ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION 13020L






// The Main Mode policy is pending deletion.

ERROR_IPSEC_MM_POLICY_PENDING_DELETION 13021L






// The Main Mode authentication bundle is pending deletion.

ERROR_IPSEC_MM_AUTH_PENDING_DELETION 13022L






// The Quick Mode policy is pending deletion.

ERROR_IPSEC_QM_POLICY_PENDING_DELETION 13023L






// The Main Mode policy was successfully added, but some of the requested offers are not supported.

WARNING_IPSEC_MM_POLICY_PRUNED   13024L






// The Quick Mode policy was successfully added, but some of the requested offers are not supported.

WARNING_IPSEC_QM_POLICY_PRUNED   13025L






//  ERROR_IPSEC_IKE_NEG_STATUS_BEGIN

ERROR_IPSEC_IKE_NEG_STATUS_BEGIN 13800L






// IKE authentication credentials are unacceptable

ERROR_IPSEC_IKE_AUTH_FAIL        13801L






// IKE security attributes are unacceptable

ERROR_IPSEC_IKE_ATTRIB_FAIL      13802L






// IKE Negotiation in progress

ERROR_IPSEC_IKE_NEGOTIATION_PENDING 13803L






// General processing error

ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR 13804L






// Negotiation timed out

ERROR_IPSEC_IKE_TIMED_OUT        13805L






// IKE failed to find valid machine certificate. Contact your Network Security Administrator about installing a valid certificate in the appropriate Certificate Store.

ERROR_IPSEC_IKE_NO_CERT          13806L






// IKE SA deleted by peer before establishment completed

ERROR_IPSEC_IKE_SA_DELETED       13807L






// IKE SA deleted before establishment completed

ERROR_IPSEC_IKE_SA_REAPED        13808L






// Negotiation request sat in Queue too long

ERROR_IPSEC_IKE_MM_ACQUIRE_DROP  13809L






// Negotiation request sat in Queue too long

ERROR_IPSEC_IKE_QM_ACQUIRE_DROP  13810L






// Negotiation request sat in Queue too long

ERROR_IPSEC_IKE_QUEUE_DROP_MM    13811L






// Negotiation request sat in Queue too long

ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM 13812L






// No response from peer

ERROR_IPSEC_IKE_DROP_NO_RESPONSE 13813L






// Negotiation took too long

ERROR_IPSEC_IKE_MM_DELAY_DROP    13814L






// Negotiation took too long

ERROR_IPSEC_IKE_QM_DELAY_DROP    13815L






// Unknown error occurred

ERROR_IPSEC_IKE_ERROR            13816L






// Certificate Revocation Check failed

ERROR_IPSEC_IKE_CRL_FAILED       13817L






// Invalid certificate key usage

ERROR_IPSEC_IKE_INVALID_KEY_USAGE 13818L






// Invalid certificate type

ERROR_IPSEC_IKE_INVALID_CERT_TYPE 13819L






// IKE negotiation failed because the machine certificate used does not have a private key. IPsec certificates require a private key. Contact your Network Security administrator about replacing with a certificate that has a private key.

ERROR_IPSEC_IKE_NO_PRIVATE_KEY   13820L






// Simultaneous rekeys were detected.

ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY 13821L






// Failure in Diffie-Hellman computation

ERROR_IPSEC_IKE_DH_FAIL          13822L






// Don't know how to process critical payload

ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED 13823L






// Invalid header

ERROR_IPSEC_IKE_INVALID_HEADER   13824L






// No policy configured

ERROR_IPSEC_IKE_NO_POLICY        13825L






// Failed to verify signature

ERROR_IPSEC_IKE_INVALID_SIGNATURE 13826L






// Failed to authenticate using Kerberos

ERROR_IPSEC_IKE_KERBEROS_ERROR   13827L






// Peer's certificate did not have a public key

ERROR_IPSEC_IKE_NO_PUBLIC_KEY    13828L

// These must stay as a unit.





// Error processing error payload

ERROR_IPSEC_IKE_PROCESS_ERR      13829L






// Error processing SA payload

ERROR_IPSEC_IKE_PROCESS_ERR_SA   13830L






// Error processing Proposal payload

ERROR_IPSEC_IKE_PROCESS_ERR_PROP 13831L






// Error processing Transform payload

ERROR_IPSEC_IKE_PROCESS_ERR_TRANS 13832L






// Error processing KE payload

ERROR_IPSEC_IKE_PROCESS_ERR_KE   13833L






// Error processing ID payload

ERROR_IPSEC_IKE_PROCESS_ERR_ID   13834L






// Error processing Cert payload

ERROR_IPSEC_IKE_PROCESS_ERR_CERT 13835L






// Error processing Certificate Request payload

ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ 13836L






// Error processing Hash payload

ERROR_IPSEC_IKE_PROCESS_ERR_HASH 13837L






// Error processing Signature payload

ERROR_IPSEC_IKE_PROCESS_ERR_SIG  13838L






// Error processing Nonce payload

ERROR_IPSEC_IKE_PROCESS_ERR_NONCE 13839L






// Error processing Notify payload

ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY 13840L






// Error processing Delete Payload

ERROR_IPSEC_IKE_PROCESS_ERR_DELETE 13841L






// Error processing VendorId payload

ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR 13842L






// Invalid payload received

ERROR_IPSEC_IKE_INVALID_PAYLOAD  13843L






// Soft SA loaded

ERROR_IPSEC_IKE_LOAD_SOFT_SA     13844L






// Soft SA torn down

ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN 13845L






// Invalid cookie received.

ERROR_IPSEC_IKE_INVALID_COOKIE   13846L






// Peer failed to send valid machine certificate

ERROR_IPSEC_IKE_NO_PEER_CERT     13847L






// Certification Revocation check of peer's certificate failed

ERROR_IPSEC_IKE_PEER_CRL_FAILED  13848L






// New policy invalidated SAs formed with old policy

ERROR_IPSEC_IKE_POLICY_CHANGE    13849L






// There is no available Main Mode IKE policy.

ERROR_IPSEC_IKE_NO_MM_POLICY     13850L






// Failed to enabled TCB privilege.

ERROR_IPSEC_IKE_NOTCBPRIV        13851L






// Failed to load SECURITY.DLL.

ERROR_IPSEC_IKE_SECLOADFAIL      13852L






// Failed to obtain security function table dispatch address from SSPI.

ERROR_IPSEC_IKE_FAILSSPINIT      13853L






// Failed to query Kerberos package to obtain max token size.

ERROR_IPSEC_IKE_FAILQUERYSSP     13854L






// Failed to obtain Kerberos server credentials for ISAKMP/ERROR_IPSEC_IKE service. Kerberos authentication will not function. The most likely reason for this is lack of domain membership. This is normal if your computer is a member of a workgroup.

ERROR_IPSEC_IKE_SRVACQFAIL       13855L






// Failed to determine SSPI principal name for ISAKMP/ERROR_IPSEC_IKE service (QueryCredentialsAttributes).

ERROR_IPSEC_IKE_SRVQUERYCRED     13856L






// Failed to obtain new SPI for the inbound SA from IPsec driver. The most common cause for this is that the driver does not have the correct filter. Check your policy to verify the filters.

ERROR_IPSEC_IKE_GETSPIFAIL       13857L






// Given filter is invalid

ERROR_IPSEC_IKE_INVALID_FILTER   13858L






// Memory allocation failed.

ERROR_IPSEC_IKE_OUT_OF_MEMORY    13859L






// Failed to add Security Association to IPsec Driver. The most common cause for this is if the IKE negotiation took too long to complete. If the problem persists, reduce the load on the faulting machine.

ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED 13860L






// Invalid policy

ERROR_IPSEC_IKE_INVALID_POLICY   13861L






// Invalid DOI

ERROR_IPSEC_IKE_UNKNOWN_DOI      13862L






// Invalid situation

ERROR_IPSEC_IKE_INVALID_SITUATION 13863L






// Diffie-Hellman failure

ERROR_IPSEC_IKE_DH_FAILURE       13864L






// Invalid Diffie-Hellman group

ERROR_IPSEC_IKE_INVALID_GROUP    13865L






// Error encrypting payload

ERROR_IPSEC_IKE_ENCRYPT          13866L






// Error decrypting payload

ERROR_IPSEC_IKE_DECRYPT          13867L






// Policy match error

ERROR_IPSEC_IKE_POLICY_MATCH     13868L






// Unsupported ID

ERROR_IPSEC_IKE_UNSUPPORTED_ID   13869L






// Hash verification failed

ERROR_IPSEC_IKE_INVALID_HASH     13870L






// Invalid hash algorithm

ERROR_IPSEC_IKE_INVALID_HASH_ALG 13871L






// Invalid hash size

ERROR_IPSEC_IKE_INVALID_HASH_SIZE 13872L






// Invalid encryption algorithm

ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG 13873L






// Invalid authentication algorithm

ERROR_IPSEC_IKE_INVALID_AUTH_ALG 13874L






// Invalid certificate signature

ERROR_IPSEC_IKE_INVALID_SIG      13875L






// Load failed

ERROR_IPSEC_IKE_LOAD_FAILED      13876L






// Deleted via RPC call

ERROR_IPSEC_IKE_RPC_DELETE       13877L






// Temporary state created to perform reinitialization. This is not a real failure.

ERROR_IPSEC_IKE_BENIGN_REINIT    13878L






// The lifetime value received in the Responder Lifetime Notify is below the Windows 2000 configured minimum value. Please fix the policy on the peer machine.

ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY 13879L






// The recipient cannot handle version of IKE specified in the header.

ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION 13880L






// Key length in certificate is too small for configured security requirements.

ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN 13881L






// Max number of established MM SAs to peer exceeded.

ERROR_IPSEC_IKE_MM_LIMIT         13882L






// IKE received a policy that disables negotiation.

ERROR_IPSEC_IKE_NEGOTIATION_DISABLED 13883L






// Reached maximum quick mode limit for the main mode. New main mode will be started.

ERROR_IPSEC_IKE_QM_LIMIT         13884L






// Main mode SA lifetime expired or peer sent a main mode delete.

ERROR_IPSEC_IKE_MM_EXPIRED       13885L






// Main mode SA assumed to be invalid because peer stopped responding.

ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID 13886L






// Certificate doesn't chain to a trusted root in IPsec policy.

ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH 13887L






// Received unexpected message ID.

ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID 13888L






// Received invalid authentication offers.

ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD 13889L






// Sent DoS cookie notify to initiator.

ERROR_IPSEC_IKE_DOS_COOKIE_SENT  13890L






// IKE service is shutting down.

ERROR_IPSEC_IKE_SHUTTING_DOWN    13891L






// Could not verify binding between CGA address and certificate.

ERROR_IPSEC_IKE_CGA_AUTH_FAILED  13892L






// Error processing NatOA payload.

ERROR_IPSEC_IKE_PROCESS_ERR_NATOA 13893L






// Parameters of the main mode are invalid for this quick mode.

ERROR_IPSEC_IKE_INVALID_MM_FOR_QM 13894L






// Quick mode SA was expired by IPsec driver.

ERROR_IPSEC_IKE_QM_EXPIRED       13895L






// Too many dynamically added IKEEXT filters were detected.

ERROR_IPSEC_IKE_TOO_MANY_FILTERS 13896L

// Do NOT change this final value.  It is used in a public API structure





//  ERROR_IPSEC_IKE_NEG_STATUS_END

ERROR_IPSEC_IKE_NEG_STATUS_END   13897L






// NAP reauth succeeded and must delete the dummy NAP IKEv2 tunnel.

ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL 13898L






// Error in assigning inner IP address to initiator in tunnel mode.

ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE 13899L






// Require configuration payload missing.

ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING 13900L






// A negotiation running as the security principle who issued the connection is in progress

ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING 13901L






// SA was deleted due to IKEv1/AuthIP co-existence suppress check.

ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS 13902L






// Incoming SA request was dropped due to peer IP address rate limiting.

ERROR_IPSEC_IKE_RATELIMIT_DROP   13903L






// Peer does not support MOBIKE.

ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE 13904L






// SA establishment is not authorized.

ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE 13905L






// SA establishment is not authorized because there is not a sufficiently strong PKINIT-based credential.

ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE 13906L






// SA establishment is not authorized.  You may need to enter updated or different credentials such as a smartcard.

ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY 13907L






// SA establishment is not authorized because there is not a sufficiently strong PKINIT-based credential. This might be related to certificate-to-account mapping failure for the SA.

ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE 13908L

// Extended upper bound for IKE errors to accommodate new errors





//  ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END

ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END 13909L


// Following error codes are returned by IPsec kernel.






// The SPI in the packet does not match a valid IPsec SA.

ERROR_IPSEC_BAD_SPI              13910L






// Packet was received on an IPsec SA whose lifetime has expired.

ERROR_IPSEC_SA_LIFETIME_EXPIRED  13911L






// Packet was received on an IPsec SA that does not match the packet characteristics.

ERROR_IPSEC_WRONG_SA             13912L






// Packet sequence number replay check failed.

ERROR_IPSEC_REPLAY_CHECK_FAILED  13913L






// IPsec header and/or trailer in the packet is invalid.

ERROR_IPSEC_INVALID_PACKET       13914L






// IPsec integrity check failed.

ERROR_IPSEC_INTEGRITY_CHECK_FAILED 13915L






// IPsec dropped a clear text packet.

ERROR_IPSEC_CLEAR_TEXT_DROP      13916L






// IPsec dropped an incoming ESP packet in authenticated firewall mode. This drop is benign.

ERROR_IPSEC_AUTH_FIREWALL_DROP   13917L






// IPsec dropped a packet due to DoS throttling.

ERROR_IPSEC_THROTTLE_DROP        13918L






// IPsec DoS Protection matched an explicit block rule.

ERROR_IPSEC_DOSP_BLOCK           13925L






// IPsec DoS Protection received an IPsec specific multicast packet which is not allowed.

ERROR_IPSEC_DOSP_RECEIVED_MULTICAST 13926L






// IPsec DoS Protection received an incorrectly formatted packet.

ERROR_IPSEC_DOSP_INVALID_PACKET  13927L






// IPsec DoS Protection failed to look up state.

ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED 13928L






// IPsec DoS Protection failed to create state because the maximum number of entries allowed by policy has been reached.

ERROR_IPSEC_DOSP_MAX_ENTRIES     13929L






// IPsec DoS Protection received an IPsec negotiation packet for a keying module which is not allowed by policy.

ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED 13930L






// IPsec DoS Protection has not been enabled.

ERROR_IPSEC_DOSP_NOT_INSTALLED   13931L






// IPsec DoS Protection failed to create a per internal IP rate limit queue because the maximum number of queues allowed by policy has been reached.

ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES 13932L


///////////////////////////////////////////////////
//                                               //
//           End of IPSec Error codes            //
//                                               //
//                 13000 to 13999                //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//         Start of Side By Side Error Codes     //
//                                               //
//                 14000 to 14999                //
///////////////////////////////////////////////////






// The requested section was not present in the activation context.

ERROR_SXS_SECTION_NOT_FOUND      14000L






// The application has failed to start because its side-by-side configuration is incorrect. Please see the application event log or use the command-line sxstrace.exe tool for more detail.

ERROR_SXS_CANT_GEN_ACTCTX        14001L






// The application binding data format is invalid.

ERROR_SXS_INVALID_ACTCTXDATA_FORMAT 14002L






// The referenced assembly is not installed on your system.

ERROR_SXS_ASSEMBLY_NOT_FOUND     14003L






// The manifest file does not begin with the required tag and format information.

ERROR_SXS_MANIFEST_FORMAT_ERROR  14004L






// The manifest file contains one or more syntax errors.

ERROR_SXS_MANIFEST_PARSE_ERROR   14005L






// The application attempted to activate a disabled activation context.

ERROR_SXS_ACTIVATION_CONTEXT_DISABLED 14006L






// The requested lookup key was not found in any active activation context.

ERROR_SXS_KEY_NOT_FOUND          14007L






// A component version required by the application conflicts with another component version already active.

ERROR_SXS_VERSION_CONFLICT       14008L






// The type requested activation context section does not match the query API used.

ERROR_SXS_WRONG_SECTION_TYPE     14009L






// Lack of system resources has required isolated activation to be disabled for the current thread of execution.

ERROR_SXS_THREAD_QUERIES_DISABLED 14010L






// An attempt to set the process default activation context failed because the process default activation context was already set.

ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET 14011L






// The encoding group identifier specified is not recognized.

ERROR_SXS_UNKNOWN_ENCODING_GROUP 14012L






// The encoding requested is not recognized.

ERROR_SXS_UNKNOWN_ENCODING       14013L






// The manifest contains a reference to an invalid URI.

ERROR_SXS_INVALID_XML_NAMESPACE_URI 14014L






// The application manifest contains a reference to a dependent assembly which is not installed

ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED 14015L






// The manifest for an assembly used by the application has a reference to a dependent assembly which is not installed

ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED 14016L






// The manifest contains an attribute for the assembly identity which is not valid.

ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE 14017L






// The manifest is missing the required default namespace specification on the assembly element.

ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE 14018L






// The manifest has a default namespace specified on the assembly element but its value is not "urn:schemas-microsoft-com:asm.v1".

ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE 14019L






// The private manifest probed has crossed a path with an unsupported reparse point.

ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT 14020L






// Two or more components referenced directly or indirectly by the application manifest have files by the same name.

ERROR_SXS_DUPLICATE_DLL_NAME     14021L






// Two or more components referenced directly or indirectly by the application manifest have window classes with the same name.

ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME 14022L






// Two or more components referenced directly or indirectly by the application manifest have the same COM server CLSIDs.

ERROR_SXS_DUPLICATE_CLSID        14023L






// Two or more components referenced directly or indirectly by the application manifest have proxies for the same COM interface IIDs.

ERROR_SXS_DUPLICATE_IID          14024L






// Two or more components referenced directly or indirectly by the application manifest have the same COM type library TLBIDs.

ERROR_SXS_DUPLICATE_TLBID        14025L






// Two or more components referenced directly or indirectly by the application manifest have the same COM ProgIDs.

ERROR_SXS_DUPLICATE_PROGID       14026L






// Two or more components referenced directly or indirectly by the application manifest are different versions of the same component which is not permitted.

ERROR_SXS_DUPLICATE_ASSEMBLY_NAME 14027L






// A component's file does not match the verification information present in the component manifest.

ERROR_SXS_FILE_HASH_MISMATCH     14028L






// The policy manifest contains one or more syntax errors.

ERROR_SXS_POLICY_PARSE_ERROR     14029L






// Manifest Parse Error : A string literal was expected, but no opening quote character was found.

ERROR_SXS_XML_E_MISSINGQUOTE     14030L






// Manifest Parse Error : Incorrect syntax was used in a comment.

ERROR_SXS_XML_E_COMMENTSYNTAX    14031L






// Manifest Parse Error : A name was started with an invalid character.

ERROR_SXS_XML_E_BADSTARTNAMECHAR 14032L






// Manifest Parse Error : A name contained an invalid character.

ERROR_SXS_XML_E_BADNAMECHAR      14033L






// Manifest Parse Error : A string literal contained an invalid character.

ERROR_SXS_XML_E_BADCHARINSTRING  14034L






// Manifest Parse Error : Invalid syntax for an xml declaration.

ERROR_SXS_XML_E_XMLDECLSYNTAX    14035L






// Manifest Parse Error : An Invalid character was found in text content.

ERROR_SXS_XML_E_BADCHARDATA      14036L






// Manifest Parse Error : Required white space was missing.

ERROR_SXS_XML_E_MISSINGWHITESPACE 14037L






// Manifest Parse Error : The character '>' was expected.

ERROR_SXS_XML_E_EXPECTINGTAGEND  14038L






// Manifest Parse Error : A semi colon character was expected.

ERROR_SXS_XML_E_MISSINGSEMICOLON 14039L






// Manifest Parse Error : Unbalanced parentheses.

ERROR_SXS_XML_E_UNBALANCEDPAREN  14040L






// Manifest Parse Error : Internal error.

ERROR_SXS_XML_E_INTERNALERROR    14041L






// Manifest Parse Error : Whitespace is not allowed at this location.

ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE 14042L






// Manifest Parse Error : End of file reached in invalid state for current encoding.

ERROR_SXS_XML_E_INCOMPLETE_ENCODING 14043L






// Manifest Parse Error : Missing parenthesis.

ERROR_SXS_XML_E_MISSING_PAREN    14044L






// Manifest Parse Error : A single or double closing quote character (\' or \") is missing.

ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE 14045L






// Manifest Parse Error : Multiple colons are not allowed in a name.

ERROR_SXS_XML_E_MULTIPLE_COLONS  14046L






// Manifest Parse Error : Invalid character for decimal digit.

ERROR_SXS_XML_E_INVALID_DECIMAL  14047L






// Manifest Parse Error : Invalid character for hexadecimal digit.

ERROR_SXS_XML_E_INVALID_HEXIDECIMAL 14048L






// Manifest Parse Error : Invalid unicode character value for this platform.

ERROR_SXS_XML_E_INVALID_UNICODE  14049L






// Manifest Parse Error : Expecting whitespace or '?'.

ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK 14050L






// Manifest Parse Error : End tag was not expected at this location.

ERROR_SXS_XML_E_UNEXPECTEDENDTAG 14051L






// Manifest Parse Error : The following tags were not closed: %1.

ERROR_SXS_XML_E_UNCLOSEDTAG      14052L






// Manifest Parse Error : Duplicate attribute.

ERROR_SXS_XML_E_DUPLICATEATTRIBUTE 14053L






// Manifest Parse Error : Only one top level element is allowed in an XML document.

ERROR_SXS_XML_E_MULTIPLEROOTS    14054L






// Manifest Parse Error : Invalid at the top level of the document.

ERROR_SXS_XML_E_INVALIDATROOTLEVEL 14055L






// Manifest Parse Error : Invalid xml declaration.

ERROR_SXS_XML_E_BADXMLDECL       14056L






// Manifest Parse Error : XML document must have a top level element.

ERROR_SXS_XML_E_MISSINGROOT      14057L






// Manifest Parse Error : Unexpected end of file.

ERROR_SXS_XML_E_UNEXPECTEDEOF    14058L






// Manifest Parse Error : Parameter entities cannot be used inside markup declarations in an internal subset.

ERROR_SXS_XML_E_BADPEREFINSUBSET 14059L






// Manifest Parse Error : Element was not closed.

ERROR_SXS_XML_E_UNCLOSEDSTARTTAG 14060L






// Manifest Parse Error : End element was missing the character '>'.

ERROR_SXS_XML_E_UNCLOSEDENDTAG   14061L






// Manifest Parse Error : A string literal was not closed.

ERROR_SXS_XML_E_UNCLOSEDSTRING   14062L






// Manifest Parse Error : A comment was not closed.

ERROR_SXS_XML_E_UNCLOSEDCOMMENT  14063L






// Manifest Parse Error : A declaration was not closed.

ERROR_SXS_XML_E_UNCLOSEDDECL     14064L






// Manifest Parse Error : A CDATA section was not closed.

ERROR_SXS_XML_E_UNCLOSEDCDATA    14065L






// Manifest Parse Error : The namespace prefix is not allowed to start with the reserved string "xml".

ERROR_SXS_XML_E_RESERVEDNAMESPACE 14066L






// Manifest Parse Error : System does not support the specified encoding.

ERROR_SXS_XML_E_INVALIDENCODING  14067L






// Manifest Parse Error : Switch from current encoding to specified encoding not supported.

ERROR_SXS_XML_E_INVALIDSWITCH    14068L






// Manifest Parse Error : The name 'xml' is reserved and must be lower case.

ERROR_SXS_XML_E_BADXMLCASE       14069L






// Manifest Parse Error : The standalone attribute must have the value 'yes' or 'no'.

ERROR_SXS_XML_E_INVALID_STANDALONE 14070L






// Manifest Parse Error : The standalone attribute cannot be used in external entities.

ERROR_SXS_XML_E_UNEXPECTED_STANDALONE 14071L






// Manifest Parse Error : Invalid version number.

ERROR_SXS_XML_E_INVALID_VERSION  14072L






// Manifest Parse Error : Missing equals sign between attribute and attribute value.

ERROR_SXS_XML_E_MISSINGEQUALS    14073L






// Assembly Protection Error : Unable to recover the specified assembly.

ERROR_SXS_PROTECTION_RECOVERY_FAILED 14074L






// Assembly Protection Error : The public key for an assembly was too short to be allowed.

ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT 14075L






// Assembly Protection Error : The catalog for an assembly is not valid, or does not match the assembly's manifest.

ERROR_SXS_PROTECTION_CATALOG_NOT_VALID 14076L






// An HRESULT could not be translated to a corresponding Win32 error code.

ERROR_SXS_UNTRANSLATABLE_HRESULT 14077L






// Assembly Protection Error : The catalog for an assembly is missing.

ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING 14078L






// The supplied assembly identity is missing one or more attributes which must be present in this context.

ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE 14079L






// The supplied assembly identity has one or more attribute names that contain characters not permitted in XML names.

ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME 14080L






// The referenced assembly could not be found.

ERROR_SXS_ASSEMBLY_MISSING       14081L






// The activation context activation stack for the running thread of execution is corrupt.

ERROR_SXS_CORRUPT_ACTIVATION_STACK 14082L






// The application isolation metadata for this process or thread has become corrupt.

ERROR_SXS_CORRUPTION             14083L






// The activation context being deactivated is not the most recently activated one.

ERROR_SXS_EARLY_DEACTIVATION     14084L






// The activation context being deactivated is not active for the current thread of execution.

ERROR_SXS_INVALID_DEACTIVATION   14085L






// The activation context being deactivated has already been deactivated.

ERROR_SXS_MULTIPLE_DEACTIVATION  14086L






// A component used by the isolation facility has requested to terminate the process.

ERROR_SXS_PROCESS_TERMINATION_REQUESTED 14087L






// A kernel mode component is releasing a reference on an activation context.

ERROR_SXS_RELEASE_ACTIVATION_CONTEXT 14088L






// The activation context of system default assembly could not be generated.

ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY 14089L






// The value of an attribute in an identity is not within the legal range.

ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE 14090L






// The name of an attribute in an identity is not within the legal range.

ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME 14091L






// An identity contains two definitions for the same attribute.

ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE 14092L






// The identity string is malformed. This may be due to a trailing comma, more than two unnamed attributes, missing attribute name or missing attribute value.

ERROR_SXS_IDENTITY_PARSE_ERROR   14093L






// A string containing localized substitutable content was malformed. Either a dollar sign ($) was followed by something other than a left parenthesis or another dollar sign or an substitution's right parenthesis was not found.

ERROR_MALFORMED_SUBSTITUTION_STRING 14094L






// The public key token does not correspond to the public key specified.

ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN 14095L






// A substitution string had no mapping.

ERROR_UNMAPPED_SUBSTITUTION_STRING 14096L






// The component must be locked before making the request.

ERROR_SXS_ASSEMBLY_NOT_LOCKED    14097L






// The component store has been corrupted.

ERROR_SXS_COMPONENT_STORE_CORRUPT 14098L






// An advanced installer failed during setup or servicing.

ERROR_ADVANCED_INSTALLER_FAILED  14099L






// The character encoding in the XML declaration did not match the encoding used in the document.

ERROR_XML_ENCODING_MISMATCH      14100L






// The identities of the manifests are identical but their contents are different.

ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT 14101L






// The component identities are different.

ERROR_SXS_IDENTITIES_DIFFERENT   14102L






// The assembly is not a deployment.

ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT 14103L






// The file is not a part of the assembly.

ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY 14104L






// The size of the manifest exceeds the maximum allowed.

ERROR_SXS_MANIFEST_TOO_BIG       14105L






// The setting is not registered.

ERROR_SXS_SETTING_NOT_REGISTERED 14106L






// One or more required members of the transaction are not present.

ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE 14107L






// The SMI primitive installer failed during setup or servicing.

ERROR_SMI_PRIMITIVE_INSTALLER_FAILED 14108L






// A generic command executable returned a result that indicates failure.

ERROR_GENERIC_COMMAND_FAILED     14109L






// A component is missing file verification information in its manifest.

ERROR_SXS_FILE_HASH_MISSING      14110L






// Two or more components referenced directly or indirectly by the application manifest have the same WinRT ActivatableClass IDs.

ERROR_SXS_DUPLICATE_ACTIVATABLE_CLASS 14111L


///////////////////////////////////////////////////
//                                               //
//           End of Side By Side Error Codes     //
//                                               //
//                 14000 to 14999                //
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//                                               //
//           Start of WinEvt Error codes         //
//                                               //
//                 15000 to 15079                //
///////////////////////////////////////////////////






// The specified channel path is invalid.

ERROR_EVT_INVALID_CHANNEL_PATH   15000L






// The specified query is invalid.

ERROR_EVT_INVALID_QUERY          15001L






// The publisher metadata cannot be found in the resource.

ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND 15002L






// The template for an event definition cannot be found in the resource (error = %1).

ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND 15003L






// The specified publisher name is invalid.

ERROR_EVT_INVALID_PUBLISHER_NAME 15004L






// The event data raised by the publisher is not compatible with the event template definition in the publisher's manifest.

ERROR_EVT_INVALID_EVENT_DATA     15005L






// The specified channel could not be found.

ERROR_EVT_CHANNEL_NOT_FOUND      15007L






// The specified XML text was not well-formed. See Extended Error for more details.

ERROR_EVT_MALFORMED_XML_TEXT     15008L






// The events for a direct channel go directly to a log file and cannot be subscribed to.

ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL 15009L






// Configuration error.

ERROR_EVT_CONFIGURATION_ERROR    15010L






// The query result is stale or invalid and must be recreated. This may be due to the log being cleared or rolling over after the query result was created.

ERROR_EVT_QUERY_RESULT_STALE     15011L






// The query result is currently at an invalid position.

ERROR_EVT_QUERY_RESULT_INVALID_POSITION 15012L






// Registered MSXML doesn't support validation.

ERROR_EVT_NON_VALIDATING_MSXML   15013L






// An expression can only be followed by a change-of-scope operation if the expression evaluates to a node set and is not already part of another change-of-scope operation.

ERROR_EVT_FILTER_ALREADYSCOPED   15014L






// Cannot perform a step operation from a term that does not represent an element set.

ERROR_EVT_FILTER_NOTELTSET       15015L






// Left-hand side arguments to binary operators must be either attributes, nodes or variables. Right-hand side arguments must be constants.

ERROR_EVT_FILTER_INVARG          15016L






// A step operation must involve a node test or, in the case of a predicate, an algebraic expression against which to test each node in the preceeding node set.

ERROR_EVT_FILTER_INVTEST         15017L






// This data type is currently unsupported.

ERROR_EVT_FILTER_INVTYPE         15018L






// A syntax error occurred at position %1!d!

ERROR_EVT_FILTER_PARSEERR        15019L






// This operator is unsupported by this implementation of the filter.

ERROR_EVT_FILTER_UNSUPPORTEDOP   15020L






// An unexpected token was encountered.

ERROR_EVT_FILTER_UNEXPECTEDTOKEN 15021L






// The requested operation cannot be performed over an enabled direct channel. The channel must first be disabled.

ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL 15022L






// Channel property %1!s! contains an invalid value. The value has an invalid type, is outside of its valid range, cannot be changed, or is not supported by this type of channel.

ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE 15023L






// Publisher property %1!s! contains an invalid value. The value has an invalid type, is outside of its valid range, cannot be changed, or is not supported by this type of publisher.

ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE 15024L






// The channel failed to activate.

ERROR_EVT_CHANNEL_CANNOT_ACTIVATE 15025L






// The XPath expression exceeded the supported complexity. Simplify the expression or split it into multiple expressions.

ERROR_EVT_FILTER_TOO_COMPLEX     15026L






// The message resource is present but the message was not found in the message table.

ERROR_EVT_MESSAGE_NOT_FOUND      15027L






// The message ID for the desired message could not be found.

ERROR_EVT_MESSAGE_ID_NOT_FOUND   15028L






// The substitution string for insert index (%1) could not be found.

ERROR_EVT_UNRESOLVED_VALUE_INSERT 15029L






// The description string for parameter reference (%1) could not be found.

ERROR_EVT_UNRESOLVED_PARAMETER_INSERT 15030L






// The maximum number of replacements has been reached.

ERROR_EVT_MAX_INSERTS_REACHED    15031L






// The event definition could not be found for event ID (%1).

ERROR_EVT_EVENT_DEFINITION_NOT_FOUND 15032L






// The locale specific resource for the desired message is not present.

ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND 15033L






// The resource is too old and is not supported.

ERROR_EVT_VERSION_TOO_OLD        15034L






// The resource is too new and is not supported.

ERROR_EVT_VERSION_TOO_NEW        15035L






// The channel at index %1!d! of the query can't be opened.

ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY 15036L






// The publisher has been disabled and its resource is not available. This usually occurs when the publisher is in the process of being uninstalled or upgraded.

ERROR_EVT_PUBLISHER_DISABLED     15037L






// Attempted to create a numeric type that is outside of its valid range.

ERROR_EVT_FILTER_OUT_OF_RANGE    15038L


///////////////////////////////////////////////////
//                                               //
//           Start of Wecsvc Error codes         //
//                                               //
//                 15080 to 15099                //
///////////////////////////////////////////////////






// The subscription fails to activate.

ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE 15080L






// The log of the subscription is in disabled state, and can not be used to forward events to. The log must first be enabled before the subscription can be activated.

ERROR_EC_LOG_DISABLED            15081L






// When forwarding events from local machine to itself, the query of the subscription can't contain target log of the subscription.

ERROR_EC_CIRCULAR_FORWARDING     15082L






// The credential store that is used to save credentials is full.

ERROR_EC_CREDSTORE_FULL          15083L






// The credential used by this subscription can't be found in credential store.

ERROR_EC_CRED_NOT_FOUND          15084L






// No active channel is found for the query.

ERROR_EC_NO_ACTIVE_CHANNEL       15085L


///////////////////////////////////////////////////
//                                               //
//           Start of MUI Error codes            //
//                                               //
//                 15100 to 15199                //
///////////////////////////////////////////////////






// The resource loader failed to find MUI file.

ERROR_MUI_FILE_NOT_FOUND         15100L    






// The resource loader failed to load MUI file because the file fail to pass validation.

ERROR_MUI_INVALID_FILE           15101L    






// The RC Manifest is corrupted with garbage data or unsupported version or missing required item.

ERROR_MUI_INVALID_RC_CONFIG      15102L    






// The RC Manifest has invalid culture name.

ERROR_MUI_INVALID_LOCALE_NAME    15103L    






// The RC Manifest has invalid ultimatefallback name.

ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME 15104L    






// The resource loader cache doesn't have loaded MUI entry.

ERROR_MUI_FILE_NOT_LOADED        15105L    






// User stopped resource enumeration.

ERROR_RESOURCE_ENUM_USER_STOP    15106L






// UI language installation failed.

ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED 15107L






// Locale installation failed.

ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME 15108L






// A resource does not have default or neutral value.

ERROR_MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE 15110L






// Invalid PRI config file.

ERROR_MRM_INVALID_PRICONFIG      15111L






// Invalid file type.

ERROR_MRM_INVALID_FILE_TYPE      15112L






// Unknown qualifier.

ERROR_MRM_UNKNOWN_QUALIFIER      15113L






// Invalid qualifier value.

ERROR_MRM_INVALID_QUALIFIER_VALUE 15114L






// No Candidate found.

ERROR_MRM_NO_CANDIDATE           15115L






// The ResourceMap or NamedResource has an item that does not have default or neutral resource..

ERROR_MRM_NO_MATCH_OR_DEFAULT_CANDIDATE 15116L






// Invalid ResourceCandidate type.

ERROR_MRM_RESOURCE_TYPE_MISMATCH 15117L






// Duplicate Resource Map.

ERROR_MRM_DUPLICATE_MAP_NAME     15118L






// Duplicate Entry.

ERROR_MRM_DUPLICATE_ENTRY        15119L






// Invalid Resource Identifier.

ERROR_MRM_INVALID_RESOURCE_IDENTIFIER 15120L






// Filepath too long.

ERROR_MRM_FILEPATH_TOO_LONG      15121L






// Unsupported directory type.

ERROR_MRM_UNSUPPORTED_DIRECTORY_TYPE 15122L






// Invalid PRI File.

ERROR_MRM_INVALID_PRI_FILE       15126L






// NamedResource Not Found.

ERROR_MRM_NAMED_RESOURCE_NOT_FOUND 15127L






// ResourceMap Not Found.

ERROR_MRM_MAP_NOT_FOUND          15135L






// Unsupported MRT profile type.

ERROR_MRM_UNSUPPORTED_PROFILE_TYPE 15136L






// Invalid qualifier operator.

ERROR_MRM_INVALID_QUALIFIER_OPERATOR 15137L






// Unable to determine qualifier value or qualifier value has not been set.

ERROR_MRM_INDETERMINATE_QUALIFIER_VALUE 15138L






// Automerge is enabled in the PRI file.

ERROR_MRM_AUTOMERGE_ENABLED      15139L






// Too many resources defined for package.

ERROR_MRM_TOO_MANY_RESOURCES     15140L






// Resource File can not be used for merge operation.

ERROR_MRM_UNSUPPORTED_FILE_TYPE_FOR_MERGE 15141L






// Load/UnloadPriFiles cannot be used with resource packages.

ERROR_MRM_UNSUPPORTED_FILE_TYPE_FOR_LOAD_UNLOAD_PRI_FILE 15142L






// Resource Contexts may not be created on threads that do not have a CoreWindow.

ERROR_MRM_NO_CURRENT_VIEW_ON_THREAD 15143L






// The singleton Resource Manager with different profile is already created.

ERROR_DIFFERENT_PROFILE_RESOURCE_MANAGER_EXIST 15144L






// The system component cannot operate given API operation

ERROR_OPERATION_NOT_ALLOWED_FROM_SYSTEM_COMPONENT 15145L






// The resource is a direct reference to a non-default resource candidate.

ERROR_MRM_DIRECT_REF_TO_NON_DEFAULT_RESOURCE 15146L






// Resource Map has been re-generated and the query string is not valid anymore.

ERROR_MRM_GENERATION_COUNT_MISMATCH 15147L






// The PRI files to be merged have incompatible versions.

ERROR_PRI_MERGE_VERSION_MISMATCH 15148L






// The primary PRI files to be merged does not contain a schema.

ERROR_PRI_MERGE_MISSING_SCHEMA   15149L






// Unable to load one of the PRI files to be merged.

ERROR_PRI_MERGE_LOAD_FILE_FAILED 15150L






// Unable to add one of the PRI files to the merged file.

ERROR_PRI_MERGE_ADD_FILE_FAILED  15151L






// Unable to create the merged PRI file.

ERROR_PRI_MERGE_WRITE_FILE_FAILED 15152L






// Packages for a PRI file merge must all be from the same package family.

ERROR_PRI_MERGE_MULTIPLE_PACKAGE_FAMILIES_NOT_ALLOWED 15153L






// Packages for a PRI file merge must not include multiple main packages.

ERROR_PRI_MERGE_MULTIPLE_MAIN_PACKAGES_NOT_ALLOWED 15154L






// Packages for a PRI file merge must not include bundle packages.

ERROR_PRI_MERGE_BUNDLE_PACKAGES_NOT_ALLOWED 15155L






// Packages for a PRI file merge must include one main package.

ERROR_PRI_MERGE_MAIN_PACKAGE_REQUIRED 15156L






// Packages for a PRI file merge must include at least one resource package.

ERROR_PRI_MERGE_RESOURCE_PACKAGE_REQUIRED 15157L






// Invalid name supplied for a canonical merged PRI file.

ERROR_PRI_MERGE_INVALID_FILE_NAME 15158L






// Unable to find the specified package.

ERROR_MRM_PACKAGE_NOT_FOUND      15159L






// No default value for language was specified.

ERROR_MRM_MISSING_DEFAULT_LANGUAGE 15160L


///////////////////////////////////////////////////
//                                               //
// Start of Monitor Configuration API error codes//
//                                               //
//                 15200 to 15249                //
///////////////////////////////////////////////////






// The monitor returned a DDC/CI capabilities string that did not comply with the ACCESS.bus 3.0, DDC/CI 1.1 or MCCS 2 Revision 1 specification.

ERROR_MCA_INVALID_CAPABILITIES_STRING 15200L






// The monitor's VCP Version (0xDF) VCP code returned an invalid version value.

ERROR_MCA_INVALID_VCP_VERSION    15201L






// The monitor does not comply with the MCCS specification it claims to support.

ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION 15202L






// The MCCS version in a monitor's mccs_ver capability does not match the MCCS version the monitor reports when the VCP Version (0xDF) VCP code is used.

ERROR_MCA_MCCS_VERSION_MISMATCH  15203L






// The Monitor Configuration API only works with monitors that support the MCCS 1.0 specification, MCCS 2.0 specification or the MCCS 2.0 Revision 1 specification.

ERROR_MCA_UNSUPPORTED_MCCS_VERSION 15204L






// An internal Monitor Configuration API error occurred.

ERROR_MCA_INTERNAL_ERROR         15205L






// The monitor returned an invalid monitor technology type. CRT, Plasma and LCD (TFT) are examples of monitor technology types. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.

ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED 15206L






// The caller of SetMonitorColorTemperature specified a color temperature that the current monitor did not support. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.

ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE 15207L


//////////////////////////////////////////////////
//                                              //
// End of Monitor Configuration API error codes //
//                                              //
//                15200 to 15249                //
//                                              //
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//                                              //
//         Start of Syspart error codes         //
//                15250 - 15299                 //
//                                              //
//////////////////////////////////////////////////






// The requested system device cannot be identified due to multiple indistinguishable devices potentially matching the identification criteria.

ERROR_AMBIGUOUS_SYSTEM_DEVICE    15250L






// The requested system device cannot be found.

ERROR_SYSTEM_DEVICE_NOT_FOUND    15299L

//////////////////////////////////////////////////
//                                              //
//         Start of Vortex error codes          //
//                15300 - 15320                 //
//                                              //
//////////////////////////////////////////////////






// Hash generation for the specified hash version and hash type is not enabled on the server.

ERROR_HASH_NOT_SUPPORTED         15300L






// The hash requested from the server is not available or no longer valid.

ERROR_HASH_NOT_PRESENT           15301L

//////////////////////////////////////////////////
//                                              //
//         Start of GPIO error codes            //
//                15321 - 15340                 //
//                                              //
//////////////////////////////////////////////////






// The secondary interrupt controller instance that manages the specified interrupt is not registered.

ERROR_SECONDARY_IC_PROVIDER_NOT_REGISTERED 15321L






// The information supplied by the GPIO client driver is invalid.

ERROR_GPIO_CLIENT_INFORMATION_INVALID 15322L






// The version specified by the GPIO client driver is not supported.

ERROR_GPIO_VERSION_NOT_SUPPORTED 15323L






// The registration packet supplied by the GPIO client driver is not valid.

ERROR_GPIO_INVALID_REGISTRATION_PACKET 15324L






// The requested operation is not supported for the specified handle.

ERROR_GPIO_OPERATION_DENIED      15325L






// The requested connect mode conflicts with an existing mode on one or more of the specified pins.

ERROR_GPIO_INCOMPATIBLE_CONNECT_MODE 15326L






// The interrupt requested to be unmasked is not masked.

ERROR_GPIO_INTERRUPT_ALREADY_UNMASKED 15327L

//////////////////////////////////////////////////
//                                              //
//         Start of Run Level error codes       //
//                15400 - 15500                 //
//                                              //
//////////////////////////////////////////////////






// The requested run level switch cannot be completed successfully.

ERROR_CANNOT_SWITCH_RUNLEVEL     15400L






// The service has an invalid run level setting. The run level for a service
// must not be higher than the run level of its dependent services.

ERROR_INVALID_RUNLEVEL_SETTING   15401L






// The requested run level switch cannot be completed successfully since
// one or more services will not stop or restart within the specified timeout.

ERROR_RUNLEVEL_SWITCH_TIMEOUT    15402L






// A run level switch agent did not respond within the specified timeout.

ERROR_RUNLEVEL_SWITCH_AGENT_TIMEOUT 15403L






// A run level switch is currently in progress.

ERROR_RUNLEVEL_SWITCH_IN_PROGRESS 15404L






// One or more services failed to start during the service startup phase of a run level switch.

ERROR_SERVICES_FAILED_AUTOSTART  15405L

//////////////////////////////////////////////////
//                                              //
//         Start of Com Task error codes        //
//                15501 - 15510                 //
//                                              //
//////////////////////////////////////////////////






// The task stop request cannot be completed immediately since
// task needs more time to shutdown.

ERROR_COM_TASK_STOP_PENDING      15501L

////////////////////////////////////////
//                                    //
// APPX Caller Visible Error Codes    //
//          15600-15699               //
////////////////////////////////////////





// Package could not be opened.

ERROR_INSTALL_OPEN_PACKAGE_FAILED 15600L






// Package was not found.

ERROR_INSTALL_PACKAGE_NOT_FOUND  15601L






// Package data is invalid.

ERROR_INSTALL_INVALID_PACKAGE    15602L






// Package failed updates, dependency or conflict validation.

ERROR_INSTALL_RESOLVE_DEPENDENCY_FAILED 15603L






// There is not enough disk space on your computer. Please free up some space and try again.

ERROR_INSTALL_OUT_OF_DISK_SPACE  15604L






// There was a problem downloading your product.

ERROR_INSTALL_NETWORK_FAILURE    15605L






// Package could not be registered.

ERROR_INSTALL_REGISTRATION_FAILURE 15606L






// Package could not be unregistered.

ERROR_INSTALL_DEREGISTRATION_FAILURE 15607L






// User cancelled the install request.

ERROR_INSTALL_CANCEL             15608L






// Install failed. Please contact your software vendor.

ERROR_INSTALL_FAILED             15609L






// Removal failed. Please contact your software vendor.

ERROR_REMOVE_FAILED              15610L






// The provided package is already installed, and reinstallation of the package was blocked. Check the AppXDeployment-Server event log for details.

ERROR_PACKAGE_ALREADY_EXISTS     15611L






// The application cannot be started. Try reinstalling the application to fix the problem.

ERROR_NEEDS_REMEDIATION          15612L






// A Prerequisite for an install could not be satisfied.

ERROR_INSTALL_PREREQUISITE_FAILED 15613L






// The package repository is corrupted.

ERROR_PACKAGE_REPOSITORY_CORRUPTED 15614L






// To install this application you need either a Windows developer license or a sideloading-enabled system.

ERROR_INSTALL_POLICY_FAILURE     15615L






// The application cannot be started because it is currently updating.

ERROR_PACKAGE_UPDATING           15616L






// The package deployment operation is blocked by policy. Please contact your system administrator.

ERROR_DEPLOYMENT_BLOCKED_BY_POLICY 15617L






// The package could not be installed because resources it modifies are currently in use.

ERROR_PACKAGES_IN_USE            15618L






// The package could not be recovered because necessary data for recovery have been corrupted.

ERROR_RECOVERY_FILE_CORRUPT      15619L






// The signature is invalid. To register in developer mode, AppxSignature.p7x and AppxBlockMap.xml must be valid or should not be present.

ERROR_INVALID_STAGED_SIGNATURE   15620L






// An error occurred while deleting the package's previously existing application data.

ERROR_DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED 15621L






// The package could not be installed because a higher version of this package is already installed.

ERROR_INSTALL_PACKAGE_DOWNGRADE  15622L






// An error in a system binary was detected. Try refreshing the PC to fix the problem.

ERROR_SYSTEM_NEEDS_REMEDIATION   15623L






// A corrupted CLR NGEN binary was detected on the system.

ERROR_APPX_INTEGRITY_FAILURE_CLR_NGEN 15624L






// The operation could not be resumed because necessary data for recovery have been corrupted.

ERROR_RESILIENCY_FILE_CORRUPT    15625L






// The package could not be installed because the Windows Firewall service is not running. Enable the Windows Firewall service and try again.

ERROR_INSTALL_FIREWALL_SERVICE_NOT_RUNNING 15626L






// Package move failed.

ERROR_PACKAGE_MOVE_FAILED        15627L






// The deployment operation failed because the volume is not empty.

ERROR_INSTALL_VOLUME_NOT_EMPTY   15628L






// The deployment operation failed because the volume is offline.

ERROR_INSTALL_VOLUME_OFFLINE     15629L






// The deployment operation failed because the specified volume is corrupt.

ERROR_INSTALL_VOLUME_CORRUPT     15630L






// The deployment operation failed because the specified application needs to be registered first.

ERROR_NEEDS_REGISTRATION         15631L






// The deployment operation failed because the package targets the wrong processor architecture.

ERROR_INSTALL_WRONG_PROCESSOR_ARCHITECTURE 15632L






// You have reached the maximum number of developer sideloaded packages allowed on this device. Please uninstall a sideloaded package and try again.

ERROR_DEV_SIDELOAD_LIMIT_EXCEEDED 15633L






// A main app package is required to install this optional package.  Install the main package first and try again.

ERROR_INSTALL_OPTIONAL_PACKAGE_REQUIRES_MAIN_PACKAGE 15634L






// This app package type is not supported on this filesystem

ERROR_PACKAGE_NOT_SUPPORTED_ON_FILESYSTEM 15635L






// Package move operation is blocked until the application has finished streaming

ERROR_PACKAGE_MOVE_BLOCKED_BY_STREAMING 15636L






// A main or another optional app package has the same application ID as this optional package.  Change the application ID for the optional package to avoid conflicts.

ERROR_INSTALL_OPTIONAL_PACKAGE_APPLICATIONID_NOT_UNIQUE 15637L






// This staging session has been held to allow another staging operation to be prioritized.

ERROR_PACKAGE_STAGING_ONHOLD     15638L






// A related set cannot be updated because the updated set is invalid. All packages in the related set must be updated at the same time.

ERROR_INSTALL_INVALID_RELATED_SET_UPDATE 15639L






// An optional package with a FullTrust entry point requires the main package to have the runFullTrust capability.

ERROR_INSTALL_OPTIONAL_PACKAGE_REQUIRES_MAIN_PACKAGE_FULLTRUST_CAPABILITY 15640L






// An error occurred because a user was logged off.

ERROR_DEPLOYMENT_BLOCKED_BY_USER_LOG_OFF 15641L






// An optional package provision requires the dependency main package to also be provisioned.

ERROR_PROVISION_OPTIONAL_PACKAGE_REQUIRES_MAIN_PACKAGE_PROVISIONED 15642L






// The packages failed the SmartScreen reputation check.

ERROR_PACKAGES_REPUTATION_CHECK_FAILED 15643L






// The SmartScreen reputation check operation timed out.

ERROR_PACKAGES_REPUTATION_CHECK_TIMEDOUT 15644L






// The current deployment option is not supported.

ERROR_DEPLOYMENT_OPTION_NOT_SUPPORTED 15645L






// Activation is blocked due to the .appinstaller update settings for this app.

ERROR_APPINSTALLER_ACTIVATION_BLOCKED 15646L






// Remote drives are not supported; use \\server\share to register a remote package.

ERROR_REGISTRATION_FROM_REMOTE_DRIVE_NOT_SUPPORTED 15647L






// Failed to process and write downloaded APPX package data to disk.

ERROR_APPX_RAW_DATA_WRITE_FAILED 15648L






// The deployment operation was blocked due to a per-package-family policy restricting deployments on a non-system volume. Per policy, this app must be installed to the system drive, but that's not set as the default. In Storage Settings, make the system drive the default location to save new content, then retry the install.

ERROR_DEPLOYMENT_BLOCKED_BY_VOLUME_POLICY_PACKAGE 15649L






// The deployment operation was blocked due to a machine-wide policy restricting deployments on a non-system volume. Per policy, this app must be installed to the system drive, but that's not set as the default. In Storage Settings, make the system drive the default location to save new content, then retry the install.

ERROR_DEPLOYMENT_BLOCKED_BY_VOLUME_POLICY_MACHINE 15650L






// The deployment operation was blocked because Special profile deployment is not allowed. Please try logging into an account that is not a Special profile. You can try logging out and logging back into the current account, or try logging into a different account.

ERROR_DEPLOYMENT_BLOCKED_BY_PROFILE_POLICY 15651L






// The deployment operation failed due to a conflicting package's mutable package directory. To install this package remove the existing package with the conflicting mutable package directory.

ERROR_DEPLOYMENT_FAILED_CONFLICTING_MUTABLE_PACKAGE_DIRECTORY 15652L






// The package installation failed because a singleton resource was specified and another user with that package installed is logged in. Please make sure that all active users with the package installed are logged out and retry installation.

ERROR_SINGLETON_RESOURCE_INSTALLED_IN_ACTIVE_USER 15653L






// The package installation failed because a different version of the service is installed. Try installing a newer version of the package.

ERROR_DIFFERENT_VERSION_OF_PACKAGED_SERVICE_INSTALLED 15654L






// The package installation failed because a version of the service exists outside of APPX packaging. Please contact your software vendor.

ERROR_SERVICE_EXISTS_AS_NON_PACKAGED_SERVICE 15655L






// The package installation failed because administrator privileges are required. Please contact an administrator to install this package.

ERROR_PACKAGED_SERVICE_REQUIRES_ADMIN_PRIVILEGES 15656L

//////////////////////////
//                      //
// AppModel Error Codes //
//     15700-15720      //
//                      //
//////////////////////////





// The process has no package identity.

APPMODEL_ERROR_NO_PACKAGE        15700L






// The package runtime information is corrupted.

APPMODEL_ERROR_PACKAGE_RUNTIME_CORRUPT 15701L






// The package identity is corrupted.

APPMODEL_ERROR_PACKAGE_IDENTITY_CORRUPT 15702L






// The process has no application identity.

APPMODEL_ERROR_NO_APPLICATION    15703L






// One or more AppModel Runtime group policy values could not be read. Please contact your system administrator with the contents of your AppModel Runtime event log.

APPMODEL_ERROR_DYNAMIC_PROPERTY_READ_FAILED 15704L






// One or more AppModel Runtime group policy values are invalid. Please contact your system administrator with the contents of your AppModel Runtime event log.

APPMODEL_ERROR_DYNAMIC_PROPERTY_INVALID 15705L






// The package is currently not available.

APPMODEL_ERROR_PACKAGE_NOT_AVAILABLE 15706L






// The package does not have a mutable directory.

APPMODEL_ERROR_NO_MUTABLE_DIRECTORY 15707L

/////////////////////////////
//                         //
// Appx StateManager Codes //
//     15800-15840         //
//                         //
/////////////////////////////





// Loading the state store failed.

ERROR_STATE_LOAD_STORE_FAILED    15800L






// Retrieving the state version for the application failed.

ERROR_STATE_GET_VERSION_FAILED   15801L






// Setting the state version for the application failed.

ERROR_STATE_SET_VERSION_FAILED   15802L






// Resetting the structured state of the application failed.

ERROR_STATE_STRUCTURED_RESET_FAILED 15803L






// State Manager failed to open the container.

ERROR_STATE_OPEN_CONTAINER_FAILED 15804L






// State Manager failed to create the container.

ERROR_STATE_CREATE_CONTAINER_FAILED 15805L






// State Manager failed to delete the container.

ERROR_STATE_DELETE_CONTAINER_FAILED 15806L






// State Manager failed to read the setting.

ERROR_STATE_READ_SETTING_FAILED  15807L






// State Manager failed to write the setting.

ERROR_STATE_WRITE_SETTING_FAILED 15808L






// State Manager failed to delete the setting.

ERROR_STATE_DELETE_SETTING_FAILED 15809L






// State Manager failed to query the setting.

ERROR_STATE_QUERY_SETTING_FAILED 15810L






// State Manager failed to read the composite setting.

ERROR_STATE_READ_COMPOSITE_SETTING_FAILED 15811L






// State Manager failed to write the composite setting.

ERROR_STATE_WRITE_COMPOSITE_SETTING_FAILED 15812L






// State Manager failed to enumerate the containers.

ERROR_STATE_ENUMERATE_CONTAINER_FAILED 15813L






// State Manager failed to enumerate the settings.

ERROR_STATE_ENUMERATE_SETTINGS_FAILED 15814L






// The size of the state manager composite setting value has exceeded the limit.

ERROR_STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED 15815L






// The size of the state manager setting value has exceeded the limit.

ERROR_STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED 15816L






// The length of the state manager setting name has exceeded the limit.

ERROR_STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED 15817L






// The length of the state manager container name has exceeded the limit.

ERROR_STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED 15818L

/////////////////////////////////
//                             //
// Application Partition Codes //
//     15841-15860             //
//                             //
/////////////////////////////////





// This API cannot be used in the context of the caller's application type.

ERROR_API_UNAVAILABLE            15841L

/////////////////////////////////
//                             //
// Windows Store Codes         //
//     15861-15880             //
//                             //
/////////////////////////////////





// This PC does not have a valid license for the application or product.

STORE_ERROR_UNLICENSED           15861L






// The authenticated user does not have a valid license for the application or product.

STORE_ERROR_UNLICENSED_USER      15862L






// The commerce transaction associated with this license is still pending verification.

STORE_ERROR_PENDING_COM_TRANSACTION 15863L






// The license has been revoked for this user.

STORE_ERROR_LICENSE_REVOKED      15864L

////////////////////////////////////
//                                //
//     COM Error Codes            //
//                                //
////////////////////////////////////



// The return value of COM functions and methods is an HRESULT.
// This is not a handle to anything, but is merely a 32-bit value
// with several fields encoded in the value. The parts of an
// HRESULT are shown below.

// Many of the macros and functions below were originally defined to
// operate on SCODEs. SCODEs are no longer used. The macros are
// still present for compatibility and easy porting of Win16 code.
// Newly written code should use the HRESULT macros and functions.



//  HRESULTs are 32 bit values laid out as follows:

//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +-+-+-+-+-+---------------------+-------------------------------+
//  |S|R|C|N|r|    Facility         |               Code            |
//  +-+-+-+-+-+---------------------+-------------------------------+

//  where

//      S - Severity - indicates success/fail

//          0 - Success
//          1 - Fail (COERROR)

//      R - reserved portion of the facility code, corresponds to NT's
//              second severity bit.

//      C - reserved portion of the facility code, corresponds to NT's
//              C field.

//      N - reserved portion of the facility code. Used to indicate a
//              mapped NT status value.

//      r - reserved portion of the facility code. Reserved for internal
//              use. Used to indicate HRESULT values that are not status
//              values, but are instead message ids for display strings.

//      Facility - is the facility code

//      Code - is the facility's status code



// Severity values


SEVERITY_SUCCESS    0
SEVERITY_ERROR      1



// Generic test for success on any status value (non-negative numbers
// indicate success).


SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)


// and the inverse


FAILED(hr) (((HRESULT)(hr)) < 0)



// Generic test for error on any status value.


IS_ERROR(Status) (((unsigned long)(Status)) >> 31 == SEVERITY_ERROR)


// Return the code


HRESULT_CODE(hr)    ((hr) & 0xFFFF)
SCODE_CODE(sc)      ((sc) & 0xFFFF)


//  Return the facility


HRESULT_FACILITY(hr)  (((hr) >> 16) & 0x1fff)
SCODE_FACILITY(sc)    (((sc) >> 16) & 0x1fff)


//  Return the severity


HRESULT_SEVERITY(hr)  (((hr) >> 31) & 0x1)
SCODE_SEVERITY(sc)    (((sc) >> 31) & 0x1)


// Create an HRESULT value from component pieces


MAKE_HRESULT(sev,fac,code) \
    ((HRESULT) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )
MAKE_SCODE(sev,fac,code) \
    ((SCODE) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )



// Map a WIN32 error value into a HRESULT
// Note: This assumes that WIN32 errors fall in the range -32k to 32k.

// Define bits here so macros are guaranteed to work

FACILITY_NT_BIT                 0x10000000


// HRESULT_FROM_WIN32(x) used to be a macro, however we now run it as an inline function
// to prevent double evaluation of 'x'. If you still need the macro, you can use __HRESULT_FROM_WIN32(x)

__HRESULT_FROM_WIN32(x) ((HRESULT)(x) <= 0 ? ((HRESULT)(x)) : ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000)))

#if !defined(_HRESULT_DEFINED) && !defined(__midl)
_HRESULT_DEFINED
typedef _Return_type_success_(return >= 0) long HRESULT;
#endif

#ifndef __midl
#if defined(__cplusplus) && _MSC_VER >= 1900 && !defined(SORTPP_PASS)
constexpr
#endif
FORCEINLINE _Translates_Win32_to_HRESULT_(x) HRESULT HRESULT_FROM_WIN32(unsigned long x) { return (HRESULT)(x) <= 0 ? (HRESULT)(x) : (HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000);}
#else
HRESULT_FROM_WIN32(x) __HRESULT_FROM_WIN32(x)
#endif


// Map an NT status value into a HRESULT


HRESULT_FROM_NT(x)      ((HRESULT) ((x) | FACILITY_NT_BIT))


// ****** OBSOLETE functions

// HRESULT functions
// As noted above, these functions are obsolete and should not be used.


// Extract the SCODE from a HRESULT

GetScode(hr) ((SCODE) (hr))

// Convert an SCODE into an HRESULT.

ResultFromScode(sc) ((HRESULT) (sc))


// PropagateResult is a noop
PropagateResult(hrPrevious, scBase) ((HRESULT) scBase)


// ****** End of OBSOLETE functions.

E_NOT_SET                HRESULT_FROM_WIN32(ERROR_NOT_FOUND)
E_NOT_VALID_STATE        HRESULT_FROM_WIN32(ERROR_INVALID_STATE)
E_NOT_SUFFICIENT_BUFFER  HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)
E_TIME_SENSITIVE_THREAD  HRESULT_FROM_WIN32(ERROR_TIME_SENSITIVE_THREAD)
E_NO_TASK_QUEUE          HRESULT_FROM_WIN32(ERROR_NO_TASK_QUEUE)

// ---------------------- HRESULT value definitions -----------------

// HRESULT definitions


#ifdef RC_INVOKED
_HRESULT_TYPEDEF_(_sc) _sc
#else // RC_INVOKED
_HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#endif // RC_INVOKED

NOERROR             0


// Error definitions follow



// Codes 0x4000-0x40ff are reserved for OLE


// Error codes






// Catastrophic failure

E_UNEXPECTED                     _HRESULT_TYPEDEF_(0x8000FFFFL)

#if defined(_WIN32) && !defined(_MAC)





// Not implemented

E_NOTIMPL                        _HRESULT_TYPEDEF_(0x80004001L)






// Ran out of memory

E_OUTOFMEMORY                    _HRESULT_TYPEDEF_(0x8007000EL)






// One or more arguments are invalid

E_INVALIDARG                     _HRESULT_TYPEDEF_(0x80070057L)






// No such interface supported

E_NOINTERFACE                    _HRESULT_TYPEDEF_(0x80004002L)






// Invalid pointer

E_POINTER                        _HRESULT_TYPEDEF_(0x80004003L)






// Invalid handle

E_HANDLE                         _HRESULT_TYPEDEF_(0x80070006L)






// Operation aborted

E_ABORT                          _HRESULT_TYPEDEF_(0x80004004L)






// Unspecified error

E_FAIL                           _HRESULT_TYPEDEF_(0x80004005L)






// General access denied error

E_ACCESSDENIED                   _HRESULT_TYPEDEF_(0x80070005L)

#else





// Not implemented

E_NOTIMPL                        _HRESULT_TYPEDEF_(0x80000001L)






// Ran out of memory

E_OUTOFMEMORY                    _HRESULT_TYPEDEF_(0x80000002L)






// One or more arguments are invalid

E_INVALIDARG                     _HRESULT_TYPEDEF_(0x80000003L)






// No such interface supported

E_NOINTERFACE                    _HRESULT_TYPEDEF_(0x80000004L)






// Invalid pointer

E_POINTER                        _HRESULT_TYPEDEF_(0x80000005L)






// Invalid handle

E_HANDLE                         _HRESULT_TYPEDEF_(0x80000006L)






// Operation aborted

E_ABORT                          _HRESULT_TYPEDEF_(0x80000007L)






// Unspecified error

E_FAIL                           _HRESULT_TYPEDEF_(0x80000008L)






// General access denied error

E_ACCESSDENIED                   _HRESULT_TYPEDEF_(0x80000009L)

#endif //WIN32





// The data necessary to complete this operation is not yet available.

E_PENDING                        _HRESULT_TYPEDEF_(0x8000000AL)






// The operation attempted to access data outside the valid range

E_BOUNDS                         _HRESULT_TYPEDEF_(0x8000000BL)






// A concurrent or interleaved operation changed the state of the object, invalidating this operation.

E_CHANGED_STATE                  _HRESULT_TYPEDEF_(0x8000000CL)






// An illegal state change was requested.

E_ILLEGAL_STATE_CHANGE           _HRESULT_TYPEDEF_(0x8000000DL)






// A method was called at an unexpected time.

E_ILLEGAL_METHOD_CALL            _HRESULT_TYPEDEF_(0x8000000EL)






// Typename or Namespace was not found in metadata file.

RO_E_METADATA_NAME_NOT_FOUND     _HRESULT_TYPEDEF_(0x8000000FL)






// Name is an existing namespace rather than a typename.

RO_E_METADATA_NAME_IS_NAMESPACE  _HRESULT_TYPEDEF_(0x80000010L)






// Typename has an invalid format.

RO_E_METADATA_INVALID_TYPE_FORMAT _HRESULT_TYPEDEF_(0x80000011L)






// Metadata file is invalid or corrupted.

RO_E_INVALID_METADATA_FILE       _HRESULT_TYPEDEF_(0x80000012L)






// The object has been closed.

RO_E_CLOSED                      _HRESULT_TYPEDEF_(0x80000013L)






// Only one thread may access the object during a write operation.

RO_E_EXCLUSIVE_WRITE             _HRESULT_TYPEDEF_(0x80000014L)






// Operation is prohibited during change notification.

RO_E_CHANGE_NOTIFICATION_IN_PROGRESS _HRESULT_TYPEDEF_(0x80000015L)






// The text associated with this error code could not be found.

RO_E_ERROR_STRING_NOT_FOUND      _HRESULT_TYPEDEF_(0x80000016L)






// String not null terminated.

E_STRING_NOT_NULL_TERMINATED     _HRESULT_TYPEDEF_(0x80000017L)






// A delegate was assigned when not allowed.

E_ILLEGAL_DELEGATE_ASSIGNMENT    _HRESULT_TYPEDEF_(0x80000018L)






// An async operation was not properly started.

E_ASYNC_OPERATION_NOT_STARTED    _HRESULT_TYPEDEF_(0x80000019L)






// The application is exiting and cannot service this request

E_APPLICATION_EXITING            _HRESULT_TYPEDEF_(0x8000001AL)






// The application view is exiting and cannot service this request

E_APPLICATION_VIEW_EXITING       _HRESULT_TYPEDEF_(0x8000001BL)






// The object must support the IAgileObject interface

RO_E_MUST_BE_AGILE               _HRESULT_TYPEDEF_(0x8000001CL)






// Activating a single-threaded class from MTA is not supported

RO_E_UNSUPPORTED_FROM_MTA        _HRESULT_TYPEDEF_(0x8000001DL)






// The object has been committed.

RO_E_COMMITTED                   _HRESULT_TYPEDEF_(0x8000001EL)






// A COM call to an ASTA was blocked because the call chain originated in or passed through another ASTA. This call pattern is deadlock-prone and disallowed by apartment call control.

RO_E_BLOCKED_CROSS_ASTA_CALL     _HRESULT_TYPEDEF_(0x8000001FL)






// A universal application process cannot activate a packaged WinRT server that is declared to run full trust.

RO_E_CANNOT_ACTIVATE_FULL_TRUST_SERVER _HRESULT_TYPEDEF_(0x80000020L)






// A full trust packaged application process cannot activate a packaged WinRT server unless it is also declared to run full trust.

RO_E_CANNOT_ACTIVATE_UNIVERSAL_APPLICATION_SERVER _HRESULT_TYPEDEF_(0x80000021L)






// Thread local storage failure

CO_E_INIT_TLS                    _HRESULT_TYPEDEF_(0x80004006L)






// Get shared memory allocator failure

CO_E_INIT_SHARED_ALLOCATOR       _HRESULT_TYPEDEF_(0x80004007L)






// Get memory allocator failure

CO_E_INIT_MEMORY_ALLOCATOR       _HRESULT_TYPEDEF_(0x80004008L)






// Unable to initialize class cache

CO_E_INIT_CLASS_CACHE            _HRESULT_TYPEDEF_(0x80004009L)






// Unable to initialize RPC services

CO_E_INIT_RPC_CHANNEL            _HRESULT_TYPEDEF_(0x8000400AL)






// Cannot set thread local storage channel control

CO_E_INIT_TLS_SET_CHANNEL_CONTROL _HRESULT_TYPEDEF_(0x8000400BL)






// Could not allocate thread local storage channel control

CO_E_INIT_TLS_CHANNEL_CONTROL    _HRESULT_TYPEDEF_(0x8000400CL)






// The user supplied memory allocator is unacceptable

CO_E_INIT_UNACCEPTED_USER_ALLOCATOR _HRESULT_TYPEDEF_(0x8000400DL)






// The OLE service mutex already exists

CO_E_INIT_SCM_MUTEX_EXISTS       _HRESULT_TYPEDEF_(0x8000400EL)






// The OLE service file mapping already exists

CO_E_INIT_SCM_FILE_MAPPING_EXISTS _HRESULT_TYPEDEF_(0x8000400FL)






// Unable to map view of file for OLE service

CO_E_INIT_SCM_MAP_VIEW_OF_FILE   _HRESULT_TYPEDEF_(0x80004010L)






// Failure attempting to launch OLE service

CO_E_INIT_SCM_EXEC_FAILURE       _HRESULT_TYPEDEF_(0x80004011L)






// There was an attempt to call CoInitialize a second time while single threaded

CO_E_INIT_ONLY_SINGLE_THREADED   _HRESULT_TYPEDEF_(0x80004012L)






// A Remote activation was necessary but was not allowed

CO_E_CANT_REMOTE                 _HRESULT_TYPEDEF_(0x80004013L)






// A Remote activation was necessary but the server name provided was invalid

CO_E_BAD_SERVER_NAME             _HRESULT_TYPEDEF_(0x80004014L)






// The class is configured to run as a security id different from the caller

CO_E_WRONG_SERVER_IDENTITY       _HRESULT_TYPEDEF_(0x80004015L)






// Use of Ole1 services requiring DDE windows is disabled

CO_E_OLE1DDE_DISABLED            _HRESULT_TYPEDEF_(0x80004016L)






// A RunAs specification must be <domain name>\<user name> or simply <user name>

CO_E_RUNAS_SYNTAX                _HRESULT_TYPEDEF_(0x80004017L)






// The server process could not be started. The pathname may be incorrect.

CO_E_CREATEPROCESS_FAILURE       _HRESULT_TYPEDEF_(0x80004018L)






// The server process could not be started as the configured identity. The pathname may be incorrect or unavailable.

CO_E_RUNAS_CREATEPROCESS_FAILURE _HRESULT_TYPEDEF_(0x80004019L)






// The server process could not be started because the configured identity is incorrect. Check the username and password.

CO_E_RUNAS_LOGON_FAILURE         _HRESULT_TYPEDEF_(0x8000401AL)






// The client is not allowed to launch this server.

CO_E_LAUNCH_PERMSSION_DENIED     _HRESULT_TYPEDEF_(0x8000401BL)






// The service providing this server could not be started.

CO_E_START_SERVICE_FAILURE       _HRESULT_TYPEDEF_(0x8000401CL)






// This computer was unable to communicate with the computer providing the server.

CO_E_REMOTE_COMMUNICATION_FAILURE _HRESULT_TYPEDEF_(0x8000401DL)






// The server did not respond after being launched.

CO_E_SERVER_START_TIMEOUT        _HRESULT_TYPEDEF_(0x8000401EL)






// The registration information for this server is inconsistent or incomplete.

CO_E_CLSREG_INCONSISTENT         _HRESULT_TYPEDEF_(0x8000401FL)






// The registration information for this interface is inconsistent or incomplete.

CO_E_IIDREG_INCONSISTENT         _HRESULT_TYPEDEF_(0x80004020L)






// The operation attempted is not supported.

CO_E_NOT_SUPPORTED               _HRESULT_TYPEDEF_(0x80004021L)






// A dll must be loaded.

CO_E_RELOAD_DLL                  _HRESULT_TYPEDEF_(0x80004022L)






// A Microsoft Software Installer error was encountered.

CO_E_MSI_ERROR                   _HRESULT_TYPEDEF_(0x80004023L)






// The specified activation could not occur in the client context as specified.

CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT _HRESULT_TYPEDEF_(0x80004024L)






// Activations on the server are paused.

CO_E_SERVER_PAUSED               _HRESULT_TYPEDEF_(0x80004025L)






// Activations on the server are not paused.

CO_E_SERVER_NOT_PAUSED           _HRESULT_TYPEDEF_(0x80004026L)






// The component or application containing the component has been disabled.

CO_E_CLASS_DISABLED              _HRESULT_TYPEDEF_(0x80004027L)






// The common language runtime is not available

CO_E_CLRNOTAVAILABLE             _HRESULT_TYPEDEF_(0x80004028L)






// The thread-pool rejected the submitted asynchronous work.

CO_E_ASYNC_WORK_REJECTED         _HRESULT_TYPEDEF_(0x80004029L)






// The server started, but did not finish initializing in a timely fashion.

CO_E_SERVER_INIT_TIMEOUT         _HRESULT_TYPEDEF_(0x8000402AL)






// Unable to complete the call since there is no COM+ security context inside IObjectControl.Activate.

CO_E_NO_SECCTX_IN_ACTIVATE       _HRESULT_TYPEDEF_(0x8000402BL)






// The provided tracker configuration is invalid

CO_E_TRACKER_CONFIG              _HRESULT_TYPEDEF_(0x80004030L)






// The provided thread pool configuration is invalid

CO_E_THREADPOOL_CONFIG           _HRESULT_TYPEDEF_(0x80004031L)






// The provided side-by-side configuration is invalid

CO_E_SXS_CONFIG                  _HRESULT_TYPEDEF_(0x80004032L)






// The server principal name (SPN) obtained during security negotiation is malformed.

CO_E_MALFORMED_SPN               _HRESULT_TYPEDEF_(0x80004033L)






// The caller failed to revoke a per-apartment registration before apartment shutdown.

CO_E_UNREVOKED_REGISTRATION_ON_APARTMENT_SHUTDOWN _HRESULT_TYPEDEF_(0x80004034L)






// The object has been rundown by the stub manager while there are external clients.

CO_E_PREMATURE_STUB_RUNDOWN      _HRESULT_TYPEDEF_(0x80004035L)



// Success codes

S_OK                                   ((HRESULT)0L)
S_FALSE                                ((HRESULT)1L)

// ******************
// FACILITY_ITF
// ******************


// Codes 0x0-0x01ff are reserved for the OLE group of
// interfaces.




// Generic OLE errors that may be returned by many interfaces


OLE_E_FIRST ((HRESULT)0x80040000L)
OLE_E_LAST  ((HRESULT)0x800400FFL)
OLE_S_FIRST ((HRESULT)0x00040000L)
OLE_S_LAST  ((HRESULT)0x000400FFL)


// Old OLE errors






// Invalid OLEVERB structure

OLE_E_OLEVERB                    _HRESULT_TYPEDEF_(0x80040000L)






// Invalid advise flags

OLE_E_ADVF                       _HRESULT_TYPEDEF_(0x80040001L)






// Can't enumerate any more, because the associated data is missing

OLE_E_ENUM_NOMORE                _HRESULT_TYPEDEF_(0x80040002L)






// This implementation doesn't take advises

OLE_E_ADVISENOTSUPPORTED         _HRESULT_TYPEDEF_(0x80040003L)






// There is no connection for this connection ID

OLE_E_NOCONNECTION               _HRESULT_TYPEDEF_(0x80040004L)






// Need to run the object to perform this operation

OLE_E_NOTRUNNING                 _HRESULT_TYPEDEF_(0x80040005L)






// There is no cache to operate on

OLE_E_NOCACHE                    _HRESULT_TYPEDEF_(0x80040006L)






// Uninitialized object

OLE_E_BLANK                      _HRESULT_TYPEDEF_(0x80040007L)






// Linked object's source class has changed

OLE_E_CLASSDIFF                  _HRESULT_TYPEDEF_(0x80040008L)






// Not able to get the moniker of the object

OLE_E_CANT_GETMONIKER            _HRESULT_TYPEDEF_(0x80040009L)






// Not able to bind to the source

OLE_E_CANT_BINDTOSOURCE          _HRESULT_TYPEDEF_(0x8004000AL)






// Object is static; operation not allowed

OLE_E_STATIC                     _HRESULT_TYPEDEF_(0x8004000BL)






// User canceled out of save dialog

OLE_E_PROMPTSAVECANCELLED        _HRESULT_TYPEDEF_(0x8004000CL)






// Invalid rectangle

OLE_E_INVALIDRECT                _HRESULT_TYPEDEF_(0x8004000DL)






// compobj.dll is too old for the ole2.dll initialized

OLE_E_WRONGCOMPOBJ               _HRESULT_TYPEDEF_(0x8004000EL)






// Invalid window handle

OLE_E_INVALIDHWND                _HRESULT_TYPEDEF_(0x8004000FL)






// Object is not in any of the inplace active states

OLE_E_NOT_INPLACEACTIVE          _HRESULT_TYPEDEF_(0x80040010L)






// Not able to convert object

OLE_E_CANTCONVERT                _HRESULT_TYPEDEF_(0x80040011L)






// Not able to perform the operation because object is not given storage yet

OLE_E_NOSTORAGE                  _HRESULT_TYPEDEF_(0x80040012L)






// Invalid FORMATETC structure

DV_E_FORMATETC                   _HRESULT_TYPEDEF_(0x80040064L)






// Invalid DVTARGETDEVICE structure

DV_E_DVTARGETDEVICE              _HRESULT_TYPEDEF_(0x80040065L)






// Invalid STDGMEDIUM structure

DV_E_STGMEDIUM                   _HRESULT_TYPEDEF_(0x80040066L)






// Invalid STATDATA structure

DV_E_STATDATA                    _HRESULT_TYPEDEF_(0x80040067L)






// Invalid lindex

DV_E_LINDEX                      _HRESULT_TYPEDEF_(0x80040068L)






// Invalid tymed

DV_E_TYMED                       _HRESULT_TYPEDEF_(0x80040069L)






// Invalid clipboard format

DV_E_CLIPFORMAT                  _HRESULT_TYPEDEF_(0x8004006AL)






// Invalid aspect(s)

DV_E_DVASPECT                    _HRESULT_TYPEDEF_(0x8004006BL)






// tdSize parameter of the DVTARGETDEVICE structure is invalid

DV_E_DVTARGETDEVICE_SIZE         _HRESULT_TYPEDEF_(0x8004006CL)






// Object doesn't support IViewObject interface

DV_E_NOIVIEWOBJECT               _HRESULT_TYPEDEF_(0x8004006DL)

DRAGDROP_E_FIRST 0x80040100L
DRAGDROP_E_LAST  0x8004010FL
DRAGDROP_S_FIRST 0x00040100L
DRAGDROP_S_LAST  0x0004010FL





// Trying to revoke a drop target that has not been registered

DRAGDROP_E_NOTREGISTERED         _HRESULT_TYPEDEF_(0x80040100L)






// This window has already been registered as a drop target

DRAGDROP_E_ALREADYREGISTERED     _HRESULT_TYPEDEF_(0x80040101L)






// Invalid window handle

DRAGDROP_E_INVALIDHWND           _HRESULT_TYPEDEF_(0x80040102L)






// A drag operation is already in progress

DRAGDROP_E_CONCURRENT_DRAG_ATTEMPTED _HRESULT_TYPEDEF_(0x80040103L)

CLASSFACTORY_E_FIRST  0x80040110L
CLASSFACTORY_E_LAST   0x8004011FL
CLASSFACTORY_S_FIRST  0x00040110L
CLASSFACTORY_S_LAST   0x0004011FL





// Class does not support aggregation (or class object is remote)

CLASS_E_NOAGGREGATION            _HRESULT_TYPEDEF_(0x80040110L)






// ClassFactory cannot supply requested class

CLASS_E_CLASSNOTAVAILABLE        _HRESULT_TYPEDEF_(0x80040111L)






// Class is not licensed for use

CLASS_E_NOTLICENSED              _HRESULT_TYPEDEF_(0x80040112L)

MARSHAL_E_FIRST  0x80040120L
MARSHAL_E_LAST   0x8004012FL
MARSHAL_S_FIRST  0x00040120L
MARSHAL_S_LAST   0x0004012FL
DATA_E_FIRST     0x80040130L
DATA_E_LAST      0x8004013FL
DATA_S_FIRST     0x00040130L
DATA_S_LAST      0x0004013FL
VIEW_E_FIRST     0x80040140L
VIEW_E_LAST      0x8004014FL
VIEW_S_FIRST     0x00040140L
VIEW_S_LAST      0x0004014FL





// Error drawing view

VIEW_E_DRAW                      _HRESULT_TYPEDEF_(0x80040140L)

REGDB_E_FIRST     0x80040150L
REGDB_E_LAST      0x8004015FL
REGDB_S_FIRST     0x00040150L
REGDB_S_LAST      0x0004015FL





// Could not read key from registry

REGDB_E_READREGDB                _HRESULT_TYPEDEF_(0x80040150L)






// Could not write key to registry

REGDB_E_WRITEREGDB               _HRESULT_TYPEDEF_(0x80040151L)






// Could not find the key in the registry

REGDB_E_KEYMISSING               _HRESULT_TYPEDEF_(0x80040152L)






// Invalid value for registry

REGDB_E_INVALIDVALUE             _HRESULT_TYPEDEF_(0x80040153L)






// Class not registered

REGDB_E_CLASSNOTREG              _HRESULT_TYPEDEF_(0x80040154L)






// Interface not registered

REGDB_E_IIDNOTREG                _HRESULT_TYPEDEF_(0x80040155L)






// Threading model entry is not valid

REGDB_E_BADTHREADINGMODEL        _HRESULT_TYPEDEF_(0x80040156L)






// A registration in a package violates package-specific policies

REGDB_E_PACKAGEPOLICYVIOLATION   _HRESULT_TYPEDEF_(0x80040157L)

CAT_E_FIRST     0x80040160L
CAT_E_LAST      0x80040161L





// CATID does not exist

CAT_E_CATIDNOEXIST               _HRESULT_TYPEDEF_(0x80040160L)






// Description not found

CAT_E_NODESCRIPTION              _HRESULT_TYPEDEF_(0x80040161L)

////////////////////////////////////
//                                //
//     Class Store Error Codes    //
//                                //
////////////////////////////////////
CS_E_FIRST     0x80040164L
CS_E_LAST      0x8004016FL





// No package in the software installation data in the Active Directory meets this criteria.

CS_E_PACKAGE_NOTFOUND            _HRESULT_TYPEDEF_(0x80040164L)






// Deleting this will break the referential integrity of the software installation data in the Active Directory.

CS_E_NOT_DELETABLE               _HRESULT_TYPEDEF_(0x80040165L)






// The CLSID was not found in the software installation data in the Active Directory.

CS_E_CLASS_NOTFOUND              _HRESULT_TYPEDEF_(0x80040166L)






// The software installation data in the Active Directory is corrupt.

CS_E_INVALID_VERSION             _HRESULT_TYPEDEF_(0x80040167L)






// There is no software installation data in the Active Directory.

CS_E_NO_CLASSSTORE               _HRESULT_TYPEDEF_(0x80040168L)






// There is no software installation data object in the Active Directory.

CS_E_OBJECT_NOTFOUND             _HRESULT_TYPEDEF_(0x80040169L)






// The software installation data object in the Active Directory already exists.

CS_E_OBJECT_ALREADY_EXISTS       _HRESULT_TYPEDEF_(0x8004016AL)






// The path to the software installation data in the Active Directory is not correct.

CS_E_INVALID_PATH                _HRESULT_TYPEDEF_(0x8004016BL)






// A network error interrupted the operation.

CS_E_NETWORK_ERROR               _HRESULT_TYPEDEF_(0x8004016CL)






// The size of this object exceeds the maximum size set by the Administrator.

CS_E_ADMIN_LIMIT_EXCEEDED        _HRESULT_TYPEDEF_(0x8004016DL)






// The schema for the software installation data in the Active Directory does not match the required schema.

CS_E_SCHEMA_MISMATCH             _HRESULT_TYPEDEF_(0x8004016EL)






// An error occurred in the software installation data in the Active Directory.

CS_E_INTERNAL_ERROR              _HRESULT_TYPEDEF_(0x8004016FL)

CACHE_E_FIRST     0x80040170L
CACHE_E_LAST      0x8004017FL
CACHE_S_FIRST     0x00040170L
CACHE_S_LAST      0x0004017FL





// Cache not updated

CACHE_E_NOCACHE_UPDATED          _HRESULT_TYPEDEF_(0x80040170L)

OLEOBJ_E_FIRST     0x80040180L
OLEOBJ_E_LAST      0x8004018FL
OLEOBJ_S_FIRST     0x00040180L
OLEOBJ_S_LAST      0x0004018FL





// No verbs for OLE object

OLEOBJ_E_NOVERBS                 _HRESULT_TYPEDEF_(0x80040180L)






// Invalid verb for OLE object

OLEOBJ_E_INVALIDVERB             _HRESULT_TYPEDEF_(0x80040181L)

CLIENTSITE_E_FIRST     0x80040190L
CLIENTSITE_E_LAST      0x8004019FL
CLIENTSITE_S_FIRST     0x00040190L
CLIENTSITE_S_LAST      0x0004019FL





// Undo is not available

INPLACE_E_NOTUNDOABLE            _HRESULT_TYPEDEF_(0x800401A0L)






// Space for tools is not available

INPLACE_E_NOTOOLSPACE            _HRESULT_TYPEDEF_(0x800401A1L)

INPLACE_E_FIRST     0x800401A0L
INPLACE_E_LAST      0x800401AFL
INPLACE_S_FIRST     0x000401A0L
INPLACE_S_LAST      0x000401AFL
ENUM_E_FIRST        0x800401B0L
ENUM_E_LAST         0x800401BFL
ENUM_S_FIRST        0x000401B0L
ENUM_S_LAST         0x000401BFL
CONVERT10_E_FIRST        0x800401C0L
CONVERT10_E_LAST         0x800401CFL
CONVERT10_S_FIRST        0x000401C0L
CONVERT10_S_LAST         0x000401CFL





// OLESTREAM Get method failed

CONVERT10_E_OLESTREAM_GET        _HRESULT_TYPEDEF_(0x800401C0L)






// OLESTREAM Put method failed

CONVERT10_E_OLESTREAM_PUT        _HRESULT_TYPEDEF_(0x800401C1L)






// Contents of the OLESTREAM not in correct format

CONVERT10_E_OLESTREAM_FMT        _HRESULT_TYPEDEF_(0x800401C2L)






// There was an error in a Windows GDI call while converting the bitmap to a DIB

CONVERT10_E_OLESTREAM_BITMAP_TO_DIB _HRESULT_TYPEDEF_(0x800401C3L)






// Contents of the IStorage not in correct format

CONVERT10_E_STG_FMT              _HRESULT_TYPEDEF_(0x800401C4L)






// Contents of IStorage is missing one of the standard streams

CONVERT10_E_STG_NO_STD_STREAM    _HRESULT_TYPEDEF_(0x800401C5L)






// There was an error in a Windows GDI call while converting the DIB to a bitmap.

CONVERT10_E_STG_DIB_TO_BITMAP    _HRESULT_TYPEDEF_(0x800401C6L)

CLIPBRD_E_FIRST        0x800401D0L
CLIPBRD_E_LAST         0x800401DFL
CLIPBRD_S_FIRST        0x000401D0L
CLIPBRD_S_LAST         0x000401DFL





// OpenClipboard Failed

CLIPBRD_E_CANT_OPEN              _HRESULT_TYPEDEF_(0x800401D0L)






// EmptyClipboard Failed

CLIPBRD_E_CANT_EMPTY             _HRESULT_TYPEDEF_(0x800401D1L)






// SetClipboard Failed

CLIPBRD_E_CANT_SET               _HRESULT_TYPEDEF_(0x800401D2L)






// Data on clipboard is invalid

CLIPBRD_E_BAD_DATA               _HRESULT_TYPEDEF_(0x800401D3L)






// CloseClipboard Failed

CLIPBRD_E_CANT_CLOSE             _HRESULT_TYPEDEF_(0x800401D4L)

MK_E_FIRST        0x800401E0L
MK_E_LAST         0x800401EFL
MK_S_FIRST        0x000401E0L
MK_S_LAST         0x000401EFL





// Moniker needs to be connected manually

MK_E_CONNECTMANUALLY             _HRESULT_TYPEDEF_(0x800401E0L)






// Operation exceeded deadline

MK_E_EXCEEDEDDEADLINE            _HRESULT_TYPEDEF_(0x800401E1L)






// Moniker needs to be generic

MK_E_NEEDGENERIC                 _HRESULT_TYPEDEF_(0x800401E2L)






// Operation unavailable

MK_E_UNAVAILABLE                 _HRESULT_TYPEDEF_(0x800401E3L)






// Invalid syntax

MK_E_SYNTAX                      _HRESULT_TYPEDEF_(0x800401E4L)






// No object for moniker

MK_E_NOOBJECT                    _HRESULT_TYPEDEF_(0x800401E5L)






// Bad extension for file

MK_E_INVALIDEXTENSION            _HRESULT_TYPEDEF_(0x800401E6L)






// Intermediate operation failed

MK_E_INTERMEDIATEINTERFACENOTSUPPORTED _HRESULT_TYPEDEF_(0x800401E7L)






// Moniker is not bindable

MK_E_NOTBINDABLE                 _HRESULT_TYPEDEF_(0x800401E8L)






// Moniker is not bound

MK_E_NOTBOUND                    _HRESULT_TYPEDEF_(0x800401E9L)






// Moniker cannot open file

MK_E_CANTOPENFILE                _HRESULT_TYPEDEF_(0x800401EAL)






// User input required for operation to succeed

MK_E_MUSTBOTHERUSER              _HRESULT_TYPEDEF_(0x800401EBL)






// Moniker class has no inverse

MK_E_NOINVERSE                   _HRESULT_TYPEDEF_(0x800401ECL)






// Moniker does not refer to storage

MK_E_NOSTORAGE                   _HRESULT_TYPEDEF_(0x800401EDL)






// No common prefix

MK_E_NOPREFIX                    _HRESULT_TYPEDEF_(0x800401EEL)






// Moniker could not be enumerated

MK_E_ENUMERATION_FAILED          _HRESULT_TYPEDEF_(0x800401EFL)

CO_E_FIRST        0x800401F0L
CO_E_LAST         0x800401FFL
CO_S_FIRST        0x000401F0L
CO_S_LAST         0x000401FFL





// CoInitialize has not been called.

CO_E_NOTINITIALIZED              _HRESULT_TYPEDEF_(0x800401F0L)






// CoInitialize has already been called.

CO_E_ALREADYINITIALIZED          _HRESULT_TYPEDEF_(0x800401F1L)






// Class of object cannot be determined

CO_E_CANTDETERMINECLASS          _HRESULT_TYPEDEF_(0x800401F2L)






// Invalid class string

CO_E_CLASSSTRING                 _HRESULT_TYPEDEF_(0x800401F3L)






// Invalid interface string

CO_E_IIDSTRING                   _HRESULT_TYPEDEF_(0x800401F4L)






// Application not found

CO_E_APPNOTFOUND                 _HRESULT_TYPEDEF_(0x800401F5L)






// Application cannot be run more than once

CO_E_APPSINGLEUSE                _HRESULT_TYPEDEF_(0x800401F6L)






// Some error in application program

CO_E_ERRORINAPP                  _HRESULT_TYPEDEF_(0x800401F7L)






// DLL for class not found

CO_E_DLLNOTFOUND                 _HRESULT_TYPEDEF_(0x800401F8L)






// Error in the DLL

CO_E_ERRORINDLL                  _HRESULT_TYPEDEF_(0x800401F9L)






// Wrong OS or OS version for application

CO_E_WRONGOSFORAPP               _HRESULT_TYPEDEF_(0x800401FAL)






// Object is not registered

CO_E_OBJNOTREG                   _HRESULT_TYPEDEF_(0x800401FBL)






// Object is already registered

CO_E_OBJISREG                    _HRESULT_TYPEDEF_(0x800401FCL)






// Object is not connected to server

CO_E_OBJNOTCONNECTED             _HRESULT_TYPEDEF_(0x800401FDL)






// Application was launched but it didn't register a class factory

CO_E_APPDIDNTREG                 _HRESULT_TYPEDEF_(0x800401FEL)






// Object has been released

CO_E_RELEASED                    _HRESULT_TYPEDEF_(0x800401FFL)

EVENT_E_FIRST        0x80040200L
EVENT_E_LAST         0x8004021FL
EVENT_S_FIRST        0x00040200L
EVENT_S_LAST         0x0004021FL





// An event was able to invoke some but not all of the subscribers

EVENT_S_SOME_SUBSCRIBERS_FAILED  _HRESULT_TYPEDEF_(0x00040200L)






// An event was unable to invoke any of the subscribers

EVENT_E_ALL_SUBSCRIBERS_FAILED   _HRESULT_TYPEDEF_(0x80040201L)






// An event was delivered but there were no subscribers

EVENT_S_NOSUBSCRIBERS            _HRESULT_TYPEDEF_(0x00040202L)






// A syntax error occurred trying to evaluate a query string

EVENT_E_QUERYSYNTAX              _HRESULT_TYPEDEF_(0x80040203L)






// An invalid field name was used in a query string

EVENT_E_QUERYFIELD               _HRESULT_TYPEDEF_(0x80040204L)






// An unexpected exception was raised

EVENT_E_INTERNALEXCEPTION        _HRESULT_TYPEDEF_(0x80040205L)






// An unexpected internal error was detected

EVENT_E_INTERNALERROR            _HRESULT_TYPEDEF_(0x80040206L)






// The owner SID on a per-user subscription doesn't exist

EVENT_E_INVALID_PER_USER_SID     _HRESULT_TYPEDEF_(0x80040207L)






// A user-supplied component or subscriber raised an exception

EVENT_E_USER_EXCEPTION           _HRESULT_TYPEDEF_(0x80040208L)






// An interface has too many methods to fire events from

EVENT_E_TOO_MANY_METHODS         _HRESULT_TYPEDEF_(0x80040209L)






// A subscription cannot be stored unless its event class already exists

EVENT_E_MISSING_EVENTCLASS       _HRESULT_TYPEDEF_(0x8004020AL)






// Not all the objects requested could be removed

EVENT_E_NOT_ALL_REMOVED          _HRESULT_TYPEDEF_(0x8004020BL)






// COM+ is required for this operation, but is not installed

EVENT_E_COMPLUS_NOT_INSTALLED    _HRESULT_TYPEDEF_(0x8004020CL)






// Cannot modify or delete an object that was not added using the COM+ Admin SDK

EVENT_E_CANT_MODIFY_OR_DELETE_UNCONFIGURED_OBJECT _HRESULT_TYPEDEF_(0x8004020DL)






// Cannot modify or delete an object that was added using the COM+ Admin SDK

EVENT_E_CANT_MODIFY_OR_DELETE_CONFIGURED_OBJECT _HRESULT_TYPEDEF_(0x8004020EL)






// The event class for this subscription is in an invalid partition

EVENT_E_INVALID_EVENT_CLASS_PARTITION _HRESULT_TYPEDEF_(0x8004020FL)






// The owner of the PerUser subscription is not logged on to the system specified

EVENT_E_PER_USER_SID_NOT_LOGGED_ON _HRESULT_TYPEDEF_(0x80040210L)






// TabletPC inking error code. The property was not found, or supported by the recognizer

TPC_E_INVALID_PROPERTY           _HRESULT_TYPEDEF_(0x80040241L)






// TabletPC inking error code. No default tablet

TPC_E_NO_DEFAULT_TABLET          _HRESULT_TYPEDEF_(0x80040212L)






// TabletPC inking error code. Unknown property specified

TPC_E_UNKNOWN_PROPERTY           _HRESULT_TYPEDEF_(0x8004021BL)






// TabletPC inking error code. An invalid input rectangle was specified

TPC_E_INVALID_INPUT_RECT         _HRESULT_TYPEDEF_(0x80040219L)






// TabletPC inking error code. The stroke object was deleted

TPC_E_INVALID_STROKE             _HRESULT_TYPEDEF_(0x80040222L)






// TabletPC inking error code. Initialization failure

TPC_E_INITIALIZE_FAIL            _HRESULT_TYPEDEF_(0x80040223L)






// TabletPC inking error code. The data required for the operation was not supplied

TPC_E_NOT_RELEVANT               _HRESULT_TYPEDEF_(0x80040232L)






// TabletPC inking error code. Invalid packet description

TPC_E_INVALID_PACKET_DESCRIPTION _HRESULT_TYPEDEF_(0x80040233L)






// TabletPC inking error code. There are no handwriting recognizers registered

TPC_E_RECOGNIZER_NOT_REGISTERED  _HRESULT_TYPEDEF_(0x80040235L)






// TabletPC inking error code. User does not have the necessary rights to read recognizer information

TPC_E_INVALID_RIGHTS             _HRESULT_TYPEDEF_(0x80040236L)






// TabletPC inking error code. API calls were made in an incorrect order

TPC_E_OUT_OF_ORDER_CALL          _HRESULT_TYPEDEF_(0x80040237L)






// TabletPC inking error code. Queue is full

TPC_E_QUEUE_FULL                 _HRESULT_TYPEDEF_(0x80040238L)






// TabletPC inking error code. RtpEnabled called multiple times

TPC_E_INVALID_CONFIGURATION      _HRESULT_TYPEDEF_(0x80040239L)






// TabletPC inking error code. A recognizer returned invalid data

TPC_E_INVALID_DATA_FROM_RECOGNIZER _HRESULT_TYPEDEF_(0x8004023AL)






// TabletPC inking error code. String was truncated

TPC_S_TRUNCATED                  _HRESULT_TYPEDEF_(0x00040252L)






// TabletPC inking error code. Recognition or training was interrupted

TPC_S_INTERRUPTED                _HRESULT_TYPEDEF_(0x00040253L)






// TabletPC inking error code. No personalization update to the recognizer because no training data found

TPC_S_NO_DATA_TO_PROCESS         _HRESULT_TYPEDEF_(0x00040254L)

XACT_E_FIRST   0x8004D000
XACT_E_LAST    0x8004D02B
XACT_S_FIRST   0x0004D000
XACT_S_LAST    0x0004D010





// Another single phase resource manager has already been enlisted in this transaction.

XACT_E_ALREADYOTHERSINGLEPHASE   _HRESULT_TYPEDEF_(0x8004D000L)






// A retaining commit or abort is not supported

XACT_E_CANTRETAIN                _HRESULT_TYPEDEF_(0x8004D001L)






// The transaction failed to commit for an unknown reason. The transaction was aborted.

XACT_E_COMMITFAILED              _HRESULT_TYPEDEF_(0x8004D002L)






// Cannot call commit on this transaction object because the calling application did not initiate the transaction.

XACT_E_COMMITPREVENTED           _HRESULT_TYPEDEF_(0x8004D003L)






// Instead of committing, the resource heuristically aborted.

XACT_E_HEURISTICABORT            _HRESULT_TYPEDEF_(0x8004D004L)






// Instead of aborting, the resource heuristically committed.

XACT_E_HEURISTICCOMMIT           _HRESULT_TYPEDEF_(0x8004D005L)






// Some of the states of the resource were committed while others were aborted, likely because of heuristic decisions.

XACT_E_HEURISTICDAMAGE           _HRESULT_TYPEDEF_(0x8004D006L)






// Some of the states of the resource may have been committed while others may have been aborted, likely because of heuristic decisions.

XACT_E_HEURISTICDANGER           _HRESULT_TYPEDEF_(0x8004D007L)






// The requested isolation level is not valid or supported.

XACT_E_ISOLATIONLEVEL            _HRESULT_TYPEDEF_(0x8004D008L)






// The transaction manager doesn't support an asynchronous operation for this method.

XACT_E_NOASYNC                   _HRESULT_TYPEDEF_(0x8004D009L)






// Unable to enlist in the transaction.

XACT_E_NOENLIST                  _HRESULT_TYPEDEF_(0x8004D00AL)






// The requested semantics of retention of isolation across retaining commit and abort boundaries cannot be supported by this transaction implementation, or isoFlags was not equal to zero.

XACT_E_NOISORETAIN               _HRESULT_TYPEDEF_(0x8004D00BL)






// There is no resource presently associated with this enlistment

XACT_E_NORESOURCE                _HRESULT_TYPEDEF_(0x8004D00CL)






// The transaction failed to commit due to the failure of optimistic concurrency control in at least one of the resource managers.

XACT_E_NOTCURRENT                _HRESULT_TYPEDEF_(0x8004D00DL)






// The transaction has already been implicitly or explicitly committed or aborted

XACT_E_NOTRANSACTION             _HRESULT_TYPEDEF_(0x8004D00EL)






// An invalid combination of flags was specified

XACT_E_NOTSUPPORTED              _HRESULT_TYPEDEF_(0x8004D00FL)






// The resource manager id is not associated with this transaction or the transaction manager.

XACT_E_UNKNOWNRMGRID             _HRESULT_TYPEDEF_(0x8004D010L)






// This method was called in the wrong state

XACT_E_WRONGSTATE                _HRESULT_TYPEDEF_(0x8004D011L)






// The indicated unit of work does not match the unit of work expected by the resource manager.

XACT_E_WRONGUOW                  _HRESULT_TYPEDEF_(0x8004D012L)






// An enlistment in a transaction already exists.

XACT_E_XTIONEXISTS               _HRESULT_TYPEDEF_(0x8004D013L)






// An import object for the transaction could not be found.

XACT_E_NOIMPORTOBJECT            _HRESULT_TYPEDEF_(0x8004D014L)






// The transaction cookie is invalid.

XACT_E_INVALIDCOOKIE             _HRESULT_TYPEDEF_(0x8004D015L)






// The transaction status is in doubt. A communication failure occurred, or a transaction manager or resource manager has failed

XACT_E_INDOUBT                   _HRESULT_TYPEDEF_(0x8004D016L)






// A time-out was specified, but time-outs are not supported.

XACT_E_NOTIMEOUT                 _HRESULT_TYPEDEF_(0x8004D017L)






// The requested operation is already in progress for the transaction.

XACT_E_ALREADYINPROGRESS         _HRESULT_TYPEDEF_(0x8004D018L)






// The transaction has already been aborted.

XACT_E_ABORTED                   _HRESULT_TYPEDEF_(0x8004D019L)






// The Transaction Manager returned a log full error.

XACT_E_LOGFULL                   _HRESULT_TYPEDEF_(0x8004D01AL)






// The Transaction Manager is not available.

XACT_E_TMNOTAVAILABLE            _HRESULT_TYPEDEF_(0x8004D01BL)






// A connection with the transaction manager was lost.

XACT_E_CONNECTION_DOWN           _HRESULT_TYPEDEF_(0x8004D01CL)






// A request to establish a connection with the transaction manager was denied.

XACT_E_CONNECTION_DENIED         _HRESULT_TYPEDEF_(0x8004D01DL)






// Resource manager reenlistment to determine transaction status timed out.

XACT_E_REENLISTTIMEOUT           _HRESULT_TYPEDEF_(0x8004D01EL)






// This transaction manager failed to establish a connection with another TIP transaction manager.

XACT_E_TIP_CONNECT_FAILED        _HRESULT_TYPEDEF_(0x8004D01FL)






// This transaction manager encountered a protocol error with another TIP transaction manager.

XACT_E_TIP_PROTOCOL_ERROR        _HRESULT_TYPEDEF_(0x8004D020L)






// This transaction manager could not propagate a transaction from another TIP transaction manager.

XACT_E_TIP_PULL_FAILED           _HRESULT_TYPEDEF_(0x8004D021L)






// The Transaction Manager on the destination machine is not available.

XACT_E_DEST_TMNOTAVAILABLE       _HRESULT_TYPEDEF_(0x8004D022L)






// The Transaction Manager has disabled its support for TIP.

XACT_E_TIP_DISABLED              _HRESULT_TYPEDEF_(0x8004D023L)






// The transaction manager has disabled its support for remote/network transactions.

XACT_E_NETWORK_TX_DISABLED       _HRESULT_TYPEDEF_(0x8004D024L)






// The partner transaction manager has disabled its support for remote/network transactions.

XACT_E_PARTNER_NETWORK_TX_DISABLED _HRESULT_TYPEDEF_(0x8004D025L)






// The transaction manager has disabled its support for XA transactions.

XACT_E_XA_TX_DISABLED            _HRESULT_TYPEDEF_(0x8004D026L)






// MSDTC was unable to read its configuration information.

XACT_E_UNABLE_TO_READ_DTC_CONFIG _HRESULT_TYPEDEF_(0x8004D027L)






// MSDTC was unable to load the dtc proxy dll.

XACT_E_UNABLE_TO_LOAD_DTC_PROXY  _HRESULT_TYPEDEF_(0x8004D028L)






// The local transaction has aborted.

XACT_E_ABORTING                  _HRESULT_TYPEDEF_(0x8004D029L)






// The MSDTC transaction manager was unable to push the transaction to the destination transaction manager due to communication problems. Possible causes are: a firewall is present and it doesn't have an exception for the MSDTC process, the two machines cannot find each other by their NetBIOS names, or the support for network transactions is not enabled for one of the two transaction managers.

XACT_E_PUSH_COMM_FAILURE         _HRESULT_TYPEDEF_(0x8004D02AL)






// The MSDTC transaction manager was unable to pull the transaction from the source transaction manager due to communication problems. Possible causes are: a firewall is present and it doesn't have an exception for the MSDTC process, the two machines cannot find each other by their NetBIOS names, or the support for network transactions is not enabled for one of the two transaction managers.

XACT_E_PULL_COMM_FAILURE         _HRESULT_TYPEDEF_(0x8004D02BL)






// The MSDTC transaction manager has disabled its support for SNA LU 6.2 transactions.

XACT_E_LU_TX_DISABLED            _HRESULT_TYPEDEF_(0x8004D02CL)


// TXF & CRM errors start 4d080.





//  XACT_E_CLERKNOTFOUND

XACT_E_CLERKNOTFOUND             _HRESULT_TYPEDEF_(0x8004D080L)






//  XACT_E_CLERKEXISTS

XACT_E_CLERKEXISTS               _HRESULT_TYPEDEF_(0x8004D081L)






//  XACT_E_RECOVERYINPROGRESS

XACT_E_RECOVERYINPROGRESS        _HRESULT_TYPEDEF_(0x8004D082L)






//  XACT_E_TRANSACTIONCLOSED

XACT_E_TRANSACTIONCLOSED         _HRESULT_TYPEDEF_(0x8004D083L)






//  XACT_E_INVALIDLSN

XACT_E_INVALIDLSN                _HRESULT_TYPEDEF_(0x8004D084L)






//  XACT_E_REPLAYREQUEST

XACT_E_REPLAYREQUEST             _HRESULT_TYPEDEF_(0x8004D085L)

// Begin XACT_DTC_CONSTANTS enumerated values defined in txdtc.h

// SymbolicName=XACT_E_CONNECTION_REQUEST_DENIED





// The request to connect to the specified transaction coordinator was denied.



// SymbolicName=XACT_E_TOOMANY_ENLISTMENTS





// The maximum number of enlistments for the specified transaction has been reached.



// SymbolicName=XACT_E_DUPLICATE_GUID





// A resource manager with the same identifier is already registered with the specified transaction coordinator.



// SymbolicName=XACT_E_NOTSINGLEPHASE





// The prepare request given was not eligible for single phase optimizations.



// SymbolicName=XACT_E_RECOVERYALREADYDONE





// RecoveryComplete has already been called for the given resource manager.



// SymbolicName=XACT_E_PROTOCOL





// The interface call made was incorrect for the current state of the protocol.



// SymbolicName=XACT_E_RM_FAILURE





// xa_open call failed for the XA resource.



// SymbolicName=XACT_E_RECOVERY_FAILED





// xa_recover call failed for the XA resource.



// SymbolicName=XACT_E_LU_NOT_FOUND





// The Logical Unit of Work specified cannot be found.



// SymbolicName=XACT_E_DUPLICATE_LU





// The specified Logical Unit of Work already exists.



// SymbolicName=XACT_E_LU_NOT_CONNECTED





// Subordinate creation failed. The specified Logical Unit of Work was not connected.



// SymbolicName=XACT_E_DUPLICATE_TRANSID





// A transaction with the given identifier already exists.



// SymbolicName=XACT_E_LU_BUSY





// The resource is in use.



// SymbolicName=XACT_E_LU_NO_RECOVERY_PROCESS





// The LU Recovery process is down.



// SymbolicName=XACT_E_LU_DOWN





// The remote session was lost.



// SymbolicName=XACT_E_LU_RECOVERING





// The resource is currently recovering.



// SymbolicName=XACT_E_LU_RECOVERY_MISMATCH





// There was a mismatch in driving recovery.



// SymbolicName=XACT_E_RM_UNAVAILABLE





// An error occurred with the XA resource.



// End XACT_DTC_CONSTANTS enumerated values defined in txdtc.h


// OleTx Success codes.






// An asynchronous operation was specified. The operation has begun, but its outcome is not known yet.

XACT_S_ASYNC                     _HRESULT_TYPEDEF_(0x0004D000L)






//  XACT_S_DEFECT

XACT_S_DEFECT                    _HRESULT_TYPEDEF_(0x0004D001L)






// The method call succeeded because the transaction was read-only.

XACT_S_READONLY                  _HRESULT_TYPEDEF_(0x0004D002L)






// The transaction was successfully aborted. However, this is a coordinated transaction, and some number of enlisted resources were aborted outright because they could not support abort-retaining semantics

XACT_S_SOMENORETAIN              _HRESULT_TYPEDEF_(0x0004D003L)






// No changes were made during this call, but the sink wants another chance to look if any other sinks make further changes.

XACT_S_OKINFORM                  _HRESULT_TYPEDEF_(0x0004D004L)






// The sink is content and wishes the transaction to proceed. Changes were made to one or more resources during this call.

XACT_S_MADECHANGESCONTENT        _HRESULT_TYPEDEF_(0x0004D005L)






// The sink is for the moment and wishes the transaction to proceed, but if other changes are made following this return by other event sinks then this sink wants another chance to look

XACT_S_MADECHANGESINFORM         _HRESULT_TYPEDEF_(0x0004D006L)






// The transaction was successfully aborted. However, the abort was non-retaining.

XACT_S_ALLNORETAIN               _HRESULT_TYPEDEF_(0x0004D007L)






// An abort operation was already in progress.

XACT_S_ABORTING                  _HRESULT_TYPEDEF_(0x0004D008L)






// The resource manager has performed a single-phase commit of the transaction.

XACT_S_SINGLEPHASE               _HRESULT_TYPEDEF_(0x0004D009L)






// The local transaction has not aborted.

XACT_S_LOCALLY_OK                _HRESULT_TYPEDEF_(0x0004D00AL)






// The resource manager has requested to be the coordinator (last resource manager) for the transaction.

XACT_S_LASTRESOURCEMANAGER       _HRESULT_TYPEDEF_(0x0004D010L)

CONTEXT_E_FIRST        0x8004E000L
CONTEXT_E_LAST         0x8004E02FL
CONTEXT_S_FIRST        0x0004E000L
CONTEXT_S_LAST         0x0004E02FL





// The root transaction wanted to commit, but transaction aborted

CONTEXT_E_ABORTED                _HRESULT_TYPEDEF_(0x8004E002L)






// You made a method call on a COM+ component that has a transaction that has already aborted or in the process of aborting.

CONTEXT_E_ABORTING               _HRESULT_TYPEDEF_(0x8004E003L)






// There is no MTS object context

CONTEXT_E_NOCONTEXT              _HRESULT_TYPEDEF_(0x8004E004L)






// The component is configured to use synchronization and this method call would cause a deadlock to occur.

CONTEXT_E_WOULD_DEADLOCK         _HRESULT_TYPEDEF_(0x8004E005L)






// The component is configured to use synchronization and a thread has timed out waiting to enter the context.

CONTEXT_E_SYNCH_TIMEOUT          _HRESULT_TYPEDEF_(0x8004E006L)






// You made a method call on a COM+ component that has a transaction that has already committed or aborted.

CONTEXT_E_OLDREF                 _HRESULT_TYPEDEF_(0x8004E007L)






// The specified role was not configured for the application

CONTEXT_E_ROLENOTFOUND           _HRESULT_TYPEDEF_(0x8004E00CL)






// COM+ was unable to talk to the Microsoft Distributed Transaction Coordinator

CONTEXT_E_TMNOTAVAILABLE         _HRESULT_TYPEDEF_(0x8004E00FL)






// An unexpected error occurred during COM+ Activation.

CO_E_ACTIVATIONFAILED            _HRESULT_TYPEDEF_(0x8004E021L)






// COM+ Activation failed. Check the event log for more information

CO_E_ACTIVATIONFAILED_EVENTLOGGED _HRESULT_TYPEDEF_(0x8004E022L)






// COM+ Activation failed due to a catalog or configuration error.

CO_E_ACTIVATIONFAILED_CATALOGERROR _HRESULT_TYPEDEF_(0x8004E023L)






// COM+ activation failed because the activation could not be completed in the specified amount of time.

CO_E_ACTIVATIONFAILED_TIMEOUT    _HRESULT_TYPEDEF_(0x8004E024L)






// COM+ Activation failed because an initialization function failed. Check the event log for more information.

CO_E_INITIALIZATIONFAILED        _HRESULT_TYPEDEF_(0x8004E025L)






// The requested operation requires that JIT be in the current context and it is not

CONTEXT_E_NOJIT                  _HRESULT_TYPEDEF_(0x8004E026L)






// The requested operation requires that the current context have a Transaction, and it does not

CONTEXT_E_NOTRANSACTION          _HRESULT_TYPEDEF_(0x8004E027L)






// The components threading model has changed after install into a COM+ Application. Please re-install component.

CO_E_THREADINGMODEL_CHANGED      _HRESULT_TYPEDEF_(0x8004E028L)






// IIS intrinsics not available. Start your work with IIS.

CO_E_NOIISINTRINSICS             _HRESULT_TYPEDEF_(0x8004E029L)






// An attempt to write a cookie failed.

CO_E_NOCOOKIES                   _HRESULT_TYPEDEF_(0x8004E02AL)






// An attempt to use a database generated a database specific error.

CO_E_DBERROR                     _HRESULT_TYPEDEF_(0x8004E02BL)






// The COM+ component you created must use object pooling to work.

CO_E_NOTPOOLED                   _HRESULT_TYPEDEF_(0x8004E02CL)






// The COM+ component you created must use object construction to work correctly.

CO_E_NOTCONSTRUCTED              _HRESULT_TYPEDEF_(0x8004E02DL)






// The COM+ component requires synchronization, and it is not configured for it.

CO_E_NOSYNCHRONIZATION           _HRESULT_TYPEDEF_(0x8004E02EL)






// The TxIsolation Level property for the COM+ component being created is stronger than the TxIsolationLevel for the "root" component for the transaction. The creation failed.

CO_E_ISOLEVELMISMATCH            _HRESULT_TYPEDEF_(0x8004E02FL)






// The component attempted to make a cross-context call between invocations of EnterTransactionScopeand ExitTransactionScope. This is not allowed. Cross-context calls cannot be made while inside of a transaction scope.

CO_E_CALL_OUT_OF_TX_SCOPE_NOT_ALLOWED _HRESULT_TYPEDEF_(0x8004E030L)






// The component made a call to EnterTransactionScope, but did not make a corresponding call to ExitTransactionScope before returning.

CO_E_EXIT_TRANSACTION_SCOPE_NOT_CALLED _HRESULT_TYPEDEF_(0x8004E031L)


// Old OLE Success Codes






// Use the registry database to provide the requested information

OLE_S_USEREG                     _HRESULT_TYPEDEF_(0x00040000L)






// Success, but static

OLE_S_STATIC                     _HRESULT_TYPEDEF_(0x00040001L)






// Macintosh clipboard format

OLE_S_MAC_CLIPFORMAT             _HRESULT_TYPEDEF_(0x00040002L)






// Successful drop took place

DRAGDROP_S_DROP                  _HRESULT_TYPEDEF_(0x00040100L)






// Drag-drop operation canceled

DRAGDROP_S_CANCEL                _HRESULT_TYPEDEF_(0x00040101L)






// Use the default cursor

DRAGDROP_S_USEDEFAULTCURSORS     _HRESULT_TYPEDEF_(0x00040102L)






// Data has same FORMATETC

DATA_S_SAMEFORMATETC             _HRESULT_TYPEDEF_(0x00040130L)






// View is already frozen

VIEW_S_ALREADY_FROZEN            _HRESULT_TYPEDEF_(0x00040140L)






// FORMATETC not supported

CACHE_S_FORMATETC_NOTSUPPORTED   _HRESULT_TYPEDEF_(0x00040170L)






// Same cache

CACHE_S_SAMECACHE                _HRESULT_TYPEDEF_(0x00040171L)






// Some cache(s) not updated

CACHE_S_SOMECACHES_NOTUPDATED    _HRESULT_TYPEDEF_(0x00040172L)






// Invalid verb for OLE object

OLEOBJ_S_INVALIDVERB             _HRESULT_TYPEDEF_(0x00040180L)






// Verb number is valid but verb cannot be done now

OLEOBJ_S_CANNOT_DOVERB_NOW       _HRESULT_TYPEDEF_(0x00040181L)






// Invalid window handle passed

OLEOBJ_S_INVALIDHWND             _HRESULT_TYPEDEF_(0x00040182L)








INPLACE_S_TRUNCATED              _HRESULT_TYPEDEF_(0x000401A0L)






// Unable to convert OLESTREAM to IStorage

CONVERT10_S_NO_PRESENTATION      _HRESULT_TYPEDEF_(0x000401C0L)






// Moniker reduced to itself

MK_S_REDUCED_TO_SELF             _HRESULT_TYPEDEF_(0x000401E2L)






// Common prefix is this moniker

MK_S_ME                          _HRESULT_TYPEDEF_(0x000401E4L)






// Common prefix is input moniker

MK_S_HIM                         _HRESULT_TYPEDEF_(0x000401E5L)






// Common prefix is both monikers

MK_S_US                          _HRESULT_TYPEDEF_(0x000401E6L)






// Moniker is already registered in running object table

MK_S_MONIKERALREADYREGISTERED    _HRESULT_TYPEDEF_(0x000401E7L)


// Task Scheduler errors






// The task is ready to run at its next scheduled time.

SCHED_S_TASK_READY               _HRESULT_TYPEDEF_(0x00041300L)






// The task is currently running.

SCHED_S_TASK_RUNNING             _HRESULT_TYPEDEF_(0x00041301L)






// The task will not run at the scheduled times because it has been disabled.

SCHED_S_TASK_DISABLED            _HRESULT_TYPEDEF_(0x00041302L)






// The task has not yet run.

SCHED_S_TASK_HAS_NOT_RUN         _HRESULT_TYPEDEF_(0x00041303L)






// There are no more runs scheduled for this task.

SCHED_S_TASK_NO_MORE_RUNS        _HRESULT_TYPEDEF_(0x00041304L)






// One or more of the properties that are needed to run this task on a schedule have not been set.

SCHED_S_TASK_NOT_SCHEDULED       _HRESULT_TYPEDEF_(0x00041305L)






// The last run of the task was terminated by the user.

SCHED_S_TASK_TERMINATED          _HRESULT_TYPEDEF_(0x00041306L)






// Either the task has no triggers or the existing triggers are disabled or not set.

SCHED_S_TASK_NO_VALID_TRIGGERS   _HRESULT_TYPEDEF_(0x00041307L)






// Event triggers don't have set run times.

SCHED_S_EVENT_TRIGGER            _HRESULT_TYPEDEF_(0x00041308L)






// Trigger not found.

SCHED_E_TRIGGER_NOT_FOUND        _HRESULT_TYPEDEF_(0x80041309L)






// One or more of the properties that are needed to run this task have not been set.

SCHED_E_TASK_NOT_READY           _HRESULT_TYPEDEF_(0x8004130AL)






// There is no running instance of the task.

SCHED_E_TASK_NOT_RUNNING         _HRESULT_TYPEDEF_(0x8004130BL)






// The Task Scheduler Service is not installed on this computer.

SCHED_E_SERVICE_NOT_INSTALLED    _HRESULT_TYPEDEF_(0x8004130CL)






// The task object could not be opened.

SCHED_E_CANNOT_OPEN_TASK         _HRESULT_TYPEDEF_(0x8004130DL)






// The object is either an invalid task object or is not a task object.

SCHED_E_INVALID_TASK             _HRESULT_TYPEDEF_(0x8004130EL)






// No account information could be found in the Task Scheduler security database for the task indicated.

SCHED_E_ACCOUNT_INFORMATION_NOT_SET _HRESULT_TYPEDEF_(0x8004130FL)






// Unable to establish existence of the account specified.

SCHED_E_ACCOUNT_NAME_NOT_FOUND   _HRESULT_TYPEDEF_(0x80041310L)






// Corruption was detected in the Task Scheduler security database; the database has been reset.

SCHED_E_ACCOUNT_DBASE_CORRUPT    _HRESULT_TYPEDEF_(0x80041311L)






// Task Scheduler security services are available only on Windows NT.

SCHED_E_NO_SECURITY_SERVICES     _HRESULT_TYPEDEF_(0x80041312L)






// The task object version is either unsupported or invalid.

SCHED_E_UNKNOWN_OBJECT_VERSION   _HRESULT_TYPEDEF_(0x80041313L)






// The task has been configured with an unsupported combination of account settings and run time options.

SCHED_E_UNSUPPORTED_ACCOUNT_OPTION _HRESULT_TYPEDEF_(0x80041314L)






// The Task Scheduler Service is not running.

SCHED_E_SERVICE_NOT_RUNNING      _HRESULT_TYPEDEF_(0x80041315L)






// The task XML contains an unexpected node.

SCHED_E_UNEXPECTEDNODE           _HRESULT_TYPEDEF_(0x80041316L)






// The task XML contains an element or attribute from an unexpected namespace.

SCHED_E_NAMESPACE                _HRESULT_TYPEDEF_(0x80041317L)






// The task XML contains a value which is incorrectly formatted or out of range.

SCHED_E_INVALIDVALUE             _HRESULT_TYPEDEF_(0x80041318L)






// The task XML is missing a required element or attribute.

SCHED_E_MISSINGNODE              _HRESULT_TYPEDEF_(0x80041319L)






// The task XML is malformed.

SCHED_E_MALFORMEDXML             _HRESULT_TYPEDEF_(0x8004131AL)






// The task is registered, but not all specified triggers will start the task, check task scheduler event log for detailed information.

SCHED_S_SOME_TRIGGERS_FAILED     _HRESULT_TYPEDEF_(0x0004131BL)






// The task is registered, but may fail to start. Batch logon privilege needs to be enabled for the task principal.

SCHED_S_BATCH_LOGON_PROBLEM      _HRESULT_TYPEDEF_(0x0004131CL)






// The task XML contains too many nodes of the same type.

SCHED_E_TOO_MANY_NODES           _HRESULT_TYPEDEF_(0x8004131DL)






// The task cannot be started after the trigger's end boundary.

SCHED_E_PAST_END_BOUNDARY        _HRESULT_TYPEDEF_(0x8004131EL)






// An instance of this task is already running.

SCHED_E_ALREADY_RUNNING          _HRESULT_TYPEDEF_(0x8004131FL)






// The task will not run because the user is not logged on.

SCHED_E_USER_NOT_LOGGED_ON       _HRESULT_TYPEDEF_(0x80041320L)






// The task image is corrupt or has been tampered with.

SCHED_E_INVALID_TASK_HASH        _HRESULT_TYPEDEF_(0x80041321L)






// The Task Scheduler service is not available.

SCHED_E_SERVICE_NOT_AVAILABLE    _HRESULT_TYPEDEF_(0x80041322L)






// The Task Scheduler service is too busy to handle your request. Please try again later.

SCHED_E_SERVICE_TOO_BUSY         _HRESULT_TYPEDEF_(0x80041323L)






// The Task Scheduler service attempted to run the task, but the task did not run due to one of the constraints in the task definition.

SCHED_E_TASK_ATTEMPTED           _HRESULT_TYPEDEF_(0x80041324L)






// The Task Scheduler service has asked the task to run.

SCHED_S_TASK_QUEUED              _HRESULT_TYPEDEF_(0x00041325L)






// The task is disabled.

SCHED_E_TASK_DISABLED            _HRESULT_TYPEDEF_(0x80041326L)






// The task has properties that are not compatible with previous versions of Windows.

SCHED_E_TASK_NOT_V1_COMPAT       _HRESULT_TYPEDEF_(0x80041327L)






// The task settings do not allow the task to start on demand.

SCHED_E_START_ON_DEMAND          _HRESULT_TYPEDEF_(0x80041328L)






// The combination of properties that task is using is not compatible with the scheduling engine.

SCHED_E_TASK_NOT_UBPM_COMPAT     _HRESULT_TYPEDEF_(0x80041329L)






// The task definition uses a deprecated feature.

SCHED_E_DEPRECATED_FEATURE_USED  _HRESULT_TYPEDEF_(0x80041330L)

// ******************
// FACILITY_WINDOWS
// ******************

// Codes 0x0-0x01ff are reserved for the OLE group of
// interfaces.






// Attempt to create a class object failed

CO_E_CLASS_CREATE_FAILED         _HRESULT_TYPEDEF_(0x80080001L)






// OLE service could not bind object

CO_E_SCM_ERROR                   _HRESULT_TYPEDEF_(0x80080002L)






// RPC communication failed with OLE service

CO_E_SCM_RPC_FAILURE             _HRESULT_TYPEDEF_(0x80080003L)






// Bad path to object

CO_E_BAD_PATH                    _HRESULT_TYPEDEF_(0x80080004L)






// Server execution failed

CO_E_SERVER_EXEC_FAILURE         _HRESULT_TYPEDEF_(0x80080005L)






// OLE service could not communicate with the object server

CO_E_OBJSRV_RPC_FAILURE          _HRESULT_TYPEDEF_(0x80080006L)






// Moniker path could not be normalized

MK_E_NO_NORMALIZED               _HRESULT_TYPEDEF_(0x80080007L)






// Object server is stopping when OLE service contacts it

CO_E_SERVER_STOPPING             _HRESULT_TYPEDEF_(0x80080008L)






// An invalid root block pointer was specified

MEM_E_INVALID_ROOT               _HRESULT_TYPEDEF_(0x80080009L)






// An allocation chain contained an invalid link pointer

MEM_E_INVALID_LINK               _HRESULT_TYPEDEF_(0x80080010L)






// The requested allocation size was too large

MEM_E_INVALID_SIZE               _HRESULT_TYPEDEF_(0x80080011L)






// Not all the requested interfaces were available

CO_S_NOTALLINTERFACES            _HRESULT_TYPEDEF_(0x00080012L)






// The specified machine name was not found in the cache.

CO_S_MACHINENAMENOTFOUND         _HRESULT_TYPEDEF_(0x00080013L)






// The activation requires a display name to be present under the CLSID key.

CO_E_MISSING_DISPLAYNAME         _HRESULT_TYPEDEF_(0x80080015L)






// The activation requires that the RunAs value for the application is Activate As Activator.

CO_E_RUNAS_VALUE_MUST_BE_AAA     _HRESULT_TYPEDEF_(0x80080016L)






// The class is not configured to support Elevated activation.

CO_E_ELEVATION_DISABLED          _HRESULT_TYPEDEF_(0x80080017L)


// Codes 0x0200-0x02ff are reserved for the APPX errors






// Appx packaging API has encountered an internal error.

APPX_E_PACKAGING_INTERNAL        _HRESULT_TYPEDEF_(0x80080200L)






// The file is not a valid Appx package because its contents are interleaved.

APPX_E_INTERLEAVING_NOT_ALLOWED  _HRESULT_TYPEDEF_(0x80080201L)






// The file is not a valid Appx package because it contains OPC relationships.

APPX_E_RELATIONSHIPS_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80080202L)






// The file is not a valid Appx package because it is missing a manifest or block map, or missing a signature file when the code integrity file is present.

APPX_E_MISSING_REQUIRED_FILE     _HRESULT_TYPEDEF_(0x80080203L)






// The Appx package's manifest is invalid.

APPX_E_INVALID_MANIFEST          _HRESULT_TYPEDEF_(0x80080204L)






// The Appx package's block map is invalid.

APPX_E_INVALID_BLOCKMAP          _HRESULT_TYPEDEF_(0x80080205L)






// The Appx package's content cannot be read because it is corrupt.

APPX_E_CORRUPT_CONTENT           _HRESULT_TYPEDEF_(0x80080206L)






// The computed hash value of the block does not match the one stored in the block map.

APPX_E_BLOCK_HASH_INVALID        _HRESULT_TYPEDEF_(0x80080207L)






// The requested byte range is over 4GB when translated to byte range of blocks.

APPX_E_REQUESTED_RANGE_TOO_LARGE _HRESULT_TYPEDEF_(0x80080208L)






// The SIP_SUBJECTINFO structure used to sign the package didn't contain the required data.

APPX_E_INVALID_SIP_CLIENT_DATA   _HRESULT_TYPEDEF_(0x80080209L)






// The APPX_KEY_INFO structure used to encrypt or decrypt the package contains invalid data.

APPX_E_INVALID_KEY_INFO          _HRESULT_TYPEDEF_(0x8008020AL)






// The Appx package's content group map is invalid.

APPX_E_INVALID_CONTENTGROUPMAP   _HRESULT_TYPEDEF_(0x8008020BL)






// The .appinstaller file is invalid.

APPX_E_INVALID_APPINSTALLER      _HRESULT_TYPEDEF_(0x8008020CL)






// The baseline package version in delta package does not match the version in the baseline package to be updated.

APPX_E_DELTA_BASELINE_VERSION_MISMATCH _HRESULT_TYPEDEF_(0x8008020DL)






// The delta package is missing a file from the updated package.

APPX_E_DELTA_PACKAGE_MISSING_FILE _HRESULT_TYPEDEF_(0x8008020EL)






// The delta package is invalid.

APPX_E_INVALID_DELTA_PACKAGE     _HRESULT_TYPEDEF_(0x8008020FL)






// The delta appended package is not allowed for the current operation.

APPX_E_DELTA_APPENDED_PACKAGE_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80080210L)






// The packaging layout file is invalid.

APPX_E_INVALID_PACKAGING_LAYOUT  _HRESULT_TYPEDEF_(0x80080211L)






// The packageSignConfig file is invalid.

APPX_E_INVALID_PACKAGESIGNCONFIG _HRESULT_TYPEDEF_(0x80080212L)






// The resources.pri file is not allowed when there are no resource elements in the package manifest.

APPX_E_RESOURCESPRI_NOT_ALLOWED  _HRESULT_TYPEDEF_(0x80080213L)






// The compression state of file in baseline and updated package does not match.

APPX_E_FILE_COMPRESSION_MISMATCH _HRESULT_TYPEDEF_(0x80080214L)






// Non appx extensions are not allowed for payload packages targeting older platforms.

APPX_E_INVALID_PAYLOAD_PACKAGE_EXTENSION _HRESULT_TYPEDEF_(0x80080215L)






// The encryptionExclusionFileList file is invalid.

APPX_E_INVALID_ENCRYPTION_EXCLUSION_FILE_LIST _HRESULT_TYPEDEF_(0x80080216L)


// Codes 0x0300-0x030f are reserved for background task error codes.






// The background task activation is spurious.

BT_E_SPURIOUS_ACTIVATION         _HRESULT_TYPEDEF_(0x80080300L)

// ******************
// FACILITY_DISPATCH
// ******************





// Unknown interface.

DISP_E_UNKNOWNINTERFACE          _HRESULT_TYPEDEF_(0x80020001L)






// Member not found.

DISP_E_MEMBERNOTFOUND            _HRESULT_TYPEDEF_(0x80020003L)






// Parameter not found.

DISP_E_PARAMNOTFOUND             _HRESULT_TYPEDEF_(0x80020004L)






// Type mismatch.

DISP_E_TYPEMISMATCH              _HRESULT_TYPEDEF_(0x80020005L)






// Unknown name.

DISP_E_UNKNOWNNAME               _HRESULT_TYPEDEF_(0x80020006L)






// No named arguments.

DISP_E_NONAMEDARGS               _HRESULT_TYPEDEF_(0x80020007L)






// Bad variable type.

DISP_E_BADVARTYPE                _HRESULT_TYPEDEF_(0x80020008L)






// Exception occurred.

DISP_E_EXCEPTION                 _HRESULT_TYPEDEF_(0x80020009L)






// Out of present range.

DISP_E_OVERFLOW                  _HRESULT_TYPEDEF_(0x8002000AL)






// Invalid index.

DISP_E_BADINDEX                  _HRESULT_TYPEDEF_(0x8002000BL)






// Unknown language.

DISP_E_UNKNOWNLCID               _HRESULT_TYPEDEF_(0x8002000CL)






// Memory is locked.

DISP_E_ARRAYISLOCKED             _HRESULT_TYPEDEF_(0x8002000DL)






// Invalid number of parameters.

DISP_E_BADPARAMCOUNT             _HRESULT_TYPEDEF_(0x8002000EL)






// Parameter not optional.

DISP_E_PARAMNOTOPTIONAL          _HRESULT_TYPEDEF_(0x8002000FL)






// Invalid callee.

DISP_E_BADCALLEE                 _HRESULT_TYPEDEF_(0x80020010L)






// Does not support a collection.

DISP_E_NOTACOLLECTION            _HRESULT_TYPEDEF_(0x80020011L)






// Division by zero.

DISP_E_DIVBYZERO                 _HRESULT_TYPEDEF_(0x80020012L)






// Buffer too small

DISP_E_BUFFERTOOSMALL            _HRESULT_TYPEDEF_(0x80020013L)






// Buffer too small.

TYPE_E_BUFFERTOOSMALL            _HRESULT_TYPEDEF_(0x80028016L)






// Field name not defined in the record.

TYPE_E_FIELDNOTFOUND             _HRESULT_TYPEDEF_(0x80028017L)






// Old format or invalid type library.

TYPE_E_INVDATAREAD               _HRESULT_TYPEDEF_(0x80028018L)






// Old format or invalid type library.

TYPE_E_UNSUPFORMAT               _HRESULT_TYPEDEF_(0x80028019L)






// Error accessing the OLE registry.

TYPE_E_REGISTRYACCESS            _HRESULT_TYPEDEF_(0x8002801CL)






// Library not registered.

TYPE_E_LIBNOTREGISTERED          _HRESULT_TYPEDEF_(0x8002801DL)






// Bound to unknown type.

TYPE_E_UNDEFINEDTYPE             _HRESULT_TYPEDEF_(0x80028027L)






// Qualified name disallowed.

TYPE_E_QUALIFIEDNAMEDISALLOWED   _HRESULT_TYPEDEF_(0x80028028L)






// Invalid forward reference, or reference to uncompiled type.

TYPE_E_INVALIDSTATE              _HRESULT_TYPEDEF_(0x80028029L)






// Type mismatch.

TYPE_E_WRONGTYPEKIND             _HRESULT_TYPEDEF_(0x8002802AL)






// Element not found.

TYPE_E_ELEMENTNOTFOUND           _HRESULT_TYPEDEF_(0x8002802BL)






// Ambiguous name.

TYPE_E_AMBIGUOUSNAME             _HRESULT_TYPEDEF_(0x8002802CL)






// Name already exists in the library.

TYPE_E_NAMECONFLICT              _HRESULT_TYPEDEF_(0x8002802DL)






// Unknown LCID.

TYPE_E_UNKNOWNLCID               _HRESULT_TYPEDEF_(0x8002802EL)






// Function not defined in specified DLL.

TYPE_E_DLLFUNCTIONNOTFOUND       _HRESULT_TYPEDEF_(0x8002802FL)






// Wrong module kind for the operation.

TYPE_E_BADMODULEKIND             _HRESULT_TYPEDEF_(0x800288BDL)






// Size may not exceed 64K.

TYPE_E_SIZETOOBIG                _HRESULT_TYPEDEF_(0x800288C5L)






// Duplicate ID in inheritance hierarchy.

TYPE_E_DUPLICATEID               _HRESULT_TYPEDEF_(0x800288C6L)






// Incorrect inheritance depth in standard OLE hmember.

TYPE_E_INVALIDID                 _HRESULT_TYPEDEF_(0x800288CFL)






// Type mismatch.

TYPE_E_TYPEMISMATCH              _HRESULT_TYPEDEF_(0x80028CA0L)






// Invalid number of arguments.

TYPE_E_OUTOFBOUNDS               _HRESULT_TYPEDEF_(0x80028CA1L)






// I/O Error.

TYPE_E_IOERROR                   _HRESULT_TYPEDEF_(0x80028CA2L)






// Error creating unique tmp file.

TYPE_E_CANTCREATETMPFILE         _HRESULT_TYPEDEF_(0x80028CA3L)






// Error loading type library/DLL.

TYPE_E_CANTLOADLIBRARY           _HRESULT_TYPEDEF_(0x80029C4AL)






// Inconsistent property functions.

TYPE_E_INCONSISTENTPROPFUNCS     _HRESULT_TYPEDEF_(0x80029C83L)






// Circular dependency between types/modules.

TYPE_E_CIRCULARTYPE              _HRESULT_TYPEDEF_(0x80029C84L)

// ******************
// FACILITY_STORAGE
// ******************





// Unable to perform requested operation.

STG_E_INVALIDFUNCTION            _HRESULT_TYPEDEF_(0x80030001L)






// %1 could not be found.

STG_E_FILENOTFOUND               _HRESULT_TYPEDEF_(0x80030002L)






// The path %1 could not be found.

STG_E_PATHNOTFOUND               _HRESULT_TYPEDEF_(0x80030003L)






// There are insufficient resources to open another file.

STG_E_TOOMANYOPENFILES           _HRESULT_TYPEDEF_(0x80030004L)






// Access Denied.

STG_E_ACCESSDENIED               _HRESULT_TYPEDEF_(0x80030005L)






// Attempted an operation on an invalid object.

STG_E_INVALIDHANDLE              _HRESULT_TYPEDEF_(0x80030006L)






// There is insufficient memory available to complete operation.

STG_E_INSUFFICIENTMEMORY         _HRESULT_TYPEDEF_(0x80030008L)






// Invalid pointer error.

STG_E_INVALIDPOINTER             _HRESULT_TYPEDEF_(0x80030009L)






// There are no more entries to return.

STG_E_NOMOREFILES                _HRESULT_TYPEDEF_(0x80030012L)






// Disk is write-protected.

STG_E_DISKISWRITEPROTECTED       _HRESULT_TYPEDEF_(0x80030013L)






// An error occurred during a seek operation.

STG_E_SEEKERROR                  _HRESULT_TYPEDEF_(0x80030019L)






// A disk error occurred during a write operation.

STG_E_WRITEFAULT                 _HRESULT_TYPEDEF_(0x8003001DL)






// A disk error occurred during a read operation.

STG_E_READFAULT                  _HRESULT_TYPEDEF_(0x8003001EL)






// A share violation has occurred.

STG_E_SHAREVIOLATION             _HRESULT_TYPEDEF_(0x80030020L)






// A lock violation has occurred.

STG_E_LOCKVIOLATION              _HRESULT_TYPEDEF_(0x80030021L)






// %1 already exists.

STG_E_FILEALREADYEXISTS          _HRESULT_TYPEDEF_(0x80030050L)






// Invalid parameter error.

STG_E_INVALIDPARAMETER           _HRESULT_TYPEDEF_(0x80030057L)






// There is insufficient disk space to complete operation.

STG_E_MEDIUMFULL                 _HRESULT_TYPEDEF_(0x80030070L)






// Illegal write of non-simple property to simple property set.

STG_E_PROPSETMISMATCHED          _HRESULT_TYPEDEF_(0x800300F0L)






// An API call exited abnormally.

STG_E_ABNORMALAPIEXIT            _HRESULT_TYPEDEF_(0x800300FAL)






// The file %1 is not a valid compound file.

STG_E_INVALIDHEADER              _HRESULT_TYPEDEF_(0x800300FBL)






// The name %1 is not valid.

STG_E_INVALIDNAME                _HRESULT_TYPEDEF_(0x800300FCL)






// An unexpected error occurred.

STG_E_UNKNOWN                    _HRESULT_TYPEDEF_(0x800300FDL)






// That function is not implemented.

STG_E_UNIMPLEMENTEDFUNCTION      _HRESULT_TYPEDEF_(0x800300FEL)






// Invalid flag error.

STG_E_INVALIDFLAG                _HRESULT_TYPEDEF_(0x800300FFL)






// Attempted to use an object that is busy.

STG_E_INUSE                      _HRESULT_TYPEDEF_(0x80030100L)






// The storage has been changed since the last commit.

STG_E_NOTCURRENT                 _HRESULT_TYPEDEF_(0x80030101L)






// Attempted to use an object that has ceased to exist.

STG_E_REVERTED                   _HRESULT_TYPEDEF_(0x80030102L)






// Can't save.

STG_E_CANTSAVE                   _HRESULT_TYPEDEF_(0x80030103L)






// The compound file %1 was produced with an incompatible version of storage.

STG_E_OLDFORMAT                  _HRESULT_TYPEDEF_(0x80030104L)






// The compound file %1 was produced with a newer version of storage.

STG_E_OLDDLL                     _HRESULT_TYPEDEF_(0x80030105L)






// Share.exe or equivalent is required for operation.

STG_E_SHAREREQUIRED              _HRESULT_TYPEDEF_(0x80030106L)






// Illegal operation called on non-file based storage.

STG_E_NOTFILEBASEDSTORAGE        _HRESULT_TYPEDEF_(0x80030107L)






// Illegal operation called on object with extant marshallings.

STG_E_EXTANTMARSHALLINGS         _HRESULT_TYPEDEF_(0x80030108L)






// The docfile has been corrupted.

STG_E_DOCFILECORRUPT             _HRESULT_TYPEDEF_(0x80030109L)






// OLE32.DLL has been loaded at the wrong address.

STG_E_BADBASEADDRESS             _HRESULT_TYPEDEF_(0x80030110L)






// The compound file is too large for the current implementation

STG_E_DOCFILETOOLARGE            _HRESULT_TYPEDEF_(0x80030111L)






// The compound file was not created with the STGM_SIMPLE flag

STG_E_NOTSIMPLEFORMAT            _HRESULT_TYPEDEF_(0x80030112L)






// The file download was aborted abnormally. The file is incomplete.

STG_E_INCOMPLETE                 _HRESULT_TYPEDEF_(0x80030201L)






// The file download has been terminated.

STG_E_TERMINATED                 _HRESULT_TYPEDEF_(0x80030202L)






// The underlying file was converted to compound file format.

STG_S_CONVERTED                  _HRESULT_TYPEDEF_(0x00030200L)






// The storage operation should block until more data is available.

STG_S_BLOCK                      _HRESULT_TYPEDEF_(0x00030201L)






// The storage operation should retry immediately.

STG_S_RETRYNOW                   _HRESULT_TYPEDEF_(0x00030202L)






// The notified event sink will not influence the storage operation.

STG_S_MONITORING                 _HRESULT_TYPEDEF_(0x00030203L)






// Multiple opens prevent consolidated. (commit succeeded).

STG_S_MULTIPLEOPENS              _HRESULT_TYPEDEF_(0x00030204L)






// Consolidation of the storage file failed. (commit succeeded).

STG_S_CONSOLIDATIONFAILED        _HRESULT_TYPEDEF_(0x00030205L)






// Consolidation of the storage file is inappropriate. (commit succeeded).

STG_S_CANNOTCONSOLIDATE          _HRESULT_TYPEDEF_(0x00030206L)






// The device needs to be power cycled. (commit succeeded).

STG_S_POWER_CYCLE_REQUIRED       _HRESULT_TYPEDEF_(0x00030207L)






// The specified firmware slot is invalid.

STG_E_FIRMWARE_SLOT_INVALID      _HRESULT_TYPEDEF_(0x80030208L)






// The specified firmware image is invalid.

STG_E_FIRMWARE_IMAGE_INVALID     _HRESULT_TYPEDEF_(0x80030209L)






// The storage device is unresponsive.

STG_E_DEVICE_UNRESPONSIVE        _HRESULT_TYPEDEF_(0x8003020AL)

/*++

 MessageId's 0x0305 - 0x031f (inclusive) are reserved for **STORAGE**
 copy protection errors.

--*/





// Generic Copy Protection Error.

STG_E_STATUS_COPY_PROTECTION_FAILURE _HRESULT_TYPEDEF_(0x80030305L)






// Copy Protection Error - DVD CSS Authentication failed.

STG_E_CSS_AUTHENTICATION_FAILURE _HRESULT_TYPEDEF_(0x80030306L)






// Copy Protection Error - The given sector does not have a valid CSS key.

STG_E_CSS_KEY_NOT_PRESENT        _HRESULT_TYPEDEF_(0x80030307L)






// Copy Protection Error - DVD session key not established.

STG_E_CSS_KEY_NOT_ESTABLISHED    _HRESULT_TYPEDEF_(0x80030308L)






// Copy Protection Error - The read failed because the sector is encrypted.

STG_E_CSS_SCRAMBLED_SECTOR       _HRESULT_TYPEDEF_(0x80030309L)






// Copy Protection Error - The current DVD's region does not correspond to the region setting of the drive.

STG_E_CSS_REGION_MISMATCH        _HRESULT_TYPEDEF_(0x8003030AL)






// Copy Protection Error - The drive's region setting may be permanent or the number of user resets has been exhausted.

STG_E_RESETS_EXHAUSTED           _HRESULT_TYPEDEF_(0x8003030BL)

/*++

 MessageId's 0x0305 - 0x031f (inclusive) are reserved for **STORAGE**
 copy protection errors.

--*/
// ******************
// FACILITY_RPC
// ******************

// Codes 0x0-0x11 are propagated from 16 bit OLE.






// Call was rejected by callee.

RPC_E_CALL_REJECTED              _HRESULT_TYPEDEF_(0x80010001L)






// Call was canceled by the message filter.

RPC_E_CALL_CANCELED              _HRESULT_TYPEDEF_(0x80010002L)






// The caller is dispatching an intertask SendMessage call and cannot call out via PostMessage.

RPC_E_CANTPOST_INSENDCALL        _HRESULT_TYPEDEF_(0x80010003L)






// The caller is dispatching an asynchronous call and cannot make an outgoing call on behalf of this call.

RPC_E_CANTCALLOUT_INASYNCCALL    _HRESULT_TYPEDEF_(0x80010004L)






// It is illegal to call out while inside message filter.

RPC_E_CANTCALLOUT_INEXTERNALCALL _HRESULT_TYPEDEF_(0x80010005L)






// The connection terminated or is in a bogus state and cannot be used any more. Other connections are still valid.

RPC_E_CONNECTION_TERMINATED      _HRESULT_TYPEDEF_(0x80010006L)






// The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call may have executed.

RPC_E_SERVER_DIED                _HRESULT_TYPEDEF_(0x80010007L)






// The caller (client) disappeared while the callee (server) was processing a call.

RPC_E_CLIENT_DIED                _HRESULT_TYPEDEF_(0x80010008L)






// The data packet with the marshalled parameter data is incorrect.

RPC_E_INVALID_DATAPACKET         _HRESULT_TYPEDEF_(0x80010009L)






// The call was not transmitted properly; the message queue was full and was not emptied after yielding.

RPC_E_CANTTRANSMIT_CALL          _HRESULT_TYPEDEF_(0x8001000AL)






// The client (caller) cannot marshall the parameter data - low memory, etc.

RPC_E_CLIENT_CANTMARSHAL_DATA    _HRESULT_TYPEDEF_(0x8001000BL)






// The client (caller) cannot unmarshall the return data - low memory, etc.

RPC_E_CLIENT_CANTUNMARSHAL_DATA  _HRESULT_TYPEDEF_(0x8001000CL)






// The server (callee) cannot marshall the return data - low memory, etc.

RPC_E_SERVER_CANTMARSHAL_DATA    _HRESULT_TYPEDEF_(0x8001000DL)






// The server (callee) cannot unmarshall the parameter data - low memory, etc.

RPC_E_SERVER_CANTUNMARSHAL_DATA  _HRESULT_TYPEDEF_(0x8001000EL)






// Received data is invalid; could be server or client data.

RPC_E_INVALID_DATA               _HRESULT_TYPEDEF_(0x8001000FL)






// A particular parameter is invalid and cannot be (un)marshalled.

RPC_E_INVALID_PARAMETER          _HRESULT_TYPEDEF_(0x80010010L)






// There is no second outgoing call on same channel in DDE conversation.

RPC_E_CANTCALLOUT_AGAIN          _HRESULT_TYPEDEF_(0x80010011L)






// The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call did not execute.

RPC_E_SERVER_DIED_DNE            _HRESULT_TYPEDEF_(0x80010012L)






// System call failed.

RPC_E_SYS_CALL_FAILED            _HRESULT_TYPEDEF_(0x80010100L)






// Could not allocate some required resource (memory, events, ...)

RPC_E_OUT_OF_RESOURCES           _HRESULT_TYPEDEF_(0x80010101L)






// Attempted to make calls on more than one thread in single threaded mode.

RPC_E_ATTEMPTED_MULTITHREAD      _HRESULT_TYPEDEF_(0x80010102L)






// The requested interface is not registered on the server object.

RPC_E_NOT_REGISTERED             _HRESULT_TYPEDEF_(0x80010103L)






// RPC could not call the server or could not return the results of calling the server.

RPC_E_FAULT                      _HRESULT_TYPEDEF_(0x80010104L)






// The server threw an exception.

RPC_E_SERVERFAULT                _HRESULT_TYPEDEF_(0x80010105L)






// Cannot change thread mode after it is set.

RPC_E_CHANGED_MODE               _HRESULT_TYPEDEF_(0x80010106L)






// The method called does not exist on the server.

RPC_E_INVALIDMETHOD              _HRESULT_TYPEDEF_(0x80010107L)






// The object invoked has disconnected from its clients.

RPC_E_DISCONNECTED               _HRESULT_TYPEDEF_(0x80010108L)






// The object invoked chose not to process the call now. Try again later.

RPC_E_RETRY                      _HRESULT_TYPEDEF_(0x80010109L)






// The message filter indicated that the application is busy.

RPC_E_SERVERCALL_RETRYLATER      _HRESULT_TYPEDEF_(0x8001010AL)






// The message filter rejected the call.

RPC_E_SERVERCALL_REJECTED        _HRESULT_TYPEDEF_(0x8001010BL)






// A call control interfaces was called with invalid data.

RPC_E_INVALID_CALLDATA           _HRESULT_TYPEDEF_(0x8001010CL)






// An outgoing call cannot be made since the application is dispatching an input-synchronous call.

RPC_E_CANTCALLOUT_ININPUTSYNCCALL _HRESULT_TYPEDEF_(0x8001010DL)






// The application called an interface that was marshalled for a different thread.

RPC_E_WRONG_THREAD               _HRESULT_TYPEDEF_(0x8001010EL)






// CoInitialize has not been called on the current thread.

RPC_E_THREAD_NOT_INIT            _HRESULT_TYPEDEF_(0x8001010FL)






// The version of OLE on the client and server machines does not match.

RPC_E_VERSION_MISMATCH           _HRESULT_TYPEDEF_(0x80010110L)






// OLE received a packet with an invalid header.

RPC_E_INVALID_HEADER             _HRESULT_TYPEDEF_(0x80010111L)






// OLE received a packet with an invalid extension.

RPC_E_INVALID_EXTENSION          _HRESULT_TYPEDEF_(0x80010112L)






// The requested object or interface does not exist.

RPC_E_INVALID_IPID               _HRESULT_TYPEDEF_(0x80010113L)






// The requested object does not exist.

RPC_E_INVALID_OBJECT             _HRESULT_TYPEDEF_(0x80010114L)






// OLE has sent a request and is waiting for a reply.

RPC_S_CALLPENDING                _HRESULT_TYPEDEF_(0x80010115L)






// OLE is waiting before retrying a request.

RPC_S_WAITONTIMER                _HRESULT_TYPEDEF_(0x80010116L)






// Call context cannot be accessed after call completed.

RPC_E_CALL_COMPLETE              _HRESULT_TYPEDEF_(0x80010117L)






// Impersonate on unsecure calls is not supported.

RPC_E_UNSECURE_CALL              _HRESULT_TYPEDEF_(0x80010118L)






// Security must be initialized before any interfaces are marshalled or unmarshalled. It cannot be changed once initialized.

RPC_E_TOO_LATE                   _HRESULT_TYPEDEF_(0x80010119L)






// No security packages are installed on this machine or the user is not logged on or there are no compatible security packages between the client and server.

RPC_E_NO_GOOD_SECURITY_PACKAGES  _HRESULT_TYPEDEF_(0x8001011AL)






// Access is denied.

RPC_E_ACCESS_DENIED              _HRESULT_TYPEDEF_(0x8001011BL)






// Remote calls are not allowed for this process.

RPC_E_REMOTE_DISABLED            _HRESULT_TYPEDEF_(0x8001011CL)






// The marshaled interface data packet (OBJREF) has an invalid or unknown format.

RPC_E_INVALID_OBJREF             _HRESULT_TYPEDEF_(0x8001011DL)






// No context is associated with this call. This happens for some custom marshalled calls and on the client side of the call.

RPC_E_NO_CONTEXT                 _HRESULT_TYPEDEF_(0x8001011EL)






// This operation returned because the timeout period expired.

RPC_E_TIMEOUT                    _HRESULT_TYPEDEF_(0x8001011FL)






// There are no synchronize objects to wait on.

RPC_E_NO_SYNC                    _HRESULT_TYPEDEF_(0x80010120L)






// Full subject issuer chain SSL principal name expected from the server.

RPC_E_FULLSIC_REQUIRED           _HRESULT_TYPEDEF_(0x80010121L)






// Principal name is not a valid MSSTD name.

RPC_E_INVALID_STD_NAME           _HRESULT_TYPEDEF_(0x80010122L)






// Unable to impersonate DCOM client

CO_E_FAILEDTOIMPERSONATE         _HRESULT_TYPEDEF_(0x80010123L)






// Unable to obtain server's security context

CO_E_FAILEDTOGETSECCTX           _HRESULT_TYPEDEF_(0x80010124L)






// Unable to open the access token of the current thread

CO_E_FAILEDTOOPENTHREADTOKEN     _HRESULT_TYPEDEF_(0x80010125L)






// Unable to obtain user info from an access token

CO_E_FAILEDTOGETTOKENINFO        _HRESULT_TYPEDEF_(0x80010126L)






// The client who called IAccessControl::IsAccessPermitted was not the trustee provided to the method

CO_E_TRUSTEEDOESNTMATCHCLIENT    _HRESULT_TYPEDEF_(0x80010127L)






// Unable to obtain the client's security blanket

CO_E_FAILEDTOQUERYCLIENTBLANKET  _HRESULT_TYPEDEF_(0x80010128L)






// Unable to set a discretionary ACL into a security descriptor

CO_E_FAILEDTOSETDACL             _HRESULT_TYPEDEF_(0x80010129L)






// The system function, AccessCheck, returned false

CO_E_ACCESSCHECKFAILED           _HRESULT_TYPEDEF_(0x8001012AL)






// Either NetAccessDel or NetAccessAdd returned an error code.

CO_E_NETACCESSAPIFAILED          _HRESULT_TYPEDEF_(0x8001012BL)






// One of the trustee strings provided by the user did not conform to the <Domain>\<Name> syntax and it was not the "*" string

CO_E_WRONGTRUSTEENAMESYNTAX      _HRESULT_TYPEDEF_(0x8001012CL)






// One of the security identifiers provided by the user was invalid

CO_E_INVALIDSID                  _HRESULT_TYPEDEF_(0x8001012DL)






// Unable to convert a wide character trustee string to a multibyte trustee string

CO_E_CONVERSIONFAILED            _HRESULT_TYPEDEF_(0x8001012EL)






// Unable to find a security identifier that corresponds to a trustee string provided by the user

CO_E_NOMATCHINGSIDFOUND          _HRESULT_TYPEDEF_(0x8001012FL)






// The system function, LookupAccountSID, failed

CO_E_LOOKUPACCSIDFAILED          _HRESULT_TYPEDEF_(0x80010130L)






// Unable to find a trustee name that corresponds to a security identifier provided by the user

CO_E_NOMATCHINGNAMEFOUND         _HRESULT_TYPEDEF_(0x80010131L)






// The system function, LookupAccountName, failed

CO_E_LOOKUPACCNAMEFAILED         _HRESULT_TYPEDEF_(0x80010132L)






// Unable to set or reset a serialization handle

CO_E_SETSERLHNDLFAILED           _HRESULT_TYPEDEF_(0x80010133L)






// Unable to obtain the Windows directory

CO_E_FAILEDTOGETWINDIR           _HRESULT_TYPEDEF_(0x80010134L)






// Path too long

CO_E_PATHTOOLONG                 _HRESULT_TYPEDEF_(0x80010135L)






// Unable to generate a uuid.

CO_E_FAILEDTOGENUUID             _HRESULT_TYPEDEF_(0x80010136L)






// Unable to create file

CO_E_FAILEDTOCREATEFILE          _HRESULT_TYPEDEF_(0x80010137L)






// Unable to close a serialization handle or a file handle.

CO_E_FAILEDTOCLOSEHANDLE         _HRESULT_TYPEDEF_(0x80010138L)






// The number of ACEs in an ACL exceeds the system limit.

CO_E_EXCEEDSYSACLLIMIT           _HRESULT_TYPEDEF_(0x80010139L)






// Not all the DENY_ACCESS ACEs are arranged in front of the GRANT_ACCESS ACEs in the stream.

CO_E_ACESINWRONGORDER            _HRESULT_TYPEDEF_(0x8001013AL)






// The version of ACL format in the stream is not supported by this implementation of IAccessControl

CO_E_INCOMPATIBLESTREAMVERSION   _HRESULT_TYPEDEF_(0x8001013BL)






// Unable to open the access token of the server process

CO_E_FAILEDTOOPENPROCESSTOKEN    _HRESULT_TYPEDEF_(0x8001013CL)






// Unable to decode the ACL in the stream provided by the user

CO_E_DECODEFAILED                _HRESULT_TYPEDEF_(0x8001013DL)






// The COM IAccessControl object is not initialized

CO_E_ACNOTINITIALIZED            _HRESULT_TYPEDEF_(0x8001013FL)






// Call Cancellation is disabled

CO_E_CANCEL_DISABLED             _HRESULT_TYPEDEF_(0x80010140L)






// An internal error occurred.

RPC_E_UNEXPECTED                 _HRESULT_TYPEDEF_(0x8001FFFFL)



//////////////////////////////////////
//                                  //
// Additional Security Status Codes //
//                                  //
// Facility=Security                //
//                                  //
//////////////////////////////////////







// The specified event is currently not being audited.

ERROR_AUDITING_DISABLED          _HRESULT_TYPEDEF_(0xC0090001L)






// The SID filtering operation removed all SIDs.

ERROR_ALL_SIDS_FILTERED          _HRESULT_TYPEDEF_(0xC0090002L)






// Business rule scripts are disabled for the calling application.

ERROR_BIZRULES_NOT_ENABLED       _HRESULT_TYPEDEF_(0xC0090003L)



/////////////////////////////////////////////
//                                         //
// end of Additional Security Status Codes //
//                                         //
/////////////////////////////////////////////



 /////////////////
 //
 //  FACILITY_SSPI
 //
 /////////////////






// Bad UID.

NTE_BAD_UID                      _HRESULT_TYPEDEF_(0x80090001L)






// Bad Hash.

NTE_BAD_HASH                     _HRESULT_TYPEDEF_(0x80090002L)






// Bad Key.

NTE_BAD_KEY                      _HRESULT_TYPEDEF_(0x80090003L)






// Bad Length.

NTE_BAD_LEN                      _HRESULT_TYPEDEF_(0x80090004L)






// Bad Data.

NTE_BAD_DATA                     _HRESULT_TYPEDEF_(0x80090005L)






// Invalid Signature.

NTE_BAD_SIGNATURE                _HRESULT_TYPEDEF_(0x80090006L)






// Bad Version of provider.

NTE_BAD_VER                      _HRESULT_TYPEDEF_(0x80090007L)






// Invalid algorithm specified.

NTE_BAD_ALGID                    _HRESULT_TYPEDEF_(0x80090008L)






// Invalid flags specified.

NTE_BAD_FLAGS                    _HRESULT_TYPEDEF_(0x80090009L)






// Invalid type specified.

NTE_BAD_TYPE                     _HRESULT_TYPEDEF_(0x8009000AL)






// Key not valid for use in specified state.

NTE_BAD_KEY_STATE                _HRESULT_TYPEDEF_(0x8009000BL)






// Hash not valid for use in specified state.

NTE_BAD_HASH_STATE               _HRESULT_TYPEDEF_(0x8009000CL)






// Key does not exist.

NTE_NO_KEY                       _HRESULT_TYPEDEF_(0x8009000DL)






// Insufficient memory available for the operation.

NTE_NO_MEMORY                    _HRESULT_TYPEDEF_(0x8009000EL)






// Object already exists.

NTE_EXISTS                       _HRESULT_TYPEDEF_(0x8009000FL)






// Access denied.

NTE_PERM                         _HRESULT_TYPEDEF_(0x80090010L)






// Object was not found.

NTE_NOT_FOUND                    _HRESULT_TYPEDEF_(0x80090011L)






// Data already encrypted.

NTE_DOUBLE_ENCRYPT               _HRESULT_TYPEDEF_(0x80090012L)






// Invalid provider specified.

NTE_BAD_PROVIDER                 _HRESULT_TYPEDEF_(0x80090013L)






// Invalid provider type specified.

NTE_BAD_PROV_TYPE                _HRESULT_TYPEDEF_(0x80090014L)






// Provider's public key is invalid.

NTE_BAD_PUBLIC_KEY               _HRESULT_TYPEDEF_(0x80090015L)






// Keyset does not exist

NTE_BAD_KEYSET                   _HRESULT_TYPEDEF_(0x80090016L)






// Provider type not defined.

NTE_PROV_TYPE_NOT_DEF            _HRESULT_TYPEDEF_(0x80090017L)






// Provider type as registered is invalid.

NTE_PROV_TYPE_ENTRY_BAD          _HRESULT_TYPEDEF_(0x80090018L)






// The keyset is not defined.

NTE_KEYSET_NOT_DEF               _HRESULT_TYPEDEF_(0x80090019L)






// Keyset as registered is invalid.

NTE_KEYSET_ENTRY_BAD             _HRESULT_TYPEDEF_(0x8009001AL)






// Provider type does not match registered value.

NTE_PROV_TYPE_NO_MATCH           _HRESULT_TYPEDEF_(0x8009001BL)






// The digital signature file is corrupt.

NTE_SIGNATURE_FILE_BAD           _HRESULT_TYPEDEF_(0x8009001CL)






// Provider DLL failed to initialize correctly.

NTE_PROVIDER_DLL_FAIL            _HRESULT_TYPEDEF_(0x8009001DL)






// Provider DLL could not be found.

NTE_PROV_DLL_NOT_FOUND           _HRESULT_TYPEDEF_(0x8009001EL)






// The Keyset parameter is invalid.

NTE_BAD_KEYSET_PARAM             _HRESULT_TYPEDEF_(0x8009001FL)






// An internal error occurred.

NTE_FAIL                         _HRESULT_TYPEDEF_(0x80090020L)






// A base error occurred.

NTE_SYS_ERR                      _HRESULT_TYPEDEF_(0x80090021L)






// Provider could not perform the action since the context was acquired as silent.

NTE_SILENT_CONTEXT               _HRESULT_TYPEDEF_(0x80090022L)






// The security token does not have storage space available for an additional container.

NTE_TOKEN_KEYSET_STORAGE_FULL    _HRESULT_TYPEDEF_(0x80090023L)






// The profile for the user is a temporary profile.

NTE_TEMPORARY_PROFILE            _HRESULT_TYPEDEF_(0x80090024L)






// The key parameters could not be set because the CSP uses fixed parameters.

NTE_FIXEDPARAMETER               _HRESULT_TYPEDEF_(0x80090025L)






// The supplied handle is invalid.

NTE_INVALID_HANDLE               _HRESULT_TYPEDEF_(0x80090026L)






// The parameter is incorrect.

NTE_INVALID_PARAMETER            _HRESULT_TYPEDEF_(0x80090027L)






// The buffer supplied to a function was too small.

NTE_BUFFER_TOO_SMALL             _HRESULT_TYPEDEF_(0x80090028L)






// The requested operation is not supported.

NTE_NOT_SUPPORTED                _HRESULT_TYPEDEF_(0x80090029L)






// No more data is available.

NTE_NO_MORE_ITEMS                _HRESULT_TYPEDEF_(0x8009002AL)






// The supplied buffers overlap incorrectly.

NTE_BUFFERS_OVERLAP              _HRESULT_TYPEDEF_(0x8009002BL)






// The specified data could not be decrypted.

NTE_DECRYPTION_FAILURE           _HRESULT_TYPEDEF_(0x8009002CL)






// An internal consistency check failed.

NTE_INTERNAL_ERROR               _HRESULT_TYPEDEF_(0x8009002DL)






// This operation requires input from the user.

NTE_UI_REQUIRED                  _HRESULT_TYPEDEF_(0x8009002EL)






// The cryptographic provider does not support HMAC.

NTE_HMAC_NOT_SUPPORTED           _HRESULT_TYPEDEF_(0x8009002FL)






// The device that is required by this cryptographic provider is not ready for use.

NTE_DEVICE_NOT_READY             _HRESULT_TYPEDEF_(0x80090030L)






// The dictionary attack mitigation is triggered and the provided authorization was ignored by the provider.

NTE_AUTHENTICATION_IGNORED       _HRESULT_TYPEDEF_(0x80090031L)






// The validation of the provided data failed the integrity or signature validation.

NTE_VALIDATION_FAILED            _HRESULT_TYPEDEF_(0x80090032L)






// Incorrect password.

NTE_INCORRECT_PASSWORD           _HRESULT_TYPEDEF_(0x80090033L)






// Encryption failed.

NTE_ENCRYPTION_FAILURE           _HRESULT_TYPEDEF_(0x80090034L)






// The device that is required by this cryptographic provider is not found on this platform.

NTE_DEVICE_NOT_FOUND             _HRESULT_TYPEDEF_(0x80090035L)






// The action was cancelled by the user.

NTE_USER_CANCELLED               _HRESULT_TYPEDEF_(0x80090036L)






// The password is no longer valid and must be changed.

NTE_PASSWORD_CHANGE_REQUIRED     _HRESULT_TYPEDEF_(0x80090037L)






// The operation cannot be completed from Terminal Server client sessions.

NTE_NOT_ACTIVE_CONSOLE           _HRESULT_TYPEDEF_(0x80090038L)






// Not enough memory is available to complete this request

SEC_E_INSUFFICIENT_MEMORY        _HRESULT_TYPEDEF_(0x80090300L)






// The handle specified is invalid

SEC_E_INVALID_HANDLE             _HRESULT_TYPEDEF_(0x80090301L)






// The function requested is not supported

SEC_E_UNSUPPORTED_FUNCTION       _HRESULT_TYPEDEF_(0x80090302L)






// The specified target is unknown or unreachable

SEC_E_TARGET_UNKNOWN             _HRESULT_TYPEDEF_(0x80090303L)






// The Local Security Authority cannot be contacted

SEC_E_INTERNAL_ERROR             _HRESULT_TYPEDEF_(0x80090304L)






// The requested security package does not exist

SEC_E_SECPKG_NOT_FOUND           _HRESULT_TYPEDEF_(0x80090305L)






// The caller is not the owner of the desired credentials

SEC_E_NOT_OWNER                  _HRESULT_TYPEDEF_(0x80090306L)






// The security package failed to initialize, and cannot be installed

SEC_E_CANNOT_INSTALL             _HRESULT_TYPEDEF_(0x80090307L)






// The token supplied to the function is invalid

SEC_E_INVALID_TOKEN              _HRESULT_TYPEDEF_(0x80090308L)






// The security package is not able to marshall the logon buffer, so the logon attempt has failed

SEC_E_CANNOT_PACK                _HRESULT_TYPEDEF_(0x80090309L)






// The per-message Quality of Protection is not supported by the security package

SEC_E_QOP_NOT_SUPPORTED          _HRESULT_TYPEDEF_(0x8009030AL)






// The security context does not allow impersonation of the client

SEC_E_NO_IMPERSONATION           _HRESULT_TYPEDEF_(0x8009030BL)






// The logon attempt failed

SEC_E_LOGON_DENIED               _HRESULT_TYPEDEF_(0x8009030CL)






// The credentials supplied to the package were not recognized

SEC_E_UNKNOWN_CREDENTIALS        _HRESULT_TYPEDEF_(0x8009030DL)






// No credentials are available in the security package

SEC_E_NO_CREDENTIALS             _HRESULT_TYPEDEF_(0x8009030EL)






// The message or signature supplied for verification has been altered

SEC_E_MESSAGE_ALTERED            _HRESULT_TYPEDEF_(0x8009030FL)






// The message supplied for verification is out of sequence

SEC_E_OUT_OF_SEQUENCE            _HRESULT_TYPEDEF_(0x80090310L)






// No authority could be contacted for authentication.

SEC_E_NO_AUTHENTICATING_AUTHORITY _HRESULT_TYPEDEF_(0x80090311L)






// The function completed successfully, but must be called again to complete the context

SEC_I_CONTINUE_NEEDED            _HRESULT_TYPEDEF_(0x00090312L)






// The function completed successfully, but CompleteToken must be called

SEC_I_COMPLETE_NEEDED            _HRESULT_TYPEDEF_(0x00090313L)






// The function completed successfully, but both CompleteToken and this function must be called to complete the context

SEC_I_COMPLETE_AND_CONTINUE      _HRESULT_TYPEDEF_(0x00090314L)






// The logon was completed, but no network authority was available. The logon was made using locally known information

SEC_I_LOCAL_LOGON                _HRESULT_TYPEDEF_(0x00090315L)






// Schannel has received a TLS extension the SSPI caller subscribed to.

SEC_I_GENERIC_EXTENSION_RECEIVED _HRESULT_TYPEDEF_(0x00090316L)






// The requested security package does not exist

SEC_E_BAD_PKGID                  _HRESULT_TYPEDEF_(0x80090316L)






// The context has expired and can no longer be used.

SEC_E_CONTEXT_EXPIRED            _HRESULT_TYPEDEF_(0x80090317L)






// The context has expired and can no longer be used.

SEC_I_CONTEXT_EXPIRED            _HRESULT_TYPEDEF_(0x00090317L)






// The supplied message is incomplete. The signature was not verified.

SEC_E_INCOMPLETE_MESSAGE         _HRESULT_TYPEDEF_(0x80090318L)






// The credentials supplied were not complete, and could not be verified. The context could not be initialized.

SEC_E_INCOMPLETE_CREDENTIALS     _HRESULT_TYPEDEF_(0x80090320L)






// The buffers supplied to a function was too small.

SEC_E_BUFFER_TOO_SMALL           _HRESULT_TYPEDEF_(0x80090321L)






// The credentials supplied were not complete, and could not be verified. Additional information can be returned from the context.

SEC_I_INCOMPLETE_CREDENTIALS     _HRESULT_TYPEDEF_(0x00090320L)






// The context data must be renegotiated with the peer.

SEC_I_RENEGOTIATE                _HRESULT_TYPEDEF_(0x00090321L)






// The target principal name is incorrect.

SEC_E_WRONG_PRINCIPAL            _HRESULT_TYPEDEF_(0x80090322L)






// There is no LSA mode context associated with this context.

SEC_I_NO_LSA_CONTEXT             _HRESULT_TYPEDEF_(0x00090323L)






// The clocks on the client and server machines are skewed.

SEC_E_TIME_SKEW                  _HRESULT_TYPEDEF_(0x80090324L)






// The certificate chain was issued by an authority that is not trusted.

SEC_E_UNTRUSTED_ROOT             _HRESULT_TYPEDEF_(0x80090325L)






// The message received was unexpected or badly formatted.

SEC_E_ILLEGAL_MESSAGE            _HRESULT_TYPEDEF_(0x80090326L)






// An unknown error occurred while processing the certificate.

SEC_E_CERT_UNKNOWN               _HRESULT_TYPEDEF_(0x80090327L)






// The received certificate has expired.

SEC_E_CERT_EXPIRED               _HRESULT_TYPEDEF_(0x80090328L)






// The specified data could not be encrypted.

SEC_E_ENCRYPT_FAILURE            _HRESULT_TYPEDEF_(0x80090329L)






// The specified data could not be decrypted.
// 

SEC_E_DECRYPT_FAILURE            _HRESULT_TYPEDEF_(0x80090330L)






// The client and server cannot communicate, because they do not possess a common algorithm.

SEC_E_ALGORITHM_MISMATCH         _HRESULT_TYPEDEF_(0x80090331L)






// The security context could not be established due to a failure in the requested quality of service (e.g. mutual authentication or delegation).

SEC_E_SECURITY_QOS_FAILED        _HRESULT_TYPEDEF_(0x80090332L)






// A security context was deleted before the context was completed. This is considered a logon failure.

SEC_E_UNFINISHED_CONTEXT_DELETED _HRESULT_TYPEDEF_(0x80090333L)






// The client is trying to negotiate a context and the server requires user-to-user but didn't send a TGT reply.

SEC_E_NO_TGT_REPLY               _HRESULT_TYPEDEF_(0x80090334L)






// Unable to accomplish the requested task because the local machine does not have any IP addresses.

SEC_E_NO_IP_ADDRESSES            _HRESULT_TYPEDEF_(0x80090335L)






// The supplied credential handle does not match the credential associated with the security context.

SEC_E_WRONG_CREDENTIAL_HANDLE    _HRESULT_TYPEDEF_(0x80090336L)






// The crypto system or checksum function is invalid because a required function is unavailable.

SEC_E_CRYPTO_SYSTEM_INVALID      _HRESULT_TYPEDEF_(0x80090337L)






// The number of maximum ticket referrals has been exceeded.

SEC_E_MAX_REFERRALS_EXCEEDED     _HRESULT_TYPEDEF_(0x80090338L)






// The local machine must be a Kerberos KDC (domain controller) and it is not.

SEC_E_MUST_BE_KDC                _HRESULT_TYPEDEF_(0x80090339L)






// The other end of the security negotiation is requires strong crypto but it is not supported on the local machine.

SEC_E_STRONG_CRYPTO_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x8009033AL)






// The KDC reply contained more than one principal name.

SEC_E_TOO_MANY_PRINCIPALS        _HRESULT_TYPEDEF_(0x8009033BL)






// Expected to find PA data for a hint of what etype to use, but it was not found.

SEC_E_NO_PA_DATA                 _HRESULT_TYPEDEF_(0x8009033CL)






// The client certificate does not contain a valid UPN, or does not match the client name in the logon request. Please contact your administrator.

SEC_E_PKINIT_NAME_MISMATCH       _HRESULT_TYPEDEF_(0x8009033DL)






// Smartcard logon is required and was not used.

SEC_E_SMARTCARD_LOGON_REQUIRED   _HRESULT_TYPEDEF_(0x8009033EL)






// A system shutdown is in progress.

SEC_E_SHUTDOWN_IN_PROGRESS       _HRESULT_TYPEDEF_(0x8009033FL)






// An invalid request was sent to the KDC.

SEC_E_KDC_INVALID_REQUEST        _HRESULT_TYPEDEF_(0x80090340L)






// The KDC was unable to generate a referral for the service requested.

SEC_E_KDC_UNABLE_TO_REFER        _HRESULT_TYPEDEF_(0x80090341L)






// The encryption type requested is not supported by the KDC.

SEC_E_KDC_UNKNOWN_ETYPE          _HRESULT_TYPEDEF_(0x80090342L)






// An unsupported preauthentication mechanism was presented to the Kerberos package.

SEC_E_UNSUPPORTED_PREAUTH        _HRESULT_TYPEDEF_(0x80090343L)






// The requested operation cannot be completed. The computer must be trusted for delegation and the current user account must be configured to allow delegation.

SEC_E_DELEGATION_REQUIRED        _HRESULT_TYPEDEF_(0x80090345L)






// Client's supplied SSPI channel bindings were incorrect.

SEC_E_BAD_BINDINGS               _HRESULT_TYPEDEF_(0x80090346L)






// The received certificate was mapped to multiple accounts.

SEC_E_MULTIPLE_ACCOUNTS          _HRESULT_TYPEDEF_(0x80090347L)






//  SEC_E_NO_KERB_KEY

SEC_E_NO_KERB_KEY                _HRESULT_TYPEDEF_(0x80090348L)






// The certificate is not valid for the requested usage.

SEC_E_CERT_WRONG_USAGE           _HRESULT_TYPEDEF_(0x80090349L)






// The system cannot contact a domain controller to service the authentication request. Please try again later.

SEC_E_DOWNGRADE_DETECTED         _HRESULT_TYPEDEF_(0x80090350L)






// The smartcard certificate used for authentication has been revoked. Please contact your system administrator. There may be additional information in the event log.

SEC_E_SMARTCARD_CERT_REVOKED     _HRESULT_TYPEDEF_(0x80090351L)






// An untrusted certificate authority was detected while processing the smartcard certificate used for authentication. Please contact your system administrator.

SEC_E_ISSUING_CA_UNTRUSTED       _HRESULT_TYPEDEF_(0x80090352L)






// The revocation status of the smartcard certificate used for authentication could not be determined. Please contact your system administrator.

SEC_E_REVOCATION_OFFLINE_C       _HRESULT_TYPEDEF_(0x80090353L)






// The smartcard certificate used for authentication was not trusted. Please contact your system administrator.

SEC_E_PKINIT_CLIENT_FAILURE      _HRESULT_TYPEDEF_(0x80090354L)






// The smartcard certificate used for authentication has expired. Please contact your system administrator.

SEC_E_SMARTCARD_CERT_EXPIRED     _HRESULT_TYPEDEF_(0x80090355L)






// The Kerberos subsystem encountered an error. A service for user protocol request was made against a domain controller which does not support service for user.

SEC_E_NO_S4U_PROT_SUPPORT        _HRESULT_TYPEDEF_(0x80090356L)






// An attempt was made by this server to make a Kerberos constrained delegation request for a target outside of the server's realm. This is not supported, and indicates a misconfiguration on this server's allowed to delegate to list. Please contact your administrator.

SEC_E_CROSSREALM_DELEGATION_FAILURE _HRESULT_TYPEDEF_(0x80090357L)






// The revocation status of the domain controller certificate used for smartcard authentication could not be determined. There is additional information in the system event log. Please contact your system administrator.

SEC_E_REVOCATION_OFFLINE_KDC     _HRESULT_TYPEDEF_(0x80090358L)






// An untrusted certificate authority was detected while processing the domain controller certificate used for authentication. There is additional information in the system event log. Please contact your system administrator.

SEC_E_ISSUING_CA_UNTRUSTED_KDC   _HRESULT_TYPEDEF_(0x80090359L)






// The domain controller certificate used for smartcard logon has expired. Please contact your system administrator with the contents of your system event log.

SEC_E_KDC_CERT_EXPIRED           _HRESULT_TYPEDEF_(0x8009035AL)






// The domain controller certificate used for smartcard logon has been revoked. Please contact your system administrator with the contents of your system event log.

SEC_E_KDC_CERT_REVOKED           _HRESULT_TYPEDEF_(0x8009035BL)






// A signature operation must be performed before the user can authenticate.

SEC_I_SIGNATURE_NEEDED           _HRESULT_TYPEDEF_(0x0009035CL)






// One or more of the parameters passed to the function was invalid.

SEC_E_INVALID_PARAMETER          _HRESULT_TYPEDEF_(0x8009035DL)






// Client policy does not allow credential delegation to target server.

SEC_E_DELEGATION_POLICY          _HRESULT_TYPEDEF_(0x8009035EL)






// Client policy does not allow credential delegation to target server with NLTM only authentication.

SEC_E_POLICY_NLTM_ONLY           _HRESULT_TYPEDEF_(0x8009035FL)






// The recipient rejected the renegotiation request.

SEC_I_NO_RENEGOTIATION           _HRESULT_TYPEDEF_(0x00090360L)






// The required security context does not exist.

SEC_E_NO_CONTEXT                 _HRESULT_TYPEDEF_(0x80090361L)






// The PKU2U protocol encountered an error while attempting to utilize the associated certificates.

SEC_E_PKU2U_CERT_FAILURE         _HRESULT_TYPEDEF_(0x80090362L)






// The identity of the server computer could not be verified.

SEC_E_MUTUAL_AUTH_FAILED         _HRESULT_TYPEDEF_(0x80090363L)






// The returned buffer is only a fragment of the message.  More fragments need to be returned.

SEC_I_MESSAGE_FRAGMENT           _HRESULT_TYPEDEF_(0x00090364L)






// Only https scheme is allowed.

SEC_E_ONLY_HTTPS_ALLOWED         _HRESULT_TYPEDEF_(0x80090365L)






// The function completed successfully, but must be called again to complete the context.  Early start can be used.

SEC_I_CONTINUE_NEEDED_MESSAGE_OK _HRESULT_TYPEDEF_(0x00090366L)






// No common application protocol exists between the client and the server. Application protocol negotiation failed.

SEC_E_APPLICATION_PROTOCOL_MISMATCH _HRESULT_TYPEDEF_(0x80090367L)






// An asynchronous SSPI routine has been called and the work is pending completion.

SEC_I_ASYNC_CALL_PENDING         _HRESULT_TYPEDEF_(0x00090368L)






// You can't sign in with a user ID in this format. Try using your email address instead.

SEC_E_INVALID_UPN_NAME           _HRESULT_TYPEDEF_(0x80090369L)






// The buffer supplied by the SSPI caller to receive generic extensions is too small.

SEC_E_EXT_BUFFER_TOO_SMALL       _HRESULT_TYPEDEF_(0x8009036AL)






// Not enough secbuffers were supplied to generate a token.

SEC_E_INSUFFICIENT_BUFFERS       _HRESULT_TYPEDEF_(0x8009036BL)


// Provided for backwards compatibility


SEC_E_NO_SPM SEC_E_INTERNAL_ERROR
SEC_E_NOT_SUPPORTED SEC_E_UNSUPPORTED_FUNCTION






// An error occurred while performing an operation on a cryptographic message.

CRYPT_E_MSG_ERROR                _HRESULT_TYPEDEF_(0x80091001L)






// Unknown cryptographic algorithm.

CRYPT_E_UNKNOWN_ALGO             _HRESULT_TYPEDEF_(0x80091002L)






// The object identifier is poorly formatted.

CRYPT_E_OID_FORMAT               _HRESULT_TYPEDEF_(0x80091003L)






// Invalid cryptographic message type.

CRYPT_E_INVALID_MSG_TYPE         _HRESULT_TYPEDEF_(0x80091004L)






// Unexpected cryptographic message encoding.

CRYPT_E_UNEXPECTED_ENCODING      _HRESULT_TYPEDEF_(0x80091005L)






// The cryptographic message does not contain an expected authenticated attribute.

CRYPT_E_AUTH_ATTR_MISSING        _HRESULT_TYPEDEF_(0x80091006L)






// The hash value is not correct.

CRYPT_E_HASH_VALUE               _HRESULT_TYPEDEF_(0x80091007L)






// The index value is not valid.

CRYPT_E_INVALID_INDEX            _HRESULT_TYPEDEF_(0x80091008L)






// The content of the cryptographic message has already been decrypted.

CRYPT_E_ALREADY_DECRYPTED        _HRESULT_TYPEDEF_(0x80091009L)






// The content of the cryptographic message has not been decrypted yet.

CRYPT_E_NOT_DECRYPTED            _HRESULT_TYPEDEF_(0x8009100AL)






// The enveloped-data message does not contain the specified recipient.

CRYPT_E_RECIPIENT_NOT_FOUND      _HRESULT_TYPEDEF_(0x8009100BL)






// Invalid control type.

CRYPT_E_CONTROL_TYPE             _HRESULT_TYPEDEF_(0x8009100CL)






// Invalid issuer and/or serial number.

CRYPT_E_ISSUER_SERIALNUMBER      _HRESULT_TYPEDEF_(0x8009100DL)






// Cannot find the original signer.

CRYPT_E_SIGNER_NOT_FOUND         _HRESULT_TYPEDEF_(0x8009100EL)






// The cryptographic message does not contain all of the requested attributes.

CRYPT_E_ATTRIBUTES_MISSING       _HRESULT_TYPEDEF_(0x8009100FL)






// The streamed cryptographic message is not ready to return data.

CRYPT_E_STREAM_MSG_NOT_READY     _HRESULT_TYPEDEF_(0x80091010L)






// The streamed cryptographic message requires more data to complete the decode operation.

CRYPT_E_STREAM_INSUFFICIENT_DATA _HRESULT_TYPEDEF_(0x80091011L)






// The protected data needs to be re-protected.

CRYPT_I_NEW_PROTECTION_REQUIRED  _HRESULT_TYPEDEF_(0x00091012L)






// The length specified for the output data was insufficient.

CRYPT_E_BAD_LEN                  _HRESULT_TYPEDEF_(0x80092001L)






// An error occurred during encode or decode operation.

CRYPT_E_BAD_ENCODE               _HRESULT_TYPEDEF_(0x80092002L)






// An error occurred while reading or writing to a file.

CRYPT_E_FILE_ERROR               _HRESULT_TYPEDEF_(0x80092003L)






// Cannot find object or property.

CRYPT_E_NOT_FOUND                _HRESULT_TYPEDEF_(0x80092004L)






// The object or property already exists.

CRYPT_E_EXISTS                   _HRESULT_TYPEDEF_(0x80092005L)






// No provider was specified for the store or object.

CRYPT_E_NO_PROVIDER              _HRESULT_TYPEDEF_(0x80092006L)






// The specified certificate is self signed.

CRYPT_E_SELF_SIGNED              _HRESULT_TYPEDEF_(0x80092007L)






// The previous certificate or CRL context was deleted.

CRYPT_E_DELETED_PREV             _HRESULT_TYPEDEF_(0x80092008L)






// Cannot find the requested object.

CRYPT_E_NO_MATCH                 _HRESULT_TYPEDEF_(0x80092009L)






// The certificate does not have a property that references a private key.

CRYPT_E_UNEXPECTED_MSG_TYPE      _HRESULT_TYPEDEF_(0x8009200AL)






// Cannot find the certificate and private key for decryption.

CRYPT_E_NO_KEY_PROPERTY          _HRESULT_TYPEDEF_(0x8009200BL)






// Cannot find the certificate and private key to use for decryption.

CRYPT_E_NO_DECRYPT_CERT          _HRESULT_TYPEDEF_(0x8009200CL)






// Not a cryptographic message or the cryptographic message is not formatted correctly.

CRYPT_E_BAD_MSG                  _HRESULT_TYPEDEF_(0x8009200DL)






// The signed cryptographic message does not have a signer for the specified signer index.

CRYPT_E_NO_SIGNER                _HRESULT_TYPEDEF_(0x8009200EL)






// Final closure is pending until additional frees or closes.

CRYPT_E_PENDING_CLOSE            _HRESULT_TYPEDEF_(0x8009200FL)






// The certificate is revoked.

CRYPT_E_REVOKED                  _HRESULT_TYPEDEF_(0x80092010L)






// No Dll or exported function was found to verify revocation.

CRYPT_E_NO_REVOCATION_DLL        _HRESULT_TYPEDEF_(0x80092011L)






// The revocation function was unable to check revocation for the certificate.

CRYPT_E_NO_REVOCATION_CHECK      _HRESULT_TYPEDEF_(0x80092012L)






// The revocation function was unable to check revocation because the revocation server was offline.

CRYPT_E_REVOCATION_OFFLINE       _HRESULT_TYPEDEF_(0x80092013L)






// The certificate is not in the revocation server's database.

CRYPT_E_NOT_IN_REVOCATION_DATABASE _HRESULT_TYPEDEF_(0x80092014L)






// The string contains a non-numeric character.

CRYPT_E_INVALID_NUMERIC_STRING   _HRESULT_TYPEDEF_(0x80092020L)






// The string contains a non-printable character.

CRYPT_E_INVALID_PRINTABLE_STRING _HRESULT_TYPEDEF_(0x80092021L)






// The string contains a character not in the 7 bit ASCII character set.

CRYPT_E_INVALID_IA5_STRING       _HRESULT_TYPEDEF_(0x80092022L)






// The string contains an invalid X500 name attribute key, oid, value or delimiter.

CRYPT_E_INVALID_X500_STRING      _HRESULT_TYPEDEF_(0x80092023L)






// The dwValueType for the CERT_NAME_VALUE is not one of the character strings. Most likely it is either a CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING.

CRYPT_E_NOT_CHAR_STRING          _HRESULT_TYPEDEF_(0x80092024L)






// The Put operation cannot continue. The file needs to be resized. However, there is already a signature present. A complete signing operation must be done.

CRYPT_E_FILERESIZED              _HRESULT_TYPEDEF_(0x80092025L)






// The cryptographic operation failed due to a local security option setting.

CRYPT_E_SECURITY_SETTINGS        _HRESULT_TYPEDEF_(0x80092026L)






// No DLL or exported function was found to verify subject usage.

CRYPT_E_NO_VERIFY_USAGE_DLL      _HRESULT_TYPEDEF_(0x80092027L)






// The called function was unable to do a usage check on the subject.

CRYPT_E_NO_VERIFY_USAGE_CHECK    _HRESULT_TYPEDEF_(0x80092028L)






// Since the server was offline, the called function was unable to complete the usage check.

CRYPT_E_VERIFY_USAGE_OFFLINE     _HRESULT_TYPEDEF_(0x80092029L)






// The subject was not found in a Certificate Trust List (CTL).

CRYPT_E_NOT_IN_CTL               _HRESULT_TYPEDEF_(0x8009202AL)






// None of the signers of the cryptographic message or certificate trust list is trusted.

CRYPT_E_NO_TRUSTED_SIGNER        _HRESULT_TYPEDEF_(0x8009202BL)






// The public key's algorithm parameters are missing.

CRYPT_E_MISSING_PUBKEY_PARA      _HRESULT_TYPEDEF_(0x8009202CL)






// An object could not be located using the object locator infrastructure with the given name.

CRYPT_E_OBJECT_LOCATOR_OBJECT_NOT_FOUND _HRESULT_TYPEDEF_(0x8009202DL)






// OSS Certificate encode/decode error code base
// 
// See asn1code.h for a definition of the OSS runtime errors. The OSS error values are offset by CRYPT_E_OSS_ERROR.

CRYPT_E_OSS_ERROR                _HRESULT_TYPEDEF_(0x80093000L)






// OSS ASN.1 Error: Output Buffer is too small.

OSS_MORE_BUF                     _HRESULT_TYPEDEF_(0x80093001L)






// OSS ASN.1 Error: Signed integer is encoded as a unsigned integer.

OSS_NEGATIVE_UINTEGER            _HRESULT_TYPEDEF_(0x80093002L)






// OSS ASN.1 Error: Unknown ASN.1 data type.

OSS_PDU_RANGE                    _HRESULT_TYPEDEF_(0x80093003L)






// OSS ASN.1 Error: Output buffer is too small, the decoded data has been truncated.

OSS_MORE_INPUT                   _HRESULT_TYPEDEF_(0x80093004L)






// OSS ASN.1 Error: Invalid data.

OSS_DATA_ERROR                   _HRESULT_TYPEDEF_(0x80093005L)






// OSS ASN.1 Error: Invalid argument.

OSS_BAD_ARG                      _HRESULT_TYPEDEF_(0x80093006L)






// OSS ASN.1 Error: Encode/Decode version mismatch.

OSS_BAD_VERSION                  _HRESULT_TYPEDEF_(0x80093007L)






// OSS ASN.1 Error: Out of memory.

OSS_OUT_MEMORY                   _HRESULT_TYPEDEF_(0x80093008L)






// OSS ASN.1 Error: Encode/Decode Error.

OSS_PDU_MISMATCH                 _HRESULT_TYPEDEF_(0x80093009L)






// OSS ASN.1 Error: Internal Error.

OSS_LIMITED                      _HRESULT_TYPEDEF_(0x8009300AL)






// OSS ASN.1 Error: Invalid data.

OSS_BAD_PTR                      _HRESULT_TYPEDEF_(0x8009300BL)






// OSS ASN.1 Error: Invalid data.

OSS_BAD_TIME                     _HRESULT_TYPEDEF_(0x8009300CL)






// OSS ASN.1 Error: Unsupported BER indefinite-length encoding.

OSS_INDEFINITE_NOT_SUPPORTED     _HRESULT_TYPEDEF_(0x8009300DL)






// OSS ASN.1 Error: Access violation.

OSS_MEM_ERROR                    _HRESULT_TYPEDEF_(0x8009300EL)






// OSS ASN.1 Error: Invalid data.

OSS_BAD_TABLE                    _HRESULT_TYPEDEF_(0x8009300FL)






// OSS ASN.1 Error: Invalid data.

OSS_TOO_LONG                     _HRESULT_TYPEDEF_(0x80093010L)






// OSS ASN.1 Error: Invalid data.

OSS_CONSTRAINT_VIOLATED          _HRESULT_TYPEDEF_(0x80093011L)






// OSS ASN.1 Error: Internal Error.

OSS_FATAL_ERROR                  _HRESULT_TYPEDEF_(0x80093012L)






// OSS ASN.1 Error: Multi-threading conflict.

OSS_ACCESS_SERIALIZATION_ERROR   _HRESULT_TYPEDEF_(0x80093013L)






// OSS ASN.1 Error: Invalid data.

OSS_NULL_TBL                     _HRESULT_TYPEDEF_(0x80093014L)






// OSS ASN.1 Error: Invalid data.

OSS_NULL_FCN                     _HRESULT_TYPEDEF_(0x80093015L)






// OSS ASN.1 Error: Invalid data.

OSS_BAD_ENCRULES                 _HRESULT_TYPEDEF_(0x80093016L)






// OSS ASN.1 Error: Encode/Decode function not implemented.

OSS_UNAVAIL_ENCRULES             _HRESULT_TYPEDEF_(0x80093017L)






// OSS ASN.1 Error: Trace file error.

OSS_CANT_OPEN_TRACE_WINDOW       _HRESULT_TYPEDEF_(0x80093018L)






// OSS ASN.1 Error: Function not implemented.

OSS_UNIMPLEMENTED                _HRESULT_TYPEDEF_(0x80093019L)






// OSS ASN.1 Error: Program link error.

OSS_OID_DLL_NOT_LINKED           _HRESULT_TYPEDEF_(0x8009301AL)






// OSS ASN.1 Error: Trace file error.

OSS_CANT_OPEN_TRACE_FILE         _HRESULT_TYPEDEF_(0x8009301BL)






// OSS ASN.1 Error: Trace file error.

OSS_TRACE_FILE_ALREADY_OPEN      _HRESULT_TYPEDEF_(0x8009301CL)






// OSS ASN.1 Error: Invalid data.

OSS_TABLE_MISMATCH               _HRESULT_TYPEDEF_(0x8009301DL)






// OSS ASN.1 Error: Invalid data.

OSS_TYPE_NOT_SUPPORTED           _HRESULT_TYPEDEF_(0x8009301EL)






// OSS ASN.1 Error: Program link error.

OSS_REAL_DLL_NOT_LINKED          _HRESULT_TYPEDEF_(0x8009301FL)






// OSS ASN.1 Error: Program link error.

OSS_REAL_CODE_NOT_LINKED         _HRESULT_TYPEDEF_(0x80093020L)






// OSS ASN.1 Error: Program link error.

OSS_OUT_OF_RANGE                 _HRESULT_TYPEDEF_(0x80093021L)






// OSS ASN.1 Error: Program link error.

OSS_COPIER_DLL_NOT_LINKED        _HRESULT_TYPEDEF_(0x80093022L)






// OSS ASN.1 Error: Program link error.

OSS_CONSTRAINT_DLL_NOT_LINKED    _HRESULT_TYPEDEF_(0x80093023L)






// OSS ASN.1 Error: Program link error.

OSS_COMPARATOR_DLL_NOT_LINKED    _HRESULT_TYPEDEF_(0x80093024L)






// OSS ASN.1 Error: Program link error.

OSS_COMPARATOR_CODE_NOT_LINKED   _HRESULT_TYPEDEF_(0x80093025L)






// OSS ASN.1 Error: Program link error.

OSS_MEM_MGR_DLL_NOT_LINKED       _HRESULT_TYPEDEF_(0x80093026L)






// OSS ASN.1 Error: Program link error.

OSS_PDV_DLL_NOT_LINKED           _HRESULT_TYPEDEF_(0x80093027L)






// OSS ASN.1 Error: Program link error.

OSS_PDV_CODE_NOT_LINKED          _HRESULT_TYPEDEF_(0x80093028L)






// OSS ASN.1 Error: Program link error.

OSS_API_DLL_NOT_LINKED           _HRESULT_TYPEDEF_(0x80093029L)






// OSS ASN.1 Error: Program link error.

OSS_BERDER_DLL_NOT_LINKED        _HRESULT_TYPEDEF_(0x8009302AL)






// OSS ASN.1 Error: Program link error.

OSS_PER_DLL_NOT_LINKED           _HRESULT_TYPEDEF_(0x8009302BL)






// OSS ASN.1 Error: Program link error.

OSS_OPEN_TYPE_ERROR              _HRESULT_TYPEDEF_(0x8009302CL)






// OSS ASN.1 Error: System resource error.

OSS_MUTEX_NOT_CREATED            _HRESULT_TYPEDEF_(0x8009302DL)






// OSS ASN.1 Error: Trace file error.

OSS_CANT_CLOSE_TRACE_FILE        _HRESULT_TYPEDEF_(0x8009302EL)






// ASN1 Certificate encode/decode error code base. The ASN1 error values are offset by CRYPT_E_ASN1_ERROR.

CRYPT_E_ASN1_ERROR               _HRESULT_TYPEDEF_(0x80093100L)






// ASN1 internal encode or decode error.

CRYPT_E_ASN1_INTERNAL            _HRESULT_TYPEDEF_(0x80093101L)






// ASN1 unexpected end of data.

CRYPT_E_ASN1_EOD                 _HRESULT_TYPEDEF_(0x80093102L)






// ASN1 corrupted data.

CRYPT_E_ASN1_CORRUPT             _HRESULT_TYPEDEF_(0x80093103L)






// ASN1 value too large.

CRYPT_E_ASN1_LARGE               _HRESULT_TYPEDEF_(0x80093104L)






// ASN1 constraint violated.

CRYPT_E_ASN1_CONSTRAINT          _HRESULT_TYPEDEF_(0x80093105L)






// ASN1 out of memory.

CRYPT_E_ASN1_MEMORY              _HRESULT_TYPEDEF_(0x80093106L)






// ASN1 buffer overflow.

CRYPT_E_ASN1_OVERFLOW            _HRESULT_TYPEDEF_(0x80093107L)






// ASN1 function not supported for this PDU.

CRYPT_E_ASN1_BADPDU              _HRESULT_TYPEDEF_(0x80093108L)






// ASN1 bad arguments to function call.

CRYPT_E_ASN1_BADARGS             _HRESULT_TYPEDEF_(0x80093109L)






// ASN1 bad real value.

CRYPT_E_ASN1_BADREAL             _HRESULT_TYPEDEF_(0x8009310AL)






// ASN1 bad tag value met.

CRYPT_E_ASN1_BADTAG              _HRESULT_TYPEDEF_(0x8009310BL)






// ASN1 bad choice value.

CRYPT_E_ASN1_CHOICE              _HRESULT_TYPEDEF_(0x8009310CL)






// ASN1 bad encoding rule.

CRYPT_E_ASN1_RULE                _HRESULT_TYPEDEF_(0x8009310DL)






// ASN1 bad unicode (UTF8).

CRYPT_E_ASN1_UTF8                _HRESULT_TYPEDEF_(0x8009310EL)






// ASN1 bad PDU type.

CRYPT_E_ASN1_PDU_TYPE            _HRESULT_TYPEDEF_(0x80093133L)






// ASN1 not yet implemented.

CRYPT_E_ASN1_NYI                 _HRESULT_TYPEDEF_(0x80093134L)






// ASN1 skipped unknown extension(s).

CRYPT_E_ASN1_EXTENDED            _HRESULT_TYPEDEF_(0x80093201L)






// ASN1 end of data expected

CRYPT_E_ASN1_NOEOD               _HRESULT_TYPEDEF_(0x80093202L)






// The request subject name is invalid or too long.

CERTSRV_E_BAD_REQUESTSUBJECT     _HRESULT_TYPEDEF_(0x80094001L)






// The request does not exist.

CERTSRV_E_NO_REQUEST             _HRESULT_TYPEDEF_(0x80094002L)






// The request's current status does not allow this operation.

CERTSRV_E_BAD_REQUESTSTATUS      _HRESULT_TYPEDEF_(0x80094003L)






// The requested property value is empty.

CERTSRV_E_PROPERTY_EMPTY         _HRESULT_TYPEDEF_(0x80094004L)






// The certification authority's certificate contains invalid data.

CERTSRV_E_INVALID_CA_CERTIFICATE _HRESULT_TYPEDEF_(0x80094005L)






// Certificate service has been suspended for a database restore operation.

CERTSRV_E_SERVER_SUSPENDED       _HRESULT_TYPEDEF_(0x80094006L)






// The certificate contains an encoded length that is potentially incompatible with older enrollment software.

CERTSRV_E_ENCODING_LENGTH        _HRESULT_TYPEDEF_(0x80094007L)






// The operation is denied. The user has multiple roles assigned and the certification authority is configured to enforce role separation.

CERTSRV_E_ROLECONFLICT           _HRESULT_TYPEDEF_(0x80094008L)






// The operation is denied. It can only be performed by a certificate manager that is allowed to manage certificates for the current requester.

CERTSRV_E_RESTRICTEDOFFICER      _HRESULT_TYPEDEF_(0x80094009L)






// Cannot archive private key. The certification authority is not configured for key archival.

CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED _HRESULT_TYPEDEF_(0x8009400AL)






// Cannot archive private key. The certification authority could not verify one or more key recovery certificates.

CERTSRV_E_NO_VALID_KRA           _HRESULT_TYPEDEF_(0x8009400BL)






// The request is incorrectly formatted. The encrypted private key must be in an unauthenticated attribute in an outermost signature.

CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL _HRESULT_TYPEDEF_(0x8009400CL)






// At least one security principal must have the permission to manage this CA.

CERTSRV_E_NO_CAADMIN_DEFINED     _HRESULT_TYPEDEF_(0x8009400DL)






// The request contains an invalid renewal certificate attribute.

CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE _HRESULT_TYPEDEF_(0x8009400EL)






// An attempt was made to open a Certification Authority database session, but there are already too many active sessions. The server may need to be configured to allow additional sessions.

CERTSRV_E_NO_DB_SESSIONS         _HRESULT_TYPEDEF_(0x8009400FL)






// A memory reference caused a data alignment fault.

CERTSRV_E_ALIGNMENT_FAULT        _HRESULT_TYPEDEF_(0x80094010L)






// The permissions on this certification authority do not allow the current user to enroll for certificates.

CERTSRV_E_ENROLL_DENIED          _HRESULT_TYPEDEF_(0x80094011L)






// The permissions on the certificate template do not allow the current user to enroll for this type of certificate.

CERTSRV_E_TEMPLATE_DENIED        _HRESULT_TYPEDEF_(0x80094012L)






// The contacted domain controller cannot support signed LDAP traffic. Update the domain controller or configure Certificate Services to use SSL for Active Directory access.

CERTSRV_E_DOWNLEVEL_DC_SSL_OR_UPGRADE _HRESULT_TYPEDEF_(0x80094013L)






// The request was denied by a certificate manager or CA administrator.

CERTSRV_E_ADMIN_DENIED_REQUEST   _HRESULT_TYPEDEF_(0x80094014L)






// An enrollment policy server cannot be located.

CERTSRV_E_NO_POLICY_SERVER       _HRESULT_TYPEDEF_(0x80094015L)






// A signature algorithm or public key length does not meet the system's minimum required strength.

CERTSRV_E_WEAK_SIGNATURE_OR_KEY  _HRESULT_TYPEDEF_(0x80094016L)






// Failed to create an attested key.  This computer or the cryptographic provider may not meet the hardware requirements to support key attestation.

CERTSRV_E_KEY_ATTESTATION_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80094017L)






// No encryption certificate was specified.

CERTSRV_E_ENCRYPTION_CERT_REQUIRED _HRESULT_TYPEDEF_(0x80094018L)






// The requested certificate template is not supported by this CA.

CERTSRV_E_UNSUPPORTED_CERT_TYPE  _HRESULT_TYPEDEF_(0x80094800L)






// The request contains no certificate template information.

CERTSRV_E_NO_CERT_TYPE           _HRESULT_TYPEDEF_(0x80094801L)






// The request contains conflicting template information.

CERTSRV_E_TEMPLATE_CONFLICT      _HRESULT_TYPEDEF_(0x80094802L)






// The request is missing a required Subject Alternate name extension.

CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED _HRESULT_TYPEDEF_(0x80094803L)






// The request is missing a required private key for archival by the server.

CERTSRV_E_ARCHIVED_KEY_REQUIRED  _HRESULT_TYPEDEF_(0x80094804L)






// The request is missing a required SMIME capabilities extension.

CERTSRV_E_SMIME_REQUIRED         _HRESULT_TYPEDEF_(0x80094805L)






// The request was made on behalf of a subject other than the caller. The certificate template must be configured to require at least one signature to authorize the request.

CERTSRV_E_BAD_RENEWAL_SUBJECT    _HRESULT_TYPEDEF_(0x80094806L)






// The request template version is newer than the supported template version.

CERTSRV_E_BAD_TEMPLATE_VERSION   _HRESULT_TYPEDEF_(0x80094807L)






// The template is missing a required signature policy attribute.

CERTSRV_E_TEMPLATE_POLICY_REQUIRED _HRESULT_TYPEDEF_(0x80094808L)






// The request is missing required signature policy information.

CERTSRV_E_SIGNATURE_POLICY_REQUIRED _HRESULT_TYPEDEF_(0x80094809L)






// The request is missing one or more required signatures.

CERTSRV_E_SIGNATURE_COUNT        _HRESULT_TYPEDEF_(0x8009480AL)






// One or more signatures did not include the required application or issuance policies. The request is missing one or more required valid signatures.

CERTSRV_E_SIGNATURE_REJECTED     _HRESULT_TYPEDEF_(0x8009480BL)






// The request is missing one or more required signature issuance policies.

CERTSRV_E_ISSUANCE_POLICY_REQUIRED _HRESULT_TYPEDEF_(0x8009480CL)






// The UPN is unavailable and cannot be added to the Subject Alternate name.

CERTSRV_E_SUBJECT_UPN_REQUIRED   _HRESULT_TYPEDEF_(0x8009480DL)






// The Active Directory GUID is unavailable and cannot be added to the Subject Alternate name.

CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED _HRESULT_TYPEDEF_(0x8009480EL)






// The DNS name is unavailable and cannot be added to the Subject Alternate name.

CERTSRV_E_SUBJECT_DNS_REQUIRED   _HRESULT_TYPEDEF_(0x8009480FL)






// The request includes a private key for archival by the server, but key archival is not enabled for the specified certificate template.

CERTSRV_E_ARCHIVED_KEY_UNEXPECTED _HRESULT_TYPEDEF_(0x80094810L)






// The public key does not meet the minimum size required by the specified certificate template.

CERTSRV_E_KEY_LENGTH             _HRESULT_TYPEDEF_(0x80094811L)






// The EMail name is unavailable and cannot be added to the Subject or Subject Alternate name.

CERTSRV_E_SUBJECT_EMAIL_REQUIRED _HRESULT_TYPEDEF_(0x80094812L)






// One or more certificate templates to be enabled on this certification authority could not be found.

CERTSRV_E_UNKNOWN_CERT_TYPE      _HRESULT_TYPEDEF_(0x80094813L)






// The certificate template renewal period is longer than the certificate validity period. The template should be reconfigured or the CA certificate renewed.

CERTSRV_E_CERT_TYPE_OVERLAP      _HRESULT_TYPEDEF_(0x80094814L)






// The certificate template requires too many RA signatures. Only one RA signature is allowed.

CERTSRV_E_TOO_MANY_SIGNATURES    _HRESULT_TYPEDEF_(0x80094815L)






// The certificate template requires renewal with the same public key, but the request uses a different public key.

CERTSRV_E_RENEWAL_BAD_PUBLIC_KEY _HRESULT_TYPEDEF_(0x80094816L)






// The certification authority cannot interpret or verify the endorsement key information supplied in the request, or the information is inconsistent.

CERTSRV_E_INVALID_EK             _HRESULT_TYPEDEF_(0x80094817L)






// The certification authority cannot validate the Attestation Identity Key Id Binding.

CERTSRV_E_INVALID_IDBINDING      _HRESULT_TYPEDEF_(0x80094818L)






// The certification authority cannot validate the private key attestation data.

CERTSRV_E_INVALID_ATTESTATION    _HRESULT_TYPEDEF_(0x80094819L)






// The request does not support private key attestation as defined in the certificate template.

CERTSRV_E_KEY_ATTESTATION        _HRESULT_TYPEDEF_(0x8009481AL)






// The request public key is not consistent with the private key attestation data.

CERTSRV_E_CORRUPT_KEY_ATTESTATION _HRESULT_TYPEDEF_(0x8009481BL)






// The private key attestation challenge cannot be validated because the encryption certificate has expired, or the certificate or key is unavailable.

CERTSRV_E_EXPIRED_CHALLENGE      _HRESULT_TYPEDEF_(0x8009481CL)






// The client's response could not be validated. It is either unexpected or incorrect.

CERTSRV_E_INVALID_RESPONSE       _HRESULT_TYPEDEF_(0x8009481DL)






// A valid Request ID was not detected in the request attributes, or an invalid one was submitted.

CERTSRV_E_INVALID_REQUESTID      _HRESULT_TYPEDEF_(0x8009481EL)






// The request is not consistent with the previously generated precertificate.

CERTSRV_E_REQUEST_PRECERTIFICATE_MISMATCH _HRESULT_TYPEDEF_(0x8009481FL)






// The request is locked against edits until a response is received from the client.

CERTSRV_E_PENDING_CLIENT_RESPONSE _HRESULT_TYPEDEF_(0x80094820L)


// The range 0x5000-0x51ff is reserved for XENROLL errors.






// The key is not exportable.

XENROLL_E_KEY_NOT_EXPORTABLE     _HRESULT_TYPEDEF_(0x80095000L)






// You cannot add the root CA certificate into your local store.

XENROLL_E_CANNOT_ADD_ROOT_CERT   _HRESULT_TYPEDEF_(0x80095001L)






// The key archival hash attribute was not found in the response.

XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND _HRESULT_TYPEDEF_(0x80095002L)






// An unexpected key archival hash attribute was found in the response.

XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH _HRESULT_TYPEDEF_(0x80095003L)






// There is a key archival hash mismatch between the request and the response.

XENROLL_E_RESPONSE_KA_HASH_MISMATCH _HRESULT_TYPEDEF_(0x80095004L)






// Signing certificate cannot include SMIME extension.

XENROLL_E_KEYSPEC_SMIME_MISMATCH _HRESULT_TYPEDEF_(0x80095005L)






// A system-level error occurred while verifying trust.

TRUST_E_SYSTEM_ERROR             _HRESULT_TYPEDEF_(0x80096001L)






// The certificate for the signer of the message is invalid or not found.

TRUST_E_NO_SIGNER_CERT           _HRESULT_TYPEDEF_(0x80096002L)






// One of the counter signatures was invalid.

TRUST_E_COUNTER_SIGNER           _HRESULT_TYPEDEF_(0x80096003L)






// The signature of the certificate cannot be verified.

TRUST_E_CERT_SIGNATURE           _HRESULT_TYPEDEF_(0x80096004L)






// The timestamp signature and/or certificate could not be verified or is malformed.

TRUST_E_TIME_STAMP               _HRESULT_TYPEDEF_(0x80096005L)






// The digital signature of the object did not verify.

TRUST_E_BAD_DIGEST               _HRESULT_TYPEDEF_(0x80096010L)






// The digital signature of the object is malformed. For technical detail, see security bulletin MS13-098.

TRUST_E_MALFORMED_SIGNATURE      _HRESULT_TYPEDEF_(0x80096011L)






// A certificate's basic constraint extension has not been observed.

TRUST_E_BASIC_CONSTRAINTS        _HRESULT_TYPEDEF_(0x80096019L)






// The certificate does not meet or contain the Authenticode(tm) financial extensions.

TRUST_E_FINANCIAL_CRITERIA       _HRESULT_TYPEDEF_(0x8009601EL)


// Error codes for mssipotf.dll
// Most of the error codes can only occur when an error occurs
//    during font file signing







// Tried to reference a part of the file outside the proper range.

MSSIPOTF_E_OUTOFMEMRANGE         _HRESULT_TYPEDEF_(0x80097001L)






// Could not retrieve an object from the file.

MSSIPOTF_E_CANTGETOBJECT         _HRESULT_TYPEDEF_(0x80097002L)






// Could not find the head table in the file.

MSSIPOTF_E_NOHEADTABLE           _HRESULT_TYPEDEF_(0x80097003L)






// The magic number in the head table is incorrect.

MSSIPOTF_E_BAD_MAGICNUMBER       _HRESULT_TYPEDEF_(0x80097004L)






// The offset table has incorrect values.

MSSIPOTF_E_BAD_OFFSET_TABLE      _HRESULT_TYPEDEF_(0x80097005L)






// Duplicate table tags or tags out of alphabetical order.

MSSIPOTF_E_TABLE_TAGORDER        _HRESULT_TYPEDEF_(0x80097006L)






// A table does not start on a long word boundary.

MSSIPOTF_E_TABLE_LONGWORD        _HRESULT_TYPEDEF_(0x80097007L)






// First table does not appear after header information.

MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT _HRESULT_TYPEDEF_(0x80097008L)






// Two or more tables overlap.

MSSIPOTF_E_TABLES_OVERLAP        _HRESULT_TYPEDEF_(0x80097009L)






// Too many pad bytes between tables or pad bytes are not 0.

MSSIPOTF_E_TABLE_PADBYTES        _HRESULT_TYPEDEF_(0x8009700AL)






// File is too small to contain the last table.

MSSIPOTF_E_FILETOOSMALL          _HRESULT_TYPEDEF_(0x8009700BL)






// A table checksum is incorrect.

MSSIPOTF_E_TABLE_CHECKSUM        _HRESULT_TYPEDEF_(0x8009700CL)






// The file checksum is incorrect.

MSSIPOTF_E_FILE_CHECKSUM         _HRESULT_TYPEDEF_(0x8009700DL)






// The signature does not have the correct attributes for the policy.

MSSIPOTF_E_FAILED_POLICY         _HRESULT_TYPEDEF_(0x80097010L)






// The file did not pass the hints check.

MSSIPOTF_E_FAILED_HINTS_CHECK    _HRESULT_TYPEDEF_(0x80097011L)






// The file is not an OpenType file.

MSSIPOTF_E_NOT_OPENTYPE          _HRESULT_TYPEDEF_(0x80097012L)






// Failed on a file operation (open, map, read, write).

MSSIPOTF_E_FILE                  _HRESULT_TYPEDEF_(0x80097013L)






// A call to a CryptoAPI function failed.

MSSIPOTF_E_CRYPT                 _HRESULT_TYPEDEF_(0x80097014L)






// There is a bad version number in the file.

MSSIPOTF_E_BADVERSION            _HRESULT_TYPEDEF_(0x80097015L)






// The structure of the DSIG table is incorrect.

MSSIPOTF_E_DSIG_STRUCTURE        _HRESULT_TYPEDEF_(0x80097016L)






// A check failed in a partially constant table.

MSSIPOTF_E_PCONST_CHECK          _HRESULT_TYPEDEF_(0x80097017L)






// Some kind of structural error.

MSSIPOTF_E_STRUCTURE             _HRESULT_TYPEDEF_(0x80097018L)






// The requested credential requires confirmation.

ERROR_CRED_REQUIRES_CONFIRMATION _HRESULT_TYPEDEF_(0x80097019L)

NTE_OP_OK 0


// Note that additional FACILITY_SSPI errors are in issperr.h

// ******************
// FACILITY_CERT
// ******************





// Unknown trust provider.

TRUST_E_PROVIDER_UNKNOWN         _HRESULT_TYPEDEF_(0x800B0001L)






// The trust verification action specified is not supported by the specified trust provider.

TRUST_E_ACTION_UNKNOWN           _HRESULT_TYPEDEF_(0x800B0002L)






// The form specified for the subject is not one supported or known by the specified trust provider.

TRUST_E_SUBJECT_FORM_UNKNOWN     _HRESULT_TYPEDEF_(0x800B0003L)






// The subject is not trusted for the specified action.

TRUST_E_SUBJECT_NOT_TRUSTED      _HRESULT_TYPEDEF_(0x800B0004L)






// Error due to problem in ASN.1 encoding process.

DIGSIG_E_ENCODE                  _HRESULT_TYPEDEF_(0x800B0005L)






// Error due to problem in ASN.1 decoding process.

DIGSIG_E_DECODE                  _HRESULT_TYPEDEF_(0x800B0006L)






// Reading / writing Extensions where Attributes are appropriate, and vice versa.

DIGSIG_E_EXTENSIBILITY           _HRESULT_TYPEDEF_(0x800B0007L)






// Unspecified cryptographic failure.

DIGSIG_E_CRYPTO                  _HRESULT_TYPEDEF_(0x800B0008L)






// The size of the data could not be determined.

PERSIST_E_SIZEDEFINITE           _HRESULT_TYPEDEF_(0x800B0009L)






// The size of the indefinite-sized data could not be determined.

PERSIST_E_SIZEINDEFINITE         _HRESULT_TYPEDEF_(0x800B000AL)






// This object does not read and write self-sizing data.

PERSIST_E_NOTSELFSIZING          _HRESULT_TYPEDEF_(0x800B000BL)






// No signature was present in the subject.

TRUST_E_NOSIGNATURE              _HRESULT_TYPEDEF_(0x800B0100L)






// A required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file.

CERT_E_EXPIRED                   _HRESULT_TYPEDEF_(0x800B0101L)






// The validity periods of the certification chain do not nest correctly.

CERT_E_VALIDITYPERIODNESTING     _HRESULT_TYPEDEF_(0x800B0102L)






// A certificate that can only be used as an end-entity is being used as a CA or vice versa.

CERT_E_ROLE                      _HRESULT_TYPEDEF_(0x800B0103L)






// A path length constraint in the certification chain has been violated.

CERT_E_PATHLENCONST              _HRESULT_TYPEDEF_(0x800B0104L)






// A certificate contains an unknown extension that is marked 'critical'.

CERT_E_CRITICAL                  _HRESULT_TYPEDEF_(0x800B0105L)






// A certificate being used for a purpose other than the ones specified by its CA.

CERT_E_PURPOSE                   _HRESULT_TYPEDEF_(0x800B0106L)






// A parent of a given certificate in fact did not issue that child certificate.

CERT_E_ISSUERCHAINING            _HRESULT_TYPEDEF_(0x800B0107L)






// A certificate is missing or has an empty value for an important field, such as a subject or issuer name.

CERT_E_MALFORMED                 _HRESULT_TYPEDEF_(0x800B0108L)






// A certificate chain processed, but terminated in a root certificate which is not trusted by the trust provider.

CERT_E_UNTRUSTEDROOT             _HRESULT_TYPEDEF_(0x800B0109L)






// A certificate chain could not be built to a trusted root authority.

CERT_E_CHAINING                  _HRESULT_TYPEDEF_(0x800B010AL)






// Generic trust failure.

TRUST_E_FAIL                     _HRESULT_TYPEDEF_(0x800B010BL)






// A certificate was explicitly revoked by its issuer.

CERT_E_REVOKED                   _HRESULT_TYPEDEF_(0x800B010CL)






// The certification path terminates with the test root which is not trusted with the current policy settings.

CERT_E_UNTRUSTEDTESTROOT         _HRESULT_TYPEDEF_(0x800B010DL)






// The revocation process could not continue - the certificate(s) could not be checked.

CERT_E_REVOCATION_FAILURE        _HRESULT_TYPEDEF_(0x800B010EL)






// The certificate's CN name does not match the passed value.

CERT_E_CN_NO_MATCH               _HRESULT_TYPEDEF_(0x800B010FL)






// The certificate is not valid for the requested usage.

CERT_E_WRONG_USAGE               _HRESULT_TYPEDEF_(0x800B0110L)






// The certificate was explicitly marked as untrusted by the user.

TRUST_E_EXPLICIT_DISTRUST        _HRESULT_TYPEDEF_(0x800B0111L)






// A certification chain processed correctly, but one of the CA certificates is not trusted by the policy provider.

CERT_E_UNTRUSTEDCA               _HRESULT_TYPEDEF_(0x800B0112L)






// The certificate has invalid policy.

CERT_E_INVALID_POLICY            _HRESULT_TYPEDEF_(0x800B0113L)






// The certificate has an invalid name. The name is not included in the permitted list or is explicitly excluded.

CERT_E_INVALID_NAME              _HRESULT_TYPEDEF_(0x800B0114L)

// *****************
// FACILITY_MEDIASERVER
// *****************

// Also known as FACILITY_MF and FACILITY_NS

// The error codes are defined in mferror.mc, dlnaerror.mc, nserror.mc, and neterror.mc

// *****************
// FACILITY_SETUPAPI
// *****************

// Since these error codes aren't in the standard Win32 range (i.e., 0-64K), define a
// macro to map either Win32 or SetupAPI error codes into an HRESULT.

HRESULT_FROM_SETUPAPI(x) ((((x) & (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR)) == (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR)) \
                                 ? ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_SETUPAPI << 16) | 0x80000000))                               \
                                 : HRESULT_FROM_WIN32(x))





// A non-empty line was encountered in the INF before the start of a section.

SPAPI_E_EXPECTED_SECTION_NAME    _HRESULT_TYPEDEF_(0x800F0000L)






// A section name marker in the INF is not complete, or does not exist on a line by itself.

SPAPI_E_BAD_SECTION_NAME_LINE    _HRESULT_TYPEDEF_(0x800F0001L)






// An INF section was encountered whose name exceeds the maximum section name length.

SPAPI_E_SECTION_NAME_TOO_LONG    _HRESULT_TYPEDEF_(0x800F0002L)






// The syntax of the INF is invalid.

SPAPI_E_GENERAL_SYNTAX           _HRESULT_TYPEDEF_(0x800F0003L)






// The style of the INF is different than what was requested.

SPAPI_E_WRONG_INF_STYLE          _HRESULT_TYPEDEF_(0x800F0100L)






// The required section was not found in the INF.

SPAPI_E_SECTION_NOT_FOUND        _HRESULT_TYPEDEF_(0x800F0101L)






// The required line was not found in the INF.

SPAPI_E_LINE_NOT_FOUND           _HRESULT_TYPEDEF_(0x800F0102L)






// The files affected by the installation of this file queue have not been backed up for uninstall.

SPAPI_E_NO_BACKUP                _HRESULT_TYPEDEF_(0x800F0103L)






// The INF or the device information set or element does not have an associated install class.

SPAPI_E_NO_ASSOCIATED_CLASS      _HRESULT_TYPEDEF_(0x800F0200L)






// The INF or the device information set or element does not match the specified install class.

SPAPI_E_CLASS_MISMATCH           _HRESULT_TYPEDEF_(0x800F0201L)






// An existing device was found that is a duplicate of the device being manually installed.

SPAPI_E_DUPLICATE_FOUND          _HRESULT_TYPEDEF_(0x800F0202L)






// There is no driver selected for the device information set or element.

SPAPI_E_NO_DRIVER_SELECTED       _HRESULT_TYPEDEF_(0x800F0203L)






// The requested device registry key does not exist.

SPAPI_E_KEY_DOES_NOT_EXIST       _HRESULT_TYPEDEF_(0x800F0204L)






// The device instance name is invalid.

SPAPI_E_INVALID_DEVINST_NAME     _HRESULT_TYPEDEF_(0x800F0205L)






// The install class is not present or is invalid.

SPAPI_E_INVALID_CLASS            _HRESULT_TYPEDEF_(0x800F0206L)






// The device instance cannot be created because it already exists.

SPAPI_E_DEVINST_ALREADY_EXISTS   _HRESULT_TYPEDEF_(0x800F0207L)






// The operation cannot be performed on a device information element that has not been registered.

SPAPI_E_DEVINFO_NOT_REGISTERED   _HRESULT_TYPEDEF_(0x800F0208L)






// The device property code is invalid.

SPAPI_E_INVALID_REG_PROPERTY     _HRESULT_TYPEDEF_(0x800F0209L)






// The INF from which a driver list is to be built does not exist.

SPAPI_E_NO_INF                   _HRESULT_TYPEDEF_(0x800F020AL)






// The device instance does not exist in the hardware tree.

SPAPI_E_NO_SUCH_DEVINST          _HRESULT_TYPEDEF_(0x800F020BL)






// The icon representing this install class cannot be loaded.

SPAPI_E_CANT_LOAD_CLASS_ICON     _HRESULT_TYPEDEF_(0x800F020CL)






// The class installer registry entry is invalid.

SPAPI_E_INVALID_CLASS_INSTALLER  _HRESULT_TYPEDEF_(0x800F020DL)






// The class installer has indicated that the default action should be performed for this installation request.

SPAPI_E_DI_DO_DEFAULT            _HRESULT_TYPEDEF_(0x800F020EL)






// The operation does not require any files to be copied.

SPAPI_E_DI_NOFILECOPY            _HRESULT_TYPEDEF_(0x800F020FL)






// The specified hardware profile does not exist.

SPAPI_E_INVALID_HWPROFILE        _HRESULT_TYPEDEF_(0x800F0210L)






// There is no device information element currently selected for this device information set.

SPAPI_E_NO_DEVICE_SELECTED       _HRESULT_TYPEDEF_(0x800F0211L)






// The operation cannot be performed because the device information set is locked.

SPAPI_E_DEVINFO_LIST_LOCKED      _HRESULT_TYPEDEF_(0x800F0212L)






// The operation cannot be performed because the device information element is locked.

SPAPI_E_DEVINFO_DATA_LOCKED      _HRESULT_TYPEDEF_(0x800F0213L)






// The specified path does not contain any applicable device INFs.

SPAPI_E_DI_BAD_PATH              _HRESULT_TYPEDEF_(0x800F0214L)






// No class installer parameters have been set for the device information set or element.

SPAPI_E_NO_CLASSINSTALL_PARAMS   _HRESULT_TYPEDEF_(0x800F0215L)






// The operation cannot be performed because the file queue is locked.

SPAPI_E_FILEQUEUE_LOCKED         _HRESULT_TYPEDEF_(0x800F0216L)






// A service installation section in this INF is invalid.

SPAPI_E_BAD_SERVICE_INSTALLSECT  _HRESULT_TYPEDEF_(0x800F0217L)






// There is no class driver list for the device information element.

SPAPI_E_NO_CLASS_DRIVER_LIST     _HRESULT_TYPEDEF_(0x800F0218L)






// The installation failed because a function driver was not specified for this device instance.

SPAPI_E_NO_ASSOCIATED_SERVICE    _HRESULT_TYPEDEF_(0x800F0219L)






// There is presently no default device interface designated for this interface class.

SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE _HRESULT_TYPEDEF_(0x800F021AL)






// The operation cannot be performed because the device interface is currently active.

SPAPI_E_DEVICE_INTERFACE_ACTIVE  _HRESULT_TYPEDEF_(0x800F021BL)






// The operation cannot be performed because the device interface has been removed from the system.

SPAPI_E_DEVICE_INTERFACE_REMOVED _HRESULT_TYPEDEF_(0x800F021CL)






// An interface installation section in this INF is invalid.

SPAPI_E_BAD_INTERFACE_INSTALLSECT _HRESULT_TYPEDEF_(0x800F021DL)






// This interface class does not exist in the system.

SPAPI_E_NO_SUCH_INTERFACE_CLASS  _HRESULT_TYPEDEF_(0x800F021EL)






// The reference string supplied for this interface device is invalid.

SPAPI_E_INVALID_REFERENCE_STRING _HRESULT_TYPEDEF_(0x800F021FL)






// The specified machine name does not conform to UNC naming conventions.

SPAPI_E_INVALID_MACHINENAME      _HRESULT_TYPEDEF_(0x800F0220L)






// A general remote communication error occurred.

SPAPI_E_REMOTE_COMM_FAILURE      _HRESULT_TYPEDEF_(0x800F0221L)






// The machine selected for remote communication is not available at this time.

SPAPI_E_MACHINE_UNAVAILABLE      _HRESULT_TYPEDEF_(0x800F0222L)






// The Plug and Play service is not available on the remote machine.

SPAPI_E_NO_CONFIGMGR_SERVICES    _HRESULT_TYPEDEF_(0x800F0223L)






// The property page provider registry entry is invalid.

SPAPI_E_INVALID_PROPPAGE_PROVIDER _HRESULT_TYPEDEF_(0x800F0224L)






// The requested device interface is not present in the system.

SPAPI_E_NO_SUCH_DEVICE_INTERFACE _HRESULT_TYPEDEF_(0x800F0225L)






// The device's co-installer has additional work to perform after installation is complete.

SPAPI_E_DI_POSTPROCESSING_REQUIRED _HRESULT_TYPEDEF_(0x800F0226L)






// The device's co-installer is invalid.

SPAPI_E_INVALID_COINSTALLER      _HRESULT_TYPEDEF_(0x800F0227L)






// There are no compatible drivers for this device.

SPAPI_E_NO_COMPAT_DRIVERS        _HRESULT_TYPEDEF_(0x800F0228L)






// There is no icon that represents this device or device type.

SPAPI_E_NO_DEVICE_ICON           _HRESULT_TYPEDEF_(0x800F0229L)






// A logical configuration specified in this INF is invalid.

SPAPI_E_INVALID_INF_LOGCONFIG    _HRESULT_TYPEDEF_(0x800F022AL)






// The class installer has denied the request to install or upgrade this device.

SPAPI_E_DI_DONT_INSTALL          _HRESULT_TYPEDEF_(0x800F022BL)






// One of the filter drivers installed for this device is invalid.

SPAPI_E_INVALID_FILTER_DRIVER    _HRESULT_TYPEDEF_(0x800F022CL)






// The driver selected for this device does not support this version of Windows.

SPAPI_E_NON_WINDOWS_NT_DRIVER    _HRESULT_TYPEDEF_(0x800F022DL)






// The driver selected for this device does not support Windows.

SPAPI_E_NON_WINDOWS_DRIVER       _HRESULT_TYPEDEF_(0x800F022EL)






// The third-party INF does not contain digital signature information.

SPAPI_E_NO_CATALOG_FOR_OEM_INF   _HRESULT_TYPEDEF_(0x800F022FL)






// An invalid attempt was made to use a device installation file queue for verification of digital signatures relative to other platforms.

SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE _HRESULT_TYPEDEF_(0x800F0230L)






// The device cannot be disabled.

SPAPI_E_NOT_DISABLEABLE          _HRESULT_TYPEDEF_(0x800F0231L)






// The device could not be dynamically removed.

SPAPI_E_CANT_REMOVE_DEVINST      _HRESULT_TYPEDEF_(0x800F0232L)






// Cannot copy to specified target.

SPAPI_E_INVALID_TARGET           _HRESULT_TYPEDEF_(0x800F0233L)






// Driver is not intended for this platform.

SPAPI_E_DRIVER_NONNATIVE         _HRESULT_TYPEDEF_(0x800F0234L)






// Operation not allowed in WOW64.

SPAPI_E_IN_WOW64                 _HRESULT_TYPEDEF_(0x800F0235L)






// The operation involving unsigned file copying was rolled back, so that a system restore point could be set.

SPAPI_E_SET_SYSTEM_RESTORE_POINT _HRESULT_TYPEDEF_(0x800F0236L)






// An INF was copied into the Windows INF directory in an improper manner.

SPAPI_E_INCORRECTLY_COPIED_INF   _HRESULT_TYPEDEF_(0x800F0237L)






// The Security Configuration Editor (SCE) APIs have been disabled on this Embedded product.

SPAPI_E_SCE_DISABLED             _HRESULT_TYPEDEF_(0x800F0238L)






// An unknown exception was encountered.

SPAPI_E_UNKNOWN_EXCEPTION        _HRESULT_TYPEDEF_(0x800F0239L)






// A problem was encountered when accessing the Plug and Play registry database.

SPAPI_E_PNP_REGISTRY_ERROR       _HRESULT_TYPEDEF_(0x800F023AL)






// The requested operation is not supported for a remote machine.

SPAPI_E_REMOTE_REQUEST_UNSUPPORTED _HRESULT_TYPEDEF_(0x800F023BL)






// The specified file is not an installed OEM INF.

SPAPI_E_NOT_AN_INSTALLED_OEM_INF _HRESULT_TYPEDEF_(0x800F023CL)






// One or more devices are presently installed using the specified INF.

SPAPI_E_INF_IN_USE_BY_DEVICES    _HRESULT_TYPEDEF_(0x800F023DL)






// The requested device install operation is obsolete.

SPAPI_E_DI_FUNCTION_OBSOLETE     _HRESULT_TYPEDEF_(0x800F023EL)






// A file could not be verified because it does not have an associated catalog signed via Authenticode(tm).

SPAPI_E_NO_AUTHENTICODE_CATALOG  _HRESULT_TYPEDEF_(0x800F023FL)






// Authenticode(tm) signature verification is not supported for the specified INF.

SPAPI_E_AUTHENTICODE_DISALLOWED  _HRESULT_TYPEDEF_(0x800F0240L)






// The INF was signed with an Authenticode(tm) catalog from a trusted publisher.

SPAPI_E_AUTHENTICODE_TRUSTED_PUBLISHER _HRESULT_TYPEDEF_(0x800F0241L)






// The publisher of an Authenticode(tm) signed catalog has not yet been established as trusted.

SPAPI_E_AUTHENTICODE_TRUST_NOT_ESTABLISHED _HRESULT_TYPEDEF_(0x800F0242L)






// The publisher of an Authenticode(tm) signed catalog was not established as trusted.

SPAPI_E_AUTHENTICODE_PUBLISHER_NOT_TRUSTED _HRESULT_TYPEDEF_(0x800F0243L)






// The software was tested for compliance with Windows Logo requirements on a different version of Windows, and may not be compatible with this version.

SPAPI_E_SIGNATURE_OSATTRIBUTE_MISMATCH _HRESULT_TYPEDEF_(0x800F0244L)






// The file may only be validated by a catalog signed via Authenticode(tm).

SPAPI_E_ONLY_VALIDATE_VIA_AUTHENTICODE _HRESULT_TYPEDEF_(0x800F0245L)






// One of the installers for this device cannot perform the installation at this time.

SPAPI_E_DEVICE_INSTALLER_NOT_READY _HRESULT_TYPEDEF_(0x800F0246L)






// A problem was encountered while attempting to add the driver to the store.

SPAPI_E_DRIVER_STORE_ADD_FAILED  _HRESULT_TYPEDEF_(0x800F0247L)






// The installation of this device is forbidden by system policy. Contact your system administrator.

SPAPI_E_DEVICE_INSTALL_BLOCKED   _HRESULT_TYPEDEF_(0x800F0248L)






// The installation of this driver is forbidden by system policy. Contact your system administrator.

SPAPI_E_DRIVER_INSTALL_BLOCKED   _HRESULT_TYPEDEF_(0x800F0249L)






// The specified INF is the wrong type for this operation.

SPAPI_E_WRONG_INF_TYPE           _HRESULT_TYPEDEF_(0x800F024AL)






// The hash for the file is not present in the specified catalog file. The file is likely corrupt or the victim of tampering.

SPAPI_E_FILE_HASH_NOT_IN_CATALOG _HRESULT_TYPEDEF_(0x800F024BL)






// A problem was encountered while attempting to delete the driver from the store.

SPAPI_E_DRIVER_STORE_DELETE_FAILED _HRESULT_TYPEDEF_(0x800F024CL)






// An unrecoverable stack overflow was encountered.

SPAPI_E_UNRECOVERABLE_STACK_OVERFLOW _HRESULT_TYPEDEF_(0x800F0300L)






// No installed components were detected.

SPAPI_E_ERROR_NOT_INSTALLED      _HRESULT_TYPEDEF_(0x800F1000L)

// *****************
// FACILITY_SCARD
// *****************

// =============================
// Facility SCARD Error Messages
// =============================

SCARD_S_SUCCESS NO_ERROR





// An internal consistency check failed.

SCARD_F_INTERNAL_ERROR           _HRESULT_TYPEDEF_(0x80100001L)






// The action was cancelled by an SCardCancel request.

SCARD_E_CANCELLED                _HRESULT_TYPEDEF_(0x80100002L)






// The supplied handle was invalid.

SCARD_E_INVALID_HANDLE           _HRESULT_TYPEDEF_(0x80100003L)






// One or more of the supplied parameters could not be properly interpreted.

SCARD_E_INVALID_PARAMETER        _HRESULT_TYPEDEF_(0x80100004L)






// Registry startup information is missing or invalid.

SCARD_E_INVALID_TARGET           _HRESULT_TYPEDEF_(0x80100005L)






// Not enough memory available to complete this command.

SCARD_E_NO_MEMORY                _HRESULT_TYPEDEF_(0x80100006L)






// An internal consistency timer has expired.

SCARD_F_WAITED_TOO_LONG          _HRESULT_TYPEDEF_(0x80100007L)






// The data buffer to receive returned data is too small for the returned data.

SCARD_E_INSUFFICIENT_BUFFER      _HRESULT_TYPEDEF_(0x80100008L)






// The specified reader name is not recognized.

SCARD_E_UNKNOWN_READER           _HRESULT_TYPEDEF_(0x80100009L)






// The user-specified timeout value has expired.

SCARD_E_TIMEOUT                  _HRESULT_TYPEDEF_(0x8010000AL)






// The smart card cannot be accessed because of other connections outstanding.

SCARD_E_SHARING_VIOLATION        _HRESULT_TYPEDEF_(0x8010000BL)






// The operation requires a smart card, but no smart card is currently in the device.

SCARD_E_NO_SMARTCARD             _HRESULT_TYPEDEF_(0x8010000CL)






// The specified smart card name is not recognized.

SCARD_E_UNKNOWN_CARD             _HRESULT_TYPEDEF_(0x8010000DL)






// The system could not dispose of the media in the requested manner.

SCARD_E_CANT_DISPOSE             _HRESULT_TYPEDEF_(0x8010000EL)






// The requested protocols are incompatible with the protocol currently in use with the smart card.

SCARD_E_PROTO_MISMATCH           _HRESULT_TYPEDEF_(0x8010000FL)






// The reader or smart card is not ready to accept commands.

SCARD_E_NOT_READY                _HRESULT_TYPEDEF_(0x80100010L)






// One or more of the supplied parameters values could not be properly interpreted.

SCARD_E_INVALID_VALUE            _HRESULT_TYPEDEF_(0x80100011L)






// The action was cancelled by the system, presumably to log off or shut down.

SCARD_E_SYSTEM_CANCELLED         _HRESULT_TYPEDEF_(0x80100012L)






// An internal communications error has been detected.

SCARD_F_COMM_ERROR               _HRESULT_TYPEDEF_(0x80100013L)






// An internal error has been detected, but the source is unknown.

SCARD_F_UNKNOWN_ERROR            _HRESULT_TYPEDEF_(0x80100014L)






// An ATR obtained from the registry is not a valid ATR string.

SCARD_E_INVALID_ATR              _HRESULT_TYPEDEF_(0x80100015L)






// An attempt was made to end a non-existent transaction.

SCARD_E_NOT_TRANSACTED           _HRESULT_TYPEDEF_(0x80100016L)






// The specified reader is not currently available for use.

SCARD_E_READER_UNAVAILABLE       _HRESULT_TYPEDEF_(0x80100017L)






// The operation has been aborted to allow the server application to exit.

SCARD_P_SHUTDOWN                 _HRESULT_TYPEDEF_(0x80100018L)






// The PCI Receive buffer was too small.

SCARD_E_PCI_TOO_SMALL            _HRESULT_TYPEDEF_(0x80100019L)






// The reader driver does not meet minimal requirements for support.

SCARD_E_READER_UNSUPPORTED       _HRESULT_TYPEDEF_(0x8010001AL)






// The reader driver did not produce a unique reader name.

SCARD_E_DUPLICATE_READER         _HRESULT_TYPEDEF_(0x8010001BL)






// The smart card does not meet minimal requirements for support.

SCARD_E_CARD_UNSUPPORTED         _HRESULT_TYPEDEF_(0x8010001CL)






// The Smart Card Resource Manager is not running.

SCARD_E_NO_SERVICE               _HRESULT_TYPEDEF_(0x8010001DL)






// The Smart Card Resource Manager has shut down.

SCARD_E_SERVICE_STOPPED          _HRESULT_TYPEDEF_(0x8010001EL)






// An unexpected card error has occurred.

SCARD_E_UNEXPECTED               _HRESULT_TYPEDEF_(0x8010001FL)






// No Primary Provider can be found for the smart card.

SCARD_E_ICC_INSTALLATION         _HRESULT_TYPEDEF_(0x80100020L)






// The requested order of object creation is not supported.

SCARD_E_ICC_CREATEORDER          _HRESULT_TYPEDEF_(0x80100021L)






// This smart card does not support the requested feature.

SCARD_E_UNSUPPORTED_FEATURE      _HRESULT_TYPEDEF_(0x80100022L)






// The identified directory does not exist in the smart card.

SCARD_E_DIR_NOT_FOUND            _HRESULT_TYPEDEF_(0x80100023L)






// The identified file does not exist in the smart card.

SCARD_E_FILE_NOT_FOUND           _HRESULT_TYPEDEF_(0x80100024L)






// The supplied path does not represent a smart card directory.

SCARD_E_NO_DIR                   _HRESULT_TYPEDEF_(0x80100025L)






// The supplied path does not represent a smart card file.

SCARD_E_NO_FILE                  _HRESULT_TYPEDEF_(0x80100026L)






// Access is denied to this file.

SCARD_E_NO_ACCESS                _HRESULT_TYPEDEF_(0x80100027L)






// The smart card does not have enough memory to store the information.

SCARD_E_WRITE_TOO_MANY           _HRESULT_TYPEDEF_(0x80100028L)






// There was an error trying to set the smart card file object pointer.

SCARD_E_BAD_SEEK                 _HRESULT_TYPEDEF_(0x80100029L)






// The supplied PIN is incorrect.

SCARD_E_INVALID_CHV              _HRESULT_TYPEDEF_(0x8010002AL)






// An unrecognized error code was returned from a layered component.

SCARD_E_UNKNOWN_RES_MNG          _HRESULT_TYPEDEF_(0x8010002BL)






// The requested certificate does not exist.

SCARD_E_NO_SUCH_CERTIFICATE      _HRESULT_TYPEDEF_(0x8010002CL)






// The requested certificate could not be obtained.

SCARD_E_CERTIFICATE_UNAVAILABLE  _HRESULT_TYPEDEF_(0x8010002DL)






// Cannot find a smart card reader.

SCARD_E_NO_READERS_AVAILABLE     _HRESULT_TYPEDEF_(0x8010002EL)






// A communications error with the smart card has been detected. Retry the operation.

SCARD_E_COMM_DATA_LOST           _HRESULT_TYPEDEF_(0x8010002FL)






// The requested key container does not exist on the smart card.

SCARD_E_NO_KEY_CONTAINER         _HRESULT_TYPEDEF_(0x80100030L)






// The Smart Card Resource Manager is too busy to complete this operation.

SCARD_E_SERVER_TOO_BUSY          _HRESULT_TYPEDEF_(0x80100031L)






// The smart card PIN cache has expired.

SCARD_E_PIN_CACHE_EXPIRED        _HRESULT_TYPEDEF_(0x80100032L)






// The smart card PIN cannot be cached.

SCARD_E_NO_PIN_CACHE             _HRESULT_TYPEDEF_(0x80100033L)






// The smart card is read only and cannot be written to.

SCARD_E_READ_ONLY_CARD           _HRESULT_TYPEDEF_(0x80100034L)


// These are warning codes.






// The reader cannot communicate with the smart card, due to ATR configuration conflicts.

SCARD_W_UNSUPPORTED_CARD         _HRESULT_TYPEDEF_(0x80100065L)






// The smart card is not responding to a reset.

SCARD_W_UNRESPONSIVE_CARD        _HRESULT_TYPEDEF_(0x80100066L)






// Power has been removed from the smart card, so that further communication is not possible.

SCARD_W_UNPOWERED_CARD           _HRESULT_TYPEDEF_(0x80100067L)






// The smart card has been reset, so any shared state information is invalid.

SCARD_W_RESET_CARD               _HRESULT_TYPEDEF_(0x80100068L)






// The smart card has been removed, so that further communication is not possible.

SCARD_W_REMOVED_CARD             _HRESULT_TYPEDEF_(0x80100069L)






// Access was denied because of a security violation.

SCARD_W_SECURITY_VIOLATION       _HRESULT_TYPEDEF_(0x8010006AL)






// The card cannot be accessed because the wrong PIN was presented.

SCARD_W_WRONG_CHV                _HRESULT_TYPEDEF_(0x8010006BL)






// The card cannot be accessed because the maximum number of PIN entry attempts has been reached.

SCARD_W_CHV_BLOCKED              _HRESULT_TYPEDEF_(0x8010006CL)






// The end of the smart card file has been reached.

SCARD_W_EOF                      _HRESULT_TYPEDEF_(0x8010006DL)






// The action was cancelled by the user.

SCARD_W_CANCELLED_BY_USER        _HRESULT_TYPEDEF_(0x8010006EL)






// No PIN was presented to the smart card.

SCARD_W_CARD_NOT_AUTHENTICATED   _HRESULT_TYPEDEF_(0x8010006FL)






// The requested item could not be found in the cache.

SCARD_W_CACHE_ITEM_NOT_FOUND     _HRESULT_TYPEDEF_(0x80100070L)






// The requested cache item is too old and was deleted from the cache.

SCARD_W_CACHE_ITEM_STALE         _HRESULT_TYPEDEF_(0x80100071L)






// The new cache item exceeds the maximum per-item size defined for the cache.

SCARD_W_CACHE_ITEM_TOO_BIG       _HRESULT_TYPEDEF_(0x80100072L)

// *****************
// FACILITY_COMPLUS
// *****************

// ===============================
// Facility COMPLUS Error Messages
// ===============================


// The following are the subranges  within the COMPLUS facility
// 0x400 - 0x4ff               COMADMIN_E_CAT
// 0x600 - 0x6ff               COMQC errors
// 0x700 - 0x7ff               MSDTC errors
// 0x800 - 0x8ff               Other COMADMIN errors

// COMPLUS Admin errors






// Errors occurred accessing one or more objects - the ErrorInfo collection may have more detail

COMADMIN_E_OBJECTERRORS          _HRESULT_TYPEDEF_(0x80110401L)






// One or more of the object's properties are missing or invalid

COMADMIN_E_OBJECTINVALID         _HRESULT_TYPEDEF_(0x80110402L)






// The object was not found in the catalog

COMADMIN_E_KEYMISSING            _HRESULT_TYPEDEF_(0x80110403L)






// The object is already registered

COMADMIN_E_ALREADYINSTALLED      _HRESULT_TYPEDEF_(0x80110404L)






// Error occurred writing to the application file

COMADMIN_E_APP_FILE_WRITEFAIL    _HRESULT_TYPEDEF_(0x80110407L)






// Error occurred reading the application file

COMADMIN_E_APP_FILE_READFAIL     _HRESULT_TYPEDEF_(0x80110408L)






// Invalid version number in application file

COMADMIN_E_APP_FILE_VERSION      _HRESULT_TYPEDEF_(0x80110409L)






// The file path is invalid

COMADMIN_E_BADPATH               _HRESULT_TYPEDEF_(0x8011040AL)






// The application is already installed

COMADMIN_E_APPLICATIONEXISTS     _HRESULT_TYPEDEF_(0x8011040BL)






// The role already exists

COMADMIN_E_ROLEEXISTS            _HRESULT_TYPEDEF_(0x8011040CL)






// An error occurred copying the file

COMADMIN_E_CANTCOPYFILE          _HRESULT_TYPEDEF_(0x8011040DL)






// One or more users are not valid

COMADMIN_E_NOUSER                _HRESULT_TYPEDEF_(0x8011040FL)






// One or more users in the application file are not valid

COMADMIN_E_INVALIDUSERIDS        _HRESULT_TYPEDEF_(0x80110410L)






// The component's CLSID is missing or corrupt

COMADMIN_E_NOREGISTRYCLSID       _HRESULT_TYPEDEF_(0x80110411L)






// The component's progID is missing or corrupt

COMADMIN_E_BADREGISTRYPROGID     _HRESULT_TYPEDEF_(0x80110412L)






// Unable to set required authentication level for update request

COMADMIN_E_AUTHENTICATIONLEVEL   _HRESULT_TYPEDEF_(0x80110413L)






// The identity or password set on the application is not valid

COMADMIN_E_USERPASSWDNOTVALID    _HRESULT_TYPEDEF_(0x80110414L)






// Application file CLSIDs or IIDs do not match corresponding DLLs

COMADMIN_E_CLSIDORIIDMISMATCH    _HRESULT_TYPEDEF_(0x80110418L)






// Interface information is either missing or changed

COMADMIN_E_REMOTEINTERFACE       _HRESULT_TYPEDEF_(0x80110419L)






// DllRegisterServer failed on component install

COMADMIN_E_DLLREGISTERSERVER     _HRESULT_TYPEDEF_(0x8011041AL)






// No server file share available

COMADMIN_E_NOSERVERSHARE         _HRESULT_TYPEDEF_(0x8011041BL)






// DLL could not be loaded

COMADMIN_E_DLLLOADFAILED         _HRESULT_TYPEDEF_(0x8011041DL)






// The registered TypeLib ID is not valid

COMADMIN_E_BADREGISTRYLIBID      _HRESULT_TYPEDEF_(0x8011041EL)






// Application install directory not found

COMADMIN_E_APPDIRNOTFOUND        _HRESULT_TYPEDEF_(0x8011041FL)






// Errors occurred while in the component registrar

COMADMIN_E_REGISTRARFAILED       _HRESULT_TYPEDEF_(0x80110423L)






// The file does not exist

COMADMIN_E_COMPFILE_DOESNOTEXIST _HRESULT_TYPEDEF_(0x80110424L)






// The DLL could not be loaded

COMADMIN_E_COMPFILE_LOADDLLFAIL  _HRESULT_TYPEDEF_(0x80110425L)






// GetClassObject failed in the DLL

COMADMIN_E_COMPFILE_GETCLASSOBJ  _HRESULT_TYPEDEF_(0x80110426L)






// The DLL does not support the components listed in the TypeLib

COMADMIN_E_COMPFILE_CLASSNOTAVAIL _HRESULT_TYPEDEF_(0x80110427L)






// The TypeLib could not be loaded

COMADMIN_E_COMPFILE_BADTLB       _HRESULT_TYPEDEF_(0x80110428L)






// The file does not contain components or component information

COMADMIN_E_COMPFILE_NOTINSTALLABLE _HRESULT_TYPEDEF_(0x80110429L)






// Changes to this object and its sub-objects have been disabled

COMADMIN_E_NOTCHANGEABLE         _HRESULT_TYPEDEF_(0x8011042AL)






// The delete function has been disabled for this object

COMADMIN_E_NOTDELETEABLE         _HRESULT_TYPEDEF_(0x8011042BL)






// The server catalog version is not supported

COMADMIN_E_SESSION               _HRESULT_TYPEDEF_(0x8011042CL)






// The component move was disallowed, because the source or destination application is either a system application or currently locked against changes

COMADMIN_E_COMP_MOVE_LOCKED      _HRESULT_TYPEDEF_(0x8011042DL)






// The component move failed because the destination application no longer exists

COMADMIN_E_COMP_MOVE_BAD_DEST    _HRESULT_TYPEDEF_(0x8011042EL)






// The system was unable to register the TypeLib

COMADMIN_E_REGISTERTLB           _HRESULT_TYPEDEF_(0x80110430L)






// This operation cannot be performed on the system application

COMADMIN_E_SYSTEMAPP             _HRESULT_TYPEDEF_(0x80110433L)






// The component registrar referenced in this file is not available

COMADMIN_E_COMPFILE_NOREGISTRAR  _HRESULT_TYPEDEF_(0x80110434L)






// A component in the same DLL is already installed

COMADMIN_E_COREQCOMPINSTALLED    _HRESULT_TYPEDEF_(0x80110435L)






// The service is not installed

COMADMIN_E_SERVICENOTINSTALLED   _HRESULT_TYPEDEF_(0x80110436L)






// One or more property settings are either invalid or in conflict with each other

COMADMIN_E_PROPERTYSAVEFAILED    _HRESULT_TYPEDEF_(0x80110437L)






// The object you are attempting to add or rename already exists

COMADMIN_E_OBJECTEXISTS          _HRESULT_TYPEDEF_(0x80110438L)






// The component already exists

COMADMIN_E_COMPONENTEXISTS       _HRESULT_TYPEDEF_(0x80110439L)






// The registration file is corrupt

COMADMIN_E_REGFILE_CORRUPT       _HRESULT_TYPEDEF_(0x8011043BL)






// The property value is too large

COMADMIN_E_PROPERTY_OVERFLOW     _HRESULT_TYPEDEF_(0x8011043CL)






// Object was not found in registry

COMADMIN_E_NOTINREGISTRY         _HRESULT_TYPEDEF_(0x8011043EL)






// This object is not poolable

COMADMIN_E_OBJECTNOTPOOLABLE     _HRESULT_TYPEDEF_(0x8011043FL)






// A CLSID with the same GUID as the new application ID is already installed on this machine

COMADMIN_E_APPLID_MATCHES_CLSID  _HRESULT_TYPEDEF_(0x80110446L)






// A role assigned to a component, interface, or method did not exist in the application

COMADMIN_E_ROLE_DOES_NOT_EXIST   _HRESULT_TYPEDEF_(0x80110447L)






// You must have components in an application in order to start the application

COMADMIN_E_START_APP_NEEDS_COMPONENTS _HRESULT_TYPEDEF_(0x80110448L)






// This operation is not enabled on this platform

COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM _HRESULT_TYPEDEF_(0x80110449L)






// Application Proxy is not exportable

COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY _HRESULT_TYPEDEF_(0x8011044AL)






// Failed to start application because it is either a library application or an application proxy

COMADMIN_E_CAN_NOT_START_APP     _HRESULT_TYPEDEF_(0x8011044BL)






// System application is not exportable

COMADMIN_E_CAN_NOT_EXPORT_SYS_APP _HRESULT_TYPEDEF_(0x8011044CL)






// Cannot subscribe to this component (the component may have been imported)

COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT _HRESULT_TYPEDEF_(0x8011044DL)






// An event class cannot also be a subscriber component

COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER _HRESULT_TYPEDEF_(0x8011044EL)






// Library applications and application proxies are incompatible

COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE _HRESULT_TYPEDEF_(0x8011044FL)






// This function is valid for the base partition only

COMADMIN_E_BASE_PARTITION_ONLY   _HRESULT_TYPEDEF_(0x80110450L)






// You cannot start an application that has been disabled

COMADMIN_E_START_APP_DISABLED    _HRESULT_TYPEDEF_(0x80110451L)






// The specified partition name is already in use on this computer

COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME _HRESULT_TYPEDEF_(0x80110457L)






// The specified partition name is invalid. Check that the name contains at least one visible character

COMADMIN_E_CAT_INVALID_PARTITION_NAME _HRESULT_TYPEDEF_(0x80110458L)






// The partition cannot be deleted because it is the default partition for one or more users

COMADMIN_E_CAT_PARTITION_IN_USE  _HRESULT_TYPEDEF_(0x80110459L)






// The partition cannot be exported, because one or more components in the partition have the same file name

COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES _HRESULT_TYPEDEF_(0x8011045AL)






// Applications that contain one or more imported components cannot be installed into a non-base partition

COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED _HRESULT_TYPEDEF_(0x8011045BL)






// The application name is not unique and cannot be resolved to an application id

COMADMIN_E_AMBIGUOUS_APPLICATION_NAME _HRESULT_TYPEDEF_(0x8011045CL)






// The partition name is not unique and cannot be resolved to a partition id

COMADMIN_E_AMBIGUOUS_PARTITION_NAME _HRESULT_TYPEDEF_(0x8011045DL)






// The COM+ registry database has not been initialized

COMADMIN_E_REGDB_NOTINITIALIZED  _HRESULT_TYPEDEF_(0x80110472L)






// The COM+ registry database is not open

COMADMIN_E_REGDB_NOTOPEN         _HRESULT_TYPEDEF_(0x80110473L)






// The COM+ registry database detected a system error

COMADMIN_E_REGDB_SYSTEMERR       _HRESULT_TYPEDEF_(0x80110474L)






// The COM+ registry database is already running

COMADMIN_E_REGDB_ALREADYRUNNING  _HRESULT_TYPEDEF_(0x80110475L)






// This version of the COM+ registry database cannot be migrated

COMADMIN_E_MIG_VERSIONNOTSUPPORTED _HRESULT_TYPEDEF_(0x80110480L)






// The schema version to be migrated could not be found in the COM+ registry database

COMADMIN_E_MIG_SCHEMANOTFOUND    _HRESULT_TYPEDEF_(0x80110481L)






// There was a type mismatch between binaries

COMADMIN_E_CAT_BITNESSMISMATCH   _HRESULT_TYPEDEF_(0x80110482L)






// A binary of unknown or invalid type was provided

COMADMIN_E_CAT_UNACCEPTABLEBITNESS _HRESULT_TYPEDEF_(0x80110483L)






// There was a type mismatch between a binary and an application

COMADMIN_E_CAT_WRONGAPPBITNESS   _HRESULT_TYPEDEF_(0x80110484L)






// The application cannot be paused or resumed

COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80110485L)






// The COM+ Catalog Server threw an exception during execution

COMADMIN_E_CAT_SERVERFAULT       _HRESULT_TYPEDEF_(0x80110486L)


// COMPLUS Queued component errors






// Only COM+ Applications marked "queued" can be invoked using the "queue" moniker

COMQC_E_APPLICATION_NOT_QUEUED   _HRESULT_TYPEDEF_(0x80110600L)






// At least one interface must be marked "queued" in order to create a queued component instance with the "queue" moniker

COMQC_E_NO_QUEUEABLE_INTERFACES  _HRESULT_TYPEDEF_(0x80110601L)






// MSMQ is required for the requested operation and is not installed

COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE _HRESULT_TYPEDEF_(0x80110602L)






// Unable to marshal an interface that does not support IPersistStream

COMQC_E_NO_IPERSISTSTREAM        _HRESULT_TYPEDEF_(0x80110603L)






// The message is improperly formatted or was damaged in transit

COMQC_E_BAD_MESSAGE              _HRESULT_TYPEDEF_(0x80110604L)






// An unauthenticated message was received by an application that accepts only authenticated messages

COMQC_E_UNAUTHENTICATED          _HRESULT_TYPEDEF_(0x80110605L)






// The message was requeued or moved by a user not in the "QC Trusted User" role

COMQC_E_UNTRUSTED_ENQUEUER       _HRESULT_TYPEDEF_(0x80110606L)


// The range 0x700-0x7ff is reserved for MSDTC errors.






// Cannot create a duplicate resource of type Distributed Transaction Coordinator

MSDTC_E_DUPLICATE_RESOURCE       _HRESULT_TYPEDEF_(0x80110701L)


// More COMADMIN errors from 0x8**






// One of the objects being inserted or updated does not belong to a valid parent collection

COMADMIN_E_OBJECT_PARENT_MISSING _HRESULT_TYPEDEF_(0x80110808L)






// One of the specified objects cannot be found

COMADMIN_E_OBJECT_DOES_NOT_EXIST _HRESULT_TYPEDEF_(0x80110809L)






// The specified application is not currently running

COMADMIN_E_APP_NOT_RUNNING       _HRESULT_TYPEDEF_(0x8011080AL)






// The partition(s) specified are not valid.

COMADMIN_E_INVALID_PARTITION     _HRESULT_TYPEDEF_(0x8011080BL)






// COM+ applications that run as NT service may not be pooled or recycled

COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE _HRESULT_TYPEDEF_(0x8011080DL)






// One or more users are already assigned to a local partition set.

COMADMIN_E_USER_IN_SET           _HRESULT_TYPEDEF_(0x8011080EL)






// Library applications may not be recycled.

COMADMIN_E_CANTRECYCLELIBRARYAPPS _HRESULT_TYPEDEF_(0x8011080FL)






// Applications running as NT services may not be recycled.

COMADMIN_E_CANTRECYCLESERVICEAPPS _HRESULT_TYPEDEF_(0x80110811L)






// The process has already been recycled.

COMADMIN_E_PROCESSALREADYRECYCLED _HRESULT_TYPEDEF_(0x80110812L)






// A paused process may not be recycled.

COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED _HRESULT_TYPEDEF_(0x80110813L)






// Library applications may not be NT services.

COMADMIN_E_CANTMAKEINPROCSERVICE _HRESULT_TYPEDEF_(0x80110814L)






// The ProgID provided to the copy operation is invalid. The ProgID is in use by another registered CLSID.

COMADMIN_E_PROGIDINUSEBYCLSID    _HRESULT_TYPEDEF_(0x80110815L)






// The partition specified as default is not a member of the partition set.

COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET _HRESULT_TYPEDEF_(0x80110816L)






// A recycled process may not be paused.

COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED _HRESULT_TYPEDEF_(0x80110817L)






// Access to the specified partition is denied.

COMADMIN_E_PARTITION_ACCESSDENIED _HRESULT_TYPEDEF_(0x80110818L)






// Only Application Files (*.MSI files) can be installed into partitions.

COMADMIN_E_PARTITION_MSI_ONLY    _HRESULT_TYPEDEF_(0x80110819L)






// Applications containing one or more legacy components may not be exported to 1.0 format.

COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT _HRESULT_TYPEDEF_(0x8011081AL)






// Legacy components may not exist in non-base partitions.

COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS _HRESULT_TYPEDEF_(0x8011081BL)






// A component cannot be moved (or copied) from the System Application, an application proxy or a non-changeable application

COMADMIN_E_COMP_MOVE_SOURCE      _HRESULT_TYPEDEF_(0x8011081CL)






// A component cannot be moved (or copied) to the System Application, an application proxy or a non-changeable application

COMADMIN_E_COMP_MOVE_DEST        _HRESULT_TYPEDEF_(0x8011081DL)






// A private component cannot be moved (or copied) to a library application or to the base partition

COMADMIN_E_COMP_MOVE_PRIVATE     _HRESULT_TYPEDEF_(0x8011081EL)






// The Base Application Partition exists in all partition sets and cannot be removed.

COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET _HRESULT_TYPEDEF_(0x8011081FL)






// Alas, Event Class components cannot be aliased.

COMADMIN_E_CANNOT_ALIAS_EVENTCLASS _HRESULT_TYPEDEF_(0x80110820L)






// Access is denied because the component is private.

COMADMIN_E_PRIVATE_ACCESSDENIED  _HRESULT_TYPEDEF_(0x80110821L)






// The specified SAFER level is invalid.

COMADMIN_E_SAFERINVALID          _HRESULT_TYPEDEF_(0x80110822L)






// The specified user cannot write to the system registry

COMADMIN_E_REGISTRY_ACCESSDENIED _HRESULT_TYPEDEF_(0x80110823L)






// COM+ partitions are currently disabled.

COMADMIN_E_PARTITIONS_DISABLED   _HRESULT_TYPEDEF_(0x80110824L)


// FACILITY_WER






// Debugger was attached.

WER_S_REPORT_DEBUG               _HRESULT_TYPEDEF_(0x001B0000L)






// Report was uploaded.

WER_S_REPORT_UPLOADED            _HRESULT_TYPEDEF_(0x001B0001L)






// Report was queued.

WER_S_REPORT_QUEUED              _HRESULT_TYPEDEF_(0x001B0002L)






// Reporting was disabled.

WER_S_DISABLED                   _HRESULT_TYPEDEF_(0x001B0003L)






// Reporting was temporarily suspended.

WER_S_SUSPENDED_UPLOAD           _HRESULT_TYPEDEF_(0x001B0004L)






// Report was not queued to queuing being disabled.

WER_S_DISABLED_QUEUE             _HRESULT_TYPEDEF_(0x001B0005L)






// Report was uploaded, but not archived due to archiving being disabled.

WER_S_DISABLED_ARCHIVE           _HRESULT_TYPEDEF_(0x001B0006L)






// Reporting was successfully spun off as an asynchronous operation.

WER_S_REPORT_ASYNC               _HRESULT_TYPEDEF_(0x001B0007L)






// The assertion was handled.

WER_S_IGNORE_ASSERT_INSTANCE     _HRESULT_TYPEDEF_(0x001B0008L)






// The assertion was handled and added to a permanent ignore list.

WER_S_IGNORE_ALL_ASSERTS         _HRESULT_TYPEDEF_(0x001B0009L)






// The assertion was resumed as unhandled.

WER_S_ASSERT_CONTINUE            _HRESULT_TYPEDEF_(0x001B000AL)






// Report was throttled.

WER_S_THROTTLED                  _HRESULT_TYPEDEF_(0x001B000BL)






// Report was uploaded with cab.

WER_S_REPORT_UPLOADED_CAB        _HRESULT_TYPEDEF_(0x001B000CL)






// Crash reporting failed.

WER_E_CRASH_FAILURE              _HRESULT_TYPEDEF_(0x801B8000L)






// Report aborted due to user cancellation.

WER_E_CANCELED                   _HRESULT_TYPEDEF_(0x801B8001L)






// Report aborted due to network failure.

WER_E_NETWORK_FAILURE            _HRESULT_TYPEDEF_(0x801B8002L)






// Report not initialized.

WER_E_NOT_INITIALIZED            _HRESULT_TYPEDEF_(0x801B8003L)






// Reporting is already in progress for the specified process.

WER_E_ALREADY_REPORTING          _HRESULT_TYPEDEF_(0x801B8004L)






// Dump not generated due to a throttle.

WER_E_DUMP_THROTTLED             _HRESULT_TYPEDEF_(0x801B8005L)






// Operation failed due to insufficient user consent.

WER_E_INSUFFICIENT_CONSENT       _HRESULT_TYPEDEF_(0x801B8006L)






// Report aborted due to performance criteria.

WER_E_TOO_HEAVY                  _HRESULT_TYPEDEF_(0x801B8007L)

// ***********************
// FACILITY_USERMODE_FILTER_MANAGER
// ***********************

// Translation macro for converting FilterManager error codes only from:
//     NTSTATUS  --> HRESULT

FILTER_HRESULT_FROM_FLT_NTSTATUS(x) (ASSERT((x & 0xfff0000) == 0x001c0000),(HRESULT) (((x) & 0x8000FFFF) | (FACILITY_USERMODE_FILTER_MANAGER << 16)))





// The IO was completed by a filter.

ERROR_FLT_IO_COMPLETE            _HRESULT_TYPEDEF_(0x001F0001L)






// A handler was not defined by the filter for this operation.

ERROR_FLT_NO_HANDLER_DEFINED     _HRESULT_TYPEDEF_(0x801F0001L)






// A context is already defined for this object.

ERROR_FLT_CONTEXT_ALREADY_DEFINED _HRESULT_TYPEDEF_(0x801F0002L)






// Asynchronous requests are not valid for this operation.

ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST _HRESULT_TYPEDEF_(0x801F0003L)






// Disallow the Fast IO path for this operation.

ERROR_FLT_DISALLOW_FAST_IO       _HRESULT_TYPEDEF_(0x801F0004L)






// An invalid name request was made. The name requested cannot be retrieved at this time.

ERROR_FLT_INVALID_NAME_REQUEST   _HRESULT_TYPEDEF_(0x801F0005L)






// Posting this operation to a worker thread for further processing is not safe at this time because it could lead to a system deadlock.

ERROR_FLT_NOT_SAFE_TO_POST_OPERATION _HRESULT_TYPEDEF_(0x801F0006L)






// The Filter Manager was not initialized when a filter tried to register. Make sure that the Filter Manager is getting loaded as a driver.

ERROR_FLT_NOT_INITIALIZED        _HRESULT_TYPEDEF_(0x801F0007L)






// The filter is not ready for attachment to volumes because it has not finished initializing (FltStartFiltering has not been called).

ERROR_FLT_FILTER_NOT_READY       _HRESULT_TYPEDEF_(0x801F0008L)






// The filter must cleanup any operation specific context at this time because it is being removed from the system before the operation is completed by the lower drivers.

ERROR_FLT_POST_OPERATION_CLEANUP _HRESULT_TYPEDEF_(0x801F0009L)






// The Filter Manager had an internal error from which it cannot recover, therefore the operation has been failed. This is usually the result of a filter returning an invalid value from a pre-operation callback.

ERROR_FLT_INTERNAL_ERROR         _HRESULT_TYPEDEF_(0x801F000AL)






// The object specified for this action is in the process of being deleted, therefore the action requested cannot be completed at this time.

ERROR_FLT_DELETING_OBJECT        _HRESULT_TYPEDEF_(0x801F000BL)






// Non-paged pool must be used for this type of context.

ERROR_FLT_MUST_BE_NONPAGED_POOL  _HRESULT_TYPEDEF_(0x801F000CL)






// A duplicate handler definition has been provided for an operation.

ERROR_FLT_DUPLICATE_ENTRY        _HRESULT_TYPEDEF_(0x801F000DL)






// The callback data queue has been disabled.

ERROR_FLT_CBDQ_DISABLED          _HRESULT_TYPEDEF_(0x801F000EL)






// Do not attach the filter to the volume at this time.

ERROR_FLT_DO_NOT_ATTACH          _HRESULT_TYPEDEF_(0x801F000FL)






// Do not detach the filter from the volume at this time.

ERROR_FLT_DO_NOT_DETACH          _HRESULT_TYPEDEF_(0x801F0010L)






// An instance already exists at this altitude on the volume specified.

ERROR_FLT_INSTANCE_ALTITUDE_COLLISION _HRESULT_TYPEDEF_(0x801F0011L)






// An instance already exists with this name on the volume specified.

ERROR_FLT_INSTANCE_NAME_COLLISION _HRESULT_TYPEDEF_(0x801F0012L)






// The system could not find the filter specified.

ERROR_FLT_FILTER_NOT_FOUND       _HRESULT_TYPEDEF_(0x801F0013L)






// The system could not find the volume specified.

ERROR_FLT_VOLUME_NOT_FOUND       _HRESULT_TYPEDEF_(0x801F0014L)






// The system could not find the instance specified.

ERROR_FLT_INSTANCE_NOT_FOUND     _HRESULT_TYPEDEF_(0x801F0015L)






// No registered context allocation definition was found for the given request.

ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND _HRESULT_TYPEDEF_(0x801F0016L)






// An invalid parameter was specified during context registration.

ERROR_FLT_INVALID_CONTEXT_REGISTRATION _HRESULT_TYPEDEF_(0x801F0017L)






// The name requested was not found in Filter Manager's name cache and could not be retrieved from the file system.

ERROR_FLT_NAME_CACHE_MISS        _HRESULT_TYPEDEF_(0x801F0018L)






// The requested device object does not exist for the given volume.

ERROR_FLT_NO_DEVICE_OBJECT       _HRESULT_TYPEDEF_(0x801F0019L)






// The specified volume is already mounted.

ERROR_FLT_VOLUME_ALREADY_MOUNTED _HRESULT_TYPEDEF_(0x801F001AL)






// The specified Transaction Context is already enlisted in a transaction

ERROR_FLT_ALREADY_ENLISTED       _HRESULT_TYPEDEF_(0x801F001BL)






// The specified context is already attached to another object

ERROR_FLT_CONTEXT_ALREADY_LINKED _HRESULT_TYPEDEF_(0x801F001CL)






// No waiter is present for the filter's reply to this message.

ERROR_FLT_NO_WAITER_FOR_REPLY    _HRESULT_TYPEDEF_(0x801F0020L)






// The filesystem database resource is in use. Registration cannot complete at this time.

ERROR_FLT_REGISTRATION_BUSY      _HRESULT_TYPEDEF_(0x801F0023L)


// ===============================
// Facility Graphics Error Messages
// ===============================


// The following are the subranges within the Graphics facility

// 0x0000 - 0x0fff     Display Driver Loader driver & Video Port errors (displdr.sys, videoprt.sys)
// 0x1000 - 0x1fff     Monitor Class Function driver errors             (monitor.sys)
// 0x2000 - 0x2fff     Windows Graphics Kernel Subsystem errors         (dxgkrnl.sys)
// 0x3000 - 0x3fff               Desktop Window Manager errors
//   0x2000 - 0x20ff      Common errors
//   0x2100 - 0x21ff      Video Memory Manager (VidMM) subsystem errors
//   0x2200 - 0x22ff      Video GPU Scheduler (VidSch) subsystem errors
//   0x2300 - 0x23ff      Video Display Mode Management (VidDMM) subsystem errors

// Display Driver Loader driver & Video Port errors {0x0000..0x0fff}






// {Display Driver Stopped Responding}
// The %hs display driver has stopped working normally. Save your work and reboot the system to restore full display functionality.
// The next time you reboot the machine a dialog will be displayed giving you a chance to report this failure to Microsoft.

ERROR_HUNG_DISPLAY_DRIVER_THREAD _HRESULT_TYPEDEF_(0x80260001L)


// Desktop Window Manager errors {0x3000..0x3fff}






// {Desktop composition is disabled}
// The operation could not be completed because desktop composition is disabled.

DWM_E_COMPOSITIONDISABLED        _HRESULT_TYPEDEF_(0x80263001L)






// {Some desktop composition APIs are not supported while remoting}
// The operation is not supported while running in a remote session.

DWM_E_REMOTING_NOT_SUPPORTED     _HRESULT_TYPEDEF_(0x80263002L)






// {No DWM redirection surface is available}
// The DWM was unable to provide a redirection surface to complete the DirectX present.

DWM_E_NO_REDIRECTION_SURFACE_AVAILABLE _HRESULT_TYPEDEF_(0x80263003L)






// {DWM is not queuing presents for the specified window}
// The window specified is not currently using queued presents.

DWM_E_NOT_QUEUING_PRESENTS       _HRESULT_TYPEDEF_(0x80263004L)






// {The adapter specified by the LUID is not found}
// DWM can not find the adapter specified by the LUID.

DWM_E_ADAPTER_NOT_FOUND          _HRESULT_TYPEDEF_(0x80263005L)






// {GDI redirection surface was returned}
// GDI redirection surface of the top level window was returned.

DWM_S_GDI_REDIRECTION_SURFACE    _HRESULT_TYPEDEF_(0x00263005L)






// {Redirection surface can not be created.  The size of the surface is larger than what is supported on this machine}
// Redirection surface can not be created.  The size of the surface is larger than what is supported on this machine.

DWM_E_TEXTURE_TOO_LARGE          _HRESULT_TYPEDEF_(0x80263007L)






// {GDI redirection surface is either on a different adapter or in system memory. Perform blt via GDI}
// GDI redirection surface is either on a different adapter or in system memory. Perform blt via GDI.

DWM_S_GDI_REDIRECTION_SURFACE_BLT_VIA_GDI _HRESULT_TYPEDEF_(0x00263008L)


// Monitor class function driver errors {0x1000..0x1fff}






// Monitor descriptor could not be obtained.

ERROR_MONITOR_NO_DESCRIPTOR      _HRESULT_TYPEDEF_(0x00261001L)






// Format of the obtained monitor descriptor is not supported by this release.

ERROR_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT _HRESULT_TYPEDEF_(0x00261002L)






// Checksum of the obtained monitor descriptor is invalid.

ERROR_MONITOR_INVALID_DESCRIPTOR_CHECKSUM _HRESULT_TYPEDEF_(0xC0261003L)






// Monitor descriptor contains an invalid standard timing block.

ERROR_MONITOR_INVALID_STANDARD_TIMING_BLOCK _HRESULT_TYPEDEF_(0xC0261004L)






// WMI data block registration failed for one of the MSMonitorClass WMI subclasses.

ERROR_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED _HRESULT_TYPEDEF_(0xC0261005L)






// Provided monitor descriptor block is either corrupted or does not contain monitor's detailed serial number.

ERROR_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK _HRESULT_TYPEDEF_(0xC0261006L)






// Provided monitor descriptor block is either corrupted or does not contain monitor's user friendly name.

ERROR_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK _HRESULT_TYPEDEF_(0xC0261007L)






// There is no monitor descriptor data at the specified (offset, size) region.

ERROR_MONITOR_NO_MORE_DESCRIPTOR_DATA _HRESULT_TYPEDEF_(0xC0261008L)






// Monitor descriptor contains an invalid detailed timing block.

ERROR_MONITOR_INVALID_DETAILED_TIMING_BLOCK _HRESULT_TYPEDEF_(0xC0261009L)






// Monitor descriptor contains invalid manufacture date.

ERROR_MONITOR_INVALID_MANUFACTURE_DATE _HRESULT_TYPEDEF_(0xC026100AL)


// Windows Graphics Kernel Subsystem errors {0x2000..0x2fff}

// TODO: Add DXG Win32 errors here

// Common errors {0x2000..0x20ff}






// Exclusive mode ownership is needed to create unmanaged primary allocation.

ERROR_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER _HRESULT_TYPEDEF_(0xC0262000L)






// The driver needs more DMA buffer space in order to complete the requested operation.

ERROR_GRAPHICS_INSUFFICIENT_DMA_BUFFER _HRESULT_TYPEDEF_(0xC0262001L)






// Specified display adapter handle is invalid.

ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER _HRESULT_TYPEDEF_(0xC0262002L)






// Specified display adapter and all of its state has been reset.

ERROR_GRAPHICS_ADAPTER_WAS_RESET _HRESULT_TYPEDEF_(0xC0262003L)






// The driver stack doesn't match the expected driver model.

ERROR_GRAPHICS_INVALID_DRIVER_MODEL _HRESULT_TYPEDEF_(0xC0262004L)






// Present happened but ended up into the changed desktop mode

ERROR_GRAPHICS_PRESENT_MODE_CHANGED _HRESULT_TYPEDEF_(0xC0262005L)






// Nothing to present due to desktop occlusion

ERROR_GRAPHICS_PRESENT_OCCLUDED  _HRESULT_TYPEDEF_(0xC0262006L)






// Not able to present due to denial of desktop access

ERROR_GRAPHICS_PRESENT_DENIED    _HRESULT_TYPEDEF_(0xC0262007L)






// Not able to present with color conversion

ERROR_GRAPHICS_CANNOTCOLORCONVERT _HRESULT_TYPEDEF_(0xC0262008L)






// The kernel driver detected a version mismatch between it and the user mode driver.

ERROR_GRAPHICS_DRIVER_MISMATCH   _HRESULT_TYPEDEF_(0xC0262009L)






// Specified buffer is not big enough to contain entire requested dataset. Partial data populated up to the size of the buffer. Caller needs to provide buffer of size as specified in the partially populated buffer's content (interface specific).

ERROR_GRAPHICS_PARTIAL_DATA_POPULATED _HRESULT_TYPEDEF_(0x4026200AL)






// Present redirection is disabled (desktop windowing management subsystem is off).

ERROR_GRAPHICS_PRESENT_REDIRECTION_DISABLED _HRESULT_TYPEDEF_(0xC026200BL)






// Previous exclusive VidPn source owner has released its ownership

ERROR_GRAPHICS_PRESENT_UNOCCLUDED _HRESULT_TYPEDEF_(0xC026200CL)






// Window DC is not available for presentation

ERROR_GRAPHICS_WINDOWDC_NOT_AVAILABLE _HRESULT_TYPEDEF_(0xC026200DL)






// Windowless present is disabled (desktop windowing management subsystem is off).

ERROR_GRAPHICS_WINDOWLESS_PRESENT_DISABLED _HRESULT_TYPEDEF_(0xC026200EL)






// Window handle is invalid

ERROR_GRAPHICS_PRESENT_INVALID_WINDOW _HRESULT_TYPEDEF_(0xC026200FL)






// No buffer is bound to composition surface

ERROR_GRAPHICS_PRESENT_BUFFER_NOT_BOUND _HRESULT_TYPEDEF_(0xC0262010L)






// Vail state has been changed

ERROR_GRAPHICS_VAIL_STATE_CHANGED _HRESULT_TYPEDEF_(0xC0262011L)






// Notifying indirect display UMDF class driver to abandon current swapchain.

ERROR_GRAPHICS_INDIRECT_DISPLAY_ABANDON_SWAPCHAIN _HRESULT_TYPEDEF_(0xC0262012L)






// Notifying indirect display UMDF class driver that indirect display device has been stopped.

ERROR_GRAPHICS_INDIRECT_DISPLAY_DEVICE_STOPPED _HRESULT_TYPEDEF_(0xC0262013L)


// Video Memory Manager (VidMM) subsystem errors {0x2100..0x21ff}






// Not enough video memory available to complete the operation.

ERROR_GRAPHICS_NO_VIDEO_MEMORY   _HRESULT_TYPEDEF_(0xC0262100L)






// Couldn't probe and lock the underlying memory of an allocation.

ERROR_GRAPHICS_CANT_LOCK_MEMORY  _HRESULT_TYPEDEF_(0xC0262101L)






// The allocation is currently busy.

ERROR_GRAPHICS_ALLOCATION_BUSY   _HRESULT_TYPEDEF_(0xC0262102L)






// An object being referenced has reach the maximum reference count already and can't be reference further.

ERROR_GRAPHICS_TOO_MANY_REFERENCES _HRESULT_TYPEDEF_(0xC0262103L)






// A problem couldn't be solved due to some currently existing condition. The problem should be tried again later.

ERROR_GRAPHICS_TRY_AGAIN_LATER   _HRESULT_TYPEDEF_(0xC0262104L)






// A problem couldn't be solved due to some currently existing condition. The problem should be tried again immediately.

ERROR_GRAPHICS_TRY_AGAIN_NOW     _HRESULT_TYPEDEF_(0xC0262105L)






// The allocation is invalid.

ERROR_GRAPHICS_ALLOCATION_INVALID _HRESULT_TYPEDEF_(0xC0262106L)






// No more unswizzling aperture are currently available.

ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE _HRESULT_TYPEDEF_(0xC0262107L)






// The current allocation can't be unswizzled by an aperture.

ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED _HRESULT_TYPEDEF_(0xC0262108L)






// The request failed because a pinned allocation can't be evicted.

ERROR_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION _HRESULT_TYPEDEF_(0xC0262109L)






// The allocation can't be used from its current segment location for the specified operation.

ERROR_GRAPHICS_INVALID_ALLOCATION_USAGE _HRESULT_TYPEDEF_(0xC0262110L)






// A locked allocation can't be used in the current command buffer.

ERROR_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION _HRESULT_TYPEDEF_(0xC0262111L)






// The allocation being referenced has been closed permanently.

ERROR_GRAPHICS_ALLOCATION_CLOSED _HRESULT_TYPEDEF_(0xC0262112L)






// An invalid allocation instance is being referenced.

ERROR_GRAPHICS_INVALID_ALLOCATION_INSTANCE _HRESULT_TYPEDEF_(0xC0262113L)






// An invalid allocation handle is being referenced.

ERROR_GRAPHICS_INVALID_ALLOCATION_HANDLE _HRESULT_TYPEDEF_(0xC0262114L)






// The allocation being referenced doesn't belong to the current device.

ERROR_GRAPHICS_WRONG_ALLOCATION_DEVICE _HRESULT_TYPEDEF_(0xC0262115L)






// The specified allocation lost its content.

ERROR_GRAPHICS_ALLOCATION_CONTENT_LOST _HRESULT_TYPEDEF_(0xC0262116L)


// Video GPU Scheduler (VidSch) subsystem errors {0x2200..0x22ff}






// GPU exception is detected on the given device. The device is not able to be scheduled.

ERROR_GRAPHICS_GPU_EXCEPTION_ON_DEVICE _HRESULT_TYPEDEF_(0xC0262200L)






// Skip preparation of allocations referenced by the DMA buffer.

ERROR_GRAPHICS_SKIP_ALLOCATION_PREPARATION _HRESULT_TYPEDEF_(0x40262201L)


// Video Present Network Management (VidPNMgr) subsystem errors {0x2300..0x23ff}






// Specified VidPN topology is invalid.

ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY _HRESULT_TYPEDEF_(0xC0262300L)






// Specified VidPN topology is valid but is not supported by this model of the display adapter.

ERROR_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262301L)






// Specified VidPN topology is valid but is not supported by the display adapter at this time, due to current allocation of its resources.

ERROR_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262302L)






// Specified VidPN handle is invalid.

ERROR_GRAPHICS_INVALID_VIDPN     _HRESULT_TYPEDEF_(0xC0262303L)






// Specified video present source is invalid.

ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE _HRESULT_TYPEDEF_(0xC0262304L)






// Specified video present target is invalid.

ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET _HRESULT_TYPEDEF_(0xC0262305L)






// Specified VidPN modality is not supported (e.g. at least two of the pinned modes are not cofunctional).

ERROR_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262306L)






// No mode is pinned on the specified VidPN source/target.

ERROR_GRAPHICS_MODE_NOT_PINNED   _HRESULT_TYPEDEF_(0x00262307L)






// Specified VidPN source mode set is invalid.

ERROR_GRAPHICS_INVALID_VIDPN_SOURCEMODESET _HRESULT_TYPEDEF_(0xC0262308L)






// Specified VidPN target mode set is invalid.

ERROR_GRAPHICS_INVALID_VIDPN_TARGETMODESET _HRESULT_TYPEDEF_(0xC0262309L)






// Specified video signal frequency is invalid.

ERROR_GRAPHICS_INVALID_FREQUENCY _HRESULT_TYPEDEF_(0xC026230AL)






// Specified video signal active region is invalid.

ERROR_GRAPHICS_INVALID_ACTIVE_REGION _HRESULT_TYPEDEF_(0xC026230BL)






// Specified video signal total region is invalid.

ERROR_GRAPHICS_INVALID_TOTAL_REGION _HRESULT_TYPEDEF_(0xC026230CL)






// Specified video present source mode is invalid.

ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE _HRESULT_TYPEDEF_(0xC0262310L)






// Specified video present target mode is invalid.

ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE _HRESULT_TYPEDEF_(0xC0262311L)






// Pinned mode must remain in the set on VidPN's cofunctional modality enumeration.

ERROR_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET _HRESULT_TYPEDEF_(0xC0262312L)






// Specified video present path is already in VidPN's topology.

ERROR_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY _HRESULT_TYPEDEF_(0xC0262313L)






// Specified mode is already in the mode set.

ERROR_GRAPHICS_MODE_ALREADY_IN_MODESET _HRESULT_TYPEDEF_(0xC0262314L)






// Specified video present source set is invalid.

ERROR_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET _HRESULT_TYPEDEF_(0xC0262315L)






// Specified video present target set is invalid.

ERROR_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET _HRESULT_TYPEDEF_(0xC0262316L)






// Specified video present source is already in the video present source set.

ERROR_GRAPHICS_SOURCE_ALREADY_IN_SET _HRESULT_TYPEDEF_(0xC0262317L)






// Specified video present target is already in the video present target set.

ERROR_GRAPHICS_TARGET_ALREADY_IN_SET _HRESULT_TYPEDEF_(0xC0262318L)






// Specified VidPN present path is invalid.

ERROR_GRAPHICS_INVALID_VIDPN_PRESENT_PATH _HRESULT_TYPEDEF_(0xC0262319L)






// Miniport has no recommendation for augmentation of the specified VidPN's topology.

ERROR_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY _HRESULT_TYPEDEF_(0xC026231AL)






// Specified monitor frequency range set is invalid.

ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET _HRESULT_TYPEDEF_(0xC026231BL)






// Specified monitor frequency range is invalid.

ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE _HRESULT_TYPEDEF_(0xC026231CL)






// Specified frequency range is not in the specified monitor frequency range set.

ERROR_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET _HRESULT_TYPEDEF_(0xC026231DL)






// Specified mode set does not specify preference for one of its modes.

ERROR_GRAPHICS_NO_PREFERRED_MODE _HRESULT_TYPEDEF_(0x0026231EL)






// Specified frequency range is already in the specified monitor frequency range set.

ERROR_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET _HRESULT_TYPEDEF_(0xC026231FL)






// Specified mode set is stale. Please reacquire the new mode set.

ERROR_GRAPHICS_STALE_MODESET     _HRESULT_TYPEDEF_(0xC0262320L)






// Specified monitor source mode set is invalid.

ERROR_GRAPHICS_INVALID_MONITOR_SOURCEMODESET _HRESULT_TYPEDEF_(0xC0262321L)






// Specified monitor source mode is invalid.

ERROR_GRAPHICS_INVALID_MONITOR_SOURCE_MODE _HRESULT_TYPEDEF_(0xC0262322L)






// Miniport does not have any recommendation regarding the request to provide a functional VidPN given the current display adapter configuration.

ERROR_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN _HRESULT_TYPEDEF_(0xC0262323L)






// ID of the specified mode is already used by another mode in the set.

ERROR_GRAPHICS_MODE_ID_MUST_BE_UNIQUE _HRESULT_TYPEDEF_(0xC0262324L)






// System failed to determine a mode that is supported by both the display adapter and the monitor connected to it.

ERROR_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION _HRESULT_TYPEDEF_(0xC0262325L)






// Number of video present targets must be greater than or equal to the number of video present sources.

ERROR_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES _HRESULT_TYPEDEF_(0xC0262326L)






// Specified present path is not in VidPN's topology.

ERROR_GRAPHICS_PATH_NOT_IN_TOPOLOGY _HRESULT_TYPEDEF_(0xC0262327L)






// Display adapter must have at least one video present source.

ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE _HRESULT_TYPEDEF_(0xC0262328L)






// Display adapter must have at least one video present target.

ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET _HRESULT_TYPEDEF_(0xC0262329L)






// Specified monitor descriptor set is invalid.

ERROR_GRAPHICS_INVALID_MONITORDESCRIPTORSET _HRESULT_TYPEDEF_(0xC026232AL)






// Specified monitor descriptor is invalid.

ERROR_GRAPHICS_INVALID_MONITORDESCRIPTOR _HRESULT_TYPEDEF_(0xC026232BL)






// Specified descriptor is not in the specified monitor descriptor set.

ERROR_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET _HRESULT_TYPEDEF_(0xC026232CL)






// Specified descriptor is already in the specified monitor descriptor set.

ERROR_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET _HRESULT_TYPEDEF_(0xC026232DL)






// ID of the specified monitor descriptor is already used by another descriptor in the set.

ERROR_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE _HRESULT_TYPEDEF_(0xC026232EL)






// Specified video present target subset type is invalid.

ERROR_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE _HRESULT_TYPEDEF_(0xC026232FL)






// Two or more of the specified resources are not related to each other, as defined by the interface semantics.

ERROR_GRAPHICS_RESOURCES_NOT_RELATED _HRESULT_TYPEDEF_(0xC0262330L)






// ID of the specified video present source is already used by another source in the set.

ERROR_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE _HRESULT_TYPEDEF_(0xC0262331L)






// ID of the specified video present target is already used by another target in the set.

ERROR_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE _HRESULT_TYPEDEF_(0xC0262332L)






// Specified VidPN source cannot be used because there is no available VidPN target to connect it to.

ERROR_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET _HRESULT_TYPEDEF_(0xC0262333L)






// Newly arrived monitor could not be associated with a display adapter.

ERROR_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER _HRESULT_TYPEDEF_(0xC0262334L)






// Display adapter in question does not have an associated VidPN manager.

ERROR_GRAPHICS_NO_VIDPNMGR       _HRESULT_TYPEDEF_(0xC0262335L)






// VidPN manager of the display adapter in question does not have an active VidPN.

ERROR_GRAPHICS_NO_ACTIVE_VIDPN   _HRESULT_TYPEDEF_(0xC0262336L)






// Specified VidPN topology is stale. Please reacquire the new topology.

ERROR_GRAPHICS_STALE_VIDPN_TOPOLOGY _HRESULT_TYPEDEF_(0xC0262337L)






// There is no monitor connected on the specified video present target.

ERROR_GRAPHICS_MONITOR_NOT_CONNECTED _HRESULT_TYPEDEF_(0xC0262338L)






// Specified source is not part of the specified VidPN's topology.

ERROR_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY _HRESULT_TYPEDEF_(0xC0262339L)






// Specified primary surface size is invalid.

ERROR_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE _HRESULT_TYPEDEF_(0xC026233AL)






// Specified visible region size is invalid.

ERROR_GRAPHICS_INVALID_VISIBLEREGION_SIZE _HRESULT_TYPEDEF_(0xC026233BL)






// Specified stride is invalid.

ERROR_GRAPHICS_INVALID_STRIDE    _HRESULT_TYPEDEF_(0xC026233CL)






// Specified pixel format is invalid.

ERROR_GRAPHICS_INVALID_PIXELFORMAT _HRESULT_TYPEDEF_(0xC026233DL)






// Specified color basis is invalid.

ERROR_GRAPHICS_INVALID_COLORBASIS _HRESULT_TYPEDEF_(0xC026233EL)






// Specified pixel value access mode is invalid.

ERROR_GRAPHICS_INVALID_PIXELVALUEACCESSMODE _HRESULT_TYPEDEF_(0xC026233FL)






// Specified target is not part of the specified VidPN's topology.

ERROR_GRAPHICS_TARGET_NOT_IN_TOPOLOGY _HRESULT_TYPEDEF_(0xC0262340L)






// Failed to acquire display mode management interface.

ERROR_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT _HRESULT_TYPEDEF_(0xC0262341L)






// Specified VidPN source is already owned by a DMM client and cannot be used until that client releases it.

ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE _HRESULT_TYPEDEF_(0xC0262342L)






// Specified VidPN is active and cannot be accessed.

ERROR_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN _HRESULT_TYPEDEF_(0xC0262343L)






// Specified VidPN present path importance ordinal is invalid.

ERROR_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL _HRESULT_TYPEDEF_(0xC0262344L)






// Specified VidPN present path content geometry transformation is invalid.

ERROR_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION _HRESULT_TYPEDEF_(0xC0262345L)






// Specified content geometry transformation is not supported on the respective VidPN present path.

ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262346L)






// Specified gamma ramp is invalid.

ERROR_GRAPHICS_INVALID_GAMMA_RAMP _HRESULT_TYPEDEF_(0xC0262347L)






// Specified gamma ramp is not supported on the respective VidPN present path.

ERROR_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262348L)






// Multi-sampling is not supported on the respective VidPN present path.

ERROR_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262349L)






// Specified mode is not in the specified mode set.

ERROR_GRAPHICS_MODE_NOT_IN_MODESET _HRESULT_TYPEDEF_(0xC026234AL)






// Specified data set (e.g. mode set, frequency range set, descriptor set, topology, etc.) is empty.

ERROR_GRAPHICS_DATASET_IS_EMPTY  _HRESULT_TYPEDEF_(0x0026234BL)






// Specified data set (e.g. mode set, frequency range set, descriptor set, topology, etc.) does not contain any more elements.

ERROR_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET _HRESULT_TYPEDEF_(0x0026234CL)






// Specified VidPN topology recommendation reason is invalid.

ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON _HRESULT_TYPEDEF_(0xC026234DL)






// Specified VidPN present path content type is invalid.

ERROR_GRAPHICS_INVALID_PATH_CONTENT_TYPE _HRESULT_TYPEDEF_(0xC026234EL)






// Specified VidPN present path copy protection type is invalid.

ERROR_GRAPHICS_INVALID_COPYPROTECTION_TYPE _HRESULT_TYPEDEF_(0xC026234FL)






// No more than one unassigned mode set can exist at any given time for a given VidPN source/target.

ERROR_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS _HRESULT_TYPEDEF_(0xC0262350L)






// Specified content transformation is not pinned on the specified VidPN present path.

ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED _HRESULT_TYPEDEF_(0x00262351L)






// Specified scanline ordering type is invalid.

ERROR_GRAPHICS_INVALID_SCANLINE_ORDERING _HRESULT_TYPEDEF_(0xC0262352L)






// Topology changes are not allowed for the specified VidPN.

ERROR_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED _HRESULT_TYPEDEF_(0xC0262353L)






// All available importance ordinals are already used in specified topology.

ERROR_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS _HRESULT_TYPEDEF_(0xC0262354L)






// Specified primary surface has a different private format attribute than the current primary surface

ERROR_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT _HRESULT_TYPEDEF_(0xC0262355L)






// Specified mode pruning algorithm is invalid

ERROR_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM _HRESULT_TYPEDEF_(0xC0262356L)






// Specified monitor capability origin is invalid.

ERROR_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN _HRESULT_TYPEDEF_(0xC0262357L)






// Specified monitor frequency range constraint is invalid.

ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT _HRESULT_TYPEDEF_(0xC0262358L)






// Maximum supported number of present paths has been reached.

ERROR_GRAPHICS_MAX_NUM_PATHS_REACHED _HRESULT_TYPEDEF_(0xC0262359L)






// Miniport requested that augmentation be cancelled for the specified source of the specified VidPN's topology.

ERROR_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION _HRESULT_TYPEDEF_(0xC026235AL)






// Specified client type was not recognized.

ERROR_GRAPHICS_INVALID_CLIENT_TYPE _HRESULT_TYPEDEF_(0xC026235BL)






// Client VidPN is not set on this adapter (e.g. no user mode initiated mode changes took place on this adapter yet).

ERROR_GRAPHICS_CLIENTVIDPN_NOT_SET _HRESULT_TYPEDEF_(0xC026235CL)


// Port specific status codes {0x2400..0x24ff}






// Specified display adapter child device already has an external device connected to it.

ERROR_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED _HRESULT_TYPEDEF_(0xC0262400L)    






// Specified display adapter child device does not support descriptor exposure.

ERROR_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262401L)    






// Child device presence was not reliably detected.

ERROR_GRAPHICS_UNKNOWN_CHILD_STATUS _HRESULT_TYPEDEF_(0x4026242FL)






// The display adapter is not linked to any other adapters.

ERROR_GRAPHICS_NOT_A_LINKED_ADAPTER _HRESULT_TYPEDEF_(0xC0262430L)






// Lead adapter in a linked configuration was not enumerated yet.

ERROR_GRAPHICS_LEADLINK_NOT_ENUMERATED _HRESULT_TYPEDEF_(0xC0262431L)






// Some chain adapters in a linked configuration were not enumerated yet.

ERROR_GRAPHICS_CHAINLINKS_NOT_ENUMERATED _HRESULT_TYPEDEF_(0xC0262432L)






// The chain of linked adapters is not ready to start because of an unknown failure.

ERROR_GRAPHICS_ADAPTER_CHAIN_NOT_READY _HRESULT_TYPEDEF_(0xC0262433L)






// An attempt was made to start a lead link display adapter when the chain links were not started yet.

ERROR_GRAPHICS_CHAINLINKS_NOT_STARTED _HRESULT_TYPEDEF_(0xC0262434L)






// An attempt was made to power up a lead link display adapter when the chain links were powered down.

ERROR_GRAPHICS_CHAINLINKS_NOT_POWERED_ON _HRESULT_TYPEDEF_(0xC0262435L)






// The adapter link was found to be in an inconsistent state. Not all adapters are in an expected PNP/Power state.

ERROR_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE _HRESULT_TYPEDEF_(0xC0262436L)






// Starting the leadlink adapter has been deferred temporarily.

ERROR_GRAPHICS_LEADLINK_START_DEFERRED _HRESULT_TYPEDEF_(0x40262437L)






// The driver trying to start is not the same as the driver for the POSTed display adapter.

ERROR_GRAPHICS_NOT_POST_DEVICE_DRIVER _HRESULT_TYPEDEF_(0xC0262438L)






// The display adapter is being polled for children too frequently at the same polling level.

ERROR_GRAPHICS_POLLING_TOO_FREQUENTLY _HRESULT_TYPEDEF_(0x40262439L)






// Starting the adapter has been deferred temporarily.

ERROR_GRAPHICS_START_DEFERRED    _HRESULT_TYPEDEF_(0x4026243AL)






// An operation is being attempted that requires the display adapter to be in a quiescent state.

ERROR_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED _HRESULT_TYPEDEF_(0xC026243BL)






// We can depend on the child device presence returned by the driver.

ERROR_GRAPHICS_DEPENDABLE_CHILD_STATUS _HRESULT_TYPEDEF_(0x4026243CL)


// OPM, UAB and PVP specific error codes {0x2500..0x257f}






// The driver does not support OPM.

ERROR_GRAPHICS_OPM_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262500L)    






// The driver does not support COPP.

ERROR_GRAPHICS_COPP_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262501L)    






// The driver does not support UAB.

ERROR_GRAPHICS_UAB_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262502L)    






// The specified encrypted parameters are invalid.

ERROR_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS _HRESULT_TYPEDEF_(0xC0262503L)    






// The GDI display device passed to this function does not have any active video outputs.

ERROR_GRAPHICS_OPM_NO_VIDEO_OUTPUTS_EXIST _HRESULT_TYPEDEF_(0xC0262505L)






// An internal error caused this operation to fail.

ERROR_GRAPHICS_OPM_INTERNAL_ERROR _HRESULT_TYPEDEF_(0xC026250BL)






// The function failed because the caller passed in an invalid OPM user mode handle.

ERROR_GRAPHICS_OPM_INVALID_HANDLE _HRESULT_TYPEDEF_(0xC026250CL)






// A certificate could not be returned because the certificate buffer passed to the function was too small.

ERROR_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH _HRESULT_TYPEDEF_(0xC026250EL)






// A video output could not be created because the frame buffer is in spanning mode.

ERROR_GRAPHICS_OPM_SPANNING_MODE_ENABLED _HRESULT_TYPEDEF_(0xC026250FL)






// A video output could not be created because the frame buffer is in theater mode.

ERROR_GRAPHICS_OPM_THEATER_MODE_ENABLED _HRESULT_TYPEDEF_(0xC0262510L)






// The function failed because the display adapter's Hardware Functionality Scan failed to validate the graphics hardware.

ERROR_GRAPHICS_PVP_HFS_FAILED    _HRESULT_TYPEDEF_(0xC0262511L)






// The HDCP System Renewability Message passed to this function did not comply with section 5 of the HDCP 1.1 specification.

ERROR_GRAPHICS_OPM_INVALID_SRM   _HRESULT_TYPEDEF_(0xC0262512L)






// The video output cannot enable the High-bandwidth Digital Content Protection (HDCP) System because it does not support HDCP.

ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP _HRESULT_TYPEDEF_(0xC0262513L)






// The video output cannot enable Analogue Copy Protection (ACP) because it does not support ACP.

ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP _HRESULT_TYPEDEF_(0xC0262514L)






// The video output cannot enable the Content Generation Management System Analogue (CGMS-A) protection technology because it does not support CGMS-A.

ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA _HRESULT_TYPEDEF_(0xC0262515L)






// The IOPMVideoOutput::GetInformation method cannot return the version of the SRM being used because the application never successfully passed an SRM to the video output.

ERROR_GRAPHICS_OPM_HDCP_SRM_NEVER_SET _HRESULT_TYPEDEF_(0xC0262516L)






// The IOPMVideoOutput::Configure method cannot enable the specified output protection technology because the output's screen resolution is too high.

ERROR_GRAPHICS_OPM_RESOLUTION_TOO_HIGH _HRESULT_TYPEDEF_(0xC0262517L)






// The IOPMVideoOutput::Configure method cannot enable HDCP because the display adapter's HDCP hardware is already being used by other physical outputs.

ERROR_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE _HRESULT_TYPEDEF_(0xC0262518L)






// The operating system asynchronously destroyed this OPM video output because the operating system's state changed. This error typically occurs because the monitor PDO associated with this video output was removed, the monitor PDO associated with this video output was stopped, the video output's session became a non-console session or the video output's desktop became an inactive desktop.

ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_NO_LONGER_EXISTS _HRESULT_TYPEDEF_(0xC026251AL)






// The method failed because the session is changing its type. No IOPMVideoOutput methods can be called when a session is changing its type. There are currently three types of sessions: console, disconnected and remote.

ERROR_GRAPHICS_OPM_SESSION_TYPE_CHANGE_IN_PROGRESS _HRESULT_TYPEDEF_(0xC026251BL)






// Either the IOPMVideoOutput::COPPCompatibleGetInformation, IOPMVideoOutput::GetInformation, or IOPMVideoOutput::Configure method failed. This error is returned when the caller tries to use a COPP specific command while the video output has OPM semantics only.

ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS _HRESULT_TYPEDEF_(0xC026251CL)






// The IOPMVideoOutput::GetInformation and IOPMVideoOutput::COPPCompatibleGetInformation methods return this error if the passed in sequence number is not the expected sequence number or the passed in OMAC value is invalid.

ERROR_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST _HRESULT_TYPEDEF_(0xC026251DL)






// The method failed because an unexpected error occurred inside of a display driver.

ERROR_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR _HRESULT_TYPEDEF_(0xC026251EL)






// Either the IOPMVideoOutput::COPPCompatibleGetInformation, IOPMVideoOutput::GetInformation, or IOPMVideoOutput::Configure method failed. This error is returned when the caller tries to use an OPM specific command while the video output has COPP semantics only.

ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS _HRESULT_TYPEDEF_(0xC026251FL)






// The IOPMVideoOutput::COPPCompatibleGetInformation or IOPMVideoOutput::Configure method failed because the display driver does not support the OPM_GET_ACP_AND_CGMSA_SIGNALING and OPM_SET_ACP_AND_CGMSA_SIGNALING GUIDs.

ERROR_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262520L)






// The IOPMVideoOutput::Configure function returns this error code if the passed in sequence number is not the expected sequence number or the passed in OMAC value is invalid.

ERROR_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST _HRESULT_TYPEDEF_(0xC0262521L)


// Monitor Configuration API error codes {0x2580..0x25DF}






// The monitor connected to the specified video output does not have an I2C bus.

ERROR_GRAPHICS_I2C_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262580L)    






// No device on the I2C bus has the specified address.

ERROR_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST _HRESULT_TYPEDEF_(0xC0262581L)    






// An error occurred while transmitting data to the device on the I2C bus.

ERROR_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA _HRESULT_TYPEDEF_(0xC0262582L)    






// An error occurred while receiving data from the device on the I2C bus.

ERROR_GRAPHICS_I2C_ERROR_RECEIVING_DATA _HRESULT_TYPEDEF_(0xC0262583L)    






// The monitor does not support the specified VCP code.

ERROR_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC0262584L)    






// The data received from the monitor is invalid.

ERROR_GRAPHICS_DDCCI_INVALID_DATA _HRESULT_TYPEDEF_(0xC0262585L)    






// The function failed because a monitor returned an invalid Timing Status byte when the operating system used the DDC/CI Get Timing Report & Timing Message command to get a timing report from a monitor.

ERROR_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE _HRESULT_TYPEDEF_(0xC0262586L)






// The monitor returned a DDC/CI capabilities string which did not comply with the ACCESS.bus 3.0, DDC/CI 1.1, or MCCS 2 Revision 1 specification.

ERROR_GRAPHICS_MCA_INVALID_CAPABILITIES_STRING _HRESULT_TYPEDEF_(0xC0262587L)






// An internal Monitor Configuration API error occurred.

ERROR_GRAPHICS_MCA_INTERNAL_ERROR _HRESULT_TYPEDEF_(0xC0262588L)






// An operation failed because a DDC/CI message had an invalid value in its command field.

ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND _HRESULT_TYPEDEF_(0xC0262589L)






// An error occurred because the field length of a DDC/CI message contained an invalid value.

ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH _HRESULT_TYPEDEF_(0xC026258AL)






// An error occurred because the checksum field in a DDC/CI message did not match the message's computed checksum value. This error implies that the data was corrupted while it was being transmitted from a monitor to a computer.

ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM _HRESULT_TYPEDEF_(0xC026258BL)






// This function failed because an invalid monitor handle was passed to it.

ERROR_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE _HRESULT_TYPEDEF_(0xC026258CL)






// The operating system asynchronously destroyed the monitor which corresponds to this handle because the operating system's state changed. This error typically occurs because the monitor PDO associated with this handle was removed, the monitor PDO associated with this handle was stopped, or a display mode change occurred. A display mode change occurs when windows sends a WM_DISPLAYCHANGE windows message to applications.

ERROR_GRAPHICS_MONITOR_NO_LONGER_EXISTS _HRESULT_TYPEDEF_(0xC026258DL)






// A continuous VCP code's current value is greater than its maximum value. This error code indicates that a monitor returned an invalid value.

ERROR_GRAPHICS_DDCCI_CURRENT_CURRENT_VALUE_GREATER_THAN_MAXIMUM_VALUE _HRESULT_TYPEDEF_(0xC02625D8L)






// The monitor's VCP Version (0xDF) VCP code returned an invalid version value.

ERROR_GRAPHICS_MCA_INVALID_VCP_VERSION _HRESULT_TYPEDEF_(0xC02625D9L)






// The monitor does not comply with the MCCS specification it claims to support.

ERROR_GRAPHICS_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION _HRESULT_TYPEDEF_(0xC02625DAL)






// The MCCS version in a monitor's mccs_ver capability does not match the MCCS version the monitor reports when the VCP Version (0xDF) VCP code is used.

ERROR_GRAPHICS_MCA_MCCS_VERSION_MISMATCH _HRESULT_TYPEDEF_(0xC02625DBL)






// The Monitor Configuration API only works with monitors which support the MCCS 1.0 specification, MCCS 2.0 specification or the MCCS 2.0 Revision 1 specification.

ERROR_GRAPHICS_MCA_UNSUPPORTED_MCCS_VERSION _HRESULT_TYPEDEF_(0xC02625DCL)






// The monitor returned an invalid monitor technology type. CRT, Plasma and LCD (TFT) are examples of monitor technology types. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.

ERROR_GRAPHICS_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED _HRESULT_TYPEDEF_(0xC02625DEL)






// SetMonitorColorTemperature()'s caller passed a color temperature to it which the current monitor did not support. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.

ERROR_GRAPHICS_MCA_UNSUPPORTED_COLOR_TEMPERATURE _HRESULT_TYPEDEF_(0xC02625DFL)


// OPM, UAB, PVP and DDC/CI shared error codes {0x25E0..0x25ff}






// This function can only be used if a program is running in the local console session. It cannot be used if the program is running on a remote desktop session or on a terminal server session.

ERROR_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED _HRESULT_TYPEDEF_(0xC02625E0L)






// This function cannot find an actual GDI display device which corresponds to the specified GDI display device name.

ERROR_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME _HRESULT_TYPEDEF_(0xC02625E1L)






// The function failed because the specified GDI display device was not attached to the Windows desktop.

ERROR_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP _HRESULT_TYPEDEF_(0xC02625E2L)






// This function does not support GDI mirroring display devices because GDI mirroring display devices do not have any physical monitors associated with them.

ERROR_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED _HRESULT_TYPEDEF_(0xC02625E3L)






// The function failed because an invalid pointer parameter was passed to it. A pointer parameter is invalid if it is NULL, points to an invalid address, points to a kernel mode address, or is not correctly aligned.

ERROR_GRAPHICS_INVALID_POINTER   _HRESULT_TYPEDEF_(0xC02625E4L)






// The function failed because the specified GDI device did not have any monitors associated with it.

ERROR_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE _HRESULT_TYPEDEF_(0xC02625E5L)






// An array passed to the function cannot hold all of the data that the function must copy into the array.

ERROR_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL _HRESULT_TYPEDEF_(0xC02625E6L)






// An internal error caused an operation to fail.

ERROR_GRAPHICS_INTERNAL_ERROR    _HRESULT_TYPEDEF_(0xC02625E7L)






// The function failed because the current session is changing its type. This function cannot be called when the current session is changing its type. There are currently three types of sessions: console, disconnected and remote.

ERROR_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS _HRESULT_TYPEDEF_(0xC02605E8L)


// FACILITY_NAP






// The NAP SoH packet is invalid.

NAP_E_INVALID_PACKET             _HRESULT_TYPEDEF_(0x80270001L)






// An SoH was missing from the NAP packet.

NAP_E_MISSING_SOH                _HRESULT_TYPEDEF_(0x80270002L)






// The entity ID conflicts with an already registered id.

NAP_E_CONFLICTING_ID             _HRESULT_TYPEDEF_(0x80270003L)






// No cached SoH is present.

NAP_E_NO_CACHED_SOH              _HRESULT_TYPEDEF_(0x80270004L)






// The entity is still bound to the NAP system.

NAP_E_STILL_BOUND                _HRESULT_TYPEDEF_(0x80270005L)






// The entity is not registered with the NAP system.

NAP_E_NOT_REGISTERED             _HRESULT_TYPEDEF_(0x80270006L)






// The entity is not initialized with the NAP system.

NAP_E_NOT_INITIALIZED            _HRESULT_TYPEDEF_(0x80270007L)






// The correlation id in the SoH-Request and SoH-Response do not match up.

NAP_E_MISMATCHED_ID              _HRESULT_TYPEDEF_(0x80270008L)






// Completion was indicated on a request that is not currently pending.

NAP_E_NOT_PENDING                _HRESULT_TYPEDEF_(0x80270009L)






// The NAP component's id was not found.

NAP_E_ID_NOT_FOUND               _HRESULT_TYPEDEF_(0x8027000AL)






// The maximum size of the connection is too small for an SoH packet.

NAP_E_MAXSIZE_TOO_SMALL          _HRESULT_TYPEDEF_(0x8027000BL)






// The NapAgent service is not running.

NAP_E_SERVICE_NOT_RUNNING        _HRESULT_TYPEDEF_(0x8027000CL)






// A certificate is already present in the cert store.

NAP_S_CERT_ALREADY_PRESENT       _HRESULT_TYPEDEF_(0x0027000DL)






// The entity is disabled with the NapAgent service.

NAP_E_ENTITY_DISABLED            _HRESULT_TYPEDEF_(0x8027000EL)






// Group Policy is not configured.

NAP_E_NETSH_GROUPPOLICY_ERROR    _HRESULT_TYPEDEF_(0x8027000FL)






// Too many simultaneous calls.

NAP_E_TOO_MANY_CALLS             _HRESULT_TYPEDEF_(0x80270010L)






// SHV configuration already existed.

NAP_E_SHV_CONFIG_EXISTED         _HRESULT_TYPEDEF_(0x80270011L)






// SHV configuration is not found.

NAP_E_SHV_CONFIG_NOT_FOUND       _HRESULT_TYPEDEF_(0x80270012L)






// SHV timed out on the request.

NAP_E_SHV_TIMEOUT                _HRESULT_TYPEDEF_(0x80270013L)


// ===============================
// TPM Services and TPM Software Error Messages
// ===============================

// The TPM services and TPM software facilities are used by the various
// TPM software components. There are two facilities because the services
// errors are within the TCG-defined error space and the software errors
// are not.

// The following are the subranges within the TPM Services facility.
// The TPM hardware errors are defined in the document
// TPM Main Specification 1.2 Part 2 TPM Structures.
// The TBS errors are slotted into the TCG error namespace at the TBS layer.

// 0x0000 - 0x08ff     TPM hardware errors
// 0x4000 - 0x40ff     TPM Base Services errors (tbssvc.dll)

// The following are the subranges within the TPM Software facility. The TBS
// has two classes of errors - those that can be returned (the public errors,
// defined in the TBS spec), which are in the TPM services facility,  and
// those that are internal or implementation specific, which are here in the
// TPM software facility.

// 0x0000 - 0x00ff     TPM device driver errors (tpm.sys)
// 0x0100 - 0x01ff     TPM API errors (tpmapi.lib)
// 0x0200 - 0x02ff     TBS internal errors (tbssvc.dll)
// 0x0300 - 0x03ff     TPM Physical Presence errors


// TPM hardware error codes {0x0000..0x08ff}
// This space is further subdivided into hardware errors, vendor-specific
// errors, and non-fatal errors.


// TPM hardware errors {0x0000..0x003ff}






// This is an error mask to convert TPM hardware errors to win errors.

TPM_E_ERROR_MASK                 _HRESULT_TYPEDEF_(0x80280000L)






// TPM 1.2: Authentication failed.

TPM_E_AUTHFAIL                   _HRESULT_TYPEDEF_(0x80280001L)






// TPM 1.2: The index to a PCR, DIR or other register is incorrect.

TPM_E_BADINDEX                   _HRESULT_TYPEDEF_(0x80280002L)






// TPM 1.2: One or more parameter is bad.

TPM_E_BAD_PARAMETER              _HRESULT_TYPEDEF_(0x80280003L)






// TPM 1.2: An operation completed successfully but the auditing of that operation failed.

TPM_E_AUDITFAILURE               _HRESULT_TYPEDEF_(0x80280004L)






// TPM 1.2: The clear disable flag is set and all clear operations now require physical access.

TPM_E_CLEAR_DISABLED             _HRESULT_TYPEDEF_(0x80280005L)






// TPM 1.2: Activate the Trusted Platform Module (TPM).

TPM_E_DEACTIVATED                _HRESULT_TYPEDEF_(0x80280006L)






// TPM 1.2: Enable the Trusted Platform Module (TPM).

TPM_E_DISABLED                   _HRESULT_TYPEDEF_(0x80280007L)






// TPM 1.2: The target command has been disabled.

TPM_E_DISABLED_CMD               _HRESULT_TYPEDEF_(0x80280008L)






// TPM 1.2: The operation failed.

TPM_E_FAIL                       _HRESULT_TYPEDEF_(0x80280009L)






// TPM 1.2: The ordinal was unknown or inconsistent.

TPM_E_BAD_ORDINAL                _HRESULT_TYPEDEF_(0x8028000AL)






// TPM 1.2: The ability to install an owner is disabled.

TPM_E_INSTALL_DISABLED           _HRESULT_TYPEDEF_(0x8028000BL)






// TPM 1.2: The key handle cannot be interpreted.

TPM_E_INVALID_KEYHANDLE          _HRESULT_TYPEDEF_(0x8028000CL)






// TPM 1.2: The key handle points to an invalid key.

TPM_E_KEYNOTFOUND                _HRESULT_TYPEDEF_(0x8028000DL)






// TPM 1.2: Unacceptable encryption scheme.

TPM_E_INAPPROPRIATE_ENC          _HRESULT_TYPEDEF_(0x8028000EL)






// TPM 1.2: Migration authorization failed.

TPM_E_MIGRATEFAIL                _HRESULT_TYPEDEF_(0x8028000FL)






// TPM 1.2: PCR information could not be interpreted.

TPM_E_INVALID_PCR_INFO           _HRESULT_TYPEDEF_(0x80280010L)






// TPM 1.2: No room to load key.

TPM_E_NOSPACE                    _HRESULT_TYPEDEF_(0x80280011L)






// TPM 1.2: There is no Storage Root Key (SRK) set.

TPM_E_NOSRK                      _HRESULT_TYPEDEF_(0x80280012L)






// TPM 1.2: An encrypted blob is invalid or was not created by this TPM.

TPM_E_NOTSEALED_BLOB             _HRESULT_TYPEDEF_(0x80280013L)






// TPM 1.2: The Trusted Platform Module (TPM) already has an owner.

TPM_E_OWNER_SET                  _HRESULT_TYPEDEF_(0x80280014L)






// TPM 1.2: The TPM has insufficient internal resources to perform the requested action.

TPM_E_RESOURCES                  _HRESULT_TYPEDEF_(0x80280015L)






// TPM 1.2: A random string was too short.

TPM_E_SHORTRANDOM                _HRESULT_TYPEDEF_(0x80280016L)






// TPM 1.2: The TPM does not have the space to perform the operation.

TPM_E_SIZE                       _HRESULT_TYPEDEF_(0x80280017L)






// TPM 1.2: The named PCR value does not match the current PCR value.

TPM_E_WRONGPCRVAL                _HRESULT_TYPEDEF_(0x80280018L)






// TPM 1.2: The paramSize argument to the command has the incorrect value .

TPM_E_BAD_PARAM_SIZE             _HRESULT_TYPEDEF_(0x80280019L)






// TPM 1.2: There is no existing SHA-1 thread.

TPM_E_SHA_THREAD                 _HRESULT_TYPEDEF_(0x8028001AL)






// TPM 1.2: The calculation is unable to proceed because the existing SHA-1 thread has already encountered an error.

TPM_E_SHA_ERROR                  _HRESULT_TYPEDEF_(0x8028001BL)






// TPM 1.2: The TPM hardware device reported a failure during its internal self test. Try restarting the computer to resolve the problem. If the problem continues, check for the latest BIOS or firmware update for your TPM hardware. Consult the computer manufacturer's documentation for instructions.

TPM_E_FAILEDSELFTEST             _HRESULT_TYPEDEF_(0x8028001CL)






// TPM 1.2: The authorization for the second key in a 2 key function failed authorization.

TPM_E_AUTH2FAIL                  _HRESULT_TYPEDEF_(0x8028001DL)






// TPM 1.2: The tag value sent to for a command is invalid.

TPM_E_BADTAG                     _HRESULT_TYPEDEF_(0x8028001EL)






// TPM 1.2: An IO error occurred transmitting information to the TPM.

TPM_E_IOERROR                    _HRESULT_TYPEDEF_(0x8028001FL)






// TPM 1.2: The encryption process had a problem.

TPM_E_ENCRYPT_ERROR              _HRESULT_TYPEDEF_(0x80280020L)






// TPM 1.2: The decryption process did not complete.

TPM_E_DECRYPT_ERROR              _HRESULT_TYPEDEF_(0x80280021L)






// TPM 1.2: An invalid handle was used.

TPM_E_INVALID_AUTHHANDLE         _HRESULT_TYPEDEF_(0x80280022L)






// TPM 1.2: The TPM does not have an Endorsement Key (EK) installed.

TPM_E_NO_ENDORSEMENT             _HRESULT_TYPEDEF_(0x80280023L)






// TPM 1.2: The usage of a key is not allowed.

TPM_E_INVALID_KEYUSAGE           _HRESULT_TYPEDEF_(0x80280024L)






// TPM 1.2: The submitted entity type is not allowed.

TPM_E_WRONG_ENTITYTYPE           _HRESULT_TYPEDEF_(0x80280025L)






// TPM 1.2: The command was received in the wrong sequence relative to TPM_Init and a subsequent TPM_Startup.

TPM_E_INVALID_POSTINIT           _HRESULT_TYPEDEF_(0x80280026L)






// TPM 1.2: Signed data cannot include additional DER information.

TPM_E_INAPPROPRIATE_SIG          _HRESULT_TYPEDEF_(0x80280027L)






// TPM 1.2: The key properties in TPM_KEY_PARMs are not supported by this TPM.

TPM_E_BAD_KEY_PROPERTY           _HRESULT_TYPEDEF_(0x80280028L)






// TPM 1.2: The migration properties of this key are incorrect.

TPM_E_BAD_MIGRATION              _HRESULT_TYPEDEF_(0x80280029L)






// TPM 1.2: The signature or encryption scheme for this key is incorrect or not permitted in this situation.

TPM_E_BAD_SCHEME                 _HRESULT_TYPEDEF_(0x8028002AL)






// TPM 1.2: The size of the data (or blob) parameter is bad or inconsistent with the referenced key.

TPM_E_BAD_DATASIZE               _HRESULT_TYPEDEF_(0x8028002BL)






// TPM 1.2: A mode parameter is bad, such as capArea or subCapArea for TPM_GetCapability, phsicalPresence parameter for TPM_PhysicalPresence, or migrationType for TPM_CreateMigrationBlob.

TPM_E_BAD_MODE                   _HRESULT_TYPEDEF_(0x8028002CL)






// TPM 1.2: Either the physicalPresence or physicalPresenceLock bits have the wrong value.

TPM_E_BAD_PRESENCE               _HRESULT_TYPEDEF_(0x8028002DL)






// TPM 1.2: The TPM cannot perform this version of the capability.

TPM_E_BAD_VERSION                _HRESULT_TYPEDEF_(0x8028002EL)






// TPM 1.2: The TPM does not allow for wrapped transport sessions.

TPM_E_NO_WRAP_TRANSPORT          _HRESULT_TYPEDEF_(0x8028002FL)






// TPM 1.2: TPM audit construction failed and the underlying command was returning a failure code also.

TPM_E_AUDITFAIL_UNSUCCESSFUL     _HRESULT_TYPEDEF_(0x80280030L)






// TPM 1.2: TPM audit construction failed and the underlying command was returning success.

TPM_E_AUDITFAIL_SUCCESSFUL       _HRESULT_TYPEDEF_(0x80280031L)






// TPM 1.2: Attempt to reset a PCR register that does not have the resettable attribute.

TPM_E_NOTRESETABLE               _HRESULT_TYPEDEF_(0x80280032L)






// TPM 1.2: Attempt to reset a PCR register that requires locality and locality modifier not part of command transport.

TPM_E_NOTLOCAL                   _HRESULT_TYPEDEF_(0x80280033L)






// TPM 1.2: Make identity blob not properly typed.

TPM_E_BAD_TYPE                   _HRESULT_TYPEDEF_(0x80280034L)






// TPM 1.2: When saving context identified resource type does not match actual resource.

TPM_E_INVALID_RESOURCE           _HRESULT_TYPEDEF_(0x80280035L)






// TPM 1.2: The TPM is attempting to execute a command only available when in FIPS mode.

TPM_E_NOTFIPS                    _HRESULT_TYPEDEF_(0x80280036L)






// TPM 1.2: The command is attempting to use an invalid family ID.

TPM_E_INVALID_FAMILY             _HRESULT_TYPEDEF_(0x80280037L)






// TPM 1.2: The permission to manipulate the NV storage is not available.

TPM_E_NO_NV_PERMISSION           _HRESULT_TYPEDEF_(0x80280038L)






// TPM 1.2: The operation requires a signed command.

TPM_E_REQUIRES_SIGN              _HRESULT_TYPEDEF_(0x80280039L)






// TPM 1.2: Wrong operation to load an NV key.

TPM_E_KEY_NOTSUPPORTED           _HRESULT_TYPEDEF_(0x8028003AL)






// TPM 1.2: NV_LoadKey blob requires both owner and blob authorization.

TPM_E_AUTH_CONFLICT              _HRESULT_TYPEDEF_(0x8028003BL)






// TPM 1.2: The NV area is locked and not writable.

TPM_E_AREA_LOCKED                _HRESULT_TYPEDEF_(0x8028003CL)






// TPM 1.2: The locality is incorrect for the attempted operation.

TPM_E_BAD_LOCALITY               _HRESULT_TYPEDEF_(0x8028003DL)






// TPM 1.2: The NV area is read only and can't be written to.

TPM_E_READ_ONLY                  _HRESULT_TYPEDEF_(0x8028003EL)






// TPM 1.2: There is no protection on the write to the NV area.

TPM_E_PER_NOWRITE                _HRESULT_TYPEDEF_(0x8028003FL)






// TPM 1.2: The family count value does not match.

TPM_E_FAMILYCOUNT                _HRESULT_TYPEDEF_(0x80280040L)






// TPM 1.2: The NV area has already been written to.

TPM_E_WRITE_LOCKED               _HRESULT_TYPEDEF_(0x80280041L)






// TPM 1.2: The NV area attributes conflict.

TPM_E_BAD_ATTRIBUTES             _HRESULT_TYPEDEF_(0x80280042L)






// TPM 1.2: The structure tag and version are invalid or inconsistent.

TPM_E_INVALID_STRUCTURE          _HRESULT_TYPEDEF_(0x80280043L)






// TPM 1.2: The key is under control of the TPM Owner and can only be evicted by the TPM Owner.

TPM_E_KEY_OWNER_CONTROL          _HRESULT_TYPEDEF_(0x80280044L)






// TPM 1.2: The counter handle is incorrect.

TPM_E_BAD_COUNTER                _HRESULT_TYPEDEF_(0x80280045L)






// TPM 1.2: The write is not a complete write of the area.

TPM_E_NOT_FULLWRITE              _HRESULT_TYPEDEF_(0x80280046L)






// TPM 1.2: The gap between saved context counts is too large.

TPM_E_CONTEXT_GAP                _HRESULT_TYPEDEF_(0x80280047L)






// TPM 1.2: The maximum number of NV writes without an owner has been exceeded.

TPM_E_MAXNVWRITES                _HRESULT_TYPEDEF_(0x80280048L)






// TPM 1.2: No operator AuthData value is set.

TPM_E_NOOPERATOR                 _HRESULT_TYPEDEF_(0x80280049L)






// TPM 1.2: The resource pointed to by context is not loaded.

TPM_E_RESOURCEMISSING            _HRESULT_TYPEDEF_(0x8028004AL)






// TPM 1.2: The delegate administration is locked.

TPM_E_DELEGATE_LOCK              _HRESULT_TYPEDEF_(0x8028004BL)






// TPM 1.2: Attempt to manage a family other then the delegated family.

TPM_E_DELEGATE_FAMILY            _HRESULT_TYPEDEF_(0x8028004CL)






// TPM 1.2: Delegation table management not enabled.

TPM_E_DELEGATE_ADMIN             _HRESULT_TYPEDEF_(0x8028004DL)






// TPM 1.2: There was a command executed outside of an exclusive transport session.

TPM_E_TRANSPORT_NOTEXCLUSIVE     _HRESULT_TYPEDEF_(0x8028004EL)






// TPM 1.2: Attempt to context save a owner evict controlled key.

TPM_E_OWNER_CONTROL              _HRESULT_TYPEDEF_(0x8028004FL)






// TPM 1.2: The DAA command has no resources available to execute the command.

TPM_E_DAA_RESOURCES              _HRESULT_TYPEDEF_(0x80280050L)






// TPM 1.2: The consistency check on DAA parameter inputData0 has failed.

TPM_E_DAA_INPUT_DATA0            _HRESULT_TYPEDEF_(0x80280051L)






// TPM 1.2: The consistency check on DAA parameter inputData1 has failed.

TPM_E_DAA_INPUT_DATA1            _HRESULT_TYPEDEF_(0x80280052L)






// TPM 1.2: The consistency check on DAA_issuerSettings has failed.

TPM_E_DAA_ISSUER_SETTINGS        _HRESULT_TYPEDEF_(0x80280053L)






// TPM 1.2: The consistency check on DAA_tpmSpecific has failed.

TPM_E_DAA_TPM_SETTINGS           _HRESULT_TYPEDEF_(0x80280054L)






// TPM 1.2: The atomic process indicated by the submitted DAA command is not the expected process.

TPM_E_DAA_STAGE                  _HRESULT_TYPEDEF_(0x80280055L)






// TPM 1.2: The issuer's validity check has detected an inconsistency.

TPM_E_DAA_ISSUER_VALIDITY        _HRESULT_TYPEDEF_(0x80280056L)






// TPM 1.2: The consistency check on w has failed.

TPM_E_DAA_WRONG_W                _HRESULT_TYPEDEF_(0x80280057L)






// TPM 1.2: The handle is incorrect.

TPM_E_BAD_HANDLE                 _HRESULT_TYPEDEF_(0x80280058L)






// TPM 1.2: Delegation is not correct.

TPM_E_BAD_DELEGATE               _HRESULT_TYPEDEF_(0x80280059L)






// TPM 1.2: The context blob is invalid.

TPM_E_BADCONTEXT                 _HRESULT_TYPEDEF_(0x8028005AL)






// TPM 1.2: Too many contexts held by the TPM.

TPM_E_TOOMANYCONTEXTS            _HRESULT_TYPEDEF_(0x8028005BL)






// TPM 1.2: Migration authority signature validation failure.

TPM_E_MA_TICKET_SIGNATURE        _HRESULT_TYPEDEF_(0x8028005CL)






// TPM 1.2: Migration destination not authenticated.

TPM_E_MA_DESTINATION             _HRESULT_TYPEDEF_(0x8028005DL)






// TPM 1.2: Migration source incorrect.

TPM_E_MA_SOURCE                  _HRESULT_TYPEDEF_(0x8028005EL)






// TPM 1.2: Incorrect migration authority.

TPM_E_MA_AUTHORITY               _HRESULT_TYPEDEF_(0x8028005FL)






// TPM 1.2: Attempt to revoke the EK and the EK is not revocable.

TPM_E_PERMANENTEK                _HRESULT_TYPEDEF_(0x80280061L)






// TPM 1.2: Bad signature of CMK ticket.

TPM_E_BAD_SIGNATURE              _HRESULT_TYPEDEF_(0x80280062L)






// TPM 1.2: There is no room in the context list for additional contexts.

TPM_E_NOCONTEXTSPACE             _HRESULT_TYPEDEF_(0x80280063L)






// TPM 2.0: Asymmetric algorithm not supported or not correct.

TPM_20_E_ASYMMETRIC              _HRESULT_TYPEDEF_(0x80280081L)






// TPM 2.0: Inconsistent attributes.

TPM_20_E_ATTRIBUTES              _HRESULT_TYPEDEF_(0x80280082L)






// TPM 2.0: Hash algorithm not supported or not appropriate.

TPM_20_E_HASH                    _HRESULT_TYPEDEF_(0x80280083L)






// TPM 2.0: Value is out of range or is not correct for the context.

TPM_20_E_VALUE                   _HRESULT_TYPEDEF_(0x80280084L)






// TPM 2.0: Hierarchy is not enabled or is not correct for the use.

TPM_20_E_HIERARCHY               _HRESULT_TYPEDEF_(0x80280085L)






// TPM 2.0: Key size is not supported.

TPM_20_E_KEY_SIZE                _HRESULT_TYPEDEF_(0x80280087L)






// TPM 2.0: Mask generation function not supported.

TPM_20_E_MGF                     _HRESULT_TYPEDEF_(0x80280088L)






// TPM 2.0: Mode of operation not supported.

TPM_20_E_MODE                    _HRESULT_TYPEDEF_(0x80280089L)






// TPM 2.0: The type of the value is not appropriate for the use.

TPM_20_E_TYPE                    _HRESULT_TYPEDEF_(0x8028008AL)






// TPM 2.0: The Handle is not correct for the use.

TPM_20_E_HANDLE                  _HRESULT_TYPEDEF_(0x8028008BL)






// TPM 2.0: Unsupported key derivation function or function not appropriate for use.

TPM_20_E_KDF                     _HRESULT_TYPEDEF_(0x8028008CL)






// TPM 2.0: Value was out of allowed range.

TPM_20_E_RANGE                   _HRESULT_TYPEDEF_(0x8028008DL)






// TPM 2.0: The authorization HMAC check failed and DA counter incremented.

TPM_20_E_AUTH_FAIL               _HRESULT_TYPEDEF_(0x8028008EL)






// TPM 2.0: Invalid nonce size.

TPM_20_E_NONCE                   _HRESULT_TYPEDEF_(0x8028008FL)






// TPM 2.0: Authorization requires assertion of PP.

TPM_20_E_PP                      _HRESULT_TYPEDEF_(0x80280090L)






// TPM 2.0: Unsupported or incompatible scheme.

TPM_20_E_SCHEME                  _HRESULT_TYPEDEF_(0x80280092L)






// TPM 2.0: Structure is wrong size.

TPM_20_E_SIZE                    _HRESULT_TYPEDEF_(0x80280095L)






// TPM 2.0: Unsupported symmetric algorithm or key size, or not appropriate for instance.

TPM_20_E_SYMMETRIC               _HRESULT_TYPEDEF_(0x80280096L)






// TPM 2.0: Incorrect structure tag.

TPM_20_E_TAG                     _HRESULT_TYPEDEF_(0x80280097L)






// TPM 2.0: Union selector is incorrect.

TPM_20_E_SELECTOR                _HRESULT_TYPEDEF_(0x80280098L)






// TPM 2.0: The TPM was unable to unmarshal a value because there were not enough octets in the input buffer.

TPM_20_E_INSUFFICIENT            _HRESULT_TYPEDEF_(0x8028009AL)






// TPM 2.0: The signature is not valid.

TPM_20_E_SIGNATURE               _HRESULT_TYPEDEF_(0x8028009BL)






// TPM 2.0: Key fields are not compatible with the selected use.

TPM_20_E_KEY                     _HRESULT_TYPEDEF_(0x8028009CL)






// TPM 2.0: A policy check failed.

TPM_20_E_POLICY_FAIL             _HRESULT_TYPEDEF_(0x8028009DL)






// TPM 2.0: Integrity check failed.

TPM_20_E_INTEGRITY               _HRESULT_TYPEDEF_(0x8028009FL)






// TPM 2.0: Invalid ticket.

TPM_20_E_TICKET                  _HRESULT_TYPEDEF_(0x802800A0L)






// TPM 2.0: Reserved bits not set to zero as required.

TPM_20_E_RESERVED_BITS           _HRESULT_TYPEDEF_(0x802800A1L)






// TPM 2.0: Authorization failure without DA implications.

TPM_20_E_BAD_AUTH                _HRESULT_TYPEDEF_(0x802800A2L)






// TPM 2.0: The policy has expired.

TPM_20_E_EXPIRED                 _HRESULT_TYPEDEF_(0x802800A3L)






// TPM 2.0: The command code in the policy is not the command code of the command or the command code in a policy command references a command that is not implemented.

TPM_20_E_POLICY_CC               _HRESULT_TYPEDEF_(0x802800A4L)






// TPM 2.0: Public and sensitive portions of an object are not cryptographically bound.

TPM_20_E_BINDING                 _HRESULT_TYPEDEF_(0x802800A5L)






// TPM 2.0: Curve not supported.

TPM_20_E_CURVE                   _HRESULT_TYPEDEF_(0x802800A6L)






// TPM 2.0: Point is not on the required curve.

TPM_20_E_ECC_POINT               _HRESULT_TYPEDEF_(0x802800A7L)






// TPM 2.0: TPM not initialized.

TPM_20_E_INITIALIZE              _HRESULT_TYPEDEF_(0x80280100L)






// TPM 2.0: Commands not being accepted because of a TPM failure.

TPM_20_E_FAILURE                 _HRESULT_TYPEDEF_(0x80280101L)






// TPM 2.0: Improper use of a sequence handle.

TPM_20_E_SEQUENCE                _HRESULT_TYPEDEF_(0x80280103L)






// TPM 2.0: TPM_RC_PRIVATE error.

TPM_20_E_PRIVATE                 _HRESULT_TYPEDEF_(0x8028010BL)






// TPM 2.0: TPM_RC_HMAC.

TPM_20_E_HMAC                    _HRESULT_TYPEDEF_(0x80280119L)






// TPM 2.0: TPM_RC_DISABLED.

TPM_20_E_DISABLED                _HRESULT_TYPEDEF_(0x80280120L)






// TPM 2.0: Command failed because audit sequence required exclusivity.

TPM_20_E_EXCLUSIVE               _HRESULT_TYPEDEF_(0x80280121L)






// TPM 2.0: Unsupported ECC curve.

TPM_20_E_ECC_CURVE               _HRESULT_TYPEDEF_(0x80280123L)






// TPM 2.0: Authorization handle is not correct for command.

TPM_20_E_AUTH_TYPE               _HRESULT_TYPEDEF_(0x80280124L)






// TPM 2.0: Command requires an authorization session for handle and is not present.

TPM_20_E_AUTH_MISSING            _HRESULT_TYPEDEF_(0x80280125L)






// TPM 2.0: Policy failure in Math Operation or an invalid authPolicy value.

TPM_20_E_POLICY                  _HRESULT_TYPEDEF_(0x80280126L)






// TPM 2.0: PCR check fail.

TPM_20_E_PCR                     _HRESULT_TYPEDEF_(0x80280127L)






// TPM 2.0: PCR have changed since checked.

TPM_20_E_PCR_CHANGED             _HRESULT_TYPEDEF_(0x80280128L)






// TPM 2.0: The TPM is not in the right mode for upgrade.

TPM_20_E_UPGRADE                 _HRESULT_TYPEDEF_(0x8028012DL)






// TPM 2.0: Context ID counter is at maximum.

TPM_20_E_TOO_MANY_CONTEXTS       _HRESULT_TYPEDEF_(0x8028012EL)






// TPM 2.0: authValue or authPolicy is not available for selected entity.

TPM_20_E_AUTH_UNAVAILABLE        _HRESULT_TYPEDEF_(0x8028012FL)






// TPM 2.0: A _TPM_Init and Startup(CLEAR) is required before the TPM can resume operation.

TPM_20_E_REBOOT                  _HRESULT_TYPEDEF_(0x80280130L)






// TPM 2.0: The protection algorithms (hash and symmetric) are not reasonably balanced. The digest size of the hash must be larger than the key size of the symmetric algorithm.

TPM_20_E_UNBALANCED              _HRESULT_TYPEDEF_(0x80280131L)






// TPM 2.0: The TPM command's commandSize value is inconsistent with contents of the command buffer; either the size is not the same as the bytes loaded by the hardware interface layer or the value is not large enough to hold a command header.

TPM_20_E_COMMAND_SIZE            _HRESULT_TYPEDEF_(0x80280142L)






// TPM 2.0: Command code not supported.

TPM_20_E_COMMAND_CODE            _HRESULT_TYPEDEF_(0x80280143L)






// TPM 2.0: The value of authorizationSize is out of range or the number of octets in the authorization Area is greater than required.

TPM_20_E_AUTHSIZE                _HRESULT_TYPEDEF_(0x80280144L)






// TPM 2.0: Use of an authorization session with a context command or another command that cannot have an authorization session.

TPM_20_E_AUTH_CONTEXT            _HRESULT_TYPEDEF_(0x80280145L)






// TPM 2.0: NV offset+size is out of range.

TPM_20_E_NV_RANGE                _HRESULT_TYPEDEF_(0x80280146L)






// TPM 2.0: Requested allocation size is larger than allowed.

TPM_20_E_NV_SIZE                 _HRESULT_TYPEDEF_(0x80280147L)






// TPM 2.0: NV access locked.

TPM_20_E_NV_LOCKED               _HRESULT_TYPEDEF_(0x80280148L)






// TPM 2.0: NV access authorization fails in command actions

TPM_20_E_NV_AUTHORIZATION        _HRESULT_TYPEDEF_(0x80280149L)






// TPM 2.0: An NV index is used before being initialized or the state saved by TPM2_Shutdown(STATE) could not be restored.

TPM_20_E_NV_UNINITIALIZED        _HRESULT_TYPEDEF_(0x8028014AL)






// TPM 2.0: Insufficient space for NV allocation.

TPM_20_E_NV_SPACE                _HRESULT_TYPEDEF_(0x8028014BL)






// TPM 2.0: NV index or persistent object already defined.

TPM_20_E_NV_DEFINED              _HRESULT_TYPEDEF_(0x8028014CL)






// TPM 2.0: Context in TPM2_ContextLoad() is not valid.

TPM_20_E_BAD_CONTEXT             _HRESULT_TYPEDEF_(0x80280150L)






// TPM 2.0: chHash value already set or not correct for use.

TPM_20_E_CPHASH                  _HRESULT_TYPEDEF_(0x80280151L)






// TPM 2.0: Handle for parent is not a valid parent.

TPM_20_E_PARENT                  _HRESULT_TYPEDEF_(0x80280152L)






// TPM 2.0: Some function needs testing.

TPM_20_E_NEEDS_TEST              _HRESULT_TYPEDEF_(0x80280153L)






// TPM 2.0: returned when an internal function cannot process a request due to an unspecified problem. This code is usually related to invalid parameters that are not properly filtered by the input unmarshaling code.

TPM_20_E_NO_RESULT               _HRESULT_TYPEDEF_(0x80280154L)






// TPM 2.0: The sensitive area did not unmarshal correctly after decryption - this code is used in lieu of the other unmarshaling errors so that an attacker cannot determine where the unmarshaling error occurred.

TPM_20_E_SENSITIVE               _HRESULT_TYPEDEF_(0x80280155L)


// TPM vendor specific hardware errors {0x0400..0x04ff}






// The command was blocked.

TPM_E_COMMAND_BLOCKED            _HRESULT_TYPEDEF_(0x80280400L)






// The specified handle was not found.

TPM_E_INVALID_HANDLE             _HRESULT_TYPEDEF_(0x80280401L)






// The TPM returned a duplicate handle and the command needs to be resubmitted.

TPM_E_DUPLICATE_VHANDLE          _HRESULT_TYPEDEF_(0x80280402L)






// The command within the transport was blocked.

TPM_E_EMBEDDED_COMMAND_BLOCKED   _HRESULT_TYPEDEF_(0x80280403L)






// The command within the transport is not supported.

TPM_E_EMBEDDED_COMMAND_UNSUPPORTED _HRESULT_TYPEDEF_(0x80280404L)


// TPM non-fatal hardware errors {0x0800..0x08ff}






// The TPM is too busy to respond to the command immediately, but the command could be resubmitted at a later time.

TPM_E_RETRY                      _HRESULT_TYPEDEF_(0x80280800L)






// SelfTestFull has not been run.

TPM_E_NEEDS_SELFTEST             _HRESULT_TYPEDEF_(0x80280801L)






// The TPM is currently executing a full selftest.

TPM_E_DOING_SELFTEST             _HRESULT_TYPEDEF_(0x80280802L)






// The TPM is defending against dictionary attacks and is in a time-out period.

TPM_E_DEFEND_LOCK_RUNNING        _HRESULT_TYPEDEF_(0x80280803L)






// TPM 2.0: Gap for context ID is too large.

TPM_20_E_CONTEXT_GAP             _HRESULT_TYPEDEF_(0x80280901L)






// TPM 2.0: Out of memory for object contexts.

TPM_20_E_OBJECT_MEMORY           _HRESULT_TYPEDEF_(0x80280902L)






// TPM 2.0: Out of memory for session contexts.

TPM_20_E_SESSION_MEMORY          _HRESULT_TYPEDEF_(0x80280903L)






// TPM 2.0: Out of shared object/session memory or need space for internal operations.

TPM_20_E_MEMORY                  _HRESULT_TYPEDEF_(0x80280904L)






// TPM 2.0: Out of session handles - a session must be flushed before a nes session may be created.

TPM_20_E_SESSION_HANDLES         _HRESULT_TYPEDEF_(0x80280905L)






// TPM 2.0: Out of object handles - the handle space for objects is depleted and a reboot is required.

TPM_20_E_OBJECT_HANDLES          _HRESULT_TYPEDEF_(0x80280906L)






// TPM 2.0: Bad locality.

TPM_20_E_LOCALITY                _HRESULT_TYPEDEF_(0x80280907L)






// TPM 2.0: The TPM has suspended operation on the command; forward progress was made and the command may be retried.

TPM_20_E_YIELDED                 _HRESULT_TYPEDEF_(0x80280908L)






// TPM 2.0: The command was canceled.

TPM_20_E_CANCELED                _HRESULT_TYPEDEF_(0x80280909L)






// TPM 2.0: TPM is performing self-tests.

TPM_20_E_TESTING                 _HRESULT_TYPEDEF_(0x8028090AL)






// TPM 2.0: The TPM is rate-limiting accesses to prevent wearout of NV

TPM_20_E_NV_RATE                 _HRESULT_TYPEDEF_(0x80280920L)






// TPM 2.0: Authorization for objects subject to DA protection are not allowed at this time because the TPM is in DA lockout mode.

TPM_20_E_LOCKOUT                 _HRESULT_TYPEDEF_(0x80280921L)






// TPM 2.0: The TPM was not able to start the command.

TPM_20_E_RETRY                   _HRESULT_TYPEDEF_(0x80280922L)






// TPM 2.0: the command may require writing of NV and NV is not current accessible.

TPM_20_E_NV_UNAVAILABLE          _HRESULT_TYPEDEF_(0x80280923L)


// TPM Base Services error codes {0x4000..0x40ff}






// An internal error has occurred within the Trusted Platform Module support program.

TBS_E_INTERNAL_ERROR             _HRESULT_TYPEDEF_(0x80284001L)






// One or more input parameters is bad.

TBS_E_BAD_PARAMETER              _HRESULT_TYPEDEF_(0x80284002L)






// A specified output pointer is bad.

TBS_E_INVALID_OUTPUT_POINTER     _HRESULT_TYPEDEF_(0x80284003L)






// The specified context handle does not refer to a valid context.

TBS_E_INVALID_CONTEXT            _HRESULT_TYPEDEF_(0x80284004L)






// A specified output buffer is too small.

TBS_E_INSUFFICIENT_BUFFER        _HRESULT_TYPEDEF_(0x80284005L)






// An error occurred while communicating with the TPM.

TBS_E_IOERROR                    _HRESULT_TYPEDEF_(0x80284006L)






// One or more context parameters is invalid.

TBS_E_INVALID_CONTEXT_PARAM      _HRESULT_TYPEDEF_(0x80284007L)






// The TBS service is not running and could not be started.

TBS_E_SERVICE_NOT_RUNNING        _HRESULT_TYPEDEF_(0x80284008L)






// A new context could not be created because there are too many open contexts.

TBS_E_TOO_MANY_TBS_CONTEXTS      _HRESULT_TYPEDEF_(0x80284009L)






// A new virtual resource could not be created because there are too many open virtual resources.

TBS_E_TOO_MANY_RESOURCES         _HRESULT_TYPEDEF_(0x8028400AL)






// The TBS service has been started but is not yet running.

TBS_E_SERVICE_START_PENDING      _HRESULT_TYPEDEF_(0x8028400BL)






// The physical presence interface is not supported.

TBS_E_PPI_NOT_SUPPORTED          _HRESULT_TYPEDEF_(0x8028400CL)






// The command was canceled.

TBS_E_COMMAND_CANCELED           _HRESULT_TYPEDEF_(0x8028400DL)






// The input or output buffer is too large.

TBS_E_BUFFER_TOO_LARGE           _HRESULT_TYPEDEF_(0x8028400EL)






// A compatible Trusted Platform Module (TPM) Security Device cannot be found on this computer.

TBS_E_TPM_NOT_FOUND              _HRESULT_TYPEDEF_(0x8028400FL)






// The TBS service has been disabled.

TBS_E_SERVICE_DISABLED           _HRESULT_TYPEDEF_(0x80284010L)






// No TCG event log is available.

TBS_E_NO_EVENT_LOG               _HRESULT_TYPEDEF_(0x80284011L)






// The caller does not have the appropriate rights to perform the requested operation.

TBS_E_ACCESS_DENIED              _HRESULT_TYPEDEF_(0x80284012L)






// The TPM provisioning action is not allowed by the specified flags.  For provisioning to be successful, one of several actions may be required.  The TPM management console (tpm.msc) action to make the TPM Ready may help.  For further information, see the documentation for the Win32_Tpm WMI method 'Provision'.  (The actions that may be required include importing the TPM Owner Authorization value into the system, calling the Win32_Tpm WMI method for provisioning the TPM and specifying TRUE for either 'ForceClear_Allowed' or 'PhysicalPresencePrompts_Allowed' (as indicated by the value returned in the Additional Information), or enabling the TPM in the system BIOS.)

TBS_E_PROVISIONING_NOT_ALLOWED   _HRESULT_TYPEDEF_(0x80284013L)






// The Physical Presence Interface of this firmware does not support the requested method.

TBS_E_PPI_FUNCTION_UNSUPPORTED   _HRESULT_TYPEDEF_(0x80284014L)






// The requested TPM OwnerAuth value was not found.

TBS_E_OWNERAUTH_NOT_FOUND        _HRESULT_TYPEDEF_(0x80284015L)






// The TPM provisioning did not complete.  For more information on completing the provisioning, call the Win32_Tpm WMI method for provisioning the TPM ('Provision') and check the returned Information.

TBS_E_PROVISIONING_INCOMPLETE    _HRESULT_TYPEDEF_(0x80284016L)


// TPM API error codes {0x0100..0x01ff}






// The command buffer is not in the correct state.

TPMAPI_E_INVALID_STATE           _HRESULT_TYPEDEF_(0x80290100L)






// The command buffer does not contain enough data to satisfy the request.

TPMAPI_E_NOT_ENOUGH_DATA         _HRESULT_TYPEDEF_(0x80290101L)






// The command buffer cannot contain any more data.

TPMAPI_E_TOO_MUCH_DATA           _HRESULT_TYPEDEF_(0x80290102L)






// One or more output parameters was NULL or invalid.

TPMAPI_E_INVALID_OUTPUT_POINTER  _HRESULT_TYPEDEF_(0x80290103L)






// One or more input parameters is invalid.

TPMAPI_E_INVALID_PARAMETER       _HRESULT_TYPEDEF_(0x80290104L)






// Not enough memory was available to satisfy the request.

TPMAPI_E_OUT_OF_MEMORY           _HRESULT_TYPEDEF_(0x80290105L)






// The specified buffer was too small.

TPMAPI_E_BUFFER_TOO_SMALL        _HRESULT_TYPEDEF_(0x80290106L)






// An internal error was detected.

TPMAPI_E_INTERNAL_ERROR          _HRESULT_TYPEDEF_(0x80290107L)






// The caller does not have the appropriate rights to perform the requested operation.

TPMAPI_E_ACCESS_DENIED           _HRESULT_TYPEDEF_(0x80290108L)






// The specified authorization information was invalid.

TPMAPI_E_AUTHORIZATION_FAILED    _HRESULT_TYPEDEF_(0x80290109L)






// The specified context handle was not valid.

TPMAPI_E_INVALID_CONTEXT_HANDLE  _HRESULT_TYPEDEF_(0x8029010AL)






// An error occurred while communicating with the TBS.

TPMAPI_E_TBS_COMMUNICATION_ERROR _HRESULT_TYPEDEF_(0x8029010BL)






// The TPM returned an unexpected result.

TPMAPI_E_TPM_COMMAND_ERROR       _HRESULT_TYPEDEF_(0x8029010CL)






// The message was too large for the encoding scheme.

TPMAPI_E_MESSAGE_TOO_LARGE       _HRESULT_TYPEDEF_(0x8029010DL)






// The encoding in the blob was not recognized.

TPMAPI_E_INVALID_ENCODING        _HRESULT_TYPEDEF_(0x8029010EL)






// The key size is not valid.

TPMAPI_E_INVALID_KEY_SIZE        _HRESULT_TYPEDEF_(0x8029010FL)






// The encryption operation failed.

TPMAPI_E_ENCRYPTION_FAILED       _HRESULT_TYPEDEF_(0x80290110L)






// The key parameters structure was not valid

TPMAPI_E_INVALID_KEY_PARAMS      _HRESULT_TYPEDEF_(0x80290111L)






// The requested supplied data does not appear to be a valid migration authorization blob.

TPMAPI_E_INVALID_MIGRATION_AUTHORIZATION_BLOB _HRESULT_TYPEDEF_(0x80290112L)






// The specified PCR index was invalid

TPMAPI_E_INVALID_PCR_INDEX       _HRESULT_TYPEDEF_(0x80290113L)






// The data given does not appear to be a valid delegate blob.

TPMAPI_E_INVALID_DELEGATE_BLOB   _HRESULT_TYPEDEF_(0x80290114L)






// One or more of the specified context parameters was not valid.

TPMAPI_E_INVALID_CONTEXT_PARAMS  _HRESULT_TYPEDEF_(0x80290115L)






// The data given does not appear to be a valid key blob

TPMAPI_E_INVALID_KEY_BLOB        _HRESULT_TYPEDEF_(0x80290116L)






// The specified PCR data was invalid.

TPMAPI_E_INVALID_PCR_DATA        _HRESULT_TYPEDEF_(0x80290117L)






// The format of the owner auth data was invalid.

TPMAPI_E_INVALID_OWNER_AUTH      _HRESULT_TYPEDEF_(0x80290118L)






// The random number generated did not pass FIPS RNG check.

TPMAPI_E_FIPS_RNG_CHECK_FAILED   _HRESULT_TYPEDEF_(0x80290119L)






// The TCG Event Log does not contain any data.

TPMAPI_E_EMPTY_TCG_LOG           _HRESULT_TYPEDEF_(0x8029011AL)






// An entry in the TCG Event Log was invalid.

TPMAPI_E_INVALID_TCG_LOG_ENTRY   _HRESULT_TYPEDEF_(0x8029011BL)






// A TCG Separator was not found.

TPMAPI_E_TCG_SEPARATOR_ABSENT    _HRESULT_TYPEDEF_(0x8029011CL)






// A digest value in a TCG Log entry did not match hashed data.

TPMAPI_E_TCG_INVALID_DIGEST_ENTRY _HRESULT_TYPEDEF_(0x8029011DL)






// The requested operation was blocked by current TPM policy. Please contact your system administrator for assistance.

TPMAPI_E_POLICY_DENIES_OPERATION _HRESULT_TYPEDEF_(0x8029011EL)






// The Windows TPM NV Bits index is not defined.

TPMAPI_E_NV_BITS_NOT_DEFINED     _HRESULT_TYPEDEF_(0x8029011FL)






// The Windows TPM NV Bits index is not ready for use.

TPMAPI_E_NV_BITS_NOT_READY       _HRESULT_TYPEDEF_(0x80290120L)






// The TPM key that was used to seal the data is no longer available.

TPMAPI_E_SEALING_KEY_NOT_AVAILABLE _HRESULT_TYPEDEF_(0x80290121L)






// An authorization chain could not be found that authorizes the PolicyAuthorize unseal.

TPMAPI_E_NO_AUTHORIZATION_CHAIN_FOUND _HRESULT_TYPEDEF_(0x80290122L)






// The SVN counter to which the authorization was bound is not available.

TPMAPI_E_SVN_COUNTER_NOT_AVAILABLE _HRESULT_TYPEDEF_(0x80290123L)






// The TPM Storage hierarchy (Owner) auth value is required to be NULL for this operation.

TPMAPI_E_OWNER_AUTH_NOT_NULL     _HRESULT_TYPEDEF_(0x80290124L)






// The TPM Endorsement hierarchy auth value is required to be NULL for this operation.

TPMAPI_E_ENDORSEMENT_AUTH_NOT_NULL _HRESULT_TYPEDEF_(0x80290125L)






// The authorization to perform this operation has been revoked.

TPMAPI_E_AUTHORIZATION_REVOKED   _HRESULT_TYPEDEF_(0x80290126L)






// The authorization public key is malformed.

TPMAPI_E_MALFORMED_AUTHORIZATION_KEY _HRESULT_TYPEDEF_(0x80290127L)






// The authorization public key is not supported.

TPMAPI_E_AUTHORIZING_KEY_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80290128L)






// The authorization signature is invalid.

TPMAPI_E_INVALID_AUTHORIZATION_SIGNATURE _HRESULT_TYPEDEF_(0x80290129L)






// The authorization policy is malformed.

TPMAPI_E_MALFORMED_AUTHORIZATION_POLICY _HRESULT_TYPEDEF_(0x8029012AL)






// The authorization data is malformed.

TPMAPI_E_MALFORMED_AUTHORIZATION_OTHER _HRESULT_TYPEDEF_(0x8029012BL)






// The key used to unseal this data has changed since sealing the data. This may be the result of a TPM clear.

TPMAPI_E_SEALING_KEY_CHANGED     _HRESULT_TYPEDEF_(0x8029012CL)


// TBS implementation error codes {0x0200..0x02ff}






// The specified buffer was too small.

TBSIMP_E_BUFFER_TOO_SMALL        _HRESULT_TYPEDEF_(0x80290200L)






// The context could not be cleaned up.

TBSIMP_E_CLEANUP_FAILED          _HRESULT_TYPEDEF_(0x80290201L)






// The specified context handle is invalid.

TBSIMP_E_INVALID_CONTEXT_HANDLE  _HRESULT_TYPEDEF_(0x80290202L)






// An invalid context parameter was specified.

TBSIMP_E_INVALID_CONTEXT_PARAM   _HRESULT_TYPEDEF_(0x80290203L)






// An error occurred while communicating with the TPM

TBSIMP_E_TPM_ERROR               _HRESULT_TYPEDEF_(0x80290204L)






// No entry with the specified key was found.

TBSIMP_E_HASH_BAD_KEY            _HRESULT_TYPEDEF_(0x80290205L)






// The specified virtual handle matches a virtual handle already in use.

TBSIMP_E_DUPLICATE_VHANDLE       _HRESULT_TYPEDEF_(0x80290206L)






// The pointer to the returned handle location was NULL or invalid

TBSIMP_E_INVALID_OUTPUT_POINTER  _HRESULT_TYPEDEF_(0x80290207L)






// One or more parameters is invalid

TBSIMP_E_INVALID_PARAMETER       _HRESULT_TYPEDEF_(0x80290208L)






// The RPC subsystem could not be initialized.

TBSIMP_E_RPC_INIT_FAILED         _HRESULT_TYPEDEF_(0x80290209L)






// The TBS scheduler is not running.

TBSIMP_E_SCHEDULER_NOT_RUNNING   _HRESULT_TYPEDEF_(0x8029020AL)






// The command was canceled.

TBSIMP_E_COMMAND_CANCELED        _HRESULT_TYPEDEF_(0x8029020BL)






// There was not enough memory to fulfill the request

TBSIMP_E_OUT_OF_MEMORY           _HRESULT_TYPEDEF_(0x8029020CL)






// The specified list is empty, or the iteration has reached the end of the list.

TBSIMP_E_LIST_NO_MORE_ITEMS      _HRESULT_TYPEDEF_(0x8029020DL)






// The specified item was not found in the list.

TBSIMP_E_LIST_NOT_FOUND          _HRESULT_TYPEDEF_(0x8029020EL)






// The TPM does not have enough space to load the requested resource.

TBSIMP_E_NOT_ENOUGH_SPACE        _HRESULT_TYPEDEF_(0x8029020FL)






// There are too many TPM contexts in use.

TBSIMP_E_NOT_ENOUGH_TPM_CONTEXTS _HRESULT_TYPEDEF_(0x80290210L)






// The TPM command failed.

TBSIMP_E_COMMAND_FAILED          _HRESULT_TYPEDEF_(0x80290211L)






// The TBS does not recognize the specified ordinal.

TBSIMP_E_UNKNOWN_ORDINAL         _HRESULT_TYPEDEF_(0x80290212L)






// The requested resource is no longer available.

TBSIMP_E_RESOURCE_EXPIRED        _HRESULT_TYPEDEF_(0x80290213L)






// The resource type did not match.

TBSIMP_E_INVALID_RESOURCE        _HRESULT_TYPEDEF_(0x80290214L)






// No resources can be unloaded.

TBSIMP_E_NOTHING_TO_UNLOAD       _HRESULT_TYPEDEF_(0x80290215L)






// No new entries can be added to the hash table.

TBSIMP_E_HASH_TABLE_FULL         _HRESULT_TYPEDEF_(0x80290216L)






// A new TBS context could not be created because there are too many open contexts.

TBSIMP_E_TOO_MANY_TBS_CONTEXTS   _HRESULT_TYPEDEF_(0x80290217L)






// A new virtual resource could not be created because there are too many open virtual resources.

TBSIMP_E_TOO_MANY_RESOURCES      _HRESULT_TYPEDEF_(0x80290218L)






// The physical presence interface is not supported.

TBSIMP_E_PPI_NOT_SUPPORTED       _HRESULT_TYPEDEF_(0x80290219L)






// TBS is not compatible with the version of TPM found on the system.

TBSIMP_E_TPM_INCOMPATIBLE        _HRESULT_TYPEDEF_(0x8029021AL)






// No TCG event log is available.

TBSIMP_E_NO_EVENT_LOG            _HRESULT_TYPEDEF_(0x8029021BL)


// TPM Physical Presence implementation error codes {0x0300..0x03ff}






// A general error was detected when attempting to acquire the BIOS's response to a Physical Presence command.

TPM_E_PPI_ACPI_FAILURE           _HRESULT_TYPEDEF_(0x80290300L)






// The user failed to confirm the TPM operation request.

TPM_E_PPI_USER_ABORT             _HRESULT_TYPEDEF_(0x80290301L)






// The BIOS failure prevented the successful execution of the requested TPM operation (e.g. invalid TPM operation request, BIOS communication error with the TPM).

TPM_E_PPI_BIOS_FAILURE           _HRESULT_TYPEDEF_(0x80290302L)






// The BIOS does not support the physical presence interface.

TPM_E_PPI_NOT_SUPPORTED          _HRESULT_TYPEDEF_(0x80290303L)






// The Physical Presence command was blocked by current BIOS settings. The system owner may be able to reconfigure the BIOS settings to allow the command.

TPM_E_PPI_BLOCKED_IN_BIOS        _HRESULT_TYPEDEF_(0x80290304L)


// Platform Crypto Provider (PCPTPM12.dll and future platform crypto providers)  error codes {0x0400..0x04ff}






// This is an error mask to convert Platform Crypto Provider errors to win errors.

TPM_E_PCP_ERROR_MASK             _HRESULT_TYPEDEF_(0x80290400L)






// The Platform Crypto Device is currently not ready. It needs to be fully provisioned to be operational.

TPM_E_PCP_DEVICE_NOT_READY       _HRESULT_TYPEDEF_(0x80290401L)






// The handle provided to the Platform Crypto Provider is invalid.

TPM_E_PCP_INVALID_HANDLE         _HRESULT_TYPEDEF_(0x80290402L)






// A parameter provided to the Platform Crypto Provider is invalid.

TPM_E_PCP_INVALID_PARAMETER      _HRESULT_TYPEDEF_(0x80290403L)






// A provided flag to the Platform Crypto Provider is not supported.

TPM_E_PCP_FLAG_NOT_SUPPORTED     _HRESULT_TYPEDEF_(0x80290404L)






// The requested operation is not supported by this Platform Crypto Provider.

TPM_E_PCP_NOT_SUPPORTED          _HRESULT_TYPEDEF_(0x80290405L)






// The buffer is too small to contain all data. No information has been written to the buffer.

TPM_E_PCP_BUFFER_TOO_SMALL       _HRESULT_TYPEDEF_(0x80290406L)






// An unexpected internal error has occurred in the Platform Crypto Provider.

TPM_E_PCP_INTERNAL_ERROR         _HRESULT_TYPEDEF_(0x80290407L)






// The authorization to use a provider object has failed.

TPM_E_PCP_AUTHENTICATION_FAILED  _HRESULT_TYPEDEF_(0x80290408L)






// The Platform Crypto Device has ignored the authorization for the provider object, to mitigate against a dictionary attack.

TPM_E_PCP_AUTHENTICATION_IGNORED _HRESULT_TYPEDEF_(0x80290409L)






// The referenced policy was not found.

TPM_E_PCP_POLICY_NOT_FOUND       _HRESULT_TYPEDEF_(0x8029040AL)






// The referenced profile was not found.

TPM_E_PCP_PROFILE_NOT_FOUND      _HRESULT_TYPEDEF_(0x8029040BL)






// The validation was not succesful.

TPM_E_PCP_VALIDATION_FAILED      _HRESULT_TYPEDEF_(0x8029040CL)






// An attempt was made to import or load a key under an incorrect storage parent.

TPM_E_PCP_WRONG_PARENT           _HRESULT_TYPEDEF_(0x8029040EL)






// The TPM key is not loaded.

TPM_E_KEY_NOT_LOADED             _HRESULT_TYPEDEF_(0x8029040FL)






// The TPM key certification has not been generated.

TPM_E_NO_KEY_CERTIFICATION       _HRESULT_TYPEDEF_(0x80290410L)






// The TPM key is not yet finalized.

TPM_E_KEY_NOT_FINALIZED          _HRESULT_TYPEDEF_(0x80290411L)






// The TPM attestation challenge is not set.

TPM_E_ATTESTATION_CHALLENGE_NOT_SET _HRESULT_TYPEDEF_(0x80290412L)






// The TPM PCR info is not available.

TPM_E_NOT_PCR_BOUND              _HRESULT_TYPEDEF_(0x80290413L)






// The TPM key is already finalized.

TPM_E_KEY_ALREADY_FINALIZED      _HRESULT_TYPEDEF_(0x80290414L)






// The TPM key usage policy is not supported.

TPM_E_KEY_USAGE_POLICY_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80290415L)






// The TPM key usage policy is invalid.

TPM_E_KEY_USAGE_POLICY_INVALID   _HRESULT_TYPEDEF_(0x80290416L)






// There was a problem with the software key being imported into the TPM.

TPM_E_SOFT_KEY_ERROR             _HRESULT_TYPEDEF_(0x80290417L)






// The TPM key is not authenticated.

TPM_E_KEY_NOT_AUTHENTICATED      _HRESULT_TYPEDEF_(0x80290418L)






// The TPM key is not an AIK.

TPM_E_PCP_KEY_NOT_AIK            _HRESULT_TYPEDEF_(0x80290419L)






// The TPM key is not a signing key.

TPM_E_KEY_NOT_SIGNING_KEY        _HRESULT_TYPEDEF_(0x8029041AL)






// The TPM is locked out.

TPM_E_LOCKED_OUT                 _HRESULT_TYPEDEF_(0x8029041BL)






// The claim type requested is not supported.

TPM_E_CLAIM_TYPE_NOT_SUPPORTED   _HRESULT_TYPEDEF_(0x8029041CL)






// TPM version is not supported.

TPM_E_VERSION_NOT_SUPPORTED      _HRESULT_TYPEDEF_(0x8029041DL)






// The buffer lengths do not match.

TPM_E_BUFFER_LENGTH_MISMATCH     _HRESULT_TYPEDEF_(0x8029041EL)






// The RSA key creation is blocked on this TPM due to known security vulnerabilities.

TPM_E_PCP_IFX_RSA_KEY_CREATION_BLOCKED _HRESULT_TYPEDEF_(0x8029041FL)






// A ticket required to use a key was not provided.

TPM_E_PCP_TICKET_MISSING         _HRESULT_TYPEDEF_(0x80290420L)






// This key has a raw policy so the KSP can't authenticate against it.

TPM_E_PCP_RAW_POLICY_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80290421L)






// The TPM key's handle was unexpectedly invalidated due to a hardware or firmware issue.

TPM_E_PCP_KEY_HANDLE_INVALIDATED _HRESULT_TYPEDEF_(0x80290422L)






// The requested salt size for signing with RSAPSS does not match what the TPM uses.

TPM_E_PCP_UNSUPPORTED_PSS_SALT   _HRESULT_TYPEDEF_(0x40290423L)


// Misc error codes in TPM code {0x0500..0x05ff}






// TPM related network operations are blocked as Zero Exhaust mode is enabled on client.

TPM_E_ZERO_EXHAUST_ENABLED       _HRESULT_TYPEDEF_(0x80290500L)


// If the application is designed to use TCG defined TPM return codes
// then undefine the Windows defined codes for the same symbols. The application
// declares usage of TCG return codes by defining WIN_OMIT_TSS_TPM_RETURN_CODES
// before including windows.h

#ifdef WIN_OMIT_TSS_TPM_RETURN_CODES
#undef TPM_E_AREA_LOCKED
#undef TPM_E_AUDITFAILURE
#undef TPM_E_AUDITFAIL_SUCCESSFUL
#undef TPM_E_AUDITFAIL_UNSUCCESSFUL
#undef TPM_E_AUTH2FAIL
#undef TPM_E_AUTHFAIL
#undef TPM_E_AUTH_CONFLICT
#undef TPM_E_BADCONTEXT
#undef TPM_E_BADINDEX
#undef TPM_E_BADTAG
#undef TPM_E_BAD_ATTRIBUTES
#undef TPM_E_BAD_COUNTER
#undef TPM_E_BAD_DATASIZE
#undef TPM_E_BAD_DELEGATE
#undef TPM_E_BAD_HANDLE
#undef TPM_E_BAD_KEY_PROPERTY
#undef TPM_E_BAD_LOCALITY
#undef TPM_E_BAD_MIGRATION
#undef TPM_E_BAD_MODE
#undef TPM_E_BAD_ORDINAL
#undef TPM_E_BAD_PARAMETER
#undef TPM_E_BAD_PARAM_SIZE
#undef TPM_E_BAD_PRESENCE
#undef TPM_E_BAD_SCHEME
#undef TPM_E_BAD_SIGNATURE
#undef TPM_E_BAD_TYPE
#undef TPM_E_BAD_VERSION
#undef TPM_E_CLEAR_DISABLED
#undef TPM_E_CONTEXT_GAP
#undef TPM_E_DAA_INPUT_DATA0
#undef TPM_E_DAA_INPUT_DATA1
#undef TPM_E_DAA_ISSUER_SETTINGS
#undef TPM_E_DAA_ISSUER_VALIDITY
#undef TPM_E_DAA_RESOURCES
#undef TPM_E_DAA_STAGE
#undef TPM_E_DAA_TPM_SETTINGS
#undef TPM_E_DAA_WRONG_W
#undef TPM_E_DEACTIVATED
#undef TPM_E_DECRYPT_ERROR
#undef TPM_E_DEFEND_LOCK_RUNNING
#undef TPM_E_DELEGATE_ADMIN
#undef TPM_E_DELEGATE_FAMILY
#undef TPM_E_DELEGATE_LOCK
#undef TPM_E_DISABLED
#undef TPM_E_DISABLED_CMD
#undef TPM_E_DOING_SELFTEST
#undef TPM_E_ENCRYPT_ERROR
#undef TPM_E_FAIL
#undef TPM_E_FAILEDSELFTEST
#undef TPM_E_FAMILYCOUNT
#undef TPM_E_INAPPROPRIATE_ENC
#undef TPM_E_INAPPROPRIATE_SIG
#undef TPM_E_INSTALL_DISABLED
#undef TPM_E_INVALID_AUTHHANDLE
#undef TPM_E_INVALID_FAMILY
#undef TPM_E_INVALID_KEYHANDLE
#undef TPM_E_INVALID_KEYUSAGE
#undef TPM_E_INVALID_PCR_INFO
#undef TPM_E_INVALID_POSTINIT
#undef TPM_E_INVALID_RESOURCE
#undef TPM_E_INVALID_STRUCTURE
#undef TPM_E_IOERROR
#undef TPM_E_KEYNOTFOUND
#undef TPM_E_KEY_NOTSUPPORTED
#undef TPM_E_KEY_OWNER_CONTROL
#undef TPM_E_MAXNVWRITES
#undef TPM_E_MA_AUTHORITY
#undef TPM_E_MA_DESTINATION
#undef TPM_E_MA_SOURCE
#undef TPM_E_MA_TICKET_SIGNATURE
#undef TPM_E_MIGRATEFAIL
#undef TPM_E_NEEDS_SELFTEST
#undef TPM_E_NOCONTEXTSPACE
#undef TPM_E_NOOPERATOR
#undef TPM_E_NOSPACE
#undef TPM_E_NOSRK
#undef TPM_E_NOTFIPS
#undef TPM_E_NOTLOCAL
#undef TPM_E_NOTRESETABLE
#undef TPM_E_NOTSEALED_BLOB
#undef TPM_E_NOT_FULLWRITE
#undef TPM_E_NO_ENDORSEMENT
#undef TPM_E_NO_NV_PERMISSION
#undef TPM_E_NO_WRAP_TRANSPORT
#undef TPM_E_OWNER_CONTROL
#undef TPM_E_OWNER_SET
#undef TPM_E_PERMANENTEK
#undef TPM_E_PER_NOWRITE
#undef TPM_E_READ_ONLY
#undef TPM_E_REQUIRES_SIGN
#undef TPM_E_RESOURCEMISSING
#undef TPM_E_RESOURCES
#undef TPM_E_RETRY
#undef TPM_E_SHA_ERROR
#undef TPM_E_SHA_THREAD
#undef TPM_E_SHORTRANDOM
#undef TPM_E_SIZE
#undef TPM_E_TOOMANYCONTEXTS
#undef TPM_E_TRANSPORT_NOTEXCLUSIVE
#undef TPM_E_WRITE_LOCKED
#undef TPM_E_WRONGPCRVAL
#undef TPM_E_WRONG_ENTITYTYPE
#undef TPM_SUCCESS
#endif

// =======================================================
// Facility Performance Logs & Alerts (PLA) Error Messages
// =======================================================






// Data Collector Set was not found.

PLA_E_DCS_NOT_FOUND              _HRESULT_TYPEDEF_(0x80300002L)






// The Data Collector Set or one of its dependencies is already in use.

PLA_E_DCS_IN_USE                 _HRESULT_TYPEDEF_(0x803000AAL)






// Unable to start Data Collector Set because there are too many folders.

PLA_E_TOO_MANY_FOLDERS           _HRESULT_TYPEDEF_(0x80300045L)






// Not enough free disk space to start Data Collector Set.

PLA_E_NO_MIN_DISK                _HRESULT_TYPEDEF_(0x80300070L)






// Data Collector Set already exists.

PLA_E_DCS_ALREADY_EXISTS         _HRESULT_TYPEDEF_(0x803000B7L)






// Property value will be ignored.

PLA_S_PROPERTY_IGNORED           _HRESULT_TYPEDEF_(0x00300100L)






// Property value conflict.

PLA_E_PROPERTY_CONFLICT          _HRESULT_TYPEDEF_(0x80300101L)






// The current configuration for this Data Collector Set requires that it contain exactly one Data Collector.

PLA_E_DCS_SINGLETON_REQUIRED     _HRESULT_TYPEDEF_(0x80300102L)






// A user account is required in order to commit the current Data Collector Set properties.

PLA_E_CREDENTIALS_REQUIRED       _HRESULT_TYPEDEF_(0x80300103L)






// Data Collector Set is not running.

PLA_E_DCS_NOT_RUNNING            _HRESULT_TYPEDEF_(0x80300104L)






// A conflict was detected in the list of include/exclude APIs. Do not specify the same API in both the include list and the exclude list.

PLA_E_CONFLICT_INCL_EXCL_API     _HRESULT_TYPEDEF_(0x80300105L)






// The executable path you have specified refers to a network share or UNC path.

PLA_E_NETWORK_EXE_NOT_VALID      _HRESULT_TYPEDEF_(0x80300106L)






// The executable path you have specified is already configured for API tracing.

PLA_E_EXE_ALREADY_CONFIGURED     _HRESULT_TYPEDEF_(0x80300107L)






// The executable path you have specified does not exist. Verify that the specified path is correct.

PLA_E_EXE_PATH_NOT_VALID         _HRESULT_TYPEDEF_(0x80300108L)






// Data Collector already exists.

PLA_E_DC_ALREADY_EXISTS          _HRESULT_TYPEDEF_(0x80300109L)






// The wait for the Data Collector Set start notification has timed out.

PLA_E_DCS_START_WAIT_TIMEOUT     _HRESULT_TYPEDEF_(0x8030010AL)






// The wait for the Data Collector to start has timed out.

PLA_E_DC_START_WAIT_TIMEOUT      _HRESULT_TYPEDEF_(0x8030010BL)






// The wait for the report generation tool to finish has timed out.

PLA_E_REPORT_WAIT_TIMEOUT        _HRESULT_TYPEDEF_(0x8030010CL)






// Duplicate items are not allowed.

PLA_E_NO_DUPLICATES              _HRESULT_TYPEDEF_(0x8030010DL)






// When specifying the executable that you want to trace, you must specify a full path to the executable and not just a filename.

PLA_E_EXE_FULL_PATH_REQUIRED     _HRESULT_TYPEDEF_(0x8030010EL)






// The session name provided is invalid.

PLA_E_INVALID_SESSION_NAME       _HRESULT_TYPEDEF_(0x8030010FL)






// The Event Log channel Microsoft-Windows-Diagnosis-PLA/Operational must be enabled to perform this operation.

PLA_E_PLA_CHANNEL_NOT_ENABLED    _HRESULT_TYPEDEF_(0x80300110L)






// The Event Log channel Microsoft-Windows-TaskScheduler must be enabled to perform this operation.

PLA_E_TASKSCHED_CHANNEL_NOT_ENABLED _HRESULT_TYPEDEF_(0x80300111L)






// The execution of the Rules Manager failed.

PLA_E_RULES_MANAGER_FAILED       _HRESULT_TYPEDEF_(0x80300112L)






// An error occurred while attempting to compress or extract the data.

PLA_E_CABAPI_FAILURE             _HRESULT_TYPEDEF_(0x80300113L)


// =======================================================
// Full Volume Encryption Error Messages
// =======================================================






// This drive is locked by BitLocker Drive Encryption. You must unlock this drive from Control Panel.

FVE_E_LOCKED_VOLUME              _HRESULT_TYPEDEF_(0x80310000L)






// This drive is not encrypted.

FVE_E_NOT_ENCRYPTED              _HRESULT_TYPEDEF_(0x80310001L)






// The BIOS did not correctly communicate with the Trusted Platform Module (TPM). Contact the computer manufacturer for BIOS upgrade instructions.

FVE_E_NO_TPM_BIOS                _HRESULT_TYPEDEF_(0x80310002L)






// The BIOS did not correctly communicate with the master boot record (MBR). Contact the computer manufacturer for BIOS upgrade instructions.

FVE_E_NO_MBR_METRIC              _HRESULT_TYPEDEF_(0x80310003L)






// A required TPM measurement is missing. If there is a bootable CD or DVD in your computer, remove it, restart the computer, and turn on BitLocker again. If the problem persists, ensure the master boot record is up to date.

FVE_E_NO_BOOTSECTOR_METRIC       _HRESULT_TYPEDEF_(0x80310004L)






// The boot sector of this drive is not compatible with BitLocker Drive Encryption. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot manager (BOOTMGR).

FVE_E_NO_BOOTMGR_METRIC          _HRESULT_TYPEDEF_(0x80310005L)






// The boot manager of this operating system is not compatible with BitLocker Drive Encryption. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot manager (BOOTMGR).

FVE_E_WRONG_BOOTMGR              _HRESULT_TYPEDEF_(0x80310006L)






// At least one secure key protector is required for this operation to be performed.

FVE_E_SECURE_KEY_REQUIRED        _HRESULT_TYPEDEF_(0x80310007L)






// BitLocker Drive Encryption is not enabled on this drive. Turn on BitLocker.

FVE_E_NOT_ACTIVATED              _HRESULT_TYPEDEF_(0x80310008L)






// BitLocker Drive Encryption cannot perform the requested action. This condition may occur when two requests are issued at the same time. Wait a few moments and then try the action again.

FVE_E_ACTION_NOT_ALLOWED         _HRESULT_TYPEDEF_(0x80310009L)






// The Active Directory Domain Services forest does not contain the required attributes and classes to host BitLocker Drive Encryption or Trusted Platform Module information. Contact your domain administrator to verify that any required BitLocker Active Directory schema extensions have been installed.

FVE_E_AD_SCHEMA_NOT_INSTALLED    _HRESULT_TYPEDEF_(0x8031000AL)






// The type of the data obtained from Active Directory was not expected. The BitLocker recovery information may be missing or corrupted.

FVE_E_AD_INVALID_DATATYPE        _HRESULT_TYPEDEF_(0x8031000BL)






// The size of the data obtained from Active Directory was not expected. The BitLocker recovery information may be missing or corrupted.

FVE_E_AD_INVALID_DATASIZE        _HRESULT_TYPEDEF_(0x8031000CL)






// The attribute read from Active Directory does not contain any values. The BitLocker recovery information may be missing or corrupted.

FVE_E_AD_NO_VALUES               _HRESULT_TYPEDEF_(0x8031000DL)






// The attribute was not set. Verify that you are logged on with a domain account that has the ability to write information to Active Directory objects.

FVE_E_AD_ATTR_NOT_SET            _HRESULT_TYPEDEF_(0x8031000EL)






// The specified attribute cannot be found in Active Directory Domain Services. Contact your domain administrator to verify that any required BitLocker Active Directory schema extensions have been installed.

FVE_E_AD_GUID_NOT_FOUND          _HRESULT_TYPEDEF_(0x8031000FL)






// The BitLocker metadata for the encrypted drive is not valid. You can attempt to repair the drive to restore access.

FVE_E_BAD_INFORMATION            _HRESULT_TYPEDEF_(0x80310010L)






// The drive cannot be encrypted because it does not have enough free space. Delete any unnecessary data on the drive to create additional free space and then try again.

FVE_E_TOO_SMALL                  _HRESULT_TYPEDEF_(0x80310011L)






// The drive cannot be encrypted because it contains system boot information. Create a separate partition for use as the system drive that contains the boot information and a second partition for use as the operating system drive and then encrypt the operating system drive.

FVE_E_SYSTEM_VOLUME              _HRESULT_TYPEDEF_(0x80310012L)






// The drive cannot be encrypted because the file system is not supported.

FVE_E_FAILED_WRONG_FS            _HRESULT_TYPEDEF_(0x80310013L)






// The file system size is larger than the partition size in the partition table. This drive may be corrupt or may have been tampered with. To use it with BitLocker, you must reformat the partition.

FVE_E_BAD_PARTITION_SIZE         _HRESULT_TYPEDEF_(0x80310014L)






// This drive cannot be encrypted.

FVE_E_NOT_SUPPORTED              _HRESULT_TYPEDEF_(0x80310015L)






// The data is not valid.

FVE_E_BAD_DATA                   _HRESULT_TYPEDEF_(0x80310016L)






// The data drive specified is not set to automatically unlock on the current computer and cannot be unlocked automatically.

FVE_E_VOLUME_NOT_BOUND           _HRESULT_TYPEDEF_(0x80310017L)






// You must initialize the Trusted Platform Module (TPM) before you can use BitLocker Drive Encryption.

FVE_E_TPM_NOT_OWNED              _HRESULT_TYPEDEF_(0x80310018L)






// The operation attempted cannot be performed on an operating system drive.

FVE_E_NOT_DATA_VOLUME            _HRESULT_TYPEDEF_(0x80310019L)






// The buffer supplied to a function was insufficient to contain the returned data. Increase the buffer size before running the function again.

FVE_E_AD_INSUFFICIENT_BUFFER     _HRESULT_TYPEDEF_(0x8031001AL)






// A read operation failed while converting the drive. The drive was not converted. Please re-enable BitLocker.

FVE_E_CONV_READ                  _HRESULT_TYPEDEF_(0x8031001BL)






// A write operation failed while converting the drive. The drive was not converted. Please re-enable BitLocker.

FVE_E_CONV_WRITE                 _HRESULT_TYPEDEF_(0x8031001CL)






// One or more BitLocker key protectors are required. You cannot delete the last key on this drive.

FVE_E_KEY_REQUIRED               _HRESULT_TYPEDEF_(0x8031001DL)






// Cluster configurations are not supported by BitLocker Drive Encryption.

FVE_E_CLUSTERING_NOT_SUPPORTED   _HRESULT_TYPEDEF_(0x8031001EL)






// The drive specified is already configured to be automatically unlocked on the current computer.

FVE_E_VOLUME_BOUND_ALREADY       _HRESULT_TYPEDEF_(0x8031001FL)






// The operating system drive is not protected by BitLocker Drive Encryption.

FVE_E_OS_NOT_PROTECTED           _HRESULT_TYPEDEF_(0x80310020L)






// BitLocker Drive Encryption has been suspended on this drive. All BitLocker key protectors configured for this drive are effectively disabled, and the drive will be automatically unlocked using an unencrypted (clear) key.

FVE_E_PROTECTION_DISABLED        _HRESULT_TYPEDEF_(0x80310021L)






// The drive you are attempting to lock does not have any key protectors available for encryption because BitLocker protection is currently suspended. Re-enable BitLocker to lock this drive.

FVE_E_RECOVERY_KEY_REQUIRED      _HRESULT_TYPEDEF_(0x80310022L)






// BitLocker cannot use the Trusted Platform Module (TPM) to protect a data drive. TPM protection can only be used with the operating system drive.

FVE_E_FOREIGN_VOLUME             _HRESULT_TYPEDEF_(0x80310023L)






// The BitLocker metadata for the encrypted drive cannot be updated because it was locked for updating by another process. Please try this process again.

FVE_E_OVERLAPPED_UPDATE          _HRESULT_TYPEDEF_(0x80310024L)






// The authorization data for the storage root key (SRK) of the Trusted Platform Module (TPM) is not zero and is therefore incompatible with BitLocker. Please initialize the TPM before attempting to use it with BitLocker.

FVE_E_TPM_SRK_AUTH_NOT_ZERO      _HRESULT_TYPEDEF_(0x80310025L)






// The drive encryption algorithm cannot be used on this sector size.

FVE_E_FAILED_SECTOR_SIZE         _HRESULT_TYPEDEF_(0x80310026L)






// The drive cannot be unlocked with the key provided. Confirm that you have provided the correct key and try again.

FVE_E_FAILED_AUTHENTICATION      _HRESULT_TYPEDEF_(0x80310027L)






// The drive specified is not the operating system drive.

FVE_E_NOT_OS_VOLUME              _HRESULT_TYPEDEF_(0x80310028L)






// BitLocker Drive Encryption cannot be turned off on the operating system drive until the auto unlock feature has been disabled for the fixed data drives and removable data drives associated with this computer.

FVE_E_AUTOUNLOCK_ENABLED         _HRESULT_TYPEDEF_(0x80310029L)






// The system partition boot sector does not perform Trusted Platform Module (TPM) measurements. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot sector.

FVE_E_WRONG_BOOTSECTOR           _HRESULT_TYPEDEF_(0x8031002AL)






// BitLocker Drive Encryption operating system drives must be formatted with the NTFS file system in order to be encrypted. Convert the drive to NTFS, and then turn on BitLocker.

FVE_E_WRONG_SYSTEM_FS            _HRESULT_TYPEDEF_(0x8031002BL)






// Group Policy settings require that a recovery password be specified before encrypting the drive.

FVE_E_POLICY_PASSWORD_REQUIRED   _HRESULT_TYPEDEF_(0x8031002CL)






// The drive encryption algorithm and key cannot be set on a previously encrypted drive. To encrypt this drive with BitLocker Drive Encryption, remove the previous encryption and then turn on BitLocker.

FVE_E_CANNOT_SET_FVEK_ENCRYPTED  _HRESULT_TYPEDEF_(0x8031002DL)






// BitLocker Drive Encryption cannot encrypt the specified drive because an encryption key is not available. Add a key protector to encrypt this drive.

FVE_E_CANNOT_ENCRYPT_NO_KEY      _HRESULT_TYPEDEF_(0x8031002EL)






// BitLocker Drive Encryption detected bootable media (CD or DVD) in the computer. Remove the media and restart the computer before configuring BitLocker.

FVE_E_BOOTABLE_CDDVD             _HRESULT_TYPEDEF_(0x80310030L)






// This key protector cannot be added. Only one key protector of this type is allowed for this drive.

FVE_E_PROTECTOR_EXISTS           _HRESULT_TYPEDEF_(0x80310031L)






// The recovery password file was not found because a relative path was specified. Recovery passwords must be saved to a fully qualified path. Environment variables configured on the computer can be used in the path.

FVE_E_RELATIVE_PATH              _HRESULT_TYPEDEF_(0x80310032L)






// The specified key protector was not found on the drive. Try another key protector.

FVE_E_PROTECTOR_NOT_FOUND        _HRESULT_TYPEDEF_(0x80310033L)






// The recovery key provided is corrupt and cannot be used to access the drive. An alternative recovery method, such as recovery password, a data recovery agent, or a backup version of the recovery key must be used to recover access to the drive.

FVE_E_INVALID_KEY_FORMAT         _HRESULT_TYPEDEF_(0x80310034L)






// The format of the recovery password provided is invalid. BitLocker recovery passwords are 48 digits. Verify that the recovery password is in the correct format and then try again.

FVE_E_INVALID_PASSWORD_FORMAT    _HRESULT_TYPEDEF_(0x80310035L)






// The random number generator check test failed.

FVE_E_FIPS_RNG_CHECK_FAILED      _HRESULT_TYPEDEF_(0x80310036L)






// The Group Policy setting requiring FIPS compliance prevents a local recovery password from being generated or used by BitLocker Drive Encryption. When operating in FIPS-compliant mode, BitLocker recovery options can be either a recovery key stored on a USB drive or recovery through a data recovery agent.

FVE_E_FIPS_PREVENTS_RECOVERY_PASSWORD _HRESULT_TYPEDEF_(0x80310037L)






// The Group Policy setting requiring FIPS compliance prevents the recovery password from being saved to Active Directory. When operating in FIPS-compliant mode, BitLocker recovery options can be either a recovery key stored on a USB drive or recovery through a data recovery agent. Check your Group Policy settings configuration.

FVE_E_FIPS_PREVENTS_EXTERNAL_KEY_EXPORT _HRESULT_TYPEDEF_(0x80310038L)






// The drive must be fully decrypted to complete this operation.

FVE_E_NOT_DECRYPTED              _HRESULT_TYPEDEF_(0x80310039L)






// The key protector specified cannot be used for this operation.

FVE_E_INVALID_PROTECTOR_TYPE     _HRESULT_TYPEDEF_(0x8031003AL)






// No key protectors exist on the drive to perform the hardware test.

FVE_E_NO_PROTECTORS_TO_TEST      _HRESULT_TYPEDEF_(0x8031003BL)






// The BitLocker startup key or recovery password cannot be found on the USB device. Verify that you have the correct USB device, that the USB device is plugged into the computer on an active USB port, restart the computer, and then try again. If the problem persists, contact the computer manufacturer for BIOS upgrade instructions.

FVE_E_KEYFILE_NOT_FOUND          _HRESULT_TYPEDEF_(0x8031003CL)






// The BitLocker startup key or recovery password file provided is corrupt or invalid. Verify that you have the correct startup key or recovery password file and try again.

FVE_E_KEYFILE_INVALID            _HRESULT_TYPEDEF_(0x8031003DL)






// The BitLocker encryption key cannot be obtained from the startup key or recovery password. Verify that you have the correct startup key or recovery password and try again.

FVE_E_KEYFILE_NO_VMK             _HRESULT_TYPEDEF_(0x8031003EL)






// The Trusted Platform Module (TPM) is disabled. The TPM must be enabled, initialized, and have valid ownership before it can be used with BitLocker Drive Encryption.

FVE_E_TPM_DISABLED               _HRESULT_TYPEDEF_(0x8031003FL)






// The BitLocker configuration of the specified drive cannot be managed because this computer is currently operating in Safe Mode. While in Safe Mode, BitLocker Drive Encryption can only be used for recovery purposes.

FVE_E_NOT_ALLOWED_IN_SAFE_MODE   _HRESULT_TYPEDEF_(0x80310040L)






// The Trusted Platform Module (TPM) was unable to unlock the drive. Either the system boot information changed after choosing BitLocker settings or the PIN did not match. If the problem persists after several tries, there may be a hardware or firmware problem.

FVE_E_TPM_INVALID_PCR            _HRESULT_TYPEDEF_(0x80310041L)






// The BitLocker encryption key cannot be obtained from the Trusted Platform Module (TPM).

FVE_E_TPM_NO_VMK                 _HRESULT_TYPEDEF_(0x80310042L)






// The BitLocker encryption key cannot be obtained from the Trusted Platform Module (TPM) and PIN.

FVE_E_PIN_INVALID                _HRESULT_TYPEDEF_(0x80310043L)






// A boot application has changed since BitLocker Drive Encryption was enabled.

FVE_E_AUTH_INVALID_APPLICATION   _HRESULT_TYPEDEF_(0x80310044L)






// The Boot Configuration Data (BCD) settings have changed since BitLocker Drive Encryption was enabled.

FVE_E_AUTH_INVALID_CONFIG        _HRESULT_TYPEDEF_(0x80310045L)






// The Group Policy setting requiring FIPS compliance prohibits the use of unencrypted keys, which prevents BitLocker from being suspended on this drive. Please contact your domain administrator for more information.

FVE_E_FIPS_DISABLE_PROTECTION_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310046L)






// This drive cannot be encrypted by BitLocker Drive Encryption because the file system does not extend to the end of the drive. Repartition this drive and then try again.

FVE_E_FS_NOT_EXTENDED            _HRESULT_TYPEDEF_(0x80310047L)






// BitLocker Drive Encryption cannot be enabled on the operating system drive. Contact the computer manufacturer for BIOS upgrade instructions.

FVE_E_FIRMWARE_TYPE_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80310048L)






// This version of Windows does not include BitLocker Drive Encryption. To use BitLocker Drive Encryption, please upgrade the operating system.

FVE_E_NO_LICENSE                 _HRESULT_TYPEDEF_(0x80310049L)






// BitLocker Drive Encryption cannot be used because critical BitLocker system files are missing or corrupted. Use Windows Startup Repair to restore these files to your computer.

FVE_E_NOT_ON_STACK               _HRESULT_TYPEDEF_(0x8031004AL)






// The drive cannot be locked when the drive is in use.

FVE_E_FS_MOUNTED                 _HRESULT_TYPEDEF_(0x8031004BL)






// The access token associated with the current thread is not an impersonated token.

FVE_E_TOKEN_NOT_IMPERSONATED     _HRESULT_TYPEDEF_(0x8031004CL)






// The BitLocker encryption key cannot be obtained. Verify that the Trusted Platform Module (TPM) is enabled and ownership has been taken. If this computer does not have a TPM, verify that the USB drive is inserted and available.

FVE_E_DRY_RUN_FAILED             _HRESULT_TYPEDEF_(0x8031004DL)






// You must restart your computer before continuing with BitLocker Drive Encryption.

FVE_E_REBOOT_REQUIRED            _HRESULT_TYPEDEF_(0x8031004EL)






// Drive encryption cannot occur while boot debugging is enabled. Use the bcdedit command-line tool to turn off boot debugging.

FVE_E_DEBUGGER_ENABLED           _HRESULT_TYPEDEF_(0x8031004FL)






// No action was taken as BitLocker Drive Encryption is in raw access mode.

FVE_E_RAW_ACCESS                 _HRESULT_TYPEDEF_(0x80310050L)






// BitLocker Drive Encryption cannot enter raw access mode for this drive because the drive is currently in use.

FVE_E_RAW_BLOCKED                _HRESULT_TYPEDEF_(0x80310051L)






// The path specified in the Boot Configuration Data (BCD) for a BitLocker Drive Encryption integrity-protected application is incorrect. Please verify and correct your BCD settings and try again.

FVE_E_BCD_APPLICATIONS_PATH_INCORRECT _HRESULT_TYPEDEF_(0x80310052L)






// BitLocker Drive Encryption can only be used for limited provisioning or recovery purposes when the computer is running in pre-installation or recovery environments.

FVE_E_NOT_ALLOWED_IN_VERSION     _HRESULT_TYPEDEF_(0x80310053L)






// The auto-unlock master key was not available from the operating system drive.

FVE_E_NO_AUTOUNLOCK_MASTER_KEY   _HRESULT_TYPEDEF_(0x80310054L)






// The system firmware failed to enable clearing of system memory when the computer was restarted.

FVE_E_MOR_FAILED                 _HRESULT_TYPEDEF_(0x80310055L)






// The hidden drive cannot be encrypted.

FVE_E_HIDDEN_VOLUME              _HRESULT_TYPEDEF_(0x80310056L)






// BitLocker encryption keys were ignored because the drive was in a transient state.

FVE_E_TRANSIENT_STATE            _HRESULT_TYPEDEF_(0x80310057L)






// Public key based protectors are not allowed on this drive.

FVE_E_PUBKEY_NOT_ALLOWED         _HRESULT_TYPEDEF_(0x80310058L)






// BitLocker Drive Encryption is already performing an operation on this drive. Please complete all operations before continuing.

FVE_E_VOLUME_HANDLE_OPEN         _HRESULT_TYPEDEF_(0x80310059L)






// This version of Windows does not support this feature of BitLocker Drive Encryption. To use this feature, upgrade the operating system.

FVE_E_NO_FEATURE_LICENSE         _HRESULT_TYPEDEF_(0x8031005AL)






// The Group Policy settings for BitLocker startup options are in conflict and cannot be applied. Contact your system administrator for more information.

FVE_E_INVALID_STARTUP_OPTIONS    _HRESULT_TYPEDEF_(0x8031005BL)






// Group Policy settings do not permit the creation of a recovery password.

FVE_E_POLICY_RECOVERY_PASSWORD_NOT_ALLOWED _HRESULT_TYPEDEF_(0x8031005CL)






// Group Policy settings require the creation of a recovery password.

FVE_E_POLICY_RECOVERY_PASSWORD_REQUIRED _HRESULT_TYPEDEF_(0x8031005DL)






// Group Policy settings do not permit the creation of a recovery key.

FVE_E_POLICY_RECOVERY_KEY_NOT_ALLOWED _HRESULT_TYPEDEF_(0x8031005EL)






// Group Policy settings require the creation of a recovery key.

FVE_E_POLICY_RECOVERY_KEY_REQUIRED _HRESULT_TYPEDEF_(0x8031005FL)






// Group Policy settings do not permit the use of a PIN at startup. Please choose a different BitLocker startup option.

FVE_E_POLICY_STARTUP_PIN_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310060L)






// Group Policy settings require the use of a PIN at startup. Please choose this BitLocker startup option.

FVE_E_POLICY_STARTUP_PIN_REQUIRED _HRESULT_TYPEDEF_(0x80310061L)






// Group Policy settings do not permit the use of a startup key. Please choose a different BitLocker startup option.

FVE_E_POLICY_STARTUP_KEY_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310062L)






// Group Policy settings require the use of a startup key. Please choose this BitLocker startup option.

FVE_E_POLICY_STARTUP_KEY_REQUIRED _HRESULT_TYPEDEF_(0x80310063L)






// Group Policy settings do not permit the use of a startup key and PIN. Please choose a different BitLocker startup option.

FVE_E_POLICY_STARTUP_PIN_KEY_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310064L)






// Group Policy settings require the use of a startup key and PIN. Please choose this BitLocker startup option.

FVE_E_POLICY_STARTUP_PIN_KEY_REQUIRED _HRESULT_TYPEDEF_(0x80310065L)






// Group policy does not permit the use of TPM-only at startup. Please choose a different BitLocker startup option.

FVE_E_POLICY_STARTUP_TPM_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310066L)






// Group Policy settings require the use of TPM-only at startup. Please choose this BitLocker startup option.

FVE_E_POLICY_STARTUP_TPM_REQUIRED _HRESULT_TYPEDEF_(0x80310067L)






// The PIN provided does not meet minimum or maximum length requirements.

FVE_E_POLICY_INVALID_PIN_LENGTH  _HRESULT_TYPEDEF_(0x80310068L)






// The key protector is not supported by the version of BitLocker Drive Encryption currently on the drive. Upgrade the drive to add the key protector.

FVE_E_KEY_PROTECTOR_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80310069L)






// Group Policy settings do not permit the creation of a password.

FVE_E_POLICY_PASSPHRASE_NOT_ALLOWED _HRESULT_TYPEDEF_(0x8031006AL)






// Group Policy settings require the creation of a password.

FVE_E_POLICY_PASSPHRASE_REQUIRED _HRESULT_TYPEDEF_(0x8031006BL)






// The Group Policy setting requiring FIPS compliance prevents passwords from being generated or used. Please contact your system administrator for more information.

FVE_E_FIPS_PREVENTS_PASSPHRASE   _HRESULT_TYPEDEF_(0x8031006CL)






// A password cannot be added to the operating system drive.

FVE_E_OS_VOLUME_PASSPHRASE_NOT_ALLOWED _HRESULT_TYPEDEF_(0x8031006DL)






// The BitLocker object identifier (OID) on the drive appears to be invalid or corrupt. Use manage-BDE to reset the OID on this drive.

FVE_E_INVALID_BITLOCKER_OID      _HRESULT_TYPEDEF_(0x8031006EL)






// The drive is too small to be protected using BitLocker Drive Encryption.

FVE_E_VOLUME_TOO_SMALL           _HRESULT_TYPEDEF_(0x8031006FL)






// The selected discovery drive type is incompatible with the file system on the drive. BitLocker To Go discovery drives must be created on FAT formatted drives.

FVE_E_DV_NOT_SUPPORTED_ON_FS     _HRESULT_TYPEDEF_(0x80310070L)






// The selected discovery drive type is not allowed by the computer's Group Policy settings. Verify that Group Policy settings allow the creation of discovery drives for use with BitLocker To Go.

FVE_E_DV_NOT_ALLOWED_BY_GP       _HRESULT_TYPEDEF_(0x80310071L)






// Group Policy settings do not permit user certificates such as smart cards to be used with BitLocker Drive Encryption.

FVE_E_POLICY_USER_CERTIFICATE_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310072L)






// Group Policy settings require that you have a valid user certificate, such as a smart card, to be used with BitLocker Drive Encryption.

FVE_E_POLICY_USER_CERTIFICATE_REQUIRED _HRESULT_TYPEDEF_(0x80310073L)






// Group Policy settings requires that you use a smart card-based key protector with BitLocker Drive Encryption.

FVE_E_POLICY_USER_CERT_MUST_BE_HW _HRESULT_TYPEDEF_(0x80310074L)






// Group Policy settings do not permit BitLocker-protected fixed data drives to be automatically unlocked.

FVE_E_POLICY_USER_CONFIGURE_FDV_AUTOUNLOCK_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310075L)






// Group Policy settings do not permit BitLocker-protected removable data drives to be automatically unlocked.

FVE_E_POLICY_USER_CONFIGURE_RDV_AUTOUNLOCK_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310076L)






// Group Policy settings do not permit you to configure BitLocker Drive Encryption on removable data drives.

FVE_E_POLICY_USER_CONFIGURE_RDV_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310077L)






// Group Policy settings do not permit you to turn on BitLocker Drive Encryption on removable data drives. Please contact your system administrator if you need to turn on BitLocker.

FVE_E_POLICY_USER_ENABLE_RDV_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310078L)






// Group Policy settings do not permit turning off BitLocker Drive Encryption on removable data drives. Please contact your system administrator if you need to turn off BitLocker.

FVE_E_POLICY_USER_DISABLE_RDV_NOT_ALLOWED _HRESULT_TYPEDEF_(0x80310079L)






// Your password does not meet minimum password length requirements. By default, passwords must be at least 8 characters in length. Check with your system administrator for the password length requirement in your organization.

FVE_E_POLICY_INVALID_PASSPHRASE_LENGTH _HRESULT_TYPEDEF_(0x80310080L)






// Your password does not meet the complexity requirements set by your system administrator. Try adding upper and lowercase characters, numbers, and symbols.

FVE_E_POLICY_PASSPHRASE_TOO_SIMPLE _HRESULT_TYPEDEF_(0x80310081L)






// This drive cannot be encrypted because it is reserved for Windows System Recovery Options.

FVE_E_RECOVERY_PARTITION         _HRESULT_TYPEDEF_(0x80310082L)






// BitLocker Drive Encryption cannot be applied to this drive because of conflicting Group Policy settings. BitLocker cannot be configured to automatically unlock fixed data drives when user recovery options are disabled. If you want BitLocker-protected fixed data drives to be automatically unlocked after key validation has occurred, please ask your system administrator to resolve the settings conflict before enabling BitLocker.

FVE_E_POLICY_CONFLICT_FDV_RK_OFF_AUK_ON _HRESULT_TYPEDEF_(0x80310083L)






// BitLocker Drive Encryption cannot be applied to this drive because of conflicting Group Policy settings. BitLocker cannot be configured to automatically unlock removable data drives when user recovery option are disabled. If you want BitLocker-protected removable data drives to be automatically unlocked after key validation has occurred, please ask your system administrator to resolve the settings conflict before enabling BitLocker.

FVE_E_POLICY_CONFLICT_RDV_RK_OFF_AUK_ON _HRESULT_TYPEDEF_(0x80310084L)






// The Enhanced Key Usage (EKU) attribute of the specified certificate does not permit it to be used for BitLocker Drive Encryption. BitLocker does not require that a certificate have an EKU attribute, but if one is configured it must be set to an object identifier (OID) that matches the OID configured for BitLocker.

FVE_E_NON_BITLOCKER_OID          _HRESULT_TYPEDEF_(0x80310085L)






// BitLocker Drive Encryption cannot be applied to this drive as currently configured because of Group Policy settings. The certificate you provided for drive encryption is self-signed. Current Group Policy settings do not permit the use of self-signed certificates. Obtain a new certificate from your certification authority before attempting to enable BitLocker.

FVE_E_POLICY_PROHIBITS_SELFSIGNED _HRESULT_TYPEDEF_(0x80310086L)






// BitLocker Encryption cannot be applied to this drive because of conflicting Group Policy settings. When write access to drives not protected by BitLocker is denied, the use of a USB startup key cannot be required. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.

FVE_E_POLICY_CONFLICT_RO_AND_STARTUP_KEY_REQUIRED _HRESULT_TYPEDEF_(0x80310087L)






// BitLocker Drive Encryption failed to recover from an abruptly terminated conversion. This could be due to either all conversion logs being corrupted or the media being write-protected.

FVE_E_CONV_RECOVERY_FAILED       _HRESULT_TYPEDEF_(0x80310088L)






// The requested virtualization size is too big.

FVE_E_VIRTUALIZED_SPACE_TOO_BIG  _HRESULT_TYPEDEF_(0x80310089L)






// BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on operating system drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.

FVE_E_POLICY_CONFLICT_OSV_RP_OFF_ADB_ON _HRESULT_TYPEDEF_(0x80310090L)






// BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on fixed data drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.

FVE_E_POLICY_CONFLICT_FDV_RP_OFF_ADB_ON _HRESULT_TYPEDEF_(0x80310091L)






// BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on removable data drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.

FVE_E_POLICY_CONFLICT_RDV_RP_OFF_ADB_ON _HRESULT_TYPEDEF_(0x80310092L)






// The Key Usage (KU) attribute of the specified certificate does not permit it to be used for BitLocker Drive Encryption. BitLocker does not require that a certificate have a KU attribute, but if one is configured it must be set to either Key Encipherment or Key Agreement.

FVE_E_NON_BITLOCKER_KU           _HRESULT_TYPEDEF_(0x80310093L)






// The private key associated with the specified certificate cannot be authorized. The private key authorization was either not provided or the provided authorization was invalid.

FVE_E_PRIVATEKEY_AUTH_FAILED     _HRESULT_TYPEDEF_(0x80310094L)






// Removal of the data recovery agent certificate must be done using the Certificates snap-in.

FVE_E_REMOVAL_OF_DRA_FAILED      _HRESULT_TYPEDEF_(0x80310095L)






// This drive was encrypted using the version of BitLocker Drive Encryption included with Windows Vista and Windows Server 2008 which does not support organizational identifiers. To specify organizational identifiers for this drive upgrade the drive encryption to the latest version using the "manage-bde -upgrade" command.

FVE_E_OPERATION_NOT_SUPPORTED_ON_VISTA_VOLUME _HRESULT_TYPEDEF_(0x80310096L)






// The drive cannot be locked because it is automatically unlocked on this computer.  Remove the automatic unlock protector to lock this drive.

FVE_E_CANT_LOCK_AUTOUNLOCK_ENABLED_VOLUME _HRESULT_TYPEDEF_(0x80310097L)






// The default BitLocker Key Derivation Function SP800-56A for ECC smart cards is not supported by your smart card. The Group Policy setting requiring FIPS-compliance prevents BitLocker from using any other key derivation function for encryption. You have to use a FIPS compliant smart card in FIPS restricted environments.

FVE_E_FIPS_HASH_KDF_NOT_ALLOWED  _HRESULT_TYPEDEF_(0x80310098L)






// The BitLocker encryption key could not be obtained from the Trusted Platform Module (TPM) and enhanced PIN. Try using a PIN containing only numerals.

FVE_E_ENH_PIN_INVALID            _HRESULT_TYPEDEF_(0x80310099L)






// The requested TPM PIN contains invalid characters.

FVE_E_INVALID_PIN_CHARS          _HRESULT_TYPEDEF_(0x8031009AL)






// The management information stored on the drive contained an unknown type. If you are using an old version of Windows, try accessing the drive from the latest version.

FVE_E_INVALID_DATUM_TYPE         _HRESULT_TYPEDEF_(0x8031009BL)






// The feature is only supported on EFI systems.

FVE_E_EFI_ONLY                   _HRESULT_TYPEDEF_(0x8031009CL)






// More than one Network Key Protector certificate has been found on the system.

FVE_E_MULTIPLE_NKP_CERTS         _HRESULT_TYPEDEF_(0x8031009DL)






// Removal of the Network Key Protector certificate must be done using the Certificates snap-in.

FVE_E_REMOVAL_OF_NKP_FAILED      _HRESULT_TYPEDEF_(0x8031009EL)






// An invalid certificate has been found in the Network Key Protector certificate store.

FVE_E_INVALID_NKP_CERT           _HRESULT_TYPEDEF_(0x8031009FL)






// This drive isn't protected with a PIN.

FVE_E_NO_EXISTING_PIN            _HRESULT_TYPEDEF_(0x803100A0L)






// Please enter the correct current PIN.

FVE_E_PROTECTOR_CHANGE_PIN_MISMATCH _HRESULT_TYPEDEF_(0x803100A1L)






// You must be logged on with an administrator account to change the PIN. Click the link to reset the PIN as an administrator.

FVE_E_PIN_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED _HRESULT_TYPEDEF_(0x803100A2L)






// BitLocker has disabled PIN changes after too many failed requests. Click the link to reset the PIN as an administrator.

FVE_E_PROTECTOR_CHANGE_MAX_PIN_CHANGE_ATTEMPTS_REACHED _HRESULT_TYPEDEF_(0x803100A3L)






// Your system administrator requires that passwords contain only printable ASCII characters. This includes unaccented letters (A-Z, a-z), numbers (0-9), space, arithmetic signs, common punctuation, separators, and the following symbols: # $ & @ ^ _ ~ .

FVE_E_POLICY_PASSPHRASE_REQUIRES_ASCII _HRESULT_TYPEDEF_(0x803100A4L)






// BitLocker Drive Encryption only supports Used Space Only encryption on thin provisioned storage.

FVE_E_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE _HRESULT_TYPEDEF_(0x803100A5L)






// BitLocker Drive Encryption does not support wiping free space on thin provisioned storage.

FVE_E_WIPE_NOT_ALLOWED_ON_TP_STORAGE _HRESULT_TYPEDEF_(0x803100A6L)






// The required authentication key length is not supported by the drive.

FVE_E_KEY_LENGTH_NOT_SUPPORTED_BY_EDRIVE _HRESULT_TYPEDEF_(0x803100A7L)






// This drive isn't protected with a password.

FVE_E_NO_EXISTING_PASSPHRASE     _HRESULT_TYPEDEF_(0x803100A8L)






// Please enter the correct current password.

FVE_E_PROTECTOR_CHANGE_PASSPHRASE_MISMATCH _HRESULT_TYPEDEF_(0x803100A9L)






// The password cannot exceed 256 characters.

FVE_E_PASSPHRASE_TOO_LONG        _HRESULT_TYPEDEF_(0x803100AAL)






// A password key protector cannot be added because a TPM protector exists on the drive.

FVE_E_NO_PASSPHRASE_WITH_TPM     _HRESULT_TYPEDEF_(0x803100ABL)






// A TPM key protector cannot be added because a password protector exists on the drive.

FVE_E_NO_TPM_WITH_PASSPHRASE     _HRESULT_TYPEDEF_(0x803100ACL)






// This command can only be performed from the coordinator node for the specified CSV volume.

FVE_E_NOT_ALLOWED_ON_CSV_STACK   _HRESULT_TYPEDEF_(0x803100ADL)






// This command cannot be performed on a volume when it is part of a cluster.

FVE_E_NOT_ALLOWED_ON_CLUSTER     _HRESULT_TYPEDEF_(0x803100AEL)






// BitLocker did not revert to using BitLocker software encryption due to group policy configuration.

FVE_E_EDRIVE_NO_FAILOVER_TO_SW   _HRESULT_TYPEDEF_(0x803100AFL)






// The drive cannot be managed by BitLocker because the drive's hardware encryption feature is already in use.

FVE_E_EDRIVE_BAND_IN_USE         _HRESULT_TYPEDEF_(0x803100B0L)






// Group Policy settings do not allow the use of hardware-based encryption.

FVE_E_EDRIVE_DISALLOWED_BY_GP    _HRESULT_TYPEDEF_(0x803100B1L)






// The drive specified does not support hardware-based encryption.

FVE_E_EDRIVE_INCOMPATIBLE_VOLUME _HRESULT_TYPEDEF_(0x803100B2L)






// BitLocker cannot be upgraded during disk encryption or decryption.

FVE_E_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING _HRESULT_TYPEDEF_(0x803100B3L)






// Discovery Volumes are not supported for volumes using hardware encryption.

FVE_E_EDRIVE_DV_NOT_SUPPORTED    _HRESULT_TYPEDEF_(0x803100B4L)






// No pre-boot keyboard detected. The user may not be able to provide required input to unlock the volume.

FVE_E_NO_PREBOOT_KEYBOARD_DETECTED _HRESULT_TYPEDEF_(0x803100B5L)






// No pre-boot keyboard or Windows Recovery Environment detected. The user may not be able to provide required input to unlock the volume.

FVE_E_NO_PREBOOT_KEYBOARD_OR_WINRE_DETECTED _HRESULT_TYPEDEF_(0x803100B6L)






// Group Policy settings require the creation of a startup PIN, but a pre-boot keyboard is not available on this device. The user may not be able to provide required input to unlock the volume.

FVE_E_POLICY_REQUIRES_STARTUP_PIN_ON_TOUCH_DEVICE _HRESULT_TYPEDEF_(0x803100B7L)






// Group Policy settings require the creation of a recovery password, but neither a pre-boot keyboard nor Windows Recovery Environment is available on this device. The user may not be able to provide required input to unlock the volume.

FVE_E_POLICY_REQUIRES_RECOVERY_PASSWORD_ON_TOUCH_DEVICE _HRESULT_TYPEDEF_(0x803100B8L)






// Wipe of free space is not currently taking place.

FVE_E_WIPE_CANCEL_NOT_APPLICABLE _HRESULT_TYPEDEF_(0x803100B9L)






// BitLocker cannot use Secure Boot for platform integrity because Secure Boot has been disabled.

FVE_E_SECUREBOOT_DISABLED        _HRESULT_TYPEDEF_(0x803100BAL)






// BitLocker cannot use Secure Boot for platform integrity because the Secure Boot configuration does not meet the requirements for BitLocker.

FVE_E_SECUREBOOT_CONFIGURATION_INVALID _HRESULT_TYPEDEF_(0x803100BBL)






// Your computer doesn't support BitLocker hardware-based encryption. Check with your computer manufacturer for firmware updates.

FVE_E_EDRIVE_DRY_RUN_FAILED      _HRESULT_TYPEDEF_(0x803100BCL)






// BitLocker cannot be enabled on the volume because it contains a Volume Shadow Copy. Remove all Volume Shadow Copies before encrypting the volume.

FVE_E_SHADOW_COPY_PRESENT        _HRESULT_TYPEDEF_(0x803100BDL)






// BitLocker Drive Encryption cannot be applied to this drive because the Group Policy setting for Enhanced Boot Configuration Data contains invalid data. Please have your system administrator resolve this invalid configuration before attempting to enable BitLocker.

FVE_E_POLICY_INVALID_ENHANCED_BCD_SETTINGS _HRESULT_TYPEDEF_(0x803100BEL)






// This PC's firmware is not capable of supporting hardware encryption.

FVE_E_EDRIVE_INCOMPATIBLE_FIRMWARE _HRESULT_TYPEDEF_(0x803100BFL)






// BitLocker has disabled password changes after too many failed requests. Click the link to reset the password as an administrator.

FVE_E_PROTECTOR_CHANGE_MAX_PASSPHRASE_CHANGE_ATTEMPTS_REACHED _HRESULT_TYPEDEF_(0x803100C0L)






// You must be logged on with an administrator account to change the password. Click the link to reset the password as an administrator.

FVE_E_PASSPHRASE_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED _HRESULT_TYPEDEF_(0x803100C1L)






// BitLocker cannot save the recovery password because the specified Microsoft account is Suspended.

FVE_E_LIVEID_ACCOUNT_SUSPENDED   _HRESULT_TYPEDEF_(0x803100C2L)






// BitLocker cannot save the recovery password because the specified Microsoft account is Blocked.

FVE_E_LIVEID_ACCOUNT_BLOCKED     _HRESULT_TYPEDEF_(0x803100C3L)






// This PC is not provisioned to support device encryption. Please enable BitLocker on all volumes to comply with device encryption policy.

FVE_E_NOT_PROVISIONED_ON_ALL_VOLUMES _HRESULT_TYPEDEF_(0x803100C4L)






// This PC cannot support device encryption because unencrypted fixed data volumes are present.

FVE_E_DE_FIXED_DATA_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x803100C5L)






// This PC does not meet the hardware requirements to support device encryption.

FVE_E_DE_HARDWARE_NOT_COMPLIANT  _HRESULT_TYPEDEF_(0x803100C6L)






// This PC cannot support device encryption because WinRE is not properly configured.

FVE_E_DE_WINRE_NOT_CONFIGURED    _HRESULT_TYPEDEF_(0x803100C7L)






// Protection is enabled on the volume but has been suspended. This is likely to have happened due to an update being applied to your system. Please try again after a reboot.

FVE_E_DE_PROTECTION_SUSPENDED    _HRESULT_TYPEDEF_(0x803100C8L)






// This PC is not provisioned to support device encryption.

FVE_E_DE_OS_VOLUME_NOT_PROTECTED _HRESULT_TYPEDEF_(0x803100C9L)






// Device Lock has been triggered due to too many incorrect password attempts.

FVE_E_DE_DEVICE_LOCKEDOUT        _HRESULT_TYPEDEF_(0x803100CAL)






// Protection has not been enabled on the volume. Enabling protection requires a connected account. If you already have a connected account and are seeing this error, please refer to the event log for more information.

FVE_E_DE_PROTECTION_NOT_YET_ENABLED _HRESULT_TYPEDEF_(0x803100CBL)






// Your PIN can only contain numbers from 0 to 9.

FVE_E_INVALID_PIN_CHARS_DETAILED _HRESULT_TYPEDEF_(0x803100CCL)






// BitLocker cannot use hardware replay protection because no counter is available on your PC.

FVE_E_DEVICE_LOCKOUT_COUNTER_UNAVAILABLE _HRESULT_TYPEDEF_(0x803100CDL)






// Device Lockout state validation failed due to counter mismatch.

FVE_E_DEVICELOCKOUT_COUNTER_MISMATCH _HRESULT_TYPEDEF_(0x803100CEL)






// The input buffer is too large.

FVE_E_BUFFER_TOO_LARGE           _HRESULT_TYPEDEF_(0x803100CFL)






// The target of an invocation does not support requested capability.

FVE_E_NO_SUCH_CAPABILITY_ON_TARGET _HRESULT_TYPEDEF_(0x803100D0L)






// Device encryption is currently blocked by this PC's configuration.

FVE_E_DE_PREVENTED_FOR_OS        _HRESULT_TYPEDEF_(0x803100D1L)






// This drive has been opted out of device encryption.

FVE_E_DE_VOLUME_OPTED_OUT        _HRESULT_TYPEDEF_(0x803100D2L)






// Device encryption isn't available for this drive.

FVE_E_DE_VOLUME_NOT_SUPPORTED    _HRESULT_TYPEDEF_(0x803100D3L)






// The encrypt on write mode for BitLocker is not supported in this version of Windows. You can turn on BitLocker without using the encrypt on write mode.

FVE_E_EOW_NOT_SUPPORTED_IN_VERSION _HRESULT_TYPEDEF_(0x803100D4L)






// Group policy prevents you from backing up your recovery password to Active Directory for this drive type. For more info, contact your system administrator.

FVE_E_ADBACKUP_NOT_ENABLED       _HRESULT_TYPEDEF_(0x803100D5L)






// Device encryption can't be turned off while this drive is being encrypted. Please try again later.

FVE_E_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT _HRESULT_TYPEDEF_(0x803100D6L)






// This action isn't supported because this drive isn't automatically managed with device encryption.

FVE_E_NOT_DE_VOLUME              _HRESULT_TYPEDEF_(0x803100D7L)






// BitLocker can't be suspended on this drive until the next restart.

FVE_E_PROTECTION_CANNOT_BE_DISABLED _HRESULT_TYPEDEF_(0x803100D8L)






// BitLocker Drive Encryption policy does not allow KSR operation with protected OS volume.

FVE_E_OSV_KSR_NOT_ALLOWED        _HRESULT_TYPEDEF_(0x803100D9L)






// Recovery Password Rotation cannot be performed because Active Directory Backup policy is not set to Required for OS drive.

FVE_E_AD_BACKUP_REQUIRED_POLICY_NOT_SET_OS_DRIVE _HRESULT_TYPEDEF_(0x803100DAL)






// Recovery Password Rotation cannot be performed because Active Directory Backup policy is not set to Required for Fixed drive.

FVE_E_AD_BACKUP_REQUIRED_POLICY_NOT_SET_FIXED_DRIVE _HRESULT_TYPEDEF_(0x803100DBL)






// Recovery Password Rotation cannot be performed because Active Directory Backup policy is not set to Required for Removable drive.

FVE_E_AD_BACKUP_REQUIRED_POLICY_NOT_SET_REMOVABLE_DRIVE _HRESULT_TYPEDEF_(0x803100DCL)






// Bitlocker Recovery Password rotation not supported.

FVE_E_KEY_ROTATION_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x803100DDL)






// An Instance of Server issued recovery password rotation already in Progress. No second RotateRecoveryPasswords request allowed within 1 hour interval.

FVE_E_EXECUTE_REQUEST_SENT_TOO_SOON _HRESULT_TYPEDEF_(0x803100DEL)






// Recovery Passwords Key Rotation is not Enabled.

FVE_E_KEY_ROTATION_NOT_ENABLED   _HRESULT_TYPEDEF_(0x803100DFL)






// Recovery Passwords Rotation could not be performed because the device is not joined to AAD or Hybrid.

FVE_E_DEVICE_NOT_JOINED          _HRESULT_TYPEDEF_(0x803100E0L)


// =======================================================
// Windows Filtering Platform Error Messages
// =======================================================






// The callout does not exist.

FWP_E_CALLOUT_NOT_FOUND          _HRESULT_TYPEDEF_(0x80320001L)






// The filter condition does not exist.

FWP_E_CONDITION_NOT_FOUND        _HRESULT_TYPEDEF_(0x80320002L)






// The filter does not exist.

FWP_E_FILTER_NOT_FOUND           _HRESULT_TYPEDEF_(0x80320003L)






// The layer does not exist.

FWP_E_LAYER_NOT_FOUND            _HRESULT_TYPEDEF_(0x80320004L)






// The provider does not exist.

FWP_E_PROVIDER_NOT_FOUND         _HRESULT_TYPEDEF_(0x80320005L)






// The provider context does not exist.

FWP_E_PROVIDER_CONTEXT_NOT_FOUND _HRESULT_TYPEDEF_(0x80320006L)






// The sublayer does not exist.

FWP_E_SUBLAYER_NOT_FOUND         _HRESULT_TYPEDEF_(0x80320007L)






// The object does not exist.

FWP_E_NOT_FOUND                  _HRESULT_TYPEDEF_(0x80320008L)






// An object with that GUID or LUID already exists.

FWP_E_ALREADY_EXISTS             _HRESULT_TYPEDEF_(0x80320009L)






// The object is referenced by other objects so cannot be deleted.

FWP_E_IN_USE                     _HRESULT_TYPEDEF_(0x8032000AL)






// The call is not allowed from within a dynamic session.

FWP_E_DYNAMIC_SESSION_IN_PROGRESS _HRESULT_TYPEDEF_(0x8032000BL)






// The call was made from the wrong session so cannot be completed.

FWP_E_WRONG_SESSION              _HRESULT_TYPEDEF_(0x8032000CL)






// The call must be made from within an explicit transaction.

FWP_E_NO_TXN_IN_PROGRESS         _HRESULT_TYPEDEF_(0x8032000DL)






// The call is not allowed from within an explicit transaction.

FWP_E_TXN_IN_PROGRESS            _HRESULT_TYPEDEF_(0x8032000EL)






// The explicit transaction has been forcibly cancelled.

FWP_E_TXN_ABORTED                _HRESULT_TYPEDEF_(0x8032000FL)






// The session has been cancelled.

FWP_E_SESSION_ABORTED            _HRESULT_TYPEDEF_(0x80320010L)






// The call is not allowed from within a read-only transaction.

FWP_E_INCOMPATIBLE_TXN           _HRESULT_TYPEDEF_(0x80320011L)






// The call timed out while waiting to acquire the transaction lock.

FWP_E_TIMEOUT                    _HRESULT_TYPEDEF_(0x80320012L)






// Collection of network diagnostic events is disabled.

FWP_E_NET_EVENTS_DISABLED        _HRESULT_TYPEDEF_(0x80320013L)






// The operation is not supported by the specified layer.

FWP_E_INCOMPATIBLE_LAYER         _HRESULT_TYPEDEF_(0x80320014L)






// The call is allowed for kernel-mode callers only.

FWP_E_KM_CLIENTS_ONLY            _HRESULT_TYPEDEF_(0x80320015L)






// The call tried to associate two objects with incompatible lifetimes.

FWP_E_LIFETIME_MISMATCH          _HRESULT_TYPEDEF_(0x80320016L)






// The object is built in so cannot be deleted.

FWP_E_BUILTIN_OBJECT             _HRESULT_TYPEDEF_(0x80320017L)






// The maximum number of callouts has been reached.

FWP_E_TOO_MANY_CALLOUTS          _HRESULT_TYPEDEF_(0x80320018L)






// A notification could not be delivered because a message queue is at its maximum capacity.

FWP_E_NOTIFICATION_DROPPED       _HRESULT_TYPEDEF_(0x80320019L)






// The traffic parameters do not match those for the security association context.

FWP_E_TRAFFIC_MISMATCH           _HRESULT_TYPEDEF_(0x8032001AL)






// The call is not allowed for the current security association state.

FWP_E_INCOMPATIBLE_SA_STATE      _HRESULT_TYPEDEF_(0x8032001BL)






// A required pointer is null.

FWP_E_NULL_POINTER               _HRESULT_TYPEDEF_(0x8032001CL)






// An enumerator is not valid.

FWP_E_INVALID_ENUMERATOR         _HRESULT_TYPEDEF_(0x8032001DL)






// The flags field contains an invalid value.

FWP_E_INVALID_FLAGS              _HRESULT_TYPEDEF_(0x8032001EL)






// A network mask is not valid.

FWP_E_INVALID_NET_MASK           _HRESULT_TYPEDEF_(0x8032001FL)






// An FWP_RANGE is not valid.

FWP_E_INVALID_RANGE              _HRESULT_TYPEDEF_(0x80320020L)






// The time interval is not valid.

FWP_E_INVALID_INTERVAL           _HRESULT_TYPEDEF_(0x80320021L)






// An array that must contain at least one element is zero length.

FWP_E_ZERO_LENGTH_ARRAY          _HRESULT_TYPEDEF_(0x80320022L)






// The displayData.name field cannot be null.

FWP_E_NULL_DISPLAY_NAME          _HRESULT_TYPEDEF_(0x80320023L)






// The action type is not one of the allowed action types for a filter.

FWP_E_INVALID_ACTION_TYPE        _HRESULT_TYPEDEF_(0x80320024L)






// The filter weight is not valid.

FWP_E_INVALID_WEIGHT             _HRESULT_TYPEDEF_(0x80320025L)






// A filter condition contains a match type that is not compatible with the operands.

FWP_E_MATCH_TYPE_MISMATCH        _HRESULT_TYPEDEF_(0x80320026L)






// An FWP_VALUE or FWPM_CONDITION_VALUE is of the wrong type.

FWP_E_TYPE_MISMATCH              _HRESULT_TYPEDEF_(0x80320027L)






// An integer value is outside the allowed range.

FWP_E_OUT_OF_BOUNDS              _HRESULT_TYPEDEF_(0x80320028L)






// A reserved field is non-zero.

FWP_E_RESERVED                   _HRESULT_TYPEDEF_(0x80320029L)






// A filter cannot contain multiple conditions operating on a single field.

FWP_E_DUPLICATE_CONDITION        _HRESULT_TYPEDEF_(0x8032002AL)






// A policy cannot contain the same keying module more than once.

FWP_E_DUPLICATE_KEYMOD           _HRESULT_TYPEDEF_(0x8032002BL)






// The action type is not compatible with the layer.

FWP_E_ACTION_INCOMPATIBLE_WITH_LAYER _HRESULT_TYPEDEF_(0x8032002CL)






// The action type is not compatible with the sublayer.

FWP_E_ACTION_INCOMPATIBLE_WITH_SUBLAYER _HRESULT_TYPEDEF_(0x8032002DL)






// The raw context or the provider context is not compatible with the layer.

FWP_E_CONTEXT_INCOMPATIBLE_WITH_LAYER _HRESULT_TYPEDEF_(0x8032002EL)






// The raw context or the provider context is not compatible with the callout.

FWP_E_CONTEXT_INCOMPATIBLE_WITH_CALLOUT _HRESULT_TYPEDEF_(0x8032002FL)






// The authentication method is not compatible with the policy type.

FWP_E_INCOMPATIBLE_AUTH_METHOD   _HRESULT_TYPEDEF_(0x80320030L)






// The Diffie-Hellman group is not compatible with the policy type.

FWP_E_INCOMPATIBLE_DH_GROUP      _HRESULT_TYPEDEF_(0x80320031L)






// An IKE policy cannot contain an Extended Mode policy.

FWP_E_EM_NOT_SUPPORTED           _HRESULT_TYPEDEF_(0x80320032L)






// The enumeration template or subscription will never match any objects.

FWP_E_NEVER_MATCH                _HRESULT_TYPEDEF_(0x80320033L)






// The provider context is of the wrong type.

FWP_E_PROVIDER_CONTEXT_MISMATCH  _HRESULT_TYPEDEF_(0x80320034L)






// The parameter is incorrect.

FWP_E_INVALID_PARAMETER          _HRESULT_TYPEDEF_(0x80320035L)






// The maximum number of sublayers has been reached.

FWP_E_TOO_MANY_SUBLAYERS         _HRESULT_TYPEDEF_(0x80320036L)






// The notification function for a callout returned an error.

FWP_E_CALLOUT_NOTIFICATION_FAILED _HRESULT_TYPEDEF_(0x80320037L)






// The IPsec authentication transform is not valid.

FWP_E_INVALID_AUTH_TRANSFORM     _HRESULT_TYPEDEF_(0x80320038L)






// The IPsec cipher transform is not valid.

FWP_E_INVALID_CIPHER_TRANSFORM   _HRESULT_TYPEDEF_(0x80320039L)






// The IPsec cipher transform is not compatible with the policy.

FWP_E_INCOMPATIBLE_CIPHER_TRANSFORM _HRESULT_TYPEDEF_(0x8032003AL)






// The combination of IPsec transform types is not valid.

FWP_E_INVALID_TRANSFORM_COMBINATION _HRESULT_TYPEDEF_(0x8032003BL)






// A policy cannot contain the same auth method more than once.

FWP_E_DUPLICATE_AUTH_METHOD      _HRESULT_TYPEDEF_(0x8032003CL)






// A tunnel endpoint configuration is invalid.

FWP_E_INVALID_TUNNEL_ENDPOINT    _HRESULT_TYPEDEF_(0x8032003DL)






// The WFP MAC Layers are not ready.

FWP_E_L2_DRIVER_NOT_READY        _HRESULT_TYPEDEF_(0x8032003EL)






// A key manager capable of key dictation is already registered

FWP_E_KEY_DICTATOR_ALREADY_REGISTERED _HRESULT_TYPEDEF_(0x8032003FL)






// A key manager dictated invalid keys

FWP_E_KEY_DICTATION_INVALID_KEYING_MATERIAL _HRESULT_TYPEDEF_(0x80320040L)






// The BFE IPsec Connection Tracking is disabled.

FWP_E_CONNECTIONS_DISABLED       _HRESULT_TYPEDEF_(0x80320041L)






// The DNS name is invalid.

FWP_E_INVALID_DNS_NAME           _HRESULT_TYPEDEF_(0x80320042L)






// The engine option is still enabled due to other configuration settings.

FWP_E_STILL_ON                   _HRESULT_TYPEDEF_(0x80320043L)






// The IKEEXT service is not running.  This service only runs when there is IPsec policy applied to the machine.

FWP_E_IKEEXT_NOT_RUNNING         _HRESULT_TYPEDEF_(0x80320044L)






// The packet should be dropped, no ICMP should be sent.

FWP_E_DROP_NOICMP                _HRESULT_TYPEDEF_(0x80320104L)


///////////////////////////////////////////////////
//                                               //
//       Web Services Platform Error Codes       //
//                                               //
///////////////////////////////////////////////////






// The function call is completing asynchronously.

WS_S_ASYNC                       _HRESULT_TYPEDEF_(0x003D0000L)






// There are no more messages available on the channel.

WS_S_END                         _HRESULT_TYPEDEF_(0x003D0001L)






// The input data was not in the expected format or did not have the expected value.

WS_E_INVALID_FORMAT              _HRESULT_TYPEDEF_(0x803D0000L)






// The operation could not be completed because the object is in a faulted state due to a previous error.

WS_E_OBJECT_FAULTED              _HRESULT_TYPEDEF_(0x803D0001L)






// The operation could not be completed because it would lead to numeric overflow.

WS_E_NUMERIC_OVERFLOW            _HRESULT_TYPEDEF_(0x803D0002L)






// The operation is not allowed due to the current state of the object.

WS_E_INVALID_OPERATION           _HRESULT_TYPEDEF_(0x803D0003L)






// The operation was aborted.

WS_E_OPERATION_ABORTED           _HRESULT_TYPEDEF_(0x803D0004L)






// Access was denied by the remote endpoint.

WS_E_ENDPOINT_ACCESS_DENIED      _HRESULT_TYPEDEF_(0x803D0005L)






// The operation did not complete within the time allotted.

WS_E_OPERATION_TIMED_OUT         _HRESULT_TYPEDEF_(0x803D0006L)






// The operation was abandoned.

WS_E_OPERATION_ABANDONED         _HRESULT_TYPEDEF_(0x803D0007L)






// A quota was exceeded.

WS_E_QUOTA_EXCEEDED              _HRESULT_TYPEDEF_(0x803D0008L)






// The information was not available in the specified language.

WS_E_NO_TRANSLATION_AVAILABLE    _HRESULT_TYPEDEF_(0x803D0009L)






// Security verification was not successful for the received data.

WS_E_SECURITY_VERIFICATION_FAILURE _HRESULT_TYPEDEF_(0x803D000AL)






// The address is already being used.

WS_E_ADDRESS_IN_USE              _HRESULT_TYPEDEF_(0x803D000BL)






// The address is not valid for this context.

WS_E_ADDRESS_NOT_AVAILABLE       _HRESULT_TYPEDEF_(0x803D000CL)






// The remote endpoint does not exist or could not be located.

WS_E_ENDPOINT_NOT_FOUND          _HRESULT_TYPEDEF_(0x803D000DL)






// The remote endpoint is not currently in service at this location.

WS_E_ENDPOINT_NOT_AVAILABLE      _HRESULT_TYPEDEF_(0x803D000EL)






// The remote endpoint could not process the request.

WS_E_ENDPOINT_FAILURE            _HRESULT_TYPEDEF_(0x803D000FL)






// The remote endpoint was not reachable.

WS_E_ENDPOINT_UNREACHABLE        _HRESULT_TYPEDEF_(0x803D0010L)






// The operation was not supported by the remote endpoint.

WS_E_ENDPOINT_ACTION_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x803D0011L)






// The remote endpoint is unable to process the request due to being overloaded.

WS_E_ENDPOINT_TOO_BUSY           _HRESULT_TYPEDEF_(0x803D0012L)






// A message containing a fault was received from the remote endpoint.

WS_E_ENDPOINT_FAULT_RECEIVED     _HRESULT_TYPEDEF_(0x803D0013L)






// The connection with the remote endpoint was terminated.

WS_E_ENDPOINT_DISCONNECTED       _HRESULT_TYPEDEF_(0x803D0014L)






// The HTTP proxy server could not process the request.

WS_E_PROXY_FAILURE               _HRESULT_TYPEDEF_(0x803D0015L)






// Access was denied by the HTTP proxy server.

WS_E_PROXY_ACCESS_DENIED         _HRESULT_TYPEDEF_(0x803D0016L)






// The requested feature is not available on this platform.

WS_E_NOT_SUPPORTED               _HRESULT_TYPEDEF_(0x803D0017L)






// The HTTP proxy server requires HTTP authentication scheme 'basic'.

WS_E_PROXY_REQUIRES_BASIC_AUTH   _HRESULT_TYPEDEF_(0x803D0018L)






// The HTTP proxy server requires HTTP authentication scheme 'digest'.

WS_E_PROXY_REQUIRES_DIGEST_AUTH  _HRESULT_TYPEDEF_(0x803D0019L)






// The HTTP proxy server requires HTTP authentication scheme 'NTLM'.

WS_E_PROXY_REQUIRES_NTLM_AUTH    _HRESULT_TYPEDEF_(0x803D001AL)






// The HTTP proxy server requires HTTP authentication scheme 'negotiate'.

WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH _HRESULT_TYPEDEF_(0x803D001BL)






// The remote endpoint requires HTTP authentication scheme 'basic'.

WS_E_SERVER_REQUIRES_BASIC_AUTH  _HRESULT_TYPEDEF_(0x803D001CL)






// The remote endpoint requires HTTP authentication scheme 'digest'.

WS_E_SERVER_REQUIRES_DIGEST_AUTH _HRESULT_TYPEDEF_(0x803D001DL)






// The remote endpoint requires HTTP authentication scheme 'NTLM'.

WS_E_SERVER_REQUIRES_NTLM_AUTH   _HRESULT_TYPEDEF_(0x803D001EL)






// The remote endpoint requires HTTP authentication scheme 'negotiate'.

WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH _HRESULT_TYPEDEF_(0x803D001FL)






// The endpoint address URL is invalid.

WS_E_INVALID_ENDPOINT_URL        _HRESULT_TYPEDEF_(0x803D0020L)






// Unrecognized error occurred in the Windows Web Services framework.

WS_E_OTHER                       _HRESULT_TYPEDEF_(0x803D0021L)






// A security token was rejected by the server because it has expired.

WS_E_SECURITY_TOKEN_EXPIRED      _HRESULT_TYPEDEF_(0x803D0022L)






// A security operation failed in the Windows Web Services framework.

WS_E_SECURITY_SYSTEM_FAILURE     _HRESULT_TYPEDEF_(0x803D0023L)



// NDIS error codes (ndis.sys)



#ifdef RC_INVOKED
_NDIS_ERROR_TYPEDEF_(_sc)  _sc
#else // RC_INVOKED
_NDIS_ERROR_TYPEDEF_(_sc)  (DWORD)(_sc)
#endif // RC_INVOKED






// The binding to the network interface is being closed.

ERROR_NDIS_INTERFACE_CLOSING     _NDIS_ERROR_TYPEDEF_(0x80340002L)






// An invalid version was specified.

ERROR_NDIS_BAD_VERSION           _NDIS_ERROR_TYPEDEF_(0x80340004L)






// An invalid characteristics table was used.

ERROR_NDIS_BAD_CHARACTERISTICS   _NDIS_ERROR_TYPEDEF_(0x80340005L)






// Failed to find the network interface or network interface is not ready.

ERROR_NDIS_ADAPTER_NOT_FOUND     _NDIS_ERROR_TYPEDEF_(0x80340006L)






// Failed to open the network interface.

ERROR_NDIS_OPEN_FAILED           _NDIS_ERROR_TYPEDEF_(0x80340007L)






// Network interface has encountered an internal unrecoverable failure.

ERROR_NDIS_DEVICE_FAILED         _NDIS_ERROR_TYPEDEF_(0x80340008L)






// The multicast list on the network interface is full.

ERROR_NDIS_MULTICAST_FULL        _NDIS_ERROR_TYPEDEF_(0x80340009L)






// An attempt was made to add a duplicate multicast address to the list.

ERROR_NDIS_MULTICAST_EXISTS      _NDIS_ERROR_TYPEDEF_(0x8034000AL)






// At attempt was made to remove a multicast address that was never added.

ERROR_NDIS_MULTICAST_NOT_FOUND   _NDIS_ERROR_TYPEDEF_(0x8034000BL)






// Netowork interface aborted the request.

ERROR_NDIS_REQUEST_ABORTED       _NDIS_ERROR_TYPEDEF_(0x8034000CL)






// Network interface can not process the request because it is being reset.

ERROR_NDIS_RESET_IN_PROGRESS     _NDIS_ERROR_TYPEDEF_(0x8034000DL)






// Netword interface does not support this request.

ERROR_NDIS_NOT_SUPPORTED         _NDIS_ERROR_TYPEDEF_(0x803400BBL)






// An attempt was made to send an invalid packet on a network interface.

ERROR_NDIS_INVALID_PACKET        _NDIS_ERROR_TYPEDEF_(0x8034000FL)






// Network interface is not ready to complete this operation.

ERROR_NDIS_ADAPTER_NOT_READY     _NDIS_ERROR_TYPEDEF_(0x80340011L)






// The length of the buffer submitted for this operation is not valid.

ERROR_NDIS_INVALID_LENGTH        _NDIS_ERROR_TYPEDEF_(0x80340014L)






// The data used for this operation is not valid.

ERROR_NDIS_INVALID_DATA          _NDIS_ERROR_TYPEDEF_(0x80340015L)






// The length of buffer submitted for this operation is too small.

ERROR_NDIS_BUFFER_TOO_SHORT      _NDIS_ERROR_TYPEDEF_(0x80340016L)






// Network interface does not support this OID (Object Identifier)

ERROR_NDIS_INVALID_OID           _NDIS_ERROR_TYPEDEF_(0x80340017L)






// The network interface has been removed.

ERROR_NDIS_ADAPTER_REMOVED       _NDIS_ERROR_TYPEDEF_(0x80340018L)






// Network interface does not support this media type.

ERROR_NDIS_UNSUPPORTED_MEDIA     _NDIS_ERROR_TYPEDEF_(0x80340019L)






// An attempt was made to remove a token ring group address that is in use by other components.

ERROR_NDIS_GROUP_ADDRESS_IN_USE  _NDIS_ERROR_TYPEDEF_(0x8034001AL)






// An attempt was made to map a file that can not be found.

ERROR_NDIS_FILE_NOT_FOUND        _NDIS_ERROR_TYPEDEF_(0x8034001BL)






// An error occurred while NDIS tried to map the file.

ERROR_NDIS_ERROR_READING_FILE    _NDIS_ERROR_TYPEDEF_(0x8034001CL)






// An attempt was made to map a file that is alreay mapped.

ERROR_NDIS_ALREADY_MAPPED        _NDIS_ERROR_TYPEDEF_(0x8034001DL)






// An attempt to allocate a hardware resource failed because the resource is used by another component.

ERROR_NDIS_RESOURCE_CONFLICT     _NDIS_ERROR_TYPEDEF_(0x8034001EL)






// The I/O operation failed because network media is disconnected or wireless access point is out of range.

ERROR_NDIS_MEDIA_DISCONNECTED    _NDIS_ERROR_TYPEDEF_(0x8034001FL)






// The network address used in the request is invalid.

ERROR_NDIS_INVALID_ADDRESS       _NDIS_ERROR_TYPEDEF_(0x80340022L)






// The specified request is not a valid operation for the target device.

ERROR_NDIS_INVALID_DEVICE_REQUEST _NDIS_ERROR_TYPEDEF_(0x80340010L)






// The offload operation on the network interface has been paused.

ERROR_NDIS_PAUSED                _NDIS_ERROR_TYPEDEF_(0x8034002AL)






// Network interface was not found.

ERROR_NDIS_INTERFACE_NOT_FOUND   _NDIS_ERROR_TYPEDEF_(0x8034002BL)






// The revision number specified in the structure is not supported.

ERROR_NDIS_UNSUPPORTED_REVISION  _NDIS_ERROR_TYPEDEF_(0x8034002CL)






// The specified port does not exist on this network interface.

ERROR_NDIS_INVALID_PORT          _NDIS_ERROR_TYPEDEF_(0x8034002DL)






// The current state of the specified port on this network interface does not support the requested operation.

ERROR_NDIS_INVALID_PORT_STATE    _NDIS_ERROR_TYPEDEF_(0x8034002EL)






// The miniport adapter is in low power state.

ERROR_NDIS_LOW_POWER_STATE       _NDIS_ERROR_TYPEDEF_(0x8034002FL)






// This operation requires the miniport adapter to be reinitialized.

ERROR_NDIS_REINIT_REQUIRED       _NDIS_ERROR_TYPEDEF_(0x80340030L)






// There are not enough queues to complete the operation.

ERROR_NDIS_NO_QUEUES             _NDIS_ERROR_TYPEDEF_(0x80340031L)



// NDIS error codes (802.11 wireless LAN)







// The wireless local area network interface is in auto configuration mode and doesn't support the requested parameter change operation.

ERROR_NDIS_DOT11_AUTO_CONFIG_ENABLED _NDIS_ERROR_TYPEDEF_(0x80342000L)






// The wireless local area network interface is busy and can not perform the requested operation.

ERROR_NDIS_DOT11_MEDIA_IN_USE    _NDIS_ERROR_TYPEDEF_(0x80342001L)






// The wireless local area network interface is powered down and doesn't support the requested operation.

ERROR_NDIS_DOT11_POWER_STATE_INVALID _NDIS_ERROR_TYPEDEF_(0x80342002L)






// The list of wake on LAN patterns is full.

ERROR_NDIS_PM_WOL_PATTERN_LIST_FULL _NDIS_ERROR_TYPEDEF_(0x80342003L)






// The list of low power protocol offloads is full.

ERROR_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL _NDIS_ERROR_TYPEDEF_(0x80342004L)






// The wireless local area network interface cannot start an AP on the specified channel right now.

ERROR_NDIS_DOT11_AP_CHANNEL_CURRENTLY_NOT_AVAILABLE _NDIS_ERROR_TYPEDEF_(0x80342005L)






// The wireless local area network interface cannot start an AP on the specified band right now.

ERROR_NDIS_DOT11_AP_BAND_CURRENTLY_NOT_AVAILABLE _NDIS_ERROR_TYPEDEF_(0x80342006L)






// The wireless local area network interface cannot start an AP on this channel due to regulatory reasons.

ERROR_NDIS_DOT11_AP_CHANNEL_NOT_ALLOWED _NDIS_ERROR_TYPEDEF_(0x80342007L)






// The wireless local area network interface cannot start an AP on this band due to regulatory reasons.

ERROR_NDIS_DOT11_AP_BAND_NOT_ALLOWED _NDIS_ERROR_TYPEDEF_(0x80342008L)


// NDIS informational code (ndis.sys)







// The request will be completed later by NDIS status indication.

ERROR_NDIS_INDICATION_REQUIRED   _NDIS_ERROR_TYPEDEF_(0x00340001L)


// NDIS Chimney Offload codes (ndis.sys)







// The TCP connection is not offloadable because of a local policy setting.

ERROR_NDIS_OFFLOAD_POLICY        _NDIS_ERROR_TYPEDEF_(0xC034100FL)






// The TCP connection is not offloadable by the Chimney Offload target.

ERROR_NDIS_OFFLOAD_CONNECTION_REJECTED _NDIS_ERROR_TYPEDEF_(0xC0341012L)






// The IP Path object is not in an offloadable state.

ERROR_NDIS_OFFLOAD_PATH_REJECTED _NDIS_ERROR_TYPEDEF_(0xC0341013L)


// Hypervisor error codes







// The hypervisor does not support the operation because the specified hypercall code is not supported.

ERROR_HV_INVALID_HYPERCALL_CODE  _NDIS_ERROR_TYPEDEF_(0xC0350002L)






// The hypervisor does not support the operation because the encoding for the hypercall input register is not supported.

ERROR_HV_INVALID_HYPERCALL_INPUT _NDIS_ERROR_TYPEDEF_(0xC0350003L)






// The hypervisor could not perform the operation because a parameter has an invalid alignment.

ERROR_HV_INVALID_ALIGNMENT       _NDIS_ERROR_TYPEDEF_(0xC0350004L)






// The hypervisor could not perform the operation because an invalid parameter was specified.

ERROR_HV_INVALID_PARAMETER       _NDIS_ERROR_TYPEDEF_(0xC0350005L)






// Access to the specified object was denied.

ERROR_HV_ACCESS_DENIED           _NDIS_ERROR_TYPEDEF_(0xC0350006L)






// The hypervisor could not perform the operation because the partition is entering or in an invalid state.

ERROR_HV_INVALID_PARTITION_STATE _NDIS_ERROR_TYPEDEF_(0xC0350007L)






// The operation is not allowed in the current state.

ERROR_HV_OPERATION_DENIED        _NDIS_ERROR_TYPEDEF_(0xC0350008L)






// The hypervisor does not recognize the specified partition property.

ERROR_HV_UNKNOWN_PROPERTY        _NDIS_ERROR_TYPEDEF_(0xC0350009L)






// The specified value of a partition property is out of range or violates an invariant.

ERROR_HV_PROPERTY_VALUE_OUT_OF_RANGE _NDIS_ERROR_TYPEDEF_(0xC035000AL)






// There is not enough memory in the hypervisor pool to complete the operation.

ERROR_HV_INSUFFICIENT_MEMORY     _NDIS_ERROR_TYPEDEF_(0xC035000BL)






// The maximum partition depth has been exceeded for the partition hierarchy.

ERROR_HV_PARTITION_TOO_DEEP      _NDIS_ERROR_TYPEDEF_(0xC035000CL)






// A partition with the specified partition Id does not exist.

ERROR_HV_INVALID_PARTITION_ID    _NDIS_ERROR_TYPEDEF_(0xC035000DL)






// The hypervisor could not perform the operation because the specified VP index is invalid.

ERROR_HV_INVALID_VP_INDEX        _NDIS_ERROR_TYPEDEF_(0xC035000EL)






// The hypervisor could not perform the operation because the specified port identifier is invalid.

ERROR_HV_INVALID_PORT_ID         _NDIS_ERROR_TYPEDEF_(0xC0350011L)






// The hypervisor could not perform the operation because the specified connection identifier is invalid.

ERROR_HV_INVALID_CONNECTION_ID   _NDIS_ERROR_TYPEDEF_(0xC0350012L)






// Not enough buffers were supplied to send a message.

ERROR_HV_INSUFFICIENT_BUFFERS    _NDIS_ERROR_TYPEDEF_(0xC0350013L)






// The previous virtual interrupt has not been acknowledged.

ERROR_HV_NOT_ACKNOWLEDGED        _NDIS_ERROR_TYPEDEF_(0xC0350014L)






// A virtual processor is not in the correct state for the indicated operation.

ERROR_HV_INVALID_VP_STATE        _NDIS_ERROR_TYPEDEF_(0xC0350015L)






// The previous virtual interrupt has already been acknowledged.

ERROR_HV_ACKNOWLEDGED            _NDIS_ERROR_TYPEDEF_(0xC0350016L)






// The indicated partition is not in a valid state for saving or restoring.

ERROR_HV_INVALID_SAVE_RESTORE_STATE _NDIS_ERROR_TYPEDEF_(0xC0350017L)






// The hypervisor could not complete the operation because a required feature of the synthetic interrupt controller (SynIC) was disabled.

ERROR_HV_INVALID_SYNIC_STATE     _NDIS_ERROR_TYPEDEF_(0xC0350018L)






// The hypervisor could not perform the operation because the object or value was either already in use or being used for a purpose that would not permit completing the operation.

ERROR_HV_OBJECT_IN_USE           _NDIS_ERROR_TYPEDEF_(0xC0350019L)






// The proximity domain information is invalid.

ERROR_HV_INVALID_PROXIMITY_DOMAIN_INFO _NDIS_ERROR_TYPEDEF_(0xC035001AL)






// An attempt to retrieve debugging data failed because none was available.

ERROR_HV_NO_DATA                 _NDIS_ERROR_TYPEDEF_(0xC035001BL)






// The physical connection being used for debugging has not recorded any receive activity since the last operation.

ERROR_HV_INACTIVE                _NDIS_ERROR_TYPEDEF_(0xC035001CL)






// There are not enough resources to complete the operation.

ERROR_HV_NO_RESOURCES            _NDIS_ERROR_TYPEDEF_(0xC035001DL)






// A hypervisor feature is not available to the user.

ERROR_HV_FEATURE_UNAVAILABLE     _NDIS_ERROR_TYPEDEF_(0xC035001EL)






// The specified buffer was too small to contain all of the requested data.

ERROR_HV_INSUFFICIENT_BUFFER     _NDIS_ERROR_TYPEDEF_(0xC0350033L)






// The maximum number of domains supported by the platform I/O remapping hardware is currently in use. No domains are available to assign this device to this partition.

ERROR_HV_INSUFFICIENT_DEVICE_DOMAINS _NDIS_ERROR_TYPEDEF_(0xC0350038L)






// Validation of CPUID data of the processor failed.

ERROR_HV_CPUID_FEATURE_VALIDATION _NDIS_ERROR_TYPEDEF_(0xC035003CL)






// Validation of XSAVE CPUID data of the processor failed.

ERROR_HV_CPUID_XSAVE_FEATURE_VALIDATION _NDIS_ERROR_TYPEDEF_(0xC035003DL)






// Processor did not respond within the timeout period.

ERROR_HV_PROCESSOR_STARTUP_TIMEOUT _NDIS_ERROR_TYPEDEF_(0xC035003EL)






// SMX has been enabled in the BIOS.

ERROR_HV_SMX_ENABLED             _NDIS_ERROR_TYPEDEF_(0xC035003FL)






// The hypervisor could not perform the operation because the specified LP index is invalid.

ERROR_HV_INVALID_LP_INDEX        _NDIS_ERROR_TYPEDEF_(0xC0350041L)






// The supplied register value is invalid.

ERROR_HV_INVALID_REGISTER_VALUE  _NDIS_ERROR_TYPEDEF_(0xC0350050L)






// The supplied virtual trust level is not in the correct state to perform the requested operation.

ERROR_HV_INVALID_VTL_STATE       _NDIS_ERROR_TYPEDEF_(0xC0350051L)






// No execute feature (NX) is not present or not enabled in the BIOS.

ERROR_HV_NX_NOT_DETECTED         _NDIS_ERROR_TYPEDEF_(0xC0350055L)






// The supplied device ID is invalid.

ERROR_HV_INVALID_DEVICE_ID       _NDIS_ERROR_TYPEDEF_(0xC0350057L)






// The operation is not allowed in the current device state.

ERROR_HV_INVALID_DEVICE_STATE    _NDIS_ERROR_TYPEDEF_(0xC0350058L)






// The device had pending page requests which were discarded.

ERROR_HV_PENDING_PAGE_REQUESTS   _NDIS_ERROR_TYPEDEF_(0x00350059L)






// The supplied page request specifies a memory access that the guest does not have permissions to perform.

ERROR_HV_PAGE_REQUEST_INVALID    _NDIS_ERROR_TYPEDEF_(0xC0350060L)






// A CPU group with the specified CPU group Id does not exist.

ERROR_HV_INVALID_CPU_GROUP_ID    _NDIS_ERROR_TYPEDEF_(0xC035006FL)






// The hypervisor could not perform the operation because the CPU group is entering or in an invalid state.

ERROR_HV_INVALID_CPU_GROUP_STATE _NDIS_ERROR_TYPEDEF_(0xC0350070L)






// The requested operation failed.

ERROR_HV_OPERATION_FAILED        _NDIS_ERROR_TYPEDEF_(0xC0350071L)






// The hypervisor could not perform the operation because it is not allowed with nested virtualization active.

ERROR_HV_NOT_ALLOWED_WITH_NESTED_VIRT_ACTIVE _NDIS_ERROR_TYPEDEF_(0xC0350072L)






// There is not enough memory in the root partition's pool to complete the operation.

ERROR_HV_INSUFFICIENT_ROOT_MEMORY _NDIS_ERROR_TYPEDEF_(0xC0350073L)






// No hypervisor is present on this system.

ERROR_HV_NOT_PRESENT             _NDIS_ERROR_TYPEDEF_(0xC0351000L)


// Virtualization error codes - these codes are used by the Virtualization Infrastructure Driver (VID) and other components
//                              of the virtualization stack.

// VID errors (0x0001 - 0x00ff)







// The handler for the virtualization infrastructure driver is already registered. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_DUPLICATE_HANDLER      _NDIS_ERROR_TYPEDEF_(0xC0370001L)






// The number of registered handlers for the virtualization infrastructure driver exceeded the maximum. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_TOO_MANY_HANDLERS      _NDIS_ERROR_TYPEDEF_(0xC0370002L)






// The message queue for the virtualization infrastructure driver is full and cannot accept new messages. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_QUEUE_FULL             _NDIS_ERROR_TYPEDEF_(0xC0370003L)






// No handler exists to handle the message for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_HANDLER_NOT_PRESENT    _NDIS_ERROR_TYPEDEF_(0xC0370004L)






// The name of the partition or message queue for the virtualization infrastructure driver is invalid. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_INVALID_OBJECT_NAME    _NDIS_ERROR_TYPEDEF_(0xC0370005L)






// The partition name of the virtualization infrastructure driver exceeds the maximum.

ERROR_VID_PARTITION_NAME_TOO_LONG _NDIS_ERROR_TYPEDEF_(0xC0370006L)






// The message queue name of the virtualization infrastructure driver exceeds the maximum.

ERROR_VID_MESSAGE_QUEUE_NAME_TOO_LONG _NDIS_ERROR_TYPEDEF_(0xC0370007L)






// Cannot create the partition for the virtualization infrastructure driver because another partition with the same name already exists.

ERROR_VID_PARTITION_ALREADY_EXISTS _NDIS_ERROR_TYPEDEF_(0xC0370008L)






// The virtualization infrastructure driver has encountered an error. The requested partition does not exist. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_PARTITION_DOES_NOT_EXIST _NDIS_ERROR_TYPEDEF_(0xC0370009L)






// The virtualization infrastructure driver has encountered an error. Could not find the requested partition. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_PARTITION_NAME_NOT_FOUND _NDIS_ERROR_TYPEDEF_(0xC037000AL)






// A message queue with the same name already exists for the virtualization infrastructure driver.

ERROR_VID_MESSAGE_QUEUE_ALREADY_EXISTS _NDIS_ERROR_TYPEDEF_(0xC037000BL)






// The memory block page for the virtualization infrastructure driver cannot be mapped because the page map limit has been reached. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT _NDIS_ERROR_TYPEDEF_(0xC037000CL)






// The memory block for the virtualization infrastructure driver is still being used and cannot be destroyed.

ERROR_VID_MB_STILL_REFERENCED    _NDIS_ERROR_TYPEDEF_(0xC037000DL)






// Cannot unlock the page array for the guest operating system memory address because it does not match a previous lock request. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_CHILD_GPA_PAGE_SET_CORRUPTED _NDIS_ERROR_TYPEDEF_(0xC037000EL)






// The non-uniform memory access (NUMA) node settings do not match the system NUMA topology. In order to start the virtual machine, you will need to modify the NUMA configuration.

ERROR_VID_INVALID_NUMA_SETTINGS  _NDIS_ERROR_TYPEDEF_(0xC037000FL)






// The non-uniform memory access (NUMA) node index does not match a valid index in the system NUMA topology.

ERROR_VID_INVALID_NUMA_NODE_INDEX _NDIS_ERROR_TYPEDEF_(0xC0370010L)






// The memory block for the virtualization infrastructure driver is already associated with a message queue.

ERROR_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED _NDIS_ERROR_TYPEDEF_(0xC0370011L)






// The handle is not a valid memory block handle for the virtualization infrastructure driver.

ERROR_VID_INVALID_MEMORY_BLOCK_HANDLE _NDIS_ERROR_TYPEDEF_(0xC0370012L)






// The request exceeded the memory block page limit for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_PAGE_RANGE_OVERFLOW    _NDIS_ERROR_TYPEDEF_(0xC0370013L)






// The handle is not a valid message queue handle for the virtualization infrastructure driver.

ERROR_VID_INVALID_MESSAGE_QUEUE_HANDLE _NDIS_ERROR_TYPEDEF_(0xC0370014L)






// The handle is not a valid page range handle for the virtualization infrastructure driver.

ERROR_VID_INVALID_GPA_RANGE_HANDLE _NDIS_ERROR_TYPEDEF_(0xC0370015L)






// Cannot install client notifications because no message queue for the virtualization infrastructure driver is associated with the memory block.

ERROR_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE _NDIS_ERROR_TYPEDEF_(0xC0370016L)






// The request to lock or map a memory block page failed because the virtualization infrastructure driver memory block limit has been reached. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED _NDIS_ERROR_TYPEDEF_(0xC0370017L)






// The handle is not a valid parent partition mapping handle for the virtualization infrastructure driver.

ERROR_VID_INVALID_PPM_HANDLE     _NDIS_ERROR_TYPEDEF_(0xC0370018L)






// Notifications cannot be created on the memory block because it is use.

ERROR_VID_MBPS_ARE_LOCKED        _NDIS_ERROR_TYPEDEF_(0xC0370019L)






// The message queue for the virtualization infrastructure driver has been closed. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_MESSAGE_QUEUE_CLOSED   _NDIS_ERROR_TYPEDEF_(0xC037001AL)






// Cannot add a virtual processor to the partition because the maximum has been reached.

ERROR_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED _NDIS_ERROR_TYPEDEF_(0xC037001BL)






// Cannot stop the virtual processor immediately because of a pending intercept.

ERROR_VID_STOP_PENDING           _NDIS_ERROR_TYPEDEF_(0xC037001CL)






// Invalid state for the virtual processor. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_INVALID_PROCESSOR_STATE _NDIS_ERROR_TYPEDEF_(0xC037001DL)






// The maximum number of kernel mode clients for the virtualization infrastructure driver has been reached. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT _NDIS_ERROR_TYPEDEF_(0xC037001EL)






// This kernel mode interface for the virtualization infrastructure driver has already been initialized. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_KM_INTERFACE_ALREADY_INITIALIZED _NDIS_ERROR_TYPEDEF_(0xC037001FL)






// Cannot set or reset the memory block property more than once for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_MB_PROPERTY_ALREADY_SET_RESET _NDIS_ERROR_TYPEDEF_(0xC0370020L)






// The memory mapped I/O for this page range no longer exists. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_MMIO_RANGE_DESTROYED   _NDIS_ERROR_TYPEDEF_(0xC0370021L)






// The lock or unlock request uses an invalid guest operating system memory address. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_INVALID_CHILD_GPA_PAGE_SET _NDIS_ERROR_TYPEDEF_(0xC0370022L)






// Cannot destroy or reuse the reserve page set for the virtualization infrastructure driver because it is in use. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_RESERVE_PAGE_SET_IS_BEING_USED _NDIS_ERROR_TYPEDEF_(0xC0370023L)






// The reserve page set for the virtualization infrastructure driver is too small to use in the lock request. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_RESERVE_PAGE_SET_TOO_SMALL _NDIS_ERROR_TYPEDEF_(0xC0370024L)






// Cannot lock or map the memory block page for the virtualization infrastructure driver because it has already been locked using a reserve page set page. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE _NDIS_ERROR_TYPEDEF_(0xC0370025L)






// Cannot create the memory block for the virtualization infrastructure driver because the requested number of pages exceeded the limit. Restarting the virtual machine may fix the problem. If the problem persists, try restarting the physical computer.

ERROR_VID_MBP_COUNT_EXCEEDED_LIMIT _NDIS_ERROR_TYPEDEF_(0xC0370026L)






// Cannot restore this virtual machine because the saved state data cannot be read. Delete the saved state data and then try to start the virtual machine.

ERROR_VID_SAVED_STATE_CORRUPT    _NDIS_ERROR_TYPEDEF_(0xC0370027L)






// Cannot restore this virtual machine because an item read from the saved state data is not recognized. Delete the saved state data and then try to start the virtual machine.

ERROR_VID_SAVED_STATE_UNRECOGNIZED_ITEM _NDIS_ERROR_TYPEDEF_(0xC0370028L)






// Cannot restore this virtual machine to the saved state because of hypervisor incompatibility. Delete the saved state data and then try to start the virtual machine.

ERROR_VID_SAVED_STATE_INCOMPATIBLE _NDIS_ERROR_TYPEDEF_(0xC0370029L)






// The specified VTL does not have the permission to access the resource.

ERROR_VID_VTL_ACCESS_DENIED      _NDIS_ERROR_TYPEDEF_(0xC037002AL)


// Host compute service errors (0x0100-0x01ff)






// The virtual machine or container exited unexpectedly while starting.

ERROR_VMCOMPUTE_TERMINATED_DURING_START _NDIS_ERROR_TYPEDEF_(0xC0370100L)






// The container operating system does not match the host operating system.

ERROR_VMCOMPUTE_IMAGE_MISMATCH   _NDIS_ERROR_TYPEDEF_(0xC0370101L)






// The virtual machine could not be started because a required feature is not installed.

ERROR_VMCOMPUTE_HYPERV_NOT_INSTALLED _NDIS_ERROR_TYPEDEF_(0xC0370102L)






// The call to start an asynchronous operation succeeded and the operation is performed in the background.

ERROR_VMCOMPUTE_OPERATION_PENDING _NDIS_ERROR_TYPEDEF_(0xC0370103L)






// The supported number of notification callbacks has been exceeded.

ERROR_VMCOMPUTE_TOO_MANY_NOTIFICATIONS _NDIS_ERROR_TYPEDEF_(0xC0370104L)






// The requested virtual machine or container operation is not valid in the current state.

ERROR_VMCOMPUTE_INVALID_STATE    _NDIS_ERROR_TYPEDEF_(0xC0370105L)






// The virtual machine or container exited unexpectedly.

ERROR_VMCOMPUTE_UNEXPECTED_EXIT  _NDIS_ERROR_TYPEDEF_(0xC0370106L)






// The virtual machine or container was forcefully exited.

ERROR_VMCOMPUTE_TERMINATED       _NDIS_ERROR_TYPEDEF_(0xC0370107L)






// A connection could not be established with the container or virtual machine.

ERROR_VMCOMPUTE_CONNECT_FAILED   _NDIS_ERROR_TYPEDEF_(0xC0370108L)






// The operation timed out because a response was not received from the virtual machine or container.

ERROR_VMCOMPUTE_TIMEOUT          _NDIS_ERROR_TYPEDEF_(0xC0370109L)






// The connection with the virtual machine or container was closed.

ERROR_VMCOMPUTE_CONNECTION_CLOSED _NDIS_ERROR_TYPEDEF_(0xC037010AL)






// An unknown internal message was received by the virtual machine or container.

ERROR_VMCOMPUTE_UNKNOWN_MESSAGE  _NDIS_ERROR_TYPEDEF_(0xC037010BL)






// The virtual machine or container does not support an available version of the communication protocol with the host.

ERROR_VMCOMPUTE_UNSUPPORTED_PROTOCOL_VERSION _NDIS_ERROR_TYPEDEF_(0xC037010CL)






// The virtual machine or container JSON document is invalid.

ERROR_VMCOMPUTE_INVALID_JSON     _NDIS_ERROR_TYPEDEF_(0xC037010DL)






// A virtual machine or container with the specified identifier does not exist.

ERROR_VMCOMPUTE_SYSTEM_NOT_FOUND _NDIS_ERROR_TYPEDEF_(0xC037010EL)






// A virtual machine or container with the specified identifier already exists.

ERROR_VMCOMPUTE_SYSTEM_ALREADY_EXISTS _NDIS_ERROR_TYPEDEF_(0xC037010FL)






// The virtual machine or container with the specified identifier is not running.

ERROR_VMCOMPUTE_SYSTEM_ALREADY_STOPPED _NDIS_ERROR_TYPEDEF_(0xC0370110L)






// A communication protocol error has occurred between the virtual machine or container and the host.

ERROR_VMCOMPUTE_PROTOCOL_ERROR   _NDIS_ERROR_TYPEDEF_(0xC0370111L)






// The container image contains a layer with an unrecognized format.

ERROR_VMCOMPUTE_INVALID_LAYER    _NDIS_ERROR_TYPEDEF_(0xC0370112L)






// To use this container image, you must join the Windows Insider Program. Please see https://go.microsoft.com/fwlink/?linkid=850659 for more information.

ERROR_VMCOMPUTE_WINDOWS_INSIDER_REQUIRED _NDIS_ERROR_TYPEDEF_(0xC0370113L)


// Host Compute System error codes (0x0100-0x01ff HRESULT codes)






// The virtual machine or container exited unexpectedly while starting.

HCS_E_TERMINATED_DURING_START    _HRESULT_TYPEDEF_(0x80370100L)






// The container operating system does not match the host operating system.

HCS_E_IMAGE_MISMATCH             _HRESULT_TYPEDEF_(0x80370101L)






// The virtual machine could not be started because a required feature is not installed.

HCS_E_HYPERV_NOT_INSTALLED       _HRESULT_TYPEDEF_(0x80370102L)






// The requested virtual machine or container operation is not valid in the current state.

HCS_E_INVALID_STATE              _HRESULT_TYPEDEF_(0x80370105L)






// The virtual machine or container exited unexpectedly.

HCS_E_UNEXPECTED_EXIT            _HRESULT_TYPEDEF_(0x80370106L)






// The virtual machine or container was forcefully exited.

HCS_E_TERMINATED                 _HRESULT_TYPEDEF_(0x80370107L)






// A connection could not be established with the container or virtual machine.

HCS_E_CONNECT_FAILED             _HRESULT_TYPEDEF_(0x80370108L)






// The operation timed out because a response was not received from the virtual machine or container.

HCS_E_CONNECTION_TIMEOUT         _HRESULT_TYPEDEF_(0x80370109L)






// The connection with the virtual machine or container was closed.

HCS_E_CONNECTION_CLOSED          _HRESULT_TYPEDEF_(0x8037010AL)






// An unknown internal message was received by the virtual machine or container.

HCS_E_UNKNOWN_MESSAGE            _HRESULT_TYPEDEF_(0x8037010BL)






// The virtual machine or container does not support an available version of the communication protocol with the host.

HCS_E_UNSUPPORTED_PROTOCOL_VERSION _HRESULT_TYPEDEF_(0x8037010CL)






// The virtual machine or container JSON document is invalid.

HCS_E_INVALID_JSON               _HRESULT_TYPEDEF_(0x8037010DL)






// A virtual machine or container with the specified identifier does not exist.

HCS_E_SYSTEM_NOT_FOUND           _HRESULT_TYPEDEF_(0x8037010EL)






// A virtual machine or container with the specified identifier already exists.

HCS_E_SYSTEM_ALREADY_EXISTS      _HRESULT_TYPEDEF_(0x8037010FL)






// The virtual machine or container with the specified identifier is not running.

HCS_E_SYSTEM_ALREADY_STOPPED     _HRESULT_TYPEDEF_(0x80370110L)






// A communication protocol error has occurred between the virtual machine or container and the host.

HCS_E_PROTOCOL_ERROR             _HRESULT_TYPEDEF_(0x80370111L)






// The container image contains a layer with an unrecognized format.

HCS_E_INVALID_LAYER              _HRESULT_TYPEDEF_(0x80370112L)






// To use this container image, you must join the Windows Insider Program. Please see https://go.microsoft.com/fwlink/?linkid=850659 for more information.

HCS_E_WINDOWS_INSIDER_REQUIRED   _HRESULT_TYPEDEF_(0x80370113L)






// The operation could not be started because a required feature is not installed.

HCS_E_SERVICE_NOT_AVAILABLE      _HRESULT_TYPEDEF_(0x80370114L)






// The operation has not started.

HCS_E_OPERATION_NOT_STARTED      _HRESULT_TYPEDEF_(0x80370115L)






// The operation is already running.

HCS_E_OPERATION_ALREADY_STARTED  _HRESULT_TYPEDEF_(0x80370116L)






// The operation is still running.

HCS_E_OPERATION_PENDING          _HRESULT_TYPEDEF_(0x80370117L)






// The operation did not complete in time.

HCS_E_OPERATION_TIMEOUT          _HRESULT_TYPEDEF_(0x80370118L)






// An event callback has already been registered on this handle.

HCS_E_OPERATION_SYSTEM_CALLBACK_ALREADY_SET _HRESULT_TYPEDEF_(0x80370119L)






// Not enough memory available to return the result of the operation.

HCS_E_OPERATION_RESULT_ALLOCATION_FAILED _HRESULT_TYPEDEF_(0x8037011AL)






// Insufficient privileges. Only administrators or users that are members of the Hyper-V Administrators user group are permitted to access virtual machines or containers. To add yourself to the Hyper-V Administrators user group, please see https://aka.ms/hcsadmin for more information.

HCS_E_ACCESS_DENIED              _HRESULT_TYPEDEF_(0x8037011BL)






// The virtual machine or container reported a critical error and was stopped or restarted.

HCS_E_GUEST_CRITICAL_ERROR       _HRESULT_TYPEDEF_(0x8037011CL)


// Virtual networking errors (0x0200-0x02ff)






// A virtual switch with the given name was not found.

ERROR_VNET_VIRTUAL_SWITCH_NAME_NOT_FOUND _NDIS_ERROR_TYPEDEF_(0xC0370200L)


// VID warnings (0x0000 - 0x00ff):






// A virtual machine is running with its memory allocated across multiple NUMA nodes. This does not indicate a problem unless the performance of your virtual machine is unusually slow. If you are experiencing performance problems, you may need to modify the NUMA configuration.

ERROR_VID_REMOTE_NODE_PARENT_GPA_PAGES_USED _NDIS_ERROR_TYPEDEF_(0x80370001L)


// User-mode Hypervisor API error codes (0x0300-0x03ff)






// The specified capability does not exist.

WHV_E_UNKNOWN_CAPABILITY         _HRESULT_TYPEDEF_(0x80370300L)






// The specified buffer is too small for the requested data.

WHV_E_INSUFFICIENT_BUFFER        _HRESULT_TYPEDEF_(0x80370301L)






// The specified property does not exist.

WHV_E_UNKNOWN_PROPERTY           _HRESULT_TYPEDEF_(0x80370302L)






// The configuration of the hypervisor on this system is not supported.

WHV_E_UNSUPPORTED_HYPERVISOR_CONFIG _HRESULT_TYPEDEF_(0x80370303L)






// The configuration of the partition is not valid.

WHV_E_INVALID_PARTITION_CONFIG   _HRESULT_TYPEDEF_(0x80370304L)






// The specified GPA range was not found.

WHV_E_GPA_RANGE_NOT_FOUND        _HRESULT_TYPEDEF_(0x80370305L)






// A virtual processor with the specified index already exists.

WHV_E_VP_ALREADY_EXISTS          _HRESULT_TYPEDEF_(0x80370306L)






// A virtual processor with the specified index does not exist.

WHV_E_VP_DOES_NOT_EXIST          _HRESULT_TYPEDEF_(0x80370307L)






// The virtual processor is not in the correct state to perform the requested operation.

WHV_E_INVALID_VP_STATE           _HRESULT_TYPEDEF_(0x80370308L)






// A virtual processor register with the specified name does not exist.

WHV_E_INVALID_VP_REGISTER_NAME   _HRESULT_TYPEDEF_(0x80370309L)


// Virtual storage error codes (0x0400-0x04ff)






// Cannot restore this virtual machine because a file read from the vSMB saved state data could not be found. Delete the saved state data and then try to start the virtual machine.

ERROR_VSMB_SAVED_STATE_FILE_NOT_FOUND _NDIS_ERROR_TYPEDEF_(0xC0370400L)






// Cannot restore this virtual machine because the vSMB saved state data cannot be read. Delete the saved state data and then try to start the virtual machine.

ERROR_VSMB_SAVED_STATE_CORRUPT   _NDIS_ERROR_TYPEDEF_(0xC0370401L)



// Volume manager error codes mapped from status codes



// WARNINGS






// The regeneration operation was not able to copy all data from the active plexes due to bad sectors.

ERROR_VOLMGR_INCOMPLETE_REGENERATION _NDIS_ERROR_TYPEDEF_(0x80380001L)






// One or more disks were not fully migrated to the target pack. They may or may not require reimport after fixing the hardware problems.

ERROR_VOLMGR_INCOMPLETE_DISK_MIGRATION _NDIS_ERROR_TYPEDEF_(0x80380002L)


// ERRORS






// The configuration database is full.

ERROR_VOLMGR_DATABASE_FULL       _NDIS_ERROR_TYPEDEF_(0xC0380001L)






// The configuration data on the disk is corrupted.

ERROR_VOLMGR_DISK_CONFIGURATION_CORRUPTED _NDIS_ERROR_TYPEDEF_(0xC0380002L)






// The configuration on the disk is not insync with the in-memory configuration.

ERROR_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC _NDIS_ERROR_TYPEDEF_(0xC0380003L)






// A majority of disks failed to be updated with the new configuration.

ERROR_VOLMGR_PACK_CONFIG_UPDATE_FAILED _NDIS_ERROR_TYPEDEF_(0xC0380004L)






// The disk contains non-simple volumes.

ERROR_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME _NDIS_ERROR_TYPEDEF_(0xC0380005L)






// The same disk was specified more than once in the migration list.

ERROR_VOLMGR_DISK_DUPLICATE      _NDIS_ERROR_TYPEDEF_(0xC0380006L)






// The disk is already dynamic.

ERROR_VOLMGR_DISK_DYNAMIC        _NDIS_ERROR_TYPEDEF_(0xC0380007L)






// The specified disk id is invalid. There are no disks with the specified disk id.

ERROR_VOLMGR_DISK_ID_INVALID     _NDIS_ERROR_TYPEDEF_(0xC0380008L)






// The specified disk is an invalid disk. Operation cannot complete on an invalid disk.

ERROR_VOLMGR_DISK_INVALID        _NDIS_ERROR_TYPEDEF_(0xC0380009L)






// The specified disk(s) cannot be removed since it is the last remaining voter.

ERROR_VOLMGR_DISK_LAST_VOTER     _NDIS_ERROR_TYPEDEF_(0xC038000AL)






// The specified disk has an invalid disk layout.

ERROR_VOLMGR_DISK_LAYOUT_INVALID _NDIS_ERROR_TYPEDEF_(0xC038000BL)






// The disk layout contains non-basic partitions which appear after basic partitions. This is an invalid disk layout.

ERROR_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS _NDIS_ERROR_TYPEDEF_(0xC038000CL)






// The disk layout contains partitions which are not cylinder aligned.

ERROR_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED _NDIS_ERROR_TYPEDEF_(0xC038000DL)






// The disk layout contains partitions which are smaller than the minimum size.

ERROR_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL _NDIS_ERROR_TYPEDEF_(0xC038000EL)






// The disk layout contains primary partitions in between logical drives. This is an invalid disk layout.

ERROR_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS _NDIS_ERROR_TYPEDEF_(0xC038000FL)






// The disk layout contains more than the maximum number of supported partitions.

ERROR_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS _NDIS_ERROR_TYPEDEF_(0xC0380010L)






// The specified disk is missing. The operation cannot complete on a missing disk.

ERROR_VOLMGR_DISK_MISSING        _NDIS_ERROR_TYPEDEF_(0xC0380011L)






// The specified disk is not empty.

ERROR_VOLMGR_DISK_NOT_EMPTY      _NDIS_ERROR_TYPEDEF_(0xC0380012L)






// There is not enough usable space for this operation.

ERROR_VOLMGR_DISK_NOT_ENOUGH_SPACE _NDIS_ERROR_TYPEDEF_(0xC0380013L)






// The force revectoring of bad sectors failed.

ERROR_VOLMGR_DISK_REVECTORING_FAILED _NDIS_ERROR_TYPEDEF_(0xC0380014L)






// The specified disk has an invalid sector size.

ERROR_VOLMGR_DISK_SECTOR_SIZE_INVALID _NDIS_ERROR_TYPEDEF_(0xC0380015L)






// The specified disk set contains volumes which exist on disks outside of the set.

ERROR_VOLMGR_DISK_SET_NOT_CONTAINED _NDIS_ERROR_TYPEDEF_(0xC0380016L)






// A disk in the volume layout provides extents to more than one member of a plex.

ERROR_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS _NDIS_ERROR_TYPEDEF_(0xC0380017L)






// A disk in the volume layout provides extents to more than one plex.

ERROR_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES _NDIS_ERROR_TYPEDEF_(0xC0380018L)






// Dynamic disks are not supported on this system.

ERROR_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED _NDIS_ERROR_TYPEDEF_(0xC0380019L)






// The specified extent is already used by other volumes.

ERROR_VOLMGR_EXTENT_ALREADY_USED _NDIS_ERROR_TYPEDEF_(0xC038001AL)






// The specified volume is retained and can only be extended into a contiguous extent. The specified extent to grow the volume is not contiguous with the specified volume.

ERROR_VOLMGR_EXTENT_NOT_CONTIGUOUS _NDIS_ERROR_TYPEDEF_(0xC038001BL)






// The specified volume extent is not within the public region of the disk.

ERROR_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION _NDIS_ERROR_TYPEDEF_(0xC038001CL)






// The specified volume extent is not sector aligned.

ERROR_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED _NDIS_ERROR_TYPEDEF_(0xC038001DL)






// The specified partition overlaps an EBR (the first track of an extended partition on an MBR disk).

ERROR_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION _NDIS_ERROR_TYPEDEF_(0xC038001EL)






// The specified extent lengths cannot be used to construct a volume with specified length.

ERROR_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH _NDIS_ERROR_TYPEDEF_(0xC038001FL)






// The system does not support fault tolerant volumes.

ERROR_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED _NDIS_ERROR_TYPEDEF_(0xC0380020L)






// The specified interleave length is invalid.

ERROR_VOLMGR_INTERLEAVE_LENGTH_INVALID _NDIS_ERROR_TYPEDEF_(0xC0380021L)






// There is already a maximum number of registered users.

ERROR_VOLMGR_MAXIMUM_REGISTERED_USERS _NDIS_ERROR_TYPEDEF_(0xC0380022L)






// The specified member is already in-sync with the other active members. It does not need to be regenerated.

ERROR_VOLMGR_MEMBER_IN_SYNC      _NDIS_ERROR_TYPEDEF_(0xC0380023L)






// The same member index was specified more than once.

ERROR_VOLMGR_MEMBER_INDEX_DUPLICATE _NDIS_ERROR_TYPEDEF_(0xC0380024L)






// The specified member index is greater or equal than the number of members in the volume plex.

ERROR_VOLMGR_MEMBER_INDEX_INVALID _NDIS_ERROR_TYPEDEF_(0xC0380025L)






// The specified member is missing. It cannot be regenerated.

ERROR_VOLMGR_MEMBER_MISSING      _NDIS_ERROR_TYPEDEF_(0xC0380026L)






// The specified member is not detached. Cannot replace a member which is not detached.

ERROR_VOLMGR_MEMBER_NOT_DETACHED _NDIS_ERROR_TYPEDEF_(0xC0380027L)






// The specified member is already regenerating.

ERROR_VOLMGR_MEMBER_REGENERATING _NDIS_ERROR_TYPEDEF_(0xC0380028L)






// All disks belonging to the pack failed.

ERROR_VOLMGR_ALL_DISKS_FAILED    _NDIS_ERROR_TYPEDEF_(0xC0380029L)






// There are currently no registered users for notifications. The task number is irrelevant unless there are registered users.

ERROR_VOLMGR_NO_REGISTERED_USERS _NDIS_ERROR_TYPEDEF_(0xC038002AL)






// The specified notification user does not exist. Failed to unregister user for notifications.

ERROR_VOLMGR_NO_SUCH_USER        _NDIS_ERROR_TYPEDEF_(0xC038002BL)






// The notifications have been reset. Notifications for the current user are invalid. Unregister and re-register for notifications.

ERROR_VOLMGR_NOTIFICATION_RESET  _NDIS_ERROR_TYPEDEF_(0xC038002CL)






// The specified number of members is invalid.

ERROR_VOLMGR_NUMBER_OF_MEMBERS_INVALID _NDIS_ERROR_TYPEDEF_(0xC038002DL)






// The specified number of plexes is invalid.

ERROR_VOLMGR_NUMBER_OF_PLEXES_INVALID _NDIS_ERROR_TYPEDEF_(0xC038002EL)






// The specified source and target packs are identical.

ERROR_VOLMGR_PACK_DUPLICATE      _NDIS_ERROR_TYPEDEF_(0xC038002FL)






// The specified pack id is invalid. There are no packs with the specified pack id.

ERROR_VOLMGR_PACK_ID_INVALID     _NDIS_ERROR_TYPEDEF_(0xC0380030L)






// The specified pack is the invalid pack. The operation cannot complete with the invalid pack.

ERROR_VOLMGR_PACK_INVALID        _NDIS_ERROR_TYPEDEF_(0xC0380031L)






// The specified pack name is invalid.

ERROR_VOLMGR_PACK_NAME_INVALID   _NDIS_ERROR_TYPEDEF_(0xC0380032L)






// The specified pack is offline.

ERROR_VOLMGR_PACK_OFFLINE        _NDIS_ERROR_TYPEDEF_(0xC0380033L)






// The specified pack already has a quorum of healthy disks.

ERROR_VOLMGR_PACK_HAS_QUORUM     _NDIS_ERROR_TYPEDEF_(0xC0380034L)






// The pack does not have a quorum of healthy disks.

ERROR_VOLMGR_PACK_WITHOUT_QUORUM _NDIS_ERROR_TYPEDEF_(0xC0380035L)






// The specified disk has an unsupported partition style. Only MBR and GPT partition styles are supported.

ERROR_VOLMGR_PARTITION_STYLE_INVALID _NDIS_ERROR_TYPEDEF_(0xC0380036L)






// Failed to update the disk's partition layout.

ERROR_VOLMGR_PARTITION_UPDATE_FAILED _NDIS_ERROR_TYPEDEF_(0xC0380037L)






// The specified plex is already in-sync with the other active plexes. It does not need to be regenerated.

ERROR_VOLMGR_PLEX_IN_SYNC        _NDIS_ERROR_TYPEDEF_(0xC0380038L)






// The same plex index was specified more than once.

ERROR_VOLMGR_PLEX_INDEX_DUPLICATE _NDIS_ERROR_TYPEDEF_(0xC0380039L)






// The specified plex index is greater or equal than the number of plexes in the volume.

ERROR_VOLMGR_PLEX_INDEX_INVALID  _NDIS_ERROR_TYPEDEF_(0xC038003AL)






// The specified plex is the last active plex in the volume. The plex cannot be removed or else the volume will go offline.

ERROR_VOLMGR_PLEX_LAST_ACTIVE    _NDIS_ERROR_TYPEDEF_(0xC038003BL)






// The specified plex is missing.

ERROR_VOLMGR_PLEX_MISSING        _NDIS_ERROR_TYPEDEF_(0xC038003CL)






// The specified plex is currently regenerating.

ERROR_VOLMGR_PLEX_REGENERATING   _NDIS_ERROR_TYPEDEF_(0xC038003DL)






// The specified plex type is invalid.

ERROR_VOLMGR_PLEX_TYPE_INVALID   _NDIS_ERROR_TYPEDEF_(0xC038003EL)






// The operation is only supported on RAID-5 plexes.

ERROR_VOLMGR_PLEX_NOT_RAID5      _NDIS_ERROR_TYPEDEF_(0xC038003FL)






// The operation is only supported on simple plexes.

ERROR_VOLMGR_PLEX_NOT_SIMPLE     _NDIS_ERROR_TYPEDEF_(0xC0380040L)






// The Size fields in the VM_VOLUME_LAYOUT input structure are incorrectly set.

ERROR_VOLMGR_STRUCTURE_SIZE_INVALID _NDIS_ERROR_TYPEDEF_(0xC0380041L)






// There is already a pending request for notifications. Wait for the existing request to return before requesting for more notifications.

ERROR_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS _NDIS_ERROR_TYPEDEF_(0xC0380042L)






// There is currently a transaction in process.

ERROR_VOLMGR_TRANSACTION_IN_PROGRESS _NDIS_ERROR_TYPEDEF_(0xC0380043L)






// An unexpected layout change occurred outside of the volume manager.

ERROR_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE _NDIS_ERROR_TYPEDEF_(0xC0380044L)






// The specified volume contains a missing disk.

ERROR_VOLMGR_VOLUME_CONTAINS_MISSING_DISK _NDIS_ERROR_TYPEDEF_(0xC0380045L)






// The specified volume id is invalid. There are no volumes with the specified volume id.

ERROR_VOLMGR_VOLUME_ID_INVALID   _NDIS_ERROR_TYPEDEF_(0xC0380046L)






// The specified volume length is invalid.

ERROR_VOLMGR_VOLUME_LENGTH_INVALID _NDIS_ERROR_TYPEDEF_(0xC0380047L)






// The specified size for the volume is not a multiple of the sector size.

ERROR_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE _NDIS_ERROR_TYPEDEF_(0xC0380048L)






// The operation is only supported on mirrored volumes.

ERROR_VOLMGR_VOLUME_NOT_MIRRORED _NDIS_ERROR_TYPEDEF_(0xC0380049L)






// The specified volume does not have a retain partition.

ERROR_VOLMGR_VOLUME_NOT_RETAINED _NDIS_ERROR_TYPEDEF_(0xC038004AL)






// The specified volume is offline.

ERROR_VOLMGR_VOLUME_OFFLINE      _NDIS_ERROR_TYPEDEF_(0xC038004BL)






// The specified volume already has a retain partition.

ERROR_VOLMGR_VOLUME_RETAINED     _NDIS_ERROR_TYPEDEF_(0xC038004CL)






// The specified number of extents is invalid.

ERROR_VOLMGR_NUMBER_OF_EXTENTS_INVALID _NDIS_ERROR_TYPEDEF_(0xC038004DL)






// All disks participating to the volume must have the same sector size.

ERROR_VOLMGR_DIFFERENT_SECTOR_SIZE _NDIS_ERROR_TYPEDEF_(0xC038004EL)






// The boot disk experienced failures.

ERROR_VOLMGR_BAD_BOOT_DISK       _NDIS_ERROR_TYPEDEF_(0xC038004FL)






// The configuration of the pack is offline.

ERROR_VOLMGR_PACK_CONFIG_OFFLINE _NDIS_ERROR_TYPEDEF_(0xC0380050L)






// The configuration of the pack is online.

ERROR_VOLMGR_PACK_CONFIG_ONLINE  _NDIS_ERROR_TYPEDEF_(0xC0380051L)






// The specified pack is not the primary pack.

ERROR_VOLMGR_NOT_PRIMARY_PACK    _NDIS_ERROR_TYPEDEF_(0xC0380052L)






// All disks failed to be updated with the new content of the log.

ERROR_VOLMGR_PACK_LOG_UPDATE_FAILED _NDIS_ERROR_TYPEDEF_(0xC0380053L)






// The specified number of disks in a plex is invalid.

ERROR_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID _NDIS_ERROR_TYPEDEF_(0xC0380054L)






// The specified number of disks in a plex member is invalid.

ERROR_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID _NDIS_ERROR_TYPEDEF_(0xC0380055L)






// The operation is not supported on mirrored volumes.

ERROR_VOLMGR_VOLUME_MIRRORED     _NDIS_ERROR_TYPEDEF_(0xC0380056L)






// The operation is only supported on simple and spanned plexes.

ERROR_VOLMGR_PLEX_NOT_SIMPLE_SPANNED _NDIS_ERROR_TYPEDEF_(0xC0380057L)






// The pack has no valid log copies.

ERROR_VOLMGR_NO_VALID_LOG_COPIES _NDIS_ERROR_TYPEDEF_(0xC0380058L)






// A primary pack is already present.

ERROR_VOLMGR_PRIMARY_PACK_PRESENT _NDIS_ERROR_TYPEDEF_(0xC0380059L)






// The specified number of disks is invalid.

ERROR_VOLMGR_NUMBER_OF_DISKS_INVALID _NDIS_ERROR_TYPEDEF_(0xC038005AL)






// The system does not support mirrored volumes.

ERROR_VOLMGR_MIRROR_NOT_SUPPORTED _NDIS_ERROR_TYPEDEF_(0xC038005BL)






// The system does not support RAID-5 volumes.

ERROR_VOLMGR_RAID5_NOT_SUPPORTED _NDIS_ERROR_TYPEDEF_(0xC038005CL)



// Boot Code Data (BCD) error codes







// Some BCD entries were not imported correctly from the BCD store.

ERROR_BCD_NOT_ALL_ENTRIES_IMPORTED _NDIS_ERROR_TYPEDEF_(0x80390001L)






// Entries enumerated have exceeded the allowed threshold.

ERROR_BCD_TOO_MANY_ELEMENTS      _NDIS_ERROR_TYPEDEF_(0xC0390002L)






// Some BCD entries were not synchronized correctly with the firmware.

ERROR_BCD_NOT_ALL_ENTRIES_SYNCHRONIZED _NDIS_ERROR_TYPEDEF_(0x80390003L)


// Vhd error codes - These codes are used by the virtual hard diskparser component.


// Errors:







// The virtual hard disk is corrupted. The virtual hard disk drive footer is missing.

ERROR_VHD_DRIVE_FOOTER_MISSING   _NDIS_ERROR_TYPEDEF_(0xC03A0001L)






// The virtual hard disk is corrupted. The virtual hard disk drive footer checksum does not match the on-disk checksum.

ERROR_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH _NDIS_ERROR_TYPEDEF_(0xC03A0002L)






// The virtual hard disk is corrupted. The virtual hard disk drive footer in the virtual hard disk is corrupted.

ERROR_VHD_DRIVE_FOOTER_CORRUPT   _NDIS_ERROR_TYPEDEF_(0xC03A0003L)






// The system does not recognize the file format of this virtual hard disk.

ERROR_VHD_FORMAT_UNKNOWN         _NDIS_ERROR_TYPEDEF_(0xC03A0004L)






// The version does not support this version of the file format.

ERROR_VHD_FORMAT_UNSUPPORTED_VERSION _NDIS_ERROR_TYPEDEF_(0xC03A0005L)






// The virtual hard disk is corrupted. The sparse header checksum does not match the on-disk checksum.

ERROR_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH _NDIS_ERROR_TYPEDEF_(0xC03A0006L)






// The system does not support this version of the virtual hard disk.This version of the sparse header is not supported.

ERROR_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION _NDIS_ERROR_TYPEDEF_(0xC03A0007L)






// The virtual hard disk is corrupted. The sparse header in the virtual hard disk is corrupt.

ERROR_VHD_SPARSE_HEADER_CORRUPT  _NDIS_ERROR_TYPEDEF_(0xC03A0008L)






// Failed to write to the virtual hard disk failed because the system failed to allocate a new block in the virtual hard disk.

ERROR_VHD_BLOCK_ALLOCATION_FAILURE _NDIS_ERROR_TYPEDEF_(0xC03A0009L)






// The virtual hard disk is corrupted. The block allocation table in the virtual hard disk is corrupt.

ERROR_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT _NDIS_ERROR_TYPEDEF_(0xC03A000AL)






// The system does not support this version of the virtual hard disk. The block size is invalid.

ERROR_VHD_INVALID_BLOCK_SIZE     _NDIS_ERROR_TYPEDEF_(0xC03A000BL)






// The virtual hard disk is corrupted. The block bitmap does not match with the block data present in the virtual hard disk.

ERROR_VHD_BITMAP_MISMATCH        _NDIS_ERROR_TYPEDEF_(0xC03A000CL)






// The chain of virtual hard disks is broken. The system cannot locate the parent virtual hard disk for the differencing disk.

ERROR_VHD_PARENT_VHD_NOT_FOUND   _NDIS_ERROR_TYPEDEF_(0xC03A000DL)






// The chain of virtual hard disks is corrupted. There is a mismatch in the identifiers of the parent virtual hard disk and differencing disk.

ERROR_VHD_CHILD_PARENT_ID_MISMATCH _NDIS_ERROR_TYPEDEF_(0xC03A000EL)






// The chain of virtual hard disks is corrupted. The time stamp of the parent virtual hard disk does not match the time stamp of the differencing disk.

ERROR_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH _NDIS_ERROR_TYPEDEF_(0xC03A000FL)






// Failed to read the metadata of the virtual hard disk.

ERROR_VHD_METADATA_READ_FAILURE  _NDIS_ERROR_TYPEDEF_(0xC03A0010L)






// Failed to write to the metadata of the virtual hard disk.

ERROR_VHD_METADATA_WRITE_FAILURE _NDIS_ERROR_TYPEDEF_(0xC03A0011L)






// The size of the virtual hard disk is not valid.

ERROR_VHD_INVALID_SIZE           _NDIS_ERROR_TYPEDEF_(0xC03A0012L)






// The file size of this virtual hard disk is not valid.

ERROR_VHD_INVALID_FILE_SIZE      _NDIS_ERROR_TYPEDEF_(0xC03A0013L)






// A virtual disk support provider for the specified file was not found.

ERROR_VIRTDISK_PROVIDER_NOT_FOUND _NDIS_ERROR_TYPEDEF_(0xC03A0014L)






// The specified disk is not a virtual disk.

ERROR_VIRTDISK_NOT_VIRTUAL_DISK  _NDIS_ERROR_TYPEDEF_(0xC03A0015L)






// The chain of virtual hard disks is inaccessible. The process has not been granted access rights to the parent virtual hard disk for the differencing disk.

ERROR_VHD_PARENT_VHD_ACCESS_DENIED _NDIS_ERROR_TYPEDEF_(0xC03A0016L)






// The chain of virtual hard disks is corrupted. There is a mismatch in the virtual sizes of the parent virtual hard disk and differencing disk.

ERROR_VHD_CHILD_PARENT_SIZE_MISMATCH _NDIS_ERROR_TYPEDEF_(0xC03A0017L)






// The chain of virtual hard disks is corrupted. A differencing disk is indicated in its own parent chain.

ERROR_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED _NDIS_ERROR_TYPEDEF_(0xC03A0018L)






// The chain of virtual hard disks is inaccessible. There was an error opening a virtual hard disk further up the chain.

ERROR_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT _NDIS_ERROR_TYPEDEF_(0xC03A0019L)






// The requested operation could not be completed due to a virtual disk system limitation.  Virtual hard disk files must be uncompressed and unencrypted and must not be sparse.

ERROR_VIRTUAL_DISK_LIMITATION    _NDIS_ERROR_TYPEDEF_(0xC03A001AL)






// The requested operation cannot be performed on a virtual disk of this type.

ERROR_VHD_INVALID_TYPE           _NDIS_ERROR_TYPEDEF_(0xC03A001BL)






// The requested operation cannot be performed on the virtual disk in its current state.

ERROR_VHD_INVALID_STATE          _NDIS_ERROR_TYPEDEF_(0xC03A001CL)






// The sector size of the physical disk on which the virtual disk resides is not supported.

ERROR_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE _NDIS_ERROR_TYPEDEF_(0xC03A001DL)






// The disk is already owned by a different owner.

ERROR_VIRTDISK_DISK_ALREADY_OWNED _NDIS_ERROR_TYPEDEF_(0xC03A001EL)






// The disk must be offline or read-only.

ERROR_VIRTDISK_DISK_ONLINE_AND_WRITABLE _NDIS_ERROR_TYPEDEF_(0xC03A001FL)






// Change Tracking is not initialized for this virtual disk.

ERROR_CTLOG_TRACKING_NOT_INITIALIZED _NDIS_ERROR_TYPEDEF_(0xC03A0020L)






// Size of change tracking file exceeded the maximum size limit.

ERROR_CTLOG_LOGFILE_SIZE_EXCEEDED_MAXSIZE _NDIS_ERROR_TYPEDEF_(0xC03A0021L)






// VHD file is changed due to compaction, expansion, or offline updates.

ERROR_CTLOG_VHD_CHANGED_OFFLINE  _NDIS_ERROR_TYPEDEF_(0xC03A0022L)






// Change Tracking for the virtual disk is not in a valid state to perform this request.  Change tracking could be discontinued or already in the requested state.

ERROR_CTLOG_INVALID_TRACKING_STATE _NDIS_ERROR_TYPEDEF_(0xC03A0023L)






// Change Tracking file for the virtual disk is not in a valid state.

ERROR_CTLOG_INCONSISTENT_TRACKING_FILE _NDIS_ERROR_TYPEDEF_(0xC03A0024L)






// The requested resize operation could not be completed because it might truncate user data residing on the virtual disk.

ERROR_VHD_RESIZE_WOULD_TRUNCATE_DATA _NDIS_ERROR_TYPEDEF_(0xC03A0025L)






// The requested operation could not be completed because the virtual disk's minimum safe size could not be determined.
// This may be due to a missing or corrupt partition table.

ERROR_VHD_COULD_NOT_COMPUTE_MINIMUM_VIRTUAL_SIZE _NDIS_ERROR_TYPEDEF_(0xC03A0026L)






// The requested operation could not be completed because the virtual disk's size cannot be safely reduced further.

ERROR_VHD_ALREADY_AT_OR_BELOW_MINIMUM_VIRTUAL_SIZE _NDIS_ERROR_TYPEDEF_(0xC03A0027L)






// There is not enough space in the virtual disk file for the provided metadata item.

ERROR_VHD_METADATA_FULL          _NDIS_ERROR_TYPEDEF_(0xC03A0028L)






// The specified change tracking identifier is not valid.

ERROR_VHD_INVALID_CHANGE_TRACKING_ID _NDIS_ERROR_TYPEDEF_(0xC03A0029L)






// Change tracking is disabled for the specified virtual hard disk, so no change tracking information is available.

ERROR_VHD_CHANGE_TRACKING_DISABLED _NDIS_ERROR_TYPEDEF_(0xC03A002AL)






// There is no change tracking data available associated with the specified change tracking identifier.

ERROR_VHD_MISSING_CHANGE_TRACKING_INFORMATION _NDIS_ERROR_TYPEDEF_(0xC03A0030L)


// Warnings:






// The virtualization storage subsystem has generated an error.

ERROR_QUERY_STORAGE_ERROR        _NDIS_ERROR_TYPEDEF_(0x803A0001L)


// =======================================================
// Host Network Service (HNS/GNS) Error Messages
// =======================================================






// The network was not found.

HCN_E_NETWORK_NOT_FOUND          _HRESULT_TYPEDEF_(0x803B0001L)






// The endpoint was not found.

HCN_E_ENDPOINT_NOT_FOUND         _HRESULT_TYPEDEF_(0x803B0002L)






// The network's underlying layer was not found.

HCN_E_LAYER_NOT_FOUND            _HRESULT_TYPEDEF_(0x803B0003L)






// The virtual switch was not found.

HCN_E_SWITCH_NOT_FOUND           _HRESULT_TYPEDEF_(0x803B0004L)






// The network does not have a subnet for this endpoint.

HCN_E_SUBNET_NOT_FOUND           _HRESULT_TYPEDEF_(0x803B0005L)






// An adapter was not found.

HCN_E_ADAPTER_NOT_FOUND          _HRESULT_TYPEDEF_(0x803B0006L)






// The switch-port was not found.

HCN_E_PORT_NOT_FOUND             _HRESULT_TYPEDEF_(0x803B0007L)






// An expected policy was not found.

HCN_E_POLICY_NOT_FOUND           _HRESULT_TYPEDEF_(0x803B0008L)






// A required VFP port setting was not found.

HCN_E_VFP_PORTSETTING_NOT_FOUND  _HRESULT_TYPEDEF_(0x803B0009L)






// The provided network configuration is invalid or missing parameters.

HCN_E_INVALID_NETWORK            _HRESULT_TYPEDEF_(0x803B000AL)






// Invalid network type.

HCN_E_INVALID_NETWORK_TYPE       _HRESULT_TYPEDEF_(0x803B000BL)






// The provided endpoint configuration is invalid or missing parameters.

HCN_E_INVALID_ENDPOINT           _HRESULT_TYPEDEF_(0x803B000CL)






// The provided policy configuration is invalid or missing parameters.

HCN_E_INVALID_POLICY             _HRESULT_TYPEDEF_(0x803B000DL)






// Invalid policy type.

HCN_E_INVALID_POLICY_TYPE        _HRESULT_TYPEDEF_(0x803B000EL)






// This requested operation is invalid for a remote endpoint.

HCN_E_INVALID_REMOTE_ENDPOINT_OPERATION _HRESULT_TYPEDEF_(0x803B000FL)






// A network with this name already exists.

HCN_E_NETWORK_ALREADY_EXISTS     _HRESULT_TYPEDEF_(0x803B0010L)






// A network with this name already exists.

HCN_E_LAYER_ALREADY_EXISTS       _HRESULT_TYPEDEF_(0x803B0011L)






// Policy information already exists on this object.

HCN_E_POLICY_ALREADY_EXISTS      _HRESULT_TYPEDEF_(0x803B0012L)






// The specified port already exists.

HCN_E_PORT_ALREADY_EXISTS        _HRESULT_TYPEDEF_(0x803B0013L)






// This endpoint is already attached to the switch.

HCN_E_ENDPOINT_ALREADY_ATTACHED  _HRESULT_TYPEDEF_(0x803B0014L)






// The specified request is unsupported.

HCN_E_REQUEST_UNSUPPORTED        _HRESULT_TYPEDEF_(0x803B0015L)






// Port mapping is not supported on the given network.

HCN_E_MAPPING_NOT_SUPPORTED      _HRESULT_TYPEDEF_(0x803B0016L)






// There was an operation attempted on a degraded object.

HCN_E_DEGRADED_OPERATION         _HRESULT_TYPEDEF_(0x803B0017L)






// Cannot modify a switch shared by multiple networks.

HCN_E_SHARED_SWITCH_MODIFICATION _HRESULT_TYPEDEF_(0x803B0018L)






// Failed to interpret a parameter as a GUID.

HCN_E_GUID_CONVERSION_FAILURE    _HRESULT_TYPEDEF_(0x803B0019L)






// Failed to process registry key.

HCN_E_REGKEY_FAILURE             _HRESULT_TYPEDEF_(0x803B001AL)






// Invalid JSON document string.

HCN_E_INVALID_JSON               _HRESULT_TYPEDEF_(0x803B001BL)






// The reference is invalid in the JSON document.

HCN_E_INVALID_JSON_REFERENCE     _HRESULT_TYPEDEF_(0x803B001CL)






// Endpoint sharing is disabled.

HCN_E_ENDPOINT_SHARING_DISABLED  _HRESULT_TYPEDEF_(0x803B001DL)






// IP address is either invalid or not part of any configured subnet(s).

HCN_E_INVALID_IP                 _HRESULT_TYPEDEF_(0x803B001EL)






// The specified switch extension does not exist on this switch.

HCN_E_SWITCH_EXTENSION_NOT_FOUND _HRESULT_TYPEDEF_(0x803B001FL)






// Operation cannot be performed while service is stopping.

HCN_E_MANAGER_STOPPED            _HRESULT_TYPEDEF_(0x803B0020L)






// Operation cannot be performed while service module not found.

GCN_E_MODULE_NOT_FOUND           _HRESULT_TYPEDEF_(0x803B0021L)






// Request Handlers not present to handle the JSON request.

GCN_E_NO_REQUEST_HANDLERS        _HRESULT_TYPEDEF_(0x803B0022L)






// The specified request is unsupported.

GCN_E_REQUEST_UNSUPPORTED        _HRESULT_TYPEDEF_(0x803B0023L)






// Add runtime keys to container failed.

GCN_E_RUNTIMEKEYS_FAILED         _HRESULT_TYPEDEF_(0x803B0024L)






// Timeout while waiting for network adapter with the given instance id

GCN_E_NETADAPTER_TIMEOUT         _HRESULT_TYPEDEF_(0x803B0025L)






// Network adapter not found for the given instance id

GCN_E_NETADAPTER_NOT_FOUND       _HRESULT_TYPEDEF_(0x803B0026L)






// Network compartment not found for the given  id

GCN_E_NETCOMPARTMENT_NOT_FOUND   _HRESULT_TYPEDEF_(0x803B0027L)






// Network interface not found for the given  id

GCN_E_NETINTERFACE_NOT_FOUND     _HRESULT_TYPEDEF_(0x803B0028L)






// Default Namespace already exists

GCN_E_DEFAULTNAMESPACE_EXISTS    _HRESULT_TYPEDEF_(0x803B0029L)






// Internet Connection Sharing service (SharedAccess) is disabled and cannot be started

HCN_E_ICS_DISABLED               _HRESULT_TYPEDEF_(0x803B002AL)






// This requested operation is invalid as endpoint is already part of a network namespace.

HCN_E_ENDPOINT_NAMESPACE_ALREADY_EXISTS _HRESULT_TYPEDEF_(0x803B002BL)






// The specified entity cannot be removed while it still has references.

HCN_E_ENTITY_HAS_REFERENCES      _HRESULT_TYPEDEF_(0x803B002CL)






// The internal port must exist and cannot be zero.

HCN_E_INVALID_INTERNAL_PORT      _HRESULT_TYPEDEF_(0x803B002DL)






// The requested operation for attach namespace failed.

HCN_E_NAMESPACE_ATTACH_FAILED    _HRESULT_TYPEDEF_(0x803B002EL)






// An address provided is invalid or reserved.

HCN_E_ADDR_INVALID_OR_RESERVED   _HRESULT_TYPEDEF_(0x803B002FL)


// =======================================================
// Facility Scripted Diagnostics (SDIAG) Error Messages
// =======================================================






// The operation was cancelled.

SDIAG_E_CANCELLED                _NDIS_ERROR_TYPEDEF_(0x803C0100L)






// An error occurred when running a PowerShell script.

SDIAG_E_SCRIPT                   _NDIS_ERROR_TYPEDEF_(0x803C0101L)






// An error occurred when interacting with PowerShell runtime.

SDIAG_E_POWERSHELL               _NDIS_ERROR_TYPEDEF_(0x803C0102L)






// An error occurred in the Scripted Diagnostic Managed Host.

SDIAG_E_MANAGEDHOST              _NDIS_ERROR_TYPEDEF_(0x803C0103L)






// The troubleshooting pack does not contain a required verifier to complete the verification.

SDIAG_E_NOVERIFIER               _NDIS_ERROR_TYPEDEF_(0x803C0104L)






// The troubleshooting pack cannot be executed on this system.

SDIAG_S_CANNOTRUN                _NDIS_ERROR_TYPEDEF_(0x003C0105L)






// Scripted diagnostics is disabled by group policy.

SDIAG_E_DISABLED                 _NDIS_ERROR_TYPEDEF_(0x803C0106L)






// Trust validation of the troubleshooting pack failed.

SDIAG_E_TRUST                    _NDIS_ERROR_TYPEDEF_(0x803C0107L)






// The troubleshooting pack cannot be executed on this system.

SDIAG_E_CANNOTRUN                _NDIS_ERROR_TYPEDEF_(0x803C0108L)






// This version of the troubleshooting pack is not supported.

SDIAG_E_VERSION                  _NDIS_ERROR_TYPEDEF_(0x803C0109L)






// A required resource cannot be loaded.

SDIAG_E_RESOURCE                 _NDIS_ERROR_TYPEDEF_(0x803C010AL)






// The troubleshooting pack reported information for a root cause without adding the root cause.

SDIAG_E_ROOTCAUSE                _NDIS_ERROR_TYPEDEF_(0x803C010BL)


// =======================================================
// Facility Windows Push Notifications (WPN) Error Messages
// =======================================================






// The notification channel has already been closed.

WPN_E_CHANNEL_CLOSED             _HRESULT_TYPEDEF_(0x803E0100L)






// The notification channel request did not complete successfully.

WPN_E_CHANNEL_REQUEST_NOT_COMPLETE _HRESULT_TYPEDEF_(0x803E0101L)






// The application identifier provided is invalid.

WPN_E_INVALID_APP                _HRESULT_TYPEDEF_(0x803E0102L)






// A notification channel request for the provided application identifier is in progress.

WPN_E_OUTSTANDING_CHANNEL_REQUEST _HRESULT_TYPEDEF_(0x803E0103L)






// The channel identifier is already tied to another application endpoint.

WPN_E_DUPLICATE_CHANNEL          _HRESULT_TYPEDEF_(0x803E0104L)






// The notification platform is unavailable.

WPN_E_PLATFORM_UNAVAILABLE       _HRESULT_TYPEDEF_(0x803E0105L)






// The notification has already been posted.

WPN_E_NOTIFICATION_POSTED        _HRESULT_TYPEDEF_(0x803E0106L)






// The notification has already been hidden.

WPN_E_NOTIFICATION_HIDDEN        _HRESULT_TYPEDEF_(0x803E0107L)






// The notification cannot be hidden until it has been shown.

WPN_E_NOTIFICATION_NOT_POSTED    _HRESULT_TYPEDEF_(0x803E0108L)






// Cloud notifications have been turned off.

WPN_E_CLOUD_DISABLED             _HRESULT_TYPEDEF_(0x803E0109L)






// The application does not have the cloud notification capability.

WPN_E_CLOUD_INCAPABLE            _HRESULT_TYPEDEF_(0x803E0110L)






// The notification platform is unable to retrieve the authentication credentials required to connect to the cloud notification service.

WPN_E_CLOUD_AUTH_UNAVAILABLE     _HRESULT_TYPEDEF_(0x803E011AL)






// The notification platform is unable to connect to the cloud notification service.

WPN_E_CLOUD_SERVICE_UNAVAILABLE  _HRESULT_TYPEDEF_(0x803E011BL)






// The notification platform is unable to initialize a callback for lock screen updates.

WPN_E_FAILED_LOCK_SCREEN_UPDATE_INTIALIZATION _HRESULT_TYPEDEF_(0x803E011CL)






// Settings prevent the notification from being delivered.

WPN_E_NOTIFICATION_DISABLED      _HRESULT_TYPEDEF_(0x803E0111L)






// Application capabilities prevent the notification from being delivered.

WPN_E_NOTIFICATION_INCAPABLE     _HRESULT_TYPEDEF_(0x803E0112L)






// The application does not have the internet access capability.

WPN_E_INTERNET_INCAPABLE         _HRESULT_TYPEDEF_(0x803E0113L)






// Settings prevent the notification type from being delivered.

WPN_E_NOTIFICATION_TYPE_DISABLED _HRESULT_TYPEDEF_(0x803E0114L)






// The size of the notification content is too large.

WPN_E_NOTIFICATION_SIZE          _HRESULT_TYPEDEF_(0x803E0115L)






// The size of the notification tag is too large.

WPN_E_TAG_SIZE                   _HRESULT_TYPEDEF_(0x803E0116L)






// The notification platform doesn't have appropriate privilege on resources.

WPN_E_ACCESS_DENIED              _HRESULT_TYPEDEF_(0x803E0117L)






// The notification platform found application is already registered.

WPN_E_DUPLICATE_REGISTRATION     _HRESULT_TYPEDEF_(0x803E0118L)






// The application background task does not have the push notification capability.

WPN_E_PUSH_NOTIFICATION_INCAPABLE _HRESULT_TYPEDEF_(0x803E0119L)






// The size of the developer id for scheduled notification is too large.

WPN_E_DEV_ID_SIZE                _HRESULT_TYPEDEF_(0x803E0120L)






// The notification tag is not alphanumeric.

WPN_E_TAG_ALPHANUMERIC           _HRESULT_TYPEDEF_(0x803E012AL)






// The notification platform has received invalid HTTP status code other than 2xx for polling.

WPN_E_INVALID_HTTP_STATUS_CODE   _HRESULT_TYPEDEF_(0x803E012BL)






// The notification platform has run out of presentation layer sessions.

WPN_E_OUT_OF_SESSION             _HRESULT_TYPEDEF_(0x803E0200L)






// The notification platform rejects image download request due to system in power save mode.

WPN_E_POWER_SAVE                 _HRESULT_TYPEDEF_(0x803E0201L)






// The notification platform doesn't have the requested image in its cache.

WPN_E_IMAGE_NOT_FOUND_IN_CACHE   _HRESULT_TYPEDEF_(0x803E0202L)






// The notification platform cannot complete all of requested image.

WPN_E_ALL_URL_NOT_COMPLETED      _HRESULT_TYPEDEF_(0x803E0203L)






// A cloud image downloaded from the notification platform is invalid.

WPN_E_INVALID_CLOUD_IMAGE        _HRESULT_TYPEDEF_(0x803E0204L)






// Notification Id provided as filter is matched with what the notification platform maintains.

WPN_E_NOTIFICATION_ID_MATCHED    _HRESULT_TYPEDEF_(0x803E0205L)






// Notification callback interface is already registered.

WPN_E_CALLBACK_ALREADY_REGISTERED _HRESULT_TYPEDEF_(0x803E0206L)






// Toast Notification was dropped without being displayed to the user.

WPN_E_TOAST_NOTIFICATION_DROPPED _HRESULT_TYPEDEF_(0x803E0207L)






// The notification platform does not have the proper privileges to complete the request.

WPN_E_STORAGE_LOCKED             _HRESULT_TYPEDEF_(0x803E0208L)






// The size of the notification group is too large.

WPN_E_GROUP_SIZE                 _HRESULT_TYPEDEF_(0x803E0209L)






// The notification group is not alphanumeric.

WPN_E_GROUP_ALPHANUMERIC         _HRESULT_TYPEDEF_(0x803E020AL)






// Cloud notifications have been disabled for the application due to a policy setting.

WPN_E_CLOUD_DISABLED_FOR_APP     _HRESULT_TYPEDEF_(0x803E020BL)



// MBN error codes







// Context is not activated.

E_MBN_CONTEXT_NOT_ACTIVATED      _HRESULT_TYPEDEF_(0x80548201L)






// Bad SIM is inserted.

E_MBN_BAD_SIM                    _HRESULT_TYPEDEF_(0x80548202L)






// Requested data class is not available.

E_MBN_DATA_CLASS_NOT_AVAILABLE   _HRESULT_TYPEDEF_(0x80548203L)






// Access point name (APN) or Access string is incorrect.

E_MBN_INVALID_ACCESS_STRING      _HRESULT_TYPEDEF_(0x80548204L)






// Max activated contexts have reached.

E_MBN_MAX_ACTIVATED_CONTEXTS     _HRESULT_TYPEDEF_(0x80548205L)






// Device is in packet detach state.

E_MBN_PACKET_SVC_DETACHED        _HRESULT_TYPEDEF_(0x80548206L)






// Provider is not visible.

E_MBN_PROVIDER_NOT_VISIBLE       _HRESULT_TYPEDEF_(0x80548207L)






// Radio is powered off.

E_MBN_RADIO_POWER_OFF            _HRESULT_TYPEDEF_(0x80548208L)






// MBN subscription is not activated.

E_MBN_SERVICE_NOT_ACTIVATED      _HRESULT_TYPEDEF_(0x80548209L)






// SIM is not inserted.

E_MBN_SIM_NOT_INSERTED           _HRESULT_TYPEDEF_(0x8054820AL)






// Voice call in progress.

E_MBN_VOICE_CALL_IN_PROGRESS     _HRESULT_TYPEDEF_(0x8054820BL)






// Visible provider cache is invalid.

E_MBN_INVALID_CACHE              _HRESULT_TYPEDEF_(0x8054820CL)






// Device is not registered.

E_MBN_NOT_REGISTERED             _HRESULT_TYPEDEF_(0x8054820DL)






// Providers not found.

E_MBN_PROVIDERS_NOT_FOUND        _HRESULT_TYPEDEF_(0x8054820EL)






// Pin is not supported.

E_MBN_PIN_NOT_SUPPORTED          _HRESULT_TYPEDEF_(0x8054820FL)






// Pin is required.

E_MBN_PIN_REQUIRED               _HRESULT_TYPEDEF_(0x80548210L)






// PIN is disabled.

E_MBN_PIN_DISABLED               _HRESULT_TYPEDEF_(0x80548211L)






// Generic Failure.

E_MBN_FAILURE                    _HRESULT_TYPEDEF_(0x80548212L)

// Profile related error messages





// Profile is invalid.

E_MBN_INVALID_PROFILE            _HRESULT_TYPEDEF_(0x80548218L)






// Default profile exist.

E_MBN_DEFAULT_PROFILE_EXIST      _HRESULT_TYPEDEF_(0x80548219L)

// SMS related error messages





// SMS encoding is not supported.

E_MBN_SMS_ENCODING_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80548220L)






// SMS filter is not supported.

E_MBN_SMS_FILTER_NOT_SUPPORTED   _HRESULT_TYPEDEF_(0x80548221L)






// Invalid SMS memory index is used.

E_MBN_SMS_INVALID_MEMORY_INDEX   _HRESULT_TYPEDEF_(0x80548222L)






// SMS language is not supported.

E_MBN_SMS_LANG_NOT_SUPPORTED     _HRESULT_TYPEDEF_(0x80548223L)






// SMS memory failure occurred.

E_MBN_SMS_MEMORY_FAILURE         _HRESULT_TYPEDEF_(0x80548224L)






// SMS network timeout happened.

E_MBN_SMS_NETWORK_TIMEOUT        _HRESULT_TYPEDEF_(0x80548225L)






// Unknown SMSC address is used.

E_MBN_SMS_UNKNOWN_SMSC_ADDRESS   _HRESULT_TYPEDEF_(0x80548226L)






// SMS format is not supported.

E_MBN_SMS_FORMAT_NOT_SUPPORTED   _HRESULT_TYPEDEF_(0x80548227L)






// SMS operation is not allowed.

E_MBN_SMS_OPERATION_NOT_ALLOWED  _HRESULT_TYPEDEF_(0x80548228L)






// Device SMS memory is full.

E_MBN_SMS_MEMORY_FULL            _HRESULT_TYPEDEF_(0x80548229L)



// P2P error codes







// The IPv6 protocol is not installed.

PEER_E_IPV6_NOT_INSTALLED        _HRESULT_TYPEDEF_(0x80630001L)






// The component has not been initialized.

PEER_E_NOT_INITIALIZED           _HRESULT_TYPEDEF_(0x80630002L)






// The required service cannot be started.

PEER_E_CANNOT_START_SERVICE      _HRESULT_TYPEDEF_(0x80630003L)






// The P2P protocol is not licensed to run on this OS.

PEER_E_NOT_LICENSED              _HRESULT_TYPEDEF_(0x80630004L)






// The graph handle is invalid.

PEER_E_INVALID_GRAPH             _HRESULT_TYPEDEF_(0x80630010L)






// The graph database name has changed.

PEER_E_DBNAME_CHANGED            _HRESULT_TYPEDEF_(0x80630011L)






// A graph with the same ID already exists.

PEER_E_DUPLICATE_GRAPH           _HRESULT_TYPEDEF_(0x80630012L)






// The graph is not ready.

PEER_E_GRAPH_NOT_READY           _HRESULT_TYPEDEF_(0x80630013L)






// The graph is shutting down.

PEER_E_GRAPH_SHUTTING_DOWN       _HRESULT_TYPEDEF_(0x80630014L)






// The graph is still in use.

PEER_E_GRAPH_IN_USE              _HRESULT_TYPEDEF_(0x80630015L)






// The graph database is corrupt.

PEER_E_INVALID_DATABASE          _HRESULT_TYPEDEF_(0x80630016L)






// Too many attributes have been used.

PEER_E_TOO_MANY_ATTRIBUTES       _HRESULT_TYPEDEF_(0x80630017L)






// The connection can not be found.

PEER_E_CONNECTION_NOT_FOUND      _HRESULT_TYPEDEF_(0x80630103L)






// The peer attempted to connect to itself.

PEER_E_CONNECT_SELF              _HRESULT_TYPEDEF_(0x80630106L)






// The peer is already listening for connections.

PEER_E_ALREADY_LISTENING         _HRESULT_TYPEDEF_(0x80630107L)






// The node was not found.

PEER_E_NODE_NOT_FOUND            _HRESULT_TYPEDEF_(0x80630108L)






// The Connection attempt failed.

PEER_E_CONNECTION_FAILED         _HRESULT_TYPEDEF_(0x80630109L)






// The peer connection could not be authenticated.

PEER_E_CONNECTION_NOT_AUTHENTICATED _HRESULT_TYPEDEF_(0x8063010AL)






// The connection was refused.

PEER_E_CONNECTION_REFUSED        _HRESULT_TYPEDEF_(0x8063010BL)






// The peer name classifier is too long.

PEER_E_CLASSIFIER_TOO_LONG       _HRESULT_TYPEDEF_(0x80630201L)






// The maximum number of identities have been created.

PEER_E_TOO_MANY_IDENTITIES       _HRESULT_TYPEDEF_(0x80630202L)






// Unable to access a key.

PEER_E_NO_KEY_ACCESS             _HRESULT_TYPEDEF_(0x80630203L)






// The group already exists.

PEER_E_GROUPS_EXIST              _HRESULT_TYPEDEF_(0x80630204L)

// record error codes





// The requested record could not be found.

PEER_E_RECORD_NOT_FOUND          _HRESULT_TYPEDEF_(0x80630301L)






// Access to the database was denied.

PEER_E_DATABASE_ACCESSDENIED     _HRESULT_TYPEDEF_(0x80630302L)






// The Database could not be initialized.

PEER_E_DBINITIALIZATION_FAILED   _HRESULT_TYPEDEF_(0x80630303L)






// The record is too big.

PEER_E_MAX_RECORD_SIZE_EXCEEDED  _HRESULT_TYPEDEF_(0x80630304L)






// The database already exists.

PEER_E_DATABASE_ALREADY_PRESENT  _HRESULT_TYPEDEF_(0x80630305L)






// The database could not be found.

PEER_E_DATABASE_NOT_PRESENT      _HRESULT_TYPEDEF_(0x80630306L)






// The identity could not be found.

PEER_E_IDENTITY_NOT_FOUND        _HRESULT_TYPEDEF_(0x80630401L)

// eventing error





// The event handle could not be found.

PEER_E_EVENT_HANDLE_NOT_FOUND    _HRESULT_TYPEDEF_(0x80630501L)

// searching error





// Invalid search.

PEER_E_INVALID_SEARCH            _HRESULT_TYPEDEF_(0x80630601L)






// The search attributes are invalid.

PEER_E_INVALID_ATTRIBUTES        _HRESULT_TYPEDEF_(0x80630602L)


// certificate verification error codes





// The invitation is not trusted.

PEER_E_INVITATION_NOT_TRUSTED    _HRESULT_TYPEDEF_(0x80630701L)






// The certchain is too long.

PEER_E_CHAIN_TOO_LONG            _HRESULT_TYPEDEF_(0x80630703L)






// The time period is invalid.

PEER_E_INVALID_TIME_PERIOD       _HRESULT_TYPEDEF_(0x80630705L)






// A circular cert chain was detected.

PEER_E_CIRCULAR_CHAIN_DETECTED   _HRESULT_TYPEDEF_(0x80630706L)






// The certstore is corrupted.

PEER_E_CERT_STORE_CORRUPTED      _HRESULT_TYPEDEF_(0x80630801L)






// The specified PNRP cloud does not exist.

PEER_E_NO_CLOUD                  _HRESULT_TYPEDEF_(0x80631001L)






// The cloud name is ambiguous.

PEER_E_CLOUD_NAME_AMBIGUOUS      _HRESULT_TYPEDEF_(0x80631005L)






// The record is invalid.

PEER_E_INVALID_RECORD            _HRESULT_TYPEDEF_(0x80632010L)






// Not authorized.

PEER_E_NOT_AUTHORIZED            _HRESULT_TYPEDEF_(0x80632020L)






// The password does not meet policy requirements.

PEER_E_PASSWORD_DOES_NOT_MEET_POLICY _HRESULT_TYPEDEF_(0x80632021L)






// The record validation has been deferred.

PEER_E_DEFERRED_VALIDATION       _HRESULT_TYPEDEF_(0x80632030L)






// The group properties are invalid.

PEER_E_INVALID_GROUP_PROPERTIES  _HRESULT_TYPEDEF_(0x80632040L)






// The peername is invalid.

PEER_E_INVALID_PEER_NAME         _HRESULT_TYPEDEF_(0x80632050L)






// The classifier is invalid.

PEER_E_INVALID_CLASSIFIER        _HRESULT_TYPEDEF_(0x80632060L)






// The friendly name is invalid.

PEER_E_INVALID_FRIENDLY_NAME     _HRESULT_TYPEDEF_(0x80632070L)






// Invalid role property.

PEER_E_INVALID_ROLE_PROPERTY     _HRESULT_TYPEDEF_(0x80632071L)






// Invalid classifier property.

PEER_E_INVALID_CLASSIFIER_PROPERTY _HRESULT_TYPEDEF_(0x80632072L)






// Invalid record expiration.

PEER_E_INVALID_RECORD_EXPIRATION _HRESULT_TYPEDEF_(0x80632080L)






// Invalid credential info.

PEER_E_INVALID_CREDENTIAL_INFO   _HRESULT_TYPEDEF_(0x80632081L)






// Invalid credential.

PEER_E_INVALID_CREDENTIAL        _HRESULT_TYPEDEF_(0x80632082L)






// Invalid record size.

PEER_E_INVALID_RECORD_SIZE       _HRESULT_TYPEDEF_(0x80632083L)






// Unsupported version.

PEER_E_UNSUPPORTED_VERSION       _HRESULT_TYPEDEF_(0x80632090L)






// The group is not ready.

PEER_E_GROUP_NOT_READY           _HRESULT_TYPEDEF_(0x80632091L)






// The group is still in use.

PEER_E_GROUP_IN_USE              _HRESULT_TYPEDEF_(0x80632092L)






// The group is invalid.

PEER_E_INVALID_GROUP             _HRESULT_TYPEDEF_(0x80632093L)






// No members were found.

PEER_E_NO_MEMBERS_FOUND          _HRESULT_TYPEDEF_(0x80632094L)






// There are no member connections.

PEER_E_NO_MEMBER_CONNECTIONS     _HRESULT_TYPEDEF_(0x80632095L)






// Unable to listen.

PEER_E_UNABLE_TO_LISTEN          _HRESULT_TYPEDEF_(0x80632096L)






// The identity does not exist.

PEER_E_IDENTITY_DELETED          _HRESULT_TYPEDEF_(0x806320A0L)






// The service is not available.

PEER_E_SERVICE_NOT_AVAILABLE     _HRESULT_TYPEDEF_(0x806320A1L)

// Contacts APIs error code





// THe contact could not be found.

PEER_E_CONTACT_NOT_FOUND         _HRESULT_TYPEDEF_(0x80636001L)

// Special success codes





// The graph data was created.

PEER_S_GRAPH_DATA_CREATED        _HRESULT_TYPEDEF_(0x00630001L)






// There is not more event data.

PEER_S_NO_EVENT_DATA             _HRESULT_TYPEDEF_(0x00630002L)






// The graph is already connect.

PEER_S_ALREADY_CONNECTED         _HRESULT_TYPEDEF_(0x00632000L)






// The subscription already exists.

PEER_S_SUBSCRIPTION_EXISTS       _HRESULT_TYPEDEF_(0x00636000L)






// No connectivity.

PEER_S_NO_CONNECTIVITY           _HRESULT_TYPEDEF_(0x00630005L)






// Already a member.

PEER_S_ALREADY_A_MEMBER          _HRESULT_TYPEDEF_(0x00630006L)

// Pnrp helpers errors





// The peername could not be converted to a DNS pnrp name.

PEER_E_CANNOT_CONVERT_PEER_NAME  _HRESULT_TYPEDEF_(0x80634001L)






// Invalid peer host name.

PEER_E_INVALID_PEER_HOST_NAME    _HRESULT_TYPEDEF_(0x80634002L)






// No more data could be found.

PEER_E_NO_MORE                   _HRESULT_TYPEDEF_(0x80634003L)






// The existing peer name is already registered.

PEER_E_PNRP_DUPLICATE_PEER_NAME  _HRESULT_TYPEDEF_(0x80634005L)

// AppInvite APIs error code





// The app invite request was cancelled by the user.

PEER_E_INVITE_CANCELLED          _HRESULT_TYPEDEF_(0x80637000L)






// No response of the invite was received.

PEER_E_INVITE_RESPONSE_NOT_AVAILABLE _HRESULT_TYPEDEF_(0x80637001L)

// Serverless presence error codes





// User is not signed into serverless presence.

PEER_E_NOT_SIGNED_IN             _HRESULT_TYPEDEF_(0x80637003L)






// The user declined the privacy policy prompt.

PEER_E_PRIVACY_DECLINED          _HRESULT_TYPEDEF_(0x80637004L)






// A timeout occurred.

PEER_E_TIMEOUT                   _HRESULT_TYPEDEF_(0x80637005L)






// The address is invalid.

PEER_E_INVALID_ADDRESS           _HRESULT_TYPEDEF_(0x80637007L)






// A required firewall exception is disabled.

PEER_E_FW_EXCEPTION_DISABLED     _HRESULT_TYPEDEF_(0x80637008L)






// The service is blocked by a firewall policy.

PEER_E_FW_BLOCKED_BY_POLICY      _HRESULT_TYPEDEF_(0x80637009L)






// Firewall exceptions are disabled.

PEER_E_FW_BLOCKED_BY_SHIELDS_UP  _HRESULT_TYPEDEF_(0x8063700AL)






// The user declined to enable the firewall exceptions.

PEER_E_FW_DECLINED               _HRESULT_TYPEDEF_(0x8063700BL)



// UI error codes







// The object could not be created.

UI_E_CREATE_FAILED               _HRESULT_TYPEDEF_(0x802A0001L)






// Shutdown was already called on this object or the object that owns it.

UI_E_SHUTDOWN_CALLED             _HRESULT_TYPEDEF_(0x802A0002L)






// This method cannot be called during this type of callback.

UI_E_ILLEGAL_REENTRANCY          _HRESULT_TYPEDEF_(0x802A0003L)






// This object has been sealed, so this change is no longer allowed.

UI_E_OBJECT_SEALED               _HRESULT_TYPEDEF_(0x802A0004L)






// The requested value was never set.

UI_E_VALUE_NOT_SET               _HRESULT_TYPEDEF_(0x802A0005L)






// The requested value cannot be determined.

UI_E_VALUE_NOT_DETERMINED        _HRESULT_TYPEDEF_(0x802A0006L)






// A callback returned an invalid output parameter.

UI_E_INVALID_OUTPUT              _HRESULT_TYPEDEF_(0x802A0007L)






// A callback returned a success code other than S_OK or S_FALSE.

UI_E_BOOLEAN_EXPECTED            _HRESULT_TYPEDEF_(0x802A0008L)






// A parameter that should be owned by this object is owned by a different object.

UI_E_DIFFERENT_OWNER             _HRESULT_TYPEDEF_(0x802A0009L)






// More than one item matched the search criteria.

UI_E_AMBIGUOUS_MATCH             _HRESULT_TYPEDEF_(0x802A000AL)






// A floating-point overflow occurred.

UI_E_FP_OVERFLOW                 _HRESULT_TYPEDEF_(0x802A000BL)






// This method can only be called from the thread that created the object.

UI_E_WRONG_THREAD                _HRESULT_TYPEDEF_(0x802A000CL)






// The storyboard is currently in the schedule.

UI_E_STORYBOARD_ACTIVE           _HRESULT_TYPEDEF_(0x802A0101L)






// The storyboard is not playing.

UI_E_STORYBOARD_NOT_PLAYING      _HRESULT_TYPEDEF_(0x802A0102L)






// The start keyframe might occur after the end keyframe.

UI_E_START_KEYFRAME_AFTER_END    _HRESULT_TYPEDEF_(0x802A0103L)






// It might not be possible to determine the end keyframe time when the start keyframe is reached.

UI_E_END_KEYFRAME_NOT_DETERMINED _HRESULT_TYPEDEF_(0x802A0104L)






// Two repeated portions of a storyboard might overlap.

UI_E_LOOPS_OVERLAP               _HRESULT_TYPEDEF_(0x802A0105L)






// The transition has already been added to a storyboard.

UI_E_TRANSITION_ALREADY_USED     _HRESULT_TYPEDEF_(0x802A0106L)






// The transition has not been added to a storyboard.

UI_E_TRANSITION_NOT_IN_STORYBOARD _HRESULT_TYPEDEF_(0x802A0107L)






// The transition might eclipse the beginning of another transition in the storyboard.

UI_E_TRANSITION_ECLIPSED         _HRESULT_TYPEDEF_(0x802A0108L)






// The given time is earlier than the time passed to the last update.

UI_E_TIME_BEFORE_LAST_UPDATE     _HRESULT_TYPEDEF_(0x802A0109L)






// This client is already connected to a timer.

UI_E_TIMER_CLIENT_ALREADY_CONNECTED _HRESULT_TYPEDEF_(0x802A010AL)






// The passed dimension is invalid or does not match the object's dimension.

UI_E_INVALID_DIMENSION           _HRESULT_TYPEDEF_(0x802A010BL)






// The added primitive begins at or beyond the duration of the interpolator.

UI_E_PRIMITIVE_OUT_OF_BOUNDS     _HRESULT_TYPEDEF_(0x802A010CL)






// The operation cannot be completed because the window is being closed.

UI_E_WINDOW_CLOSED               _HRESULT_TYPEDEF_(0x802A0201L)



// Bluetooth Attribute Protocol Warnings







// The attribute handle given was not valid on this server.

E_BLUETOOTH_ATT_INVALID_HANDLE   _HRESULT_TYPEDEF_(0x80650001L)






// The attribute cannot be read.

E_BLUETOOTH_ATT_READ_NOT_PERMITTED _HRESULT_TYPEDEF_(0x80650002L)






// The attribute cannot be written.

E_BLUETOOTH_ATT_WRITE_NOT_PERMITTED _HRESULT_TYPEDEF_(0x80650003L)






// The attribute PDU was invalid.

E_BLUETOOTH_ATT_INVALID_PDU      _HRESULT_TYPEDEF_(0x80650004L)






// The attribute requires authentication before it can be read or written.

E_BLUETOOTH_ATT_INSUFFICIENT_AUTHENTICATION _HRESULT_TYPEDEF_(0x80650005L)






// Attribute server does not support the request received from the client.

E_BLUETOOTH_ATT_REQUEST_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80650006L)






// Offset specified was past the end of the attribute.

E_BLUETOOTH_ATT_INVALID_OFFSET   _HRESULT_TYPEDEF_(0x80650007L)






// The attribute requires authorization before it can be read or written.

E_BLUETOOTH_ATT_INSUFFICIENT_AUTHORIZATION _HRESULT_TYPEDEF_(0x80650008L)






// Too many prepare writes have been queued.

E_BLUETOOTH_ATT_PREPARE_QUEUE_FULL _HRESULT_TYPEDEF_(0x80650009L)






// No attribute found within the given attribute handle range.

E_BLUETOOTH_ATT_ATTRIBUTE_NOT_FOUND _HRESULT_TYPEDEF_(0x8065000AL)






// The attribute cannot be read or written using the Read Blob Request.

E_BLUETOOTH_ATT_ATTRIBUTE_NOT_LONG _HRESULT_TYPEDEF_(0x8065000BL)






// The Encryption Key Size used for encrypting this link is insufficient.

E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE _HRESULT_TYPEDEF_(0x8065000CL)






// The attribute value length is invalid for the operation.

E_BLUETOOTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH _HRESULT_TYPEDEF_(0x8065000DL)






// The attribute request that was requested has encountered an error that was unlikely, and therefore could not be completed as requested.

E_BLUETOOTH_ATT_UNLIKELY         _HRESULT_TYPEDEF_(0x8065000EL)






// The attribute requires encryption before it can be read or written.

E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION _HRESULT_TYPEDEF_(0x8065000FL)






// The attribute type is not a supported grouping attribute as defined by a higher layer specification.

E_BLUETOOTH_ATT_UNSUPPORTED_GROUP_TYPE _HRESULT_TYPEDEF_(0x80650010L)






// Insufficient Resources to complete the request.

E_BLUETOOTH_ATT_INSUFFICIENT_RESOURCES _HRESULT_TYPEDEF_(0x80650011L)






// An error that lies in the reserved range has been received.

E_BLUETOOTH_ATT_UNKNOWN_ERROR    _HRESULT_TYPEDEF_(0x80651000L)



// Audio errors







// PortCls could not find an audio engine node exposed by a miniport driver claiming support for IMiniportAudioEngineNode.

E_AUDIO_ENGINE_NODE_NOT_FOUND    _HRESULT_TYPEDEF_(0x80660001L)






// HD Audio widget encountered an unexpected empty connection list.

E_HDAUDIO_EMPTY_CONNECTION_LIST  _HRESULT_TYPEDEF_(0x80660002L)






// HD Audio widget does not support the connection list parameter.

E_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80660003L)






// No HD Audio subdevices were successfully created.

E_HDAUDIO_NO_LOGICAL_DEVICES_CREATED _HRESULT_TYPEDEF_(0x80660004L)






// An unexpected NULL pointer was encountered in a linked list.

E_HDAUDIO_NULL_LINKED_LIST_ENTRY _HRESULT_TYPEDEF_(0x80660005L)


// StateRepository errors






// Optimistic locking failure. Data cannot be updated if it has changed since it was read.

STATEREPOSITORY_E_CONCURRENCY_LOCKING_FAILURE _HRESULT_TYPEDEF_(0x80670001L)






// A prepared statement has been stepped at least once but not run to completion or reset. This may result in busy waits.

STATEREPOSITORY_E_STATEMENT_INPROGRESS _HRESULT_TYPEDEF_(0x80670002L)






// The StateRepository configuration is not valid.

STATEREPOSITORY_E_CONFIGURATION_INVALID _HRESULT_TYPEDEF_(0x80670003L)






// The StateRepository schema version is not known.

STATEREPOSITORY_E_UNKNOWN_SCHEMA_VERSION _HRESULT_TYPEDEF_(0x80670004L)






// A StateRepository dictionary is not valid.

STATEREPOSITORY_ERROR_DICTIONARY_CORRUPTED _HRESULT_TYPEDEF_(0x80670005L)






// The request failed because the StateRepository is actively blocking requests.

STATEREPOSITORY_E_BLOCKED        _HRESULT_TYPEDEF_(0x80670006L)






// The database file is locked. The request will be retried.

STATEREPOSITORY_E_BUSY_RETRY     _HRESULT_TYPEDEF_(0x80670007L)






// The database file is locked because another process is busy recovering the database. The request will be retried.

STATEREPOSITORY_E_BUSY_RECOVERY_RETRY _HRESULT_TYPEDEF_(0x80670008L)






// A table in the database is locked. The request will be retried.

STATEREPOSITORY_E_LOCKED_RETRY   _HRESULT_TYPEDEF_(0x80670009L)






// The shared cache for the database is locked by another connection. The request will be retried.

STATEREPOSITORY_E_LOCKED_SHAREDCACHE_RETRY _HRESULT_TYPEDEF_(0x8067000AL)






// A transaction is required to perform the request operation.

STATEREPOSITORY_E_TRANSACTION_REQUIRED _HRESULT_TYPEDEF_(0x8067000BL)






// The database file is locked. The request has exceeded the allowed threshold.

STATEREPOSITORY_E_BUSY_TIMEOUT_EXCEEDED _HRESULT_TYPEDEF_(0x8067000CL)






// The database file is locked because another process is busy recovering the database. The request has exceeded the allowed threshold.

STATEREPOSITORY_E_BUSY_RECOVERY_TIMEOUT_EXCEEDED _HRESULT_TYPEDEF_(0x8067000DL)






// A table in the database is locked. The request has exceeded the allowed threshold.

STATEREPOSITORY_E_LOCKED_TIMEOUT_EXCEEDED _HRESULT_TYPEDEF_(0x8067000EL)






// The shared cache for the database is locked by another connection. The request has exceeded the allowed threshold.

STATEREPOSITORY_E_LOCKED_SHAREDCACHE_TIMEOUT_EXCEEDED _HRESULT_TYPEDEF_(0x8067000FL)






// The StateRepository service Stop event is in progress.

STATEREPOSITORY_E_SERVICE_STOP_IN_PROGRESS _HRESULT_TYPEDEF_(0x80670010L)






// Nested transactions are not supported.

STATEREPOSTORY_E_NESTED_TRANSACTION_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80670011L)






// The StateRepository cache is not valid.

STATEREPOSITORY_ERROR_CACHE_CORRUPTED _HRESULT_TYPEDEF_(0x80670012L)






// The transaction caller id has changed.

STATEREPOSITORY_TRANSACTION_CALLER_ID_CHANGED _HRESULT_TYPEDEF_(0x00670013L)






// A transaction is in progress for the database connection.

STATEREPOSITORY_TRANSACTION_IN_PROGRESS _HRESULT_TYPEDEF_(0x00670014L)


// Spaceport errors

// Success





// The storage pool was deleted by the driver. The object cache should be updated.

ERROR_SPACES_POOL_WAS_DELETED    _HRESULT_TYPEDEF_(0x00E70001L)

// Errors





// The specified fault domain type or combination of minimum / maximum fault domain type is not valid.

ERROR_SPACES_FAULT_DOMAIN_TYPE_INVALID _HRESULT_TYPEDEF_(0x80E70001L)






// A Storage Spaces internal error occurred.

ERROR_SPACES_INTERNAL_ERROR      _HRESULT_TYPEDEF_(0x80E70002L)






// The specified resiliency type is not valid.

ERROR_SPACES_RESILIENCY_TYPE_INVALID _HRESULT_TYPEDEF_(0x80E70003L)






// The physical disk's sector size is not supported by the storage pool.

ERROR_SPACES_DRIVE_SECTOR_SIZE_INVALID _HRESULT_TYPEDEF_(0x80E70004L)






// The requested redundancy is outside of the supported range of values.

ERROR_SPACES_DRIVE_REDUNDANCY_INVALID _HRESULT_TYPEDEF_(0x80E70006L)






// The number of data copies requested is outside of the supported range of values.

ERROR_SPACES_NUMBER_OF_DATA_COPIES_INVALID _HRESULT_TYPEDEF_(0x80E70007L)






// The value for ParityLayout is outside of the supported range of values.

ERROR_SPACES_PARITY_LAYOUT_INVALID _HRESULT_TYPEDEF_(0x80E70008L)






// The value for interleave length is outside of the supported range of values or is not a power of 2.

ERROR_SPACES_INTERLEAVE_LENGTH_INVALID _HRESULT_TYPEDEF_(0x80E70009L)






// The number of columns specified is outside of the supported range of values.

ERROR_SPACES_NUMBER_OF_COLUMNS_INVALID _HRESULT_TYPEDEF_(0x80E7000AL)






// There were not enough physical disks to complete the requested operation.

ERROR_SPACES_NOT_ENOUGH_DRIVES   _HRESULT_TYPEDEF_(0x80E7000BL)






// Extended error information is available.

ERROR_SPACES_EXTENDED_ERROR      _HRESULT_TYPEDEF_(0x80E7000CL)






// The specified provisioning type is not valid.

ERROR_SPACES_PROVISIONING_TYPE_INVALID _HRESULT_TYPEDEF_(0x80E7000DL)






// The allocation size is outside of the supported range of values.

ERROR_SPACES_ALLOCATION_SIZE_INVALID _HRESULT_TYPEDEF_(0x80E7000EL)






// Enclosure awareness is not supported for this virtual disk.

ERROR_SPACES_ENCLOSURE_AWARE_INVALID _HRESULT_TYPEDEF_(0x80E7000FL)






// The write cache size is outside of the supported range of values.

ERROR_SPACES_WRITE_CACHE_SIZE_INVALID _HRESULT_TYPEDEF_(0x80E70010L)






// The value for number of groups is outside of the supported range of values.

ERROR_SPACES_NUMBER_OF_GROUPS_INVALID _HRESULT_TYPEDEF_(0x80E70011L)






// The OperationalState of the physical disk is invalid for this operation.

ERROR_SPACES_DRIVE_OPERATIONAL_STATE_INVALID _HRESULT_TYPEDEF_(0x80E70012L)






// The specified log entry is not complete.

ERROR_SPACES_ENTRY_INCOMPLETE    _HRESULT_TYPEDEF_(0x80E70013L)






// The specified log entry is not valid.

ERROR_SPACES_ENTRY_INVALID       _HRESULT_TYPEDEF_(0x80E70014L)


// Volsnap errors

// Success





// The bootfile is too small to support persistent snapshots.

ERROR_VOLSNAP_BOOTFILE_NOT_VALID _HRESULT_TYPEDEF_(0x80820001L)






// Activation of persistent snapshots on this volume took longer than was allowed.

ERROR_VOLSNAP_ACTIVATION_TIMEOUT _HRESULT_TYPEDEF_(0x80820002L)


// Tiering errors

// Errors





// The specified volume does not support storage tiers.

ERROR_TIERING_NOT_SUPPORTED_ON_VOLUME _HRESULT_TYPEDEF_(0x80830001L)






// The Storage Tiers Management service detected that the specified volume is in the process of being dismounted.

ERROR_TIERING_VOLUME_DISMOUNT_IN_PROGRESS _HRESULT_TYPEDEF_(0x80830002L)






// The specified storage tier could not be found on the volume. Confirm that the storage tier name is valid.

ERROR_TIERING_STORAGE_TIER_NOT_FOUND _HRESULT_TYPEDEF_(0x80830003L)






// The file identifier specified is not valid on the volume.

ERROR_TIERING_INVALID_FILE_ID    _HRESULT_TYPEDEF_(0x80830004L)






// Storage tier operations must be called on the clustering node that owns the metadata volume.

ERROR_TIERING_WRONG_CLUSTER_NODE _HRESULT_TYPEDEF_(0x80830005L)






// The Storage Tiers Management service is already optimizing the storage tiers on the specified volume.

ERROR_TIERING_ALREADY_PROCESSING _HRESULT_TYPEDEF_(0x80830006L)






// The requested object type cannot be assigned to a storage tier.

ERROR_TIERING_CANNOT_PIN_OBJECT  _HRESULT_TYPEDEF_(0x80830007L)






// The requested file is not pinned to a tier.

ERROR_TIERING_FILE_IS_NOT_PINNED _HRESULT_TYPEDEF_(0x80830008L)






// The volume is not a tiered volume.

ERROR_NOT_A_TIERED_VOLUME        _HRESULT_TYPEDEF_(0x80830009L)






// The requested attribute is not present on the specified file or directory.

ERROR_ATTRIBUTE_NOT_PRESENT      _HRESULT_TYPEDEF_(0x8083000AL)


// Embedded Security Core

// Reserved id values 0x0001 - 0x00FF
//                    0x8xxx
//                    0x4xxx





// The command was not recognized by the security core

ERROR_SECCORE_INVALID_COMMAND    _HRESULT_TYPEDEF_(0xC0E80000L)


// Clip modern app and windows licensing error messages.






// No applicable app licenses found.

ERROR_NO_APPLICABLE_APP_LICENSES_FOUND _HRESULT_TYPEDEF_(0xC0EA0001L)






// CLiP license not found.

ERROR_CLIP_LICENSE_NOT_FOUND     _HRESULT_TYPEDEF_(0xC0EA0002L)






// CLiP device license not found.

ERROR_CLIP_DEVICE_LICENSE_MISSING _HRESULT_TYPEDEF_(0xC0EA0003L)






// CLiP license has an invalid signature.

ERROR_CLIP_LICENSE_INVALID_SIGNATURE _HRESULT_TYPEDEF_(0xC0EA0004L)






// CLiP keyholder license is invalid or missing.

ERROR_CLIP_KEYHOLDER_LICENSE_MISSING_OR_INVALID _HRESULT_TYPEDEF_(0xC0EA0005L)






// CLiP license has expired.

ERROR_CLIP_LICENSE_EXPIRED       _HRESULT_TYPEDEF_(0xC0EA0006L)






// CLiP license is signed by an unknown source.

ERROR_CLIP_LICENSE_SIGNED_BY_UNKNOWN_SOURCE _HRESULT_TYPEDEF_(0xC0EA0007L)






// CLiP license is not signed.

ERROR_CLIP_LICENSE_NOT_SIGNED    _HRESULT_TYPEDEF_(0xC0EA0008L)






// CLiP license hardware ID is out of tolerance.

ERROR_CLIP_LICENSE_HARDWARE_ID_OUT_OF_TOLERANCE _HRESULT_TYPEDEF_(0xC0EA0009L)






// CLiP license device ID does not match the device ID in the bound device license.

ERROR_CLIP_LICENSE_DEVICE_ID_MISMATCH _HRESULT_TYPEDEF_(0xC0EA000AL)


// ===============================
// Facility Direct* Error Messages
// ===============================




// DXGI status (success) codes







// The Present operation was invisible to the user.

DXGI_STATUS_OCCLUDED             _HRESULT_TYPEDEF_(0x087A0001L)






// The Present operation was partially invisible to the user.

DXGI_STATUS_CLIPPED              _HRESULT_TYPEDEF_(0x087A0002L)






// The driver is requesting that the DXGI runtime not use shared resources to communicate with the Desktop Window Manager.

DXGI_STATUS_NO_REDIRECTION       _HRESULT_TYPEDEF_(0x087A0004L)






// The Present operation was not visible because the Windows session has switched to another desktop (for example, ctrl-alt-del).

DXGI_STATUS_NO_DESKTOP_ACCESS    _HRESULT_TYPEDEF_(0x087A0005L)






// The Present operation was not visible because the target monitor was being used for some other purpose.

DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE _HRESULT_TYPEDEF_(0x087A0006L)






// The Present operation was not visible because the display mode changed. DXGI will have re-attempted the presentation.

DXGI_STATUS_MODE_CHANGED         _HRESULT_TYPEDEF_(0x087A0007L)






// The Present operation was not visible because another Direct3D device was attempting to take fullscreen mode at the time.

DXGI_STATUS_MODE_CHANGE_IN_PROGRESS _HRESULT_TYPEDEF_(0x087A0008L)



// DXGI error codes







// The application made a call that is invalid. Either the parameters of the call or the state of some object was incorrect.
// Enable the D3D debug layer in order to see details via debug messages.

DXGI_ERROR_INVALID_CALL          _HRESULT_TYPEDEF_(0x887A0001L)






// The object was not found. If calling IDXGIFactory::EnumAdaptes, there is no adapter with the specified ordinal.

DXGI_ERROR_NOT_FOUND             _HRESULT_TYPEDEF_(0x887A0002L)






// The caller did not supply a sufficiently large buffer.

DXGI_ERROR_MORE_DATA             _HRESULT_TYPEDEF_(0x887A0003L)






// The specified device interface or feature level is not supported on this system.

DXGI_ERROR_UNSUPPORTED           _HRESULT_TYPEDEF_(0x887A0004L)






// The GPU device instance has been suspended. Use GetDeviceRemovedReason to determine the appropriate action.

DXGI_ERROR_DEVICE_REMOVED        _HRESULT_TYPEDEF_(0x887A0005L)






// The GPU will not respond to more commands, most likely because of an invalid command passed by the calling application.

DXGI_ERROR_DEVICE_HUNG           _HRESULT_TYPEDEF_(0x887A0006L)






// The GPU will not respond to more commands, most likely because some other application submitted invalid commands.
// The calling application should re-create the device and continue.

DXGI_ERROR_DEVICE_RESET          _HRESULT_TYPEDEF_(0x887A0007L)






// The GPU was busy at the moment when the call was made, and the call was neither executed nor scheduled.

DXGI_ERROR_WAS_STILL_DRAWING     _HRESULT_TYPEDEF_(0x887A000AL)






// An event (such as power cycle) interrupted the gathering of presentation statistics. Any previous statistics should be
// considered invalid.

DXGI_ERROR_FRAME_STATISTICS_DISJOINT _HRESULT_TYPEDEF_(0x887A000BL)






// Fullscreen mode could not be achieved because the specified output was already in use.

DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE _HRESULT_TYPEDEF_(0x887A000CL)






// An internal issue prevented the driver from carrying out the specified operation. The driver's state is probably suspect,
// and the application should not continue.

DXGI_ERROR_DRIVER_INTERNAL_ERROR _HRESULT_TYPEDEF_(0x887A0020L)






// A global counter resource was in use, and the specified counter cannot be used by this Direct3D device at this time.

DXGI_ERROR_NONEXCLUSIVE          _HRESULT_TYPEDEF_(0x887A0021L)






// A resource is not available at the time of the call, but may become available later.

DXGI_ERROR_NOT_CURRENTLY_AVAILABLE _HRESULT_TYPEDEF_(0x887A0022L)






// The application's remote device has been removed due to session disconnect or network disconnect.
// The application should call IDXGIFactory1::IsCurrent to find out when the remote device becomes available again.

DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED _HRESULT_TYPEDEF_(0x887A0023L)






// The device has been removed during a remote session because the remote computer ran out of memory.

DXGI_ERROR_REMOTE_OUTOFMEMORY    _HRESULT_TYPEDEF_(0x887A0024L)






// The keyed mutex was abandoned.

DXGI_ERROR_ACCESS_LOST           _HRESULT_TYPEDEF_(0x887A0026L)






// The timeout value has elapsed and the resource is not yet available.

DXGI_ERROR_WAIT_TIMEOUT          _HRESULT_TYPEDEF_(0x887A0027L)






// The output duplication has been turned off because the Windows session ended or was disconnected.
// This happens when a remote user disconnects, or when "switch user" is used locally.

DXGI_ERROR_SESSION_DISCONNECTED  _HRESULT_TYPEDEF_(0x887A0028L)






// The DXGI output (monitor) to which the swapchain content was restricted, has been disconnected or changed.

DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE _HRESULT_TYPEDEF_(0x887A0029L)






// DXGI is unable to provide content protection on the swapchain. This is typically caused by an older driver,
// or by the application using a swapchain that is incompatible with content protection.

DXGI_ERROR_CANNOT_PROTECT_CONTENT _HRESULT_TYPEDEF_(0x887A002AL)






// The application is trying to use a resource to which it does not have the required access privileges.
// This is most commonly caused by writing to a shared resource with read-only access.

DXGI_ERROR_ACCESS_DENIED         _HRESULT_TYPEDEF_(0x887A002BL)






// The application is trying to create a shared handle using a name that is already associated with some other resource.

DXGI_ERROR_NAME_ALREADY_EXISTS   _HRESULT_TYPEDEF_(0x887A002CL)






// The application requested an operation that depends on an SDK component that is missing or mismatched.

DXGI_ERROR_SDK_COMPONENT_MISSING _HRESULT_TYPEDEF_(0x887A002DL)






// The DXGI objects that the application has created are no longer current & need to be recreated for this operation to be performed.

DXGI_ERROR_NOT_CURRENT           _HRESULT_TYPEDEF_(0x887A002EL)






// Insufficient HW protected memory exits for proper function.

DXGI_ERROR_HW_PROTECTION_OUTOFMEMORY _HRESULT_TYPEDEF_(0x887A0030L)






// Creating this device would violate the process's dynamic code policy.

DXGI_ERROR_DYNAMIC_CODE_POLICY_VIOLATION _HRESULT_TYPEDEF_(0x887A0031L)






// The operation failed because the compositor is not in control of the output.

DXGI_ERROR_NON_COMPOSITED_UI     _HRESULT_TYPEDEF_(0x887A0032L)



// DXGI errors that are internal to the Desktop Window Manager







// The swapchain has become unoccluded.

DXGI_STATUS_UNOCCLUDED           _HRESULT_TYPEDEF_(0x087A0009L)






// The adapter did not have access to the required resources to complete the Desktop Duplication Present() call, the Present() call needs to be made again

DXGI_STATUS_DDA_WAS_STILL_DRAWING _HRESULT_TYPEDEF_(0x087A000AL)






// An on-going mode change prevented completion of the call. The call may succeed if attempted later.

DXGI_ERROR_MODE_CHANGE_IN_PROGRESS _HRESULT_TYPEDEF_(0x887A0025L)






// The present succeeded but the caller should present again on the next V-sync, even if there are no changes to the content.

DXGI_STATUS_PRESENT_REQUIRED     _HRESULT_TYPEDEF_(0x087A002FL)



// DXGI errors that are produced by the D3D Shader Cache component







// The cache is corrupt and either could not be opened or could not be reset.

DXGI_ERROR_CACHE_CORRUPT         _HRESULT_TYPEDEF_(0x887A0033L)






// This entry would cause the cache to exceed its quota. On a load operation, this may indicate exceeding the maximum in-memory size.

DXGI_ERROR_CACHE_FULL            _HRESULT_TYPEDEF_(0x887A0034L)






// A cache entry was found, but the key provided does not match the key stored in the entry.

DXGI_ERROR_CACHE_HASH_COLLISION  _HRESULT_TYPEDEF_(0x887A0035L)






// The desired element already exists.

DXGI_ERROR_ALREADY_EXISTS        _HRESULT_TYPEDEF_(0x887A0036L)



// DXGI DDI







// The GPU was busy when the operation was requested.

DXGI_DDI_ERR_WASSTILLDRAWING     _HRESULT_TYPEDEF_(0x887B0001L)






// The driver has rejected the creation of this resource.

DXGI_DDI_ERR_UNSUPPORTED         _HRESULT_TYPEDEF_(0x887B0002L)






// The GPU counter was in use by another process or d3d device when application requested access to it.

DXGI_DDI_ERR_NONEXCLUSIVE        _HRESULT_TYPEDEF_(0x887B0003L)



// Direct3D10







// The application has exceeded the maximum number of unique state objects per Direct3D device.
// The limit is 4096 for feature levels up to 11.1.

D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS _HRESULT_TYPEDEF_(0x88790001L)






// The specified file was not found.

D3D10_ERROR_FILE_NOT_FOUND       _HRESULT_TYPEDEF_(0x88790002L)



// Direct3D11







// The application has exceeded the maximum number of unique state objects per Direct3D device.
// The limit is 4096 for feature levels up to 11.1.

D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS _HRESULT_TYPEDEF_(0x887C0001L)






// The specified file was not found.

D3D11_ERROR_FILE_NOT_FOUND       _HRESULT_TYPEDEF_(0x887C0002L)






// The application has exceeded the maximum number of unique view objects per Direct3D device.
// The limit is 2^20 for feature levels up to 11.1.

D3D11_ERROR_TOO_MANY_UNIQUE_VIEW_OBJECTS _HRESULT_TYPEDEF_(0x887C0003L)






// The application's first call per command list to Map on a deferred context did not use D3D11_MAP_WRITE_DISCARD.

D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD _HRESULT_TYPEDEF_(0x887C0004L)



// Direct3D12







// The blob provided does not match the adapter that the device was created on.

D3D12_ERROR_ADAPTER_NOT_FOUND    _HRESULT_TYPEDEF_(0x887E0001L)






// The blob provided was created for a different version of the driver, and must be re-created.

D3D12_ERROR_DRIVER_VERSION_MISMATCH _HRESULT_TYPEDEF_(0x887E0002L)



// Direct2D







// The object was not in the correct state to process the method.

D2DERR_WRONG_STATE               _HRESULT_TYPEDEF_(0x88990001L)






// The object has not yet been initialized.

D2DERR_NOT_INITIALIZED           _HRESULT_TYPEDEF_(0x88990002L)






// The requested operation is not supported.

D2DERR_UNSUPPORTED_OPERATION     _HRESULT_TYPEDEF_(0x88990003L)






// The geometry scanner failed to process the data.

D2DERR_SCANNER_FAILED            _HRESULT_TYPEDEF_(0x88990004L)






// Direct2D could not access the screen.

D2DERR_SCREEN_ACCESS_DENIED      _HRESULT_TYPEDEF_(0x88990005L)






// A valid display state could not be determined.

D2DERR_DISPLAY_STATE_INVALID     _HRESULT_TYPEDEF_(0x88990006L)






// The supplied vector is zero.

D2DERR_ZERO_VECTOR               _HRESULT_TYPEDEF_(0x88990007L)






// An internal error (Direct2D bug) occurred. On checked builds, we would assert. The application should close this instance of Direct2D and should consider restarting its process.

D2DERR_INTERNAL_ERROR            _HRESULT_TYPEDEF_(0x88990008L)






// The display format Direct2D needs to render is not supported by the hardware device.

D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x88990009L)






// A call to this method is invalid.

D2DERR_INVALID_CALL              _HRESULT_TYPEDEF_(0x8899000AL)






// No hardware rendering device is available for this operation.

D2DERR_NO_HARDWARE_DEVICE        _HRESULT_TYPEDEF_(0x8899000BL)






// There has been a presentation error that may be recoverable. The caller needs to recreate, rerender the entire frame, and reattempt present.

D2DERR_RECREATE_TARGET           _HRESULT_TYPEDEF_(0x8899000CL)






// Shader construction failed because it was too complex.

D2DERR_TOO_MANY_SHADER_ELEMENTS  _HRESULT_TYPEDEF_(0x8899000DL)






// Shader compilation failed.

D2DERR_SHADER_COMPILE_FAILED     _HRESULT_TYPEDEF_(0x8899000EL)






// Requested DirectX surface size exceeded maximum texture size.

D2DERR_MAX_TEXTURE_SIZE_EXCEEDED _HRESULT_TYPEDEF_(0x8899000FL)






// The requested Direct2D version is not supported.

D2DERR_UNSUPPORTED_VERSION       _HRESULT_TYPEDEF_(0x88990010L)






// Invalid number.

D2DERR_BAD_NUMBER                _HRESULT_TYPEDEF_(0x88990011L)






// Objects used together must be created from the same factory instance.

D2DERR_WRONG_FACTORY             _HRESULT_TYPEDEF_(0x88990012L)






// A layer resource can only be in use once at any point in time.

D2DERR_LAYER_ALREADY_IN_USE      _HRESULT_TYPEDEF_(0x88990013L)






// The pop call did not match the corresponding push call.

D2DERR_POP_CALL_DID_NOT_MATCH_PUSH _HRESULT_TYPEDEF_(0x88990014L)






// The resource was realized on the wrong render target.

D2DERR_WRONG_RESOURCE_DOMAIN     _HRESULT_TYPEDEF_(0x88990015L)






// The push and pop calls were unbalanced.

D2DERR_PUSH_POP_UNBALANCED       _HRESULT_TYPEDEF_(0x88990016L)






// Attempt to copy from a render target while a layer or clip rect is applied.

D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT _HRESULT_TYPEDEF_(0x88990017L)






// The brush types are incompatible for the call.

D2DERR_INCOMPATIBLE_BRUSH_TYPES  _HRESULT_TYPEDEF_(0x88990018L)






// An unknown win32 failure occurred.

D2DERR_WIN32_ERROR               _HRESULT_TYPEDEF_(0x88990019L)






// The render target is not compatible with GDI.

D2DERR_TARGET_NOT_GDI_COMPATIBLE _HRESULT_TYPEDEF_(0x8899001AL)






// A text client drawing effect object is of the wrong type.

D2DERR_TEXT_EFFECT_IS_WRONG_TYPE _HRESULT_TYPEDEF_(0x8899001BL)






// The application is holding a reference to the IDWriteTextRenderer interface after the corresponding DrawText or DrawTextLayout call has returned. The IDWriteTextRenderer instance will be invalid.

D2DERR_TEXT_RENDERER_NOT_RELEASED _HRESULT_TYPEDEF_(0x8899001CL)






// The requested size is larger than the guaranteed supported texture size at the Direct3D device's current feature level.

D2DERR_EXCEEDS_MAX_BITMAP_SIZE   _HRESULT_TYPEDEF_(0x8899001DL)






// There was a configuration error in the graph.

D2DERR_INVALID_GRAPH_CONFIGURATION _HRESULT_TYPEDEF_(0x8899001EL)






// There was a internal configuration error in the graph.

D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION _HRESULT_TYPEDEF_(0x8899001FL)






// There was a cycle in the graph.

D2DERR_CYCLIC_GRAPH              _HRESULT_TYPEDEF_(0x88990020L)






// Cannot draw with a bitmap that has the D2D1_BITMAP_OPTIONS_CANNOT_DRAW option.

D2DERR_BITMAP_CANNOT_DRAW        _HRESULT_TYPEDEF_(0x88990021L)






// The operation cannot complete while there are outstanding references to the target bitmap.

D2DERR_OUTSTANDING_BITMAP_REFERENCES _HRESULT_TYPEDEF_(0x88990022L)






// The operation failed because the original target is not currently bound as a target.

D2DERR_ORIGINAL_TARGET_NOT_BOUND _HRESULT_TYPEDEF_(0x88990023L)






// Cannot set the image as a target because it is either an effect or is a bitmap that does not have the D2D1_BITMAP_OPTIONS_TARGET flag set.

D2DERR_INVALID_TARGET            _HRESULT_TYPEDEF_(0x88990024L)






// Cannot draw with a bitmap that is currently bound as the target bitmap.

D2DERR_BITMAP_BOUND_AS_TARGET    _HRESULT_TYPEDEF_(0x88990025L)






// D3D Device does not have sufficient capabilities to perform the requested action.

D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES _HRESULT_TYPEDEF_(0x88990026L)






// The graph could not be rendered with the context's current tiling settings.

D2DERR_INTERMEDIATE_TOO_LARGE    _HRESULT_TYPEDEF_(0x88990027L)






// The CLSID provided to Unregister did not correspond to a registered effect.

D2DERR_EFFECT_IS_NOT_REGISTERED  _HRESULT_TYPEDEF_(0x88990028L)






// The specified property does not exist.

D2DERR_INVALID_PROPERTY          _HRESULT_TYPEDEF_(0x88990029L)






// The specified sub-property does not exist.

D2DERR_NO_SUBPROPERTIES          _HRESULT_TYPEDEF_(0x8899002AL)






// AddPage or Close called after print job is already closed.

D2DERR_PRINT_JOB_CLOSED          _HRESULT_TYPEDEF_(0x8899002BL)






// Error during print control creation. Indicates that none of the package target types (representing printer formats) are supported by Direct2D print control.

D2DERR_PRINT_FORMAT_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x8899002CL)






// An effect attempted to use a transform with too many inputs.

D2DERR_TOO_MANY_TRANSFORM_INPUTS _HRESULT_TYPEDEF_(0x8899002DL)






// An error was encountered while decoding or parsing the requested glyph image.

D2DERR_INVALID_GLYPH_IMAGE       _HRESULT_TYPEDEF_(0x8899002EL)



// DirectWrite







// Indicates an error in an input file such as a font file.

DWRITE_E_FILEFORMAT              _HRESULT_TYPEDEF_(0x88985000L)






// Indicates an error originating in DirectWrite code, which is not expected to occur but is safe to recover from.

DWRITE_E_UNEXPECTED              _HRESULT_TYPEDEF_(0x88985001L)






// Indicates the specified font does not exist.

DWRITE_E_NOFONT                  _HRESULT_TYPEDEF_(0x88985002L)






// A font file could not be opened because the file, directory, network location, drive, or other storage location does not exist or is unavailable.

DWRITE_E_FILENOTFOUND            _HRESULT_TYPEDEF_(0x88985003L)






// A font file exists but could not be opened due to access denied, sharing violation, or similar error.

DWRITE_E_FILEACCESS              _HRESULT_TYPEDEF_(0x88985004L)






// A font collection is obsolete due to changes in the system.

DWRITE_E_FONTCOLLECTIONOBSOLETE  _HRESULT_TYPEDEF_(0x88985005L)






// The given interface is already registered.

DWRITE_E_ALREADYREGISTERED       _HRESULT_TYPEDEF_(0x88985006L)






// The font cache contains invalid data.

DWRITE_E_CACHEFORMAT             _HRESULT_TYPEDEF_(0x88985007L)






// A font cache file corresponds to a different version of DirectWrite.

DWRITE_E_CACHEVERSION            _HRESULT_TYPEDEF_(0x88985008L)






// The operation is not supported for this type of font.

DWRITE_E_UNSUPPORTEDOPERATION    _HRESULT_TYPEDEF_(0x88985009L)






// The version of the text renderer interface is not compatible.

DWRITE_E_TEXTRENDERERINCOMPATIBLE _HRESULT_TYPEDEF_(0x8898500AL)






// The flow direction conflicts with the reading direction. They must be perpendicular to each other.

DWRITE_E_FLOWDIRECTIONCONFLICTS  _HRESULT_TYPEDEF_(0x8898500BL)






// The font or glyph run does not contain any colored glyphs.

DWRITE_E_NOCOLOR                 _HRESULT_TYPEDEF_(0x8898500CL)






// A font resource could not be accessed because it is remote.

DWRITE_E_REMOTEFONT              _HRESULT_TYPEDEF_(0x8898500DL)






// A font download was canceled.

DWRITE_E_DOWNLOADCANCELLED       _HRESULT_TYPEDEF_(0x8898500EL)






// A font download failed.

DWRITE_E_DOWNLOADFAILED          _HRESULT_TYPEDEF_(0x8898500FL)






// A font download request was not added or a download failed because there are too many active downloads.

DWRITE_E_TOOMANYDOWNLOADS        _HRESULT_TYPEDEF_(0x88985010L)



// Windows Codecs







// The codec is in the wrong state.

WINCODEC_ERR_WRONGSTATE          _HRESULT_TYPEDEF_(0x88982F04L)






// The value is out of range.

WINCODEC_ERR_VALUEOUTOFRANGE     _HRESULT_TYPEDEF_(0x88982F05L)






// The image format is unknown.

WINCODEC_ERR_UNKNOWNIMAGEFORMAT  _HRESULT_TYPEDEF_(0x88982F07L)






// The SDK version is unsupported.

WINCODEC_ERR_UNSUPPORTEDVERSION  _HRESULT_TYPEDEF_(0x88982F0BL)






// The component is not initialized.

WINCODEC_ERR_NOTINITIALIZED      _HRESULT_TYPEDEF_(0x88982F0CL)






// There is already an outstanding read or write lock.

WINCODEC_ERR_ALREADYLOCKED       _HRESULT_TYPEDEF_(0x88982F0DL)






// The specified bitmap property cannot be found.

WINCODEC_ERR_PROPERTYNOTFOUND    _HRESULT_TYPEDEF_(0x88982F40L)






// The bitmap codec does not support the bitmap property.

WINCODEC_ERR_PROPERTYNOTSUPPORTED _HRESULT_TYPEDEF_(0x88982F41L)






// The bitmap property size is invalid.

WINCODEC_ERR_PROPERTYSIZE        _HRESULT_TYPEDEF_(0x88982F42L)






// An unknown error has occurred.

WINCODEC_ERR_CODECPRESENT        _HRESULT_TYPEDEF_(0x88982F43L)






// The bitmap codec does not support a thumbnail.

WINCODEC_ERR_CODECNOTHUMBNAIL    _HRESULT_TYPEDEF_(0x88982F44L)






// The bitmap palette is unavailable.

WINCODEC_ERR_PALETTEUNAVAILABLE  _HRESULT_TYPEDEF_(0x88982F45L)






// Too many scanlines were requested.

WINCODEC_ERR_CODECTOOMANYSCANLINES _HRESULT_TYPEDEF_(0x88982F46L)






// An internal error occurred.

WINCODEC_ERR_INTERNALERROR       _HRESULT_TYPEDEF_(0x88982F48L)






// The bitmap bounds do not match the bitmap dimensions.

WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS _HRESULT_TYPEDEF_(0x88982F49L)






// The component cannot be found.

WINCODEC_ERR_COMPONENTNOTFOUND   _HRESULT_TYPEDEF_(0x88982F50L)






// The bitmap size is outside the valid range.

WINCODEC_ERR_IMAGESIZEOUTOFRANGE _HRESULT_TYPEDEF_(0x88982F51L)






// There is too much metadata to be written to the bitmap.

WINCODEC_ERR_TOOMUCHMETADATA     _HRESULT_TYPEDEF_(0x88982F52L)






// The image is unrecognized.

WINCODEC_ERR_BADIMAGE            _HRESULT_TYPEDEF_(0x88982F60L)






// The image header is unrecognized.

WINCODEC_ERR_BADHEADER           _HRESULT_TYPEDEF_(0x88982F61L)






// The bitmap frame is missing.

WINCODEC_ERR_FRAMEMISSING        _HRESULT_TYPEDEF_(0x88982F62L)






// The image metadata header is unrecognized.

WINCODEC_ERR_BADMETADATAHEADER   _HRESULT_TYPEDEF_(0x88982F63L)






// The stream data is unrecognized.

WINCODEC_ERR_BADSTREAMDATA       _HRESULT_TYPEDEF_(0x88982F70L)






// Failed to write to the stream.

WINCODEC_ERR_STREAMWRITE         _HRESULT_TYPEDEF_(0x88982F71L)






// Failed to read from the stream.

WINCODEC_ERR_STREAMREAD          _HRESULT_TYPEDEF_(0x88982F72L)






// The stream is not available.

WINCODEC_ERR_STREAMNOTAVAILABLE  _HRESULT_TYPEDEF_(0x88982F73L)






// The bitmap pixel format is unsupported.

WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT _HRESULT_TYPEDEF_(0x88982F80L)






// The operation is unsupported.

WINCODEC_ERR_UNSUPPORTEDOPERATION _HRESULT_TYPEDEF_(0x88982F81L)






// The component registration is invalid.

WINCODEC_ERR_INVALIDREGISTRATION _HRESULT_TYPEDEF_(0x88982F8AL)






// The component initialization has failed.

WINCODEC_ERR_COMPONENTINITIALIZEFAILURE _HRESULT_TYPEDEF_(0x88982F8BL)






// The buffer allocated is insufficient.

WINCODEC_ERR_INSUFFICIENTBUFFER  _HRESULT_TYPEDEF_(0x88982F8CL)






// Duplicate metadata is present.

WINCODEC_ERR_DUPLICATEMETADATAPRESENT _HRESULT_TYPEDEF_(0x88982F8DL)






// The bitmap property type is unexpected.

WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE _HRESULT_TYPEDEF_(0x88982F8EL)






// The size is unexpected.

WINCODEC_ERR_UNEXPECTEDSIZE      _HRESULT_TYPEDEF_(0x88982F8FL)






// The property query is invalid.

WINCODEC_ERR_INVALIDQUERYREQUEST _HRESULT_TYPEDEF_(0x88982F90L)






// The metadata type is unexpected.

WINCODEC_ERR_UNEXPECTEDMETADATATYPE _HRESULT_TYPEDEF_(0x88982F91L)






// The specified bitmap property is only valid at root level.

WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT _HRESULT_TYPEDEF_(0x88982F92L)






// The query string contains an invalid character.

WINCODEC_ERR_INVALIDQUERYCHARACTER _HRESULT_TYPEDEF_(0x88982F93L)






// Windows Codecs received an error from the Win32 system.

WINCODEC_ERR_WIN32ERROR          _HRESULT_TYPEDEF_(0x88982F94L)






// The requested level of detail is not present.

WINCODEC_ERR_INVALIDPROGRESSIVELEVEL _HRESULT_TYPEDEF_(0x88982F95L)






// The scan index is invalid.

WINCODEC_ERR_INVALIDJPEGSCANINDEX _HRESULT_TYPEDEF_(0x88982F96L)



// MIL/DWM







// MILERR_OBJECTBUSY

MILERR_OBJECTBUSY                _HRESULT_TYPEDEF_(0x88980001L)






// MILERR_INSUFFICIENTBUFFER

MILERR_INSUFFICIENTBUFFER        _HRESULT_TYPEDEF_(0x88980002L)






// MILERR_WIN32ERROR

MILERR_WIN32ERROR                _HRESULT_TYPEDEF_(0x88980003L)






// MILERR_SCANNER_FAILED

MILERR_SCANNER_FAILED            _HRESULT_TYPEDEF_(0x88980004L)






// MILERR_SCREENACCESSDENIED

MILERR_SCREENACCESSDENIED        _HRESULT_TYPEDEF_(0x88980005L)






// MILERR_DISPLAYSTATEINVALID

MILERR_DISPLAYSTATEINVALID       _HRESULT_TYPEDEF_(0x88980006L)






// MILERR_NONINVERTIBLEMATRIX

MILERR_NONINVERTIBLEMATRIX       _HRESULT_TYPEDEF_(0x88980007L)






// MILERR_ZEROVECTOR

MILERR_ZEROVECTOR                _HRESULT_TYPEDEF_(0x88980008L)






// MILERR_TERMINATED

MILERR_TERMINATED                _HRESULT_TYPEDEF_(0x88980009L)






// MILERR_BADNUMBER

MILERR_BADNUMBER                 _HRESULT_TYPEDEF_(0x8898000AL)






// An internal error (MIL bug) occurred. On checked builds, an assert would be raised.

MILERR_INTERNALERROR             _HRESULT_TYPEDEF_(0x88980080L)






// The display format we need to render is not supported by the hardware device.

MILERR_DISPLAYFORMATNOTSUPPORTED _HRESULT_TYPEDEF_(0x88980084L)






// A call to this method is invalid.

MILERR_INVALIDCALL               _HRESULT_TYPEDEF_(0x88980085L)






// Lock attempted on an already locked object.

MILERR_ALREADYLOCKED             _HRESULT_TYPEDEF_(0x88980086L)






// Unlock attempted on an unlocked object.

MILERR_NOTLOCKED                 _HRESULT_TYPEDEF_(0x88980087L)






// No algorithm available to render text with this device

MILERR_DEVICECANNOTRENDERTEXT    _HRESULT_TYPEDEF_(0x88980088L)






// Some glyph bitmaps, required for glyph run rendering, are not contained in glyph cache.

MILERR_GLYPHBITMAPMISSED         _HRESULT_TYPEDEF_(0x88980089L)






// Some glyph bitmaps in glyph cache are unexpectedly big.

MILERR_MALFORMEDGLYPHCACHE       _HRESULT_TYPEDEF_(0x8898008AL)






// Marker error for known Win32 errors that are currently being ignored by the compositor. This is to avoid returning S_OK when an error has occurred, but still unwind the stack in the correct location.

MILERR_GENERIC_IGNORE            _HRESULT_TYPEDEF_(0x8898008BL)






// Guideline coordinates are not sorted properly or contain NaNs.

MILERR_MALFORMED_GUIDELINE_DATA  _HRESULT_TYPEDEF_(0x8898008CL)






// No HW rendering device is available for this operation.

MILERR_NO_HARDWARE_DEVICE        _HRESULT_TYPEDEF_(0x8898008DL)






// There has been a presentation error that may be recoverable. The caller needs to recreate, rerender the entire frame, and reattempt present.
// There are two known case for this: 1) D3D Driver Internal error 2) D3D E_FAIL 2a) Unknown root cause b) When resizing too quickly for DWM and D3D stay in sync

MILERR_NEED_RECREATE_AND_PRESENT _HRESULT_TYPEDEF_(0x8898008EL)






// The object has already been initialized.

MILERR_ALREADY_INITIALIZED       _HRESULT_TYPEDEF_(0x8898008FL)






// The size of the object does not match the expected size.

MILERR_MISMATCHED_SIZE           _HRESULT_TYPEDEF_(0x88980090L)






// No Redirection surface available.

MILERR_NO_REDIRECTION_SURFACE_AVAILABLE _HRESULT_TYPEDEF_(0x88980091L)






// Remoting of this content is not supported.

MILERR_REMOTING_NOT_SUPPORTED    _HRESULT_TYPEDEF_(0x88980092L)






// Queued Presents are not supported.

MILERR_QUEUED_PRESENT_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x88980093L)






// Queued Presents are not being used.

MILERR_NOT_QUEUING_PRESENTS      _HRESULT_TYPEDEF_(0x88980094L)






// No redirection surface was available. Caller should retry the call.

MILERR_NO_REDIRECTION_SURFACE_RETRY_LATER _HRESULT_TYPEDEF_(0x88980095L)






// Shader construction failed because it was too complex.

MILERR_TOOMANYSHADERELEMNTS      _HRESULT_TYPEDEF_(0x88980096L)






// MROW attempt to get a read lock failed.

MILERR_MROW_READLOCK_FAILED      _HRESULT_TYPEDEF_(0x88980097L)






// MROW attempt to update the data failed because another update was outstanding.

MILERR_MROW_UPDATE_FAILED        _HRESULT_TYPEDEF_(0x88980098L)






// Shader compilation failed.

MILERR_SHADER_COMPILE_FAILED     _HRESULT_TYPEDEF_(0x88980099L)






// Requested DX redirection surface size exceeded maximum texture size.

MILERR_MAX_TEXTURE_SIZE_EXCEEDED _HRESULT_TYPEDEF_(0x8898009AL)






// QueryPerformanceCounter returned a time in the past.

MILERR_QPC_TIME_WENT_BACKWARD    _HRESULT_TYPEDEF_(0x8898009BL)






// Primary Display device returned an invalid refresh rate.

MILERR_DXGI_ENUMERATION_OUT_OF_SYNC _HRESULT_TYPEDEF_(0x8898009DL)






// DWM can not find the adapter specified by the LUID.

MILERR_ADAPTER_NOT_FOUND         _HRESULT_TYPEDEF_(0x8898009EL)






// The requested bitmap color space is not supported.

MILERR_COLORSPACE_NOT_SUPPORTED  _HRESULT_TYPEDEF_(0x8898009FL)






// The requested bitmap pre-filtering state is not supported.

MILERR_PREFILTER_NOT_SUPPORTED   _HRESULT_TYPEDEF_(0x889800A0L)






// Access is denied to the requested bitmap for the specified display id.

MILERR_DISPLAYID_ACCESS_DENIED   _HRESULT_TYPEDEF_(0x889800A1L)

// Composition engine errors





// UCEERR_INVALIDPACKETHEADER

UCEERR_INVALIDPACKETHEADER       _HRESULT_TYPEDEF_(0x88980400L)






// UCEERR_UNKNOWNPACKET

UCEERR_UNKNOWNPACKET             _HRESULT_TYPEDEF_(0x88980401L)






// UCEERR_ILLEGALPACKET

UCEERR_ILLEGALPACKET             _HRESULT_TYPEDEF_(0x88980402L)






// UCEERR_MALFORMEDPACKET

UCEERR_MALFORMEDPACKET           _HRESULT_TYPEDEF_(0x88980403L)






// UCEERR_ILLEGALHANDLE

UCEERR_ILLEGALHANDLE             _HRESULT_TYPEDEF_(0x88980404L)






// UCEERR_HANDLELOOKUPFAILED

UCEERR_HANDLELOOKUPFAILED        _HRESULT_TYPEDEF_(0x88980405L)






// UCEERR_RENDERTHREADFAILURE

UCEERR_RENDERTHREADFAILURE       _HRESULT_TYPEDEF_(0x88980406L)






// UCEERR_CTXSTACKFRSTTARGETNULL

UCEERR_CTXSTACKFRSTTARGETNULL    _HRESULT_TYPEDEF_(0x88980407L)






// UCEERR_CONNECTIONIDLOOKUPFAILED

UCEERR_CONNECTIONIDLOOKUPFAILED  _HRESULT_TYPEDEF_(0x88980408L)






// UCEERR_BLOCKSFULL

UCEERR_BLOCKSFULL                _HRESULT_TYPEDEF_(0x88980409L)






// UCEERR_MEMORYFAILURE

UCEERR_MEMORYFAILURE             _HRESULT_TYPEDEF_(0x8898040AL)






// UCEERR_PACKETRECORDOUTOFRANGE

UCEERR_PACKETRECORDOUTOFRANGE    _HRESULT_TYPEDEF_(0x8898040BL)






// UCEERR_ILLEGALRECORDTYPE

UCEERR_ILLEGALRECORDTYPE         _HRESULT_TYPEDEF_(0x8898040CL)






// UCEERR_OUTOFHANDLES

UCEERR_OUTOFHANDLES              _HRESULT_TYPEDEF_(0x8898040DL)






// UCEERR_UNCHANGABLE_UPDATE_ATTEMPTED

UCEERR_UNCHANGABLE_UPDATE_ATTEMPTED _HRESULT_TYPEDEF_(0x8898040EL)






// UCEERR_NO_MULTIPLE_WORKER_THREADS

UCEERR_NO_MULTIPLE_WORKER_THREADS _HRESULT_TYPEDEF_(0x8898040FL)






// UCEERR_REMOTINGNOTSUPPORTED

UCEERR_REMOTINGNOTSUPPORTED      _HRESULT_TYPEDEF_(0x88980410L)






// UCEERR_MISSINGENDCOMMAND

UCEERR_MISSINGENDCOMMAND         _HRESULT_TYPEDEF_(0x88980411L)






// UCEERR_MISSINGBEGINCOMMAND

UCEERR_MISSINGBEGINCOMMAND       _HRESULT_TYPEDEF_(0x88980412L)






// UCEERR_CHANNELSYNCTIMEDOUT

UCEERR_CHANNELSYNCTIMEDOUT       _HRESULT_TYPEDEF_(0x88980413L)






// UCEERR_CHANNELSYNCABANDONED

UCEERR_CHANNELSYNCABANDONED      _HRESULT_TYPEDEF_(0x88980414L)






// UCEERR_UNSUPPORTEDTRANSPORTVERSION

UCEERR_UNSUPPORTEDTRANSPORTVERSION _HRESULT_TYPEDEF_(0x88980415L)






// UCEERR_TRANSPORTUNAVAILABLE

UCEERR_TRANSPORTUNAVAILABLE      _HRESULT_TYPEDEF_(0x88980416L)






// UCEERR_FEEDBACK_UNSUPPORTED

UCEERR_FEEDBACK_UNSUPPORTED      _HRESULT_TYPEDEF_(0x88980417L)






// UCEERR_COMMANDTRANSPORTDENIED

UCEERR_COMMANDTRANSPORTDENIED    _HRESULT_TYPEDEF_(0x88980418L)






// UCEERR_GRAPHICSSTREAMUNAVAILABLE

UCEERR_GRAPHICSSTREAMUNAVAILABLE _HRESULT_TYPEDEF_(0x88980419L)






// UCEERR_GRAPHICSSTREAMALREADYOPEN

UCEERR_GRAPHICSSTREAMALREADYOPEN _HRESULT_TYPEDEF_(0x88980420L)






// UCEERR_TRANSPORTDISCONNECTED

UCEERR_TRANSPORTDISCONNECTED     _HRESULT_TYPEDEF_(0x88980421L)






// UCEERR_TRANSPORTOVERLOADED

UCEERR_TRANSPORTOVERLOADED       _HRESULT_TYPEDEF_(0x88980422L)






// UCEERR_PARTITION_ZOMBIED

UCEERR_PARTITION_ZOMBIED         _HRESULT_TYPEDEF_(0x88980423L)

// MIL AV Specific errors





// MILAVERR_NOCLOCK

MILAVERR_NOCLOCK                 _HRESULT_TYPEDEF_(0x88980500L)






// MILAVERR_NOMEDIATYPE

MILAVERR_NOMEDIATYPE             _HRESULT_TYPEDEF_(0x88980501L)






// MILAVERR_NOVIDEOMIXER

MILAVERR_NOVIDEOMIXER            _HRESULT_TYPEDEF_(0x88980502L)






// MILAVERR_NOVIDEOPRESENTER

MILAVERR_NOVIDEOPRESENTER        _HRESULT_TYPEDEF_(0x88980503L)






// MILAVERR_NOREADYFRAMES

MILAVERR_NOREADYFRAMES           _HRESULT_TYPEDEF_(0x88980504L)






// MILAVERR_MODULENOTLOADED

MILAVERR_MODULENOTLOADED         _HRESULT_TYPEDEF_(0x88980505L)






// MILAVERR_WMPFACTORYNOTREGISTERED

MILAVERR_WMPFACTORYNOTREGISTERED _HRESULT_TYPEDEF_(0x88980506L)






// MILAVERR_INVALIDWMPVERSION

MILAVERR_INVALIDWMPVERSION       _HRESULT_TYPEDEF_(0x88980507L)






// MILAVERR_INSUFFICIENTVIDEORESOURCES

MILAVERR_INSUFFICIENTVIDEORESOURCES _HRESULT_TYPEDEF_(0x88980508L)






// MILAVERR_VIDEOACCELERATIONNOTAVAILABLE

MILAVERR_VIDEOACCELERATIONNOTAVAILABLE _HRESULT_TYPEDEF_(0x88980509L)






// MILAVERR_REQUESTEDTEXTURETOOBIG

MILAVERR_REQUESTEDTEXTURETOOBIG  _HRESULT_TYPEDEF_(0x8898050AL)






// MILAVERR_SEEKFAILED

MILAVERR_SEEKFAILED              _HRESULT_TYPEDEF_(0x8898050BL)






// MILAVERR_UNEXPECTEDWMPFAILURE

MILAVERR_UNEXPECTEDWMPFAILURE    _HRESULT_TYPEDEF_(0x8898050CL)






// MILAVERR_MEDIAPLAYERCLOSED

MILAVERR_MEDIAPLAYERCLOSED       _HRESULT_TYPEDEF_(0x8898050DL)






// MILAVERR_UNKNOWNHARDWAREERROR

MILAVERR_UNKNOWNHARDWAREERROR    _HRESULT_TYPEDEF_(0x8898050EL)

// MIL Bitmap Effect errors





// MILEFFECTSERR_UNKNOWNPROPERTY

MILEFFECTSERR_UNKNOWNPROPERTY    _HRESULT_TYPEDEF_(0x8898060EL)






// MILEFFECTSERR_EFFECTNOTPARTOFGROUP

MILEFFECTSERR_EFFECTNOTPARTOFGROUP _HRESULT_TYPEDEF_(0x8898060FL)






// MILEFFECTSERR_NOINPUTSOURCEATTACHED

MILEFFECTSERR_NOINPUTSOURCEATTACHED _HRESULT_TYPEDEF_(0x88980610L)






// MILEFFECTSERR_CONNECTORNOTCONNECTED

MILEFFECTSERR_CONNECTORNOTCONNECTED _HRESULT_TYPEDEF_(0x88980611L)






// MILEFFECTSERR_CONNECTORNOTASSOCIATEDWITHEFFECT

MILEFFECTSERR_CONNECTORNOTASSOCIATEDWITHEFFECT _HRESULT_TYPEDEF_(0x88980612L)






// MILEFFECTSERR_RESERVED

MILEFFECTSERR_RESERVED           _HRESULT_TYPEDEF_(0x88980613L)






// MILEFFECTSERR_CYCLEDETECTED

MILEFFECTSERR_CYCLEDETECTED      _HRESULT_TYPEDEF_(0x88980614L)






// MILEFFECTSERR_EFFECTINMORETHANONEGRAPH

MILEFFECTSERR_EFFECTINMORETHANONEGRAPH _HRESULT_TYPEDEF_(0x88980615L)






// MILEFFECTSERR_EFFECTALREADYINAGRAPH

MILEFFECTSERR_EFFECTALREADYINAGRAPH _HRESULT_TYPEDEF_(0x88980616L)






// MILEFFECTSERR_EFFECTHASNOCHILDREN

MILEFFECTSERR_EFFECTHASNOCHILDREN _HRESULT_TYPEDEF_(0x88980617L)






// MILEFFECTSERR_ALREADYATTACHEDTOLISTENER

MILEFFECTSERR_ALREADYATTACHEDTOLISTENER _HRESULT_TYPEDEF_(0x88980618L)






// MILEFFECTSERR_NOTAFFINETRANSFORM

MILEFFECTSERR_NOTAFFINETRANSFORM _HRESULT_TYPEDEF_(0x88980619L)






// MILEFFECTSERR_EMPTYBOUNDS

MILEFFECTSERR_EMPTYBOUNDS        _HRESULT_TYPEDEF_(0x8898061AL)






// MILEFFECTSERR_OUTPUTSIZETOOLARGE

MILEFFECTSERR_OUTPUTSIZETOOLARGE _HRESULT_TYPEDEF_(0x8898061BL)

// DWM specific errors





// DWMERR_STATE_TRANSITION_FAILED

DWMERR_STATE_TRANSITION_FAILED   _HRESULT_TYPEDEF_(0x88980700L)






// DWMERR_THEME_FAILED

DWMERR_THEME_FAILED              _HRESULT_TYPEDEF_(0x88980701L)






// DWMERR_CATASTROPHIC_FAILURE

DWMERR_CATASTROPHIC_FAILURE      _HRESULT_TYPEDEF_(0x88980702L)



// DirectComposition







// DCOMPOSITION_ERROR_WINDOW_ALREADY_COMPOSED

DCOMPOSITION_ERROR_WINDOW_ALREADY_COMPOSED _HRESULT_TYPEDEF_(0x88980800L)






// DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED

DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED _HRESULT_TYPEDEF_(0x88980801L)






// DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED

DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED _HRESULT_TYPEDEF_(0x88980802L)



// OnlineId







// Authentication target is invalid or not configured correctly.

ONL_E_INVALID_AUTHENTICATION_TARGET _HRESULT_TYPEDEF_(0x80860001L)






// Your application cannot get the Online Id properties due to the Terms of Use accepted by the user.

ONL_E_ACCESS_DENIED_BY_TOU       _HRESULT_TYPEDEF_(0x80860002L)






// The application requesting authentication tokens is either disabled or incorrectly configured.

ONL_E_INVALID_APPLICATION        _HRESULT_TYPEDEF_(0x80860003L)






// Online Id password must be updated before signin.

ONL_E_PASSWORD_UPDATE_REQUIRED   _HRESULT_TYPEDEF_(0x80860004L)






// Online Id account properties must be updated before signin.

ONL_E_ACCOUNT_UPDATE_REQUIRED    _HRESULT_TYPEDEF_(0x80860005L)






// To help protect your Online Id account you must signin again.

ONL_E_FORCESIGNIN                _HRESULT_TYPEDEF_(0x80860006L)






// Online Id account was locked because there have been too many attempts to sign in.

ONL_E_ACCOUNT_LOCKED             _HRESULT_TYPEDEF_(0x80860007L)






// Online Id account requires parental consent before proceeding.

ONL_E_PARENTAL_CONSENT_REQUIRED  _HRESULT_TYPEDEF_(0x80860008L)






// Online Id signin name is not yet verified. Email verification is required before signin.

ONL_E_EMAIL_VERIFICATION_REQUIRED _HRESULT_TYPEDEF_(0x80860009L)






// We have noticed some unusual activity in your Online Id account. Your action is needed to make sure no one else is using your account.

ONL_E_ACCOUNT_SUSPENDED_COMPROIMISE _HRESULT_TYPEDEF_(0x8086000AL)






// We detected some suspicious activity with your Online Id account. To help protect you, we've temporarily blocked your account.

ONL_E_ACCOUNT_SUSPENDED_ABUSE    _HRESULT_TYPEDEF_(0x8086000BL)






// User interaction is required for authentication.

ONL_E_ACTION_REQUIRED            _HRESULT_TYPEDEF_(0x8086000CL)






// User has reached the maximum device associations per user limit.

ONL_CONNECTION_COUNT_LIMIT       _HRESULT_TYPEDEF_(0x8086000DL)






// Cannot sign out from the application since the user account is connected.

ONL_E_CONNECTED_ACCOUNT_CAN_NOT_SIGNOUT _HRESULT_TYPEDEF_(0x8086000EL)






// User authentication is required for this operation.

ONL_E_USER_AUTHENTICATION_REQUIRED _HRESULT_TYPEDEF_(0x8086000FL)






// We want to make sure this is you. User interaction is required for authentication.

ONL_E_REQUEST_THROTTLED          _HRESULT_TYPEDEF_(0x80860010L)



// Facility Shell Error codes







// The maximum number of items for the access list has been reached. An item must be removed before another item is added.

FA_E_MAX_PERSISTED_ITEMS_REACHED _HRESULT_TYPEDEF_(0x80270220L)






// Cannot access Homegroup. Homegroup may not be set up or may have encountered an error.

FA_E_HOMEGROUP_NOT_AVAILABLE     _HRESULT_TYPEDEF_(0x80270222L)






// This app can't start because the screen resolution is below 1024x768. Choose a higher screen resolution and then try again.

E_MONITOR_RESOLUTION_TOO_LOW     _HRESULT_TYPEDEF_(0x80270250L)






// This app can't be activated from an elevated context.

E_ELEVATED_ACTIVATION_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80270251L)






// This app can't be activated when UAC is disabled.

E_UAC_DISABLED                   _HRESULT_TYPEDEF_(0x80270252L)






// This app can't be activated by the Built-in Administrator.

E_FULL_ADMIN_NOT_SUPPORTED       _HRESULT_TYPEDEF_(0x80270253L)






// This app does not support the contract specified or is not installed.

E_APPLICATION_NOT_REGISTERED     _HRESULT_TYPEDEF_(0x80270254L)






// This app has multiple extensions registered to support the specified contract. Activation by AppUserModelId is ambiguous.

E_MULTIPLE_EXTENSIONS_FOR_APPLICATION _HRESULT_TYPEDEF_(0x80270255L)






// This app's package family has more than one package installed. This is not supported.

E_MULTIPLE_PACKAGES_FOR_FAMILY   _HRESULT_TYPEDEF_(0x80270256L)






// The app manager is required to activate applications, but is not running.

E_APPLICATION_MANAGER_NOT_RUNNING _HRESULT_TYPEDEF_(0x80270257L)






// The Store was launched instead of the specified app because the app's package was in an invalid state.

S_STORE_LAUNCHED_FOR_REMEDIATION _HRESULT_TYPEDEF_(0x00270258L)






// This app failed to launch, but the error was handled with a dialog.

S_APPLICATION_ACTIVATION_ERROR_HANDLED_BY_DIALOG _HRESULT_TYPEDEF_(0x00270259L)






// The app didn't start in the required time.

E_APPLICATION_ACTIVATION_TIMED_OUT _HRESULT_TYPEDEF_(0x8027025AL)






// The app didn't start.

E_APPLICATION_ACTIVATION_EXEC_FAILURE _HRESULT_TYPEDEF_(0x8027025BL)






// This app failed to launch because of an issue with its license. Please try again in a moment.

E_APPLICATION_TEMPORARY_LICENSE_ERROR _HRESULT_TYPEDEF_(0x8027025CL)






// This app failed to launch because its trial license has expired.

E_APPLICATION_TRIAL_LICENSE_EXPIRED _HRESULT_TYPEDEF_(0x8027025DL)






// Please choose a folder on a drive that's formatted with the NTFS file system.

E_SKYDRIVE_ROOT_TARGET_FILE_SYSTEM_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80270260L)






// This location is already being used. Please choose a different location.

E_SKYDRIVE_ROOT_TARGET_OVERLAP   _HRESULT_TYPEDEF_(0x80270261L)






// This location cannot be indexed. Please choose a different location.

E_SKYDRIVE_ROOT_TARGET_CANNOT_INDEX _HRESULT_TYPEDEF_(0x80270262L)






// Sorry, the action couldn't be completed because the file hasn't finished uploading. Try again later.

E_SKYDRIVE_FILE_NOT_UPLOADED     _HRESULT_TYPEDEF_(0x80270263L)






// Sorry, the action couldn't be completed.

E_SKYDRIVE_UPDATE_AVAILABILITY_FAIL _HRESULT_TYPEDEF_(0x80270264L)






// This content can only be moved to a folder. To move the content to this drive, please choose or create a folder.

E_SKYDRIVE_ROOT_TARGET_VOLUME_ROOT_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x80270265L)


// Sync Engine File Error Codes






// The file size is larger than supported by the sync engine.

E_SYNCENGINE_FILE_SIZE_OVER_LIMIT _HRESULT_TYPEDEF_(0x8802B001L)






// The file cannot be uploaded because it doesn't fit in the user's available service provided storage space.

E_SYNCENGINE_FILE_SIZE_EXCEEDS_REMAINING_QUOTA _HRESULT_TYPEDEF_(0x8802B002L)






// The file name contains invalid characters.

E_SYNCENGINE_UNSUPPORTED_FILE_NAME _HRESULT_TYPEDEF_(0x8802B003L)






// The maximum file count has been reached for this folder in the sync engine.

E_SYNCENGINE_FOLDER_ITEM_COUNT_LIMIT_EXCEEDED _HRESULT_TYPEDEF_(0x8802B004L)






// The file sync has been delegated to another program and has run into an issue.

E_SYNCENGINE_FILE_SYNC_PARTNER_ERROR _HRESULT_TYPEDEF_(0x8802B005L)






// Sync has been delayed due to a throttling request from the service.

E_SYNCENGINE_SYNC_PAUSED_BY_SERVICE _HRESULT_TYPEDEF_(0x8802B006L)


// Sync Engine Stream Resolver Errors






// We can't seem to find that file. Please try again later.

E_SYNCENGINE_FILE_IDENTIFIER_UNKNOWN _HRESULT_TYPEDEF_(0x8802C002L)






// The account you're signed in with doesn't have permission to open this file.

E_SYNCENGINE_SERVICE_AUTHENTICATION_FAILED _HRESULT_TYPEDEF_(0x8802C003L)






// There was a problem connecting to the service. Please try again later.

E_SYNCENGINE_UNKNOWN_SERVICE_ERROR _HRESULT_TYPEDEF_(0x8802C004L)






// Sorry, there was a problem downloading the file.

E_SYNCENGINE_SERVICE_RETURNED_UNEXPECTED_SIZE _HRESULT_TYPEDEF_(0x8802C005L)






// We're having trouble downloading the file right now. Please try again later.

E_SYNCENGINE_REQUEST_BLOCKED_BY_SERVICE _HRESULT_TYPEDEF_(0x8802C006L)






// We're having trouble downloading the file right now. Please try again later.

E_SYNCENGINE_REQUEST_BLOCKED_DUE_TO_CLIENT_ERROR _HRESULT_TYPEDEF_(0x8802C007L)


// Sync Engine Global Errors






// The sync engine does not have permissions to access a local folder under the sync root.

E_SYNCENGINE_FOLDER_INACCESSIBLE _HRESULT_TYPEDEF_(0x8802D001L)






// The folder name contains invalid characters.

E_SYNCENGINE_UNSUPPORTED_FOLDER_NAME _HRESULT_TYPEDEF_(0x8802D002L)






// The sync engine is not allowed to run in your current market.

E_SYNCENGINE_UNSUPPORTED_MARKET  _HRESULT_TYPEDEF_(0x8802D003L)






// All files and folders can't be uploaded because a path of a file or folder is too long.

E_SYNCENGINE_PATH_LENGTH_LIMIT_EXCEEDED _HRESULT_TYPEDEF_(0x8802D004L)






// All file and folders cannot be synchronized because a path of a file or folder would exceed the local path limit.

E_SYNCENGINE_REMOTE_PATH_LENGTH_LIMIT_EXCEEDED _HRESULT_TYPEDEF_(0x8802D005L)






// Updates are needed in order to use the sync engine.

E_SYNCENGINE_CLIENT_UPDATE_NEEDED _HRESULT_TYPEDEF_(0x8802D006L)






// The sync engine needs to authenticate with a proxy server.

E_SYNCENGINE_PROXY_AUTHENTICATION_REQUIRED _HRESULT_TYPEDEF_(0x8802D007L)






// There was a problem setting up the storage services for the account.

E_SYNCENGINE_STORAGE_SERVICE_PROVISIONING_FAILED _HRESULT_TYPEDEF_(0x8802D008L)






// Files can't be uploaded because there's an unsupported reparse point.

E_SYNCENGINE_UNSUPPORTED_REPARSE_POINT _HRESULT_TYPEDEF_(0x8802D009L)






// The service has blocked your account from accessing the storage service.

E_SYNCENGINE_STORAGE_SERVICE_BLOCKED _HRESULT_TYPEDEF_(0x8802D00AL)






// The action can't be performed right now because this folder is being moved. Please try again later.

E_SYNCENGINE_FOLDER_IN_REDIRECTION _HRESULT_TYPEDEF_(0x8802D00BL)



// EAS







// Windows cannot evaluate this EAS policy since this is not managed by the operating system.

EAS_E_POLICY_NOT_MANAGED_BY_OS   _HRESULT_TYPEDEF_(0x80550001L)






// The system can be made compliant to this EAS policy if certain actions are performed by the user.

EAS_E_POLICY_COMPLIANT_WITH_ACTIONS _HRESULT_TYPEDEF_(0x80550002L)






// The EAS policy being evaluated cannot be enforced by the system.

EAS_E_REQUESTED_POLICY_NOT_ENFORCEABLE _HRESULT_TYPEDEF_(0x80550003L)






// EAS password policies for the user cannot be evaluated as the user has a blank password.

EAS_E_CURRENT_USER_HAS_BLANK_PASSWORD _HRESULT_TYPEDEF_(0x80550004L)






// EAS password expiration policy cannot be satisfied as the password expiration interval is less than the minimum password interval of the system.

EAS_E_REQUESTED_POLICY_PASSWORD_EXPIRATION_INCOMPATIBLE _HRESULT_TYPEDEF_(0x80550005L)






// The user is not allowed to change her password.

EAS_E_USER_CANNOT_CHANGE_PASSWORD _HRESULT_TYPEDEF_(0x80550006L)






// EAS password policies cannot be evaluated as one or more admins have blank passwords.

EAS_E_ADMINS_HAVE_BLANK_PASSWORD _HRESULT_TYPEDEF_(0x80550007L)






// One or more admins are not allowed to change their password.

EAS_E_ADMINS_CANNOT_CHANGE_PASSWORD _HRESULT_TYPEDEF_(0x80550008L)






// There are other standard users present who are not allowed to change their password.

EAS_E_LOCAL_CONTROLLED_USERS_CANNOT_CHANGE_PASSWORD _HRESULT_TYPEDEF_(0x80550009L)






// The EAS password policy cannot be enforced by the connected account provider of at least one administrator.

EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CONNECTED_ADMINS _HRESULT_TYPEDEF_(0x8055000AL)






// There is at least one administrator whose connected account password needs to be changed for EAS password policy compliance.

EAS_E_CONNECTED_ADMINS_NEED_TO_CHANGE_PASSWORD _HRESULT_TYPEDEF_(0x8055000BL)






// The EAS password policy cannot be enforced by the connected account provider of the current user.

EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CURRENT_CONNECTED_USER _HRESULT_TYPEDEF_(0x8055000CL)






// The connected account password of the current user needs to be changed for EAS password policy compliance.

EAS_E_CURRENT_CONNECTED_USER_NEED_TO_CHANGE_PASSWORD _HRESULT_TYPEDEF_(0x8055000DL)






// Unsupported format.

WEB_E_UNSUPPORTED_FORMAT         _HRESULT_TYPEDEF_(0x83750001L)






// Invalid XML.

WEB_E_INVALID_XML                _HRESULT_TYPEDEF_(0x83750002L)






// Missing required element.

WEB_E_MISSING_REQUIRED_ELEMENT   _HRESULT_TYPEDEF_(0x83750003L)






// Missing required attribute.

WEB_E_MISSING_REQUIRED_ATTRIBUTE _HRESULT_TYPEDEF_(0x83750004L)






// Unexpected content.

WEB_E_UNEXPECTED_CONTENT         _HRESULT_TYPEDEF_(0x83750005L)






// Resource too large.

WEB_E_RESOURCE_TOO_LARGE         _HRESULT_TYPEDEF_(0x83750006L)






// Invalid JSON string.

WEB_E_INVALID_JSON_STRING        _HRESULT_TYPEDEF_(0x83750007L)






// Invalid JSON number.

WEB_E_INVALID_JSON_NUMBER        _HRESULT_TYPEDEF_(0x83750008L)






// JSON value not found.

WEB_E_JSON_VALUE_NOT_FOUND       _HRESULT_TYPEDEF_(0x83750009L)






// Unexpected HTTP status code.

HTTP_E_STATUS_UNEXPECTED         _HRESULT_TYPEDEF_(0x80190001L)






// Unexpected redirection status code (3xx).

HTTP_E_STATUS_UNEXPECTED_REDIRECTION _HRESULT_TYPEDEF_(0x80190003L)






// Unexpected client error status code (4xx).

HTTP_E_STATUS_UNEXPECTED_CLIENT_ERROR _HRESULT_TYPEDEF_(0x80190004L)






// Unexpected server error status code (5xx).

HTTP_E_STATUS_UNEXPECTED_SERVER_ERROR _HRESULT_TYPEDEF_(0x80190005L)






// Multiple choices (300).

HTTP_E_STATUS_AMBIGUOUS          _HRESULT_TYPEDEF_(0x8019012CL)






// Moved permanently (301).

HTTP_E_STATUS_MOVED              _HRESULT_TYPEDEF_(0x8019012DL)






// Found (302).

HTTP_E_STATUS_REDIRECT           _HRESULT_TYPEDEF_(0x8019012EL)






// See Other (303).

HTTP_E_STATUS_REDIRECT_METHOD    _HRESULT_TYPEDEF_(0x8019012FL)






// Not modified (304).

HTTP_E_STATUS_NOT_MODIFIED       _HRESULT_TYPEDEF_(0x80190130L)






// Use proxy (305).

HTTP_E_STATUS_USE_PROXY          _HRESULT_TYPEDEF_(0x80190131L)






// Temporary redirect (307).

HTTP_E_STATUS_REDIRECT_KEEP_VERB _HRESULT_TYPEDEF_(0x80190133L)






// Bad request (400).

HTTP_E_STATUS_BAD_REQUEST        _HRESULT_TYPEDEF_(0x80190190L)






// Unauthorized (401).

HTTP_E_STATUS_DENIED             _HRESULT_TYPEDEF_(0x80190191L)






// Payment required (402).

HTTP_E_STATUS_PAYMENT_REQ        _HRESULT_TYPEDEF_(0x80190192L)






// Forbidden (403).

HTTP_E_STATUS_FORBIDDEN          _HRESULT_TYPEDEF_(0x80190193L)






// Not found (404).

HTTP_E_STATUS_NOT_FOUND          _HRESULT_TYPEDEF_(0x80190194L)






// Method not allowed (405).

HTTP_E_STATUS_BAD_METHOD         _HRESULT_TYPEDEF_(0x80190195L)






// Not acceptable (406).

HTTP_E_STATUS_NONE_ACCEPTABLE    _HRESULT_TYPEDEF_(0x80190196L)






// Proxy authentication required (407).

HTTP_E_STATUS_PROXY_AUTH_REQ     _HRESULT_TYPEDEF_(0x80190197L)






// Request timeout (408).

HTTP_E_STATUS_REQUEST_TIMEOUT    _HRESULT_TYPEDEF_(0x80190198L)






// Conflict (409).

HTTP_E_STATUS_CONFLICT           _HRESULT_TYPEDEF_(0x80190199L)






// Gone (410).

HTTP_E_STATUS_GONE               _HRESULT_TYPEDEF_(0x8019019AL)






// Length required (411).

HTTP_E_STATUS_LENGTH_REQUIRED    _HRESULT_TYPEDEF_(0x8019019BL)






// Precondition failed (412).

HTTP_E_STATUS_PRECOND_FAILED     _HRESULT_TYPEDEF_(0x8019019CL)






// Request entity too large (413).

HTTP_E_STATUS_REQUEST_TOO_LARGE  _HRESULT_TYPEDEF_(0x8019019DL)






// Request-URI too long (414).

HTTP_E_STATUS_URI_TOO_LONG       _HRESULT_TYPEDEF_(0x8019019EL)






// Unsupported media type (415).

HTTP_E_STATUS_UNSUPPORTED_MEDIA  _HRESULT_TYPEDEF_(0x8019019FL)






// Requested range not satisfiable (416).

HTTP_E_STATUS_RANGE_NOT_SATISFIABLE _HRESULT_TYPEDEF_(0x801901A0L)






// Expectation failed (417).

HTTP_E_STATUS_EXPECTATION_FAILED _HRESULT_TYPEDEF_(0x801901A1L)






// Internal server error (500).

HTTP_E_STATUS_SERVER_ERROR       _HRESULT_TYPEDEF_(0x801901F4L)






// Not implemented (501).

HTTP_E_STATUS_NOT_SUPPORTED      _HRESULT_TYPEDEF_(0x801901F5L)






// Bad gateway (502).

HTTP_E_STATUS_BAD_GATEWAY        _HRESULT_TYPEDEF_(0x801901F6L)






// Service unavailable (503).

HTTP_E_STATUS_SERVICE_UNAVAIL    _HRESULT_TYPEDEF_(0x801901F7L)






// Gateway timeout (504).

HTTP_E_STATUS_GATEWAY_TIMEOUT    _HRESULT_TYPEDEF_(0x801901F8L)






// Version not supported (505).

HTTP_E_STATUS_VERSION_NOT_SUP    _HRESULT_TYPEDEF_(0x801901F9L)



// WebSocket







// Invalid operation performed by the protocol.

E_INVALID_PROTOCOL_OPERATION     _HRESULT_TYPEDEF_(0x83760001L)






// Invalid data format for the specific protocol operation.

E_INVALID_PROTOCOL_FORMAT        _HRESULT_TYPEDEF_(0x83760002L)






// Protocol extensions are not supported.

E_PROTOCOL_EXTENSIONS_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x83760003L)






// Subprotocol is not supported.

E_SUBPROTOCOL_NOT_SUPPORTED      _HRESULT_TYPEDEF_(0x83760004L)






// Incorrect protocol version.

E_PROTOCOL_VERSION_NOT_SUPPORTED _HRESULT_TYPEDEF_(0x83760005L)



// Touch and Pen Input Platform Error Codes







// Input data cannot be processed in the non-chronological order.

INPUT_E_OUT_OF_ORDER             _HRESULT_TYPEDEF_(0x80400000L)






// Requested operation cannot be performed inside the callback or event handler.

INPUT_E_REENTRANCY               _HRESULT_TYPEDEF_(0x80400001L)






// Input cannot be processed because there is ongoing interaction with another pointer type.

INPUT_E_MULTIMODAL               _HRESULT_TYPEDEF_(0x80400002L)






// One or more fields in the input packet are invalid.

INPUT_E_PACKET                   _HRESULT_TYPEDEF_(0x80400003L)






// Packets in the frame are inconsistent. Either pointer ids are not unique or there is a discrepancy in timestamps, frame ids, pointer types or source devices.

INPUT_E_FRAME                    _HRESULT_TYPEDEF_(0x80400004L)






// The history of frames is inconsistent. Pointer ids, types, source devices don't match, or frame ids are not unique, or timestamps are out of order.

INPUT_E_HISTORY                  _HRESULT_TYPEDEF_(0x80400005L)






// Failed to retrieve information about the input device.

INPUT_E_DEVICE_INFO              _HRESULT_TYPEDEF_(0x80400006L)






// Coordinate system transformation failed to transform the data.

INPUT_E_TRANSFORM                _HRESULT_TYPEDEF_(0x80400007L)






// The property is not supported or not reported correctly by the input device.

INPUT_E_DEVICE_PROPERTY          _HRESULT_TYPEDEF_(0x80400008L)


// Internet






// The URL is invalid.

INET_E_INVALID_URL               _HRESULT_TYPEDEF_(0x800C0002L)






// No Internet session has been established.

INET_E_NO_SESSION                _HRESULT_TYPEDEF_(0x800C0003L)






// Unable to connect to the target server.

INET_E_CANNOT_CONNECT            _HRESULT_TYPEDEF_(0x800C0004L)






// The system cannot locate the resource specified.

INET_E_RESOURCE_NOT_FOUND        _HRESULT_TYPEDEF_(0x800C0005L)






// The system cannot locate the object specified.

INET_E_OBJECT_NOT_FOUND          _HRESULT_TYPEDEF_(0x800C0006L)






// No data is available for the requested resource.

INET_E_DATA_NOT_AVAILABLE        _HRESULT_TYPEDEF_(0x800C0007L)






// The download of the specified resource has failed.

INET_E_DOWNLOAD_FAILURE          _HRESULT_TYPEDEF_(0x800C0008L)






// Authentication is required to access this resource.

INET_E_AUTHENTICATION_REQUIRED   _HRESULT_TYPEDEF_(0x800C0009L)






// The server could not recognize the provided mime type.

INET_E_NO_VALID_MEDIA            _HRESULT_TYPEDEF_(0x800C000AL)






// The operation was timed out.

INET_E_CONNECTION_TIMEOUT        _HRESULT_TYPEDEF_(0x800C000BL)






// The server did not understand the request, or the request was invalid.

INET_E_INVALID_REQUEST           _HRESULT_TYPEDEF_(0x800C000CL)






// The specified protocol is unknown.

INET_E_UNKNOWN_PROTOCOL          _HRESULT_TYPEDEF_(0x800C000DL)






// A security problem occurred.

INET_E_SECURITY_PROBLEM          _HRESULT_TYPEDEF_(0x800C000EL)






// The system could not load the persisted data.

INET_E_CANNOT_LOAD_DATA          _HRESULT_TYPEDEF_(0x800C000FL)






// Unable to instantiate the object.

INET_E_CANNOT_INSTANTIATE_OBJECT _HRESULT_TYPEDEF_(0x800C0010L)






// Security certificate required to access this resource is invalid.

INET_E_INVALID_CERTIFICATE       _HRESULT_TYPEDEF_(0x800C0019L)






// A redirection problem occurred.

INET_E_REDIRECT_FAILED           _HRESULT_TYPEDEF_(0x800C0014L)






// The requested resource is a directory, not a file.

INET_E_REDIRECT_TO_DIR           _HRESULT_TYPEDEF_(0x800C0015L)


// Debuggers






// Could not create new process from ARM architecture device.

ERROR_DBG_CREATE_PROCESS_FAILURE_LOCKDOWN _HRESULT_TYPEDEF_(0x80B00001L)






// Could not attach to the application process from ARM architecture device.

ERROR_DBG_ATTACH_PROCESS_FAILURE_LOCKDOWN _HRESULT_TYPEDEF_(0x80B00002L)






// Could not connect to dbgsrv server from ARM architecture device.

ERROR_DBG_CONNECT_SERVER_FAILURE_LOCKDOWN _HRESULT_TYPEDEF_(0x80B00003L)






// Could not start dbgsrv server from ARM architecture device.

ERROR_DBG_START_SERVER_FAILURE_LOCKDOWN _HRESULT_TYPEDEF_(0x80B00004L)


//Sdbus






// The operation was preempted by a higher priority operation. It must be resumed later.

ERROR_IO_PREEMPTED               _HRESULT_TYPEDEF_(0x89010001L)


//JScript






// Function could not execute because it was deleted or garbage collected.

JSCRIPT_E_CANTEXECUTE            _HRESULT_TYPEDEF_(0x89020001L)


//WEP - Windows Encryption Providers






// One or more fixed volumes are not provisioned with the 3rd party encryption providers to support device encryption. Enable encryption with the 3rd party provider to comply with policy.

WEP_E_NOT_PROVISIONED_ON_ALL_VOLUMES _HRESULT_TYPEDEF_(0x88010001L)






// This computer is not fully encrypted. There are fixed volumes present which are not supported for encryption.

WEP_E_FIXED_DATA_NOT_SUPPORTED   _HRESULT_TYPEDEF_(0x88010002L)






// This computer does not meet the hardware requirements to support device encryption with the installed 3rd party provider.

WEP_E_HARDWARE_NOT_COMPLIANT     _HRESULT_TYPEDEF_(0x88010003L)


//device lock feature - requires encryption software to use something like a TPM or a secure location to store failed counts of the password in an interactive logon to lock out the device






// This computer cannot support device encryption because the requisites for the device lock feature are not configured.

WEP_E_LOCK_NOT_CONFIGURED        _HRESULT_TYPEDEF_(0x88010004L)






// Protection is enabled on this volume but is not in the active state.

WEP_E_PROTECTION_SUSPENDED       _HRESULT_TYPEDEF_(0x88010005L)






// The 3rd party provider has been installed, but cannot activate encryption because a license has not been activated.

WEP_E_NO_LICENSE                 _HRESULT_TYPEDEF_(0x88010006L)






// The operating system drive is not protected by 3rd party drive encryption.

WEP_E_OS_NOT_PROTECTED           _HRESULT_TYPEDEF_(0x88010007L)






// Unexpected failure was encountered while calling into the 3rd Party drive encryption plugin.

WEP_E_UNEXPECTED_FAIL            _HRESULT_TYPEDEF_(0x88010008L)






// The input buffer size for the lockout metadata used by the 3rd party drive encryption is too large.

WEP_E_BUFFER_TOO_LARGE           _HRESULT_TYPEDEF_(0x88010009L)


// Shared VHDX status codes (svhdxflt.sys)






// The proper error code with sense data was stored on server side.

ERROR_SVHDX_ERROR_STORED         _HRESULT_TYPEDEF_(0xC05C0000L)






// The requested error data is not available on the server.

ERROR_SVHDX_ERROR_NOT_AVAILABLE  _HRESULT_TYPEDEF_(0xC05CFF00L)






// Unit Attention data is available for the initiator to query.

ERROR_SVHDX_UNIT_ATTENTION_AVAILABLE _HRESULT_TYPEDEF_(0xC05CFF01L)






// The data capacity of the device has changed, resulting in a Unit Attention condition.

ERROR_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED _HRESULT_TYPEDEF_(0xC05CFF02L)






// A previous operation resulted in this initiator's reservations being preempted, resulting in a Unit Attention condition.

ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED _HRESULT_TYPEDEF_(0xC05CFF03L)






// A previous operation resulted in this initiator's reservations being released, resulting in a Unit Attention condition.

ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED _HRESULT_TYPEDEF_(0xC05CFF04L)






// A previous operation resulted in this initiator's registrations being preempted, resulting in a Unit Attention condition.

ERROR_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED _HRESULT_TYPEDEF_(0xC05CFF05L)






// The data storage format of the device has changed, resulting in a Unit Attention condition.

ERROR_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED _HRESULT_TYPEDEF_(0xC05CFF06L)






// The current initiator is not allowed to perform the SCSI command because of a reservation conflict.

ERROR_SVHDX_RESERVATION_CONFLICT _HRESULT_TYPEDEF_(0xC05CFF07L)






// Multiple virtual machines sharing a virtual hard disk is supported only on Fixed or Dynamic VHDX format virtual hard disks.

ERROR_SVHDX_WRONG_FILE_TYPE      _HRESULT_TYPEDEF_(0xC05CFF08L)






// The server version does not match the requested version.

ERROR_SVHDX_VERSION_MISMATCH     _HRESULT_TYPEDEF_(0xC05CFF09L)






// The requested operation cannot be performed on the virtual disk as it is currently used in shared mode.

ERROR_VHD_SHARED                 _HRESULT_TYPEDEF_(0xC05CFF0AL)






// Invalid Shared VHDX open due to lack of initiator ID. Check for related Continuous Availability failures.

ERROR_SVHDX_NO_INITIATOR         _HRESULT_TYPEDEF_(0xC05CFF0BL)






// The requested operation failed due to a missing backing storage file.

ERROR_VHDSET_BACKING_STORAGE_NOT_FOUND _HRESULT_TYPEDEF_(0xC05CFF0CL)


// SMB status codes






// Failed to negotiate a preauthentication integrity hash function.

ERROR_SMB_NO_PREAUTH_INTEGRITY_HASH_OVERLAP _HRESULT_TYPEDEF_(0xC05D0000L)






// The current cluster functional level does not support this SMB dialect.

ERROR_SMB_BAD_CLUSTER_DIALECT    _HRESULT_TYPEDEF_(0xC05D0001L)


// WININET.DLL errors - propagated as HRESULT's using FACILITY=WIN32






// No more Internet handles can be allocated

WININET_E_OUT_OF_HANDLES         _HRESULT_TYPEDEF_(0x80072EE1L)






// The operation timed out

WININET_E_TIMEOUT                _HRESULT_TYPEDEF_(0x80072EE2L)






// The server returned extended information

WININET_E_EXTENDED_ERROR         _HRESULT_TYPEDEF_(0x80072EE3L)






// An internal error occurred in the Microsoft Internet extensions

WININET_E_INTERNAL_ERROR         _HRESULT_TYPEDEF_(0x80072EE4L)






// The URL is invalid

WININET_E_INVALID_URL            _HRESULT_TYPEDEF_(0x80072EE5L)






// The URL does not use a recognized protocol

WININET_E_UNRECOGNIZED_SCHEME    _HRESULT_TYPEDEF_(0x80072EE6L)






// The server name or address could not be resolved

WININET_E_NAME_NOT_RESOLVED      _HRESULT_TYPEDEF_(0x80072EE7L)






// A protocol with the required capabilities was not found

WININET_E_PROTOCOL_NOT_FOUND     _HRESULT_TYPEDEF_(0x80072EE8L)






// The option is invalid

WININET_E_INVALID_OPTION         _HRESULT_TYPEDEF_(0x80072EE9L)






// The length is incorrect for the option type

WININET_E_BAD_OPTION_LENGTH      _HRESULT_TYPEDEF_(0x80072EEAL)






// The option value cannot be set

WININET_E_OPTION_NOT_SETTABLE    _HRESULT_TYPEDEF_(0x80072EEBL)






// Microsoft Internet Extension support has been shut down

WININET_E_SHUTDOWN               _HRESULT_TYPEDEF_(0x80072EECL)






// The user name was not allowed

WININET_E_INCORRECT_USER_NAME    _HRESULT_TYPEDEF_(0x80072EEDL)






// The password was not allowed

WININET_E_INCORRECT_PASSWORD     _HRESULT_TYPEDEF_(0x80072EEEL)






// The login request was denied

WININET_E_LOGIN_FAILURE          _HRESULT_TYPEDEF_(0x80072EEFL)






// The requested operation is invalid

WININET_E_INVALID_OPERATION      _HRESULT_TYPEDEF_(0x80072EF0L)






// The operation has been canceled

WININET_E_OPERATION_CANCELLED    _HRESULT_TYPEDEF_(0x80072EF1L)






// The supplied handle is the wrong type for the requested operation

WININET_E_INCORRECT_HANDLE_TYPE  _HRESULT_TYPEDEF_(0x80072EF2L)






// The handle is in the wrong state for the requested operation

WININET_E_INCORRECT_HANDLE_STATE _HRESULT_TYPEDEF_(0x80072EF3L)






// The request cannot be made on a Proxy session

WININET_E_NOT_PROXY_REQUEST      _HRESULT_TYPEDEF_(0x80072EF4L)






// The registry value could not be found

WININET_E_REGISTRY_VALUE_NOT_FOUND _HRESULT_TYPEDEF_(0x80072EF5L)






// The registry parameter is incorrect

WININET_E_BAD_REGISTRY_PARAMETER _HRESULT_TYPEDEF_(0x80072EF6L)






// Direct Internet access is not available

WININET_E_NO_DIRECT_ACCESS       _HRESULT_TYPEDEF_(0x80072EF7L)






// No context value was supplied

WININET_E_NO_CONTEXT             _HRESULT_TYPEDEF_(0x80072EF8L)






// No status callback was supplied

WININET_E_NO_CALLBACK            _HRESULT_TYPEDEF_(0x80072EF9L)






// There are outstanding requests

WININET_E_REQUEST_PENDING        _HRESULT_TYPEDEF_(0x80072EFAL)






// The information format is incorrect

WININET_E_INCORRECT_FORMAT       _HRESULT_TYPEDEF_(0x80072EFBL)






// The requested item could not be found

WININET_E_ITEM_NOT_FOUND         _HRESULT_TYPEDEF_(0x80072EFCL)






// A connection with the server could not be established

WININET_E_CANNOT_CONNECT         _HRESULT_TYPEDEF_(0x80072EFDL)






// The connection with the server was terminated abnormally

WININET_E_CONNECTION_ABORTED     _HRESULT_TYPEDEF_(0x80072EFEL)






// The connection with the server was reset

WININET_E_CONNECTION_RESET       _HRESULT_TYPEDEF_(0x80072EFFL)






// The action must be retried

WININET_E_FORCE_RETRY            _HRESULT_TYPEDEF_(0x80072F00L)






// The proxy request is invalid

WININET_E_INVALID_PROXY_REQUEST  _HRESULT_TYPEDEF_(0x80072F01L)






// User interaction is required to complete the operation

WININET_E_NEED_UI                _HRESULT_TYPEDEF_(0x80072F02L)






// The handle already exists

WININET_E_HANDLE_EXISTS          _HRESULT_TYPEDEF_(0x80072F04L)






// The date in the certificate is invalid or has expired

WININET_E_SEC_CERT_DATE_INVALID  _HRESULT_TYPEDEF_(0x80072F05L)






// The host name in the certificate is invalid or does not match

WININET_E_SEC_CERT_CN_INVALID    _HRESULT_TYPEDEF_(0x80072F06L)






// A redirect request will change a non-secure to a secure connection

WININET_E_HTTP_TO_HTTPS_ON_REDIR _HRESULT_TYPEDEF_(0x80072F07L)






// A redirect request will change a secure to a non-secure connection

WININET_E_HTTPS_TO_HTTP_ON_REDIR _HRESULT_TYPEDEF_(0x80072F08L)






// Mixed secure and non-secure connections

WININET_E_MIXED_SECURITY         _HRESULT_TYPEDEF_(0x80072F09L)






// Changing to non-secure post

WININET_E_CHG_POST_IS_NON_SECURE _HRESULT_TYPEDEF_(0x80072F0AL)






// Data is being posted on a non-secure connection

WININET_E_POST_IS_NON_SECURE     _HRESULT_TYPEDEF_(0x80072F0BL)






// A certificate is required to complete client authentication

WININET_E_CLIENT_AUTH_CERT_NEEDED _HRESULT_TYPEDEF_(0x80072F0CL)






// The certificate authority is invalid or incorrect

WININET_E_INVALID_CA             _HRESULT_TYPEDEF_(0x80072F0DL)






// Client authentication has not been correctly installed

WININET_E_CLIENT_AUTH_NOT_SETUP  _HRESULT_TYPEDEF_(0x80072F0EL)






// An error has occurred in a Wininet asynchronous thread. You may need to restart

WININET_E_ASYNC_THREAD_FAILED    _HRESULT_TYPEDEF_(0x80072F0FL)






// The protocol scheme has changed during a redirect operation

WININET_E_REDIRECT_SCHEME_CHANGE _HRESULT_TYPEDEF_(0x80072F10L)






// There are operations awaiting retry

WININET_E_DIALOG_PENDING         _HRESULT_TYPEDEF_(0x80072F11L)






// The operation must be retried

WININET_E_RETRY_DIALOG           _HRESULT_TYPEDEF_(0x80072F12L)






// There are no new cache containers

WININET_E_NO_NEW_CONTAINERS      _HRESULT_TYPEDEF_(0x80072F13L)






// A security zone check indicates the operation must be retried

WININET_E_HTTPS_HTTP_SUBMIT_REDIR _HRESULT_TYPEDEF_(0x80072F14L)






// The SSL certificate contains errors.

WININET_E_SEC_CERT_ERRORS        _HRESULT_TYPEDEF_(0x80072F17L)






// It was not possible to connect to the revocation server or a definitive response could not be obtained.

WININET_E_SEC_CERT_REV_FAILED    _HRESULT_TYPEDEF_(0x80072F19L)






// The requested header was not found

WININET_E_HEADER_NOT_FOUND       _HRESULT_TYPEDEF_(0x80072F76L)






// The server does not support the requested protocol level

WININET_E_DOWNLEVEL_SERVER       _HRESULT_TYPEDEF_(0x80072F77L)






// The server returned an invalid or unrecognized response

WININET_E_INVALID_SERVER_RESPONSE _HRESULT_TYPEDEF_(0x80072F78L)






// The supplied HTTP header is invalid

WININET_E_INVALID_HEADER         _HRESULT_TYPEDEF_(0x80072F79L)






// The request for a HTTP header is invalid

WININET_E_INVALID_QUERY_REQUEST  _HRESULT_TYPEDEF_(0x80072F7AL)






// The HTTP header already exists

WININET_E_HEADER_ALREADY_EXISTS  _HRESULT_TYPEDEF_(0x80072F7BL)






// The HTTP redirect request failed

WININET_E_REDIRECT_FAILED        _HRESULT_TYPEDEF_(0x80072F7CL)






// An error occurred in the secure channel support

WININET_E_SECURITY_CHANNEL_ERROR _HRESULT_TYPEDEF_(0x80072F7DL)






// The file could not be written to the cache

WININET_E_UNABLE_TO_CACHE_FILE   _HRESULT_TYPEDEF_(0x80072F7EL)






// The TCP/IP protocol is not installed properly

WININET_E_TCPIP_NOT_INSTALLED    _HRESULT_TYPEDEF_(0x80072F7FL)






// The computer is disconnected from the network

WININET_E_DISCONNECTED           _HRESULT_TYPEDEF_(0x80072F83L)






// The server is unreachable

WININET_E_SERVER_UNREACHABLE     _HRESULT_TYPEDEF_(0x80072F84L)






// The proxy server is unreachable

WININET_E_PROXY_SERVER_UNREACHABLE _HRESULT_TYPEDEF_(0x80072F85L)






// The proxy auto-configuration script is in error

WININET_E_BAD_AUTO_PROXY_SCRIPT  _HRESULT_TYPEDEF_(0x80072F86L)






// Could not download the proxy auto-configuration script file

WININET_E_UNABLE_TO_DOWNLOAD_SCRIPT _HRESULT_TYPEDEF_(0x80072F87L)






// The supplied certificate is invalid

WININET_E_SEC_INVALID_CERT       _HRESULT_TYPEDEF_(0x80072F89L)






// The supplied certificate has been revoked

WININET_E_SEC_CERT_REVOKED       _HRESULT_TYPEDEF_(0x80072F8AL)






// The Dialup failed because file sharing was turned on and a failure was requested if security check was needed

WININET_E_FAILED_DUETOSECURITYCHECK _HRESULT_TYPEDEF_(0x80072F8BL)






// Initialization of the WinINet API has not occurred

WININET_E_NOT_INITIALIZED        _HRESULT_TYPEDEF_(0x80072F8CL)






// Login failed and the client should display the entity body to the user

WININET_E_LOGIN_FAILURE_DISPLAY_ENTITY_BODY _HRESULT_TYPEDEF_(0x80072F8EL)






// Content decoding has failed

WININET_E_DECODING_FAILED        _HRESULT_TYPEDEF_(0x80072F8FL)






// The HTTP request was not redirected

WININET_E_NOT_REDIRECTED         _HRESULT_TYPEDEF_(0x80072F80L)






// A cookie from the server must be confirmed by the user

WININET_E_COOKIE_NEEDS_CONFIRMATION _HRESULT_TYPEDEF_(0x80072F81L)






// A cookie from the server has been declined acceptance

WININET_E_COOKIE_DECLINED        _HRESULT_TYPEDEF_(0x80072F82L)






// The HTTP redirect request must be confirmed by the user

WININET_E_REDIRECT_NEEDS_CONFIRMATION _HRESULT_TYPEDEF_(0x80072F88L)



// SQLite







// SQL error or missing database

SQLITE_E_ERROR                   _HRESULT_TYPEDEF_(0x87AF0001L)






// Internal logic error in SQLite

SQLITE_E_INTERNAL                _HRESULT_TYPEDEF_(0x87AF0002L)






// Access permission denied

SQLITE_E_PERM                    _HRESULT_TYPEDEF_(0x87AF0003L)






// Callback routine requested an abort

SQLITE_E_ABORT                   _HRESULT_TYPEDEF_(0x87AF0004L)






// The database file is locked

SQLITE_E_BUSY                    _HRESULT_TYPEDEF_(0x87AF0005L)






// A table in the database is locked

SQLITE_E_LOCKED                  _HRESULT_TYPEDEF_(0x87AF0006L)






// A malloc() failed

SQLITE_E_NOMEM                   _HRESULT_TYPEDEF_(0x87AF0007L)






// Attempt to write a readonly database

SQLITE_E_READONLY                _HRESULT_TYPEDEF_(0x87AF0008L)






// Operation terminated by sqlite3_interrupt()

SQLITE_E_INTERRUPT               _HRESULT_TYPEDEF_(0x87AF0009L)






// Some kind of disk I/O error occurred

SQLITE_E_IOERR                   _HRESULT_TYPEDEF_(0x87AF000AL)






// The database disk image is malformed

SQLITE_E_CORRUPT                 _HRESULT_TYPEDEF_(0x87AF000BL)






// Unknown opcode in sqlite3_file_control()

SQLITE_E_NOTFOUND                _HRESULT_TYPEDEF_(0x87AF000CL)






// Insertion failed because database is full

SQLITE_E_FULL                    _HRESULT_TYPEDEF_(0x87AF000DL)






// Unable to open the database file

SQLITE_E_CANTOPEN                _HRESULT_TYPEDEF_(0x87AF000EL)






// Database lock protocol error

SQLITE_E_PROTOCOL                _HRESULT_TYPEDEF_(0x87AF000FL)






// Database is empty

SQLITE_E_EMPTY                   _HRESULT_TYPEDEF_(0x87AF0010L)






// The database schema changed

SQLITE_E_SCHEMA                  _HRESULT_TYPEDEF_(0x87AF0011L)






// String or BLOB exceeds size limit

SQLITE_E_TOOBIG                  _HRESULT_TYPEDEF_(0x87AF0012L)






// Abort due to constraint violation

SQLITE_E_CONSTRAINT              _HRESULT_TYPEDEF_(0x87AF0013L)






// Data type mismatch

SQLITE_E_MISMATCH                _HRESULT_TYPEDEF_(0x87AF0014L)






// Library used incorrectly

SQLITE_E_MISUSE                  _HRESULT_TYPEDEF_(0x87AF0015L)






// Uses OS features not supported on host

SQLITE_E_NOLFS                   _HRESULT_TYPEDEF_(0x87AF0016L)






// Authorization denied

SQLITE_E_AUTH                    _HRESULT_TYPEDEF_(0x87AF0017L)






// Auxiliary database format error

SQLITE_E_FORMAT                  _HRESULT_TYPEDEF_(0x87AF0018L)






// 2nd parameter to sqlite3_bind out of range

SQLITE_E_RANGE                   _HRESULT_TYPEDEF_(0x87AF0019L)






// File opened that is not a database file

SQLITE_E_NOTADB                  _HRESULT_TYPEDEF_(0x87AF001AL)






// Notifications from sqlite3_log()

SQLITE_E_NOTICE                  _HRESULT_TYPEDEF_(0x87AF001BL)






// Warnings from sqlite3_log()

SQLITE_E_WARNING                 _HRESULT_TYPEDEF_(0x87AF001CL)






// sqlite3_step() has another row ready

SQLITE_E_ROW                     _HRESULT_TYPEDEF_(0x87AF0064L)






// sqlite3_step() has finished executing

SQLITE_E_DONE                    _HRESULT_TYPEDEF_(0x87AF0065L)






// SQLITE_IOERR_READ

SQLITE_E_IOERR_READ              _HRESULT_TYPEDEF_(0x87AF010AL)






// SQLITE_IOERR_SHORT_READ

SQLITE_E_IOERR_SHORT_READ        _HRESULT_TYPEDEF_(0x87AF020AL)






// SQLITE_IOERR_WRITE

SQLITE_E_IOERR_WRITE             _HRESULT_TYPEDEF_(0x87AF030AL)






// SQLITE_IOERR_FSYNC

SQLITE_E_IOERR_FSYNC             _HRESULT_TYPEDEF_(0x87AF040AL)






// SQLITE_IOERR_DIR_FSYNC

SQLITE_E_IOERR_DIR_FSYNC         _HRESULT_TYPEDEF_(0x87AF050AL)






// SQLITE_IOERR_TRUNCATE

SQLITE_E_IOERR_TRUNCATE          _HRESULT_TYPEDEF_(0x87AF060AL)






// SQLITE_IOERR_FSTAT

SQLITE_E_IOERR_FSTAT             _HRESULT_TYPEDEF_(0x87AF070AL)






// SQLITE_IOERR_UNLOCK

SQLITE_E_IOERR_UNLOCK            _HRESULT_TYPEDEF_(0x87AF080AL)






// SQLITE_IOERR_RDLOCK

SQLITE_E_IOERR_RDLOCK            _HRESULT_TYPEDEF_(0x87AF090AL)






// SQLITE_IOERR_DELETE

SQLITE_E_IOERR_DELETE            _HRESULT_TYPEDEF_(0x87AF0A0AL)






// SQLITE_IOERR_BLOCKED

SQLITE_E_IOERR_BLOCKED           _HRESULT_TYPEDEF_(0x87AF0B0AL)






// SQLITE_IOERR_NOMEM

SQLITE_E_IOERR_NOMEM             _HRESULT_TYPEDEF_(0x87AF0C0AL)






// SQLITE_IOERR_ACCESS

SQLITE_E_IOERR_ACCESS            _HRESULT_TYPEDEF_(0x87AF0D0AL)






// SQLITE_IOERR_CHECKRESERVEDLOCK

SQLITE_E_IOERR_CHECKRESERVEDLOCK _HRESULT_TYPEDEF_(0x87AF0E0AL)






// SQLITE_IOERR_LOCK

SQLITE_E_IOERR_LOCK              _HRESULT_TYPEDEF_(0x87AF0F0AL)






// SQLITE_IOERR_CLOSE

SQLITE_E_IOERR_CLOSE             _HRESULT_TYPEDEF_(0x87AF100AL)






// SQLITE_IOERR_DIR_CLOSE

SQLITE_E_IOERR_DIR_CLOSE         _HRESULT_TYPEDEF_(0x87AF110AL)






// SQLITE_IOERR_SHMOPEN

SQLITE_E_IOERR_SHMOPEN           _HRESULT_TYPEDEF_(0x87AF120AL)






// SQLITE_IOERR_SHMSIZE

SQLITE_E_IOERR_SHMSIZE           _HRESULT_TYPEDEF_(0x87AF130AL)






// SQLITE_IOERR_SHMLOCK

SQLITE_E_IOERR_SHMLOCK           _HRESULT_TYPEDEF_(0x87AF140AL)






// SQLITE_IOERR_SHMMAP

SQLITE_E_IOERR_SHMMAP            _HRESULT_TYPEDEF_(0x87AF150AL)






// SQLITE_IOERR_SEEK

SQLITE_E_IOERR_SEEK              _HRESULT_TYPEDEF_(0x87AF160AL)






// SQLITE_IOERR_DELETE_NOENT

SQLITE_E_IOERR_DELETE_NOENT      _HRESULT_TYPEDEF_(0x87AF170AL)






// SQLITE_IOERR_MMAP

SQLITE_E_IOERR_MMAP              _HRESULT_TYPEDEF_(0x87AF180AL)






// SQLITE_IOERR_GETTEMPPATH

SQLITE_E_IOERR_GETTEMPPATH       _HRESULT_TYPEDEF_(0x87AF190AL)






// SQLITE_IOERR_CONVPATH

SQLITE_E_IOERR_CONVPATH          _HRESULT_TYPEDEF_(0x87AF1A0AL)






// SQLITE_IOERR_VNODE

SQLITE_E_IOERR_VNODE             _HRESULT_TYPEDEF_(0x87AF1A02L)






// SQLITE_IOERR_AUTH

SQLITE_E_IOERR_AUTH              _HRESULT_TYPEDEF_(0x87AF1A03L)






// SQLITE_LOCKED_SHAREDCACHE

SQLITE_E_LOCKED_SHAREDCACHE      _HRESULT_TYPEDEF_(0x87AF0106L)






// SQLITE_BUSY_RECOVERY

SQLITE_E_BUSY_RECOVERY           _HRESULT_TYPEDEF_(0x87AF0105L)






// SQLITE_BUSY_SNAPSHOT

SQLITE_E_BUSY_SNAPSHOT           _HRESULT_TYPEDEF_(0x87AF0205L)






// SQLITE_CANTOPEN_NOTEMPDIR

SQLITE_E_CANTOPEN_NOTEMPDIR      _HRESULT_TYPEDEF_(0x87AF010EL)






// SQLITE_CANTOPEN_ISDIR

SQLITE_E_CANTOPEN_ISDIR          _HRESULT_TYPEDEF_(0x87AF020EL)






// SQLITE_CANTOPEN_FULLPATH

SQLITE_E_CANTOPEN_FULLPATH       _HRESULT_TYPEDEF_(0x87AF030EL)






// SQLITE_CANTOPEN_CONVPATH

SQLITE_E_CANTOPEN_CONVPATH       _HRESULT_TYPEDEF_(0x87AF040EL)






// SQLITE_CORRUPT_VTAB

SQLITE_E_CORRUPT_VTAB            _HRESULT_TYPEDEF_(0x87AF010BL)






// SQLITE_READONLY_RECOVERY

SQLITE_E_READONLY_RECOVERY       _HRESULT_TYPEDEF_(0x87AF0108L)






// SQLITE_READONLY_CANTLOCK

SQLITE_E_READONLY_CANTLOCK       _HRESULT_TYPEDEF_(0x87AF0208L)






// SQLITE_READONLY_ROLLBACK

SQLITE_E_READONLY_ROLLBACK       _HRESULT_TYPEDEF_(0x87AF0308L)






// SQLITE_READONLY_DBMOVED

SQLITE_E_READONLY_DBMOVED        _HRESULT_TYPEDEF_(0x87AF0408L)






// SQLITE_ABORT_ROLLBACK

SQLITE_E_ABORT_ROLLBACK          _HRESULT_TYPEDEF_(0x87AF0204L)






// SQLITE_CONSTRAINT_CHECK

SQLITE_E_CONSTRAINT_CHECK        _HRESULT_TYPEDEF_(0x87AF0113L)






// SQLITE_CONSTRAINT_COMMITHOOK

SQLITE_E_CONSTRAINT_COMMITHOOK   _HRESULT_TYPEDEF_(0x87AF0213L)






// SQLITE_CONSTRAINT_FOREIGNKEY

SQLITE_E_CONSTRAINT_FOREIGNKEY   _HRESULT_TYPEDEF_(0x87AF0313L)






// SQLITE_CONSTRAINT_FUNCTION

SQLITE_E_CONSTRAINT_FUNCTION     _HRESULT_TYPEDEF_(0x87AF0413L)






// SQLITE_CONSTRAINT_NOTNULL

SQLITE_E_CONSTRAINT_NOTNULL      _HRESULT_TYPEDEF_(0x87AF0513L)






// SQLITE_CONSTRAINT_PRIMARYKEY

SQLITE_E_CONSTRAINT_PRIMARYKEY   _HRESULT_TYPEDEF_(0x87AF0613L)






// SQLITE_CONSTRAINT_TRIGGER

SQLITE_E_CONSTRAINT_TRIGGER      _HRESULT_TYPEDEF_(0x87AF0713L)






// SQLITE_CONSTRAINT_UNIQUE

SQLITE_E_CONSTRAINT_UNIQUE       _HRESULT_TYPEDEF_(0x87AF0813L)






// SQLITE_CONSTRAINT_VTAB

SQLITE_E_CONSTRAINT_VTAB         _HRESULT_TYPEDEF_(0x87AF0913L)






// SQLITE_CONSTRAINT_ROWID

SQLITE_E_CONSTRAINT_ROWID        _HRESULT_TYPEDEF_(0x87AF0A13L)






// SQLITE_NOTICE_RECOVER_WAL

SQLITE_E_NOTICE_RECOVER_WAL      _HRESULT_TYPEDEF_(0x87AF011BL)






// SQLITE_NOTICE_RECOVER_ROLLBACK

SQLITE_E_NOTICE_RECOVER_ROLLBACK _HRESULT_TYPEDEF_(0x87AF021BL)






// SQLITE_WARNING_AUTOINDEX

SQLITE_E_WARNING_AUTOINDEX       _HRESULT_TYPEDEF_(0x87AF011CL)


// FACILITY_UTC






// Toggle (alternative) trace started

UTC_E_TOGGLE_TRACE_STARTED       _HRESULT_TYPEDEF_(0x87C51001L)






// Cannot pre-empt running trace: The current trace has a higher priority

UTC_E_ALTERNATIVE_TRACE_CANNOT_PREEMPT _HRESULT_TYPEDEF_(0x87C51002L)






// The always-on-trace is not running

UTC_E_AOT_NOT_RUNNING            _HRESULT_TYPEDEF_(0x87C51003L)






// RunScriptAction contains an invalid script type

UTC_E_SCRIPT_TYPE_INVALID        _HRESULT_TYPEDEF_(0x87C51004L)






// Requested scenario definition cannot be found

UTC_E_SCENARIODEF_NOT_FOUND      _HRESULT_TYPEDEF_(0x87C51005L)






// Requested trace profile cannot be found

UTC_E_TRACEPROFILE_NOT_FOUND     _HRESULT_TYPEDEF_(0x87C51006L)






// Trigger forwarder is already enabled

UTC_E_FORWARDER_ALREADY_ENABLED  _HRESULT_TYPEDEF_(0x87C51007L)






// Trigger forwarder is already disabled

UTC_E_FORWARDER_ALREADY_DISABLED _HRESULT_TYPEDEF_(0x87C51008L)






// Cannot parse EventLog XML: The entry is malformed

UTC_E_EVENTLOG_ENTRY_MALFORMED   _HRESULT_TYPEDEF_(0x87C51009L)






// <diagrules> node contains a schemaversion which is not compatible with this client

UTC_E_DIAGRULES_SCHEMAVERSION_MISMATCH _HRESULT_TYPEDEF_(0x87C5100AL)






// RunScriptAction was forced to terminate a script

UTC_E_SCRIPT_TERMINATED          _HRESULT_TYPEDEF_(0x87C5100BL)






// ToggleTraceWithCustomFilterAction contains an invalid custom filter

UTC_E_INVALID_CUSTOM_FILTER      _HRESULT_TYPEDEF_(0x87C5100CL)






// The trace is not running

UTC_E_TRACE_NOT_RUNNING          _HRESULT_TYPEDEF_(0x87C5100DL)






// A scenario failed to escalate: This scenario has escalated too recently

UTC_E_REESCALATED_TOO_QUICKLY    _HRESULT_TYPEDEF_(0x87C5100EL)






// A scenario failed to escalate: This scenario is already running an escalation

UTC_E_ESCALATION_ALREADY_RUNNING _HRESULT_TYPEDEF_(0x87C5100FL)






// Cannot start tracing: PerfTrack component is already tracing

UTC_E_PERFTRACK_ALREADY_TRACING  _HRESULT_TYPEDEF_(0x87C51010L)






// A scenario failed to escalate: This scenario has reached max escalations for this escalation type

UTC_E_REACHED_MAX_ESCALATIONS    _HRESULT_TYPEDEF_(0x87C51011L)






// Cannot update forwarder: The forwarder passed to the function is of a different type

UTC_E_FORWARDER_PRODUCER_MISMATCH _HRESULT_TYPEDEF_(0x87C51012L)






// RunScriptAction failed intentionally to force this escalation to terminate

UTC_E_INTENTIONAL_SCRIPT_FAILURE _HRESULT_TYPEDEF_(0x87C51013L)






// Failed to initialize SQM logger

UTC_E_SQM_INIT_FAILED            _HRESULT_TYPEDEF_(0x87C51014L)






// Failed to initialize WER logger: This system does not support WER for UTC

UTC_E_NO_WER_LOGGER_SUPPORTED    _HRESULT_TYPEDEF_(0x87C51015L)






// The TraceManager has attempted to take a tracing action without initializing tracers

UTC_E_TRACERS_DONT_EXIST         _HRESULT_TYPEDEF_(0x87C51016L)






// WinRT initialization failed

UTC_E_WINRT_INIT_FAILED          _HRESULT_TYPEDEF_(0x87C51017L)






// <scenario> node contains a schemaversion that is not compatible with this client

UTC_E_SCENARIODEF_SCHEMAVERSION_MISMATCH _HRESULT_TYPEDEF_(0x87C51018L)






// Scenario contains an invalid filter that can never be satisfied

UTC_E_INVALID_FILTER             _HRESULT_TYPEDEF_(0x87C51019L)






// RunExeWithArgsAction was forced to terminate a running executable

UTC_E_EXE_TERMINATED             _HRESULT_TYPEDEF_(0x87C5101AL)






// Escalation for scenario failed due to insufficient permissions

UTC_E_ESCALATION_NOT_AUTHORIZED  _HRESULT_TYPEDEF_(0x87C5101BL)






// Setup for scenario failed due to insufficient permissions

UTC_E_SETUP_NOT_AUTHORIZED       _HRESULT_TYPEDEF_(0x87C5101CL)






// A process launched by UTC failed with a non-zero exit code.

UTC_E_CHILD_PROCESS_FAILED       _HRESULT_TYPEDEF_(0x87C5101DL)






// A RunExeWithArgs action contains an unauthorized command line.

UTC_E_COMMAND_LINE_NOT_AUTHORIZED _HRESULT_TYPEDEF_(0x87C5101EL)






// UTC cannot load Scenario Editor XML. Convert the scenario file to a DiagTrack XML using the editor.

UTC_E_CANNOT_LOAD_SCENARIO_EDITOR_XML _HRESULT_TYPEDEF_(0x87C5101FL)






// Escalation for scenario has timed out

UTC_E_ESCALATION_TIMED_OUT       _HRESULT_TYPEDEF_(0x87C51020L)






// Setup for scenario has timed out

UTC_E_SETUP_TIMED_OUT            _HRESULT_TYPEDEF_(0x87C51021L)






// The given trigger does not match the expected trigger type

UTC_E_TRIGGER_MISMATCH           _HRESULT_TYPEDEF_(0x87C51022L)






// Requested trigger cannot be found

UTC_E_TRIGGER_NOT_FOUND          _HRESULT_TYPEDEF_(0x87C51023L)






// SIF is not supported on the machine

UTC_E_SIF_NOT_SUPPORTED          _HRESULT_TYPEDEF_(0x87C51024L)






// The delay action was terminated

UTC_E_DELAY_TERMINATED           _HRESULT_TYPEDEF_(0x87C51025L)






// The device ticket was not obtained

UTC_E_DEVICE_TICKET_ERROR        _HRESULT_TYPEDEF_(0x87C51026L)






// The trace profile needs more memory than is available for tracing

UTC_E_TRACE_BUFFER_LIMIT_EXCEEDED _HRESULT_TYPEDEF_(0x87C51027L)






// The API was not completed successfully so the result is unavailable

UTC_E_API_RESULT_UNAVAILABLE     _HRESULT_TYPEDEF_(0x87C51028L)






// The requested API encountered a timeout in the API manager

UTC_E_RPC_TIMEOUT                _HRESULT_TYPEDEF_(0x87C51029L)






// The synchronous API encountered a wait failure

UTC_E_RPC_WAIT_FAILED            _HRESULT_TYPEDEF_(0x87C5102AL)






// The UTC API is busy with another request

UTC_E_API_BUSY                   _HRESULT_TYPEDEF_(0x87C5102BL)






// The running trace profile does not have a sufficient runtime to fulfill the escalation request

UTC_E_TRACE_MIN_DURATION_REQUIREMENT_NOT_MET _HRESULT_TYPEDEF_(0x87C5102CL)






// The trace profile could not be started because it requires exclusivity and another higher priority trace is already running

UTC_E_EXCLUSIVITY_NOT_AVAILABLE  _HRESULT_TYPEDEF_(0x87C5102DL)






// The file path is not approved for the GetFile escalation action

UTC_E_GETFILE_FILE_PATH_NOT_APPROVED _HRESULT_TYPEDEF_(0x87C5102EL)






// The escalation working directory for the requested escalation could not be created because it already exists

UTC_E_ESCALATION_DIRECTORY_ALREADY_EXISTS _HRESULT_TYPEDEF_(0x87C5102FL)






// Time triggers cannot be used on a transition originating from the "_start" state

UTC_E_TIME_TRIGGER_ON_START_INVALID _HRESULT_TYPEDEF_(0x87C51030L)






// Time triggers can only be attached to a single transition

UTC_E_TIME_TRIGGER_ONLY_VALID_ON_SINGLE_TRANSITION _HRESULT_TYPEDEF_(0x87C51031L)






// Time trigger duration must fall within an inclusive range of one second and 15 minutes

UTC_E_TIME_TRIGGER_INVALID_TIME_RANGE _HRESULT_TYPEDEF_(0x87C51032L)






// Only one Time Trigger is allowed per state

UTC_E_MULTIPLE_TIME_TRIGGER_ON_SINGLE_STATE _HRESULT_TYPEDEF_(0x87C51033L)






// A RunExeWithArgs action contains a binary which is not present on the targeted device.

UTC_E_BINARY_MISSING             _HRESULT_TYPEDEF_(0x87C51034L)






// A network capture trace is not allowed.

UTC_E_NETWORK_CAPTURE_NOT_ALLOWED _HRESULT_TYPEDEF_(0x87C51035L)






// UTC failed to identify the container id to use for a scenario escalation action.

UTC_E_FAILED_TO_RESOLVE_CONTAINER_ID _HRESULT_TYPEDEF_(0x87C51036L)






// Failed to resolve session ID during API invocation.

UTC_E_UNABLE_TO_RESOLVE_SESSION  _HRESULT_TYPEDEF_(0x87C51037L)






// UTC has throttled the event for firing too often.

UTC_E_THROTTLED                  _HRESULT_TYPEDEF_(0x87C51038L)






// The script is not approved to run as part of DiagTrack scenario.

UTC_E_UNAPPROVED_SCRIPT          _HRESULT_TYPEDEF_(0x87C51039L)






// The script referenced in DiagTrack scenario is not present on the system.

UTC_E_SCRIPT_MISSING             _HRESULT_TYPEDEF_(0x87C5103AL)






// A trigger in this scenario is throttled, blocking the scenario from being loaded.

UTC_E_SCENARIO_THROTTLED         _HRESULT_TYPEDEF_(0x87C5103BL)






// The requested UTC API call is not supported on this device.

UTC_E_API_NOT_SUPPORTED          _HRESULT_TYPEDEF_(0x87C5103CL)






// The file path is not approved for collection on external rings for the GetFile escalation action.

UTC_E_GETFILE_EXTERNAL_PATH_NOT_APPROVED _HRESULT_TYPEDEF_(0x87C5103DL)






// Querying a scenario definition exceeded the specified maximum timeout.

UTC_E_TRY_GET_SCENARIO_TIMEOUT_EXCEEDED _HRESULT_TYPEDEF_(0x87C5103EL)






// Certification revocation checking has been enabled, but the revocation check failed to verify whether a certificate has been revoked. The server used to check for revocation might be unreachable.

UTC_E_CERT_REV_FAILED            _HRESULT_TYPEDEF_(0x87C5103FL)






// Failed to start NDISCAP service for network packet capture trace.

UTC_E_FAILED_TO_START_NDISCAP    _HRESULT_TYPEDEF_(0x87C51040L)






// UTC can perform no more than one KernelDump action on a device every 24 hours.

UTC_E_KERNELDUMP_LIMIT_REACHED   _HRESULT_TYPEDEF_(0x87C51041L)






// The event contained an aggregation or differential privacy structure, but did not specify MICROSOFT_EVENTTAG_AGGREGATE.

UTC_E_MISSING_AGGREGATE_EVENT_TAG _HRESULT_TYPEDEF_(0x87C51042L)






// The event contained an invalid aggregation or differential privacy structure.

UTC_E_INVALID_AGGREGATION_STRUCT _HRESULT_TYPEDEF_(0x87C51043L)






// The action cannot be completed in the specified destination.

UTC_E_ACTION_NOT_SUPPORTED_IN_DESTINATION _HRESULT_TYPEDEF_(0x87C51044L)






// Filter command is missing a required attribute.

UTC_E_FILTER_MISSING_ATTRIBUTE   _HRESULT_TYPEDEF_(0x87C51045L)






// Filter command contains an unsupported type.

UTC_E_FILTER_INVALID_TYPE        _HRESULT_TYPEDEF_(0x87C51046L)






// Filter variable does not exist at point of evaluation.

UTC_E_FILTER_VARIABLE_NOT_FOUND  _HRESULT_TYPEDEF_(0x87C51047L)






// Filter command is not allowed in the current context.

UTC_E_FILTER_FUNCTION_RESTRICTED _HRESULT_TYPEDEF_(0x87C51048L)






// Requested filter version is incompatible with available version.

UTC_E_FILTER_VERSION_MISMATCH    _HRESULT_TYPEDEF_(0x87C51049L)






// Filter does not support this function.

UTC_E_FILTER_INVALID_FUNCTION    _HRESULT_TYPEDEF_(0x87C51050L)






// Filter function does not accept the provided parameter types and/or count.

UTC_E_FILTER_INVALID_FUNCTION_PARAMS _HRESULT_TYPEDEF_(0x87C51051L)






// Filter command does not exist or is incorrectly formatted.

UTC_E_FILTER_INVALID_COMMAND     _HRESULT_TYPEDEF_(0x87C51052L)






// Filter types can not be compared to each other.

UTC_E_FILTER_ILLEGAL_EVAL        _HRESULT_TYPEDEF_(0x87C51053L)






// TTTracer executable returned a code other than ERROR_SUCCESS.

UTC_E_TTTRACER_RETURNED_ERROR    _HRESULT_TYPEDEF_(0x87C51054L)






// The total size of the compressed escalation data payload exceeded the allowable limit.

UTC_E_AGENT_DIAGNOSTICS_TOO_LARGE _HRESULT_TYPEDEF_(0x87C51055L)






// Escalation data was not completely transferred from agent to host.

UTC_E_FAILED_TO_RECEIVE_AGENT_DIAGNOSTICS _HRESULT_TYPEDEF_(0x87C51056L)






// An escalation was requested for a scenario which has no actions for the passed type.

UTC_E_SCENARIO_HAS_NO_ACTIONS    _HRESULT_TYPEDEF_(0x87C51057L)






// UTC allocated space for TTTracer escalations is full.

UTC_E_TTTRACER_STORAGE_FULL      _HRESULT_TYPEDEF_(0x87C51058L)






// Disk needs minimum of 15GB to start TTD recording session.

UTC_E_INSUFFICIENT_SPACE_TO_START_TRACE _HRESULT_TYPEDEF_(0x87C51059L)






// Escalation was cancelled due to component shutdown.

UTC_E_ESCALATION_CANCELLED_AT_SHUTDOWN _HRESULT_TYPEDEF_(0x87C5105AL)






// The file for the GetFileInfo action must be under the \Windows, \Program Files, or \Program Files (x86) directories.

UTC_E_GETFILEINFOACTION_FILE_NOT_APPROVED _HRESULT_TYPEDEF_(0x87C5105BL)






// The registry value type for SetRegKey action must be REG_SZ, REG_MULTI_SZ, REG_EXPAND_SZ, REG_BINARY, REG_DWORD, or REG_QWORD.

UTC_E_SETREGKEYACTION_TYPE_NOT_APPROVED _HRESULT_TYPEDEF_(0x87C5105CL)



// WinML







// The device is invalid or does not support machine learning.

WINML_ERR_INVALID_DEVICE         _HRESULT_TYPEDEF_(0x88900001L)






// The binding is incomplete or does not match the input/output description.

WINML_ERR_INVALID_BINDING        _HRESULT_TYPEDEF_(0x88900002L)






// An attempt was made to bind an unknown input or output.

WINML_ERR_VALUE_NOTFOUND         _HRESULT_TYPEDEF_(0x88900003L)






// The size of the buffer provided for a bound variable is invalid.

WINML_ERR_SIZE_MISMATCH          _HRESULT_TYPEDEF_(0x88900004L)
    };

}

#endif
#endif
