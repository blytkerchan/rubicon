#ifndef rubicon_compiler_dependencies_hpp
#define rubicon_compiler_dependencies_hpp

#include <string>
#include <vector>
#include <map>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Dependencies
{
public :
	typedef std::map< std::string, std::vector< std::string > > Map;
	typedef Map::value_type Entry;

	template < typename InputIterator >
	void add(std::string const &name, InputIterator first, InputIterator last)
	{
		add(name, Entry::second_type(first, last));
	}
	void add(std::string const &name, std::vector< std::string > const &dependencies);
	Map::const_iterator begin() const { return entries_.begin(); }
	Map::const_iterator end() const { return entries_.end(); }

	void clear() { entries_.clear(); }

private :
	Map entries_;
};
}}}
namespace std {
	ostream& operator<<(ostream &os, Vlinder::Rubicon::Compiler::Dependencies const &dependencies);
}

#endif

