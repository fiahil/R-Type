
#include	<cstring>

#include	"WinSocketTcp.h"
#include	"exceptionSocket.h"

namespace Net
{

SocketTcp::SocketTcp(SocketMode mode)
	: connected_(false), mode_(mode)
{
	WSAStartup(MAKEWORD(2,2), &this->wsa_);
	this->Create_();
}

SocketTcp::~SocketTcp(void)
{
	this->Close_();
	WSACleanup();
}

bool SocketTcp::isServerMode(void) const
{
	return (this->mode_ == SERVERMODE) ? (true) : (false);
}

bool SocketTcp::isClientMode(void) const
{
	return (this->mode_ == CLIENTMODE) ? (true) : (false);
}

void SocketTcp::Create_(void)
{
	this->listenSocket_ = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, 0);
}

void SocketTcp::Close_(void)
{
	closesocket(this->listenSocket_);
	closesocket(this->acceptSocket_);
}

void SocketTcp::Listen_(void)
{
	listen(this->listenSocket_, 100);
}

void SocketTcp::Connect(const EndPoint& ep)
{
	SOCKADDR_IN sin;

    memset(&sin, 0, sizeof(sin));
	sin.sin_addr.s_addr = inet_addr(ep.getIpStr().c_str());
    sin.sin_family = AF_INET;
	WSAHtons(this->listenSocket_, ep.getPort(), &sin.sin_port);
	if ((WSAConnect(this->listenSocket_, reinterpret_cast<SOCKADDR*>(&sin), sizeof sin, 0, 0, 0, 0)) != INVALID_SOCKET) {
		this->connected_ = true;
		this->acceptSocket_ = this->listenSocket_;
	}
	else
		throw ErrorInit("Cannot connect to the server");
}

void SocketTcp::Bind(const EndPoint& ep)
{
	SOCKADDR_IN	sin;

	if (!ep.getIp())
		WSAHtonl(this->listenSocket_, INADDR_ANY, &sin.sin_addr.s_addr);
	else
		sin.sin_addr.s_addr = inet_addr(ep.getIpStr().c_str());
	sin.sin_family = AF_INET;
	WSAHtons(this->listenSocket_, ep.getPort(), &sin.sin_port);
	if ((bind(this->listenSocket_, reinterpret_cast<SOCKADDR*>(&sin), sizeof sin)) == SOCKET_ERROR)
		throw ErrorInit("Cannot bind the socket");
	this->Listen_();
}

ISocket* SocketTcp::Accept()
{
	ISocket* ret = new SocketTcp();
	SOCKADDR_IN	sin;
	int sinlen = sizeof sin;

	if ((this->acceptSocket_ = WSAAccept(this->listenSocket_, reinterpret_cast<SOCKADDR*>(&sin), &sinlen, 0, 0)) != INVALID_SOCKET)
		this->connected_ = true;
	return 0; //tmp
}

void SocketTcp::Send(const std::string& packet)
{
	if (this->connected_)
		if (send(this->acceptSocket_, packet.c_str(), packet.size(), 0) == SOCKET_ERROR)
			throw ErrorInOut("Cannot send data");
}

std::string SocketTcp::Recv(void)
{
	if (this->connected_) {
		char buff[4096] = {0};

		int ret;
		if ((ret = recv(this->acceptSocket_, buff, 4095, 0)) == SOCKET_ERROR)
			throw ErrorInOut("Cannot receive data");
		buff[ret] = 0;
		return (std::string(buff));
	}
	else
		throw std::exception();
}

}			// namespace Net