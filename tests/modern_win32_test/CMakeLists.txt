cmake_minimum_required (VERSION 3.24)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(modern_win32_test ${TEST_SOURCES} 
    "context.cpp" 
    "delayed_callback_test.cpp"
    "environment_test.cpp"
    "event_test.cpp" 
    "guid_test.cpp" 
    "process_test.cpp"
    "semaphore_test.cpp"
    "slim_lock_test.cpp" 
    "synchronization_timer_test.cpp"
    "thread_test.cpp"  
    "timer_test.cpp"
)

# use this if/when utils exports something
target_link_libraries(modern_win32_test PUBLIC modern_win32 GTest::GTest GTest::Main)

set_target_properties(modern_win32_test PROPERTIES
    INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
)

if (CMAKE_BUILD_TYPE MATCHES "Release")
	add_definitions(-DUNICODE -D_UNICODE -D_ENABLE_EXTENDED_ALIGNED_STORAGE -DNDEBUG -D_MBCS -DWIN32 -D_WINDOWS)
else()
	add_definitions(-DUNICODE -D_UNICODE -D_ENABLE_EXTENDED_ALIGNED_STORAGE -D_DEBUG -D_MBCS -DWIN32 -D_WINDOWS)
endif()

message(status " vcpkg: ${CMAKE_TOOLCHAIN_FILE}")
find_package(GTest REQUIRED)

add_test(NAME modern_win32_test COMMAND modern_win32_test)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(status " using msvc compiler")
    set(MSVC_TOOLSET_VERSION 143)

    set(CMAKE_CXX_FLAGS "/W4 /GR /GS /EHsc /wd4100 /wd4206 /wd4702 /wd6255 /nologo /diagnostics:column /std:c++20 /Zc:inline /fp:precise /errorReport:prompt /WX- /Zc:forScope /Zc:wchar_t /Zi /Gm- /we4715 /we4172")
	set(CMAKE_CXX_FLAGS_RELEASE "/MP /Gy /O2 /Gd /Oi /MD /FC")
	set(CMAKE_CXX_FLAGS_DEBUG "/JMC /MP /we4172 /GS /Od /RTC1 /Gd /MDd ")

    if (CMAKE_BUILD_TYPE MATCHES "Release")
		if (${USE_SPECTRE} MATCHES "true")
			message(status " Spectre is enabled, adding /QSpectre flag")
			target_compile_options(modern_win32_test PRIVATE /Qspectre)

			target_link_options(modern_win32_test PRIVATE /DYNAMICBASE)

		else()
			message(status " Spectre is not enabled")
		endif()

    else()
		if (${USE_SPECTRE} MATCHES "true")
			message(status " Spectre is enabled, adding /QSpectre flag")
			target_compile_options(modern_win32_test PRIVATE /Qspectre)

			target_link_options(modern_win32_test PRIVATE /DYNAMICBASE)
		else()
			message(status " Spectre is not enabled")
		endif()
    endif()

   # Tell linker to include symbol data
	set_target_properties(modern_win32_test PROPERTIES 
		LINK_FLAGS "/INCREMENTAL:NO /DEBUG /OPT:REF /OPT:ICF"
	)

    # Set file name & location
    set_target_properties(modern_win32_test PROPERTIES 
        COMPILE_PDB_NAME modern_win32_test 
        COMPILE_PDB_OUTPUT_DIR ${CMAKE_BINARY_DIR}
    )

	set_property(TARGET modern_win32_test PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()



# must be a better way to copy output but I haven't found it yet; strangely this just worked in the previous CMake setup
message(STATUS "Spectre enabled")
add_custom_command(
	TARGET modern_win32_test
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../out/build/${PRESET_NAME}/src/modern_win32/modern_win32.dll ${CMAKE_CURRENT_SOURCE_DIR}/../../out/build/${PRESET_NAME}/tests/modern_win32_test/modern_win32.dll 
	COMMENT "Copying modern_win32.dll to modern_win32_test folder"
)


set_tests_properties(modern_win32_test
  PROPERTIES
	  ENVIRONMENT PATH="${CMAKE_CURRENT_SOURCE_DIR}/../../out/build/${PRESET_NAME}/src/modern_win32")
