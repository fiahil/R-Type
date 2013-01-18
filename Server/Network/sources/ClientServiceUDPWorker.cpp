#include "PackManUDP.h"
#include "logger.h"
#include "ClientService.h"
#include "IRequest.h"
#include "exceptionSocket.h"
#include "ThreadPool.h"
#include "ThreadPoolWorker.h"
#include "ClientServiceUDPWorker.h"

#ifdef WIN32

# ifndef WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
#  define WIN32_LEAN_AND_MEAN_HEADER_PROTECTION
#  include "WinSocketUdp.h"
# endif

#else
# include "UnixSocketUdp.h"
#endif

ClientServiceUDPWorker::ClientServiceUDPWorker(UDPstorage& in, Net::ISocket* s, IClientService* cs)
	: service_(cs), inProducer_(&in), sock_(s)
{
}

void	ClientServiceUDPWorker::operator()()
{
	while (true)
	{
		try
		{
			std::string s(this->sock_->Recv());

			DEBUG << "Packet received by worker" << std::endl;

			UDPPacket*	pack = new UDPPacket();
			PackManUDP::Memcpy(pack, s.data(), s.size());

			DEBUG << "Packet UDP Size : " << pack->H.size
				<< " ; Packet UDP Type : " << pack->H.type
				<< " ; Packet UDP Player : " << pack->H.player
				<< " ; Packet UDP Clock : " << pack->clock
				<< " ; Pack Data : " << pack->value << std::endl;

			this->inProducer_.produce(pack);

			DEBUG << "Packet produced by worker" << std::endl;
		}
		catch (Net::ErrorInOut&)
		{
			DEBUG << "UDP Client Service error" << std::endl;
			break;
		}
	}
}
