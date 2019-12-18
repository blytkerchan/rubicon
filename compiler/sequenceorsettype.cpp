#include "sequenceorsettype.hpp"
#include <algorithm>
#include <stack>
#include "autotagvisitor.hpp"
#include "componentsofresolutionvisitor.hpp"
#include "definedtyperesolutionvisitor.hpp"
#include "tagresolutionvisitor.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */void SequenceOrSetType::ComponentType::generateInstance(ostream &os, string const &instance_name) const
{
	os << "\t" << getTypeName() << " " << (optional() ? "*" : "") << instance_name << ";\n";
}
/*virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::ComponentsOfType::visit(AutoTagVisitor &visitor)
{
	return visitor.visit(*this);
}
/*virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::ComponentsOfType::visit(ComponentsOfResolutionVisitor &visitor)
{
	return visitor.visit(*this);
}
/*virtual */void SequenceOrSetType::ComponentsOfType::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
{
    type_->visit(visitor);
}
/*virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::ComponentsOfType::visit(TagResolutionVisitor &visitor)
{
	return visitor.visit(*this);
}
void SequenceOrSetType::NamedComponentType::generateHeaderGetterAndSetter(ostream &os) const
{
	string name(getName());
	name[0] = toupper(name[0]);
	os << "\t" << getTypeName() << ((optional() && !hasDefaultValue()) ? " const* " : " ") << "get" << name << "() const;\n";
	os << "\t" << "void set" << name << "(" << getTypeName() << " const &" << toVariableName(getName()) << ");\n";
}
/*virtual */void SequenceOrSetType::NamedComponentType::generateGetterImplementation(string const &type_name, ostream &os) const/* override*/
{
	string name(getName());
	name[0] = toupper(name[0]);
	os <<
		getTypeName() << ((optional() && !hasDefaultValue()) ? " const* " : " ") << type_name <<  "::get" << name << "() const\n"
		"{\n"
		;
	if (optional() && hasDefaultValue())
	{
		os << "\treturn " << toMemberName(getName()) << " ? *" << toMemberName(getName()) << " : " << default_value_->generateInstance() << ";\n";
	}
    else if (optional() && !hasDefaultValue())
	{
		os << "\treturn " << toMemberName(getName()) << ";\n";
	}
	else
	{
		//TODO use the default value if the value is not set
		os << "\treturn " << toMemberName(getName()) << ";\n";
	}
	os << "}\n";
}
/*virtual */void SequenceOrSetType::NamedComponentType::generateSetterImplementation(string const &type_name, ostream &os) const/* override*/
{
	string name(getName());
	name[0] = toupper(name[0]);
	os <<
		"void " << type_name <<  "::set" << name << "(" << getTypeName() << " const &" << toVariableName(getName()) << ")\n"
		"{\n"
		;
	if (optional())
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
void SequenceOrSetType::NamedComponentType::generateCompareImplementation(std::ostream& os) const
{
    if (optional())
    {   // if optional and both sides are NULL, we don't care about default values
        os << "\tif (!" << toMemberName(getName()) << " && !other." << toMemberName(getName()) << ")\n";
        os << "\t{ /* both sides are NULL, so either both default values or absent */ }\n";
        os << "\telse if (!" << toMemberName(getName()) << " && other." << toMemberName(getName()) << ")\n";
        os << "\t{ // we have a right-hand-side\n";
        if (!!default_value_)
        {
            os << "\t\tcompare_result = -other." << toMemberName(getName()) << "->compare(" << default_value_->generateInstance() << ");\n";
        }
        else
        { // no default value
            os << "\t\t// We don't have a default value, so if the other side exists, they get it.\n";
            os << "\t\tcompare_result = 1;\n";
        }
        os << "\t}\n";
        os << "\telse if (" << toMemberName(getName()) << " && !other." << toMemberName(getName()) << ")\n";
        os << "\t{ // we have a left-hand-side\n";
        if (!!default_value_)
        {
            os << "\t\tcompare_result = "<< toMemberName(getName()) << "->compare(" << default_value_->generateInstance() << ");\n";
        }
        else
        { // no default value
            os << "\t\t// We don't have a default value, so if the we exist and the other side doesn't, we get it.\n";
            os << "\t\tcompare_result = -1;\n";
        }
        os << "\t}\n";
        os << "\telse\n";
        os << "\t{ // we have both sides\n";
        os << "\t\tcompare_result = "<< toMemberName(getName()) << "->compare(*other." << toMemberName(getName()) << ");\n";
        os << "\t}\n";
    }
    else
    {   // if not optional, we can just directly run compare
        os << "\tcompare_result = "<< toMemberName(getName()) << ".compare(other." << toMemberName(getName()) << ");\n";
    }
}
/*virtual */void SequenceOrSetType::NamedComponentType::generateMemberDeclarations(ostream &os) const/* override*/
{
	os << "\t" << getTypeName() << (optional() ? " *" : " ") << toMemberName(getName()) << (optional() ? " = nullptr" : "") << ";\n";
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
/*virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::NamedComponentType::visit(AutoTagVisitor &visitor)
{
	return visitor.visit(*this);
}
/*virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::NamedComponentType::visit(ComponentsOfResolutionVisitor &visitor)
{
	return visitor.visit(*this);
}
/*virtual */void SequenceOrSetType::NamedComponentType::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
{
	visitor.visit(*this);
}
/*virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::NamedComponentType::visit(TagResolutionVisitor &visitor)
{
	return visitor.visit(*this);
}

/* virtual */set< string > SequenceOrSetType::ComponentTypeList::getDependencies() const/* override*/
{
	assert(!"This should not be called");
	return set< string >();
}
/* virtual */set< string > SequenceOrSetType::ComponentTypeList::getStrongDependencies() const/* override*/
{
	assert(!"This should not be called");
	return set< string >();
}
/* virtual */set< string > SequenceOrSetType::ComponentTypeList::getWeakDependencies() const/* override*/
{
	assert(!"This should not be called");
	return set< string >();
}
/* virtual */bool SequenceOrSetType::ComponentTypeList::hasTypeName() const/* override*/
{
	assert(!"This should not be called");
	return false;
}
/* virtual */string SequenceOrSetType::ComponentTypeList::getTypeName() const/* override*/
{
	assert(!"This should not be called");
	return string();
}
/* virtual */bool SequenceOrSetType::ComponentTypeList::optional() const/* override*/
{
	assert(!"This should not be called");
	return false;
}
/* virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::ComponentTypeList::visit(AutoTagVisitor &visitor)/* override*/
{
	assert(!"This should not be called");
	return shared_ptr< ComponentType >();
}
/* virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::ComponentTypeList::visit(ComponentsOfResolutionVisitor &visitor)/* override*/
{
	assert(!"This should not be called");
	return shared_ptr< ComponentType >();
}
/*virtual */void SequenceOrSetType::ComponentTypeList::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
{
	assert(!"This should not be called");
}
/* virtual */shared_ptr< SequenceOrSetType::ComponentType > SequenceOrSetType::ComponentTypeList::visit(TagResolutionVisitor &visitor)/* override*/
{
	assert(!"This should not be called");
	return shared_ptr< ComponentType >();
}

void SequenceOrSetType::visit(AutoTagVisitor &visitor)
{
	visitor = for_each(component_types_.begin(), component_types_.end(), move(visitor));
}

void SequenceOrSetType::visit(ComponentsOfResolutionVisitor &visitor)
{
	visitor = for_each(component_types_.begin(), component_types_.end(), move(visitor));
}
/*virtual */void SequenceOrSetType::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
{
	visitor = for_each(component_types_.begin(), component_types_.end(), move(visitor));
}
void SequenceOrSetType::visit(TagResolutionVisitor &visitor)
{
	visitor = for_each(component_types_.begin(), component_types_.end(), move(visitor));
}

void SequenceOrSetType::flatten()
{
	decltype(component_types_) new_component_types;
	for (auto component_type : component_types_)
	{
		assert(!dynamic_pointer_cast< ComponentsOfType >(component_type));
		if (dynamic_pointer_cast< NamedComponentType >(component_type))
		{
			new_component_types.push_back(component_type);
		}
		else if (dynamic_pointer_cast< ComponentTypeList >(component_type))
		{
			auto component_type_list(static_pointer_cast< ComponentTypeList >(component_type));
			copy(component_type_list->components_.begin(), component_type_list->components_.end(), back_inserter(new_component_types));
		}
		else
		{
			assert(!"This code should be unreachable");
		}
	}
	component_types_ = new_component_types;
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
		retval |= component_type->optional();
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
			if (component_type->optional())
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
			if (component_type->optional())
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
	for (auto component_type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(component_type));
		if (named_component_type)
		{
			if (component_type->optional())
			{
				os << "\tstd::swap(" << NamedComponentType::toMemberName(named_component_type->getName()) << ", other." << NamedComponentType::toMemberName(named_component_type->getName()) << ");\n";
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

void SequenceOrSetType::generateCompareImplementation(std::ostream& os) const
{
    os << "\tint compare_result(0);\n";
    for (auto type : component_types_)
	{
		auto named_component_type(dynamic_pointer_cast< NamedComponentType >(type));
		if (named_component_type)
		{
            named_component_type->generateCompareImplementation(os);
            os << "\tif (compare_result) return compare_result;\n";
            //if (output_else) os << "\telse ";
            //os << (output_else ? "" : "\t") << "if (";
            //named_component_type->generateCompareImplementation(os, false);
            //os << ") return -1;\n";
            //os << "\telse if (";
            //named_component_type->generateCompareImplementation(os, true);
            //os << ") return 1;\n";
            //output_else = true;
		}
		else
		{
			throw logic_error("Generation of sequences and sets with COMPONENTS OF is not implemented yet");
		}
	}
    os << "\treturn compare_result;\n";
}

}}}





