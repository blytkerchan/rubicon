#ifndef vlinder_rubicon_compiler_valueassignment_hpp
#define vlinder_rubicon_compiler_valueassignment_hpp

#include "value.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
	struct ValueAssignment
	{
		ValueAssignment(std::string const &name, std::shared_ptr< Value > const &value)
			: name_(name)
			, value_(value)
		{ /* no-op */ }

		std::string getName() const { return name_; }
		std::set< std::string > getDependencies() const { return value_->getDependencies(); }

		std::string name_;
		std::shared_ptr< Value > value_;
	};
}}}

#endif
