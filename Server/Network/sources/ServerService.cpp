//
// ServerService.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Sat Jan 12 18:15:05 2013 alexandre teisseire
// Last update Sat Jan 12 19:09:30 2013 alexandre teisseire
//

#include "ServerService.h"

ServerService::ServerService(Net::EndPoint const&)
{
  // this->sock_ = new Net::SocketTcp();
  // this->sock_.Bind(ep);
}

ServerService::~ServerService() {}

IRequest*	ServerService::pull()
{
  // TCPPacket	P;
  // IRequest*	R = unpack();
  return NULL;
}

void		ServerService::push(IRequest* )
{

}

IClientService*	ServerService::accept()
{
  
}
