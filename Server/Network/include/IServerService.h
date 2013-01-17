
#pragma once

#include	"IService.h"
#include	"IClientService.h"

class		IServerService : public IService
{
public:
  virtual ~IServerService() {}
  virtual IClientService*		accept() = 0;
};
