
#ifdef WIN32
# include "WinThread.h"
#else
# include "UnixThread.h"
#endif

#include "ClientServiceWorker.h"
#include "PackMan.h"
#include "logger.h"
#include "exceptionSocket.h"

ClientServiceWorker::ClientServiceWorker(storage& in, Net::ISocket* s)
	: inProducer_(&in), thread_(0), sock_(s), online_(new bool(false)) 
{
	this->thread_ = new LWP::Thread<ClientServiceWorker>(*this);
}

ClientServiceWorker::~ClientServiceWorker()
{
	delete this->thread_;
	delete this->online_;
}

void	ClientServiceWorker::launch()
{
	this->thread_->launch();
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