#ifndef rubicon_compiler_characterstringtype_hpp
#define rubicon_compiler_characterstringtype_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
class CharacterStringType : public TypeDescriptor
{
public :
	CharacterStringType() = default;
	CharacterStringType(std::string const &character_class)
		: character_class_(character_class)
	{ /* no-op */ }

	~CharacterStringType() = default;

	bool restricted() const { return !character_class_.empty(); }

private :
	std::string character_class_;
};
}}}

#endif


