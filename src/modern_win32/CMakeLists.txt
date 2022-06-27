# CMakeList.txt : CMake project for modern_win32, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(root_header_files
    "../../include/modern_win32/access_denied_exception.h"
    "../../include/modern_win32/com_exception.h"
    "../../include/modern_win32/invalid_handle.h"
    "../../include/modern_win32/environment.h"
    "../../include/modern_win32/guid.h"
    "../../include/modern_win32/modern_win32_export.h"
    "../../include/modern_win32/module_handle.h"
    "../../include/modern_win32/null_handle.h"
    "../../include/modern_win32/process.h"
    "../../include/modern_win32/process_module.h"
    "../../include/modern_win32/process_enums.h"
    "../../include/modern_win32/process_startup_info.h"
    "../../include/modern_win32/shared_utilities.h"
    "../../include/modern_win32/string.h"
    "../../include/modern_win32/unique_handle.h"
    "../../include/modern_win32/wait_for.h"
    "../../include/modern_win32/wait_for_result.h"
    "../../include/modern_win32/windows_exception.h"
    "../../include/modern_win32/windows_error.h"
    "../../include/modern_win32/window_handle.h"
    "../../include/modern_win32/windows_memory.h"
)

set(shared_header_files
    "../../include/modern_win32/shared/case_insensitive_string.h"
    "../../include/modern_win32/shared/chrono_extensions.h"
    "../../include/modern_win32/shared/timed_lock_guard.h"
    "../../include/modern_win32/shared/timeout_exception.h"
)

set(threading_header_files
    "../../include/modern_win32/threading/event.h"
    "../../include/modern_win32/threading/semaphore.h"
    "../../include/modern_win32/threading/slim_lock.h"
    "../../include/modern_win32/threading/thread.h"
    "../../include/modern_win32/threading/thread_start.h"
)

set(public_header_files
    ${root_header_files}
    ${shared_header_files}
    ${threading_header_files}
)

# define the source (cpp) files
set(source_files

    "impl/process_impl.h"
    "impl/process_impl.cpp"
    "threading/slim_lock.cpp"
    "threading/semaphore.cpp"
    "threading/timer.cpp"
    "threading/thread.cpp"
    "environment.cpp"
    "guid.cpp"
    "process.cpp" 
    "process_module.cpp" 
    "version_info.h"
    "wait_for.cpp"
    "windows_error.cpp"
)

# Add source to this project's executable.

add_definitions(-DMODERN_WIN32_EXPORTS -DUNICODE -D_UNICODE)

add_library(modern_win32 SHARED ${source_files} ${public_header_files})

include(GenerateExportHeader)
generate_export_header(modern_win32)

set_target_properties(modern_win32 PROPERTIES EXPORT_NAME modern_win32)
set_target_properties(modern_win32 PROPERTIES VS_GLOBAL_KEYWORD "Win32Proj")

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC" AND CMAKE_BUILD_TYPE MATCHES "Release")
   target_compile_options(modern_win32 PRIVATE /Zi)

   # Tell linker to include symbol data
    set_target_properties(modern_win32 PROPERTIES 
        LINK_FLAGS "/INCREMENTAL:NO /DEBUG /OPT:REF /OPT:ICF"
    )

    # Set file name & location
    set_target_properties(modern_win32 PROPERTIES 
        COMPILE_PDB_NAME modern_win32 
        COMPILE_PDB_OUTPUT_DIR ${CMAKE_BINARY_DIR}
    )
endif()

set_property(TARGET modern_win32 PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")


target_include_directories(modern_win32
    PUBLIC        
        $<INSTALL_INTERFACE:../../include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS modern_win32
    EXPORT modern_win32
    LIBRARY DESTINATION lib 
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION lib
)
install(FILES $<TARGET_PDB_FILE:modern_win32> DESTINATION lib)

install(FILES ${root_header_files} DESTINATION include/modern_win32)
install(FILES ${shared_header_files} DESTINATION include/modern_win32/shared)
install(FILES ${threading_header_files} DESTINATION include/modern_win32/threading)

