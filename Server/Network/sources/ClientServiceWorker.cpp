
#ifdef WIN32
# include "WinThread.h"
#else
# include "UnixThread.h"
#endif

#include "ClientServiceWorker.h"
#include "PackMan.h"
#include "logger.h"
#include "exceptionSocket.h"
#include "IClientService.h"

ClientServiceWorker::ClientServiceWorker(storage& in, Net::ISocket* s, IClientService* cs)
	: service_(cs), inProducer_(&in), sock_(s), online_(new bool(true)) 
{
}

ClientServiceWorker::~ClientServiceWorker()
{
	delete this->online_;
}

void	ClientServiceWorker::operator()()
{
	while (true)
	{
		try
		{
			std::string	s(this->sock_->Recv());

			DEBUG << "Packet received by worker" << std::endl;

			TCPPacket*	pack = new TCPPacket();
			PackMan::Memcpy(pack, s.data(), s.size());

			  DEBUG << "Packet Size : " << pack->H.size
				  << " ; Pack Type : " << pack->H.type 
				  << " ; Pack Data : " << pack->B << std::endl;

			this->inProducer_.produce(pack);
			DEBUG << "Packet produced by worker" << std::endl;

			IRequest* r = this->service_->pull();
			
			if (r)
			{
				DEBUG << "Manage Request" << std::endl;
				r->manageRequest(this->service_);
			}
		}
		catch (Net::ErrorInOut&)
		{
			DEBUG << "ClientServiceWorker disconnected" << std::endl;
			*this->online_ = false;
			break;
		}
	}
}

bool	ClientServiceWorker::isOnline() const
{
	return *this->online_;
}