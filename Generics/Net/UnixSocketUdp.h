
#pragma once

#include	<netdb.h>
#include	<unistd.h>
#include	<arpa/inet.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>

#include	<list>

#include	"ISocket.h"

namespace Net
{

class SocketUdp : public ISocket
{
private:
	int socket_;
	std::list<EndPoint*> client_;

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