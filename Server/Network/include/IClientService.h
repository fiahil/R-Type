
#pragma once

#include "IService.h"

class		IClientService : public IService
{
public:
  virtual ~IClientService() {}
  virtual void	operator()(void) = 0;
};
