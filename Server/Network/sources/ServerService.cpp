
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
  return 0;
}

void		ServerService::push(IRequest*)
{
  assert(0);
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
