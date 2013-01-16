
#pragma once

#include "Consumer.h"
#include "Storage.h"
#include "Producer.h"
#include "ThreadPoolQueue.h"
#include "TCPPacket.h"
#include "ISocket.h"
#include "IClientService.h"

#ifdef WIN32
# include "WinCondVar.h"
#else
# include "UnixCondVar.h"
#endif

class ClientServiceWorker
{
	typedef PC::Storage<TCPPacket, TP::ThreadPoolQueue<TCPPacket>, LWP::CondVar> storage;
	typedef PC::Consumer<TCPPacket, storage> consumer;
	typedef PC::Producer<TCPPacket, storage> producer;

private:
	IClientService*	service_;
	producer		inProducer_;
	Net::ISocket*	sock_;
	volatile bool*	online_;

public:
	ClientServiceWorker(storage& in, Net::ISocket* s, IClientService* cs);
	~ClientServiceWorker();

	void	operator()();
	bool	isOnline() const;
};