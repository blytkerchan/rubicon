#ifndef rubicon_compiler_componentsofresolutionvisitor_hpp
#define rubicon_compiler_componentsofresolutionvisitor_hpp

#include "sequenceorsettype.hpp"
#include "directory.hpp"

namespace Vlinder { namespace Rubicon { namespace Compiler {
class ComponentsOfResolutionVisitor
{
public :
	explicit ComponentsOfResolutionVisitor(Directory const &directory);
	ComponentsOfResolutionVisitor(ComponentsOfResolutionVisitor &&) = default;
	ComponentsOfResolutionVisitor(ComponentsOfResolutionVisitor const &) = delete;
	ComponentsOfResolutionVisitor& operator=(ComponentsOfResolutionVisitor &&) = default;
	ComponentsOfResolutionVisitor& operator=(ComponentsOfResolutionVisitor const &) = delete;
	
	ComponentsOfResolutionVisitor const& operator()(SequenceOrSetType &sequence_or_set_type);
	void operator()(std::shared_ptr< SequenceOrSetType::ComponentType > &component_type);

	std::shared_ptr< SequenceOrSetType::ComponentType > visit(SequenceOrSetType::ComponentsOfType &components_of_type);
	std::shared_ptr< SequenceOrSetType::ComponentType > visit(SequenceOrSetType::NamedComponentType &named_component_type);
	std::shared_ptr< SequenceOrSetType::ComponentType > visit(std::shared_ptr< SequenceOrSetType::ComponentType > const &component_type);

private :
	enum State {
                  gather__
                , dive__
	};

        static void emitWarning(SourceLocation const &source_location, char const *fmt, ...);
        static void emitError(SourceLocation const &source_location, char const *fmt, ...);

        std::vector< std::shared_ptr< SequenceOrSetType::ComponentType > > components_;

        State state_ = gather__;
        Directory directory_;
};
}}}

#endif
