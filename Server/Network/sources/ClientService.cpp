
#include "PackMan.h"
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
# endif

#else
# include "UnixSocketTcp.h"
#endif

ClientService::ClientService(Net::ISocket* s)
	: sock_(s),
	inStorage_(),
	outStorage_(),
	outConsumer_(&outStorage_),
	inConsumer_(&inStorage_),
	outProducer_(&outStorage_),
	worker_(inStorage_, s, this)
{
}

ClientService::~ClientService()
{
	delete this->sock_;
}

void		ClientService::operator()(void)
{
	DEBUG << "ClientService functor" << std::endl;

	TP::ThreadPool<ClientServiceWorker>*	tp = TP::ThreadPool<ClientServiceWorker>::getInstance(10);

	tp->push(&this->worker_);
	if (tp->isSaturated())
		tp->allocate();

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
			this->outConsumer_.wait();
	}
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
