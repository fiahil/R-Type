//
// test_client_S.hpp for RType in /home/teisse_a//Documents/Tek3/RType/Client
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Sun Jan 13 03:03:13 2013 alexandre teisseire
// Last update Sun Jan 13 04:41:17 2013 alexandre teisseire
//

#ifndef	_TEST_2H_
#define _TEST_2H_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include "TCPPacket.h"


enum			eRequestType
  {
    CONNECT = 1201,
    CREATE_ROOM = 1202,
    LEAVE_ROOM = 1203,
    JOIN_ROOM = 1204,
    INVITE_PLAYER = 1205,
    SET_GAME_PARAM = 1206,
    LAUNCH_GAME = 1207,
    PING = 1208,
    READY = 1209,
    ANSWER_CREATE_ROOM = 1301,
    START_DATA_STREAM = 1302,
    STREAM = 1303,
    STOP_DATA_STREAM = 1304,
    CLIENT_INVITED = 1305,
    ACK_ = 1306,
    GAME_LAUNCHED = 1307
  };

class		PackMan
{
  template<typename S>
  static void* MemSet(S* dest, std::size_t c)
  {
    unsigned char *Tdest = reinterpret_cast<unsigned char*>(dest);
    unsigned char const *Tc = reinterpret_cast<unsigned char const*>(dest) + c;

    while (Tdest != Tc)
      *(Tdest++) = 0;
    return (dest);
  }

public:
  template<typename S, typename U>
  static void* Memcpy(U* dest, S* src, std::size_t c)
  {
    unsigned char const *Tsrc = reinterpret_cast<unsigned char const*>(src);
    unsigned char *Tdest = reinterpret_cast<unsigned char *>(dest);
    unsigned char const *Tc = reinterpret_cast<unsigned char const*>(src) + c;
    
    PackMan::MemSet(Tdest, c);
    while (Tsrc != Tc)
      *(Tdest++) = *(Tsrc++);
    
    return (dest);
  }
};


class	Client_S
{
private:
  boost::asio::io_service&	 ios;
  boost::asio::ip::tcp::socket	 sock;  

 public:
  Client_S(boost::asio::io_service& ios, boost::asio::ip::tcp::endpoint ep) : 
    ios(ios),
    sock(ios)
    {
      std::cout << "Client Created" << std::endl;
      this->sock.async_connect(ep,
			       boost::bind(&Client_S::handleConnect, 
					   this, 
					   boost::asio::placeholders::error, ep));
    }
  
  ~Client_S() {}
  
  TCPPacket*	MakeIt(eRequestType type, std::string s)
  {
    	TCPPacket*	TCPP = new TCPPacket();
	TCPP->H.size = s.size() + 4;
	TCPP->H.type = (int16_t)type;
	PackMan::Memcpy(TCPP->B, s.data(), s.size());
	return (TCPP);
  }

  void		handleConnect(const boost::system::error_code& e, boost::asio::ip::tcp::endpoint ep)
  {
    if (!e)
      {
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Connected to : " << ep.address() << std::endl;
	std::cout << "--------------------------------" << std::endl;
	this->sendData(MakeIt(CONNECT, "toto:12e12f3ea9esp8dlf5gm2dsq"));
	this->sendData(MakeIt(CREATE_ROOM, ""));
	this->sendData(MakeIt(JOIN_ROOM, "0"));
	this->sendData(MakeIt(LEAVE_ROOM, "0"));
	this->sendData(MakeIt(INVITE_PLAYER, "bite"));
	this->sendData(MakeIt(LAUNCH_GAME, ""));
	this->sendData(MakeIt(PING, ""));
	this->sendData(MakeIt(READY, "127.0.0.1:42666"));
      }
    else
      std::cout << "Failed to connect to : " << ep.address() << std::endl;
  }

  void		sendData(TCPPacket *NP)
  {
    char			*pack = new char[NP->H.size + 1];
    
    PackMan::Memcpy(pack, NP, NP->H.size);
    PackMan::Memcpy(pack, NP, NP->H.size);
	std::string pack2((char const*)NP, NP->H.size);
    
    boost::asio::async_write(this->sock,
			     boost::asio::buffer(pack2.data(), pack2.size()),
			     boost::bind(&Client_S::handleSend, 
					 this,
					 boost::asio::placeholders::error,
					 pack, NP));
  }

  void			handleSend(const boost::system::error_code& error, char* request, TCPPacket *NP)
  {
    if (!error)
      {
	std::string r(request);
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Request : " << r << " successfully sent" << std::endl;
	std::cout << "NetPacket Data : " << NP->H.size << "  ;  " << NP->H.type << "  ;  " << NP->B << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	// delete request;
	// delete NP;
      }
    else
      {
	std::cout << "Send Error : " << error.message() << " with the request : " << request << std::endl;
      }
  }
};

#endif
