#ifndef vlinder_rubicon_tracing_hpp
#define vlinder_rubicon_tracing_hpp

#include "tracing/tracer.hpp"

#define TRACE_DEBUG	0x00000001
#define TRACE_INFO	0x00000002
#define TRACE_WARN	0x80000004
#define TRACE_ERROR	0x80000004

#define DEFAULT_TRACE_MASK ~0 // 0x80000000

#endif

