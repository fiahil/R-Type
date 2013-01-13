
#include "PackMan.h"
#include "logger.h"
#include "ClientService.h"
#include "IRequest.h"

#ifdef WIN32

# ifndef WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
#  define WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
#  include "WinSocketTcp.h"
# endif

#else
# include "UnixSocketTcp.h"
#endif

ClientService::ClientService(Net::ISocket* s)
	: sock_(s)
{
}

ClientService::~ClientService()
{
	delete this->sock_;
}

void		ClientService::operator()(void)
{
	DEBUG << "ClientService functor" << std::endl;

}

IRequest*	ClientService::pull()
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
  return 0;
}

void		ClientService::push(IRequest* r)
{
  DEBUG << "Sending request" << std::endl;
  TCPPacket* pack = PackMan::pack(r);
  std::string s(reinterpret_cast<char*>(pack), pack->H.size);
  this->sock_->Send(s);
}
