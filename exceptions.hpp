#ifndef vlinder_rubicon_exceptions_hpp
#define vlinder_rubicon_exceptions_hpp

#include "exceptions/exception.hpp"
namespace Vlinder { namespace Rubicon {
	enum struct Errors {
		  no_error__
		, encoding_error__
		, decoding_error__
		};
	typedef Exceptions::Exception< std::runtime_error, Errors, Errors::encoding_error__ > EncodingError;
	typedef Exceptions::Exception< std::runtime_error, Errors, Errors::decoding_error__ > DecodingError;
}}

#endif

