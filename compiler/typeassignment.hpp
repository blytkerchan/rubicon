#ifndef vlinder_rubicon_compiler_type_assignment_hpp
#define vlinder_rubicon_compiler_type_assignment_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
	struct TypeAssignment
	{
		TypeAssignment(std::string const &name, std::shared_ptr< TypeDescriptor > const &type_descriptor)
			: name_(name)
			, type_descriptor_(type_descriptor)
		{ /* no-op */ }

		std::string name_;
		std::shared_ptr< TypeDescriptor > type_descriptor_;
	};
}}}

#endif
