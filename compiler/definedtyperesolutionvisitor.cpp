#include "definedtyperesolutionvisitor.hpp"
#include "choicetype.hpp"
#include "constrainedtype.hpp"
#include "definedtype.hpp"
#include "selectiontype.hpp"
#include "sequenceorsetoftype.hpp"
#include "taggedtype.hpp"
#include "tracing.hpp"
#include "runtime/exceptions.hpp"
#include "integervalue.hpp"
#include <memory>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*explicit */DefinedTypeResolutionVisitor::DefinedTypeResolutionVisitor(Directory const &directory)
        : directory_(directory)
{ /* no-op */ }

DefinedTypeResolutionVisitor const& DefinedTypeResolutionVisitor::operator()(SequenceOrSetType &sequence_or_set_type)
{
    sequence_or_set_type.visit(*this);
	return *this;
}
void DefinedTypeResolutionVisitor::operator()(shared_ptr< SequenceOrSetType::ComponentType > &component_type)
{
    component_type->visit(*this);
}
void DefinedTypeResolutionVisitor::visit(SequenceOrSetType::ComponentsOfType &components_of_type)
{
    assert(!"This should not be called");
}
void DefinedTypeResolutionVisitor::visit(SequenceOrSetType::NamedComponentType &named_component_type)
{
    named_component_type.named_type_.getType()->visit(*this);
}
void DefinedTypeResolutionVisitor::visit(shared_ptr< SequenceOrSetType::ComponentType > const &component_type)
{
    assert(!"This should not be called");
}
void DefinedTypeResolutionVisitor::visit(ChoiceType &choice_type)
{
    choice_type.visit(*this);
}
void DefinedTypeResolutionVisitor::visit(ConstrainedType &constrained_type)
{
    constrained_type.visit(*this);
}
void DefinedTypeResolutionVisitor::visit(DefinedType &defined_type)
{
	auto type_assignments(directory_.getTypeAssignments());
	auto const name(defined_type.getTypeName());
	auto which(find_if(type_assignments.begin(), type_assignments.end(), [name](auto type_assignment){ return name == type_assignment.getName(); }));
	if (which == type_assignments.end())
	{
		emitError(which->getSourceLocation(), "undefined reference to %s", defined_type.getTypeName().c_str());
		throw UndefinedReference("undefined reference");
	}
	else
	{ /* found it */ }
    defined_type.setReferencedType(which->getType());
    which->getType()->visit(*this);
}

void DefinedTypeResolutionVisitor::visit(NamedType &named_type)
{
    named_type.visit(*this);
}

void DefinedTypeResolutionVisitor::visit(SelectionType &selection_type)
{
    selection_type.visit(*this);
}

void DefinedTypeResolutionVisitor::visit(SequenceOrSetOfType &sequence_or_set_of_type)
{
    sequence_or_set_of_type.visit(*this);
}

void DefinedTypeResolutionVisitor::visit(TaggedType &tagged_type)
{
    tagged_type.visit(*this);
}

/*static */void DefinedTypeResolutionVisitor::emitWarning(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: warning: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
/*static */void DefinedTypeResolutionVisitor::emitError(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: error: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
}}}
