#ifndef rubicon_preprocessor_preprocessor_hpp
#define rubicon_preprocessor_preprocessor_hpp

#include <string>
#include <iostream>

namespace Vlinder { namespace Rubicon { namespace Preprocessor {
class Preprocessor
{
public :
	Preprocessor(std::string const &input_filename);

	Preprocessor& operator()(std::ostream *out);
	explicit operator bool () const;

private :
	std::string input_filename_;
	bool okay_ = true;
};
}}}

#endif

