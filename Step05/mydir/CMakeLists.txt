add_library(mydir mysqrt.cpp MathFunctions.cpp)

target_include_directories(mydir 
	                   INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mydir tutorial_compiler_flags)

set(installable_libs mydir tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
