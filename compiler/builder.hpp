#ifndef rubicon_compiler_builder_hpp
#define rubicon_compiler_builder_hpp

#include <iostream>
#include <memory>
#include <string>
#include "dependencies.hpp"
#include "typeassignment.hpp"
#include "valueassignment.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Listener;
class TypeAssignment;
class Builder
{
public :
	Builder(std::string const &input_filename);
	~Builder();
	Builder(Builder const&) = delete;
	Builder& operator=(Builder const&) = delete;

	explicit operator bool () const { return okay_; }
	Builder& operator()(std::istream &is, bool produce_debug_output = false);

	Dependencies getTypeDependencies() const { return type_dependencies_; }
	Dependencies getValueDependencies() const { return value_dependencies_; }
	std::string getModuleName() const;
	std::vector< TypeAssignment > getTypeAssignments() const;
	std::vector< ValueAssignment > getValueAssignments() const;

private :
	void parse(std::istream &is);
	void postParseSanityCheck();
	void resolve();
	void scanDependencies();
	void produceDebugOutput() const;

	bool okay_ = true;
	std::string input_filename_;
	Listener *listener_ = nullptr;
	Dependencies type_dependencies_;
	Dependencies value_dependencies_;
};
}}}

#endif



