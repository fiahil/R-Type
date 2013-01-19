#include "logger.h"

#include	<cassert>

#include	"WinSocketUdp.h"
#include	"exceptionSocket.h"
#include	"PackManUDP.h"

namespace Net
{

bool SocketUdp::isWSAinit_ = false;
WSADATA* SocketUdp::wsa_ = 0;

SocketUdp::SocketUdp(SocketMode mode) : mode_(mode)
{
	if (!SocketUdp::isWSAinit_) {
		SocketUdp::wsa_ = new WSADATA;
		WSAStartup(MAKEWORD(2,2), SocketUdp::wsa_);
		SocketUdp::isWSAinit_ = true;
	}
	this->Create_();
}

SocketUdp::~SocketUdp(void)
{
	this->Close_();
	WSACleanup();
}

bool SocketUdp::isServerMode(void) const
{
	return (this->mode_ == SERVERMODE) ? (true) : (false);
}

bool SocketUdp::isClientMode(void) const
{
	return (this->mode_ == CLIENTMODE) ? (true) : (false);
}

void SocketUdp::Create_(void)
{
	this->socket_ = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, 0, 0, WSA_FLAG_OVERLAPPED);
}

void SocketUdp::Close_(void)
{
	closesocket(this->socket_);
}

void SocketUdp::Connect(const EndPoint& ep)
{
	this->client_.push_front(new EndPoint(ep));
}

void SocketUdp::Bind(const EndPoint& ep)
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
}

ISocket* SocketUdp::Accept()
{
	assert(0);
	return (0);
}

void SocketUdp::Send(const std::string& packet)
{
	SOCKADDR_IN sin;

	DEBUG << "Sending in progress" << std::endl;
	for (std::list<EndPoint*>::iterator it = this->client_.begin() ; it != this->client_.end() ; ++it) { 
		sin.sin_family = AF_INET;
		sin.sin_addr.s_addr = inet_addr((*it)->getIpStr().c_str());
		WSAHtons(this->socket_, (*it)->getPort(), &sin.sin_port);

		WSABUF* fb = new WSABUF();
		CHAR* buffer = new CHAR[sizeof(UDPPacket)];
		PackManUDP::Memcpy(buffer, packet.data(), packet.size());
		fb->buf = buffer;
		fb->len = sizeof(UDPPacket);

		DWORD sended = 0;

		if (WSASendTo(this->socket_, fb, 1, &sended, 0, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin), 0, 0) == SOCKET_ERROR)
			throw ErrorInOut("Cannot send data");
		DEBUG << "Sending completed" << std::endl;

		delete fb;
		delete buffer;
	}
}

std::string SocketUdp::Recv(void)
{
	SOCKADDR_IN sin;

	int len = sizeof(sin);

	char* buff = new char[sizeof(UDPPacket)];
	DWORD flags = 0;
	DWORD ret = 0;
	WSABUF* fb = new WSABUF();
	fb->buf = buff;
	fb->len = sizeof(UDPPacket);


	DWORD error = WSARecvFrom(this->socket_, fb, 1, &ret, &flags, reinterpret_cast<struct sockaddr*>(&sin), &len, 0, 0);
	if (error == SOCKET_ERROR && WSAGetLastError() != WSAEMSGSIZE)
		throw ErrorInOut("Cannot recv data");

	DEBUG << "Receiving complete" << std::endl;

	std::string pack = std::string(buff, ret);

	delete fb;
	delete buff;

	return (pack);
}

}			// namespace Net