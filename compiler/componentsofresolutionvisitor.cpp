#include "componentsofresolutionvisitor.hpp"
#include "tracing.hpp"
#include "runtime/exceptions.hpp"
#include <memory>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*explicit */ComponentsOfResolutionVisitor::ComponentsOfResolutionVisitor(Directory const &directory)
        : directory_(directory)
{ /* no-op */ }

ComponentsOfResolutionVisitor const& ComponentsOfResolutionVisitor::operator()(SequenceOrSetType &sequence_or_set_type)
{
        sequence_or_set_type.visit(*this);
	return *this;
}
void ComponentsOfResolutionVisitor::operator()(shared_ptr< SequenceOrSetType::ComponentType > &component_type)
{
        auto retval(component_type->visit(*this));
        component_type = retval ? retval : component_type;
}
shared_ptr< SequenceOrSetType::ComponentType > ComponentsOfResolutionVisitor::visit(SequenceOrSetType::ComponentsOfType &components_of_type)
{
        if (gather__ == state_)
        {
                auto parent_component_name(components_of_type.getTypeName());
                auto parent_type(directory_.findType(parent_component_name));
                auto parent(dynamic_pointer_cast< SequenceOrSetType >(parent_type));
                if (!parent)
                {
                        emitError(components_of_type.getSourceLocation(), "%s is not a Sequence or Set type", parent_component_name.c_str());
                        throw InvalidDefinition("Not a Sequence or Set type");
                }
                else
                { /* all is well */ }
                components_.clear();
                state_ = dive__;
                parent->visit(*this);
                state_ = gather__;
                return make_shared< SequenceOrSetType::ComponentTypeList >(components_of_type.getSourceLocation(), components_.begin(), components_.end());
        }
        else
        { /* no-op */ }
        return shared_ptr< SequenceOrSetType::ComponentType >();
}
shared_ptr< SequenceOrSetType::ComponentType > ComponentsOfResolutionVisitor::visit(SequenceOrSetType::NamedComponentType &named_component_type)
{
        if ((state_ == dive__) && named_component_type.root())
        {
                components_.push_back(make_shared< SequenceOrSetType::NamedComponentType >(named_component_type));
                components_.back()->setRoot(false);
        }
        else
        { /* no need to keep it around */ }
        return shared_ptr< SequenceOrSetType::ComponentType >();
}
shared_ptr< SequenceOrSetType::ComponentType > ComponentsOfResolutionVisitor::visit(shared_ptr< SequenceOrSetType::ComponentType > const &component_type)
{
        return shared_ptr< SequenceOrSetType::ComponentType >();
}
/*static */void ComponentsOfResolutionVisitor::emitWarning(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: warning: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
/*static */void ComponentsOfResolutionVisitor::emitError(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: error: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
}}}
