//
// ServerService.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Sat Jan 12 18:15:05 2013 alexandre teisseire
// Last update Sat Jan 12 23:05:20 2013 alexandre teisseire
//

#include <cassert>
#include "PackMan.h"
#include "ClientService.h"
#include "ServerService.h"
#include "UnixSocketTcp.h"
// #include "logger.h"

ServerService::ServerService(Net::EndPoint const &ep) :
  ep(ep)
{
  this->sock_ = new Net::SocketTcp(Net::SERVERMODE);
  this->sock_->Bind(ep);
}

ServerService::~ServerService() {}

IRequest*	ServerService::pull()
{
  std::string	s = this->sock_->Recv();
  TCPPacket*	TCPP = new TCPPacket();

  PackMan::Memcpy(&TCPP->H.size, s.substr(0, 2).data(), 2);
  PackMan::Memcpy(&TCPP->H.type, s.substr(2, 4).data(), 2);
  PackMan::Memcpy(TCPP->B, s.substr(4).data(), TCPP->H.size - 4);

  // DEBUG << "Packet Size : " << TCPP->H.size 
  // 	<< " ; Pack Type : " << TCPP->H.type 
  // 	<< " ; Pack Data : " << TCPP->B << std::endl;

  IRequest* IR = PackMan::unpack(TCPP);
  
  return IR;
}

void		ServerService::push(IRequest*)
{
  assert(0);
  // TCPPacket* pack = PackMan::pack(R);
  // std::string s(reinterpret_cast<char*>(pack), pack->H.size);
  // this->sock_->Send(s);
}

IClientService*	ServerService::accept()
{
  // Net::ISocket*	S = this->sock_->Accept();
  // if (S)
  //   {
  //     IClientService*	ICS = new ClientService(S);
  //     return (ICS);
  //   }
  // else
    return NULL;
}
