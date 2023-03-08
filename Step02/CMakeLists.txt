cmake_minimum_required(VERSION 3.10)

project(step2 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(step.h.in step.h)

option(USE_MYMATH "Use our implemented function" ON)

if (USE_MYMATH)
    add_subdirectory(mydir)
    list(APPEND EXTRA_LIBS mydir)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/mydir")
endif()

add_executable(step2 step.cpp)

target_link_libraries(step2 PUBLIC ${EXTRA_LIBS})

target_include_directories(step2 PUBLIC 
	                   "${PROJECT_BINARY_DIR}"
			   ${EXTRA_INCLUDES})
