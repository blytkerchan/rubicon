#include "autotagvisitor.hpp"
#include "../runtime/exceptions.hpp"
#include "../exceptions/contract.hpp"
#include "../tracing.hpp"
#include "taggedtype.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*explicit */AutoTagVisitor::AutoTagVisitor(bool is_set)
	: is_set_(is_set)
{ /* no-op */ }

AutoTagVisitor const& AutoTagVisitor::operator()(SequenceOrSetType &sequence_or_set_type)
{
	if (*this)
	{
		sequence_or_set_type.visit(*this);
		step_ = next();
	}
	else
	{ /* no-op */ }
	return *this;
}
void AutoTagVisitor::operator()(shared_ptr< SequenceOrSetType::ComponentType > &component_type)
{
	auto retval(component_type->visit(*this));
	component_type = retval ? retval : component_type;
}
shared_ptr< SequenceOrSetType::ComponentType > AutoTagVisitor::visit(SequenceOrSetType::ComponentsOfType &components_of_type)
{
	throw std::logic_error("ComponentsOfType should have been resolved by now");
	return shared_ptr< SequenceOrSetType::ComponentType >();
}
shared_ptr< SequenceOrSetType::ComponentType > AutoTagVisitor::visit(SequenceOrSetType::NamedComponentType &named_component_type)
{
	switch (step_)
	{
	case check_permitted__ :
		if (is_set_)
		{
			// Automatic tagging for sets, according to X.680 27.3, results as the application of 25.8, but
			// it doesn't say anything about being permitted when there are any tagged types or not, so we 
			// will assume that it is always permitted.
		}
		else
		{ // it's a sequence
			// Automatic tagging is not permitted according to X.680 25.3 if any of the component types 
			// of the sequence are TaggedType or a "textualy tagged type". X.680 doesn't clearly define
			// "textually tagged", but I take it to mean "tagged in the text using the tag notation", which
			// results in the tag of the type being non-universal. Hence, all we have to do here is to ask
			// the type for its tag, and see if what we get back is universal.
			auto tag(named_component_type.named_type_.getTag());
			is_permitted_ &= (tag.class_ == Tag::universal__);
		}
		break;
	case check_necessity__ :
		if (is_set_)
		{
			// AFAICT, according to X.680 27.3, this is necessary unless all members are tagged, so it is 
			// necessary as soon as a single one of the components is not tagged
			auto tag(named_component_type.named_type_.getTag());
			is_necessary_ &= (tag.class_ != Tag::universal__);
		}
		else
		{ // it's a sequence
			// Automatic tagging is necessary as soon as any of the optional members is followed by a member
			// with the same tag.
			if (latest_member_.optional_)
			{
				is_necessary_ = (latest_member_.tag_ == named_component_type.named_type_.getTag());
			}
			else
			{ /* no need to check */ }
			latest_member_.optional_ = named_component_type.isOptional();
			latest_member_.tag_ = named_component_type.named_type_.getTag();
		}
	case tag_types__ :
		named_component_type.named_type_.setType(
			  make_shared< TaggedType >(
				  named_component_type.named_type_.getType()->getSourceLocation()
				, Tag(Tag::context_specific__, next_class_number_++)
				, false
				, false
				, named_component_type.named_type_.getType()
				)
			);
		break;
	}
	return shared_ptr< SequenceOrSetType::ComponentType >();
}
shared_ptr< SequenceOrSetType::ComponentType > AutoTagVisitor::visit(shared_ptr< SequenceOrSetType::ComponentType > const &component_type)
{
	auto retval(component_type->visit(*this));
	return retval ? retval : component_type;
}
AutoTagVisitor::Step AutoTagVisitor::next() const
{
	switch (step_)
	{
	case check_permitted__ :
		if (is_permitted_) return check_necessity__;
		else break;
	case check_necessity__ :
		if (is_necessary_) return tag_types__;
		else break;
	}
	return final__;
}
#if 0
/*static */void AutoTagVisitor::emitWarning(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: warning: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
/*static */void AutoTagVisitor::emitError(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: error: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
#endif
}}}




