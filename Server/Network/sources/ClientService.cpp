
#include "PackMan.h"
#include "PackManUDP.h"
#include "logger.h"
#include "ClientService.h"
#include "IRequest.h"
#include "exceptionSocket.h"
#include "ThreadPool.h"
#include "ThreadPoolWorker.h"

#ifdef WIN32

# ifndef WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
#  define WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
#  include "WinSocketTcp.h"
#  include "WinSocketUdp.h"
# endif

#else
# include "UnixSocketTcp.h"
# include "UnixSocketUdp.h"
#endif

static Net::ISocket*	iniSocket()
{
	Net::ISocket*	s = new Net::SocketUdp(Net::SERVERMODE);
	s->Bind(Net::EndPoint(42999));
	return s;
}

Net::ISocket*	ClientService::UDPsock_ = iniSocket();

ClientService::ClientService(Net::ISocket* s)
	: sock_(s),
	inStorage_(),
	outStorage_(),
	outConsumer_(&outStorage_),
	inConsumer_(&inStorage_),
	outProducer_(&outStorage_),
	worker_(inStorage_, s, this),
	UDPinStorage_(),
	UDPinConsumer_(&UDPinStorage_),
	UDPworker_(UDPinStorage_, ClientService::UDPsock_, this)
{
}

ClientService::~ClientService()
{
	delete this->sock_;
}

void		ClientService::operator()(void)
{
	DEBUG << "Client's Service launched" << std::endl;

	TP::ThreadPool<ClientServiceWorker>*	tp = TP::ThreadPool<ClientServiceWorker>::getInstance(10);

	tp->push(&this->worker_);
	if (tp->isSaturated())
		tp->allocate();
	
	TP::ThreadPool<ClientServiceUDPWorker>*	tUDPp = TP::ThreadPool<ClientServiceUDPWorker>::getInstance(10);

	tUDPp->push(&this->UDPworker_);
	if (tUDPp->isSaturated())
		tUDPp->allocate();

	bool flag = true;

	while (this->worker_.isOnline() && flag)
	{
		TCPPacket* packet = 0;
		while ((packet = this->outConsumer_.consume()) != 0)
		{
			try
			{
			std::string buffer(reinterpret_cast<char const*>(packet), packet->H.size);
			this->sock_->Send(buffer);
			}
			catch (Net::ErrorInOut&)
			{
				DEBUG << "Send fail" << std::endl;
				flag = false;
				break;
			}
			DEBUG << "Packet Sent" << std::endl;
		}
		if (flag)
		{
			DEBUG << "Client Service wait" << std::endl;
			this->outConsumer_.wait();
		}
	}
	DEBUG << "Client Service ended" << std::endl;
}

IRequest*	ClientService::pull()
{
	TCPPacket*	 pack = this->inConsumer_.consume();

	if (pack)
	{
		DEBUG << "Packet Received" << std::endl;
		IRequest* r = PackMan::unpack(pack);

		return r;
	}

	DEBUG << "Null Packet received" << std::endl;
	return 0;
}

void		ClientService::push(IRequest* r)
{
  DEBUG << "Sending request" << std::endl;

  TCPPacket* pack = PackMan::pack(r);

  if (pack)
  DEBUG << "Packet Size : " << pack->H.size
   	<< " ; Pack Type : " << pack->H.type
  	<< " ; Pack Data : " << pack->B << std::endl;
  else
	  DEBUG << "Null Packet" << std::endl;

  this->outProducer_.produce(pack);
}

void		ClientService::push(ICommand* r)
{
	DEBUG << "Client Service UDP push" << std::endl;

	DEBUG << "TODO gameclock" << std::endl;
	UDPPacket* pack = PackManUDP::pack(r, 666, r->getType(), 5555); // todo cmd to pack

	DEBUG << "Packet UDP Size : " << pack->H.size << std::endl
		<< " ; Packet UDP Type : " << pack->H.type << std::endl
		<< " ; Packet UDP Player : " << pack->H.player << std::endl
		<< " ; Packet UDP Clock : " << pack->clock << std::endl
		<< " ; Pack Data : " << pack->value << std::endl;

	try
	{
		std::string buffer(reinterpret_cast<char const*>(pack), sizeof(UDPPacket));
		this->UDPsock_->Send(buffer);
		DEBUG << "UDP SEND SUCCEED" << std::endl;
	}
	catch (Net::ErrorInOut&)
	{
		DEBUG << "UDP SEND FAIL" << std::endl;
	}
}

ICommand*		ClientService::Zpull()
{
	DEBUG << "Client Service UDP pull" << std::endl;

	UDPPacket*	 pack = this->UDPinConsumer_.consume();

	if (pack)
	{
		DEBUG << "UDP Packet Received" << std::endl;
		ICommand* r = PackManUDP::unpack(pack);

		return r;
	}

	DEBUG << "NULL UDP Packet received" << std::endl;
	return 0;

	return 0;
}

void			ClientService::connect(std::string const& e)
{
	this->UDPsock_->Connect(Net::EndPoint(e, 42998));
}
