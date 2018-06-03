#ifndef rubicon_compiler_builder_hpp
#define rubicon_compiler_builder_hpp

#include <iostream>
#include <memory>
#include <string>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Listener;
class TypeAssignment;
class Builder
{
public :
	Builder(std::string const &output_directory_name, std::string const &input_filename, std::string const &namespace_prefix, std::string const &namespace_suffix);
	~Builder();
	Builder(Builder const&) = delete;
	Builder& operator=(Builder const&) = delete;

	explicit operator bool () const { return okay_; }
	Builder& operator()(std::istream &is, bool output_dependencies);

private :
	void parse(std::istream &is);
	void postParseSanityCheck();
	void outputDependencies() const;
	void createOutputDirectory();
	void outputTypes();
	void generateHeader(TypeAssignment const &type_assignment);
	void generateImplementation(TypeAssignment const &type_assignment);

	bool okay_ = true;
	std::string input_filename_;
	std::string namespace_prefix_;
	std::string namespace_suffix_;
	Listener *listener_ = nullptr;
	std::string output_directory_name_;
};
}}}

#endif



