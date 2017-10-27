#ifndef vlinder_rubicon_exceptions_hpp
#define vlinder_rubicon_exceptions_hpp

#include "exceptions/exception.hpp"
namespace Vlinder { namespace Rubicon {
	enum struct Errors {
		  no_error__
		, encoding_error__
		, decoding_error__
		, stack_overflow__
		, parse_error__
		, unresolved_reference__
		};
	typedef Exceptions::Exception< std::runtime_error, Errors, Errors::encoding_error__ > EncodingError;
	typedef Exceptions::Exception< std::runtime_error, Errors, Errors::decoding_error__ > DecodingError;
	typedef Exceptions::Exception< std::runtime_error, Errors, Errors::stack_overflow__ > StackOverflow;
	typedef Exceptions::Exception< std::runtime_error, Errors, Errors::parse_error__ > ParseError;
	typedef Exceptions::Exception< std::runtime_error, Errors, Errors::unresolved_reference__ > UnresolvedReference;
}}

#endif

