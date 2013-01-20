//
// TCPService.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 23:16:13 2013 alexandre teisseire
// Last update Sun Jan 20 22:51:28 2013 alexandre teisseire
//

#include	      <iostream>
#include	<vector>
#include	<string>
#include	<boost/bind.hpp>
#include	"TCPService.hpp"
#include	"PackMan.h"
#include	"CSRequest.h"

TCPService::TCPService(boost::asio::io_service& ios, boost::asio::ip::tcp::endpoint ep) :
  sock(ios)
{
  this->sock.async_connect(ep, boost::bind(&TCPService::handleConnect, this,
					   boost::asio::placeholders::error, ep));
}

TCPService::~TCPService() {}

void			TCPService::recvData()
{
  char *pack = new char[4];
  boost::asio::async_read(this->sock,
  			  boost::asio::buffer(pack, 4),
  			  boost::bind(&TCPService::handleRecv, 
  				      this,
  				      boost::asio::placeholders::error, std::string(pack, 4)));

}

void			TCPService::sendData(TCPPacket *TCPP)
{
  char			*pack = new char[TCPP->H.size + 1];

  PackMan::Memcpy(pack, TCPP, TCPP->H.size);

  boost::asio::async_write(this->sock,
  			  boost::asio::buffer(pack, TCPP->H.size),
  			   boost::bind(&TCPService::handleSend, 
  				       this,
  				       boost::asio::placeholders::error,
  				       pack, TCPP));
}

void			TCPService::retrieveBody(std::string header)
{
  struct TCPPacket::Header *H = new TCPPacket::Header();

  PackMan::Memcpy(H, header.data(), 4);

  char			*pack = new char[H->size - 4];

  boost::asio::async_read(this->sock,
  			  boost::asio::buffer(pack, H->size - 4),
  			  boost::bind(&TCPService::handlePack, this,
  				      boost::asio::placeholders::error, 
  				      header, pack));
}

void			TCPService::handleConnect(const boost::system::error_code& e, boost::asio::ip::tcp::endpoint ep)
{
  std::cout << "Connected to : " << ep << std::endl;
  if (!e)
    { 
       Connect	C(std::string("boby"), std::string("Passwd.pas.Hash.>_<"));
       Connect::parameters param = C.getParam();
       TCPPacket* TCPP = new TCPPacket();
       TCPP->H.size = sizeof(param) + 4;
       TCPP->H.type = C.getType();
       PackMan::Memcpy(TCPP->B, &param, sizeof(param));
       this->sendData(TCPP);

       CreateRoom	CR;
       TCPPacket* TCPP2 = new TCPPacket();
       TCPP2->H.size = 4;
       TCPP2->H.type = CR.getType();
       this->sendData(TCPP2);

    }
  else
    std::cout << "Error --> " << e.message() << " <-- catched while tring to connect to : " << ep << std::endl;
}

void			TCPService::handleRecv(const boost::system::error_code& e, std::string h)
{
  if (!e)
    {
      this->retrieveBody(h);
    }
  else
    std::cout << "[TCP] Recv Error : " << e.message() << " while receiving datas" << std::endl;
}

void			TCPService::handleSend(const boost::system::error_code& error, char* request, TCPPacket *TCPP)
{
  if (!error)
    {
      std::string r(request);
      std::cout << "[TCP] Request : " << r << " successfully sent" << std::endl;
      std::cout << "TCPPacket Data : " << TCPP->H.size << "  ;  " << TCPP->H.type << "  ;  " << TCPP->B << std::endl;
      // delete request;
      // delete TCPP;
    }
  else
    {
      std::cout << "Send Error : " << error.message() << " with the request : " << request << std::endl;
    }
}

void			TCPService::handlePack(const boost::system::error_code&error, std::string header, char *body)
{
  if (!error)
    {
      std::cout << "[TCP] #### Package successfully received ####" << std::endl;

      TCPPacket	*TCPP = new TCPPacket();

      PackMan::Memcpy(&TCPP->H.size, header.substr(0, 2).data(), 2);
      PackMan::Memcpy(&TCPP->H.type, header.substr(2, 4).data(), 2);
      PackMan::Memcpy(TCPP->B, body, TCPP->H.size - 4);

      std::cout << "package type : " << TCPP->H.type << std::endl;
      std::cout << "His size is : " << TCPP->H.size << std::endl;
      std::cout << "and he contains : " << TCPP->B << std::endl;

      IRequest* IR = PackMan::unpack(TCPP);
      if (IR)
      	IR->manageRequest(this);

      // delete header;
      // delete body;
      // delete TCPP;
      
    }
  else
    {
      std::cout << "[TCP] Recv Error : " << error.message() << " while receiving datas" << std::endl;
    }
}

boost::asio::ip::tcp::socket&	TCPService::socket()
{
  return this->sock;
}
