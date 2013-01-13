
#include	<cstring>

#include	"UnixSocketTcp.h"
#include	"exceptionSocket.h"

namespace Net
{

  SocketTcp::SocketTcp(SocketMode mode)
    : connected_(false), mode_(mode)
  {
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
    this->socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  }

  void SocketTcp::Close_(void)
  {
    close(this->socket_);
  }

  void SocketTcp::Listen_(void)
  {
    listen(this->socket_, 100);
  }

  void SocketTcp::Connect(const EndPoint& ep)
  {
    sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));
    sin.sin_addr.s_addr = inet_addr(ep.getIpStr().c_str());
    sin.sin_family = AF_INET;
    sin.sin_port = htons(ep.getPort());
    if ((connect(this->socket_, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin))) != -1)
      this->connected_ = true;
    else
      throw ErrorInit("Cannot connect to the server");
  }

  void SocketTcp::Bind(const EndPoint& ep)
  {
    sockaddr_in	sin;

    if (!ep.getIp())
      sin.sin_addr.s_addr = htonl(INADDR_ANY);
    else
      sin.sin_addr.s_addr = inet_addr(ep.getIpStr().c_str());
    sin.sin_family = AF_INET;
    sin.sin_port = htons(ep.getPort());
    if ((bind(this->socket_, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin))) == -1)
      throw ErrorInit("Cannot bind the socket");
    this->Listen_();
  }

  ISocket* SocketTcp::Accept()
  {
    SocketTcp* ret = new SocketTcp(SERVERMODE);
    sockaddr_in	sin;
    unsigned int sinlen = sizeof sin;

    if ((ret->socket_ = accept(this->socket_, reinterpret_cast<struct sockaddr*>(&sin), &sinlen)) != -1)
      ret->connected_ = true;
    return (0);
  }

  void SocketTcp::Send(const std::string& packet)
  {
    if (this->connected_)
      if (send(this->socket_, packet.c_str(), packet.size(), 0) == -1)
	throw ErrorInOut("Cannot send data");
  }

  std::string SocketTcp::Recv(void)
  {
    if (this->connected_) {
      char buff[4096] = {0};

      int ret;
      if ((ret = recv(this->socket_, buff, 4095, 0)) == -1)
	throw ErrorInOut("Cannot receive data");
      buff[ret] = 0;
      return (std::string(buff));
    }
    else
      throw std::exception();
  }

}			// namespace Net
