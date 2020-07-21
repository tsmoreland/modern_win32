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

#ifndef __MODERN_WIN32_PROCESS_STARTUP_INFO_H__
#define __MODERN_WIN32_PROCESS_STARTUP_INFO_H__
#ifdef _WIN32

#include <filesystem>
#include <map>
#include <string>
#include <modern_win32/window_handle.h>

namespace modern_win32
{

    template <typename TCHAR>
    class process_startup_info final
    {
        using string_type = std::basic_string<TCHAR>;
        using char_array_type = TCHAR[];
    public:
        process_startup_info() = default;

        [[nodiscard]] string_type get_filename() const
        {
            return m_filename;
        }
        void set_filename(string_type const& filename)
        {
            m_filename = filename;
        }
        __declspec(property(get = get_filename, put = set_filename)) string_type filename;

        [[nodiscard]] string_type get_arguments() const
        {
            return m_arguments;
        }
        void set_arguments(string_type const& arguments)
        {
            m_arguments = arguments;
        }
        __declspec(property(get = get_arguments, put = set_arguments)) string_type arguments;

        [[nodiscard]] string_type get_directory() const
        {
            return m_directory;
        }
        void set_directory(string_type const& directory)
        {
            m_directory = directory;
        }
        __declspec(property(get = get_directory, put = set_directory)) string_type directory;

        [[nodiscard]] window_handle const& get_error_dialog() const
        {
            return m_error_dialog;
        }
        [[nodiscard]] window_handle& get_error_dialog() 
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

        [[nodiscard]] bool get_redirect_standard_input() const
        {
            return m_redirect_standard_input;
        }
        void set_redirect_standard_input(bool const redirect_standard_input)
        {
            m_redirect_standard_input = redirect_standard_input;
        }
        __declspec(property(get = get_redirect_standard_input, put = set_redirect_standard_input))
        bool redirect_standard_input;

        [[nodiscard]] bool get_redirect_standard_output() const
        {
            return m_redirect_standard_output;
        }
        void set_redirect_standard_output(bool const redirect_standard_output)
        {
            m_redirect_standard_output = redirect_standard_output;
        }
        __declspec(property(get = get_redirect_standard_output, put = set_redirect_standard_output))
        bool redirect_standard_output;

        [[nodiscard]] bool get_redirect_standard_error() const
        {
            return m_redirect_standard_error;
        }
        void set_redirect_standard_error(bool const redirect_standard_error)
        {
            m_redirect_standard_error = redirect_standard_error;
        }
        __declspec(property(get = get_redirect_standard_error, put = set_redirect_standard_error))
        bool redirect_standard_error;

        [[nodiscard]] bool get_create_window() const
        {
            return m_create_window;
        }
        void set_create_window(bool const create_window)
        {
            m_create_window = create_window;
        }
        __declspec(property(get = get_create_window, put = set_create_window)) bool create_window;

        [[nodiscard]] std::map<string_type, string_type> get_environment() const
        {
            return m_environment;
        }
        void set_environment(const std::map<string_type, string_type>& environment)
        {
            m_environment = environment;
        }

        __declspec(property(get = get_environment, put = set_environment))
        std::map<string_type, string_type> environment;

        [[nodiscard]] static constexpr bool is_wide() 
        {
            return typeid(TCHAR) == typeid(wchar_t);
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
        std::map<string_type, string_type> m_environment;
    };

    using ansi_process_startup_info = process_startup_info<char>;
    using wide_process_startup_info = process_startup_info<wchar_t>;

    /*
        string fileName;
        string arguments;
        string directory;
        string verb;
        ProcessWindowStyle windowStyle;
        bool errorDialog;
        IntPtr errorDialogParentHandle;
#if FEATURE_PAL
        bool useShellExecute = false;
#else //FEATURE_PAL
        bool useShellExecute = true;
        string userName;
        string domain;
        SecureString password;
        string passwordInClearText;
        bool loadUserProfile;
#endif //FEATURE_PAL
        bool redirectStandardInput = false;
        bool redirectStandardOutput = false;       
        bool redirectStandardError = false;
        Encoding standardOutputEncoding;
        Encoding standardErrorEncoding; 
        
        bool createNoWindow = false;
        WeakReference weakParentProcess;
        internal StringDictionary environmentVariables;
    */
    
}

#endif
#endif