#include "any.hpp"

namespace Vlinder { namespace Rubicon { namespace Details {
	Any::Any()
		: empty_(true)
	{ /* no-op */ }
	Any::Any(const Any &any)
		: empty_(any.empty_)
	{
		if (!empty_)
		{
			const AnyCarrier *rhs(reinterpret_cast< const AnyCarrier* >(any.payload_.value_));
			rhs->cloneInto(payload_.value_);
		}
		else
		{ /* we're empty :) */ }
	}
	Any& Any::operator=(Any any)
	{
		return swap(any);
	}

	Any::~Any()
	{
		clear();
	}

	Any& Any::swap(Any &rhs)
	{
		using std::swap;
		swap(empty_, rhs.empty_);
		if (!empty_ && !rhs.empty_)
		{
			AnyCarrier *lhs(reinterpret_cast< AnyCarrier* >(payload_.value_));
			lhs->swap(*reinterpret_cast< AnyCarrier* >(rhs.payload_.value_));
		}
		else if (empty_ && !rhs.empty_)
		{	// need to move left-hand-side to right-hand-side
			const AnyCarrier *lhs(reinterpret_cast< AnyCarrier* >(payload_.value_));
			lhs->cloneInto(rhs.payload_.value_);
			lhs->~AnyCarrier();
		}
		else if (!empty_ && rhs.empty_)
		{	// need to move right-hand-side to left-hand-side
			const AnyCarrier *_rhs(reinterpret_cast< AnyCarrier* >(rhs.payload_.value_));
			_rhs->cloneInto(payload_.value_);
			_rhs->~AnyCarrier();
		}
		else
		{ /* no real value to swap */ }
		return *this;
	}

	void Any::clear()
	{
		if (!empty_)
		{
			AnyCarrier *this_carrier(reinterpret_cast< AnyCarrier* >(payload_.value_));
			this_carrier->~AnyCarrier();
		}
		else
		{ /* no real value to swap */ }
		empty_ = true;
	}

	/*static */void Any::onBadAnyCast()
	{
		throw BadAnyCast();
	}
}}}

