//
// INetworkManager.h for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/NetWork/include
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  9 11:29:51 2013 alexandre teisseire
// Last update Sat Jan 12 18:52:50 2013 alexandre teisseire
//

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
