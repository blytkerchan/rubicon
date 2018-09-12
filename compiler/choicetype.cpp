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

/*virtual */void ChoiceType::generateEncodeImplementation(std::ostream &os) const/* override*/
{
	os << "//TODO" << endl;
}
unsigned int ChoiceType::getCloneID() const
{
	pre_condition(isClone());
	return clone_id_;
}

std::string ChoiceType::getCloneName() const
{
	pre_condition(isClone());
	return clone_name_;
}
}}}


