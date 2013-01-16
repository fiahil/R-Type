//
// UDPService.hpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan 16 14:24:01 2013 alexandre teisseire
// Last update Wed Jan 16 17:24:05 2013 alexandre teisseire
//

#ifndef	__UDPSERVICE_HPP__
#define	__UDPSERVICE_HPP__

#include "boost/asio.hpp"
#include "UDPPacket.h"

class	UDPService
{
private:
  boost::asio::ip::udp::socket	sock;
  boost::asio::ip::udp::endpoint  ep;

public:
  UDPService(boost::asio::io_service&, boost::asio::ip::udp::endpoint);
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
