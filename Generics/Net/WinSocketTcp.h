
#pragma once

#include	<winsock2.h>
#include	<ws2tcpip.h>
#include	<Windows.h>

#include	<deque>

#include	"ISocket.h"

namespace Net
{

class SocketTcp : public ISocket
{
private:
	bool connected_;
	SOCKET listenSocket_;
	SOCKET acceptSocket_;
	WSADATA wsa_;

	virtual void Create_(void);
	virtual void Close_(void);
	void Listen_(void);

	SocketTcp(const SocketTcp&);
	SocketTcp& operator=(const SocketTcp&);

public:
	SocketTcp(void);
	virtual ~SocketTcp(void);
	virtual void Connect(const EndPoint&);
	virtual void Bind(const EndPoint&);
	virtual void Send(const std::string&);
	virtual std::string Recv(void);
	void Accept();
};

}			// namespace Net