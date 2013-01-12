
#include	<cassert>

#include	"WinSocketUdp.h"
#include	"exceptionSocket.h"

namespace Net
{

SocketUdp::SocketUdp(SocketMode mode) : mode_(mode)
{
	WSAStartup(MAKEWORD(2,2), &this->wsa_);
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
	this->socket_ = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, 0, 0, 0);
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

	for (std::list<EndPoint*>::iterator it = this->client_.begin() ; it != this->client_.end() ; ++it) { 
		sin.sin_family = AF_INET;
		sin.sin_addr.s_addr = inet_addr((*it)->getIpStr().c_str());
		WSAHtons(this->socket_, (*it)->getPort(), &sin.sin_port);
		if ((sendto(this->socket_, packet.c_str(), packet.size(), 0, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin))) == SOCKET_ERROR)
			throw ErrorInOut("Cannot send data");
	}
}

std::string SocketUdp::Recv(void)
{
	char buff[4096] = {0};
	SOCKADDR_IN sin;

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = 0;
	int len = sizeof(sin);

	int ret;
	if ((ret = recvfrom(this->socket_, buff, 4095, 0, reinterpret_cast<struct sockaddr*>(&sin), &len)) == SOCKET_ERROR)
		throw ErrorInOut("Cannot send data");
	buff[ret] = 0;
	return (std::string(buff));
}

}			// namespace Net