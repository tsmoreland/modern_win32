//
// Copyright � 2020 Terry Moreland
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

#pragma warning(push, 1)
#include <gtest/gtest.h>
#pragma warning(pop)
#include <chrono>
#include <filesystem>

#include <modern_win32/process.h>
#include "context.h"

#ifdef _WIN64
auto CommandExe = R"(c:\windows\system32\cmd.exe)";
auto TaskListExe = R"(c:\windows\system32\tasklist.exe)";
#else
auto CommandExe = R"(c:\windows\SysWOW64\cmd.exe)";
auto TaskListExe = R"(c:\windows\SysWOW64\tasklist.exe)";
#endif

using modern_win32::combine;
using modern_win32::open_process;
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
        : m_command(command)
        , m_arguments(arguments)
    {
    }

    TCHAR const* get_command() const noexcept
    {
        return m_command;
    }
    TCHAR const* get_arguments() const noexcept
    {
        return m_arguments;
    }

private:
    TCHAR const* m_command{};
    TCHAR const* m_arguments{};
    
};

TEST(process_should, throw_file_error_when_file_not_found)
{
    ASSERT_THROW({ auto const process = start_process("file_not_found", ""); }, std::filesystem::filesystem_error);
}

TEST(process_should, return_process_with_id_when_file_exists)
{
    auto const process = start_process(TaskListExe, "");
    auto const id = process.get_process_id();
    ASSERT_TRUE(id.has_value());
}

TEST(process_should, stop_waiting_after_exit)
{
    auto const process = start_process(CommandExe, "/c exit 5");
    ASSERT_TRUE(process.wait_for_exit(milliseconds(2500)));
}

TEST(process_should, report_is_running_when_active)
{
    auto const process = start_process(CommandExe, "1");
    ASSERT_TRUE(process.is_running());
    ASSERT_TRUE(!process.has_exited());
}

TEST(process_should, report_correct_exit_code)
{
    auto const process = start_process(CommandExe, "/c exit 5");
    EXPECT_TRUE(process.wait_for_exit(milliseconds(2500)));
    ASSERT_EQ(process::exit_code_type(5),  process.get_exit_code());
}

TEST(process_should, report_has_exited_after_exit)
{
    auto const process = start_process(CommandExe, "/c Sleep 1");
    EXPECT_TRUE(process.wait_for_exit(milliseconds(2500)));
    ASSERT_TRUE(process.has_exited());
    ASSERT_TRUE(!process.is_running());
}

TEST(process_should, timeout_when_waiting_too_long)
{
    auto const process = start_process(CommandExe, "/c Sleep 1");
    auto const timeout = process.wait_for_exit(milliseconds(250));

    process.wait_for_exit();
    ASSERT_FALSE(timeout);
}

TEST(process_should, open_process_with_valid_id)
{
    auto const process = start_process(CommandExe, "/c Sleep 1");
    auto const id = process.get_process_id().value_or(0UL);
    EXPECT_NE(0UL, id);

    auto opened_process = open_process(id, combine(process_access_rights::process_query_information, process_access_rights::synchronize));

}
