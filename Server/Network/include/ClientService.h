
#pragma once

#include "IClientService.h"
#include "IRequest.h"
#include "ICommand.h"
#include "ISocket.h"
#include "IThread.h"
#include "Storage.h"
#include "Producer.h"
#include "Consumer.h"
#include "TCPPacket.h"
#include "UDPPacket.h"
#include "ClientServiceWorker.h"
#include "ClientServiceUDPWorker.h"

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
	typedef PC::Storage<UDPPacket, TP::ThreadPoolQueue<UDPPacket>, LWP::CondVar> UDPstorage;
	typedef PC::Consumer<UDPPacket, UDPstorage> UDPconsumer;
	typedef PC::Producer<UDPPacket, UDPstorage> UDPproducer;

private:
	Net::ISocket*		sock_;
	//ajout socket UDP
	storage				inStorage_;
	storage				outStorage_;
	consumer			outConsumer_;
	consumer			inConsumer_;
	producer			outProducer_;
	ClientServiceWorker	worker_;

	Net::ISocket*		UDPsock_;
	UDPstorage			UDPinStorage_;
	UDPconsumer			UDPinConsumer_;
	ClientServiceUDPWorker UDPworker_;

public:
	ClientService(Net::ISocket*);
	~ClientService();

	void		operator()(void);
	IRequest*	pull();
	ICommand*	Zpull();
	void		push(IRequest*);
	void		push(ICommand*);
	void		bind(Net::EndPoint const&);
};
