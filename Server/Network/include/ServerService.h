
#pragma once

#include "IServerService.h"
#include "ISocket.h"
#include "TCPPacket.h"
#include "IRequest.h"

class		ServerService : public IServerService
{
private:
  Net::ISocket*		sock_;
  Net::EndPoint		ep;

public:

  ServerService(Net::EndPoint const& ep);
  ~ServerService();

public:
  
  virtual IRequest*			pull();
  virtual void				push(IRequest*);
  virtual IClientService*	accept();
};
