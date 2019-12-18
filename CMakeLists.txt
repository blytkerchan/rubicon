cmake_minimum_required(VERSION 3.10)
project(Rubicon VERSION 0.2.00)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(cmake/settings.cmake)
include(GNUInstallDirs)

if (WIN32)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
endif()
find_package(Boost REQUIRED COMPONENTS program_options filesystem system)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${BOOST_LIBRARYDIR})

if (NOT WIN32)
	set(CPACK_PACKAGE_NAME rubicon)
	set(CPACK_PACKAGE_VENDOR "Vlinder Software")
	set(CPACK_PACKAGE_CONTACT "Ronald Landheer-Cieslak <rlc@vlinder.ca>")
	set(CPACK_PACKAGE_VERSION_MAJOR 0)
	set(CPACK_PACKAGE_VERSION_MINOR 2)
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
endif()

enable_testing()

if (WIN32)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /FC")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FC")
endif()

if (CMAKE_COMPILER_IS_GNUCC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-psabi -Werror")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-psabi -Werror")
endif()

if (WIN32)
	include_directories(
		${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src
		${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/atn
		${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/dfa
		${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/misc
		${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/support
		${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/tree
		${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/tree/pattern
		${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/tree/xpath
		)
	file(GLOB libantlrcpp_SRC
		"${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/*.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/atn/*.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/dfa/*.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/misc/*.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/support/*.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/tree/*.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/tree/pattern/*.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/antlr4/runtime/src/tree/xpath/*.cpp"
		)
	add_library(antlr4_shared SHARED ${libantlrcpp_SRC})
	add_library(antlr4_static STATIC ${libantlrcpp_SRC})
	set(extra_share_compile_flags "-DANTLR4CPP_EXPORTS -MP /wd4251")
	set(extra_static_compile_flags "-DANTLR4CPP_STATIC -MP")
	set(disabled_compile_warnings "/wd4251")
	set_target_properties(antlr4_shared
		PROPERTIES	COMPILE_FLAGS "${disabled_compile_warnings} ${extra_share_compile_flags}"
		)
	set_target_properties(antlr4_static
		PROPERTIES	COMPILE_FLAGS "${disabled_compile_warnings} ${extra_static_compile_flags}"
		)
	add_custom_target(antlr4-build)
else()
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
endif()

add_subdirectory(exceptions)
add_subdirectory(tracing)
add_executable(poc-real
	tests/poc-real.cpp
	)
target_link_libraries(poc-real exceptions rubicon)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

if (NOT WIN32)
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
else()
	add_custom_target(preproc-grammar)
	add_custom_target(compiler-grammar)
endif()

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
if (NOT WIN32)
	foreach(src_file ${preproc-GENERATED_SRC})
		set_source_files_properties(
			${src_file}
			PROPERTIES GENERATED TRUE
			)
	endforeach()
endif()
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
	if (NOT WIN32)
		set_source_files_properties(
			${src_file}
			PROPERTIES GENERATED TRUE
			)
	endif()
endforeach()

set(preproc-SRC
	${PROJECT_SOURCE_DIR}/preprocessor/listener.cpp
	${PROJECT_SOURCE_DIR}/preprocessor/listener.hpp
	${PROJECT_SOURCE_DIR}/preprocessor/preprocessor.cpp
	${PROJECT_SOURCE_DIR}/preprocessor/preprocessor.hpp
	${preproc-GENERATED_SRC}
	)

if (CMAKE_COMPILER_IS_GNUCC)
	foreach(src_file ${preproc-SRC})
		set_source_files_properties(
			${src_file}
			PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable -Wno-attributes"
			)
	endforeach()
endif()
set(compiler-SRC
	${PROJECT_SOURCE_DIR}/compiler/anytype.cpp
	${PROJECT_SOURCE_DIR}/compiler/anytype.hpp
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
	${PROJECT_SOURCE_DIR}/compiler/definedtyperesolutionvisitor.cpp
	${PROJECT_SOURCE_DIR}/compiler/definedtyperesolutionvisitor.hpp
	${PROJECT_SOURCE_DIR}/compiler/definedvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/dependencies.cpp
	${PROJECT_SOURCE_DIR}/compiler/dependencies.hpp
	${PROJECT_SOURCE_DIR}/compiler/directory.cpp
	${PROJECT_SOURCE_DIR}/compiler/directory.hpp
	${PROJECT_SOURCE_DIR}/compiler/embeddedpdvvalue.hpp
	${PROJECT_SOURCE_DIR}/compiler/enumeratedtype.cpp
	${PROJECT_SOURCE_DIR}/compiler/enumeratedtype.hpp
	${PROJECT_SOURCE_DIR}/compiler/enumeratedvalue.cpp
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
	${PROJECT_SOURCE_DIR}/compiler/objectidentifiervalue.cpp
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
if (CMAKE_COMPILER_IS_GNUCC)
	foreach(src_file ${compiler-SRC})
		set_source_files_properties(
			${src_file}
			PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable -Wno-attributes"
			)
	endforeach()
endif()

add_executable(asn1p 
	${PROJECT_SOURCE_DIR}/asn1p.cpp
	${preproc-SRC}
	)
add_dependencies(asn1p preproc-grammar antlr4-build)
if (WIN32)
	target_link_libraries(asn1p antlr4_shared ${Boost_PROGRAM_OPTIONS_LIBRARY} exceptions tracing)
else()
	target_link_libraries(asn1p libantlr4-runtime.a ${Boost_PROGRAM_OPTIONS_LIBRARY} exceptions tracing)
endif()
add_executable(asn1c
	${PROJECT_SOURCE_DIR}/asn1c.cpp
	${compiler-SRC}
	${preproc-SRC}
	)
add_dependencies(asn1c compiler-grammar preproc-grammar antlr4-build)
if (WIN32)
	target_link_libraries(asn1c antlr4_shared ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} exceptions tracing)
else()
	target_link_libraries(asn1c libantlr4-runtime.a ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} exceptions tracing)
endif()
if (CMAKE_COMPILER_IS_GNUCC)
	set_source_files_properties(
		${PROJECT_SOURCE_DIR}/asn1c.cpp
		PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual -Wno-shadow -Wno-unused-but-set-variable -Wno-attributes"
		)
endif()

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
	runtime/objectidentifier.cpp
	runtime/objectidentifier.hpp
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
	EXPORT RubiconTargets
	RUNTIME DESTINATION bin
	)
install(
	TARGETS rubicon
	EXPORT RubiconTargets
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	INCLUDES DESTINATION include
	)
install(
	DIRECTORY runtime/
	DESTINATION include/rubicon
	FILES_MATCHING PATTERN "*.hpp"
	)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/rubicon/rubicon-config-version.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

export(EXPORT RubiconTargets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/rubicon/rubicon-targets.cmake"
	NAMESPACE Vlinder::
)
configure_file(rubicon-config.cmake "${CMAKE_CURRENT_BINARY_DIR}/rubicon/rubicon-config.cmake"
	COPYONLY
)

set(ConfigPackageLocation lib/cmake/rubicon)
install(EXPORT RubiconTargets
	FILE rubicon-targets.cmake
	NAMESPACE Vlinder::
	DESTINATION ${ConfigPackageLocation}
)
install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/rubicon/rubicon-config.cmake" "${CMAKE_CURRENT_BINARY_DIR}/rubicon/rubicon-config-version.cmake"
	DESTINATION ${ConfigPackageLocation}
	COMPONENT Devel
)
target_include_directories(rubicon INTERFACE "$<INSTALL_INTERFACE:include>")

file(GLOB TEST_RUBICON_SOURCES tests/*.test.cpp)

add_executable(test_rubicon
	${TEST_RUBICON_SOURCES}
	tests/catch.hpp
	tests/main.cpp
	)
if (WIN32)
	set_target_properties(test_rubicon PROPERTIES COMPILE_FLAGS "/wd4805")
endif()
target_link_libraries(test_rubicon rubicon)
add_test(test_rubicon test_rubicon)

