//
// ServerService.h for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/NetWork/include
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  9 11:36:32 2013 alexandre teisseire
// Last update Wed Jan  9 11:41:42 2013 alexandre teisseire
//

#pragma once

#include "IServerService.h"
#include "ISocket.h"
#include "TCPPacket.h"

class		ServerService : public IServerService
{
private:
	Net::ISocket*		sock_;

public:
	ServerService(Net::EndPoint const& ep);
	~ServerService();

	virtual IRequest*			pull();
	virtual void				push(IRequest*);
	virtual IClientService*		accept();
};
