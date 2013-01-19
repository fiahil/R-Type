//
// UDPService.hpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan 16 14:24:01 2013 alexandre teisseire
// Last update Sat Jan 19 15:31:36 2013 alexandre teisseire
//

#ifndef	__UDPSERVICE_HPP__
#define	__UDPSERVICE_HPP__

#include <deque>
#include <boost/asio.hpp>
#include "UDPPacket.h"
#include "Command.h"
#include "NetworkManager.hpp"

class	UDPService
{
private:
  NetworkManager&		  NM;
  boost::asio::ip::udp::socket	  sock;
  boost::asio::ip::udp::endpoint  ep;

public:
  UDPService(NetworkManager&, boost::asio::io_service&, boost::asio::ip::udp::endpoint);
  ~UDPService();

public:
  void			recvData();
  void			sendData(UDPPacket*);
  void			retrieveBody(std::string);
public:
  void			handleRecv(const boost::system::error_code&, char*);
  void			handleSend(const boost::system::error_code&, char*, UDPPacket*);
  void			handleConnect(const boost::system::error_code&, boost::asio::ip::udp::endpoint);
  void			handlePack(const boost::system::error_code&, std::string, char*);
};

#endif
