//
// UDPService.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan 16 15:12:08 2013 alexandre teisseire
// Last update Sun Jan 20 19:57:14 2013 alexandre teisseire
//
//

#include	<iostream>
#include	<boost/bind.hpp>
#include	"NetworkManager.hpp"
#include	"UDPService.hpp"
#include	"PackMan.h"
#include	"PackManUDP.h"

UDPService::UDPService(NetworkManager& NM, boost::asio::io_service& ios, boost::asio::ip::udp::endpoint ep) :
  NM(NM),
  sock(ios, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 42998)),
  ep(ep),
  pack(new char[sizeof(UDPPacket)])
{
  PackMan::MemSet(this->pack, sizeof(UDPPacket));
}

 UDPService::~UDPService() {}

 void			UDPService::recvData()
 {

   this->sock.async_receive(boost::asio::buffer(this->pack, sizeof(UDPPacket)), 
			    boost::bind(&UDPService::handlePack, this,
					boost::asio::placeholders::error, pack));

 }

 void			UDPService::sendData(UDPPacket *UDPP)
 {
   //char			*pack = new char[UDPP->H.size + 1];
   char			*pack = new char[11];

   //PackMan::Memcpy(pack, UDPP, UDPP->H.size);
//   this->sock.async_send( boost::asio::buffer(pack, UDPP->H.size),
   this->sock.async_send_to( boost::asio::buffer(pack, 10), boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("10.19.253.179"), 42999), 
			    boost::bind(&UDPService::handleSend, 
					this,
					boost::asio::placeholders::error,
					pack, UDPP));
 }

 void			UDPService::retrieveBody(std::string)
 {
 }

 void			UDPService::handleConnect(const boost::system::error_code& , boost::asio::ip::udp::endpoint)
 {
 }

 void			UDPService::handleRecv(const boost::system::error_code&e, char*header)
 {
   if (!e)
     {
       std::cout << "HANDLE RECV : " << header << std::endl;
     }
   else
     std::cout << "Recv Error : " << e.message() << " while receiving datas" << std::endl;
 }

 void			UDPService::handleSend(const boost::system::error_code& error, char* request, UDPPacket *UDPP)
 {
   if (!error)
     {
       std::string r(request);
       std::cout << "[UDP] >> Request : " << r << " successfully sent" << std::endl;
       std::cout << "[UDP] >> UDPPacket Data : " << UDPP->H.size << "  ;  " << UDPP->H.type << "  ;  " << UDPP->value << std::endl;
       // delete request;
       // delete UDPP;
     }
   else
     {
       std::cout << " [UDP] Send Error : " << error.message() << " with the request : " << request << std::endl;
     }
 }

 void			UDPService::handlePack(const boost::system::error_code&error, char *pack)
 {
   if (!error)
     {
       std::cout << "#### [UDP] >> Package successfully received ####" << std::endl;

       std::string header(pack, sizeof(UDPPacket));

       UDPPacket	*UDPP = new UDPPacket();

       PackMan::Memcpy(&UDPP->H.size, header.substr(0, 2).data(), 2);
       PackMan::Memcpy(&UDPP->H.player, header.substr(2, 4).data(), 2);
       PackMan::Memcpy(&UDPP->H.type, header.substr(4, 8).data(), 4);
       PackMan::Memcpy(&UDPP->clock, header.substr(8, 12).data(), 4);

       PackMan::Memcpy(UDPP->value, header.substr(12).data(), UDPP->H.size - 12);

       std::cout << "[UDP] >> package type : " << UDPP->H.type << std::endl;
       std::cout << "[UDP] >> His size is : " << UDPP->H.size << std::endl;
       std::cout << "[UDP] >> and he contains : " << UDPP->value << std::endl;

       // ICommand*	IC = PackManUDP::unpack(UDPP);
       // if (IC)
       // 	 NM.push_back(IC);

      // delete header;
      // delete body;
      // delete UDPP;
      
    }
  else
    {
      std::cout << "[UDP] Recv Error : " << error.message() << " while receiving datas" << std::endl;
    }
}
