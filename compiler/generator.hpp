#ifndef rubicon_compiler_generator_hpp
#define rubicon_compiler_generator_hpp

#include <string>
#include <vector>
#include <boost/filesystem/path.hpp>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Builder;
class TypeAssignment;
class ValueAssignment;
class Generator
{
public :
	Generator(std::string const &output_directory_name, std::string const &namespace_prefix, std::string const &namespace_suffix);
	~Generator();
	Generator(Generator const&) = delete;
	Generator& operator=(Generator const&) = delete;

	explicit operator bool () const { return okay_; }
	Generator& operator()(Builder const &builder, bool output_dependencies, std::string const &rubicon_include_directory);

	std::string getNamespaceName() const { return namespace_name_; }
	std::string getOutputDirectoryName() const { return output_directory_name_; }

private :
	void setNamespaceName();
	void createOutputDirectory();
	void outputDependencies() const;
	void outputTypes();
	void outputValues();
	void generateHeader(TypeAssignment const &type_assignment);
	void generateHeader(ValueAssignment const &value_assignment);
	void generateImplementation(TypeAssignment const &type_assignment);
	void generateImplementation(ValueAssignment const &value_assignment);
	void generateDecoder();
	void generateDecoderHeader();
	void generateDecoderImplementation();
	void generateBuilderDeclaration(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateBuilderImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateCMakeLists() const;

	void generatePreamble(std::ostream &ofs) const;
	void openIncludeGuard(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void openIncludeGuard(std::ostream &ofs, ValueAssignment const &value_assignment) const;
	void closeIncludeGuard(std::ostream &ofs) const;
	void generateHeaderIncludeDirectives(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateHeaderIncludeDirectives(std::ostream &ofs, ValueAssignment const &value_assignment) const;
	void generateHeaderForwardDeclarations(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateImplementationIncludeDirectives(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateImplementationUsingDirectives(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateImplementationIncludeDirectives(std::ostream &ofs, ValueAssignment const &value_assignment) const;
	void generateImplementationUsingDirectives(std::ostream &ofs, ValueAssignment const &value_assignment) const;
	void openNamespace(std::ostream &ofs) const;
	void closeNamespace(std::ostream &ofs) const;
	void openClassDefinition(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void closeClassDefinition(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generatePublicDefinitionSection(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generatePublicStaticMembers(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateAlternateConstructorImplementations(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generatePrivateDefinitionSection(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateCopyConstructorImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateDestructorImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateAssignmentOperatorImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateSwapparatorImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateGetterAndSetterImplementations(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateDeclaration(std::ostream &os, ValueAssignment const &value_assignment) const;
	void generateDefinition(std::ostream &os, ValueAssignment const &value_assignment) const;
	void generateComparisonOperatorDeclarations(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateCompareImplementation(std::ostream &ofs, TypeAssignment const &type_assignment) const;
	void generateComparisonOperatorDefinitions(std::ostream &ofs, TypeAssignment const &type_assignment) const;

	bool okay_ = true;
	std::string output_directory_name_;
	std::string namespace_prefix_;
	std::string namespace_suffix_;
	std::string namespace_name_;
	Builder const *builder_ = nullptr;
	std::vector< boost::filesystem::path > generated_files_;
    std::string rubicon_include_directory_;
};
}}}

#endif



