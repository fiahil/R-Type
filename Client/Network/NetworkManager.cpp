//
// NetworkManager.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 22:05:03 2013 alexandre teisseire
// Last update Wed Jan 16 17:31:38 2013 alexandre teisseire
//

#include	<iostream>
#include	<sstream>
#include	"NetworkManager.hpp"
#include	"TCPService.hpp"

NetworkManager::NetworkManager(char**av)
{
  std::stringstream	ss;
  ss << av[2];
  ss >> this->port;

  boost::asio::ip::tcp::endpoint e(boost::asio::ip::address::from_string(std::string(av[1])),
				   this->port);
  this->ep = e;
}

void		NetworkManager::run()
{
  try
    {
      TCPService	TCPS(this->ios, this->ep);
      // UDPService	UDPS();
      
      this->ios.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }      
}
