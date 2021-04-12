set(TEST_PROJECT_NAME ${CMAKE_PROJECT_NAME}_test)

find_package(GTest REQUIRED)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${TEST_PROJECT_NAME} ${TEST_SOURCES} 
    "context.cpp" 
    "event_test.cpp" 
    "guid_test.cpp" 
    "process_test.cpp"
    "rsa_crypto_provider_test.cpp"
    "slim_lock_test.cpp" 
    "thread_test.cpp" )

add_test(NAME ${TEST_PROJECT_NAME} COMMAND ${TEST_PROJECT_NAME})


set_target_properties(${TEST_PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
use_props(${TEST_PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

# use this if/when utils exports something
# target_link_libraries(${TEST_PROJECT_NAME} PUBLIC ${CMAKE_PROJECT_NAME}_lib GTest::GTest GTest::Main)
target_link_libraries(${TEST_PROJECT_NAME} PUBLIC ${CMAKE_PROJECT_NAME} GTest::GTest GTest::Main)

set_target_properties(${TEST_PROJECT_NAME} PROPERTIES
	INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
)

target_include_directories(${TEST_PROJECT_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${TEST_PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${TEST_PROJECT_NAME} PRIVATE
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
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${TEST_PROJECT_NAME} PRIVATE
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
        target_compile_options(${TEST_PROJECT_NAME} PRIVATE
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

	target_link_options(${TEST_PROJECT_NAME} PRIVATE
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
