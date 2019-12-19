#include "typeassignment.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
void TypeAssignment::generateCopyConstructorImplementation(ostream &os) const
{
	if (hasOptionalMembers())
	{
		os << getName() << "::" << getName() << "(" << getName() << " const &other)\n";
        type_descriptor_->generateCopyConstructorInitializers(os);
        os << "{\n";
		type_descriptor_->generateCopyConstructorImplementation(os);
		os << "}\n";
	}
	else
	{ /* no optional members - default copy constructor */ }
}
void TypeAssignment::generateAlternateConstructorImplementations(ostream &os) const
{
	type_descriptor_->generateAlternateConstructorImplementations(os, name_);
}
void TypeAssignment::generateDestructorImplementation(ostream &os) const
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
void TypeAssignment::generateAssignmentOperatorImplementation(ostream &os) const
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
void TypeAssignment::generateSwapparatorImplementation(ostream &os) const
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
void TypeAssignment::generateGetterAndSetterImplementations(ostream &ofs) const
{
	type_descriptor_->generateGetterAndSetterImplementations(getName(), ofs);
}
void TypeAssignment::generateEncodeImplementation(ostream &ofs) const
{
	ofs << "void " << getName() << "::encode(DEREncoder &der_encoder) const\n";
	ofs << "{\n";
	type_descriptor_->generateEncodeImplementation(ofs);
	ofs << "}\n";
}
void TypeAssignment::generateCompareImplementation(ostream &ofs) const
{
	ofs << "int " << getName() << "::compare(" << getName() << " const &other) const\n";
	ofs << "{\n";
	type_descriptor_->generateCompareImplementation(ofs);
	ofs << "}\n";
}
}}}


