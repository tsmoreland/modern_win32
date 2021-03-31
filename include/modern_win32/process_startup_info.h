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

#ifndef MODERN_WIN32_PROCESS_STARTUP_INFO_H_
#define MODERN_WIN32_PROCESS_STARTUP_INFO_H_
#ifdef _WIN32

#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <modern_win32/window_handle.h>

namespace modern_win32
{
    /// <summary>
    /// data transfer object storing details for process start up include command line arguments,
    /// environment settings, ...
    /// </summary>
    /// <typeparam name="TCHAR"></typeparam>
    template <typename TCHAR>
    class process_startup_info final
    {
    public:
        using string_type = std::basic_string<TCHAR>;
        using char_array_type = TCHAR[];
        using environment_variable_container = std::optional<std::map<string_type, string_type>>;

        process_startup_info() = default;

        [[nodiscard]]
        string_type const& get_filename() const
        {
            return m_filename;
        }
        void set_filename(string_type const& filename)
        {
            m_filename = filename;
        }
        __declspec(property(get = get_filename, put = set_filename)) string_type filename;

        [[nodiscard]]
        string_type get_arguments() const
        {
            return m_arguments;
        }
        void set_arguments(string_type const& arguments)
        {
            m_arguments = arguments;
        }
        __declspec(property(get = get_arguments, put = set_arguments)) string_type arguments;

        [[nodiscard]]
        string_type const& get_directory() const
        {
            return m_directory;
        }
        void set_directory(string_type const& directory)
        {
            m_directory = directory;
        }
        __declspec(property(get = get_directory, put = set_directory)) string_type directory;

        [[nodiscard]]
        window_handle const& get_error_dialog() const
        {
            return m_error_dialog;
        }
        [[nodiscard]]
        window_handle& get_error_dialog() 
        {
            return m_error_dialog;
        }
        void set_error_dialog(window_handle&& error_dialog)
        {
            m_error_dialog = std::move(error_dialog);
        }
        void set_error_dialog(window_handle::native_handle_type const handle)
        {
            static_cast<void>(m_error_dialog.reset(handle)); 
        }
        __declspec(property(get = get_error_dialog, put = set_error_dialog)) window_handle error_dialog;

        [[nodiscard]]
        bool get_redirect_standard_input() const
        {
            return m_redirect_standard_input;
        }
        void set_redirect_standard_input(bool const redirect_standard_input)
        {
            m_redirect_standard_input = redirect_standard_input;
        }
        __declspec(property(get = get_redirect_standard_input, put = set_redirect_standard_input))
        bool redirect_standard_input;

        [[nodiscard]]
        bool get_redirect_standard_output() const
        {
            return m_redirect_standard_output;
        }
        void set_redirect_standard_output(bool const redirect_standard_output)
        {
            m_redirect_standard_output = redirect_standard_output;
        }
        __declspec(property(get = get_redirect_standard_output, put = set_redirect_standard_output))
        bool redirect_standard_output;

        [[nodiscard]]
        bool get_redirect_standard_error() const
        {
            return m_redirect_standard_error;
        }
        void set_redirect_standard_error(bool const redirect_standard_error)
        {
            m_redirect_standard_error = redirect_standard_error;
        }
        __declspec(property(get = get_redirect_standard_error, put = set_redirect_standard_error))
        bool redirect_standard_error;

        [[nodiscard]]
        bool get_create_window() const
        {
            return m_create_window;
        }
        void set_create_window(bool const create_window)
        {
            m_create_window = create_window;
        }
        __declspec(property(get = get_create_window, put = set_create_window)) bool create_window;

        
        [[nodiscard]]
        bool get_inherit_handles() const
        {
            return m_inherit_handles;
        }
        void set_inherit_handles(bool const inherit_handles)
        {
            m_inherit_handles = inherit_handles;
        }
        __declspec(property(get = get_inherit_handles, put = set_inherit_handles)) bool inherit_handles;

        [[nodiscard]]
        environment_variable_container const& get_environment() const
        {
            return m_environment;
        }
        void set_environment(environment_variable_container const& environment)
        {
            m_environment = environment;
        }

        __declspec(property(get = get_environment, put = set_environment))
        environment_variable_container environment;

        [[nodiscard]]
        static constexpr bool is_wide() 
        {
            return typeid(TCHAR) == typeid(wchar_t);
        }


        [[nodiscard]]
        process_creation_options build_creation_options() const
        {
            process_creation_options options = process_creation_options::none;

            if (!create_window)
                options |= process_creation_options::create_no_window;

            if (is_wide())
                options |= process_creation_options::create_unicode_environment;

            return options;
        }

        [[nodiscard]]
        std::unique_ptr<char_array_type> build_command_buffer() const
        {
            std::basic_stringstream<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>> builder;
            builder << m_filename.c_str() << TCHAR(' ') << m_arguments.c_str();
            string_type command_line{builder.str()};
            auto buffer = std::make_unique<char_array_type>(command_line.size() + 1);
            std::copy(begin(command_line), end(command_line), buffer.get());
            return buffer;
        }

        template <typename STARTUP_INFO_T>
        [[nodiscard]]
        constexpr auto build_native_startup_info() const
        {
            auto flags = process_startup_options::none;

            if (redirect_standard_input || m_redirect_standard_output || redirect_standard_error) {
                // TODO: add handle support - maybe change these flags to std::optional<...handle>
                flags |= process_startup_options::use_standard_handles;
            }

            STARTUP_INFO_T startup_info{};
            startup_info.cb = sizeof(startup_info);
            startup_info.dwFlags = to_underlying_type(flags);
            return startup_info;
        }

    private:
        string_type m_filename;
        string_type m_arguments;
        string_type m_directory;
        // ProcessWindowStyle - add enum 
        window_handle m_error_dialog;
        //string_type m_username;
        //string_type m_password; // need to identify SecureString equivalent or skip AsUser runs
        //string_type m_domain;
        //bool m_load_user_profile;
        bool m_redirect_standard_input{false};
        bool m_redirect_standard_output{false};
        bool m_redirect_standard_error{false};
        bool m_create_window{true};
        bool m_inherit_handles{true};
        environment_variable_container m_environment;
    };

    using ansi_process_startup_info = process_startup_info<char>;
    using wide_process_startup_info = process_startup_info<wchar_t>;
        
    template <typename TCHAR>
    class process_startup_info_builder final
    {
    public:
        using string_type = typename process_startup_info<TCHAR>::string_type;
        using char_array_type = typename process_startup_info<TCHAR>::char_array_type;
        using environment_variable_container = typename process_startup_info<TCHAR>::environment_variable_container;

        process_startup_info<TCHAR>&& build()
        {
            return std::move(m_startup_info);
        }

        process_startup_info_builder& with_filename(string_type const& filename)
        {
            m_startup_info.filename = filename;
            return *this;
        }
        process_startup_info_builder& with_arguments(string_type const& arguments)
        {
            m_startup_info.arguments = arguments;
            return *this;
        }
        process_startup_info_builder& with_directory(string_type const& directory)
        {
            m_startup_info.directory = directory;
            return *this;
        }
        process_startup_info_builder& with_error_dialog(window_handle&& error_dialog)
        {
            m_startup_info.error_dialog = std::move(error_dialog);
            return *this;
        }
        process_startup_info_builder& with_redirect_standard_input(bool redirect_standard_input)
        {
            m_startup_info.redirect_standard_input = redirect_standard_input; 
            return *this;
        }
        process_startup_info_builder& with_redirect_standard_output(bool redirect_standard_output)
        {
            m_startup_info.redirect_standard_output = redirect_standard_output; 
            return *this;
        }
        process_startup_info_builder& with_redirect_standard_error(bool redirect_standard_error)
        {
            m_startup_info.redirect_standard_error = redirect_standard_error;
            return *this;
        }
        process_startup_info_builder& with_create_window(bool create_window)
        {
            m_startup_info.create_window = create_window;
            return *this;
        }
        process_startup_info_builder& with_inherit_handles(bool inherit_handles)
        {
            m_startup_info.inherit_handles = inherit_handles; 
            return *this;
        }
        process_startup_info_builder& with_environment(environment_variable_container&& environment)
        {
            m_startup_info.environment = std::move(environment); 
            return *this;
        }
        process_startup_info_builder& with_environment(environment_variable_container const& environment)
        {
            m_startup_info.environment = environment; 
            return *this;
        }

        void reset()
        {
            m_startup_info = process_startup_info<TCHAR>();
        }
    private:
        process_startup_info<TCHAR> m_startup_info;

    };

    using ansi_process_startup_info_builder = process_startup_info_builder<char>;
    using wide_process_startup_info_builder = process_startup_info_builder<wchar_t>;

}

#endif
#endif