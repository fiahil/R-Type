
#include <cassert>
#include "PackMan.h"
#include "ClientService.h"
#include "ServerService.h"

#ifdef WIN32

# ifndef WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
#  define WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
#  include "WinSocketTcp.h"
# endif

#else
# include "UnixSocketTcp.h"
#endif

#include "logger.h"

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

  DEBUG << "Packet Size : " << TCPP->H.size 
   	<< " ; Pack Type : " << TCPP->H.type 
  	<< " ; Pack Data : " << TCPP->B << std::endl;

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
	Net::ISocket*	S = this->sock_->Accept();
	if (S)
	{
		IClientService*	ICS = new ClientService(S);
		return (ICS);
	}
	return 0;
}
