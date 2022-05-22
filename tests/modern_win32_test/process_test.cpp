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

#pragma warning(disable : 26812 26495)
#include <gtest/gtest.h>
#pragma warning(default : 26812 26495)
#include <chrono>
#include <filesystem>

#include <modern_win32/process.h>
#include <modern_win32/shared_utilities.h>
#include "context.h"

#ifdef _WIN64
auto CommandExe = R"(c:\windows\system32\cmd.exe)";
auto TaskListExe = R"(c:\windows\system32\tasklist.exe)";
#else
auto CommandExe = R"(c:\windows\SysWOW64\cmd.exe)";
auto TaskListExe = R"(c:\windows\SysWOW64\tasklist.exe)";
#endif

using modern_win32::combine;
using modern_win32::open_process_or_throw;
using modern_win32::process;
using modern_win32::process_access_rights;
using modern_win32::start_process;

using std::chrono::milliseconds;

template <typename TCHAR>
class test_context final
{
public:
    using string_type = std::basic_string<TCHAR>;
    using char_type = TCHAR;

    test_context(TCHAR const* command, TCHAR const* arguments)
        : command_(command)
        , arguments_(arguments)
    {
    }

    TCHAR const* get_command() const noexcept
    {
        return command_;
    }
    TCHAR const* get_arguments() const noexcept
    {
        return arguments_;
    }

private:
    TCHAR const* command_{};
    TCHAR const* arguments_{};
    
};

TEST(process, constructor_should_throw_file_error_when_file_not_found)
{
    ASSERT_THROW({ auto const process = start_process("file_not_found", ""); }, std::filesystem::filesystem_error);
}

TEST(process, get_process_id_should_return_process_with_id_when_file_exists)
{
    auto const process = start_process(TaskListExe, "");
    auto const id = process.get_process_id();
    ASSERT_TRUE(id.has_value());
}

TEST(process, wait_for_exit_should_timeout_after_timeout_value)
{
    auto const process = start_process(CommandExe, "/c exit 5");
    ASSERT_TRUE(process.wait_for_exit(milliseconds(2500)));
}

TEST(process, is_running_should_return_true_when_active)
{
    auto const process = start_process(CommandExe, "1");
    ASSERT_TRUE(process.is_running());
    ASSERT_TRUE(!process.has_exited());
}

TEST(process, wait_for_exit_should_report_correct_exit_code)
{
    auto const process = start_process(CommandExe, "/c exit 3");
    EXPECT_TRUE(process.wait_for_exit(milliseconds(2500)));
    ASSERT_EQ(process::exit_code_type{ 3 }, process.get_exit_code());
}

TEST(process, has_exit_should_report_true_after_exit)
{
    auto const process = start_process(CommandExe, "/c Ping -n 2 127.0.0.1");
    EXPECT_TRUE(process.wait_for_exit(milliseconds(5000)));
    ASSERT_TRUE(process.has_exited());
    ASSERT_TRUE(!process.is_running());
}

TEST(process, wait_for_exit_should_timeout_when_waiting_too_long)
{
    auto const process = start_process(CommandExe, "/c Ping 127.0.0.1");
    auto const timeout = process.wait_for_exit(milliseconds(250));

    process.wait_for_exit();
    ASSERT_FALSE(timeout);
}

TEST(process, open_process_or_throw_should_open_process_with_valid_id)
{
    auto const process = start_process(CommandExe, "/c Sleep 1");
    auto const id = process.get_process_id().value_or(0UL);
    EXPECT_NE(0UL, id);

    ASSERT_NO_THROW({
        std::ignore = open_process_or_throw(id, combine(process_access_rights::process_query_information, process_access_rights::synchronize));
    });
}

TEST(process, open_process_should_open_process_with_valid_id)
{
    auto const process = start_process(CommandExe, "/c Sleep 1");
    auto const id = process.get_process_id().value_or(0UL);
    EXPECT_NE(0UL, id);

    auto const opened_process = open_process(id, combine(process_access_rights::process_query_information, process_access_rights::synchronize));

    ASSERT_TRUE(opened_process.has_value());
}
