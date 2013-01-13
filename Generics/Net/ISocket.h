
#pragma once

#include	<string>

#include	"EndPoint.h"

namespace Net
{

enum SocketMode { SERVERMODE, CLIENTMODE };

class ISocket
{
public:
	virtual ~ISocket(void) {}

	/*
	** TCP/UDP : Return true if the socket is on Server Mode
	*/
	virtual bool isServerMode(void) const = 0;

	/*
	** TCP/UDP : Return true if the sokcet is on Client Mode
	*/
	virtual bool isClientMode(void) const = 0;

	/*
	** TCP : Connect the socket to the EndPoint (ClientMode)
	** UDP : Add the EndPoint to the client list. Allow send (ClientMode / ServerMode)
	*/
	virtual void Connect(const EndPoint&) = 0;

	/*
	** TCP : Bind the listen socket on this EndPoint (ServerMode)
	** UDP : Bind the socket on this EndPoint. Allow reception (ClientMode / ServerMode)
	*/
	virtual void Bind(const EndPoint&) = 0;

	/*
	** TCP : Accept connection and Create a new Socket
	** UDP : Assertion fail (should not be used)
	*/
	virtual ISocket* Accept() = 0;

	/*
	** TCP : Send data to the connected EndPoint (ClientMode / ServerMode)
	** UDP : Send data to each EndPoint of the client list (ClientMode / ServerMode)
	*/
	virtual void Send(const std::string&) = 0;

	/*
	** TCP : Recv data from the connected EndPoint (ClientMode / ServerMode)
	** UDP : Recv data from the client (ClientMode / ServerMode)
	*/
	virtual std::string Recv(void) = 0;
};

}			// namespace Net
