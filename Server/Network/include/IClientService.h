
#pragma once

#include "IService.h"

class ICommand;

class		IClientService : public IService
{
public:
  virtual ~IClientService() {}
  virtual void	operator()(void) = 0;
  virtual ICommand*		Zpull() = 0;
  virtual void			push(ICommand*) = 0;
};
