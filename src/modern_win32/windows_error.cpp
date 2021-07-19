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

#include <modern_win32/windows_error.h>

namespace modern_win32
{

windows_error_details::windows_error_details() noexcept
    : windows_error_details(GetLastError())
{
}

windows_error_details::windows_error_details(windows_error const error_code) noexcept
    : native_error_code_(static_cast<native_windows_error>(error_code))
{
}
windows_error_details::windows_error_details(native_windows_error const error_code) noexcept
    : native_error_code_(error_code)
{
}

/// <summary>
/// Returns the native windows error code value
/// </summary>
/// <returns>native windows error code value</returns>
native_windows_error windows_error_details::native_error_code() const noexcept
{
    return native_error_code_;
}

/// <summary>
/// Returns true if native_error_code is NO_ERROR
/// </summary>
/// <returns>true if native_error_code is NO_ERROR</returns>
windows_error_details::operator bool() const noexcept
{
    return native_error_code_ == static_cast<native_windows_error>(windows_error::none);
}

/// <summary>
/// Returns the <see cref="windows_error"/> formed using the original native error code if a match is found; otherwise <see cref="windows_error::unknown"/>
/// </summary>
/// <returns><see cref="windows_error"/> formed using the original native error code if a match is found; otherwise <see cref="windows_error::unknown"/></returns>
windows_error windows_error_details::get() const noexcept
{
    switch (native_error_code_) {
        case static_cast<native_windows_error>(windows_error::none):
            return windows_error::none;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_function):
            return windows_error::error_invalid_function;
        
        case static_cast<native_windows_error>(windows_error::error_file_not_found):
            return windows_error::error_file_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_path_not_found):
            return windows_error::error_path_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_open_files):
            return windows_error::error_too_many_open_files;
        
        case static_cast<native_windows_error>(windows_error::error_access_denied):
            return windows_error::error_access_denied;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_handle):
            return windows_error::error_invalid_handle;
        
        case static_cast<native_windows_error>(windows_error::error_arena_trashed):
            return windows_error::error_arena_trashed;
        
        case static_cast<native_windows_error>(windows_error::error_not_enough_memory):
            return windows_error::error_not_enough_memory;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_block):
            return windows_error::error_invalid_block;
        
        case static_cast<native_windows_error>(windows_error::error_bad_environment):
            return windows_error::error_bad_environment;
        
        case static_cast<native_windows_error>(windows_error::error_bad_format):
            return windows_error::error_bad_format;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_access):
            return windows_error::error_invalid_access;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_data):
            return windows_error::error_invalid_data;
        
        case static_cast<native_windows_error>(windows_error::error_outofmemory):
            return windows_error::error_outofmemory;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_drive):
            return windows_error::error_invalid_drive;
        
        case static_cast<native_windows_error>(windows_error::error_current_directory):
            return windows_error::error_current_directory;
        
        case static_cast<native_windows_error>(windows_error::error_not_same_device):
            return windows_error::error_not_same_device;
        
        case static_cast<native_windows_error>(windows_error::error_no_more_files):
            return windows_error::error_no_more_files;
        
        case static_cast<native_windows_error>(windows_error::error_write_protect):
            return windows_error::error_write_protect;
        
        case static_cast<native_windows_error>(windows_error::error_bad_unit):
            return windows_error::error_bad_unit;
        
        case static_cast<native_windows_error>(windows_error::error_not_ready):
            return windows_error::error_not_ready;
        
        case static_cast<native_windows_error>(windows_error::error_bad_command):
            return windows_error::error_bad_command;
        
        case static_cast<native_windows_error>(windows_error::error_crc):
            return windows_error::error_crc;
        
        case static_cast<native_windows_error>(windows_error::error_bad_length):
            return windows_error::error_bad_length;
        
        case static_cast<native_windows_error>(windows_error::error_seek):
            return windows_error::error_seek;
        
        case static_cast<native_windows_error>(windows_error::error_not_dos_disk):
            return windows_error::error_not_dos_disk;
        
        case static_cast<native_windows_error>(windows_error::error_sector_not_found):
            return windows_error::error_sector_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_out_of_paper):
            return windows_error::error_out_of_paper;
        
        case static_cast<native_windows_error>(windows_error::error_write_fault):
            return windows_error::error_write_fault;
        
        case static_cast<native_windows_error>(windows_error::error_read_fault):
            return windows_error::error_read_fault;
        
        case static_cast<native_windows_error>(windows_error::error_gen_failure):
            return windows_error::error_gen_failure;
        
        case static_cast<native_windows_error>(windows_error::error_sharing_violation):
            return windows_error::error_sharing_violation;
        
        case static_cast<native_windows_error>(windows_error::error_lock_violation):
            return windows_error::error_lock_violation;
        
        
        case static_cast<native_windows_error>(windows_error::error_wrong_disk):
            return windows_error::error_wrong_disk;
        
        case static_cast<native_windows_error>(windows_error::error_sharing_buffer_exceeded):
            return windows_error::error_sharing_buffer_exceeded;
        
        case static_cast<native_windows_error>(windows_error::error_handle_eof):
            return windows_error::error_handle_eof;
        
        case static_cast<native_windows_error>(windows_error::error_handle_disk_full):
            return windows_error::error_handle_disk_full;
        
        case static_cast<native_windows_error>(windows_error::error_not_supported):
            return windows_error::error_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_rem_not_list):
            return windows_error::error_rem_not_list;
        
        case static_cast<native_windows_error>(windows_error::error_dup_name):
            return windows_error::error_dup_name;
        
        case static_cast<native_windows_error>(windows_error::error_bad_netpath):
            return windows_error::error_bad_netpath;
        
        case static_cast<native_windows_error>(windows_error::error_network_busy):
            return windows_error::error_network_busy;
        
        case static_cast<native_windows_error>(windows_error::error_dev_not_exist):
            return windows_error::error_dev_not_exist;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_cmds):
            return windows_error::error_too_many_cmds;
        
        case static_cast<native_windows_error>(windows_error::error_adap_hdw_err):
            return windows_error::error_adap_hdw_err;
        
        case static_cast<native_windows_error>(windows_error::error_bad_net_resp):
            return windows_error::error_bad_net_resp;
        
        case static_cast<native_windows_error>(windows_error::error_unexp_net_err):
            return windows_error::error_unexp_net_err;
        
        case static_cast<native_windows_error>(windows_error::error_bad_rem_adap):
            return windows_error::error_bad_rem_adap;
        
        case static_cast<native_windows_error>(windows_error::error_printq_full):
            return windows_error::error_printq_full;
        
        case static_cast<native_windows_error>(windows_error::error_no_spool_space):
            return windows_error::error_no_spool_space;
        
        case static_cast<native_windows_error>(windows_error::error_print_cancelled):
            return windows_error::error_print_cancelled;
        
        case static_cast<native_windows_error>(windows_error::error_netname_deleted):
            return windows_error::error_netname_deleted;
        
        case static_cast<native_windows_error>(windows_error::error_network_access_denied):
            return windows_error::error_network_access_denied;
        
        case static_cast<native_windows_error>(windows_error::error_bad_dev_type):
            return windows_error::error_bad_dev_type;
        
        case static_cast<native_windows_error>(windows_error::error_bad_net_name):
            return windows_error::error_bad_net_name;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_names):
            return windows_error::error_too_many_names;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_sess):
            return windows_error::error_too_many_sess;
        
        case static_cast<native_windows_error>(windows_error::error_sharing_paused):
            return windows_error::error_sharing_paused;
        
        case static_cast<native_windows_error>(windows_error::error_req_not_accep):
            return windows_error::error_req_not_accep;
        
        case static_cast<native_windows_error>(windows_error::error_redir_paused):
            return windows_error::error_redir_paused;
        
        case static_cast<native_windows_error>(windows_error::error_file_exists):
            return windows_error::error_file_exists;
        
        case static_cast<native_windows_error>(windows_error::error_cannot_make):
            return windows_error::error_cannot_make;
        
        case static_cast<native_windows_error>(windows_error::error_fail_i24):
            return windows_error::error_fail_i24;
        
        case static_cast<native_windows_error>(windows_error::error_out_of_structures):
            return windows_error::error_out_of_structures;
        
        case static_cast<native_windows_error>(windows_error::error_already_assigned):
            return windows_error::error_already_assigned;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_password):
            return windows_error::error_invalid_password;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_parameter):
            return windows_error::error_invalid_parameter;
        
        case static_cast<native_windows_error>(windows_error::error_net_write_fault):
            return windows_error::error_net_write_fault;
        
        case static_cast<native_windows_error>(windows_error::error_no_proc_slots):
            return windows_error::error_no_proc_slots;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_semaphores):
            return windows_error::error_too_many_semaphores;
        
        case static_cast<native_windows_error>(windows_error::error_excl_sem_already_owned):
            return windows_error::error_excl_sem_already_owned;
        
        case static_cast<native_windows_error>(windows_error::error_sem_is_set):
            return windows_error::error_sem_is_set;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_sem_requests):
            return windows_error::error_too_many_sem_requests;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_at_interrupt_time):
            return windows_error::error_invalid_at_interrupt_time;
        
        case static_cast<native_windows_error>(windows_error::error_sem_owner_died):
            return windows_error::error_sem_owner_died;
        
        case static_cast<native_windows_error>(windows_error::error_sem_user_limit):
            return windows_error::error_sem_user_limit;
        
        case static_cast<native_windows_error>(windows_error::error_disk_change):
            return windows_error::error_disk_change;
        
        case static_cast<native_windows_error>(windows_error::error_drive_locked):
            return windows_error::error_drive_locked;
        
        case static_cast<native_windows_error>(windows_error::error_broken_pipe):
            return windows_error::error_broken_pipe;
        
        case static_cast<native_windows_error>(windows_error::error_open_failed):
            return windows_error::error_open_failed;
        
        case static_cast<native_windows_error>(windows_error::error_buffer_overflow):
            return windows_error::error_buffer_overflow;
        
        case static_cast<native_windows_error>(windows_error::error_disk_full):
            return windows_error::error_disk_full;
        
        case static_cast<native_windows_error>(windows_error::error_no_more_search_handles):
            return windows_error::error_no_more_search_handles;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_target_handle):
            return windows_error::error_invalid_target_handle;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_category):
            return windows_error::error_invalid_category;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_verify_switch):
            return windows_error::error_invalid_verify_switch;
        
        case static_cast<native_windows_error>(windows_error::error_bad_driver_level):
            return windows_error::error_bad_driver_level;
        
        case static_cast<native_windows_error>(windows_error::error_call_not_implemented):
            return windows_error::error_call_not_implemented;
        
        case static_cast<native_windows_error>(windows_error::error_sem_timeout):
            return windows_error::error_sem_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_insufficient_buffer):
            return windows_error::error_insufficient_buffer;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_name):
            return windows_error::error_invalid_name;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_level):
            return windows_error::error_invalid_level;
        
        case static_cast<native_windows_error>(windows_error::error_no_volume_label):
            return windows_error::error_no_volume_label;
        
        case static_cast<native_windows_error>(windows_error::error_mod_not_found):
            return windows_error::error_mod_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_proc_not_found):
            return windows_error::error_proc_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_wait_no_children):
            return windows_error::error_wait_no_children;
        
        case static_cast<native_windows_error>(windows_error::error_child_not_complete):
            return windows_error::error_child_not_complete;
        
        case static_cast<native_windows_error>(windows_error::error_direct_access_handle):
            return windows_error::error_direct_access_handle;
        
        case static_cast<native_windows_error>(windows_error::error_negative_seek):
            return windows_error::error_negative_seek;
        
        case static_cast<native_windows_error>(windows_error::error_seek_on_device):
            return windows_error::error_seek_on_device;
        
        case static_cast<native_windows_error>(windows_error::error_is_join_target):
            return windows_error::error_is_join_target;
        
        case static_cast<native_windows_error>(windows_error::error_is_joined):
            return windows_error::error_is_joined;
        
        case static_cast<native_windows_error>(windows_error::error_is_substed):
            return windows_error::error_is_substed;
        
        case static_cast<native_windows_error>(windows_error::error_not_joined):
            return windows_error::error_not_joined;
        
        case static_cast<native_windows_error>(windows_error::error_not_substed):
            return windows_error::error_not_substed;
        
        case static_cast<native_windows_error>(windows_error::error_join_to_join):
            return windows_error::error_join_to_join;
        
        case static_cast<native_windows_error>(windows_error::error_subst_to_subst):
            return windows_error::error_subst_to_subst;
        
        case static_cast<native_windows_error>(windows_error::error_join_to_subst):
            return windows_error::error_join_to_subst;
        
        case static_cast<native_windows_error>(windows_error::error_subst_to_join):
            return windows_error::error_subst_to_join;
        
        case static_cast<native_windows_error>(windows_error::error_busy_drive):
            return windows_error::error_busy_drive;
        
        case static_cast<native_windows_error>(windows_error::error_same_drive):
            return windows_error::error_same_drive;
        
        case static_cast<native_windows_error>(windows_error::error_dir_not_root):
            return windows_error::error_dir_not_root;
        
        case static_cast<native_windows_error>(windows_error::error_dir_not_empty):
            return windows_error::error_dir_not_empty;
        
        case static_cast<native_windows_error>(windows_error::error_is_subst_path):
            return windows_error::error_is_subst_path;
        
        case static_cast<native_windows_error>(windows_error::error_is_join_path):
            return windows_error::error_is_join_path;
        
        case static_cast<native_windows_error>(windows_error::error_path_busy):
            return windows_error::error_path_busy;
        
        case static_cast<native_windows_error>(windows_error::error_is_subst_target):
            return windows_error::error_is_subst_target;
        
        case static_cast<native_windows_error>(windows_error::error_system_trace):
            return windows_error::error_system_trace;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_event_count):
            return windows_error::error_invalid_event_count;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_muxwaiters):
            return windows_error::error_too_many_muxwaiters;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_list_format):
            return windows_error::error_invalid_list_format;
        
        case static_cast<native_windows_error>(windows_error::error_label_too_long):
            return windows_error::error_label_too_long;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_tcbs):
            return windows_error::error_too_many_tcbs;
        
        case static_cast<native_windows_error>(windows_error::error_signal_refused):
            return windows_error::error_signal_refused;
        
        case static_cast<native_windows_error>(windows_error::error_discarded):
            return windows_error::error_discarded;
        
        case static_cast<native_windows_error>(windows_error::error_not_locked):
            return windows_error::error_not_locked;
        
        case static_cast<native_windows_error>(windows_error::error_bad_threadid_addr):
            return windows_error::error_bad_threadid_addr;
        
        case static_cast<native_windows_error>(windows_error::error_bad_arguments):
            return windows_error::error_bad_arguments;
        
        case static_cast<native_windows_error>(windows_error::error_bad_pathname):
            return windows_error::error_bad_pathname;
        
        case static_cast<native_windows_error>(windows_error::error_signal_pending):
            return windows_error::error_signal_pending;
        
        case static_cast<native_windows_error>(windows_error::error_max_thrds_reached):
            return windows_error::error_max_thrds_reached;
        
        case static_cast<native_windows_error>(windows_error::error_lock_failed):
            return windows_error::error_lock_failed;
        
        case static_cast<native_windows_error>(windows_error::error_busy):
            return windows_error::error_busy;
        
        case static_cast<native_windows_error>(windows_error::error_device_support_in_progress):
            return windows_error::error_device_support_in_progress;
        
        case static_cast<native_windows_error>(windows_error::error_cancel_violation):
            return windows_error::error_cancel_violation;
        
        case static_cast<native_windows_error>(windows_error::error_atomic_locks_not_supported):
            return windows_error::error_atomic_locks_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_segment_number):
            return windows_error::error_invalid_segment_number;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_ordinal):
            return windows_error::error_invalid_ordinal;
        
        case static_cast<native_windows_error>(windows_error::error_already_exists):
            return windows_error::error_already_exists;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_flag_number):
            return windows_error::error_invalid_flag_number;
        
        case static_cast<native_windows_error>(windows_error::error_sem_not_found):
            return windows_error::error_sem_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_starting_codeseg):
            return windows_error::error_invalid_starting_codeseg;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_stackseg):
            return windows_error::error_invalid_stackseg;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_moduletype):
            return windows_error::error_invalid_moduletype;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_exe_signature):
            return windows_error::error_invalid_exe_signature;
        
        case static_cast<native_windows_error>(windows_error::error_exe_marked_invalid):
            return windows_error::error_exe_marked_invalid;
        
        case static_cast<native_windows_error>(windows_error::error_bad_exe_format):
            return windows_error::error_bad_exe_format;
        
        case static_cast<native_windows_error>(windows_error::error_iterated_data_exceeds_64k):
            return windows_error::error_iterated_data_exceeds_64k;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_minallocsize):
            return windows_error::error_invalid_minallocsize;
        
        case static_cast<native_windows_error>(windows_error::error_dynlink_from_invalid_ring):
            return windows_error::error_dynlink_from_invalid_ring;
        
        case static_cast<native_windows_error>(windows_error::error_iopl_not_enabled):
            return windows_error::error_iopl_not_enabled;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_segdpl):
            return windows_error::error_invalid_segdpl;
        
        case static_cast<native_windows_error>(windows_error::error_autodataseg_exceeds_64k):
            return windows_error::error_autodataseg_exceeds_64k;
        
        case static_cast<native_windows_error>(windows_error::error_ring2seg_must_be_movable):
            return windows_error::error_ring2seg_must_be_movable;
        
        case static_cast<native_windows_error>(windows_error::error_reloc_chain_xeeds_seglim):
            return windows_error::error_reloc_chain_xeeds_seglim;
        
        case static_cast<native_windows_error>(windows_error::error_infloop_in_reloc_chain):
            return windows_error::error_infloop_in_reloc_chain;
        
        case static_cast<native_windows_error>(windows_error::error_envvar_not_found):
            return windows_error::error_envvar_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_no_signal_sent):
            return windows_error::error_no_signal_sent;
        
        case static_cast<native_windows_error>(windows_error::error_filename_exced_range):
            return windows_error::error_filename_exced_range;
        
        case static_cast<native_windows_error>(windows_error::error_ring2_stack_in_use):
            return windows_error::error_ring2_stack_in_use;
        
        case static_cast<native_windows_error>(windows_error::error_meta_expansion_too_long):
            return windows_error::error_meta_expansion_too_long;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_signal_number):
            return windows_error::error_invalid_signal_number;
        
        case static_cast<native_windows_error>(windows_error::error_thread_1_inactive):
            return windows_error::error_thread_1_inactive;
        
        case static_cast<native_windows_error>(windows_error::error_locked):
            return windows_error::error_locked;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_modules):
            return windows_error::error_too_many_modules;
        
        case static_cast<native_windows_error>(windows_error::error_nesting_not_allowed):
            return windows_error::error_nesting_not_allowed;
        
        case static_cast<native_windows_error>(windows_error::error_exe_machine_type_mismatch):
            return windows_error::error_exe_machine_type_mismatch;
        
        case static_cast<native_windows_error>(windows_error::error_exe_cannot_modify_signed_binary):
            return windows_error::error_exe_cannot_modify_signed_binary;
        
        case static_cast<native_windows_error>(windows_error::error_exe_cannot_modify_strong_signed_binary):
            return windows_error::error_exe_cannot_modify_strong_signed_binary;
        
        case static_cast<native_windows_error>(windows_error::error_file_checked_out):
            return windows_error::error_file_checked_out;
        
        case static_cast<native_windows_error>(windows_error::error_checkout_required):
            return windows_error::error_checkout_required;
        
        case static_cast<native_windows_error>(windows_error::error_bad_file_type):
            return windows_error::error_bad_file_type;
        
        case static_cast<native_windows_error>(windows_error::error_file_too_large):
            return windows_error::error_file_too_large;
        
        case static_cast<native_windows_error>(windows_error::error_forms_auth_required):
            return windows_error::error_forms_auth_required;
        
        case static_cast<native_windows_error>(windows_error::error_virus_infected):
            return windows_error::error_virus_infected;
        
        case static_cast<native_windows_error>(windows_error::error_virus_deleted):
            return windows_error::error_virus_deleted;
        
        case static_cast<native_windows_error>(windows_error::error_pipe_local):
            return windows_error::error_pipe_local;
        
        case static_cast<native_windows_error>(windows_error::error_bad_pipe):
            return windows_error::error_bad_pipe;
        
        case static_cast<native_windows_error>(windows_error::error_pipe_busy):
            return windows_error::error_pipe_busy;
        
        case static_cast<native_windows_error>(windows_error::error_no_data):
            return windows_error::error_no_data;
        
        case static_cast<native_windows_error>(windows_error::error_pipe_not_connected):
            return windows_error::error_pipe_not_connected;
        
        case static_cast<native_windows_error>(windows_error::error_more_data):
            return windows_error::error_more_data;
        
        case static_cast<native_windows_error>(windows_error::error_no_work_done):
            return windows_error::error_no_work_done;
        
        case static_cast<native_windows_error>(windows_error::error_vc_disconnected):
            return windows_error::error_vc_disconnected;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_ea_name):
            return windows_error::error_invalid_ea_name;
        
        case static_cast<native_windows_error>(windows_error::error_ea_list_inconsistent):
            return windows_error::error_ea_list_inconsistent;
        
        case static_cast<native_windows_error>(windows_error::wait_timeout):
            return windows_error::wait_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_no_more_items):
            return windows_error::error_no_more_items;
        
        case static_cast<native_windows_error>(windows_error::error_cannot_copy):
            return windows_error::error_cannot_copy;
        
        case static_cast<native_windows_error>(windows_error::error_directory):
            return windows_error::error_directory;
        
        case static_cast<native_windows_error>(windows_error::error_eas_didnt_fit):
            return windows_error::error_eas_didnt_fit;
        
        case static_cast<native_windows_error>(windows_error::error_ea_file_corrupt):
            return windows_error::error_ea_file_corrupt;
        
        case static_cast<native_windows_error>(windows_error::error_ea_table_full):
            return windows_error::error_ea_table_full;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_ea_handle):
            return windows_error::error_invalid_ea_handle;
        
        case static_cast<native_windows_error>(windows_error::error_eas_not_supported):
            return windows_error::error_eas_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_not_owner):
            return windows_error::error_not_owner;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_posts):
            return windows_error::error_too_many_posts;
        
        case static_cast<native_windows_error>(windows_error::error_partial_copy):
            return windows_error::error_partial_copy;
        
        case static_cast<native_windows_error>(windows_error::error_oplock_not_granted):
            return windows_error::error_oplock_not_granted;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_oplock_protocol):
            return windows_error::error_invalid_oplock_protocol;
        
        case static_cast<native_windows_error>(windows_error::error_disk_too_fragmented):
            return windows_error::error_disk_too_fragmented;
        
        case static_cast<native_windows_error>(windows_error::error_delete_pending):
            return windows_error::error_delete_pending;
        
        case static_cast<native_windows_error>(windows_error::error_incompatible_with_global_short_name_registry_setting):
            return windows_error::error_incompatible_with_global_short_name_registry_setting;
        
        case static_cast<native_windows_error>(windows_error::error_short_names_not_enabled_on_volume):
            return windows_error::error_short_names_not_enabled_on_volume;
        
        
        case static_cast<native_windows_error>(windows_error::error_security_stream_is_inconsistent):
            return windows_error::error_security_stream_is_inconsistent;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_lock_range):
            return windows_error::error_invalid_lock_range;
        
        case static_cast<native_windows_error>(windows_error::error_image_subsystem_not_present):
            return windows_error::error_image_subsystem_not_present;
        
        case static_cast<native_windows_error>(windows_error::error_notification_guid_already_defined):
            return windows_error::error_notification_guid_already_defined;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_exception_handler):
            return windows_error::error_invalid_exception_handler;
        
        case static_cast<native_windows_error>(windows_error::error_duplicate_privileges):
            return windows_error::error_duplicate_privileges;
        
        case static_cast<native_windows_error>(windows_error::error_no_ranges_processed):
            return windows_error::error_no_ranges_processed;
        
        case static_cast<native_windows_error>(windows_error::error_not_allowed_on_system_file):
            return windows_error::error_not_allowed_on_system_file;
        
        case static_cast<native_windows_error>(windows_error::error_disk_resources_exhausted):
            return windows_error::error_disk_resources_exhausted;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_token):
            return windows_error::error_invalid_token;
        
        case static_cast<native_windows_error>(windows_error::error_device_feature_not_supported):
            return windows_error::error_device_feature_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_mr_mid_not_found):
            return windows_error::error_mr_mid_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_scope_not_found):
            return windows_error::error_scope_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_undefined_scope):
            return windows_error::error_undefined_scope;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_cap):
            return windows_error::error_invalid_cap;
        
        case static_cast<native_windows_error>(windows_error::error_device_unreachable):
            return windows_error::error_device_unreachable;
        
        case static_cast<native_windows_error>(windows_error::error_device_no_resources):
            return windows_error::error_device_no_resources;
        
        case static_cast<native_windows_error>(windows_error::error_data_checksum_error):
            return windows_error::error_data_checksum_error;
        
        case static_cast<native_windows_error>(windows_error::error_intermixed_kernel_ea_operation):
            return windows_error::error_intermixed_kernel_ea_operation;
        
        case static_cast<native_windows_error>(windows_error::error_file_level_trim_not_supported):
            return windows_error::error_file_level_trim_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_offset_alignment_violation):
            return windows_error::error_offset_alignment_violation;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_field_in_parameter_list):
            return windows_error::error_invalid_field_in_parameter_list;
        
        case static_cast<native_windows_error>(windows_error::error_operation_in_progress):
            return windows_error::error_operation_in_progress;
        
        case static_cast<native_windows_error>(windows_error::error_bad_device_path):
            return windows_error::error_bad_device_path;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_descriptors):
            return windows_error::error_too_many_descriptors;
        
        case static_cast<native_windows_error>(windows_error::error_scrub_data_disabled):
            return windows_error::error_scrub_data_disabled;
        
        case static_cast<native_windows_error>(windows_error::error_not_redundant_storage):
            return windows_error::error_not_redundant_storage;
        
        case static_cast<native_windows_error>(windows_error::error_resident_file_not_supported):
            return windows_error::error_resident_file_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_compressed_file_not_supported):
            return windows_error::error_compressed_file_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_directory_not_supported):
            return windows_error::error_directory_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_not_read_from_copy):
            return windows_error::error_not_read_from_copy;
        
        case static_cast<native_windows_error>(windows_error::error_ft_write_failure):
            return windows_error::error_ft_write_failure;
        
        case static_cast<native_windows_error>(windows_error::error_ft_di_scan_required):
            return windows_error::error_ft_di_scan_required;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_kernel_info_version):
            return windows_error::error_invalid_kernel_info_version;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_pep_info_version):
            return windows_error::error_invalid_pep_info_version;
        
        case static_cast<native_windows_error>(windows_error::error_object_not_externally_backed):
            return windows_error::error_object_not_externally_backed;
        
        case static_cast<native_windows_error>(windows_error::error_external_backing_provider_unknown):
            return windows_error::error_external_backing_provider_unknown;
        
        case static_cast<native_windows_error>(windows_error::error_compression_not_beneficial):
            return windows_error::error_compression_not_beneficial;
        
        case static_cast<native_windows_error>(windows_error::error_storage_topology_id_mismatch):
            return windows_error::error_storage_topology_id_mismatch;
        
        case static_cast<native_windows_error>(windows_error::error_blocked_by_parental_controls):
            return windows_error::error_blocked_by_parental_controls;
        
        case static_cast<native_windows_error>(windows_error::error_block_too_many_references):
            return windows_error::error_block_too_many_references;
        
        case static_cast<native_windows_error>(windows_error::error_marked_to_disallow_writes):
            return windows_error::error_marked_to_disallow_writes;
        
        case static_cast<native_windows_error>(windows_error::error_enclave_failure):
            return windows_error::error_enclave_failure;
        
        case static_cast<native_windows_error>(windows_error::error_fail_noaction_reboot):
            return windows_error::error_fail_noaction_reboot;
        
        case static_cast<native_windows_error>(windows_error::error_fail_shutdown):
            return windows_error::error_fail_shutdown;
        
        case static_cast<native_windows_error>(windows_error::error_fail_restart):
            return windows_error::error_fail_restart;
        
        case static_cast<native_windows_error>(windows_error::error_max_sessions_reached):
            return windows_error::error_max_sessions_reached;
        
        case static_cast<native_windows_error>(windows_error::error_network_access_denied_edp):
            return windows_error::error_network_access_denied_edp;
        
        case static_cast<native_windows_error>(windows_error::error_device_hint_name_buffer_too_small):
            return windows_error::error_device_hint_name_buffer_too_small;
        
        case static_cast<native_windows_error>(windows_error::error_edp_policy_denies_operation):
            return windows_error::error_edp_policy_denies_operation;
        
        case static_cast<native_windows_error>(windows_error::error_edp_dpl_policy_cant_be_satisfied):
            return windows_error::error_edp_dpl_policy_cant_be_satisfied;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_sync_root_metadata_corrupt):
            return windows_error::error_cloud_file_sync_root_metadata_corrupt;
        
        case static_cast<native_windows_error>(windows_error::error_device_in_maintenance):
            return windows_error::error_device_in_maintenance;
        
        case static_cast<native_windows_error>(windows_error::error_not_supported_on_dax):
            return windows_error::error_not_supported_on_dax;
        
        case static_cast<native_windows_error>(windows_error::error_dax_mapping_exists):
            return windows_error::error_dax_mapping_exists;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_provider_not_running):
            return windows_error::error_cloud_file_provider_not_running;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_metadata_corrupt):
            return windows_error::error_cloud_file_metadata_corrupt;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_metadata_too_large):
            return windows_error::error_cloud_file_metadata_too_large;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_property_blob_too_large):
            return windows_error::error_cloud_file_property_blob_too_large;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_property_blob_checksum_mismatch):
            return windows_error::error_cloud_file_property_blob_checksum_mismatch;
        
        case static_cast<native_windows_error>(windows_error::error_child_process_blocked):
            return windows_error::error_child_process_blocked;
        
        case static_cast<native_windows_error>(windows_error::error_storage_lost_data_persistence):
            return windows_error::error_storage_lost_data_persistence;
        
        case static_cast<native_windows_error>(windows_error::error_file_system_virtualization_unavailable):
            return windows_error::error_file_system_virtualization_unavailable;
        
        case static_cast<native_windows_error>(windows_error::error_file_system_virtualization_metadata_corrupt):
            return windows_error::error_file_system_virtualization_metadata_corrupt;
        
        case static_cast<native_windows_error>(windows_error::error_file_system_virtualization_busy):
            return windows_error::error_file_system_virtualization_busy;
        
        case static_cast<native_windows_error>(windows_error::error_file_system_virtualization_provider_unknown):
            return windows_error::error_file_system_virtualization_provider_unknown;
        
        case static_cast<native_windows_error>(windows_error::error_gdi_handle_leak):
            return windows_error::error_gdi_handle_leak;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_too_many_property_blobs):
            return windows_error::error_cloud_file_too_many_property_blobs;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_property_version_not_supported):
            return windows_error::error_cloud_file_property_version_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_not_a_cloud_file):
            return windows_error::error_not_a_cloud_file;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_not_in_sync):
            return windows_error::error_cloud_file_not_in_sync;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_already_connected):
            return windows_error::error_cloud_file_already_connected;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_not_supported):
            return windows_error::error_cloud_file_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_invalid_request):
            return windows_error::error_cloud_file_invalid_request;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_read_only_volume):
            return windows_error::error_cloud_file_read_only_volume;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_connected_provider_only):
            return windows_error::error_cloud_file_connected_provider_only;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_validation_failed):
            return windows_error::error_cloud_file_validation_failed;
        
        
        case static_cast<native_windows_error>(windows_error::error_smb1_not_available):
            return windows_error::error_smb1_not_available;
        
        case static_cast<native_windows_error>(windows_error::error_file_system_virtualization_invalid_operation):
            return windows_error::error_file_system_virtualization_invalid_operation;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_authentication_failed):
            return windows_error::error_cloud_file_authentication_failed;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_insufficient_resources):
            return windows_error::error_cloud_file_insufficient_resources;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_network_unavailable):
            return windows_error::error_cloud_file_network_unavailable;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_unsuccessful):
            return windows_error::error_cloud_file_unsuccessful;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_not_under_sync_root):
            return windows_error::error_cloud_file_not_under_sync_root;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_in_use):
            return windows_error::error_cloud_file_in_use;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_pinned):
            return windows_error::error_cloud_file_pinned;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_request_aborted):
            return windows_error::error_cloud_file_request_aborted;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_property_corrupt):
            return windows_error::error_cloud_file_property_corrupt;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_access_denied):
            return windows_error::error_cloud_file_access_denied;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_incompatible_hardlinks):
            return windows_error::error_cloud_file_incompatible_hardlinks;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_property_lock_conflict):
            return windows_error::error_cloud_file_property_lock_conflict;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_request_canceled):
            return windows_error::error_cloud_file_request_canceled;
        
        case static_cast<native_windows_error>(windows_error::error_external_syskey_not_supported):
            return windows_error::error_external_syskey_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_thread_mode_already_background):
            return windows_error::error_thread_mode_already_background;
        
        case static_cast<native_windows_error>(windows_error::error_thread_mode_not_background):
            return windows_error::error_thread_mode_not_background;
        
        case static_cast<native_windows_error>(windows_error::error_process_mode_already_background):
            return windows_error::error_process_mode_already_background;
        
        case static_cast<native_windows_error>(windows_error::error_process_mode_not_background):
            return windows_error::error_process_mode_not_background;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_provider_terminated):
            return windows_error::error_cloud_file_provider_terminated;
        
        case static_cast<native_windows_error>(windows_error::error_not_a_cloud_sync_root):
            return windows_error::error_not_a_cloud_sync_root;
        
        case static_cast<native_windows_error>(windows_error::error_file_protected_under_dpl):
            return windows_error::error_file_protected_under_dpl;
        
        case static_cast<native_windows_error>(windows_error::error_volume_not_cluster_aligned):
            return windows_error::error_volume_not_cluster_aligned;
        
        case static_cast<native_windows_error>(windows_error::error_no_physically_aligned_free_space_found):
            return windows_error::error_no_physically_aligned_free_space_found;
        
        case static_cast<native_windows_error>(windows_error::error_appx_file_not_encrypted):
            return windows_error::error_appx_file_not_encrypted;
        
        case static_cast<native_windows_error>(windows_error::error_rwraw_encrypted_file_not_encrypted):
            return windows_error::error_rwraw_encrypted_file_not_encrypted;
        
        case static_cast<native_windows_error>(windows_error::error_rwraw_encrypted_invalid_edatainfo_fileoffset):
            return windows_error::error_rwraw_encrypted_invalid_edatainfo_fileoffset;
        
        case static_cast<native_windows_error>(windows_error::error_rwraw_encrypted_invalid_edatainfo_filerange):
            return windows_error::error_rwraw_encrypted_invalid_edatainfo_filerange;
        
        case static_cast<native_windows_error>(windows_error::error_rwraw_encrypted_invalid_edatainfo_parameter):
            return windows_error::error_rwraw_encrypted_invalid_edatainfo_parameter;
        
        case static_cast<native_windows_error>(windows_error::error_linux_subsystem_not_present):
            return windows_error::error_linux_subsystem_not_present;
        
        case static_cast<native_windows_error>(windows_error::error_ft_read_failure):
            return windows_error::error_ft_read_failure;
        
        case static_cast<native_windows_error>(windows_error::error_storage_reserve_id_invalid):
            return windows_error::error_storage_reserve_id_invalid;
        
        case static_cast<native_windows_error>(windows_error::error_storage_reserve_does_not_exist):
            return windows_error::error_storage_reserve_does_not_exist;
        
        case static_cast<native_windows_error>(windows_error::error_storage_reserve_already_exists):
            return windows_error::error_storage_reserve_already_exists;
        
        case static_cast<native_windows_error>(windows_error::error_storage_reserve_not_empty):
            return windows_error::error_storage_reserve_not_empty;
        
        case static_cast<native_windows_error>(windows_error::error_not_a_dax_volume):
            return windows_error::error_not_a_dax_volume;
        
        case static_cast<native_windows_error>(windows_error::error_not_dax_mappable):
            return windows_error::error_not_dax_mappable;
        
        case static_cast<native_windows_error>(windows_error::error_time_sensitive_thread):
            return windows_error::error_time_sensitive_thread;
        
        case static_cast<native_windows_error>(windows_error::error_dpl_not_supported_for_user):
            return windows_error::error_dpl_not_supported_for_user;
        
        case static_cast<native_windows_error>(windows_error::error_case_differing_names_in_dir):
            return windows_error::error_case_differing_names_in_dir;
        
        case static_cast<native_windows_error>(windows_error::error_file_not_supported):
            return windows_error::error_file_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_cloud_file_request_timeout):
            return windows_error::error_cloud_file_request_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_no_task_queue):
            return windows_error::error_no_task_queue;
        
        case static_cast<native_windows_error>(windows_error::error_src_srv_dll_load_failed):
            return windows_error::error_src_srv_dll_load_failed;
        
        case static_cast<native_windows_error>(windows_error::error_not_supported_with_btt):
            return windows_error::error_not_supported_with_btt;
        
        case static_cast<native_windows_error>(windows_error::error_encryption_disabled):
            return windows_error::error_encryption_disabled;
        
        case static_cast<native_windows_error>(windows_error::error_encrypting_metadata_disallowed):
            return windows_error::error_encrypting_metadata_disallowed;
        
        case static_cast<native_windows_error>(windows_error::error_cant_clear_encryption_flag):
            return windows_error::error_cant_clear_encryption_flag;
        
        case static_cast<native_windows_error>(windows_error::error_no_such_device):
            return windows_error::error_no_such_device;

        
        case static_cast<native_windows_error>(windows_error::error_capauthz_not_devunlocked):
            return windows_error::error_capauthz_not_devunlocked;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_change_type):
            return windows_error::error_capauthz_change_type;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_not_provisioned):
            return windows_error::error_capauthz_not_provisioned;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_not_authorized):
            return windows_error::error_capauthz_not_authorized;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_no_policy):
            return windows_error::error_capauthz_no_policy;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_db_corrupted):
            return windows_error::error_capauthz_db_corrupted;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_sccd_invalid_catalog):
            return windows_error::error_capauthz_sccd_invalid_catalog;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_sccd_no_auth_entity):
            return windows_error::error_capauthz_sccd_no_auth_entity;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_sccd_parse_error):
            return windows_error::error_capauthz_sccd_parse_error;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_sccd_dev_mode_required):
            return windows_error::error_capauthz_sccd_dev_mode_required;
        
        case static_cast<native_windows_error>(windows_error::error_capauthz_sccd_no_capability_match):
            return windows_error::error_capauthz_sccd_no_capability_match;
        
        
        case static_cast<native_windows_error>(windows_error::error_pnp_query_remove_device_timeout):
            return windows_error::error_pnp_query_remove_device_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_pnp_query_remove_related_device_timeout):
            return windows_error::error_pnp_query_remove_related_device_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_pnp_query_remove_unrelated_device_timeout):
            return windows_error::error_pnp_query_remove_unrelated_device_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_device_hardware_error):
            return windows_error::error_device_hardware_error;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_address):
            return windows_error::error_invalid_address;
        
        case static_cast<native_windows_error>(windows_error::error_vrf_cfg_enabled):
            return windows_error::error_vrf_cfg_enabled;
        
        case static_cast<native_windows_error>(windows_error::error_partition_terminating):
            return windows_error::error_partition_terminating;
        
        case static_cast<native_windows_error>(windows_error::error_user_profile_load):
            return windows_error::error_user_profile_load;
        
        
        case static_cast<native_windows_error>(windows_error::error_arithmetic_overflow):
            return windows_error::error_arithmetic_overflow;
        
        case static_cast<native_windows_error>(windows_error::error_pipe_connected):
            return windows_error::error_pipe_connected;
        
        case static_cast<native_windows_error>(windows_error::error_pipe_listening):
            return windows_error::error_pipe_listening;
        
        case static_cast<native_windows_error>(windows_error::error_verifier_stop):
            return windows_error::error_verifier_stop;
        
        case static_cast<native_windows_error>(windows_error::error_abios_error):
            return windows_error::error_abios_error;
        
        case static_cast<native_windows_error>(windows_error::error_wx86_warning):
            return windows_error::error_wx86_warning;
        
        case static_cast<native_windows_error>(windows_error::error_wx86_error):
            return windows_error::error_wx86_error;
        
        case static_cast<native_windows_error>(windows_error::error_timer_not_canceled):
            return windows_error::error_timer_not_canceled;
        
        case static_cast<native_windows_error>(windows_error::error_unwind):
            return windows_error::error_unwind;
        
        case static_cast<native_windows_error>(windows_error::error_bad_stack):
            return windows_error::error_bad_stack;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_unwind_target):
            return windows_error::error_invalid_unwind_target;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_port_attributes):
            return windows_error::error_invalid_port_attributes;
        
        case static_cast<native_windows_error>(windows_error::error_port_message_too_long):
            return windows_error::error_port_message_too_long;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_quota_lower):
            return windows_error::error_invalid_quota_lower;
        
        case static_cast<native_windows_error>(windows_error::error_device_already_attached):
            return windows_error::error_device_already_attached;
        
        case static_cast<native_windows_error>(windows_error::error_instruction_misalignment):
            return windows_error::error_instruction_misalignment;
        
        case static_cast<native_windows_error>(windows_error::error_profiling_not_started):
            return windows_error::error_profiling_not_started;
        
        case static_cast<native_windows_error>(windows_error::error_profiling_not_stopped):
            return windows_error::error_profiling_not_stopped;
        
        case static_cast<native_windows_error>(windows_error::error_could_not_interpret):
            return windows_error::error_could_not_interpret;
        
        case static_cast<native_windows_error>(windows_error::error_profiling_at_limit):
            return windows_error::error_profiling_at_limit;
        
        case static_cast<native_windows_error>(windows_error::error_cant_wait):
            return windows_error::error_cant_wait;
        
        case static_cast<native_windows_error>(windows_error::error_cant_terminate_self):
            return windows_error::error_cant_terminate_self;
        
        
        case static_cast<native_windows_error>(windows_error::error_unexpected_mm_create_err):
            return windows_error::error_unexpected_mm_create_err;
        
        
        case static_cast<native_windows_error>(windows_error::error_unexpected_mm_map_error):
            return windows_error::error_unexpected_mm_map_error;
        
        
        case static_cast<native_windows_error>(windows_error::error_unexpected_mm_extend_err):
            return windows_error::error_unexpected_mm_extend_err;
        
        case static_cast<native_windows_error>(windows_error::error_bad_function_table):
            return windows_error::error_bad_function_table;
        
        
        case static_cast<native_windows_error>(windows_error::error_no_guid_translation):
            return windows_error::error_no_guid_translation;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_ldt_size):
            return windows_error::error_invalid_ldt_size;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_ldt_offset):
            return windows_error::error_invalid_ldt_offset;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_ldt_descriptor):
            return windows_error::error_invalid_ldt_descriptor;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_threads):
            return windows_error::error_too_many_threads;
        
        case static_cast<native_windows_error>(windows_error::error_thread_not_in_process):
            return windows_error::error_thread_not_in_process;
        
        case static_cast<native_windows_error>(windows_error::error_pagefile_quota_exceeded):
            return windows_error::error_pagefile_quota_exceeded;
        
        case static_cast<native_windows_error>(windows_error::error_logon_server_conflict):
            return windows_error::error_logon_server_conflict;
        
        case static_cast<native_windows_error>(windows_error::error_synchronization_required):
            return windows_error::error_synchronization_required;
        
        case static_cast<native_windows_error>(windows_error::error_net_open_failed):
            return windows_error::error_net_open_failed;
        
        
        case static_cast<native_windows_error>(windows_error::error_io_privilege_failed):
            return windows_error::error_io_privilege_failed;
        
        
        case static_cast<native_windows_error>(windows_error::error_control_c_exit):
            return windows_error::error_control_c_exit;
        
        
        case static_cast<native_windows_error>(windows_error::error_missing_systemfile):
            return windows_error::error_missing_systemfile;
        
        
        case static_cast<native_windows_error>(windows_error::error_unhandled_exception):
            return windows_error::error_unhandled_exception;
        
        
        case static_cast<native_windows_error>(windows_error::error_app_init_failure):
            return windows_error::error_app_init_failure;
        
        
        case static_cast<native_windows_error>(windows_error::error_pagefile_create_failed):
            return windows_error::error_pagefile_create_failed;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_image_hash):
            return windows_error::error_invalid_image_hash;
        
        
        case static_cast<native_windows_error>(windows_error::error_no_pagefile):
            return windows_error::error_no_pagefile;
        
        
        case static_cast<native_windows_error>(windows_error::error_illegal_float_context):
            return windows_error::error_illegal_float_context;
        
        case static_cast<native_windows_error>(windows_error::error_no_event_pair):
            return windows_error::error_no_event_pair;
        
        case static_cast<native_windows_error>(windows_error::error_domain_ctrlr_config_error):
            return windows_error::error_domain_ctrlr_config_error;
        
        case static_cast<native_windows_error>(windows_error::error_illegal_character):
            return windows_error::error_illegal_character;
        
        case static_cast<native_windows_error>(windows_error::error_undefined_character):
            return windows_error::error_undefined_character;
        
        case static_cast<native_windows_error>(windows_error::error_floppy_volume):
            return windows_error::error_floppy_volume;
        
        case static_cast<native_windows_error>(windows_error::error_bios_failed_to_connect_interrupt):
            return windows_error::error_bios_failed_to_connect_interrupt;
        
        case static_cast<native_windows_error>(windows_error::error_backup_controller):
            return windows_error::error_backup_controller;
        
        case static_cast<native_windows_error>(windows_error::error_mutant_limit_exceeded):
            return windows_error::error_mutant_limit_exceeded;
        
        case static_cast<native_windows_error>(windows_error::error_fs_driver_required):
            return windows_error::error_fs_driver_required;
        
        case static_cast<native_windows_error>(windows_error::error_cannot_load_registry_file):
            return windows_error::error_cannot_load_registry_file;
        
        
        case static_cast<native_windows_error>(windows_error::error_debug_attach_failed):
            return windows_error::error_debug_attach_failed;
        
        case static_cast<native_windows_error>(windows_error::error_system_process_terminated):
            return windows_error::error_system_process_terminated;
        
        
        case static_cast<native_windows_error>(windows_error::error_data_not_accepted):
            return windows_error::error_data_not_accepted;
        
        case static_cast<native_windows_error>(windows_error::error_vdm_hard_error):
            return windows_error::error_vdm_hard_error;
        
        
        case static_cast<native_windows_error>(windows_error::error_driver_cancel_timeout):
            return windows_error::error_driver_cancel_timeout;
        
        
        case static_cast<native_windows_error>(windows_error::error_reply_message_mismatch):
            return windows_error::error_reply_message_mismatch;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_lost_writebehind_data):
            return windows_error::error_lost_writebehind_data;
        
        case static_cast<native_windows_error>(windows_error::error_client_server_parameters_invalid):
            return windows_error::error_client_server_parameters_invalid;
        
        case static_cast<native_windows_error>(windows_error::error_not_tiny_stream):
            return windows_error::error_not_tiny_stream;
        
        case static_cast<native_windows_error>(windows_error::error_stack_overflow_read):
            return windows_error::error_stack_overflow_read;
        
        case static_cast<native_windows_error>(windows_error::error_convert_to_large):
            return windows_error::error_convert_to_large;
        
        case static_cast<native_windows_error>(windows_error::error_found_out_of_scope):
            return windows_error::error_found_out_of_scope;
        
        case static_cast<native_windows_error>(windows_error::error_allocate_bucket):
            return windows_error::error_allocate_bucket;
        
        case static_cast<native_windows_error>(windows_error::error_marshall_overflow):
            return windows_error::error_marshall_overflow;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_variant):
            return windows_error::error_invalid_variant;
        
        case static_cast<native_windows_error>(windows_error::error_bad_compression_buffer):
            return windows_error::error_bad_compression_buffer;
        
        
        case static_cast<native_windows_error>(windows_error::error_audit_failed):
            return windows_error::error_audit_failed;
        
        case static_cast<native_windows_error>(windows_error::error_timer_resolution_not_set):
            return windows_error::error_timer_resolution_not_set;
        
        case static_cast<native_windows_error>(windows_error::error_insufficient_logon_info):
            return windows_error::error_insufficient_logon_info;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_bad_dll_entrypoint):
            return windows_error::error_bad_dll_entrypoint;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_bad_service_entrypoint):
            return windows_error::error_bad_service_entrypoint;
        
        case static_cast<native_windows_error>(windows_error::error_ip_address_conflict1):
            return windows_error::error_ip_address_conflict1;
        
        case static_cast<native_windows_error>(windows_error::error_ip_address_conflict2):
            return windows_error::error_ip_address_conflict2;
        
        
        case static_cast<native_windows_error>(windows_error::error_registry_quota_limit):
            return windows_error::error_registry_quota_limit;
        
        case static_cast<native_windows_error>(windows_error::error_no_callback_active):
            return windows_error::error_no_callback_active;
        
        
        case static_cast<native_windows_error>(windows_error::error_pwd_too_short):
            return windows_error::error_pwd_too_short;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_pwd_too_recent):
            return windows_error::error_pwd_too_recent;
        
        
        case static_cast<native_windows_error>(windows_error::error_pwd_history_conflict):
            return windows_error::error_pwd_history_conflict;
        
        case static_cast<native_windows_error>(windows_error::error_unsupported_compression):
            return windows_error::error_unsupported_compression;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_hw_profile):
            return windows_error::error_invalid_hw_profile;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_plugplay_device_path):
            return windows_error::error_invalid_plugplay_device_path;
        
        case static_cast<native_windows_error>(windows_error::error_quota_list_inconsistent):
            return windows_error::error_quota_list_inconsistent;
        
        
        case static_cast<native_windows_error>(windows_error::error_evaluation_expiration):
            return windows_error::error_evaluation_expiration;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_illegal_dll_relocation):
            return windows_error::error_illegal_dll_relocation;
        
        
        case static_cast<native_windows_error>(windows_error::error_dll_init_failed_logoff):
            return windows_error::error_dll_init_failed_logoff;
        
        case static_cast<native_windows_error>(windows_error::error_validate_continue):
            return windows_error::error_validate_continue;
        
        case static_cast<native_windows_error>(windows_error::error_no_more_matches):
            return windows_error::error_no_more_matches;
        
        case static_cast<native_windows_error>(windows_error::error_range_list_conflict):
            return windows_error::error_range_list_conflict;
        
        case static_cast<native_windows_error>(windows_error::error_server_sid_mismatch):
            return windows_error::error_server_sid_mismatch;
        
        case static_cast<native_windows_error>(windows_error::error_cant_enable_deny_only):
            return windows_error::error_cant_enable_deny_only;
        
        
        case static_cast<native_windows_error>(windows_error::error_float_multiple_faults):
            return windows_error::error_float_multiple_faults;
        
        
        case static_cast<native_windows_error>(windows_error::error_float_multiple_traps):
            return windows_error::error_float_multiple_traps;
        
        case static_cast<native_windows_error>(windows_error::error_nointerface):
            return windows_error::error_nointerface;
        
        
        case static_cast<native_windows_error>(windows_error::error_driver_failed_sleep):
            return windows_error::error_driver_failed_sleep;
        
        case static_cast<native_windows_error>(windows_error::error_corrupt_system_file):
            return windows_error::error_corrupt_system_file;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_commitment_minimum):
            return windows_error::error_commitment_minimum;
        
        case static_cast<native_windows_error>(windows_error::error_pnp_restart_enumeration):
            return windows_error::error_pnp_restart_enumeration;
        
        
        
        
        case static_cast<native_windows_error>(windows_error::error_system_image_bad_signature):
            return windows_error::error_system_image_bad_signature;
        
        case static_cast<native_windows_error>(windows_error::error_pnp_reboot_required):
            return windows_error::error_pnp_reboot_required;
        
        case static_cast<native_windows_error>(windows_error::error_insufficient_power):
            return windows_error::error_insufficient_power;
        
        case static_cast<native_windows_error>(windows_error::error_multiple_fault_violation):
            return windows_error::error_multiple_fault_violation;
        
        case static_cast<native_windows_error>(windows_error::error_system_shutdown):
            return windows_error::error_system_shutdown;
        
        case static_cast<native_windows_error>(windows_error::error_port_not_set):
            return windows_error::error_port_not_set;
        
        case static_cast<native_windows_error>(windows_error::error_ds_version_check_failure):
            return windows_error::error_ds_version_check_failure;
        
        case static_cast<native_windows_error>(windows_error::error_range_not_found):
            return windows_error::error_range_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_not_safe_mode_driver):
            return windows_error::error_not_safe_mode_driver;
        
        case static_cast<native_windows_error>(windows_error::error_failed_driver_entry):
            return windows_error::error_failed_driver_entry;
        
        
        case static_cast<native_windows_error>(windows_error::error_device_enumeration_error):
            return windows_error::error_device_enumeration_error;
        
        case static_cast<native_windows_error>(windows_error::error_mount_point_not_resolved):
            return windows_error::error_mount_point_not_resolved;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_device_object_parameter):
            return windows_error::error_invalid_device_object_parameter;
        
        case static_cast<native_windows_error>(windows_error::error_mca_occured):
            return windows_error::error_mca_occured;
        
        case static_cast<native_windows_error>(windows_error::error_driver_database_error):
            return windows_error::error_driver_database_error;
        
        case static_cast<native_windows_error>(windows_error::error_system_hive_too_large):
            return windows_error::error_system_hive_too_large;
        
        case static_cast<native_windows_error>(windows_error::error_driver_failed_prior_unload):
            return windows_error::error_driver_failed_prior_unload;
        
        
        case static_cast<native_windows_error>(windows_error::error_volsnap_prepare_hibernate):
            return windows_error::error_volsnap_prepare_hibernate;
        
        case static_cast<native_windows_error>(windows_error::error_hibernation_failure):
            return windows_error::error_hibernation_failure;
        
        
        case static_cast<native_windows_error>(windows_error::error_pwd_too_long):
            return windows_error::error_pwd_too_long;
        
        case static_cast<native_windows_error>(windows_error::error_file_system_limitation):
            return windows_error::error_file_system_limitation;
        
        case static_cast<native_windows_error>(windows_error::error_assertion_failure):
            return windows_error::error_assertion_failure;
        
        case static_cast<native_windows_error>(windows_error::error_acpi_error):
            return windows_error::error_acpi_error;
        
        case static_cast<native_windows_error>(windows_error::error_wow_assertion):
            return windows_error::error_wow_assertion;
        
        
        case static_cast<native_windows_error>(windows_error::error_pnp_bad_mps_table):
            return windows_error::error_pnp_bad_mps_table;
        
        case static_cast<native_windows_error>(windows_error::error_pnp_translation_failed):
            return windows_error::error_pnp_translation_failed;
        
        case static_cast<native_windows_error>(windows_error::error_pnp_irq_translation_failed):
            return windows_error::error_pnp_irq_translation_failed;
        
        case static_cast<native_windows_error>(windows_error::error_pnp_invalid_id):
            return windows_error::error_pnp_invalid_id;
        
        
        case static_cast<native_windows_error>(windows_error::error_wake_system_debugger):
            return windows_error::error_wake_system_debugger;
        
        
        case static_cast<native_windows_error>(windows_error::error_handles_closed):
            return windows_error::error_handles_closed;
        
        
        case static_cast<native_windows_error>(windows_error::error_extraneous_information):
            return windows_error::error_extraneous_information;
        
        
        case static_cast<native_windows_error>(windows_error::error_rxact_commit_necessary):
            return windows_error::error_rxact_commit_necessary;
        
        
        case static_cast<native_windows_error>(windows_error::error_media_check):
            return windows_error::error_media_check;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_guid_substitution_made):
            return windows_error::error_guid_substitution_made;
        
        case static_cast<native_windows_error>(windows_error::error_stopped_on_symlink):
            return windows_error::error_stopped_on_symlink;
        
        case static_cast<native_windows_error>(windows_error::error_longjump):
            return windows_error::error_longjump;
        
        case static_cast<native_windows_error>(windows_error::error_plugplay_query_vetoed):
            return windows_error::error_plugplay_query_vetoed;
        
        case static_cast<native_windows_error>(windows_error::error_unwind_consolidate):
            return windows_error::error_unwind_consolidate;
        
        case static_cast<native_windows_error>(windows_error::error_registry_hive_recovered):
            return windows_error::error_registry_hive_recovered;
        
        case static_cast<native_windows_error>(windows_error::error_dll_might_be_insecure):
            return windows_error::error_dll_might_be_insecure;
        
        case static_cast<native_windows_error>(windows_error::error_dll_might_be_incompatible):
            return windows_error::error_dll_might_be_incompatible;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_exception_not_handled):
            return windows_error::error_dbg_exception_not_handled;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_reply_later):
            return windows_error::error_dbg_reply_later;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_unable_to_provide_handle):
            return windows_error::error_dbg_unable_to_provide_handle;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_terminate_thread):
            return windows_error::error_dbg_terminate_thread;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_terminate_process):
            return windows_error::error_dbg_terminate_process;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_control_c):
            return windows_error::error_dbg_control_c;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_printexception_c):
            return windows_error::error_dbg_printexception_c;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_ripexception):
            return windows_error::error_dbg_ripexception;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_control_break):
            return windows_error::error_dbg_control_break;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_command_exception):
            return windows_error::error_dbg_command_exception;
        
        
        case static_cast<native_windows_error>(windows_error::error_object_name_exists):
            return windows_error::error_object_name_exists;
        
        
        case static_cast<native_windows_error>(windows_error::error_thread_was_suspended):
            return windows_error::error_thread_was_suspended;
        
        
        case static_cast<native_windows_error>(windows_error::error_image_not_at_base):
            return windows_error::error_image_not_at_base;
        
        case static_cast<native_windows_error>(windows_error::error_rxact_state_created):
            return windows_error::error_rxact_state_created;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_segment_notification):
            return windows_error::error_segment_notification;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_bad_current_directory):
            return windows_error::error_bad_current_directory;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_ft_read_recovery_from_backup):
            return windows_error::error_ft_read_recovery_from_backup;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_ft_write_recovery):
            return windows_error::error_ft_write_recovery;
        
        
        case static_cast<native_windows_error>(windows_error::error_image_machine_type_mismatch):
            return windows_error::error_image_machine_type_mismatch;
        
        
        case static_cast<native_windows_error>(windows_error::error_receive_partial):
            return windows_error::error_receive_partial;
        
        
        case static_cast<native_windows_error>(windows_error::error_receive_expedited):
            return windows_error::error_receive_expedited;
        
        
        case static_cast<native_windows_error>(windows_error::error_receive_partial_expedited):
            return windows_error::error_receive_partial_expedited;
        
        
        case static_cast<native_windows_error>(windows_error::error_event_done):
            return windows_error::error_event_done;
        
        
        case static_cast<native_windows_error>(windows_error::error_event_pending):
            return windows_error::error_event_pending;
        
        case static_cast<native_windows_error>(windows_error::error_checking_file_system):
            return windows_error::error_checking_file_system;
        
        
        case static_cast<native_windows_error>(windows_error::error_fatal_app_exit):
            return windows_error::error_fatal_app_exit;
        
        case static_cast<native_windows_error>(windows_error::error_predefined_handle):
            return windows_error::error_predefined_handle;
        
        
        case static_cast<native_windows_error>(windows_error::error_was_unlocked):
            return windows_error::error_was_unlocked;
        
        case static_cast<native_windows_error>(windows_error::error_service_notification):
            return windows_error::error_service_notification;
        
        
        case static_cast<native_windows_error>(windows_error::error_was_locked):
            return windows_error::error_was_locked;
        
        case static_cast<native_windows_error>(windows_error::error_log_hard_error):
            return windows_error::error_log_hard_error;
        
        case static_cast<native_windows_error>(windows_error::error_already_win32):
            return windows_error::error_already_win32;
        
        
        case static_cast<native_windows_error>(windows_error::error_image_machine_type_mismatch_exe):
            return windows_error::error_image_machine_type_mismatch_exe;
        
        case static_cast<native_windows_error>(windows_error::error_no_yield_performed):
            return windows_error::error_no_yield_performed;
        
        case static_cast<native_windows_error>(windows_error::error_timer_resume_ignored):
            return windows_error::error_timer_resume_ignored;
        
        case static_cast<native_windows_error>(windows_error::error_arbitration_unhandled):
            return windows_error::error_arbitration_unhandled;
        
        case static_cast<native_windows_error>(windows_error::error_cardbus_not_supported):
            return windows_error::error_cardbus_not_supported;
        
        case static_cast<native_windows_error>(windows_error::error_mp_processor_mismatch):
            return windows_error::error_mp_processor_mismatch;
        
        case static_cast<native_windows_error>(windows_error::error_hibernated):
            return windows_error::error_hibernated;
        
        case static_cast<native_windows_error>(windows_error::error_resume_hibernation):
            return windows_error::error_resume_hibernation;
        
        case static_cast<native_windows_error>(windows_error::error_firmware_updated):
            return windows_error::error_firmware_updated;
        
        case static_cast<native_windows_error>(windows_error::error_drivers_leaking_locked_pages):
            return windows_error::error_drivers_leaking_locked_pages;
        
        case static_cast<native_windows_error>(windows_error::error_wake_system):
            return windows_error::error_wake_system;
        
        case static_cast<native_windows_error>(windows_error::error_wait_1):
            return windows_error::error_wait_1;
        
        case static_cast<native_windows_error>(windows_error::error_wait_2):
            return windows_error::error_wait_2;
        
        case static_cast<native_windows_error>(windows_error::error_wait_3):
            return windows_error::error_wait_3;
        
        case static_cast<native_windows_error>(windows_error::error_wait_63):
            return windows_error::error_wait_63;
        
        case static_cast<native_windows_error>(windows_error::error_abandoned_wait_0):
            return windows_error::error_abandoned_wait_0;
        
        case static_cast<native_windows_error>(windows_error::error_abandoned_wait_63):
            return windows_error::error_abandoned_wait_63;
        
        case static_cast<native_windows_error>(windows_error::error_user_apc):
            return windows_error::error_user_apc;
        
        case static_cast<native_windows_error>(windows_error::error_kernel_apc):
            return windows_error::error_kernel_apc;
        
        case static_cast<native_windows_error>(windows_error::error_alerted):
            return windows_error::error_alerted;
        
        case static_cast<native_windows_error>(windows_error::error_elevation_required):
            return windows_error::error_elevation_required;
        
        case static_cast<native_windows_error>(windows_error::error_reparse):
            return windows_error::error_reparse;
        
        case static_cast<native_windows_error>(windows_error::error_oplock_break_in_progress):
            return windows_error::error_oplock_break_in_progress;
        
        case static_cast<native_windows_error>(windows_error::error_volume_mounted):
            return windows_error::error_volume_mounted;
        
        
        case static_cast<native_windows_error>(windows_error::error_rxact_committed):
            return windows_error::error_rxact_committed;
        
        case static_cast<native_windows_error>(windows_error::error_notify_cleanup):
            return windows_error::error_notify_cleanup;
        
        
        
        case static_cast<native_windows_error>(windows_error::error_primary_transport_connect_failed):
            return windows_error::error_primary_transport_connect_failed;
        
        case static_cast<native_windows_error>(windows_error::error_page_fault_transition):
            return windows_error::error_page_fault_transition;
        
        case static_cast<native_windows_error>(windows_error::error_page_fault_demand_zero):
            return windows_error::error_page_fault_demand_zero;
        
        case static_cast<native_windows_error>(windows_error::error_page_fault_copy_on_write):
            return windows_error::error_page_fault_copy_on_write;
        
        case static_cast<native_windows_error>(windows_error::error_page_fault_guard_page):
            return windows_error::error_page_fault_guard_page;
        
        case static_cast<native_windows_error>(windows_error::error_page_fault_paging_file):
            return windows_error::error_page_fault_paging_file;
        
        case static_cast<native_windows_error>(windows_error::error_cache_page_locked):
            return windows_error::error_cache_page_locked;
        
        case static_cast<native_windows_error>(windows_error::error_crash_dump):
            return windows_error::error_crash_dump;
        
        case static_cast<native_windows_error>(windows_error::error_buffer_all_zeros):
            return windows_error::error_buffer_all_zeros;
        
        case static_cast<native_windows_error>(windows_error::error_reparse_object):
            return windows_error::error_reparse_object;
        
        case static_cast<native_windows_error>(windows_error::error_resource_requirements_changed):
            return windows_error::error_resource_requirements_changed;
        
        case static_cast<native_windows_error>(windows_error::error_translation_complete):
            return windows_error::error_translation_complete;
        
        case static_cast<native_windows_error>(windows_error::error_nothing_to_terminate):
            return windows_error::error_nothing_to_terminate;
        
        case static_cast<native_windows_error>(windows_error::error_process_not_in_job):
            return windows_error::error_process_not_in_job;
        
        case static_cast<native_windows_error>(windows_error::error_process_in_job):
            return windows_error::error_process_in_job;
        
        
        case static_cast<native_windows_error>(windows_error::error_volsnap_hibernate_ready):
            return windows_error::error_volsnap_hibernate_ready;
        
        case static_cast<native_windows_error>(windows_error::error_fsfilter_op_completed_successfully):
            return windows_error::error_fsfilter_op_completed_successfully;
        
        case static_cast<native_windows_error>(windows_error::error_interrupt_vector_already_connected):
            return windows_error::error_interrupt_vector_already_connected;
        
        case static_cast<native_windows_error>(windows_error::error_interrupt_still_connected):
            return windows_error::error_interrupt_still_connected;
        
        case static_cast<native_windows_error>(windows_error::error_wait_for_oplock):
            return windows_error::error_wait_for_oplock;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_exception_handled):
            return windows_error::error_dbg_exception_handled;
        
        case static_cast<native_windows_error>(windows_error::error_dbg_continue):
            return windows_error::error_dbg_continue;
        
        case static_cast<native_windows_error>(windows_error::error_callback_pop_stack):
            return windows_error::error_callback_pop_stack;
        
        case static_cast<native_windows_error>(windows_error::error_compression_disabled):
            return windows_error::error_compression_disabled;
        
        case static_cast<native_windows_error>(windows_error::error_cantfetchbackwards):
            return windows_error::error_cantfetchbackwards;
        
        case static_cast<native_windows_error>(windows_error::error_cantscrollbackwards):
            return windows_error::error_cantscrollbackwards;
        
        case static_cast<native_windows_error>(windows_error::error_rowsnotreleased):
            return windows_error::error_rowsnotreleased;
        
        case static_cast<native_windows_error>(windows_error::error_bad_accessor_flags):
            return windows_error::error_bad_accessor_flags;
        
        case static_cast<native_windows_error>(windows_error::error_errors_encountered):
            return windows_error::error_errors_encountered;
        
        case static_cast<native_windows_error>(windows_error::error_not_capable):
            return windows_error::error_not_capable;
        
        case static_cast<native_windows_error>(windows_error::error_request_out_of_sequence):
            return windows_error::error_request_out_of_sequence;
        
        case static_cast<native_windows_error>(windows_error::error_version_parse_error):
            return windows_error::error_version_parse_error;
        
        case static_cast<native_windows_error>(windows_error::error_badstartposition):
            return windows_error::error_badstartposition;
        
        case static_cast<native_windows_error>(windows_error::error_memory_hardware):
            return windows_error::error_memory_hardware;
        
        case static_cast<native_windows_error>(windows_error::error_disk_repair_disabled):
            return windows_error::error_disk_repair_disabled;
        
        case static_cast<native_windows_error>(windows_error::error_insufficient_resource_for_specified_shared_section_size):
            return windows_error::error_insufficient_resource_for_specified_shared_section_size;
        
        case static_cast<native_windows_error>(windows_error::error_system_powerstate_transition):
            return windows_error::error_system_powerstate_transition;
        
        case static_cast<native_windows_error>(windows_error::error_system_powerstate_complex_transition):
            return windows_error::error_system_powerstate_complex_transition;
        
        case static_cast<native_windows_error>(windows_error::error_mca_exception):
            return windows_error::error_mca_exception;
        
        case static_cast<native_windows_error>(windows_error::error_access_audit_by_policy):
            return windows_error::error_access_audit_by_policy;
        
        case static_cast<native_windows_error>(windows_error::error_access_disabled_no_safer_ui_by_policy):
            return windows_error::error_access_disabled_no_safer_ui_by_policy;
        
        case static_cast<native_windows_error>(windows_error::error_abandon_hiberfile):
            return windows_error::error_abandon_hiberfile;
        
        case static_cast<native_windows_error>(windows_error::error_lost_writebehind_data_network_disconnected):
            return windows_error::error_lost_writebehind_data_network_disconnected;
        
        case static_cast<native_windows_error>(windows_error::error_lost_writebehind_data_network_server_error):
            return windows_error::error_lost_writebehind_data_network_server_error;
        
        case static_cast<native_windows_error>(windows_error::error_lost_writebehind_data_local_disk_error):
            return windows_error::error_lost_writebehind_data_local_disk_error;
        
        case static_cast<native_windows_error>(windows_error::error_bad_mcfg_table):
            return windows_error::error_bad_mcfg_table;
        
        case static_cast<native_windows_error>(windows_error::error_disk_repair_redirected):
            return windows_error::error_disk_repair_redirected;
        
        case static_cast<native_windows_error>(windows_error::error_disk_repair_unsuccessful):
            return windows_error::error_disk_repair_unsuccessful;
        
        case static_cast<native_windows_error>(windows_error::error_corrupt_log_overfull):
            return windows_error::error_corrupt_log_overfull;
        
        case static_cast<native_windows_error>(windows_error::error_corrupt_log_corrupted):
            return windows_error::error_corrupt_log_corrupted;
        
        case static_cast<native_windows_error>(windows_error::error_corrupt_log_unavailable):
            return windows_error::error_corrupt_log_unavailable;
        
        case static_cast<native_windows_error>(windows_error::error_corrupt_log_deleted_full):
            return windows_error::error_corrupt_log_deleted_full;
        
        case static_cast<native_windows_error>(windows_error::error_corrupt_log_cleared):
            return windows_error::error_corrupt_log_cleared;
        
        case static_cast<native_windows_error>(windows_error::error_orphan_name_exhausted):
            return windows_error::error_orphan_name_exhausted;
        
        case static_cast<native_windows_error>(windows_error::error_oplock_switched_to_new_handle):
            return windows_error::error_oplock_switched_to_new_handle;
        
        case static_cast<native_windows_error>(windows_error::error_cannot_grant_requested_oplock):
            return windows_error::error_cannot_grant_requested_oplock;
        
        case static_cast<native_windows_error>(windows_error::error_cannot_break_oplock):
            return windows_error::error_cannot_break_oplock;
        
        case static_cast<native_windows_error>(windows_error::error_oplock_handle_closed):
            return windows_error::error_oplock_handle_closed;
        
        case static_cast<native_windows_error>(windows_error::error_no_ace_condition):
            return windows_error::error_no_ace_condition;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_ace_condition):
            return windows_error::error_invalid_ace_condition;
        
        case static_cast<native_windows_error>(windows_error::error_file_handle_revoked):
            return windows_error::error_file_handle_revoked;
        
        case static_cast<native_windows_error>(windows_error::error_image_at_different_base):
            return windows_error::error_image_at_different_base;
        
        case static_cast<native_windows_error>(windows_error::error_encrypted_io_not_possible):
            return windows_error::error_encrypted_io_not_possible;
        
        case static_cast<native_windows_error>(windows_error::error_file_metadata_optimization_in_progress):
            return windows_error::error_file_metadata_optimization_in_progress;
        
        case static_cast<native_windows_error>(windows_error::error_quota_activity):
            return windows_error::error_quota_activity;
        
        case static_cast<native_windows_error>(windows_error::error_handle_revoked):
            return windows_error::error_handle_revoked;
        
        case static_cast<native_windows_error>(windows_error::error_callback_invoke_inline):
            return windows_error::error_callback_invoke_inline;
        
        case static_cast<native_windows_error>(windows_error::error_cpu_set_invalid):
            return windows_error::error_cpu_set_invalid;
        
        case static_cast<native_windows_error>(windows_error::error_enclave_not_terminated):
            return windows_error::error_enclave_not_terminated;
        
        case static_cast<native_windows_error>(windows_error::error_enclave_violation):
            return windows_error::error_enclave_violation;
        
        
        case static_cast<native_windows_error>(windows_error::error_ea_access_denied):
            return windows_error::error_ea_access_denied;
        
        case static_cast<native_windows_error>(windows_error::error_operation_aborted):
            return windows_error::error_operation_aborted;
        
        case static_cast<native_windows_error>(windows_error::error_io_incomplete):
            return windows_error::error_io_incomplete;
        
        case static_cast<native_windows_error>(windows_error::error_io_pending):
            return windows_error::error_io_pending;
        
        case static_cast<native_windows_error>(windows_error::error_noaccess):
            return windows_error::error_noaccess;
        
        case static_cast<native_windows_error>(windows_error::error_swaperror):
            return windows_error::error_swaperror;
        
        case static_cast<native_windows_error>(windows_error::error_stack_overflow):
            return windows_error::error_stack_overflow;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_message):
            return windows_error::error_invalid_message;
        
        case static_cast<native_windows_error>(windows_error::error_can_not_complete):
            return windows_error::error_can_not_complete;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_flags):
            return windows_error::error_invalid_flags;
        
        
        
        
        case static_cast<native_windows_error>(windows_error::error_unrecognized_volume):
            return windows_error::error_unrecognized_volume;
        
        case static_cast<native_windows_error>(windows_error::error_file_invalid):
            return windows_error::error_file_invalid;
        
        case static_cast<native_windows_error>(windows_error::error_fullscreen_mode):
            return windows_error::error_fullscreen_mode;
        
        case static_cast<native_windows_error>(windows_error::error_no_token):
            return windows_error::error_no_token;
        
        case static_cast<native_windows_error>(windows_error::error_baddb):
            return windows_error::error_baddb;
        
        case static_cast<native_windows_error>(windows_error::error_badkey):
            return windows_error::error_badkey;
        
        case static_cast<native_windows_error>(windows_error::error_cantopen):
            return windows_error::error_cantopen;
        
        case static_cast<native_windows_error>(windows_error::error_cantread):
            return windows_error::error_cantread;
        
        case static_cast<native_windows_error>(windows_error::error_cantwrite):
            return windows_error::error_cantwrite;
        
        case static_cast<native_windows_error>(windows_error::error_registry_recovered):
            return windows_error::error_registry_recovered;
        
        
        
        
        
        case static_cast<native_windows_error>(windows_error::error_registry_corrupt):
            return windows_error::error_registry_corrupt;
        
        case static_cast<native_windows_error>(windows_error::error_registry_io_failed):
            return windows_error::error_registry_io_failed;
        
        case static_cast<native_windows_error>(windows_error::error_not_registry_file):
            return windows_error::error_not_registry_file;
        
        case static_cast<native_windows_error>(windows_error::error_key_deleted):
            return windows_error::error_key_deleted;
        
        case static_cast<native_windows_error>(windows_error::error_no_log_space):
            return windows_error::error_no_log_space;
        
        case static_cast<native_windows_error>(windows_error::error_key_has_children):
            return windows_error::error_key_has_children;
        
        case static_cast<native_windows_error>(windows_error::error_child_must_be_volatile):
            return windows_error::error_child_must_be_volatile;
        
        case static_cast<native_windows_error>(windows_error::error_notify_enum_dir):
            return windows_error::error_notify_enum_dir;
        
        case static_cast<native_windows_error>(windows_error::error_dependent_services_running):
            return windows_error::error_dependent_services_running;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_service_control):
            return windows_error::error_invalid_service_control;
        
        case static_cast<native_windows_error>(windows_error::error_service_request_timeout):
            return windows_error::error_service_request_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_service_no_thread):
            return windows_error::error_service_no_thread;
        
        case static_cast<native_windows_error>(windows_error::error_service_database_locked):
            return windows_error::error_service_database_locked;
        
        case static_cast<native_windows_error>(windows_error::error_service_already_running):
            return windows_error::error_service_already_running;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_service_account):
            return windows_error::error_invalid_service_account;
        
        case static_cast<native_windows_error>(windows_error::error_service_disabled):
            return windows_error::error_service_disabled;
        
        case static_cast<native_windows_error>(windows_error::error_circular_dependency):
            return windows_error::error_circular_dependency;
        
        case static_cast<native_windows_error>(windows_error::error_service_does_not_exist):
            return windows_error::error_service_does_not_exist;
        
        case static_cast<native_windows_error>(windows_error::error_service_cannot_accept_ctrl):
            return windows_error::error_service_cannot_accept_ctrl;
        
        case static_cast<native_windows_error>(windows_error::error_service_not_active):
            return windows_error::error_service_not_active;
        
        case static_cast<native_windows_error>(windows_error::error_failed_service_controller_connect):
            return windows_error::error_failed_service_controller_connect;
        
        case static_cast<native_windows_error>(windows_error::error_exception_in_service):
            return windows_error::error_exception_in_service;
        
        case static_cast<native_windows_error>(windows_error::error_database_does_not_exist):
            return windows_error::error_database_does_not_exist;
        
        case static_cast<native_windows_error>(windows_error::error_service_specific_error):
            return windows_error::error_service_specific_error;
        
        case static_cast<native_windows_error>(windows_error::error_process_aborted):
            return windows_error::error_process_aborted;
        
        case static_cast<native_windows_error>(windows_error::error_service_dependency_fail):
            return windows_error::error_service_dependency_fail;
        
        case static_cast<native_windows_error>(windows_error::error_service_logon_failed):
            return windows_error::error_service_logon_failed;
        
        case static_cast<native_windows_error>(windows_error::error_service_start_hang):
            return windows_error::error_service_start_hang;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_service_lock):
            return windows_error::error_invalid_service_lock;
        
        case static_cast<native_windows_error>(windows_error::error_service_marked_for_delete):
            return windows_error::error_service_marked_for_delete;
        
        case static_cast<native_windows_error>(windows_error::error_service_exists):
            return windows_error::error_service_exists;
        
        case static_cast<native_windows_error>(windows_error::error_already_running_lkg):
            return windows_error::error_already_running_lkg;
        
        case static_cast<native_windows_error>(windows_error::error_service_dependency_deleted):
            return windows_error::error_service_dependency_deleted;
        
        case static_cast<native_windows_error>(windows_error::error_boot_already_accepted):
            return windows_error::error_boot_already_accepted;
        
        case static_cast<native_windows_error>(windows_error::error_service_never_started):
            return windows_error::error_service_never_started;
        
        case static_cast<native_windows_error>(windows_error::error_duplicate_service_name):
            return windows_error::error_duplicate_service_name;
        
        case static_cast<native_windows_error>(windows_error::error_different_service_account):
            return windows_error::error_different_service_account;
        
        case static_cast<native_windows_error>(windows_error::error_cannot_detect_driver_failure):
            return windows_error::error_cannot_detect_driver_failure;
        
        
        case static_cast<native_windows_error>(windows_error::error_cannot_detect_process_abort):
            return windows_error::error_cannot_detect_process_abort;
        
        case static_cast<native_windows_error>(windows_error::error_no_recovery_program):
            return windows_error::error_no_recovery_program;
        
        case static_cast<native_windows_error>(windows_error::error_service_not_in_exe):
            return windows_error::error_service_not_in_exe;
        
        case static_cast<native_windows_error>(windows_error::error_not_safeboot_service):
            return windows_error::error_not_safeboot_service;
        
        case static_cast<native_windows_error>(windows_error::error_end_of_media):
            return windows_error::error_end_of_media;
        
        case static_cast<native_windows_error>(windows_error::error_filemark_detected):
            return windows_error::error_filemark_detected;
        
        case static_cast<native_windows_error>(windows_error::error_beginning_of_media):
            return windows_error::error_beginning_of_media;
        
        case static_cast<native_windows_error>(windows_error::error_setmark_detected):
            return windows_error::error_setmark_detected;
        
        case static_cast<native_windows_error>(windows_error::error_no_data_detected):
            return windows_error::error_no_data_detected;
        
        case static_cast<native_windows_error>(windows_error::error_partition_failure):
            return windows_error::error_partition_failure;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_block_length):
            return windows_error::error_invalid_block_length;
        
        case static_cast<native_windows_error>(windows_error::error_device_not_partitioned):
            return windows_error::error_device_not_partitioned;
        
        case static_cast<native_windows_error>(windows_error::error_unable_to_lock_media):
            return windows_error::error_unable_to_lock_media;
        
        case static_cast<native_windows_error>(windows_error::error_unable_to_unload_media):
            return windows_error::error_unable_to_unload_media;
        
        case static_cast<native_windows_error>(windows_error::error_media_changed):
            return windows_error::error_media_changed;
        
        case static_cast<native_windows_error>(windows_error::error_bus_reset):
            return windows_error::error_bus_reset;
        
        case static_cast<native_windows_error>(windows_error::error_no_media_in_drive):
            return windows_error::error_no_media_in_drive;
        
        case static_cast<native_windows_error>(windows_error::error_no_unicode_translation):
            return windows_error::error_no_unicode_translation;
        
        case static_cast<native_windows_error>(windows_error::error_dll_init_failed):
            return windows_error::error_dll_init_failed;
        
        case static_cast<native_windows_error>(windows_error::error_shutdown_in_progress):
            return windows_error::error_shutdown_in_progress;
        
        case static_cast<native_windows_error>(windows_error::error_no_shutdown_in_progress):
            return windows_error::error_no_shutdown_in_progress;
        
        case static_cast<native_windows_error>(windows_error::error_io_device):
            return windows_error::error_io_device;
        
        case static_cast<native_windows_error>(windows_error::error_serial_no_device):
            return windows_error::error_serial_no_device;
        
        case static_cast<native_windows_error>(windows_error::error_irq_busy):
            return windows_error::error_irq_busy;
        
        
        case static_cast<native_windows_error>(windows_error::error_more_writes):
            return windows_error::error_more_writes;
        
        
        case static_cast<native_windows_error>(windows_error::error_counter_timeout):
            return windows_error::error_counter_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_floppy_id_mark_not_found):
            return windows_error::error_floppy_id_mark_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_floppy_wrong_cylinder):
            return windows_error::error_floppy_wrong_cylinder;
        
        case static_cast<native_windows_error>(windows_error::error_floppy_unknown_error):
            return windows_error::error_floppy_unknown_error;
        
        case static_cast<native_windows_error>(windows_error::error_floppy_bad_registers):
            return windows_error::error_floppy_bad_registers;
        
        case static_cast<native_windows_error>(windows_error::error_disk_recalibrate_failed):
            return windows_error::error_disk_recalibrate_failed;
        
        case static_cast<native_windows_error>(windows_error::error_disk_operation_failed):
            return windows_error::error_disk_operation_failed;
        
        case static_cast<native_windows_error>(windows_error::error_disk_reset_failed):
            return windows_error::error_disk_reset_failed;
        
        case static_cast<native_windows_error>(windows_error::error_eom_overflow):
            return windows_error::error_eom_overflow;
        
        case static_cast<native_windows_error>(windows_error::error_not_enough_server_memory):
            return windows_error::error_not_enough_server_memory;
        
        case static_cast<native_windows_error>(windows_error::error_possible_deadlock):
            return windows_error::error_possible_deadlock;
        
        case static_cast<native_windows_error>(windows_error::error_mapped_alignment):
            return windows_error::error_mapped_alignment;
        
        case static_cast<native_windows_error>(windows_error::error_set_power_state_vetoed):
            return windows_error::error_set_power_state_vetoed;
        
        case static_cast<native_windows_error>(windows_error::error_set_power_state_failed):
            return windows_error::error_set_power_state_failed;
        
        case static_cast<native_windows_error>(windows_error::error_too_many_links):
            return windows_error::error_too_many_links;
        
        case static_cast<native_windows_error>(windows_error::error_old_win_version):
            return windows_error::error_old_win_version;
        
        case static_cast<native_windows_error>(windows_error::error_app_wrong_os):
            return windows_error::error_app_wrong_os;
        
        case static_cast<native_windows_error>(windows_error::error_single_instance_app):
            return windows_error::error_single_instance_app;
        
        case static_cast<native_windows_error>(windows_error::error_rmode_app):
            return windows_error::error_rmode_app;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_dll):
            return windows_error::error_invalid_dll;
        
        case static_cast<native_windows_error>(windows_error::error_no_association):
            return windows_error::error_no_association;
        
        case static_cast<native_windows_error>(windows_error::error_dde_fail):
            return windows_error::error_dde_fail;
        
        case static_cast<native_windows_error>(windows_error::error_dll_not_found):
            return windows_error::error_dll_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_no_more_user_handles):
            return windows_error::error_no_more_user_handles;
        
        case static_cast<native_windows_error>(windows_error::error_message_sync_only):
            return windows_error::error_message_sync_only;
        
        case static_cast<native_windows_error>(windows_error::error_source_element_empty):
            return windows_error::error_source_element_empty;
        
        case static_cast<native_windows_error>(windows_error::error_destination_element_full):
            return windows_error::error_destination_element_full;
        
        case static_cast<native_windows_error>(windows_error::error_illegal_element_address):
            return windows_error::error_illegal_element_address;
        
        case static_cast<native_windows_error>(windows_error::error_magazine_not_present):
            return windows_error::error_magazine_not_present;
        
        case static_cast<native_windows_error>(windows_error::error_device_reinitialization_needed):
            return windows_error::error_device_reinitialization_needed;
        
        case static_cast<native_windows_error>(windows_error::error_device_requires_cleaning):
            return windows_error::error_device_requires_cleaning;
        
        case static_cast<native_windows_error>(windows_error::error_device_door_open):
            return windows_error::error_device_door_open;
        
        case static_cast<native_windows_error>(windows_error::error_device_not_connected):
            return windows_error::error_device_not_connected;
        
        case static_cast<native_windows_error>(windows_error::error_not_found):
            return windows_error::error_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_no_match):
            return windows_error::error_no_match;
        
        case static_cast<native_windows_error>(windows_error::error_set_not_found):
            return windows_error::error_set_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_point_not_found):
            return windows_error::error_point_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_no_tracking_service):
            return windows_error::error_no_tracking_service;
        
        case static_cast<native_windows_error>(windows_error::error_no_volume_id):
            return windows_error::error_no_volume_id;
        
        case static_cast<native_windows_error>(windows_error::error_unable_to_remove_replaced):
            return windows_error::error_unable_to_remove_replaced;
        
        case static_cast<native_windows_error>(windows_error::error_unable_to_move_replacement):
            return windows_error::error_unable_to_move_replacement;
        

        case static_cast<native_windows_error>(windows_error::error_unable_to_move_replacement_2):
            return windows_error::error_unable_to_move_replacement_2;
        

        case static_cast<native_windows_error>(windows_error::error_journal_delete_in_progress):
            return windows_error::error_journal_delete_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_journal_not_active):
            return windows_error::error_journal_not_active;
        

        case static_cast<native_windows_error>(windows_error::error_potential_file_found):
            return windows_error::error_potential_file_found;
        

        case static_cast<native_windows_error>(windows_error::error_journal_entry_deleted):
            return windows_error::error_journal_entry_deleted;
        

        case static_cast<native_windows_error>(windows_error::error_shutdown_is_scheduled):
            return windows_error::error_shutdown_is_scheduled;
        

        case static_cast<native_windows_error>(windows_error::error_shutdown_users_logged_on):
            return windows_error::error_shutdown_users_logged_on;
        

        case static_cast<native_windows_error>(windows_error::error_bad_device):
            return windows_error::error_bad_device;
        

        case static_cast<native_windows_error>(windows_error::error_connection_unavail):
            return windows_error::error_connection_unavail;
        

        case static_cast<native_windows_error>(windows_error::error_device_already_remembered):
            return windows_error::error_device_already_remembered;
        

        case static_cast<native_windows_error>(windows_error::error_no_net_or_bad_path):
            return windows_error::error_no_net_or_bad_path;
        

        case static_cast<native_windows_error>(windows_error::error_bad_provider):
            return windows_error::error_bad_provider;
        

        case static_cast<native_windows_error>(windows_error::error_cannot_open_profile):
            return windows_error::error_cannot_open_profile;
        

        case static_cast<native_windows_error>(windows_error::error_bad_profile):
            return windows_error::error_bad_profile;
        

        case static_cast<native_windows_error>(windows_error::error_not_container):
            return windows_error::error_not_container;
        

        case static_cast<native_windows_error>(windows_error::error_extended_error):
            return windows_error::error_extended_error;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_groupname):
            return windows_error::error_invalid_groupname;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_computername):
            return windows_error::error_invalid_computername;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_eventname):
            return windows_error::error_invalid_eventname;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_domainname):
            return windows_error::error_invalid_domainname;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_servicename):
            return windows_error::error_invalid_servicename;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_netname):
            return windows_error::error_invalid_netname;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_sharename):
            return windows_error::error_invalid_sharename;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_passwordname):
            return windows_error::error_invalid_passwordname;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_messagename):
            return windows_error::error_invalid_messagename;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_messagedest):
            return windows_error::error_invalid_messagedest;
        

        case static_cast<native_windows_error>(windows_error::error_session_credential_conflict):
            return windows_error::error_session_credential_conflict;
        

        case static_cast<native_windows_error>(windows_error::error_remote_session_limit_exceeded):
            return windows_error::error_remote_session_limit_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_dup_domainname):
            return windows_error::error_dup_domainname;
        

        case static_cast<native_windows_error>(windows_error::error_no_network):
            return windows_error::error_no_network;
        

        case static_cast<native_windows_error>(windows_error::error_cancelled):
            return windows_error::error_cancelled;
        

        case static_cast<native_windows_error>(windows_error::error_user_mapped_file):
            return windows_error::error_user_mapped_file;
        

        case static_cast<native_windows_error>(windows_error::error_connection_refused):
            return windows_error::error_connection_refused;
        

        case static_cast<native_windows_error>(windows_error::error_graceful_disconnect):
            return windows_error::error_graceful_disconnect;
        

        case static_cast<native_windows_error>(windows_error::error_address_already_associated):
            return windows_error::error_address_already_associated;
        

        case static_cast<native_windows_error>(windows_error::error_address_not_associated):
            return windows_error::error_address_not_associated;
        

        case static_cast<native_windows_error>(windows_error::error_connection_invalid):
            return windows_error::error_connection_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_connection_active):
            return windows_error::error_connection_active;
        

        case static_cast<native_windows_error>(windows_error::error_network_unreachable):
            return windows_error::error_network_unreachable;
        

        case static_cast<native_windows_error>(windows_error::error_host_unreachable):
            return windows_error::error_host_unreachable;
        

        case static_cast<native_windows_error>(windows_error::error_protocol_unreachable):
            return windows_error::error_protocol_unreachable;
        

        case static_cast<native_windows_error>(windows_error::error_port_unreachable):
            return windows_error::error_port_unreachable;
        

        case static_cast<native_windows_error>(windows_error::error_request_aborted):
            return windows_error::error_request_aborted;
        

        case static_cast<native_windows_error>(windows_error::error_connection_aborted):
            return windows_error::error_connection_aborted;
        

        case static_cast<native_windows_error>(windows_error::error_retry):
            return windows_error::error_retry;
        

        case static_cast<native_windows_error>(windows_error::error_connection_count_limit):
            return windows_error::error_connection_count_limit;
        

        case static_cast<native_windows_error>(windows_error::error_login_time_restriction):
            return windows_error::error_login_time_restriction;
        

        case static_cast<native_windows_error>(windows_error::error_login_wksta_restriction):
            return windows_error::error_login_wksta_restriction;
        

        case static_cast<native_windows_error>(windows_error::error_incorrect_address):
            return windows_error::error_incorrect_address;
        

        case static_cast<native_windows_error>(windows_error::error_already_registered):
            return windows_error::error_already_registered;
        

        case static_cast<native_windows_error>(windows_error::error_service_not_found):
            return windows_error::error_service_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_not_authenticated):
            return windows_error::error_not_authenticated;
        

        case static_cast<native_windows_error>(windows_error::error_not_logged_on):
            return windows_error::error_not_logged_on;
        

        case static_cast<native_windows_error>(windows_error::error_continue):
            return windows_error::error_continue;
        

        case static_cast<native_windows_error>(windows_error::error_already_initialized):
            return windows_error::error_already_initialized;
        

        case static_cast<native_windows_error>(windows_error::error_no_more_devices):
            return windows_error::error_no_more_devices;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_site):
            return windows_error::error_no_such_site;
        

        case static_cast<native_windows_error>(windows_error::error_domain_controller_exists):
            return windows_error::error_domain_controller_exists;
        

        case static_cast<native_windows_error>(windows_error::error_only_if_connected):
            return windows_error::error_only_if_connected;
        

        case static_cast<native_windows_error>(windows_error::error_override_nochanges):
            return windows_error::error_override_nochanges;
        

        case static_cast<native_windows_error>(windows_error::error_bad_user_profile):
            return windows_error::error_bad_user_profile;
        

        case static_cast<native_windows_error>(windows_error::error_not_supported_on_sbs):
            return windows_error::error_not_supported_on_sbs;
        

        case static_cast<native_windows_error>(windows_error::error_server_shutdown_in_progress):
            return windows_error::error_server_shutdown_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_host_down):
            return windows_error::error_host_down;
        

        case static_cast<native_windows_error>(windows_error::error_non_account_sid):
            return windows_error::error_non_account_sid;
        

        case static_cast<native_windows_error>(windows_error::error_non_domain_sid):
            return windows_error::error_non_domain_sid;
        

        case static_cast<native_windows_error>(windows_error::error_apphelp_block):
            return windows_error::error_apphelp_block;
        

        case static_cast<native_windows_error>(windows_error::error_access_disabled_by_policy):
            return windows_error::error_access_disabled_by_policy;
        

        case static_cast<native_windows_error>(windows_error::error_reg_nat_consumption):
            return windows_error::error_reg_nat_consumption;
        

        case static_cast<native_windows_error>(windows_error::error_cscshare_offline):
            return windows_error::error_cscshare_offline;
        

        case static_cast<native_windows_error>(windows_error::error_pkinit_failure):
            return windows_error::error_pkinit_failure;
        

        case static_cast<native_windows_error>(windows_error::error_smartcard_subsystem_failure):
            return windows_error::error_smartcard_subsystem_failure;
        

        case static_cast<native_windows_error>(windows_error::error_downgrade_detected):
            return windows_error::error_downgrade_detected;
        
        

        case static_cast<native_windows_error>(windows_error::error_machine_locked):
            return windows_error::error_machine_locked;
        

        case static_cast<native_windows_error>(windows_error::error_smb_guest_logon_blocked):
            return windows_error::error_smb_guest_logon_blocked;
        

        case static_cast<native_windows_error>(windows_error::error_callback_supplied_invalid_data):
            return windows_error::error_callback_supplied_invalid_data;
        

        case static_cast<native_windows_error>(windows_error::error_sync_foreground_refresh_required):
            return windows_error::error_sync_foreground_refresh_required;
        

        case static_cast<native_windows_error>(windows_error::error_driver_blocked):
            return windows_error::error_driver_blocked;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_import_of_non_dll):
            return windows_error::error_invalid_import_of_non_dll;
        

        case static_cast<native_windows_error>(windows_error::error_access_disabled_webblade):
            return windows_error::error_access_disabled_webblade;
        

        case static_cast<native_windows_error>(windows_error::error_access_disabled_webblade_tamper):
            return windows_error::error_access_disabled_webblade_tamper;
        

        case static_cast<native_windows_error>(windows_error::error_recovery_failure):
            return windows_error::error_recovery_failure;
        

        case static_cast<native_windows_error>(windows_error::error_already_fiber):
            return windows_error::error_already_fiber;
        

        case static_cast<native_windows_error>(windows_error::error_already_thread):
            return windows_error::error_already_thread;
        

        case static_cast<native_windows_error>(windows_error::error_stack_buffer_overrun):
            return windows_error::error_stack_buffer_overrun;
        

        case static_cast<native_windows_error>(windows_error::error_parameter_quota_exceeded):
            return windows_error::error_parameter_quota_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_debugger_inactive):
            return windows_error::error_debugger_inactive;
        

        case static_cast<native_windows_error>(windows_error::error_delay_load_failed):
            return windows_error::error_delay_load_failed;
        

        case static_cast<native_windows_error>(windows_error::error_vdm_disallowed):
            return windows_error::error_vdm_disallowed;
        

        case static_cast<native_windows_error>(windows_error::error_unidentified_error):
            return windows_error::error_unidentified_error;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_cruntime_parameter):
            return windows_error::error_invalid_cruntime_parameter;
        

        case static_cast<native_windows_error>(windows_error::error_beyond_vdl):
            return windows_error::error_beyond_vdl;
        

        case static_cast<native_windows_error>(windows_error::error_incompatible_service_sid_type):
            return windows_error::error_incompatible_service_sid_type;
        

        case static_cast<native_windows_error>(windows_error::error_driver_process_terminated):
            return windows_error::error_driver_process_terminated;
        

        case static_cast<native_windows_error>(windows_error::error_implementation_limit):
            return windows_error::error_implementation_limit;
        
        case static_cast<native_windows_error>(windows_error::error_process_is_protected):
            return windows_error::error_process_is_protected;

        
        case static_cast<native_windows_error>(windows_error::error_service_notify_client_lagging):
            return windows_error::error_service_notify_client_lagging;

        
        
        
        
        case static_cast<native_windows_error>(windows_error::error_disk_quota_exceeded):
            return windows_error::error_disk_quota_exceeded;

        
        case static_cast<native_windows_error>(windows_error::error_content_blocked):
            return windows_error::error_content_blocked;

        
        
        
        
        case static_cast<native_windows_error>(windows_error::error_incompatible_service_privilege):
            return windows_error::error_incompatible_service_privilege;
        

        case static_cast<native_windows_error>(windows_error::error_app_hang):
            return windows_error::error_app_hang;
        
        case static_cast<native_windows_error>(windows_error::error_invalid_label):
            return windows_error::error_invalid_label;

        
        case static_cast<native_windows_error>(windows_error::error_not_all_assigned):
            return windows_error::error_not_all_assigned;

        
        case static_cast<native_windows_error>(windows_error::error_some_not_mapped):
            return windows_error::error_some_not_mapped;

        
        case static_cast<native_windows_error>(windows_error::error_no_quotas_for_account):
            return windows_error::error_no_quotas_for_account;

        
        case static_cast<native_windows_error>(windows_error::error_local_user_session_key):
            return windows_error::error_local_user_session_key;
        

        case static_cast<native_windows_error>(windows_error::error_null_lm_password):
            return windows_error::error_null_lm_password;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_revision):
            return windows_error::error_unknown_revision;
        

        case static_cast<native_windows_error>(windows_error::error_revision_mismatch):
            return windows_error::error_revision_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_owner):
            return windows_error::error_invalid_owner;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_primary_group):
            return windows_error::error_invalid_primary_group;
        

        case static_cast<native_windows_error>(windows_error::error_no_impersonation_token):
            return windows_error::error_no_impersonation_token;
        

        case static_cast<native_windows_error>(windows_error::error_cant_disable_mandatory):
            return windows_error::error_cant_disable_mandatory;
        

        case static_cast<native_windows_error>(windows_error::error_no_logon_servers):
            return windows_error::error_no_logon_servers;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_logon_session):
            return windows_error::error_no_such_logon_session;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_privilege):
            return windows_error::error_no_such_privilege;
        

        case static_cast<native_windows_error>(windows_error::error_privilege_not_held):
            return windows_error::error_privilege_not_held;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_account_name):
            return windows_error::error_invalid_account_name;
        

        case static_cast<native_windows_error>(windows_error::error_user_exists):
            return windows_error::error_user_exists;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_user):
            return windows_error::error_no_such_user;
        

        case static_cast<native_windows_error>(windows_error::error_group_exists):
            return windows_error::error_group_exists;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_group):
            return windows_error::error_no_such_group;
        

        case static_cast<native_windows_error>(windows_error::error_member_in_group):
            return windows_error::error_member_in_group;
        

        case static_cast<native_windows_error>(windows_error::error_member_not_in_group):
            return windows_error::error_member_not_in_group;
        

        case static_cast<native_windows_error>(windows_error::error_last_admin):
            return windows_error::error_last_admin;
        

        case static_cast<native_windows_error>(windows_error::error_wrong_password):
            return windows_error::error_wrong_password;
        

        case static_cast<native_windows_error>(windows_error::error_ill_formed_password):
            return windows_error::error_ill_formed_password;
        

        case static_cast<native_windows_error>(windows_error::error_password_restriction):
            return windows_error::error_password_restriction;
        

        case static_cast<native_windows_error>(windows_error::error_logon_failure):
            return windows_error::error_logon_failure;
        

        case static_cast<native_windows_error>(windows_error::error_account_restriction):
            return windows_error::error_account_restriction;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_logon_hours):
            return windows_error::error_invalid_logon_hours;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_workstation):
            return windows_error::error_invalid_workstation;
        

        case static_cast<native_windows_error>(windows_error::error_password_expired):
            return windows_error::error_password_expired;
        

        case static_cast<native_windows_error>(windows_error::error_account_disabled):
            return windows_error::error_account_disabled;
        

        case static_cast<native_windows_error>(windows_error::error_none_mapped):
            return windows_error::error_none_mapped;
        

        case static_cast<native_windows_error>(windows_error::error_too_many_luids_requested):
            return windows_error::error_too_many_luids_requested;
        

        case static_cast<native_windows_error>(windows_error::error_luids_exhausted):
            return windows_error::error_luids_exhausted;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_sub_authority):
            return windows_error::error_invalid_sub_authority;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_acl):
            return windows_error::error_invalid_acl;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_sid):
            return windows_error::error_invalid_sid;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_security_descr):
            return windows_error::error_invalid_security_descr;
        

        case static_cast<native_windows_error>(windows_error::error_bad_inheritance_acl):
            return windows_error::error_bad_inheritance_acl;
        

        case static_cast<native_windows_error>(windows_error::error_server_disabled):
            return windows_error::error_server_disabled;
        

        case static_cast<native_windows_error>(windows_error::error_server_not_disabled):
            return windows_error::error_server_not_disabled;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_id_authority):
            return windows_error::error_invalid_id_authority;
        

        case static_cast<native_windows_error>(windows_error::error_allotted_space_exceeded):
            return windows_error::error_allotted_space_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_group_attributes):
            return windows_error::error_invalid_group_attributes;
        

        case static_cast<native_windows_error>(windows_error::error_bad_impersonation_level):
            return windows_error::error_bad_impersonation_level;
        

        case static_cast<native_windows_error>(windows_error::error_cant_open_anonymous):
            return windows_error::error_cant_open_anonymous;
        

        case static_cast<native_windows_error>(windows_error::error_bad_validation_class):
            return windows_error::error_bad_validation_class;
        

        case static_cast<native_windows_error>(windows_error::error_bad_token_type):
            return windows_error::error_bad_token_type;
        

        case static_cast<native_windows_error>(windows_error::error_no_security_on_object):
            return windows_error::error_no_security_on_object;
        

        case static_cast<native_windows_error>(windows_error::error_cant_access_domain_info):
            return windows_error::error_cant_access_domain_info;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_server_state):
            return windows_error::error_invalid_server_state;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_domain_state):
            return windows_error::error_invalid_domain_state;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_domain_role):
            return windows_error::error_invalid_domain_role;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_domain):
            return windows_error::error_no_such_domain;
        

        case static_cast<native_windows_error>(windows_error::error_domain_exists):
            return windows_error::error_domain_exists;
        

        case static_cast<native_windows_error>(windows_error::error_domain_limit_exceeded):
            return windows_error::error_domain_limit_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_internal_db_corruption):
            return windows_error::error_internal_db_corruption;
        

        case static_cast<native_windows_error>(windows_error::error_internal_error):
            return windows_error::error_internal_error;
        

        case static_cast<native_windows_error>(windows_error::error_generic_not_mapped):
            return windows_error::error_generic_not_mapped;
        

        case static_cast<native_windows_error>(windows_error::error_bad_descriptor_format):
            return windows_error::error_bad_descriptor_format;
        

        case static_cast<native_windows_error>(windows_error::error_not_logon_process):
            return windows_error::error_not_logon_process;
        

        case static_cast<native_windows_error>(windows_error::error_logon_session_exists):
            return windows_error::error_logon_session_exists;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_package):
            return windows_error::error_no_such_package;
        

        case static_cast<native_windows_error>(windows_error::error_bad_logon_session_state):
            return windows_error::error_bad_logon_session_state;
        

        case static_cast<native_windows_error>(windows_error::error_logon_session_collision):
            return windows_error::error_logon_session_collision;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_logon_type):
            return windows_error::error_invalid_logon_type;
        

        case static_cast<native_windows_error>(windows_error::error_cannot_impersonate):
            return windows_error::error_cannot_impersonate;
        

        case static_cast<native_windows_error>(windows_error::error_rxact_invalid_state):
            return windows_error::error_rxact_invalid_state;
        

        case static_cast<native_windows_error>(windows_error::error_rxact_commit_failure):
            return windows_error::error_rxact_commit_failure;
        

        case static_cast<native_windows_error>(windows_error::error_special_account):
            return windows_error::error_special_account;
        

        case static_cast<native_windows_error>(windows_error::error_special_group):
            return windows_error::error_special_group;
        

        case static_cast<native_windows_error>(windows_error::error_special_user):
            return windows_error::error_special_user;
        

        case static_cast<native_windows_error>(windows_error::error_members_primary_group):
            return windows_error::error_members_primary_group;
        

        case static_cast<native_windows_error>(windows_error::error_token_already_in_use):
            return windows_error::error_token_already_in_use;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_alias):
            return windows_error::error_no_such_alias;
        

        case static_cast<native_windows_error>(windows_error::error_member_not_in_alias):
            return windows_error::error_member_not_in_alias;
        

        case static_cast<native_windows_error>(windows_error::error_member_in_alias):
            return windows_error::error_member_in_alias;
        

        case static_cast<native_windows_error>(windows_error::error_alias_exists):
            return windows_error::error_alias_exists;
        

        case static_cast<native_windows_error>(windows_error::error_logon_not_granted):
            return windows_error::error_logon_not_granted;
        

        case static_cast<native_windows_error>(windows_error::error_too_many_secrets):
            return windows_error::error_too_many_secrets;
        

        case static_cast<native_windows_error>(windows_error::error_secret_too_long):
            return windows_error::error_secret_too_long;
        

        case static_cast<native_windows_error>(windows_error::error_internal_db_error):
            return windows_error::error_internal_db_error;
        

        case static_cast<native_windows_error>(windows_error::error_too_many_context_ids):
            return windows_error::error_too_many_context_ids;
        

        case static_cast<native_windows_error>(windows_error::error_logon_type_not_granted):
            return windows_error::error_logon_type_not_granted;
        

        case static_cast<native_windows_error>(windows_error::error_nt_cross_encryption_required):
            return windows_error::error_nt_cross_encryption_required;
        

        case static_cast<native_windows_error>(windows_error::error_no_such_member):
            return windows_error::error_no_such_member;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_member):
            return windows_error::error_invalid_member;
        

        case static_cast<native_windows_error>(windows_error::error_too_many_sids):
            return windows_error::error_too_many_sids;
        

        case static_cast<native_windows_error>(windows_error::error_lm_cross_encryption_required):
            return windows_error::error_lm_cross_encryption_required;
        

        case static_cast<native_windows_error>(windows_error::error_no_inheritance):
            return windows_error::error_no_inheritance;
        

        case static_cast<native_windows_error>(windows_error::error_file_corrupt):
            return windows_error::error_file_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_disk_corrupt):
            return windows_error::error_disk_corrupt;
        
        case static_cast<native_windows_error>(windows_error::error_no_user_session_key):
            return windows_error::error_no_user_session_key;

        
        case static_cast<native_windows_error>(windows_error::error_license_quota_exceeded):
            return windows_error::error_license_quota_exceeded;

        
        case static_cast<native_windows_error>(windows_error::error_wrong_target_name):
            return windows_error::error_wrong_target_name;

        
        case static_cast<native_windows_error>(windows_error::error_mutual_auth_failed):
            return windows_error::error_mutual_auth_failed;

        
        case static_cast<native_windows_error>(windows_error::error_time_skew):
            return windows_error::error_time_skew;

        
        case static_cast<native_windows_error>(windows_error::error_current_domain_not_allowed):
            return windows_error::error_current_domain_not_allowed;

        
        case static_cast<native_windows_error>(windows_error::error_invalid_window_handle):
            return windows_error::error_invalid_window_handle;

        
        case static_cast<native_windows_error>(windows_error::error_invalid_menu_handle):
            return windows_error::error_invalid_menu_handle;

        
        case static_cast<native_windows_error>(windows_error::error_invalid_cursor_handle):
            return windows_error::error_invalid_cursor_handle;

        
        case static_cast<native_windows_error>(windows_error::error_invalid_accel_handle):
            return windows_error::error_invalid_accel_handle;

        
        case static_cast<native_windows_error>(windows_error::error_invalid_hook_handle):
            return windows_error::error_invalid_hook_handle;

        
        case static_cast<native_windows_error>(windows_error::error_invalid_dwp_handle):
            return windows_error::error_invalid_dwp_handle;

        
        case static_cast<native_windows_error>(windows_error::error_tlw_with_wschild):
            return windows_error::error_tlw_with_wschild;

        
        case static_cast<native_windows_error>(windows_error::error_cannot_find_wnd_class):
            return windows_error::error_cannot_find_wnd_class;

        
        case static_cast<native_windows_error>(windows_error::error_window_of_other_thread):
            return windows_error::error_window_of_other_thread;

        
        case static_cast<native_windows_error>(windows_error::error_hotkey_already_registered):
            return windows_error::error_hotkey_already_registered;

        
        case static_cast<native_windows_error>(windows_error::error_class_already_exists):
            return windows_error::error_class_already_exists;

        
        case static_cast<native_windows_error>(windows_error::error_class_does_not_exist):
            return windows_error::error_class_does_not_exist;
        

        case static_cast<native_windows_error>(windows_error::error_class_has_windows):
            return windows_error::error_class_has_windows;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_index):
            return windows_error::error_invalid_index;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_icon_handle):
            return windows_error::error_invalid_icon_handle;
        

        case static_cast<native_windows_error>(windows_error::error_private_dialog_index):
            return windows_error::error_private_dialog_index;
        

        case static_cast<native_windows_error>(windows_error::error_listbox_id_not_found):
            return windows_error::error_listbox_id_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_no_wildcard_characters):
            return windows_error::error_no_wildcard_characters;
        

        case static_cast<native_windows_error>(windows_error::error_clipboard_not_open):
            return windows_error::error_clipboard_not_open;
        

        case static_cast<native_windows_error>(windows_error::error_hotkey_not_registered):
            return windows_error::error_hotkey_not_registered;
        

        case static_cast<native_windows_error>(windows_error::error_window_not_dialog):
            return windows_error::error_window_not_dialog;
        

        case static_cast<native_windows_error>(windows_error::error_control_id_not_found):
            return windows_error::error_control_id_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_combobox_message):
            return windows_error::error_invalid_combobox_message;
        

        case static_cast<native_windows_error>(windows_error::error_window_not_combobox):
            return windows_error::error_window_not_combobox;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_edit_height):
            return windows_error::error_invalid_edit_height;
        

        case static_cast<native_windows_error>(windows_error::error_dc_not_found):
            return windows_error::error_dc_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_hook_filter):
            return windows_error::error_invalid_hook_filter;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_filter_proc):
            return windows_error::error_invalid_filter_proc;
        

        case static_cast<native_windows_error>(windows_error::error_hook_needs_hmod):
            return windows_error::error_hook_needs_hmod;
        

        case static_cast<native_windows_error>(windows_error::error_global_only_hook):
            return windows_error::error_global_only_hook;
        

        case static_cast<native_windows_error>(windows_error::error_journal_hook_set):
            return windows_error::error_journal_hook_set;
        

        case static_cast<native_windows_error>(windows_error::error_hook_not_installed):
            return windows_error::error_hook_not_installed;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_lb_message):
            return windows_error::error_invalid_lb_message;
        

        case static_cast<native_windows_error>(windows_error::error_setcount_on_bad_lb):
            return windows_error::error_setcount_on_bad_lb;
        

        case static_cast<native_windows_error>(windows_error::error_lb_without_tabstops):
            return windows_error::error_lb_without_tabstops;
        

        case static_cast<native_windows_error>(windows_error::error_destroy_object_of_other_thread):
            return windows_error::error_destroy_object_of_other_thread;
        

        case static_cast<native_windows_error>(windows_error::error_child_window_menu):
            return windows_error::error_child_window_menu;
        

        case static_cast<native_windows_error>(windows_error::error_no_system_menu):
            return windows_error::error_no_system_menu;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_msgbox_style):
            return windows_error::error_invalid_msgbox_style;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_spi_value):
            return windows_error::error_invalid_spi_value;
        

        case static_cast<native_windows_error>(windows_error::error_screen_already_locked):
            return windows_error::error_screen_already_locked;
        

        case static_cast<native_windows_error>(windows_error::error_hwnds_have_diff_parent):
            return windows_error::error_hwnds_have_diff_parent;
        

        case static_cast<native_windows_error>(windows_error::error_not_child_window):
            return windows_error::error_not_child_window;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_gw_command):
            return windows_error::error_invalid_gw_command;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_thread_id):
            return windows_error::error_invalid_thread_id;
        

        case static_cast<native_windows_error>(windows_error::error_non_mdichild_window):
            return windows_error::error_non_mdichild_window;
        

        case static_cast<native_windows_error>(windows_error::error_popup_already_active):
            return windows_error::error_popup_already_active;
        

        case static_cast<native_windows_error>(windows_error::error_no_scrollbars):
            return windows_error::error_no_scrollbars;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_scrollbar_range):
            return windows_error::error_invalid_scrollbar_range;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_showwin_command):
            return windows_error::error_invalid_showwin_command;
        

        case static_cast<native_windows_error>(windows_error::error_no_system_resources):
            return windows_error::error_no_system_resources;
        

        case static_cast<native_windows_error>(windows_error::error_nonpaged_system_resources):
            return windows_error::error_nonpaged_system_resources;
        

        case static_cast<native_windows_error>(windows_error::error_paged_system_resources):
            return windows_error::error_paged_system_resources;
        

        case static_cast<native_windows_error>(windows_error::error_working_set_quota):
            return windows_error::error_working_set_quota;
        

        case static_cast<native_windows_error>(windows_error::error_pagefile_quota):
            return windows_error::error_pagefile_quota;
        

        case static_cast<native_windows_error>(windows_error::error_commitment_limit):
            return windows_error::error_commitment_limit;
        

        case static_cast<native_windows_error>(windows_error::error_menu_item_not_found):
            return windows_error::error_menu_item_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_keyboard_handle):
            return windows_error::error_invalid_keyboard_handle;
        

        case static_cast<native_windows_error>(windows_error::error_hook_type_not_allowed):
            return windows_error::error_hook_type_not_allowed;
        

        case static_cast<native_windows_error>(windows_error::error_requires_interactive_windowstation):
            return windows_error::error_requires_interactive_windowstation;
        

        case static_cast<native_windows_error>(windows_error::error_timeout):
            return windows_error::error_timeout;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_monitor_handle):
            return windows_error::error_invalid_monitor_handle;
        

        case static_cast<native_windows_error>(windows_error::error_incorrect_size):
            return windows_error::error_incorrect_size;
        

        case static_cast<native_windows_error>(windows_error::error_symlink_class_disabled):
            return windows_error::error_symlink_class_disabled;
        

        case static_cast<native_windows_error>(windows_error::error_symlink_not_supported):
            return windows_error::error_symlink_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_xml_parse_error):
            return windows_error::error_xml_parse_error;
        

        case static_cast<native_windows_error>(windows_error::error_xmldsig_error):
            return windows_error::error_xmldsig_error;
        

        case static_cast<native_windows_error>(windows_error::error_restart_application):
            return windows_error::error_restart_application;
        

        case static_cast<native_windows_error>(windows_error::error_wrong_compartment):
            return windows_error::error_wrong_compartment;
        

        case static_cast<native_windows_error>(windows_error::error_authip_failure):
            return windows_error::error_authip_failure;
        

        case static_cast<native_windows_error>(windows_error::error_no_nvram_resources):
            return windows_error::error_no_nvram_resources;
        

        case static_cast<native_windows_error>(windows_error::error_not_gui_process):
            return windows_error::error_not_gui_process;
        

        case static_cast<native_windows_error>(windows_error::error_eventlog_file_corrupt):
            return windows_error::error_eventlog_file_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_eventlog_cant_start):
            return windows_error::error_eventlog_cant_start;
        

        case static_cast<native_windows_error>(windows_error::error_log_file_full):
            return windows_error::error_log_file_full;
        

        case static_cast<native_windows_error>(windows_error::error_eventlog_file_changed):
            return windows_error::error_eventlog_file_changed;
        

        case static_cast<native_windows_error>(windows_error::error_container_assigned):
            return windows_error::error_container_assigned;
        

        case static_cast<native_windows_error>(windows_error::error_job_no_container):
            return windows_error::error_job_no_container;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_task_name):
            return windows_error::error_invalid_task_name;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_task_index):
            return windows_error::error_invalid_task_index;
        

        case static_cast<native_windows_error>(windows_error::error_thread_already_in_task):
            return windows_error::error_thread_already_in_task;
        

        case static_cast<native_windows_error>(windows_error::error_install_service_failure):
            return windows_error::error_install_service_failure;
        

        case static_cast<native_windows_error>(windows_error::error_install_userexit):
            return windows_error::error_install_userexit;
        

        case static_cast<native_windows_error>(windows_error::error_install_failure):
            return windows_error::error_install_failure;
        

        case static_cast<native_windows_error>(windows_error::error_install_suspend):
            return windows_error::error_install_suspend;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_product):
            return windows_error::error_unknown_product;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_feature):
            return windows_error::error_unknown_feature;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_component):
            return windows_error::error_unknown_component;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_property):
            return windows_error::error_unknown_property;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_handle_state):
            return windows_error::error_invalid_handle_state;
        

        case static_cast<native_windows_error>(windows_error::error_bad_configuration):
            return windows_error::error_bad_configuration;
        

        case static_cast<native_windows_error>(windows_error::error_index_absent):
            return windows_error::error_index_absent;
        

        case static_cast<native_windows_error>(windows_error::error_install_source_absent):
            return windows_error::error_install_source_absent;
        

        case static_cast<native_windows_error>(windows_error::error_install_package_version):
            return windows_error::error_install_package_version;
        

        case static_cast<native_windows_error>(windows_error::error_product_uninstalled):
            return windows_error::error_product_uninstalled;
        

        case static_cast<native_windows_error>(windows_error::error_bad_query_syntax):
            return windows_error::error_bad_query_syntax;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_field):
            return windows_error::error_invalid_field;
        

        case static_cast<native_windows_error>(windows_error::error_device_removed):
            return windows_error::error_device_removed;
        

        case static_cast<native_windows_error>(windows_error::error_install_already_running):
            return windows_error::error_install_already_running;
        

        case static_cast<native_windows_error>(windows_error::error_install_package_open_failed):
            return windows_error::error_install_package_open_failed;
        

        case static_cast<native_windows_error>(windows_error::error_install_package_invalid):
            return windows_error::error_install_package_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_install_ui_failure):
            return windows_error::error_install_ui_failure;
        

        case static_cast<native_windows_error>(windows_error::error_install_log_failure):
            return windows_error::error_install_log_failure;
        

        case static_cast<native_windows_error>(windows_error::error_install_language_unsupported):
            return windows_error::error_install_language_unsupported;
        

        case static_cast<native_windows_error>(windows_error::error_install_transform_failure):
            return windows_error::error_install_transform_failure;
        

        case static_cast<native_windows_error>(windows_error::error_install_package_rejected):
            return windows_error::error_install_package_rejected;
        

        case static_cast<native_windows_error>(windows_error::error_function_not_called):
            return windows_error::error_function_not_called;
        

        case static_cast<native_windows_error>(windows_error::error_function_failed):
            return windows_error::error_function_failed;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_table):
            return windows_error::error_invalid_table;
        

        case static_cast<native_windows_error>(windows_error::error_datatype_mismatch):
            return windows_error::error_datatype_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_unsupported_type):
            return windows_error::error_unsupported_type;
        

        case static_cast<native_windows_error>(windows_error::error_create_failed):
            return windows_error::error_create_failed;
        

        case static_cast<native_windows_error>(windows_error::error_install_temp_unwritable):
            return windows_error::error_install_temp_unwritable;
        

        case static_cast<native_windows_error>(windows_error::error_install_platform_unsupported):
            return windows_error::error_install_platform_unsupported;
        

        case static_cast<native_windows_error>(windows_error::error_install_notused):
            return windows_error::error_install_notused;
        

        case static_cast<native_windows_error>(windows_error::error_patch_package_open_failed):
            return windows_error::error_patch_package_open_failed;
        

        case static_cast<native_windows_error>(windows_error::error_patch_package_invalid):
            return windows_error::error_patch_package_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_patch_package_unsupported):
            return windows_error::error_patch_package_unsupported;
        

        case static_cast<native_windows_error>(windows_error::error_product_version):
            return windows_error::error_product_version;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_command_line):
            return windows_error::error_invalid_command_line;
        

        case static_cast<native_windows_error>(windows_error::error_install_remote_disallowed):
            return windows_error::error_install_remote_disallowed;
        

        case static_cast<native_windows_error>(windows_error::error_success_reboot_initiated):
            return windows_error::error_success_reboot_initiated;
        

        case static_cast<native_windows_error>(windows_error::error_patch_target_not_found):
            return windows_error::error_patch_target_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_patch_package_rejected):
            return windows_error::error_patch_package_rejected;
        

        case static_cast<native_windows_error>(windows_error::error_install_transform_rejected):
            return windows_error::error_install_transform_rejected;
        

        case static_cast<native_windows_error>(windows_error::error_install_remote_prohibited):
            return windows_error::error_install_remote_prohibited;
        

        case static_cast<native_windows_error>(windows_error::error_patch_removal_unsupported):
            return windows_error::error_patch_removal_unsupported;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_patch):
            return windows_error::error_unknown_patch;
        

        case static_cast<native_windows_error>(windows_error::error_patch_no_sequence):
            return windows_error::error_patch_no_sequence;
        

        case static_cast<native_windows_error>(windows_error::error_patch_removal_disallowed):
            return windows_error::error_patch_removal_disallowed;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_patch_xml):
            return windows_error::error_invalid_patch_xml;
        

        case static_cast<native_windows_error>(windows_error::error_patch_managed_advertised_product):
            return windows_error::error_patch_managed_advertised_product;
        

        case static_cast<native_windows_error>(windows_error::error_install_service_safeboot):
            return windows_error::error_install_service_safeboot;
        

        case static_cast<native_windows_error>(windows_error::error_fail_fast_exception):
            return windows_error::error_fail_fast_exception;
        

        case static_cast<native_windows_error>(windows_error::error_install_rejected):
            return windows_error::error_install_rejected;
        

        case static_cast<native_windows_error>(windows_error::error_dynamic_code_blocked):
            return windows_error::error_dynamic_code_blocked;
        

        case static_cast<native_windows_error>(windows_error::error_not_same_object):
            return windows_error::error_not_same_object;
        

        case static_cast<native_windows_error>(windows_error::error_strict_cfg_violation):
            return windows_error::error_strict_cfg_violation;
        

        case static_cast<native_windows_error>(windows_error::error_set_context_denied):
            return windows_error::error_set_context_denied;
        

        case static_cast<native_windows_error>(windows_error::error_cross_partition_violation):
            return windows_error::error_cross_partition_violation;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_string_binding):
            return windows_error::rpc_s_invalid_string_binding;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_wrong_kind_of_binding):
            return windows_error::rpc_s_wrong_kind_of_binding;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_binding):
            return windows_error::rpc_s_invalid_binding;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_protseq_not_supported):
            return windows_error::rpc_s_protseq_not_supported;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_rpc_protseq):
            return windows_error::rpc_s_invalid_rpc_protseq;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_string_uuid):
            return windows_error::rpc_s_invalid_string_uuid;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_endpoint_format):
            return windows_error::rpc_s_invalid_endpoint_format;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_net_addr):
            return windows_error::rpc_s_invalid_net_addr;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_endpoint_found):
            return windows_error::rpc_s_no_endpoint_found;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_timeout):
            return windows_error::rpc_s_invalid_timeout;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_object_not_found):
            return windows_error::rpc_s_object_not_found;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_already_registered):
            return windows_error::rpc_s_already_registered;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_type_already_registered):
            return windows_error::rpc_s_type_already_registered;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_already_listening):
            return windows_error::rpc_s_already_listening;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_protseqs_registered):
            return windows_error::rpc_s_no_protseqs_registered;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_not_listening):
            return windows_error::rpc_s_not_listening;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unknown_mgr_type):
            return windows_error::rpc_s_unknown_mgr_type;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unknown_if):
            return windows_error::rpc_s_unknown_if;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_bindings):
            return windows_error::rpc_s_no_bindings;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_protseqs):
            return windows_error::rpc_s_no_protseqs;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_cant_create_endpoint):
            return windows_error::rpc_s_cant_create_endpoint;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_out_of_resources):
            return windows_error::rpc_s_out_of_resources;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_server_unavailable):
            return windows_error::rpc_s_server_unavailable;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_server_too_busy):
            return windows_error::rpc_s_server_too_busy;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_network_options):
            return windows_error::rpc_s_invalid_network_options;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_call_active):
            return windows_error::rpc_s_no_call_active;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_call_failed):
            return windows_error::rpc_s_call_failed;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_call_failed_dne):
            return windows_error::rpc_s_call_failed_dne;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_protocol_error):
            return windows_error::rpc_s_protocol_error;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_proxy_access_denied):
            return windows_error::rpc_s_proxy_access_denied;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unsupported_trans_syn):
            return windows_error::rpc_s_unsupported_trans_syn;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unsupported_type):
            return windows_error::rpc_s_unsupported_type;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_tag):
            return windows_error::rpc_s_invalid_tag;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_bound):
            return windows_error::rpc_s_invalid_bound;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_entry_name):
            return windows_error::rpc_s_no_entry_name;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_name_syntax):
            return windows_error::rpc_s_invalid_name_syntax;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unsupported_name_syntax):
            return windows_error::rpc_s_unsupported_name_syntax;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_uuid_no_address):
            return windows_error::rpc_s_uuid_no_address;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_duplicate_endpoint):
            return windows_error::rpc_s_duplicate_endpoint;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unknown_authn_type):
            return windows_error::rpc_s_unknown_authn_type;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_max_calls_too_small):
            return windows_error::rpc_s_max_calls_too_small;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_string_too_long):
            return windows_error::rpc_s_string_too_long;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_protseq_not_found):
            return windows_error::rpc_s_protseq_not_found;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_procnum_out_of_range):
            return windows_error::rpc_s_procnum_out_of_range;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_binding_has_no_auth):
            return windows_error::rpc_s_binding_has_no_auth;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unknown_authn_service):
            return windows_error::rpc_s_unknown_authn_service;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unknown_authn_level):
            return windows_error::rpc_s_unknown_authn_level;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_auth_identity):
            return windows_error::rpc_s_invalid_auth_identity;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unknown_authz_service):
            return windows_error::rpc_s_unknown_authz_service;
        

        case static_cast<native_windows_error>(windows_error::ept_s_invalid_entry):
            return windows_error::ept_s_invalid_entry;
        

        case static_cast<native_windows_error>(windows_error::ept_s_cant_perform_op):
            return windows_error::ept_s_cant_perform_op;
        

        case static_cast<native_windows_error>(windows_error::ept_s_not_registered):
            return windows_error::ept_s_not_registered;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_nothing_to_export):
            return windows_error::rpc_s_nothing_to_export;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_incomplete_name):
            return windows_error::rpc_s_incomplete_name;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_vers_option):
            return windows_error::rpc_s_invalid_vers_option;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_more_members):
            return windows_error::rpc_s_no_more_members;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_not_all_objs_unexported):
            return windows_error::rpc_s_not_all_objs_unexported;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_interface_not_found):
            return windows_error::rpc_s_interface_not_found;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_entry_already_exists):
            return windows_error::rpc_s_entry_already_exists;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_entry_not_found):
            return windows_error::rpc_s_entry_not_found;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_name_service_unavailable):
            return windows_error::rpc_s_name_service_unavailable;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_naf_id):
            return windows_error::rpc_s_invalid_naf_id;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_cannot_support):
            return windows_error::rpc_s_cannot_support;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_context_available):
            return windows_error::rpc_s_no_context_available;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_internal_error):
            return windows_error::rpc_s_internal_error;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_zero_divide):
            return windows_error::rpc_s_zero_divide;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_address_error):
            return windows_error::rpc_s_address_error;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_fp_div_zero):
            return windows_error::rpc_s_fp_div_zero;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_fp_underflow):
            return windows_error::rpc_s_fp_underflow;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_fp_overflow):
            return windows_error::rpc_s_fp_overflow;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_no_more_entries):
            return windows_error::rpc_x_no_more_entries;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_ss_char_trans_open_fail):
            return windows_error::rpc_x_ss_char_trans_open_fail;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_ss_char_trans_short_file):
            return windows_error::rpc_x_ss_char_trans_short_file;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_ss_in_null_context):
            return windows_error::rpc_x_ss_in_null_context;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_ss_context_damaged):
            return windows_error::rpc_x_ss_context_damaged;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_ss_handles_mismatch):
            return windows_error::rpc_x_ss_handles_mismatch;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_ss_cannot_get_call_handle):
            return windows_error::rpc_x_ss_cannot_get_call_handle;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_null_ref_pointer):
            return windows_error::rpc_x_null_ref_pointer;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_enum_value_out_of_range):
            return windows_error::rpc_x_enum_value_out_of_range;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_byte_count_too_small):
            return windows_error::rpc_x_byte_count_too_small;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_bad_stub_data):
            return windows_error::rpc_x_bad_stub_data;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_user_buffer):
            return windows_error::error_invalid_user_buffer;
        

        case static_cast<native_windows_error>(windows_error::error_unrecognized_media):
            return windows_error::error_unrecognized_media;
        

        case static_cast<native_windows_error>(windows_error::error_no_trust_lsa_secret):
            return windows_error::error_no_trust_lsa_secret;
        

        case static_cast<native_windows_error>(windows_error::error_no_trust_sam_account):
            return windows_error::error_no_trust_sam_account;
        

        case static_cast<native_windows_error>(windows_error::error_trusted_domain_failure):
            return windows_error::error_trusted_domain_failure;
        

        case static_cast<native_windows_error>(windows_error::error_trusted_relationship_failure):
            return windows_error::error_trusted_relationship_failure;
        

        case static_cast<native_windows_error>(windows_error::error_trust_failure):
            return windows_error::error_trust_failure;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_call_in_progress):
            return windows_error::rpc_s_call_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_netlogon_not_started):
            return windows_error::error_netlogon_not_started;
        

        case static_cast<native_windows_error>(windows_error::error_account_expired):
            return windows_error::error_account_expired;
        

        case static_cast<native_windows_error>(windows_error::error_redirector_has_open_handles):
            return windows_error::error_redirector_has_open_handles;
        

        case static_cast<native_windows_error>(windows_error::error_printer_driver_already_installed):
            return windows_error::error_printer_driver_already_installed;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_port):
            return windows_error::error_unknown_port;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_printer_driver):
            return windows_error::error_unknown_printer_driver;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_printprocessor):
            return windows_error::error_unknown_printprocessor;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_separator_file):
            return windows_error::error_invalid_separator_file;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_priority):
            return windows_error::error_invalid_priority;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_printer_name):
            return windows_error::error_invalid_printer_name;
        

        case static_cast<native_windows_error>(windows_error::error_printer_already_exists):
            return windows_error::error_printer_already_exists;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_printer_command):
            return windows_error::error_invalid_printer_command;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_datatype):
            return windows_error::error_invalid_datatype;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_environment):
            return windows_error::error_invalid_environment;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_more_bindings):
            return windows_error::rpc_s_no_more_bindings;
        

        case static_cast<native_windows_error>(windows_error::error_nologon_interdomain_trust_account):
            return windows_error::error_nologon_interdomain_trust_account;
        

        case static_cast<native_windows_error>(windows_error::error_nologon_workstation_trust_account):
            return windows_error::error_nologon_workstation_trust_account;
        

        case static_cast<native_windows_error>(windows_error::error_nologon_server_trust_account):
            return windows_error::error_nologon_server_trust_account;
        

        case static_cast<native_windows_error>(windows_error::error_domain_trust_inconsistent):
            return windows_error::error_domain_trust_inconsistent;
        

        case static_cast<native_windows_error>(windows_error::error_server_has_open_handles):
            return windows_error::error_server_has_open_handles;
        

        case static_cast<native_windows_error>(windows_error::error_resource_data_not_found):
            return windows_error::error_resource_data_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_resource_type_not_found):
            return windows_error::error_resource_type_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_resource_name_not_found):
            return windows_error::error_resource_name_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_resource_lang_not_found):
            return windows_error::error_resource_lang_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_not_enough_quota):
            return windows_error::error_not_enough_quota;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_interfaces):
            return windows_error::rpc_s_no_interfaces;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_call_cancelled):
            return windows_error::rpc_s_call_cancelled;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_binding_incomplete):
            return windows_error::rpc_s_binding_incomplete;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_comm_failure):
            return windows_error::rpc_s_comm_failure;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_unsupported_authn_level):
            return windows_error::rpc_s_unsupported_authn_level;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_no_princ_name):
            return windows_error::rpc_s_no_princ_name;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_not_rpc_error):
            return windows_error::rpc_s_not_rpc_error;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_uuid_local_only):
            return windows_error::rpc_s_uuid_local_only;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_sec_pkg_error):
            return windows_error::rpc_s_sec_pkg_error;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_not_cancelled):
            return windows_error::rpc_s_not_cancelled;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_invalid_es_action):
            return windows_error::rpc_x_invalid_es_action;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_wrong_es_version):
            return windows_error::rpc_x_wrong_es_version;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_wrong_stub_version):
            return windows_error::rpc_x_wrong_stub_version;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_invalid_pipe_object):
            return windows_error::rpc_x_invalid_pipe_object;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_wrong_pipe_order):
            return windows_error::rpc_x_wrong_pipe_order;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_wrong_pipe_version):
            return windows_error::rpc_x_wrong_pipe_version;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_cookie_auth_failed):
            return windows_error::rpc_s_cookie_auth_failed;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_do_not_disturb):
            return windows_error::rpc_s_do_not_disturb;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_system_handle_count_exceeded):
            return windows_error::rpc_s_system_handle_count_exceeded;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_system_handle_type_mismatch):
            return windows_error::rpc_s_system_handle_type_mismatch;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_group_member_not_found):
            return windows_error::rpc_s_group_member_not_found;
        

        case static_cast<native_windows_error>(windows_error::ept_s_cant_create):
            return windows_error::ept_s_cant_create;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_object):
            return windows_error::rpc_s_invalid_object;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_time):
            return windows_error::error_invalid_time;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_form_name):
            return windows_error::error_invalid_form_name;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_form_size):
            return windows_error::error_invalid_form_size;
        

        case static_cast<native_windows_error>(windows_error::error_already_waiting):
            return windows_error::error_already_waiting;
        

        case static_cast<native_windows_error>(windows_error::error_printer_deleted):
            return windows_error::error_printer_deleted;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_printer_state):
            return windows_error::error_invalid_printer_state;
        

        case static_cast<native_windows_error>(windows_error::error_password_must_change):
            return windows_error::error_password_must_change;
        

        case static_cast<native_windows_error>(windows_error::error_domain_controller_not_found):
            return windows_error::error_domain_controller_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_account_locked_out):
            return windows_error::error_account_locked_out;
        

        case static_cast<native_windows_error>(windows_error::or_invalid_oxid):
            return windows_error::or_invalid_oxid;
        

        case static_cast<native_windows_error>(windows_error::or_invalid_oid):
            return windows_error::or_invalid_oid;
        

        case static_cast<native_windows_error>(windows_error::or_invalid_set):
            return windows_error::or_invalid_set;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_send_incomplete):
            return windows_error::rpc_s_send_incomplete;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_async_handle):
            return windows_error::rpc_s_invalid_async_handle;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_invalid_async_call):
            return windows_error::rpc_s_invalid_async_call;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_pipe_closed):
            return windows_error::rpc_x_pipe_closed;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_pipe_discipline_error):
            return windows_error::rpc_x_pipe_discipline_error;
        

        case static_cast<native_windows_error>(windows_error::rpc_x_pipe_empty):
            return windows_error::rpc_x_pipe_empty;
        

        case static_cast<native_windows_error>(windows_error::error_no_sitename):
            return windows_error::error_no_sitename;
        

        case static_cast<native_windows_error>(windows_error::error_cant_access_file):
            return windows_error::error_cant_access_file;
        

        case static_cast<native_windows_error>(windows_error::error_cant_resolve_filename):
            return windows_error::error_cant_resolve_filename;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_entry_type_mismatch):
            return windows_error::rpc_s_entry_type_mismatch;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_not_all_objs_exported):
            return windows_error::rpc_s_not_all_objs_exported;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_interface_not_exported):
            return windows_error::rpc_s_interface_not_exported;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_profile_not_added):
            return windows_error::rpc_s_profile_not_added;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_prf_elt_not_added):
            return windows_error::rpc_s_prf_elt_not_added;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_prf_elt_not_removed):
            return windows_error::rpc_s_prf_elt_not_removed;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_grp_elt_not_added):
            return windows_error::rpc_s_grp_elt_not_added;
        

        case static_cast<native_windows_error>(windows_error::rpc_s_grp_elt_not_removed):
            return windows_error::rpc_s_grp_elt_not_removed;
        

        case static_cast<native_windows_error>(windows_error::error_km_driver_blocked):
            return windows_error::error_km_driver_blocked;
        

        case static_cast<native_windows_error>(windows_error::error_context_expired):
            return windows_error::error_context_expired;
        

        case static_cast<native_windows_error>(windows_error::error_per_user_trust_quota_exceeded):
            return windows_error::error_per_user_trust_quota_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_all_user_trust_quota_exceeded):
            return windows_error::error_all_user_trust_quota_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_user_delete_trust_quota_exceeded):
            return windows_error::error_user_delete_trust_quota_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_authentication_firewall_failed):
            return windows_error::error_authentication_firewall_failed;
        

        case static_cast<native_windows_error>(windows_error::error_remote_print_connections_blocked):
            return windows_error::error_remote_print_connections_blocked;
        

        case static_cast<native_windows_error>(windows_error::error_ntlm_blocked):
            return windows_error::error_ntlm_blocked;
        

        case static_cast<native_windows_error>(windows_error::error_password_change_required):
            return windows_error::error_password_change_required;
        

        case static_cast<native_windows_error>(windows_error::error_lost_mode_logon_restriction):
            return windows_error::error_lost_mode_logon_restriction;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_pixel_format):
            return windows_error::error_invalid_pixel_format;
        

        case static_cast<native_windows_error>(windows_error::error_bad_driver):
            return windows_error::error_bad_driver;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_window_style):
            return windows_error::error_invalid_window_style;
        

        case static_cast<native_windows_error>(windows_error::error_metafile_not_supported):
            return windows_error::error_metafile_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_transform_not_supported):
            return windows_error::error_transform_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_clipping_not_supported):
            return windows_error::error_clipping_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_cmm):
            return windows_error::error_invalid_cmm;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_profile):
            return windows_error::error_invalid_profile;
        

        case static_cast<native_windows_error>(windows_error::error_tag_not_found):
            return windows_error::error_tag_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_tag_not_present):
            return windows_error::error_tag_not_present;
        

        case static_cast<native_windows_error>(windows_error::error_duplicate_tag):
            return windows_error::error_duplicate_tag;
        

        case static_cast<native_windows_error>(windows_error::error_profile_not_associated_with_device):
            return windows_error::error_profile_not_associated_with_device;
        

        case static_cast<native_windows_error>(windows_error::error_profile_not_found):
            return windows_error::error_profile_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_colorspace):
            return windows_error::error_invalid_colorspace;
        

        case static_cast<native_windows_error>(windows_error::error_icm_not_enabled):
            return windows_error::error_icm_not_enabled;
        

        case static_cast<native_windows_error>(windows_error::error_deleting_icm_xform):
            return windows_error::error_deleting_icm_xform;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_transform):
            return windows_error::error_invalid_transform;
        

        case static_cast<native_windows_error>(windows_error::error_colorspace_mismatch):
            return windows_error::error_colorspace_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_colorindex):
            return windows_error::error_invalid_colorindex;
        

        case static_cast<native_windows_error>(windows_error::error_profile_does_not_match_device):
            return windows_error::error_profile_does_not_match_device;
        

        case static_cast<native_windows_error>(windows_error::error_connected_other_password):
            return windows_error::error_connected_other_password;
        

        case static_cast<native_windows_error>(windows_error::error_connected_other_password_default):
            return windows_error::error_connected_other_password_default;
        

        case static_cast<native_windows_error>(windows_error::error_bad_username):
            return windows_error::error_bad_username;
        

        case static_cast<native_windows_error>(windows_error::error_not_connected):
            return windows_error::error_not_connected;
        

        case static_cast<native_windows_error>(windows_error::error_open_files):
            return windows_error::error_open_files;
        

        case static_cast<native_windows_error>(windows_error::error_active_connections):
            return windows_error::error_active_connections;
        

        case static_cast<native_windows_error>(windows_error::error_device_in_use):
            return windows_error::error_device_in_use;
        

        case static_cast<native_windows_error>(windows_error::error_unknown_print_monitor):
            return windows_error::error_unknown_print_monitor;
        

        case static_cast<native_windows_error>(windows_error::error_printer_driver_in_use):
            return windows_error::error_printer_driver_in_use;
        

        case static_cast<native_windows_error>(windows_error::error_spool_file_not_found):
            return windows_error::error_spool_file_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_spl_no_startdoc):
            return windows_error::error_spl_no_startdoc;
        

        case static_cast<native_windows_error>(windows_error::error_spl_no_addjob):
            return windows_error::error_spl_no_addjob;
        

        case static_cast<native_windows_error>(windows_error::error_print_processor_already_installed):
            return windows_error::error_print_processor_already_installed;
        

        case static_cast<native_windows_error>(windows_error::error_print_monitor_already_installed):
            return windows_error::error_print_monitor_already_installed;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_print_monitor):
            return windows_error::error_invalid_print_monitor;
        

        case static_cast<native_windows_error>(windows_error::error_print_monitor_in_use):
            return windows_error::error_print_monitor_in_use;
        

        case static_cast<native_windows_error>(windows_error::error_printer_has_jobs_queued):
            return windows_error::error_printer_has_jobs_queued;
        

        case static_cast<native_windows_error>(windows_error::error_success_reboot_required):
            return windows_error::error_success_reboot_required;
        

        case static_cast<native_windows_error>(windows_error::error_success_restart_required):
            return windows_error::error_success_restart_required;
        

        case static_cast<native_windows_error>(windows_error::error_printer_not_found):
            return windows_error::error_printer_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_printer_driver_warned):
            return windows_error::error_printer_driver_warned;
        

        case static_cast<native_windows_error>(windows_error::error_printer_driver_blocked):
            return windows_error::error_printer_driver_blocked;
        

        case static_cast<native_windows_error>(windows_error::error_printer_driver_package_in_use):
            return windows_error::error_printer_driver_package_in_use;
        

        case static_cast<native_windows_error>(windows_error::error_core_driver_package_not_found):
            return windows_error::error_core_driver_package_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_fail_reboot_required):
            return windows_error::error_fail_reboot_required;
        

        case static_cast<native_windows_error>(windows_error::error_fail_reboot_initiated):
            return windows_error::error_fail_reboot_initiated;
        

        case static_cast<native_windows_error>(windows_error::error_printer_driver_download_needed):
            return windows_error::error_printer_driver_download_needed;
        

        case static_cast<native_windows_error>(windows_error::error_print_job_restart_required):
            return windows_error::error_print_job_restart_required;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_printer_driver_manifest):
            return windows_error::error_invalid_printer_driver_manifest;
        

        case static_cast<native_windows_error>(windows_error::error_printer_not_shareable):
            return windows_error::error_printer_not_shareable;
        

        case static_cast<native_windows_error>(windows_error::error_request_paused):
            return windows_error::error_request_paused;
        

        case static_cast<native_windows_error>(windows_error::error_appexec_condition_not_satisfied):
            return windows_error::error_appexec_condition_not_satisfied;
        

        case static_cast<native_windows_error>(windows_error::error_appexec_handle_invalidated):
            return windows_error::error_appexec_handle_invalidated;
        

        case static_cast<native_windows_error>(windows_error::error_appexec_invalid_host_generation):
            return windows_error::error_appexec_invalid_host_generation;
        

        case static_cast<native_windows_error>(windows_error::error_appexec_unexpected_process_registration):
            return windows_error::error_appexec_unexpected_process_registration;
        

        case static_cast<native_windows_error>(windows_error::error_appexec_invalid_host_state):
            return windows_error::error_appexec_invalid_host_state;
        

        case static_cast<native_windows_error>(windows_error::error_appexec_no_donor):
            return windows_error::error_appexec_no_donor;
        

        case static_cast<native_windows_error>(windows_error::error_appexec_host_id_mismatch):
            return windows_error::error_appexec_host_id_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_appexec_unknown_user):
            return windows_error::error_appexec_unknown_user;

        

        case static_cast<native_windows_error>(windows_error::error_io_reissue_as_cached):
            return windows_error::error_io_reissue_as_cached;

        

        case static_cast<native_windows_error>(windows_error::error_wins_internal):
            return windows_error::error_wins_internal;
        

        case static_cast<native_windows_error>(windows_error::error_can_not_del_local_wins):
            return windows_error::error_can_not_del_local_wins;
        

        case static_cast<native_windows_error>(windows_error::error_static_init):
            return windows_error::error_static_init;
        

        case static_cast<native_windows_error>(windows_error::error_inc_backup):
            return windows_error::error_inc_backup;
        

        case static_cast<native_windows_error>(windows_error::error_full_backup):
            return windows_error::error_full_backup;
        

        case static_cast<native_windows_error>(windows_error::error_rec_non_existent):
            return windows_error::error_rec_non_existent;
        

        case static_cast<native_windows_error>(windows_error::error_rpl_not_allowed):
            return windows_error::error_rpl_not_allowed;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_contentinfo_version_unsupported):
            return windows_error::peerdist_error_contentinfo_version_unsupported;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_cannot_parse_contentinfo):
            return windows_error::peerdist_error_cannot_parse_contentinfo;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_missing_data):
            return windows_error::peerdist_error_missing_data;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_no_more):
            return windows_error::peerdist_error_no_more;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_not_initialized):
            return windows_error::peerdist_error_not_initialized;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_already_initialized):
            return windows_error::peerdist_error_already_initialized;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_shutdown_in_progress):
            return windows_error::peerdist_error_shutdown_in_progress;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_invalidated):
            return windows_error::peerdist_error_invalidated;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_already_exists):
            return windows_error::peerdist_error_already_exists;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_operation_notfound):
            return windows_error::peerdist_error_operation_notfound;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_already_completed):
            return windows_error::peerdist_error_already_completed;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_out_of_bounds):
            return windows_error::peerdist_error_out_of_bounds;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_version_unsupported):
            return windows_error::peerdist_error_version_unsupported;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_invalid_configuration):
            return windows_error::peerdist_error_invalid_configuration;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_not_licensed):
            return windows_error::peerdist_error_not_licensed;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_service_unavailable):
            return windows_error::peerdist_error_service_unavailable;
        

        case static_cast<native_windows_error>(windows_error::peerdist_error_trust_failure):
            return windows_error::peerdist_error_trust_failure;
        

        case static_cast<native_windows_error>(windows_error::error_dhcp_address_conflict):
            return windows_error::error_dhcp_address_conflict;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_guid_not_found):
            return windows_error::error_wmi_guid_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_instance_not_found):
            return windows_error::error_wmi_instance_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_itemid_not_found):
            return windows_error::error_wmi_itemid_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_try_again):
            return windows_error::error_wmi_try_again;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_dp_not_found):
            return windows_error::error_wmi_dp_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_unresolved_instance_ref):
            return windows_error::error_wmi_unresolved_instance_ref;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_already_enabled):
            return windows_error::error_wmi_already_enabled;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_guid_disconnected):
            return windows_error::error_wmi_guid_disconnected;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_server_unavailable):
            return windows_error::error_wmi_server_unavailable;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_dp_failed):
            return windows_error::error_wmi_dp_failed;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_invalid_mof):
            return windows_error::error_wmi_invalid_mof;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_invalid_reginfo):
            return windows_error::error_wmi_invalid_reginfo;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_already_disabled):
            return windows_error::error_wmi_already_disabled;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_read_only):
            return windows_error::error_wmi_read_only;
        

        case static_cast<native_windows_error>(windows_error::error_wmi_set_failure):
            return windows_error::error_wmi_set_failure;
        

        case static_cast<native_windows_error>(windows_error::error_not_appcontainer):
            return windows_error::error_not_appcontainer;
        

        case static_cast<native_windows_error>(windows_error::error_appcontainer_required):
            return windows_error::error_appcontainer_required;
        

        case static_cast<native_windows_error>(windows_error::error_not_supported_in_appcontainer):
            return windows_error::error_not_supported_in_appcontainer;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_package_sid_length):
            return windows_error::error_invalid_package_sid_length;

        

        case static_cast<native_windows_error>(windows_error::error_invalid_media):
            return windows_error::error_invalid_media;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_library):
            return windows_error::error_invalid_library;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_media_pool):
            return windows_error::error_invalid_media_pool;
        

        case static_cast<native_windows_error>(windows_error::error_drive_media_mismatch):
            return windows_error::error_drive_media_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_media_offline):
            return windows_error::error_media_offline;
        

        case static_cast<native_windows_error>(windows_error::error_library_offline):
            return windows_error::error_library_offline;
        

        case static_cast<native_windows_error>(windows_error::error_empty):
            return windows_error::error_empty;
        

        case static_cast<native_windows_error>(windows_error::error_not_empty):
            return windows_error::error_not_empty;
        

        case static_cast<native_windows_error>(windows_error::error_media_unavailable):
            return windows_error::error_media_unavailable;
        

        case static_cast<native_windows_error>(windows_error::error_resource_disabled):
            return windows_error::error_resource_disabled;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_cleaner):
            return windows_error::error_invalid_cleaner;
        

        case static_cast<native_windows_error>(windows_error::error_unable_to_clean):
            return windows_error::error_unable_to_clean;
        

        case static_cast<native_windows_error>(windows_error::error_object_not_found):
            return windows_error::error_object_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_database_failure):
            return windows_error::error_database_failure;
        

        case static_cast<native_windows_error>(windows_error::error_database_full):
            return windows_error::error_database_full;
        

        case static_cast<native_windows_error>(windows_error::error_media_incompatible):
            return windows_error::error_media_incompatible;
        

        case static_cast<native_windows_error>(windows_error::error_resource_not_present):
            return windows_error::error_resource_not_present;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_operation):
            return windows_error::error_invalid_operation;
        

        case static_cast<native_windows_error>(windows_error::error_media_not_available):
            return windows_error::error_media_not_available;
        

        case static_cast<native_windows_error>(windows_error::error_device_not_available):
            return windows_error::error_device_not_available;
        

        case static_cast<native_windows_error>(windows_error::error_request_refused):
            return windows_error::error_request_refused;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_drive_object):
            return windows_error::error_invalid_drive_object;
        

        case static_cast<native_windows_error>(windows_error::error_library_full):
            return windows_error::error_library_full;
        

        case static_cast<native_windows_error>(windows_error::error_medium_not_accessible):
            return windows_error::error_medium_not_accessible;
        

        case static_cast<native_windows_error>(windows_error::error_unable_to_load_medium):
            return windows_error::error_unable_to_load_medium;
        

        case static_cast<native_windows_error>(windows_error::error_unable_to_inventory_drive):
            return windows_error::error_unable_to_inventory_drive;
        

        case static_cast<native_windows_error>(windows_error::error_unable_to_inventory_slot):
            return windows_error::error_unable_to_inventory_slot;
        

        case static_cast<native_windows_error>(windows_error::error_unable_to_inventory_transport):
            return windows_error::error_unable_to_inventory_transport;
        

        case static_cast<native_windows_error>(windows_error::error_transport_full):
            return windows_error::error_transport_full;
        

        case static_cast<native_windows_error>(windows_error::error_controlling_ieport):
            return windows_error::error_controlling_ieport;
        

        case static_cast<native_windows_error>(windows_error::error_unable_to_eject_mounted_media):
            return windows_error::error_unable_to_eject_mounted_media;
        

        case static_cast<native_windows_error>(windows_error::error_cleaner_slot_set):
            return windows_error::error_cleaner_slot_set;
        

        case static_cast<native_windows_error>(windows_error::error_cleaner_slot_not_set):
            return windows_error::error_cleaner_slot_not_set;
        

        case static_cast<native_windows_error>(windows_error::error_cleaner_cartridge_spent):
            return windows_error::error_cleaner_cartridge_spent;
        

        case static_cast<native_windows_error>(windows_error::error_unexpected_omid):
            return windows_error::error_unexpected_omid;
        

        case static_cast<native_windows_error>(windows_error::error_cant_delete_last_item):
            return windows_error::error_cant_delete_last_item;
        

        case static_cast<native_windows_error>(windows_error::error_message_exceeds_max_size):
            return windows_error::error_message_exceeds_max_size;
        

        case static_cast<native_windows_error>(windows_error::error_volume_contains_sys_files):
            return windows_error::error_volume_contains_sys_files;
        

        case static_cast<native_windows_error>(windows_error::error_indigenous_type):
            return windows_error::error_indigenous_type;
        

        case static_cast<native_windows_error>(windows_error::error_no_supporting_drives):
            return windows_error::error_no_supporting_drives;
        

        case static_cast<native_windows_error>(windows_error::error_cleaner_cartridge_installed):
            return windows_error::error_cleaner_cartridge_installed;
        

        case static_cast<native_windows_error>(windows_error::error_ieport_full):
            return windows_error::error_ieport_full;
        

        case static_cast<native_windows_error>(windows_error::error_file_offline):
            return windows_error::error_file_offline;
        

        case static_cast<native_windows_error>(windows_error::error_remote_storage_not_active):
            return windows_error::error_remote_storage_not_active;
        

        case static_cast<native_windows_error>(windows_error::error_remote_storage_media_error):
            return windows_error::error_remote_storage_media_error;
        

        case static_cast<native_windows_error>(windows_error::error_not_a_reparse_point):
            return windows_error::error_not_a_reparse_point;
        

        case static_cast<native_windows_error>(windows_error::error_reparse_attribute_conflict):
            return windows_error::error_reparse_attribute_conflict;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_reparse_data):
            return windows_error::error_invalid_reparse_data;
        

        case static_cast<native_windows_error>(windows_error::error_reparse_tag_invalid):
            return windows_error::error_reparse_tag_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_reparse_tag_mismatch):
            return windows_error::error_reparse_tag_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_reparse_point_encountered):
            return windows_error::error_reparse_point_encountered;
        

        case static_cast<native_windows_error>(windows_error::error_app_data_not_found):
            return windows_error::error_app_data_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_app_data_expired):
            return windows_error::error_app_data_expired;
        

        case static_cast<native_windows_error>(windows_error::error_app_data_corrupt):
            return windows_error::error_app_data_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_app_data_limit_exceeded):
            return windows_error::error_app_data_limit_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_app_data_reboot_required):
            return windows_error::error_app_data_reboot_required;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_rollback_detected):
            return windows_error::error_secureboot_rollback_detected;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_policy_violation):
            return windows_error::error_secureboot_policy_violation;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_invalid_policy):
            return windows_error::error_secureboot_invalid_policy;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_policy_publisher_not_found):
            return windows_error::error_secureboot_policy_publisher_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_policy_not_signed):
            return windows_error::error_secureboot_policy_not_signed;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_not_enabled):
            return windows_error::error_secureboot_not_enabled;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_file_replaced):
            return windows_error::error_secureboot_file_replaced;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_policy_not_authorized):
            return windows_error::error_secureboot_policy_not_authorized;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_policy_unknown):
            return windows_error::error_secureboot_policy_unknown;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_policy_missing_antirollbackversion):
            return windows_error::error_secureboot_policy_missing_antirollbackversion;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_platform_id_mismatch):
            return windows_error::error_secureboot_platform_id_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_policy_rollback_detected):
            return windows_error::error_secureboot_policy_rollback_detected;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_policy_upgrade_mismatch):
            return windows_error::error_secureboot_policy_upgrade_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_required_policy_file_missing):
            return windows_error::error_secureboot_required_policy_file_missing;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_not_base_policy):
            return windows_error::error_secureboot_not_base_policy;
        

        case static_cast<native_windows_error>(windows_error::error_secureboot_not_supplemental_policy):
            return windows_error::error_secureboot_not_supplemental_policy;
        

        case static_cast<native_windows_error>(windows_error::error_offload_read_flt_not_supported):
            return windows_error::error_offload_read_flt_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_offload_write_flt_not_supported):
            return windows_error::error_offload_write_flt_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_offload_read_file_not_supported):
            return windows_error::error_offload_read_file_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_offload_write_file_not_supported):
            return windows_error::error_offload_write_file_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_already_has_stream_id):
            return windows_error::error_already_has_stream_id;
        

        case static_cast<native_windows_error>(windows_error::error_smr_garbage_collection_required):
            return windows_error::error_smr_garbage_collection_required;
        

        case static_cast<native_windows_error>(windows_error::error_wof_wim_header_corrupt):
            return windows_error::error_wof_wim_header_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_wof_wim_resource_table_corrupt):
            return windows_error::error_wof_wim_resource_table_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_wof_file_resource_table_corrupt):
            return windows_error::error_wof_file_resource_table_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_volume_not_sis_enabled):
            return windows_error::error_volume_not_sis_enabled;
        

        case static_cast<native_windows_error>(windows_error::error_system_integrity_rollback_detected):
            return windows_error::error_system_integrity_rollback_detected;
        

        case static_cast<native_windows_error>(windows_error::error_system_integrity_policy_violation):
            return windows_error::error_system_integrity_policy_violation;
        

        case static_cast<native_windows_error>(windows_error::error_system_integrity_invalid_policy):
            return windows_error::error_system_integrity_invalid_policy;
        

        case static_cast<native_windows_error>(windows_error::error_system_integrity_policy_not_signed):
            return windows_error::error_system_integrity_policy_not_signed;
        

        case static_cast<native_windows_error>(windows_error::error_system_integrity_too_many_policies):
            return windows_error::error_system_integrity_too_many_policies;
        

        case static_cast<native_windows_error>(windows_error::error_system_integrity_supplemental_policy_not_authorized):
            return windows_error::error_system_integrity_supplemental_policy_not_authorized;
        

        case static_cast<native_windows_error>(windows_error::error_vsm_not_initialized):
            return windows_error::error_vsm_not_initialized;
        

        case static_cast<native_windows_error>(windows_error::error_vsm_dma_protection_not_in_use):
            return windows_error::error_vsm_dma_protection_not_in_use;

        

        case static_cast<native_windows_error>(windows_error::error_platform_manifest_not_authorized):
            return windows_error::error_platform_manifest_not_authorized;
        

        case static_cast<native_windows_error>(windows_error::error_platform_manifest_invalid):
            return windows_error::error_platform_manifest_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_platform_manifest_file_not_authorized):
            return windows_error::error_platform_manifest_file_not_authorized;
        

        case static_cast<native_windows_error>(windows_error::error_platform_manifest_catalog_not_authorized):
            return windows_error::error_platform_manifest_catalog_not_authorized;
        

        case static_cast<native_windows_error>(windows_error::error_platform_manifest_binary_id_not_found):
            return windows_error::error_platform_manifest_binary_id_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_platform_manifest_not_active):
            return windows_error::error_platform_manifest_not_active;
        

        case static_cast<native_windows_error>(windows_error::error_platform_manifest_not_signed):
            return windows_error::error_platform_manifest_not_signed;
        

        case static_cast<native_windows_error>(windows_error::error_dependent_resource_exists):
            return windows_error::error_dependent_resource_exists;
        

        case static_cast<native_windows_error>(windows_error::error_dependency_not_found):
            return windows_error::error_dependency_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_dependency_already_exists):
            return windows_error::error_dependency_already_exists;
        

        case static_cast<native_windows_error>(windows_error::error_resource_not_online):
            return windows_error::error_resource_not_online;
        

        case static_cast<native_windows_error>(windows_error::error_host_node_not_available):
            return windows_error::error_host_node_not_available;
        

        case static_cast<native_windows_error>(windows_error::error_resource_not_available):
            return windows_error::error_resource_not_available;
        

        case static_cast<native_windows_error>(windows_error::error_resource_not_found):
            return windows_error::error_resource_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_shutdown_cluster):
            return windows_error::error_shutdown_cluster;
        

        case static_cast<native_windows_error>(windows_error::error_cant_evict_active_node):
            return windows_error::error_cant_evict_active_node;
        

        case static_cast<native_windows_error>(windows_error::error_object_already_exists):
            return windows_error::error_object_already_exists;
        

        case static_cast<native_windows_error>(windows_error::error_object_in_list):
            return windows_error::error_object_in_list;
        

        case static_cast<native_windows_error>(windows_error::error_group_not_available):
            return windows_error::error_group_not_available;
        

        case static_cast<native_windows_error>(windows_error::error_group_not_found):
            return windows_error::error_group_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_group_not_online):
            return windows_error::error_group_not_online;
        

        case static_cast<native_windows_error>(windows_error::error_host_node_not_resource_owner):
            return windows_error::error_host_node_not_resource_owner;
        

        case static_cast<native_windows_error>(windows_error::error_host_node_not_group_owner):
            return windows_error::error_host_node_not_group_owner;
        

        case static_cast<native_windows_error>(windows_error::error_resmon_create_failed):
            return windows_error::error_resmon_create_failed;
        

        case static_cast<native_windows_error>(windows_error::error_resmon_online_failed):
            return windows_error::error_resmon_online_failed;
        

        case static_cast<native_windows_error>(windows_error::error_resource_online):
            return windows_error::error_resource_online;
        

        case static_cast<native_windows_error>(windows_error::error_quorum_resource):
            return windows_error::error_quorum_resource;
        

        case static_cast<native_windows_error>(windows_error::error_not_quorum_capable):
            return windows_error::error_not_quorum_capable;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_shutting_down):
            return windows_error::error_cluster_shutting_down;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_state):
            return windows_error::error_invalid_state;
        

        case static_cast<native_windows_error>(windows_error::error_resource_properties_stored):
            return windows_error::error_resource_properties_stored;
        

        case static_cast<native_windows_error>(windows_error::error_not_quorum_class):
            return windows_error::error_not_quorum_class;
        

        case static_cast<native_windows_error>(windows_error::error_core_resource):
            return windows_error::error_core_resource;
        

        case static_cast<native_windows_error>(windows_error::error_quorum_resource_online_failed):
            return windows_error::error_quorum_resource_online_failed;
        

        case static_cast<native_windows_error>(windows_error::error_quorumlog_open_failed):
            return windows_error::error_quorumlog_open_failed;
        

        case static_cast<native_windows_error>(windows_error::error_clusterlog_corrupt):
            return windows_error::error_clusterlog_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_clusterlog_record_exceeds_maxsize):
            return windows_error::error_clusterlog_record_exceeds_maxsize;
        

        case static_cast<native_windows_error>(windows_error::error_clusterlog_exceeds_maxsize):
            return windows_error::error_clusterlog_exceeds_maxsize;
        

        case static_cast<native_windows_error>(windows_error::error_clusterlog_chkpoint_not_found):
            return windows_error::error_clusterlog_chkpoint_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_clusterlog_not_enough_space):
            return windows_error::error_clusterlog_not_enough_space;
        

        case static_cast<native_windows_error>(windows_error::error_quorum_owner_alive):
            return windows_error::error_quorum_owner_alive;
        

        case static_cast<native_windows_error>(windows_error::error_network_not_available):
            return windows_error::error_network_not_available;
        

        case static_cast<native_windows_error>(windows_error::error_node_not_available):
            return windows_error::error_node_not_available;
        

        case static_cast<native_windows_error>(windows_error::error_all_nodes_not_available):
            return windows_error::error_all_nodes_not_available;
        

        case static_cast<native_windows_error>(windows_error::error_resource_failed):
            return windows_error::error_resource_failed;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_node):
            return windows_error::error_cluster_invalid_node;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_exists):
            return windows_error::error_cluster_node_exists;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_join_in_progress):
            return windows_error::error_cluster_join_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_not_found):
            return windows_error::error_cluster_node_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_local_node_not_found):
            return windows_error::error_cluster_local_node_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_network_exists):
            return windows_error::error_cluster_network_exists;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_network_not_found):
            return windows_error::error_cluster_network_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_netinterface_exists):
            return windows_error::error_cluster_netinterface_exists;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_netinterface_not_found):
            return windows_error::error_cluster_netinterface_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_request):
            return windows_error::error_cluster_invalid_request;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_network_provider):
            return windows_error::error_cluster_invalid_network_provider;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_down):
            return windows_error::error_cluster_node_down;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_unreachable):
            return windows_error::error_cluster_node_unreachable;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_not_member):
            return windows_error::error_cluster_node_not_member;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_join_not_in_progress):
            return windows_error::error_cluster_join_not_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_network):
            return windows_error::error_cluster_invalid_network;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_up):
            return windows_error::error_cluster_node_up;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_ipaddr_in_use):
            return windows_error::error_cluster_ipaddr_in_use;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_not_paused):
            return windows_error::error_cluster_node_not_paused;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_no_security_context):
            return windows_error::error_cluster_no_security_context;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_network_not_internal):
            return windows_error::error_cluster_network_not_internal;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_already_up):
            return windows_error::error_cluster_node_already_up;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_already_down):
            return windows_error::error_cluster_node_already_down;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_network_already_online):
            return windows_error::error_cluster_network_already_online;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_network_already_offline):
            return windows_error::error_cluster_network_already_offline;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_already_member):
            return windows_error::error_cluster_node_already_member;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_last_internal_network):
            return windows_error::error_cluster_last_internal_network;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_network_has_dependents):
            return windows_error::error_cluster_network_has_dependents;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_operation_on_quorum):
            return windows_error::error_invalid_operation_on_quorum;
        

        case static_cast<native_windows_error>(windows_error::error_dependency_not_allowed):
            return windows_error::error_dependency_not_allowed;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_paused):
            return windows_error::error_cluster_node_paused;
        

        case static_cast<native_windows_error>(windows_error::error_node_cant_host_resource):
            return windows_error::error_node_cant_host_resource;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_not_ready):
            return windows_error::error_cluster_node_not_ready;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_shutting_down):
            return windows_error::error_cluster_node_shutting_down;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_join_aborted):
            return windows_error::error_cluster_join_aborted;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_incompatible_versions):
            return windows_error::error_cluster_incompatible_versions;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_maxnum_of_resources_exceeded):
            return windows_error::error_cluster_maxnum_of_resources_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_system_config_changed):
            return windows_error::error_cluster_system_config_changed;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_type_not_found):
            return windows_error::error_cluster_resource_type_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_restype_not_supported):
            return windows_error::error_cluster_restype_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resname_not_found):
            return windows_error::error_cluster_resname_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_no_rpc_packages_registered):
            return windows_error::error_cluster_no_rpc_packages_registered;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_owner_not_in_preflist):
            return windows_error::error_cluster_owner_not_in_preflist;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_database_seqmismatch):
            return windows_error::error_cluster_database_seqmismatch;
        

        case static_cast<native_windows_error>(windows_error::error_resmon_invalid_state):
            return windows_error::error_resmon_invalid_state;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_gum_not_locker):
            return windows_error::error_cluster_gum_not_locker;
        

        case static_cast<native_windows_error>(windows_error::error_quorum_disk_not_found):
            return windows_error::error_quorum_disk_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_database_backup_corrupt):
            return windows_error::error_database_backup_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_already_has_dfs_root):
            return windows_error::error_cluster_node_already_has_dfs_root;
        

        case static_cast<native_windows_error>(windows_error::error_resource_property_unchangeable):
            return windows_error::error_resource_property_unchangeable;
        

        case static_cast<native_windows_error>(windows_error::error_no_admin_access_point):
            return windows_error::error_no_admin_access_point;

        /*
         Codes from 4300 through 5889 overlap with codes in ds\published\inc\apperr2.w.
         Do not add any more error codes in that range.
        */

        

        case static_cast<native_windows_error>(windows_error::error_cluster_membership_invalid_state):
            return windows_error::error_cluster_membership_invalid_state;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_quorumlog_not_found):
            return windows_error::error_cluster_quorumlog_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_membership_halt):
            return windows_error::error_cluster_membership_halt;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_instance_id_mismatch):
            return windows_error::error_cluster_instance_id_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_network_not_found_for_ip):
            return windows_error::error_cluster_network_not_found_for_ip;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_property_data_type_mismatch):
            return windows_error::error_cluster_property_data_type_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_evict_without_cleanup):
            return windows_error::error_cluster_evict_without_cleanup;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_parameter_mismatch):
            return windows_error::error_cluster_parameter_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_node_cannot_be_clustered):
            return windows_error::error_node_cannot_be_clustered;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_wrong_os_version):
            return windows_error::error_cluster_wrong_os_version;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_cant_create_dup_cluster_name):
            return windows_error::error_cluster_cant_create_dup_cluster_name;
        

        case static_cast<native_windows_error>(windows_error::error_cluscfg_already_committed):
            return windows_error::error_cluscfg_already_committed;
        

        case static_cast<native_windows_error>(windows_error::error_cluscfg_rollback_failed):
            return windows_error::error_cluscfg_rollback_failed;
        

        case static_cast<native_windows_error>(windows_error::error_cluscfg_system_disk_drive_letter_conflict):
            return windows_error::error_cluscfg_system_disk_drive_letter_conflict;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_old_version):
            return windows_error::error_cluster_old_version;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_mismatched_computer_acct_name):
            return windows_error::error_cluster_mismatched_computer_acct_name;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_no_net_adapters):
            return windows_error::error_cluster_no_net_adapters;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_poisoned):
            return windows_error::error_cluster_poisoned;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_group_moving):
            return windows_error::error_cluster_group_moving;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_type_busy):
            return windows_error::error_cluster_resource_type_busy;
        

        case static_cast<native_windows_error>(windows_error::error_resource_call_timed_out):
            return windows_error::error_resource_call_timed_out;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_cluster_ipv6_address):
            return windows_error::error_invalid_cluster_ipv6_address;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_internal_invalid_function):
            return windows_error::error_cluster_internal_invalid_function;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_parameter_out_of_bounds):
            return windows_error::error_cluster_parameter_out_of_bounds;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_partial_send):
            return windows_error::error_cluster_partial_send;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_registry_invalid_function):
            return windows_error::error_cluster_registry_invalid_function;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_string_termination):
            return windows_error::error_cluster_invalid_string_termination;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_string_format):
            return windows_error::error_cluster_invalid_string_format;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_database_transaction_in_progress):
            return windows_error::error_cluster_database_transaction_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_database_transaction_not_in_progress):
            return windows_error::error_cluster_database_transaction_not_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_null_data):
            return windows_error::error_cluster_null_data;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_partial_read):
            return windows_error::error_cluster_partial_read;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_partial_write):
            return windows_error::error_cluster_partial_write;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_cant_deserialize_data):
            return windows_error::error_cluster_cant_deserialize_data;
        

        case static_cast<native_windows_error>(windows_error::error_dependent_resource_property_conflict):
            return windows_error::error_dependent_resource_property_conflict;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_no_quorum):
            return windows_error::error_cluster_no_quorum;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_ipv6_network):
            return windows_error::error_cluster_invalid_ipv6_network;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_ipv6_tunnel_network):
            return windows_error::error_cluster_invalid_ipv6_tunnel_network;
        

        case static_cast<native_windows_error>(windows_error::error_quorum_not_allowed_in_this_group):
            return windows_error::error_quorum_not_allowed_in_this_group;
        

        case static_cast<native_windows_error>(windows_error::error_dependency_tree_too_complex):
            return windows_error::error_dependency_tree_too_complex;
        

        case static_cast<native_windows_error>(windows_error::error_exception_in_resource_call):
            return windows_error::error_exception_in_resource_call;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_rhs_failed_initialization):
            return windows_error::error_cluster_rhs_failed_initialization;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_not_installed):
            return windows_error::error_cluster_not_installed;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resources_must_be_online_on_the_same_node):
            return windows_error::error_cluster_resources_must_be_online_on_the_same_node;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_max_nodes_in_cluster):
            return windows_error::error_cluster_max_nodes_in_cluster;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_too_many_nodes):
            return windows_error::error_cluster_too_many_nodes;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_object_already_used):
            return windows_error::error_cluster_object_already_used;
        

        case static_cast<native_windows_error>(windows_error::error_noncore_groups_found):
            return windows_error::error_noncore_groups_found;
        

        case static_cast<native_windows_error>(windows_error::error_file_share_resource_conflict):
            return windows_error::error_file_share_resource_conflict;
        
        

        case static_cast<native_windows_error>(windows_error::error_cluster_evict_invalid_request):
            return windows_error::error_cluster_evict_invalid_request;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_singleton_resource):
            return windows_error::error_cluster_singleton_resource;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_group_singleton_resource):
            return windows_error::error_cluster_group_singleton_resource;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_provider_failed):
            return windows_error::error_cluster_resource_provider_failed;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_configuration_error):
            return windows_error::error_cluster_resource_configuration_error;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_group_busy):
            return windows_error::error_cluster_group_busy;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_not_shared_volume):
            return windows_error::error_cluster_not_shared_volume;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_security_descriptor):
            return windows_error::error_cluster_invalid_security_descriptor;
        
        

        case static_cast<native_windows_error>(windows_error::error_cluster_shared_volumes_in_use):
            return windows_error::error_cluster_shared_volumes_in_use;
        
        

        case static_cast<native_windows_error>(windows_error::error_cluster_use_shared_volumes_api):
            return windows_error::error_cluster_use_shared_volumes_api;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_backup_in_progress):
            return windows_error::error_cluster_backup_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_non_csv_path):
            return windows_error::error_non_csv_path;
        

        case static_cast<native_windows_error>(windows_error::error_csv_volume_not_local):
            return windows_error::error_csv_volume_not_local;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_watchdog_terminating):
            return windows_error::error_cluster_watchdog_terminating;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_vetoed_move_incompatible_nodes):
            return windows_error::error_cluster_resource_vetoed_move_incompatible_nodes;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_node_weight):
            return windows_error::error_cluster_invalid_node_weight;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_vetoed_call):
            return windows_error::error_cluster_resource_vetoed_call;
        

        case static_cast<native_windows_error>(windows_error::error_resmon_system_resources_lacking):
            return windows_error::error_resmon_system_resources_lacking;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_vetoed_move_not_enough_resources_on_destination):
            return windows_error::error_cluster_resource_vetoed_move_not_enough_resources_on_destination;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_vetoed_move_not_enough_resources_on_source):
            return windows_error::error_cluster_resource_vetoed_move_not_enough_resources_on_source;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_group_queued):
            return windows_error::error_cluster_group_queued;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_locked_status):
            return windows_error::error_cluster_resource_locked_status;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_shared_volume_failover_not_allowed):
            return windows_error::error_cluster_shared_volume_failover_not_allowed;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_drain_in_progress):
            return windows_error::error_cluster_node_drain_in_progress;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_disk_not_connected):
            return windows_error::error_cluster_disk_not_connected;

        

        case static_cast<native_windows_error>(windows_error::error_disk_not_csv_capable):
            return windows_error::error_disk_not_csv_capable;

        

        case static_cast<native_windows_error>(windows_error::error_resource_not_in_available_storage):
            return windows_error::error_resource_not_in_available_storage;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_shared_volume_redirected):
            return windows_error::error_cluster_shared_volume_redirected;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_shared_volume_not_redirected):
            return windows_error::error_cluster_shared_volume_not_redirected;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_cannot_return_properties):
            return windows_error::error_cluster_cannot_return_properties;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_contains_unsupported_diff_area_for_shared_volumes):
            return windows_error::error_cluster_resource_contains_unsupported_diff_area_for_shared_volumes;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_is_in_maintenance_mode):
            return windows_error::error_cluster_resource_is_in_maintenance_mode;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_affinity_conflict):
            return windows_error::error_cluster_affinity_conflict;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_is_replica_virtual_machine):
            return windows_error::error_cluster_resource_is_replica_virtual_machine;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_upgrade_incompatible_versions):
            return windows_error::error_cluster_upgrade_incompatible_versions;

        
        
        
        
        
        
        case static_cast<native_windows_error>(windows_error::error_cluster_upgrade_fix_quorum_not_supported):
            return windows_error::error_cluster_upgrade_fix_quorum_not_supported;

        
        
        
        
        
        case static_cast<native_windows_error>(windows_error::error_cluster_upgrade_restart_required):
            return windows_error::error_cluster_upgrade_restart_required;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_upgrade_in_progress):
            return windows_error::error_cluster_upgrade_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_upgrade_incomplete):
            return windows_error::error_cluster_upgrade_incomplete;
        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_in_grace_period):
            return windows_error::error_cluster_node_in_grace_period;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_csv_io_pause_timeout):
            return windows_error::error_cluster_csv_io_pause_timeout;

        

        case static_cast<native_windows_error>(windows_error::error_node_not_active_cluster_member):
            return windows_error::error_node_not_active_cluster_member;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_not_monitored):
            return windows_error::error_cluster_resource_not_monitored;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_does_not_support_unmonitored):
            return windows_error::error_cluster_resource_does_not_support_unmonitored;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_resource_is_replicated):
            return windows_error::error_cluster_resource_is_replicated;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_isolated):
            return windows_error::error_cluster_node_isolated;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_node_quarantined):
            return windows_error::error_cluster_node_quarantined;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_database_update_condition_failed):
            return windows_error::error_cluster_database_update_condition_failed;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_space_degraded):
            return windows_error::error_cluster_space_degraded;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_token_delegation_not_supported):
            return windows_error::error_cluster_token_delegation_not_supported;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_csv_invalid_handle):
            return windows_error::error_cluster_csv_invalid_handle;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_csv_supported_only_on_coordinator):
            return windows_error::error_cluster_csv_supported_only_on_coordinator;

        

        case static_cast<native_windows_error>(windows_error::error_groupset_not_available):
            return windows_error::error_groupset_not_available;

        

        case static_cast<native_windows_error>(windows_error::error_groupset_not_found):
            return windows_error::error_groupset_not_found;

        

        case static_cast<native_windows_error>(windows_error::error_groupset_cant_provide):
            return windows_error::error_groupset_cant_provide;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_fault_domain_parent_not_found):
            return windows_error::error_cluster_fault_domain_parent_not_found;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_fault_domain_invalid_hierarchy):
            return windows_error::error_cluster_fault_domain_invalid_hierarchy;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_fault_domain_failed_s2d_validation):
            return windows_error::error_cluster_fault_domain_failed_s2d_validation;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_fault_domain_s2d_connectivity_loss):
            return windows_error::error_cluster_fault_domain_s2d_connectivity_loss;

        

        case static_cast<native_windows_error>(windows_error::error_cluster_invalid_infrastructure_fileserver_name):
            return windows_error::error_cluster_invalid_infrastructure_fileserver_name;

        

        case static_cast<native_windows_error>(windows_error::error_clusterset_management_cluster_unreachable):
            return windows_error::error_clusterset_management_cluster_unreachable;

        

        case static_cast<native_windows_error>(windows_error::error_encryption_failed):
            return windows_error::error_encryption_failed;
        

        case static_cast<native_windows_error>(windows_error::error_decryption_failed):
            return windows_error::error_decryption_failed;
        

        case static_cast<native_windows_error>(windows_error::error_file_encrypted):
            return windows_error::error_file_encrypted;
        

        case static_cast<native_windows_error>(windows_error::error_no_recovery_policy):
            return windows_error::error_no_recovery_policy;
        

        case static_cast<native_windows_error>(windows_error::error_no_efs):
            return windows_error::error_no_efs;
        

        case static_cast<native_windows_error>(windows_error::error_wrong_efs):
            return windows_error::error_wrong_efs;
        

        case static_cast<native_windows_error>(windows_error::error_no_user_keys):
            return windows_error::error_no_user_keys;
        

        case static_cast<native_windows_error>(windows_error::error_file_not_encrypted):
            return windows_error::error_file_not_encrypted;
        

        case static_cast<native_windows_error>(windows_error::error_not_export_format):
            return windows_error::error_not_export_format;
        

        case static_cast<native_windows_error>(windows_error::error_file_read_only):
            return windows_error::error_file_read_only;
        

        case static_cast<native_windows_error>(windows_error::error_dir_efs_disallowed):
            return windows_error::error_dir_efs_disallowed;
        

        case static_cast<native_windows_error>(windows_error::error_efs_server_not_trusted):
            return windows_error::error_efs_server_not_trusted;
        

        case static_cast<native_windows_error>(windows_error::error_bad_recovery_policy):
            return windows_error::error_bad_recovery_policy;
        

        case static_cast<native_windows_error>(windows_error::error_efs_alg_blob_too_big):
            return windows_error::error_efs_alg_blob_too_big;
        

        case static_cast<native_windows_error>(windows_error::error_volume_not_support_efs):
            return windows_error::error_volume_not_support_efs;
        

        case static_cast<native_windows_error>(windows_error::error_efs_disabled):
            return windows_error::error_efs_disabled;
        

        case static_cast<native_windows_error>(windows_error::error_efs_version_not_support):
            return windows_error::error_efs_version_not_support;
        

        case static_cast<native_windows_error>(windows_error::error_cs_encryption_invalid_server_response):
            return windows_error::error_cs_encryption_invalid_server_response;
        

        case static_cast<native_windows_error>(windows_error::error_cs_encryption_unsupported_server):
            return windows_error::error_cs_encryption_unsupported_server;
        

        case static_cast<native_windows_error>(windows_error::error_cs_encryption_existing_encrypted_file):
            return windows_error::error_cs_encryption_existing_encrypted_file;
        

        case static_cast<native_windows_error>(windows_error::error_cs_encryption_new_encrypted_file):
            return windows_error::error_cs_encryption_new_encrypted_file;
        

        case static_cast<native_windows_error>(windows_error::error_cs_encryption_file_not_cse):
            return windows_error::error_cs_encryption_file_not_cse;
        

        case static_cast<native_windows_error>(windows_error::error_encryption_policy_denies_operation):
            return windows_error::error_encryption_policy_denies_operation;
        

        case static_cast<native_windows_error>(windows_error::error_wip_encryption_failed):
            return windows_error::error_wip_encryption_failed;
        

        case static_cast<native_windows_error>(windows_error::error_no_browser_servers_found):
            return windows_error::error_no_browser_servers_found;

        

        case static_cast<native_windows_error>(windows_error::sched_e_service_not_localsystem):
            return windows_error::sched_e_service_not_localsystem;
        

        case static_cast<native_windows_error>(windows_error::error_log_sector_invalid):
            return windows_error::error_log_sector_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_sector_parity_invalid):
            return windows_error::error_log_sector_parity_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_sector_remapped):
            return windows_error::error_log_sector_remapped;
        

        case static_cast<native_windows_error>(windows_error::error_log_block_incomplete):
            return windows_error::error_log_block_incomplete;
        

        case static_cast<native_windows_error>(windows_error::error_log_invalid_range):
            return windows_error::error_log_invalid_range;
        

        case static_cast<native_windows_error>(windows_error::error_log_blocks_exhausted):
            return windows_error::error_log_blocks_exhausted;
        

        case static_cast<native_windows_error>(windows_error::error_log_read_context_invalid):
            return windows_error::error_log_read_context_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_restart_invalid):
            return windows_error::error_log_restart_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_block_version):
            return windows_error::error_log_block_version;
        

        case static_cast<native_windows_error>(windows_error::error_log_block_invalid):
            return windows_error::error_log_block_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_read_mode_invalid):
            return windows_error::error_log_read_mode_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_no_restart):
            return windows_error::error_log_no_restart;
        

        case static_cast<native_windows_error>(windows_error::error_log_metadata_corrupt):
            return windows_error::error_log_metadata_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_log_metadata_invalid):
            return windows_error::error_log_metadata_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_metadata_inconsistent):
            return windows_error::error_log_metadata_inconsistent;
        

        case static_cast<native_windows_error>(windows_error::error_log_reservation_invalid):
            return windows_error::error_log_reservation_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_cant_delete):
            return windows_error::error_log_cant_delete;
        

        case static_cast<native_windows_error>(windows_error::error_log_container_limit_exceeded):
            return windows_error::error_log_container_limit_exceeded;
        

        case static_cast<native_windows_error>(windows_error::error_log_start_of_log):
            return windows_error::error_log_start_of_log;
        

        case static_cast<native_windows_error>(windows_error::error_log_policy_already_installed):
            return windows_error::error_log_policy_already_installed;
        

        case static_cast<native_windows_error>(windows_error::error_log_policy_not_installed):
            return windows_error::error_log_policy_not_installed;
        

        case static_cast<native_windows_error>(windows_error::error_log_policy_invalid):
            return windows_error::error_log_policy_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_policy_conflict):
            return windows_error::error_log_policy_conflict;
        

        case static_cast<native_windows_error>(windows_error::error_log_pinned_archive_tail):
            return windows_error::error_log_pinned_archive_tail;
        

        case static_cast<native_windows_error>(windows_error::error_log_record_nonexistent):
            return windows_error::error_log_record_nonexistent;
        

        case static_cast<native_windows_error>(windows_error::error_log_records_reserved_invalid):
            return windows_error::error_log_records_reserved_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_space_reserved_invalid):
            return windows_error::error_log_space_reserved_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_tail_invalid):
            return windows_error::error_log_tail_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_full):
            return windows_error::error_log_full;
        

        case static_cast<native_windows_error>(windows_error::error_could_not_resize_log):
            return windows_error::error_could_not_resize_log;
        

        case static_cast<native_windows_error>(windows_error::error_log_multiplexed):
            return windows_error::error_log_multiplexed;
        

        case static_cast<native_windows_error>(windows_error::error_log_dedicated):
            return windows_error::error_log_dedicated;
        

        case static_cast<native_windows_error>(windows_error::error_log_archive_not_in_progress):
            return windows_error::error_log_archive_not_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_log_archive_in_progress):
            return windows_error::error_log_archive_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_log_ephemeral):
            return windows_error::error_log_ephemeral;
        

        case static_cast<native_windows_error>(windows_error::error_log_not_enough_containers):
            return windows_error::error_log_not_enough_containers;
        

        case static_cast<native_windows_error>(windows_error::error_log_client_already_registered):
            return windows_error::error_log_client_already_registered;
        

        case static_cast<native_windows_error>(windows_error::error_log_client_not_registered):
            return windows_error::error_log_client_not_registered;
        

        case static_cast<native_windows_error>(windows_error::error_log_full_handler_in_progress):
            return windows_error::error_log_full_handler_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_log_container_read_failed):
            return windows_error::error_log_container_read_failed;
        

        case static_cast<native_windows_error>(windows_error::error_log_container_write_failed):
            return windows_error::error_log_container_write_failed;
        

        case static_cast<native_windows_error>(windows_error::error_log_container_open_failed):
            return windows_error::error_log_container_open_failed;
        

        case static_cast<native_windows_error>(windows_error::error_log_container_state_invalid):
            return windows_error::error_log_container_state_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_state_invalid):
            return windows_error::error_log_state_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_log_pinned):
            return windows_error::error_log_pinned;
        

        case static_cast<native_windows_error>(windows_error::error_log_metadata_flush_failed):
            return windows_error::error_log_metadata_flush_failed;
        

        case static_cast<native_windows_error>(windows_error::error_log_inconsistent_security):
            return windows_error::error_log_inconsistent_security;
        

        case static_cast<native_windows_error>(windows_error::error_log_appended_flush_failed):
            return windows_error::error_log_appended_flush_failed;
        

        case static_cast<native_windows_error>(windows_error::error_log_pinned_reservation):
            return windows_error::error_log_pinned_reservation;
        

        case static_cast<native_windows_error>(windows_error::error_invalid_transaction):
            return windows_error::error_invalid_transaction;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_not_active):
            return windows_error::error_transaction_not_active;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_request_not_valid):
            return windows_error::error_transaction_request_not_valid;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_not_requested):
            return windows_error::error_transaction_not_requested;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_already_aborted):
            return windows_error::error_transaction_already_aborted;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_already_committed):
            return windows_error::error_transaction_already_committed;
        

        case static_cast<native_windows_error>(windows_error::error_tm_initialization_failed):
            return windows_error::error_tm_initialization_failed;
        

        case static_cast<native_windows_error>(windows_error::error_resourcemanager_read_only):
            return windows_error::error_resourcemanager_read_only;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_not_joined):
            return windows_error::error_transaction_not_joined;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_superior_exists):
            return windows_error::error_transaction_superior_exists;
        

        case static_cast<native_windows_error>(windows_error::error_crm_protocol_already_exists):
            return windows_error::error_crm_protocol_already_exists;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_propagation_failed):
            return windows_error::error_transaction_propagation_failed;
        

        case static_cast<native_windows_error>(windows_error::error_crm_protocol_not_found):
            return windows_error::error_crm_protocol_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_invalid_marshall_buffer):
            return windows_error::error_transaction_invalid_marshall_buffer;
        

        case static_cast<native_windows_error>(windows_error::error_current_transaction_not_valid):
            return windows_error::error_current_transaction_not_valid;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_not_found):
            return windows_error::error_transaction_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_resourcemanager_not_found):
            return windows_error::error_resourcemanager_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_enlistment_not_found):
            return windows_error::error_enlistment_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_transactionmanager_not_found):
            return windows_error::error_transactionmanager_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_transactionmanager_not_online):
            return windows_error::error_transactionmanager_not_online;
        

        case static_cast<native_windows_error>(windows_error::error_transactionmanager_recovery_name_collision):
            return windows_error::error_transactionmanager_recovery_name_collision;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_not_root):
            return windows_error::error_transaction_not_root;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_object_expired):
            return windows_error::error_transaction_object_expired;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_response_not_enlisted):
            return windows_error::error_transaction_response_not_enlisted;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_record_too_long):
            return windows_error::error_transaction_record_too_long;
        

        case static_cast<native_windows_error>(windows_error::error_implicit_transaction_not_supported):
            return windows_error::error_implicit_transaction_not_supported;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_integrity_violated):
            return windows_error::error_transaction_integrity_violated;
        

        case static_cast<native_windows_error>(windows_error::error_transactionmanager_identity_mismatch):
            return windows_error::error_transactionmanager_identity_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_rm_cannot_be_frozen_for_snapshot):
            return windows_error::error_rm_cannot_be_frozen_for_snapshot;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_must_writethrough):
            return windows_error::error_transaction_must_writethrough;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_no_superior):
            return windows_error::error_transaction_no_superior;
        

        case static_cast<native_windows_error>(windows_error::error_heuristic_damage_possible):
            return windows_error::error_heuristic_damage_possible;
        

        case static_cast<native_windows_error>(windows_error::error_transactional_conflict):
            return windows_error::error_transactional_conflict;
        

        case static_cast<native_windows_error>(windows_error::error_rm_not_active):
            return windows_error::error_rm_not_active;
        

        case static_cast<native_windows_error>(windows_error::error_rm_metadata_corrupt):
            return windows_error::error_rm_metadata_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_directory_not_rm):
            return windows_error::error_directory_not_rm;
        

        case static_cast<native_windows_error>(windows_error::error_transactions_unsupported_remote):
            return windows_error::error_transactions_unsupported_remote;
        

        case static_cast<native_windows_error>(windows_error::error_log_resize_invalid_size):
            return windows_error::error_log_resize_invalid_size;
        

        case static_cast<native_windows_error>(windows_error::error_object_no_longer_exists):
            return windows_error::error_object_no_longer_exists;
        

        case static_cast<native_windows_error>(windows_error::error_stream_miniversion_not_found):
            return windows_error::error_stream_miniversion_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_stream_miniversion_not_valid):
            return windows_error::error_stream_miniversion_not_valid;
        

        case static_cast<native_windows_error>(windows_error::error_miniversion_inaccessible_from_specified_transaction):
            return windows_error::error_miniversion_inaccessible_from_specified_transaction;
        

        case static_cast<native_windows_error>(windows_error::error_cant_open_miniversion_with_modify_intent):
            return windows_error::error_cant_open_miniversion_with_modify_intent;
        

        case static_cast<native_windows_error>(windows_error::error_cant_create_more_stream_miniversions):
            return windows_error::error_cant_create_more_stream_miniversions;
        

        case static_cast<native_windows_error>(windows_error::error_remote_file_version_mismatch):
            return windows_error::error_remote_file_version_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_handle_no_longer_valid):
            return windows_error::error_handle_no_longer_valid;
        

        case static_cast<native_windows_error>(windows_error::error_no_txf_metadata):
            return windows_error::error_no_txf_metadata;
        

        case static_cast<native_windows_error>(windows_error::error_log_corruption_detected):
            return windows_error::error_log_corruption_detected;
        

        case static_cast<native_windows_error>(windows_error::error_cant_recover_with_handle_open):
            return windows_error::error_cant_recover_with_handle_open;
        

        case static_cast<native_windows_error>(windows_error::error_rm_disconnected):
            return windows_error::error_rm_disconnected;
        

        case static_cast<native_windows_error>(windows_error::error_enlistment_not_superior):
            return windows_error::error_enlistment_not_superior;
        

        case static_cast<native_windows_error>(windows_error::error_recovery_not_needed):
            return windows_error::error_recovery_not_needed;
        

        case static_cast<native_windows_error>(windows_error::error_rm_already_started):
            return windows_error::error_rm_already_started;
        

        case static_cast<native_windows_error>(windows_error::error_file_identity_not_persistent):
            return windows_error::error_file_identity_not_persistent;
        

        case static_cast<native_windows_error>(windows_error::error_cant_break_transactional_dependency):
            return windows_error::error_cant_break_transactional_dependency;
        

        case static_cast<native_windows_error>(windows_error::error_cant_cross_rm_boundary):
            return windows_error::error_cant_cross_rm_boundary;
        

        case static_cast<native_windows_error>(windows_error::error_txf_dir_not_empty):
            return windows_error::error_txf_dir_not_empty;
        

        case static_cast<native_windows_error>(windows_error::error_indoubt_transactions_exist):
            return windows_error::error_indoubt_transactions_exist;
        

        case static_cast<native_windows_error>(windows_error::error_tm_volatile):
            return windows_error::error_tm_volatile;
        

        case static_cast<native_windows_error>(windows_error::error_rollback_timer_expired):
            return windows_error::error_rollback_timer_expired;
        

        case static_cast<native_windows_error>(windows_error::error_txf_attribute_corrupt):
            return windows_error::error_txf_attribute_corrupt;
        

        case static_cast<native_windows_error>(windows_error::error_efs_not_allowed_in_transaction):
            return windows_error::error_efs_not_allowed_in_transaction;
        

        case static_cast<native_windows_error>(windows_error::error_transactional_open_not_allowed):
            return windows_error::error_transactional_open_not_allowed;
        

        case static_cast<native_windows_error>(windows_error::error_log_growth_failed):
            return windows_error::error_log_growth_failed;
        

        case static_cast<native_windows_error>(windows_error::error_transacted_mapping_unsupported_remote):
            return windows_error::error_transacted_mapping_unsupported_remote;
        

        case static_cast<native_windows_error>(windows_error::error_txf_metadata_already_present):
            return windows_error::error_txf_metadata_already_present;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_scope_callbacks_not_set):
            return windows_error::error_transaction_scope_callbacks_not_set;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_required_promotion):
            return windows_error::error_transaction_required_promotion;
        

        case static_cast<native_windows_error>(windows_error::error_cannot_execute_file_in_transaction):
            return windows_error::error_cannot_execute_file_in_transaction;
        

        case static_cast<native_windows_error>(windows_error::error_transactions_not_frozen):
            return windows_error::error_transactions_not_frozen;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_freeze_in_progress):
            return windows_error::error_transaction_freeze_in_progress;
        

        case static_cast<native_windows_error>(windows_error::error_not_snapshot_volume):
            return windows_error::error_not_snapshot_volume;
        

        case static_cast<native_windows_error>(windows_error::error_no_savepoint_with_open_files):
            return windows_error::error_no_savepoint_with_open_files;
        

        case static_cast<native_windows_error>(windows_error::error_data_lost_repair):
            return windows_error::error_data_lost_repair;
        

        case static_cast<native_windows_error>(windows_error::error_sparse_not_allowed_in_transaction):
            return windows_error::error_sparse_not_allowed_in_transaction;
        

        case static_cast<native_windows_error>(windows_error::error_tm_identity_mismatch):
            return windows_error::error_tm_identity_mismatch;
        

        case static_cast<native_windows_error>(windows_error::error_floated_section):
            return windows_error::error_floated_section;
        

        case static_cast<native_windows_error>(windows_error::error_cannot_accept_transacted_work):
            return windows_error::error_cannot_accept_transacted_work;
        

        case static_cast<native_windows_error>(windows_error::error_cannot_abort_transactions):
            return windows_error::error_cannot_abort_transactions;
        

        case static_cast<native_windows_error>(windows_error::error_bad_clusters):
            return windows_error::error_bad_clusters;
        

        case static_cast<native_windows_error>(windows_error::error_compression_not_allowed_in_transaction):
            return windows_error::error_compression_not_allowed_in_transaction;
        

        case static_cast<native_windows_error>(windows_error::error_volume_dirty):
            return windows_error::error_volume_dirty;
        

        case static_cast<native_windows_error>(windows_error::error_no_link_tracking_in_transaction):
            return windows_error::error_no_link_tracking_in_transaction;
        

        case static_cast<native_windows_error>(windows_error::error_operation_not_supported_in_transaction):
            return windows_error::error_operation_not_supported_in_transaction;
        

        case static_cast<native_windows_error>(windows_error::error_expired_handle):
            return windows_error::error_expired_handle;
        

        case static_cast<native_windows_error>(windows_error::error_transaction_not_enlisted):
            return windows_error::error_transaction_not_enlisted;
        

        case static_cast<native_windows_error>(windows_error::error_ctx_winstation_name_invalid):
            return windows_error::error_ctx_winstation_name_invalid;
        

        case static_cast<native_windows_error>(windows_error::error_ctx_invalid_pd):
            return windows_error::error_ctx_invalid_pd;
        

        case static_cast<native_windows_error>(windows_error::error_ctx_pd_not_found):
            return windows_error::error_ctx_pd_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_ctx_wd_not_found):
            return windows_error::error_ctx_wd_not_found;
        

        case static_cast<native_windows_error>(windows_error::error_ctx_cannot_make_eventlog_entry):
            return windows_error::error_ctx_cannot_make_eventlog_entry;
        

        case static_cast<native_windows_error>(windows_error::error_ctx_service_name_collision):
            return windows_error::error_ctx_service_name_collision;

        
        case static_cast<native_windows_error>(windows_error::error_ctx_close_pending):
            return windows_error::error_ctx_close_pending;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_no_outbuf):
            return windows_error::error_ctx_no_outbuf;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_modem_inf_not_found):
            return windows_error::error_ctx_modem_inf_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_invalid_modemname):
            return windows_error::error_ctx_invalid_modemname;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_modem_response_error):
            return windows_error::error_ctx_modem_response_error;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_modem_response_timeout):
            return windows_error::error_ctx_modem_response_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_modem_response_no_carrier):
            return windows_error::error_ctx_modem_response_no_carrier;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_modem_response_no_dialtone):
            return windows_error::error_ctx_modem_response_no_dialtone;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_modem_response_busy):
            return windows_error::error_ctx_modem_response_busy;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_modem_response_voice):
            return windows_error::error_ctx_modem_response_voice;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_td_error):
            return windows_error::error_ctx_td_error;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_winstation_not_found):
            return windows_error::error_ctx_winstation_not_found;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_winstation_already_exists):
            return windows_error::error_ctx_winstation_already_exists;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_winstation_busy):
            return windows_error::error_ctx_winstation_busy;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_bad_video_mode):
            return windows_error::error_ctx_bad_video_mode;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_graphics_invalid):
            return windows_error::error_ctx_graphics_invalid;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_logon_disabled):
            return windows_error::error_ctx_logon_disabled;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_not_console):
            return windows_error::error_ctx_not_console;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_client_query_timeout):
            return windows_error::error_ctx_client_query_timeout;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_console_disconnect):
            return windows_error::error_ctx_console_disconnect;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_console_connect):
            return windows_error::error_ctx_console_connect;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_shadow_denied):
            return windows_error::error_ctx_shadow_denied;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_winstation_access_denied):
            return windows_error::error_ctx_winstation_access_denied;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_invalid_wd):
            return windows_error::error_ctx_invalid_wd;
        
        
        case static_cast<native_windows_error>(windows_error::error_ctx_shadow_invalid):
            return windows_error::error_ctx_shadow_invalid;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_shadow_disabled):
            return windows_error::error_ctx_shadow_disabled;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_client_license_in_use):
            return windows_error::error_ctx_client_license_in_use;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_client_license_not_set):
            return windows_error::error_ctx_client_license_not_set;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_license_not_available):
            return windows_error::error_ctx_license_not_available;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_license_client_invalid):
            return windows_error::error_ctx_license_client_invalid;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_license_expired):
            return windows_error::error_ctx_license_expired;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_shadow_not_running):
            return windows_error::error_ctx_shadow_not_running;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_shadow_ended_by_mode_change):
            return windows_error::error_ctx_shadow_ended_by_mode_change;
        
        case static_cast<native_windows_error>(windows_error::error_activation_count_exceeded):
            return windows_error::error_activation_count_exceeded;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_winstations_disabled):
            return windows_error::error_ctx_winstations_disabled;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_encryption_level_required):
            return windows_error::error_ctx_encryption_level_required;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_session_in_use):
            return windows_error::error_ctx_session_in_use;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_no_force_logoff):
            return windows_error::error_ctx_no_force_logoff;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_account_restriction):
            return windows_error::error_ctx_account_restriction;
        
        case static_cast<native_windows_error>(windows_error::error_rdp_protocol_error):
            return windows_error::error_rdp_protocol_error;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_cdm_connect):
            return windows_error::error_ctx_cdm_connect;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_cdm_disconnect):
            return windows_error::error_ctx_cdm_disconnect;
        
        case static_cast<native_windows_error>(windows_error::error_ctx_security_layer_error):
            return windows_error::error_ctx_security_layer_error;
        
        case static_cast<native_windows_error>(windows_error::error_ts_incompatible_sessions):
            return windows_error::error_ts_incompatible_sessions;
        
        case static_cast<native_windows_error>(windows_error::error_ts_video_subsystem_error):
            return windows_error::error_ts_video_subsystem_error;
        default:
            return windows_error::unknown;
    }
}

windows_error_details::operator windows_error() const noexcept
{
    return get();
}

}