#include "directory.hpp"

using namespace std;

namespace Vlinder { namespace Rubicon { namespace Compiler {
ModuleNameMappings Directory::getModuleNameMappings() const
{
        return module_name_mappings_;
}
Directory::ImportedSymbols Directory::getImportedSymbols() const
{
        return imported_symbols_;
}
vector< string > Directory::getSymbolsToExport() const
{
        return symbols_to_export_;
}
vector< TypeAssignment > Directory::getTypeAssignments() const
{
        return type_assignments_;
}
vector< ValueAssignment > Directory::getValueAssignments() const
{
        return value_assignments_;
}

shared_ptr< TypeDescriptor > Directory::findType(string const &type_name) const
{
        auto which(
                  find_if(
                            type_assignments_.begin()
                          , type_assignments_.end()
                          , [=](TypeAssignment const &type_assignment) -> bool {
                                        return type_assignment.getName() == type_name;
                                }
                          )
                );
        if (which != type_assignments_.end())
        {
                return which->getType();
        }
        else
        {
                return shared_ptr< TypeDescriptor >();
        }
}
shared_ptr< Value > Directory::findValue(string const &value_name) const
{
        auto which(
                find_if(
                          value_assignments_.begin()
                        , value_assignments_.end()
                        , [=](ValueAssignment const &value_assignment) -> bool {
                                        return value_assignment.getName() == value_name;
                                }
                        )
                );
        if (which != value_assignments_.end())
        {
                return which->getValue();
        }
        else
        {
                return shared_ptr< Value >();
        }
}
}}}

