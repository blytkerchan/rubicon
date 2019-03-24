#ifndef vlinder_rubicon_compiler_choiceselection_hpp
#define vlinder_rubicon_compiler_choiceselection_hpp

#include "choicetype.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ChoiceSelectionVisitor
{
public :
	ChoiceSelectionVisitor() = default;
	ChoiceSelectionVisitor(ChoiceSelectionVisitor &&) = default;
	ChoiceSelectionVisitor(ChoiceSelectionVisitor const &) = delete;
	ChoiceSelectionVisitor& operator=(ChoiceSelectionVisitor &&) = default;
	ChoiceSelectionVisitor& operator=(ChoiceSelectionVisitor const &) = delete;
	
	ChoiceSelectionVisitor const& operator()(ChoiceType &choice_type);
	void operator()(std::shared_ptr< ChoiceType::AlternativeType > &component_type);

	std::shared_ptr< ChoiceType::AlternativeType > visit(ChoiceType::AlternativeType &alternative_type);

private :
	std::shared_ptr< ChoiceType::AlternativeType > selection_;
};
}}}

#endif



