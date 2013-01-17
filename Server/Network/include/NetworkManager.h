
#pragma once

#include "IServerService.h"
#include "IClientService.h"

#include "ThreadPool.h"
#include "EndPoint.h"

#include "ServerService.h"
#include "ClientService.h"

class		NetworkManager
{
private:
  IServerService*					SS_;
  TP::ThreadPool<IClientService>*	CS_;

public:
	NetworkManager(Net::EndPoint const&);
	~NetworkManager();

public:
	void	run();
};
