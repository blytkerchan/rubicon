#ifndef rubicon_compiler_tuple_hpp
#define rubicon_compiler_tuple_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct Tuple
{
	Tuple(unsigned int table_column, unsigned int table_row)
		: table_column_(table_column)
		, table_row_(table_row)
	{ /* no-op */ }

	unsigned int table_column_;
	unsigned int table_row_;
};
}}}

#endif



