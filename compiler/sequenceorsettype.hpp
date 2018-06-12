#ifndef rubicon_compiler_sequenceorsettype_hpp
#define rubicon_compiler_sequenceorsettype_hpp

#include "typedescriptor.hpp"
#include "namedtype.hpp"
#include "value.hpp"
#include <memory>
#include <vector>
#include <set>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class SequenceOrSetType : public TypeDescriptor
{
public :
	struct ComponentType
	{
		virtual ~ComponentType() = default;

		virtual bool root() const noexcept = 0;
		virtual std::set< std::string > getDependencies() const = 0;
		virtual std::set< std::string > getStrongDependencies() const = 0;
		virtual std::set< std::string > getWeakDependencies() const = 0;
		virtual bool hasTypeName() const = 0;
		virtual std::string getTypeName() const = 0;
		virtual void generateInstance(std::ostream &os, std::string const &instance_name) const;
		virtual bool isOptional() const = 0;
	};
	struct ComponentsOfType : ComponentType
	{
		typedef std::shared_ptr< TypeDescriptor > Type;

		ComponentsOfType(Type const &type)
			: type_(type)
		{ /* no-op */ }
		virtual bool root() const noexcept override { return false; }
		virtual std::set< std::string > getDependencies() const override { return hasTypeName() ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual std::set< std::string > getStrongDependencies() const override { return (!isOptional() && hasTypeName()) ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual std::set< std::string > getWeakDependencies() const override { return (isOptional() && hasTypeName()) ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual bool hasTypeName() const override { return type_->hasTypeName(); }
		virtual std::string getTypeName() const override { return type_->getTypeName(); }
		virtual bool isOptional() const override { return false; };

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
		virtual std::set< std::string > getDependencies() const override { return hasTypeName() ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual std::set< std::string > getStrongDependencies() const override { return (!isOptional() && hasTypeName()) ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual std::set< std::string > getWeakDependencies() const override { return (isOptional() && hasTypeName()) ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual bool hasTypeName() const override { return named_type_.hasTypeName(); }
		virtual std::string getTypeName() const override { return named_type_.getTypeName(); }
		std::string getName() const { return named_type_.getName(); }
		void generateEncodeImplementation(std::ostream &os, std::string const &member_name) const { named_type_.generateEncodeImplementation(os, member_name); }
		virtual bool isOptional() const override { return optional_; };
		void generateHeaderGettersAndSetters(std::ostream &os) const;
		void generateMemberDeclarations(std::ostream &os) const;

		static std::string toVariableName(std::string const &name);
		static std::string toMemberName(std::string const &name);

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

	virtual std::set< std::string > getDependencies() const override;
	virtual std::set< std::string > getStrongDependencies() const override;
	virtual std::set< std::string > getWeakDependencies() const override;
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateEventHandlers(std::ostream &os) const override;
	virtual bool hasOptionalMembers() const override;
	virtual void generateHeaderGettersAndSetters(std::ostream &os) const override;
	virtual void generateMemberDeclarations(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;

private :
	bool is_set_ = false;
	ComponentTypes component_types_;
};
}}}

#endif



