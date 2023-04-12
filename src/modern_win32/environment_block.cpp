//
// Copyright (c) 2023 Terry Moreland
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

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <modern_win32/environment_block.h>
#include <modern_win32/windows_exception.h>
#include <UserEnv.h>

namespace modern_win32 {

    environment_block::environment_block(bool const inherit_from_current_process) {
        if (TRUE != CreateEnvironmentBlock(&environment_, nullptr, inherit_from_current_process ? TRUE : FALSE)) {
            throw windows_exception();
        }
    }

    environment_block::~environment_block() {
        if (environment_ != nullptr) {
            DestroyEnvironmentBlock(environment_);
            environment_ = nullptr;
        }
    }

    environment_block_iterator environment_block::begin() const noexcept {
        return environment_block_iterator(*this);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic -- keeping as member to work as an iterator
    environment_block_iterator environment_block::end() const noexcept {
        return environment_block_iterator();
    }


}
