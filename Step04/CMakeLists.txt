cmake_minimum_required(VERSION 3.15)

project(step4 VERSION 1.0)

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

configure_file(step.h.in step.h)

option(USE_MYMATH "Use our implemented function" ON)

if (USE_MYMATH)
    add_subdirectory(mydir)
    list(APPEND EXTRA_LIBS mydir)
endif()

add_executable(step4 step.cpp)

target_link_libraries(step4 PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

target_include_directories(step4 PUBLIC 
	                   "${PROJECT_BINARY_DIR}")

target_compile_options(tutorial_compiler_flags INTERFACE
	               "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
	               "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")
