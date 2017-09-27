cmake_minimum_required(VERSION 2.6)
project(Rubicon)
set(VLINDER_USING_CXX14 1)
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

add_custom_target(preproc-grammar
	COMMAND java -Xmx500M -cp "/usr/local/lib/java/antlr-4.7-complete.jar:${CLASSPATH}" org.antlr.v4.Tool -Dlanguage=Cpp -o generated preproc.g4
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	SOURCES preproc.g4
	)
add_custom_target(asn1-grammar
	COMMAND java -Xmx500M -cp "/usr/local/lib/java/antlr-4.7-complete.jar:${CLASSPATH}" org.antlr.v4.Tool -Dlanguage=Cpp -o generated asn1.g4
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	SOURCES preproc.g4
	)

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
set(preproc-SRC
	${PROJECT_SOURCE_DIR}/preproc.cpp
	${PROJECT_SOURCE_DIR}/preprocessor/listener.cpp
	${PROJECT_SOURCE_DIR}/preprocessor/listener.hpp
	${preproc-GENERATED_SRC}
	)
foreach(src_file ${preproc-SRC})
	set_source_files_properties(
		${src_file}
		PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable"
		)
endforeach()

add_executable(preproc ${preproc-SRC})
add_dependencies(preproc preproc-grammar)
target_link_libraries(preproc antlr4-runtime boost_program_options exceptions)


