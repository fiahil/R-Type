
#pragma once

#ifndef WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
# define WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
# define WIN32_LEAN_AND_MEAN

# include	<winsock2.h>

#endif

#include	<list>

#include	"ISocket.h"

namespace Net
{

class SocketUdp : public ISocket
{
private:
	SOCKET socket_;
	std::list<EndPoint*> client_;
	static WSADATA* wsa_;
	static bool isWSAinit_;
	SocketMode mode_;

	void Create_(void);
	void Close_(void);

	SocketUdp(const SocketUdp&);
	SocketUdp& operator=(const SocketUdp&);

public:
	SocketUdp(SocketMode);
	virtual ~SocketUdp(void);
	virtual bool isServerMode(void) const;
	virtual bool isClientMode(void) const;
	virtual void Connect(const EndPoint&);
	virtual void Bind(const EndPoint&);
	virtual void Send(const std::string&);
	virtual std::string Recv(void);
	virtual ISocket* Accept();
};

}			// namespace Net