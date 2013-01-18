
#pragma once

class IRequest;

class IService
{
public:
  virtual ~IService() {}
  virtual IRequest*		pull() = 0;
  virtual void			push(IRequest*) = 0;
};
