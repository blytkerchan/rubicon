#ifndef rubicon_compiler_sequenceorsettype_hpp
#define rubicon_compiler_sequenceorsettype_hpp

#include "typedescriptor.hpp"
#include "namedtype.hpp"
#include "value.hpp"
#include <memory>
#include <vector>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class SequenceOrSetType : public TypeDescriptor
{
public :
	struct ComponentType
	{
		virtual ~ComponentType() = default;

		virtual bool root() const noexcept = 0;
	};
	struct ComponentsOfType : ComponentType
	{
		typedef std::shared_ptr< TypeDescriptor > Type;

		ComponentsOfType(Type const &type)
			: type_(type)
		{ /* no-op */ }
		virtual bool root() const noexcept override { return false; }

		Type type_;
	};
	struct NamedComponentType : ComponentType
	{
		NamedComponentType(bool root, NamedType const &named_type, bool optional = false)
			: root_(root)
			, named_type_(named_type)
			, optional_(optional)
		{ /* no-op */ }

		NamedComponentType(bool root, NamedType const &named_type, std::shared_ptr< Value > const &default_value)
			: root_(root)
			, named_type_(named_type)
			, optional_(true)
			, default_value_(default_value)
		{ /* no-op */ }
		NamedComponentType(NamedComponentType const&) = delete;
		NamedComponentType(NamedComponentType &&) = default;
		NamedComponentType& operator=(NamedComponentType const&) = delete;
		NamedComponentType& operator=(NamedComponentType &&) = default;

		virtual bool root() const noexcept override { return root_; }

		bool root_;
		NamedType named_type_;
		bool optional_;
		std::shared_ptr< Value > default_value_;
	};
	typedef std::vector< std::shared_ptr< ComponentType > > ComponentTypes;

	SequenceOrSetType() = default;
	SequenceOrSetType(bool is_set, ComponentTypes const &component_types)
		: is_set_(is_set)
		, component_types_(component_types)
	{ /* no-op */ }
	virtual std::vector< std::string > getDependencies() const;

private :
	bool is_set_ = false;
	ComponentTypes component_types_;
};
}}}

#endif



