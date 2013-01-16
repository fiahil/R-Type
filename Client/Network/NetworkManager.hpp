//
// NetworkManager.hpp for ClientRtype in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 21:50:21 2013 alexandre teisseire
// Last update Tue Jan 15 22:30:19 2013 alexandre teisseire
//

#ifndef		_NETWORKMANAGER_HPP_
#define		_NETWORKMANAGER_HPP_

#include	<boost/asio.hpp>
#include	"INetworkManager.hpp"

class		NetworkManager : public INetworkManager
{
private:
  boost::asio::io_service	 ios;
  boost::asio::ip::tcp::endpoint ep;
  int				 port;

public:
  NetworkManager(char**);
  virtual ~NetworkManager() {};

public:
  virtual void	run();
};

#endif
