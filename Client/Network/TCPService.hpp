//
// TCPService.hpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 23:16:10 2013 alexandre teisseire
// Last update Wed Jan 16 14:35:59 2013 alexandre teisseire
//

#ifndef	_TCPSERVICE_HPP_
#define	_TCPSERVICE_HPP_

#include "boost/asio.hpp"
#include "TCPPacket.h"

class	TCPService
{
private:
  boost::asio::ip::tcp::socket sock;

public:
  TCPService(boost::asio::io_service&, boost::asio::ip::tcp::endpoint);
  ~TCPService();

public:
  void			recvData();
  void			sendData(TCPPacket*);
  void			retrieveBody(std::string);
public:
  void			handleRecv(const boost::system::error_code&, char*);
  void			handleSend(const boost::system::error_code&, char*, TCPPacket*);
  void			handleConnect(const boost::system::error_code&, boost::asio::ip::tcp::endpoint);
  void			handlePack(const boost::system::error_code&, std::string, char*);
};

#endif
