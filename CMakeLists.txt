cmake_minimum_required(VERSION 3.10)
project(Rubicon VERSION 1.0.00)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(cmake/settings.cmake)

find_package(Boost REQUIRED COMPONENTS program_options filesystem system)

set(CPACK_PACKAGE_NAME rubicon)
set(CPACK_PACKAGE_VENDOR "Vlinder Software")
set(CPACK_PACKAGE_CONTACT "Ronald Landheer-Cieslak <rlc@vlinder.ca>")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 00)
set(CPACK_PACKAGE_DESCRIPTION "ASN1 compiler, code generator, runtime library")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ASN1 compiler, code generator, runtime library")
set(CPACK_PACKAGE_DESCRIPTION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/CPack.Description.txt)
set(CPACK_PACKAGE_HOMEPAGE_URL "http://vlinder.ca")
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md)
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libboost-filesystem${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION},libboost-program-options${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION}, libboost-system${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION}")
set(CPACK_GENERATOR DEB)
include(CPack)

enable_testing()

include(ExternalProject)
ExternalProject_Add(antlr4
	DOWNLOAD_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/gen -d
	INSTALL_COMMAND ""
	STEP_TARGETS build
	)
ExternalProject_Get_property(antlr4 SOURCE_DIR)
include_directories(${SOURCE_DIR}/runtime/src)
ExternalProject_Get_property(antlr4 BINARY_DIR)
link_directories(${BINARY_DIR}/../antlr4/dist)

add_subdirectory(exceptions)
add_subdirectory(tracing)
add_executable(poc-real
	tests/poc-real.cpp
	)
target_link_libraries(poc-real exceptions rubicon)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

add_custom_command(OUTPUT preproc-grammar-tag
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/gen -p
	COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/preproc-grammar-tag
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	MAIN_DEPENDENCY preproc.g4
	VERBATIM
	)
add_custom_target(preproc-grammar DEPENDS preproc-grammar-tag)
add_custom_command(OUTPUT compiler-grammar-tag
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/gen -a
	COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/compiler-grammar-tag
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	MAIN_DEPENDENCY asn1.g4
	VERBATIM
	)
add_custom_target(compiler-grammar DEPENDS compiler-grammar-tag)

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
	${PROJECT_SOURCE_DIR}/preprocessor/listener.cpp
	${PROJECT_SOURCE_DIR}/preprocessor/listener.hpp
	${PROJECT_SOURCE_DIR}/preprocessor/preprocessor.cpp
	${PROJECT_SOURCE_DIR}/preprocessor/preprocessor.hpp
	${preproc-GENERATED_SRC}
	)
foreach(src_file ${preproc-SRC})
	set_source_files_properties(
		${src_file}
		PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable -Wno-attributes"
		)
endforeach()
set(compiler-SRC
	${PROJECT_SOURCE_DIR}/compiler/arcidentifier.hpp
	${PROJECT_SOURCE_DIR}/compiler/autotagvisitor.cpp
	${PROJECT_SOURCE_DIR}/compiler/autotagvisitor.hpp
	${PROJECT_SOURCE_DIR}/compiler/bitstringtype.cpp
	${PROJECT_SOURCE_DIR}/compiler/bitstringtype.hpp
	${PROJECT_SOURCE_DIR}/compiler/bitstringvalue.cpp
	${PROJECT_SOURCE_DIR}/compiler/bitstringvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/booleantype.cpp
	${PROJECT_SOURCE_DIR}/compiler/booleantype.hpp
	${PROJECT_SOURCE_DIR}/compiler/booleanvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/builder.cpp
	${PROJECT_SOURCE_DIR}/compiler/builder.hpp
	${PROJECT_SOURCE_DIR}/compiler/characterstringtype.cpp
	${PROJECT_SOURCE_DIR}/compiler/characterstringtype.hpp
	${PROJECT_SOURCE_DIR}/compiler/choicetype.cpp
	${PROJECT_SOURCE_DIR}/compiler/choicetype.hpp
	${PROJECT_SOURCE_DIR}/compiler/choicevalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/componentsofresolutionvisitor.cpp
	${PROJECT_SOURCE_DIR}/compiler/componentsofresolutionvisitor.hpp
	${PROJECT_SOURCE_DIR}/compiler/constrainedtype.cpp
	${PROJECT_SOURCE_DIR}/compiler/constrainedtype.hpp
	${PROJECT_SOURCE_DIR}/compiler/constraint.hpp
	${PROJECT_SOURCE_DIR}/compiler/definedtype.cpp
	${PROJECT_SOURCE_DIR}/compiler/definedtype.hpp
	${PROJECT_SOURCE_DIR}/compiler/definedvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/dependencies.cpp
	${PROJECT_SOURCE_DIR}/compiler/dependencies.hpp
	${PROJECT_SOURCE_DIR}/compiler/directory.cpp
	${PROJECT_SOURCE_DIR}/compiler/directory.hpp
	${PROJECT_SOURCE_DIR}/compiler/embeddedpdvvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/enumeratedtype.cpp
	${PROJECT_SOURCE_DIR}/compiler/enumeratedtype.hpp
	${PROJECT_SOURCE_DIR}/compiler/enumeratedvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/errorlistener.cpp
	${PROJECT_SOURCE_DIR}/compiler/errorlistener.hpp
	${PROJECT_SOURCE_DIR}/compiler/externaltypereference.cpp
	${PROJECT_SOURCE_DIR}/compiler/externaltypereference.hpp
	${PROJECT_SOURCE_DIR}/compiler/generalizedtimetype.cpp
	${PROJECT_SOURCE_DIR}/compiler/generalizedtimetype.hpp
	${PROJECT_SOURCE_DIR}/compiler/generator.cpp
	${PROJECT_SOURCE_DIR}/compiler/generator.hpp
	${PROJECT_SOURCE_DIR}/compiler/integertype.cpp
	${PROJECT_SOURCE_DIR}/compiler/integertype.hpp
	${PROJECT_SOURCE_DIR}/compiler/integervalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/irivalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/listener.cpp
	${PROJECT_SOURCE_DIR}/compiler/listener.hpp
	${PROJECT_SOURCE_DIR}/compiler/modulenamemappings.cpp
	${PROJECT_SOURCE_DIR}/compiler/modulenamemappings.hpp
	${PROJECT_SOURCE_DIR}/compiler/namednumber.hpp
	${PROJECT_SOURCE_DIR}/compiler/namedtype.cpp
	${PROJECT_SOURCE_DIR}/compiler/namedtype.hpp
	${PROJECT_SOURCE_DIR}/compiler/namedvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/nullvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/objectdescriptortype.cpp
	${PROJECT_SOURCE_DIR}/compiler/objectdescriptortype.hpp
	${PROJECT_SOURCE_DIR}/compiler/objectidentifier.hpp
	${PROJECT_SOURCE_DIR}/compiler/objectidentifiervalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/octetstringvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/oidcomponent.hpp
	${PROJECT_SOURCE_DIR}/compiler/oidvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/primitivetype.cpp
	${PROJECT_SOURCE_DIR}/compiler/primitivetype.hpp
	${PROJECT_SOURCE_DIR}/compiler/quadruple.hpp
	${PROJECT_SOURCE_DIR}/compiler/realvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/resolver.cpp
	${PROJECT_SOURCE_DIR}/compiler/resolver.hpp
	${PROJECT_SOURCE_DIR}/compiler/restrictedcharacterstringvalue.cpp
	${PROJECT_SOURCE_DIR}/compiler/restrictedcharacterstringvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/selectiontype.cpp
	${PROJECT_SOURCE_DIR}/compiler/selectiontype.hpp
	${PROJECT_SOURCE_DIR}/compiler/sequenceofvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/sequenceorsetoftype.cpp
	${PROJECT_SOURCE_DIR}/compiler/sequenceorsetoftype.hpp
	${PROJECT_SOURCE_DIR}/compiler/sequenceorsettype.cpp
	${PROJECT_SOURCE_DIR}/compiler/sequenceorsettype.hpp
	${PROJECT_SOURCE_DIR}/compiler/sequencevalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/setofvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/setvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/sourcelocation.hpp
	${PROJECT_SOURCE_DIR}/compiler/statemachine.hpp
	${PROJECT_SOURCE_DIR}/compiler/statemachinebuilder.cpp
	${PROJECT_SOURCE_DIR}/compiler/statemachinebuilder.hpp
	${PROJECT_SOURCE_DIR}/compiler/taggedtype.cpp
	${PROJECT_SOURCE_DIR}/compiler/taggedtype.hpp
	${PROJECT_SOURCE_DIR}/compiler/tag.cpp
	${PROJECT_SOURCE_DIR}/compiler/tag.hpp
	${PROJECT_SOURCE_DIR}/compiler/tagresolutionvisitor.cpp
	${PROJECT_SOURCE_DIR}/compiler/tagresolutionvisitor.hpp
	${PROJECT_SOURCE_DIR}/compiler/tuple.hpp
	${PROJECT_SOURCE_DIR}/compiler/typeassignment.cpp
	${PROJECT_SOURCE_DIR}/compiler/typeassignment.hpp
	${PROJECT_SOURCE_DIR}/compiler/typedescriptor.cpp
	${PROJECT_SOURCE_DIR}/compiler/typedescriptor.hpp
	${PROJECT_SOURCE_DIR}/compiler/typewithconstraint.cpp
	${PROJECT_SOURCE_DIR}/compiler/typewithconstraint.hpp
	${PROJECT_SOURCE_DIR}/compiler/unknowntype.cpp
	${PROJECT_SOURCE_DIR}/compiler/unknowntype.hpp
	${PROJECT_SOURCE_DIR}/compiler/unrestrictedcharacterstringvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/utctimetype.cpp
	${PROJECT_SOURCE_DIR}/compiler/utctimetype.hpp
	${PROJECT_SOURCE_DIR}/compiler/valueassignment.cpp
	${PROJECT_SOURCE_DIR}/compiler/valueassignment.hpp
	${PROJECT_SOURCE_DIR}/compiler/value.hpp
	${PROJECT_SOURCE_DIR}/compiler/versionedtypelist.hpp
	${compiler-GENERATED_SRC}
	)
foreach(src_file ${compiler-SRC})
	set_source_files_properties(
		${src_file}
		PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable -Wno-attributes"
		)
endforeach()

add_executable(asn1p 
	${PROJECT_SOURCE_DIR}/asn1p.cpp
	${preproc-SRC}
	)
add_dependencies(asn1p preproc-grammar antlr4-build)
target_link_libraries(asn1p libantlr4-runtime.a ${Boost_PROGRAM_OPTIONS_LIBRARY} exceptions tracing)
add_executable(asn1c
	${PROJECT_SOURCE_DIR}/asn1c.cpp
	${compiler-SRC}
	${preproc-SRC}
	)
add_dependencies(asn1c compiler-grammar preproc-grammar antlr4-build)
target_link_libraries(asn1c libantlr4-runtime.a ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} exceptions tracing)
set_source_files_properties(
	${PROJECT_SOURCE_DIR}/asn1c.cpp
	PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable -Wno-attributes"
	)

add_library(rubicon SHARED
	runtime/bitstring.cpp
	runtime/bitstring.hpp
	runtime/boolean.cpp
	runtime/boolean.hpp
	runtime/decoder.cpp
	runtime/decoder.hpp
	runtime/derdecoder.cpp
	runtime/derdecoder.hpp
	runtime/derencoder.hpp
	runtime/details/any.cpp
	runtime/details/any.hpp
	runtime/details/buffer.hpp
	runtime/integer.cpp
	runtime/integer.hpp
	runtime/null.hpp
	runtime/octetstring.cpp
	runtime/octetstring.hpp
	runtime/real.cpp
	runtime/real.hpp
	)
target_link_libraries(rubicon exceptions)
set_target_properties(rubicon PROPERTIES SOVERSION 1)
set_target_properties(rubicon PROPERTIES VERSION ${PROJECT_VERSION})
install(
	TARGETS asn1c asn1p
	RUNTIME DESTINATION bin
	)
install(
	TARGETS rubicon
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	DESTINATION lib
	)
install(
	DIRECTORY runtime/
	DESTINATION include/rubicon
	FILES_MATCHING PATTERN "*.hpp"
	)
add_executable(test_rubicon
	tests/bitstring.cpp
	tests/catch.hpp
	tests/derdecoder.cpp
	tests/derencoder.cpp
	tests/main.cpp
	)
target_link_libraries(test_rubicon rubicon)
add_test(test_rubicon test_rubicon)

