#include "choicetype.hpp"
#include <algorithm>
#include "../exceptions/contract.hpp"
#include "definedtyperesolutionvisitor.hpp"
#include "helpers.hpp"

using namespace std;
using namespace boost;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*virtual */set< string > ChoiceType::getDependencies() const
{
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(set< string > &retval)
			: retval_(retval)
		{ /* no-op */ }
		void operator()(NamedType const &named_type) const
		{
			retval_.insert(retval_.end(), named_type.getName());
		}
		void operator()(VersionedTypeList const &versioned_type_list) const
		{
			for_each(versioned_type_list.second.begin(), versioned_type_list.second.end(), *this);
		}

		set< string > &retval_;
	};
	set< string > retval;

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(retval), type);
	}

	return retval;
}

/*virtual */Tag ChoiceType::getTag() const/* override*/
{
	Tag retval(Tag::universal__, 0);
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(Tag &retval)
			: retval_(retval)
		{ /* no-op */ }

		void operator()(NamedType const &named_type) const
		{
			Tag tag(named_type.getTag());
			if (tag.class_ != Tag::universal__)
			{
				retval_ = tag;
			}
			else
			{ /* no change */ }
		}
		void operator()(VersionedTypeList const &versioned_type_list) const
		{
			for_each(versioned_type_list.second.begin(), versioned_type_list.second.end(), *this);
		}

		Tag &retval_;
	};
	
	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(retval), type);
	}

	retval.class_number_ = 0/* zero is reserved for encodings, but in this context this function is called to know the class, not the number */;
	return retval;
}

/*virtual */void ChoiceType::generateEncodeImplementation(ostream &os) const/* override*/
{
	os << "//TODO" << endl;
}
/*virtual */void ChoiceType::generateAlternateConstructorDeclarations(ostream& os, string const& class_name) const/* override*/
{
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(std::ostream& os, string const &class_name)
            : os_(os)
            , class_name_(class_name)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
			os_ << "\texplicit " << class_name_ << "(" << named_type.getTypeName() << " const &" << toVariableName(named_type.getName()) << ");\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		ostream& os_;
        string class_name_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os, class_name), type);
	}
}
/*virtual */void ChoiceType::generateHeaderGettersAndSetters(std::ostream& os) const/* override*/
{
    /* The CHOICE type should have one "special" getter telling it what the underlying type is. We'll call it getTag and return the tag */
    os << "\tunsigned int getTag() const noexcept;\n";

	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(std::ostream& os)
            : os_(os)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
			os_ << "\t" << named_type.getTypeName() << "* const get" << named_type.getTypeName() << "() const;\n";
			os_ << "\tvoid set" << named_type.getTypeName() << "(" << named_type.getTypeName() << " const &" << toVariableName(named_type.getName()) << ");\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		std::ostream& os_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os), type);
	}
}
/*virtual */void ChoiceType::generateMemberDeclarations(std::ostream &os) const/* override*/
{
    os << "\tunsigned int tag_ = 0;\n";

	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(std::ostream& os)
            : os_(os)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
			os_ << "\t" << named_type.getTypeName() << " *" << toMemberName(named_type.getName()) << " = nullptr;\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		std::ostream& os_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os), type);
	}
}

/*virtual */void ChoiceType::generateCopyConstructorInitializers(std::ostream& os) const/* override*/
{
    os << "\t: tag_(other.tag_)\n";

	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(std::ostream& os)
            : os_(os)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
			os_ << "\t, " << toMemberName(named_type.getName()) << "(nullptr)\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		std::ostream& os_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os), type);
	}
}

/*virtual */void ChoiceType::generateCopyConstructorImplementation(std::ostream& os) const/* override*/
{
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(std::ostream& os)
            : os_(os)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
            os_ << "\tif (other." << toMemberName(named_type.getName()) << ") " << toMemberName(named_type.getName()) << " = new " << named_type.getTypeName() << "(*other." << toMemberName(named_type.getName()) << ");\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		std::ostream& os_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os), type);
	}
}

/*virtual */void ChoiceType::generateDestructorImplementation(std::ostream &os) const/* override*/
{
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(std::ostream& os)
            : os_(os)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
            os_ << "\tdelete " << toMemberName(named_type.getName()) << ";\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		std::ostream& os_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os), type);
	}
}

/*virtual */void ChoiceType::generateSwapparatorImplementation(std::ostream& os) const/* override*/
{
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(std::ostream& os)
            : os_(os)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
            os_ << "\tstd::swap(" << toMemberName(named_type.getName()) << ", other." << toMemberName(named_type.getName()) << ");\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		std::ostream& os_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os), type);
	}
}

/*virtual */void ChoiceType::generateCompareImplementation(std::ostream& os) const/* override*/
{
    os << "\tint compare_result(other.tag_ - tag_);\n";
    os << "\tif (compare_result) return compare_result;\n";
    os << "\t\n";
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(std::ostream& os)
            : os_(os)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
            os_ << "\tif (" << toMemberName(named_type.getName()) << " && other." << toMemberName(named_type.getName()) << ") compare_result = " << toMemberName(named_type.getName()) << "->compare(*other." << toMemberName(named_type.getName()) << ");\n";
            os_ << "\tif (compare_result) return compare_result;\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		std::ostream& os_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os), type);
	}
    os << "\treturn compare_result;\n";
}

/*virtual */void ChoiceType::generateGetterAndSetterImplementations(std::string const& type_name, std::ostream& os) const/* override*/
{
    os << "unsigned int " << type_name << "::getTag() const noexcept\n";
    os << "{\n";
    os << "\treturn tag_;\n";
    os << "}\n";
    os << "\n";
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(ostream& os, string const& type_name, AlternativeTypes const &alternative_types)
            : os_(os)
            , type_name_(type_name)
            , alternative_types_(alternative_types)
		{ /* no-op */ }

		void operator()(NamedType &named_type) const
		{
			os_ << named_type.getTypeName() << "* const " << type_name_ << "::get" << named_type.getTypeName() << "() const\n";
            os_ << "{\n";
            os_ << "\treturn " << toMemberName(named_type.getName()) << ";\n";
            os_ << "}\n";
            os_ << "\n";
			os_ << "void " << type_name_ << "::set" << named_type.getTypeName() << "(" << named_type.getTypeName() << " const &" << toVariableName(named_type.getName()) << ")\n";
            os_ << "{\n";
            
            os_ << "\tif (" << toMemberName(named_type.getName()) << ")\n";
            os_ << "\t{\n";
            os_ << "\t\t*" << toMemberName(named_type.getName()) << " = " << toVariableName(named_type.getName()) << ";\n";
            os_ << "\t}\n";
            os_ << "\telse\n";
            os_ << "\t{\n";
            os_ << "\t\t" << toMemberName(named_type.getName()) << " = new " << named_type.getTypeName() << "(" << toVariableName(named_type.getName()) << ");\n";
            os_ << "\t}\n";

	        struct TypeVisitor2 : static_visitor<>
	        {
		        TypeVisitor2(ostream& os, string const& type_name, NamedType &current_named_type)
                    : os_(os)
                    , type_name_(type_name)
                    , current_named_type_(current_named_type)
		        { /* no-op */ }

		        void operator()(NamedType &named_type) const
		        {
                    if (named_type.getName() != current_named_type_.getName())
                    {
                        os_ << "\tdelete " << toMemberName(named_type.getName()) << "\n";
                        os_ << "\t" << toMemberName(named_type.getName()) << " = nullptr;\n";
                    }
                    else
                    { /* nothing to delete */ }
		        }
		        void operator()(VersionedTypeList &versioned_type_list) const
		        {
                    throw logic_error("not yet implemented");
		        }

		        ostream& os_;
                string type_name_;
                NamedType &current_named_type_;
	        };
            for (auto type : alternative_types_)
            {
                apply_visitor(TypeVisitor2(os_, type_name_, named_type), type);
            }

            os_ << "}\n";
            os_ << "\n";
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
            throw logic_error("not yet implemented");
		}

		ostream& os_;
        string type_name_;
        AlternativeTypes const &alternative_types_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(os, type_name, alternative_types_), type);
	}
}

unsigned int ChoiceType::getCloneID() const
{
	pre_condition(isClone());
	return clone_id_;
}

string ChoiceType::getCloneName() const
{
	pre_condition(isClone());
	return clone_name_;
}
/*virtual */void ChoiceType::visit(DefinedTypeResolutionVisitor &visitor)/* override*/
{
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(DefinedTypeResolutionVisitor &visitor)
			: visitor_(visitor)
		{ /* no-op */ }
		void operator()(NamedType &named_type) const
		{
			visitor_.visit(named_type);
		}
		void operator()(VersionedTypeList &versioned_type_list) const
		{
			for_each(versioned_type_list.second.begin(), versioned_type_list.second.end(), *this);
		}

		DefinedTypeResolutionVisitor &visitor_;
	};

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(visitor), type);
	}
}
}}}


