
#pragma once

#include "IClientService.h"
#include "IRequest.h"
#include "ISocket.h"
#include "IThread.h"
#include "Storage.h"
#include "Producer.h"
#include "Consumer.h"
#include "TCPPacket.h"
#include "ClientServiceWorker.h"

#ifdef WIN32
# include "WinCondVar.h"
#else
# include "UnixCondVar.h"
#endif

class ClientService : public IClientService
{
	typedef PC::Storage<TCPPacket, TP::ThreadPoolQueue<TCPPacket>, LWP::CondVar> storage;
	typedef PC::Consumer<TCPPacket, storage> consumer;
	typedef PC::Producer<TCPPacket, storage> producer;

private:
	Net::ISocket*		sock_;
	storage				inStorage_;
	storage				outStorage_;
	consumer			outConsumer_;
	consumer			inConsumer_;
	producer			outProducer_;
	ClientServiceWorker	worker_;

public:
	ClientService(Net::ISocket*);
	~ClientService();

	void		operator()(void);
	IRequest*	pull();
	void		push(IRequest*);
};
