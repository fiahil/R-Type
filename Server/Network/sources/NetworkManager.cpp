
#include "NetworkManager.h"
#include "logger.h"

NetworkManager::NetworkManager(Net::EndPoint const& ep)
	: SS_(new ServerService(ep)), CS_(TP::ThreadPool<IClientService>::getInstance(5))
{
	DEBUG << "NetworkManager created" << std::endl;
}

NetworkManager::~NetworkManager()
{
	delete this->SS_;
}

void	NetworkManager::run()
{
	while (true)
	{
		this->CS_->push(this->SS_->accept());

		DEBUG << "Accept connection" << std::endl;

		if (this->CS_->isSaturated())
		{
			DEBUG << "ServicePool is saturated. Allocate new chunk" << std::endl;
			this->CS_->allocate();
		}
	}
}