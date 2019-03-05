#ifndef rubicon_compiler_sequenceorsettype_hpp
#define rubicon_compiler_sequenceorsettype_hpp

#include "typedescriptor.hpp"
#include "namedtype.hpp"
#include "value.hpp"
#include <memory>
#include <vector>
#include <set>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class AutoTagVisitor;
class ComponentsOfResolutionVisitor;
class SequenceOrSetType : public TypeDescriptor
{
public :
	struct ComponentType
	{
		ComponentType(SourceLocation const &source_location)
			: source_location_(source_location)
		{ /* no-op */ }
		virtual ~ComponentType() = default;

		SourceLocation getSourceLocation() const { return source_location_; }
		virtual bool root() const noexcept = 0;
		virtual void setRoot(bool value) noexcept = 0;
		virtual std::set< std::string > getDependencies() const = 0;
		virtual std::set< std::string > getStrongDependencies() const = 0;
		virtual std::set< std::string > getWeakDependencies() const = 0;
		virtual bool hasTypeName() const = 0;
		virtual std::string getTypeName() const = 0;
		virtual void generateInstance(std::ostream &os, std::string const &instance_name) const;
		virtual bool isOptional() const = 0;
		virtual bool hasDefaultValue() const { false; }
		virtual std::shared_ptr< ComponentType > visit(AutoTagVisitor &visitor) = 0;
		virtual std::shared_ptr< ComponentType > visit(ComponentsOfResolutionVisitor &visitor) = 0;

		SourceLocation source_location_;
	};
	struct ComponentsOfType : ComponentType
	{
		typedef std::shared_ptr< TypeDescriptor > Type;

		ComponentsOfType(SourceLocation const &source_location, Type const &type)
			: ComponentType(source_location)
			, type_(type)
		{ /* no-op */ }
		virtual bool root() const noexcept override { return false; }
		virtual void setRoot(bool value) noexcept override { assert(!value); }
		virtual std::set< std::string > getDependencies() const override { return hasTypeName() ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual std::set< std::string > getStrongDependencies() const override { return (!isOptional() && hasTypeName()) ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual std::set< std::string > getWeakDependencies() const override { return (isOptional() && hasTypeName()) ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual bool hasTypeName() const override { return type_->hasTypeName(); }
		virtual std::string getTypeName() const override { return type_->getTypeName(); }
		virtual bool isOptional() const override { return false; };
		virtual std::shared_ptr< ComponentType > visit(AutoTagVisitor &visitor) override;
		virtual std::shared_ptr< ComponentType > visit(ComponentsOfResolutionVisitor &visitor) override;

		Type type_;
	};
	struct NamedComponentType : ComponentType
	{
		NamedComponentType(SourceLocation const &source_location, bool root, NamedType const &named_type, bool optional = false)
			: ComponentType(source_location)
			, root_(root)
			, named_type_(named_type)
			, optional_(optional)
		{ /* no-op */ }

		NamedComponentType(SourceLocation const &source_location, bool root, NamedType const &named_type, std::shared_ptr< Value > const &default_value)
			: ComponentType(source_location)
			, root_(root)
			, named_type_(named_type)
			, optional_(true)
			, default_value_(default_value)
		{ /* no-op */ }
		NamedComponentType(NamedComponentType const&) = default;
		NamedComponentType(NamedComponentType &&) = default;
		NamedComponentType& operator=(NamedComponentType const&) = delete;
		NamedComponentType& operator=(NamedComponentType &&) = default;

		virtual bool root() const noexcept override { return root_; }
		virtual void setRoot(bool value) noexcept override { root_ = value; }
		virtual std::set< std::string > getDependencies() const override { return hasTypeName() ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual std::set< std::string > getStrongDependencies() const override { return (!isOptional() && hasTypeName()) ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual std::set< std::string > getWeakDependencies() const override { return (isOptional() && hasTypeName()) ? std::set< std::string >{ getTypeName() } : std::set< std::string >(); }
		virtual bool hasTypeName() const override { return named_type_.hasTypeName(); }
		virtual std::string getTypeName() const override { return named_type_.getTypeName(); }
		std::string getName() const { return named_type_.getName(); }
		void generateEncodeImplementation(std::ostream &os, std::string const &member_name) const { /*named_type_.generateEncodeImplementation(os, member_name);*/ }
		virtual bool isOptional() const override { return optional_; }
		virtual bool hasDefaultValue() const override { return (bool)default_value_; }
		void generateHeaderGetterAndSetter(std::ostream &os) const;
		void generateMemberDeclarations(std::ostream &os) const;
		void generateGetterImplementation(std::string const &type_name, std::ostream &os) const;
		void generateSetterImplementation(std::string const &type_name, std::ostream &os) const;
		virtual std::shared_ptr< ComponentType > visit(AutoTagVisitor &visitor) override;
		virtual std::shared_ptr< ComponentType > visit(ComponentsOfResolutionVisitor &visitor) override;

		static std::string toVariableName(std::string const &name);
		static std::string toMemberName(std::string const &name);

		bool root_;
		NamedType named_type_;
		bool optional_;
		std::shared_ptr< Value > default_value_;
	};
	typedef std::vector< std::shared_ptr< ComponentType > > ComponentTypes;
	struct ComponentTypeList : ComponentType
	{
		ComponentTypeList(SourceLocation const &source_location, ComponentTypes::const_iterator first, ComponentTypes::const_iterator last)
			: ComponentType(source_location)
			, components_(first, last)
		{ /* no-op */ }

		virtual bool root() const noexcept override { return false; };
		virtual void setRoot(bool value) noexcept override { assert(!value); }
		virtual std::set< std::string > getDependencies() const override;
		virtual std::set< std::string > getStrongDependencies() const override;
		virtual std::set< std::string > getWeakDependencies() const override;
		virtual bool hasTypeName() const override;
		virtual std::string getTypeName() const override;
		virtual bool isOptional() const override;
		virtual std::shared_ptr< ComponentType > visit(AutoTagVisitor &visitor) override;
		virtual std::shared_ptr< ComponentType > visit(ComponentsOfResolutionVisitor &visitor) override;

		ComponentTypes components_;
	};

	SequenceOrSetType(SourceLocation const &source_location)
		: TypeDescriptor(source_location)
	{ /* no-op */ }
	SequenceOrSetType(SourceLocation const &source_location, bool is_set, ComponentTypes const &component_types)
		: TypeDescriptor(source_location)
		, is_set_(is_set)
		, component_types_(component_types)
	{ /* no-op */ }

	virtual Tag getTag() const override { return { Tag::universal__, is_set_ ? 17U : 16U }; }
	virtual std::shared_ptr< TypeDescriptor > visit(Resolver &resolver) override { return resolver.resolve(*this); }
	void visit(AutoTagVisitor &visitor);
	void visit(ComponentsOfResolutionVisitor &visitor);
	void flatten();
	virtual std::set< std::string > getDependencies() const override;
	virtual std::set< std::string > getStrongDependencies() const override;
	virtual std::set< std::string > getWeakDependencies() const override;
	virtual void generateEncodeImplementation(std::ostream &os) const override;
	virtual void generateEventHandlers(std::ostream &os) const override;
	virtual bool hasOptionalMembers() const override;
	virtual void generateHeaderGettersAndSetters(std::ostream &os) const override;
	virtual void generateMemberDeclarations(std::ostream &os) const override;
	virtual void generateCopyConstructorImplementation(std::ostream &os) const override;
	virtual void generateDestructorImplementation(std::ostream &os) const override;
	virtual void generateSwapparatorImplementation(std::ostream &os) const override;
	virtual void generateGetterAndSetterImplementations(std::string const &type_name, std::ostream &ofs) const override;
	bool isSet() const { return is_set_; }
	ComponentTypes::size_type getComponentTypeCount() const noexcept { return component_types_.size(); } 

private :
	bool is_set_ = false;
	ComponentTypes component_types_;
};
}}}

#endif



