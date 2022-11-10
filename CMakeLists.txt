# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_SYSTEM_VERSION 10.0.10941 CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 20)

project ("modern_win32")

message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

SET(USE_SPECTRE $ENV{SPECTRE})
SET(PRESET_NAME $ENV{preset_name})

if (${USE_SPECTRE} MATCHES "true")
    message(status " Spectre is enabled")
endif()
message(status " preset name: '" ${PRESET_NAME} "'")

if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

include_directories(include)
enable_testing()

# Include sub-projects.
add_subdirectory ("src")
add_subdirectory(tests/modern_win32_test)

