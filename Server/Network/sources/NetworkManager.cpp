
#include "NetworkManager.h"

NetworkManager::NetworkManager()
	: SS_(new ServerService()), CS_(TP::ThreadPool<IClientService>::getInstance(5))
{
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
		if (this->CS_->isSaturated())
			this->CS_->allocate();
	}
}