add_library(mydir mysqrt.cpp MathFunctions.cpp)

target_include_directories(mydir 
	                   INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
