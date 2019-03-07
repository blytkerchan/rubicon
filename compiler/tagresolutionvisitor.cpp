#include "tagresolutionvisitor.hpp"
#include "tracing.hpp"
#include "runtime/exceptions.hpp"
#include "integervalue.hpp"
#include <memory>

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
/*explicit */TagResolutionVisitor::TagResolutionVisitor(Directory const &directory)
        : directory_(directory)
{ /* no-op */ }

TagResolutionVisitor const& TagResolutionVisitor::operator()(SequenceOrSetType &sequence_or_set_type)
{
        sequence_or_set_type.visit(*this);
}
void TagResolutionVisitor::operator()(shared_ptr< SequenceOrSetType::ComponentType > &component_type)
{
        auto retval(component_type->visit(*this));
        component_type = retval ? retval : component_type;
}
shared_ptr< SequenceOrSetType::ComponentType > TagResolutionVisitor::visit(SequenceOrSetType::ComponentsOfType &components_of_type)
{
        assert(!"This should not be called");
        return shared_ptr< SequenceOrSetType::ComponentType >();
}
shared_ptr< SequenceOrSetType::ComponentType > TagResolutionVisitor::visit(SequenceOrSetType::NamedComponentType &named_component_type)
{
        auto tag(named_component_type.getTag());
        assert((tag.class_number_.which() == 0) || (tag.class_number_.which() == 1));
        if (tag.class_number_.which() == 1) // defined value
        {
                auto const defined_value(boost::get< DefinedValue >(tag.class_number_));
                auto source_location(defined_value.getSourceLocation());
                string identifier(defined_value.getValueName());
                unsigned int tries(3);
                bool done(false);
                do
                {
                        auto const value(directory_.findValue(identifier));
                        if (!value)
                        {
                                emitError(source_location, "Value not found: %s", identifier.c_str());
                                throw InvalidDefinition("Value not found");
                        }
                        else
                        { /* all is well so far */ }
                        source_location = value->getSourceLocation();
                        auto const integer_value(dynamic_pointer_cast< IntegerValue >(value));
                        if (!integer_value)
                        {
                                emitError(source_location, "Not an integer value: %s", identifier.c_str());
                                throw InvalidDefinition("Not an integer value");
                        }
                        else
                        { /* all is well so far */ }
                        if (!integer_value->getIdentifier().empty())
                        {
                                identifier = integer_value->getIdentifier();
                                --tries;
                        }
                        else
                        {
                                tag.class_number_ = boost::apply_visitor([integer_value](auto val) -> unsigned int { return integer_value->getValue(); }, tag.class_number_);
                                named_component_type.setTag(tag);
                                done = true;
                        }
                } while(!done && tries);
                if (!done)
                {
                        emitError(source_location, "Value not found: %s", identifier.c_str());
                        throw InvalidDefinition("Value not found");
                }
                else
                { /* all is well */ }
        }
        else
        { /* unsigned int */ }
        return shared_ptr< SequenceOrSetType::ComponentType >();
}
shared_ptr< SequenceOrSetType::ComponentType > TagResolutionVisitor::visit(shared_ptr< SequenceOrSetType::ComponentType > const &component_type)
{
        return shared_ptr< SequenceOrSetType::ComponentType >();
}
/*static */void TagResolutionVisitor::emitWarning(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: warning: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
/*static */void TagResolutionVisitor::emitError(SourceLocation const &source_location, char const *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	tracer__->trace(1, TRACE_ERROR)("%s:%u:%u: error: ", source_location.filename_.c_str(), source_location.line_, source_location.offset_)(fmt, ap)("\n");
	va_end(ap);
}
}}}
