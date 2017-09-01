cmake_minimum_required(VERSION 2.6)
project(Rubicon)
set(VLINDER_USING_CXX11 1)
include(cmake/settings.cmake)
include_directories(/usr/local/include)
include_directories(/usr/local/include/antlr4-runtime)
link_directories(/usr/local/lib)
add_subdirectory(exceptions)
add_executable(poc-real
	tests/poc-real.cpp
	)
target_link_libraries(poc-real exceptions)

find_package(Boost REQUIRED COMPONENTS program_options)

set(preproc-GENERATED_SRC 
	${PROJECT_SOURCE_DIR}/generated/preprocBaseListener.cpp
	${PROJECT_SOURCE_DIR}/generated/preprocBaseListener.h
	${PROJECT_SOURCE_DIR}/generated/preprocLexer.cpp
	${PROJECT_SOURCE_DIR}/generated/preprocLexer.h
	${PROJECT_SOURCE_DIR}/generated/preprocListener.cpp
	${PROJECT_SOURCE_DIR}/generated/preprocListener.h
	${PROJECT_SOURCE_DIR}/generated/preprocParser.cpp
	${PROJECT_SOURCE_DIR}/generated/preprocParser.h
	)
foreach(src_file ${preproc-GENERATED_SRC})
	set_source_files_properties(
		${src_file}
		PROPERTIES GENERATED TRUE
		)
endforeach()
set(preproc-SRC ${PROJECT_SOURCE_DIR}/preproc.cpp ${preproc-GENERATED_SRC})
foreach(src_file ${preproc-SRC})
	set_source_files_properties(
		${src_file}
		PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable"
		)
endforeach()

add_executable(preproc ${preproc-SRC})
target_link_libraries(preproc antlr4-runtime boost_program_options exceptions)

