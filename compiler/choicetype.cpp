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


