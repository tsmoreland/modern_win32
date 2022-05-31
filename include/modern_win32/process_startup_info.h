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

#ifndef MODERN_WIN32_PROCESS_STARTUP_INFO_H_
#define MODERN_WIN32_PROCESS_STARTUP_INFO_H_
#ifdef _WIN32

#include <map>
#include <modern_win32/window_handle.h>
#include <optional>
#include <sstream>
#include <string>

namespace modern_win32 {
    /// <summary>
    /// data transfer object storing details for process start up include command line arguments,
    /// environment settings, ...
    /// </summary>
    /// <typeparam name="TCHAR"></typeparam>
    template <typename TCHAR>
    class process_startup_info final {
    public:
        using string_type                    = std::basic_string<TCHAR>;
        using char_array_type                = TCHAR[];
        using environment_variable_container = std::optional<std::map<string_type, string_type>>;

        process_startup_info() = default;

        [[nodiscard]] string_type const& get_filename() const {
            return filename_;
        }
        void set_filename(string_type const& filename) {
            filename_ = filename;
        }
        __declspec(property(get = get_filename, put = set_filename)) string_type filename;

        [[nodiscard]] string_type get_arguments() const {
            return arguments_;
        }
        void set_arguments(string_type const& arguments) {
            arguments_ = arguments;
        }
        __declspec(property(get = get_arguments, put = set_arguments)) string_type arguments;

        [[nodiscard]] string_type const& get_directory() const {
            return directory_;
        }
        void set_directory(string_type const& directory) {
            directory_ = directory;
        }
        __declspec(property(get = get_directory, put = set_directory)) string_type directory;

        [[nodiscard]] window_handle const& get_error_dialog() const {
            return error_dialog_;
        }
        [[nodiscard]] window_handle& get_error_dialog() {
            return error_dialog_;
        }
        void set_error_dialog(window_handle&& error_dialog) {
            static_cast<void>(error_dialog_.reset(error_dialog.release()));
        }
        void set_error_dialog(window_handle::native_handle_type const handle) {
            static_cast<void>(error_dialog_.reset(handle));
        }
        __declspec(property(get = get_error_dialog, put = set_error_dialog)) window_handle error_dialog;

        [[nodiscard]] bool get_redirect_standard_input() const {
            return redirect_standard_input_;
        }
        void set_redirect_standard_input(bool const redirect_standard_input) {
            redirect_standard_input_ = redirect_standard_input;
        }
        __declspec(property(
            get = get_redirect_standard_input, put = set_redirect_standard_input)) bool redirect_standard_input;

        [[nodiscard]] bool get_redirect_standard_output() const {
            return redirect_standard_output_;
        }
        void set_redirect_standard_output(bool const redirect_standard_output) {
            redirect_standard_output_ = redirect_standard_output;
        }
        __declspec(property(
            get = get_redirect_standard_output, put = set_redirect_standard_output)) bool redirect_standard_output;

        [[nodiscard]] bool get_redirect_standard_error() const {
            return redirect_standard_error_;
        }
        void set_redirect_standard_error(bool const redirect_standard_error) {
            redirect_standard_error_ = redirect_standard_error;
        }
        __declspec(property(
            get = get_redirect_standard_error, put = set_redirect_standard_error)) bool redirect_standard_error;

        [[nodiscard]] bool get_create_window() const {
            return create_window_;
        }
        void set_create_window(bool const create_window) {
            create_window_ = create_window;
        }
        __declspec(property(get = get_create_window, put = set_create_window)) bool create_window;


        [[nodiscard]] bool get_inherit_handles() const {
            return inherit_handles_;
        }
        void set_inherit_handles(bool const inherit_handles) {
            inherit_handles_ = inherit_handles;
        }
        __declspec(property(get = get_inherit_handles, put = set_inherit_handles)) bool inherit_handles;

        [[nodiscard]] environment_variable_container const& get_environment() const {
            return environment_;
        }
        void set_environment(environment_variable_container const& environment) {
            environment_ = environment;
        }

        __declspec(property(get = get_environment, put = set_environment)) environment_variable_container environment;

        [[nodiscard]] static constexpr bool is_wide() {
            return typeid(TCHAR) == typeid(wchar_t);
        }


        [[nodiscard]] process_creation_options build_creation_options() const {
            process_creation_options options = process_creation_options::none;

            if (!create_window)
                options |= process_creation_options::create_no_window;

            if (is_wide())
                options |= process_creation_options::create_unicode_environment;

            return options;
        }

        [[nodiscard]] std::unique_ptr<char_array_type> build_command_buffer() const {
            std::basic_stringstream<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>> builder;
            builder << filename_.c_str() << TCHAR(' ') << arguments_.c_str();
            string_type command_line{builder.str()};
            auto buffer = std::make_unique<char_array_type>(command_line.size() + 1);
            std::copy(begin(command_line), end(command_line), buffer.get());
            return buffer;
        }

        template <typename STARTUP_INFO_T>
        [[nodiscard]] constexpr auto build_native_startup_info() const {
            auto flags = process_startup_options::none;

            if (redirect_standard_input || redirect_standard_output_ || redirect_standard_error) {
                // TODO: add handle support - maybe change these flags to std::optional<...handle>
                flags |= process_startup_options::use_standard_handles;
            }

            STARTUP_INFO_T startup_info{};
            startup_info.cb      = sizeof(startup_info);
            startup_info.dwFlags = to_underlying_type(flags);
            return startup_info;
        }

    private:
        string_type filename_;
        string_type arguments_;
        string_type directory_;
        // ProcessWindowStyle - add enum
        window_handle error_dialog_;
        // string_type username_;
        // string_type password_; // need to identify SecureString equivalent or skip AsUser runs
        // string_type domain_;
        // bool load_user_profile_;
        bool redirect_standard_input_{false};
        bool redirect_standard_output_{false};
        bool redirect_standard_error_{false};
        bool create_window_{true};
        bool inherit_handles_{true};
        environment_variable_container environment_;
    };

    using narrow_process_startup_info = process_startup_info<char>;
    using wide_process_startup_info   = process_startup_info<wchar_t>;

    template <typename TCHAR>
    class process_startup_info_builder final {
    public:
        using string_type                    = typename process_startup_info<TCHAR>::string_type;
        using char_array_type                = typename process_startup_info<TCHAR>::char_array_type;
        using environment_variable_container = typename process_startup_info<TCHAR>::environment_variable_container;

        process_startup_info<TCHAR>&& build() {
            return std::move(startup_info_);
        }

        process_startup_info_builder& with_filename(string_type const& filename) {
            startup_info_.filename = filename;
            return *this;
        }
        process_startup_info_builder& with_arguments(string_type const& arguments) {
            startup_info_.arguments = arguments;
            return *this;
        }
        process_startup_info_builder& with_directory(string_type const& directory) {
            startup_info_.directory = directory;
            return *this;
        }
        process_startup_info_builder& with_error_dialog(window_handle&& error_dialog) {
            startup_info_.error_dialog = std::move(error_dialog);
            return *this;
        }
        process_startup_info_builder& with_redirect_standard_input(bool redirect_standard_input) {
            startup_info_.redirect_standard_input = redirect_standard_input;
            return *this;
        }
        process_startup_info_builder& with_redirect_standard_output(bool redirect_standard_output) {
            startup_info_.redirect_standard_output = redirect_standard_output;
            return *this;
        }
        process_startup_info_builder& with_redirect_standard_error(bool redirect_standard_error) {
            startup_info_.redirect_standard_error = redirect_standard_error;
            return *this;
        }
        process_startup_info_builder& with_create_window(bool create_window) {
            startup_info_.create_window = create_window;
            return *this;
        }
        process_startup_info_builder& with_inherit_handles(bool inherit_handles) {
            startup_info_.inherit_handles = inherit_handles;
            return *this;
        }
        process_startup_info_builder& with_environment(environment_variable_container&& environment) {
            startup_info_.environment = std::move(environment);
            return *this;
        }
        process_startup_info_builder& with_environment(environment_variable_container const& environment) {
            startup_info_.environment = environment;
            return *this;
        }

        void reset() {
            startup_info_ = process_startup_info<TCHAR>();
        }

    private:
        process_startup_info<TCHAR> startup_info_;
    };

    using narrow_process_startup_info_builder = process_startup_info_builder<char>;
    using wide_process_startup_info_builder   = process_startup_info_builder<wchar_t>;

} // namespace modern_win32

#endif
#endif