#ifndef vlinder_rubicon_compiler_directory_hpp
#define vlinder_rubicon_compiler_directory_hpp

#include "modulenamemappings.hpp"
#include "typeassignment.hpp"
#include "valueassignment.hpp"
#include <string>
#include <vector>

namespace Vlinder { namespace Rubicon { namespace Compiler {
class Directory
{
public :
       	typedef std::map< std::string, std::vector< std::string > > ImportedSymbols;

	ModuleNameMappings getModuleNameMappings() const;
	ImportedSymbols getImportedSymbols() const;
	std::vector< std::string > getSymbolsToExport() const;
	std::vector< TypeAssignment > getTypeAssignments() const;
	std::vector< ValueAssignment > getValueAssignments() const;

    std::shared_ptr< TypeDescriptor > findType(std::string const &type_name) const;
	std::shared_ptr< Value > findValue(std::string const &value_name) const;
	
protected :
	std::vector< std::string > symbols_to_export_;
	ModuleNameMappings module_name_mappings_;
	ImportedSymbols imported_symbols_;
	std::vector< TypeAssignment > type_assignments_;
	std::vector< ValueAssignment > value_assignments_;
};
}}}

#endif
