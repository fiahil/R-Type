
#pragma once

#ifndef WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
# define WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
# define WIN32_LEAN_AND_MEAN

# include	<winsock2.h>

#endif


#include	<deque>

#include	"ISocket.h"

namespace Net
{

class SocketTcp : public ISocket
{
private:
	bool connected_;
	SOCKET socket_;
	static WSADATA* wsa_;
	static bool isWSAinit_;
	SocketMode mode_;

	void Create_(void);
	void Close_(void);
	void Listen_(void);

	SocketTcp(const SocketTcp&);
	SocketTcp& operator=(const SocketTcp&);

public:
	SocketTcp(SocketMode);
	virtual ~SocketTcp(void);
	virtual bool isServerMode(void) const;
	virtual bool isClientMode(void) const;
	virtual void Connect(const EndPoint&);
	virtual void Bind(const EndPoint&);
	virtual void Send(const std::string&);
	virtual std::string Recv(void);
	virtual ISocket* Accept();
};

}			// namespace Net