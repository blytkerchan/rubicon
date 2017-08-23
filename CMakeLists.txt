cmake_minimum_required(VERSION 2.6)
project(Rubicon)
set(VLINDER_USING_CXX11 1)
include(cmake/settings.cmake)
add_subdirectory(exceptions)
add_executable(poc-real
	tests/poc-real.cpp
	)
target_link_libraries(poc-real exceptions)
