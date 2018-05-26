#include "choicetype.hpp"
#include <algorithm>

using namespace std;
using namespace boost;

namespace Vlinder { namespace Rubicon { namespace Compiler {
	typedef std::vector< boost::variant< NamedType, VersionedTypeList > > AlternativeTypes;

/*virtual */vector< string > ChoiceType::getWeakDependencies() const
{
	struct TypeVisitor : static_visitor<>
	{
		TypeVisitor(vector< string > &retval)
			: retval_(retval)
		{ /* no-op */ }
		void operator()(NamedType const &named_type) const
		{
			retval_.push_back(named_type.name_);
		}
		void operator()(VersionedTypeList const &versioned_type_list) const
		{
			for_each(versioned_type_list.second.begin(), versioned_type_list.second.end(), *this);
		}

		vector< string > &retval_;
	};
	vector< string > retval;

	for (auto type : alternative_types_)
	{
		apply_visitor(TypeVisitor(retval), type);
	}

	return retval;
}

	AlternativeTypes alternative_types_;
}}}


