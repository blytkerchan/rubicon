#ifndef rubicon_compiler_generator_hpp
#define rubicon_compiler_generator_hpp

#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Builder;
class TypeAssignment;
class Generator
{
public :
	Generator(std::string const &output_directory_name, std::string const &namespace_prefix, std::string const &namespace_suffix);
	~Generator();
	Generator(Generator const&) = delete;
	Generator& operator=(Generator const&) = delete;

	explicit operator bool () const { return okay_; }
	Generator& operator()(Builder const &builder, bool output_dependencies);

	std::string getNamespaceName() const { return namespace_name_; }
	std::string getOutputDirectoryName() const { return output_directory_name_; }

private :
	void setNamespaceName();
	void createOutputDirectory();
	void outputDependencies() const;
	void outputTypes();
	void generateHeader(TypeAssignment const &type_assignment);
	void generateImplementation(TypeAssignment const &type_assignment);
	void generatePreamble(std::ostream &ofs);
	void openIncludeGuard(std::ostream &ofs, TypeAssignment const &type_assignment);
	void closeIncludeGuard(std::ostream &ofs);
	void generateHeaderIncludeDirectives(std::ostream &ofs, TypeAssignment const &type_assignment);
	void generateImplementationIncludeDirectives(std::ostream &ofs, TypeAssignment const &type_assignment);
	void openNamespace(std::ostream &ofs, TypeAssignment const &type_assignment);
	void closeNamespace(std::ostream &ofs, TypeAssignment const &type_assignment);
	void openClassDefinition(std::ostream &ofs, TypeAssignment const &type_assignment);
	void closeClassDefinition(std::ostream &ofs, TypeAssignment const &type_assignment);
	void generatePublicDefinitionSection(std::ostream &ofs, TypeAssignment const &type_assignment);
	void generatePrivateDefinitionSection(std::ostream &ofs, TypeAssignment const &type_assignment);
	void generateCopyConstructorImplementation(std::ostream &ofs, TypeAssignment const &type_assignment);
	void generateDestructorImplementation(std::ostream &ofs, TypeAssignment const &type_assignment);
	void generateAssignmentOperatorImplementation(std::ostream &ofs, TypeAssignment const &type_assignment);

	bool okay_ = true;
	std::string output_directory_name_;
	std::string namespace_prefix_;
	std::string namespace_suffix_;
	std::string namespace_name_;
	Builder const *builder_ = nullptr;
};
}}}

#endif



