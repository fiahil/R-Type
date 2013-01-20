//
// NetworkManager.cpp for RType in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 22:05:03 2013 alexandre teisseire
// Last update Sun Jan 20 01:09:26 2013 alexandre teisseire
//

#include	<iostream>
#include	<sstream>
#include	"NetworkManager.hpp"

NetworkManager::NetworkManager(char**av)
{
  std::stringstream	ss;
  ss << av[2];
  ss >> this->port;

  boost::asio::ip::tcp::endpoint etcp(boost::asio::ip::address::from_string(std::string(av[1])), this->port);
  boost::asio::ip::udp::endpoint eudp(boost::asio::ip::address::from_string(std::string(av[1])), 42999);
  this->etcp = etcp;
  this->eudp = eudp;
  this->TCPS = new TCPService(this->ios, this->etcp);
  // this->UDPS = new UDPService(*this, this->ios, this->eudp);
}

void		NetworkManager::run()
{
  try
    {

      this->TCPS->recvData();
      // this->UDPS.recvData();
      this->ios.poll();
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
