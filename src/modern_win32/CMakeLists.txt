project(modern_win32 CXX)

# Source groups
set(source_files
	"threading/slim_lock.cpp"
	"threading/thread.cpp"
	"guid.cpp"
	
    "process.cpp" 
    "wait_for.cpp"
    "windows_error.cpp")

source_group("source files" FILES ${source_files})

set (public_header_files
    "../../include/modern_win32/access_denied_exception.h"
    "../../include/modern_win32/com_exception.h"
    "../../include/modern_win32/threading/event.h"
    "../../include/modern_win32/invalid_handle.h"
    "../../include/modern_win32/guid.h"
    "../../include/modern_win32/modern_win32_export.h"
    "../../include/modern_win32/module_handle.h"
    "../../include/modern_win32/naive_stack_allocator.h"
    "../../include/modern_win32/null_handle.h"
    "../../include/modern_win32/process.h"
    "../../include/modern_win32/process_enums.h"
    "../../include/modern_win32/process_information.h"
    "../../include/modern_win32/process_startup_info.h"
    "../../include/modern_win32/template_utilities.h"
    "../../include/modern_win32/threading/slim_lock.h"
    "../../include/modern_win32/threading/thread.h"
    "../../include/modern_win32/threading/thread_start.h"
    "../../include/modern_win32/unique_handle.h"
    "../../include/modern_win32/wait_for.h"
    "../../include/modern_win32/wait_for_result.h"
    "../../include/modern_win32/windows_exception.h"
    "../../include/modern_win32/windows_error.h"
    "../../include/modern_win32/windows_handle.h")

source_group("public header files" FILES ${public_header_files})

# Target
add_library(${PROJECT_NAME} SHARED ${source_files})

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE modern_win32)

set_target_properties(${PROJECT_NAME} PROPERTIES VS_GLOBAL_KEYWORD "Win32Proj")

# Output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/"
	OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/${CMAKE_VS_PLATFORM_NAME}/$<CONFIG>/"
)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Compile definitions
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
        "MODERN_WIN32_EXPORTS"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
        "MODERN_WIN32_EXPORTS"
    )
endif()

# Compile and link options
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Release>:
                /Oi;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy
            >
            /permissive-;
            /std:c++latest;
            /sdl;
            /W4;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Release>:
                /Oi;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy
            >
            /permissive-;
            /std:c++latest;
            /sdl;
            /W4;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()
