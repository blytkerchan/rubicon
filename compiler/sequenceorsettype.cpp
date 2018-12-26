#include "sequenceorsettype.hpp"
#include <algorithm>
#include <stack>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void SequenceOrSetType::ComponentType::generateInstance(ostream &os, string const &instance_name) const
{
	os << "\t" << getTypeName() << " " << (isOptional() ? "*" : "") << instance_name << ";\n";
}
void SequenceOrSetType::NamedComponentType::generateHeaderGetterAndSetter(ostream &os) const
{
	string name(getName());
	name[0] = toupper(name[0]);
	os << "\t" << getTypeName() << ((isOptional() && !hasDefaultValue()) ? " const* " : " ") << "get" << name << "() const;\n";
	os << "\t" << "void set" << name << "(" << getTypeName() << " const &" << toVariableName(getName()) << ");\n";
}
void SequenceOrSetType::NamedComponentType::generateGetterImplementation(string const &type_name, ostream &os) const
{
	string name(getName());
	name[0] = toupper(name[0]);
	os <<
		getTypeName() << ((isOptional() && !hasDefaultValue()) ? " const* " : " ") << type_name <<  "::get" << name << "() const\n"
		"{\n"
		;
	if (isOptional() && hasDefaultValue())
	{
		os << "\treturn " << toMemberName(getName()) << " ? " << toMemberName(getName()) << " : " << default_value_->generateInstance() << "\n";
	}
	else
	{
		//TODO use the default value if the value is not set
		os << "\treturn " << toMemberName(getName()) << ";\n";
	}
	os << "}\n";
}
void SequenceOrSetType::NamedComponentType::generateSetterImplementation(string const &type_name, ostream &os) const
{
	string name(getName());
	name[0] = toupper(name[0]);
	os <<
		"void " << type_name <<  "::set" << name << "(" << getTypeName() << " const &" << toVariableName(getName()) << ")\n"
		"{\n"
		;
	if (isOptional())
	{
		os <<
			"\tusing namespace std;\n"
			"\tif (" << toMemberName(getName()) << ")\n"
			"\t{\n"
			"\t\t*" << toMemberName(getName()) << " = " << toVariableName(getName()) << ";\n"
			"\t}\n"
			"\telse\n"
			"\t{\n"
			"\t\t" << toMemberName(getName()) << " = new " << getTypeName() << "(" << toVariableName(getName()) << ");\n"
			"\t}\n"
			;
	}
	else
	{
		os <<
			"\t" << toMemberName(getName()) << " = " << toVariableName(getName()) << ";\n"
			;
	}
	os <<
		"}\n"
		;
}
void SequenceOrSetType::NamedComponentType::generateMemberDeclarations(ostream &os) const
{
	os << "\t" << getTypeName() << (isOptional() ? " *" : " ") << toMemberName(getName()) << ";\n";
}
/*static */string SequenceOrSetType::NamedComponentType::toVariableName(string const &name)
{
	string retval;
	for (char c : name)
	{
		if (c == tolower(c))
		{
			retval.append(1, c);
		}
		else
		{
			retval.append("_");
			retval.append(1, tolower(c));
		}
	}

	return retval;
}
/*static */string SequenceOrSetType::NamedComponentType::toMemberName(string const &name)
{
	return toVariableName(name) + "_";
}

/*virtual */set< string > SequenceOrSetType::getDependencies() const
{
	set< string > retval;

	for (auto type : component_types_)
	{
		auto deps(type->getDependencies());
		retval.insert(deps.begin(), deps.end());
	}

	return retval;
}
/*virtual */set< string > SequenceOrSetType::getStrongDependencies() const
{
	set< string > retval;

	for (auto type : component_types_)
	{
		auto deps(type->getStrongDependencies());
		retval.insert(deps.begin(), deps.end());
	}

	return retval;
}
/*virtual */set< string > SequenceOrSetType::getWeakDependencies() const
{
	set< string > retval;

	for (auto type : component_types_)
	{
		auto deps(type->getWeakDependencies());
		retval.insert(deps.begin(), deps.end());
	}

	return retval;
}
/*virtual */void SequenceOrSetType::generateEncodeImplementation(ostream &os) const/* override*/
{
//	os <<
//		"\tonStartEncoding(der_encoder);\n"
//		;
//	for (auto type : component_types_)
//	{
//		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
//		if (named_component_type)
//		{
//			os <<
//				"\tonEncode(der_encoder, false, \"" << named_component_type->getName() << "\");\n"
//				;
//			named_component_type->generateEncodeImplementation(os, toMemberName(named_component_type->getName()));
//			os <<
//				"\tonEncode(der_encoder, true, \"" << named_component_type->getName() << "\");\n"
//				;
//		}
//		else
//		{
//			throw logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
//		}
//	}
//	os <<
//		"\tonFinishEncoding(der_encoder);\n"
//		;
}
/*virtual */void SequenceOrSetType::generateEventHandlers(ostream &os) const/* override*/
{
	os <<
		"\t// called at the start of encoding this instance, before any members have been encoded\n"
		"\tvirtual void onStartEncoding(Vlinder::Rubicon::DEREncoder &der_encoder) {}\n"
		"\t// called at the end of encoding this instance, when all members have been encoded\n"
		"\tvirtual void onFinishEncoding(Vlinder::Rubicon::DEREncoder &der_encoder) {}\n"
		"\t// called before and after each member is encoded.\n"
		"\tvirtual void onEncode(Vlinder::Rubicon::DEREncoder &der_encoder, bool encoded, std::string const &name) {}\n"
		;
}
/*virtual */bool SequenceOrSetType::hasOptionalMembers() const/* override*/
{
	bool retval(false);
	for (auto component_type : component_types_)
	{
		retval |= component_type->isOptional();
	}	

	return retval;
}
/*virtual */void SequenceOrSetType::generateHeaderGettersAndSetters(ostream &os) const/* override*/
{
	for (auto type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
		if (named_component_type)
		{
			named_component_type->generateHeaderGetterAndSetter(os);
		}
		else
		{
			throw logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
		}
	}
}
/*virtual */void SequenceOrSetType::generateMemberDeclarations(ostream &os) const/* override*/
{
	for (auto type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
		if (named_component_type)
		{
			named_component_type->generateMemberDeclarations(os);
		}
		else
		{
			throw logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
		}
	}
}
/*virtual */void SequenceOrSetType::generateCopyConstructorImplementation(ostream &os) const/* override*/
{
	if (hasOptionalMembers())
	{
		os << "\tusing namespace std;\n";
		stack< string > optional_members;
		for (auto component_type : component_types_)
		{
			if (component_type->isOptional())
			{
				auto named_component_type(dynamic_pointer_cast< NamedComponentType >(component_type));
				if (named_component_type)
				{
					os << "\tauto " << NamedComponentType::toVariableName(named_component_type->getName()) << "(make_unique< " << named_component_type->getTypeName() << " >(*other." << NamedComponentType::toMemberName(named_component_type->getName()) << "));\n";
					optional_members.push(named_component_type->getName());
				}
				else
				{
					throw logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
				}
			}
		}	

		while (!optional_members.empty())
		{
			os << "\t" << NamedComponentType::toMemberName(optional_members.top()) << " = " << NamedComponentType::toVariableName(optional_members.top())<< ".release();\n";
			optional_members.pop();
		}
	}
	else
	{ /* no-op */ }
}
/*virtual */void SequenceOrSetType::generateDestructorImplementation(ostream &os) const/* override*/
{
	if (hasOptionalMembers())
	{
		stack< string > optional_members;
		for (auto component_type : component_types_)
		{
			if (component_type->isOptional())
			{
				auto named_component_type(dynamic_pointer_cast< NamedComponentType >(component_type));
				if (named_component_type)
				{
					optional_members.push(named_component_type->getName());
				}
				else
				{
					throw logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
				}
			}
		}	

		while (!optional_members.empty())
		{
			os << "\tdelete " << NamedComponentType::toMemberName(optional_members.top()) << ";\n";
			optional_members.pop();
		}
	}
	else
	{ /* no-op */ }
}
/*virtual */void SequenceOrSetType::generateSwapparatorImplementation(ostream &os) const/* override*/
{
	if (hasOptionalMembers())
	{
		os << "\tusing namespace std;\n";
	}
	else
	{ /* won't use std::swap */ }
	for (auto component_type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(component_type));
		if (named_component_type)
		{
			if (component_type->isOptional())
			{
				os << "\tswap(" << NamedComponentType::toMemberName(named_component_type->getName()) << ", other." << NamedComponentType::toMemberName(named_component_type->getName()) << ");\n";
			}
			else
			{
				os << "\t" << NamedComponentType::toMemberName(named_component_type->getName()) << ".swap(other." << NamedComponentType::toMemberName(named_component_type->getName()) << ");\n";
			}
		}
		else
		{
			throw logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
		}
	}	
}
/*virtual */void SequenceOrSetType::generateGetterAndSetterImplementations(string const &type_name, ostream &ofs) const/* override*/
{
	for (auto type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
		if (named_component_type)
		{
			named_component_type->generateGetterImplementation(type_name, ofs);
			named_component_type->generateSetterImplementation(type_name, ofs);
		}
		else
		{
			throw logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
		}
	}
}

}}}





