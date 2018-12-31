#ifndef vlinder_rubicon_details_buffer_hpp
#define vlinder_rubicon_details_buffer_hpp

namespace Vlinder { namespace Rubicon { namespace Details {
class Buffer
{
public :
	typedef unsigned char value_type;

	virtual ~Buffer() = default;
	virtual void push_back(unsigned char uc) = 0;
};

template < typename T >
class Buffer_ : public Buffer
{
public :
	Buffer_(T &v)
		: v_(v)
	{ /* no-op */ }
	virtual void push_back(unsigned char uc) override
	{
		v_.push_back(uc);
	}

private :
	T &v_;
};
}}}

#endif



