//
// IClientService.h for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/NetWork/include
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  9 11:24:52 2013 alexandre teisseire
// Last update Sat Jan 12 18:52:21 2013 alexandre teisseire
//

#pragma once

#include "IService.h"

class		IClientService : public IService
{
public:
  virtual ~IClientService() {}
  virtual void	operator()(void) = 0;
};
