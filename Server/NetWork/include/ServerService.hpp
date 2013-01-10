//
// ServerService.hpp for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/NetWork/include
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  9 11:36:32 2013 alexandre teisseire
// Last update Wed Jan  9 11:41:42 2013 alexandre teisseire
//

#pragma once

#include "IServerService.h"

class		ServerService : public IServerService
{
private:
  //  ISocket*	sock;

public:
  ServerService();
  ~ServerService();


  virtual TCPPacket	pull();
  virtual void		push(TCPPacket);
};
