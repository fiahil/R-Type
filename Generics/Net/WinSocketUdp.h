
#pragma once

#include	<winsock2.h>
#include	<Windows.h>

#include	<list>

#include	"ISocket.h"

namespace Net
{

class SocketUdp : public ISocket
{
private:
	SOCKET socket_;
	std::list<EndPoint*> client_;
	WSADATA wsa_;

	virtual void Create_(void);
	virtual void Close_(void);

	SocketUdp(const SocketUdp&);
	SocketUdp& operator=(const SocketUdp&);

public:
	SocketUdp(void);
	~SocketUdp(void);
	virtual void Connect(const EndPoint&);
	virtual void Bind(const EndPoint&);
	virtual void Send(const std::string&);
	virtual std::string Recv(void);
};

}			// namespace Net