
#include	<cstring>

#include	"UnixSocketTcp.h"
#include	"exceptionSocket.h"

namespace Net
{

  SocketTcp::SocketTcp(void)
    : connected_(false)
  {
    this->Create_();
  }

  SocketTcp::~SocketTcp(void)
  {
    this->Close_();
  }

  void SocketTcp::Create_(void)
  {
    this->listenSocket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    std::cout << "Id socket : " << this->listenSocket_ << std::endl;
  }

  void SocketTcp::Close_(void)
  {
    close(this->listenSocket_);
    close(this->acceptSocket_);
  }

  void SocketTcp::Listen_(void)
  {
    listen(this->listenSocket_, 100);
  }

  void SocketTcp::Connect(const EndPoint& ep)
  {
    sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));
    sin.sin_addr.s_addr = inet_addr(ep.getIpStr().c_str());
    sin.sin_family = AF_INET;
    sin.sin_port = htons(ep.getPort());
    if ((connect(this->listenSocket_, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin))) != -1) {
      this->connected_ = true;
      this->acceptSocket_ = this->listenSocket_;
    }
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
    if ((bind(this->listenSocket_, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin))) == -1)
      throw ErrorInit("Cannot bind the socket");
    this->Listen_();
  }

  void SocketTcp::Accept()
  {
    sockaddr_in	sin;
    unsigned int sinlen = sizeof sin;

    if ((this->acceptSocket_ = accept(this->listenSocket_, reinterpret_cast<struct sockaddr*>(&sin), &sinlen)) != -1)
      this->connected_ = true;
  }

  void SocketTcp::Send(const std::string& packet)
  {
    if (this->connected_)
      if (send(this->acceptSocket_, packet.c_str(), packet.size(), 0) == -1)
	throw ErrorInOut("Cannot send data");
  }

  std::string SocketTcp::Recv(void)
  {
    if (this->connected_) {
      char buff[4096] = {0};

      int ret;
      if ((ret = recv(this->acceptSocket_, buff, 4095, 0)) == -1)
	throw ErrorInOut("Cannot receive data");
      buff[ret] = 0;
      return (std::string(buff));
    }
    else
      throw std::exception();
  }

}			// namespace Net
