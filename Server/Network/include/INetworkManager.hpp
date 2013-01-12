//
// INetworkManager.hpp for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/NetWork/include
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  9 11:29:51 2013 alexandre teisseire
// Last update Wed Jan  9 11:34:49 2013 alexandre teisseire
//

#pragma once

class		NetworkManager
{
private:
  IServerService	*SS;

  //
  // Thread Pool de Services
  //  

public:
  NetworkManager();
  ~NetworkManager();

public:
  void			run();
};
