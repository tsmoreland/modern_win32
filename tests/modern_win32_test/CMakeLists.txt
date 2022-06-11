cmake_minimum_required (VERSION 3.8)

find_package(GTest REQUIRED)

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

add_definitions(-DMODERN_WIN32_EXPORTS -DUNICODE -D_UNICODE)

#gtest_add_tests(TARGET modern_win32_test)
add_test(NAME modern_win32_test COMMAND modern_win32_test)


# must be a better way to copy output but I haven't found it yet; strangely this just worked in the previous CMake setup

add_custom_command(
	TARGET modern_win32_test
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../out/build/${CMAKE_VS_PLATFORM_NAME}-$<CONFIG>/src/modern_win32/$<CONFIG>/modern_win32.dll ${CMAKE_CURRENT_SOURCE_DIR}/../../out/build/${CMAKE_VS_PLATFORM_NAME}-$<CONFIG>/tests/modern_win32_test/$<CONFIG>/modern_win32.dll 
	COMMENT "Copying modern_win32.dll to modern_win32_test folder"
)


set_tests_properties(modern_win32_test
  PROPERTIES
      ENVIRONMENT PATH="${CMAKE_CURRENT_SOURCE_DIR}/../../out/build/${CMAKE_VS_PLATFORM_NAME}-$<CONFIG>/src/modern_win32")


