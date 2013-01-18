//
// test_client.cpp for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Client
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Sun Jan 13 00:54:22 2013 alexandre teisseire
// Last update Tue Jan 15 22:20:35 2013 alexandre teisseire
//

// #include "test_client.hpp"
#include "test_client_S.hpp"

int		main(int ac, char **av)
{
  if (ac == 2)
    {
      try
	{
	  boost::asio::io_service io_service;
	  boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(std::string(av[1])),
					    42666);
	  
	  Client_S C(io_service, ep);
	  io_service.run();
	}
      catch (std::exception& e)
	{
	  std::cerr << e.what() << std::endl;
	}
      
      return 0;  
    }
  else
    std::cout << "Usage : ./testClient [Ip_to_connect]" << std::endl;
}