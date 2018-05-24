#ifndef rubicon_compiler_builder_hpp
#define rubicon_compiler_builder_hpp

#include <string>
#include <iostream>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Builder
{
public :
	Builder(std::ostream *out, std::string const &input_filename, std::string const &namespace_prefix, std::string const &namespace_suffix);

	explicit operator bool () const { return okay_; }
	Builder& operator()();

private :
	bool okay_ = true;
	std::ostream *out_ = nullptr;
	std::string input_filename_;
	std::string namespace_prefix_;
	std::string namespace_suffix_;
};
}}}

#endif



