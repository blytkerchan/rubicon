#include "choicetype.hpp"
#include <algorithm>
#include "../exceptions/contract.hpp"

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
}}}


