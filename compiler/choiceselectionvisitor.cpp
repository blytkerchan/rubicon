#include "choiceselectionvisitor.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
ChoiceSelectionVisitor const& ChoiceSelectionVisitor::operator()(ChoiceType &choice_type)
{
	return *this;
}
void ChoiceSelectionVisitor::operator()(std::shared_ptr< ChoiceType::AlternativeType > &component_type)
{
}

std::shared_ptr< ChoiceType::AlternativeType > ChoiceSelectionVisitor::visit(ChoiceType::AlternativeType &alternative_type)
{
	return selection_;
}
}}}




