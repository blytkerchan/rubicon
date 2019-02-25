#ifndef vlinder_rubicon_compiler_autotagvisitor_hpp
#define vlinder_rubicon_compiler_autotagvisitor_hpp

#include "sequenceorsettype.hpp"
#include "tag.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class AutoTagVisitor
{
public :
	explicit AutoTagVisitor(bool is_set);
	AutoTagVisitor(AutoTagVisitor &&) = default;
	AutoTagVisitor(AutoTagVisitor const &) = delete;
	AutoTagVisitor& operator=(AutoTagVisitor &&) = default;
	AutoTagVisitor& operator=(AutoTagVisitor const &) = delete;
	
	AutoTagVisitor const& operator()(SequenceOrSetType &sequence_or_set_type);
	void operator()(std::shared_ptr< SequenceOrSetType::ComponentType > &component_type);

	std::shared_ptr< SequenceOrSetType::ComponentType > visit(SequenceOrSetType::ComponentsOfType &components_of_type);
	std::shared_ptr< SequenceOrSetType::ComponentType > visit(SequenceOrSetType::NamedComponentType &named_component_type);
	std::shared_ptr< SequenceOrSetType::ComponentType > visit(std::shared_ptr< SequenceOrSetType::ComponentType > const &component_type);

	explicit operator bool () const { return step_ != final__; }

private :
	enum Step {
		  check_permitted__
		, check_necessity__
		, tag_types__
		, final__
	};
	struct MemberInfo
	{
		bool optional_;
		Tag tag_;
	};

	Step next() const;

	bool is_set_ = false;
	bool is_permitted_ = true;
	bool is_necessary_ = false;
	Step step_ = check_permitted__;
	MemberInfo latest_member_ = { false, { Tag::universal__, 0 } };
	unsigned int next_class_number_ = 0;
};
}}}

#endif


