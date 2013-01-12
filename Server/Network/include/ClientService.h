
#pragma once

#include "IClientService.h"
#include "IRequest.h"
#include "ISocket.h"

class ClientService : public IClientService
{
private:
	Net::ISocket*	sock_;

public:
	ClientService(Net::EndPoint const&);
	~ClientService();

	void		operator()(void);
	IRequest*	pull();
	void		push(IRequest*);
};
