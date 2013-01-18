
#pragma once

#include "Consumer.h"
#include "Storage.h"
#include "Producer.h"
#include "ThreadPoolQueue.h"
#include "UDPPacket.h"
#include "ISocket.h"
#include "EndPoint.h"
#include "IClientService.h"

#ifdef WIN32
# include "WinCondVar.h"
#else
# include "UnixCondVar.h"
#endif

class ClientServiceUDPWorker
{
	typedef PC::Storage<UDPPacket, TP::ThreadPoolQueue<UDPPacket>, LWP::CondVar> UDPstorage;
	typedef PC::Consumer<UDPPacket, UDPstorage> UDPconsumer;
	typedef PC::Producer<UDPPacket, UDPstorage> UDPproducer;

	IClientService*		service_;
	UDPproducer			inProducer_;
	Net::ISocket*		sock_;

public:
	ClientServiceUDPWorker(UDPstorage& in, Net::ISocket* s, IClientService* cs);

	void	operator()();
};