//
// IService.hpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  2 11:26:15 2013 alexandre teisseire
// Last update Wed Jan  9 11:26:33 2013 alexandre teisseire
//

#pragma once

#include "TCPPacket.h"

class IService
{
public:
  virtual ~IService() {}
  virtual TCPPacket*	pull() = 0;
  virtual void			push(TCPPacket*) = 0;
};
