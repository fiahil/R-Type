//
// UDPService.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan 16 15:12:08 2013 alexandre teisseire
// Last update Thu Jan 17 19:29:48 2013 alexandre teisseire
//
//

#include	<boost/bind.hpp>
#include	"UDPService.hpp"
#include	"PackMan.h"

UDPService::UDPService(boost::asio::io_service& ios, boost::asio::ip::udp::endpoint ep) :
  sock(ios),
  ep(ep)
{
  this->sock.async_connect(ep, boost::bind(&UDPService::handleConnect, this,
					   boost::asio::placeholders::error, ep));
}

UDPService::~UDPService() {}

void			UDPService::recvData()
{
  char *pack = new char[8];

  this->sock.async_receive( boost::asio::buffer(pack, 8), 
  			  boost::bind(&UDPService::handleRecv, this,
  				      boost::asio::placeholders::error, 
  				      pack));
}

void			UDPService::sendData(UDPPacket *UDPP)
{
  char			*pack = new char[UDPP->H.size + 1];

  PackMan::Memcpy(pack, UDPP, UDPP->H.size);

  this->sock.async_send( boost::asio::buffer(pack, UDPP->H.size),
  			   boost::bind(&UDPService::handleSend, 
  				       this,
  				       boost::asio::placeholders::error,
  				       pack, UDPP));
}

void			UDPService::retrieveBody(std::string header)
{
  struct UDPPacket::Header *H = new UDPPacket::Header();

  PackMan::Memcpy(H, header.data(), 8);

  char			*pack = new char[H->size - 8];
  
  this->sock.async_receive( boost::asio::buffer(pack, H->size - 8),
			      boost::bind(&UDPService::handlePack, this,
					  boost::asio::placeholders::error, 
					  header, pack));
}

void			UDPService::handleConnect(const boost::system::error_code& e, boost::asio::ip::udp::endpoint ep)
{
  if (!e)
    {
      //
      // Send la request de connexion UDP.
      //
      std::cout << "Receiving Datas from : " << ep << std::endl;

      this->recvData();
    }
  else
    std::cout << "Error --> " << e.message() << " <-- catched while tring to connect to : " << ep << std::endl;
}

void			UDPService::handleRecv(const boost::system::error_code& e, char* header)
{
  if (!e)
    {
      this->retrieveBody(std::string(header, 8));
    }
  else
    std::cout << "Recv Error : " << e.message() << " while receiving datas" << std::endl;
}

void			UDPService::handleSend(const boost::system::error_code& error, char* request, UDPPacket *UDPP)
{
  if (!error)
    {
      std::string r(request);
      std::cout << "Request : " << r << " successfully sent" << std::endl;
      std::cout << "UDPPacket Data : " << UDPP->H.size << "  ;  " << UDPP->H.type << "  ;  " << UDPP->value << std::endl;
      // delete request;
      // delete UDPP;
    }
  else
    {
      std::cout << "Send Error : " << error.message() << " with the request : " << request << std::endl;
    }
}

void			UDPService::handlePack(const boost::system::error_code&error, std::string header, char *body)
{
  if (!error)
    {
      std::cout << "#### Package successfully received ####" << std::endl;

      UDPPacket	*UDPP = new UDPPacket();

      PackMan::Memcpy(&UDPP->H.size, header.substr(0, 2).data(), 2);
      PackMan::Memcpy(&UDPP->H.type, header.substr(2, 4).data(), 2);
      PackMan::Memcpy(UDPP->value, body, UDPP->H.size - 4);

      std::cout << "package type : " << UDPP->H.type << std::endl;
      std::cout << "His size is : " << UDPP->H.size << std::endl;
      std::cout << "and he contains : " << UDPP->value << std::endl;

      // IRequest* IR = PackMan::unpack(UDPP);
      // if (IR)
      // 	IR->manageRequest(*this);

      // delete header;
      // delete body;
      // delete UDPP;
      
    }
  else
    {
      std::cout << "Recv Error : " << error.message() << " while receiving datas" << std::endl;
    }
  this->recvData();
}
