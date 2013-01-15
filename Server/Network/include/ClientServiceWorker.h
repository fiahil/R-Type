
#pragma once

#include "Consumer.h"
#include "Storage.h"
#include "Producer.h"
#include "ThreadPoolQueue.h"
#include "TCPPacket.h"
#include "IThread.h"
#include "ISocket.h"

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
	producer		inProducer_;
	LWP::IThread*	thread_;
	Net::ISocket*	sock_;
	volatile bool*	online_;

public:
	ClientServiceWorker(storage& in, Net::ISocket* s);
	~ClientServiceWorker();

	void	launch();
	void	operator()();
	bool	isOnline() const;
};