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

#ifndef MODERN_WIN32_PROCESS_H
#define MODERN_WIN32_PROCESS_H
#ifdef _WIN32

#include <chrono>
#include <modern_win32/modern_win32_export.h>
#include <modern_win32/null_handle.h>
#include <modern_win32/process_enums.h>
#include <modern_win32/process_module.h>
#include <modern_win32/process_startup_info.h>
#include <optional>

#include <Windows.h>

namespace modern_win32 {
    using process_handle  = null_handle;
    using process_id_type = decltype(PROCESS_INFORMATION::dwProcessId);

    class MODERN_WIN32_EXPORT process final {
    public:
        using native_handle_type = process_handle::native_handle_type;
        using exit_code_type     = unsigned long;
        using deconstruct_type   = std::pair<process_id_type, native_handle_type>;

        [[nodiscard]] static constexpr deconstruct_type make_deconstruct_type(
            process_id_type id, native_handle_type handle) {
            return deconstruct_type{id, handle};
        }
        [[nodiscard]] static constexpr deconstruct_type empty() noexcept {
            return make_deconstruct_type(0UL, process_handle::invalid());
        }

        explicit process(native_handle_type const& handle = process_handle::invalid());
        explicit process(process_id_type const& id);
        explicit process(
            process_id_type const& id, process_access_rights const access_rights, bool const inherit_handles = false);
        explicit process(process_id_type const& id, native_handle_type const& handle);
        explicit process(deconstruct_type const& id_handle_pair);
        process(process const&) = delete;
        process(process&& other) noexcept;
        ~process() = default;

        process& operator=(process const&) = delete;
        process& operator                  =(process&& other) noexcept;

        MODERN_WIN32_EXPORT
        friend bool operator==(process const& first, process const& second);
        MODERN_WIN32_EXPORT
        friend bool operator!=(process const& first, process const& second);

        /// <summary>
        /// Returns true if process handle is not invalid
        /// </summary>
        [[nodiscard]] explicit operator bool() const noexcept;

        /// <summary>swaps the value of <paramref name="lhs"/> and <paramref name="rhs"/></summary>
        MODERN_WIN32_EXPORT
        friend void swap(process& first, process& second) noexcept;

        /// <summary>replaces the managed object</summary>
        /// <returns>true if the replacement represents a valid process; otherwise, false</returns>
        [[nodiscard]] bool reset(deconstruct_type const& process = empty());

        /// <summary>replaces the managed object</summary>
        /// <returns>true if the replacement represents a valid process; otherwise, false</returns>
        [[nodiscard]] bool reset(native_handle_type const handle = process_handle::invalid());

        /// <summary>
        /// releases the ownership of the process handle if any,
        /// </summary>
        /// <returns><see cref="native_handle_type"/> containing the contents of the managed object</returns>
        [[nodiscard]] deconstruct_type release();

        /// <summary>
        /// Returns the underlying implementation-defined native handle object.
        /// </summary>
        /// <returns>implementation-defined native handle object.</returns>
        [[nodiscard]] native_handle_type native_handle() const noexcept;

        /// <summary>
        /// Returns a reference to the managed handle object.
        /// </summary>
        /// <returns>reference to the managed handle object.</returns>
        [[nodiscard]] process_handle& get() noexcept;

        /// <summary>
        /// Retrieves the process identifier of the process.
        /// </summary>
        /// <returns>
        /// the process identifier of the process, if found; otherise <see cref="std::nullopt"/>
        /// </returns>
        /// <exception cref="windows_exception">if call to native GetProcessId fails</exception>
        [[nodiscard]] std::optional<process_id_type> get_process_id() const;

        /// <summary>returns true if a process is currently owned and is running; otherwise, false</summary>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        [[nodiscard]] bool is_running() const;

        /// <summary>Gets a value indicating whether the associated process has been terminated.</summary>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        [[nodiscard]] bool has_exited() const;

        /// <summary>
        /// Returns the priority of the process if running; otherwise std::nullopt
        /// </summary>
        /// <returns>priority of the process if running; otherwise std::nullopt</returns>
        /// <exception cref="windows_exception">if native api (GetPriorityClass) fails</exception>
        [[nodiscard]] std::optional<process_priority> get_priority() const;

        /// <summary>
        /// Returns the process exit code if it is no longer running; otherwise <see cref="std::nullopt"/>
        /// </summary>
        /// <returns>process exit code if process has exited</returns>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        [[nodiscard]] std::optional<exit_code_type> get_exit_code() const;

        /// <summary>waits for process to exit</summary>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        /// <exception cref="std::runtime_exception">
        /// if process_information was incorectly built from mutex which was abandoned
        /// </exception>
        void wait_for_exit() const;

        /// <summary>
        /// waits until process has exited or <paramref name="timeout"/> milliseconds have elapsed
        /// </summary>
        /// <param name="timeout">number of milliseconds to wait for process to exit</param>
        /// <returns>true if process has exited; otherwise, false</returns>
        /// <exception cref="windows_exception">if an error occurs calling the Win32 API</exception>
        /// <exception cref="std::runtime_exception">
        /// if process_information was incorectly built from mutex which was abandoned
        /// </exception>
        [[nodiscard]] bool wait_for_exit(std::chrono::milliseconds const& timeout) const;

        /// <summary>
        /// returns the first module of the process
        /// </summary>
        /// <returns>the first module of the process</returns>
        /// <exception cref="windows_exception">if error occurs with Win32 API</exception>
        [[nodiscard]] process_module get_primary_module() const;

        /// <summary>
        /// returns a collection of all modules in the process
        /// </summary>
        /// <param name="max_count">maximum number of modules to retrieve</param>
        /// <returns>a collection of all modules in the process</returns>
        /// <exception cref="windows_exception">if error occurs with Win32 API</exception>
        /// <exception cref="std::invalid_argument">if max_count is 0</exception>
        [[nodiscard]] std::vector<process_module> get_modules(DWORD max_count = 1024) const;

    private:
#pragma warning(push)
#pragma warning(disable : 4251)
        process_handle handle_;
#pragma warning(pop)
        process_id_type id_;

        void close() noexcept;
    };

    /**
     * \brief Opens an existing local process object, or throws an exception if unable to
     * \param id The identifier of the local process to be opened.
     * \param access_rights The access to the process object. This access right is checked against the security
     *                      descriptor for the process. This parameter can be one or more of the <see
     * cref="process_access_rights"/>. \param inherit_handles  If this value is true, processes created by this process
     * will inherit the handle. Otherwise, the processes do not inherit this handle. \return processs instance
     * \exception std::invalid_argument if process_id is 0
     * \exception access_denied_exception if insufficent access to open process
     */
    [[nodiscard]] MODERN_WIN32_EXPORT process open_process_or_throw(
        process_id_type const& id, process_access_rights const access_rights, bool const inherit_handles = false);

    /**
     * \brief Opens an existing local process object or an empty optional
     * \param id The identifier of the local process to be opened.
     * \param access_rights The access to the process object. This access right is checked against the security
     *                      descriptor for the process. This parameter can be one or more of the <see
     * cref="process_access_rights"/>. \param inherit_handles  If this value is true, processes created by this process
     * will inherit the handle. Otherwise, the processes do not inherit this handle.</param> \return process if able to
     * open or empty optional
     */
    [[nodiscard]] MODERN_WIN32_EXPORT std::optional<process> open_process(
        process_id_type const& id, process_access_rights const access_rights, bool const inherit_handles = false);

    /**
     * \brief opens first process matching process_name
     * \param process_name name of the process to open
     * \return std::optional containing the process matching process_name; otherwise, std::nullopt
     */
    [[nodiscard]] MODERN_WIN32_EXPORT std::optional<process> open_process_by_name(wchar_t const* process_name);

    /// <summary>
    /// Starts the process resource that is specified by the parameter containing process start information
    /// (for example, the file name of the process to start) and associates the resource with a new Process component.
    /// </summary>
    /// <param name="startup_info">
    /// The <see cref="narrow_process_start_info"/> that contains the information that is used to start the process,
    /// including the file name and any command-line arguments.
    /// </param>
    /// <returns>
    /// A new Process that is associated with the process resource, Note that a new process that's started
    /// alongside already running instances of the same process will be independent from the others. In addition,
    /// start may return a non-null process with its has_exited already set to true. In this case, the started
    /// process may have activated an existing instance of itself and then exited.
    /// </returns>
    /// <exception cref="std::filesystem::filesystem_error">thrown if thte filename specified in <paramref
    /// name="startup_info"/> is not found.</exception> <exception cref="windows_exception">if there is an error in the
    /// native CreateProcess call</exception>
    [[nodiscard]] MODERN_WIN32_EXPORT process start_process_or_throw(narrow_process_startup_info const& startup_info);

    /// <summary>
    /// Starts the process resource that is specified by the parameter containing process start information
    /// (for example, the file name of the process to start) and associates the resource with a new Process component.
    /// </summary>
    /// <param name="startup_info">
    /// The <see cref="wide_process_start_info"/> that contains the information that is used to start the process,
    /// including the file name and any command-line arguments.
    /// </param>
    /// <returns>
    /// A new Process that is associated with the process resource, Note that a new process that's started
    /// alongside already running instances of the same process will be independent from the others. In addition,
    /// start may return a non-null process with its has_exited already set to true. In this case, the started
    /// process may have activated an existing instance of itself and then exited.
    /// </returns>
    /// <exception cref="std::filesystem::filesystem_error">thrown if thte filename specified in <paramref
    /// name="startup_info"/> is not found.</exception> <exception cref="windows_exception">if there is an error in the
    /// native CreateProcess call</exception>
    [[nodiscard]] MODERN_WIN32_EXPORT process start_process_or_throw(wide_process_startup_info const& startup_info);

    /**
     * \brief Starts a process resource and associates it with a process instance
     * \param filename the executable to run
     * \param arguments command line arguments for the executable
     * \return process instance
     * \exception std::error_code if file is not found
     * \exception modern_win32::windows_exception if error occured creating the process
     */
    [[nodiscard]] MODERN_WIN32_EXPORT process start_process_or_throw(char const* filename, char const* arguments);

    /**
     * \brief Starts a process resource and associates it with a process instance
     * \param filename the executable to run
     * \param arguments command line arguments for the executable
     * \return process instance
     * \exception std::error_code if file is not found
     * \exception modern_win32::windows_exception if error occured creating the process
     */
    [[nodiscard]] MODERN_WIN32_EXPORT process start_process_or_throw(wchar_t const* filename, wchar_t const* arguments);

    /**
     * \brief gets all active process ids
     * \return std::vector containing active process ids;
     */
    [[nodiscard]] MODERN_WIN32_EXPORT std::vector<process_id_type> get_proccess_ids();

} // namespace modern_win32

#endif
#endif