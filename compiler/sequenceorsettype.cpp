#include "sequenceorsettype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void SequenceOrSetType::ComponentType::generateInstance(std::ostream &os, std::string const &instance_name) const
{
	os << "\t" << getTypeName() << " " << (isOptional() ? "*" : "") << instance_name << ";\n";
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
/*virtual */void SequenceOrSetType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	os <<
		"\tonStartEncoding(der_encoder);\n"
		;
	for (auto type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
		if (named_component_type)
		{
			os <<
				"\tonEncode(der_encoder, false, \"" << named_component_type->getName() << "\");\n"
				;
			named_component_type->generateEncodeImplementation(os, toMemberName(named_component_type->getName()));
			os <<
				"\tonEncode(der_encoder, true, \"" << named_component_type->getName() << "\");\n"
				;
		}
		else
		{
			throw std::logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
		}
	}
	os <<
		"\tonFinishEncoding(der_encoder);\n"
		;
}
/*virtual */void SequenceOrSetType::generateEventHandlers(std::ostream &os) const/* override*/
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
/*virtual */void SequenceOrSetType::generateDataMembers(std::ostream &os) const/* override*/
{
	for (auto type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
		if (named_component_type)
		{
			named_component_type->generateInstance(os, toMemberName(named_component_type->getName()));
		}
		else
		{
			throw std::logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
		}
	}
	
}
/*static */string SequenceOrSetType::toMemberName(string const &name)
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
	retval.append("_");

	return retval;
}
}}}





