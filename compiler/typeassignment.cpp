#include "typeassignment.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
void TypeAssignment::generateHeader(std::ostream &os) const
{
	os <<
		"class " << name_ << "\n"
		"{\n"
		"public :\n"
		"\tvoid encode(Vlinder::Rubicon::DEREncoder &der_encoder);\n"
		"protected :\n"
		;
	type_descriptor_->generateEventHandlers(os);
	os <<
		"\n"
		"private :\n"
		;
	type_descriptor_->generateDataMembers(os);
	os <<
		"};\n"
		;
}
void TypeAssignment::generateImplementation(std::ostream &os) const
{
	os <<
		"void " << name_ << "::encode(Vlinder::Rubicon::DEREncoder &der_encoder)\n"
		"{\n"
		;
	type_descriptor_->generateEncodeImplementation(os);
	os <<
		"}\n"
		;
}
}}}


