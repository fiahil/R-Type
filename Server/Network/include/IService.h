
#pragma once

class IRequest;
class ICommand;

class IService
{
public:
  virtual ~IService() {}
  virtual IRequest*		pull() = 0;
  virtual void			push(IRequest*) = 0;
  virtual ICommand*		Zpull() = 0;
  virtual void			push(ICommand*) = 0;
};
