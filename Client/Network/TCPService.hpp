//
// TCPService.hpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 23:16:10 2013 alexandre teisseire
// Last update Sat Jan 19 01:24:34 2013 alexandre teisseire
//

#ifndef	_TCPSERVICE_HPP_
#define	_TCPSERVICE_HPP_

#include "boost/asio.hpp"
#include "IClientService.h"
#include "TCPPacket.h"

class	TCPService : public ITCPClientService
{
private:
  boost::asio::ip::tcp::socket sock;

public:
  TCPService(boost::asio::io_service&, boost::asio::ip::tcp::endpoint);
  virtual ~TCPService();

public:
  virtual void		recvData();
  virtual void		sendData(TCPPacket*);
  void			retrieveBody(std::string);
public:
  void			handleRecv(const boost::system::error_code&, char*);
  void			handleSend(const boost::system::error_code&, char*, TCPPacket*);
  void			handleConnect(const boost::system::error_code&, boost::asio::ip::tcp::endpoint);
  void			handlePack(const boost::system::error_code&, std::string, char*);
};

#endif
