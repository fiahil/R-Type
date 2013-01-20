//
// TCPService.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 23:16:13 2013 alexandre teisseire
// Last update Sun Jan 20 01:28:08 2013 alexandre teisseire
//

#include	<vector>
#include	<boost/shared_ptr.hpp>
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
  boost::shared_ptr<std::vector<char> > data(new std::vector<char>);

  boost::asio::async_read(this->sock,
  			  boost::asio::buffer(*data),
			  boost::bind(&TCPService::handleRecv, 
				      this,
				      boost::asio::placeholders::error));
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
  std::cout << "Header Size :" << H->size << " ; Header Type : " << H->type << std::endl;

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

      //
      // Launch GUI
      //

      // Connect	C(std::string("boby"), std::string("Passwd.pas.Hash.>_<"));
      // Connect::parameters param = C.getParam();
      // TCPPacket* TCPP = new TCPPacket();
      // TCPP->H.size = sizeof(param) + 4;
      // TCPP->H.type = C.getType();
      // PackMan::Memcpy(TCPP->B, &param, sizeof(param));
      // this->sendData(TCPP);

      // CreateRoom	CR;
      // TCPPacket* TCPP2 = new TCPPacket();
      // TCPP2->H.size = 4;
      // TCPP2->H.type = CR.getType();
      // this->sendData(TCPP2);

      // JoinRoom		JR(0);
      // JoinRoom::parameters param1 = JR.getParam();
      // TCPPacket* TCPP3 = new TCPPacket();
      // TCPP3->H.size = sizeof(param1) + 4;
      // TCPP3->H.type = JR.getType();
      // PackMan::Memcpy(TCPP3->B, &param1, sizeof(param1));
      // this->sendData(TCPP3);

      // LeaveRoom		LR(0);
      // LeaveRoom::parameters param2 = LR.getParam();
      // TCPPacket* TCPP4 = new TCPPacket();
      // TCPP4->H.size = sizeof(param2) + 4;
      // TCPP4->H.type = LR.getType();
      // PackMan::Memcpy(TCPP4->B, &param2, sizeof(param2));
      // this->sendData(TCPP4);

      // JoinRoom		JR2(0);
      // JoinRoom::parameters param3 = JR2.getParam();
      // TCPPacket* TCPP5 = new TCPPacket();
      // TCPP5->H.size = sizeof(param3) + 4;
      // TCPP5->H.type = JR2.getType();
      // PackMan::Memcpy(TCPP5->B, &param3, sizeof(param3));
      // this->sendData(TCPP5);

      // Connect	C2(std::string("Jacky"), std::string("Passwd.pas.Hash.>_<"));
      // Connect::parameters param4 = C2.getParam();
      // TCPPacket* TCPP6 = new TCPPacket();
      // TCPP6->H.size = sizeof(param4) + 4;
      // TCPP6->H.type = C.getType();
      // PackMan::Memcpy(TCPP6->B, &param4, sizeof(param4));
      // this->sendData(TCPP6);

      // // std::string	s("Jacky");
      // // InvitePlayer	IP(s.c_str(), 42);
      // // InvitePlayer::parameters param5 = IP.getParam();
      // // TCPPacket* TCPP7 = new TCPPacket();
      // // TCPP7->H.size = sizeof(param5) + 4;
      // // TCPP7->H.type = IP.getType();
      // // PackMan::Memcpy(TCPP7->B, &param5, sizeof(param5));
      // // this->sendData(TCPP7);

      // JoinRoom		JR3(0);
      // JoinRoom::parameters param12 = JR3.getParam();
      // TCPPacket* TCPP12 = new TCPPacket();
      // TCPP12->H.size = sizeof(param12) + 4;
      // TCPP12->H.type = JR3.getType();
      // PackMan::Memcpy(TCPP12->B, &param12, sizeof(param12));
      // this->sendData(TCPP12);

      // LaunchGame	IP2(0);
      // LaunchGame::parameters param6 = IP2.getParam();
      // TCPPacket* TCPP8 = new TCPPacket();
      // TCPP8->H.size = sizeof(param6) + 4;
      // TCPP8->H.type = IP2.getType();
      // PackMan::Memcpy(TCPP8->B, &param6, sizeof(param6));
      // this->sendData(TCPP8);
    }
  else
    std::cout << "Error --> " << e.message() << " <-- catched while tring to connect to : " << ep << std::endl;
}

void			TCPService::handleRecv(const boost::system::error_code& e)
{
  if (!e)
    {
      // this->retrieveBody(std::string(header, 4));
      // delete[] header;
    }
  else
    std::cout << "Recv Error : " << e.message() << " while receiving datas" << std::endl;
}

void			TCPService::handleSend(const boost::system::error_code& error, char* request, TCPPacket *TCPP)
{
  if (!error)
    {
      std::string r(request);
      std::cout << "Request : " << r << " successfully sent" << std::endl;
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
      std::cout << "#### Package successfully received ####" << std::endl;

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
      std::cout << "Recv Error : " << error.message() << " while receiving datas" << std::endl;
    }
}
