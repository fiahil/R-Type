
#pragma once

#include	<winsock2.h>
#include	<ws2tcpip.h>
#include	<Windows.h>

#pragma comment(lib, "WS2_32")

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