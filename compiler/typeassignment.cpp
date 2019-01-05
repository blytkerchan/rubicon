#include "typeassignment.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
void TypeAssignment::generateCopyConstructorImplementation(std::ostream &os) const
{
	if (hasOptionalMembers())
	{
		os << getName() << "::" << getName() << "(" << getName() << " const &other)\n{\n";
		type_descriptor_->generateCopyConstructorImplementation(os);
		os << "}\n";
	}
	else
	{ /* no optional members - default copy constructor */ }
}
void TypeAssignment::generateAlternateConstructorImplementations(std::ostream &os) const
{
	type_descriptor_->generateAlternateConstructorImplementations(os, name_);
}
void TypeAssignment::generateDestructorImplementation(std::ostream &os) const
{
	if (hasOptionalMembers())
	{
		os << getName() << "::~" << getName() << "()\n{\n";
		type_descriptor_->generateDestructorImplementation(os);
		os << "}\n";
	}
	else
	{ /* no optional members - default copy constructor */ }
}
void TypeAssignment::generateAssignmentOperatorImplementation(std::ostream &os) const
{
	if (hasOptionalMembers())
	{
		os <<
			getName() << "& " << getName() << "::operator=(" << getName() << " const &other)\n"
			"{\n"
			"\t" << getName() << " temp(other);\n"
			"\treturn swap(temp);\n"
			"}\n";
	}
	else
	{ /* no optional members - default copy constructor */ }
}
void TypeAssignment::generateSwapparatorImplementation(std::ostream &os) const
{
	os <<
		getName() << "& " << getName() << "::swap(" << getName() << " &other)\n"
		"{\n"
		;
	type_descriptor_->generateSwapparatorImplementation(os);
	os <<
		"\treturn *this;\n"
		"}\n"
		;
}
void TypeAssignment::generateGetterAndSetterImplementations(std::ostream &ofs) const
{
	type_descriptor_->generateGetterAndSetterImplementations(getName(), ofs);
}
void TypeAssignment::generateEncodeImplementation(std::ostream &ofs) const
{
	ofs << "void " << getName() << "::encode(DEREncoder &der_encoder) const\n";
	ofs << "{\n";
	type_descriptor_->generateEncodeImplementation(ofs);
	ofs << "}\n";
}
void TypeAssignment::generateCompareImplementation(std::ostream &ofs) const
{
	ofs << "int " << getName() << "::compare(" << getName() << " const &other) const\n";
	ofs << "{\n";
	type_descriptor_->generateCompareImplementation(ofs);
	ofs << "}\n";
}
}}}


