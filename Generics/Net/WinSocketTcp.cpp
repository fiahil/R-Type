
#include "logger.h"

#include	<cstring>

#include	"WinSocketTcp.h"
#include	"exceptionSocket.h"
#include	"PackMan.h"

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
	this->socket_ = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, WSA_FLAG_OVERLAPPED);
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
	DEBUG << "Sending in progress" << std::endl;
	if (this->connected_)
	{
		WSABUF* fb = new WSABUF();
		CHAR* buffer = new CHAR[packet.size()];
		PackMan::Memcpy(buffer, packet.data(), packet.size());
		fb->buf = buffer;
		fb->len = packet.size();

		DWORD sended;

		if (WSASend(this->socket_, fb, 1, &sended, 0, 0, 0) == SOCKET_ERROR)
			throw ErrorInOut("Cannot send data");
		DEBUG << "Sending completed" << std::endl;
	}
}

std::string SocketTcp::Recv(void)
{
	if (this->connected_) {
		char *buff = new char[4];

		DWORD ret = 0;
		WSABUF* fb = new WSABUF();
		fb->buf = buff;
		fb->len = 4;

		DWORD l = MSG_WAITALL;

		if (WSARecv(this->socket_, fb, 1, &ret, &l, 0, 0) == SOCKET_ERROR || ret == 0)
		{
			int err = WSAGetLastError();
			if (err == WSAECONNRESET || err == WSAENETRESET || err == WSAECONNABORTED || ret == 0)
				throw ErrorInOut("Disconnect");
		}

		union
		{
			char s[2];
			short sh;
		} size;

		size.s[0] = buff[0];
		size.s[1] = buff[1];

		DEBUG << "HEADER RECEIVED !"
			<< "Packet size - " << size.sh
			<< "Packet type - " << size.s << std::endl;

		if (size.sh - 4 > 0)
		{
			char* body = new char[size.sh];

			WSABUF* fbody = new WSABUF();
			fbody->buf = body;
			fbody->len = size.sh - 4;

			DWORD retl;
			DWORD ll = MSG_WAITALL;

			if (WSARecv(this->socket_, fbody, 1, &retl, &ll, 0, 0) == SOCKET_ERROR)
			{
				int err = WSAGetLastError();
				if (err == WSAECONNRESET || err == WSAENETRESET || err == WSAECONNABORTED)
					throw ErrorInOut("Disconnect");
			}

			std::string concated(std::string(buff, ret) + std::string(body, size.sh));
			DEBUG << "Concatenation successfull : " << concated << std::endl;

			return concated;
		}
		else
		{
			DEBUG << "BAD Packet size : " << size.sh << std::endl;
			return std::string(buff, 4);
		}
	}
	else
		throw ErrorInit("Try to receive data on a not connected socket");
}

}			// namespace Net