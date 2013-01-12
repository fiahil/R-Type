
#ifdef WIN32
# include "WinSocketTcp.h"
#else
# include "UnixSocketTcp.h"
#endif

#include "logger.h"
#include "ClientService.h"
#include "IRequest.h"

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
	DEBUG << "ClientService pull <TODO> fetch from socket" << std::endl;
	/*
	** THIS IZ LAPIN
	** () ()
	** (o.O)
	** (u u)
	*/
	return 0;
}

void		ClientService::push(IRequest* r)
{
	DEBUG << "Sending request" << std::endl;
	/*
	** THIS IZ LAPIN
	** () ()
	** (o.O)
	** (u u)
	*/
}
