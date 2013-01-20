//
// NetworkManager.hpp for ClientRtype in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 21:50:21 2013 alexandre teisseire
// Last update Sat Jan 19 22:36:53 2013 alexandre teisseire
//

#ifndef		_NETWORKMANAGER_HPP_
#define		_NETWORKMANAGER_HPP_

#include	<deque>
#include	<boost/asio.hpp>
#include	"INetworkManager.hpp"
#include	"TCPService.hpp"
#include	"UDPService.hpp"

class		NetworkManager : public INetworkManager
{
private:
  boost::asio::io_service	 ios;
  boost::asio::ip::udp::endpoint eudp;
  boost::asio::ip::tcp::endpoint etcp;
private:
  int				 port;
  std::deque<ICommand*>		 actions;
  TCPService*			 TCPS;
  // UDPService*		 UDPS;

public:
  NetworkManager(char**);
  virtual ~NetworkManager() {};

public:
  virtual void	run();
  virtual ICommand* getAction();

public:
  void	push_back(ICommand*);
};

#endif
