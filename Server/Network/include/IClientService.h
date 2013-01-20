
#pragma once

#include "IService.h"
#include "EndPoint.h"

class ICommand;

class		IClientService : public IService
{
public:
  virtual ~IClientService() {}
  virtual void	operator()(void) = 0;
  virtual ICommand*		Zpull() = 0;
  virtual void			push(ICommand*) = 0;
  virtual void			connect(std::string const&) = 0;
};
