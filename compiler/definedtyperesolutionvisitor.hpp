#ifndef rubicon_compiler_definedtyperesolutionvisitor_hpp
#define rubicon_compiler_definedtyperesolutionvisitor_hpp

#include "sequenceorsettype.hpp"
#include "directory.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class DefinedTypeResolutionVisitor
{
public :
	explicit DefinedTypeResolutionVisitor(Directory const &directory);
	DefinedTypeResolutionVisitor(DefinedTypeResolutionVisitor &&) = default;
	DefinedTypeResolutionVisitor(DefinedTypeResolutionVisitor const &) = delete;
	DefinedTypeResolutionVisitor& operator=(DefinedTypeResolutionVisitor &&) = default;
	DefinedTypeResolutionVisitor& operator=(DefinedTypeResolutionVisitor const &) = delete;
	
	DefinedTypeResolutionVisitor const& operator()(SequenceOrSetType &sequence_or_set_type);
	void operator()(std::shared_ptr< SequenceOrSetType::ComponentType > &component_type);

	void visit(SequenceOrSetType::ComponentsOfType &components_of_type);
	void visit(SequenceOrSetType::NamedComponentType &named_component_type);
	void visit(std::shared_ptr< SequenceOrSetType::ComponentType > const &component_type);

    void visit(ChoiceType &choice_type);
    void visit(ConstrainedType &constrained_type);
    void visit(DefinedType &defined_type);
    void visit(NamedType &named_type);
    void visit(SelectionType &selection_type);
    void visit(SequenceOrSetOfType &sequence_or_set_of_type);
    void visit(TaggedType &tagged_type);

private :
	static void emitWarning(SourceLocation const &source_location, char const *fmt, ...);
	static void emitError(SourceLocation const &source_location, char const *fmt, ...);

	std::vector< std::shared_ptr< SequenceOrSetType::ComponentType > > components_;

	Directory directory_;
};
}}}

#endif
