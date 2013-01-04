
#pragma once

#include	<string>

#include	"EndPoint.h"

namespace Net
{

class ISocket
{
protected:
	virtual void Create_(void) = 0;
	virtual void Close_(void) = 0;

public:
	virtual ~ISocket(void) {}
	virtual void Connect(const EndPoint&) = 0;
	virtual void Bind(const EndPoint&) = 0;
	virtual void Send(const std::string&) = 0;
	virtual std::string Recv(void) = 0;
};

}			// namespace Net