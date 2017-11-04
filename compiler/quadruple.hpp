#ifndef rubicon_compiler_quadruple_hpp
#define rubicon_compiler_quadruple_hpp

namespace Vlinder { namespace Rubicon { namespace Compiler {
struct Quadruple
{
	Quadruple(unsigned int group, unsigned int plane, unsigned int row, unsigned int cell)
		: group_(group)
		, plane_(plane)
		, row_(row)
		, cell_(cell)
	{ /* no-op */ }

	unsigned int group_;
	unsigned int plane_;
	unsigned int row_;
	unsigned int cell_;
};
}}}

#endif



