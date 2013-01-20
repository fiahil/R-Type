//
// TCPService.hpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 23:16:10 2013 alexandre teisseire
// Last update Sun Jan 20 03:48:03 2013 alexandre teisseire
//

#ifndef	_TCPSERVICE_HPP_
#define	_TCPSERVICE_HPP_

#include	<boost/asio/streambuf.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "TCPPacket.h"

class	TCPService
{
private:
  boost::asio::ip::tcp::socket sock;
  char* p;
  
public:
  TCPService(boost::asio::io_service&, boost::asio::ip::tcp::endpoint);
  ~TCPService();

public:
  void			recvData();
  void			sendData(TCPPacket*);
  void			retrieveBody(std::string);
  boost::asio::ip::tcp::socket&	socket();
public:
  void			handleRecv(const boost::system::error_code&, std::string);
  void			handleSend(const boost::system::error_code&, char*, TCPPacket*);
  void			handleConnect(const boost::system::error_code&, boost::asio::ip::tcp::endpoint);
  void			handlePack(const boost::system::error_code&, std::string, char*);
};

#endif
