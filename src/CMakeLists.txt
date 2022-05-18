# include sub-projects here.
cmake_minimum_required (VERSION 3.8)

set(CMAKE_SYSTEM_VERSION 10.0 CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 20)

# Include sub-projects.
add_subdirectory ("modern_win32")
