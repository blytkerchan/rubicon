cmake_minimum_required(VERSION 2.6)
project(Rubicon)
set(VLINDER_USING_CXX14 1)
include(cmake/settings.cmake)
include_directories(/usr/local/include)
include_directories(/usr/local/include/antlr4-runtime)
link_directories(/usr/local/lib)
add_subdirectory(exceptions)
add_subdirectory(tracing)
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
add_custom_target(compiler-grammar
	COMMAND java -Xmx500M -cp "/usr/local/lib/java/antlr-4.7-complete.jar:${CLASSPATH}" org.antlr.v4.Tool -visitor -Dlanguage=Cpp -o generated asn1.g4
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
set(compiler-GENERATED_SRC
	${PROJECT_SOURCE_DIR}/generated/asn1BaseListener.cpp
	${PROJECT_SOURCE_DIR}/generated/asn1BaseListener.h
	${PROJECT_SOURCE_DIR}/generated/asn1BaseVisitor.cpp
	${PROJECT_SOURCE_DIR}/generated/asn1BaseVisitor.h
	${PROJECT_SOURCE_DIR}/generated/asn1Lexer.cpp
	${PROJECT_SOURCE_DIR}/generated/asn1Lexer.h
	${PROJECT_SOURCE_DIR}/generated/asn1Lexer.tokens
	${PROJECT_SOURCE_DIR}/generated/asn1Listener.cpp
	${PROJECT_SOURCE_DIR}/generated/asn1Listener.h
	${PROJECT_SOURCE_DIR}/generated/asn1Parser.cpp
	${PROJECT_SOURCE_DIR}/generated/asn1Parser.h
	${PROJECT_SOURCE_DIR}/generated/asn1Visitor.cpp
	${PROJECT_SOURCE_DIR}/generated/asn1Visitor.h
	)
foreach(src_file ${compiler-GENERATED_SRC})
	set_source_files_properties(
		${src_file}
		PROPERTIES GENERATED TRUE
		)
endforeach()

set(preproc-SRC
	${PROJECT_SOURCE_DIR}/asn1p.cpp
	${PROJECT_SOURCE_DIR}/preprocessor/listener.cpp
	${PROJECT_SOURCE_DIR}/preprocessor/listener.hpp
	${preproc-GENERATED_SRC}
	)
foreach(src_file ${preproc-SRC})
	set_source_files_properties(
		${src_file}
		PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable -Wno-attributes"
		)
endforeach()
set(compiler-SRC
	${PROJECT_SOURCE_DIR}/asn1c.cpp
	${PROJECT_SOURCE_DIR}/compiler/listener.cpp
	${PROJECT_SOURCE_DIR}/compiler/listener.hpp
	${compiler-GENERATED_SRC}
	)
foreach(src_file ${compiler-SRC})
	set_source_files_properties(
		${src_file}
		PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable -Wno-attributes"
		)
endforeach()

add_executable(asn1p ${preproc-SRC})
add_dependencies(asn1p preproc-grammar)
target_link_libraries(asn1p antlr4-runtime boost_program_options exceptions tracing)

add_executable(asn1c ${compiler-SRC})
add_dependencies(asn1c compiler-grammar)
target_link_libraries(asn1c antlr4-runtime boost_program_options exceptions tracing)


