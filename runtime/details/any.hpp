#ifndef vlinder_rubicon_details_any_hpp
#define vlinder_rubicon_details_any_hpp

#include "../config.hpp"
#include <new>
#include <algorithm> // for swap
#include <stdexcept> // for std::logic_error

namespace Vlinder { namespace Rubicon { namespace Details {
	struct BadAnyCast : std::logic_error
	{
		BadAnyCast() : std::logic_error("bad any cast") {}
		~BadAnyCast() throw() {}
	};
	struct AnyCarrier
	{
		virtual ~AnyCarrier() {}

		virtual void cloneInto(void *ptr) const = 0;
		virtual void swap(AnyCarrier &rhs) = 0;
	};
	template < typename T >
	struct AnyCarrier_ : AnyCarrier
	{
		AnyCarrier_(const T &v)
			: v_(v)
		{ /* no-op */ }

		/*virtual */void cloneInto(void *ptr) const/* = 0;*/
		{
			new (ptr) AnyCarrier_(*this);
		}

		/*virtual */void swap(AnyCarrier &rhs)/* = 0*/
		{
			using std::swap;
			//TODO handle the case in which the right hand side is of a different type
			swap(v_, static_cast< AnyCarrier_< T >& >(rhs).v_);
		}

		T v_;
	};
	

	class Any;
	template < typename T >
	T any_cast(const Any &any);
	template < typename T >
	T& any_cast(Any &any);

	class Any
	{
	public :
		typedef bool Any::* Bool_;

		Any();
		Any(const Any & any);
		Any& operator=(Any any);
		~Any();

		template < typename T >
		Any(T const &v)
		{
			static_assert(sizeof(Details::AnyCarrier_< T >) <= sizeof(payload_.value_));
			new (payload_.value_) Details::AnyCarrier_< T >(v);
			empty_ = false;
		}

		Any& swap(Any &rhs);

		bool empty() const { return empty_; }
		void clear();

		template < typename T >
		Any& operator=(T v)
		{
			// if this fails, set Details::Config::max_any_type_size__ to a higher value and recompile
			static_assert(sizeof(Details::AnyCarrier_< T >) <= sizeof(payload_.value_));
			if (empty_)
			{
				new (payload_.value_) Details::AnyCarrier_< T >(v);
				empty_ = false;
				
				return *this;
			}
			else
			{
				Any temp(v);
				return swap(temp);
			}
		}

		operator Bool_ () const
		{
			return !empty_ ? &Any::empty_ : 0;
		}

	private :
		static void onBadAnyCast();

		bool empty_;
		union 
		{
			double alignment_;
			char value_[RUBICON_MAX_ANY_SIZE_TYPE + sizeof(Details::AnyCarrier)];
		} payload_;

		template < typename T >
		friend T any_cast(const Any &any);
		template < typename T >
		friend T& any_cast(Any &any);
	};

	template < typename T >
	T any_cast(Any const &any)
	{
		if (any.empty_)
		{
			Any::onBadAnyCast();
			throw std::logic_error("bad any cast not thrown??"); // here to kill a warning
		}
		else if (dynamic_cast< const Details::AnyCarrier_< T >* >(reinterpret_cast< const Details::AnyCarrier* >(any.payload_.value_)) == 0)
		{
			Any::onBadAnyCast();
			throw std::logic_error("bad any cast not thrown??"); // here to kill a warning
		}
		else
		{
			return static_cast< const Details::AnyCarrier_< T >* >(reinterpret_cast< const Details::AnyCarrier* >(any.payload_.value_))->v_;
		}
	}
	template < typename T >
	T& any_cast(Any &any)
	{
		if (any.empty_)
		{
			Any::onBadAnyCast();
			throw std::logic_error("bad any cast not thrown??"); // here to kill a warning
		}
		else if (dynamic_cast< Details::AnyCarrier_< T >* >(reinterpret_cast< Details::AnyCarrier* >(any.payload_.value_)) == 0)
		{
			Any::onBadAnyCast();
			throw std::logic_error("bad any cast not thrown??"); // here to kill a warning
		}
		else
		{
			return static_cast< Details::AnyCarrier_< T >* >(reinterpret_cast< Details::AnyCarrier* >(any.payload_.value_))->v_;
		}
	}
}}}

#endif

