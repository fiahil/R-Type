//
// NetworkManager.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 22:05:03 2013 alexandre teisseire
// Last update Sat Jan 19 20:19:15 2013 alexandre teisseire
//

#include	<iostream>
#include	<sstream>
#include	"NetworkManager.hpp"
#include	"TCPService.hpp"
#include	"UDPService.hpp"

NetworkManager::NetworkManager(char**av)
{
  std::stringstream	ss;
  ss << av[2];
  ss >> this->port;

  boost::asio::ip::tcp::endpoint etcp(boost::asio::ip::address::from_string(std::string(av[1])), this->port);
  boost::asio::ip::udp::endpoint eudp(boost::asio::ip::address::from_string(std::string(av[1])), this->port);
  this->etcp = etcp;
  this->eudp = eudp;
}

void		NetworkManager::run()
{
  try
    {
      TCPService	TCPS(this->ios, this->etcp);
      UDPService	UDPS(*this, this->ios, this->eudp);
      
      this->ios.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }      
}

void		NetworkManager::push_back(ICommand *IC)
{
  this->actions.push_back(IC);
}

ICommand*	NetworkManager::getAction()
{
  if (!this->actions.empty())
    {
      ICommand*	IC = this->actions.front();
      this->actions.pop_front();
      return IC;
    }
  return 0;
}
