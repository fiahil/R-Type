
#include	<iostream>

#include	<cstring>

#include	"WinSocketTcp.h"
#include	"exceptionSocket.h"

namespace Net
{

bool SocketTcp::isWSAinit_ = false;
WSADATA* SocketTcp::wsa_ = 0;

SocketTcp::SocketTcp(SocketMode mode)
	: connected_(false), mode_(mode)
{
	if (!SocketTcp::isWSAinit_) {
		SocketTcp::wsa_ = new WSADATA;
		WSAStartup(MAKEWORD(2,2), SocketTcp::wsa_);
		SocketTcp::isWSAinit_ = true;
	}
	this->Create_();
}

SocketTcp::~SocketTcp(void)
{
	this->Close_();
}

bool SocketTcp::isServerMode(void) const
{
	return (this->mode_ == SERVERMODE);
}

bool SocketTcp::isClientMode(void) const
{
	return (this->mode_ == CLIENTMODE);
}

void SocketTcp::Create_(void)
{
	this->socket_ = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, 0);
}

void SocketTcp::Close_(void)
{
	closesocket(this->socket_);
}

void SocketTcp::Listen_(void)
{
	listen(this->socket_, 100);
}

void SocketTcp::Connect(const EndPoint& ep)
{
	SOCKADDR_IN sin;

    memset(&sin, 0, sizeof(sin));
	sin.sin_addr.s_addr = inet_addr(ep.getIpStr().c_str());
    sin.sin_family = AF_INET;
	WSAHtons(this->socket_, ep.getPort(), &sin.sin_port);
	if ((WSAConnect(this->socket_, reinterpret_cast<SOCKADDR*>(&sin), sizeof sin, 0, 0, 0, 0)) != INVALID_SOCKET)
		this->connected_ = true;
	else
		throw ErrorInit("Cannot connect to the server");
}

void SocketTcp::Bind(const EndPoint& ep)
{
	SOCKADDR_IN	sin;

	if (!ep.getIp())
		WSAHtonl(this->socket_, INADDR_ANY, &sin.sin_addr.s_addr);
	else
		sin.sin_addr.s_addr = inet_addr(ep.getIpStr().c_str());
	sin.sin_family = AF_INET;
	WSAHtons(this->socket_, ep.getPort(), &sin.sin_port);
	if ((bind(this->socket_, reinterpret_cast<SOCKADDR*>(&sin), sizeof sin)) == SOCKET_ERROR)
		throw ErrorInit("Cannot bind the socket");
	this->Listen_();
}

ISocket* SocketTcp::Accept()
{
	SocketTcp* ret = new SocketTcp(SERVERMODE);
	SOCKADDR_IN	sin;
	int sinlen = sizeof sin;

	if ((ret->socket_ = WSAAccept(this->socket_, reinterpret_cast<SOCKADDR*>(&sin), &sinlen, 0, 0)) != INVALID_SOCKET)
		ret->connected_ = true;
	return (ret);
}

void SocketTcp::Send(const std::string& packet)
{
	if (this->connected_)
		if (send(this->socket_, packet.c_str(), packet.size(), 0) == SOCKET_ERROR)
			throw ErrorInOut("Cannot send data");
}

std::string SocketTcp::Recv(void)
{
	if (this->connected_) {
		char buff[4096] = {0};

		int ret;
		if ((ret = recv(this->socket_, buff, 4095, 0)) == SOCKET_ERROR || ret == 0)
			throw ErrorInOut("Cannot receive data");
		buff[ret] = 0;
		return (std::string(buff, ret));
	}
	else
		throw std::exception();
}

}			// namespace Net