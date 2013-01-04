
#pragma once

#include	<netdb.h>
#include	<unistd.h>
#include	<arpa/inet.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>

#include	<deque>

#include	"ISocket.h"

namespace Net
{

  class SocketTcp : public ISocket
  {
  private:
    bool connected_;
    int listenSocket_;
    int acceptSocket_;

    virtual void Create_(void);
    virtual void Close_(void);
    void Listen_(void);

    SocketTcp(const SocketTcp&);
    SocketTcp& operator=(const SocketTcp&);

  public:
    SocketTcp(void);
    virtual ~SocketTcp(void);
    virtual void Connect(const EndPoint&);
    virtual void Bind(const EndPoint&);
    virtual void Send(const std::string&);
    virtual std::string Recv(void);
    void Accept();
  };

}			// namespace Net
