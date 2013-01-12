
#include	<iostream>
#include	<cassert>

#include	"UnixSocketUdp.h"
#include	"exceptionSocket.h"

namespace Net
{

  SocketUdp::SocketUdp(SocketMode)
  {
    this->Create_();
  }

  SocketUdp::~SocketUdp(void)
  {
    this->Close_();
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
    this->socket_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  }

  void SocketUdp::Close_(void)
  {
    close(this->socket_);
  }

  void SocketUdp::Connect(const EndPoint& ep)
  {
    this->client_.push_front(new EndPoint(ep));
  }

  void SocketUdp::Bind(const EndPoint& ep)
  {
    sockaddr_in	sin;

    if (!ep.getIp())
      sin.sin_addr.s_addr = INADDR_ANY;
    else
      sin.sin_addr.s_addr = inet_addr(ep.getIpStr().c_str());
    sin.sin_family = AF_INET;
    sin.sin_port = htons(ep.getPort());
    if ((bind(this->socket_, reinterpret_cast<struct sockaddr*>(&sin), sizeof sin)) == -1)
      throw ErrorInit("Cannot bind the socket");
  }

  ISocket* SocketUdp::Accept()
  {
	assert(0);
	return 0;
  }
  
  void SocketUdp::Send(const std::string& packet)
  {
    sockaddr_in sin;

    for (std::list<EndPoint*>::iterator it = this->client_.begin() ; it != this->client_.end() ; ++it) {
      sin.sin_family = AF_INET;
      sin.sin_addr.s_addr = inet_addr((*it)->getIpStr().c_str());
      sin.sin_port = htons((*it)->getPort());
      if ((sendto(this->socket_, packet.c_str(), packet.size(), 0, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin))) == -1)
	throw ErrorInOut("Cannot send data");
    }
  }

  std::string SocketUdp::Recv(void)
  {
    char buff[4096] = {0};
    sockaddr_in sin;

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = 0;
    unsigned int len = sizeof(sin);

    int ret;
    if ((ret = recvfrom(this->socket_, buff, 4095, 0, reinterpret_cast<struct sockaddr*>(&sin), &len)) == -1)
      throw ErrorInOut("Cannot send data");
    buff[ret] = 0;
    return (std::string(buff));
  }

}			// namespace Net
