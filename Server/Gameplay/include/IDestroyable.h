#pragma once

class IDestroyable
{
public:
  virtual ~IDestroyable(void) {}
  virtual void destroy()	= 0;
  virtual int getLife() const	= 0;
  virtual void subLife(int)	= 0;
};
