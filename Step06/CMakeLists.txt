cmake_minimum_required(VERSION 3.15)

project(step6 VERSION 1.0)

enable_testing()

add_test(NAME Runs COMMAND step6 25)
add_test(NAME Usage COMMAND step6)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPERSSION "Usage:.*number")

add_test(NAME StandardUse COMMAND step6 4)
set_tests_properties(StandardUse PROPERTIES PASS_REGULAR_EXPRESSION "4 is 2")

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

add_executable(step6 step.cpp)

target_link_libraries(step6 PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

target_include_directories(step6 PUBLIC 
	                   "${PROJECT_BINARY_DIR}")

target_compile_options(tutorial_compiler_flags INTERFACE
	               "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
	               "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

install(TARGETS step6 DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/step.h" DESTINATION include)

function(do_test target arg result)
add_test(NAME Comp${arg} COMMAND ${target} ${arg})
set_tests_properties(Comp${arg}
		     PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()

do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is (-nan|nan|0)")
do_test(Tutorial 0.0001 "0.0001 is 0.01")
